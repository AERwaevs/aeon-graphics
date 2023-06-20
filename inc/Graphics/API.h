#pragma once

#include <Base/Base.h>

namespace aer::gfx
{

typedef enum API : uint8_t
{
    None    = 0b0,
    Vulkan  = 0b1,
    Default = None
} API;

} // namespace aer::gfx