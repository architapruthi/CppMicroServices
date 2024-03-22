#include <sstream>
#include <cstdio>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#include "cppmicroservices/ServiceReference.h"

#include "FormatterLoggerImpl.hpp"
#include "LoggerImpl.hpp"

namespace cppmicroservices
{
    namespace logservice
    {
       
	FormatterLoggerImpl::FormatterLoggerImpl(std::string const& loggerName)
        {
	    m_Logger = std::make_shared<LoggerImpl>(loggerName);
        }

        void
        FormatterLoggerImpl::audit(std::string const& message)
        {
            m_Logger->audit(message);
        }

         void
        FormatterLoggerImpl::audit(std::string const& format, std::string const& arg)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
             // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg.c_str());
            m_Logger->audit(buffer);
        }

        void
        FormatterLoggerImpl::audit(std::string const& format, std::string const& arg1, std::string const& arg2)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg1.c_str(), arg2.c_str());
            m_Logger->audit(buffer);
        }

          void
        FormatterLoggerImpl::audit(std::string const& message, const std::exception_ptr ex)
        {
            m_Logger->audit(message, ex);
        }
        void
        FormatterLoggerImpl::audit(std::string const& message, ServiceReferenceBase const& sr)
        {
            m_Logger->audit(message, sr);
        }

        void
        FormatterLoggerImpl::audit(std::string const& message,
                                   ServiceReferenceBase const& sr,
                                   const std::exception_ptr ex)
        {
            m_Logger->audit(message, sr, ex);
        }

        void
        FormatterLoggerImpl::debug(std::string const& message)
        {
	    m_Logger->debug(message);
        }

        void
        FormatterLoggerImpl::debug(std::string const& format, std::string const& arg)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg.c_str());
            m_Logger->debug(buffer); 
        }

        void
        FormatterLoggerImpl::debug(std::string const& format, std::string const& arg1, std::string const& arg2)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg1.c_str(), arg2.c_str());
            m_Logger->debug(buffer);
        }

        void
        FormatterLoggerImpl::debug(std::string const& message, const std::exception_ptr ex)
        {     
            m_Logger->debug(message, ex);
        }
        void
        FormatterLoggerImpl::debug(std::string const& message, ServiceReferenceBase const& sr)
        {
            m_Logger->debug(message, sr);
        }

        void
        FormatterLoggerImpl::debug(std::string const& message,
                                   ServiceReferenceBase const& sr,
                                   const std::exception_ptr ex)
        {   
            m_Logger->debug(message, sr, ex);
        }

        void
        FormatterLoggerImpl::error(std::string const& message)
        {
	    m_Logger->error(message);
        }

        void
        FormatterLoggerImpl::error(std::string const& format, std::string const& arg)
        {            
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg.c_str());
            m_Logger->error(buffer);
        }

        void
        FormatterLoggerImpl::error(std::string const& format, std::string const& arg1, std::string const& arg2)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg1.c_str(), arg2.c_str());
            m_Logger->error(buffer);
        }

         void
        FormatterLoggerImpl::error(std::string const& message, const std::exception_ptr ex)
        {
            m_Logger->error(message, ex);
        }
        void
        FormatterLoggerImpl::error(std::string const& message, ServiceReferenceBase const& sr)
        {
            m_Logger->error(message, sr);
        }

        void
        FormatterLoggerImpl::error(std::string const& message,
                                   ServiceReferenceBase const& sr,
                                   const std::exception_ptr ex)
        {
            m_Logger->error(message, sr, ex);
        }

        void
        FormatterLoggerImpl::info(std::string const& message)
        {
            m_Logger->info(message);
        }

        void
        FormatterLoggerImpl::info(std::string const& format, std::string const& arg)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg.c_str());
            m_Logger->info(buffer);
        }

        void
        FormatterLoggerImpl::info(std::string const& format, std::string const& arg1, std::string const& arg2)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg1.c_str(), arg2.c_str());
            m_Logger->info(buffer);
        }

          void
        FormatterLoggerImpl::info(std::string const& message, const std::exception_ptr ex)
        {
            m_Logger->info(message, ex);
        }
        void
        FormatterLoggerImpl::info(std::string const& message, ServiceReferenceBase const& sr)
        {
            m_Logger->info(message, sr);
        }

        void
        FormatterLoggerImpl::info(std::string const& message,
                                   ServiceReferenceBase const& sr,
                                   const std::exception_ptr ex)
        {
            m_Logger->info(message, sr, ex);
        }

        void
        FormatterLoggerImpl::trace(std::string const& message)
        {
            m_Logger->trace(message);
        }

        void
        FormatterLoggerImpl::trace(std::string const& format, std::string const& arg)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg.c_str());
            m_Logger->trace(buffer);
        }

        void
        FormatterLoggerImpl::trace(std::string const& format, std::string const& arg1, std::string const& arg2)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg1.c_str(), arg2.c_str());
            m_Logger->trace(buffer);
        }

          void
        FormatterLoggerImpl::trace(std::string const& message, const std::exception_ptr ex)
        {
            m_Logger->trace(message, ex);
        }
        void
        FormatterLoggerImpl::trace(std::string const& message, ServiceReferenceBase const& sr)
        {
            m_Logger->trace(message, sr);
        }

        void
        FormatterLoggerImpl::trace(std::string const& message,
                                   ServiceReferenceBase const& sr,
                                   const std::exception_ptr ex)
        {
            m_Logger->trace(message, sr, ex);
        }

        void
        FormatterLoggerImpl::warn(std::string const& message)
        {
            m_Logger->warn(message);
        }

        void
        FormatterLoggerImpl::warn(std::string const& format, std::string const& arg)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg.c_str());
            m_Logger->warn(buffer);
        }

        void
        FormatterLoggerImpl::warn(std::string const& format, std::string const& arg1, std::string const& arg2)
        {
            char buffer[100]; // Make sure the buffer is large enough to hold the formatted string
            // Use sprintf to format a string
            sprintf(buffer, format.c_str(), arg1.c_str(), arg2.c_str());
            m_Logger->warn(buffer);
        }

          void
        FormatterLoggerImpl::warn(std::string const& message, const std::exception_ptr ex)
        {
            m_Logger->warn(message, ex);
        }
        void
        FormatterLoggerImpl::warn(std::string const& message, ServiceReferenceBase const& sr)
        {
            m_Logger->warn(message, sr);
        }

        void
        FormatterLoggerImpl::warn(std::string const& message,
                                   ServiceReferenceBase const& sr,
                                   const std::exception_ptr ex)
        {
            m_Logger->warn(message, sr, ex);
        }

        void
        FormatterLoggerImpl::AddSink(spdlog::sink_ptr& sink)
        {
            m_Logger->AddSink(sink);
        }
    } // namespace logservice
} // namespace cppmicroservices

