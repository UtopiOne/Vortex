#pragma once

#include <spdlog/spdlog.h>

#include <memory>

namespace Vortex {

class Logger {
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
        return s_CoreLogger;
    }
    inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() {
        return s_ApplicationLogger;
    }

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ApplicationLogger;
};

} // namespace Vortex

#define VT_CORE_INFO(...)    Vortex::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define VT_CORE_TRACE(...)   Vortex::Logger::GetCoreLogger()->trace(__VA_ARGS__);
#define VT_CORE_WARNING(...) Vortex::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define VT_CORE_ERROR(...)   Vortex::Logger::GetCoreLogger()->critical(__VA_ARGS__);

#define VT_INFO(...)    Vortex::Logger::GetApplicationLogger()->info(__VA_ARGS__);
#define VT_TRACE(...)   Vortex::Logger::GetApplicationLogger()->trace(__VA_ARGS__);
#define VT_WARNING(...) Vortex::Logger::GetApplicationLogger()->warn(__VA_ARGS__);
#define VT_ERROR(...)   Vortex::Logger::GetApplicationLogger()->critical(__VA_ARGS__);
