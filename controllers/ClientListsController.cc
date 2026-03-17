#include "ClientListsController.h"
#include<string>

void ClientListsController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto client = drogon::app().getDbClient();
    std::string sql_command = "SELECT id, name FROM clientes ORDER BY id DESC";

    client->execSqlAsync
    (
    sql_command,
    [callback](const drogon::orm::Result &db_result)
    {
        Json::Value array(Json::arrayValue);

        for (auto const &row : db_result)
        {
            Json::Value tempClient;
            tempClient["id"] = row["id"].as<int>();
            tempClient["name"] = row["name"].as<std::string>();

            array.append(tempClient);
        }

        auto resp = HttpResponse::newHttpJsonResponse(array);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "*");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        callback(resp);
    },
    [callback](const drogon::orm::DrogonDbException &db_error)
    {
        Json::Value error;
        error["status"] = "failed";
        error["message"] = "Erro no banco";

        auto resp = HttpResponse::newHttpJsonResponse(error);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "*");
        resp->addHeader("Access-Control-Allow-Headers", "*");
        callback(resp);
    }
    );
}