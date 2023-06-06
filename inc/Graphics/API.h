#pragma once

#include <Base/Base.h>

namespace aer::Graphics
{

typedef enum API : uint8_t
{
    None    = 0,
    Vulkan  = BIT(0),
    Default = None
} API;

} // namespace aer::Graphics