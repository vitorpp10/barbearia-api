#include "RegisterController.h"
#include<string>

void RegisterController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value json;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    auto receive_json = req->getJsonObject();

    if (!receive_json)
    {
        Json::Value errorJson;
        errorJson["message"] = "JSON invalido";
        std::cerr << "error json response" << std::endl;
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "*");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        callback(resp);
        return;
    }

    std::string clientName = (*receive_json)["name"].asString();

    auto client = drogon::app().getDbClient();
    std::string sql_command = "INSERT INTO clients (nome), VALUES ($1)";

    client->execSqlAsync
    (
    sql_command,
    [callback](const drogon::orm::Result &db_result)
    {
        Json::Value successJson;
        successJson["status"] = "success";
        successJson["message"] = "Agendado no Banco";

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
        errorJson["message"] = "Erro no banco";

        auto resp = HttpResponse::newHttpJsonResponse(errorJson);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "*");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        callback(resp);
    },
    clientName
    );
}