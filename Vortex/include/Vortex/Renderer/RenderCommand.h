#pragma once

#include "Vortex/Renderer/RendererAPI.h"

namespace Vortex {

class RenderCommand {
public:
    inline static void SetClearColor() {
        s_RendererAPI->SetClearColor();
    }

    inline static void Clear() {
        s_RendererAPI->Clear();
    }

private:
    static RendererAPI* s_RendererAPI;
};

} // namespace Vortex
