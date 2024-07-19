#include "Vortex/Application.h"

#include "VortexPCH.h"

#include "Vortex/Logging.h"
#include "Vortex/Window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

namespace Vortex {

Application* Application::s_Instance = nullptr;

Application::Application() {
    s_Instance = this;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        VT_CORE_ERROR("Failed to initialize SDL: {0}", SDL_GetError());
    }

    m_Window = std::make_unique<Window>("Vortex Applicaiont", 800, 600);
}

Application::~Application() {
    SDL_Quit();
}

void Application::Run() {
    while (!m_ShouldQuit) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                m_ShouldQuit = true;
            }
        }
    }
}

} // namespace Vortex
