#pragma once

#include "Vortex/Window.h"

#include <memory>

namespace Vortex {

class Application {
public:
    Application();
    virtual ~Application();

    void Run();

    inline static Application& Get() {
        return *s_Instance;
    }

private:
    static Application* s_Instance;

    std::unique_ptr<Window> m_Window;

    bool m_ShouldQuit = false;
};

Application* CreateApplication();

} // namespace Vortex
