#pragma once

#include <Graphics/Renderer.h>

namespace AEON::Graphics
{

class Viewport : public Inherit< Object, Viewport >
{
public:
    Viewport( Renderer* renderer )
    :   m_renderer{ renderer }
    {};

    virtual bool AdvanceFrame();
    virtual bool AcquireFrame();
    virtual void Update();
    virtual void Present();

    ~Viewport();
private:
    Shared<Renderer>    m_renderer;
};
using Viewports = List<Shared<Viewport>>;
    
} // namespace AEON::Graphics