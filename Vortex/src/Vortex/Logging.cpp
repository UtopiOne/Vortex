#include "Vortex/Logging.h"

#include <spdlog/spdlog.h>
#include <spdlog/common.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Vortex {

std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
std::shared_ptr<spdlog::logger> Logger::s_ApplicationLogger;

void Logger::Init() {
    spdlog::set_pattern("[%H:%M:%S] [%n] %v");

    s_CoreLogger = spdlog::stdout_color_mt("Vortex");
    s_ApplicationLogger = spdlog::stdout_color_mt("Application");

    s_CoreLogger->set_level(spdlog::level::trace);
    s_ApplicationLogger->set_level(spdlog::level::trace);
}

} // namespace Vortex
