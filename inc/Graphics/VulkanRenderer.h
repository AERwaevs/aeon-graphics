#pragma once

#include <Graphics/Renderer.h>

#include "vk/vk.h"

namespace aer
{
    class VulkanRenderer : public Renderer
    {
    public:
        VulkanRenderer();
        virtual         ~VulkanRenderer() noexcept = default;
    };

}