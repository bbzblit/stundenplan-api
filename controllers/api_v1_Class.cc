#include "api_v1_Class.h"

using namespace api::v1;

// Add definition of your processing function here
void Class::getAllClasses(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback)
{
    static auto dbClient = app().getDbClient();

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(move(callback));
    *dbClient
            << "SELECT * FROM class" >>
        [callbackPtr](const Result &result)
    {
        Json::Value ret;
        ret.resize(0);
        for (const auto &row : result)
        {
            school_classes::Class classes = school_classes::Class(row);
            ret.append(classes.toJson());
        }
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(HttpStatusCode::k200OK);
        (*callbackPtr)(resp);
    };
}

void Class::getClassById(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback,
    int id)
{
    static auto dbClient = app().getDbClient();

    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(move(callback));
    *dbClient
            << "SELECT * FROM class "
               "WHERE id = ?"
            << id >>
        [callbackPtr](const Result &result)
    {
        auto resp = HttpResponse::newNotFoundResponse();
        if (result.size() == 1)
        {
            Json::Value ret;
            ret.resize(0);
            school_classes::Class classes = school_classes::Class(result[0]);
            ret.append(classes.toJson());
            resp = HttpResponse::newHttpJsonResponse(ret);
        }
        (*callbackPtr)(resp);
    };
}