#include <Vortex.h>

#include <imgui.h>

class GameLayer : public Vortex::Layer {
public:
    GameLayer() : Vortex::Layer("GameLayer") {
    }

    void OnAttach() override {
        VT_INFO("Hello from GameLayer!");
    }

    void OnUpdate(double deltaTime) override {
    }

    void OnDebugUIUpdate() override {
        ImGui::Begin("test");
        ImGui::Text("%i", m_Shots);
        ImGui::End();
    }

    void OnEvent(Vortex::Event& event) override {
        if (event.IsInCategory(Vortex::EventCategoryKeyboard)) {
            if (Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::W) ||
                Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::Up)) {
                VT_INFO("Move Up!");
            }
            if (Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::S) ||
                Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::Down)) {
                VT_INFO("Move Down!");
            }
            if (Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::A) ||
                Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::Left)) {
                VT_INFO("Move Left!");
            }
            if (Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::D) ||
                Vortex::Input::IsKeyPressed(Vortex::KeyboardKeycode::Right)) {
                VT_INFO("Move Right!");
            }
        }

        if (Vortex::Input::IsMouseButtonPressed(Vortex::MouseButtonCode::LeftMouseButton) && !m_JustShot) {
            m_Shots++;
            auto [x, y] = Vortex::Input::GetMousePosition();
            VT_INFO("You shot {0} times at {1}, {2}", m_Shots, x, y);

            m_JustShot = true;
        }
        if (Vortex::Input::IsMouseButtonReleased(Vortex::MouseButtonCode::LeftMouseButton)) {
            m_JustShot = false;
        }
    }

private:
    unsigned int m_Shots = 0;

    bool m_JustShot = false;
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
