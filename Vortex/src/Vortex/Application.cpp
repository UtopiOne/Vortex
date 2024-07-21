#include "Vortex/Application.h"

#include "Vortex/Events/MouseEvent.h"
#include "Vortex/Input/Input.h"
#include "VortexPCH.h"

#include "Vortex/Core.h"
#include "Vortex/Events/ApplicationEvent.h"
#include "Vortex/Events/Event.h"
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
    m_Window->SetEventCallback(VT_BIND_EVENT_FN(Application::OnEvent));
}

Application::~Application() {
    SDL_Quit();
}

void Application::OnEvent(Event& event) {
    EventDispatcher dispatcher(event);
    dispatcher.Dispatch<WindowCloseEvent>(VT_BIND_EVENT_FN(Application::OnWindowClose));

    for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
        (*--it)->OnEvent(event);
        if (event.WasHandled()) {
            break;
        }
    }
}

void Application::Run() {
    WindowResizeEvent e(1280, 720);

    while (!m_ShouldQuit) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

        for (Layer* layer : m_LayerStack) {
            layer->OnUpdate();
        }

        m_Window->OnUpdate();
    }
}

void Application::PushLayer(Layer* layer) {
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}

void Application::PushOverlay(Layer* overlay) {
    m_LayerStack.PushOverlay(overlay);
    overlay->OnAttach();
}

bool Application::OnWindowClose(WindowCloseEvent& e) {
    m_ShouldQuit = true;
    return true;
}

} // namespace Vortex
