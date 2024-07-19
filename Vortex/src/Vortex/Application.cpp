#include "Vortex/Application.h"

#include "VortexPCH.h"

#include <thread>

namespace Vortex {

Application::Application() {
}

Application::~Application() {
}

void Application::Run() {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

} // namespace Vortex
