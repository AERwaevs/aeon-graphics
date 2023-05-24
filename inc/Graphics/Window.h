#pragma once

#include <Base/Base.h>
#include <Base/EventListener.h>

#include "Renderer.h"
#include "Viewport.h"

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
    static  ref_ptr<Window>     create( const WindowProperties& props = WindowProperties() );
    template< typename Window_t >
            Window_t            native();
    virtual String              name()                   const = 0;
    virtual bool                minimized()              const = 0;
    virtual uint32_t            width()                  const = 0;
    virtual uint32_t            height()                 const = 0;
    
    virtual void                SetName( const String& )       = 0;

            void                Update(){};
protected:
    virtual ~Window() = default;
protected:
            ref_ptr<Renderer>   _renderer;
            ref_ptr<Viewport>   _viewport;

};
using Windows = List<ref_ptr<Window>>;

}