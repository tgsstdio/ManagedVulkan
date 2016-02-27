// This is the main DLL file.

#include "stdafx.h"
#include <vulkan/vulkan.h>
#include "ManagedVulkan.h"

UInt32 ManagedVulkan::Vulkan::GetNoOfExtensionProperties()
{
	uint32_t instance_extension_count = 0;
	auto err = vkEnumerateInstanceExtensionProperties(
		NULL, &instance_extension_count, NULL);
	return (UInt32) instance_extension_count;
}

array<ManagedVulkan::ExtensionProperties^>^ ManagedVulkan::Vulkan::EnumerateInstanceExtensionProperties()
{
	VkExtensionProperties* instance_extensions = nullptr;
	try
	{

		uint32_t instance_extension_count = 0;
		auto err = vkEnumerateInstanceExtensionProperties(
			NULL, &instance_extension_count, NULL);

		int count = (int)instance_extension_count;
		instance_extensions = new VkExtensionProperties[count];
		err = vkEnumerateInstanceExtensionProperties(
			NULL, &instance_extension_count, instance_extensions);

		array<ExtensionProperties ^> ^output = gcnew array<ExtensionProperties ^>(count);
		
		// CODE copied from http://www.codeproject.com/Articles/19354/Quick-C-CLI-Learn-C-CLI-in-less-than-minutes#A8
		// We use the tracking reference to access the references inside the array
		// since normally strings are passed by value
		VkExtensionProperties* current = &instance_extensions[0];

		for (int i = 0; i < count; ++i)
		{
			// HOPEFULLY THIS ISN'T NULL PADDED TO 256
			output[i] = gcnew ExtensionProperties();
			output[i]->ExtensionName = gcnew String(current->extensionName);
			output[i]->SpecVersion = current->specVersion;
			++current;
		}

		return output;
	}
	finally
	{
		if (instance_extensions != nullptr)
		{
			delete instance_extensions;
		}
	}
}

using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

ManagedVulkan::Instance ^ ManagedVulkan::Vulkan::CreateInstance(ManagedVulkan::CreateInstanceInfo^ createInfo)
{
	char* layerNames = nullptr;
	char* enabledExtensions = nullptr;
		
	List<IntPtr>^ disposables = gcnew List<IntPtr>();

	try
	{
		VkInstanceCreateInfo input;
		VkApplicationInfo appInfo;

		if (createInfo->ApplicationInfo != nullptr)
		{
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pNext = nullptr;
			
			appInfo.apiVersion = createInfo->ApplicationInfo->ApiVersion;
			appInfo.applicationVersion = createInfo->ApplicationInfo->ApplicationVersion;
			appInfo.engineVersion = createInfo->ApplicationInfo->EngineVersion;

			// APPLICATION NAME
			if (createInfo->ApplicationInfo->ApplicationName != nullptr)
			{
				IntPtr applicationName = Marshal::StringToHGlobalAnsi(createInfo->ApplicationInfo->ApplicationName);
				disposables->Add(applicationName);
				appInfo.pApplicationName = static_cast<char*>(applicationName.ToPointer());
			}
			else
			{
				appInfo.pApplicationName = nullptr;
			}

			// ENGINE NAME 
			if (createInfo->ApplicationInfo->EngineName != nullptr)
			{
				IntPtr engineName = Marshal::StringToHGlobalAnsi(createInfo->ApplicationInfo->EngineName);
				disposables->Add(engineName);
				appInfo.pEngineName = static_cast<char*>(engineName.ToPointer());
			}
			else
			{
				appInfo.pEngineName = nullptr;
			}
			input.pApplicationInfo = &appInfo;
		}
		else
		{
			input.pApplicationInfo = nullptr;
		}

		input.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		input.pNext = nullptr;

		input.flags = createInfo->Flags;
	
		// enabled layer names
		input.enabledLayerCount = (UInt32) createInfo->EnabledLayerNames->Length;
		for each (String^ layer in createInfo->EnabledLayerNames)
		{
			IntPtr layerName = Marshal::StringToHGlobalAnsi(layer);
			disposables->Add(layerName);
			appInfo.pEngineName = static_cast<char*>(layerName.ToPointer());
		}

		// enabled extensions
		input.enabledExtensionCount = (UInt32)createInfo->EnabledExtensionNames->Length;
		for each (String^ extension in createInfo->EnabledExtensionNames)
		{
			IntPtr extensionName = Marshal::StringToHGlobalAnsi(extension);
			disposables->Add(extensionName);
			appInfo.pEngineName = static_cast<char*>(extensionName.ToPointer());
		}

		VkInstance inst;
		VkResult result = vkCreateInstance(&input, nullptr, &inst);

		if (result != VK_SUCCESS)
		{
			switch (result)
			{
			case VK_ERROR_OUT_OF_HOST_MEMORY:
				throw gcnew System::InvalidOperationException("VK_ERROR_OUT_OF_HOST_MEMORY");
			case VK_ERROR_OUT_OF_DEVICE_MEMORY:
				throw gcnew System::InvalidOperationException("VK_ERROR_OUT_OF_DEVICE_MEMORY");
			case VK_ERROR_INITIALIZATION_FAILED:
				throw gcnew System::InvalidOperationException("VK_ERROR_INITIALIZATION_FAILED");
			case VK_ERROR_LAYER_NOT_PRESENT:
				throw gcnew System::InvalidOperationException("VK_ERROR_LAYER_NOT_PRESENT");
			case VK_ERROR_EXTENSION_NOT_PRESENT:
				throw gcnew System::InvalidOperationException("VK_ERROR_EXTENSION_NOT_PRESENT");
			case VK_ERROR_INCOMPATIBLE_DRIVER:
				throw gcnew System::InvalidOperationException("VK_ERROR_INCOMPATIBLE_DRIVER");
			default:
				throw gcnew System::InvalidOperationException("VK ERROR - UNKNOWN");
			}
		}

		ManagedVulkan::Instance^ outcome = gcnew ManagedVulkan::Instance();
		outcome->inst = inst;
		return outcome;
	}
	finally
	{
		for each(IntPtr str in disposables)
		{
			Marshal::FreeHGlobal(str);
		}
	}
	
}
