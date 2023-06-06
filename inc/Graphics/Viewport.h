#pragma once

#include <Base/Base.h>

#include "Renderer.h"

namespace aer::Graphics
{

class Window;

class Viewport : public virtual Object
{
public:
    template< API api = API::Default >
    static ref_ptr<Viewport> create( Window* window );
public:
    virtual bool AdvanceFrame();
    virtual bool AcquireFrame();
    virtual void Update();
    virtual void Present();
protected:
    Viewport( Window* window, Renderer* renderer ) : _window( window ), _renderer( renderer ) {};
    virtual ~Viewport() = default;
protected:
    friend class Window;
    spy_ptr<Window>   _window;
    ref_ptr<Renderer> _renderer;
};
using Viewports = List<ref_ptr<Viewport>>;

} // namespace aer::Graphics