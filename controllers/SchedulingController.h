#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class SchedulingController : public drogon::HttpSimpleController<SchedulingController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
        PATH_ADD("/api/clientes", Get, Post, Options);
    PATH_LIST_END
};
