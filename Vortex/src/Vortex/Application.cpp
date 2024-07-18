#include "Vortex/Application.h"
#include "Vortex/Logging.h"
#include <thread>
#include <chrono>

namespace Vortex {

Application::Application() {
    Logger::Init();

    VT_CORE_INFO("Welcome to Lumina!");

    Run();
}

Application::~Application() {
    VT_CORE_INFO("Goodbye!");
}

void Application::Run() {
}

} // namespace Vortex
