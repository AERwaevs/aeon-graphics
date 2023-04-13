#pragma once

#include "Renderer.h"

namespace AEON::Graphics
{

class Window;

class Viewport : public virtual Object, Implements< Viewport, ICreatable >
{
public:
    Viewport( Window* window ) : _parent( window ), _renderer( Renderer::create() ) 
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
using Viewports = List<Shared<Viewport>>;
    
} // namespace AEON::Graphics