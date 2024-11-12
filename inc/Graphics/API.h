#pragma once

#include <Base/Base.h>

namespace aer
{

typedef enum API : uint8_t
{
    None    = 0b0,
    Vulkan  = 0b1,
    Default = Vulkan
} API;

} // namespace aer