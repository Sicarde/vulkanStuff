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

	void createCommandBuffers(VkDevice device, SwapChain &swapChain, RenderPass &renderPass, GraphicPipeline &graphicPipeline);
};
