#include <Graphics/Viewport.h>

namespace aer::gfx
{

//template<> ref_ptr<Viewport> Viewport::create< API::None >( Window* window )
//{
//    AE_WARN( "Creating viewport with no API" );
//    return{};
//}

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
    
} // namespace aer::gfx
