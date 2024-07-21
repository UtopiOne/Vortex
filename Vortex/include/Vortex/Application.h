#pragma once

#include "Vortex/Events/ApplicationEvent.h"
#include "Vortex/Layer.h"
#include "Vortex/Window.h"

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
    bool m_ShouldQuit = false;

    LayerStack m_LayerStack;

    bool OnWindowClose(WindowCloseEvent& e);
};

Application* CreateApplication();

} // namespace Vortex
