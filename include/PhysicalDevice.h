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

	void createLogicalDevice(VkSurfaceKHR surface, VkDevice device, VkQueue graphicsQueue, VkQueue presentQueue);
	void pickPhysicalDevice(VkInstance instance, SwapChain &swapChain, VkSurfaceKHR surface, VkDevice device);
	bool isDeviceSuitable(VkPhysicalDevice physDevice, VkDevice device, SwapChain &swapChain, VkSurfaceKHR surface);
	bool checkDeviceExtensionSupport();
	QueueFamilyIndices findQueueFamilies(VkSurfaceKHR surface);
};

