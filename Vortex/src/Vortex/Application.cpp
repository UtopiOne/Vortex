#include "Vortex/Application.h"

#include "VortexPCH.h"

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
