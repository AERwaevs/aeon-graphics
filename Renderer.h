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

class Renderer : public virtual Object, public Implements< Renderer, ISingleton >
{
public:
    static ref_ptr<Renderer>    create();
    Renderer( API api = API::None ) { _api = api; }
    static API api() { return _api; }
protected:
    virtual ~Renderer() = default;
private:
    static inline API   _api;
};

}