// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan 
{
	// INTERFACES
	// Vulkan
	public interface class IVulkan
	{
	public:
		VkResult CreateInstance(InstanceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Instance^ pInstance);
		VkResult EnumerateInstanceLayerProperties(out array<LayerProperties^>^ pProperties);
		VkResult EnumerateInstanceExtensionProperties(String^ pLayerName, out array<ExtensionProperties^>^ pProperties);
	};

	// VkInstance
	public interface class IVkInstance
	{
	private:
		VkInstance mInst;
	public:
		void DestroyInstance(AllocationCallbacks^ pAllocator);
		VkResult EnumeratePhysicalDevices(out array<PhysicalDevice^>^ pPhysicalDevices);
		PFN_vkVoidFunction^ GetInstanceProcAddr(String^ pName);
		VkResult CreateDisplayPlaneSurfaceKHR(DisplaySurfaceCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SurfaceKHR^ pSurface);
		void DestroySurfaceKHR(SurfaceKHR^ surface, AllocationCallbacks^ pAllocator);
		VkResult CreateWin32SurfaceKHR(Win32SurfaceCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SurfaceKHR^ pSurface);
		VkResult CreateDebugReportCallbackEXT(DebugReportCallbackCreateInfoEXT^ pCreateInfo, AllocationCallbacks^ pAllocator, out DebugReportCallbackEXT^ pCallback);
		void DestroyDebugReportCallbackEXT(DebugReportCallbackEXT^ callback, AllocationCallbacks^ pAllocator);
		void DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, UInt64 object, IntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage);
	};

	// VkDevice
	public interface class IVkDevice
	{
	private:
		VkDevice mInst;
	public:
		PFN_vkVoidFunction^ GetDeviceProcAddr(String^ pName);
		void DestroyDevice(AllocationCallbacks^ pAllocator);
		void GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, Queue^ pQueue);
		VkResult DeviceWaitIdle();
		VkResult AllocateMemory(MemoryAllocateInfo^ pAllocateInfo, AllocationCallbacks^ pAllocator, DeviceMemory^ pMemory);
		void FreeMemory(DeviceMemory^ memory, AllocationCallbacks^ pAllocator);
		VkResult MapMemory(DeviceMemory^ memory, UInt64 offset, UInt64 size, VkMemoryMapFlags flags, ref IntPtr ppData);
		void UnmapMemory(DeviceMemory^ memory);
		VkResult FlushMappedMemoryRanges(array<MappedMemoryRange^>^ pMemoryRanges);
		VkResult InvalidateMappedMemoryRanges(array<MappedMemoryRange^>^ pMemoryRanges);
		void GetDeviceMemoryCommitment(DeviceMemory^ memory, ref UInt64 pCommittedMemoryInBytes);
		void GetBufferMemoryRequirements(Buffer^ buffer, MemoryRequirements^ pMemoryRequirements);
		VkResult BindBufferMemory(Buffer^ buffer, DeviceMemory^ memory, UInt64 memoryOffset);
		void GetImageMemoryRequirements(Image^ image, MemoryRequirements^ pMemoryRequirements);
		VkResult BindImageMemory(Image^ image, DeviceMemory^ memory, UInt64 memoryOffset);
		void GetImageSparseMemoryRequirements(Image^ image, array<SparseImageMemoryRequirements^>^ pSparseMemoryRequirements);
		VkResult CreateFence(FenceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Fence^ pFence);
		void DestroyFence(Fence^ fence, AllocationCallbacks^ pAllocator);
		VkResult ResetFences(UInt32 fenceCount, Fence^ pFences);
		VkResult GetFenceStatus(Fence^ fence);
		VkResult WaitForFences(UInt32 fenceCount, Fence^ pFences, bool waitAll, UInt64 timeout);
		VkResult CreateSemaphore(SemaphoreCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Semaphore^ pSemaphore);
		void DestroySemaphore(Semaphore^ semaphore, AllocationCallbacks^ pAllocator);
		VkResult CreateEvent(EventCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Event^ pEvent);
		void DestroyEvent(Event^ event, AllocationCallbacks^ pAllocator);
		VkResult GetEventStatus(Event^ event);
		VkResult SetEvent(Event^ event);
		VkResult ResetEvent(Event^ event);
		VkResult CreateQueryPool(QueryPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out QueryPool^ pQueryPool);
		void DestroyQueryPool(QueryPool^ queryPool, AllocationCallbacks^ pAllocator);
		VkResult GetQueryPoolResults(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, IntPtr dataSize, IntPtr pData, UInt64 stride, VkQueryResultFlags flags);
		VkResult CreateBuffer(BufferCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Buffer^ pBuffer);
		void DestroyBuffer(Buffer^ buffer, AllocationCallbacks^ pAllocator);
		VkResult CreateBufferView(BufferViewCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out BufferView^ pView);
		void DestroyBufferView(BufferView^ bufferView, AllocationCallbacks^ pAllocator);
		VkResult CreateImage(ImageCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Image^ pImage);
		void DestroyImage(Image^ image, AllocationCallbacks^ pAllocator);
		void GetImageSubresourceLayout(Image^ image, ImageSubresource^ pSubresource, SubresourceLayout^ pLayout);
		VkResult CreateImageView(ImageViewCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out ImageView^ pView);
		void DestroyImageView(ImageView^ imageView, AllocationCallbacks^ pAllocator);
		VkResult CreateShaderModule(ShaderModuleCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out ShaderModule^ pShaderModule);
		void DestroyShaderModule(ShaderModule^ shaderModule, AllocationCallbacks^ pAllocator);
		VkResult CreatePipelineCache(PipelineCacheCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out PipelineCache^ pPipelineCache);
		void DestroyPipelineCache(PipelineCache^ pipelineCache, AllocationCallbacks^ pAllocator);
		VkResult GetPipelineCacheData(PipelineCache^ pipelineCache, ref IntPtr pDataSize, IntPtr pData);
		VkResult MergePipelineCaches(PipelineCache^ dstCache, array<PipelineCache^>^ pSrcCaches);
		VkResult CreateGraphicsPipelines(PipelineCache^ pipelineCache, array<GraphicsPipelineCreateInfo^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<Pipeline^>^ pPipelines);
		VkResult CreateComputePipelines(PipelineCache^ pipelineCache, array<ComputePipelineCreateInfo^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<Pipeline^>^ pPipelines);
		void DestroyPipeline(Pipeline^ pipeline, AllocationCallbacks^ pAllocator);
		VkResult CreatePipelineLayout(PipelineLayoutCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out PipelineLayout^ pPipelineLayout);
		void DestroyPipelineLayout(PipelineLayout^ pipelineLayout, AllocationCallbacks^ pAllocator);
		VkResult CreateSampler(SamplerCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Sampler^ pSampler);
		void DestroySampler(Sampler^ sampler, AllocationCallbacks^ pAllocator);
		VkResult CreateDescriptorSetLayout(DescriptorSetLayoutCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out DescriptorSetLayout^ pSetLayout);
		void DestroyDescriptorSetLayout(DescriptorSetLayout^ descriptorSetLayout, AllocationCallbacks^ pAllocator);
		VkResult CreateDescriptorPool(DescriptorPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out DescriptorPool^ pDescriptorPool);
		void DestroyDescriptorPool(DescriptorPool^ descriptorPool, AllocationCallbacks^ pAllocator);
		VkResult ResetDescriptorPool(DescriptorPool^ descriptorPool, VkDescriptorPoolResetFlags flags);
		VkResult AllocateDescriptorSets(DescriptorSetAllocateInfo^ pAllocateInfo, DescriptorSet^ pDescriptorSets);
		VkResult FreeDescriptorSets(DescriptorPool^ descriptorPool, UInt32 descriptorSetCount, DescriptorSet^ pDescriptorSets);
		void UpdateDescriptorSets(UInt32 descriptorWriteCount, WriteDescriptorSet^ pDescriptorWrites, UInt32 descriptorCopyCount, CopyDescriptorSet^ pDescriptorCopies);
		VkResult CreateFramebuffer(FramebufferCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Framebuffer^ pFramebuffer);
		void DestroyFramebuffer(Framebuffer^ framebuffer, AllocationCallbacks^ pAllocator);
		VkResult CreateRenderPass(RenderPassCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out RenderPass^ pRenderPass);
		void DestroyRenderPass(RenderPass^ renderPass, AllocationCallbacks^ pAllocator);
		void GetRenderAreaGranularity(RenderPass^ renderPass, Extent2D^ pGranularity);
		VkResult CreateCommandPool(CommandPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out CommandPool^ pCommandPool);
		void DestroyCommandPool(CommandPool^ commandPool, AllocationCallbacks^ pAllocator);
		VkResult ResetCommandPool(CommandPool^ commandPool, VkCommandPoolResetFlags flags);
		VkResult AllocateCommandBuffers(CommandBufferAllocateInfo^ pAllocateInfo, CommandBuffer^ pCommandBuffers);
		void FreeCommandBuffers(CommandPool^ commandPool, array<CommandBuffer^>^ pCommandBuffers);
		VkResult CreateSharedSwapchainsKHR(array<SwapchainCreateInfoKHR^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<SwapchainKHR^>^ pSwapchains);
		VkResult CreateSwapchainKHR(SwapchainCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SwapchainKHR^ pSwapchain);
		void DestroySwapchainKHR(SwapchainKHR^ swapchain, AllocationCallbacks^ pAllocator);
		VkResult GetSwapchainImagesKHR(SwapchainKHR^ swapchain, array<Image^>^ pSwapchainImages);
		VkResult AcquireNextImageKHR(SwapchainKHR^ swapchain, UInt64 timeout, Semaphore^ semaphore, Fence^ fence, ref UInt32 pImageIndex);
	};

	// VkPhysicalDevice
	public interface class IVkPhysicalDevice
	{
	private:
		VkPhysicalDevice mInst;
	public:
		void GetPhysicalDeviceProperties(PhysicalDeviceProperties^ pProperties);
		void GetPhysicalDeviceQueueFamilyProperties(array<QueueFamilyProperties^>^ pQueueFamilyProperties);
		void GetPhysicalDeviceMemoryProperties(PhysicalDeviceMemoryProperties^ pMemoryProperties);
		void GetPhysicalDeviceFeatures(PhysicalDeviceFeatures^ pFeatures);
		void GetPhysicalDeviceFormatProperties(VkFormat format, FormatProperties^ pFormatProperties);
		VkResult GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, ImageFormatProperties^ pImageFormatProperties);
		VkResult CreateDevice(DeviceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Device^ pDevice);
		VkResult EnumerateDeviceLayerProperties(out array<LayerProperties^>^ pProperties);
		VkResult EnumerateDeviceExtensionProperties(String^ pLayerName, out array<ExtensionProperties^>^ pProperties);
		void GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, array<SparseImageFormatProperties^>^ pProperties);
		VkResult GetPhysicalDeviceDisplayPropertiesKHR(array<DisplayPropertiesKHR^>^ pProperties);
		VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR(ref UInt32 pPropertyCount, DisplayPlanePropertiesKHR^ pProperties);
		VkResult GetDisplayPlaneSupportedDisplaysKHR(UInt32 planeIndex, ref UInt32 pDisplayCount, DisplayKHR^ pDisplays);
		VkResult GetDisplayModePropertiesKHR(DisplayKHR^ display, array<DisplayModePropertiesKHR^>^ pProperties);
		VkResult CreateDisplayModeKHR(DisplayKHR^ display, DisplayModeCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out DisplayModeKHR^ pMode);
		VkResult GetDisplayPlaneCapabilitiesKHR(DisplayModeKHR^ mode, UInt32 planeIndex, DisplayPlaneCapabilitiesKHR^ pCapabilities);
		VkResult GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, SurfaceKHR^ surface, ref bool pSupported);
		VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR^ surface, SurfaceCapabilitiesKHR^ pSurfaceCapabilities);
		VkResult GetPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR^ surface, array<SurfaceFormatKHR^>^ pSurfaceFormats);
		VkResult GetPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR^ surface, array<VkPresentModeKHR>^ pPresentModes);
		bool GetPhysicalDeviceWin32PresentationSupportKHR(UInt32 queueFamilyIndex);
	};

	// VkQueue
	public interface class IVkQueue
	{
	private:
		VkQueue mInst;
	public:
		VkResult QueueSubmit(UInt32 submitCount, SubmitInfo^ pSubmits, Fence^ fence);
		VkResult QueueWaitIdle();
		VkResult QueueBindSparse(UInt32 bindInfoCount, BindSparseInfo^ pBindInfo, Fence^ fence);
		VkResult QueuePresentKHR(PresentInfoKHR^ pPresentInfo);
	};

	// VkCommandBuffer
	public interface class IVkCommandBuffer
	{
	private:
		VkCommandBuffer mInst;
	public:
		VkResult BeginCommandBuffer(CommandBufferBeginInfo^ pBeginInfo);
		VkResult EndCommandBuffer();
		VkResult ResetCommandBuffer(VkCommandBufferResetFlags flags);
		void CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, Pipeline^ pipeline);
		void CmdSetViewport(UInt32 firstViewport, UInt32 viewportCount, array<Viewport^>^ pViewports);
		void CmdSetScissor(UInt32 firstScissor, UInt32 scissorCount, array<Rect2D^>^ pScissors);
		void CmdSetLineWidth(float lineWidth);
		void CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
		void CmdSetBlendConstants(float blendConstants[4]);
		void CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds);
		void CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, UInt32 compareMask);
		void CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, UInt32 writeMask);
		void CmdSetStencilReference(VkStencilFaceFlags faceMask, UInt32 reference);
		void CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, PipelineLayout^ layout, UInt32 firstSet, array<DescriptorSet^>^ pDescriptorSets, array<UInt32>^ pDynamicOffsets);
		void CmdBindIndexBuffer(Buffer^ buffer, UInt64 offset, VkIndexType indexType);
		void CmdBindVertexBuffers(UInt32 firstBinding, UInt32 bindingCount, array<Buffer^>^ pBuffers, array<UInt64>^ pOffsets);
		void CmdDraw(UInt32 vertexCount, UInt32 instanceCount, UInt32 firstVertex, UInt32 firstInstance);
		void CmdDrawIndexed(UInt32 indexCount, UInt32 instanceCount, UInt32 firstIndex, Int32 vertexOffset, UInt32 firstInstance);
		void CmdDrawIndirect(Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride);
		void CmdDrawIndexedIndirect(Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride);
		void CmdDispatch(UInt32 x, UInt32 y, UInt32 z);
		void CmdDispatchIndirect(Buffer^ buffer, UInt64 offset);
		void CmdCopyBuffer(Buffer^ srcBuffer, Buffer^ dstBuffer, array<BufferCopy^>^ pRegions);
		void CmdCopyImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageCopy^>^ pRegions);
		void CmdBlitImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageBlit^>^ pRegions, VkFilter filter);
		void CmdCopyBufferToImage(Buffer^ srcBuffer, Image^ dstImage, VkImageLayout dstImageLayout, array<BufferImageCopy^>^ pRegions);
		void CmdCopyImageToBuffer(Image^ srcImage, VkImageLayout srcImageLayout, Buffer^ dstBuffer, array<BufferImageCopy^>^ pRegions);
		void CmdUpdateBuffer(Buffer^ dstBuffer, UInt64 dstOffset, UInt64 dataSize, ref UInt32 pData);
		void CmdFillBuffer(Buffer^ dstBuffer, UInt64 dstOffset, UInt64 size, UInt32 data);
		void CmdClearColorImage(Image^ image, VkImageLayout imageLayout, VkClearColorValue* pColor, array<ImageSubresourceRange^>^ pRanges);
		void CmdClearDepthStencilImage(Image^ image, VkImageLayout imageLayout, ClearDepthStencilValue^ pDepthStencil, array<ImageSubresourceRange^>^ pRanges);
		void CmdClearAttachments(array<ClearAttachment^>^ pAttachments, array<ClearRect^>^ pRects);
		void CmdResolveImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageResolve^>^ pRegions);
		void CmdSetEvent(Event^ event, VkPipelineStageFlags stageMask);
		void CmdResetEvent(Event^ event, VkPipelineStageFlags stageMask);
		void CmdWaitEvents(array<Event^>^ pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, array<MemoryBarrier^>^ pMemoryBarriers, array<BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ImageMemoryBarrier^>^ pImageMemoryBarriers);
		void CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, array<MemoryBarrier^>^ pMemoryBarriers, array<BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ImageMemoryBarrier^>^ pImageMemoryBarriers);
		void CmdBeginQuery(QueryPool^ queryPool, UInt32 query, VkQueryControlFlags flags);
		void CmdEndQuery(QueryPool^ queryPool, UInt32 query);
		void CmdResetQueryPool(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount);
		void CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, QueryPool^ queryPool, UInt32 query);
		void CmdCopyQueryPoolResults(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, Buffer^ dstBuffer, UInt64 dstOffset, UInt64 stride, VkQueryResultFlags flags);
		void CmdPushConstants(PipelineLayout^ layout, VkShaderStageFlags stageFlags, UInt32 offset, UInt32 size, IntPtr pValues);
		void CmdBeginRenderPass(RenderPassBeginInfo^ pRenderPassBegin, VkSubpassContents contents);
		void CmdNextSubpass(VkSubpassContents contents);
		void CmdEndRenderPass();
		void CmdExecuteCommands(array<CommandBuffer^>^ pCommandBuffers);
	};

}