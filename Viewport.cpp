#include <Graphics/Viewport.h>

#include <Platform/Vulkan/VulkanViewport.h>

namespace AEON::Graphics
{

Shared<Viewport> Viewport::create()
{
    switch ( Renderer::api() )
    {
        case Renderer::Vulkan : return VulkanViewport::create(); break;
        //case Renderer::OpenGL : return OpenGLViewport::create(); break;
        default: return Shared<Viewport>( new Viewport() );      break;
    }
}

bool Viewport::AdvanceFrame()
{
    return false;
}

bool Viewport::AcquireFrame()
{
    return false;
}

void Viewport::Update()
{

}

void Viewport::Present()
{
    
}
    
} // namespace AEON::Graphics
