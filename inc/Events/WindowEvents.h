#pragma once

#include <Base/Base.h>
#include <Base/Event.h>

#include <Graphics/Window.h>

namespace aer
{

struct WindowEvent : public Event
{
    WindowEvent( Window* in_window ) : window( in_window ) {};
    const spy_ptr<Window>  window;
};

struct WindowCloseEvent : public WindowEvent
{
    WindowCloseEvent( auto window ) : WindowEvent( window ) {};
};

struct WindowExposeEvent : public WindowEvent
{
    WindowExposeEvent( auto window ) : WindowEvent( window ) {};
};
        
struct WindowConfigureEvent : public WindowEvent
{
    WindowConfigureEvent( auto window, uint32_t pos_x, uint32_t pos_y, uint32_t width, uint32_t height )
    : WindowEvent( window ), x( pos_x ), y( pos_y ), width( width ), height( height ) {};
    const uint32_t x, y, width, height;
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