#pragma once

#include "Vortex/DebugUI/DebugUILayer.h"
#include "Vortex/Events/ApplicationEvent.h"
#include "Vortex/Layer.h"
#include "Vortex/Window.h"

#include <SDL_stdinc.h>
#include <memory>

namespace Vortex {

class Application {
public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event& event);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    inline std::unique_ptr<Window>& GetWindow() {
        return m_Window;
    }

    inline static Application& Get() {
        return *s_Instance;
    }

private:
    static Application* s_Instance;

    std::unique_ptr<Window> m_Window;
    unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

    bool m_ShouldQuit = false;
    Uint64 m_TicksCount = 0;

    LayerStack m_LayerStack;
    DebugUILayer* m_DebugUILayer;

    bool OnWindowClose(WindowCloseEvent& e);
};

Application* CreateApplication();

} // namespace Vortex
