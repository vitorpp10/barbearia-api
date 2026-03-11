#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class TesteController : public drogon::HttpSimpleController<TesteController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
        PATH_ADD("/api/teste", Get, Options);
    PATH_LIST_END
};
