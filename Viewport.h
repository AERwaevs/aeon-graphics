#pragma once

#include "Renderer.h"

namespace AEON::Graphics
{

class Window;

class Viewport : public Object<>
{
public:
    virtual bool AdvanceFrame();
    virtual bool AcquireFrame();
    virtual void Update();
    virtual void Present();
protected:
    Viewport( Window* window ) : _parent{ window }, _renderer{ Renderer::instance() }
    {};
    virtual                 ~Viewport() = default;
private:
    static Shared<Viewport> create( Window* window );
protected:
    friend class Window;
    Observer<Window>    _parent;
    Shared<Renderer>    _renderer;
    
};
using Viewports = List<Shared<Viewport>>;
    
} // namespace AEON::Graphics