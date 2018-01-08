#pragma once
#include <vulkan/vulkan.h>
#include <string>

class SwapChain;

class RenderPass
{
private:
public:
	VkRenderPass renderPass;
	RenderPass();
	~RenderPass();

	std::string createRenderPass(VkDevice &device, SwapChain const &swapChain);
};

