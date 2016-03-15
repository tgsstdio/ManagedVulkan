// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkStructs.h"
#include "VkInstance.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace ManagedVulkan
{
	//// INTERFACES
	public ref class Vulkan
	{
	public:
		static UInt32 MakeVersion(UInt32 major, UInt32 minor, UInt32 patch);
		static ManagedVulkan::Result CreateInstance(ManagedVulkan::InstanceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Instance^% pInstance);
		static ManagedVulkan::Result EnumerateInstanceLayerProperties([Out] array<ManagedVulkan::LayerProperties^>^% pProperties);
		static ManagedVulkan::Result EnumerateInstanceExtensionProperties(String^ pLayerName, [Out] array<ManagedVulkan::ExtensionProperties^>^% pProperties);
	};
}
