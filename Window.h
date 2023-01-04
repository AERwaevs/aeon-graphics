#pragma once

#include <Graphics/Renderer.h>

class Event;
class Events;

namespace AEON
{
    struct AEON_DLL WindowProperties
    {
        String      m_name;
        bool        m_fullscreen;
        uint32_t    m_width;
        uint32_t    m_height;

        WindowProperties( const String&     name        = "AEON",
                                bool        fullscreen  = false,
                                uint32_t    width       = 1280,
                                uint32_t    height      = 720 ) 
        :   m_name(       name ),
            m_fullscreen( fullscreen ),
            m_width(      width ),
            m_height(     height ) 
        {};
    };

    class AEON_DLL Window : public Inherit< Object, Window >
    {
        using Properties = WindowProperties;
        using Renderer   = Graphics::Renderer;

    public:
        static  Shared<Window>      create( const Properties& props = Properties() );
        
        virtual uint32_t            GetWidth()          const           = 0;
        virtual uint32_t            GetHeight()         const           = 0;
        virtual String              GetName()           const           = 0;
        virtual bool                GetVsync()          const           = 0;

        virtual void                SetName( const String&  name )      = 0;
        virtual void                SetVsync(      bool     enabled )   = 0;
    
        virtual bool                PollEvents( Events& events_list )   = 0;
    protected:
        virtual                     ~Window() = default;

    protected:
                Events              m_events_buffer;
                Shared<Renderer>    m_renderer;

    };
    using Windows = List<Shared<Window>>;
}