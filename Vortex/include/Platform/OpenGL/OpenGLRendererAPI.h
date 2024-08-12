#pragma once

#include "Vortex/Renderer/RendererAPI.h"

namespace Vortex {

class OpenGLRendererAPI : public RendererAPI {
    virtual void SetClearColor() override;
    virtual void Clear() override;
};

} // namespace Vortex
