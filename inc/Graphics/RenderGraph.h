#pragma once

#include <Base/nodes/group.h>

#include <vk/Instance.h>
#include <vk/Surface.h>
#include <vk/LogicalDevice.h>
#include <vk/Swapchain.h>
#include <vk/Context.h>
#include <vk/PipelineLayout.h>
#include <vk/GraphicsPipeline.h>
#include <vk/Framebuffer.h>
#include <vk/CommandPool.h>
#include <vk/CommandBuffer.h>
#include <vk/Semaphore.h>
#include <vk/Fence.h>

#include <vk/state/Image.h>
#include <vk/state/ImageView.h>

#include "VulkanRenderer.h"

namespace aer
{
    
struct RecordTraversal;

class RenderGraph : public Group
{

    void accept( RecordTraversal& recordTraversal ); 
    
};

} // namespace aer
