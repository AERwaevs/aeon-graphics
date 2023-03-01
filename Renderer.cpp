#include "Base.h"
#include "Renderer.h"

#include "../Vendor/glad/include/glad/vulkan.h"
#include "../Vendor/glad/include/glad/gl.h"

#define AEON_GL_VERSION GLAD_MAKE_VERSION( 4, 6 )
#define AEON_VK_VERSION GLAD_MAKE_VERSION( 1, 2 )

#include "../Platform/Vulkan/VulkanRenderer.h"
#include "../Platform/OpenGL/OpenGLRenderer.h"

namespace AEON::Graphics
{
    static bool OpenGLSupported()
    {
        int version = gladLoaderLoadGL();  //! returns 0, can't load opengl?
        AE_INFO( "OpenGL version: %d.%d", 
                    GLAD_VERSION_MAJOR(version),
                    GLAD_VERSION_MINOR(version) );
        return version >= AEON_GL_VERSION;
    }

    static bool VulkanSupported()
    {
        int version = gladLoaderLoadVulkan( nullptr, nullptr, nullptr );
        AE_INFO( "Vulkan version: %d.%d", 
                    GLAD_VERSION_MAJOR(version),
                    GLAD_VERSION_MINOR(version) );
        return version >= AEON_VK_VERSION;
    }

    Shared<Renderer> Renderer::create( GraphicsAPI api )
    {
        if( api == Vulkan && VulkanSupported() )
        {
            return Shared<VulkanRenderer>( new VulkanRenderer() );
        }
        else if( api == OpenGL && OpenGLSupported() )
        {
            return Shared<OpenGLRenderer>( new OpenGLRenderer() );
        }
        else return Shared<Renderer>();
    }

    Renderer::~Renderer()
    {
        if( m_graphics_api == Vulkan ) gladLoaderUnloadVulkan();
    }
}