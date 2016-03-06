// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkStructs.h"

using namespace System;

namespace ManagedVulkan 
{
	// INTERFACES
	public ref class Vulkan
	{
	public:
		ManagedVulkan::VkResult CreateInstance(ManagedVulkan::InstanceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Instance% pInstance);
		ManagedVulkan::VkResult EnumerateInstanceLayerProperties([Out] array<ManagedVulkan::LayerProperties^>^% pProperties);
		ManagedVulkan::VkResult EnumerateInstanceExtensionProperties(String^ pLayerName, [Out] array<ManagedVulkan::ExtensionProperties^>^% pProperties);
	};

	public ref class Instance
	{
	internal:
		VkInstance mHandle;
	public:
		void DestroyInstance(ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult EnumeratePhysicalDevices([Out] array<ManagedVulkan::PhysicalDevice>^% pPhysicalDevices);
		ManagedVulkan::PFN_vkVoidFunction^ GetInstanceProcAddr(String^ pName);
		ManagedVulkan::VkResult CreateDisplayPlaneSurfaceKHR(ManagedVulkan::DisplaySurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface);
		void DestroySurfaceKHR(ManagedVulkan::SurfaceKHR^ surface, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateWin32SurfaceKHR(ManagedVulkan::Win32SurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface);
		ManagedVulkan::VkResult CreateDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackCreateInfoEXT^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DebugReportCallbackEXT^% pCallback);
		void DestroyDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackEXT^ callback, ManagedVulkan::AllocationCallbacks^ pAllocator);
		void DebugReportMessageEXT(UInt32 flags, ManagedVulkan::VkDebugReportObjectTypeEXT objectType, UInt64 object, IntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage);
	};

