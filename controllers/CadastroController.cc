#include "CadastroController.h"
#include<string>

void CadastroController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value json;
    auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
    auto receive_json = req->getJsonObject();

    if (!receive_json)
    {
        std::cerr << "Error getting json object" << std::endl;
        callback(resp);
        exit(EXIT_FAILURE);
    }

    std::string nomeCliente = (*receive_json)["nomeCliente"].asString();

    orm::DbClientPtr client = getDbClient();
    std::string sql_command = "INSERT INTO nomeCliente (nome) VALUES ($1)";



    // std::string sql_command = "INSERT INTO clientes (nome) VALUE ($1)";


}
