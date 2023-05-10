#include <Graphics/Viewport.h>

namespace AEON::Graphics
{
    
template<> ref_ptr<Viewport> Viewport::create< API::None >( Window* window )
{
    AE_WARN( "Creating viewport with no API" );
    return{};
}

Viewport::Viewport( Window* window )
: _window( window ), _renderer( Renderer::instance() )
{

};

bool Viewport::AdvanceFrame()
{
    return false;
}

bool Viewport::AcquireFrame()
{
    return false;
}

void Viewport::Update()
{

}

void Viewport::Present()
{
    
}
    
} // namespace AEON::Graphics