	public ref class Device
	{
	internal:
		VkDevice mHandle;
	public:
		ManagedVulkan::PFN_vkVoidFunction^ GetDeviceProcAddr(String^ pName);
		void DestroyDevice(ManagedVulkan::AllocationCallbacks^ pAllocator);
		void GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, [Out] ManagedVulkan::Queue% pQueue);
		ManagedVulkan::VkResult DeviceWaitIdle();
		ManagedVulkan::VkResult AllocateMemory(ManagedVulkan::MemoryAllocateInfo^ pAllocateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, ManagedVulkan::DeviceMemory^ pMemory);
		void FreeMemory(ManagedVulkan::DeviceMemory^ memory, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult MapMemory(ManagedVulkan::DeviceMemory^ memory, UInt64 offset, UInt64 size, UInt32 flags, array<IntPtr> ppData);
		void UnmapMemory(ManagedVulkan::DeviceMemory^ memory);
		ManagedVulkan::VkResult FlushMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges);
		ManagedVulkan::VkResult InvalidateMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges);
		void GetDeviceMemoryCommitment(ManagedVulkan::DeviceMemory^ memory, UInt64 pCommittedMemoryInBytes);
		void GetBufferMemoryRequirements(ManagedVulkan::Buffer^ buffer, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements);
		ManagedVulkan::VkResult BindBufferMemory(ManagedVulkan::Buffer^ buffer, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset);
		void GetImageMemoryRequirements(ManagedVulkan::Image^ image, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements);
		ManagedVulkan::VkResult BindImageMemory(ManagedVulkan::Image^ image, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset);
		void GetImageSparseMemoryRequirements(ManagedVulkan::Image^ image, [Out] array<ManagedVulkan::SparseImageMemoryRequirements^>^% pSparseMemoryRequirements);
		ManagedVulkan::VkResult CreateFence(ManagedVulkan::FenceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Fence^% pFence);
		void DestroyFence(ManagedVulkan::Fence^ fence, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult ResetFences(array<ManagedVulkan::Fence^>^ pFences);
		ManagedVulkan::VkResult GetFenceStatus(ManagedVulkan::Fence^ fence);
		ManagedVulkan::VkResult WaitForFences(array<ManagedVulkan::Fence^>^ pFences, bool waitAll, UInt64 timeout);
		ManagedVulkan::VkResult CreateSemaphore(ManagedVulkan::SemaphoreCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Semaphore^% pSemaphore);
		void DestroySemaphore(ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateEvent(ManagedVulkan::EventCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Event^% pEvent);
		void DestroyEvent(ManagedVulkan::Event^ event, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult GetEventStatus(ManagedVulkan::Event^ event);
		ManagedVulkan::VkResult SetEvent(ManagedVulkan::Event^ event);
		ManagedVulkan::VkResult ResetEvent(ManagedVulkan::Event^ event);
		ManagedVulkan::VkResult CreateQueryPool(ManagedVulkan::QueryPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::QueryPool^% pQueryPool);
		void DestroyQueryPool(ManagedVulkan::QueryPool^ queryPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult GetQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, IntPtr dataSize, IntPtr pData, UInt64 stride, UInt32 flags);
		ManagedVulkan::VkResult CreateBuffer(ManagedVulkan::BufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Buffer^% pBuffer);
		void DestroyBuffer(ManagedVulkan::Buffer^ buffer, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateBufferView(ManagedVulkan::BufferViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::BufferView^% pView);
		void DestroyBufferView(ManagedVulkan::BufferView^ bufferView, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateImage(ManagedVulkan::ImageCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Image^% pImage);
		void DestroyImage(ManagedVulkan::Image^ image, ManagedVulkan::AllocationCallbacks^ pAllocator);
		void GetImageSubresourceLayout(ManagedVulkan::Image^ image, ManagedVulkan::ImageSubresource^ pSubresource, [Out] ManagedVulkan::SubresourceLayout^% pLayout);
		ManagedVulkan::VkResult CreateImageView(ManagedVulkan::ImageViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ImageView^% pView);
		void DestroyImageView(ManagedVulkan::ImageView^ imageView, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateShaderModule(ManagedVulkan::ShaderModuleCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ShaderModule^% pShaderModule);
		void DestroyShaderModule(ManagedVulkan::ShaderModule^ shaderModule, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreatePipelineCache(ManagedVulkan::PipelineCacheCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineCache^% pPipelineCache);
		void DestroyPipelineCache(ManagedVulkan::PipelineCache^ pipelineCache, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult GetPipelineCacheData(ManagedVulkan::PipelineCache^ pipelineCache, IntPtr pDataSize, IntPtr pData);
		ManagedVulkan::VkResult MergePipelineCaches(ManagedVulkan::PipelineCache^ dstCache, array<ManagedVulkan::PipelineCache^>^ pSrcCaches);
		ManagedVulkan::VkResult CreateGraphicsPipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::GraphicsPipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines);
		ManagedVulkan::VkResult CreateComputePipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::ComputePipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines);
		void DestroyPipeline(ManagedVulkan::Pipeline^ pipeline, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreatePipelineLayout(ManagedVulkan::PipelineLayoutCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineLayout^% pPipelineLayout);
		void DestroyPipelineLayout(ManagedVulkan::PipelineLayout^ pipelineLayout, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateSampler(ManagedVulkan::SamplerCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Sampler^% pSampler);
		void DestroySampler(ManagedVulkan::Sampler^ sampler, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateDescriptorSetLayout(ManagedVulkan::DescriptorSetLayoutCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DescriptorSetLayout^% pSetLayout);
		void DestroyDescriptorSetLayout(ManagedVulkan::DescriptorSetLayout^ descriptorSetLayout, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateDescriptorPool(ManagedVulkan::DescriptorPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DescriptorPool^% pDescriptorPool);
		void DestroyDescriptorPool(ManagedVulkan::DescriptorPool^ descriptorPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult ResetDescriptorPool(ManagedVulkan::DescriptorPool^ descriptorPool, UInt32 flags);
		ManagedVulkan::VkResult AllocateDescriptorSets(ManagedVulkan::DescriptorSetAllocateInfo^ pAllocateInfo, ManagedVulkan::DescriptorSet^ pDescriptorSets);
		ManagedVulkan::VkResult FreeDescriptorSets(ManagedVulkan::DescriptorPool^ descriptorPool, UInt32 descriptorSetCount, ManagedVulkan::DescriptorSet^ pDescriptorSets);
		void UpdateDescriptorSets(UInt32 descriptorWriteCount, ManagedVulkan::WriteDescriptorSet^ pDescriptorWrites, UInt32 descriptorCopyCount, ManagedVulkan::CopyDescriptorSet^ pDescriptorCopies);
		ManagedVulkan::VkResult CreateFramebuffer(ManagedVulkan::FramebufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Framebuffer^% pFramebuffer);
		void DestroyFramebuffer(ManagedVulkan::Framebuffer^ framebuffer, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult CreateRenderPass(ManagedVulkan::RenderPassCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::RenderPass^% pRenderPass);
		void DestroyRenderPass(ManagedVulkan::RenderPass^ renderPass, ManagedVulkan::AllocationCallbacks^ pAllocator);
		void GetRenderAreaGranularity(ManagedVulkan::RenderPass^ renderPass, [Out] ManagedVulkan::Extent2D^% pGranularity);
		ManagedVulkan::VkResult CreateCommandPool(ManagedVulkan::CommandPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::CommandPool^% pCommandPool);
		void DestroyCommandPool(ManagedVulkan::CommandPool^ commandPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult ResetCommandPool(ManagedVulkan::CommandPool^ commandPool, UInt32 flags);
		ManagedVulkan::VkResult AllocateCommandBuffers(ManagedVulkan::CommandBufferAllocateInfo^ pAllocateInfo, ManagedVulkan::CommandBuffer pCommandBuffers);
		void FreeCommandBuffers(ManagedVulkan::CommandPool^ commandPool, array<ManagedVulkan::CommandBuffer>^ pCommandBuffers);
		ManagedVulkan::VkResult CreateSharedSwapchainsKHR(array<ManagedVulkan::SwapchainCreateInfoKHR^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::SwapchainKHR^>^% pSwapchains);
		ManagedVulkan::VkResult CreateSwapchainKHR(ManagedVulkan::SwapchainCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SwapchainKHR^% pSwapchain);
		void DestroySwapchainKHR(ManagedVulkan::SwapchainKHR^ swapchain, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::VkResult GetSwapchainImagesKHR(ManagedVulkan::SwapchainKHR^ swapchain, [Out] array<ManagedVulkan::Image^>^% pSwapchainImages);
		ManagedVulkan::VkResult AcquireNextImageKHR(ManagedVulkan::SwapchainKHR^ swapchain, UInt64 timeout, ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::Fence^ fence, UInt32 pImageIndex);
	};

	public ref class PhysicalDevice
	{
	internal:
		VkPhysicalDevice mHandle;
	public:
		void GetPhysicalDeviceProperties([Out] ManagedVulkan::PhysicalDeviceProperties^% pProperties);
		void GetPhysicalDeviceQueueFamilyProperties([Out] array<ManagedVulkan::QueueFamilyProperties^>^% pQueueFamilyProperties);
		void GetPhysicalDeviceMemoryProperties([Out] ManagedVulkan::PhysicalDeviceMemoryProperties^% pMemoryProperties);
		void GetPhysicalDeviceFeatures([Out] ManagedVulkan::PhysicalDeviceFeatures^% pFeatures);
		void GetPhysicalDeviceFormatProperties(ManagedVulkan::VkFormat format, [Out] ManagedVulkan::FormatProperties^% pFormatProperties);
		ManagedVulkan::VkResult GetPhysicalDeviceImageFormatProperties(ManagedVulkan::VkFormat format, ManagedVulkan::VkImageType type, ManagedVulkan::VkImageTiling tiling, UInt32 usage, UInt32 flags, [Out] ManagedVulkan::ImageFormatProperties^% pImageFormatProperties);
		ManagedVulkan::VkResult CreateDevice(ManagedVulkan::DeviceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Device% pDevice);
		ManagedVulkan::VkResult EnumerateDeviceLayerProperties([Out] array<ManagedVulkan::LayerProperties^>^% pProperties);
		ManagedVulkan::VkResult EnumerateDeviceExtensionProperties(String^ pLayerName, [Out] array<ManagedVulkan::ExtensionProperties^>^% pProperties);
		void GetPhysicalDeviceSparseImageFormatProperties(ManagedVulkan::VkFormat format, ManagedVulkan::VkImageType type, ManagedVulkan::VkSampleCountFlagBits samples, UInt32 usage, ManagedVulkan::VkImageTiling tiling, [Out] array<ManagedVulkan::SparseImageFormatProperties^>^% pProperties);
		ManagedVulkan::VkResult GetPhysicalDeviceDisplayPropertiesKHR([Out] array<ManagedVulkan::DisplayPropertiesKHR^>^% pProperties);
		ManagedVulkan::VkResult GetPhysicalDeviceDisplayPlanePropertiesKHR([Out] array<ManagedVulkan::DisplayPlanePropertiesKHR^>^% pProperties);
		ManagedVulkan::VkResult GetDisplayPlaneSupportedDisplaysKHR(UInt32 planeIndex, [Out] array<ManagedVulkan::DisplayKHR^>^% pDisplays);
		ManagedVulkan::VkResult GetDisplayModePropertiesKHR(ManagedVulkan::DisplayKHR^ display, [Out] array<ManagedVulkan::DisplayModePropertiesKHR^>^% pProperties);
		ManagedVulkan::VkResult CreateDisplayModeKHR(ManagedVulkan::DisplayKHR^ display,  pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DisplayModeKHR^% pMode);
		ManagedVulkan::VkResult GetDisplayPlaneCapabilitiesKHR(ManagedVulkan::DisplayModeKHR^ mode, UInt32 planeIndex, [Out] ManagedVulkan::DisplayPlaneCapabilitiesKHR^% pCapabilities);
		ManagedVulkan::VkResult GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, ManagedVulkan::SurfaceKHR^ surface, bool pSupported);
		ManagedVulkan::VkResult GetPhysicalDeviceSurfaceCapabilitiesKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] ManagedVulkan::SurfaceCapabilitiesKHR^% pSurfaceCapabilities);
		ManagedVulkan::VkResult GetPhysicalDeviceSurfaceFormatsKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] array<ManagedVulkan::SurfaceFormatKHR^>^% pSurfaceFormats);
		ManagedVulkan::VkResult GetPhysicalDeviceSurfacePresentModesKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] array<ManagedVulkan::VkPresentModeKHR>^% pPresentModes);
		bool GetPhysicalDeviceWin32PresentationSupportKHR(UInt32 queueFamilyIndex);
	};

	public ref class Queue
	{
	internal:
		VkQueue mHandle;
	public:
		ManagedVulkan::VkResult QueueSubmit(array<ManagedVulkan::SubmitInfo^>^ pSubmits, ManagedVulkan::Fence^ fence);
		ManagedVulkan::VkResult QueueWaitIdle();
		ManagedVulkan::VkResult QueueBindSparse(array<ManagedVulkan::BindSparseInfo^>^ pBindInfo, ManagedVulkan::Fence^ fence);
		ManagedVulkan::VkResult QueuePresentKHR(ManagedVulkan::PresentInfoKHR^ pPresentInfo);
	};

	public ref class CommandBuffer
	{
	internal:
		VkCommandBuffer mHandle;
	public:
		ManagedVulkan::VkResult BeginCommandBuffer(ManagedVulkan::CommandBufferBeginInfo^ pBeginInfo);
		ManagedVulkan::VkResult EndCommandBuffer();
		ManagedVulkan::VkResult ResetCommandBuffer(UInt32 flags);
		void CmdBindPipeline(ManagedVulkan::VkPipelineBindPoint pipelineBindPoint, ManagedVulkan::Pipeline^ pipeline);
		void CmdSetViewport(UInt32 firstViewport, UInt32 viewportCount, array<ManagedVulkan::Viewport^>^ pViewports);
		void CmdSetScissor(UInt32 firstScissor, UInt32 scissorCount, array<ManagedVulkan::Rect2D^>^ pScissors);
		void CmdSetLineWidth(float lineWidth);
		void CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
		void CmdSetBlendConstants(float blendConstants[4]);
		void CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds);
		void CmdSetStencilCompareMask(UInt32 faceMask, UInt32 compareMask);
		void CmdSetStencilWriteMask(UInt32 faceMask, UInt32 writeMask);
		void CmdSetStencilReference(UInt32 faceMask, UInt32 reference);
		void CmdBindDescriptorSets(ManagedVulkan::VkPipelineBindPoint pipelineBindPoint, ManagedVulkan::PipelineLayout^ layout, UInt32 firstSet, UInt32 descriptorSetCount, array<ManagedVulkan::DescriptorSet^>^ pDescriptorSets, UInt32 dynamicOffsetCount, array<UInt32>^ pDynamicOffsets);
		void CmdBindIndexBuffer(ManagedVulkan::Buffer^ buffer, UInt64 offset, ManagedVulkan::VkIndexType indexType);
		void CmdBindVertexBuffers(UInt32 firstBinding, UInt32 bindingCount, array<ManagedVulkan::Buffer^>^ pBuffers, array<UInt64>^ pOffsets);
		void CmdDraw(UInt32 vertexCount, UInt32 instanceCount, UInt32 firstVertex, UInt32 firstInstance);
		void CmdDrawIndexed(UInt32 indexCount, UInt32 instanceCount, UInt32 firstIndex, Int32 vertexOffset, UInt32 firstInstance);
		void CmdDrawIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride);
		void CmdDrawIndexedIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride);
		void CmdDispatch(UInt32 x, UInt32 y, UInt32 z);
		void CmdDispatchIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset);
		void CmdCopyBuffer(ManagedVulkan::Buffer^ srcBuffer, ManagedVulkan::Buffer^ dstBuffer, array<ManagedVulkan::BufferCopy^>^ pRegions);
		void CmdCopyImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::VkImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::VkImageLayout dstImageLayout, array<ManagedVulkan::ImageCopy^>^ pRegions);
		void CmdBlitImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::VkImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::VkImageLayout dstImageLayout, array<ManagedVulkan::ImageBlit^>^ pRegions, ManagedVulkan::VkFilter filter);
		void CmdCopyBufferToImage(ManagedVulkan::Buffer^ srcBuffer, ManagedVulkan::Image^ dstImage, ManagedVulkan::VkImageLayout dstImageLayout, array<ManagedVulkan::BufferImageCopy^>^ pRegions);
		void CmdCopyImageToBuffer(ManagedVulkan::Image^ srcImage, ManagedVulkan::VkImageLayout srcImageLayout, ManagedVulkan::Buffer^ dstBuffer, array<ManagedVulkan::BufferImageCopy^>^ pRegions);
		void CmdUpdateBuffer(ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 dataSize, UInt32 pData);
		void CmdFillBuffer(ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 size, UInt32 data);
		void CmdClearColorImage(ManagedVulkan::Image^ image, ManagedVulkan::VkImageLayout imageLayout, ManagedVulkan::ClearColorValue^ pColor, array<ManagedVulkan::ImageSubresourceRange^>^ pRanges);
		void CmdClearDepthStencilImage(ManagedVulkan::Image^ image, ManagedVulkan::VkImageLayout imageLayout, ManagedVulkan::ClearDepthStencilValue^ pDepthStencil, array<ManagedVulkan::ImageSubresourceRange^>^ pRanges);
		void CmdClearAttachments(array<ManagedVulkan::ClearAttachment^>^ pAttachments, array<ManagedVulkan::ClearRect^>^ pRects);
		void CmdResolveImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::VkImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::VkImageLayout dstImageLayout, array<ManagedVulkan::ImageResolve^>^ pRegions);
		void CmdSetEvent(ManagedVulkan::Event^ event, UInt32 stageMask);
		void CmdResetEvent(ManagedVulkan::Event^ event, UInt32 stageMask);
		void CmdWaitEvents(array<ManagedVulkan::Event^>^ pEvents, UInt32 srcStageMask, UInt32 dstStageMask, array<ManagedVulkan::MemoryBarrier^>^ pMemoryBarriers, array<ManagedVulkan::BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ManagedVulkan::ImageMemoryBarrier^>^ pImageMemoryBarriers);
		void CmdPipelineBarrier(UInt32 srcStageMask, UInt32 dstStageMask, UInt32 dependencyFlags, array<ManagedVulkan::MemoryBarrier^>^ pMemoryBarriers, array<ManagedVulkan::BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ManagedVulkan::ImageMemoryBarrier^>^ pImageMemoryBarriers);
		void CmdBeginQuery(ManagedVulkan::QueryPool^ queryPool, UInt32 query, UInt32 flags);
		void CmdEndQuery(ManagedVulkan::QueryPool^ queryPool, UInt32 query);
		void CmdResetQueryPool(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount);
		void CmdWriteTimestamp(ManagedVulkan::VkPipelineStageFlagBits pipelineStage, ManagedVulkan::QueryPool^ queryPool, UInt32 query);
		void CmdCopyQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 stride, UInt32 flags);
		void CmdPushConstants(ManagedVulkan::PipelineLayout^ layout, UInt32 stageFlags, UInt32 offset, UInt32 size, IntPtr pValues);
		void CmdBeginRenderPass(ManagedVulkan::RenderPassBeginInfo^ pRenderPassBegin, ManagedVulkan::VkSubpassContents contents);
		void CmdNextSubpass(ManagedVulkan::VkSubpassContents contents);
		void CmdEndRenderPass();
		void CmdExecuteCommands(array<ManagedVulkan::CommandBuffer>^ pCommandBuffers);
	};

}