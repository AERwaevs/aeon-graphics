#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#include <Vendor/glad/include/glad/gl.h>
#include <Vendor/glad/include/glad/vulkan.h>

#define AEON_GL_VERSION GLAD_MAKE_VERSION( 4, 6 )
#define AEON_VK_VERSION GLAD_MAKE_VERSION( 1, 2 )

namespace AEON::Graphics
{
    class AEON_DLL Renderer : public Inherit< Object, Renderer >
    {
        public:
            typedef enum : uint8_t
            {
                None    = 0,
                Vulkan  = BIT(0),
                OpenGL  = BIT(1)
            } GraphicsAPI;

            static Shared<Renderer> create( GraphicsAPI api = GraphicsAPI::None );

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

        protected:
            virtual ~Renderer() = default;
        private:
            static inline GraphicsAPI m_graphics_api = None;
    };
}