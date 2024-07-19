#pragma once

#ifdef VT_LINUXBSD

    #include <signal.h>

    #define VT_ASSERT(x, ...)                                                                                          \
        {                                                                                                              \
            if (!x) {                                                                                                  \
                VT_ERROR("Assertion failed: {0}", __VA_ARGS__);                                                        \
                raise(SIGTRAP);                                                                                        \
            }                                                                                                          \
        }

    #define VT_CORE_ASSERT(x, ...)                                                                                     \
        {                                                                                                              \
            if (!x) {                                                                                                  \
                VT_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__);                                                   \
                raise(SIGTRAP);                                                                                        \
            }                                                                                                          \
        }

#endif
