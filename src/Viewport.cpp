#include <Graphics/Viewport.h>

namespace AEON::Graphics
{

//ref_ptr<Viewport> Viewport::create( Window* window )
//{
//    switch( Renderer::instance()->api() )
//    {
//        case API::Vulkan : return VulkanViewport::create( window );
//        //case Renderer::OpenGL : return OpenGLViewport::create();
//        default: return ref_ptr<Viewport>();
//    }
//}

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
