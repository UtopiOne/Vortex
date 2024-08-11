#include "VortexPCH.h"

#include "Vortex/Input/Input.h"

#include "Vortex/Application.h"

#include <SDL.h>

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

std::pair<int, int> Input::GetMousePosition() {
    int x, y;
    uint32 currentMouseState = SDL_GetMouseState(&x, &y);

    return {x, y};
}

int Input::GetMouseX() {
    int x;
    uint32 currentMouseX = SDL_GetMouseState(&x, nullptr);

    return x;
}

int Input::GetMouseY() {
    int y;
    uint32 currentMouseX = SDL_GetMouseState(&y, nullptr);

    return y;
}

} // namespace Vortex
