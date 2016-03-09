// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkStructs.h"
#include "VkCommandBuffer.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ManagedVulkan
{
	public ref class Device
	{
	internal:
		VkDevice mHandle;
	public:
		//TODO: figure out delegates
		//ManagedVulkan::PFN_vkVoidFunction^ GetDeviceProcAddr(String^ pName);
		void DestroyDevice(ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	void GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, [Out] ManagedVulkan::Queue% pQueue);
		//	ManagedVulkan::VkResult DeviceWaitIdle();
		//	ManagedVulkan::VkResult AllocateMemory(ManagedVulkan::MemoryAllocateInfo^ pAllocateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, ManagedVulkan::DeviceMemory^ pMemory);
		//	void FreeMemory(ManagedVulkan::DeviceMemory^ memory, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult MapMemory(ManagedVulkan::DeviceMemory^ memory, UInt64 offset, UInt64 size, UInt32 flags, array<IntPtr> ppData);
		//	void UnmapMemory(ManagedVulkan::DeviceMemory^ memory);
		//	ManagedVulkan::VkResult FlushMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges);
		//	ManagedVulkan::VkResult InvalidateMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges);
		//	void GetDeviceMemoryCommitment(ManagedVulkan::DeviceMemory^ memory, UInt64 pCommittedMemoryInBytes);
		//	void GetBufferMemoryRequirements(ManagedVulkan::Buffer^ buffer, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements);
		//	ManagedVulkan::VkResult BindBufferMemory(ManagedVulkan::Buffer^ buffer, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset);
		//	void GetImageMemoryRequirements(ManagedVulkan::Image^ image, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements);
		//	ManagedVulkan::VkResult BindImageMemory(ManagedVulkan::Image^ image, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset);
		//	void GetImageSparseMemoryRequirements(ManagedVulkan::Image^ image, [Out] array<ManagedVulkan::SparseImageMemoryRequirements^>^% pSparseMemoryRequirements);
		//	ManagedVulkan::VkResult CreateFence(ManagedVulkan::FenceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Fence^% pFence);
		//	void DestroyFence(ManagedVulkan::Fence^ fence, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult ResetFences(array<ManagedVulkan::Fence^>^ pFences);
		//	ManagedVulkan::VkResult GetFenceStatus(ManagedVulkan::Fence^ fence);
		//	ManagedVulkan::VkResult WaitForFences(array<ManagedVulkan::Fence^>^ pFences, bool waitAll, UInt64 timeout);
		//	ManagedVulkan::VkResult CreateSemaphore(ManagedVulkan::SemaphoreCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Semaphore^% pSemaphore);
		//	void DestroySemaphore(ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateEvent(ManagedVulkan::EventCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Event^% pEvent);
		//	void DestroyEvent(ManagedVulkan::Event^ event, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult GetEventStatus(ManagedVulkan::Event^ event);
		//	ManagedVulkan::VkResult SetEvent(ManagedVulkan::Event^ event);
		//	ManagedVulkan::VkResult ResetEvent(ManagedVulkan::Event^ event);
		//	ManagedVulkan::VkResult CreateQueryPool(ManagedVulkan::QueryPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::QueryPool^% pQueryPool);
		//	void DestroyQueryPool(ManagedVulkan::QueryPool^ queryPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult GetQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, IntPtr dataSize, IntPtr pData, UInt64 stride, UInt32 flags);
		//	ManagedVulkan::VkResult CreateBuffer(ManagedVulkan::BufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Buffer^% pBuffer);
		//	void DestroyBuffer(ManagedVulkan::Buffer^ buffer, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateBufferView(ManagedVulkan::BufferViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::BufferView^% pView);
		//	void DestroyBufferView(ManagedVulkan::BufferView^ bufferView, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateImage(ManagedVulkan::ImageCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Image^% pImage);
		//	void DestroyImage(ManagedVulkan::Image^ image, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	void GetImageSubresourceLayout(ManagedVulkan::Image^ image, ManagedVulkan::ImageSubresource^ pSubresource, [Out] ManagedVulkan::SubresourceLayout^% pLayout);
		//	ManagedVulkan::VkResult CreateImageView(ManagedVulkan::ImageViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ImageView^% pView);
		//	void DestroyImageView(ManagedVulkan::ImageView^ imageView, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateShaderModule(ManagedVulkan::ShaderModuleCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ShaderModule^% pShaderModule);
		//	void DestroyShaderModule(ManagedVulkan::ShaderModule^ shaderModule, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreatePipelineCache(ManagedVulkan::PipelineCacheCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineCache^% pPipelineCache);
		//	void DestroyPipelineCache(ManagedVulkan::PipelineCache^ pipelineCache, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult GetPipelineCacheData(ManagedVulkan::PipelineCache^ pipelineCache, IntPtr pDataSize, IntPtr pData);
		//	ManagedVulkan::VkResult MergePipelineCaches(ManagedVulkan::PipelineCache^ dstCache, array<ManagedVulkan::PipelineCache^>^ pSrcCaches);
		//	ManagedVulkan::VkResult CreateGraphicsPipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::GraphicsPipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines);
		//	ManagedVulkan::VkResult CreateComputePipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::ComputePipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines);
		//	void DestroyPipeline(ManagedVulkan::Pipeline^ pipeline, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreatePipelineLayout(ManagedVulkan::PipelineLayoutCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineLayout^% pPipelineLayout);
		//	void DestroyPipelineLayout(ManagedVulkan::PipelineLayout^ pipelineLayout, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateSampler(ManagedVulkan::SamplerCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Sampler^% pSampler);
		//	void DestroySampler(ManagedVulkan::Sampler^ sampler, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateDescriptorSetLayout(ManagedVulkan::DescriptorSetLayoutCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DescriptorSetLayout^% pSetLayout);
		//	void DestroyDescriptorSetLayout(ManagedVulkan::DescriptorSetLayout^ descriptorSetLayout, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateDescriptorPool(ManagedVulkan::DescriptorPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DescriptorPool^% pDescriptorPool);
		//	void DestroyDescriptorPool(ManagedVulkan::DescriptorPool^ descriptorPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult ResetDescriptorPool(ManagedVulkan::DescriptorPool^ descriptorPool, UInt32 flags);
		//	ManagedVulkan::VkResult AllocateDescriptorSets(ManagedVulkan::DescriptorSetAllocateInfo^ pAllocateInfo, ManagedVulkan::DescriptorSet^ pDescriptorSets);
		//	ManagedVulkan::VkResult FreeDescriptorSets(ManagedVulkan::DescriptorPool^ descriptorPool, UInt32 descriptorSetCount, ManagedVulkan::DescriptorSet^ pDescriptorSets);
		//	void UpdateDescriptorSets(UInt32 descriptorWriteCount, ManagedVulkan::WriteDescriptorSet^ pDescriptorWrites, UInt32 descriptorCopyCount, ManagedVulkan::CopyDescriptorSet^ pDescriptorCopies);
		//	ManagedVulkan::VkResult CreateFramebuffer(ManagedVulkan::FramebufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Framebuffer^% pFramebuffer);
		//	void DestroyFramebuffer(ManagedVulkan::Framebuffer^ framebuffer, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult CreateRenderPass(ManagedVulkan::RenderPassCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::RenderPass^% pRenderPass);
		//	void DestroyRenderPass(ManagedVulkan::RenderPass^ renderPass, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	void GetRenderAreaGranularity(ManagedVulkan::RenderPass^ renderPass, [Out] ManagedVulkan::Extent2D^% pGranularity);
		//	ManagedVulkan::VkResult CreateCommandPool(ManagedVulkan::CommandPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::CommandPool^% pCommandPool);
		//	void DestroyCommandPool(ManagedVulkan::CommandPool^ commandPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult ResetCommandPool(ManagedVulkan::CommandPool^ commandPool, UInt32 flags);
		//	ManagedVulkan::VkResult AllocateCommandBuffers(ManagedVulkan::CommandBufferAllocateInfo^ pAllocateInfo, ManagedVulkan::CommandBuffer pCommandBuffers);
		//	void FreeCommandBuffers(ManagedVulkan::CommandPool^ commandPool, array<ManagedVulkan::CommandBuffer>^ pCommandBuffers);
		//	ManagedVulkan::VkResult CreateSharedSwapchainsKHR(array<ManagedVulkan::SwapchainCreateInfoKHR^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::SwapchainKHR^>^% pSwapchains);
		//	ManagedVulkan::VkResult CreateSwapchainKHR(ManagedVulkan::SwapchainCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SwapchainKHR^% pSwapchain);
		//	void DestroySwapchainKHR(ManagedVulkan::SwapchainKHR^ swapchain, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::VkResult GetSwapchainImagesKHR(ManagedVulkan::SwapchainKHR^ swapchain, [Out] array<ManagedVulkan::Image^>^% pSwapchainImages);
		//	ManagedVulkan::VkResult AcquireNextImageKHR(ManagedVulkan::SwapchainKHR^ swapchain, UInt64 timeout, ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::Fence^ fence, UInt32 pImageIndex);
	};
}
