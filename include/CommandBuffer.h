#pragma once
#include <vulkan/vulkan.h>
#include <vector>

class SwapChain;
class RenderPass;
class GraphicPipeline;

class CommandBuffer
{
public:
	std::vector<VkCommandBuffer> commandBuffers;
	CommandBuffer();
	~CommandBuffer();

	std::string createCommandBuffers(VkDevice const &device, SwapChain &swapChain, RenderPass &renderPass, GraphicPipeline &graphicPipeline, VkCommandPool const &commandPool);
};
