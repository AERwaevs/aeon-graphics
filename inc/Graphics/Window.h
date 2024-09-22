#pragma once

#include <Base/Base.h>
#include <Base/EventListener.h>

#include "Renderer.h"
#include "Viewport.h"

namespace aer::gfx
{
    
struct WindowProperties
{
    std::string name{        "AER"  };
    bool        fullscreen{  false  };
    bool        minimized{   false  };
    uint32_t    width{       1280   };
    uint32_t    height{      720    };
    uint32_t    posx{        0      };
    uint32_t    posy{        0      };
    std::any    nativeWindow;
    std::any    systemConnection;
};


class Window : public Object, public IEventListener<Window>
{
public:
    static  ref_ptr<Window>     create( const WindowProperties& props = WindowProperties() );
    template< typename Window_t >
            Window_t            native();
    virtual std::string         name()                   const = 0;
    virtual bool                minimized()              const = 0;
    virtual uint32_t            width()                  const = 0;
    virtual uint32_t            height()                 const = 0;
    
    virtual void                SetName( const std::string& )  = 0;

            void                Update(){};
protected:
    virtual ~Window() = default;
protected:
            ref_ptr<Renderer>   _renderer;
            ref_ptr<Viewport>   _viewport;

};
using Windows = std::list<ref_ptr<Window>>;

}