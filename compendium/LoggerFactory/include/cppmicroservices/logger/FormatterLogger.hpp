#ifndef CPPMICROSERVICES_FORMATTER_LOGGER_H__
#define CPPMICROSERVICES_FORMATTER_LOGGER_H__

#include "Logger.hpp"

namespace cppmicroservices
{
    namespace logservice
    {
	 class FormatterLogger : public Logger
         {
             public:
                 virtual ~FormatterLogger() = default;
	 } ;
    }
}

#endif
