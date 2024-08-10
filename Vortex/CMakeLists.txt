set(VORTEX_DIR ${PROJECT_SOURCE_DIR}/Vortex)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog"
  GIT_TAG "v1.x"
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.26.3
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(SDL2)

add_library(glad STATIC)
target_sources(
  glad
  PRIVATE ${VORTEX_DIR}/thirdparty/glad/src/glad.c
          ${VORTEX_DIR}/thirdparty/glad/include/glad/glad.h
          ${VORTEX_DIR}/thirdparty/glad/include/KHR/khrplatform.h)
target_include_directories(glad PUBLIC ${VORTEX_DIR}/thirdparty/glad/include)

add_library(vortex STATIC)
target_sources(
  vortex
  PRIVATE ${VORTEX_DIR}/include/Vortex.h
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
          ${VORTEX_DIR}/src/Vortex/Utils.cpp
          ${VORTEX_DIR}/include/Vortex/Utils.h
          ${VORTEX_DIR}/src/Vortex/Window.cpp
          ${VORTEX_DIR}/include/Vortex/Window.h
          ${VORTEX_DIR}/src/Vortex/Layer.cpp
          ${VORTEX_DIR}/include/Vortex/Layer.h
          ${VORTEX_DIR}/src/Vortex/Input/Input.cpp
          ${VORTEX_DIR}/include/Vortex/Input/Input.h
          ${VORTEX_DIR}/include/Vortex/Input/Keycodes.h)
target_include_directories(vortex PUBLIC ${VORTEX_DIR}/include)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(vortex PUBLIC VT_LINUXBSD)
  message(STATUS "Compile target: Linux")
endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
  target_compile_definitions(vortex PUBLIC VT_ENABLE_ASSERTS)
endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

target_link_libraries(
  vortex
  PRIVATE glad SDL2
  PUBLIC spdlog $<$<BOOL:${MINGW}>:ws2_32>)
target_precompile_headers(vortex PUBLIC ${VORTEX_DIR}/include/VortexPCH.h)
