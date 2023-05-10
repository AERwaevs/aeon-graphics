#pragma once

#include <Base/Base.h>

#include "API.h"

namespace AEON::Graphics
{

class Renderer : public virtual Object
{
public:
    Renderer( API api )
    {
        _api = api;
    }

    template< API api >
    static ref_ptr<Renderer> create();

    template< API api = API::Default >
    static auto instance( Renderer* renderer = nullptr )
    {
        AE_WARN_IF( _instance && renderer, "Already an instance of renderer!" );
        if( !_instance ) _instance = renderer ? ref_ptr( renderer ) : Renderer::create< api >();
        return _instance;
    }

    static API api() { return _api; }
protected:
    virtual ~Renderer() = default;
private:
    static inline API       _api{ API::Default };
    static inline ref_ptr<Renderer> _instance;
};

template<> inline ref_ptr<Renderer> Renderer::create< API::None >()
{
    AE_WARN( "Creating renderer with no API" );
    return{};
}

}