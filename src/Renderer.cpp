#include <Graphics/Window.h>

namespace aer
{

template<> ref_ptr<Renderer> Renderer::get_or_create< API::None >()
{
    ABORT_F( "Invalid API" );
}

} // namespace aer
