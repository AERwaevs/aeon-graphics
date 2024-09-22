#pragma once

#include <Base/Base.h>
#include <Base/Event.h>

namespace aer
{
    
namespace Graphics
{
    class Window;   // forward declare
}

struct WindowEvent : public Event
{
    WindowEvent( gfx::Window* window ) : _window( window ) {};
    
    spy_ptr<gfx::Window>  window() const { return _window; }
private:
    spy_ptr<gfx::Window>  _window;
};

struct WindowCloseEvent : public WindowEvent
{
    WindowCloseEvent( auto* window ) : WindowEvent( window ) {};
};
        
struct WindowMoveEvent : public WindowEvent
{
    WindowMoveEvent( auto* window, uint32_t pos_x, uint32_t pos_y )
    : WindowEvent( window ), _x( pos_x ), _y( pos_y ) {};
    
    uint32_t x() const { return _x; }
    uint32_t y() const { return _y; }
private:
    uint32_t _x;
    uint32_t _y;
};

struct WindowResizeEvent : public WindowEvent
{
    WindowResizeEvent( auto* window, uint32_t width, uint32_t height )
    : WindowEvent( window ), _width( width ), _height( height ) {};

    uint32_t    width()  const { return _width; }
    uint32_t    height() const { return _height; }
private:
    uint32_t    _width;
    uint32_t    _height;
};

struct WindowMinimizeEvent : public WindowEvent
{
    WindowMinimizeEvent( auto* window ) : WindowEvent( window ) {};
};

struct WindowMaximizeEvent : public WindowEvent
{
    WindowMaximizeEvent( auto* window ) : WindowEvent( window ) {};
};
    
struct WindowFocusEvent : public WindowEvent
{
    WindowFocusEvent( auto* window ) : WindowEvent( window ) {};
};
        
struct WindowUnfocusEvent : public WindowEvent
{
    WindowUnfocusEvent( auto* window ) : WindowEvent( window ) {};
};

} // namespace aer