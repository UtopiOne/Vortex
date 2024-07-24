#pragma once

#include "Vortex/Core.h"

#include <SDL2/SDL.h>

namespace Vortex {

class Time {
public:
    static const uint64 GetTimeInMilliseconds() {
        return SDL_GetTicks64();
    }
};

} // namespace Vortex
