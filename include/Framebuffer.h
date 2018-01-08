#pragma once
#include <vulkan/vulkan.h>
#include <vector>

class SwapChain;
class RenderPass;

class Framebuffer
{
private:
public:
	Framebuffer();
	~Framebuffer();

	std::string createFramebuffers(VkDevice const &device, SwapChain &swapChain, RenderPass const &renderPass);
};

