#pragma once

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

//                                Renderer(){ s_instance = Shared<Renderer>( this ); };
        static Shared<Renderer> GetOrCreate();
        static Shared<Renderer> create( GraphicsAPI api = GraphicsAPI::None );
        static Shared<Renderer> instance() { return s_instance; }
        static GraphicsAPI      api()      { return s_graphics_api; }
    protected:
        virtual ~Renderer() = default;
    private:
        static inline   Shared<Renderer>        s_instance;
        static inline   GraphicsAPI             s_graphics_api = None;
};

}