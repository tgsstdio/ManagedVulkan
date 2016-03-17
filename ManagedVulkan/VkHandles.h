// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

using namespace System;

namespace ManagedVulkan
{
	// HANDLES
	public ref class DeviceMemory
	{
	internal:
		VkDeviceMemory mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class CommandPool
	{
	internal:
		VkCommandPool mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Buffer
	{
	internal:
		VkBuffer mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class BufferView
	{
	internal:
		VkBufferView mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Image
	{
	internal:
		VkImage mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class ImageView
	{
	internal:
		VkImageView mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class ShaderModule
	{
	internal:
		VkShaderModule mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Pipeline
	{
	internal:
		VkPipeline mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class PipelineLayout
	{
	internal:
		VkPipelineLayout mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Sampler
	{
	internal:
		VkSampler mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class DescriptorSet
	{
	internal:
		VkDescriptorSet mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class DescriptorSetLayout
	{
	internal:
		VkDescriptorSetLayout mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class DescriptorPool
	{
	internal:
		VkDescriptorPool mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Fence
	{
	internal:
		VkFence mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Semaphore
	{
	internal:
		VkSemaphore mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Event
	{
	internal:
		VkEvent mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class QueryPool
	{
	internal:
		VkQueryPool mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class Framebuffer
	{
	internal:
		VkFramebuffer mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class RenderPass
	{
	internal:
		VkRenderPass mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class PipelineCache
	{
	internal:
		VkPipelineCache mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class DisplayKHR
	{
	internal:
		VkDisplayKHR mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class DisplayModeKHR
	{
	internal:
		VkDisplayModeKHR mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class SurfaceKHR
	{
	internal:
		VkSurfaceKHR mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class SwapchainKHR
	{
	internal:
		VkSwapchainKHR mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};

	public ref class DebugReportCallbackEXT
	{
	internal:
		VkDebugReportCallbackEXT mHandle;
	public:
		bool IsNullHandle()
		{
			return mHandle == VK_NULL_HANDLE;
		}
	};


}