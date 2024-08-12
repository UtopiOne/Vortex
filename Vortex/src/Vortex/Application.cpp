#include "Vortex/DebugUI/DebugUILayer.h"
#include "Vortex/Renderer/RenderCommand.h"
#include "VortexPCH.h"

#include "Vortex/Application.h"

#include "Vortex/Core.h"
#include "Vortex/Events/ApplicationEvent.h"
#include "Vortex/Events/Event.h"
#include "Vortex/Logging.h"
#include "Vortex/Window.h"
#include "Vortex/Time.h"

#include <glad/glad.h>
#include <SDL.h>

namespace Vortex {

Application* Application::s_Instance = nullptr;

Application::Application() {
    s_Instance = this;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        VT_CORE_ERROR("Failed to initialize SDL: {0}", SDL_GetError());
    }

    m_Window = std::make_unique<Window>("Vortex Application", 800, 600);
    m_Window->SetEventCallback(VT_BIND_EVENT_FN(Application::OnEvent));

    m_DebugUILayer = new DebugUILayer();
    PushOverlay(m_DebugUILayer);

    VT_CORE_INFO("Created Rendering Context: OpenGL");
    VT_CORE_INFO("Vendor:     {0}", (const char*)glGetString(GL_VENDOR));
    VT_CORE_INFO("Renderer:   {0}", (const char*)glGetString(GL_RENDERER))
    VT_CORE_INFO("Version:    {0}", (const char*)glGetString(GL_VERSION));

    glGenVertexArrays(1, &m_VertexArray);
    glBindVertexArray(m_VertexArray);

    glGenBuffers(1, &m_VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

    float vertices[3 * 3] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    glGenBuffers(1, &m_IndexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);

    unsigned int indices[3] = {0, 1, 2};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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
    while (!m_ShouldQuit) {
        double deltaTime = (Time::GetTimeInMilliseconds() - m_TicksCount) / 1000.0;
        m_TicksCount = Time::GetTimeInMilliseconds();

        RenderCommand::Clear();
        RenderCommand::SetClearColor();

        glBindVertexArray(m_VertexArray);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

        for (Layer* layer : m_LayerStack) {
            layer->OnUpdate(deltaTime);
        }

        m_DebugUILayer->Begin();
        for (Layer* layer : m_LayerStack) {
            layer->OnDebugUIUpdate();
        }
        m_DebugUILayer->End();

        m_Window->OnUpdate(deltaTime);
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
