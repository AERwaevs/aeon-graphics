#pragma once

#include <Base/Base.h>

#include "API.h"

namespace aer
{

class Renderer : public Object
{
public:
    template< API api = API::Default >
    static ref_ptr<Renderer> get_or_create();

    virtual ~Renderer() noexcept = default;
};

}