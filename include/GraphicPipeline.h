#pragma once
#include <vulkan/vulkan.h>
#include <vector>

class SwapChain;
class RenderPass;

class GraphicPipeline
{
private:
	std::vector<char> readFile(const std::string& filename);
public:
	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;
	GraphicPipeline();
	~GraphicPipeline();

	void createGraphicsPipeline(VkDevice device, SwapChain &swapChain, RenderPass &renderPass);
	VkShaderModule createShaderModule(VkDevice device, const std::vector<char>& code);
};

