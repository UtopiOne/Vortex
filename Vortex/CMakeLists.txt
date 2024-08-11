set(VT_DIR ${PROJECT_SOURCE_DIR}/Vortex)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog"
  GIT_TAG "v1.x"
  GIT_PROGRESS TRUE)

set(BUILD_SHARED_LIBS FALSE)
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
  GIT_TAG "release-2.26.3"
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY "https://github.com/ocornut/imgui"
  GIT_TAG "docking"
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)

FetchContent_MakeAvailable(spdlog SDL2 imgui)

add_library(glad STATIC)
target_sources(
  glad
  PRIVATE ${VT_DIR}/thirdparty/glad/src/glad.c
          ${VT_DIR}/thirdparty/glad/include/glad/glad.h
          ${VT_DIR}/thirdparty/glad/include/KHR/khrplatform.h)
target_include_directories(glad PUBLIC ${VT_DIR}/thirdparty/glad/include)

add_library(
  imgui_sdl STATIC
  "${imgui_SOURCE_DIR}/imgui.cpp"
  "${imgui_SOURCE_DIR}/imgui_draw.cpp"
  "${imgui_SOURCE_DIR}/imgui_tables.cpp"
  "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
  "${imgui_SOURCE_DIR}/imgui_demo.cpp"
  "${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp"
  "${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp"
  "${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp")
target_include_directories(imgui_sdl PUBLIC "${imgui_SOURCE_DIR}"
                                            "${imgui_SOURCE_DIR}/backends/")
target_link_libraries(imgui_sdl PUBLIC SDL2::SDL2main SDL2::SDL2-static glad)

add_library(vortex STATIC)
target_sources(
  vortex
  PRIVATE ${VT_DIR}/include/Vortex.h
          ${VT_DIR}/include/VortexPCH.h
          ${VT_DIR}/include/Vortex/EntryPoint.h
          ${VT_DIR}/include/Vortex/Core.h
          # Events
          ${VT_DIR}/include/Vortex/Events/Event.h
          ${VT_DIR}/include/Vortex/Events/ApplicationEvent.h
          ${VT_DIR}/include/Vortex/Events/KeyboardEvent.h
          ${VT_DIR}/include/Vortex/Events/MouseEvent.h
          # Application
          ${VT_DIR}/include/Vortex/Application.h
          ${VT_DIR}/src/Vortex/Application.cpp
          # Logging
          ${VT_DIR}/src/Vortex/Logging.cpp
          ${VT_DIR}/include/Vortex/Logging.h
          # Utils
          ${VT_DIR}/src/Vortex/Utils.cpp
          ${VT_DIR}/include/Vortex/Utils.h
          # Window
          ${VT_DIR}/src/Vortex/Window.cpp
          ${VT_DIR}/include/Vortex/Window.h
          # Layer
          ${VT_DIR}/src/Vortex/Layer.cpp
          ${VT_DIR}/include/Vortex/Layer.h
          # Input
          ${VT_DIR}/src/Vortex/Input/Input.cpp
          ${VT_DIR}/include/Vortex/Input/Input.h
          ${VT_DIR}/include/Vortex/Input/Keycodes.h
          # Debug UI
          ${VT_DIR}/src/Vortex/DebugUI/DebugUILayer.cpp
          ${VT_DIR}/include/Vortex/DebugUI/DebugUILayer.h)
target_include_directories(vortex PUBLIC ${VT_DIR}/include)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(vortex PUBLIC VT_LINUXBSD)
  message(STATUS "Compile target: Linux")
endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(vortex PUBLIC VT_WINDOWS)
  message(STATUS "Compile target: Windows")
endif(CMAKE_SYSTEM_NAME STREQUAL "Windows")

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
  target_compile_definitions(vortex PUBLIC VT_ENABLE_ASSERTS)
endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

target_link_libraries(
  vortex
  PRIVATE glad
  PUBLIC imgui_sdl spdlog SDL2::SDL2main SDL2::SDL2-static)
target_precompile_headers(vortex PUBLIC ${VT_DIR}/include/VortexPCH.h)
