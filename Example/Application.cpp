#include "Vortex.h"

class Application : public Vortex::Application {
public:
    Application() {
        VT_INFO("Welcome to Example Application");
    }

    ~Application() {
        VT_INFO("Goodbye from Example Application");
    }

    void Run() {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
};

int main() {
    auto app = std::make_unique<Application>();
    app->Run();
}
