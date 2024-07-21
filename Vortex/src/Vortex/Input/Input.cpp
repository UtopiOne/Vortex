#include "Vortex/Application.h"

#include "VortexPCH.h"

#include "Vortex/Input/Input.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

namespace Vortex {

bool Input::IsKeyPressed(KeyboardKeycode keycode) {
    const uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);

    if (currentKeyStates[(int)keycode]) {
        return true;
    }

    return false;
}

bool Input::IsMouseButtonPressed(MouseButtonCode button) {
    uint32 currentMouseState = SDL_GetMouseState(nullptr, nullptr);

    return (currentMouseState & SDL_BUTTON((int)button));
}

bool Input::IsMouseButtonReleased(MouseButtonCode button) {
    uint32 currentMouseState = SDL_GetMouseState(nullptr, nullptr);

    return !(currentMouseState & SDL_BUTTON((int)button));
}

} // namespace Vortex
