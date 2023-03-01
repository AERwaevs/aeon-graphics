#include <Viewport.h>

#include "../Platform/Vulkan/VulkanViewport.h"

namespace AEON::Graphics
{

Shared<Viewport> Viewport::create( Window* window )
{
    switch( Renderer::get_or_create()->api() )
    {
        case Renderer::Vulkan : return Shared<VulkanViewport>( new VulkanViewport( window ) );
        //case Renderer::OpenGL : return OpenGLViewport::create();
        default: return Shared<Viewport>();
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
