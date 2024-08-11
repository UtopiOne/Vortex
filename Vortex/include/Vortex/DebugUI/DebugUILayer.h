#pragma once

#include "Vortex/Layer.h"

namespace Vortex {

class DebugUILayer : public Layer {
public:
    DebugUILayer();
    ~DebugUILayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnDebugUIUpdate() override;

    void Begin();
    void End();
};

} // namespace Vortex
