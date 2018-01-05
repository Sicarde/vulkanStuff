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

	void createFramebuffers(VkDevice device, SwapChain &swapChain, RenderPass &renderPass);
};

