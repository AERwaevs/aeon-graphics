#pragma once

#include "Viewport.h"

#include <Core/Event.h>
#include <Core/EventListener.h>

namespace AEON::Graphics
{
struct WindowProperties
{
    String      name{        "AEON" };
    bool        fullscreen{  false  };
    bool        minimized{   false  };
    uint32_t    width{       1280   };
    uint32_t    height{      720    };
    uint32_t    pos_x{       0      };
    uint32_t    pos_y{       0      };
};


class Window : public virtual Object, public Implements< Window, IEventListener >
{
public:
    static  Shared<Window>      create( const WindowProperties& props = WindowProperties() );
    virtual String              name()                   const = 0;
    virtual bool                minimized()              const = 0;
    virtual uint32_t            width()                  const = 0;
    virtual uint32_t            height()                 const = 0;
    
    virtual void                SetName( const String& )       = 0;

            void                Update();
protected:
            Window( const WindowProperties& props = WindowProperties() )
            : _viewport( Viewport::create( this ) )
            {};
    virtual ~Window() = default;

protected:
            Shared<Viewport>    _viewport;

};
using Windows = List<Shared<Window>>;

}