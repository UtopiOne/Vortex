#pragma once

#include "SDL_video.h"
#include "Vortex/Core.h"
#include "Vortex/Events/Event.h"

#include <functional>
#include <string>

#include <SDL.h>

namespace Vortex {

class Window {
public:
    using EventCallbackFn = std::function<void(Event&)>;

    Window(const std::string title, const uint32 width, const uint32 height);
    ~Window();

    void OnUpdate(double deltaTime);

    inline const std::string GetTitle() const {
        return m_Title;
    }
    inline const uint32 GetWidth() const {
        return m_Width;
    }
    inline const uint32 GetHeight() const {
        return m_Height;
    }

    inline SDL_Window* GetWindowHandle() const {
        return m_WindowHandle;
    }
    inline const SDL_GLContext GetRenderingContext() const {
        return m_RenderingContext;
    }

    inline void SetEventCallback(const EventCallbackFn& callback) {
        m_CallbackFunction = callback;
    }

private:
    SDL_Window* m_WindowHandle;
    SDL_GLContext m_RenderingContext;
    std::string m_Title;

    EventCallbackFn m_CallbackFunction;

    uint32 m_Width, m_Height;

    void HandleEvents(SDL_Event& event);
};

} // namespace Vortex
