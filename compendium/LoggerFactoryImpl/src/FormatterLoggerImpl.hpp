#include "cppmicroservices/logger/FormatterLogger.hpp"
#include "spdlog/spdlog.h"

namespace cppmicroservices
{
    namespace logservice
    {
        class FormatterLoggerImpl final : public FormatterLogger
        {
            public:
                FormatterLoggerImpl(std::string const& loggerName);
                ~FormatterLoggerImpl() = default;

                void audit(const std::string& message) ;
                void audit(std::string const& format, std::string const& arg) ;
                void audit(std::string const& format, std::string const& arg1, std::string const& arg2) ;
                void audit(std::string const& message, const std::exception_ptr ex) ;
                void audit(std::string const& message, ServiceReferenceBase const& sr) ;
                void audit(std::string const& message,
                           ServiceReferenceBase const& sr,
                           const std::exception_ptr ex) ;

                void debug(std::string const& message) ;
                void debug(std::string const& format, std::string const& arg) ;
                void debug(std::string const& format, std::string const& arg1, std::string const& arg2) ;
                void debug(std::string const& message, const std::exception_ptr ex) ;
                void debug(std::string const& message, ServiceReferenceBase const& sr) ;
                void debug(std::string const& message,
                           ServiceReferenceBase const& sr,
                           const std::exception_ptr ex) ;


                void error(std::string const& message) ;
                void error(std::string const& format, std::string const& arg) ;
                void error(std::string const& format, std::string const& arg1, std::string const& arg2) ;
                void error(std::string const& message, const std::exception_ptr ex) ;
                void error(std::string const& message, ServiceReferenceBase const& sr) ;
                void error(std::string const& message,
                           ServiceReferenceBase const& sr,
                           const std::exception_ptr ex) ;

                void info(std::string const& message) ;
                void info(std::string const& format, std::string const& arg) ;
                void info(std::string const& format, std::string const& arg1, std::string const& arg2) ;
                void info(std::string const& message, const std::exception_ptr ex) ;
                void info(std::string const& message, ServiceReferenceBase const& sr) ;
                void info(std::string const& message,
                          ServiceReferenceBase const& sr,
                          const std::exception_ptr ex) ;

                void trace(std::string const& message) ;
                void trace(std::string const& format, std::string const& arg) ;
                void trace(std::string const& format, std::string const& arg1, std::string const& arg2) ;
                void trace(std::string const& message, const std::exception_ptr ex) ;
                void trace(std::string const& message, ServiceReferenceBase const& sr) ;
                void trace(std::string const& message,
                           ServiceReferenceBase const& sr,
                           const std::exception_ptr ex) ;

                void warn(std::string const& message) ;
                void warn(std::string const& format, std::string const& arg) ;
                void warn(std::string const& format, std::string const& arg1, std::string const& arg2) ;
                void warn(std::string const& message, const std::exception_ptr ex) ;
                void warn(std::string const& message, ServiceReferenceBase const& sr) ;
                void warn(std::string const& message,
                          ServiceReferenceBase const& sr,
                          const std::exception_ptr ex) ;

                void AddSink(spdlog::sink_ptr& sink) ;
            private:
                std::shared_ptr<Logger> m_Logger;
        };
    } // namespace logservice
} // namespace cppmicroservices

