#pragma once

#include <Base/Base.h>

#include "API.h"

namespace AEON::Graphics
{

class Renderer : public Object, public Interfaces< Renderer, ISingleton >
{
public:
    template< API api >
    static ref_ptr<Renderer> create();

    template< API api = API::Default >
    static auto get_or_create()
    {
        if( !_singleton ) _singleton = create< api >();
        return _singleton;
    }

protected:
    virtual ~Renderer() = default;
};

template<> inline ref_ptr<Renderer> Renderer::create< API::None >()
{
    AE_WARN( "Creating renderer with no API" );
    return{};
}

}