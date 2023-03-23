#include "GraphicsLayer.h"

#include <Core/Application.h>

namespace AEON::Graphics
{
    GraphicsLayer::GraphicsLayer( API api )
    :   Layer( "GraphicsLayer" ),
        _renderer( Renderer::instance( api ) ),
        _windows{ Window::create( Application::instance().name() ) }
    {};

    bool GraphicsLayer::OnEvent( Event& event )
    {
        return event.Dispatch< WindowCloseEvent >( this, &GraphicsLayer::OnWindowClose );
    }
    
} // namespace AEON::Graphics