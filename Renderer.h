#pragma once

#include <Base/Base.h>

namespace AEON::Graphics
{

typedef enum API : uint8_t
{
    None    = 0,
    Vulkan  = BIT(0),
    OpenGL  = BIT(1)
} API;

class Renderer : public ICreatable< Renderer >, public ISingleton< Renderer >
{
    public:
        template< API Api = None, typename T >
        requires std::derived_from< T, Renderer >
        static inline auto create()
        {
            AE_WARN_IF( Api == None, "Attempting to create renderer with no api!");
            return ref_ptr<T>();
        }

        Renderer( API api = API::None ) : _api{ api } {}
        API     api() { return _api; }
    protected:
        virtual ~Renderer();
    private:
        API             _api;
};

}