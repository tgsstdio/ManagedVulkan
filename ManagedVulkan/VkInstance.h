#pragma once

// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkStructs.h"
#include "VkPhysicalDevice.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ManagedVulkan
{
	//// INTERFACES
	public ref class Instance
	{
	internal:
		VkInstance mHandle;
		PFN_vkCreateDebugReportCallbackEXT mCreateDebugReportCallbackEXT;
		PFN_vkDestroyDebugReportCallbackEXT mDestroyDebugReportCallbackEXT;
		PFN_vkDebugReportMessageEXT mDebugReportMessageEXT;
		PFN_vkCreateDisplayPlaneSurfaceKHR mCreateDisplayPlaneSurface;
	public:
		void DestroyInstance(ManagedVulkan::AllocationCallbacks^ pAllocator);
		ManagedVulkan::Result EnumeratePhysicalDevices([Out] array<ManagedVulkan::PhysicalDevice^>^% pPhysicalDevices);
		generic <typename VkDelegate>
		where VkDelegate : System::Delegate, ref class
		bool GetInstanceProcAddr(String^ pName, [Out] VkDelegate% del);

		ManagedVulkan::Result CreateDisplayPlaneSurfaceKHR(ManagedVulkan::DisplaySurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface);
		void DestroySurfaceKHR(ManagedVulkan::SurfaceKHR^ surface, ManagedVulkan::AllocationCallbacks^ pAllocator);

#ifdef VK_USE_PLATFORM_WIN32_KHR
		ManagedVulkan::Result CreateWin32SurfaceKHR(ManagedVulkan::Win32SurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface);
#endif
		ManagedVulkan::Result CreateDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackCreateInfoEXT^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DebugReportCallbackEXT^% pCallback);
		void DestroyDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackEXT^ callback, ManagedVulkan::AllocationCallbacks^ pAllocator);
		void DebugReportMessageEXT(ManagedVulkan::DebugReportFlagBitsEXT flags, ManagedVulkan::DebugReportObjectTypeEXT objectType, UInt64 object, size_t location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage);
	};

	//public delegate ManagedVulkan::Result vkCreateDebugReportCallbackEXT(ManagedVulkan::Instance^ instance, ManagedVulkan::DebugReportCallbackCreateInfoEXT^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DebugReportCallbackEXT^% pCallback);

	//public delegate void vkDestroyDebugReportCallbackEXT(ManagedVulkan::Instance^ instance, ManagedVulkan::DebugReportCallbackEXT callback, ManagedVulkan::AllocationCallbacks^ pAllocator);

	//public delegate void vkDebugReportMessageEXT(ManagedVulkan::DebugReportFlagBitsEXT flags, ManagedVulkan::DebugReportObjectTypeEXT objectType, UInt64 object, size_t location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage);

}