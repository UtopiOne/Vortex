#include "Vortex/Renderer/RendererAPI.h"
#include "VortexPCH.h"

#include "Vortex/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Vortex {

RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}
