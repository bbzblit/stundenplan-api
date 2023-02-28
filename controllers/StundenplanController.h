#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class StundenplanController : public drogon::HttpSimpleController<StundenplanController>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    PATH_ADD("/",Get,Post);
    PATH_ADD("/test",Get);
    PATH_LIST_END
};
