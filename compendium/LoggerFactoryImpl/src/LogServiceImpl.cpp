#include <sstream>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#include "cppmicroservices/ServiceReference.h"

#include "LogServiceImpl.hpp"
#include "LoggerFactoryImpl.hpp"

namespace cppmicroservices
{
    namespace logservice
    {
       
        LogServiceImpl::LogServiceImpl(std::string const& loggerName)
        {
            logger = getLogger(loggerName);
        }

        void
        LogServiceImpl::Log(SeverityLevel level, std::string const& message)
        {
            switch (level)
            {
                case SeverityLevel::LOG_DEBUG:
                {
                    logger->debug(message);
                    break;
                }
                 case SeverityLevel::LOG_INFO:
                {
                    logger->info(message);
                    break;
                }
                case SeverityLevel::LOG_WARNING:
                {
                    logger->warn(message);
                    break;
                }
                case SeverityLevel::LOG_ERROR:
                {
                    logger->error(message);
                    break;
                }
            }
        }

        void
        LogServiceImpl::Log(SeverityLevel level, std::string const& message, const std::exception_ptr ex)
        {
            switch (level)
            {
                case SeverityLevel::LOG_DEBUG:
                {
                    logger->debug(message, ex);
                    break;
                }
                case SeverityLevel::LOG_INFO:
                {
                    logger->info(message, ex);
                    break;
                }
                case SeverityLevel::LOG_WARNING:
                {
                    logger->warn(message, ex);
                    break;
                }
                case SeverityLevel::LOG_ERROR:
                {
                    logger->error(message, ex);
                    break;
                }
            }
        }

        void
        LogServiceImpl::Log(ServiceReferenceBase const& sr, SeverityLevel level, std::string const& message)
        {
            switch (level)
            {
                case SeverityLevel::LOG_DEBUG:
                {
                    logger->debug(message, sr);
                    break;
                }
                case SeverityLevel::LOG_INFO:
                {
                    logger->info(message, sr);
                    break;
                }
                case SeverityLevel::LOG_WARNING:
                {
                    logger->warn(message, sr);
                    break;
                }
                case SeverityLevel::LOG_ERROR:
                {
                    logger->error(message, sr);
                    break;
                }
            }
        }

        void
        LogServiceImpl::Log(ServiceReferenceBase const& sr,
                            SeverityLevel level,
                            std::string const& message,
                            const std::exception_ptr ex)
        {
            switch (level)
            {
                case SeverityLevel::LOG_DEBUG:
                {
                    logger->debug(message, sr, ex);
                    break;
                }
                case SeverityLevel::LOG_INFO:
                {
                    logger->info(message, sr, ex);
                    break;
                }
                case SeverityLevel::LOG_WARNING:
                {
                    logger->warn(message, sr, ex);
                    break;
                }
                case SeverityLevel::LOG_ERROR:
                {
                    logger->error(message, sr, ex);
                    break;
                }
            }
        }

        std::shared_ptr<Logger> 
            LogServiceImpl::getLogger(std::string const& name) const
        {
            std::shared_ptr<LoggerFactory> lf = std::make_shared<LoggerFactoryImpl>();
            return lf->getLogger(name);
        }

        std::shared_ptr<Logger>
            LogServiceImpl::getLogger(std::string const& name, LoggerType type) const
        {
            std::shared_ptr<LoggerFactory> lf = std::make_shared<LoggerFactoryImpl>();
            return lf->getLogger(name, type);
        }

        void
        LogServiceImpl::AddSink(spdlog::sink_ptr& sink)
        {
            logger->AddSink(sink);
        }
    } // namespace logservice
} // namespace cppmicroservices
