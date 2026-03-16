#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class EditClientsController : public drogon::HttpSimpleController<EditClientsController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
        PATH_ADD("/api/clients/edit", Get, Post, Options);
    PATH_LIST_END
};
