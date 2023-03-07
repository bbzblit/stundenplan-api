#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
  namespace v1
  {
    class Stundenplan : public drogon::HttpController<Stundenplan>
    {
    public:
      METHOD_LIST_BEGIN

      METHOD_LIST_END
    };
  }
}
