#include "Vortex/Application.h"

#include "VortexPCH.h"

#include "Vortex/Logging.h"
#include "Vortex/Window.h"

#include <glad/glad.h>
#include <SDL2/SDL.h>

namespace Vortex {

Application* Application::s_Instance = nullptr;

Application::Application() {
    s_Instance = this;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        VT_CORE_ERROR("Failed to initialize SDL: {0}", SDL_GetError());
    }

    m_Window = std::make_unique<Window>("Vortex Application", 800, 600);
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

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 0.1f, 0.1f, 1.0f);
        m_Window->OnUpdate();
    }
}

} // namespace Vortex
