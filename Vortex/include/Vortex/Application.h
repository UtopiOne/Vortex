#pragma once

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
};

Application* CreateApplication();

} // namespace Vortex
