#pragma once
#include <vulkan/vulkan.h>
#include <vector>
class SwapChain;

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

struct QueueFamilyIndices {
	int graphicsFamily = -1;
	int presentFamily = -1;

	bool isComplete() {
		return graphicsFamily >= 0 && presentFamily >= 0;
	}
};

class PhysicalDevice
{
public:
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

	PhysicalDevice();
	~PhysicalDevice();

	std::string createLogicalDevice(VkSurfaceKHR const &surface, VkDevice &device, VkQueue &graphicsQueue, VkQueue &presentQueue);
	std::string pickPhysicalDevice(VkInstance const &instance, SwapChain const &swapChain, VkSurfaceKHR const &surface, VkDevice const &device);
	bool isDeviceSuitable(VkPhysicalDevice const &physDevice, VkDevice const &device, SwapChain const &swapChain, VkSurfaceKHR const &surface) const;
	bool checkDeviceExtensionSupport(VkPhysicalDevice const &pDevice) const;
	QueueFamilyIndices findQueueFamilies(VkSurfaceKHR const &surface, VkPhysicalDevice const &pDevice) const;
};

