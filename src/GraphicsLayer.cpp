#include <GraphicsLayer.h>
#include <Window.h>
#include <Renderer.h>

#include <Core/Events/WindowEvents.h>
#include <Core/Events/LayerEvents.h>

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
}

bool GraphicsLayer::PollEvents( Events& poll_to, bool clear_unhandled )
{
    for( auto& event : _events )
    {
        event->Dispatch< WindowCloseEvent >( this, &GraphicsLayer::OnWindowClose );
    }

    return Layer::PollEvents( poll_to, clear_unhandled );
}

bool GraphicsLayer::OnWindowClose( WindowCloseEvent& event )
{
    _windows.remove( event.window() );
    if( _windows.size() == 0 ) _events.emplace_back( new LayerPopEvent( this ) );
    return true;
}

} // namespace AEON::Graphics