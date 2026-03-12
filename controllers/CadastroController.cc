#include "CadastroController.h"

#include <cmath>
#include<string>

void CadastroController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value json;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    auto receive_json = req->getJsonObject();

    if (!receive_json)
    {
        std::cerr << "error json response" << std::endl;
        callback(resp);
        return;
    }

<<<<<<< HEAD
    std::string clientName = (*receive_json)["clientes"].asString();

    auto client = drogon::app().getDbClient();
    std::string sql_command = "INSERT INTO clientes (nome) VALUES ($1)";

    client->execSqlAsync(
    sql_command,
    [callback](const drogon::orm::Result &db_result) {
        Json::Value successJson;
        successJson["status"] = "success";
        successJson["message"] = "Agendado no Banco";

        auto resp = HttpResponse::newHttpJsonResponse(successJson);
        resp->addHeader("Access-Control-Allow-Origin", "*");
        resp->addHeader("Access-Control-Allow-Methods", "*");
        resp->addHeader("Access-Control-Allow-Headers", "*");

        callback(resp);
    },
    [callback](const drogon::orm::DrogonDbException &db_error) {
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
=======
    std::string clientName = (*receive_json)["clientName"].asString();

    auto client = drogon::app().getDbClient();
    std::string sql_command = "INSERT INTO clientes (nome) VALUES ($1)";
>>>>>>> 8dcaf7bff30cc90900c955a841a0d643da597a99

	client->execSqlAsync(
		sql_command,
		[callback](const drogon::orm::Result &db_result) {
			Json::Value success_json;
			success_json["status"] = "success";
			success_json["message"] = "Agendado no banco";
			
			auto resp = drogon::HttpResponse::newHttpJsonResponse(success_json);
			resp->addHeader("Access-Control-Allow-Origin", "*");
			resp->addHeader("Access-Control-Allow-Methods", "*");
			resp->addHeader("Access-Control-Allow-Headers", "*");
			callback(resp);
		},
		[callback](const drogon::orm::DrogonDbException &db_error) {
		    Json::Value error_json;
		    error_json["status"] = "failed";
		    error_json["message"] = "Erro no banco";
		    
		    auto resp = drogon::HttpResponse::newHttpJsonResponse(error_json);
		    resp->addHeader("Access-Control-Allow-Origin", "*");
		    resp->addHeader("Access-Control-Allow-Methods", "*");
		    resp->addHeader("Access-Control-Allow-Headers", "*");
		    callback(resp);
		},
		clientName
	);
}
