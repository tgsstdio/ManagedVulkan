#include "stdafx.h"
#include "VkInstance.h"

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
		VkAllocationCallbacks* arg_1 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_1 = &inst_1;
			pAllocator->CopyTo(arg_1, pins);
		}

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

		auto callback_0 = vkGetInstanceProcAddr(this->mHandle, "vkGetPhysicalDeviceDisplayPropertiesKHR");
		PFN_vkGetPhysicalDeviceDisplayPropertiesKHR getPhysicalDevicePtr_0 =  (callback_0 != nullptr) ? (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR) callback_0 : nullptr;

		auto callback_1 = vkGetInstanceProcAddr(this->mHandle, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
		PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR getPhysicalDevicePtr_1 = (callback_1 != nullptr) ? (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)callback_1 : nullptr;		

		auto callback_2 = vkGetInstanceProcAddr(this->mHandle, "vkGetDisplayPlaneSupportedDisplaysKHR");
		PFN_vkGetDisplayPlaneSupportedDisplaysKHR getPhysicalDevicePtr_2 = (callback_2 != nullptr) ? (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)callback_2 : nullptr;
		
		auto callback_3 = vkGetInstanceProcAddr(this->mHandle, "vkGetDisplayModePropertiesKHR");
		PFN_vkGetDisplayModePropertiesKHR getPhysicalDevicePtr_3 = (callback_3 != nullptr) ? (PFN_vkGetDisplayModePropertiesKHR) callback_3 : nullptr;

		auto callback_4 = vkGetInstanceProcAddr(this->mHandle, "vkCreateDisplayModeKHR");
		PFN_vkCreateDisplayModeKHR getPhysicalDevicePtr_4 = (callback_4 != nullptr) ? (PFN_vkCreateDisplayModeKHR)callback_4 : nullptr;

		int count = (int)pPhysicalDeviceCount;
		pPhysicalDevices = gcnew array<PhysicalDevice^>(count);
		for (int i = 0; i < count; ++i)
		{
			pPhysicalDevices[i] = gcnew PhysicalDevice();
			pPhysicalDevices[i]->mHandle = arg_2[i];
			pPhysicalDevices[i]->mGetPhysicalDeviceDisplayPropertiesKHR = getPhysicalDevicePtr_0;
			pPhysicalDevices[i]->mGetPhysicalDeviceDisplayPlanePropertiesKHR = getPhysicalDevicePtr_1;
			pPhysicalDevices[i]->mGetDisplayPlaneSupportedDisplaysKHR = getPhysicalDevicePtr_2;
			pPhysicalDevices[i]->mGetDisplayModePropertiesKHR = getPhysicalDevicePtr_3;
			pPhysicalDevices[i]->mCreateDisplayModeKHR = getPhysicalDevicePtr_4;
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

generic <typename VkDelegate>
where VkDelegate : System::Delegate, ref class
bool ManagedVulkan::Instance::GetInstanceProcAddr(String^ pName, [Out] VkDelegate% del)
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

		PFN_vkVoidFunction result = vkGetInstanceProcAddr(arg_0, arg_1);

		if (result != nullptr)
		{
			IntPtr stub(result);
			del = Marshal::GetDelegateForFunctionPointer<VkDelegate>(stub);
			return true;
		}
		else
		{
			return false;
		}
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

ManagedVulkan::Result ManagedVulkan::Instance::CreateDisplayPlaneSurfaceKHR(ManagedVulkan::DisplaySurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// FUNCTION STUB
		if (mCreateDisplayPlaneSurface == nullptr)
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkCreateDisplayPlaneSurfaceKHR");

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

		auto result = this->mCreateDisplayPlaneSurface(arg_0, arg_1, arg_2, arg_3);

		pSurface = gcnew SurfaceKHR();
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

		auto result = vkCreateWin32SurfaceKHR(arg_0, arg_1, arg_2, arg_3);

		pSurface = gcnew SurfaceKHR();
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


ManagedVulkan::Result ManagedVulkan::Instance::CreateDebugReportCallbackEXT(ManagedVulkan::DebugReportCallbackCreateInfoEXT^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::DebugReportCallbackEXT^% pCallback)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT
		if (this->mCreateDebugReportCallbackEXT == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkCreateDebugReportCallbackEXT");
		}


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
		VkDebugReportCallbackEXT* arg_3 = &inst_3;

		auto result = this->mCreateDebugReportCallbackEXT(arg_0, arg_1, arg_2, arg_3);

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
		// FUNCTION STUB
		if (this->mDestroyDebugReportCallbackEXT == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkDestroyDebugReportCallbackEXT");
		}

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

		this->mDestroyDebugReportCallbackEXT(arg_0, arg_1, arg_2);


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

void ManagedVulkan::Instance::DebugReportMessageEXT(ManagedVulkan::DebugReportFlagBitsEXT flags, ManagedVulkan::DebugReportObjectTypeEXT objectType, UInt64 object, UIntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// FUNCTION STUB
		if (this->mDebugReportMessageEXT == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find DebugReportMessageEXT");
		}

		// INITS 0 - instance		
		VkInstance arg_0 = this->mHandle;
		// INITS 1 - flags		
		VkDebugReportFlagsEXT arg_1 =(VkDebugReportFlagsEXT) flags;
		// INITS 2 - objectType		
		VkDebugReportObjectTypeEXT arg_2 = (VkDebugReportObjectTypeEXT)objectType;
		// INITS 3 - object		
		uint64_t arg_3 = object;
		// INITS 4 - location		
		size_t arg_4 = (location.Size == 8) ? location.ToUInt64() : location.ToUInt32();
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

		this->mDebugReportMessageEXT(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


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


