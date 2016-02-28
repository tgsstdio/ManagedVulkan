// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan 
{

	// Vulkan
	public interface class IVulkan
	{
		VkResult CreateInstance(VkInstanceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
		VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
		VkResult EnumerateInstanceExtensionProperties(char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
	};

	public ref class Vulkan : public IVulkan
	{
	public:
		VkResult CreateInstance(VkInstanceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkInstance* pInstance);
		VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
		VkResult EnumerateInstanceExtensionProperties(char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
	};

	// VkInstance
	public interface class IVkInstance
	{
		void DestroyInstance(VkAllocationCallbacks* pAllocator);
		VkResult EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
		PFN_vkVoidFunction GetInstanceProcAddr(char* pName);
		VkResult CreateAndroidSurfaceKHR(VkAndroidSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateDisplayPlaneSurfaceKHR(VkDisplaySurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateMirSurfaceKHR(VkMirSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		void DestroySurfaceKHR(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator);
		VkResult CreateWaylandSurfaceKHR(VkWaylandSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateWin32SurfaceKHR(VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateXlibSurfaceKHR(VkXlibSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateXcbSurfaceKHR(VkXcbSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateDebugReportCallbackEXT(VkDebugReportCallbackCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
		void DestroyDebugReportCallbackEXT(VkDebugReportCallbackEXT callback, VkAllocationCallbacks* pAllocator);
		void DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, char* pLayerPrefix, char* pMessage);
	};

	public ref class Instance : public IVkInstance
	{
	public:
		void DestroyInstance(VkAllocationCallbacks* pAllocator);
		VkResult EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices);
		PFN_vkVoidFunction GetInstanceProcAddr(char* pName);
		VkResult CreateAndroidSurfaceKHR(VkAndroidSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateDisplayPlaneSurfaceKHR(VkDisplaySurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateMirSurfaceKHR(VkMirSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		void DestroySurfaceKHR(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator);
		VkResult CreateWaylandSurfaceKHR(VkWaylandSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateWin32SurfaceKHR(VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateXlibSurfaceKHR(VkXlibSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateXcbSurfaceKHR(VkXcbSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);
		VkResult CreateDebugReportCallbackEXT(VkDebugReportCallbackCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback);
		void DestroyDebugReportCallbackEXT(VkDebugReportCallbackEXT callback, VkAllocationCallbacks* pAllocator);
		void DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, char* pLayerPrefix, char* pMessage);
	};

	// VkDevice
	public interface class IVkDevice
	{
		PFN_vkVoidFunction GetDeviceProcAddr(char* pName);
		void DestroyDevice(VkAllocationCallbacks* pAllocator);
		void GetDeviceQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
		VkResult DeviceWaitIdle(<TYPE> <NAME>);
		VkResult AllocateMemory(VkMemoryAllocateInfo* pAllocateInfo, VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
		void FreeMemory(VkDeviceMemory memory, VkAllocationCallbacks* pAllocator);
		VkResult MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
		void UnmapMemory(VkDeviceMemory memory);
		VkResult FlushMappedMemoryRanges(uint32_t memoryRangeCount, VkMappedMemoryRange* pMemoryRanges);
		VkResult InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, VkMappedMemoryRange* pMemoryRanges);
		void GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
		void GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
		VkResult BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
		void GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements);
		VkResult BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
		void GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
		VkResult CreateFence(VkFenceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkFence* pFence);
		void DestroyFence(VkFence fence, VkAllocationCallbacks* pAllocator);
		VkResult ResetFences(uint32_t fenceCount, VkFence* pFences);
		VkResult GetFenceStatus(VkFence fence);
		VkResult WaitForFences(uint32_t fenceCount, VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
		VkResult CreateSemaphore(VkSemaphoreCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
		void DestroySemaphore(VkSemaphore semaphore, VkAllocationCallbacks* pAllocator);
		VkResult CreateEvent(VkEventCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
		void DestroyEvent(VkEvent event, VkAllocationCallbacks* pAllocator);
		VkResult GetEventStatus(VkEvent event);
		VkResult SetEvent(VkEvent event);
		VkResult ResetEvent(VkEvent event);
		VkResult CreateQueryPool(VkQueryPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
		void DestroyQueryPool(VkQueryPool queryPool, VkAllocationCallbacks* pAllocator);
		VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
		VkResult CreateBuffer(VkBufferCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
		void DestroyBuffer(VkBuffer buffer, VkAllocationCallbacks* pAllocator);
		VkResult CreateBufferView(VkBufferViewCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkBufferView* pView);
		void DestroyBufferView(VkBufferView bufferView, VkAllocationCallbacks* pAllocator);
		VkResult CreateImage(VkImageCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkImage* pImage);
		void DestroyImage(VkImage image, VkAllocationCallbacks* pAllocator);
		void GetImageSubresourceLayout(VkImage image, VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
		VkResult CreateImageView(VkImageViewCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkImageView* pView);
		void DestroyImageView(VkImageView imageView, VkAllocationCallbacks* pAllocator);
		VkResult CreateShaderModule(VkShaderModuleCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
		void DestroyShaderModule(VkShaderModule shaderModule, VkAllocationCallbacks* pAllocator);
		VkResult CreatePipelineCache(VkPipelineCacheCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
		void DestroyPipelineCache(VkPipelineCache pipelineCache, VkAllocationCallbacks* pAllocator);
		VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
		VkResult MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, VkPipelineCache* pSrcCaches);
		VkResult CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, VkGraphicsPipelineCreateInfo* pCreateInfos, VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
		VkResult CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, VkComputePipelineCreateInfo* pCreateInfos, VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
		void DestroyPipeline(VkPipeline pipeline, VkAllocationCallbacks* pAllocator);
		VkResult CreatePipelineLayout(VkPipelineLayoutCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
		void DestroyPipelineLayout(VkPipelineLayout pipelineLayout, VkAllocationCallbacks* pAllocator);
		VkResult CreateSampler(VkSamplerCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
		void DestroySampler(VkSampler sampler, VkAllocationCallbacks* pAllocator);
		VkResult CreateDescriptorSetLayout(VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
		void DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, VkAllocationCallbacks* pAllocator);
		VkResult CreateDescriptorPool(VkDescriptorPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
		void DestroyDescriptorPool(VkDescriptorPool descriptorPool, VkAllocationCallbacks* pAllocator);
		VkResult ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags, <TYPE> <NAME>);
		VkResult AllocateDescriptorSets(VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
		VkResult FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, VkDescriptorSet* pDescriptorSets);
		void UpdateDescriptorSets(uint32_t descriptorWriteCount, VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, VkCopyDescriptorSet* pDescriptorCopies);
		VkResult CreateFramebuffer(VkFramebufferCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
		void DestroyFramebuffer(VkFramebuffer framebuffer, VkAllocationCallbacks* pAllocator);
		VkResult CreateRenderPass(VkRenderPassCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
		void DestroyRenderPass(VkRenderPass renderPass, VkAllocationCallbacks* pAllocator);
		void GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity);
		VkResult CreateCommandPool(VkCommandPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
		void DestroyCommandPool(VkCommandPool commandPool, VkAllocationCallbacks* pAllocator);
		VkResult ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags);
		VkResult AllocateCommandBuffers(VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
		void FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers);
		VkResult CreateSharedSwapchainsKHR(uint32_t swapchainCount, VkSwapchainCreateInfoKHR* pCreateInfos, VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);
		VkResult CreateSwapchainKHR(VkSwapchainCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
		void DestroySwapchainKHR(VkSwapchainKHR swapchain, VkAllocationCallbacks* pAllocator);
		VkResult GetSwapchainImagesKHR(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
		VkResult AcquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
	};

	public ref class Device : public IVkDevice
	{
	public:
		PFN_vkVoidFunction GetDeviceProcAddr(char* pName);
		void DestroyDevice(VkAllocationCallbacks* pAllocator);
		void GetDeviceQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
		VkResult DeviceWaitIdle(<TYPE> <NAME>);
		VkResult AllocateMemory(VkMemoryAllocateInfo* pAllocateInfo, VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory);
		void FreeMemory(VkDeviceMemory memory, VkAllocationCallbacks* pAllocator);
		VkResult MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData);
		void UnmapMemory(VkDeviceMemory memory);
		VkResult FlushMappedMemoryRanges(uint32_t memoryRangeCount, VkMappedMemoryRange* pMemoryRanges);
		VkResult InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, VkMappedMemoryRange* pMemoryRanges);
		void GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
		void GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
		VkResult BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
		void GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements);
		VkResult BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
		void GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
		VkResult CreateFence(VkFenceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkFence* pFence);
		void DestroyFence(VkFence fence, VkAllocationCallbacks* pAllocator);
		VkResult ResetFences(uint32_t fenceCount, VkFence* pFences);
		VkResult GetFenceStatus(VkFence fence);
		VkResult WaitForFences(uint32_t fenceCount, VkFence* pFences, VkBool32 waitAll, uint64_t timeout);
		VkResult CreateSemaphore(VkSemaphoreCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore);
		void DestroySemaphore(VkSemaphore semaphore, VkAllocationCallbacks* pAllocator);
		VkResult CreateEvent(VkEventCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkEvent* pEvent);
		void DestroyEvent(VkEvent event, VkAllocationCallbacks* pAllocator);
		VkResult GetEventStatus(VkEvent event);
		VkResult SetEvent(VkEvent event);
		VkResult ResetEvent(VkEvent event);
		VkResult CreateQueryPool(VkQueryPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool);
		void DestroyQueryPool(VkQueryPool queryPool, VkAllocationCallbacks* pAllocator);
		VkResult GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags);
		VkResult CreateBuffer(VkBufferCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer);
		void DestroyBuffer(VkBuffer buffer, VkAllocationCallbacks* pAllocator);
		VkResult CreateBufferView(VkBufferViewCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkBufferView* pView);
		void DestroyBufferView(VkBufferView bufferView, VkAllocationCallbacks* pAllocator);
		VkResult CreateImage(VkImageCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkImage* pImage);
		void DestroyImage(VkImage image, VkAllocationCallbacks* pAllocator);
		void GetImageSubresourceLayout(VkImage image, VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout);
		VkResult CreateImageView(VkImageViewCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkImageView* pView);
		void DestroyImageView(VkImageView imageView, VkAllocationCallbacks* pAllocator);
		VkResult CreateShaderModule(VkShaderModuleCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule);
		void DestroyShaderModule(VkShaderModule shaderModule, VkAllocationCallbacks* pAllocator);
		VkResult CreatePipelineCache(VkPipelineCacheCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache);
		void DestroyPipelineCache(VkPipelineCache pipelineCache, VkAllocationCallbacks* pAllocator);
		VkResult GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
		VkResult MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, VkPipelineCache* pSrcCaches);
		VkResult CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, VkGraphicsPipelineCreateInfo* pCreateInfos, VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
		VkResult CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, VkComputePipelineCreateInfo* pCreateInfos, VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines);
		void DestroyPipeline(VkPipeline pipeline, VkAllocationCallbacks* pAllocator);
		VkResult CreatePipelineLayout(VkPipelineLayoutCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout);
		void DestroyPipelineLayout(VkPipelineLayout pipelineLayout, VkAllocationCallbacks* pAllocator);
		VkResult CreateSampler(VkSamplerCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSampler* pSampler);
		void DestroySampler(VkSampler sampler, VkAllocationCallbacks* pAllocator);
		VkResult CreateDescriptorSetLayout(VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout);
		void DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, VkAllocationCallbacks* pAllocator);
		VkResult CreateDescriptorPool(VkDescriptorPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool);
		void DestroyDescriptorPool(VkDescriptorPool descriptorPool, VkAllocationCallbacks* pAllocator);
		VkResult ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags, <TYPE> <NAME>);
		VkResult AllocateDescriptorSets(VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets);
		VkResult FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, VkDescriptorSet* pDescriptorSets);
		void UpdateDescriptorSets(uint32_t descriptorWriteCount, VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, VkCopyDescriptorSet* pDescriptorCopies);
		VkResult CreateFramebuffer(VkFramebufferCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer);
		void DestroyFramebuffer(VkFramebuffer framebuffer, VkAllocationCallbacks* pAllocator);
		VkResult CreateRenderPass(VkRenderPassCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass);
		void DestroyRenderPass(VkRenderPass renderPass, VkAllocationCallbacks* pAllocator);
		void GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity);
		VkResult CreateCommandPool(VkCommandPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool);
		void DestroyCommandPool(VkCommandPool commandPool, VkAllocationCallbacks* pAllocator);
		VkResult ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags);
		VkResult AllocateCommandBuffers(VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers);
		void FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers);
		VkResult CreateSharedSwapchainsKHR(uint32_t swapchainCount, VkSwapchainCreateInfoKHR* pCreateInfos, VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains);
		VkResult CreateSwapchainKHR(VkSwapchainCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
		void DestroySwapchainKHR(VkSwapchainKHR swapchain, VkAllocationCallbacks* pAllocator);
		VkResult GetSwapchainImagesKHR(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages);
		VkResult AcquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
	};

	// VkPhysicalDevice
	public interface class IVkPhysicalDevice
	{
		void GetPhysicalDeviceProperties(VkPhysicalDeviceProperties* pProperties);
		void GetPhysicalDeviceQueueFamilyProperties(uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
		void GetPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties* pMemoryProperties);
		void GetPhysicalDeviceFeatures(VkPhysicalDeviceFeatures* pFeatures);
		void GetPhysicalDeviceFormatProperties(VkFormat format, VkFormatProperties* pFormatProperties);
		VkResult GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
		VkResult CreateDevice(VkDeviceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
		VkResult EnumerateDeviceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
		VkResult EnumerateDeviceExtensionProperties(char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
		void GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
		VkResult GetPhysicalDeviceDisplayPropertiesKHR(uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);
		VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);
		VkResult GetDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
		VkResult GetDisplayModePropertiesKHR(VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);
		VkResult CreateDisplayModeKHR(VkDisplayKHR display, const VkDisplayModeCreateInfoKHR*pCreateInfo, VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
		VkResult GetDisplayPlaneCapabilitiesKHR(VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);
		VkBool32 GetPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex, MirConnection* connection);
		VkResult GetPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
		VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
		VkResult GetPhysicalDeviceSurfaceFormatsKHR(VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
		VkResult GetPhysicalDeviceSurfacePresentModesKHR(VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
		VkBool32 GetPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex, wl_display* display);
		VkBool32 GetPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex);
		VkBool32 GetPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);
		VkBool32 GetPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
	};

	public ref class PhysicalDevice : public IVkPhysicalDevice
	{
	public:
		void GetPhysicalDeviceProperties(VkPhysicalDeviceProperties* pProperties);
		void GetPhysicalDeviceQueueFamilyProperties(uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties);
		void GetPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties* pMemoryProperties);
		void GetPhysicalDeviceFeatures(VkPhysicalDeviceFeatures* pFeatures);
		void GetPhysicalDeviceFormatProperties(VkFormat format, VkFormatProperties* pFormatProperties);
		VkResult GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties);
		VkResult CreateDevice(VkDeviceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDevice* pDevice);
		VkResult EnumerateDeviceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
		VkResult EnumerateDeviceExtensionProperties(char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties);
		void GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties);
		VkResult GetPhysicalDeviceDisplayPropertiesKHR(uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties);
		VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties);
		VkResult GetDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays);
		VkResult GetDisplayModePropertiesKHR(VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties);
		VkResult CreateDisplayModeKHR(VkDisplayKHR display, const VkDisplayModeCreateInfoKHR*pCreateInfo, VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode);
		VkResult GetDisplayPlaneCapabilitiesKHR(VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities);
		VkBool32 GetPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex, MirConnection* connection);
		VkResult GetPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported);
		VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities);
		VkResult GetPhysicalDeviceSurfaceFormatsKHR(VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats);
		VkResult GetPhysicalDeviceSurfacePresentModesKHR(VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes);
		VkBool32 GetPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex, wl_display* display);
		VkBool32 GetPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex);
		VkBool32 GetPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex, Display* dpy, VisualID visualID);
		VkBool32 GetPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id);
	};

	// VkQueue
	public interface class IVkQueue
	{
		VkResult QueueSubmit(uint32_t submitCount, VkSubmitInfo* pSubmits, VkFence fence);
		VkResult QueueWaitIdle();
		VkResult QueueBindSparse(uint32_t bindInfoCount, VkBindSparseInfo* pBindInfo, VkFence fence);
		VkResult QueuePresentKHR(VkPresentInfoKHR* pPresentInfo);
	};

	public ref class Queue : public IVkQueue
	{
	public:
		VkResult QueueSubmit(uint32_t submitCount, VkSubmitInfo* pSubmits, VkFence fence);
		VkResult QueueWaitIdle();
		VkResult QueueBindSparse(uint32_t bindInfoCount, VkBindSparseInfo* pBindInfo, VkFence fence);
		VkResult QueuePresentKHR(VkPresentInfoKHR* pPresentInfo);
	};

	// VkCommandBuffer
	public interface class IVkCommandBuffer
	{
		VkResult BeginCommandBuffer(VkCommandBufferBeginInfo* pBeginInfo);
		VkResult EndCommandBuffer();
		VkResult ResetCommandBuffer(VkCommandBufferResetFlags flags);
		void CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
		void CmdSetViewport(uint32_t firstViewport, uint32_t viewportCount, VkViewport* pViewports);
		void CmdSetScissor(uint32_t firstScissor, uint32_t scissorCount, VkRect2D* pScissors);
		void CmdSetLineWidth(float lineWidth);
		void CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
		void CmdSetBlendConstants(float blendConstants[4]);
		void CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds);
		void CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, uint32_t compareMask);
		void CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, uint32_t writeMask);
		void CmdSetStencilReference(VkStencilFaceFlags faceMask, uint32_t reference);
		void CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, uint32_t* pDynamicOffsets);
		void CmdBindIndexBuffer(VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
		void CmdBindVertexBuffers(uint32_t firstBinding, uint32_t bindingCount, VkBuffer* pBuffers, VkDeviceSize* pOffsets);
		void CmdDraw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
		void CmdDrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
		void CmdDrawIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
		void CmdDrawIndexedIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
		void CmdDispatch(uint32_t x, uint32_t y, uint32_t z);
		void CmdDispatchIndirect(VkBuffer buffer, VkDeviceSize offset);
		void CmdCopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, VkBufferCopy* pRegions);
		void CmdCopyImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageCopy* pRegions);
		void CmdBlitImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageBlit* pRegions, VkFilter filter);
		void CmdCopyBufferToImage(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkBufferImageCopy* pRegions);
		void CmdCopyImageToBuffer(VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, VkBufferImageCopy* pRegions);
		void CmdUpdateBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, uint32_t* pData);
		void CmdFillBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
		void CmdClearColorImage(VkImage image, VkImageLayout imageLayout, VkClearColorValue* pColor, uint32_t rangeCount, VkImageSubresourceRange* pRanges);
		void CmdClearDepthStencilImage(VkImage image, VkImageLayout imageLayout, VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, VkImageSubresourceRange* pRanges);
		void CmdClearAttachments(uint32_t attachmentCount, VkClearAttachment* pAttachments, uint32_t rectCount, VkClearRect* pRects);
		void CmdResolveImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageResolve* pRegions);
		void CmdSetEvent(VkEvent event, VkPipelineStageFlags stageMask);
		void CmdResetEvent(VkEvent event, VkPipelineStageFlags stageMask);
		void CmdWaitEvents(uint32_t eventCount, VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, VkImageMemoryBarrier* pImageMemoryBarriers);
		void CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, VkImageMemoryBarrier* pImageMemoryBarriers);
		void CmdBeginQuery(VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
		void CmdEndQuery(VkQueryPool queryPool, uint32_t query);
		void CmdResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
		void CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
		void CmdCopyQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
		void CmdPushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, void* pValues);
		void CmdBeginRenderPass(VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
		void CmdNextSubpass(VkSubpassContents contents);
		void CmdEndRenderPass();
		void CmdExecuteCommands(uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers);
	};

	public ref class CommandBuffer : public IVkCommandBuffer
	{
	public:
		VkResult BeginCommandBuffer(VkCommandBufferBeginInfo* pBeginInfo);
		VkResult EndCommandBuffer();
		VkResult ResetCommandBuffer(VkCommandBufferResetFlags flags);
		void CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
		void CmdSetViewport(uint32_t firstViewport, uint32_t viewportCount, VkViewport* pViewports);
		void CmdSetScissor(uint32_t firstScissor, uint32_t scissorCount, VkRect2D* pScissors);
		void CmdSetLineWidth(float lineWidth);
		void CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
		void CmdSetBlendConstants(float blendConstants[4]);
		void CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds);
		void CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, uint32_t compareMask);
		void CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, uint32_t writeMask);
		void CmdSetStencilReference(VkStencilFaceFlags faceMask, uint32_t reference);
		void CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, uint32_t* pDynamicOffsets);
		void CmdBindIndexBuffer(VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
		void CmdBindVertexBuffers(uint32_t firstBinding, uint32_t bindingCount, VkBuffer* pBuffers, VkDeviceSize* pOffsets);
		void CmdDraw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
		void CmdDrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance);
		void CmdDrawIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
		void CmdDrawIndexedIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride);
		void CmdDispatch(uint32_t x, uint32_t y, uint32_t z);
		void CmdDispatchIndirect(VkBuffer buffer, VkDeviceSize offset);
		void CmdCopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, VkBufferCopy* pRegions);
		void CmdCopyImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageCopy* pRegions);
		void CmdBlitImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageBlit* pRegions, VkFilter filter);
		void CmdCopyBufferToImage(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkBufferImageCopy* pRegions);
		void CmdCopyImageToBuffer(VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, VkBufferImageCopy* pRegions);
		void CmdUpdateBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, uint32_t* pData);
		void CmdFillBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data);
		void CmdClearColorImage(VkImage image, VkImageLayout imageLayout, VkClearColorValue* pColor, uint32_t rangeCount, VkImageSubresourceRange* pRanges);
		void CmdClearDepthStencilImage(VkImage image, VkImageLayout imageLayout, VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, VkImageSubresourceRange* pRanges);
		void CmdClearAttachments(uint32_t attachmentCount, VkClearAttachment* pAttachments, uint32_t rectCount, VkClearRect* pRects);
		void CmdResolveImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageResolve* pRegions);
		void CmdSetEvent(VkEvent event, VkPipelineStageFlags stageMask);
		void CmdResetEvent(VkEvent event, VkPipelineStageFlags stageMask);
		void CmdWaitEvents(uint32_t eventCount, VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, VkImageMemoryBarrier* pImageMemoryBarriers);
		void CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, VkImageMemoryBarrier* pImageMemoryBarriers);
		void CmdBeginQuery(VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags);
		void CmdEndQuery(VkQueryPool queryPool, uint32_t query);
		void CmdResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
		void CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query);
		void CmdCopyQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags);
		void CmdPushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, void* pValues);
		void CmdBeginRenderPass(VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents);
		void CmdNextSubpass(VkSubpassContents contents);
		void CmdEndRenderPass();
		void CmdExecuteCommands(uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers);
	};

}