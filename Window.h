#pragma once

#include "Viewport.h"

#include <Core/Event.h>

namespace AEON::Graphics
{

struct WindowProperties
{
    String      _name;
    bool        _fullscreen;
    uint32_t    _width;
    uint32_t    _height;
    uint32_t    _pos_x;
    uint32_t    _pos_y;

    WindowProperties( const String&     name        = "AEON",
                            bool        fullscreen  = false,
                            uint32_t    width       = 1280,
                            uint32_t    height      = 720,
                            uint32_t    pos_x       = 0,
                            uint32_t    pos_y       = 0 ) 
    :   _name( name ), _fullscreen( fullscreen ), _width( width ),
        _height( height ), _pos_x( pos_x ), _pos_y( pos_y )
    {};
};

class Window : public Object<>
{
    using Properties = WindowProperties;

public:
    static  Shared<Window>      create( const Properties& props = Properties() );
    
    virtual uint32_t            width()          const           = 0;
    virtual uint32_t            height()         const           = 0;
    virtual String              name()           const           = 0;
    virtual bool                vsync()          const           = 0;

    virtual void                SetName( const String&  name )      = 0;
    virtual void                SetVsync(      bool     enabled )   = 0;

    virtual bool                PollEvents( Events& events_list )   = 0;
            void                Update();
protected:
            Window() : _viewport{ Viewport::create( this ) } {};
    virtual ~Window() = default;

protected:
            Events              _events_buffer;
            Shared<Viewport>    _viewport;

};
using Windows = List<Shared<Window>>;

}