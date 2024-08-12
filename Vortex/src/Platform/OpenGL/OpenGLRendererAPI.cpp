#include "Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Vortex {

void OpenGLRendererAPI::SetClearColor() {
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
}

void OpenGLRendererAPI::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

} // namespace Vortex
