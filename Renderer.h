#pragma once

#include <Base/Base.h>

namespace AEON::Graphics
{

class Renderer : public Singleton< Renderer >
{
    public:
        typedef enum : uint8_t
        {
            None    = 0,
            Vulkan  = BIT(0),
            OpenGL  = BIT(1)
        } GraphicsAPI;

        Renderer( API api = API::None ) : _api{ api } {}
        API     api() { return _api; }
    protected:
        virtual ~Renderer();
    private:
        API             _api;
};

}