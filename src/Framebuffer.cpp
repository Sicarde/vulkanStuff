#include "../include/Framebuffer.h"
#include <vulkan/vulkan.h>
#include <stdexcept>
#include "../include/SwapChain.h"
#include "../include/RenderPass.h"

Framebuffer::Framebuffer() {
}

Framebuffer::~Framebuffer() {
}

std::string Framebuffer::createFramebuffers(VkDevice const &device, SwapChain &swapChain, RenderPass const &renderPass) {
	swapChain.swapChainFramebuffers.resize(swapChain.swapChainImageViews.size());

	for (size_t i = 0; i < swapChain.swapChainImageViews.size(); i++) {
		VkImageView attachments[] = {
			swapChain.swapChainImageViews[i]
		};

		VkFramebufferCreateInfo framebufferInfo = {};
		framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		framebufferInfo.renderPass = renderPass.renderPass;
		framebufferInfo.attachmentCount = 1;
		framebufferInfo.pAttachments = attachments;
		framebufferInfo.width = swapChain.swapChainExtent.width;
		framebufferInfo.height = swapChain.swapChainExtent.height;
		framebufferInfo.layers = 1;

		if (vkCreateFramebuffer(device, &framebufferInfo, nullptr, &swapChain.swapChainFramebuffers[i]) != VK_SUCCESS) {
			return "failed to create framebuffer!";
		}
	}
	return "";
}

