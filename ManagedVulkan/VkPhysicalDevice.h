// VkPhysicalDevice.h

#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkStructs.h"
#include "VkDevice.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ManagedVulkan
{
	//// INTERFACES

	public ref class PhysicalDevice
	{
	internal:
		VkPhysicalDevice mHandle;
	public:
		void GetPhysicalDeviceProperties([Out] ManagedVulkan::PhysicalDeviceProperties^% pProperties);
		void GetPhysicalDeviceQueueFamilyProperties([Out] array<ManagedVulkan::QueueFamilyProperties^>^% pQueueFamilyProperties);
		void GetPhysicalDeviceMemoryProperties([Out] ManagedVulkan::PhysicalDeviceMemoryProperties^% pMemoryProperties);
		void GetPhysicalDeviceFeatures([Out] ManagedVulkan::PhysicalDeviceFeatures^% pFeatures);
		void GetPhysicalDeviceFormatProperties(ManagedVulkan::Format format, [Out] ManagedVulkan::FormatProperties^% pFormatProperties);
		ManagedVulkan::Result GetPhysicalDeviceImageFormatProperties(ManagedVulkan::Format format, ManagedVulkan::ImageType type, ManagedVulkan::ImageTiling tiling, UInt32 usage, UInt32 flags, [Out] ManagedVulkan::ImageFormatProperties^% pImageFormatProperties);
		ManagedVulkan::Result CreateDevice(ManagedVulkan::DeviceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Device^% pDevice);
		ManagedVulkan::Result EnumerateDeviceLayerProperties([Out] array<ManagedVulkan::LayerProperties^>^% pProperties);
		ManagedVulkan::Result EnumerateDeviceExtensionProperties(String^ pLayerName, [Out] array<ManagedVulkan::ExtensionProperties^>^% pProperties);
		void GetPhysicalDeviceSparseImageFormatProperties(ManagedVulkan::Format format, ManagedVulkan::ImageType type, ManagedVulkan::SampleCountFlagBits samples, UInt32 usage, ManagedVulkan::ImageTiling tiling, [Out] array<ManagedVulkan::SparseImageFormatProperties^>^% pProperties);

#ifdef MANAGED_VULKAN_IMPLEMENTATION
		ManagedVulkan::Result GetPhysicalDeviceDisplayPropertiesKHR([Out] array<ManagedVulkan::DisplayPropertiesKHR^>^% pProperties);
#endif

#ifdef MANAGED_VULKAN_IMPLEMENTATION
		ManagedVulkan::Result GetPhysicalDeviceDisplayPlanePropertiesKHR([Out] array<ManagedVulkan::DisplayPlanePropertiesKHR^>^% pProperties);
#endif

#ifdef MANAGED_VULKAN_IMPLEMENTATION
		ManagedVulkan::Result GetDisplayPlaneSupportedDisplaysKHR(UInt32 planeIndex, [Out] array<ManagedVulkan::DisplayKHR^>^% pDisplays);
#endif

#ifdef MANAGED_VULKAN_IMPLEMENTATION
		ManagedVulkan::Result GetDisplayModePropertiesKHR(ManagedVulkan::DisplayKHR^ display, [Out] array<ManagedVulkan::DisplayModePropertiesKHR^>^% pProperties);
#endif

#ifdef MANAGED_VULKAN_IMPLEMENTATION
		ManagedVulkan::Result CreateDisplayModeKHR(ManagedVulkan::DisplayKHR^ display, DisplayModeCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DisplayModeKHR^% pMode);
#endif 

#ifdef MANAGED_VULKAN_IMPLEMENTATION
		ManagedVulkan::Result GetDisplayPlaneCapabilitiesKHR(ManagedVulkan::DisplayModeKHR^ mode, UInt32 planeIndex, [Out] ManagedVulkan::DisplayPlaneCapabilitiesKHR^% pCapabilities);
#endif

		ManagedVulkan::Result GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, ManagedVulkan::SurfaceKHR^ surface,[Out] bool% pSupported);
		ManagedVulkan::Result GetPhysicalDeviceSurfaceCapabilitiesKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] ManagedVulkan::SurfaceCapabilitiesKHR^% pSurfaceCapabilities);
		ManagedVulkan::Result GetPhysicalDeviceSurfaceFormatsKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] array<ManagedVulkan::SurfaceFormatKHR^>^% pSurfaceFormats);
		ManagedVulkan::Result GetPhysicalDeviceSurfacePresentModesKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] array<ManagedVulkan::PresentModeKHR>^% pPresentModes);
#ifdef VK_USE_PLATFORM_WIN32_KHR
		bool GetPhysicalDeviceWin32PresentationSupportKHR(UInt32 queueFamilyIndex);
#endif
	};
	
}