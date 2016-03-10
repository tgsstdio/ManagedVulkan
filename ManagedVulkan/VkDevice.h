// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkStructs.h"
#include "VkCommandBuffer.h"
#include "VkQueue.h"

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
		void GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, [Out] ManagedVulkan::Queue^% pQueue);
		ManagedVulkan::Result DeviceWaitIdle();
		ManagedVulkan::Result AllocateMemory(ManagedVulkan::MemoryAllocateInfo^ pAllocateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator,[Out] ManagedVulkan::DeviceMemory^% pMemory);
		void FreeMemory(ManagedVulkan::DeviceMemory^ memory, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result MapMemory(ManagedVulkan::DeviceMemory^ memory, UInt64 offset, UInt64 size, UInt32 flags, [Out] IntPtr^% ppData);
		void UnmapMemory(ManagedVulkan::DeviceMemory^ memory);
		ManagedVulkan::Result FlushMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges);
		ManagedVulkan::Result InvalidateMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges);
		void GetDeviceMemoryCommitment(ManagedVulkan::DeviceMemory^ memory,[Out] UInt64^% pCommittedMemoryInBytes);
		void GetBufferMemoryRequirements(ManagedVulkan::Buffer^ buffer, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements);
		ManagedVulkan::Result BindBufferMemory(ManagedVulkan::Buffer^ buffer, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset);
		void GetImageMemoryRequirements(ManagedVulkan::Image^ image, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements);
		ManagedVulkan::Result BindImageMemory(ManagedVulkan::Image^ image, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset);
		void GetImageSparseMemoryRequirements(ManagedVulkan::Image^ image, [Out] array<ManagedVulkan::SparseImageMemoryRequirements^>^% pSparseMemoryRequirements);
		ManagedVulkan::Result CreateFence(ManagedVulkan::FenceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Fence^% pFence);
		void DestroyFence(ManagedVulkan::Fence^ fence, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result ResetFences(array<ManagedVulkan::Fence^>^ pFences);
		ManagedVulkan::Result GetFenceStatus(ManagedVulkan::Fence^ fence);
		ManagedVulkan::Result WaitForFences(array<ManagedVulkan::Fence^>^ pFences, bool waitAll, UInt64 timeout);
		ManagedVulkan::Result CreateSemaphore(ManagedVulkan::SemaphoreCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Semaphore^% pSemaphore);
		void DestroySemaphore(ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result CreateEvent(ManagedVulkan::EventCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Event^% pEvent);
		void DestroyEvent(ManagedVulkan::Event^ event, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result GetEventStatus(ManagedVulkan::Event^ event);
		ManagedVulkan::Result SetEvent(ManagedVulkan::Event^ event);
		ManagedVulkan::Result ResetEvent(ManagedVulkan::Event^ event);
		ManagedVulkan::Result CreateQueryPool(ManagedVulkan::QueryPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::QueryPool^% pQueryPool);
		void DestroyQueryPool(ManagedVulkan::QueryPool^ queryPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result GetQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, size_t dataSize, IntPtr pData, UInt64 stride, UInt32 flags);
		ManagedVulkan::Result CreateBuffer(ManagedVulkan::BufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Buffer^% pBuffer);
		void DestroyBuffer(ManagedVulkan::Buffer^ buffer, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result CreateBufferView(ManagedVulkan::BufferViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::BufferView^% pView);
		void DestroyBufferView(ManagedVulkan::BufferView^ bufferView, ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result CreateImage(ManagedVulkan::ImageCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Image^% pImage);
		void DestroyImage(ManagedVulkan::Image^ image, ManagedVulkan::AllocationCallbacks^ pAllocator);
		void GetImageSubresourceLayout(ManagedVulkan::Image^ image, ManagedVulkan::ImageSubresource^ pSubresource, [Out] ManagedVulkan::SubresourceLayout^% pLayout);
		ManagedVulkan::Result CreateImageView(ManagedVulkan::ImageViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ImageView^% pView);
		//	void DestroyImageView(ManagedVulkan::ImageView^ imageView, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreateShaderModule(ManagedVulkan::ShaderModuleCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ShaderModule^% pShaderModule);
		//	void DestroyShaderModule(ManagedVulkan::ShaderModule^ shaderModule, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreatePipelineCache(ManagedVulkan::PipelineCacheCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineCache^% pPipelineCache);
		//	void DestroyPipelineCache(ManagedVulkan::PipelineCache^ pipelineCache, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result GetPipelineCacheData(ManagedVulkan::PipelineCache^ pipelineCache, IntPtr pDataSize, IntPtr pData);
		//	ManagedVulkan::Result MergePipelineCaches(ManagedVulkan::PipelineCache^ dstCache, array<ManagedVulkan::PipelineCache^>^ pSrcCaches);
		//	ManagedVulkan::Result CreateGraphicsPipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::GraphicsPipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines);
		//	ManagedVulkan::Result CreateComputePipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::ComputePipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines);
		//	void DestroyPipeline(ManagedVulkan::Pipeline^ pipeline, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreatePipelineLayout(ManagedVulkan::PipelineLayoutCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineLayout^% pPipelineLayout);
		//	void DestroyPipelineLayout(ManagedVulkan::PipelineLayout^ pipelineLayout, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreateSampler(ManagedVulkan::SamplerCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Sampler^% pSampler);
		//	void DestroySampler(ManagedVulkan::Sampler^ sampler, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreateDescriptorSetLayout(ManagedVulkan::DescriptorSetLayoutCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DescriptorSetLayout^% pSetLayout);
		//	void DestroyDescriptorSetLayout(ManagedVulkan::DescriptorSetLayout^ descriptorSetLayout, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreateDescriptorPool(ManagedVulkan::DescriptorPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DescriptorPool^% pDescriptorPool);
		//	void DestroyDescriptorPool(ManagedVulkan::DescriptorPool^ descriptorPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result ResetDescriptorPool(ManagedVulkan::DescriptorPool^ descriptorPool, UInt32 flags);
		//	ManagedVulkan::Result AllocateDescriptorSets(ManagedVulkan::DescriptorSetAllocateInfo^ pAllocateInfo, ManagedVulkan::DescriptorSet^ pDescriptorSets);
		//	ManagedVulkan::Result FreeDescriptorSets(ManagedVulkan::DescriptorPool^ descriptorPool, UInt32 descriptorSetCount, ManagedVulkan::DescriptorSet^ pDescriptorSets);
		//	void UpdateDescriptorSets(UInt32 descriptorWriteCount, ManagedVulkan::WriteDescriptorSet^ pDescriptorWrites, UInt32 descriptorCopyCount, ManagedVulkan::CopyDescriptorSet^ pDescriptorCopies);
		//	ManagedVulkan::Result CreateFramebuffer(ManagedVulkan::FramebufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Framebuffer^% pFramebuffer);
		//	void DestroyFramebuffer(ManagedVulkan::Framebuffer^ framebuffer, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result CreateRenderPass(ManagedVulkan::RenderPassCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::RenderPass^% pRenderPass);
		//	void DestroyRenderPass(ManagedVulkan::RenderPass^ renderPass, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	void GetRenderAreaGranularity(ManagedVulkan::RenderPass^ renderPass, [Out] ManagedVulkan::Extent2D^% pGranularity);
		//	ManagedVulkan::Result CreateCommandPool(ManagedVulkan::CommandPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::CommandPool^% pCommandPool);
		//	void DestroyCommandPool(ManagedVulkan::CommandPool^ commandPool, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result ResetCommandPool(ManagedVulkan::CommandPool^ commandPool, UInt32 flags);
		//	ManagedVulkan::Result AllocateCommandBuffers(ManagedVulkan::CommandBufferAllocateInfo^ pAllocateInfo, ManagedVulkan::CommandBuffer pCommandBuffers);
		//	void FreeCommandBuffers(ManagedVulkan::CommandPool^ commandPool, array<ManagedVulkan::CommandBuffer>^ pCommandBuffers);
		//	ManagedVulkan::Result CreateSharedSwapchainsKHR(array<ManagedVulkan::SwapchainCreateInfoKHR^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::SwapchainKHR^>^% pSwapchains);
		//	ManagedVulkan::Result CreateSwapchainKHR(ManagedVulkan::SwapchainCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SwapchainKHR^% pSwapchain);
		//	void DestroySwapchainKHR(ManagedVulkan::SwapchainKHR^ swapchain, ManagedVulkan::AllocationCallbacks^ pAllocator);
		//	ManagedVulkan::Result GetSwapchainImagesKHR(ManagedVulkan::SwapchainKHR^ swapchain, [Out] array<ManagedVulkan::Image^>^% pSwapchainImages);
		//	ManagedVulkan::Result AcquireNextImageKHR(ManagedVulkan::SwapchainKHR^ swapchain, UInt64 timeout, ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::Fence^ fence, UInt32 pImageIndex);
	};
}
