#pragma once
#include <vulkan/vulkan.h>
#include <vector>

class RenderPass;
class GraphicPipeline;
class Framebuffer;
class CommandBuffer;
class PhysicalDevice;

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

struct GLFWwindow;

class SwapChain
{
private:
	std::vector<VkImage> swapChainImages;
	PhysicalDevice *_pDevice = NULL;
	VkSurfaceKHR *_surface = NULL;
	VkDevice *_device = NULL;
	GLFWwindow *_window = NULL;

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);

public:
	VkSwapchainKHR swapChain;
	VkExtent2D swapChainExtent;
	VkFormat swapChainImageFormat;
	std::vector<VkFramebuffer> swapChainFramebuffers;
	std::vector<VkImageView> swapChainImageViews;
	SwapChain();
	~SwapChain();

	std::string createSwapChain(PhysicalDevice &pDevice, VkSurfaceKHR surface, VkDevice device, GLFWwindow* window);
	std::string createImageViews(VkDevice device);
	void cleanupSwapChain(VkDevice device, RenderPass &renderPass, GraphicPipeline &graphicPipeline, CommandBuffer &cb, VkCommandPool &commandPool);
	std::string recreateSwapChain(VkDevice device, RenderPass &renderPass, Framebuffer &fb, GraphicPipeline &graphicPipeline, CommandBuffer &cb, VkCommandPool &commandPool);
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice const &device, VkSurfaceKHR const &surface) const;
};

