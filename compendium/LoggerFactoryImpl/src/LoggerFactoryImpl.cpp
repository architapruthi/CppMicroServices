#include "LoggerFactoryImpl.hpp"
#include "LoggerImpl.hpp"
#include "FormatterLoggerImpl.hpp"

namespace cppmicroservices
{
    namespace logservice
    {
        std::shared_ptr<Logger> 
        LoggerFactoryImpl::getLogger(const std::string& name) const 
	{
            return std::make_shared<LoggerImpl>(name);
	}

        std::shared_ptr<Logger>
        LoggerFactoryImpl::getLogger(std::string const& name, LoggerType type) const
        {
            if (type == LoggerType::Logger)
            {
                return std::make_shared<LoggerImpl>(name);
            }
            else
            {
                return std::make_shared<FormatterLoggerImpl>(name);
            }
        }
    }
}

