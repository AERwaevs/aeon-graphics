#pragma once

#include "Renderer.h"

namespace AEON::Graphics
{

class Window;

class Viewport : public virtual Object
{
public:
    template< API api = API::Default >
    static ref_ptr<Viewport> create( Window* window );

    Viewport( Window* window ) : _parent( window ), _renderer( Renderer::instance() ) 
    {};
    virtual bool AdvanceFrame();
    virtual bool AcquireFrame();
    virtual void Update();
    virtual void Present();
protected:
    virtual                 ~Viewport() = default;
protected:
    friend class Window;
    spy_ptr<Window>     _parent;
    ref_ptr<Renderer>   _renderer;
};
using Viewports = List<ref_ptr<Viewport>>;
    
template<> inline ref_ptr<Viewport> Viewport::create< API::None >( Window* window )
{
    AE_WARN( "Creating viewport with no API" );
    return{};
}

} // namespace AEON::Graphics