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
    
class GraphicsLayer : public Layer, public Implements< GraphicsLayer, ICreatable >
{
public:
    GraphicsLayer( API api );
    virtual ~GraphicsLayer();

    bool PollEvents( Events& unhandled ) override;
    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate() override;
protected:
    bool OnWindowClose( WindowCloseEvent& event );
private:
    Events              _events;
    Windows             _windows;
    ref_ptr<Renderer>   _renderer;
};

} // namespace AEON::Graphics
