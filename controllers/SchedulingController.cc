#include "SchedulingController.h"
#include<string>

void SchedulingController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    if (req->method() == drogon::Options)
    {
        Json::Value errorJson;
        auto resp = HttpResponse::newHttpJsonResponse(errorJson);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "*");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        callback(resp);
        return;
    }

    if (req->method() == drogon::Get)
    {
        std::string data_escolhida = req->getParameter("data");

        if (data_escolhida.empty())
        {
            Json::Value errorJson;
            errorJson["message"] = "JSON invalido";
            auto resp = HttpResponse::newHttpJsonResponse(errorJson);
            resp->addHeader("Access-Control-Allow-Origin", "*");
            resp->addHeader("Access-Control-Allow-Methods", "*");
            resp->addHeader("Access-Control-Allow-Headers", "*");
            callback(resp);
            return;
        }

        auto client = drogon::app().getDbClient();
        std::string sql_command = "SELECT horario_corte FROM agendamentos WHERE data_corte = $1";

        client->execSqlAsync
        (
        sql_command,
        [callback](const drogon::orm::Result &db_result)
        {
            Json::Value array(Json::arrayValue);

            for (int i = 0; i < db_result.size(); i++)
            {
                std::string horarioStr = db_result[i]["horario_corte"].as<std::string>();
                array.append(horarioStr);
            }

            Json::Value successJson;
            successJson["status"] = "success";
            successJson["horarios"] = array;

            auto resp = HttpResponse::newHttpJsonResponse(successJson);
            resp->addHeader("Access-Control-Allow-Origin", "*");
            resp->addHeader("Access-Control-Allow-Methods", "*");
            resp->addHeader("Access-Control-Allow-Headers", "*");
            callback(resp);
        },
        [callback](const drogon::orm::DrogonDbException &db_error)
        {
            Json::Value errorJson;
            errorJson["status"] = "failed";
            errorJson["message"] = "Erro ao buscar horarios";

            auto resp = HttpResponse::newHttpJsonResponse(errorJson);
            resp->addHeader("Access-Control-Allow-Origin", "*");
            resp->addHeader("Access-Control-Allow-Methods", "*");
            resp->addHeader("Access-Control-Allow-Headers", "*");
            callback(resp);
        },
            data_escolhida
        );
        return;
    }

    if (req->method() == drogon::Post)
    {
        // fazer o INSERT depois
        return;
    }
}


