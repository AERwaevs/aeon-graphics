#include "GraphicsLayer.h"
#include "Window.h"
#include "Renderer.h"

#include <Core/Application.h>
#include <Core/Events/WindowEvents.h>
#include <Core/Events/ApplicationEvents.h>

namespace AEON::Graphics
{

GraphicsLayer::GraphicsLayer( API api )
:   Layer( "GraphicsLayer" ),
    _renderer( Renderer::instance( api ) ),
    _windows{ Window::create() }
{
    AE_INFO( "%s created", _name.c_str() );
}

GraphicsLayer::~GraphicsLayer()
{
    AE_INFO( "%s destroyed", _name.c_str() );
}

void GraphicsLayer::OnAttach()
{
    AE_INFO( "%s attaching", _name.c_str() );
}

void GraphicsLayer::OnDetach()
{
    if( _windows.size() > 0 ) _windows.clear();
    AE_INFO( "%s detaching", _name.c_str() );
}

void GraphicsLayer::OnUpdate()
{
    for( auto& window : _windows )
    {
        window->PollEvents( _events );
        window->Update();
    }

    if( _windows.size() == 0 ) Application::instance().SendEvent( new ApplicationCloseEvent() );
    AE_INFO( "%s updating", _name.c_str() );
}

bool GraphicsLayer::PollEvents( Events& destination )
{
    for( auto& event : _events )
    {
        event->Dispatch< WindowCloseEvent >( this, &GraphicsLayer::OnWindowClose );
    }

    return Layer::PollEvents( destination );
}

bool GraphicsLayer::OnWindowClose( WindowCloseEvent& event )
{
    _windows.remove( event.window() );
    return false;
}

} // namespace AEON::Graphics