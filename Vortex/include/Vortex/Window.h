#pragma once

#include "Vortex/Core.h"

#include <SDL2/SDL_video.h>
#include <memory>
#include <string>

#include <SDL2/SDL.h>

namespace Vortex {

class Window {
public:
    Window(const std::string title, const uint32 width, const uint32 height);
    ~Window();

    void OnUpdate();

    inline const std::string GetTitle() const {
        return m_Title;
    }
    inline const uint8 GetWidth() const {
        return m_Width;
    }
    inline const uint8 GetHeight() const {
        return m_Height;
    }

private:
    SDL_Window* m_WindowHandle;
    SDL_GLContext m_RenderingContext;
    std::string m_Title;

    uint32 m_Width, m_Height;
};

} // namespace Vortex
