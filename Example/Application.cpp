#include <Vortex.h>

class GameLayer : public Vortex::Layer {
public:
    GameLayer() : Vortex::Layer("GameLayer") {
    }

    void OnAttach() override {
        VT_INFO("{0}::OnAttach", GetName());
    }
    void OnDetach() override {
        VT_INFO("{0}::OnDetach", GetName());
    }
    void OnUpdate() override {
        VT_INFO("{0}::OnUpdate", GetName());
    }
    void OnEvent(Vortex::Event& event) override {
        VT_INFO("{0}", event.ToString());
    }
};

class ExampleApplication : public Vortex::Application {
public:
    ExampleApplication() {
        PushLayer(new GameLayer());
    }

    ~ExampleApplication() {
    }
};

Vortex::Application* Vortex::CreateApplication() {
    return new ExampleApplication();
}
