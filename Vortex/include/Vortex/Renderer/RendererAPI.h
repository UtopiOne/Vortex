#pragma once

namespace Vortex {

class RendererAPI {
public:
    enum class API {
        None = 0,
        OpenGL = 1,
    };

public:
    virtual void SetClearColor() = 0;
    virtual void Clear() = 0;

private:
    static API s_API;
};

} // namespace Vortex
