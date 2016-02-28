// This is the main DLL file.
#include <vulkan/vulkan.h>
#include "ManagedVulkan.h"

// Vulkan
VkResult ManagedVulkan::Vulkan::CreateInstance(VkInstanceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkInstance* pInstance)
{

}

VkResult ManagedVulkan::Vulkan::EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{

}

VkResult ManagedVulkan::Vulkan::EnumerateInstanceExtensionProperties(char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
{

}

// VkInstance
void ManagedVulkan::Instance::DestroyInstance(VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Instance::EnumeratePhysicalDevices(uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices)
{

}

PFN_vkVoidFunction ManagedVulkan::Instance::GetInstanceProcAddr(char* pName)
{

}

VkResult ManagedVulkan::Instance::CreateAndroidSurfaceKHR(VkAndroidSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

VkResult ManagedVulkan::Instance::CreateDisplayPlaneSurfaceKHR(VkDisplaySurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

VkResult ManagedVulkan::Instance::CreateMirSurfaceKHR(VkMirSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

void ManagedVulkan::Instance::DestroySurfaceKHR(VkSurfaceKHR surface, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Instance::CreateWaylandSurfaceKHR(VkWaylandSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

VkResult ManagedVulkan::Instance::CreateWin32SurfaceKHR(VkWin32SurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

VkResult ManagedVulkan::Instance::CreateXlibSurfaceKHR(VkXlibSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

VkResult ManagedVulkan::Instance::CreateXcbSurfaceKHR(VkXcbSurfaceCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface)
{

}

VkResult ManagedVulkan::Instance::CreateDebugReportCallbackEXT(VkDebugReportCallbackCreateInfoEXT* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback)
{

}

void ManagedVulkan::Instance::DestroyDebugReportCallbackEXT(VkDebugReportCallbackEXT callback, VkAllocationCallbacks* pAllocator)
{

}

void ManagedVulkan::Instance::DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, char* pLayerPrefix, char* pMessage)
{

}

// VkDevice
PFN_vkVoidFunction ManagedVulkan::Device::GetDeviceProcAddr(char* pName)
{

}

void ManagedVulkan::Device::DestroyDevice(VkAllocationCallbacks* pAllocator)
{

}

void ManagedVulkan::Device::GetDeviceQueue(uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{

}

VkResult ManagedVulkan::Device::DeviceWaitIdle(<TYPE> <NAME>)
{

}

VkResult ManagedVulkan::Device::AllocateMemory(VkMemoryAllocateInfo* pAllocateInfo, VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory)
{

}

void ManagedVulkan::Device::FreeMemory(VkDeviceMemory memory, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::MapMemory(VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData)
{

}

void ManagedVulkan::Device::UnmapMemory(VkDeviceMemory memory)
{

}

VkResult ManagedVulkan::Device::FlushMappedMemoryRanges(uint32_t memoryRangeCount, VkMappedMemoryRange* pMemoryRanges)
{

}

VkResult ManagedVulkan::Device::InvalidateMappedMemoryRanges(uint32_t memoryRangeCount, VkMappedMemoryRange* pMemoryRanges)
{

}

void ManagedVulkan::Device::GetDeviceMemoryCommitment(VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)
{

}

void ManagedVulkan::Device::GetBufferMemoryRequirements(VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)
{

}

VkResult ManagedVulkan::Device::BindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{

}

void ManagedVulkan::Device::GetImageMemoryRequirements(VkImage image, VkMemoryRequirements* pMemoryRequirements)
{

}

VkResult ManagedVulkan::Device::BindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{

}

void ManagedVulkan::Device::GetImageSparseMemoryRequirements(VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{

}

VkResult ManagedVulkan::Device::CreateFence(VkFenceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkFence* pFence)
{

}

void ManagedVulkan::Device::DestroyFence(VkFence fence, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::ResetFences(uint32_t fenceCount, VkFence* pFences)
{

}

VkResult ManagedVulkan::Device::GetFenceStatus(VkFence fence)
{

}

VkResult ManagedVulkan::Device::WaitForFences(uint32_t fenceCount, VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{

}

VkResult ManagedVulkan::Device::CreateSemaphore(VkSemaphoreCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore)
{

}

void ManagedVulkan::Device::DestroySemaphore(VkSemaphore semaphore, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateEvent(VkEventCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkEvent* pEvent)
{

}

void ManagedVulkan::Device::DestroyEvent(VkEvent event, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::GetEventStatus(VkEvent event)
{

}

VkResult ManagedVulkan::Device::SetEvent(VkEvent event)
{

}

VkResult ManagedVulkan::Device::ResetEvent(VkEvent event)
{

}

VkResult ManagedVulkan::Device::CreateQueryPool(VkQueryPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool)
{

}

void ManagedVulkan::Device::DestroyQueryPool(VkQueryPool queryPool, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::GetQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags)
{

}

VkResult ManagedVulkan::Device::CreateBuffer(VkBufferCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer)
{

}

void ManagedVulkan::Device::DestroyBuffer(VkBuffer buffer, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateBufferView(VkBufferViewCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkBufferView* pView)
{

}

void ManagedVulkan::Device::DestroyBufferView(VkBufferView bufferView, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateImage(VkImageCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkImage* pImage)
{

}

void ManagedVulkan::Device::DestroyImage(VkImage image, VkAllocationCallbacks* pAllocator)
{

}

void ManagedVulkan::Device::GetImageSubresourceLayout(VkImage image, VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout)
{

}

VkResult ManagedVulkan::Device::CreateImageView(VkImageViewCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkImageView* pView)
{

}

void ManagedVulkan::Device::DestroyImageView(VkImageView imageView, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateShaderModule(VkShaderModuleCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule)
{

}

void ManagedVulkan::Device::DestroyShaderModule(VkShaderModule shaderModule, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreatePipelineCache(VkPipelineCacheCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache)
{

}

void ManagedVulkan::Device::DestroyPipelineCache(VkPipelineCache pipelineCache, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::GetPipelineCacheData(VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
{

}

VkResult ManagedVulkan::Device::MergePipelineCaches(VkPipelineCache dstCache, uint32_t srcCacheCount, VkPipelineCache* pSrcCaches)
{

}

VkResult ManagedVulkan::Device::CreateGraphicsPipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, VkGraphicsPipelineCreateInfo* pCreateInfos, VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{

}

VkResult ManagedVulkan::Device::CreateComputePipelines(VkPipelineCache pipelineCache, uint32_t createInfoCount, VkComputePipelineCreateInfo* pCreateInfos, VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines)
{

}

void ManagedVulkan::Device::DestroyPipeline(VkPipeline pipeline, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreatePipelineLayout(VkPipelineLayoutCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout)
{

}

void ManagedVulkan::Device::DestroyPipelineLayout(VkPipelineLayout pipelineLayout, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateSampler(VkSamplerCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSampler* pSampler)
{

}

void ManagedVulkan::Device::DestroySampler(VkSampler sampler, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateDescriptorSetLayout(VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout)
{

}

void ManagedVulkan::Device::DestroyDescriptorSetLayout(VkDescriptorSetLayout descriptorSetLayout, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateDescriptorPool(VkDescriptorPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool)
{

}

void ManagedVulkan::Device::DestroyDescriptorPool(VkDescriptorPool descriptorPool, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::ResetDescriptorPool(VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags, <TYPE> <NAME>)
{

}

VkResult ManagedVulkan::Device::AllocateDescriptorSets(VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets)
{

}

VkResult ManagedVulkan::Device::FreeDescriptorSets(VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, VkDescriptorSet* pDescriptorSets)
{

}

void ManagedVulkan::Device::UpdateDescriptorSets(uint32_t descriptorWriteCount, VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, VkCopyDescriptorSet* pDescriptorCopies)
{

}

VkResult ManagedVulkan::Device::CreateFramebuffer(VkFramebufferCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer)
{

}

void ManagedVulkan::Device::DestroyFramebuffer(VkFramebuffer framebuffer, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::CreateRenderPass(VkRenderPassCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass)
{

}

void ManagedVulkan::Device::DestroyRenderPass(VkRenderPass renderPass, VkAllocationCallbacks* pAllocator)
{

}

void ManagedVulkan::Device::GetRenderAreaGranularity(VkRenderPass renderPass, VkExtent2D* pGranularity)
{

}

VkResult ManagedVulkan::Device::CreateCommandPool(VkCommandPoolCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool)
{

}

void ManagedVulkan::Device::DestroyCommandPool(VkCommandPool commandPool, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::ResetCommandPool(VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{

}

VkResult ManagedVulkan::Device::AllocateCommandBuffers(VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers)
{

}

void ManagedVulkan::Device::FreeCommandBuffers(VkCommandPool commandPool, uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers)
{

}

VkResult ManagedVulkan::Device::CreateSharedSwapchainsKHR(uint32_t swapchainCount, VkSwapchainCreateInfoKHR* pCreateInfos, VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains)
{

}

VkResult ManagedVulkan::Device::CreateSwapchainKHR(VkSwapchainCreateInfoKHR* pCreateInfo, VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
{

}

void ManagedVulkan::Device::DestroySwapchainKHR(VkSwapchainKHR swapchain, VkAllocationCallbacks* pAllocator)
{

}

VkResult ManagedVulkan::Device::GetSwapchainImagesKHR(VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages)
{

}

VkResult ManagedVulkan::Device::AcquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex)
{

}

// VkPhysicalDevice
void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceProperties(VkPhysicalDeviceProperties* pProperties)
{

}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceQueueFamilyProperties(uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties)
{

}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceMemoryProperties(VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{

}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFeatures(VkPhysicalDeviceFeatures* pFeatures)
{

}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFormatProperties(VkFormat format, VkFormatProperties* pFormatProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::CreateDevice(VkDeviceCreateInfo* pCreateInfo, VkAllocationCallbacks* pAllocator, VkDevice* pDevice)
{

}

VkResult ManagedVulkan::PhysicalDevice::EnumerateDeviceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::EnumerateDeviceExtensionProperties(char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties)
{

}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPropertiesKHR(uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPlanePropertiesKHR(uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayModePropertiesKHR(VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties)
{

}

VkResult ManagedVulkan::PhysicalDevice::CreateDisplayModeKHR(VkDisplayKHR display, const VkDisplayModeCreateInfoKHR*pCreateInfo, VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayPlaneCapabilitiesKHR(VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities)
{

}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceMirPresentationSupportKHR(uint32_t queueFamilyIndex, MirConnection* connection)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceSupportKHR(uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceCapabilitiesKHR(VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceFormatsKHR(VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats)
{

}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfacePresentModesKHR(VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes)
{

}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceWaylandPresentationSupportKHR(uint32_t queueFamilyIndex, wl_display* display)
{

}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceWin32PresentationSupportKHR(uint32_t queueFamilyIndex)
{

}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceXlibPresentationSupportKHR(uint32_t queueFamilyIndex, Display* dpy, VisualID visualID)
{

}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceXcbPresentationSupportKHR(uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id)
{

}

// VkQueue
VkResult ManagedVulkan::Queue::QueueSubmit(uint32_t submitCount, VkSubmitInfo* pSubmits, VkFence fence)
{

}

VkResult ManagedVulkan::Queue::QueueWaitIdle()
{

}

VkResult ManagedVulkan::Queue::QueueBindSparse(uint32_t bindInfoCount, VkBindSparseInfo* pBindInfo, VkFence fence)
{

}

VkResult ManagedVulkan::Queue::QueuePresentKHR(VkPresentInfoKHR* pPresentInfo)
{

}

// VkCommandBuffer
VkResult ManagedVulkan::CommandBuffer::BeginCommandBuffer(VkCommandBufferBeginInfo* pBeginInfo)
{

}

VkResult ManagedVulkan::CommandBuffer::EndCommandBuffer()
{

}

VkResult ManagedVulkan::CommandBuffer::ResetCommandBuffer(VkCommandBufferResetFlags flags)
{

}

void ManagedVulkan::CommandBuffer::CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline)
{

}

void ManagedVulkan::CommandBuffer::CmdSetViewport(uint32_t firstViewport, uint32_t viewportCount, VkViewport* pViewports)
{

}

void ManagedVulkan::CommandBuffer::CmdSetScissor(uint32_t firstScissor, uint32_t scissorCount, VkRect2D* pScissors)
{

}

void ManagedVulkan::CommandBuffer::CmdSetLineWidth(float lineWidth)
{

}

void ManagedVulkan::CommandBuffer::CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{

}

void ManagedVulkan::CommandBuffer::CmdSetBlendConstants(float blendConstants[4])
{

}

void ManagedVulkan::CommandBuffer::CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds)
{

}

void ManagedVulkan::CommandBuffer::CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, uint32_t compareMask)
{

}

void ManagedVulkan::CommandBuffer::CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, uint32_t writeMask)
{

}

void ManagedVulkan::CommandBuffer::CmdSetStencilReference(VkStencilFaceFlags faceMask, uint32_t reference)
{

}

void ManagedVulkan::CommandBuffer::CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, uint32_t* pDynamicOffsets)
{

}

void ManagedVulkan::CommandBuffer::CmdBindIndexBuffer(VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType)
{

}

void ManagedVulkan::CommandBuffer::CmdBindVertexBuffers(uint32_t firstBinding, uint32_t bindingCount, VkBuffer* pBuffers, VkDeviceSize* pOffsets)
{

}

void ManagedVulkan::CommandBuffer::CmdDraw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance)
{

}

void ManagedVulkan::CommandBuffer::CmdDrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance)
{

}

void ManagedVulkan::CommandBuffer::CmdDrawIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{

}

void ManagedVulkan::CommandBuffer::CmdDrawIndexedIndirect(VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{

}

void ManagedVulkan::CommandBuffer::CmdDispatch(uint32_t x, uint32_t y, uint32_t z)
{

}

void ManagedVulkan::CommandBuffer::CmdDispatchIndirect(VkBuffer buffer, VkDeviceSize offset)
{

}

void ManagedVulkan::CommandBuffer::CmdCopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, VkBufferCopy* pRegions)
{

}

void ManagedVulkan::CommandBuffer::CmdCopyImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageCopy* pRegions)
{

}

void ManagedVulkan::CommandBuffer::CmdBlitImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageBlit* pRegions, VkFilter filter)
{

}

void ManagedVulkan::CommandBuffer::CmdCopyBufferToImage(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkBufferImageCopy* pRegions)
{

}

void ManagedVulkan::CommandBuffer::CmdCopyImageToBuffer(VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, VkBufferImageCopy* pRegions)
{

}

void ManagedVulkan::CommandBuffer::CmdUpdateBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, uint32_t* pData)
{

}

void ManagedVulkan::CommandBuffer::CmdFillBuffer(VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{

}

void ManagedVulkan::CommandBuffer::CmdClearColorImage(VkImage image, VkImageLayout imageLayout, VkClearColorValue* pColor, uint32_t rangeCount, VkImageSubresourceRange* pRanges)
{

}

void ManagedVulkan::CommandBuffer::CmdClearDepthStencilImage(VkImage image, VkImageLayout imageLayout, VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, VkImageSubresourceRange* pRanges)
{

}

void ManagedVulkan::CommandBuffer::CmdClearAttachments(uint32_t attachmentCount, VkClearAttachment* pAttachments, uint32_t rectCount, VkClearRect* pRects)
{

}

void ManagedVulkan::CommandBuffer::CmdResolveImage(VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, VkImageResolve* pRegions)
{

}

void ManagedVulkan::CommandBuffer::CmdSetEvent(VkEvent event, VkPipelineStageFlags stageMask)
{

}

void ManagedVulkan::CommandBuffer::CmdResetEvent(VkEvent event, VkPipelineStageFlags stageMask)
{

}

void ManagedVulkan::CommandBuffer::CmdWaitEvents(uint32_t eventCount, VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, VkImageMemoryBarrier* pImageMemoryBarriers)
{

}

void ManagedVulkan::CommandBuffer::CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, VkImageMemoryBarrier* pImageMemoryBarriers)
{

}

void ManagedVulkan::CommandBuffer::CmdBeginQuery(VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags)
{

}

void ManagedVulkan::CommandBuffer::CmdEndQuery(VkQueryPool queryPool, uint32_t query)
{

}

void ManagedVulkan::CommandBuffer::CmdResetQueryPool(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount)
{

}

void ManagedVulkan::CommandBuffer::CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query)
{

}

void ManagedVulkan::CommandBuffer::CmdCopyQueryPoolResults(VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags)
{

}

void ManagedVulkan::CommandBuffer::CmdPushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, void* pValues)
{

}

void ManagedVulkan::CommandBuffer::CmdBeginRenderPass(VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents)
{

}

void ManagedVulkan::CommandBuffer::CmdNextSubpass(VkSubpassContents contents)
{

}

void ManagedVulkan::CommandBuffer::CmdEndRenderPass()
{

}

void ManagedVulkan::CommandBuffer::CmdExecuteCommands(uint32_t commandBufferCount, VkCommandBuffer* pCommandBuffers)
{

}

