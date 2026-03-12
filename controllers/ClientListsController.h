#include <drogon/HttpSimpleController.h>

using namespace drogon;

class ClientListsController : public drogon::HttpSimpleController<ClientListsController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
        PATH_ADD("/api/clients", Get, Options);
    PATH_LIST_END
};
