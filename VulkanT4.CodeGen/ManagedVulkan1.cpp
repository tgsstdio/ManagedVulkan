// This is the main DLL file.
#include <vulkan/vulkan.h>
#include "ManagedVulkan.h"

using namespace System.Collection.Generic;


// Vulkan
VkResult ManagedVulkan::Vulkan::CreateInstance(InstanceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Instance^ pInstance)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	const char* const* arg_0_5 = nullptr;
	const char* const* arg_0_7 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - pCreateInfo		
		VkInstanceCreateInfo inst_0;		
		VkInstanceCreateInfo* arg_0 = &inst_0;		
		pCreateInfo->CopyTo(arg_0 , pins);		
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
				int enabledLayerCount = (int) pCreateInfo->EnabledLayerNames->Length;		
				arg_0_5 = new char*[enabledLayerCount];		
				for (int j = 0; j < enabledLayerCount; ++j)		
				{		
					IntPtr inst_0_5 = Marshal::StringToHGlobalAnsi(pCreateInfo->EnabledLayerNames[j]);		
					pins->Add(inst_0_5);		
					arg_0_5[j] = static_cast<char*>(inst_0_5.ToPointer());		
				}		
				arg_0->ppEnabledLayerNames = arg_0_5;		
				arg_0->enabledLayerCount = enabledLayerCount;		
			}		
			// FIELD - arg_0_7 pCreateInfo->EnabledExtensionNames		
			if (pCreateInfo != nullptr && pCreateInfo->EnabledExtensionNames != nullptr)		
			{		
				int enabledExtensionCount = (int) pCreateInfo->EnabledExtensionNames->Length;		
				arg_0_7 = new char*[enabledExtensionCount];		
				for (int j = 0; j < enabledExtensionCount; ++j)		
				{		
					IntPtr inst_0_7 = Marshal::StringToHGlobalAnsi(pCreateInfo->EnabledExtensionNames[j]);		
					pins->Add(inst_0_7);		
					arg_0_7[j] = static_cast<char*>(inst_0_7.ToPointer());		
				}		
				arg_0->ppEnabledExtensionNames = arg_0_7;		
				arg_0->enabledExtensionCount = enabledExtensionCount;		
			}		
		// INITS 1 - pAllocator		
		VkAllocationCallbacks inst_1;		
		VkAllocationCallbacks* arg_1 = &inst_1;		
		pAllocator->CopyTo(arg_1 , pins);		
		// INITS 2 - pInstance		
		VkInstance inst_2;		
		VkInstance* arg_2 = &inst_2;

		var result = vkCreateInstance(arg_0, arg_1, arg_2);
								
		pInstance = gcnew Instance^();
		pInstance->mHandle = inst_2;

		return (VkResult) result;
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
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Vulkan::EnumerateInstanceLayerProperties(out array<LayerProperties^>^ pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkLayerProperties* arg_1 = nullptr;
	try
	{
		
		// 1ST CALL		
		// 0 - pPropertyCount		
		UInt32 pPropertyCount = 0;		
		UInt32* arg_0 = &pPropertyCount;

		var firstResult = vkEnumerateInstanceLayerProperties(arg_0, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return firstResult;
		}

		// MAIN INIT
		
		// INITS 1 - pProperties		
		arg_1 = new VkLayerProperties[pPropertyCount];

		var result = vkEnumerateInstanceLayerProperties(arg_0, arg_1);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<LayerProperties^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew LayerProperties^();	
			pProperties[i]->CopyFrom(arg_1[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_1 != nullptr)
		{
			delete[] arg_1;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Vulkan::EnumerateInstanceExtensionProperties(String^ pLayerName, out array<ExtensionProperties^>^ pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkExtensionProperties* arg_2 = nullptr;
	try
	{
		
		// 1ST CALL		
		// 0 - pLayerName		
		IntPtr inst_0 = Marshal::StringToHGlobalAnsi(arg_0)		
		pins->Add(inst_0)		
		char* arg_0 = static_cast<char*>(inst_0.ToPointer());		
		// 1 - pPropertyCount		
		UInt32 pPropertyCount = 0;		
		UInt32* arg_1 = &pPropertyCount;

		var firstResult = vkEnumerateInstanceExtensionProperties(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return firstResult;
		}

		// MAIN INIT
		
		// INITS 2 - pProperties		
		arg_2 = new VkExtensionProperties[pPropertyCount];

		var result = vkEnumerateInstanceExtensionProperties(arg_0, arg_1, arg_2);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<ExtensionProperties^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew ExtensionProperties^();	
			pProperties[i]->CopyFrom(arg_2[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


// VkInstance
void ManagedVulkan::Instance::DestroyInstance(AllocationCallbacks^ pAllocator)
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
		pAllocator->CopyTo(arg_1 , pins);

		vkDestroyInstance(arg_0, arg_1);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Instance::EnumeratePhysicalDevices(out array<PhysicalDevice^>^ pPhysicalDevices)
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

		var firstResult = vkEnumeratePhysicalDevices(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return firstResult;
		}

		// MAIN INIT
		
		// INITS 2 - pPhysicalDevices		
		arg_2 = new VkPhysicalDevice[pPhysicalDeviceCount];

		var result = vkEnumeratePhysicalDevices(arg_0, arg_1, arg_2);
			
		int count = (int) pPhysicalDeviceCount;	
		pPhysicalDevices = gcnew array<PhysicalDevice^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pPhysicalDevices[i] = gcnew PhysicalDevice^();	
			pPhysicalDevices[i]->CopyFrom(arg_2[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

PFN_vkVoidFunction ManagedVulkan::Instance::GetInstanceProcAddr(String^ pName)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;		
		// INITS 1 - pName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(arg_1);		
		pins->Add(inst_1);		
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());;

		var result = vkGetInstanceProcAddr(arg_0, arg_1);

		return (PFN_vkVoidFunction) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Instance::CreateDisplayPlaneSurfaceKHR(DisplaySurfaceCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SurfaceKHR^ pSurface)
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
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_9 pCreateInfo->ImageExtent		
			VkExtent2D arg_1_9 = nullptr;		
			VkExtent2D  inst_1_9;		
			if (pCreateInfo != nullptr && pCreateInfo->ImageExtent != nullptr)		
			{		
				arg_1_9 = &inst_1_9;		
				pCreateInfo->ImageExtent->CopyTo(arg_1_9, pins);		
				arg_1->imageExtent = arg_1_9;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pSurface		
		VkSurfaceKHR inst_3;		
		VkSurfaceKHR* arg_3 = &inst_3;

		var result = vkCreateDisplayPlaneSurfaceKHR(arg_0, arg_1, arg_2, arg_3);
								
		pSurface = gcnew SurfaceKHR^();
		pSurface->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Instance::DestroySurfaceKHR(SurfaceKHR^ surface, AllocationCallbacks^ pAllocator)
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
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroySurfaceKHR(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Instance::CreateWin32SurfaceKHR(Win32SurfaceCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SurfaceKHR^ pSurface)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkWin32SurfaceCreateInfoKHR inst_1;		
		VkWin32SurfaceCreateInfoKHR* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pSurface		
		VkSurfaceKHR inst_3;		
		VkSurfaceKHR* arg_3 = &inst_3;

		var result = vkCreateWin32SurfaceKHR(arg_0, arg_1, arg_2, arg_3);
								
		pSurface = gcnew SurfaceKHR^();
		pSurface->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Instance::CreateDebugReportCallbackEXT(DebugReportCallbackCreateInfoEXT^ pCreateInfo, AllocationCallbacks^ pAllocator, out DebugReportCallbackEXT^ pCallback)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkDebugReportCallbackCreateInfoEXT inst_1;		
		VkDebugReportCallbackCreateInfoEXT* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pCallback		
		VkDebugReportCallbackEXT inst_3;		
		VkDebugReportCallbackEXT* arg_3 = &inst_3;

		var result = vkCreateDebugReportCallbackEXT(arg_0, arg_1, arg_2, arg_3);
								
		pCallback = gcnew DebugReportCallbackEXT^();
		pCallback->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Instance::DestroyDebugReportCallbackEXT(DebugReportCallbackEXT^ callback, AllocationCallbacks^ pAllocator)
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
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyDebugReportCallbackEXT(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Instance::DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, UInt64 object, IntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;		
		// INITS 1 - flags		
		VkDebugReportFlagsEXT arg_1 = 0;		
		// INITS 2 - objectType		
		VkDebugReportObjectTypeEXT arg_2 = objectType;		
		// INITS 3 - object		
		uint64_t arg_3 = object;		
		// INITS 4 - location		
		size_t arg_4 = (size_t)  location;		
		// INITS 5 - messageCode		
		int32_t arg_5 = messageCode;		
		// INITS 6 - pLayerPrefix		
		IntPtr inst_6 = Marshal::StringToHGlobalAnsi(arg_6);		
		pins->Add(inst_6);		
		char* arg_6 = static_cast<char*>(inst_6.ToPointer());;		
		// INITS 7 - pMessage		
		IntPtr inst_7 = Marshal::StringToHGlobalAnsi(arg_7);		
		pins->Add(inst_7);		
		char* arg_7 = static_cast<char*>(inst_7.ToPointer());;

		vkDebugReportMessageEXT(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


// VkDevice
PFN_vkVoidFunction ManagedVulkan::Device::GetDeviceProcAddr(String^ pName)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(arg_1);		
		pins->Add(inst_1);		
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());;

		var result = vkGetDeviceProcAddr(arg_0, arg_1);

		return (PFN_vkVoidFunction) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyDevice(AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pAllocator		
		VkAllocationCallbacks inst_1;		
		VkAllocationCallbacks* arg_1 = &inst_1;		
		pAllocator->CopyTo(arg_1 , pins);

		vkDestroyDevice(arg_0, arg_1);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, out Queue^ pQueue)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - queueFamilyIndex		
		uint32_t arg_1 = queueFamilyIndex;		
		// INITS 2 - queueIndex		
		uint32_t arg_2 = queueIndex;		
		// INITS 3 - pQueue		
		VkQueue inst_3;		
		VkQueue* arg_3 = &inst_3;

		vkGetDeviceQueue(arg_0, arg_1, arg_2, arg_3);
								
		pQueue = gcnew Queue^();
		pQueue->mHandle = inst_3;

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::DeviceWaitIdle()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;

		var result = vkDeviceWaitIdle(arg_0);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::AllocateMemory(MemoryAllocateInfo^ pAllocateInfo, AllocationCallbacks^ pAllocator, DeviceMemory^ pMemory)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pAllocateInfo		
		VkMemoryAllocateInfo inst_1;		
		VkMemoryAllocateInfo* arg_1 = &inst_1;		
		pAllocateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pMemory		
		VkDeviceMemory* arg_3 = pMemory->mHandle;

		var result = vkAllocateMemory(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::FreeMemory(DeviceMemory^ memory, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkFreeMemory(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::MapMemory(DeviceMemory^ memory, UInt64 offset, UInt64 size, VkMemoryMapFlags flags, ref IntPtr ppData)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;		
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;		
		// INITS 3 - size		
		VkDeviceSize arg_3 = size;		
		// INITS 4 - flags		
		VkMemoryMapFlags arg_4 = 0;		
		// INITS 5 - ppData		
		void** arg_5 = 0;

		var result = vkMapMemory(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::UnmapMemory(DeviceMemory^ memory)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;

		vkUnmapMemory(arg_0, arg_1);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::FlushMappedMemoryRanges(array<MappedMemoryRange^>^ pMemoryRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkMappedMemoryRange* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - memoryRangeCount		
		uint32_t arg_1 = memoryRangeCount;		
		// INITS 2 - pMemoryRanges		
		arg_2 = new VkMappedMemoryRange[memoryRangeCount];

		var result = vkFlushMappedMemoryRanges(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::InvalidateMappedMemoryRanges(array<MappedMemoryRange^>^ pMemoryRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkMappedMemoryRange* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - memoryRangeCount		
		uint32_t arg_1 = memoryRangeCount;		
		// INITS 2 - pMemoryRanges		
		arg_2 = new VkMappedMemoryRange[memoryRangeCount];

		var result = vkInvalidateMappedMemoryRanges(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetDeviceMemoryCommitment(DeviceMemory^ memory, ref UInt64 pCommittedMemoryInBytes)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;		
		// INITS 2 - pCommittedMemoryInBytes		
		VkDeviceSize* arg_2 = pCommittedMemoryInBytes;

		vkGetDeviceMemoryCommitment(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetBufferMemoryRequirements(Buffer^ buffer, out MemoryRequirements^ pMemoryRequirements)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - pMemoryRequirements		
		VkMemoryRequirements inst_2;		
		VkMemoryRequirements* arg_2 = &inst_2;		
		pMemoryRequirements->CopyTo(arg_2 , pins);

		vkGetBufferMemoryRequirements(arg_0, arg_1, arg_2);
								
		pMemoryRequirements = gcnew MemoryRequirements^();
			pMemoryRequirements->CopyFrom(arg_2);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::BindBufferMemory(Buffer^ buffer, DeviceMemory^ memory, UInt64 memoryOffset)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - memory		
		VkDeviceMemory arg_2 = memory->mHandle;		
		// INITS 3 - memoryOffset		
		VkDeviceSize arg_3 = memoryOffset;

		var result = vkBindBufferMemory(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetImageMemoryRequirements(Image^ image, out MemoryRequirements^ pMemoryRequirements)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - pMemoryRequirements		
		VkMemoryRequirements inst_2;		
		VkMemoryRequirements* arg_2 = &inst_2;		
		pMemoryRequirements->CopyTo(arg_2 , pins);

		vkGetImageMemoryRequirements(arg_0, arg_1, arg_2);
								
		pMemoryRequirements = gcnew MemoryRequirements^();
			pMemoryRequirements->CopyFrom(arg_2);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::BindImageMemory(Image^ image, DeviceMemory^ memory, UInt64 memoryOffset)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - memory		
		VkDeviceMemory arg_2 = memory->mHandle;		
		// INITS 3 - memoryOffset		
		VkDeviceSize arg_3 = memoryOffset;

		var result = vkBindImageMemory(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetImageSparseMemoryRequirements(Image^ image, out array<SparseImageMemoryRequirements^>^ pSparseMemoryRequirements)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSparseImageMemoryRequirements* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - pSparseMemoryRequirementCount		
		uint32_t* arg_2 = pSparseMemoryRequirementCount;		
		// INITS 3 - pSparseMemoryRequirements		
		arg_3 = new VkSparseImageMemoryRequirements[pSparseMemoryRequirementCount];		
			// FIELD - arg_3_0 pSparseMemoryRequirements->FormatProperties		
			VkSparseImageFormatProperties arg_3_0 = nullptr;		
			VkSparseImageFormatProperties  inst_3_0;		
			if (pSparseMemoryRequirements != nullptr && pSparseMemoryRequirements->FormatProperties != nullptr)		
			{		
				arg_3_0 = &inst_3_0;		
				pSparseMemoryRequirements->FormatProperties->CopyTo(arg_3_0, pins);		
				arg_3->formatProperties = arg_3_0;		
			}		
			// FIELD - arg_3_0_1 pSparseMemoryRequirements->FormatProperties->ImageGranularity		
			VkExtent3D arg_3_0_1 = nullptr;		
			VkExtent3D  inst_3_0_1;		
			if (pSparseMemoryRequirements != nullptr && pSparseMemoryRequirements->FormatProperties != nullptr && pSparseMemoryRequirements->ImageGranularity != nullptr)		
			{		
				arg_3_0_1 = &inst_3_0_1;		
				pSparseMemoryRequirements->FormatProperties->ImageGranularity->CopyTo(arg_3_0_1, pins);		
				arg_3->formatProperties->imageGranularity = arg_3_0_1;		
			}

		vkGetImageSparseMemoryRequirements(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pSparseMemoryRequirementCount;	
		pSparseMemoryRequirements = gcnew array<SparseImageMemoryRequirements^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pSparseMemoryRequirements[i] = gcnew SparseImageMemoryRequirements^();	
			pSparseMemoryRequirements[i]->CopyFrom(arg_3[i]);
		}	

		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateFence(FenceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Fence^ pFence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkFenceCreateInfo inst_1;		
		VkFenceCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pFence		
		VkFence inst_3;		
		VkFence* arg_3 = &inst_3;

		var result = vkCreateFence(arg_0, arg_1, arg_2, arg_3);
								
		pFence = gcnew Fence^();
		pFence->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyFence(Fence^ fence, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - fence		
		VkFence arg_1 = fence->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyFence(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::ResetFences(array<Fence^>^ pFences)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkFence* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - fenceCount		
		uint32_t arg_1 = fenceCount;		
		// INITS 2 - pFences		
		arg_2 = new VkFence[fenceCount];

		var result = vkResetFences(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::GetFenceStatus(Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - fence		
		VkFence arg_1 = fence->mHandle;

		var result = vkGetFenceStatus(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::WaitForFences(array<Fence^>^ pFences, bool waitAll, UInt64 timeout)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkFence* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - fenceCount		
		uint32_t arg_1 = fenceCount;		
		// INITS 2 - pFences		
		arg_2 = new VkFence[fenceCount];		
		// INITS 3 - waitAll		
		VkBool32 arg_3 = waitAll;		
		// INITS 4 - timeout		
		uint64_t arg_4 = timeout;

		var result = vkWaitForFences(arg_0, arg_1, arg_2, arg_3, arg_4);

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateSemaphore(SemaphoreCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Semaphore^ pSemaphore)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkSemaphoreCreateInfo inst_1;		
		VkSemaphoreCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pSemaphore		
		VkSemaphore inst_3;		
		VkSemaphore* arg_3 = &inst_3;

		var result = vkCreateSemaphore(arg_0, arg_1, arg_2, arg_3);
								
		pSemaphore = gcnew Semaphore^();
		pSemaphore->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroySemaphore(Semaphore^ semaphore, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - semaphore		
		VkSemaphore arg_1 = semaphore->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroySemaphore(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateEvent(EventCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Event^ pEvent)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkEventCreateInfo inst_1;		
		VkEventCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pEvent		
		VkEvent inst_3;		
		VkEvent* arg_3 = &inst_3;

		var result = vkCreateEvent(arg_0, arg_1, arg_2, arg_3);
								
		pEvent = gcnew Event^();
		pEvent->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyEvent(Event^ event, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyEvent(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::GetEventStatus(Event^ event)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;

		var result = vkGetEventStatus(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::SetEvent(Event^ event)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;

		var result = vkSetEvent(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::ResetEvent(Event^ event)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;

		var result = vkResetEvent(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateQueryPool(QueryPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out QueryPool^ pQueryPool)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkQueryPoolCreateInfo inst_1;		
		VkQueryPoolCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pQueryPool		
		VkQueryPool inst_3;		
		VkQueryPool* arg_3 = &inst_3;

		var result = vkCreateQueryPool(arg_0, arg_1, arg_2, arg_3);
								
		pQueryPool = gcnew QueryPool^();
		pQueryPool->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyQueryPool(QueryPool^ queryPool, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyQueryPool(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::GetQueryPoolResults(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, IntPtr dataSize, IntPtr pData, UInt64 stride, VkQueryResultFlags flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;		
		// INITS 2 - firstQuery		
		uint32_t arg_2 = firstQuery;		
		// INITS 3 - queryCount		
		uint32_t arg_3 = queryCount;		
		// INITS 4 - dataSize		
		size_t arg_4 = (size_t)  dataSize;		
		// INITS 5 - pData		
		void* arg_5 = 0;		
		// INITS 6 - stride		
		VkDeviceSize arg_6 = stride;		
		// INITS 7 - flags		
		VkQueryResultFlags arg_7 = 0;

		var result = vkGetQueryPoolResults(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateBuffer(BufferCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Buffer^ pBuffer)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkBufferCreateInfo inst_1;		
		VkBufferCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pBuffer		
		VkBuffer inst_3;		
		VkBuffer* arg_3 = &inst_3;

		var result = vkCreateBuffer(arg_0, arg_1, arg_2, arg_3);
								
		pBuffer = gcnew Buffer^();
		pBuffer->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyBuffer(Buffer^ buffer, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyBuffer(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateBufferView(BufferViewCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out BufferView^ pView)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkBufferViewCreateInfo inst_1;		
		VkBufferViewCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pView		
		VkBufferView inst_3;		
		VkBufferView* arg_3 = &inst_3;

		var result = vkCreateBufferView(arg_0, arg_1, arg_2, arg_3);
								
		pView = gcnew BufferView^();
		pView->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyBufferView(BufferView^ bufferView, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - bufferView		
		VkBufferView arg_1 = bufferView->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyBufferView(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateImage(ImageCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Image^ pImage)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkImageCreateInfo inst_1;		
		VkImageCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_5 pCreateInfo->Extent		
			VkExtent3D arg_1_5 = nullptr;		
			VkExtent3D  inst_1_5;		
			if (pCreateInfo != nullptr && pCreateInfo->Extent != nullptr)		
			{		
				arg_1_5 = &inst_1_5;		
				pCreateInfo->Extent->CopyTo(arg_1_5, pins);		
				arg_1->extent = arg_1_5;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pImage		
		VkImage inst_3;		
		VkImage* arg_3 = &inst_3;

		var result = vkCreateImage(arg_0, arg_1, arg_2, arg_3);
								
		pImage = gcnew Image^();
		pImage->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyImage(Image^ image, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyImage(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetImageSubresourceLayout(Image^ image, ImageSubresource^ pSubresource, out SubresourceLayout^ pLayout)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - pSubresource		
		VkImageSubresource inst_2;		
		VkImageSubresource* arg_2 = &inst_2;		
		pSubresource->CopyTo(arg_2 , pins);		
		// INITS 3 - pLayout		
		VkSubresourceLayout inst_3;		
		VkSubresourceLayout* arg_3 = &inst_3;		
		pLayout->CopyTo(arg_3 , pins);

		vkGetImageSubresourceLayout(arg_0, arg_1, arg_2, arg_3);
								
		pLayout = gcnew SubresourceLayout^();
			pLayout->CopyFrom(arg_3);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateImageView(ImageViewCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out ImageView^ pView)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkImageViewCreateInfo inst_1;		
		VkImageViewCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_6 pCreateInfo->Components		
			VkComponentMapping arg_1_6 = nullptr;		
			VkComponentMapping  inst_1_6;		
			if (pCreateInfo != nullptr && pCreateInfo->Components != nullptr)		
			{		
				arg_1_6 = &inst_1_6;		
				pCreateInfo->Components->CopyTo(arg_1_6, pins);		
				arg_1->components = arg_1_6;		
			}		
			// FIELD - arg_1_7 pCreateInfo->SubresourceRange		
			VkImageSubresourceRange arg_1_7 = nullptr;		
			VkImageSubresourceRange  inst_1_7;		
			if (pCreateInfo != nullptr && pCreateInfo->SubresourceRange != nullptr)		
			{		
				arg_1_7 = &inst_1_7;		
				pCreateInfo->SubresourceRange->CopyTo(arg_1_7, pins);		
				arg_1->subresourceRange = arg_1_7;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pView		
		VkImageView inst_3;		
		VkImageView* arg_3 = &inst_3;

		var result = vkCreateImageView(arg_0, arg_1, arg_2, arg_3);
								
		pView = gcnew ImageView^();
		pView->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyImageView(ImageView^ imageView, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - imageView		
		VkImageView arg_1 = imageView->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyImageView(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateShaderModule(ShaderModuleCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out ShaderModule^ pShaderModule)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkShaderModuleCreateInfo inst_1;		
		VkShaderModuleCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pShaderModule		
		VkShaderModule inst_3;		
		VkShaderModule* arg_3 = &inst_3;

		var result = vkCreateShaderModule(arg_0, arg_1, arg_2, arg_3);
								
		pShaderModule = gcnew ShaderModule^();
		pShaderModule->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyShaderModule(ShaderModule^ shaderModule, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - shaderModule		
		VkShaderModule arg_1 = shaderModule->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyShaderModule(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreatePipelineCache(PipelineCacheCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out PipelineCache^ pPipelineCache)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkPipelineCacheCreateInfo inst_1;		
		VkPipelineCacheCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pPipelineCache		
		VkPipelineCache inst_3;		
		VkPipelineCache* arg_3 = &inst_3;

		var result = vkCreatePipelineCache(arg_0, arg_1, arg_2, arg_3);
								
		pPipelineCache = gcnew PipelineCache^();
		pPipelineCache->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyPipelineCache(PipelineCache^ pipelineCache, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyPipelineCache(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::GetPipelineCacheData(PipelineCache^ pipelineCache, ref IntPtr pDataSize, IntPtr pData)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;		
		// INITS 2 - pDataSize		
		size_t* arg_2 = 0;		
		// INITS 3 - pData		
		void* arg_3 = 0;

		var result = vkGetPipelineCacheData(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::MergePipelineCaches(PipelineCache^ dstCache, array<PipelineCache^>^ pSrcCaches)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkPipelineCache* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - dstCache		
		VkPipelineCache arg_1 = dstCache->mHandle;		
		// INITS 2 - srcCacheCount		
		uint32_t arg_2 = srcCacheCount;		
		// INITS 3 - pSrcCaches		
		arg_3 = new VkPipelineCache[srcCacheCount];

		var result = vkMergePipelineCaches(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateGraphicsPipelines(PipelineCache^ pipelineCache, array<GraphicsPipelineCreateInfo^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<Pipeline^>^ pPipelines)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkGraphicsPipelineCreateInfo* arg_3 = nullptr;
	VkPipeline* arg_5 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;		
		// INITS 2 - createInfoCount		
		uint32_t arg_2 = createInfoCount;		
		// INITS 3 - pCreateInfos		
		arg_3 = new VkGraphicsPipelineCreateInfo[createInfoCount];		
			// FIELD - arg_3_4 pCreateInfos->Stages		
			VkPipelineShaderStageCreateInfo* arg_3_4 = nullptr;		
			VkPipelineShaderStageCreateInfo  inst_3_4;		
			if (pCreateInfos != nullptr && pCreateInfos->Stages != nullptr)		
			{		
				arg_3_4 = &inst_3_4;		
				pCreateInfos->Stages->CopyTo(arg_3_4, pins);		
				arg_3->pStages = arg_3_4;		
			}		
			// FIELD - arg_3_4_6 pCreateInfos->Stages->SpecializationInfo		
			VkSpecializationInfo* arg_3_4_6 = nullptr;		
			VkSpecializationInfo  inst_3_4_6;		
			if (pCreateInfos != nullptr && pCreateInfos->Stages != nullptr && pCreateInfos->SpecializationInfo != nullptr)		
			{		
				arg_3_4_6 = &inst_3_4_6;		
				pCreateInfos->Stages->SpecializationInfo->CopyTo(arg_3_4_6, pins);		
				arg_3->pStages->pSpecializationInfo = arg_3_4_6;		
			}		
			// FIELD - arg_3_4_6_1 pCreateInfos->Stages->SpecializationInfo->MapEntries		
			VkSpecializationMapEntry* arg_3_4_6_1 = nullptr;		
			VkSpecializationMapEntry  inst_3_4_6_1;		
			if (pCreateInfos != nullptr && pCreateInfos->Stages != nullptr && pCreateInfos->SpecializationInfo != nullptr && pCreateInfos->MapEntries != nullptr)		
			{		
				arg_3_4_6_1 = &inst_3_4_6_1;		
				pCreateInfos->Stages->SpecializationInfo->MapEntries->CopyTo(arg_3_4_6_1, pins);		
				arg_3->pStages->pSpecializationInfo->pMapEntries = arg_3_4_6_1;		
			}		
			// FIELD - arg_3_5 pCreateInfos->VertexInputState		
			VkPipelineVertexInputStateCreateInfo* arg_3_5 = nullptr;		
			VkPipelineVertexInputStateCreateInfo  inst_3_5;		
			if (pCreateInfos != nullptr && pCreateInfos->VertexInputState != nullptr)		
			{		
				arg_3_5 = &inst_3_5;		
				pCreateInfos->VertexInputState->CopyTo(arg_3_5, pins);		
				arg_3->pVertexInputState = arg_3_5;		
			}		
			// FIELD - arg_3_5_4 pCreateInfos->VertexInputState->VertexBindingDescriptions		
			VkVertexInputBindingDescription* arg_3_5_4 = nullptr;		
			VkVertexInputBindingDescription  inst_3_5_4;		
			if (pCreateInfos != nullptr && pCreateInfos->VertexInputState != nullptr && pCreateInfos->VertexBindingDescriptions != nullptr)		
			{		
				arg_3_5_4 = &inst_3_5_4;		
				pCreateInfos->VertexInputState->VertexBindingDescriptions->CopyTo(arg_3_5_4, pins);		
				arg_3->pVertexInputState->pVertexBindingDescriptions = arg_3_5_4;		
			}		
			// FIELD - arg_3_5_6 pCreateInfos->VertexInputState->VertexAttributeDescriptions		
			VkVertexInputAttributeDescription* arg_3_5_6 = nullptr;		
			VkVertexInputAttributeDescription  inst_3_5_6;		
			if (pCreateInfos != nullptr && pCreateInfos->VertexInputState != nullptr && pCreateInfos->VertexAttributeDescriptions != nullptr)		
			{		
				arg_3_5_6 = &inst_3_5_6;		
				pCreateInfos->VertexInputState->VertexAttributeDescriptions->CopyTo(arg_3_5_6, pins);		
				arg_3->pVertexInputState->pVertexAttributeDescriptions = arg_3_5_6;		
			}		
			// FIELD - arg_3_6 pCreateInfos->InputAssemblyState		
			VkPipelineInputAssemblyStateCreateInfo* arg_3_6 = nullptr;		
			VkPipelineInputAssemblyStateCreateInfo  inst_3_6;		
			if (pCreateInfos != nullptr && pCreateInfos->InputAssemblyState != nullptr)		
			{		
				arg_3_6 = &inst_3_6;		
				pCreateInfos->InputAssemblyState->CopyTo(arg_3_6, pins);		
				arg_3->pInputAssemblyState = arg_3_6;		
			}		
			// FIELD - arg_3_7 pCreateInfos->TessellationState		
			VkPipelineTessellationStateCreateInfo* arg_3_7 = nullptr;		
			VkPipelineTessellationStateCreateInfo  inst_3_7;		
			if (pCreateInfos != nullptr && pCreateInfos->TessellationState != nullptr)		
			{		
				arg_3_7 = &inst_3_7;		
				pCreateInfos->TessellationState->CopyTo(arg_3_7, pins);		
				arg_3->pTessellationState = arg_3_7;		
			}		
			// FIELD - arg_3_8 pCreateInfos->ViewportState		
			VkPipelineViewportStateCreateInfo* arg_3_8 = nullptr;		
			VkPipelineViewportStateCreateInfo  inst_3_8;		
			if (pCreateInfos != nullptr && pCreateInfos->ViewportState != nullptr)		
			{		
				arg_3_8 = &inst_3_8;		
				pCreateInfos->ViewportState->CopyTo(arg_3_8, pins);		
				arg_3->pViewportState = arg_3_8;		
			}		
			// FIELD - arg_3_8_4 pCreateInfos->ViewportState->Viewports		
			VkViewport* arg_3_8_4 = nullptr;		
			VkViewport  inst_3_8_4;		
			if (pCreateInfos != nullptr && pCreateInfos->ViewportState != nullptr && pCreateInfos->Viewports != nullptr)		
			{		
				arg_3_8_4 = &inst_3_8_4;		
				pCreateInfos->ViewportState->Viewports->CopyTo(arg_3_8_4, pins);		
				arg_3->pViewportState->pViewports = arg_3_8_4;		
			}		
			// FIELD - arg_3_8_6 pCreateInfos->ViewportState->Scissors		
			VkRect2D* arg_3_8_6 = nullptr;		
			VkRect2D  inst_3_8_6;		
			if (pCreateInfos != nullptr && pCreateInfos->ViewportState != nullptr && pCreateInfos->Scissors != nullptr)		
			{		
				arg_3_8_6 = &inst_3_8_6;		
				pCreateInfos->ViewportState->Scissors->CopyTo(arg_3_8_6, pins);		
				arg_3->pViewportState->pScissors = arg_3_8_6;		
			}		
			// FIELD - arg_3_8_6_0 pCreateInfos->ViewportState->Scissors->Offset		
			VkOffset2D arg_3_8_6_0 = nullptr;		
			VkOffset2D  inst_3_8_6_0;		
			if (pCreateInfos != nullptr && pCreateInfos->ViewportState != nullptr && pCreateInfos->Scissors != nullptr && pCreateInfos->Offset != nullptr)		
			{		
				arg_3_8_6_0 = &inst_3_8_6_0;		
				pCreateInfos->ViewportState->Scissors->Offset->CopyTo(arg_3_8_6_0, pins);		
				arg_3->pViewportState->pScissors->offset = arg_3_8_6_0;		
			}		
			// FIELD - arg_3_8_6_1 pCreateInfos->ViewportState->Scissors->Extent		
			VkExtent2D arg_3_8_6_1 = nullptr;		
			VkExtent2D  inst_3_8_6_1;		
			if (pCreateInfos != nullptr && pCreateInfos->ViewportState != nullptr && pCreateInfos->Scissors != nullptr && pCreateInfos->Extent != nullptr)		
			{		
				arg_3_8_6_1 = &inst_3_8_6_1;		
				pCreateInfos->ViewportState->Scissors->Extent->CopyTo(arg_3_8_6_1, pins);		
				arg_3->pViewportState->pScissors->extent = arg_3_8_6_1;		
			}		
			// FIELD - arg_3_9 pCreateInfos->RasterizationState		
			VkPipelineRasterizationStateCreateInfo* arg_3_9 = nullptr;		
			VkPipelineRasterizationStateCreateInfo  inst_3_9;		
			if (pCreateInfos != nullptr && pCreateInfos->RasterizationState != nullptr)		
			{		
				arg_3_9 = &inst_3_9;		
				pCreateInfos->RasterizationState->CopyTo(arg_3_9, pins);		
				arg_3->pRasterizationState = arg_3_9;		
			}		
			// FIELD - arg_3_10 pCreateInfos->MultisampleState		
			VkPipelineMultisampleStateCreateInfo* arg_3_10 = nullptr;		
			VkPipelineMultisampleStateCreateInfo  inst_3_10;		
			if (pCreateInfos != nullptr && pCreateInfos->MultisampleState != nullptr)		
			{		
				arg_3_10 = &inst_3_10;		
				pCreateInfos->MultisampleState->CopyTo(arg_3_10, pins);		
				arg_3->pMultisampleState = arg_3_10;		
			}		
			// FIELD - arg_3_11 pCreateInfos->DepthStencilState		
			VkPipelineDepthStencilStateCreateInfo* arg_3_11 = nullptr;		
			VkPipelineDepthStencilStateCreateInfo  inst_3_11;		
			if (pCreateInfos != nullptr && pCreateInfos->DepthStencilState != nullptr)		
			{		
				arg_3_11 = &inst_3_11;		
				pCreateInfos->DepthStencilState->CopyTo(arg_3_11, pins);		
				arg_3->pDepthStencilState = arg_3_11;		
			}		
			// FIELD - arg_3_11_8 pCreateInfos->DepthStencilState->Front		
			VkStencilOpState arg_3_11_8 = nullptr;		
			VkStencilOpState  inst_3_11_8;		
			if (pCreateInfos != nullptr && pCreateInfos->DepthStencilState != nullptr && pCreateInfos->Front != nullptr)		
			{		
				arg_3_11_8 = &inst_3_11_8;		
				pCreateInfos->DepthStencilState->Front->CopyTo(arg_3_11_8, pins);		
				arg_3->pDepthStencilState->front = arg_3_11_8;		
			}		
			// FIELD - arg_3_11_9 pCreateInfos->DepthStencilState->Back		
			VkStencilOpState arg_3_11_9 = nullptr;		
			VkStencilOpState  inst_3_11_9;		
			if (pCreateInfos != nullptr && pCreateInfos->DepthStencilState != nullptr && pCreateInfos->Back != nullptr)		
			{		
				arg_3_11_9 = &inst_3_11_9;		
				pCreateInfos->DepthStencilState->Back->CopyTo(arg_3_11_9, pins);		
				arg_3->pDepthStencilState->back = arg_3_11_9;		
			}		
			// FIELD - arg_3_12 pCreateInfos->ColorBlendState		
			VkPipelineColorBlendStateCreateInfo* arg_3_12 = nullptr;		
			VkPipelineColorBlendStateCreateInfo  inst_3_12;		
			if (pCreateInfos != nullptr && pCreateInfos->ColorBlendState != nullptr)		
			{		
				arg_3_12 = &inst_3_12;		
				pCreateInfos->ColorBlendState->CopyTo(arg_3_12, pins);		
				arg_3->pColorBlendState = arg_3_12;		
			}		
			// FIELD - arg_3_12_6 pCreateInfos->ColorBlendState->Attachments		
			VkPipelineColorBlendAttachmentState* arg_3_12_6 = nullptr;		
			VkPipelineColorBlendAttachmentState  inst_3_12_6;		
			if (pCreateInfos != nullptr && pCreateInfos->ColorBlendState != nullptr && pCreateInfos->Attachments != nullptr)		
			{		
				arg_3_12_6 = &inst_3_12_6;		
				pCreateInfos->ColorBlendState->Attachments->CopyTo(arg_3_12_6, pins);		
				arg_3->pColorBlendState->pAttachments = arg_3_12_6;		
			}		
			// FIELD - arg_3_13 pCreateInfos->DynamicState		
			VkPipelineDynamicStateCreateInfo* arg_3_13 = nullptr;		
			VkPipelineDynamicStateCreateInfo  inst_3_13;		
			if (pCreateInfos != nullptr && pCreateInfos->DynamicState != nullptr)		
			{		
				arg_3_13 = &inst_3_13;		
				pCreateInfos->DynamicState->CopyTo(arg_3_13, pins);		
				arg_3->pDynamicState = arg_3_13;		
			}		
		// INITS 4 - pAllocator		
		VkAllocationCallbacks inst_4;		
		VkAllocationCallbacks* arg_4 = &inst_4;		
		pAllocator->CopyTo(arg_4 , pins);		
		// INITS 5 - pPipelines		
		arg_5 = new VkPipeline[createInfoCount];

		var result = vkCreateGraphicsPipelines(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);
			
		int count = (int) createInfoCount;	
		pPipelines = gcnew array<Pipeline^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pPipelines[i] = gcnew Pipeline^();	
			pPipelines[i]->CopyFrom(arg_5[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateComputePipelines(PipelineCache^ pipelineCache, array<ComputePipelineCreateInfo^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<Pipeline^>^ pPipelines)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkComputePipelineCreateInfo* arg_3 = nullptr;
	VkPipeline* arg_5 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;		
		// INITS 2 - createInfoCount		
		uint32_t arg_2 = createInfoCount;		
		// INITS 3 - pCreateInfos		
		arg_3 = new VkComputePipelineCreateInfo[createInfoCount];		
			// FIELD - arg_3_3 pCreateInfos->Stage		
			VkPipelineShaderStageCreateInfo arg_3_3 = nullptr;		
			VkPipelineShaderStageCreateInfo  inst_3_3;		
			if (pCreateInfos != nullptr && pCreateInfos->Stage != nullptr)		
			{		
				arg_3_3 = &inst_3_3;		
				pCreateInfos->Stage->CopyTo(arg_3_3, pins);		
				arg_3->stage = arg_3_3;		
			}		
			// FIELD - arg_3_3_6 pCreateInfos->Stage->SpecializationInfo		
			VkSpecializationInfo* arg_3_3_6 = nullptr;		
			VkSpecializationInfo  inst_3_3_6;		
			if (pCreateInfos != nullptr && pCreateInfos->Stage != nullptr && pCreateInfos->SpecializationInfo != nullptr)		
			{		
				arg_3_3_6 = &inst_3_3_6;		
				pCreateInfos->Stage->SpecializationInfo->CopyTo(arg_3_3_6, pins);		
				arg_3->stage->pSpecializationInfo = arg_3_3_6;		
			}		
			// FIELD - arg_3_3_6_1 pCreateInfos->Stage->SpecializationInfo->MapEntries		
			VkSpecializationMapEntry* arg_3_3_6_1 = nullptr;		
			VkSpecializationMapEntry  inst_3_3_6_1;		
			if (pCreateInfos != nullptr && pCreateInfos->Stage != nullptr && pCreateInfos->SpecializationInfo != nullptr && pCreateInfos->MapEntries != nullptr)		
			{		
				arg_3_3_6_1 = &inst_3_3_6_1;		
				pCreateInfos->Stage->SpecializationInfo->MapEntries->CopyTo(arg_3_3_6_1, pins);		
				arg_3->stage->pSpecializationInfo->pMapEntries = arg_3_3_6_1;		
			}		
		// INITS 4 - pAllocator		
		VkAllocationCallbacks inst_4;		
		VkAllocationCallbacks* arg_4 = &inst_4;		
		pAllocator->CopyTo(arg_4 , pins);		
		// INITS 5 - pPipelines		
		arg_5 = new VkPipeline[createInfoCount];

		var result = vkCreateComputePipelines(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);
			
		int count = (int) createInfoCount;	
		pPipelines = gcnew array<Pipeline^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pPipelines[i] = gcnew Pipeline^();	
			pPipelines[i]->CopyFrom(arg_5[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyPipeline(Pipeline^ pipeline, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pipeline		
		VkPipeline arg_1 = pipeline->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyPipeline(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreatePipelineLayout(PipelineLayoutCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out PipelineLayout^ pPipelineLayout)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkPipelineLayoutCreateInfo inst_1;		
		VkPipelineLayoutCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_6 pCreateInfo->PushConstantRanges		
			VkPushConstantRange* arg_1_6 = nullptr;		
			VkPushConstantRange  inst_1_6;		
			if (pCreateInfo != nullptr && pCreateInfo->PushConstantRanges != nullptr)		
			{		
				arg_1_6 = &inst_1_6;		
				pCreateInfo->PushConstantRanges->CopyTo(arg_1_6, pins);		
				arg_1->pPushConstantRanges = arg_1_6;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pPipelineLayout		
		VkPipelineLayout inst_3;		
		VkPipelineLayout* arg_3 = &inst_3;

		var result = vkCreatePipelineLayout(arg_0, arg_1, arg_2, arg_3);
								
		pPipelineLayout = gcnew PipelineLayout^();
		pPipelineLayout->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyPipelineLayout(PipelineLayout^ pipelineLayout, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pipelineLayout		
		VkPipelineLayout arg_1 = pipelineLayout->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyPipelineLayout(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateSampler(SamplerCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Sampler^ pSampler)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkSamplerCreateInfo inst_1;		
		VkSamplerCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pSampler		
		VkSampler inst_3;		
		VkSampler* arg_3 = &inst_3;

		var result = vkCreateSampler(arg_0, arg_1, arg_2, arg_3);
								
		pSampler = gcnew Sampler^();
		pSampler->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroySampler(Sampler^ sampler, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - sampler		
		VkSampler arg_1 = sampler->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroySampler(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateDescriptorSetLayout(DescriptorSetLayoutCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out DescriptorSetLayout^ pSetLayout)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkDescriptorSetLayoutCreateInfo inst_1;		
		VkDescriptorSetLayoutCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_4 pCreateInfo->Bindings		
			VkDescriptorSetLayoutBinding* arg_1_4 = nullptr;		
			VkDescriptorSetLayoutBinding  inst_1_4;		
			if (pCreateInfo != nullptr && pCreateInfo->Bindings != nullptr)		
			{		
				arg_1_4 = &inst_1_4;		
				pCreateInfo->Bindings->CopyTo(arg_1_4, pins);		
				arg_1->pBindings = arg_1_4;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pSetLayout		
		VkDescriptorSetLayout inst_3;		
		VkDescriptorSetLayout* arg_3 = &inst_3;

		var result = vkCreateDescriptorSetLayout(arg_0, arg_1, arg_2, arg_3);
								
		pSetLayout = gcnew DescriptorSetLayout^();
		pSetLayout->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyDescriptorSetLayout(DescriptorSetLayout^ descriptorSetLayout, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - descriptorSetLayout		
		VkDescriptorSetLayout arg_1 = descriptorSetLayout->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyDescriptorSetLayout(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateDescriptorPool(DescriptorPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out DescriptorPool^ pDescriptorPool)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkDescriptorPoolCreateInfo inst_1;		
		VkDescriptorPoolCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_5 pCreateInfo->PoolSizes		
			VkDescriptorPoolSize* arg_1_5 = nullptr;		
			VkDescriptorPoolSize  inst_1_5;		
			if (pCreateInfo != nullptr && pCreateInfo->PoolSizes != nullptr)		
			{		
				arg_1_5 = &inst_1_5;		
				pCreateInfo->PoolSizes->CopyTo(arg_1_5, pins);		
				arg_1->pPoolSizes = arg_1_5;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pDescriptorPool		
		VkDescriptorPool inst_3;		
		VkDescriptorPool* arg_3 = &inst_3;

		var result = vkCreateDescriptorPool(arg_0, arg_1, arg_2, arg_3);
								
		pDescriptorPool = gcnew DescriptorPool^();
		pDescriptorPool->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyDescriptorPool(DescriptorPool^ descriptorPool, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - descriptorPool		
		VkDescriptorPool arg_1 = descriptorPool->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyDescriptorPool(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::ResetDescriptorPool(DescriptorPool^ descriptorPool, VkDescriptorPoolResetFlags flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - descriptorPool		
		VkDescriptorPool arg_1 = descriptorPool->mHandle;		
		// INITS 2 - flags		
		VkDescriptorPoolResetFlags arg_2 = 0;

		var result = vkResetDescriptorPool(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::AllocateDescriptorSets(DescriptorSetAllocateInfo^ pAllocateInfo, DescriptorSet^ pDescriptorSets)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pAllocateInfo		
		VkDescriptorSetAllocateInfo inst_1;		
		VkDescriptorSetAllocateInfo* arg_1 = &inst_1;		
		pAllocateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pDescriptorSets		
		VkDescriptorSet* arg_2 = pDescriptorSets->mHandle;

		var result = vkAllocateDescriptorSets(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::FreeDescriptorSets(DescriptorPool^ descriptorPool, UInt32 descriptorSetCount, DescriptorSet^ pDescriptorSets)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - descriptorPool		
		VkDescriptorPool arg_1 = descriptorPool->mHandle;		
		// INITS 2 - descriptorSetCount		
		uint32_t arg_2 = descriptorSetCount;		
		// INITS 3 - pDescriptorSets		
		VkDescriptorSet* arg_3 = pDescriptorSets->mHandle;

		var result = vkFreeDescriptorSets(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::UpdateDescriptorSets(UInt32 descriptorWriteCount, WriteDescriptorSet^ pDescriptorWrites, UInt32 descriptorCopyCount, CopyDescriptorSet^ pDescriptorCopies)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - descriptorWriteCount		
		uint32_t arg_1 = descriptorWriteCount;		
		// INITS 2 - pDescriptorWrites		
		VkWriteDescriptorSet inst_2;		
		VkWriteDescriptorSet* arg_2 = &inst_2;		
		pDescriptorWrites->CopyTo(arg_2 , pins);		
			// FIELD - arg_2_7 pDescriptorWrites->ImageInfo		
			VkDescriptorImageInfo* arg_2_7 = nullptr;		
			VkDescriptorImageInfo  inst_2_7;		
			if (pDescriptorWrites != nullptr && pDescriptorWrites->ImageInfo != nullptr)		
			{		
				arg_2_7 = &inst_2_7;		
				pDescriptorWrites->ImageInfo->CopyTo(arg_2_7, pins);		
				arg_2->pImageInfo = arg_2_7;		
			}		
			// FIELD - arg_2_8 pDescriptorWrites->BufferInfo		
			VkDescriptorBufferInfo* arg_2_8 = nullptr;		
			VkDescriptorBufferInfo  inst_2_8;		
			if (pDescriptorWrites != nullptr && pDescriptorWrites->BufferInfo != nullptr)		
			{		
				arg_2_8 = &inst_2_8;		
				pDescriptorWrites->BufferInfo->CopyTo(arg_2_8, pins);		
				arg_2->pBufferInfo = arg_2_8;		
			}		
		// INITS 3 - descriptorCopyCount		
		uint32_t arg_3 = descriptorCopyCount;		
		// INITS 4 - pDescriptorCopies		
		VkCopyDescriptorSet inst_4;		
		VkCopyDescriptorSet* arg_4 = &inst_4;		
		pDescriptorCopies->CopyTo(arg_4 , pins);

		vkUpdateDescriptorSets(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateFramebuffer(FramebufferCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Framebuffer^ pFramebuffer)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkFramebufferCreateInfo inst_1;		
		VkFramebufferCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pFramebuffer		
		VkFramebuffer inst_3;		
		VkFramebuffer* arg_3 = &inst_3;

		var result = vkCreateFramebuffer(arg_0, arg_1, arg_2, arg_3);
								
		pFramebuffer = gcnew Framebuffer^();
		pFramebuffer->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyFramebuffer(Framebuffer^ framebuffer, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - framebuffer		
		VkFramebuffer arg_1 = framebuffer->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyFramebuffer(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateRenderPass(RenderPassCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out RenderPass^ pRenderPass)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkRenderPassCreateInfo inst_1;		
		VkRenderPassCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_4 pCreateInfo->Attachments		
			VkAttachmentDescription* arg_1_4 = nullptr;		
			VkAttachmentDescription  inst_1_4;		
			if (pCreateInfo != nullptr && pCreateInfo->Attachments != nullptr)		
			{		
				arg_1_4 = &inst_1_4;		
				pCreateInfo->Attachments->CopyTo(arg_1_4, pins);		
				arg_1->pAttachments = arg_1_4;		
			}		
			// FIELD - arg_1_6 pCreateInfo->Subpasses		
			VkSubpassDescription* arg_1_6 = nullptr;		
			VkSubpassDescription  inst_1_6;		
			if (pCreateInfo != nullptr && pCreateInfo->Subpasses != nullptr)		
			{		
				arg_1_6 = &inst_1_6;		
				pCreateInfo->Subpasses->CopyTo(arg_1_6, pins);		
				arg_1->pSubpasses = arg_1_6;		
			}		
			// FIELD - arg_1_6_3 pCreateInfo->Subpasses->InputAttachments		
			VkAttachmentReference* arg_1_6_3 = nullptr;		
			VkAttachmentReference  inst_1_6_3;		
			if (pCreateInfo != nullptr && pCreateInfo->Subpasses != nullptr && pCreateInfo->InputAttachments != nullptr)		
			{		
				arg_1_6_3 = &inst_1_6_3;		
				pCreateInfo->Subpasses->InputAttachments->CopyTo(arg_1_6_3, pins);		
				arg_1->pSubpasses->pInputAttachments = arg_1_6_3;		
			}		
			// FIELD - arg_1_6_5 pCreateInfo->Subpasses->ColorAttachments		
			VkAttachmentReference* arg_1_6_5 = nullptr;		
			VkAttachmentReference  inst_1_6_5;		
			if (pCreateInfo != nullptr && pCreateInfo->Subpasses != nullptr && pCreateInfo->ColorAttachments != nullptr)		
			{		
				arg_1_6_5 = &inst_1_6_5;		
				pCreateInfo->Subpasses->ColorAttachments->CopyTo(arg_1_6_5, pins);		
				arg_1->pSubpasses->pColorAttachments = arg_1_6_5;		
			}		
			// FIELD - arg_1_6_6 pCreateInfo->Subpasses->ResolveAttachments		
			VkAttachmentReference* arg_1_6_6 = nullptr;		
			VkAttachmentReference  inst_1_6_6;		
			if (pCreateInfo != nullptr && pCreateInfo->Subpasses != nullptr && pCreateInfo->ResolveAttachments != nullptr)		
			{		
				arg_1_6_6 = &inst_1_6_6;		
				pCreateInfo->Subpasses->ResolveAttachments->CopyTo(arg_1_6_6, pins);		
				arg_1->pSubpasses->pResolveAttachments = arg_1_6_6;		
			}		
			// FIELD - arg_1_6_7 pCreateInfo->Subpasses->DepthStencilAttachment		
			VkAttachmentReference* arg_1_6_7 = nullptr;		
			VkAttachmentReference  inst_1_6_7;		
			if (pCreateInfo != nullptr && pCreateInfo->Subpasses != nullptr && pCreateInfo->DepthStencilAttachment != nullptr)		
			{		
				arg_1_6_7 = &inst_1_6_7;		
				pCreateInfo->Subpasses->DepthStencilAttachment->CopyTo(arg_1_6_7, pins);		
				arg_1->pSubpasses->pDepthStencilAttachment = arg_1_6_7;		
			}		
			// FIELD - arg_1_8 pCreateInfo->Dependencies		
			VkSubpassDependency* arg_1_8 = nullptr;		
			VkSubpassDependency  inst_1_8;		
			if (pCreateInfo != nullptr && pCreateInfo->Dependencies != nullptr)		
			{		
				arg_1_8 = &inst_1_8;		
				pCreateInfo->Dependencies->CopyTo(arg_1_8, pins);		
				arg_1->pDependencies = arg_1_8;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pRenderPass		
		VkRenderPass inst_3;		
		VkRenderPass* arg_3 = &inst_3;

		var result = vkCreateRenderPass(arg_0, arg_1, arg_2, arg_3);
								
		pRenderPass = gcnew RenderPass^();
		pRenderPass->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyRenderPass(RenderPass^ renderPass, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - renderPass		
		VkRenderPass arg_1 = renderPass->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyRenderPass(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetRenderAreaGranularity(RenderPass^ renderPass, out Extent2D^ pGranularity)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - renderPass		
		VkRenderPass arg_1 = renderPass->mHandle;		
		// INITS 2 - pGranularity		
		VkExtent2D inst_2;		
		VkExtent2D* arg_2 = &inst_2;		
		pGranularity->CopyTo(arg_2 , pins);

		vkGetRenderAreaGranularity(arg_0, arg_1, arg_2);
								
		pGranularity = gcnew Extent2D^();
			pGranularity->CopyFrom(arg_2);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateCommandPool(CommandPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out CommandPool^ pCommandPool)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkCommandPoolCreateInfo inst_1;		
		VkCommandPoolCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pCommandPool		
		VkCommandPool inst_3;		
		VkCommandPool* arg_3 = &inst_3;

		var result = vkCreateCommandPool(arg_0, arg_1, arg_2, arg_3);
								
		pCommandPool = gcnew CommandPool^();
		pCommandPool->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyCommandPool(CommandPool^ commandPool, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - commandPool		
		VkCommandPool arg_1 = commandPool->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroyCommandPool(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::ResetCommandPool(CommandPool^ commandPool, VkCommandPoolResetFlags flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - commandPool		
		VkCommandPool arg_1 = commandPool->mHandle;		
		// INITS 2 - flags		
		VkCommandPoolResetFlags arg_2 = 0;

		var result = vkResetCommandPool(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::AllocateCommandBuffers(CommandBufferAllocateInfo^ pAllocateInfo, CommandBuffer^ pCommandBuffers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pAllocateInfo		
		VkCommandBufferAllocateInfo inst_1;		
		VkCommandBufferAllocateInfo* arg_1 = &inst_1;		
		pAllocateInfo->CopyTo(arg_1 , pins);		
		// INITS 2 - pCommandBuffers		
		VkCommandBuffer inst_2;		
		VkCommandBuffer* arg_2 = &inst_2;

		var result = vkAllocateCommandBuffers(arg_0, arg_1, arg_2);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::FreeCommandBuffers(CommandPool^ commandPool, array<CommandBuffer^>^ pCommandBuffers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkCommandBuffer* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - commandPool		
		VkCommandPool arg_1 = commandPool->mHandle;		
		// INITS 2 - commandBufferCount		
		uint32_t arg_2 = commandBufferCount;		
		// INITS 3 - pCommandBuffers		
		arg_3 = new VkCommandBuffer[commandBufferCount];

		vkFreeCommandBuffers(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateSharedSwapchainsKHR(array<SwapchainCreateInfoKHR^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<SwapchainKHR^>^ pSwapchains)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSwapchainCreateInfoKHR* arg_2 = nullptr;
	VkSwapchainKHR* arg_4 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - swapchainCount		
		uint32_t arg_1 = swapchainCount;		
		// INITS 2 - pCreateInfos		
		arg_2 = new VkSwapchainCreateInfoKHR[swapchainCount];		
			// FIELD - arg_2_7 pCreateInfos->ImageExtent		
			VkExtent2D arg_2_7 = nullptr;		
			VkExtent2D  inst_2_7;		
			if (pCreateInfos != nullptr && pCreateInfos->ImageExtent != nullptr)		
			{		
				arg_2_7 = &inst_2_7;		
				pCreateInfos->ImageExtent->CopyTo(arg_2_7, pins);		
				arg_2->imageExtent = arg_2_7;		
			}		
		// INITS 3 - pAllocator		
		VkAllocationCallbacks inst_3;		
		VkAllocationCallbacks* arg_3 = &inst_3;		
		pAllocator->CopyTo(arg_3 , pins);		
		// INITS 4 - pSwapchains		
		arg_4 = new VkSwapchainKHR[swapchainCount];

		var result = vkCreateSharedSwapchainsKHR(arg_0, arg_1, arg_2, arg_3, arg_4);
			
		int count = (int) swapchainCount;	
		pSwapchains = gcnew array<SwapchainKHR^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pSwapchains[i] = gcnew SwapchainKHR^();	
			pSwapchains[i]->CopyFrom(arg_4[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::CreateSwapchainKHR(SwapchainCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SwapchainKHR^ pSwapchain)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkSwapchainCreateInfoKHR inst_1;		
		VkSwapchainCreateInfoKHR* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_7 pCreateInfo->ImageExtent		
			VkExtent2D arg_1_7 = nullptr;		
			VkExtent2D  inst_1_7;		
			if (pCreateInfo != nullptr && pCreateInfo->ImageExtent != nullptr)		
			{		
				arg_1_7 = &inst_1_7;		
				pCreateInfo->ImageExtent->CopyTo(arg_1_7, pins);		
				arg_1->imageExtent = arg_1_7;		
			}		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pSwapchain		
		VkSwapchainKHR inst_3;		
		VkSwapchainKHR* arg_3 = &inst_3;

		var result = vkCreateSwapchainKHR(arg_0, arg_1, arg_2, arg_3);
								
		pSwapchain = gcnew SwapchainKHR^();
		pSwapchain->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroySwapchainKHR(SwapchainKHR^ swapchain, AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - swapchain		
		VkSwapchainKHR arg_1 = swapchain->mHandle;		
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;		
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);

		vkDestroySwapchainKHR(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::GetSwapchainImagesKHR(SwapchainKHR^ swapchain, out array<Image^>^ pSwapchainImages)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImage* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - swapchain		
		VkSwapchainKHR arg_1 = swapchain->mHandle;		
		// INITS 2 - pSwapchainImageCount		
		uint32_t* arg_2 = pSwapchainImageCount;		
		// INITS 3 - pSwapchainImages		
		arg_3 = new VkImage[pSwapchainImageCount];

		var result = vkGetSwapchainImagesKHR(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pSwapchainImageCount;	
		pSwapchainImages = gcnew array<Image^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pSwapchainImages[i] = gcnew Image^();	
			pSwapchainImages[i]->CopyFrom(arg_3[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Device::AcquireNextImageKHR(SwapchainKHR^ swapchain, UInt64 timeout, Semaphore^ semaphore, Fence^ fence, ref UInt32 pImageIndex)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;		
		// INITS 1 - swapchain		
		VkSwapchainKHR arg_1 = swapchain->mHandle;		
		// INITS 2 - timeout		
		uint64_t arg_2 = timeout;		
		// INITS 3 - semaphore		
		VkSemaphore arg_3 = semaphore->mHandle;		
		// INITS 4 - fence		
		VkFence arg_4 = fence->mHandle;		
		// INITS 5 - pImageIndex		
		uint32_t* arg_5 = pImageIndex;

		var result = vkAcquireNextImageKHR(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


// VkPhysicalDevice
void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceProperties(out PhysicalDeviceProperties^ pProperties)
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
		pProperties->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_7 pProperties->Limits		
			VkPhysicalDeviceLimits arg_1_7 = nullptr;		
			VkPhysicalDeviceLimits  inst_1_7;		
			if (pProperties != nullptr && pProperties->Limits != nullptr)		
			{		
				arg_1_7 = &inst_1_7;		
				pProperties->Limits->CopyTo(arg_1_7, pins);		
				arg_1->limits = arg_1_7;		
			}		
			// FIELD - arg_1_8 pProperties->SparseProperties		
			VkPhysicalDeviceSparseProperties arg_1_8 = nullptr;		
			VkPhysicalDeviceSparseProperties  inst_1_8;		
			if (pProperties != nullptr && pProperties->SparseProperties != nullptr)		
			{		
				arg_1_8 = &inst_1_8;		
				pProperties->SparseProperties->CopyTo(arg_1_8, pins);		
				arg_1->sparseProperties = arg_1_8;		
			}

		vkGetPhysicalDeviceProperties(arg_0, arg_1);
								
		pProperties = gcnew PhysicalDeviceProperties^();
			pProperties->CopyFrom(arg_1);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceQueueFamilyProperties(out array<QueueFamilyProperties^>^ pQueueFamilyProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkQueueFamilyProperties* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - pQueueFamilyPropertyCount		
		uint32_t* arg_1 = pQueueFamilyPropertyCount;		
		// INITS 2 - pQueueFamilyProperties		
		arg_2 = new VkQueueFamilyProperties[pQueueFamilyPropertyCount];		
			// FIELD - arg_2_3 pQueueFamilyProperties->MinImageTransferGranularity		
			VkExtent3D arg_2_3 = nullptr;		
			VkExtent3D  inst_2_3;		
			if (pQueueFamilyProperties != nullptr && pQueueFamilyProperties->MinImageTransferGranularity != nullptr)		
			{		
				arg_2_3 = &inst_2_3;		
				pQueueFamilyProperties->MinImageTransferGranularity->CopyTo(arg_2_3, pins);		
				arg_2->minImageTransferGranularity = arg_2_3;		
			}

		vkGetPhysicalDeviceQueueFamilyProperties(arg_0, arg_1, arg_2);
			
		int count = (int) pQueueFamilyPropertyCount;	
		pQueueFamilyProperties = gcnew array<QueueFamilyProperties^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pQueueFamilyProperties[i] = gcnew QueueFamilyProperties^();	
			pQueueFamilyProperties[i]->CopyFrom(arg_2[i]);
		}	

		
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceMemoryProperties(out PhysicalDeviceMemoryProperties^ pMemoryProperties)
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
		pMemoryProperties->CopyTo(arg_1 , pins);

		vkGetPhysicalDeviceMemoryProperties(arg_0, arg_1);
								
		pMemoryProperties = gcnew PhysicalDeviceMemoryProperties^();
			pMemoryProperties->CopyFrom(arg_1);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFeatures(out PhysicalDeviceFeatures^ pFeatures)
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
		pFeatures->CopyTo(arg_1 , pins);

		vkGetPhysicalDeviceFeatures(arg_0, arg_1);
								
		pFeatures = gcnew PhysicalDeviceFeatures^();
			pFeatures->CopyFrom(arg_1);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFormatProperties(VkFormat format, out FormatProperties^ pFormatProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - format		
		VkFormat arg_1 = format;		
		// INITS 2 - pFormatProperties		
		VkFormatProperties inst_2;		
		VkFormatProperties* arg_2 = &inst_2;		
		pFormatProperties->CopyTo(arg_2 , pins);

		vkGetPhysicalDeviceFormatProperties(arg_0, arg_1, arg_2);
								
		pFormatProperties = gcnew FormatProperties^();
			pFormatProperties->CopyFrom(arg_2);						

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, out ImageFormatProperties^ pImageFormatProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - format		
		VkFormat arg_1 = format;		
		// INITS 2 - type		
		VkImageType arg_2 = type;		
		// INITS 3 - tiling		
		VkImageTiling arg_3 = tiling;		
		// INITS 4 - usage		
		VkImageUsageFlags arg_4 = 0;		
		// INITS 5 - flags		
		VkImageCreateFlags arg_5 = 0;		
		// INITS 6 - pImageFormatProperties		
		VkImageFormatProperties inst_6;		
		VkImageFormatProperties* arg_6 = &inst_6;		
		pImageFormatProperties->CopyTo(arg_6 , pins);		
			// FIELD - arg_6_0 pImageFormatProperties->MaxExtent		
			VkExtent3D arg_6_0 = nullptr;		
			VkExtent3D  inst_6_0;		
			if (pImageFormatProperties != nullptr && pImageFormatProperties->MaxExtent != nullptr)		
			{		
				arg_6_0 = &inst_6_0;		
				pImageFormatProperties->MaxExtent->CopyTo(arg_6_0, pins);		
				arg_6->maxExtent = arg_6_0;		
			}

		var result = vkGetPhysicalDeviceImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);
								
		pImageFormatProperties = gcnew ImageFormatProperties^();
			pImageFormatProperties->CopyFrom(arg_6);						

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::CreateDevice(DeviceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Device^ pDevice)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	const char* const* arg_1_6 = nullptr;
	const char* const* arg_1_8 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - pCreateInfo		
		VkDeviceCreateInfo inst_1;		
		VkDeviceCreateInfo* arg_1 = &inst_1;		
		pCreateInfo->CopyTo(arg_1 , pins);		
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
				int enabledLayerCount = (int) pCreateInfo->EnabledLayerNames->Length;		
				arg_1_6 = new char*[enabledLayerCount];		
				for (int j = 0; j < enabledLayerCount; ++j)		
				{		
					IntPtr inst_1_6 = Marshal::StringToHGlobalAnsi(pCreateInfo->EnabledLayerNames[j]);		
					pins->Add(inst_1_6);		
					arg_1_6[j] = static_cast<char*>(inst_1_6.ToPointer());		
				}		
				arg_1->ppEnabledLayerNames = arg_1_6;		
				arg_1->enabledLayerCount = enabledLayerCount;		
			}		
			// FIELD - arg_1_8 pCreateInfo->EnabledExtensionNames		
			if (pCreateInfo != nullptr && pCreateInfo->EnabledExtensionNames != nullptr)		
			{		
				int enabledExtensionCount = (int) pCreateInfo->EnabledExtensionNames->Length;		
				arg_1_8 = new char*[enabledExtensionCount];		
				for (int j = 0; j < enabledExtensionCount; ++j)		
				{		
					IntPtr inst_1_8 = Marshal::StringToHGlobalAnsi(pCreateInfo->EnabledExtensionNames[j]);		
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
		VkAllocationCallbacks* arg_2 = &inst_2;		
		pAllocator->CopyTo(arg_2 , pins);		
		// INITS 3 - pDevice		
		VkDevice inst_3;		
		VkDevice* arg_3 = &inst_3;

		var result = vkCreateDevice(arg_0, arg_1, arg_2, arg_3);
								
		pDevice = gcnew Device^();
		pDevice->mHandle = inst_3;

		return (VkResult) result;
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
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::EnumerateDeviceLayerProperties(out array<LayerProperties^>^ pProperties)
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

		var firstResult = vkEnumerateDeviceLayerProperties(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return firstResult;
		}

		// MAIN INIT
		
		// INITS 2 - pProperties		
		arg_2 = new VkLayerProperties[pPropertyCount];

		var result = vkEnumerateDeviceLayerProperties(arg_0, arg_1, arg_2);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<LayerProperties^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew LayerProperties^();	
			pProperties[i]->CopyFrom(arg_2[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::EnumerateDeviceExtensionProperties(String^ pLayerName, out array<ExtensionProperties^>^ pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkExtensionProperties* arg_3 = nullptr;
	try
	{
		
		// 1ST CALL		
		// 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// 1 - pLayerName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(arg_1)		
		pins->Add(inst_1)		
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());		
		// 2 - pPropertyCount		
		UInt32 pPropertyCount = 0;		
		UInt32* arg_2 = &pPropertyCount;

		var firstResult = vkEnumerateDeviceExtensionProperties(arg_0, arg_1, arg_2, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return firstResult;
		}

		// MAIN INIT
		
		// INITS 3 - pProperties		
		arg_3 = new VkExtensionProperties[pPropertyCount];

		var result = vkEnumerateDeviceExtensionProperties(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<ExtensionProperties^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew ExtensionProperties^();	
			pProperties[i]->CopyFrom(arg_3[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, out array<SparseImageFormatProperties^>^ pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSparseImageFormatProperties* arg_7 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - format		
		VkFormat arg_1 = format;		
		// INITS 2 - type		
		VkImageType arg_2 = type;		
		// INITS 3 - samples		
		VkSampleCountFlagBits arg_3 = samples;		
		// INITS 4 - usage		
		VkImageUsageFlags arg_4 = 0;		
		// INITS 5 - tiling		
		VkImageTiling arg_5 = tiling;		
		// INITS 6 - pPropertyCount		
		uint32_t* arg_6 = pPropertyCount;		
		// INITS 7 - pProperties		
		arg_7 = new VkSparseImageFormatProperties[pPropertyCount];		
			// FIELD - arg_7_1 pProperties->ImageGranularity		
			VkExtent3D arg_7_1 = nullptr;		
			VkExtent3D  inst_7_1;		
			if (pProperties != nullptr && pProperties->ImageGranularity != nullptr)		
			{		
				arg_7_1 = &inst_7_1;		
				pProperties->ImageGranularity->CopyTo(arg_7_1, pins);		
				arg_7->imageGranularity = arg_7_1;		
			}

		vkGetPhysicalDeviceSparseImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<SparseImageFormatProperties^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew SparseImageFormatProperties^();	
			pProperties[i]->CopyFrom(arg_7[i]);
		}	

		
	}
	finally
	{
		if (arg_7 != nullptr)
		{
			delete[] arg_7;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPropertiesKHR(out array<DisplayPropertiesKHR^>^ pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDisplayPropertiesKHR* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - pPropertyCount		
		uint32_t* arg_1 = pPropertyCount;		
		// INITS 2 - pProperties		
		arg_2 = new VkDisplayPropertiesKHR[pPropertyCount];		
			// FIELD - arg_2_2 pProperties->PhysicalDimensions		
			VkExtent2D arg_2_2 = nullptr;		
			VkExtent2D  inst_2_2;		
			if (pProperties != nullptr && pProperties->PhysicalDimensions != nullptr)		
			{		
				arg_2_2 = &inst_2_2;		
				pProperties->PhysicalDimensions->CopyTo(arg_2_2, pins);		
				arg_2->physicalDimensions = arg_2_2;		
			}		
			// FIELD - arg_2_3 pProperties->PhysicalResolution		
			VkExtent2D arg_2_3 = nullptr;		
			VkExtent2D  inst_2_3;		
			if (pProperties != nullptr && pProperties->PhysicalResolution != nullptr)		
			{		
				arg_2_3 = &inst_2_3;		
				pProperties->PhysicalResolution->CopyTo(arg_2_3, pins);		
				arg_2->physicalResolution = arg_2_3;		
			}

		var result = vkGetPhysicalDeviceDisplayPropertiesKHR(arg_0, arg_1, arg_2);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<DisplayPropertiesKHR^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew DisplayPropertiesKHR^();	
			pProperties[i]->CopyFrom(arg_2[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPlanePropertiesKHR(out array<DisplayPlanePropertiesKHR^>^ pProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDisplayPlanePropertiesKHR* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - pPropertyCount		
		uint32_t* arg_1 = pPropertyCount;		
		// INITS 2 - pProperties		
		arg_2 = new VkDisplayPlanePropertiesKHR[pPropertyCount];

		var result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(arg_0, arg_1, arg_2);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<DisplayPlanePropertiesKHR^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew DisplayPlanePropertiesKHR^();	
			pProperties[i]->CopyFrom(arg_2[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayPlaneSupportedDisplaysKHR(UInt32 planeIndex, out array<DisplayKHR^>^ pDisplays)
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
		// INITS 2 - pDisplayCount		
		uint32_t* arg_2 = pDisplayCount;		
		// INITS 3 - pDisplays		
		arg_3 = new VkDisplayKHR[pDisplayCount];

		var result = vkGetDisplayPlaneSupportedDisplaysKHR(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pDisplayCount;	
		pDisplays = gcnew array<DisplayKHR^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pDisplays[i] = gcnew DisplayKHR^();	
			pDisplays[i]->CopyFrom(arg_3[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayModePropertiesKHR(DisplayKHR^ display, out array<DisplayModePropertiesKHR^>^ pProperties)
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
		uint32_t* arg_2 = pPropertyCount;		
		// INITS 3 - pProperties		
		arg_3 = new VkDisplayModePropertiesKHR[pPropertyCount];		
			// FIELD - arg_3_1 pProperties->Parameters		
			VkDisplayModeParametersKHR arg_3_1 = nullptr;		
			VkDisplayModeParametersKHR  inst_3_1;		
			if (pProperties != nullptr && pProperties->Parameters != nullptr)		
			{		
				arg_3_1 = &inst_3_1;		
				pProperties->Parameters->CopyTo(arg_3_1, pins);		
				arg_3->parameters = arg_3_1;		
			}		
			// FIELD - arg_3_1_0 pProperties->Parameters->VisibleRegion		
			VkExtent2D arg_3_1_0 = nullptr;		
			VkExtent2D  inst_3_1_0;		
			if (pProperties != nullptr && pProperties->Parameters != nullptr && pProperties->VisibleRegion != nullptr)		
			{		
				arg_3_1_0 = &inst_3_1_0;		
				pProperties->Parameters->VisibleRegion->CopyTo(arg_3_1_0, pins);		
				arg_3->parameters->visibleRegion = arg_3_1_0;		
			}

		var result = vkGetDisplayModePropertiesKHR(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pPropertyCount;	
		pProperties = gcnew array<DisplayModePropertiesKHR^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pProperties[i] = gcnew DisplayModePropertiesKHR^();	
			pProperties[i]->CopyFrom(arg_3[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::CreateDisplayModeKHR(DisplayKHR^ display, DisplayModeCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out DisplayModeKHR^ pMode)
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
		VkDisplayModeCreateInfoKHR* arg_2 = &inst_2;		
		pCreateInfo->CopyTo(arg_2 , pins);		
			// FIELD - arg_2_3 pCreateInfo->Parameters		
			VkDisplayModeParametersKHR arg_2_3 = nullptr;		
			VkDisplayModeParametersKHR  inst_2_3;		
			if (pCreateInfo != nullptr && pCreateInfo->Parameters != nullptr)		
			{		
				arg_2_3 = &inst_2_3;		
				pCreateInfo->Parameters->CopyTo(arg_2_3, pins);		
				arg_2->parameters = arg_2_3;		
			}		
			// FIELD - arg_2_3_0 pCreateInfo->Parameters->VisibleRegion		
			VkExtent2D arg_2_3_0 = nullptr;		
			VkExtent2D  inst_2_3_0;		
			if (pCreateInfo != nullptr && pCreateInfo->Parameters != nullptr && pCreateInfo->VisibleRegion != nullptr)		
			{		
				arg_2_3_0 = &inst_2_3_0;		
				pCreateInfo->Parameters->VisibleRegion->CopyTo(arg_2_3_0, pins);		
				arg_2->parameters->visibleRegion = arg_2_3_0;		
			}		
		// INITS 3 - pAllocator		
		VkAllocationCallbacks inst_3;		
		VkAllocationCallbacks* arg_3 = &inst_3;		
		pAllocator->CopyTo(arg_3 , pins);		
		// INITS 4 - pMode		
		VkDisplayModeKHR inst_4;		
		VkDisplayModeKHR* arg_4 = &inst_4;

		var result = vkCreateDisplayModeKHR(arg_0, arg_1, arg_2, arg_3, arg_4);
								
		pMode = gcnew DisplayModeKHR^();
		pMode->mHandle = inst_4;

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayPlaneCapabilitiesKHR(DisplayModeKHR^ mode, UInt32 planeIndex, out DisplayPlaneCapabilitiesKHR^ pCapabilities)
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
		pCapabilities->CopyTo(arg_3 , pins);		
			// FIELD - arg_3_1 pCapabilities->MinSrcPosition		
			VkOffset2D arg_3_1 = nullptr;		
			VkOffset2D  inst_3_1;		
			if (pCapabilities != nullptr && pCapabilities->MinSrcPosition != nullptr)		
			{		
				arg_3_1 = &inst_3_1;		
				pCapabilities->MinSrcPosition->CopyTo(arg_3_1, pins);		
				arg_3->minSrcPosition = arg_3_1;		
			}		
			// FIELD - arg_3_2 pCapabilities->MaxSrcPosition		
			VkOffset2D arg_3_2 = nullptr;		
			VkOffset2D  inst_3_2;		
			if (pCapabilities != nullptr && pCapabilities->MaxSrcPosition != nullptr)		
			{		
				arg_3_2 = &inst_3_2;		
				pCapabilities->MaxSrcPosition->CopyTo(arg_3_2, pins);		
				arg_3->maxSrcPosition = arg_3_2;		
			}		
			// FIELD - arg_3_3 pCapabilities->MinSrcExtent		
			VkExtent2D arg_3_3 = nullptr;		
			VkExtent2D  inst_3_3;		
			if (pCapabilities != nullptr && pCapabilities->MinSrcExtent != nullptr)		
			{		
				arg_3_3 = &inst_3_3;		
				pCapabilities->MinSrcExtent->CopyTo(arg_3_3, pins);		
				arg_3->minSrcExtent = arg_3_3;		
			}		
			// FIELD - arg_3_4 pCapabilities->MaxSrcExtent		
			VkExtent2D arg_3_4 = nullptr;		
			VkExtent2D  inst_3_4;		
			if (pCapabilities != nullptr && pCapabilities->MaxSrcExtent != nullptr)		
			{		
				arg_3_4 = &inst_3_4;		
				pCapabilities->MaxSrcExtent->CopyTo(arg_3_4, pins);		
				arg_3->maxSrcExtent = arg_3_4;		
			}		
			// FIELD - arg_3_5 pCapabilities->MinDstPosition		
			VkOffset2D arg_3_5 = nullptr;		
			VkOffset2D  inst_3_5;		
			if (pCapabilities != nullptr && pCapabilities->MinDstPosition != nullptr)		
			{		
				arg_3_5 = &inst_3_5;		
				pCapabilities->MinDstPosition->CopyTo(arg_3_5, pins);		
				arg_3->minDstPosition = arg_3_5;		
			}		
			// FIELD - arg_3_6 pCapabilities->MaxDstPosition		
			VkOffset2D arg_3_6 = nullptr;		
			VkOffset2D  inst_3_6;		
			if (pCapabilities != nullptr && pCapabilities->MaxDstPosition != nullptr)		
			{		
				arg_3_6 = &inst_3_6;		
				pCapabilities->MaxDstPosition->CopyTo(arg_3_6, pins);		
				arg_3->maxDstPosition = arg_3_6;		
			}		
			// FIELD - arg_3_7 pCapabilities->MinDstExtent		
			VkExtent2D arg_3_7 = nullptr;		
			VkExtent2D  inst_3_7;		
			if (pCapabilities != nullptr && pCapabilities->MinDstExtent != nullptr)		
			{		
				arg_3_7 = &inst_3_7;		
				pCapabilities->MinDstExtent->CopyTo(arg_3_7, pins);		
				arg_3->minDstExtent = arg_3_7;		
			}		
			// FIELD - arg_3_8 pCapabilities->MaxDstExtent		
			VkExtent2D arg_3_8 = nullptr;		
			VkExtent2D  inst_3_8;		
			if (pCapabilities != nullptr && pCapabilities->MaxDstExtent != nullptr)		
			{		
				arg_3_8 = &inst_3_8;		
				pCapabilities->MaxDstExtent->CopyTo(arg_3_8, pins);		
				arg_3->maxDstExtent = arg_3_8;		
			}

		var result = vkGetDisplayPlaneCapabilitiesKHR(arg_0, arg_1, arg_2, arg_3);
								
		pCapabilities = gcnew DisplayPlaneCapabilitiesKHR^();
			pCapabilities->CopyFrom(arg_3);						

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, SurfaceKHR^ surface, ref bool pSupported)
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
		VkBool32* arg_3 = pSupported;

		var result = vkGetPhysicalDeviceSurfaceSupportKHR(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR^ surface, out SurfaceCapabilitiesKHR^ pSurfaceCapabilities)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;		
		// INITS 2 - pSurfaceCapabilities		
		VkSurfaceCapabilitiesKHR inst_2;		
		VkSurfaceCapabilitiesKHR* arg_2 = &inst_2;		
		pSurfaceCapabilities->CopyTo(arg_2 , pins);		
			// FIELD - arg_2_2 pSurfaceCapabilities->CurrentExtent		
			VkExtent2D arg_2_2 = nullptr;		
			VkExtent2D  inst_2_2;		
			if (pSurfaceCapabilities != nullptr && pSurfaceCapabilities->CurrentExtent != nullptr)		
			{		
				arg_2_2 = &inst_2_2;		
				pSurfaceCapabilities->CurrentExtent->CopyTo(arg_2_2, pins);		
				arg_2->currentExtent = arg_2_2;		
			}		
			// FIELD - arg_2_3 pSurfaceCapabilities->MinImageExtent		
			VkExtent2D arg_2_3 = nullptr;		
			VkExtent2D  inst_2_3;		
			if (pSurfaceCapabilities != nullptr && pSurfaceCapabilities->MinImageExtent != nullptr)		
			{		
				arg_2_3 = &inst_2_3;		
				pSurfaceCapabilities->MinImageExtent->CopyTo(arg_2_3, pins);		
				arg_2->minImageExtent = arg_2_3;		
			}		
			// FIELD - arg_2_4 pSurfaceCapabilities->MaxImageExtent		
			VkExtent2D arg_2_4 = nullptr;		
			VkExtent2D  inst_2_4;		
			if (pSurfaceCapabilities != nullptr && pSurfaceCapabilities->MaxImageExtent != nullptr)		
			{		
				arg_2_4 = &inst_2_4;		
				pSurfaceCapabilities->MaxImageExtent->CopyTo(arg_2_4, pins);		
				arg_2->maxImageExtent = arg_2_4;		
			}

		var result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(arg_0, arg_1, arg_2);
								
		pSurfaceCapabilities = gcnew SurfaceCapabilitiesKHR^();
			pSurfaceCapabilities->CopyFrom(arg_2);						

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR^ surface, out array<SurfaceFormatKHR^>^ pSurfaceFormats)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSurfaceFormatKHR* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;		
		// INITS 2 - pSurfaceFormatCount		
		uint32_t* arg_2 = pSurfaceFormatCount;		
		// INITS 3 - pSurfaceFormats		
		arg_3 = new VkSurfaceFormatKHR[pSurfaceFormatCount];

		var result = vkGetPhysicalDeviceSurfaceFormatsKHR(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pSurfaceFormatCount;	
		pSurfaceFormats = gcnew array<SurfaceFormatKHR^>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pSurfaceFormats[i] = gcnew SurfaceFormatKHR^();	
			pSurfaceFormats[i]->CopyFrom(arg_3[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR^ surface, out array<VkPresentModeKHR>^ pPresentModes)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkPresentModeKHR* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - surface		
		VkSurfaceKHR arg_1 = surface->mHandle;		
		// INITS 2 - pPresentModeCount		
		uint32_t* arg_2 = pPresentModeCount;		
		// INITS 3 - pPresentModes		
		arg_3 = new <TYPE>[pPresentModeCount];

		var result = vkGetPhysicalDeviceSurfacePresentModesKHR(arg_0, arg_1, arg_2, arg_3);
			
		int count = (int) pPresentModeCount;	
		pPresentModes = gcnew array<VkPresentModeKHR>^(count);
		for	(int i = 0; i < count; ++i)
		{	
			pPresentModes[i] = gcnew VkPresentModeKHR();	
			pPresentModes[i]->CopyFrom(arg_3[i]);
		}	

		return (VkResult) result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceWin32PresentationSupportKHR(UInt32 queueFamilyIndex)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;		
		// INITS 1 - queueFamilyIndex		
		uint32_t arg_1 = queueFamilyIndex;

		var result = vkGetPhysicalDeviceWin32PresentationSupportKHR(arg_0, arg_1);

		return result != 0;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


// VkQueue
VkResult ManagedVulkan::Queue::QueueSubmit(array<SubmitInfo^>^ pSubmits, Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSubmitInfo* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;		
		// INITS 1 - submitCount		
		uint32_t arg_1 = submitCount;		
		// INITS 2 - pSubmits		
		arg_2 = new VkSubmitInfo[submitCount];		
		// INITS 3 - fence		
		VkFence arg_3 = fence->mHandle;

		var result = vkQueueSubmit(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Queue::QueueWaitIdle()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;

		var result = vkQueueWaitIdle(arg_0);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Queue::QueueBindSparse(array<BindSparseInfo^>^ pBindInfo, Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBindSparseInfo* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;		
		// INITS 1 - bindInfoCount		
		uint32_t arg_1 = bindInfoCount;		
		// INITS 2 - pBindInfo		
		arg_2 = new VkBindSparseInfo[bindInfoCount];		
			// FIELD - arg_2_5 pBindInfo->BufferBinds		
			VkSparseBufferMemoryBindInfo* arg_2_5 = nullptr;		
			VkSparseBufferMemoryBindInfo  inst_2_5;		
			if (pBindInfo != nullptr && pBindInfo->BufferBinds != nullptr)		
			{		
				arg_2_5 = &inst_2_5;		
				pBindInfo->BufferBinds->CopyTo(arg_2_5, pins);		
				arg_2->pBufferBinds = arg_2_5;		
			}		
			// FIELD - arg_2_5_2 pBindInfo->BufferBinds->Binds		
			VkSparseMemoryBind* arg_2_5_2 = nullptr;		
			VkSparseMemoryBind  inst_2_5_2;		
			if (pBindInfo != nullptr && pBindInfo->BufferBinds != nullptr && pBindInfo->Binds != nullptr)		
			{		
				arg_2_5_2 = &inst_2_5_2;		
				pBindInfo->BufferBinds->Binds->CopyTo(arg_2_5_2, pins);		
				arg_2->pBufferBinds->pBinds = arg_2_5_2;		
			}		
			// FIELD - arg_2_7 pBindInfo->ImageOpaqueBinds		
			VkSparseImageOpaqueMemoryBindInfo* arg_2_7 = nullptr;		
			VkSparseImageOpaqueMemoryBindInfo  inst_2_7;		
			if (pBindInfo != nullptr && pBindInfo->ImageOpaqueBinds != nullptr)		
			{		
				arg_2_7 = &inst_2_7;		
				pBindInfo->ImageOpaqueBinds->CopyTo(arg_2_7, pins);		
				arg_2->pImageOpaqueBinds = arg_2_7;		
			}		
			// FIELD - arg_2_7_2 pBindInfo->ImageOpaqueBinds->Binds		
			VkSparseMemoryBind* arg_2_7_2 = nullptr;		
			VkSparseMemoryBind  inst_2_7_2;		
			if (pBindInfo != nullptr && pBindInfo->ImageOpaqueBinds != nullptr && pBindInfo->Binds != nullptr)		
			{		
				arg_2_7_2 = &inst_2_7_2;		
				pBindInfo->ImageOpaqueBinds->Binds->CopyTo(arg_2_7_2, pins);		
				arg_2->pImageOpaqueBinds->pBinds = arg_2_7_2;		
			}		
			// FIELD - arg_2_9 pBindInfo->ImageBinds		
			VkSparseImageMemoryBindInfo* arg_2_9 = nullptr;		
			VkSparseImageMemoryBindInfo  inst_2_9;		
			if (pBindInfo != nullptr && pBindInfo->ImageBinds != nullptr)		
			{		
				arg_2_9 = &inst_2_9;		
				pBindInfo->ImageBinds->CopyTo(arg_2_9, pins);		
				arg_2->pImageBinds = arg_2_9;		
			}		
			// FIELD - arg_2_9_2 pBindInfo->ImageBinds->Binds		
			VkSparseImageMemoryBind* arg_2_9_2 = nullptr;		
			VkSparseImageMemoryBind  inst_2_9_2;		
			if (pBindInfo != nullptr && pBindInfo->ImageBinds != nullptr && pBindInfo->Binds != nullptr)		
			{		
				arg_2_9_2 = &inst_2_9_2;		
				pBindInfo->ImageBinds->Binds->CopyTo(arg_2_9_2, pins);		
				arg_2->pImageBinds->pBinds = arg_2_9_2;		
			}		
			// FIELD - arg_2_9_2_0 pBindInfo->ImageBinds->Binds->Subresource		
			VkImageSubresource arg_2_9_2_0 = nullptr;		
			VkImageSubresource  inst_2_9_2_0;		
			if (pBindInfo != nullptr && pBindInfo->ImageBinds != nullptr && pBindInfo->Binds != nullptr && pBindInfo->Subresource != nullptr)		
			{		
				arg_2_9_2_0 = &inst_2_9_2_0;		
				pBindInfo->ImageBinds->Binds->Subresource->CopyTo(arg_2_9_2_0, pins);		
				arg_2->pImageBinds->pBinds->subresource = arg_2_9_2_0;		
			}		
			// FIELD - arg_2_9_2_1 pBindInfo->ImageBinds->Binds->Offset		
			VkOffset3D arg_2_9_2_1 = nullptr;		
			VkOffset3D  inst_2_9_2_1;		
			if (pBindInfo != nullptr && pBindInfo->ImageBinds != nullptr && pBindInfo->Binds != nullptr && pBindInfo->Offset != nullptr)		
			{		
				arg_2_9_2_1 = &inst_2_9_2_1;		
				pBindInfo->ImageBinds->Binds->Offset->CopyTo(arg_2_9_2_1, pins);		
				arg_2->pImageBinds->pBinds->offset = arg_2_9_2_1;		
			}		
			// FIELD - arg_2_9_2_2 pBindInfo->ImageBinds->Binds->Extent		
			VkExtent3D arg_2_9_2_2 = nullptr;		
			VkExtent3D  inst_2_9_2_2;		
			if (pBindInfo != nullptr && pBindInfo->ImageBinds != nullptr && pBindInfo->Binds != nullptr && pBindInfo->Extent != nullptr)		
			{		
				arg_2_9_2_2 = &inst_2_9_2_2;		
				pBindInfo->ImageBinds->Binds->Extent->CopyTo(arg_2_9_2_2, pins);		
				arg_2->pImageBinds->pBinds->extent = arg_2_9_2_2;		
			}		
		// INITS 3 - fence		
		VkFence arg_3 = fence->mHandle;

		var result = vkQueueBindSparse(arg_0, arg_1, arg_2, arg_3);

		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::Queue::QueuePresentKHR(PresentInfoKHR^ pPresentInfo)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;		
		// INITS 1 - pPresentInfo		
		VkPresentInfoKHR inst_1;		
		VkPresentInfoKHR* arg_1 = &inst_1;		
		pPresentInfo->CopyTo(arg_1 , pins);

		var result = vkQueuePresentKHR(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


// VkCommandBuffer
VkResult ManagedVulkan::CommandBuffer::BeginCommandBuffer(CommandBufferBeginInfo^ pBeginInfo)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - pBeginInfo		
		VkCommandBufferBeginInfo inst_1;		
		VkCommandBufferBeginInfo* arg_1 = &inst_1;		
		pBeginInfo->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_3 pBeginInfo->InheritanceInfo		
			VkCommandBufferInheritanceInfo* arg_1_3 = nullptr;		
			VkCommandBufferInheritanceInfo  inst_1_3;		
			if (pBeginInfo != nullptr && pBeginInfo->InheritanceInfo != nullptr)		
			{		
				arg_1_3 = &inst_1_3;		
				pBeginInfo->InheritanceInfo->CopyTo(arg_1_3, pins);		
				arg_1->pInheritanceInfo = arg_1_3;		
			}

		var result = vkBeginCommandBuffer(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::CommandBuffer::EndCommandBuffer()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;

		var result = vkEndCommandBuffer(arg_0);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

VkResult ManagedVulkan::CommandBuffer::ResetCommandBuffer(VkCommandBufferResetFlags flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - flags		
		VkCommandBufferResetFlags arg_1 = 0;

		var result = vkResetCommandBuffer(arg_0, arg_1);

		return (VkResult) result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, Pipeline^ pipeline)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - pipelineBindPoint		
		VkPipelineBindPoint arg_1 = pipelineBindPoint;		
		// INITS 2 - pipeline		
		VkPipeline arg_2 = pipeline->mHandle;

		vkCmdBindPipeline(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetViewport(UInt32 firstViewport, UInt32 viewportCount, array<Viewport^>^ pViewports)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkViewport* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - firstViewport		
		uint32_t arg_1 = firstViewport;		
		// INITS 2 - viewportCount		
		uint32_t arg_2 = viewportCount;		
		// INITS 3 - pViewports		
		arg_3 = new VkViewport[viewportCount];

		vkCmdSetViewport(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetScissor(UInt32 firstScissor, UInt32 scissorCount, array<Rect2D^>^ pScissors)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkRect2D* arg_3 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - firstScissor		
		uint32_t arg_1 = firstScissor;		
		// INITS 2 - scissorCount		
		uint32_t arg_2 = scissorCount;		
		// INITS 3 - pScissors		
		arg_3 = new VkRect2D[scissorCount];		
			// FIELD - arg_3_0 pScissors->Offset		
			VkOffset2D arg_3_0 = nullptr;		
			VkOffset2D  inst_3_0;		
			if (pScissors != nullptr && pScissors->Offset != nullptr)		
			{		
				arg_3_0 = &inst_3_0;		
				pScissors->Offset->CopyTo(arg_3_0, pins);		
				arg_3->offset = arg_3_0;		
			}		
			// FIELD - arg_3_1 pScissors->Extent		
			VkExtent2D arg_3_1 = nullptr;		
			VkExtent2D  inst_3_1;		
			if (pScissors != nullptr && pScissors->Extent != nullptr)		
			{		
				arg_3_1 = &inst_3_1;		
				pScissors->Extent->CopyTo(arg_3_1, pins);		
				arg_3->extent = arg_3_1;		
			}

		vkCmdSetScissor(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetLineWidth(float lineWidth)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - lineWidth		
		float arg_1 = lineWidth;

		vkCmdSetLineWidth(arg_0, arg_1);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - depthBiasConstantFactor		
		float arg_1 = depthBiasConstantFactor;		
		// INITS 2 - depthBiasClamp		
		float arg_2 = depthBiasClamp;		
		// INITS 3 - depthBiasSlopeFactor		
		float arg_3 = depthBiasSlopeFactor;

		vkCmdSetDepthBias(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetBlendConstants(float blendConstants[4])
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - blendConstants[4]		
		float arg_1 = blendConstants[4];

		vkCmdSetBlendConstants(arg_0, arg_1);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - minDepthBounds		
		float arg_1 = minDepthBounds;		
		// INITS 2 - maxDepthBounds		
		float arg_2 = maxDepthBounds;

		vkCmdSetDepthBounds(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, UInt32 compareMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - faceMask		
		VkStencilFaceFlags arg_1 = 0;		
		// INITS 2 - compareMask		
		uint32_t arg_2 = compareMask;

		vkCmdSetStencilCompareMask(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, UInt32 writeMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - faceMask		
		VkStencilFaceFlags arg_1 = 0;		
		// INITS 2 - writeMask		
		uint32_t arg_2 = writeMask;

		vkCmdSetStencilWriteMask(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetStencilReference(VkStencilFaceFlags faceMask, UInt32 reference)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - faceMask		
		VkStencilFaceFlags arg_1 = 0;		
		// INITS 2 - reference		
		uint32_t arg_2 = reference;

		vkCmdSetStencilReference(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, PipelineLayout^ layout, UInt32 firstSet, UInt32 descriptorSetCount, array<DescriptorSet^>^ pDescriptorSets, UInt32 dynamicOffsetCount, array<UInt32>^ pDynamicOffsets)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDescriptorSet* arg_5 = nullptr;
	uint32_t* arg_7 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - pipelineBindPoint		
		VkPipelineBindPoint arg_1 = pipelineBindPoint;		
		// INITS 2 - layout		
		VkPipelineLayout arg_2 = layout->mHandle;		
		// INITS 3 - firstSet		
		uint32_t arg_3 = firstSet;		
		// INITS 4 - descriptorSetCount		
		uint32_t arg_4 = descriptorSetCount;		
		// INITS 5 - pDescriptorSets		
		arg_5 = new VkDescriptorSet[descriptorSetCount];		
		// INITS 6 - dynamicOffsetCount		
		uint32_t arg_6 = dynamicOffsetCount;		
		// INITS 7 - pDynamicOffsets		
		arg_7 = new <TYPE>[dynamicOffsetCount];

		vkCmdBindDescriptorSets(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		if (arg_7 != nullptr)
		{
			delete[] arg_7;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBindIndexBuffer(Buffer^ buffer, UInt64 offset, VkIndexType indexType)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;		
		// INITS 3 - indexType		
		VkIndexType arg_3 = indexType;

		vkCmdBindIndexBuffer(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBindVertexBuffers(UInt32 firstBinding, UInt32 bindingCount, array<Buffer^>^ pBuffers, array<UInt64>^ pOffsets)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBuffer* arg_3 = nullptr;
	VkDeviceSize* arg_4 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - firstBinding		
		uint32_t arg_1 = firstBinding;		
		// INITS 2 - bindingCount		
		uint32_t arg_2 = bindingCount;		
		// INITS 3 - pBuffers		
		arg_3 = new VkBuffer[bindingCount];		
		// INITS 4 - pOffsets		
		arg_4 = new <TYPE>[bindingCount];

		vkCmdBindVertexBuffers(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDraw(UInt32 vertexCount, UInt32 instanceCount, UInt32 firstVertex, UInt32 firstInstance)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - vertexCount		
		uint32_t arg_1 = vertexCount;		
		// INITS 2 - instanceCount		
		uint32_t arg_2 = instanceCount;		
		// INITS 3 - firstVertex		
		uint32_t arg_3 = firstVertex;		
		// INITS 4 - firstInstance		
		uint32_t arg_4 = firstInstance;

		vkCmdDraw(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDrawIndexed(UInt32 indexCount, UInt32 instanceCount, UInt32 firstIndex, Int32 vertexOffset, UInt32 firstInstance)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - indexCount		
		uint32_t arg_1 = indexCount;		
		// INITS 2 - instanceCount		
		uint32_t arg_2 = instanceCount;		
		// INITS 3 - firstIndex		
		uint32_t arg_3 = firstIndex;		
		// INITS 4 - vertexOffset		
		int32_t arg_4 = vertexOffset;		
		// INITS 5 - firstInstance		
		uint32_t arg_5 = firstInstance;

		vkCmdDrawIndexed(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDrawIndirect(Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;		
		// INITS 3 - drawCount		
		uint32_t arg_3 = drawCount;		
		// INITS 4 - stride		
		uint32_t arg_4 = stride;

		vkCmdDrawIndirect(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDrawIndexedIndirect(Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;		
		// INITS 3 - drawCount		
		uint32_t arg_3 = drawCount;		
		// INITS 4 - stride		
		uint32_t arg_4 = stride;

		vkCmdDrawIndexedIndirect(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDispatch(UInt32 x, UInt32 y, UInt32 z)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - x		
		uint32_t arg_1 = x;		
		// INITS 2 - y		
		uint32_t arg_2 = y;		
		// INITS 3 - z		
		uint32_t arg_3 = z;

		vkCmdDispatch(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDispatchIndirect(Buffer^ buffer, UInt64 offset)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;		
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;

		vkCmdDispatchIndirect(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyBuffer(Buffer^ srcBuffer, Buffer^ dstBuffer, array<BufferCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBufferCopy* arg_4 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcBuffer		
		VkBuffer arg_1 = srcBuffer->mHandle;		
		// INITS 2 - dstBuffer		
		VkBuffer arg_2 = dstBuffer->mHandle;		
		// INITS 3 - regionCount		
		uint32_t arg_3 = regionCount;		
		// INITS 4 - pRegions		
		arg_4 = new VkBufferCopy[regionCount];

		vkCmdCopyBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageCopy* arg_6 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;		
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = srcImageLayout;		
		// INITS 3 - dstImage		
		VkImage arg_3 = dstImage->mHandle;		
		// INITS 4 - dstImageLayout		
		VkImageLayout arg_4 = dstImageLayout;		
		// INITS 5 - regionCount		
		uint32_t arg_5 = regionCount;		
		// INITS 6 - pRegions		
		arg_6 = new VkImageCopy[regionCount];		
			// FIELD - arg_6_0 pRegions->SrcSubresource		
			VkImageSubresourceLayers arg_6_0 = nullptr;		
			VkImageSubresourceLayers  inst_6_0;		
			if (pRegions != nullptr && pRegions->SrcSubresource != nullptr)		
			{		
				arg_6_0 = &inst_6_0;		
				pRegions->SrcSubresource->CopyTo(arg_6_0, pins);		
				arg_6->srcSubresource = arg_6_0;		
			}		
			// FIELD - arg_6_1 pRegions->SrcOffset		
			VkOffset3D arg_6_1 = nullptr;		
			VkOffset3D  inst_6_1;		
			if (pRegions != nullptr && pRegions->SrcOffset != nullptr)		
			{		
				arg_6_1 = &inst_6_1;		
				pRegions->SrcOffset->CopyTo(arg_6_1, pins);		
				arg_6->srcOffset = arg_6_1;		
			}		
			// FIELD - arg_6_2 pRegions->DstSubresource		
			VkImageSubresourceLayers arg_6_2 = nullptr;		
			VkImageSubresourceLayers  inst_6_2;		
			if (pRegions != nullptr && pRegions->DstSubresource != nullptr)		
			{		
				arg_6_2 = &inst_6_2;		
				pRegions->DstSubresource->CopyTo(arg_6_2, pins);		
				arg_6->dstSubresource = arg_6_2;		
			}		
			// FIELD - arg_6_3 pRegions->DstOffset		
			VkOffset3D arg_6_3 = nullptr;		
			VkOffset3D  inst_6_3;		
			if (pRegions != nullptr && pRegions->DstOffset != nullptr)		
			{		
				arg_6_3 = &inst_6_3;		
				pRegions->DstOffset->CopyTo(arg_6_3, pins);		
				arg_6->dstOffset = arg_6_3;		
			}		
			// FIELD - arg_6_4 pRegions->Extent		
			VkExtent3D arg_6_4 = nullptr;		
			VkExtent3D  inst_6_4;		
			if (pRegions != nullptr && pRegions->Extent != nullptr)		
			{		
				arg_6_4 = &inst_6_4;		
				pRegions->Extent->CopyTo(arg_6_4, pins);		
				arg_6->extent = arg_6_4;		
			}

		vkCmdCopyImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);

		
	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBlitImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageBlit^>^ pRegions, VkFilter filter)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageBlit* arg_6 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;		
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = srcImageLayout;		
		// INITS 3 - dstImage		
		VkImage arg_3 = dstImage->mHandle;		
		// INITS 4 - dstImageLayout		
		VkImageLayout arg_4 = dstImageLayout;		
		// INITS 5 - regionCount		
		uint32_t arg_5 = regionCount;		
		// INITS 6 - pRegions		
		arg_6 = new VkImageBlit[regionCount];		
			// FIELD - arg_6_0 pRegions->SrcSubresource		
			VkImageSubresourceLayers arg_6_0 = nullptr;		
			VkImageSubresourceLayers  inst_6_0;		
			if (pRegions != nullptr && pRegions->SrcSubresource != nullptr)		
			{		
				arg_6_0 = &inst_6_0;		
				pRegions->SrcSubresource->CopyTo(arg_6_0, pins);		
				arg_6->srcSubresource = arg_6_0;		
			}		
			// FIELD - arg_6_2 pRegions->DstSubresource		
			VkImageSubresourceLayers arg_6_2 = nullptr;		
			VkImageSubresourceLayers  inst_6_2;		
			if (pRegions != nullptr && pRegions->DstSubresource != nullptr)		
			{		
				arg_6_2 = &inst_6_2;		
				pRegions->DstSubresource->CopyTo(arg_6_2, pins);		
				arg_6->dstSubresource = arg_6_2;		
			}		
		// INITS 7 - filter		
		VkFilter arg_7 = filter;

		vkCmdBlitImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

		
	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyBufferToImage(Buffer^ srcBuffer, Image^ dstImage, VkImageLayout dstImageLayout, array<BufferImageCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBufferImageCopy* arg_5 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcBuffer		
		VkBuffer arg_1 = srcBuffer->mHandle;		
		// INITS 2 - dstImage		
		VkImage arg_2 = dstImage->mHandle;		
		// INITS 3 - dstImageLayout		
		VkImageLayout arg_3 = dstImageLayout;		
		// INITS 4 - regionCount		
		uint32_t arg_4 = regionCount;		
		// INITS 5 - pRegions		
		arg_5 = new VkBufferImageCopy[regionCount];		
			// FIELD - arg_5_3 pRegions->ImageSubresource		
			VkImageSubresourceLayers arg_5_3 = nullptr;		
			VkImageSubresourceLayers  inst_5_3;		
			if (pRegions != nullptr && pRegions->ImageSubresource != nullptr)		
			{		
				arg_5_3 = &inst_5_3;		
				pRegions->ImageSubresource->CopyTo(arg_5_3, pins);		
				arg_5->imageSubresource = arg_5_3;		
			}		
			// FIELD - arg_5_4 pRegions->ImageOffset		
			VkOffset3D arg_5_4 = nullptr;		
			VkOffset3D  inst_5_4;		
			if (pRegions != nullptr && pRegions->ImageOffset != nullptr)		
			{		
				arg_5_4 = &inst_5_4;		
				pRegions->ImageOffset->CopyTo(arg_5_4, pins);		
				arg_5->imageOffset = arg_5_4;		
			}		
			// FIELD - arg_5_5 pRegions->ImageExtent		
			VkExtent3D arg_5_5 = nullptr;		
			VkExtent3D  inst_5_5;		
			if (pRegions != nullptr && pRegions->ImageExtent != nullptr)		
			{		
				arg_5_5 = &inst_5_5;		
				pRegions->ImageExtent->CopyTo(arg_5_5, pins);		
				arg_5->imageExtent = arg_5_5;		
			}

		vkCmdCopyBufferToImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyImageToBuffer(Image^ srcImage, VkImageLayout srcImageLayout, Buffer^ dstBuffer, array<BufferImageCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBufferImageCopy* arg_5 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;		
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = srcImageLayout;		
		// INITS 3 - dstBuffer		
		VkBuffer arg_3 = dstBuffer->mHandle;		
		// INITS 4 - regionCount		
		uint32_t arg_4 = regionCount;		
		// INITS 5 - pRegions		
		arg_5 = new VkBufferImageCopy[regionCount];		
			// FIELD - arg_5_3 pRegions->ImageSubresource		
			VkImageSubresourceLayers arg_5_3 = nullptr;		
			VkImageSubresourceLayers  inst_5_3;		
			if (pRegions != nullptr && pRegions->ImageSubresource != nullptr)		
			{		
				arg_5_3 = &inst_5_3;		
				pRegions->ImageSubresource->CopyTo(arg_5_3, pins);		
				arg_5->imageSubresource = arg_5_3;		
			}		
			// FIELD - arg_5_4 pRegions->ImageOffset		
			VkOffset3D arg_5_4 = nullptr;		
			VkOffset3D  inst_5_4;		
			if (pRegions != nullptr && pRegions->ImageOffset != nullptr)		
			{		
				arg_5_4 = &inst_5_4;		
				pRegions->ImageOffset->CopyTo(arg_5_4, pins);		
				arg_5->imageOffset = arg_5_4;		
			}		
			// FIELD - arg_5_5 pRegions->ImageExtent		
			VkExtent3D arg_5_5 = nullptr;		
			VkExtent3D  inst_5_5;		
			if (pRegions != nullptr && pRegions->ImageExtent != nullptr)		
			{		
				arg_5_5 = &inst_5_5;		
				pRegions->ImageExtent->CopyTo(arg_5_5, pins);		
				arg_5->imageExtent = arg_5_5;		
			}

		vkCmdCopyImageToBuffer(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdUpdateBuffer(Buffer^ dstBuffer, UInt64 dstOffset, UInt64 dataSize, ref UInt32 pData)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - dstBuffer		
		VkBuffer arg_1 = dstBuffer->mHandle;		
		// INITS 2 - dstOffset		
		VkDeviceSize arg_2 = dstOffset;		
		// INITS 3 - dataSize		
		VkDeviceSize arg_3 = dataSize;		
		// INITS 4 - pData		
		uint32_t* arg_4 = pData;

		vkCmdUpdateBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdFillBuffer(Buffer^ dstBuffer, UInt64 dstOffset, UInt64 size, UInt32 data)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - dstBuffer		
		VkBuffer arg_1 = dstBuffer->mHandle;		
		// INITS 2 - dstOffset		
		VkDeviceSize arg_2 = dstOffset;		
		// INITS 3 - size		
		VkDeviceSize arg_3 = size;		
		// INITS 4 - data		
		uint32_t arg_4 = data;

		vkCmdFillBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdClearColorImage(Image^ image, VkImageLayout imageLayout, ClearColorValue^ pColor, array<ImageSubresourceRange^>^ pRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageSubresourceRange* arg_5 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - imageLayout		
		VkImageLayout arg_2 = imageLayout;		
		// INITS 3 - pColor		
		VkClearColorValue inst_3;		
		VkClearColorValue* arg_3 = &inst_3;		
		pColor->CopyTo(arg_3 , pins);		
		// INITS 4 - rangeCount		
		uint32_t arg_4 = rangeCount;		
		// INITS 5 - pRanges		
		arg_5 = new VkImageSubresourceRange[rangeCount];

		vkCmdClearColorImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdClearDepthStencilImage(Image^ image, VkImageLayout imageLayout, ClearDepthStencilValue^ pDepthStencil, array<ImageSubresourceRange^>^ pRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageSubresourceRange* arg_5 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;		
		// INITS 2 - imageLayout		
		VkImageLayout arg_2 = imageLayout;		
		// INITS 3 - pDepthStencil		
		VkClearDepthStencilValue inst_3;		
		VkClearDepthStencilValue* arg_3 = &inst_3;		
		pDepthStencil->CopyTo(arg_3 , pins);		
		// INITS 4 - rangeCount		
		uint32_t arg_4 = rangeCount;		
		// INITS 5 - pRanges		
		arg_5 = new VkImageSubresourceRange[rangeCount];

		vkCmdClearDepthStencilImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdClearAttachments(array<ClearAttachment^>^ pAttachments, array<ClearRect^>^ pRects)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkClearAttachment* arg_2 = nullptr;
	VkClearRect* arg_4 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - attachmentCount		
		uint32_t arg_1 = attachmentCount;		
		// INITS 2 - pAttachments		
		arg_2 = new VkClearAttachment[attachmentCount];		
			// FIELD - arg_2_2 pAttachments->ClearValue		
			VkClearValue arg_2_2 = nullptr;		
			VkClearValue  inst_2_2;		
			if (pAttachments != nullptr && pAttachments->ClearValue != nullptr)		
			{		
				arg_2_2 = &inst_2_2;		
				pAttachments->ClearValue->CopyTo(arg_2_2, pins);		
				arg_2->clearValue = arg_2_2;		
			}		
			// FIELD - arg_2_2_0 pAttachments->ClearValue->Color		
			VkClearColorValue arg_2_2_0 = nullptr;		
			VkClearColorValue  inst_2_2_0;		
			if (pAttachments != nullptr && pAttachments->ClearValue != nullptr && pAttachments->Color != nullptr)		
			{		
				arg_2_2_0 = &inst_2_2_0;		
				pAttachments->ClearValue->Color->CopyTo(arg_2_2_0, pins);		
				arg_2->clearValue->color = arg_2_2_0;		
			}		
			// FIELD - arg_2_2_1 pAttachments->ClearValue->DepthStencil		
			VkClearDepthStencilValue arg_2_2_1 = nullptr;		
			VkClearDepthStencilValue  inst_2_2_1;		
			if (pAttachments != nullptr && pAttachments->ClearValue != nullptr && pAttachments->DepthStencil != nullptr)		
			{		
				arg_2_2_1 = &inst_2_2_1;		
				pAttachments->ClearValue->DepthStencil->CopyTo(arg_2_2_1, pins);		
				arg_2->clearValue->depthStencil = arg_2_2_1;		
			}		
		// INITS 3 - rectCount		
		uint32_t arg_3 = rectCount;		
		// INITS 4 - pRects		
		arg_4 = new VkClearRect[rectCount];		
			// FIELD - arg_4_0 pRects->Rect		
			VkRect2D arg_4_0 = nullptr;		
			VkRect2D  inst_4_0;		
			if (pRects != nullptr && pRects->Rect != nullptr)		
			{		
				arg_4_0 = &inst_4_0;		
				pRects->Rect->CopyTo(arg_4_0, pins);		
				arg_4->rect = arg_4_0;		
			}		
			// FIELD - arg_4_0_0 pRects->Rect->Offset		
			VkOffset2D arg_4_0_0 = nullptr;		
			VkOffset2D  inst_4_0_0;		
			if (pRects != nullptr && pRects->Rect != nullptr && pRects->Offset != nullptr)		
			{		
				arg_4_0_0 = &inst_4_0_0;		
				pRects->Rect->Offset->CopyTo(arg_4_0_0, pins);		
				arg_4->rect->offset = arg_4_0_0;		
			}		
			// FIELD - arg_4_0_1 pRects->Rect->Extent		
			VkExtent2D arg_4_0_1 = nullptr;		
			VkExtent2D  inst_4_0_1;		
			if (pRects != nullptr && pRects->Rect != nullptr && pRects->Extent != nullptr)		
			{		
				arg_4_0_1 = &inst_4_0_1;		
				pRects->Rect->Extent->CopyTo(arg_4_0_1, pins);		
				arg_4->rect->extent = arg_4_0_1;		
			}

		vkCmdClearAttachments(arg_0, arg_1, arg_2, arg_3, arg_4);

		
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdResolveImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageResolve^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageResolve* arg_6 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;		
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = srcImageLayout;		
		// INITS 3 - dstImage		
		VkImage arg_3 = dstImage->mHandle;		
		// INITS 4 - dstImageLayout		
		VkImageLayout arg_4 = dstImageLayout;		
		// INITS 5 - regionCount		
		uint32_t arg_5 = regionCount;		
		// INITS 6 - pRegions		
		arg_6 = new VkImageResolve[regionCount];		
			// FIELD - arg_6_0 pRegions->SrcSubresource		
			VkImageSubresourceLayers arg_6_0 = nullptr;		
			VkImageSubresourceLayers  inst_6_0;		
			if (pRegions != nullptr && pRegions->SrcSubresource != nullptr)		
			{		
				arg_6_0 = &inst_6_0;		
				pRegions->SrcSubresource->CopyTo(arg_6_0, pins);		
				arg_6->srcSubresource = arg_6_0;		
			}		
			// FIELD - arg_6_1 pRegions->SrcOffset		
			VkOffset3D arg_6_1 = nullptr;		
			VkOffset3D  inst_6_1;		
			if (pRegions != nullptr && pRegions->SrcOffset != nullptr)		
			{		
				arg_6_1 = &inst_6_1;		
				pRegions->SrcOffset->CopyTo(arg_6_1, pins);		
				arg_6->srcOffset = arg_6_1;		
			}		
			// FIELD - arg_6_2 pRegions->DstSubresource		
			VkImageSubresourceLayers arg_6_2 = nullptr;		
			VkImageSubresourceLayers  inst_6_2;		
			if (pRegions != nullptr && pRegions->DstSubresource != nullptr)		
			{		
				arg_6_2 = &inst_6_2;		
				pRegions->DstSubresource->CopyTo(arg_6_2, pins);		
				arg_6->dstSubresource = arg_6_2;		
			}		
			// FIELD - arg_6_3 pRegions->DstOffset		
			VkOffset3D arg_6_3 = nullptr;		
			VkOffset3D  inst_6_3;		
			if (pRegions != nullptr && pRegions->DstOffset != nullptr)		
			{		
				arg_6_3 = &inst_6_3;		
				pRegions->DstOffset->CopyTo(arg_6_3, pins);		
				arg_6->dstOffset = arg_6_3;		
			}		
			// FIELD - arg_6_4 pRegions->Extent		
			VkExtent3D arg_6_4 = nullptr;		
			VkExtent3D  inst_6_4;		
			if (pRegions != nullptr && pRegions->Extent != nullptr)		
			{		
				arg_6_4 = &inst_6_4;		
				pRegions->Extent->CopyTo(arg_6_4, pins);		
				arg_6->extent = arg_6_4;		
			}

		vkCmdResolveImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);

		
	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetEvent(Event^ event, VkPipelineStageFlags stageMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;		
		// INITS 2 - stageMask		
		VkPipelineStageFlags arg_2 = 0;

		vkCmdSetEvent(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdResetEvent(Event^ event, VkPipelineStageFlags stageMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;		
		// INITS 2 - stageMask		
		VkPipelineStageFlags arg_2 = 0;

		vkCmdResetEvent(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdWaitEvents(array<Event^>^ pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, array<MemoryBarrier^>^ pMemoryBarriers, array<BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ImageMemoryBarrier^>^ pImageMemoryBarriers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkEvent* arg_2 = nullptr;
	VkMemoryBarrier* arg_6 = nullptr;
	VkBufferMemoryBarrier* arg_8 = nullptr;
	VkImageMemoryBarrier* arg_10 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - eventCount		
		uint32_t arg_1 = eventCount;		
		// INITS 2 - pEvents		
		arg_2 = new VkEvent[eventCount];		
		// INITS 3 - srcStageMask		
		VkPipelineStageFlags arg_3 = 0;		
		// INITS 4 - dstStageMask		
		VkPipelineStageFlags arg_4 = 0;		
		// INITS 5 - memoryBarrierCount		
		uint32_t arg_5 = memoryBarrierCount;		
		// INITS 6 - pMemoryBarriers		
		arg_6 = new VkMemoryBarrier[memoryBarrierCount];		
		// INITS 7 - bufferMemoryBarrierCount		
		uint32_t arg_7 = bufferMemoryBarrierCount;		
		// INITS 8 - pBufferMemoryBarriers		
		arg_8 = new VkBufferMemoryBarrier[bufferMemoryBarrierCount];		
		// INITS 9 - imageMemoryBarrierCount		
		uint32_t arg_9 = imageMemoryBarrierCount;		
		// INITS 10 - pImageMemoryBarriers		
		arg_10 = new VkImageMemoryBarrier[imageMemoryBarrierCount];		
			// FIELD - arg_10_9 pImageMemoryBarriers->SubresourceRange		
			VkImageSubresourceRange arg_10_9 = nullptr;		
			VkImageSubresourceRange  inst_10_9;		
			if (pImageMemoryBarriers != nullptr && pImageMemoryBarriers->SubresourceRange != nullptr)		
			{		
				arg_10_9 = &inst_10_9;		
				pImageMemoryBarriers->SubresourceRange->CopyTo(arg_10_9, pins);		
				arg_10->subresourceRange = arg_10_9;		
			}

		vkCmdWaitEvents(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7, arg_8, arg_9, arg_10);

		
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		if (arg_8 != nullptr)
		{
			delete[] arg_8;
		}
		if (arg_10 != nullptr)
		{
			delete[] arg_10;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, array<MemoryBarrier^>^ pMemoryBarriers, array<BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ImageMemoryBarrier^>^ pImageMemoryBarriers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkMemoryBarrier* arg_5 = nullptr;
	VkBufferMemoryBarrier* arg_7 = nullptr;
	VkImageMemoryBarrier* arg_9 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - srcStageMask		
		VkPipelineStageFlags arg_1 = 0;		
		// INITS 2 - dstStageMask		
		VkPipelineStageFlags arg_2 = 0;		
		// INITS 3 - dependencyFlags		
		VkDependencyFlags arg_3 = 0;		
		// INITS 4 - memoryBarrierCount		
		uint32_t arg_4 = memoryBarrierCount;		
		// INITS 5 - pMemoryBarriers		
		arg_5 = new VkMemoryBarrier[memoryBarrierCount];		
		// INITS 6 - bufferMemoryBarrierCount		
		uint32_t arg_6 = bufferMemoryBarrierCount;		
		// INITS 7 - pBufferMemoryBarriers		
		arg_7 = new VkBufferMemoryBarrier[bufferMemoryBarrierCount];		
		// INITS 8 - imageMemoryBarrierCount		
		uint32_t arg_8 = imageMemoryBarrierCount;		
		// INITS 9 - pImageMemoryBarriers		
		arg_9 = new VkImageMemoryBarrier[imageMemoryBarrierCount];		
			// FIELD - arg_9_9 pImageMemoryBarriers->SubresourceRange		
			VkImageSubresourceRange arg_9_9 = nullptr;		
			VkImageSubresourceRange  inst_9_9;		
			if (pImageMemoryBarriers != nullptr && pImageMemoryBarriers->SubresourceRange != nullptr)		
			{		
				arg_9_9 = &inst_9_9;		
				pImageMemoryBarriers->SubresourceRange->CopyTo(arg_9_9, pins);		
				arg_9->subresourceRange = arg_9_9;		
			}

		vkCmdPipelineBarrier(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7, arg_8, arg_9);

		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		if (arg_7 != nullptr)
		{
			delete[] arg_7;
		}
		if (arg_9 != nullptr)
		{
			delete[] arg_9;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBeginQuery(QueryPool^ queryPool, UInt32 query, VkQueryControlFlags flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;		
		// INITS 2 - query		
		uint32_t arg_2 = query;		
		// INITS 3 - flags		
		VkQueryControlFlags arg_3 = 0;

		vkCmdBeginQuery(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdEndQuery(QueryPool^ queryPool, UInt32 query)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;		
		// INITS 2 - query		
		uint32_t arg_2 = query;

		vkCmdEndQuery(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdResetQueryPool(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;		
		// INITS 2 - firstQuery		
		uint32_t arg_2 = firstQuery;		
		// INITS 3 - queryCount		
		uint32_t arg_3 = queryCount;

		vkCmdResetQueryPool(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, QueryPool^ queryPool, UInt32 query)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - pipelineStage		
		VkPipelineStageFlagBits arg_1 = pipelineStage;		
		// INITS 2 - queryPool		
		VkQueryPool arg_2 = queryPool->mHandle;		
		// INITS 3 - query		
		uint32_t arg_3 = query;

		vkCmdWriteTimestamp(arg_0, arg_1, arg_2, arg_3);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyQueryPoolResults(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, Buffer^ dstBuffer, UInt64 dstOffset, UInt64 stride, VkQueryResultFlags flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;		
		// INITS 2 - firstQuery		
		uint32_t arg_2 = firstQuery;		
		// INITS 3 - queryCount		
		uint32_t arg_3 = queryCount;		
		// INITS 4 - dstBuffer		
		VkBuffer arg_4 = dstBuffer->mHandle;		
		// INITS 5 - dstOffset		
		VkDeviceSize arg_5 = dstOffset;		
		// INITS 6 - stride		
		VkDeviceSize arg_6 = stride;		
		// INITS 7 - flags		
		VkQueryResultFlags arg_7 = 0;

		vkCmdCopyQueryPoolResults(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdPushConstants(PipelineLayout^ layout, VkShaderStageFlags stageFlags, UInt32 offset, UInt32 size, IntPtr pValues)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - layout		
		VkPipelineLayout arg_1 = layout->mHandle;		
		// INITS 2 - stageFlags		
		VkShaderStageFlags arg_2 = 0;		
		// INITS 3 - offset		
		uint32_t arg_3 = offset;		
		// INITS 4 - size		
		uint32_t arg_4 = size;		
		// INITS 5 - pValues		
		void* arg_5 = 0;

		vkCmdPushConstants(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBeginRenderPass(RenderPassBeginInfo^ pRenderPassBegin, VkSubpassContents contents)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - pRenderPassBegin		
		VkRenderPassBeginInfo inst_1;		
		VkRenderPassBeginInfo* arg_1 = &inst_1;		
		pRenderPassBegin->CopyTo(arg_1 , pins);		
			// FIELD - arg_1_4 pRenderPassBegin->RenderArea		
			VkRect2D arg_1_4 = nullptr;		
			VkRect2D  inst_1_4;		
			if (pRenderPassBegin != nullptr && pRenderPassBegin->RenderArea != nullptr)		
			{		
				arg_1_4 = &inst_1_4;		
				pRenderPassBegin->RenderArea->CopyTo(arg_1_4, pins);		
				arg_1->renderArea = arg_1_4;		
			}		
			// FIELD - arg_1_4_0 pRenderPassBegin->RenderArea->Offset		
			VkOffset2D arg_1_4_0 = nullptr;		
			VkOffset2D  inst_1_4_0;		
			if (pRenderPassBegin != nullptr && pRenderPassBegin->RenderArea != nullptr && pRenderPassBegin->Offset != nullptr)		
			{		
				arg_1_4_0 = &inst_1_4_0;		
				pRenderPassBegin->RenderArea->Offset->CopyTo(arg_1_4_0, pins);		
				arg_1->renderArea->offset = arg_1_4_0;		
			}		
			// FIELD - arg_1_4_1 pRenderPassBegin->RenderArea->Extent		
			VkExtent2D arg_1_4_1 = nullptr;		
			VkExtent2D  inst_1_4_1;		
			if (pRenderPassBegin != nullptr && pRenderPassBegin->RenderArea != nullptr && pRenderPassBegin->Extent != nullptr)		
			{		
				arg_1_4_1 = &inst_1_4_1;		
				pRenderPassBegin->RenderArea->Extent->CopyTo(arg_1_4_1, pins);		
				arg_1->renderArea->extent = arg_1_4_1;		
			}		
			// FIELD - arg_1_6 pRenderPassBegin->ClearValues		
			VkClearValue* arg_1_6 = nullptr;		
			VkClearValue  inst_1_6;		
			if (pRenderPassBegin != nullptr && pRenderPassBegin->ClearValues != nullptr)		
			{		
				arg_1_6 = &inst_1_6;		
				pRenderPassBegin->ClearValues->CopyTo(arg_1_6, pins);		
				arg_1->pClearValues = arg_1_6;		
			}		
			// FIELD - arg_1_6_0 pRenderPassBegin->ClearValues->Color		
			VkClearColorValue arg_1_6_0 = nullptr;		
			VkClearColorValue  inst_1_6_0;		
			if (pRenderPassBegin != nullptr && pRenderPassBegin->ClearValues != nullptr && pRenderPassBegin->Color != nullptr)		
			{		
				arg_1_6_0 = &inst_1_6_0;		
				pRenderPassBegin->ClearValues->Color->CopyTo(arg_1_6_0, pins);		
				arg_1->pClearValues->color = arg_1_6_0;		
			}		
			// FIELD - arg_1_6_1 pRenderPassBegin->ClearValues->DepthStencil		
			VkClearDepthStencilValue arg_1_6_1 = nullptr;		
			VkClearDepthStencilValue  inst_1_6_1;		
			if (pRenderPassBegin != nullptr && pRenderPassBegin->ClearValues != nullptr && pRenderPassBegin->DepthStencil != nullptr)		
			{		
				arg_1_6_1 = &inst_1_6_1;		
				pRenderPassBegin->ClearValues->DepthStencil->CopyTo(arg_1_6_1, pins);		
				arg_1->pClearValues->depthStencil = arg_1_6_1;		
			}		
		// INITS 2 - contents		
		VkSubpassContents arg_2 = contents;

		vkCmdBeginRenderPass(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdNextSubpass(VkSubpassContents contents)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - contents		
		VkSubpassContents arg_1 = contents;

		vkCmdNextSubpass(arg_0, arg_1);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdEndRenderPass()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;

		vkCmdEndRenderPass(arg_0);

		
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdExecuteCommands(array<CommandBuffer^>^ pCommandBuffers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkCommandBuffer* arg_2 = nullptr;
	try
	{
		// MAIN INIT
		
		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;		
		// INITS 1 - commandBufferCount		
		uint32_t arg_1 = commandBufferCount;		
		// INITS 2 - pCommandBuffers		
		arg_2 = new VkCommandBuffer[commandBufferCount];

		vkCmdExecuteCommands(arg_0, arg_1, arg_2);

		
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		foreach(var str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

