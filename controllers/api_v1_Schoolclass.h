#pragma once

#include <drogon/HttpController.h>
#include <models/Classes.h>
#include <memory>

using namespace drogon;
using namespace drogon_model::school_classes;
using namespace drogon::orm;
namespace api
{
  namespace v1
  {
    class Schoolclass : public drogon::HttpController<Schoolclass>
    {

    public:
      METHOD_LIST_BEGIN

      METHOD_ADD(Schoolclass::getClassById, "/id/{1:the_class_id}", Get);

      METHOD_ADD(Schoolclass::getAllClasses, "/", Get);
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
