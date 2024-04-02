#include "LoggerFactoryImpl.hpp"
#include "LoggerImpl.hpp"

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
        LoggerFactoryImpl::getLogger(cppmicroservices::Bundle bundle, std::string const& name) const 
	{
	    return std::make_shared<LoggerImpl>(bundle, name);
	}
    }
}

