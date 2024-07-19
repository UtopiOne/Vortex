find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/Vortex/thirdparty/spdlog/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

find_package(spdlog REQUIRED)

if (LINUX OR BSD)
    add_compile_definitions(VT_LINUXBSD)
endif(LINUX OR BSD)

set(VORTEX_DIR ${PROJECT_SOURCE_DIR}/Vortex)
add_library(vortex STATIC)
target_sources(vortex PRIVATE 
    ${VORTEX_DIR}/include/Vortex.h
    ${VORTEX_DIR}/include/VortexPCH.h

    ${VORTEX_DIR}/include/Vortex/Core.h

    ${VORTEX_DIR}/include/Vortex/Application.h
    ${VORTEX_DIR}/src/Vortex/Application.cpp

    ${VORTEX_DIR}/src/Vortex/Logging.cpp
    ${VORTEX_DIR}/include/Vortex/Logging.h
)
target_include_directories(vortex PUBLIC
    ${VORTEX_DIR}/include
)
target_link_libraries(vortex PRIVATE spdlog::spdlog)
target_precompile_headers(vortex PUBLIC ${VORTEX_DIR}/include/VortexPCH.h)
