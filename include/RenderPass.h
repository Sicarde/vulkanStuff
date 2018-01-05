#pragma once
#include <vulkan/vulkan.h>

class SwapChain;

class RenderPass
{
private:
public:
	VkRenderPass renderPass;
	RenderPass();
	~RenderPass();

	void createRenderPass(VkDevice device, SwapChain &swapChain);
};

