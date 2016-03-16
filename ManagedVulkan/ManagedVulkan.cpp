// This is the main DLL file.
#include "stdafx.h"
#include <vulkan/vulkan.h>
#include "ManagedVulkan.h"

using namespace System;
using namespace System::Runtime::InteropServices;

// Vulkan

UInt32 ManagedVulkan::Vulkan::MakeVersion(UInt32 major, UInt32 minor, UInt32 patch)
{
	return VK_MAKE_VERSION(major, minor, patch);
}

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

		auto createCallback = vkGetInstanceProcAddr(inst_2, "CreateDebugReportCallbackEXT");
		pInstance->mCreateDebugReportCallbackEXT = (createCallback != nullptr) ? (PFN_vkCreateDebugReportCallbackEXT)createCallback : nullptr;

		auto destroyCallback = vkGetInstanceProcAddr(inst_2, "DestroyDebugReportCallbackEXT");
		pInstance->mDestroyDebugReportCallbackEXT = (destroyCallback != nullptr) ? (PFN_vkDestroyDebugReportCallbackEXT)destroyCallback : nullptr;

		auto debugReport = vkGetInstanceProcAddr(inst_2, "DebugReportMessageEXT");
		pInstance->mDebugReportMessageEXT = (debugReport != nullptr) ? (PFN_vkDebugReportMessageEXT)debugReport : nullptr;

		auto createPlane = vkGetInstanceProcAddr(inst_2, "CreateDisplayPlaneSurfaceKHR");
		pInstance->mCreateDisplayPlaneSurface = (createPlane != nullptr) ? (PFN_vkCreateDisplayPlaneSurfaceKHR)createPlane : nullptr;

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
