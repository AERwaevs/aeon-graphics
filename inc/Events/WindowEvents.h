#pragma once

#include <Base/Base.h>
#include <Base/Event.h>

namespace aer
{
    
namespace Graphics
{
    class Window;   // forward declare
}

struct WindowEvent : public Event, ITypeInfo< WindowEvent >
{
    WindowEvent( gfx::Window* window ) : _window( window ) {};
    
    spy_ptr<gfx::Window>  window() const { return _window; }
private:
    spy_ptr<gfx::Window>  _window;
};
AER_TYPE_NAME( aer::WindowEvent );

struct WindowCloseEvent : public WindowEvent, ITypeInfo< WindowCloseEvent >
{
    WindowCloseEvent( auto* window ) : WindowEvent( window ) {};
};
AER_TYPE_NAME( aer::WindowCloseEvent );
        
struct WindowMoveEvent : public WindowEvent, ITypeInfo< WindowMoveEvent >
{
    WindowMoveEvent( auto* window, uint32_t pos_x, uint32_t pos_y )
    : WindowEvent( window ), _x( pos_x ), _y( pos_y ) {};
    
    uint32_t x() const { return _x; }
    uint32_t y() const { return _y; }
private:
    uint32_t _x;
    uint32_t _y;
};
AER_TYPE_NAME( aer::WindowMoveEvent );

struct WindowResizeEvent : public WindowEvent, ITypeInfo< WindowResizeEvent >
{
    WindowResizeEvent( auto* window, uint32_t width, uint32_t height )
    : WindowEvent( window ), _width( width ), _height( height ) {};

    uint32_t    width()  const { return _width; }
    uint32_t    height() const { return _height; }
private:
    uint32_t    _width;
    uint32_t    _height;
};
AER_TYPE_NAME( aer::WindowResizeEvent );

struct WindowMinimizeEvent : public WindowEvent, ITypeInfo< WindowMinimizeEvent >
{
    WindowMinimizeEvent( auto* window ) : WindowEvent( window ) {};
};
AER_TYPE_NAME( aer::WindowMinimizeEvent );

struct WindowMaximizeEvent : public WindowEvent, ITypeInfo< WindowMaximizeEvent >
{
    WindowMaximizeEvent( auto* window ) : WindowEvent( window ) {};
};
AER_TYPE_NAME( aer::WindowMaximizeEvent );
    
struct WindowFocusEvent : public WindowEvent, ITypeInfo< WindowFocusEvent >
{
    WindowFocusEvent( auto* window ) : WindowEvent( window ) {};
};
AER_TYPE_NAME( aer::WindowFocusEvent );
        
struct WindowUnfocusEvent : public WindowEvent, ITypeInfo< WindowUnfocusEvent >
{
    WindowUnfocusEvent( auto* window ) : WindowEvent( window ) {};
};
AER_TYPE_NAME( aer::WindowUnfocusEvent );

} // namespace aer