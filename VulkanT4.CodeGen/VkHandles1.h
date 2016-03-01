// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan 
{
	// HANDLES
	public ref class DeviceMemory
	{
	internal:
		VkDeviceMemory mHandle;
	};

	public ref class CommandPool
	{
	internal:
		VkCommandPool mHandle;
	};

	public ref class Buffer
	{
	internal:
		VkBuffer mHandle;
	};

	public ref class BufferView
	{
	internal:
		VkBufferView mHandle;
	};

	public ref class Image
	{
	internal:
		VkImage mHandle;
	};

	public ref class ImageView
	{
	internal:
		VkImageView mHandle;
	};

	public ref class ShaderModule
	{
	internal:
		VkShaderModule mHandle;
	};

	public ref class Pipeline
	{
	internal:
		VkPipeline mHandle;
	};

	public ref class PipelineLayout
	{
	internal:
		VkPipelineLayout mHandle;
	};

	public ref class Sampler
	{
	internal:
		VkSampler mHandle;
	};

	public ref class DescriptorSet
	{
	internal:
		VkDescriptorSet mHandle;
	};

	public ref class DescriptorSetLayout
	{
	internal:
		VkDescriptorSetLayout mHandle;
	};

	public ref class DescriptorPool
	{
	internal:
		VkDescriptorPool mHandle;
	};

	public ref class Fence
	{
	internal:
		VkFence mHandle;
	};

	public ref class Semaphore
	{
	internal:
		VkSemaphore mHandle;
	};

	public ref class Event
	{
	internal:
		VkEvent mHandle;
	};

	public ref class QueryPool
	{
	internal:
		VkQueryPool mHandle;
	};

	public ref class Framebuffer
	{
	internal:
		VkFramebuffer mHandle;
	};

	public ref class RenderPass
	{
	internal:
		VkRenderPass mHandle;
	};

	public ref class PipelineCache
	{
	internal:
		VkPipelineCache mHandle;
	};

	public ref class DisplayKHR
	{
	internal:
		VkDisplayKHR mHandle;
	};

	public ref class DisplayModeKHR
	{
	internal:
		VkDisplayModeKHR mHandle;
	};

	public ref class SurfaceKHR
	{
	internal:
		VkSurfaceKHR mHandle;
	};

	public ref class SwapchainKHR
	{
	internal:
		VkSwapchainKHR mHandle;
	};

	public ref class DebugReportCallbackEXT
	{
	internal:
		VkDebugReportCallbackEXT mHandle;
	};


	// DELEGATES
	public delegate void PFN_vkInternalAllocationNotification(IntPtr pUserData, IntPtr size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkInternalFreeNotification(IntPtr pUserData, IntPtr size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkReallocationFunction(IntPtr pUserData, IntPtr pOriginal, IntPtr size, IntPtr alignment, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkAllocationFunction(IntPtr pUserData, IntPtr size, IntPtr alignment, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkFreeFunction(IntPtr pUserData, IntPtr pMemory);

	public delegate void PFN_vkVoidFunction();

	public delegate void PFN_vkDebugReportCallbackEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, UInt64 object, IntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage, IntPtr pUserData);

}