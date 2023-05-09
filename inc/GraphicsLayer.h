#pragma once

#include <Base/Base.h>

#include <Core/Event.h>
#include <Core/Events/WindowEvents.h>
#include <Core/EventListener.h>
#include <Core/Layer.h>

#include "Window.h"
#include "Renderer.h"

namespace AEON::Graphics
{
    
class GraphicsLayer : public Layer, public Implements< GraphicsLayer, ICreate >
{
public:
    GraphicsLayer( API api );
    virtual ~GraphicsLayer();

    void AddWindow( ref_ptr<Window> window );
    bool PollEvents( Events&, bool = true ) override;
    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate() override;
protected:
    bool OnWindowClose( WindowCloseEvent& event );
private:
    Windows             _windows;
    ref_ptr<Renderer>   _renderer;
};

} // namespace AEON::Graphics
