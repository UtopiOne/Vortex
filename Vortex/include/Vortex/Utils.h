#pragma once

#include <glad/glad.h>

void APIENTRY GLDebugMessageCallback(GLenum source,
                                     GLenum type,
                                     GLuint id,
                                     GLenum severity,
                                     GLsizei length,
                                     const GLchar* msg,
                                     const void* data);
