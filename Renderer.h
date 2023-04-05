#pragma once

#include <Base/Base.h>

#include <concepts>

namespace AEON::Graphics
{

typedef enum API : uint8_t
{
    None    = 0,
    Vulkan  = BIT(0),
    OpenGL  = BIT(1)
} API;

class Renderer : public ISingletonFrom< API, Renderer >
{
public:    
    template< typename A, typename = std::enable_if_t< std::same_as< A, From > > >
    static auto instance( A api )
    {
        AE_WARN_IF( api == None, "Attempting to access renderer with no api!");
        return ref_ptr<Renderer>( _instance );
    }

    Renderer( API api = API::None ) { _api = api; }
    static API api() { return _api; }
protected:
    virtual ~Renderer();
private:
    static inline API   _api;
};

}