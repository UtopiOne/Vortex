#include "VortexPCH.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>

#include "Vortex/Window.h"
#include "Vortex/Logging.h"
#include "Vortex/Core.h"

namespace Vortex {

Window::Window(const std::string title, const uint32 width, const uint32 height)
    : m_Title(title), m_Width(width), m_Height(height) {

    m_WindowHandle = SDL_CreateWindow(m_Title.c_str(),
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      m_Width,
                                      m_Height,
                                      (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE));

    VT_CORE_ASSERT(m_WindowHandle, "Failed to initialize SDL window: {}", SDL_GetError());
}

Window::~Window() {
    SDL_DestroyWindow(m_WindowHandle);
    SDL_Quit();
}

} // namespace Vortex
