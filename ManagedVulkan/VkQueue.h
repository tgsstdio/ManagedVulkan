#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkStructs.h"

using namespace System::Runtime::InteropServices;

namespace ManagedVulkan
{
	public ref class Queue
	{
	internal:
		VkQueue mHandle;
	public:
		ManagedVulkan::Result QueueSubmit(array<ManagedVulkan::SubmitInfo^>^ pSubmits, ManagedVulkan::Fence^ fence);
		ManagedVulkan::Result QueueWaitIdle();
		ManagedVulkan::Result QueueBindSparse(array<ManagedVulkan::BindSparseInfo^>^ pBindInfo, ManagedVulkan::Fence^ fence);
		ManagedVulkan::Result QueuePresentKHR(ManagedVulkan::PresentInfoKHR^ pPresentInfo,[Out] array<ManagedVulkan::Result>^% results);
	};
}