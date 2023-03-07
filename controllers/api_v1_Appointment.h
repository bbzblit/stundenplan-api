#pragma once

#include <drogon/HttpController.h>
#include <models/Appointment.h>
#include <memory>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model;

namespace api
{
  namespace v1
  {
    class Appointment : public drogon::HttpController<Appointment>
    {
    public:
      METHOD_LIST_BEGIN
      METHOD_ADD(Appointment::getAppointmentByClassId, "?classId={1:the_class_id}", Get);
      METHOD_ADD(Appointment::getFutureByClassId, "/active/?classId={1:the_class_id}");
      METHOD_LIST_END
      void getAppointmentByClassId(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, const int classId);
      void getFutureByClassId(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, const int classId);
    
    };
  }
}
