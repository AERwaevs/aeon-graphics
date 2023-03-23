#pragma once

#include <Base/Base.h>

#include <Core/Layer.h>

#include "Window.h"
#include "Renderer.h"

namespace AEON::Graphics
{
    
class GraphicsLayer : public Layer
{
public:
    GraphicsLayer( API api );
    virtual ~GraphicsLayer();
protected:
    bool OnEvent( Event& event ) override;
    bool OnWindowClose( WindowCloseEvent& event ) { return _windows.remove( event.window() ); }
private:
    Windows             _windows;
    ref_ptr<Renderer>   _renderer;
};

} // namespace AEON::Graphics
