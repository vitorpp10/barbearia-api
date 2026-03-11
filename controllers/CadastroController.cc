#include "CadastroController.h"
#include<string>

void CadastroController::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto receive_json = req->getJsonObject();
    Json::Value json;

    if (receive_json)
    {
        std::string nomeCliente = (*receive_json)["nomeCliente"].asString();

        json["status"] = "sucess";
        json["message"] = "Cliente: " + nomeCliente + " foi agendado";
    }
    else
    {
        json["status"] = "fail";
        json["message"] = "Erro no agendamento";
    }

    auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
    resp->addHeader("Acess-Control-Allow-Origin", "*");
    resp->addHeader("Access-Control-Allow-Methods", "GET, OPTIONS");
    resp->addHeader("Acess-Control-Allow-Headers", "*");
    callback(resp);
}
