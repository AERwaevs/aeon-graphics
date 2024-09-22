#pragma once

#include <Base/Base.h>

#include "API.h"

namespace aer::gfx
{

class Renderer : public inherit< Renderer, Object >
{
public:
    template< API api = API::Default >
    static ref_ptr<Renderer> get_or_create();

protected:
    virtual ~Renderer() noexcept = default;
};

}