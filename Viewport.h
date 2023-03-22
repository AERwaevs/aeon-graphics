#pragma once

#include "Renderer.h"

namespace AEON::Graphics
{

class Window;

class Viewport : public Object< Viewport >
{
public:
    virtual bool AdvanceFrame();
    virtual bool AcquireFrame();
    virtual void Update();
    virtual void Present();
protected:
    Viewport( Window* window ) : parent_window{ window }, m_renderer{ Renderer::instance() }
    {};
    virtual                 ~Viewport() = default;
private:
    static Shared<Viewport> create( Window* window );
protected:
    friend class Window;
    Observer<Window>    parent_window;
    Shared<Renderer>    m_renderer;
    
};
using Viewports = List<Shared<Viewport>>;
    
} // namespace AEON::Graphics