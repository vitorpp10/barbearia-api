#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class CadastroController : public drogon::HttpSimpleController<CadastroController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
        PATH_ADD("/api/cadastro", Get, Post, Options);
    PATH_LIST_END
};
