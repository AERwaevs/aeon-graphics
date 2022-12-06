#include <Base/Base.h>

#include <Graphics/Renderer.h>

#include <Platform/Vulkan/VulkanRenderer.h>
#include <Platform/OpenGL/OpenGLRenderer.h>

namespace AEON::Graphics
{    
    Shared<Renderer> Renderer::create( GraphicsAPI api )
    {
        if( api == Vulkan && VulkanSupported() )
        {
            m_graphics_api = Vulkan;
            return VulkanRenderer::create();
        }
        else if( api == OpenGL && OpenGLSupported() )
        {
            m_graphics_api = OpenGL;
            return OpenGLRenderer::create();
        }
        else return Shared<Renderer>( new Renderer() );
    }
}