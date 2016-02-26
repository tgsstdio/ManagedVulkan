// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan {

	public ref class ExtensionProperties
	{
		/**
		typedef struct VkExtensionProperties {
			char        extensionName[VK_MAX_EXTENSION_NAME_SIZE];
			uint32_t    specVersion;
		} VkExtensionProperties;
		**/
	private:
		String^ mExtensionName = nullptr;
		UInt32 mSpecVersion = 0;
	public:
		property String^ ExtensionName
		{
			String^ get()
			{
				return mExtensionName;
			}

			void set(String^ value)
			{
				mExtensionName = value;
			}
		}

		property UInt32 SpecVersion
		{
			UInt32 get()
			{
				return mSpecVersion;
			}
			void set(UInt32 value)
			{
				mSpecVersion = value;
			}
		}
	};

	public ref class ApplicationInfo
	{
		/**
		typedef struct VkApplicationInfo {
			VkStructureType    sType; // CONSTANT
			const void*        pNext;
			const char*        pApplicationName;
			uint32_t           applicationVersion;
			const char*        pEngineName;
			uint32_t           engineVersion;
			uint32_t           apiVersion;
		} VkApplicationInfo;
		**/
	private:
		String^ mApplicationName = nullptr;
		UInt32 mApplicationVersion = 0;
		String^ mEngineName = nullptr;
		UInt32 mEngineVersion = 0;
		UInt32 mApiVersion = 0;
	public:
		property String^ ApplicationName
		{
			String^ get()
			{
				return mApplicationName;
			}

			void set(String^ value)
			{
				mApplicationName = value;
			}
		}

		property UInt32 ApplicationVersion
		{
			UInt32 get()
			{
				return mApplicationVersion;
			}
			void set(UInt32 value)
			{
				mApplicationVersion = value;
			}
		}

		property String^ EngineName
		{
			String^ get()
			{
				return mEngineName;
			}

			void set(String^ value)
			{
				mEngineName = value;
			}
		}

		property UInt32 EngineVersion
		{
			UInt32 get()
			{
				return mEngineVersion;
			}
			void set(UInt32 value)
			{
				mEngineVersion = value;
			}
		}

		property UInt32 ApiVersion
		{
			UInt32 get()
			{
				return mApiVersion;
			}
			void set(UInt32 value)
			{
				mApiVersion = value;
			}
		}
	};

	public ref class CreateInstanceInfo
	{
		/**
		typedef struct VkInstanceCreateInfo {
			VkStructureType             sType; // CONSTANT
			const void*                 pNext; // NULL all the time
			VkInstanceCreateFlags       flags; 
			const VkApplicationInfo*    pApplicationInfo;
			uint32_t                    enabledLayerCount;
			const char* const*          ppEnabledLayerNames;
			uint32_t                    enabledExtensionCount;
			const char* const*          ppEnabledExtensionNames;
		} VkInstanceCreateInfo;
		**/

	private:
		UInt32 mFlags = 0;
		array<String ^>^ mLayerNames = nullptr;
		array<String ^>^ mEnabledExtensionNames = nullptr;
		ApplicationInfo^ mpApplicationInfo = nullptr;
	public:
		property UInt32 Flags
		{
			UInt32 get()
			{
				return mFlags;
			}
			void set(UInt32 value)
			{
				mFlags = value;
			}
		}

		property ApplicationInfo^ ApplicationInfo
		{
			ManagedVulkan::ApplicationInfo^ get()
			{
				return mpApplicationInfo;
			}
			void set(ManagedVulkan::ApplicationInfo^ value)
			{
				mpApplicationInfo = value;
			}
		}

		property array<String ^>^ EnabledLayerNames
		{
			array<String ^>^ get()
			{
				return mLayerNames;
			}
			void set(array<String ^>^ value)
			{
				mLayerNames = value;
			}
		}

		property array<String ^>^ EnabledExtensionNames
		{
			array<String ^>^ get()
			{
				return mEnabledExtensionNames;
			}
			void set(array<String ^>^ value)
			{
				mEnabledExtensionNames = value;
			}
		}
	};

	public ref class Instance
	{
	internal:
		VkInstance inst;
	};

	public ref class Vulkan
	{
		// TODO: Add your methods for this class here.
		public:
			static UInt32 GetNoOfExtensionProperties();
			static array<ExtensionProperties^>^ EnumerateInstanceExtensionProperties();
			static ManagedVulkan::Instance^ CreateInstance(ManagedVulkan::CreateInstanceInfo^ pCreateInfo);
	};
}
