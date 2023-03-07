#pragma once

#include <drogon/HttpController.h>
#include <models/Class.h>
#include <memory>

using namespace drogon;
using namespace drogon_model;
using namespace drogon::orm;
namespace api
{
  namespace v1
  {
    class Class : public drogon::HttpController<Class>
    {

    public:
      METHOD_LIST_BEGIN

      METHOD_ADD(Class::getClassById, "/{1:the_class_id}", Get);

      METHOD_ADD(Class::getAllClasses, "/", Get);
      METHOD_LIST_END
      void getAllClasses(
          const HttpRequestPtr &req,
          std::function<void(const HttpResponsePtr &)> &&callback);
      void getClassById(
          const HttpRequestPtr &req,
          std::function<void(const HttpResponsePtr &)> &&callback,
          int id);
    };

  }
}
