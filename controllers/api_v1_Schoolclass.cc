#include "api_v1_Schoolclass.h"

using namespace api::v1;

// Add definition of your processing function here
void Schoolclass::getAllClasses(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    static auto dbClient = app().getDbClient();

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(move(callback));
    *dbClient
            << "SELECT * FROM classes" >>
        [callbackPtr](const Result &result)
    {
        Json::Value ret;
        ret.resize(0);
        for (const auto &row : result)
        {
            Classes classes = Classes(row);
            ret.append(classes.toJson());
        }
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k201Created);
        (*callbackPtr)(resp);
    };
}