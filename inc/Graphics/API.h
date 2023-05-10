#pragma once

#include <Base/Base.h>

namespace AEON::Graphics
{

typedef enum API : uint8_t
{
    None    = 0,
    Vulkan  = BIT(0),
    OpenGL  = BIT(1),
    Default = Vulkan
} API;

} // namespace AEON::Graphics