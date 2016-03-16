#include "stdafx.h"
#include "VkPhysicalDevice.h"

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
		VkFormat arg_1 = (VkFormat)format;
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

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceImageFormatProperties(ManagedVulkan::Format format, ManagedVulkan::ImageType type, ManagedVulkan::ImageTiling tiling, ManagedVulkan::ImageUsageFlagBits usage, ManagedVulkan::ImageCreateFlagBits flags, [Out] ManagedVulkan::ImageFormatProperties^% pImageFormatProperties)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - format		
		VkFormat arg_1 = (VkFormat)format;
		// INITS 2 - type		
		VkImageType arg_2 = (VkImageType)type;
		// INITS 3 - tiling		
		VkImageTiling arg_3 = (VkImageTiling)tiling;
		// INITS 4 - usage		
		VkImageUsageFlags arg_4 = (VkImageUsageFlagBits) usage;
		// INITS 5 - flags		
		VkImageCreateFlags arg_5 = (VkImageCreateFlags) flags;
		// INITS 6 - pImageFormatProperties		
		VkImageFormatProperties inst_6;
		VkImageFormatProperties* arg_6 = &inst_6;

		int result = vkGetPhysicalDeviceImageFormatProperties(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);

		pImageFormatProperties = gcnew ImageFormatProperties();
		pImageFormatProperties->CopyFrom(arg_6);

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

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::CreateDevice(ManagedVulkan::DeviceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Device^% pDevice)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	char** arg_1_6 = nullptr;
	char** arg_1_8 = nullptr;
	VkDeviceQueueCreateInfo* arg_1_4 = nullptr;
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

		if (pCreateInfo != nullptr && pCreateInfo->QueueCreateInfos != nullptr)
		{
			UInt32 queueCreateInfoCount = pCreateInfo->QueueCreateInfos->Length;
			if (queueCreateInfoCount > 0)
			{
				arg_1_4 = new VkDeviceQueueCreateInfo[queueCreateInfoCount];
				for (UInt32 j = 0; j < queueCreateInfoCount; ++j)
				{
					auto srcInfo = (ManagedVulkan::DeviceQueueCreateInfo^) pCreateInfo->QueueCreateInfos[j];
					srcInfo->CopyTo(arg_1_4 + j, pins);
				}
			}
			arg_1->pQueueCreateInfos = arg_1_4;
			arg_1->queueCreateInfoCount = queueCreateInfoCount;
		}


		// FIELD - arg_1_6 pCreateInfo->EnabledLayerNames		
		if (pCreateInfo != nullptr && pCreateInfo->EnabledLayerNames != nullptr)
		{
			UInt32 enabledLayerCount = pCreateInfo->EnabledLayerNames->Length;
			arg_1_6 = new char*[enabledLayerCount];
			for (UInt32 j = 0; j < enabledLayerCount; ++j)
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
			UInt32 enabledExtensionCount = pCreateInfo->EnabledExtensionNames->Length;
			arg_1_8 = new char*[enabledExtensionCount];
			for (UInt32 j = 0; j < enabledExtensionCount; ++j)
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

		auto callback = vkGetDeviceProcAddr(inst_3, "vkCreateSharedSwapchainsKHR");
		pDevice->mCreateSharedSwapchainsKHR = (callback != nullptr) ? (PFN_vkCreateSharedSwapchainsKHR) callback : nullptr;

		return (Result)result;
	}
	finally
	{
		if (arg_1_4 != nullptr)
		{
			delete[] arg_1_4;
		}

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
			return (Result)firstResult;
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
		VkFormat arg_1 = (VkFormat)format;
		// INITS 2 - type		
		VkImageType arg_2 = (VkImageType)type;
		// INITS 3 - samples		
		VkSampleCountFlagBits arg_3 = (VkSampleCountFlagBits)samples;
		// INITS 4 - usage		
		VkImageUsageFlags arg_4 = usage;
		// INITS 5 - tiling		
		VkImageTiling arg_5 = (VkImageTiling)tiling;
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
		if (this->mGetPhysicalDeviceDisplayPropertiesKHR == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkCreateDisplayPlaneSurfaceKHR");
		}


		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		uint32_t pPropertyCount = 0;
		// INITS 1 - pPropertyCount		
		uint32_t* arg_1 = &pPropertyCount;

		int firstResult = this->mGetPhysicalDeviceDisplayPropertiesKHR(arg_0, arg_1, arg_2);

		if (firstResult != VK_SUCCESS)
		{
			return (ManagedVulkan::Result)firstResult;
		}

		// INITS 2 - pProperties		
		arg_2 = new VkDisplayPropertiesKHR[pPropertyCount];

		int result = this->mGetPhysicalDeviceDisplayPropertiesKHR(arg_0, arg_1, arg_2);

		int count = (int)pPropertyCount;
		pProperties = gcnew array<ManagedVulkan::DisplayPropertiesKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pProperties[i] = gcnew ManagedVulkan::DisplayPropertiesKHR();
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
		if (this->mGetPhysicalDeviceDisplayPlanePropertiesKHR != nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
		}

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - pPropertyCount		
		uint32_t pPropertyCount = 0;
		uint32_t* arg_1 = &pPropertyCount;

		int firstResult = this->mGetPhysicalDeviceDisplayPlanePropertiesKHR(arg_0, arg_1, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// INITS 2 - pProperties		
		arg_2 = new VkDisplayPlanePropertiesKHR[pPropertyCount];

		int result = this->mGetPhysicalDeviceDisplayPlanePropertiesKHR(arg_0, arg_1, arg_2);

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
		if (this->mGetDisplayPlaneSupportedDisplaysKHR == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkGetDisplayPlaneSupportedDisplaysKHR");
		}

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - planeIndex		
		uint32_t arg_1 = planeIndex;


		uint32_t pDisplayCount = 0;
		// INITS 2 - pDisplayCount		
		uint32_t* arg_2 = &pDisplayCount;

		int firstResult = this->mGetDisplayPlaneSupportedDisplaysKHR(arg_0, arg_1, arg_2, nullptr);
		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// INITS 3 - pDisplays		
		arg_3 = new VkDisplayKHR[pDisplayCount];

		int result = this->mGetDisplayPlaneSupportedDisplaysKHR(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pDisplayCount;
		pDisplays = gcnew array<DisplayKHR^>(count);
		for (int i = 0; i < count; ++i)
		{
			pDisplays[i] = gcnew DisplayKHR();
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
		// FUNCTION STUB
		if (this->mGetDisplayModePropertiesKHR == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkGetDisplayModePropertiesKHR");
		}

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - display		
		VkDisplayKHR arg_1 = display->mHandle;
		// INITS 2 - pPropertyCount		
		uint32_t pPropertyCount = 0;
		uint32_t* arg_2 = &pPropertyCount;

		int firstResult = this->mGetDisplayModePropertiesKHR(arg_0, arg_1, arg_2, nullptr);

		if (firstResult != VK_SUCCESS)
		{
			return (Result)firstResult;
		}

		// INITS 3 - pProperties		
		arg_3 = new VkDisplayModePropertiesKHR[pPropertyCount];

		int result = this->mGetDisplayModePropertiesKHR(arg_0, arg_1, arg_2, arg_3);

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
		// FUNCTION STUB
		if (this->mCreateDisplayModeKHR == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkCreateDisplayModeKHR");
		}

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

		auto result = this->mCreateDisplayModeKHR(arg_0, arg_1, arg_2, arg_3, arg_4);

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

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetPhysicalDeviceSurfaceSupportKHR(UInt32 queueFamilyIndex, ManagedVulkan::SurfaceKHR^ surface,[Out] bool% pSupported)
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

		auto result = vkGetPhysicalDeviceSurfaceSupportKHR(arg_0, arg_1, arg_2, arg_3);
		pSupported = inst_3 != 0;

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
			pPresentModes[i] = (PresentModeKHR)arg_3[i];
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

ManagedVulkan::Result ManagedVulkan::PhysicalDevice::GetDisplayPlaneCapabilitiesKHR(ManagedVulkan::DisplayModeKHR^ mode, UInt32 planeIndex, [Out] ManagedVulkan::DisplayPlaneCapabilitiesKHR^% pCapabilities)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// FUNCTION STUB
		if (this->mGetDisplayPlaneCapabilitiesKHR == nullptr)
		{
			throw gcnew System::NotSupportedException("GetProcAddr: Unable to find vkGetDisplayPlaneCapabilitiesKHR");
		}

		// INITS 0 - physicalDevice		
		VkPhysicalDevice arg_0 = this->mHandle;
		// INITS 1 - mode		
		VkDisplayModeKHR arg_1 = mode->mHandle;
		// INITS 2 - planeIndex		
		uint32_t arg_2 = planeIndex;
		// INITS 3 - pCapabilities		
		VkDisplayPlaneCapabilitiesKHR inst_3;
		VkDisplayPlaneCapabilitiesKHR* arg_3 = &inst_3;

		int result = this->mGetDisplayPlaneCapabilitiesKHR(arg_0, arg_1, arg_2, arg_3);

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
