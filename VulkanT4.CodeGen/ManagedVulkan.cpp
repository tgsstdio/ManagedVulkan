// This is the main DLL file.
#include <vulkan/vulkan.h>
#include "ManagedVulkan.h"


// Vulkan
VkResult ManagedVulkan::Vulkan::CreateInstance(InstanceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Instance^ pInstance)
{
	try
	{
		// 0 - pCreateInfo
		VkInstanceCreateInfo inst_0;
		VkInstanceCreateInfo* arg_0 = &inst_0;
		pCreateInfo->CopyTo(arg_0);
		// 1 - pAllocator
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = &inst_1;
		pAllocator->CopyTo(arg_1);
		// 2 - pInstance
		VkInstance inst_2;
		VkInstance* arg_2 = &inst_2;


		var result = vkCreateInstance(arg_0, arg_1, arg_2);

								
		pInstance = gcnew Instance^();
		pInstance->mHandle = inst_2;

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Vulkan::EnumerateInstanceLayerProperties(out array<LayerProperties^>^ pProperties)
{
	VkLayerProperties* arg_1 = nullptr;
	try
	{
		// 0 - pPropertyCount
		uint32_t* arg_0 = 0;
		// 1 - pProperties
		arg_1 = new VkLayerProperties[pPropertyCount];


		var result = vkEnumerateInstanceLayerProperties(arg_0, arg_1);

			
		int count = pPropertyCount;	
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
	}
}

VkResult ManagedVulkan::Vulkan::EnumerateInstanceExtensionProperties(String^ pLayerName, out array<ExtensionProperties^>^ pProperties)
{
	VkExtensionProperties* arg_2 = nullptr;
	try
	{
		// 0 - pLayerName
		char* arg_0 = 0;
		// 1 - pPropertyCount
		uint32_t* arg_1 = 0;
		// 2 - pProperties
		arg_2 = new VkExtensionProperties[pPropertyCount];


		var result = vkEnumerateInstanceExtensionProperties(arg_0, arg_1, arg_2);

			
		int count = pPropertyCount;	
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
	}
}


// VkInstance
void ManagedVulkan::Instance::DestroyInstance(AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - pAllocator
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = &inst_1;
		pAllocator->CopyTo(arg_1);


		vkDestroyInstance(arg_0, arg_1);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Instance::EnumeratePhysicalDevices(out array<PhysicalDevice^>^ pPhysicalDevices)
{
	VkPhysicalDevice* arg_2 = nullptr;
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - pPhysicalDeviceCount
		uint32_t* arg_1 = 0;
		// 2 - pPhysicalDevices
		arg_2 = new VkPhysicalDevice[pPhysicalDeviceCount];


		var result = vkEnumeratePhysicalDevices(arg_0, arg_1, arg_2);

			
		int count = pPhysicalDeviceCount;	
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
	}
}

PFN_vkVoidFunction ManagedVulkan::Instance::GetInstanceProcAddr(String^ pName)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - pName
		char* arg_1 = 0;


		var result = vkGetInstanceProcAddr(arg_0, arg_1);


		return (PFN_vkVoidFunction) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Instance::CreateDisplayPlaneSurfaceKHR(DisplaySurfaceCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SurfaceKHR^ pSurface)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkDisplaySurfaceCreateInfoKHR inst_1;
		VkDisplaySurfaceCreateInfoKHR* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pSurface
		VkSurfaceKHR inst_3;
		VkSurfaceKHR* arg_3 = &inst_3;


		var result = vkCreateDisplayPlaneSurfaceKHR(arg_0, arg_1, arg_2, arg_3);

								
		pSurface = gcnew SurfaceKHR^();
		pSurface->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Instance::DestroySurfaceKHR(SurfaceKHR^ surface, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - surface
		VkSurfaceKHR arg_1 = surface->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroySurfaceKHR(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Instance::CreateWin32SurfaceKHR(Win32SurfaceCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SurfaceKHR^ pSurface)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkWin32SurfaceCreateInfoKHR inst_1;
		VkWin32SurfaceCreateInfoKHR* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pSurface
		VkSurfaceKHR inst_3;
		VkSurfaceKHR* arg_3 = &inst_3;


		var result = vkCreateWin32SurfaceKHR(arg_0, arg_1, arg_2, arg_3);

								
		pSurface = gcnew SurfaceKHR^();
		pSurface->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Instance::CreateDebugReportCallbackEXT(DebugReportCallbackCreateInfoEXT^ pCreateInfo, AllocationCallbacks^ pAllocator, out DebugReportCallbackEXT^ pCallback)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkDebugReportCallbackCreateInfoEXT inst_1;
		VkDebugReportCallbackCreateInfoEXT* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pCallback
		VkDebugReportCallbackEXT inst_3;
		VkDebugReportCallbackEXT* arg_3 = &inst_3;


		var result = vkCreateDebugReportCallbackEXT(arg_0, arg_1, arg_2, arg_3);

								
		pCallback = gcnew DebugReportCallbackEXT^();
		pCallback->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Instance::DestroyDebugReportCallbackEXT(DebugReportCallbackEXT^ callback, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - callback
		VkDebugReportCallbackEXT arg_1 = callback->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyDebugReportCallbackEXT(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::Instance::DebugReportMessageEXT(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, UInt64 object, IntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage)
{
	try
	{
		// 0 - instance
		VkInstance arg_0 = this->mHandle;
		// 1 - flags
		VkDebugReportFlagsEXT arg_1 = 0;
		// 2 - objectType
		VkDebugReportObjectTypeEXT arg_2 = objectType;
		// 3 - object
		uint64_t arg_3 = 0;
		// 4 - location
		size_t arg_4 = 0;
		// 5 - messageCode
		int32_t arg_5 = 0;
		// 6 - pLayerPrefix
		char* arg_6 = 0;
		// 7 - pMessage
		char* arg_7 = 0;


		vkDebugReportMessageEXT(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


		
	}
	finally
	{
	}
}


// VkDevice
PFN_vkVoidFunction ManagedVulkan::Device::GetDeviceProcAddr(String^ pName)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pName
		char* arg_1 = 0;


		var result = vkGetDeviceProcAddr(arg_0, arg_1);


		return (PFN_vkVoidFunction) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyDevice(AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pAllocator
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = &inst_1;
		pAllocator->CopyTo(arg_1);


		vkDestroyDevice(arg_0, arg_1);


		
	}
	finally
	{
	}
}

void ManagedVulkan::Device::GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, out Queue^ pQueue)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - queueFamilyIndex
		uint32_t arg_1 = 0;
		// 2 - queueIndex
		uint32_t arg_2 = 0;
		// 3 - pQueue
		VkQueue inst_3;
		VkQueue* arg_3 = &inst_3;


		vkGetDeviceQueue(arg_0, arg_1, arg_2, arg_3);

								
		pQueue = gcnew Queue^();
		pQueue->mHandle = inst_3;

		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::DeviceWaitIdle()
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;


		var result = vkDeviceWaitIdle(arg_0);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::AllocateMemory(MemoryAllocateInfo^ pAllocateInfo, AllocationCallbacks^ pAllocator, DeviceMemory^ pMemory)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pAllocateInfo
		VkMemoryAllocateInfo inst_1;
		VkMemoryAllocateInfo* arg_1 = &inst_1;
		pAllocateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pMemory
		VkDeviceMemory* arg_3 = pMemory->mHandle;


		var result = vkAllocateMemory(arg_0, arg_1, arg_2, arg_3);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::FreeMemory(DeviceMemory^ memory, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - memory
		VkDeviceMemory arg_1 = memory->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkFreeMemory(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::MapMemory(DeviceMemory^ memory, UInt64 offset, UInt64 size, VkMemoryMapFlags flags, ref IntPtr ppData)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - memory
		VkDeviceMemory arg_1 = memory->mHandle;
		// 2 - offset
		VkDeviceSize arg_2 = 0;
		// 3 - size
		VkDeviceSize arg_3 = 0;
		// 4 - flags
		VkMemoryMapFlags arg_4 = 0;
		// 5 - ppData
		void** arg_5 = 0;


		var result = vkMapMemory(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::UnmapMemory(DeviceMemory^ memory)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - memory
		VkDeviceMemory arg_1 = memory->mHandle;


		vkUnmapMemory(arg_0, arg_1);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::FlushMappedMemoryRanges(array<MappedMemoryRange^>^ pMemoryRanges)
{
	VkMappedMemoryRange* arg_2 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - memoryRangeCount
		uint32_t arg_1 = 0;
		// 2 - pMemoryRanges
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
	}
}

VkResult ManagedVulkan::Device::InvalidateMappedMemoryRanges(array<MappedMemoryRange^>^ pMemoryRanges)
{
	VkMappedMemoryRange* arg_2 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - memoryRangeCount
		uint32_t arg_1 = 0;
		// 2 - pMemoryRanges
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
	}
}

void ManagedVulkan::Device::GetDeviceMemoryCommitment(DeviceMemory^ memory, ref UInt64 pCommittedMemoryInBytes)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - memory
		VkDeviceMemory arg_1 = memory->mHandle;
		// 2 - pCommittedMemoryInBytes
		VkDeviceSize* arg_2 = 0;


		vkGetDeviceMemoryCommitment(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::Device::GetBufferMemoryRequirements(Buffer^ buffer, out MemoryRequirements^ pMemoryRequirements)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - pMemoryRequirements
		VkMemoryRequirements inst_2;
		VkMemoryRequirements* arg_2 = &inst_2;
		pMemoryRequirements->CopyTo(arg_2);


		vkGetBufferMemoryRequirements(arg_0, arg_1, arg_2);

								
		pMemoryRequirements = gcnew MemoryRequirements^();
			pMemoryRequirements->CopyFrom(arg_2);						

		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::BindBufferMemory(Buffer^ buffer, DeviceMemory^ memory, UInt64 memoryOffset)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - memory
		VkDeviceMemory arg_2 = memory->mHandle;
		// 3 - memoryOffset
		VkDeviceSize arg_3 = 0;


		var result = vkBindBufferMemory(arg_0, arg_1, arg_2, arg_3);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::GetImageMemoryRequirements(Image^ image, out MemoryRequirements^ pMemoryRequirements)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - pMemoryRequirements
		VkMemoryRequirements inst_2;
		VkMemoryRequirements* arg_2 = &inst_2;
		pMemoryRequirements->CopyTo(arg_2);


		vkGetImageMemoryRequirements(arg_0, arg_1, arg_2);

								
		pMemoryRequirements = gcnew MemoryRequirements^();
			pMemoryRequirements->CopyFrom(arg_2);						

		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::BindImageMemory(Image^ image, DeviceMemory^ memory, UInt64 memoryOffset)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - memory
		VkDeviceMemory arg_2 = memory->mHandle;
		// 3 - memoryOffset
		VkDeviceSize arg_3 = 0;


		var result = vkBindImageMemory(arg_0, arg_1, arg_2, arg_3);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::GetImageSparseMemoryRequirements(Image^ image, out array<SparseImageMemoryRequirements^>^ pSparseMemoryRequirements)
{
	VkSparseImageMemoryRequirements* arg_3 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - pSparseMemoryRequirementCount
		uint32_t* arg_2 = 0;
		// 3 - pSparseMemoryRequirements
		arg_3 = new VkSparseImageMemoryRequirements[pSparseMemoryRequirementCount];


		vkGetImageSparseMemoryRequirements(arg_0, arg_1, arg_2, arg_3);

			
		int count = pSparseMemoryRequirementCount;	
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
	}
}

VkResult ManagedVulkan::Device::CreateFence(FenceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Fence^ pFence)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkFenceCreateInfo inst_1;
		VkFenceCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pFence
		VkFence inst_3;
		VkFence* arg_3 = &inst_3;


		var result = vkCreateFence(arg_0, arg_1, arg_2, arg_3);

								
		pFence = gcnew Fence^();
		pFence->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyFence(Fence^ fence, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - fence
		VkFence arg_1 = fence->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyFence(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::ResetFences(array<Fence^>^ pFences)
{
	VkFence* arg_2 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - fenceCount
		uint32_t arg_1 = 0;
		// 2 - pFences
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
	}
}

VkResult ManagedVulkan::Device::GetFenceStatus(Fence^ fence)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - fence
		VkFence arg_1 = fence->mHandle;


		var result = vkGetFenceStatus(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::WaitForFences(array<Fence^>^ pFences, bool waitAll, UInt64 timeout)
{
	VkFence* arg_2 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - fenceCount
		uint32_t arg_1 = 0;
		// 2 - pFences
		arg_2 = new VkFence[fenceCount];
		// 3 - waitAll
		VkBool32 arg_3 = 0;
		// 4 - timeout
		uint64_t arg_4 = 0;


		var result = vkWaitForFences(arg_0, arg_1, arg_2, arg_3, arg_4);


		return (VkResult) result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
	}
}

VkResult ManagedVulkan::Device::CreateSemaphore(SemaphoreCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Semaphore^ pSemaphore)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkSemaphoreCreateInfo inst_1;
		VkSemaphoreCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pSemaphore
		VkSemaphore inst_3;
		VkSemaphore* arg_3 = &inst_3;


		var result = vkCreateSemaphore(arg_0, arg_1, arg_2, arg_3);

								
		pSemaphore = gcnew Semaphore^();
		pSemaphore->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroySemaphore(Semaphore^ semaphore, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - semaphore
		VkSemaphore arg_1 = semaphore->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroySemaphore(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateEvent(EventCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Event^ pEvent)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkEventCreateInfo inst_1;
		VkEventCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pEvent
		VkEvent inst_3;
		VkEvent* arg_3 = &inst_3;


		var result = vkCreateEvent(arg_0, arg_1, arg_2, arg_3);

								
		pEvent = gcnew Event^();
		pEvent->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyEvent(Event^ event, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - event
		VkEvent arg_1 = event->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyEvent(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::GetEventStatus(Event^ event)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - event
		VkEvent arg_1 = event->mHandle;


		var result = vkGetEventStatus(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::SetEvent(Event^ event)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - event
		VkEvent arg_1 = event->mHandle;


		var result = vkSetEvent(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::ResetEvent(Event^ event)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - event
		VkEvent arg_1 = event->mHandle;


		var result = vkResetEvent(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateQueryPool(QueryPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out QueryPool^ pQueryPool)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkQueryPoolCreateInfo inst_1;
		VkQueryPoolCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pQueryPool
		VkQueryPool inst_3;
		VkQueryPool* arg_3 = &inst_3;


		var result = vkCreateQueryPool(arg_0, arg_1, arg_2, arg_3);

								
		pQueryPool = gcnew QueryPool^();
		pQueryPool->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyQueryPool(QueryPool^ queryPool, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - queryPool
		VkQueryPool arg_1 = queryPool->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyQueryPool(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::GetQueryPoolResults(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, IntPtr dataSize, IntPtr pData, UInt64 stride, VkQueryResultFlags flags)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - queryPool
		VkQueryPool arg_1 = queryPool->mHandle;
		// 2 - firstQuery
		uint32_t arg_2 = 0;
		// 3 - queryCount
		uint32_t arg_3 = 0;
		// 4 - dataSize
		size_t arg_4 = 0;
		// 5 - pData
		void* arg_5 = 0;
		// 6 - stride
		VkDeviceSize arg_6 = 0;
		// 7 - flags
		VkQueryResultFlags arg_7 = 0;


		var result = vkGetQueryPoolResults(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateBuffer(BufferCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Buffer^ pBuffer)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkBufferCreateInfo inst_1;
		VkBufferCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pBuffer
		VkBuffer inst_3;
		VkBuffer* arg_3 = &inst_3;


		var result = vkCreateBuffer(arg_0, arg_1, arg_2, arg_3);

								
		pBuffer = gcnew Buffer^();
		pBuffer->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyBuffer(Buffer^ buffer, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyBuffer(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateBufferView(BufferViewCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out BufferView^ pView)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkBufferViewCreateInfo inst_1;
		VkBufferViewCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pView
		VkBufferView inst_3;
		VkBufferView* arg_3 = &inst_3;


		var result = vkCreateBufferView(arg_0, arg_1, arg_2, arg_3);

								
		pView = gcnew BufferView^();
		pView->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyBufferView(BufferView^ bufferView, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - bufferView
		VkBufferView arg_1 = bufferView->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyBufferView(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateImage(ImageCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Image^ pImage)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkImageCreateInfo inst_1;
		VkImageCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pImage
		VkImage inst_3;
		VkImage* arg_3 = &inst_3;


		var result = vkCreateImage(arg_0, arg_1, arg_2, arg_3);

								
		pImage = gcnew Image^();
		pImage->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyImage(Image^ image, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyImage(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::Device::GetImageSubresourceLayout(Image^ image, ImageSubresource^ pSubresource, out SubresourceLayout^ pLayout)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - pSubresource
		VkImageSubresource inst_2;
		VkImageSubresource* arg_2 = &inst_2;
		pSubresource->CopyTo(arg_2);
		// 3 - pLayout
		VkSubresourceLayout inst_3;
		VkSubresourceLayout* arg_3 = &inst_3;
		pLayout->CopyTo(arg_3);


		vkGetImageSubresourceLayout(arg_0, arg_1, arg_2, arg_3);

								
		pLayout = gcnew SubresourceLayout^();
			pLayout->CopyFrom(arg_3);						

		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateImageView(ImageViewCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out ImageView^ pView)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkImageViewCreateInfo inst_1;
		VkImageViewCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pView
		VkImageView inst_3;
		VkImageView* arg_3 = &inst_3;


		var result = vkCreateImageView(arg_0, arg_1, arg_2, arg_3);

								
		pView = gcnew ImageView^();
		pView->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyImageView(ImageView^ imageView, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - imageView
		VkImageView arg_1 = imageView->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyImageView(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateShaderModule(ShaderModuleCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out ShaderModule^ pShaderModule)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkShaderModuleCreateInfo inst_1;
		VkShaderModuleCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pShaderModule
		VkShaderModule inst_3;
		VkShaderModule* arg_3 = &inst_3;


		var result = vkCreateShaderModule(arg_0, arg_1, arg_2, arg_3);

								
		pShaderModule = gcnew ShaderModule^();
		pShaderModule->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyShaderModule(ShaderModule^ shaderModule, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - shaderModule
		VkShaderModule arg_1 = shaderModule->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyShaderModule(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreatePipelineCache(PipelineCacheCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out PipelineCache^ pPipelineCache)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkPipelineCacheCreateInfo inst_1;
		VkPipelineCacheCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pPipelineCache
		VkPipelineCache inst_3;
		VkPipelineCache* arg_3 = &inst_3;


		var result = vkCreatePipelineCache(arg_0, arg_1, arg_2, arg_3);

								
		pPipelineCache = gcnew PipelineCache^();
		pPipelineCache->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyPipelineCache(PipelineCache^ pipelineCache, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pipelineCache
		VkPipelineCache arg_1 = pipelineCache->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyPipelineCache(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::GetPipelineCacheData(PipelineCache^ pipelineCache, ref IntPtr pDataSize, IntPtr pData)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pipelineCache
		VkPipelineCache arg_1 = pipelineCache->mHandle;
		// 2 - pDataSize
		size_t* arg_2 = 0;
		// 3 - pData
		void* arg_3 = 0;


		var result = vkGetPipelineCacheData(arg_0, arg_1, arg_2, arg_3);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::MergePipelineCaches(PipelineCache^ dstCache, array<PipelineCache^>^ pSrcCaches)
{
	VkPipelineCache* arg_3 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - dstCache
		VkPipelineCache arg_1 = dstCache->mHandle;
		// 2 - srcCacheCount
		uint32_t arg_2 = 0;
		// 3 - pSrcCaches
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
	}
}

VkResult ManagedVulkan::Device::CreateGraphicsPipelines(PipelineCache^ pipelineCache, array<GraphicsPipelineCreateInfo^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<Pipeline^>^ pPipelines)
{
	VkGraphicsPipelineCreateInfo* arg_3 = nullptr;
	VkPipeline* arg_5 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pipelineCache
		VkPipelineCache arg_1 = pipelineCache->mHandle;
		// 2 - createInfoCount
		uint32_t arg_2 = 0;
		// 3 - pCreateInfos
		arg_3 = new VkGraphicsPipelineCreateInfo[createInfoCount];
		// 4 - pAllocator
		VkAllocationCallbacks inst_4;
		VkAllocationCallbacks* arg_4 = &inst_4;
		pAllocator->CopyTo(arg_4);
		// 5 - pPipelines
		arg_5 = new VkPipeline[createInfoCount];


		var result = vkCreateGraphicsPipelines(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

			
		int count = createInfoCount;	
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
	}
}

VkResult ManagedVulkan::Device::CreateComputePipelines(PipelineCache^ pipelineCache, array<ComputePipelineCreateInfo^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<Pipeline^>^ pPipelines)
{
	VkComputePipelineCreateInfo* arg_3 = nullptr;
	VkPipeline* arg_5 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pipelineCache
		VkPipelineCache arg_1 = pipelineCache->mHandle;
		// 2 - createInfoCount
		uint32_t arg_2 = 0;
		// 3 - pCreateInfos
		arg_3 = new VkComputePipelineCreateInfo[createInfoCount];
		// 4 - pAllocator
		VkAllocationCallbacks inst_4;
		VkAllocationCallbacks* arg_4 = &inst_4;
		pAllocator->CopyTo(arg_4);
		// 5 - pPipelines
		arg_5 = new VkPipeline[createInfoCount];


		var result = vkCreateComputePipelines(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

			
		int count = createInfoCount;	
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
	}
}

void ManagedVulkan::Device::DestroyPipeline(Pipeline^ pipeline, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pipeline
		VkPipeline arg_1 = pipeline->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyPipeline(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreatePipelineLayout(PipelineLayoutCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out PipelineLayout^ pPipelineLayout)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkPipelineLayoutCreateInfo inst_1;
		VkPipelineLayoutCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pPipelineLayout
		VkPipelineLayout inst_3;
		VkPipelineLayout* arg_3 = &inst_3;


		var result = vkCreatePipelineLayout(arg_0, arg_1, arg_2, arg_3);

								
		pPipelineLayout = gcnew PipelineLayout^();
		pPipelineLayout->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyPipelineLayout(PipelineLayout^ pipelineLayout, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pipelineLayout
		VkPipelineLayout arg_1 = pipelineLayout->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyPipelineLayout(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateSampler(SamplerCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Sampler^ pSampler)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkSamplerCreateInfo inst_1;
		VkSamplerCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pSampler
		VkSampler inst_3;
		VkSampler* arg_3 = &inst_3;


		var result = vkCreateSampler(arg_0, arg_1, arg_2, arg_3);

								
		pSampler = gcnew Sampler^();
		pSampler->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroySampler(Sampler^ sampler, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - sampler
		VkSampler arg_1 = sampler->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroySampler(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateDescriptorSetLayout(DescriptorSetLayoutCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out DescriptorSetLayout^ pSetLayout)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkDescriptorSetLayoutCreateInfo inst_1;
		VkDescriptorSetLayoutCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pSetLayout
		VkDescriptorSetLayout inst_3;
		VkDescriptorSetLayout* arg_3 = &inst_3;


		var result = vkCreateDescriptorSetLayout(arg_0, arg_1, arg_2, arg_3);

								
		pSetLayout = gcnew DescriptorSetLayout^();
		pSetLayout->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyDescriptorSetLayout(DescriptorSetLayout^ descriptorSetLayout, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - descriptorSetLayout
		VkDescriptorSetLayout arg_1 = descriptorSetLayout->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyDescriptorSetLayout(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateDescriptorPool(DescriptorPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out DescriptorPool^ pDescriptorPool)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkDescriptorPoolCreateInfo inst_1;
		VkDescriptorPoolCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pDescriptorPool
		VkDescriptorPool inst_3;
		VkDescriptorPool* arg_3 = &inst_3;


		var result = vkCreateDescriptorPool(arg_0, arg_1, arg_2, arg_3);

								
		pDescriptorPool = gcnew DescriptorPool^();
		pDescriptorPool->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyDescriptorPool(DescriptorPool^ descriptorPool, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - descriptorPool
		VkDescriptorPool arg_1 = descriptorPool->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyDescriptorPool(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::ResetDescriptorPool(DescriptorPool^ descriptorPool, VkDescriptorPoolResetFlags flags)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - descriptorPool
		VkDescriptorPool arg_1 = descriptorPool->mHandle;
		// 2 - flags
		VkDescriptorPoolResetFlags arg_2 = 0;


		var result = vkResetDescriptorPool(arg_0, arg_1, arg_2);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::AllocateDescriptorSets(DescriptorSetAllocateInfo^ pAllocateInfo, DescriptorSet^ pDescriptorSets)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pAllocateInfo
		VkDescriptorSetAllocateInfo inst_1;
		VkDescriptorSetAllocateInfo* arg_1 = &inst_1;
		pAllocateInfo->CopyTo(arg_1);
		// 2 - pDescriptorSets
		VkDescriptorSet* arg_2 = pDescriptorSets->mHandle;


		var result = vkAllocateDescriptorSets(arg_0, arg_1, arg_2);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::FreeDescriptorSets(DescriptorPool^ descriptorPool, UInt32 descriptorSetCount, DescriptorSet^ pDescriptorSets)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - descriptorPool
		VkDescriptorPool arg_1 = descriptorPool->mHandle;
		// 2 - descriptorSetCount
		uint32_t arg_2 = 0;
		// 3 - pDescriptorSets
		VkDescriptorSet* arg_3 = pDescriptorSets->mHandle;


		var result = vkFreeDescriptorSets(arg_0, arg_1, arg_2, arg_3);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::UpdateDescriptorSets(UInt32 descriptorWriteCount, WriteDescriptorSet^ pDescriptorWrites, UInt32 descriptorCopyCount, CopyDescriptorSet^ pDescriptorCopies)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - descriptorWriteCount
		uint32_t arg_1 = 0;
		// 2 - pDescriptorWrites
		VkWriteDescriptorSet inst_2;
		VkWriteDescriptorSet* arg_2 = &inst_2;
		pDescriptorWrites->CopyTo(arg_2);
		// 3 - descriptorCopyCount
		uint32_t arg_3 = 0;
		// 4 - pDescriptorCopies
		VkCopyDescriptorSet inst_4;
		VkCopyDescriptorSet* arg_4 = &inst_4;
		pDescriptorCopies->CopyTo(arg_4);


		vkUpdateDescriptorSets(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateFramebuffer(FramebufferCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Framebuffer^ pFramebuffer)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkFramebufferCreateInfo inst_1;
		VkFramebufferCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pFramebuffer
		VkFramebuffer inst_3;
		VkFramebuffer* arg_3 = &inst_3;


		var result = vkCreateFramebuffer(arg_0, arg_1, arg_2, arg_3);

								
		pFramebuffer = gcnew Framebuffer^();
		pFramebuffer->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyFramebuffer(Framebuffer^ framebuffer, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - framebuffer
		VkFramebuffer arg_1 = framebuffer->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyFramebuffer(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateRenderPass(RenderPassCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out RenderPass^ pRenderPass)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkRenderPassCreateInfo inst_1;
		VkRenderPassCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pRenderPass
		VkRenderPass inst_3;
		VkRenderPass* arg_3 = &inst_3;


		var result = vkCreateRenderPass(arg_0, arg_1, arg_2, arg_3);

								
		pRenderPass = gcnew RenderPass^();
		pRenderPass->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyRenderPass(RenderPass^ renderPass, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - renderPass
		VkRenderPass arg_1 = renderPass->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyRenderPass(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::Device::GetRenderAreaGranularity(RenderPass^ renderPass, out Extent2D^ pGranularity)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - renderPass
		VkRenderPass arg_1 = renderPass->mHandle;
		// 2 - pGranularity
		VkExtent2D inst_2;
		VkExtent2D* arg_2 = &inst_2;
		pGranularity->CopyTo(arg_2);


		vkGetRenderAreaGranularity(arg_0, arg_1, arg_2);

								
		pGranularity = gcnew Extent2D^();
			pGranularity->CopyFrom(arg_2);						

		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::CreateCommandPool(CommandPoolCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out CommandPool^ pCommandPool)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkCommandPoolCreateInfo inst_1;
		VkCommandPoolCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pCommandPool
		VkCommandPool inst_3;
		VkCommandPool* arg_3 = &inst_3;


		var result = vkCreateCommandPool(arg_0, arg_1, arg_2, arg_3);

								
		pCommandPool = gcnew CommandPool^();
		pCommandPool->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroyCommandPool(CommandPool^ commandPool, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - commandPool
		VkCommandPool arg_1 = commandPool->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroyCommandPool(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::ResetCommandPool(CommandPool^ commandPool, VkCommandPoolResetFlags flags)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - commandPool
		VkCommandPool arg_1 = commandPool->mHandle;
		// 2 - flags
		VkCommandPoolResetFlags arg_2 = 0;


		var result = vkResetCommandPool(arg_0, arg_1, arg_2);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::AllocateCommandBuffers(CommandBufferAllocateInfo^ pAllocateInfo, CommandBuffer^ pCommandBuffers)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pAllocateInfo
		VkCommandBufferAllocateInfo inst_1;
		VkCommandBufferAllocateInfo* arg_1 = &inst_1;
		pAllocateInfo->CopyTo(arg_1);
		// 2 - pCommandBuffers
		VkCommandBuffer inst_2;
		VkCommandBuffer* arg_2 = &inst_2;


		var result = vkAllocateCommandBuffers(arg_0, arg_1, arg_2);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::FreeCommandBuffers(CommandPool^ commandPool, array<CommandBuffer^>^ pCommandBuffers)
{
	VkCommandBuffer* arg_3 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - commandPool
		VkCommandPool arg_1 = commandPool->mHandle;
		// 2 - commandBufferCount
		uint32_t arg_2 = 0;
		// 3 - pCommandBuffers
		arg_3 = new VkCommandBuffer[commandBufferCount];


		vkFreeCommandBuffers(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
	}
}

VkResult ManagedVulkan::Device::CreateSharedSwapchainsKHR(array<SwapchainCreateInfoKHR^>^ pCreateInfos, AllocationCallbacks^ pAllocator, out array<SwapchainKHR^>^ pSwapchains)
{
	VkSwapchainCreateInfoKHR* arg_2 = nullptr;
	VkSwapchainKHR* arg_4 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - swapchainCount
		uint32_t arg_1 = 0;
		// 2 - pCreateInfos
		arg_2 = new VkSwapchainCreateInfoKHR[swapchainCount];
		// 3 - pAllocator
		VkAllocationCallbacks inst_3;
		VkAllocationCallbacks* arg_3 = &inst_3;
		pAllocator->CopyTo(arg_3);
		// 4 - pSwapchains
		arg_4 = new VkSwapchainKHR[swapchainCount];


		var result = vkCreateSharedSwapchainsKHR(arg_0, arg_1, arg_2, arg_3, arg_4);

			
		int count = swapchainCount;	
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
	}
}

VkResult ManagedVulkan::Device::CreateSwapchainKHR(SwapchainCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out SwapchainKHR^ pSwapchain)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkSwapchainCreateInfoKHR inst_1;
		VkSwapchainCreateInfoKHR* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pSwapchain
		VkSwapchainKHR inst_3;
		VkSwapchainKHR* arg_3 = &inst_3;


		var result = vkCreateSwapchainKHR(arg_0, arg_1, arg_2, arg_3);

								
		pSwapchain = gcnew SwapchainKHR^();
		pSwapchain->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::Device::DestroySwapchainKHR(SwapchainKHR^ swapchain, AllocationCallbacks^ pAllocator)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - swapchain
		VkSwapchainKHR arg_1 = swapchain->mHandle;
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);


		vkDestroySwapchainKHR(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Device::GetSwapchainImagesKHR(SwapchainKHR^ swapchain, out array<Image^>^ pSwapchainImages)
{
	VkImage* arg_3 = nullptr;
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - swapchain
		VkSwapchainKHR arg_1 = swapchain->mHandle;
		// 2 - pSwapchainImageCount
		uint32_t* arg_2 = 0;
		// 3 - pSwapchainImages
		arg_3 = new VkImage[pSwapchainImageCount];


		var result = vkGetSwapchainImagesKHR(arg_0, arg_1, arg_2, arg_3);

			
		int count = pSwapchainImageCount;	
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
	}
}

VkResult ManagedVulkan::Device::AcquireNextImageKHR(SwapchainKHR^ swapchain, UInt64 timeout, Semaphore^ semaphore, Fence^ fence, ref UInt32 pImageIndex)
{
	try
	{
		// 0 - device
		VkDevice arg_0 = this->mHandle;
		// 1 - swapchain
		VkSwapchainKHR arg_1 = swapchain->mHandle;
		// 2 - timeout
		uint64_t arg_2 = 0;
		// 3 - semaphore
		VkSemaphore arg_3 = semaphore->mHandle;
		// 4 - fence
		VkFence arg_4 = fence->mHandle;
		// 5 - pImageIndex
		uint32_t* arg_5 = 0;


		var result = vkAcquireNextImageKHR(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		return (VkResult) result;
	}
	finally
	{
	}
}


// VkPhysicalDevice
void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceProperties(out PhysicalDeviceProperties^ pProperties)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pProperties
		VkPhysicalDeviceProperties inst_1;
		VkPhysicalDeviceProperties* arg_1 = &inst_1;
		pProperties->CopyTo(arg_1);


		vkGetPhysicalDeviceProperties(arg_0, arg_1);

								
		pProperties = gcnew PhysicalDeviceProperties^();
			pProperties->CopyFrom(arg_1);						

		
	}
	finally
	{
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceQueueFamilyProperties(out array<QueueFamilyProperties^>^ pQueueFamilyProperties)
{
	VkQueueFamilyProperties* arg_2 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pQueueFamilyPropertyCount
		uint32_t* arg_1 = 0;
		// 2 - pQueueFamilyProperties
		arg_2 = new VkQueueFamilyProperties[pQueueFamilyPropertyCount];


		vkGetPhysicalDeviceQueueFamilyProperties(arg_0, arg_1, arg_2);

			
		int count = pQueueFamilyPropertyCount;	
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
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceMemoryProperties(out PhysicalDeviceMemoryProperties^ pMemoryProperties)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pMemoryProperties
		VkPhysicalDeviceMemoryProperties inst_1;
		VkPhysicalDeviceMemoryProperties* arg_1 = &inst_1;
		pMemoryProperties->CopyTo(arg_1);


		vkGetPhysicalDeviceMemoryProperties(arg_0, arg_1);

								
		pMemoryProperties = gcnew PhysicalDeviceMemoryProperties^();
			pMemoryProperties->CopyFrom(arg_1);						

		
	}
	finally
	{
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFeatures(out PhysicalDeviceFeatures^ pFeatures)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pFeatures
		VkPhysicalDeviceFeatures inst_1;
		VkPhysicalDeviceFeatures* arg_1 = &inst_1;
		pFeatures->CopyTo(arg_1);


		vkGetPhysicalDeviceFeatures(arg_0, arg_1);

								
		pFeatures = gcnew PhysicalDeviceFeatures^();
			pFeatures->CopyFrom(arg_1);						

		
	}
	finally
	{
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceFormatProperties(VkFormat format, out FormatProperties^ pFormatProperties)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - format
		VkFormat arg_1 = format;
		// 2 - pFormatProperties
		VkFormatProperties inst_2;
		VkFormatProperties* arg_2 = &inst_2;
		pFormatProperties->CopyTo(arg_2);


		vkGetPhysicalDeviceFormatProperties(arg_0, arg_1, arg_2);

								
		pFormatProperties = gcnew FormatProperties^();
			pFormatProperties->CopyFrom(arg_2);						

		
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceImageFormatProperties(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, out ImageFormatProperties^ pImageFormatProperties)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - format
		VkFormat arg_1 = format;
		// 2 - type
		VkImageType arg_2 = type;
		// 3 - tiling
		VkImageTiling arg_3 = tiling;
		// 4 - usage
		VkImageUsageFlags arg_4 = 0;
		// 5 - flags
		VkImageCreateFlags arg_5 = 0;
		// 6 - pImageFormatProperties
		VkImageFormatProperties inst_6;
		VkImageFormatProperties* arg_6 = &inst_6;
		pImageFormatProperties->CopyTo(arg_6);


		var result = vkGetPhysicalDeviceImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);

								
		pImageFormatProperties = gcnew ImageFormatProperties^();
			pImageFormatProperties->CopyFrom(arg_6);						

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::CreateDevice(DeviceCreateInfo^ pCreateInfo, AllocationCallbacks^ pAllocator, out Device^ pDevice)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pCreateInfo
		VkDeviceCreateInfo inst_1;
		VkDeviceCreateInfo* arg_1 = &inst_1;
		pCreateInfo->CopyTo(arg_1);
		// 2 - pAllocator
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = &inst_2;
		pAllocator->CopyTo(arg_2);
		// 3 - pDevice
		VkDevice inst_3;
		VkDevice* arg_3 = &inst_3;


		var result = vkCreateDevice(arg_0, arg_1, arg_2, arg_3);

								
		pDevice = gcnew Device^();
		pDevice->mHandle = inst_3;

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::EnumerateDeviceLayerProperties(out array<LayerProperties^>^ pProperties)
{
	VkLayerProperties* arg_2 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pPropertyCount
		uint32_t* arg_1 = 0;
		// 2 - pProperties
		arg_2 = new VkLayerProperties[pPropertyCount];


		var result = vkEnumerateDeviceLayerProperties(arg_0, arg_1, arg_2);

			
		int count = pPropertyCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::EnumerateDeviceExtensionProperties(String^ pLayerName, out array<ExtensionProperties^>^ pProperties)
{
	VkExtensionProperties* arg_3 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pLayerName
		char* arg_1 = 0;
		// 2 - pPropertyCount
		uint32_t* arg_2 = 0;
		// 3 - pProperties
		arg_3 = new VkExtensionProperties[pPropertyCount];


		var result = vkEnumerateDeviceExtensionProperties(arg_0, arg_1, arg_2, arg_3);

			
		int count = pPropertyCount;	
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
	}
}

void ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSparseImageFormatProperties(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, out array<SparseImageFormatProperties^>^ pProperties)
{
	VkSparseImageFormatProperties* arg_7 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - format
		VkFormat arg_1 = format;
		// 2 - type
		VkImageType arg_2 = type;
		// 3 - samples
		VkSampleCountFlagBits arg_3 = samples;
		// 4 - usage
		VkImageUsageFlags arg_4 = 0;
		// 5 - tiling
		VkImageTiling arg_5 = tiling;
		// 6 - pPropertyCount
		uint32_t* arg_6 = 0;
		// 7 - pProperties
		arg_7 = new VkSparseImageFormatProperties[pPropertyCount];


		vkGetPhysicalDeviceSparseImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

			
		int count = pPropertyCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPropertiesKHR(out array<DisplayPropertiesKHR^>^ pProperties)
{
	VkDisplayPropertiesKHR* arg_2 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pPropertyCount
		uint32_t* arg_1 = 0;
		// 2 - pProperties
		arg_2 = new VkDisplayPropertiesKHR[pPropertyCount];


		var result = vkGetPhysicalDeviceDisplayPropertiesKHR(arg_0, arg_1, arg_2);

			
		int count = pPropertyCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceDisplayPlanePropertiesKHR(out array<DisplayPlanePropertiesKHR^>^ pProperties)
{
	VkDisplayPlanePropertiesKHR* arg_2 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - pPropertyCount
		uint32_t* arg_1 = 0;
		// 2 - pProperties
		arg_2 = new VkDisplayPlanePropertiesKHR[pPropertyCount];


		var result = vkGetPhysicalDeviceDisplayPlanePropertiesKHR(arg_0, arg_1, arg_2);

			
		int count = pPropertyCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayPlaneSupportedDisplaysKHR(UInt32 planeIndex, out array<DisplayKHR^>^ pDisplays)
{
	VkDisplayKHR* arg_3 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - planeIndex
		uint32_t arg_1 = 0;
		// 2 - pDisplayCount
		uint32_t* arg_2 = 0;
		// 3 - pDisplays
		arg_3 = new VkDisplayKHR[pDisplayCount];


		var result = vkGetDisplayPlaneSupportedDisplaysKHR(arg_0, arg_1, arg_2, arg_3);

			
		int count = pDisplayCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayModePropertiesKHR(DisplayKHR^ display, out array<DisplayModePropertiesKHR^>^ pProperties)
{
	VkDisplayModePropertiesKHR* arg_3 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - display
		VkDisplayKHR arg_1 = display->mHandle;
		// 2 - pPropertyCount
		uint32_t* arg_2 = 0;
		// 3 - pProperties
		arg_3 = new VkDisplayModePropertiesKHR[pPropertyCount];


		var result = vkGetDisplayModePropertiesKHR(arg_0, arg_1, arg_2, arg_3);

			
		int count = pPropertyCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::CreateDisplayModeKHR(DisplayKHR^ display, DisplayModeCreateInfoKHR^ pCreateInfo, AllocationCallbacks^ pAllocator, out DisplayModeKHR^ pMode)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - display
		VkDisplayKHR arg_1 = display->mHandle;
		// 2 - pCreateInfo
		VkDisplayModeCreateInfoKHR inst_2;
		VkDisplayModeCreateInfoKHR* arg_2 = &inst_2;
		pCreateInfo->CopyTo(arg_2);
		// 3 - pAllocator
		VkAllocationCallbacks inst_3;
		VkAllocationCallbacks* arg_3 = &inst_3;
		pAllocator->CopyTo(arg_3);
		// 4 - pMode
		VkDisplayModeKHR inst_4;
		VkDisplayModeKHR* arg_4 = &inst_4;


		var result = vkCreateDisplayModeKHR(arg_0, arg_1, arg_2, arg_3, arg_4);

								
		pMode = gcnew DisplayModeKHR^();
		pMode->mHandle = inst_4;

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetDisplayPlaneCapabilitiesKHR(DisplayModeKHR^ mode, UInt32 planeIndex, out DisplayPlaneCapabilitiesKHR^ pCapabilities)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - mode
		VkDisplayModeKHR arg_1 = mode->mHandle;
		// 2 - planeIndex
		uint32_t arg_2 = 0;
		// 3 - pCapabilities
		VkDisplayPlaneCapabilitiesKHR inst_3;
		VkDisplayPlaneCapabilitiesKHR* arg_3 = &inst_3;
		pCapabilities->CopyTo(arg_3);


		var result = vkGetDisplayPlaneCapabilitiesKHR(arg_0, arg_1, arg_2, arg_3);

								
		pCapabilities = gcnew DisplayPlaneCapabilitiesKHR^();
			pCapabilities->CopyFrom(arg_3);						

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, SurfaceKHR^ surface, ref bool pSupported)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - queueFamilyIndex
		uint32_t arg_1 = 0;
		// 2 - surface
		VkSurfaceKHR arg_2 = surface->mHandle;
		// 3 - pSupported
		VkBool32* arg_3 = 0;


		var result = vkGetPhysicalDeviceSurfaceSupportKHR(arg_0, arg_1, arg_2, arg_3);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceCapabilitiesKHR(SurfaceKHR^ surface, out SurfaceCapabilitiesKHR^ pSurfaceCapabilities)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - surface
		VkSurfaceKHR arg_1 = surface->mHandle;
		// 2 - pSurfaceCapabilities
		VkSurfaceCapabilitiesKHR inst_2;
		VkSurfaceCapabilitiesKHR* arg_2 = &inst_2;
		pSurfaceCapabilities->CopyTo(arg_2);


		var result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(arg_0, arg_1, arg_2);

								
		pSurfaceCapabilities = gcnew SurfaceCapabilitiesKHR^();
			pSurfaceCapabilities->CopyFrom(arg_2);						

		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceFormatsKHR(SurfaceKHR^ surface, out array<SurfaceFormatKHR^>^ pSurfaceFormats)
{
	VkSurfaceFormatKHR* arg_3 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - surface
		VkSurfaceKHR arg_1 = surface->mHandle;
		// 2 - pSurfaceFormatCount
		uint32_t* arg_2 = 0;
		// 3 - pSurfaceFormats
		arg_3 = new VkSurfaceFormatKHR[pSurfaceFormatCount];


		var result = vkGetPhysicalDeviceSurfaceFormatsKHR(arg_0, arg_1, arg_2, arg_3);

			
		int count = pSurfaceFormatCount;	
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
	}
}

VkResult ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfacePresentModesKHR(SurfaceKHR^ surface, out array<VkPresentModeKHR>^ pPresentModes)
{
	VkPresentModeKHR* arg_3 = nullptr;
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - surface
		VkSurfaceKHR arg_1 = surface->mHandle;
		// 2 - pPresentModeCount
		uint32_t* arg_2 = 0;
		// 3 - pPresentModes
		arg_3 = new <TYPE>[pPresentModeCount];


		var result = vkGetPhysicalDeviceSurfacePresentModesKHR(arg_0, arg_1, arg_2, arg_3);

			
		int count = pPresentModeCount;	
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
	}
}

VkBool32 ManagedVulkan::PhysicalDevice::GetPhysicalDeviceWin32PresentationSupportKHR(UInt32 queueFamilyIndex)
{
	try
	{
		// 0 - physicalDevice
		VkPhysicalDevice arg_0 = this->mHandle;
		// 1 - queueFamilyIndex
		uint32_t arg_1 = 0;


		var result = vkGetPhysicalDeviceWin32PresentationSupportKHR(arg_0, arg_1);


		return result != 0;
	}
	finally
	{
	}
}


// VkQueue
VkResult ManagedVulkan::Queue::QueueSubmit(array<SubmitInfo^>^ pSubmits, Fence^ fence)
{
	VkSubmitInfo* arg_2 = nullptr;
	try
	{
		// 0 - queue
		VkQueue arg_0 = this->mHandle;
		// 1 - submitCount
		uint32_t arg_1 = 0;
		// 2 - pSubmits
		arg_2 = new VkSubmitInfo[submitCount];
		// 3 - fence
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
	}
}

VkResult ManagedVulkan::Queue::QueueWaitIdle()
{
	try
	{
		// 0 - queue
		VkQueue arg_0 = this->mHandle;


		var result = vkQueueWaitIdle(arg_0);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::Queue::QueueBindSparse(array<BindSparseInfo^>^ pBindInfo, Fence^ fence)
{
	VkBindSparseInfo* arg_2 = nullptr;
	try
	{
		// 0 - queue
		VkQueue arg_0 = this->mHandle;
		// 1 - bindInfoCount
		uint32_t arg_1 = 0;
		// 2 - pBindInfo
		arg_2 = new VkBindSparseInfo[bindInfoCount];
		// 3 - fence
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
	}
}

VkResult ManagedVulkan::Queue::QueuePresentKHR(PresentInfoKHR^ pPresentInfo)
{
	try
	{
		// 0 - queue
		VkQueue arg_0 = this->mHandle;
		// 1 - pPresentInfo
		VkPresentInfoKHR inst_1;
		VkPresentInfoKHR* arg_1 = &inst_1;
		pPresentInfo->CopyTo(arg_1);


		var result = vkQueuePresentKHR(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}


// VkCommandBuffer
VkResult ManagedVulkan::CommandBuffer::BeginCommandBuffer(CommandBufferBeginInfo^ pBeginInfo)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - pBeginInfo
		VkCommandBufferBeginInfo inst_1;
		VkCommandBufferBeginInfo* arg_1 = &inst_1;
		pBeginInfo->CopyTo(arg_1);


		var result = vkBeginCommandBuffer(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::CommandBuffer::EndCommandBuffer()
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;


		var result = vkEndCommandBuffer(arg_0);


		return (VkResult) result;
	}
	finally
	{
	}
}

VkResult ManagedVulkan::CommandBuffer::ResetCommandBuffer(VkCommandBufferResetFlags flags)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - flags
		VkCommandBufferResetFlags arg_1 = 0;


		var result = vkResetCommandBuffer(arg_0, arg_1);


		return (VkResult) result;
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdBindPipeline(VkPipelineBindPoint pipelineBindPoint, Pipeline^ pipeline)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - pipelineBindPoint
		VkPipelineBindPoint arg_1 = pipelineBindPoint;
		// 2 - pipeline
		VkPipeline arg_2 = pipeline->mHandle;


		vkCmdBindPipeline(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetViewport(UInt32 firstViewport, UInt32 viewportCount, array<Viewport^>^ pViewports)
{
	VkViewport* arg_3 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - firstViewport
		uint32_t arg_1 = 0;
		// 2 - viewportCount
		uint32_t arg_2 = 0;
		// 3 - pViewports
		arg_3 = new VkViewport[viewportCount];


		vkCmdSetViewport(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetScissor(UInt32 firstScissor, UInt32 scissorCount, array<Rect2D^>^ pScissors)
{
	VkRect2D* arg_3 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - firstScissor
		uint32_t arg_1 = 0;
		// 2 - scissorCount
		uint32_t arg_2 = 0;
		// 3 - pScissors
		arg_3 = new VkRect2D[scissorCount];


		vkCmdSetScissor(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetLineWidth(float lineWidth)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - lineWidth
		float arg_1 = 0;


		vkCmdSetLineWidth(arg_0, arg_1);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - depthBiasConstantFactor
		float arg_1 = 0;
		// 2 - depthBiasClamp
		float arg_2 = 0;
		// 3 - depthBiasSlopeFactor
		float arg_3 = 0;


		vkCmdSetDepthBias(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetBlendConstants(float blendConstants[4])
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - blendConstants[4]
		float arg_1 = 0;


		vkCmdSetBlendConstants(arg_0, arg_1);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - minDepthBounds
		float arg_1 = 0;
		// 2 - maxDepthBounds
		float arg_2 = 0;


		vkCmdSetDepthBounds(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetStencilCompareMask(VkStencilFaceFlags faceMask, UInt32 compareMask)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - faceMask
		VkStencilFaceFlags arg_1 = 0;
		// 2 - compareMask
		uint32_t arg_2 = 0;


		vkCmdSetStencilCompareMask(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetStencilWriteMask(VkStencilFaceFlags faceMask, UInt32 writeMask)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - faceMask
		VkStencilFaceFlags arg_1 = 0;
		// 2 - writeMask
		uint32_t arg_2 = 0;


		vkCmdSetStencilWriteMask(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdSetStencilReference(VkStencilFaceFlags faceMask, UInt32 reference)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - faceMask
		VkStencilFaceFlags arg_1 = 0;
		// 2 - reference
		uint32_t arg_2 = 0;


		vkCmdSetStencilReference(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdBindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, PipelineLayout^ layout, UInt32 firstSet, UInt32 descriptorSetCount, array<DescriptorSet^>^ pDescriptorSets, UInt32 dynamicOffsetCount, array<UInt32>^ pDynamicOffsets)
{
	VkDescriptorSet* arg_5 = nullptr;
	uint32_t* arg_7 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - pipelineBindPoint
		VkPipelineBindPoint arg_1 = pipelineBindPoint;
		// 2 - layout
		VkPipelineLayout arg_2 = layout->mHandle;
		// 3 - firstSet
		uint32_t arg_3 = 0;
		// 4 - descriptorSetCount
		uint32_t arg_4 = 0;
		// 5 - pDescriptorSets
		arg_5 = new VkDescriptorSet[descriptorSetCount];
		// 6 - dynamicOffsetCount
		uint32_t arg_6 = 0;
		// 7 - pDynamicOffsets
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
	}
}

void ManagedVulkan::CommandBuffer::CmdBindIndexBuffer(Buffer^ buffer, UInt64 offset, VkIndexType indexType)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - offset
		VkDeviceSize arg_2 = 0;
		// 3 - indexType
		VkIndexType arg_3 = indexType;


		vkCmdBindIndexBuffer(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdBindVertexBuffers(UInt32 firstBinding, UInt32 bindingCount, array<Buffer^>^ pBuffers, array<UInt64>^ pOffsets)
{
	VkBuffer* arg_3 = nullptr;
	VkDeviceSize* arg_4 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - firstBinding
		uint32_t arg_1 = 0;
		// 2 - bindingCount
		uint32_t arg_2 = 0;
		// 3 - pBuffers
		arg_3 = new VkBuffer[bindingCount];
		// 4 - pOffsets
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
	}
}

void ManagedVulkan::CommandBuffer::CmdDraw(UInt32 vertexCount, UInt32 instanceCount, UInt32 firstVertex, UInt32 firstInstance)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - vertexCount
		uint32_t arg_1 = 0;
		// 2 - instanceCount
		uint32_t arg_2 = 0;
		// 3 - firstVertex
		uint32_t arg_3 = 0;
		// 4 - firstInstance
		uint32_t arg_4 = 0;


		vkCmdDraw(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdDrawIndexed(UInt32 indexCount, UInt32 instanceCount, UInt32 firstIndex, Int32 vertexOffset, UInt32 firstInstance)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - indexCount
		uint32_t arg_1 = 0;
		// 2 - instanceCount
		uint32_t arg_2 = 0;
		// 3 - firstIndex
		uint32_t arg_3 = 0;
		// 4 - vertexOffset
		int32_t arg_4 = 0;
		// 5 - firstInstance
		uint32_t arg_5 = 0;


		vkCmdDrawIndexed(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdDrawIndirect(Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - offset
		VkDeviceSize arg_2 = 0;
		// 3 - drawCount
		uint32_t arg_3 = 0;
		// 4 - stride
		uint32_t arg_4 = 0;


		vkCmdDrawIndirect(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdDrawIndexedIndirect(Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - offset
		VkDeviceSize arg_2 = 0;
		// 3 - drawCount
		uint32_t arg_3 = 0;
		// 4 - stride
		uint32_t arg_4 = 0;


		vkCmdDrawIndexedIndirect(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdDispatch(UInt32 x, UInt32 y, UInt32 z)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - x
		uint32_t arg_1 = 0;
		// 2 - y
		uint32_t arg_2 = 0;
		// 3 - z
		uint32_t arg_3 = 0;


		vkCmdDispatch(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdDispatchIndirect(Buffer^ buffer, UInt64 offset)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - buffer
		VkBuffer arg_1 = buffer->mHandle;
		// 2 - offset
		VkDeviceSize arg_2 = 0;


		vkCmdDispatchIndirect(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyBuffer(Buffer^ srcBuffer, Buffer^ dstBuffer, array<BufferCopy^>^ pRegions)
{
	VkBufferCopy* arg_4 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcBuffer
		VkBuffer arg_1 = srcBuffer->mHandle;
		// 2 - dstBuffer
		VkBuffer arg_2 = dstBuffer->mHandle;
		// 3 - regionCount
		uint32_t arg_3 = 0;
		// 4 - pRegions
		arg_4 = new VkBufferCopy[regionCount];


		vkCmdCopyBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageCopy^>^ pRegions)
{
	VkImageCopy* arg_6 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcImage
		VkImage arg_1 = srcImage->mHandle;
		// 2 - srcImageLayout
		VkImageLayout arg_2 = srcImageLayout;
		// 3 - dstImage
		VkImage arg_3 = dstImage->mHandle;
		// 4 - dstImageLayout
		VkImageLayout arg_4 = dstImageLayout;
		// 5 - regionCount
		uint32_t arg_5 = 0;
		// 6 - pRegions
		arg_6 = new VkImageCopy[regionCount];


		vkCmdCopyImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);


		
	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBlitImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageBlit^>^ pRegions, VkFilter filter)
{
	VkImageBlit* arg_6 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcImage
		VkImage arg_1 = srcImage->mHandle;
		// 2 - srcImageLayout
		VkImageLayout arg_2 = srcImageLayout;
		// 3 - dstImage
		VkImage arg_3 = dstImage->mHandle;
		// 4 - dstImageLayout
		VkImageLayout arg_4 = dstImageLayout;
		// 5 - regionCount
		uint32_t arg_5 = 0;
		// 6 - pRegions
		arg_6 = new VkImageBlit[regionCount];
		// 7 - filter
		VkFilter arg_7 = filter;


		vkCmdBlitImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


		
	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyBufferToImage(Buffer^ srcBuffer, Image^ dstImage, VkImageLayout dstImageLayout, array<BufferImageCopy^>^ pRegions)
{
	VkBufferImageCopy* arg_5 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcBuffer
		VkBuffer arg_1 = srcBuffer->mHandle;
		// 2 - dstImage
		VkImage arg_2 = dstImage->mHandle;
		// 3 - dstImageLayout
		VkImageLayout arg_3 = dstImageLayout;
		// 4 - regionCount
		uint32_t arg_4 = 0;
		// 5 - pRegions
		arg_5 = new VkBufferImageCopy[regionCount];


		vkCmdCopyBufferToImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyImageToBuffer(Image^ srcImage, VkImageLayout srcImageLayout, Buffer^ dstBuffer, array<BufferImageCopy^>^ pRegions)
{
	VkBufferImageCopy* arg_5 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcImage
		VkImage arg_1 = srcImage->mHandle;
		// 2 - srcImageLayout
		VkImageLayout arg_2 = srcImageLayout;
		// 3 - dstBuffer
		VkBuffer arg_3 = dstBuffer->mHandle;
		// 4 - regionCount
		uint32_t arg_4 = 0;
		// 5 - pRegions
		arg_5 = new VkBufferImageCopy[regionCount];


		vkCmdCopyImageToBuffer(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdUpdateBuffer(Buffer^ dstBuffer, UInt64 dstOffset, UInt64 dataSize, ref UInt32 pData)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - dstBuffer
		VkBuffer arg_1 = dstBuffer->mHandle;
		// 2 - dstOffset
		VkDeviceSize arg_2 = 0;
		// 3 - dataSize
		VkDeviceSize arg_3 = 0;
		// 4 - pData
		uint32_t* arg_4 = 0;


		vkCmdUpdateBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdFillBuffer(Buffer^ dstBuffer, UInt64 dstOffset, UInt64 size, UInt32 data)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - dstBuffer
		VkBuffer arg_1 = dstBuffer->mHandle;
		// 2 - dstOffset
		VkDeviceSize arg_2 = 0;
		// 3 - size
		VkDeviceSize arg_3 = 0;
		// 4 - data
		uint32_t arg_4 = 0;


		vkCmdFillBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdClearColorImage(Image^ image, VkImageLayout imageLayout, ClearColorValue^ pColor, array<ImageSubresourceRange^>^ pRanges)
{
	VkImageSubresourceRange* arg_5 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - imageLayout
		VkImageLayout arg_2 = imageLayout;
		// 3 - pColor
		VkClearColorValue inst_3;
		VkClearColorValue* arg_3 = &inst_3;
		pColor->CopyTo(arg_3);
		// 4 - rangeCount
		uint32_t arg_4 = 0;
		// 5 - pRanges
		arg_5 = new VkImageSubresourceRange[rangeCount];


		vkCmdClearColorImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdClearDepthStencilImage(Image^ image, VkImageLayout imageLayout, ClearDepthStencilValue^ pDepthStencil, array<ImageSubresourceRange^>^ pRanges)
{
	VkImageSubresourceRange* arg_5 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - image
		VkImage arg_1 = image->mHandle;
		// 2 - imageLayout
		VkImageLayout arg_2 = imageLayout;
		// 3 - pDepthStencil
		VkClearDepthStencilValue inst_3;
		VkClearDepthStencilValue* arg_3 = &inst_3;
		pDepthStencil->CopyTo(arg_3);
		// 4 - rangeCount
		uint32_t arg_4 = 0;
		// 5 - pRanges
		arg_5 = new VkImageSubresourceRange[rangeCount];


		vkCmdClearDepthStencilImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		
	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdClearAttachments(array<ClearAttachment^>^ pAttachments, array<ClearRect^>^ pRects)
{
	VkClearAttachment* arg_2 = nullptr;
	VkClearRect* arg_4 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - attachmentCount
		uint32_t arg_1 = 0;
		// 2 - pAttachments
		arg_2 = new VkClearAttachment[attachmentCount];
		// 3 - rectCount
		uint32_t arg_3 = 0;
		// 4 - pRects
		arg_4 = new VkClearRect[rectCount];


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
	}
}

void ManagedVulkan::CommandBuffer::CmdResolveImage(Image^ srcImage, VkImageLayout srcImageLayout, Image^ dstImage, VkImageLayout dstImageLayout, array<ImageResolve^>^ pRegions)
{
	VkImageResolve* arg_6 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcImage
		VkImage arg_1 = srcImage->mHandle;
		// 2 - srcImageLayout
		VkImageLayout arg_2 = srcImageLayout;
		// 3 - dstImage
		VkImage arg_3 = dstImage->mHandle;
		// 4 - dstImageLayout
		VkImageLayout arg_4 = dstImageLayout;
		// 5 - regionCount
		uint32_t arg_5 = 0;
		// 6 - pRegions
		arg_6 = new VkImageResolve[regionCount];


		vkCmdResolveImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);


		
	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetEvent(Event^ event, VkPipelineStageFlags stageMask)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - event
		VkEvent arg_1 = event->mHandle;
		// 2 - stageMask
		VkPipelineStageFlags arg_2 = 0;


		vkCmdSetEvent(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdResetEvent(Event^ event, VkPipelineStageFlags stageMask)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - event
		VkEvent arg_1 = event->mHandle;
		// 2 - stageMask
		VkPipelineStageFlags arg_2 = 0;


		vkCmdResetEvent(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdWaitEvents(array<Event^>^ pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, array<MemoryBarrier^>^ pMemoryBarriers, array<BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ImageMemoryBarrier^>^ pImageMemoryBarriers)
{
	VkEvent* arg_2 = nullptr;
	VkMemoryBarrier* arg_6 = nullptr;
	VkBufferMemoryBarrier* arg_8 = nullptr;
	VkImageMemoryBarrier* arg_10 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - eventCount
		uint32_t arg_1 = 0;
		// 2 - pEvents
		arg_2 = new VkEvent[eventCount];
		// 3 - srcStageMask
		VkPipelineStageFlags arg_3 = 0;
		// 4 - dstStageMask
		VkPipelineStageFlags arg_4 = 0;
		// 5 - memoryBarrierCount
		uint32_t arg_5 = 0;
		// 6 - pMemoryBarriers
		arg_6 = new VkMemoryBarrier[memoryBarrierCount];
		// 7 - bufferMemoryBarrierCount
		uint32_t arg_7 = 0;
		// 8 - pBufferMemoryBarriers
		arg_8 = new VkBufferMemoryBarrier[bufferMemoryBarrierCount];
		// 9 - imageMemoryBarrierCount
		uint32_t arg_9 = 0;
		// 10 - pImageMemoryBarriers
		arg_10 = new VkImageMemoryBarrier[imageMemoryBarrierCount];


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
	}
}

void ManagedVulkan::CommandBuffer::CmdPipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, array<MemoryBarrier^>^ pMemoryBarriers, array<BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ImageMemoryBarrier^>^ pImageMemoryBarriers)
{
	VkMemoryBarrier* arg_5 = nullptr;
	VkBufferMemoryBarrier* arg_7 = nullptr;
	VkImageMemoryBarrier* arg_9 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - srcStageMask
		VkPipelineStageFlags arg_1 = 0;
		// 2 - dstStageMask
		VkPipelineStageFlags arg_2 = 0;
		// 3 - dependencyFlags
		VkDependencyFlags arg_3 = 0;
		// 4 - memoryBarrierCount
		uint32_t arg_4 = 0;
		// 5 - pMemoryBarriers
		arg_5 = new VkMemoryBarrier[memoryBarrierCount];
		// 6 - bufferMemoryBarrierCount
		uint32_t arg_6 = 0;
		// 7 - pBufferMemoryBarriers
		arg_7 = new VkBufferMemoryBarrier[bufferMemoryBarrierCount];
		// 8 - imageMemoryBarrierCount
		uint32_t arg_8 = 0;
		// 9 - pImageMemoryBarriers
		arg_9 = new VkImageMemoryBarrier[imageMemoryBarrierCount];


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
	}
}

void ManagedVulkan::CommandBuffer::CmdBeginQuery(QueryPool^ queryPool, UInt32 query, VkQueryControlFlags flags)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - queryPool
		VkQueryPool arg_1 = queryPool->mHandle;
		// 2 - query
		uint32_t arg_2 = 0;
		// 3 - flags
		VkQueryControlFlags arg_3 = 0;


		vkCmdBeginQuery(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdEndQuery(QueryPool^ queryPool, UInt32 query)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - queryPool
		VkQueryPool arg_1 = queryPool->mHandle;
		// 2 - query
		uint32_t arg_2 = 0;


		vkCmdEndQuery(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdResetQueryPool(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - queryPool
		VkQueryPool arg_1 = queryPool->mHandle;
		// 2 - firstQuery
		uint32_t arg_2 = 0;
		// 3 - queryCount
		uint32_t arg_3 = 0;


		vkCmdResetQueryPool(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdWriteTimestamp(VkPipelineStageFlagBits pipelineStage, QueryPool^ queryPool, UInt32 query)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - pipelineStage
		VkPipelineStageFlagBits arg_1 = pipelineStage;
		// 2 - queryPool
		VkQueryPool arg_2 = queryPool->mHandle;
		// 3 - query
		uint32_t arg_3 = 0;


		vkCmdWriteTimestamp(arg_0, arg_1, arg_2, arg_3);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyQueryPoolResults(QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, Buffer^ dstBuffer, UInt64 dstOffset, UInt64 stride, VkQueryResultFlags flags)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - queryPool
		VkQueryPool arg_1 = queryPool->mHandle;
		// 2 - firstQuery
		uint32_t arg_2 = 0;
		// 3 - queryCount
		uint32_t arg_3 = 0;
		// 4 - dstBuffer
		VkBuffer arg_4 = dstBuffer->mHandle;
		// 5 - dstOffset
		VkDeviceSize arg_5 = 0;
		// 6 - stride
		VkDeviceSize arg_6 = 0;
		// 7 - flags
		VkQueryResultFlags arg_7 = 0;


		vkCmdCopyQueryPoolResults(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdPushConstants(PipelineLayout^ layout, VkShaderStageFlags stageFlags, UInt32 offset, UInt32 size, IntPtr pValues)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - layout
		VkPipelineLayout arg_1 = layout->mHandle;
		// 2 - stageFlags
		VkShaderStageFlags arg_2 = 0;
		// 3 - offset
		uint32_t arg_3 = 0;
		// 4 - size
		uint32_t arg_4 = 0;
		// 5 - pValues
		void* arg_5 = 0;


		vkCmdPushConstants(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdBeginRenderPass(RenderPassBeginInfo^ pRenderPassBegin, VkSubpassContents contents)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - pRenderPassBegin
		VkRenderPassBeginInfo inst_1;
		VkRenderPassBeginInfo* arg_1 = &inst_1;
		pRenderPassBegin->CopyTo(arg_1);
		// 2 - contents
		VkSubpassContents arg_2 = contents;


		vkCmdBeginRenderPass(arg_0, arg_1, arg_2);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdNextSubpass(VkSubpassContents contents)
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - contents
		VkSubpassContents arg_1 = contents;


		vkCmdNextSubpass(arg_0, arg_1);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdEndRenderPass()
{
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;


		vkCmdEndRenderPass(arg_0);


		
	}
	finally
	{
	}
}

void ManagedVulkan::CommandBuffer::CmdExecuteCommands(array<CommandBuffer^>^ pCommandBuffers)
{
	VkCommandBuffer* arg_2 = nullptr;
	try
	{
		// 0 - commandBuffer
		VkCommandBuffer arg_0 = this->mHandle;
		// 1 - commandBufferCount
		uint32_t arg_1 = 0;
		// 2 - pCommandBuffers
		arg_2 = new VkCommandBuffer[commandBufferCount];


		vkCmdExecuteCommands(arg_0, arg_1, arg_2);


		
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
	}
}

