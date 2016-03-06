// This is the main DLL file.
#include "stdafx.h"
#include <vulkan/vulkan.h>
#include "ManagedVulkan.h"
#include "CommandBuffer.h"

using namespace System;
using namespace System::Runtime::InteropServices;

// Vulkan
ManagedVulkan::Result ManagedVulkan::Vulkan::CreateInstance(ManagedVulkan::InstanceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Instance^% pInstance)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	char** arg_0_5 = nullptr;
	char** arg_0_7 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - pCreateInfo		
		VkInstanceCreateInfo inst_0;
		VkInstanceCreateInfo* arg_0 = &inst_0;
		pCreateInfo->CopyTo(arg_0, pins);

		// FIELD - arg_0_3 pCreateInfo->ApplicationInfo		
		VkApplicationInfo* arg_0_3 = nullptr;
		VkApplicationInfo  inst_0_3;
		if (pCreateInfo != nullptr && pCreateInfo->ApplicationInfo != nullptr)
		{
			arg_0_3 = &inst_0_3;
			pCreateInfo->ApplicationInfo->CopyTo(arg_0_3, pins);
			arg_0->pApplicationInfo = arg_0_3;
		}

		// FIELD - arg_0_5 pCreateInfo->EnabledLayerNames		
		if (pCreateInfo != nullptr && pCreateInfo->EnabledLayerNames != nullptr)
		{
			int enabledLayerCount = (int)pCreateInfo->EnabledLayerNames->Length;
			arg_0_5 = new char*[enabledLayerCount];
			for (int j = 0; j < enabledLayerCount; ++j)
			{
				IntPtr inst_0_5 = Marshal::StringToHGlobalAnsi((String^)pCreateInfo->EnabledLayerNames[j]);
				pins->Add(inst_0_5);
				arg_0_5[j] = static_cast<char*>(inst_0_5.ToPointer());
			}
			arg_0->ppEnabledLayerNames = arg_0_5;
			arg_0->enabledLayerCount = enabledLayerCount;
		}
		// FIELD - arg_0_7 pCreateInfo->EnabledExtensionNames		
		if (pCreateInfo != nullptr && pCreateInfo->EnabledExtensionNames != nullptr)
		{
			int enabledExtensionCount = (int)pCreateInfo->EnabledExtensionNames->Length;
			arg_0_7 = new char*[enabledExtensionCount];
			for (int j = 0; j < enabledExtensionCount; ++j)
			{
				IntPtr inst_0_7 = Marshal::StringToHGlobalAnsi((String^)pCreateInfo->EnabledExtensionNames[j]);
				pins->Add(inst_0_7);
				arg_0_7[j] = static_cast<char*>(inst_0_7.ToPointer());
			}
			arg_0->ppEnabledExtensionNames = arg_0_7;
			arg_0->enabledExtensionCount = enabledExtensionCount;
		}

		// INITS 1 - pAllocator		
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_1 = &inst_1;
			pAllocator->CopyTo(arg_1, pins);
		}

		// INITS 2 - pInstance		
		VkInstance inst_2;
		VkInstance* arg_2 = &inst_2;

		int result = vkCreateInstance(arg_0, arg_1, arg_2);

		pInstance = gcnew ManagedVulkan::Instance();
		pInstance->mHandle = inst_2;

		return (Result)result;
	}
	finally
	{
		if (arg_0_5 != nullptr)
		{
			delete[] arg_0_5;
		}
		if (arg_0_7 != nullptr)
		{
			delete[] arg_0_7;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Vulkan::EnumerateInstanceLayerProperties([Out] array<ManagedVulkan::LayerProperties^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkLayerProperties* arg_1 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - pPropertyCount		
		UInt32 pPropertyCount = 0;
		UInt32* arg_0 = &pPropertyCount;

		int firstResult = vkEnumerateInstanceLayerProperties(arg_0, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result) firstResult;
		}

		// MAIN INIT

		// INITS 1 - pProperties		
		arg_1 = new VkLayerProperties[pPropertyCount];

		int result = vkEnumerateInstanceLayerProperties(arg_0, arg_1);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<LayerProperties^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew LayerProperties ();
			pProperties[i]->CopyFrom((arg_1 + i));
		}

		return (Result)result;
	}
	finally
	{
		if (arg_1 != nullptr)
		{
			delete[] arg_1;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Vulkan::EnumerateInstanceExtensionProperties(String^ pLayerName, [Out] array<ManagedVulkan::ExtensionProperties^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkExtensionProperties* arg_2 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - pLayerName		
		IntPtr inst_0 = Marshal::StringToHGlobalAnsi(pLayerName);
		pins->Add(inst_0);
		char* arg_0 = static_cast<char*>(inst_0.ToPointer());
		// 1 - pPropertyCount		
		UInt32 pPropertyCount = 0;
		UInt32* arg_1 = &pPropertyCount;

		int firstResult = vkEnumerateInstanceExtensionProperties(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// MAIN INIT

		// INITS 2 - pProperties		
		arg_2 = new VkExtensionProperties[pPropertyCount];

		int result = vkEnumerateInstanceExtensionProperties(arg_0, arg_1, arg_2);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<ExtensionProperties^> (count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew ExtensionProperties ();
			pProperties[i]->CopyFrom(arg_2 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

// VkInstance
void ManagedVulkan::Instance::DestroyInstance(ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - pAllocator		
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = &inst_1;
		pAllocator->CopyTo(arg_1, pins);

		vkDestroyInstance(arg_0, arg_1);
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Instance::EnumeratePhysicalDevices([Out] array<ManagedVulkan::PhysicalDevice^>^% pPhysicalDevices)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkPhysicalDevice* arg_2 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// 1 - pPhysicalDeviceCount		
		UInt32 pPhysicalDeviceCount = 0;
		UInt32* arg_1 = &pPhysicalDeviceCount;

		int firstResult = vkEnumeratePhysicalDevices(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// MAIN INIT

		// INITS 2 - pPhysicalDevices		
		arg_2 = new VkPhysicalDevice[pPhysicalDeviceCount];

		int result = vkEnumeratePhysicalDevices(arg_0, arg_1, arg_2);

		int count = (int)pPhysicalDeviceCount;
		pPhysicalDevices = gcnew array<PhysicalDevice^>(count);
		for (int i = 0; i < count; ++i)
		{
			pPhysicalDevices[i] = gcnew PhysicalDevice();
			pPhysicalDevices[i]->mHandle = arg_2[i];
		}

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::PFN_vkVoidFunction^ ManagedVulkan::Instance::GetInstanceProcAddr(String^ pName)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - pName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(pName);
		pins->Add(inst_1);
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());

		void* result = (void*) vkGetInstanceProcAddr(arg_0, arg_1);		
		
		throw gcnew System::NotImplementedException();

		return nullptr;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#ifdef VK_CREATE_DISPLAY_PLANE_SURFACE

ManagedVulkan::Result ManagedVulkan::Instance::CreateDisplayPlaneSurfaceKHR(ManagedVulkan::DisplaySurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkDisplaySurfaceCreateInfoKHR inst_1;
		VkDisplaySurfaceCreateInfoKHR* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1, pins);
		// FIELD - arg_1_9 pCreateInfo->ImageExtent		
		VkExtent2D* arg_1_9 = nullptr;
		VkExtent2D inst_1_9;
		if (pCreateInfo != nullptr && pCreateInfo->ImageExtent != nullptr)
		{
			arg_1_9 = &inst_1_9;
			pCreateInfo->ImageExtent->CopyTo(arg_1_9, pins);
			arg_1->imageExtent = inst_1_9;
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		// INITS 3 - pSurface		
		VkSurfaceKHR inst_3;
		VkSurfaceKHR* arg_3 = &inst_3;

		int result = vkCreateDisplayPlaneSurfaceKHR(arg_0, arg_1, arg_2, arg_3);

		pSurface = gcnew SurfaceKHR ();
		pSurface->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#endif

void ManagedVulkan::Instance::DestroySurfaceKHR(ManagedVulkan::SurfaceKHR^ surface, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroySurfaceKHR(arg_0, arg_1, arg_2);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

ManagedVulkan::Result ManagedVulkan::Instance::CreateWin32SurfaceKHR(ManagedVulkan::Win32SurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkWin32SurfaceCreateInfoKHR inst_1;
		VkWin32SurfaceCreateInfoKHR* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
			arg_1 = inst_1;
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
			arg_2 = inst_2;
		}
		// INITS 3 - pSurface		
		VkSurfaceKHR inst_3;
		VkSurfaceKHR* arg_3 = nullptr;
		if (pSurface != nullptr)
		{
			arg_3 = &inst_3;
			pSurface->CopyTo(arg_3, pins);
			arg_3 = inst_3;
		}

		int result = vkCreateWin32SurfaceKHR(arg_0, arg_1, arg_2, arg_3);

		pSurface = gcnew SurfaceKHR ^ ();
		pSurface->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#endif

#ifdef VK_DEBUG_REPORT
ManagedVulkan::Result ManagedVulkan::Instance::CreateDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackCreateInfoEXT^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DebugReportCallbackEXT^% pCallback)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkDebugReportCallbackCreateInfoEXT inst_1;
		VkDebugReportCallbackCreateInfoEXT* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);

		}
		// INITS 3 - pCallback		
		VkDebugReportCallbackEXT inst_3;
		VkDebugReportCallbackEXT* arg_3 = nullptr;

		int result = vkCreateDebugReportCallbackEXT(arg_0, arg_1, arg_2, arg_3);

		pCallback = gcnew DebugReportCallbackEXT();
		pCallback->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Instance::DestroyDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackEXT^ callback, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - callback		
		VkDebugReportCallbackEXT arg_1 = callback->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyDebugReportCallbackEXT(arg_0, arg_1, arg_2);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Instance::DebugReportMessageEXT(UInt32 flags, ManagedVulkan::DebugReportObjectTypeEXT objectType, UInt64 object, size_t location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - flags		
		VkDebugReportFlagsEXT arg_1 = flags;
		// INITS 2 - objectType		
		VkDebugReportObjectTypeEXT arg_2 = (VkDebugReportObjectTypeEXT) objectType;
		// INITS 3 - object		
		uint64_t arg_3 = object;
		// INITS 4 - location		
		size_t arg_4 = location;
		// INITS 5 - messageCode		
		int32_t arg_5 = messageCode;
		// INITS 6 - pLayerPrefix		
		IntPtr inst_6 = Marshal::StringToHGlobalAnsi(pLayerPrefix);
		pins->Add(inst_6);
		char* arg_6 = static_cast<char*>(inst_6.ToPointer());;
		// INITS 7 - pMessage		
		IntPtr inst_7 = Marshal::StringToHGlobalAnsi(pMessage);
		pins->Add(inst_7);
		char* arg_7 = static_cast<char*>(inst_7.ToPointer());;

		vkDebugReportMessageEXT(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#endif

// VkPhysicalDevice
void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceProperties([Out] ManagedVulkan::PhysicalDeviceProperties^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pProperties		
		VkPhysicalDeviceProperties inst_1;
		VkPhysicalDeviceProperties* arg_1 = &inst_1;

		vkGetPhysicalDeviceProperties(arg_0, arg_1);

		pProperties = gcnew PhysicalDeviceProperties();
		pProperties->CopyFrom(arg_1);
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceQueueFamilyProperties([Out] array<ManagedVulkan::QueueFamilyProperties^>^% pQueueFamilyProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkQueueFamilyProperties* arg_2 = nullptr;
	try
	{
		uint32_t pQueueFamilyPropertyCount = 0;

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pQueueFamilyPropertyCount		
		uint32_t* arg_1 = &pQueueFamilyPropertyCount;

		vkGetPhysicalDeviceQueueFamilyProperties(arg_0, arg_1, nullptr);

		// INITS 2 - pQueueFamilyProperties		
		arg_2 = new VkQueueFamilyProperties[pQueueFamilyPropertyCount];

		vkGetPhysicalDeviceQueueFamilyProperties(arg_0, arg_1, arg_2);

		int count = (int)pQueueFamilyPropertyCount;
		pQueueFamilyProperties = gcnew array<QueueFamilyProperties^>(count);
		for (int i = 0; i < count; ++i)
		{
			pQueueFamilyProperties[i] = gcnew QueueFamilyProperties();
			pQueueFamilyProperties[i]->CopyFrom(arg_2 + i);
		}
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceMemoryProperties([Out] ManagedVulkan::PhysicalDeviceMemoryProperties^% pMemoryProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pMemoryProperties		
		VkPhysicalDeviceMemoryProperties inst_1;
		VkPhysicalDeviceMemoryProperties* arg_1 = &inst_1;

		vkGetPhysicalDeviceMemoryProperties(arg_0, arg_1);

		pMemoryProperties = gcnew PhysicalDeviceMemoryProperties();
		pMemoryProperties->CopyFrom(arg_1);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFeatures([Out] ManagedVulkan::PhysicalDeviceFeatures^% pFeatures)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pFeatures		
		VkPhysicalDeviceFeatures inst_1;
		VkPhysicalDeviceFeatures* arg_1 = &inst_1;

		vkGetPhysicalDeviceFeatures(arg_0, arg_1);

		pFeatures = gcnew PhysicalDeviceFeatures();
		pFeatures->CopyFrom(arg_1);
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFormatProperties(ManagedVulkan::Format format, [Out] ManagedVulkan::FormatProperties^% pFormatProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - format		
		VkFormat arg_1 = (VkFormat) format;
		// INITS 2 - pFormatProperties		
		VkFormatProperties inst_2;
		VkFormatProperties* arg_2 = &inst_2;

		vkGetPhysicalDeviceFormatProperties(arg_0, arg_1, arg_2);

		pFormatProperties = gcnew FormatProperties();
		pFormatProperties->CopyFrom(arg_2);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceImageFormatProperties(ManagedVulkan::Format format, ManagedVulkan::ImageType type, ManagedVulkan::ImageTiling tiling, UInt32 usage, UInt32 flags, [Out] ManagedVulkan::ImageFormatProperties^% pImageFormatProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - format		
		VkFormat arg_1 = (VkFormat) format;
		// INITS 2 - type		
		VkImageType arg_2 = (VkImageType) type;
		// INITS 3 - tiling		
		VkImageTiling arg_3 = (VkImageTiling) tiling;
		// INITS 4 - usage		
		VkImageUsageFlags arg_4 = usage;
		// INITS 5 - flags		
		VkImageCreateFlags arg_5 = flags;
		// INITS 6 - pImageFormatProperties		
		VkImageFormatProperties inst_6;
		VkImageFormatProperties* arg_6 = &inst_6;

		int result = vkGetPhysicalDeviceImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);

		pImageFormatProperties = gcnew ImageFormatProperties();
		pImageFormatProperties->CopyFrom(arg_6);

		return (Result) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::CreateDevice(ManagedVulkan::DeviceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Device^% pDevice)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	char** arg_1_6 = nullptr;
	char** arg_1_8 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkDeviceCreateInfo inst_1;
		VkDeviceCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1, pins);

		// FIELD - arg_1_4 pCreateInfo->QueueCreateInfos		
		VkDeviceQueueCreateInfo* arg_1_4 = nullptr;
		VkDeviceQueueCreateInfo  inst_1_4;
		if (pCreateInfo != nullptr && pCreateInfo->QueueCreateInfos != nullptr)
		{
			arg_1_4 = &inst_1_4;
			pCreateInfo->QueueCreateInfos->CopyTo(arg_1_4, pins);
			arg_1->pQueueCreateInfos = arg_1_4;
		}

		// FIELD - arg_1_6 pCreateInfo->EnabledLayerNames		
		if (pCreateInfo != nullptr && pCreateInfo->EnabledLayerNames != nullptr)
		{
			int enabledLayerCount = (int)pCreateInfo->EnabledLayerNames->Length;
			arg_1_6 = new char*[enabledLayerCount];
			for (int j = 0; j < enabledLayerCount; ++j)
			{
				IntPtr inst_1_6 = Marshal::StringToHGlobalAnsi((String^)pCreateInfo->EnabledLayerNames[j]);
				pins->Add(inst_1_6);
				arg_1_6[j] = static_cast<char*>(inst_1_6.ToPointer());
			}
			arg_1->ppEnabledLayerNames = arg_1_6;
			arg_1->enabledLayerCount = enabledLayerCount;
		}

		// FIELD - arg_1_8 pCreateInfo->EnabledExtensionNames		
		if (pCreateInfo != nullptr && pCreateInfo->EnabledExtensionNames != nullptr)
		{
			int enabledExtensionCount = (int)pCreateInfo->EnabledExtensionNames->Length;
			arg_1_8 = new char*[enabledExtensionCount];
			for (int j = 0; j < enabledExtensionCount; ++j)
			{
				IntPtr inst_1_8 = Marshal::StringToHGlobalAnsi((String^)pCreateInfo->EnabledExtensionNames[j]);
				pins->Add(inst_1_8);
				arg_1_8[j] = static_cast<char*>(inst_1_8.ToPointer());
			}
			arg_1->ppEnabledExtensionNames = arg_1_8;
			arg_1->enabledExtensionCount = enabledExtensionCount;
		}

		// FIELD - arg_1_9 pCreateInfo->EnabledFeatures		
		VkPhysicalDeviceFeatures* arg_1_9 = nullptr;
		VkPhysicalDeviceFeatures  inst_1_9;
		if (pCreateInfo != nullptr && pCreateInfo->EnabledFeatures != nullptr)
		{
			arg_1_9 = &inst_1_9;
			pCreateInfo->EnabledFeatures->CopyTo(arg_1_9, pins);
			arg_1->pEnabledFeatures = arg_1_9;
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		// INITS 3 - pDevice		
		VkDevice inst_3;
		VkDevice* arg_3 = &inst_3;

		int result = vkCreateDevice(arg_0, arg_1, arg_2, arg_3);

		pDevice = gcnew Device();
		pDevice->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		if (arg_1_6 != nullptr)
		{
			delete[] arg_1_6;
		}
		if (arg_1_8 != nullptr)
		{
			delete[] arg_1_8;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::EnumerateDeviceLayerProperties([Out] array<ManagedVulkan::LayerProperties^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkLayerProperties* arg_2 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pPropertyCount		
		UInt32 pPropertyCount = 0;
		UInt32* arg_1 = &pPropertyCount;

		int firstResult = vkEnumerateDeviceLayerProperties(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result) firstResult;
		}

		// MAIN INIT

		// INITS 2 - pProperties		
		arg_2 = new VkLayerProperties[pPropertyCount];

		int result = vkEnumerateDeviceLayerProperties(arg_0, arg_1, arg_2);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<LayerProperties^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew LayerProperties();
			pProperties[i]->CopyFrom(arg_2 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::EnumerateDeviceExtensionProperties(String^ pLayerName, [Out] array<ManagedVulkan::ExtensionProperties^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkExtensionProperties* arg_3 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pLayerName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(pLayerName);
		pins->Add(inst_1);
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());;
		// 2 - pPropertyCount		
		UInt32 pPropertyCount = 0;
		UInt32* arg_2 = &pPropertyCount;

		int firstResult = vkEnumerateDeviceExtensionProperties(arg_0, arg_1, arg_2, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// MAIN INIT

		// INITS 3 - pProperties		
		arg_3 = new VkExtensionProperties[pPropertyCount];

		int result = vkEnumerateDeviceExtensionProperties(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<ExtensionProperties^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew ExtensionProperties();
			pProperties[i]->CopyFrom(arg_3 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSparseImageFormatProperties(ManagedVulkan::Format format, ManagedVulkan::ImageType type, ManagedVulkan::SampleCountFlagBits samples, UInt32 usage, ManagedVulkan::ImageTiling tiling, [Out] array<ManagedVulkan::SparseImageFormatProperties^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSparseImageFormatProperties* arg_7 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - format		
		VkFormat arg_1 = (VkFormat) format;
		// INITS 2 - type		
		VkImageType arg_2 = (VkImageType) type;
		// INITS 3 - samples		
		VkSampleCountFlagBits arg_3 = (VkSampleCountFlagBits) samples;
		// INITS 4 - usage		
		VkImageUsageFlags arg_4 = usage;
		// INITS 5 - tiling		
		VkImageTiling arg_5 = (VkImageTiling) tiling;
		// INITS 6 - pPropertyCount		
		uint32_t pPropertyCount = 0;
		uint32_t* arg_6 = &pPropertyCount;

		vkGetPhysicalDeviceSparseImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, nullptr);

		// INITS 7 - pProperties		
		arg_7 = new VkSparseImageFormatProperties[pPropertyCount];

		vkGetPhysicalDeviceSparseImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<SparseImageFormatProperties^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew SparseImageFormatProperties();
			pProperties[i]->CopyFrom(arg_7 + i);
		}

	}
	finally
	{
		if (arg_7 != nullptr)
		{
			delete[] arg_7;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPropertiesKHR([Out] array<ManagedVulkan::DisplayPropertiesKHR^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDisplayPropertiesKHR* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		uint32_t pPropertyCount = 0;
		// INITS 1 - pPropertyCount		
		uint32_t* arg_1 = &pPropertyCount;

		int firstResult = vkGetPhysicalDeviceDisplayPropertiesKHR(arg_0, arg_1, arg_2);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}
		
		// INITS 2 - pProperties		
		arg_2 = new VkDisplayPropertiesKHR[pPropertyCount];

		int result = vkGetPhysicalDeviceDisplayPropertiesKHR(arg_0, arg_1, arg_2);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<DisplayPropertiesKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew DisplayPropertiesKHR();
			pProperties[i]->CopyFrom(arg_2 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPlanePropertiesKHR([Out] array<ManagedVulkan::DisplayPlanePropertiesKHR^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDisplayPlanePropertiesKHR* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pPropertyCount		
		uint32_t pPropertyCount = 0;
		uint32_t* arg_1 = &pPropertyCount;

		int firstResult = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// INITS 2 - pProperties		
		arg_2 = new VkDisplayPlanePropertiesKHR[pPropertyCount];

		int result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(arg_0, arg_1, arg_2);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<DisplayPlanePropertiesKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew DisplayPlanePropertiesKHR();
			pProperties[i]->CopyFrom(arg_2 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetDisplayPlaneSupportedDisplaysKHR(UInt32 planeIndex, [Out] array<ManagedVulkan::DisplayKHR^>^% pDisplays)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDisplayKHR* arg_3 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - planeIndex		
		uint32_t arg_1 = planeIndex;


		uint32_t pDisplayCount = 0;
		// INITS 2 - pDisplayCount		
		uint32_t* arg_2 = &pDisplayCount;

		int firstResult = vkGetDisplayPlaneSupportedDisplaysKHR(arg_0, arg_1, arg_2, nullptr);
		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// INITS 3 - pDisplays		
		arg_3 = new VkDisplayKHR[pDisplayCount];

		int result = vkGetDisplayPlaneSupportedDisplaysKHR(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pDisplayCount;
		pDisplays = gcnew array<DisplayKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pDisplays[i] = gcnew DisplayKHR ();
			pDisplays[i]->mHandle = arg_3[i];
		}

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetDisplayModePropertiesKHR(ManagedVulkan::DisplayKHR^ display, [Out] array<ManagedVulkan::DisplayModePropertiesKHR^>^% pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDisplayModePropertiesKHR* arg_3 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - display		
		VkDisplayKHR arg_1 = display->mHandle;
		// INITS 2 - pPropertyCount		
		uint32_t pPropertyCount = 0;
		uint32_t* arg_2 = &pPropertyCount;

		int firstResult = vkGetDisplayModePropertiesKHR(arg_0, arg_1, arg_2, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// INITS 3 - pProperties		
		arg_3 = new VkDisplayModePropertiesKHR[pPropertyCount];

		int result = vkGetDisplayModePropertiesKHR(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<DisplayModePropertiesKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew DisplayModePropertiesKHR();
			pProperties[i]->CopyFrom(arg_3 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::CreateDisplayModeKHR(ManagedVulkan::DisplayKHR^ display, DisplayModeCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DisplayModeKHR^% pMode)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - display		
		VkDisplayKHR arg_1 = display->mHandle;
		// INITS 2 - pCreateInfo	
		VkDisplayModeCreateInfoKHR inst_2;
		VkDisplayModeCreateInfoKHR* arg_2 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_2 = &inst_2;
			pCreateInfo->CopyTo(arg_2, pins);
		}

		// INITS 3 - pAllocator		
		VkAllocationCallbacks inst_3;
		VkAllocationCallbacks* arg_3 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_3 = &inst_3;
			pAllocator->CopyTo(arg_3, pins);
		}
		// INITS 4 - pMode		
		VkDisplayModeKHR inst_4;
		VkDisplayModeKHR* arg_4 = &inst_4;

		int result = vkCreateDisplayModeKHR(arg_0, arg_1, arg_2, arg_3, arg_4);

		pMode = gcnew DisplayModeKHR();
		pMode->mHandle = inst_4;

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, ManagedVulkan::SurfaceKHR^ surface, bool% pSupported)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - queueFamilyIndex		
		uint32_t arg_1 = queueFamilyIndex;
		// INITS 2 - surface		
		VkSurfaceKHR arg_2 = surface->mHandle;
		// INITS 3 - pSupported	
		VkBool32 inst_3;
		VkBool32* arg_3 = &inst_3;

		int result = vkGetPhysicalDeviceSurfaceSupportKHR(arg_0, arg_1, arg_2, arg_3);
		pSupported = inst_3;

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceCapabilitiesKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] ManagedVulkan::SurfaceCapabilitiesKHR^% pSurfaceCapabilities)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;
		
		// INITS 2 - pSurfaceCapabilities		
		VkSurfaceCapabilitiesKHR inst_2;
		VkSurfaceCapabilitiesKHR* arg_2 = &inst_2;

		int result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(arg_0, arg_1, arg_2);

		pSurfaceCapabilities = gcnew SurfaceCapabilitiesKHR();
		pSurfaceCapabilities->CopyFrom(arg_2);

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceFormatsKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] array<ManagedVulkan::SurfaceFormatKHR^>^% pSurfaceFormats)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSurfaceFormatKHR* arg_3 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;
		// 2 - pSurfaceFormatCount		
		UInt32 pSurfaceFormatCount = 0;
		UInt32* arg_2 = &pSurfaceFormatCount;

		int firstResult = vkGetPhysicalDeviceSurfaceFormatsKHR(arg_0, arg_1, arg_2, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// MAIN INIT

		// INITS 3 - pSurfaceFormats		
		arg_3 = new VkSurfaceFormatKHR[pSurfaceFormatCount];

		int result = vkGetPhysicalDeviceSurfaceFormatsKHR(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pSurfaceFormatCount;
		pSurfaceFormats = gcnew array<SurfaceFormatKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pSurfaceFormats[i] = gcnew SurfaceFormatKHR();
			pSurfaceFormats[i]->CopyFrom(arg_3 + i);
		}

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfacePresentModesKHR(ManagedVulkan::SurfaceKHR^ surface, [Out] array<ManagedVulkan::PresentModeKHR>^% pPresentModes)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkPresentModeKHR* arg_3 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;
		// 2 - pPresentModeCount		
		UInt32 pPresentModeCount = 0;
		UInt32* arg_2 = &pPresentModeCount;

		int firstResult = vkGetPhysicalDeviceSurfacePresentModesKHR(arg_0, arg_1, arg_2, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// MAIN INIT

		// INITS 3 - pPresentModes		
		arg_3 = new VkPresentModeKHR[pPresentModeCount];

		int result = vkGetPhysicalDeviceSurfacePresentModesKHR(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pPresentModeCount;
		pPresentModes = gcnew array<PresentModeKHR>(count);
		for (int i = 0; i < count; ++i)
		{
			pPresentModes[i] = (PresentModeKHR) arg_3[i];
		}

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#ifdef VK_USE_PLATFORM_WIN32_KHR

bool ManagedVulkan::PhysicalDevice::GetPhysicalDeviceWin32PresentationSupportKHR(UInt32 queueFamilyIndex)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - queueFamilyIndex		
		uint32_t arg_1 = queueFamilyIndex;

		int result = vkGetPhysicalDeviceWin32PresentationSupportKHR(arg_0, arg_1);

		return result != 0;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

#endif

#ifdef VK_DEBUG_REPORT
ManagedVulkan::PFN_vkVoidFunction^ ManagedVulkan::Device::GetDeviceProcAddr(String^ pName)
{
	throw gcnew NotImplementedException();

	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(pName);
		pins->Add(inst_1);
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());;

		int result = vkGetDeviceProcAddr(arg_0, arg_1);

		

		return (PFN_vkVoidFunction)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}
#endif

void ManagedVulkan::Device::DestroyDevice(ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pAllocator		
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_1 = &inst_1;
			pAllocator->CopyTo(arg_1, pins);
		}

		vkDestroyDevice(arg_0, arg_1);

	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

// VkQueue
ManagedVulkan::Result ManagedVulkan::Queue::QueueSubmit(array<ManagedVulkan::SubmitInfo^>^ pSubmits, ManagedVulkan::Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSubmitInfo* arg_2 = nullptr;

	UInt32 submitCount = 0;
	try
	{
		// MAIN INIT

		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;
		// INITS 1 - submitCount
		uint32_t arg_1 = 0;

		if (pSubmits != nullptr)
		{
			submitCount = pSubmits->Length;
			arg_1 = submitCount;

			// INITS 2 - pSubmits		
			arg_2 = new VkSubmitInfo[submitCount];
			for (int i = 0; i < submitCount; ++i)
			{
				VkSubmitInfo* dest = (arg_2 + i);
				ManagedVulkan::SubmitInfo^ src = pSubmits[i];
				src->CopyTo(dest, pins);

				UInt32 waitCount = src->WaitSemaphoreCount;
				UInt32 bufferCount = src->CommandBuffers->Length;
				UInt32 signalCount = src->SignalSemaphores->Length;

				dest->waitSemaphoreCount = waitCount;
				UInt32* waitMask = new UInt32[waitCount];
				VkSemaphore* waitSemaphores = new VkSemaphore[waitCount];
				for (int j = 0; j < waitCount; ++j)
				{
					waitMask[j] = (UInt32) src->WaitDstStageMask[j];
					ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) src->WaitSemaphores[j];
					waitSemaphores[j] = semiphore->mHandle;
				}
				dest->pWaitDstStageMask = waitMask;
				dest->pWaitSemaphores = waitSemaphores;

				dest->commandBufferCount = bufferCount;
				VkCommandBuffer* buffers = new VkCommandBuffer[bufferCount];
				for (int j = 0; j < waitCount; ++j)
				{
					ManagedVulkan::CommandBuffer^ cb = (ManagedVulkan::CommandBuffer^) src->CommandBuffers[j];
					buffers[j] = cb->mHandle;
				}
				dest->pCommandBuffers = buffers;

				dest->signalSemaphoreCount = signalCount;
				VkSemaphore* signals = new VkSemaphore[bufferCount];
				for (int j = 0; j < waitCount; ++j)
				{
					ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) src->SignalSemaphores[j];
					signals[j] = semiphore->mHandle;
				}
				dest->pSignalSemaphores = signals;
			}
		}


		// INITS 3 - fence		
		VkFence arg_3 = fence->mHandle;

		int result = vkQueueSubmit(arg_0, arg_1, arg_2, arg_3);

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			for (int i = 0; i < submitCount; ++i)
			{
				delete[] (arg_2 + i)->pWaitSemaphores;
				delete[] (arg_2 + i)->pWaitDstStageMask;
				delete[] (arg_2 + i)->pCommandBuffers;
				delete[] (arg_2 + i)->pSignalSemaphores;
			}

			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetDisplayPlaneCapabilitiesKHR(ManagedVulkan::DisplayModeKHR^ mode, UInt32 planeIndex, [Out] ManagedVulkan::DisplayPlaneCapabilitiesKHR^% pCapabilities)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - mode		
		VkDisplayModeKHR arg_1 = mode->mHandle;
		// INITS 2 - planeIndex		
		uint32_t arg_2 = planeIndex;
		// INITS 3 - pCapabilities		
		VkDisplayPlaneCapabilitiesKHR inst_3;
		VkDisplayPlaneCapabilitiesKHR* arg_3 = &inst_3;

		int result = vkGetDisplayPlaneCapabilitiesKHR(arg_0, arg_1, arg_2, arg_3);

		pCapabilities = gcnew DisplayPlaneCapabilitiesKHR();
		pCapabilities->CopyFrom(arg_3);

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}
