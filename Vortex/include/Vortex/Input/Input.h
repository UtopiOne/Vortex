#pragma once

#include "Vortex/Core.h"
#include "Vortex/Input/Keycodes.h"

#include <utility>

namespace Vortex {

class Input {
public:
    static bool IsKeyPressed(KeyboardKeycode keycode);

    static bool IsMouseButtonPressed(MouseButtonCode button);
    static bool IsMouseButtonReleased(MouseButtonCode button);
    static std::pair<int, int> GetMousePosition();
};

} // namespace Vortex
