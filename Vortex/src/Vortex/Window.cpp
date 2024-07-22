
#include "VortexPCH.h"

#include "Vortex/Events/KeyboardEvent.h"
#include "Vortex/Events/MouseEvent.h"

#include <SDL2/SDL_video.h>
#include <glad/glad.h>
#include <SDL2/SDL.h>

#include "Vortex/Window.h"
#include "Vortex/Logging.h"
#include "Vortex/Core.h"
#include "Vortex/Events/Event.h"
#include "Vortex/Events/ApplicationEvent.h"

namespace Vortex {

Window::Window(const std::string title, const uint32 width, const uint32 height)
    : m_Title(title), m_Width(width), m_Height(height) {

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_WindowHandle = SDL_CreateWindow(m_Title.c_str(),
                                      SDL_WINDOWPOS_UNDEFINED,
                                      SDL_WINDOWPOS_UNDEFINED,
                                      m_Width,
                                      m_Height,
                                      (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL));

    VT_CORE_ASSERT(m_WindowHandle, "Failed to initialize SDL window: {0}", SDL_GetError());
    VT_CORE_INFO("Window created: {0} ({1}, {2})", GetTitle(), GetWidth(), GetHeight());

    m_RenderingContext = SDL_GL_CreateContext(m_WindowHandle);
    SDL_GL_MakeCurrent(m_WindowHandle, m_RenderingContext);

    VT_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress),
                   "Failed to initialize OpenGL context: {0}",
                   SDL_GetError());

    VT_CORE_INFO("Created Rendering Context: OpenGL");
    VT_CORE_INFO("Vendor:     {0}", (const char*)glGetString(GL_VENDOR));
    VT_CORE_INFO("Renderer:   {0}", (const char*)glGetString(GL_RENDERER))
    VT_CORE_INFO("Version:    {0}", (const char*)glGetString(GL_VERSION));
}

Window::~Window() {
    SDL_DestroyWindow(m_WindowHandle);
    SDL_Quit();
}

void Window::OnUpdate() {
    SDL_Event event;
    HandleEvents(event);

    SDL_GL_SwapWindow(m_WindowHandle);
}

void Window::HandleEvents(SDL_Event& event) {
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {

        case SDL_QUIT: {
            WindowCloseEvent event;
            m_CallbackFunction(event);
        } break;

        case SDL_WINDOWEVENT: {

            switch (event.window.event) {

            case SDL_WINDOWEVENT_RESIZED: {
                int w, h;
                SDL_GetWindowSize(m_WindowHandle, &w, &h);

                WindowResizeEvent event(w, h);
                m_CallbackFunction(event);

                m_Width = w;
                m_Height = h;
            } break;

            case SDL_WINDOWEVENT_LEAVE: {
                WindowUnfocusedEvent event;
                m_CallbackFunction(event);
            } break;

            case SDL_WINDOWEVENT_ENTER: {
                WindowFocusedEvent event;
                m_CallbackFunction(event);
            } break;
            }

        } break;

        case SDL_MOUSEMOTION: {
            int x, y;
            SDL_GetMouseState(&x, &y);

            MouseMovedEvent event(x, y);
            m_CallbackFunction(event);
        } break;

        case SDL_MOUSEBUTTONDOWN: {
            MouseButtonPressedEvent e(event.button.button);
            m_CallbackFunction(e);
        } break;

        case SDL_MOUSEBUTTONUP: {
            MouseButtonReleasedEvent e(event.button.button);
            m_CallbackFunction(e);
        } break;

        case SDL_MOUSEWHEEL: {
            MouseScrolledEvent e(event.wheel.x, event.wheel.y);
            m_CallbackFunction(e);
        } break;

        case SDL_KEYDOWN: {
            KeyboardKeyPressedEvent e(event.key.keysym.scancode);
            m_CallbackFunction(e);
        } break;

        case SDL_KEYUP: {
            KeyboardKeyReleasedEvent e(event.key.keysym.scancode);
            m_CallbackFunction(e);
        }
        }
    }
}

} // namespace Vortex
