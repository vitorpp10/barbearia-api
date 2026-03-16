#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class DeleteClientsController : public drogon::HttpSimpleController<DeleteClientsController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
        PATH_ADD("/api/clients/delete", Post, Options);
    PATH_LIST_END
};
