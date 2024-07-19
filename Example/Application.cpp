#include "Vortex.h"

class ExampleApplication : public Vortex::Application {
public:
    ExampleApplication() {
        VT_INFO("Welcome to Example Application");
    }

    ~ExampleApplication() {
        VT_INFO("Goodbye from Example Application");
    }

    void Run() {
    }
};

Vortex::Application* Vortex::CreateApplication() {
    return new ExampleApplication();
}
