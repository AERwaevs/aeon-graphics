#pragma once

#include <Core/Event.h>

#include <Graphics/Viewport.h>

namespace AEON::Graphics
{

struct WindowProperties
{
    String      m_name;
    bool        m_fullscreen;
    uint32_t    m_width;
    uint32_t    m_height;
    uint32_t    m_pos_x;
    uint32_t    m_pos_y;

    WindowProperties( const String&     name        = "AEON",
                            bool        fullscreen  = false,
                            uint32_t    width       = 1280,
                            uint32_t    height      = 720,
                            uint32_t    pos_x       = 0,
                            uint32_t    pos_y       = 0 ) 
    :   m_name( name ), m_fullscreen( fullscreen ), m_width( width ),
        m_height( height ), m_pos_x( pos_x ), m_pos_y( pos_y )
    {};
};

class Window : public Object< Window >
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
            Window() : m_viewport{ Viewport::create( this ) } {};
    virtual ~Window() = default;

protected:
            Events              m_events_buffer;
            Shared<Viewport>    m_viewport;

};
using Windows = List<Shared<Window>>;

}