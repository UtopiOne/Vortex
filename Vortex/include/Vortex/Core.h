#pragma once

#ifdef VT_LINUXBSD

    #include <signal.h>

    #ifdef VT_ENABLE_ASSERTS

        #define VT_ASSERT(x, ...)                                                                                      \
            {                                                                                                          \
                if (!(x)) {                                                                                            \
                    VT_ERROR("{0}:{1} - Assertion failed: {2}", __FILE__, __LINE__, __VA_ARGS__);                      \
                    raise(SIGTRAP);                                                                                    \
                }                                                                                                      \
            }

        #define VT_CORE_ASSERT(x, ...)                                                                                 \
            {                                                                                                          \
                if (!(x)) {                                                                                            \
                    VT_CORE_ERROR("{0}:{1} - Assertion failed: {2}", __FILE__, __LINE__, __VA_ARGS__);                 \
                    raise(SIGTRAP);                                                                                    \
                }                                                                                                      \
            }

    #else

        #define VT_ASSERT(x, ...)
        #define VT_CORE_ASSERT(x, ...)

    #endif

#else

    #define VT_ASSERT(x, ...)
    #define VT_CORE_ASSERT(x, ...)

#endif

#ifdef VT_WINDOWS

    #error "Vortex only supports Linux for now"

#endif

#ifdef VT_MACOS

    #error "Vortex only supports Linux for now"

#endif

#include <cstdint>

#define uint8  uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
#define uint64 uint64_t

#define BIT(x) (1 << x)

#define VT_BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
