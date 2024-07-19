#pragma once

#ifdef VT_ENABLE_ASSERTS

    #ifdef VT_LINUXBSD

        #include <signal.h>

        #define VT_ASSERT(x, ...)                                                                                      \
            {                                                                                                          \
                if (!x) {                                                                                              \
                    VT_ERROR("Assertion failed: {0}", __VA_ARGS__);                                                    \
                    raise(SIGTRAP);                                                                                    \
                }                                                                                                      \
            }

        #define VT_CORE_ASSERT(x, ...)                                                                                 \
            {                                                                                                          \
                if (!x) {                                                                                              \
                    VT_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__);                                               \
                    raise(SIGTRAP);                                                                                    \
                }                                                                                                      \
            }
    #else

        #define VT_ASSERT(x, ...)
        #define VT_CORE_ASSERT(x, ...)

    #endif

#endif

#define uint8  uint8_t
#define uint16 uint16_t
#define uint32 uint32_t
