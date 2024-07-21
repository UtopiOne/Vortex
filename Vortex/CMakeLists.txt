if (LINUX OR BSD)
    add_compile_definitions(VT_LINUXBSD)
endif(LINUX OR BSD)

# if (${CMAKE_BUILD_TYPE} MATCHES Debug)
add_compile_definitions(VT_ENABLE_ASSERTS)
# endif(${CMAKE_BUILD_TYPE} MATCHES Debug)


set(VORTEX_DIR ${PROJECT_SOURCE_DIR}/Vortex)

find_package(spdlog REQUIRED)
add_subdirectory(thirdparty/SDL)

add_library(glad STATIC)
target_sources(glad PRIVATE
    ${VORTEX_DIR}/thirdparty/glad/src/glad.c
    ${VORTEX_DIR}/thirdparty/glad/include/glad/glad.h
    ${VORTEX_DIR}/thirdparty/glad/include/KHR/khrplatform.h
)
target_include_directories(glad PUBLIC
    ${VORTEX_DIR}/thirdparty/glad/include
)

add_library(vortex STATIC)
target_sources(vortex PRIVATE 
    ${VORTEX_DIR}/include/Vortex.h
    ${VORTEX_DIR}/include/VortexPCH.h

    ${VORTEX_DIR}/include/Vortex/EntryPoint.h

    ${VORTEX_DIR}/include/Vortex/Core.h

    ${VORTEX_DIR}/include/Vortex/Events/Event.h
    ${VORTEX_DIR}/include/Vortex/Events/ApplicationEvent.h
    ${VORTEX_DIR}/include/Vortex/Events/KeyboardEvent.h
    ${VORTEX_DIR}/include/Vortex/Events/MouseEvent.h

    ${VORTEX_DIR}/include/Vortex/Application.h
    ${VORTEX_DIR}/src/Vortex/Application.cpp

    ${VORTEX_DIR}/src/Vortex/Logging.cpp
    ${VORTEX_DIR}/include/Vortex/Logging.h

    ${VORTEX_DIR}/src/Vortex/Window.cpp
    ${VORTEX_DIR}/include/Vortex/Window.h

    ${VORTEX_DIR}/src/Vortex/Layer.cpp
    ${VORTEX_DIR}/include/Vortex/Layer.h

    ${VORTEX_DIR}/src/Vortex/Input/Input.cpp
    ${VORTEX_DIR}/include/Vortex/Input/Input.h
    ${VORTEX_DIR}/include/Vortex/Input/Keycodes.h
)
target_include_directories(vortex PUBLIC
    ${VORTEX_DIR}/include
)
target_link_libraries(vortex PRIVATE glad spdlog::spdlog SDL2)
target_precompile_headers(vortex PUBLIC ${VORTEX_DIR}/include/VortexPCH.h)
