#pragma once

namespace AEON::Graphics
{

class AEON_DLL Renderer : public Singleton< Renderer >
{
    public:
        typedef enum : uint8_t
        {
            None    = 0,
            Vulkan  = BIT(0),
            OpenGL  = BIT(1)
        } GraphicsAPI;

        static Shared<Renderer> create( GraphicsAPI api = Vulkan );
                Renderer( GraphicsAPI api = Vulkan ) : m_graphics_api{ api } {};
                GraphicsAPI      api() { return s_instance ? m_graphics_api : None; }
    protected:
        virtual ~Renderer() = default;
    private:
        GraphicsAPI             m_graphics_api;
};

}