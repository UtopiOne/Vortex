cmake_minimum_required(VERSION 3.19)

project(
  VortexEngine
  VERSION 0.1
  DESCRIPTION "Vortex: game engine for 2D games"
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/bin)

add_subdirectory(Vortex)

set(EXAMPLE_SOURCE ${PROJECT_SOURCE_DIR}/Example)
add_executable(VortexExample)
target_sources(VortexExample PRIVATE ${EXAMPLE_SOURCE}/Application.cpp)
target_link_libraries(VortexExample PRIVATE vortex)
