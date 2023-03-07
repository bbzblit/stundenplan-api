#include "api_v1_Appointment.h"

using namespace api::v1;

// Add definition of your processing function here
void Appointment::getAppointmentByClassId(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, const int classId)
{
    static auto dbClient = app().getDbClient();
    auto callbackPtr = std::make_shared<std::function<void(const HttpResponsePtr &)>>(move(callback));

    *dbClient << "SELECT * FROM appointment"
                 " WHERE class_id = ?"
              << classId >>
        [callbackPtr](const Result &result)
    {
        Json::Value ret;
        ret.resize(0);
        for (const auto &row : result)
        {
            school_classes::Appointment appointment = school_classes::Appointment(row);
            ret.append(appointment.toJson());
        }
        auto resp = HttpResponse::newHttpJsonResponse(ret);
        (*callbackPtr)(resp);
    };
}
