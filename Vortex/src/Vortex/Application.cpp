#include "Vortex/Application.h"

#include "Vortex/Core.h"
#include "Vortex/Events/ApplicationEvent.h"
#include "Vortex/Events/Event.h"
#include "VortexPCH.h"

#include "Vortex/Logging.h"
#include "Vortex/Window.h"

#include <SDL2/SDL_video.h>
#include <functional>
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
    m_Window->SetEventCallback(VT_BIND_EVENT_FN(Application::OnEvent));
}

Application::~Application() {
    SDL_Quit();
}

void Application::OnEvent(Event& event) {
    VT_CORE_INFO("{0}", event.ToString());

    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowCloseEvent>(VT_BIND_EVENT_FN(Application::OnWindowClose));

    if (event.ToString() == "WindowClose") {
        m_ShouldQuit = true;
    }
}

void Application::Run() {
    WindowResizeEvent e(1280, 720);

    while (!m_ShouldQuit) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 0.1f, 0.1f, 1.0f);

        m_Window->OnUpdate();
    }
}

bool Application::OnWindowClose(WindowCloseEvent& e) {
    m_ShouldQuit = true;
    return true;
}

} // namespace Vortex
