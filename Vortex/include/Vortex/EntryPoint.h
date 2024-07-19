#pragma once

#include "Vortex/Application.h"
#include "Vortex/Logging.h"

// #ifdef VT_LINUX

extern Vortex::Application* Vortex::CreateApplication();

int main() {
    Vortex::Logger::Init();
    VT_CORE_INFO("Welcome to Lumina!");

    Vortex::Application* app = Vortex::CreateApplication();
    app->Run();
    delete app;
    VT_CORE_INFO("Goodbye!");
}

// #endif
