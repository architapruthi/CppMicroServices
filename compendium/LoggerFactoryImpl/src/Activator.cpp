#include "Activator.hpp"
#include "LoggerFactoryImpl.hpp"
#include "LogServiceImpl.hpp"

namespace cppmicroservices
{
    namespace logservice
    {
        namespace impl
        {
            void
            Activator::Start(cppmicroservices::BundleContext bc)
            {
                auto svc1
                    = std::make_shared<cppmicroservices::logservice::LoggerFactoryImpl>();
                bc.RegisterService<cppmicroservices::logservice::LoggerFactory>(std::move(svc1));

		auto svc2
                    = std::make_shared<cppmicroservices::logservice::LogServiceImpl>("cppmicroservices::logservice");
                bc.RegisterService<cppmicroservices::logservice::LogService>(std::move(svc2));
            }

            void
            Activator::Stop(cppmicroservices::BundleContext)
            {
            }
        } // namespace impl
    }     // namespace logservice
} // namespace cppmicroservices

CPPMICROSERVICES_EXPORT_BUNDLE_ACTIVATOR(cppmicroservices::logservice::impl::Activator)
