#include "Window.h"

namespace AEON::Graphics
{

Window::Window( const WindowProperties& props )
: _viewport( Viewport::create( this ) )
{};

void AEON_API Window::Update()
{
    // TODO implement viewport functions
    //while( m_viewport->AdvanceFrame() )
    //{
    //    m_viewport->Update();
    //    m_viewport->Present();
    //}
}
    
} // namespace AEON::Graphics
