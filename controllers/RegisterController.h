#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class RegisterController : public drogon::HttpSimpleController<RegisterController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
        PATH_ADD("/api/register", Get, Post, Options);
    PATH_LIST_END
};
