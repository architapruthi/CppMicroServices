#include "cppmicroservices/logger/LoggerFactory.hpp"

namespace cppmicroservices
{
    namespace logservice
    {
        class LoggerFactoryImpl final : public LoggerFactory
        {
          public:
              LoggerFactoryImpl() = default;
              ~LoggerFactoryImpl() = default;

              std::shared_ptr<Logger> getLogger(std::string const& name) const override;
              std::shared_ptr<Logger> getLogger(std::string const& name, LoggerType type) const override;              
        };
    } // namespace logservice
} // namespace cppmicroservices
