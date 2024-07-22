#pragma once

#include "Vortex/Events/Event.h"
#include <string>
#include <vector>

namespace Vortex {

class Layer {
public:
    Layer(const std::string& name);
    virtual ~Layer();

    virtual void OnAttach() {
    }
    virtual void OnDetach() {
    }
    virtual void OnUpdate() {
    }
    virtual void OnEvent(Event& event) {
    }

    inline std::string GetName() const {
        return m_Name;
    }

private:
    std::string m_Name;
};

class LayerStack {
public:
    LayerStack();
    ~LayerStack();

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    void PopLayer(Layer* layer);
    void PopOverlay(Layer* overlay);

    std::vector<Layer*>::iterator begin() {
        return m_Layers.begin();
    }
    std::vector<Layer*>::iterator end() {
        return m_Layers.end();
    }

private:
    std::vector<Layer*> m_Layers;
    unsigned int m_LayerInsertIndex = 0;
};

} // namespace Vortex
