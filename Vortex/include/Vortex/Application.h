#pragma once

#include "Vortex/Events/ApplicationEvent.h"
#include "Vortex/Window.h"

#include <memory>

namespace Vortex {

class Application {
public:
    Application();
    virtual ~Application();

    void Run();

    void OnEvent(Event& event);

    inline static Application& Get() {
        return *s_Instance;
    }

private:
    static Application* s_Instance;

    std::unique_ptr<Window> m_Window;
    bool m_ShouldQuit = false;

    bool OnWindowClose(WindowCloseEvent& e);
};

Application* CreateApplication();

} // namespace Vortex
