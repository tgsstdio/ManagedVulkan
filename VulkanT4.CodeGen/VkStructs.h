// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>
#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"

using namespace System;

namespace ManagedVulkan 
{

	// STRUCTS 
	public ref class Offset2D
	{
	private:
		Int32 mX = 0;
		Int32 mY = 0;
	public:
		property Int32 X
		{
			Int32 get()
			{
				return mX;
			}
			void set(Int32 value)
			{
				mX = value; 
			}
		}
		property Int32 Y
		{
			Int32 get()
			{
				return mY;
			}
			void set(Int32 value)
			{
				mY = value; 
			}
		}
	};

	public ref class Offset3D
	{
	private:
		Int32 mX = 0;
		Int32 mY = 0;
		Int32 mZ = 0;
	public:
		property Int32 X
		{
			Int32 get()
			{
				return mX;
			}
			void set(Int32 value)
			{
				mX = value; 
			}
		}
		property Int32 Y
		{
			Int32 get()
			{
				return mY;
			}
			void set(Int32 value)
			{
				mY = value; 
			}
		}
		property Int32 Z
		{
			Int32 get()
			{
				return mZ;
			}
			void set(Int32 value)
			{
				mZ = value; 
			}
		}
	};

	public ref class Extent2D
	{
	private:
		UInt32 mWidth = 0;
		UInt32 mHeight = 0;
	public:
		property UInt32 Width
		{
			UInt32 get()
			{
				return mWidth;
			}
			void set(UInt32 value)
			{
				mWidth = value; 
			}
		}
		property UInt32 Height
		{
			UInt32 get()
			{
				return mHeight;
			}
			void set(UInt32 value)
			{
				mHeight = value; 
			}
		}
	};

	public ref class Extent3D
	{
	private:
		UInt32 mWidth = 0;
		UInt32 mHeight = 0;
		UInt32 mDepth = 0;
	public:
		property UInt32 Width
		{
			UInt32 get()
			{
				return mWidth;
			}
			void set(UInt32 value)
			{
				mWidth = value; 
			}
		}
		property UInt32 Height
		{
			UInt32 get()
			{
				return mHeight;
			}
			void set(UInt32 value)
			{
				mHeight = value; 
			}
		}
		property UInt32 Depth
		{
			UInt32 get()
			{
				return mDepth;
			}
			void set(UInt32 value)
			{
				mDepth = value; 
			}
		}
	};

	public ref class Viewport
	{
	private:
		float mX = 0f;
		float mY = 0f;
		float mWidth = 0f;
		float mHeight = 0f;
		float mMinDepth = 0f;
		float mMaxDepth = 0f;
	public:
		property float X
		{
			float get()
			{
				return mX;
			}
			void set(float value)
			{
				mX = value; 
			}
		}
		property float Y
		{
			float get()
			{
				return mY;
			}
			void set(float value)
			{
				mY = value; 
			}
		}
		property float Width
		{
			float get()
			{
				return mWidth;
			}
			void set(float value)
			{
				mWidth = value; 
			}
		}
		property float Height
		{
			float get()
			{
				return mHeight;
			}
			void set(float value)
			{
				mHeight = value; 
			}
		}
		property float MinDepth
		{
			float get()
			{
				return mMinDepth;
			}
			void set(float value)
			{
				mMinDepth = value; 
			}
		}
		property float MaxDepth
		{
			float get()
			{
				return mMaxDepth;
			}
			void set(float value)
			{
				mMaxDepth = value; 
			}
		}
	};

	public ref class Rect2D
	{
	private:
		Offset2D^ mOffset = nullptr;
		Extent2D^ mExtent = nullptr;
	public:
		property Offset2D^ Offset
		{
			Offset2D^ get()
			{
				return mOffset;
			}
			void set(Offset2D^ value)
			{
				mOffset = value; 
			}
		}
		property Extent2D^ Extent
		{
			Extent2D^ get()
			{
				return mExtent;
			}
			void set(Extent2D^ value)
			{
				mExtent = value; 
			}
		}
	};

	public ref class Rect3D
	{
	private:
		Offset3D^ mOffset = nullptr;
		Extent3D^ mExtent = nullptr;
	public:
		property Offset3D^ Offset
		{
			Offset3D^ get()
			{
				return mOffset;
			}
			void set(Offset3D^ value)
			{
				mOffset = value; 
			}
		}
		property Extent3D^ Extent
		{
			Extent3D^ get()
			{
				return mExtent;
			}
			void set(Extent3D^ value)
			{
				mExtent = value; 
			}
		}
	};

	public ref class ClearRect
	{
	private:
		Rect2D^ mRect = nullptr;
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property Rect2D^ Rect
		{
			Rect2D^ get()
			{
				return mRect;
			}
			void set(Rect2D^ value)
			{
				mRect = value; 
			}
		}
		property UInt32 BaseArrayLayer
		{
			UInt32 get()
			{
				return mBaseArrayLayer;
			}
			void set(UInt32 value)
			{
				mBaseArrayLayer = value; 
			}
		}
		property UInt32 LayerCount
		{
			UInt32 get()
			{
				return mLayerCount;
			}
			void set(UInt32 value)
			{
				mLayerCount = value; 
			}
		}
	};

	public ref class ComponentMapping
	{
	private:
		VkComponentSwizzle mR;
		VkComponentSwizzle mG;
		VkComponentSwizzle mB;
		VkComponentSwizzle mA;
	public:
		property VkComponentSwizzle R
		{
			VkComponentSwizzle get()
			{
				return mR;
			}
			void set(VkComponentSwizzle value)
			{
				mR = value; 
			}
		}
		property VkComponentSwizzle G
		{
			VkComponentSwizzle get()
			{
				return mG;
			}
			void set(VkComponentSwizzle value)
			{
				mG = value; 
			}
		}
		property VkComponentSwizzle B
		{
			VkComponentSwizzle get()
			{
				return mB;
			}
			void set(VkComponentSwizzle value)
			{
				mB = value; 
			}
		}
		property VkComponentSwizzle A
		{
			VkComponentSwizzle get()
			{
				return mA;
			}
			void set(VkComponentSwizzle value)
			{
				mA = value; 
			}
		}
	};

	public ref class PhysicalDeviceProperties
	{
	private:
		UInt32 mApiVersion = 0;
		UInt32 mDriverVersion = 0;
		UInt32 mVendorID = 0;
		UInt32 mDeviceID = 0;
		VkPhysicalDeviceType mDeviceType;
		String^ mDeviceName = nullptr;
		pipelineCacheUUID mVK_UUID_SIZE;
		PhysicalDeviceLimits^ mLimits = nullptr;
		PhysicalDeviceSparseProperties^ mSparseProperties = nullptr;
	public:
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
		property UInt32 DriverVersion
		{
			UInt32 get()
			{
				return mDriverVersion;
			}
			void set(UInt32 value)
			{
				mDriverVersion = value; 
			}
		}
		property UInt32 VendorID
		{
			UInt32 get()
			{
				return mVendorID;
			}
			void set(UInt32 value)
			{
				mVendorID = value; 
			}
		}
		property UInt32 DeviceID
		{
			UInt32 get()
			{
				return mDeviceID;
			}
			void set(UInt32 value)
			{
				mDeviceID = value; 
			}
		}
		property VkPhysicalDeviceType DeviceType
		{
			VkPhysicalDeviceType get()
			{
				return mDeviceType;
			}
			void set(VkPhysicalDeviceType value)
			{
				mDeviceType = value; 
			}
		}
		property String^ DeviceName
		{
			String^ get()
			{
				return mDeviceName;
			}
			void set(String^ value)
			{
				mDeviceName = value; 
			}
		}
		property pipelineCacheUUID VK_UUID_SIZE
		{
			pipelineCacheUUID get()
			{
				return mVK_UUID_SIZE;
			}
			void set(pipelineCacheUUID value)
			{
				mVK_UUID_SIZE = value; 
			}
		}
		property PhysicalDeviceLimits^ Limits
		{
			PhysicalDeviceLimits^ get()
			{
				return mLimits;
			}
			void set(PhysicalDeviceLimits^ value)
			{
				mLimits = value; 
			}
		}
		property PhysicalDeviceSparseProperties^ SparseProperties
		{
			PhysicalDeviceSparseProperties^ get()
			{
				return mSparseProperties;
			}
			void set(PhysicalDeviceSparseProperties^ value)
			{
				mSparseProperties = value; 
			}
		}
	};

	public ref class ExtensionProperties
	{
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

	public ref class LayerProperties
	{
	private:
		String^ mLayerName = nullptr;
		UInt32 mSpecVersion = 0;
		UInt32 mImplementationVersion = 0;
		String^ mDescription = nullptr;
	public:
		property String^ LayerName
		{
			String^ get()
			{
				return mLayerName;
			}
			void set(String^ value)
			{
				mLayerName = value; 
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
		property UInt32 ImplementationVersion
		{
			UInt32 get()
			{
				return mImplementationVersion;
			}
			void set(UInt32 value)
			{
				mImplementationVersion = value; 
			}
		}
		property String^ Description
		{
			String^ get()
			{
				return mDescription;
			}
			void set(String^ value)
			{
				mDescription = value; 
			}
		}
	};

	public ref class ApplicationInfo
	{
	private:
		VkStructureType mSType;
		String^ mApplicationName = nullptr;
		UInt32 mApplicationVersion = 0;
		String^ mEngineName = nullptr;
		UInt32 mEngineVersion = 0;
		UInt32 mApiVersion = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
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

	public ref class AllocationCallbacks
	{
	private:
		IntPtr mUserData = IntPtr.Zero;
		PFN_vkAllocationFunction mPfnAllocation;
		PFN_vkReallocationFunction mPfnReallocation;
		PFN_vkFreeFunction mPfnFree;
		PFN_vkInternalAllocationNotification mPfnInternalAllocation;
		PFN_vkInternalFreeNotification mPfnInternalFree;
	public:
		property IntPtr UserData
		{
			IntPtr get()
			{
				return mUserData;
			}
			void set(IntPtr value)
			{
				mUserData = value; 
			}
		}
		property PFN_vkAllocationFunction PfnAllocation
		{
			PFN_vkAllocationFunction get()
			{
				return mPfnAllocation;
			}
			void set(PFN_vkAllocationFunction value)
			{
				mPfnAllocation = value; 
			}
		}
		property PFN_vkReallocationFunction PfnReallocation
		{
			PFN_vkReallocationFunction get()
			{
				return mPfnReallocation;
			}
			void set(PFN_vkReallocationFunction value)
			{
				mPfnReallocation = value; 
			}
		}
		property PFN_vkFreeFunction PfnFree
		{
			PFN_vkFreeFunction get()
			{
				return mPfnFree;
			}
			void set(PFN_vkFreeFunction value)
			{
				mPfnFree = value; 
			}
		}
		property PFN_vkInternalAllocationNotification PfnInternalAllocation
		{
			PFN_vkInternalAllocationNotification get()
			{
				return mPfnInternalAllocation;
			}
			void set(PFN_vkInternalAllocationNotification value)
			{
				mPfnInternalAllocation = value; 
			}
		}
		property PFN_vkInternalFreeNotification PfnInternalFree
		{
			PFN_vkInternalFreeNotification get()
			{
				return mPfnInternalFree;
			}
			void set(PFN_vkInternalFreeNotification value)
			{
				mPfnInternalFree = value; 
			}
		}
	};

	public ref class DeviceQueueCreateInfo
	{
	private:
		VkStructureType mSType;
		VkDeviceQueueCreateFlags mFlags;
		UInt32 mQueueFamilyIndex = 0;
		UInt32 mQueueCount = 0;
		float mQueuePriorities = 0f;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDeviceQueueCreateFlags Flags
		{
			VkDeviceQueueCreateFlags get()
			{
				return mFlags;
			}
			void set(VkDeviceQueueCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 QueueFamilyIndex
		{
			UInt32 get()
			{
				return mQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndex = value; 
			}
		}
		property UInt32 QueueCount
		{
			UInt32 get()
			{
				return mQueueCount;
			}
			void set(UInt32 value)
			{
				mQueueCount = value; 
			}
		}
		property float QueuePriorities
		{
			float get()
			{
				return mQueuePriorities;
			}
			void set(float value)
			{
				mQueuePriorities = value; 
			}
		}
	};

	public ref class DeviceCreateInfo
	{
	private:
		VkStructureType mSType;
		VkDeviceCreateFlags mFlags;
		UInt32 mQueueCreateInfoCount = 0;
		DeviceQueueCreateInfo^ mQueueCreateInfos = nullptr;
		UInt32 mEnabledLayerCount = 0;
		array<String^>^ mEnabledLayerNames = nullptr;
		UInt32 mEnabledExtensionCount = 0;
		array<String^>^ mEnabledExtensionNames = nullptr;
		PhysicalDeviceFeatures^ mEnabledFeatures = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDeviceCreateFlags Flags
		{
			VkDeviceCreateFlags get()
			{
				return mFlags;
			}
			void set(VkDeviceCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 QueueCreateInfoCount
		{
			UInt32 get()
			{
				return mQueueCreateInfoCount;
			}
			void set(UInt32 value)
			{
				mQueueCreateInfoCount = value; 
			}
		}
		property DeviceQueueCreateInfo^ QueueCreateInfos
		{
			DeviceQueueCreateInfo^ get()
			{
				return mQueueCreateInfos;
			}
			void set(DeviceQueueCreateInfo^ value)
			{
				mQueueCreateInfos = value; 
			}
		}
		property UInt32 EnabledLayerCount
		{
			UInt32 get()
			{
				return mEnabledLayerCount;
			}
			void set(UInt32 value)
			{
				mEnabledLayerCount = value; 
			}
		}
		property array<String^>^ EnabledLayerNames
		{
			array<String^>^ get()
			{
				return mEnabledLayerNames;
			}
			void set(array<String^>^ value)
			{
				mEnabledLayerNames = value; 
			}
		}
		property UInt32 EnabledExtensionCount
		{
			UInt32 get()
			{
				return mEnabledExtensionCount;
			}
			void set(UInt32 value)
			{
				mEnabledExtensionCount = value; 
			}
		}
		property array<String^>^ EnabledExtensionNames
		{
			array<String^>^ get()
			{
				return mEnabledExtensionNames;
			}
			void set(array<String^>^ value)
			{
				mEnabledExtensionNames = value; 
			}
		}
		property PhysicalDeviceFeatures^ EnabledFeatures
		{
			PhysicalDeviceFeatures^ get()
			{
				return mEnabledFeatures;
			}
			void set(PhysicalDeviceFeatures^ value)
			{
				mEnabledFeatures = value; 
			}
		}
	};

	public ref class InstanceCreateInfo
	{
	private:
		VkStructureType mSType;
		VkInstanceCreateFlags mFlags;
		ApplicationInfo^ mApplicationInfo = nullptr;
		UInt32 mEnabledLayerCount = 0;
		array<String^>^ mEnabledLayerNames = nullptr;
		UInt32 mEnabledExtensionCount = 0;
		array<String^>^ mEnabledExtensionNames = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkInstanceCreateFlags Flags
		{
			VkInstanceCreateFlags get()
			{
				return mFlags;
			}
			void set(VkInstanceCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property ApplicationInfo^ ApplicationInfo
		{
			ApplicationInfo^ get()
			{
				return mApplicationInfo;
			}
			void set(ApplicationInfo^ value)
			{
				mApplicationInfo = value; 
			}
		}
		property UInt32 EnabledLayerCount
		{
			UInt32 get()
			{
				return mEnabledLayerCount;
			}
			void set(UInt32 value)
			{
				mEnabledLayerCount = value; 
			}
		}
		property array<String^>^ EnabledLayerNames
		{
			array<String^>^ get()
			{
				return mEnabledLayerNames;
			}
			void set(array<String^>^ value)
			{
				mEnabledLayerNames = value; 
			}
		}
		property UInt32 EnabledExtensionCount
		{
			UInt32 get()
			{
				return mEnabledExtensionCount;
			}
			void set(UInt32 value)
			{
				mEnabledExtensionCount = value; 
			}
		}
		property array<String^>^ EnabledExtensionNames
		{
			array<String^>^ get()
			{
				return mEnabledExtensionNames;
			}
			void set(array<String^>^ value)
			{
				mEnabledExtensionNames = value; 
			}
		}
	};

	public ref class QueueFamilyProperties
	{
	private:
		VkQueueFlags mQueueFlags;
		UInt32 mQueueCount = 0;
		UInt32 mTimestampValidBits = 0;
		Extent3D^ mMinImageTransferGranularity = nullptr;
	public:
		property VkQueueFlags QueueFlags
		{
			VkQueueFlags get()
			{
				return mQueueFlags;
			}
			void set(VkQueueFlags value)
			{
				mQueueFlags = value; 
			}
		}
		property UInt32 QueueCount
		{
			UInt32 get()
			{
				return mQueueCount;
			}
			void set(UInt32 value)
			{
				mQueueCount = value; 
			}
		}
		property UInt32 TimestampValidBits
		{
			UInt32 get()
			{
				return mTimestampValidBits;
			}
			void set(UInt32 value)
			{
				mTimestampValidBits = value; 
			}
		}
		property Extent3D^ MinImageTransferGranularity
		{
			Extent3D^ get()
			{
				return mMinImageTransferGranularity;
			}
			void set(Extent3D^ value)
			{
				mMinImageTransferGranularity = value; 
			}
		}
	};

	public ref class PhysicalDeviceMemoryProperties
	{
	private:
		UInt32 mMemoryTypeCount = 0;
		memoryTypes mVK_MAX_MEMORY_TYPES;
		UInt32 mMemoryHeapCount = 0;
		memoryHeaps mVK_MAX_MEMORY_HEAPS;
	public:
		property UInt32 MemoryTypeCount
		{
			UInt32 get()
			{
				return mMemoryTypeCount;
			}
			void set(UInt32 value)
			{
				mMemoryTypeCount = value; 
			}
		}
		property memoryTypes VK_MAX_MEMORY_TYPES
		{
			memoryTypes get()
			{
				return mVK_MAX_MEMORY_TYPES;
			}
			void set(memoryTypes value)
			{
				mVK_MAX_MEMORY_TYPES = value; 
			}
		}
		property UInt32 MemoryHeapCount
		{
			UInt32 get()
			{
				return mMemoryHeapCount;
			}
			void set(UInt32 value)
			{
				mMemoryHeapCount = value; 
			}
		}
		property memoryHeaps VK_MAX_MEMORY_HEAPS
		{
			memoryHeaps get()
			{
				return mVK_MAX_MEMORY_HEAPS;
			}
			void set(memoryHeaps value)
			{
				mVK_MAX_MEMORY_HEAPS = value; 
			}
		}
	};

	public ref class MemoryAllocateInfo
	{
	private:
		VkStructureType mSType;
		UInt64 mAllocationSize = 0;
		UInt32 mMemoryTypeIndex = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt64 AllocationSize
		{
			UInt64 get()
			{
				return mAllocationSize;
			}
			void set(UInt64 value)
			{
				mAllocationSize = value; 
			}
		}
		property UInt32 MemoryTypeIndex
		{
			UInt32 get()
			{
				return mMemoryTypeIndex;
			}
			void set(UInt32 value)
			{
				mMemoryTypeIndex = value; 
			}
		}
	};

	public ref class MemoryRequirements
	{
	private:
		UInt64 mSize = 0;
		UInt64 mAlignment = 0;
		UInt32 mMemoryTypeBits = 0;
	public:
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
		property UInt64 Alignment
		{
			UInt64 get()
			{
				return mAlignment;
			}
			void set(UInt64 value)
			{
				mAlignment = value; 
			}
		}
		property UInt32 MemoryTypeBits
		{
			UInt32 get()
			{
				return mMemoryTypeBits;
			}
			void set(UInt32 value)
			{
				mMemoryTypeBits = value; 
			}
		}
	};

	public ref class SparseImageFormatProperties
	{
	private:
		VkImageAspectFlags mAspectMask;
		Extent3D^ mImageGranularity = nullptr;
		VkSparseImageFormatFlags mFlags;
	public:
		property VkImageAspectFlags AspectMask
		{
			VkImageAspectFlags get()
			{
				return mAspectMask;
			}
			void set(VkImageAspectFlags value)
			{
				mAspectMask = value; 
			}
		}
		property Extent3D^ ImageGranularity
		{
			Extent3D^ get()
			{
				return mImageGranularity;
			}
			void set(Extent3D^ value)
			{
				mImageGranularity = value; 
			}
		}
		property VkSparseImageFormatFlags Flags
		{
			VkSparseImageFormatFlags get()
			{
				return mFlags;
			}
			void set(VkSparseImageFormatFlags value)
			{
				mFlags = value; 
			}
		}
	};

	public ref class SparseImageMemoryRequirements
	{
	private:
		SparseImageFormatProperties^ mFormatProperties = nullptr;
		UInt32 mImageMipTailFirstLod = 0;
		UInt64 mImageMipTailSize = 0;
		UInt64 mImageMipTailOffset = 0;
		UInt64 mImageMipTailStride = 0;
	public:
		property SparseImageFormatProperties^ FormatProperties
		{
			SparseImageFormatProperties^ get()
			{
				return mFormatProperties;
			}
			void set(SparseImageFormatProperties^ value)
			{
				mFormatProperties = value; 
			}
		}
		property UInt32 ImageMipTailFirstLod
		{
			UInt32 get()
			{
				return mImageMipTailFirstLod;
			}
			void set(UInt32 value)
			{
				mImageMipTailFirstLod = value; 
			}
		}
		property UInt64 ImageMipTailSize
		{
			UInt64 get()
			{
				return mImageMipTailSize;
			}
			void set(UInt64 value)
			{
				mImageMipTailSize = value; 
			}
		}
		property UInt64 ImageMipTailOffset
		{
			UInt64 get()
			{
				return mImageMipTailOffset;
			}
			void set(UInt64 value)
			{
				mImageMipTailOffset = value; 
			}
		}
		property UInt64 ImageMipTailStride
		{
			UInt64 get()
			{
				return mImageMipTailStride;
			}
			void set(UInt64 value)
			{
				mImageMipTailStride = value; 
			}
		}
	};

	public ref class MemoryType
	{
	private:
		VkMemoryPropertyFlags mPropertyFlags;
		UInt32 mHeapIndex = 0;
	public:
		property VkMemoryPropertyFlags PropertyFlags
		{
			VkMemoryPropertyFlags get()
			{
				return mPropertyFlags;
			}
			void set(VkMemoryPropertyFlags value)
			{
				mPropertyFlags = value; 
			}
		}
		property UInt32 HeapIndex
		{
			UInt32 get()
			{
				return mHeapIndex;
			}
			void set(UInt32 value)
			{
				mHeapIndex = value; 
			}
		}
	};

	public ref class MemoryHeap
	{
	private:
		UInt64 mSize = 0;
		VkMemoryHeapFlags mFlags;
	public:
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
		property VkMemoryHeapFlags Flags
		{
			VkMemoryHeapFlags get()
			{
				return mFlags;
			}
			void set(VkMemoryHeapFlags value)
			{
				mFlags = value; 
			}
		}
	};

	public ref class MappedMemoryRange
	{
	private:
		VkStructureType mSType;
		DeviceMemory^ mMemory = nullptr;
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property DeviceMemory^ Memory
		{
			DeviceMemory^ get()
			{
				return mMemory;
			}
			void set(DeviceMemory^ value)
			{
				mMemory = value; 
			}
		}
		property UInt64 Offset
		{
			UInt64 get()
			{
				return mOffset;
			}
			void set(UInt64 value)
			{
				mOffset = value; 
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
	};

	public ref class FormatProperties
	{
	private:
		VkFormatFeatureFlags mLinearTilingFeatures;
		VkFormatFeatureFlags mOptimalTilingFeatures;
		VkFormatFeatureFlags mBufferFeatures;
	public:
		property VkFormatFeatureFlags LinearTilingFeatures
		{
			VkFormatFeatureFlags get()
			{
				return mLinearTilingFeatures;
			}
			void set(VkFormatFeatureFlags value)
			{
				mLinearTilingFeatures = value; 
			}
		}
		property VkFormatFeatureFlags OptimalTilingFeatures
		{
			VkFormatFeatureFlags get()
			{
				return mOptimalTilingFeatures;
			}
			void set(VkFormatFeatureFlags value)
			{
				mOptimalTilingFeatures = value; 
			}
		}
		property VkFormatFeatureFlags BufferFeatures
		{
			VkFormatFeatureFlags get()
			{
				return mBufferFeatures;
			}
			void set(VkFormatFeatureFlags value)
			{
				mBufferFeatures = value; 
			}
		}
	};

	public ref class ImageFormatProperties
	{
	private:
		Extent3D^ mMaxExtent = nullptr;
		UInt32 mMaxMipLevels = 0;
		UInt32 mMaxArrayLayers = 0;
		VkSampleCountFlags mSampleCounts;
		UInt64 mMaxResourceSize = 0;
	public:
		property Extent3D^ MaxExtent
		{
			Extent3D^ get()
			{
				return mMaxExtent;
			}
			void set(Extent3D^ value)
			{
				mMaxExtent = value; 
			}
		}
		property UInt32 MaxMipLevels
		{
			UInt32 get()
			{
				return mMaxMipLevels;
			}
			void set(UInt32 value)
			{
				mMaxMipLevels = value; 
			}
		}
		property UInt32 MaxArrayLayers
		{
			UInt32 get()
			{
				return mMaxArrayLayers;
			}
			void set(UInt32 value)
			{
				mMaxArrayLayers = value; 
			}
		}
		property VkSampleCountFlags SampleCounts
		{
			VkSampleCountFlags get()
			{
				return mSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mSampleCounts = value; 
			}
		}
		property UInt64 MaxResourceSize
		{
			UInt64 get()
			{
				return mMaxResourceSize;
			}
			void set(UInt64 value)
			{
				mMaxResourceSize = value; 
			}
		}
	};

	public ref class DescriptorBufferInfo
	{
	private:
		Buffer^ mBuffer = nullptr;
		UInt64 mOffset = 0;
		UInt64 mRange = 0;
	public:
		property Buffer^ Buffer
		{
			Buffer^ get()
			{
				return mBuffer;
			}
			void set(Buffer^ value)
			{
				mBuffer = value; 
			}
		}
		property UInt64 Offset
		{
			UInt64 get()
			{
				return mOffset;
			}
			void set(UInt64 value)
			{
				mOffset = value; 
			}
		}
		property UInt64 Range
		{
			UInt64 get()
			{
				return mRange;
			}
			void set(UInt64 value)
			{
				mRange = value; 
			}
		}
	};

	public ref class DescriptorImageInfo
	{
	private:
		Sampler^ mSampler = nullptr;
		ImageView^ mImageView = nullptr;
		VkImageLayout mImageLayout;
	public:
		property Sampler^ Sampler
		{
			Sampler^ get()
			{
				return mSampler;
			}
			void set(Sampler^ value)
			{
				mSampler = value; 
			}
		}
		property ImageView^ ImageView
		{
			ImageView^ get()
			{
				return mImageView;
			}
			void set(ImageView^ value)
			{
				mImageView = value; 
			}
		}
		property VkImageLayout ImageLayout
		{
			VkImageLayout get()
			{
				return mImageLayout;
			}
			void set(VkImageLayout value)
			{
				mImageLayout = value; 
			}
		}
	};

	public ref class WriteDescriptorSet
	{
	private:
		VkStructureType mSType;
		DescriptorSet^ mDstSet = nullptr;
		UInt32 mDstBinding = 0;
		UInt32 mDstArrayElement = 0;
		UInt32 mDescriptorCount = 0;
		VkDescriptorType mDescriptorType;
		DescriptorImageInfo^ mImageInfo = nullptr;
		DescriptorBufferInfo^ mBufferInfo = nullptr;
		BufferView^ mTexelBufferView = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property DescriptorSet^ DstSet
		{
			DescriptorSet^ get()
			{
				return mDstSet;
			}
			void set(DescriptorSet^ value)
			{
				mDstSet = value; 
			}
		}
		property UInt32 DstBinding
		{
			UInt32 get()
			{
				return mDstBinding;
			}
			void set(UInt32 value)
			{
				mDstBinding = value; 
			}
		}
		property UInt32 DstArrayElement
		{
			UInt32 get()
			{
				return mDstArrayElement;
			}
			void set(UInt32 value)
			{
				mDstArrayElement = value; 
			}
		}
		property UInt32 DescriptorCount
		{
			UInt32 get()
			{
				return mDescriptorCount;
			}
			void set(UInt32 value)
			{
				mDescriptorCount = value; 
			}
		}
		property VkDescriptorType DescriptorType
		{
			VkDescriptorType get()
			{
				return mDescriptorType;
			}
			void set(VkDescriptorType value)
			{
				mDescriptorType = value; 
			}
		}
		property DescriptorImageInfo^ ImageInfo
		{
			DescriptorImageInfo^ get()
			{
				return mImageInfo;
			}
			void set(DescriptorImageInfo^ value)
			{
				mImageInfo = value; 
			}
		}
		property DescriptorBufferInfo^ BufferInfo
		{
			DescriptorBufferInfo^ get()
			{
				return mBufferInfo;
			}
			void set(DescriptorBufferInfo^ value)
			{
				mBufferInfo = value; 
			}
		}
		property BufferView^ TexelBufferView
		{
			BufferView^ get()
			{
				return mTexelBufferView;
			}
			void set(BufferView^ value)
			{
				mTexelBufferView = value; 
			}
		}
	};

	public ref class CopyDescriptorSet
	{
	private:
		VkStructureType mSType;
		DescriptorSet^ mSrcSet = nullptr;
		UInt32 mSrcBinding = 0;
		UInt32 mSrcArrayElement = 0;
		DescriptorSet^ mDstSet = nullptr;
		UInt32 mDstBinding = 0;
		UInt32 mDstArrayElement = 0;
		UInt32 mDescriptorCount = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property DescriptorSet^ SrcSet
		{
			DescriptorSet^ get()
			{
				return mSrcSet;
			}
			void set(DescriptorSet^ value)
			{
				mSrcSet = value; 
			}
		}
		property UInt32 SrcBinding
		{
			UInt32 get()
			{
				return mSrcBinding;
			}
			void set(UInt32 value)
			{
				mSrcBinding = value; 
			}
		}
		property UInt32 SrcArrayElement
		{
			UInt32 get()
			{
				return mSrcArrayElement;
			}
			void set(UInt32 value)
			{
				mSrcArrayElement = value; 
			}
		}
		property DescriptorSet^ DstSet
		{
			DescriptorSet^ get()
			{
				return mDstSet;
			}
			void set(DescriptorSet^ value)
			{
				mDstSet = value; 
			}
		}
		property UInt32 DstBinding
		{
			UInt32 get()
			{
				return mDstBinding;
			}
			void set(UInt32 value)
			{
				mDstBinding = value; 
			}
		}
		property UInt32 DstArrayElement
		{
			UInt32 get()
			{
				return mDstArrayElement;
			}
			void set(UInt32 value)
			{
				mDstArrayElement = value; 
			}
		}
		property UInt32 DescriptorCount
		{
			UInt32 get()
			{
				return mDescriptorCount;
			}
			void set(UInt32 value)
			{
				mDescriptorCount = value; 
			}
		}
	};

	public ref class BufferCreateInfo
	{
	private:
		VkStructureType mSType;
		VkBufferCreateFlags mFlags;
		UInt64 mSize = 0;
		VkBufferUsageFlags mUsage;
		VkSharingMode mSharingMode;
		UInt32 mQueueFamilyIndexCount = 0;
		UInt32 mQueueFamilyIndices = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkBufferCreateFlags Flags
		{
			VkBufferCreateFlags get()
			{
				return mFlags;
			}
			void set(VkBufferCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
		property VkBufferUsageFlags Usage
		{
			VkBufferUsageFlags get()
			{
				return mUsage;
			}
			void set(VkBufferUsageFlags value)
			{
				mUsage = value; 
			}
		}
		property VkSharingMode SharingMode
		{
			VkSharingMode get()
			{
				return mSharingMode;
			}
			void set(VkSharingMode value)
			{
				mSharingMode = value; 
			}
		}
		property UInt32 QueueFamilyIndexCount
		{
			UInt32 get()
			{
				return mQueueFamilyIndexCount;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndexCount = value; 
			}
		}
		property UInt32 QueueFamilyIndices
		{
			UInt32 get()
			{
				return mQueueFamilyIndices;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndices = value; 
			}
		}
	};

	public ref class BufferViewCreateInfo
	{
	private:
		VkStructureType mSType;
		<TYPE> m<NAME>;
		Buffer^ mBuffer = nullptr;
		VkFormat mFormat;
		UInt64 mOffset = 0;
		UInt64 mRange = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property <TYPE> <NAME>
		{
			<TYPE> get()
			{
				return m<NAME>;
			}
			void set(<TYPE> value)
			{
				m<NAME> = value; 
			}
		}
		property Buffer^ Buffer
		{
			Buffer^ get()
			{
				return mBuffer;
			}
			void set(Buffer^ value)
			{
				mBuffer = value; 
			}
		}
		property VkFormat Format
		{
			VkFormat get()
			{
				return mFormat;
			}
			void set(VkFormat value)
			{
				mFormat = value; 
			}
		}
		property UInt64 Offset
		{
			UInt64 get()
			{
				return mOffset;
			}
			void set(UInt64 value)
			{
				mOffset = value; 
			}
		}
		property UInt64 Range
		{
			UInt64 get()
			{
				return mRange;
			}
			void set(UInt64 value)
			{
				mRange = value; 
			}
		}
	};

	public ref class ImageSubresource
	{
	private:
		VkImageAspectFlags mAspectMask;
		UInt32 mMipLevel = 0;
		UInt32 mArrayLayer = 0;
	public:
		property VkImageAspectFlags AspectMask
		{
			VkImageAspectFlags get()
			{
				return mAspectMask;
			}
			void set(VkImageAspectFlags value)
			{
				mAspectMask = value; 
			}
		}
		property UInt32 MipLevel
		{
			UInt32 get()
			{
				return mMipLevel;
			}
			void set(UInt32 value)
			{
				mMipLevel = value; 
			}
		}
		property UInt32 ArrayLayer
		{
			UInt32 get()
			{
				return mArrayLayer;
			}
			void set(UInt32 value)
			{
				mArrayLayer = value; 
			}
		}
	};

	public ref class ImageSubresourceLayers
	{
	private:
		VkImageAspectFlags mAspectMask;
		UInt32 mMipLevel = 0;
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property VkImageAspectFlags AspectMask
		{
			VkImageAspectFlags get()
			{
				return mAspectMask;
			}
			void set(VkImageAspectFlags value)
			{
				mAspectMask = value; 
			}
		}
		property UInt32 MipLevel
		{
			UInt32 get()
			{
				return mMipLevel;
			}
			void set(UInt32 value)
			{
				mMipLevel = value; 
			}
		}
		property UInt32 BaseArrayLayer
		{
			UInt32 get()
			{
				return mBaseArrayLayer;
			}
			void set(UInt32 value)
			{
				mBaseArrayLayer = value; 
			}
		}
		property UInt32 LayerCount
		{
			UInt32 get()
			{
				return mLayerCount;
			}
			void set(UInt32 value)
			{
				mLayerCount = value; 
			}
		}
	};

	public ref class ImageSubresourceRange
	{
	private:
		VkImageAspectFlags mAspectMask;
		UInt32 mBaseMipLevel = 0;
		UInt32 mLevelCount = 0;
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property VkImageAspectFlags AspectMask
		{
			VkImageAspectFlags get()
			{
				return mAspectMask;
			}
			void set(VkImageAspectFlags value)
			{
				mAspectMask = value; 
			}
		}
		property UInt32 BaseMipLevel
		{
			UInt32 get()
			{
				return mBaseMipLevel;
			}
			void set(UInt32 value)
			{
				mBaseMipLevel = value; 
			}
		}
		property UInt32 LevelCount
		{
			UInt32 get()
			{
				return mLevelCount;
			}
			void set(UInt32 value)
			{
				mLevelCount = value; 
			}
		}
		property UInt32 BaseArrayLayer
		{
			UInt32 get()
			{
				return mBaseArrayLayer;
			}
			void set(UInt32 value)
			{
				mBaseArrayLayer = value; 
			}
		}
		property UInt32 LayerCount
		{
			UInt32 get()
			{
				return mLayerCount;
			}
			void set(UInt32 value)
			{
				mLayerCount = value; 
			}
		}
	};

	public ref class MemoryBarrier
	{
	private:
		VkStructureType mSType;
		VkAccessFlags mSrcAccessMask;
		VkAccessFlags mDstAccessMask;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkAccessFlags SrcAccessMask
		{
			VkAccessFlags get()
			{
				return mSrcAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mSrcAccessMask = value; 
			}
		}
		property VkAccessFlags DstAccessMask
		{
			VkAccessFlags get()
			{
				return mDstAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mDstAccessMask = value; 
			}
		}
	};

	public ref class BufferMemoryBarrier
	{
	private:
		VkStructureType mSType;
		VkAccessFlags mSrcAccessMask;
		VkAccessFlags mDstAccessMask;
		UInt32 mSrcQueueFamilyIndex = 0;
		UInt32 mDstQueueFamilyIndex = 0;
		Buffer^ mBuffer = nullptr;
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkAccessFlags SrcAccessMask
		{
			VkAccessFlags get()
			{
				return mSrcAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mSrcAccessMask = value; 
			}
		}
		property VkAccessFlags DstAccessMask
		{
			VkAccessFlags get()
			{
				return mDstAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mDstAccessMask = value; 
			}
		}
		property UInt32 SrcQueueFamilyIndex
		{
			UInt32 get()
			{
				return mSrcQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mSrcQueueFamilyIndex = value; 
			}
		}
		property UInt32 DstQueueFamilyIndex
		{
			UInt32 get()
			{
				return mDstQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mDstQueueFamilyIndex = value; 
			}
		}
		property Buffer^ Buffer
		{
			Buffer^ get()
			{
				return mBuffer;
			}
			void set(Buffer^ value)
			{
				mBuffer = value; 
			}
		}
		property UInt64 Offset
		{
			UInt64 get()
			{
				return mOffset;
			}
			void set(UInt64 value)
			{
				mOffset = value; 
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
	};

	public ref class ImageMemoryBarrier
	{
	private:
		VkStructureType mSType;
		VkAccessFlags mSrcAccessMask;
		VkAccessFlags mDstAccessMask;
		VkImageLayout mOldLayout;
		VkImageLayout mNewLayout;
		UInt32 mSrcQueueFamilyIndex = 0;
		UInt32 mDstQueueFamilyIndex = 0;
		Image^ mImage = nullptr;
		ImageSubresourceRange^ mSubresourceRange = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkAccessFlags SrcAccessMask
		{
			VkAccessFlags get()
			{
				return mSrcAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mSrcAccessMask = value; 
			}
		}
		property VkAccessFlags DstAccessMask
		{
			VkAccessFlags get()
			{
				return mDstAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mDstAccessMask = value; 
			}
		}
		property VkImageLayout OldLayout
		{
			VkImageLayout get()
			{
				return mOldLayout;
			}
			void set(VkImageLayout value)
			{
				mOldLayout = value; 
			}
		}
		property VkImageLayout NewLayout
		{
			VkImageLayout get()
			{
				return mNewLayout;
			}
			void set(VkImageLayout value)
			{
				mNewLayout = value; 
			}
		}
		property UInt32 SrcQueueFamilyIndex
		{
			UInt32 get()
			{
				return mSrcQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mSrcQueueFamilyIndex = value; 
			}
		}
		property UInt32 DstQueueFamilyIndex
		{
			UInt32 get()
			{
				return mDstQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mDstQueueFamilyIndex = value; 
			}
		}
		property Image^ Image
		{
			Image^ get()
			{
				return mImage;
			}
			void set(Image^ value)
			{
				mImage = value; 
			}
		}
		property ImageSubresourceRange^ SubresourceRange
		{
			ImageSubresourceRange^ get()
			{
				return mSubresourceRange;
			}
			void set(ImageSubresourceRange^ value)
			{
				mSubresourceRange = value; 
			}
		}
	};

	public ref class ImageCreateInfo
	{
	private:
		VkStructureType mSType;
		VkImageCreateFlags mFlags;
		VkImageType mImageType;
		VkFormat mFormat;
		Extent3D^ mExtent = nullptr;
		UInt32 mMipLevels = 0;
		UInt32 mArrayLayers = 0;
		VkSampleCountFlagBits mSamples;
		VkImageTiling mTiling;
		VkImageUsageFlags mUsage;
		VkSharingMode mSharingMode;
		UInt32 mQueueFamilyIndexCount = 0;
		UInt32 mQueueFamilyIndices = 0;
		VkImageLayout mInitialLayout;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkImageCreateFlags Flags
		{
			VkImageCreateFlags get()
			{
				return mFlags;
			}
			void set(VkImageCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property VkImageType ImageType
		{
			VkImageType get()
			{
				return mImageType;
			}
			void set(VkImageType value)
			{
				mImageType = value; 
			}
		}
		property VkFormat Format
		{
			VkFormat get()
			{
				return mFormat;
			}
			void set(VkFormat value)
			{
				mFormat = value; 
			}
		}
		property Extent3D^ Extent
		{
			Extent3D^ get()
			{
				return mExtent;
			}
			void set(Extent3D^ value)
			{
				mExtent = value; 
			}
		}
		property UInt32 MipLevels
		{
			UInt32 get()
			{
				return mMipLevels;
			}
			void set(UInt32 value)
			{
				mMipLevels = value; 
			}
		}
		property UInt32 ArrayLayers
		{
			UInt32 get()
			{
				return mArrayLayers;
			}
			void set(UInt32 value)
			{
				mArrayLayers = value; 
			}
		}
		property VkSampleCountFlagBits Samples
		{
			VkSampleCountFlagBits get()
			{
				return mSamples;
			}
			void set(VkSampleCountFlagBits value)
			{
				mSamples = value; 
			}
		}
		property VkImageTiling Tiling
		{
			VkImageTiling get()
			{
				return mTiling;
			}
			void set(VkImageTiling value)
			{
				mTiling = value; 
			}
		}
		property VkImageUsageFlags Usage
		{
			VkImageUsageFlags get()
			{
				return mUsage;
			}
			void set(VkImageUsageFlags value)
			{
				mUsage = value; 
			}
		}
		property VkSharingMode SharingMode
		{
			VkSharingMode get()
			{
				return mSharingMode;
			}
			void set(VkSharingMode value)
			{
				mSharingMode = value; 
			}
		}
		property UInt32 QueueFamilyIndexCount
		{
			UInt32 get()
			{
				return mQueueFamilyIndexCount;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndexCount = value; 
			}
		}
		property UInt32 QueueFamilyIndices
		{
			UInt32 get()
			{
				return mQueueFamilyIndices;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndices = value; 
			}
		}
		property VkImageLayout InitialLayout
		{
			VkImageLayout get()
			{
				return mInitialLayout;
			}
			void set(VkImageLayout value)
			{
				mInitialLayout = value; 
			}
		}
	};

	public ref class SubresourceLayout
	{
	private:
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
		UInt64 mRowPitch = 0;
		UInt64 mArrayPitch = 0;
		UInt64 mDepthPitch = 0;
	public:
		property UInt64 Offset
		{
			UInt64 get()
			{
				return mOffset;
			}
			void set(UInt64 value)
			{
				mOffset = value; 
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
		property UInt64 RowPitch
		{
			UInt64 get()
			{
				return mRowPitch;
			}
			void set(UInt64 value)
			{
				mRowPitch = value; 
			}
		}
		property UInt64 ArrayPitch
		{
			UInt64 get()
			{
				return mArrayPitch;
			}
			void set(UInt64 value)
			{
				mArrayPitch = value; 
			}
		}
		property UInt64 DepthPitch
		{
			UInt64 get()
			{
				return mDepthPitch;
			}
			void set(UInt64 value)
			{
				mDepthPitch = value; 
			}
		}
	};

	public ref class ImageViewCreateInfo
	{
	private:
		VkStructureType mSType;
		VkImageViewCreateFlags mFlags;
		Image^ mImage = nullptr;
		VkImageViewType mViewType;
		VkFormat mFormat;
		ComponentMapping^ mComponents = nullptr;
		ImageSubresourceRange^ mSubresourceRange = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkImageViewCreateFlags Flags
		{
			VkImageViewCreateFlags get()
			{
				return mFlags;
			}
			void set(VkImageViewCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property Image^ Image
		{
			Image^ get()
			{
				return mImage;
			}
			void set(Image^ value)
			{
				mImage = value; 
			}
		}
		property VkImageViewType ViewType
		{
			VkImageViewType get()
			{
				return mViewType;
			}
			void set(VkImageViewType value)
			{
				mViewType = value; 
			}
		}
		property VkFormat Format
		{
			VkFormat get()
			{
				return mFormat;
			}
			void set(VkFormat value)
			{
				mFormat = value; 
			}
		}
		property ComponentMapping^ Components
		{
			ComponentMapping^ get()
			{
				return mComponents;
			}
			void set(ComponentMapping^ value)
			{
				mComponents = value; 
			}
		}
		property ImageSubresourceRange^ SubresourceRange
		{
			ImageSubresourceRange^ get()
			{
				return mSubresourceRange;
			}
			void set(ImageSubresourceRange^ value)
			{
				mSubresourceRange = value; 
			}
		}
	};

	public ref class BufferCopy
	{
	private:
		UInt64 mSrcOffset = 0;
		UInt64 mDstOffset = 0;
		UInt64 mSize = 0;
	public:
		property UInt64 SrcOffset
		{
			UInt64 get()
			{
				return mSrcOffset;
			}
			void set(UInt64 value)
			{
				mSrcOffset = value; 
			}
		}
		property UInt64 DstOffset
		{
			UInt64 get()
			{
				return mDstOffset;
			}
			void set(UInt64 value)
			{
				mDstOffset = value; 
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
	};

	public ref class SparseMemoryBind
	{
	private:
		UInt64 mResourceOffset = 0;
		UInt64 mSize = 0;
		DeviceMemory^ mMemory = nullptr;
		UInt64 mMemoryOffset = 0;
		<TYPE> m<NAME>;
	public:
		property UInt64 ResourceOffset
		{
			UInt64 get()
			{
				return mResourceOffset;
			}
			void set(UInt64 value)
			{
				mResourceOffset = value; 
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value; 
			}
		}
		property DeviceMemory^ Memory
		{
			DeviceMemory^ get()
			{
				return mMemory;
			}
			void set(DeviceMemory^ value)
			{
				mMemory = value; 
			}
		}
		property UInt64 MemoryOffset
		{
			UInt64 get()
			{
				return mMemoryOffset;
			}
			void set(UInt64 value)
			{
				mMemoryOffset = value; 
			}
		}
		property <TYPE> <NAME>
		{
			<TYPE> get()
			{
				return m<NAME>;
			}
			void set(<TYPE> value)
			{
				m<NAME> = value; 
			}
		}
	};

	public ref class SparseImageMemoryBind
	{
	private:
		ImageSubresource^ mSubresource = nullptr;
		Offset3D^ mOffset = nullptr;
		Extent3D^ mExtent = nullptr;
		DeviceMemory^ mMemory = nullptr;
		UInt64 mMemoryOffset = 0;
		<TYPE> m<NAME>;
	public:
		property ImageSubresource^ Subresource
		{
			ImageSubresource^ get()
			{
				return mSubresource;
			}
			void set(ImageSubresource^ value)
			{
				mSubresource = value; 
			}
		}
		property Offset3D^ Offset
		{
			Offset3D^ get()
			{
				return mOffset;
			}
			void set(Offset3D^ value)
			{
				mOffset = value; 
			}
		}
		property Extent3D^ Extent
		{
			Extent3D^ get()
			{
				return mExtent;
			}
			void set(Extent3D^ value)
			{
				mExtent = value; 
			}
		}
		property DeviceMemory^ Memory
		{
			DeviceMemory^ get()
			{
				return mMemory;
			}
			void set(DeviceMemory^ value)
			{
				mMemory = value; 
			}
		}
		property UInt64 MemoryOffset
		{
			UInt64 get()
			{
				return mMemoryOffset;
			}
			void set(UInt64 value)
			{
				mMemoryOffset = value; 
			}
		}
		property <TYPE> <NAME>
		{
			<TYPE> get()
			{
				return m<NAME>;
			}
			void set(<TYPE> value)
			{
				m<NAME> = value; 
			}
		}
	};

	public ref class SparseBufferMemoryBindInfo
	{
	private:
		Buffer^ mBuffer = nullptr;
		UInt32 mBindCount = 0;
		SparseMemoryBind^ mBinds = nullptr;
	public:
		property Buffer^ Buffer
		{
			Buffer^ get()
			{
				return mBuffer;
			}
			void set(Buffer^ value)
			{
				mBuffer = value; 
			}
		}
		property UInt32 BindCount
		{
			UInt32 get()
			{
				return mBindCount;
			}
			void set(UInt32 value)
			{
				mBindCount = value; 
			}
		}
		property SparseMemoryBind^ Binds
		{
			SparseMemoryBind^ get()
			{
				return mBinds;
			}
			void set(SparseMemoryBind^ value)
			{
				mBinds = value; 
			}
		}
	};

	public ref class SparseImageOpaqueMemoryBindInfo
	{
	private:
		Image^ mImage = nullptr;
		UInt32 mBindCount = 0;
		SparseMemoryBind^ mBinds = nullptr;
	public:
		property Image^ Image
		{
			Image^ get()
			{
				return mImage;
			}
			void set(Image^ value)
			{
				mImage = value; 
			}
		}
		property UInt32 BindCount
		{
			UInt32 get()
			{
				return mBindCount;
			}
			void set(UInt32 value)
			{
				mBindCount = value; 
			}
		}
		property SparseMemoryBind^ Binds
		{
			SparseMemoryBind^ get()
			{
				return mBinds;
			}
			void set(SparseMemoryBind^ value)
			{
				mBinds = value; 
			}
		}
	};

	public ref class SparseImageMemoryBindInfo
	{
	private:
		Image^ mImage = nullptr;
		UInt32 mBindCount = 0;
		SparseImageMemoryBind^ mBinds = nullptr;
	public:
		property Image^ Image
		{
			Image^ get()
			{
				return mImage;
			}
			void set(Image^ value)
			{
				mImage = value; 
			}
		}
		property UInt32 BindCount
		{
			UInt32 get()
			{
				return mBindCount;
			}
			void set(UInt32 value)
			{
				mBindCount = value; 
			}
		}
		property SparseImageMemoryBind^ Binds
		{
			SparseImageMemoryBind^ get()
			{
				return mBinds;
			}
			void set(SparseImageMemoryBind^ value)
			{
				mBinds = value; 
			}
		}
	};

	public ref class BindSparseInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		Semaphore^ mWaitSemaphores = nullptr;
		UInt32 mBufferBindCount = 0;
		SparseBufferMemoryBindInfo^ mBufferBinds = nullptr;
		UInt32 mImageOpaqueBindCount = 0;
		SparseImageOpaqueMemoryBindInfo^ mImageOpaqueBinds = nullptr;
		UInt32 mImageBindCount = 0;
		SparseImageMemoryBindInfo^ mImageBinds = nullptr;
		UInt32 mSignalSemaphoreCount = 0;
		Semaphore^ mSignalSemaphores = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt32 WaitSemaphoreCount
		{
			UInt32 get()
			{
				return mWaitSemaphoreCount;
			}
			void set(UInt32 value)
			{
				mWaitSemaphoreCount = value; 
			}
		}
		property Semaphore^ WaitSemaphores
		{
			Semaphore^ get()
			{
				return mWaitSemaphores;
			}
			void set(Semaphore^ value)
			{
				mWaitSemaphores = value; 
			}
		}
		property UInt32 BufferBindCount
		{
			UInt32 get()
			{
				return mBufferBindCount;
			}
			void set(UInt32 value)
			{
				mBufferBindCount = value; 
			}
		}
		property SparseBufferMemoryBindInfo^ BufferBinds
		{
			SparseBufferMemoryBindInfo^ get()
			{
				return mBufferBinds;
			}
			void set(SparseBufferMemoryBindInfo^ value)
			{
				mBufferBinds = value; 
			}
		}
		property UInt32 ImageOpaqueBindCount
		{
			UInt32 get()
			{
				return mImageOpaqueBindCount;
			}
			void set(UInt32 value)
			{
				mImageOpaqueBindCount = value; 
			}
		}
		property SparseImageOpaqueMemoryBindInfo^ ImageOpaqueBinds
		{
			SparseImageOpaqueMemoryBindInfo^ get()
			{
				return mImageOpaqueBinds;
			}
			void set(SparseImageOpaqueMemoryBindInfo^ value)
			{
				mImageOpaqueBinds = value; 
			}
		}
		property UInt32 ImageBindCount
		{
			UInt32 get()
			{
				return mImageBindCount;
			}
			void set(UInt32 value)
			{
				mImageBindCount = value; 
			}
		}
		property SparseImageMemoryBindInfo^ ImageBinds
		{
			SparseImageMemoryBindInfo^ get()
			{
				return mImageBinds;
			}
			void set(SparseImageMemoryBindInfo^ value)
			{
				mImageBinds = value; 
			}
		}
		property UInt32 SignalSemaphoreCount
		{
			UInt32 get()
			{
				return mSignalSemaphoreCount;
			}
			void set(UInt32 value)
			{
				mSignalSemaphoreCount = value; 
			}
		}
		property Semaphore^ SignalSemaphores
		{
			Semaphore^ get()
			{
				return mSignalSemaphores;
			}
			void set(Semaphore^ value)
			{
				mSignalSemaphores = value; 
			}
		}
	};

	public ref class ImageCopy
	{
	private:
		ImageSubresourceLayers^ mSrcSubresource = nullptr;
		Offset3D^ mSrcOffset = nullptr;
		ImageSubresourceLayers^ mDstSubresource = nullptr;
		Offset3D^ mDstOffset = nullptr;
		Extent3D^ mExtent = nullptr;
	public:
		property ImageSubresourceLayers^ SrcSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mSrcSubresource = value; 
			}
		}
		property Offset3D^ SrcOffset
		{
			Offset3D^ get()
			{
				return mSrcOffset;
			}
			void set(Offset3D^ value)
			{
				mSrcOffset = value; 
			}
		}
		property ImageSubresourceLayers^ DstSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mDstSubresource = value; 
			}
		}
		property Offset3D^ DstOffset
		{
			Offset3D^ get()
			{
				return mDstOffset;
			}
			void set(Offset3D^ value)
			{
				mDstOffset = value; 
			}
		}
		property Extent3D^ Extent
		{
			Extent3D^ get()
			{
				return mExtent;
			}
			void set(Extent3D^ value)
			{
				mExtent = value; 
			}
		}
	};

	public ref class ImageBlit
	{
	private:
		ImageSubresourceLayers^ mSrcSubresource = nullptr;
		srcOffsets m2;
		ImageSubresourceLayers^ mDstSubresource = nullptr;
		dstOffsets m2;
	public:
		property ImageSubresourceLayers^ SrcSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mSrcSubresource = value; 
			}
		}
		property srcOffsets 2
		{
			srcOffsets get()
			{
				return m2;
			}
			void set(srcOffsets value)
			{
				m2 = value; 
			}
		}
		property ImageSubresourceLayers^ DstSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mDstSubresource = value; 
			}
		}
		property dstOffsets 2
		{
			dstOffsets get()
			{
				return m2;
			}
			void set(dstOffsets value)
			{
				m2 = value; 
			}
		}
	};

	public ref class BufferImageCopy
	{
	private:
		UInt64 mBufferOffset = 0;
		UInt32 mBufferRowLength = 0;
		UInt32 mBufferImageHeight = 0;
		ImageSubresourceLayers^ mImageSubresource = nullptr;
		Offset3D^ mImageOffset = nullptr;
		Extent3D^ mImageExtent = nullptr;
	public:
		property UInt64 BufferOffset
		{
			UInt64 get()
			{
				return mBufferOffset;
			}
			void set(UInt64 value)
			{
				mBufferOffset = value; 
			}
		}
		property UInt32 BufferRowLength
		{
			UInt32 get()
			{
				return mBufferRowLength;
			}
			void set(UInt32 value)
			{
				mBufferRowLength = value; 
			}
		}
		property UInt32 BufferImageHeight
		{
			UInt32 get()
			{
				return mBufferImageHeight;
			}
			void set(UInt32 value)
			{
				mBufferImageHeight = value; 
			}
		}
		property ImageSubresourceLayers^ ImageSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mImageSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mImageSubresource = value; 
			}
		}
		property Offset3D^ ImageOffset
		{
			Offset3D^ get()
			{
				return mImageOffset;
			}
			void set(Offset3D^ value)
			{
				mImageOffset = value; 
			}
		}
		property Extent3D^ ImageExtent
		{
			Extent3D^ get()
			{
				return mImageExtent;
			}
			void set(Extent3D^ value)
			{
				mImageExtent = value; 
			}
		}
	};

	public ref class ImageResolve
	{
	private:
		ImageSubresourceLayers^ mSrcSubresource = nullptr;
		Offset3D^ mSrcOffset = nullptr;
		ImageSubresourceLayers^ mDstSubresource = nullptr;
		Offset3D^ mDstOffset = nullptr;
		Extent3D^ mExtent = nullptr;
	public:
		property ImageSubresourceLayers^ SrcSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mSrcSubresource = value; 
			}
		}
		property Offset3D^ SrcOffset
		{
			Offset3D^ get()
			{
				return mSrcOffset;
			}
			void set(Offset3D^ value)
			{
				mSrcOffset = value; 
			}
		}
		property ImageSubresourceLayers^ DstSubresource
		{
			ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ImageSubresourceLayers^ value)
			{
				mDstSubresource = value; 
			}
		}
		property Offset3D^ DstOffset
		{
			Offset3D^ get()
			{
				return mDstOffset;
			}
			void set(Offset3D^ value)
			{
				mDstOffset = value; 
			}
		}
		property Extent3D^ Extent
		{
			Extent3D^ get()
			{
				return mExtent;
			}
			void set(Extent3D^ value)
			{
				mExtent = value; 
			}
		}
	};

	public ref class ShaderModuleCreateInfo
	{
	private:
		VkStructureType mSType;
		VkShaderModuleCreateFlags mFlags;
		IntPtr mCodeSize = 0;
		UInt32 mCode = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkShaderModuleCreateFlags Flags
		{
			VkShaderModuleCreateFlags get()
			{
				return mFlags;
			}
			void set(VkShaderModuleCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property IntPtr CodeSize
		{
			IntPtr get()
			{
				return mCodeSize;
			}
			void set(IntPtr value)
			{
				mCodeSize = value; 
			}
		}
		property UInt32 Code
		{
			UInt32 get()
			{
				return mCode;
			}
			void set(UInt32 value)
			{
				mCode = value; 
			}
		}
	};

	public ref class DescriptorSetLayoutBinding
	{
	private:
		UInt32 mBinding = 0;
		VkDescriptorType mDescriptorType;
		UInt32 mDescriptorCount = 0;
		VkShaderStageFlags mStageFlags;
		Sampler^ mImmutableSamplers = nullptr;
	public:
		property UInt32 Binding
		{
			UInt32 get()
			{
				return mBinding;
			}
			void set(UInt32 value)
			{
				mBinding = value; 
			}
		}
		property VkDescriptorType DescriptorType
		{
			VkDescriptorType get()
			{
				return mDescriptorType;
			}
			void set(VkDescriptorType value)
			{
				mDescriptorType = value; 
			}
		}
		property UInt32 DescriptorCount
		{
			UInt32 get()
			{
				return mDescriptorCount;
			}
			void set(UInt32 value)
			{
				mDescriptorCount = value; 
			}
		}
		property VkShaderStageFlags StageFlags
		{
			VkShaderStageFlags get()
			{
				return mStageFlags;
			}
			void set(VkShaderStageFlags value)
			{
				mStageFlags = value; 
			}
		}
		property Sampler^ ImmutableSamplers
		{
			Sampler^ get()
			{
				return mImmutableSamplers;
			}
			void set(Sampler^ value)
			{
				mImmutableSamplers = value; 
			}
		}
	};

	public ref class DescriptorSetLayoutCreateInfo
	{
	private:
		VkStructureType mSType;
		VkDescriptorSetLayoutCreateFlags mFlags;
		UInt32 mBindingCount = 0;
		DescriptorSetLayoutBinding^ mBindings = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDescriptorSetLayoutCreateFlags Flags
		{
			VkDescriptorSetLayoutCreateFlags get()
			{
				return mFlags;
			}
			void set(VkDescriptorSetLayoutCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 BindingCount
		{
			UInt32 get()
			{
				return mBindingCount;
			}
			void set(UInt32 value)
			{
				mBindingCount = value; 
			}
		}
		property DescriptorSetLayoutBinding^ Bindings
		{
			DescriptorSetLayoutBinding^ get()
			{
				return mBindings;
			}
			void set(DescriptorSetLayoutBinding^ value)
			{
				mBindings = value; 
			}
		}
	};

	public ref class DescriptorPoolSize
	{
	private:
		VkDescriptorType mType;
		UInt32 mDescriptorCount = 0;
	public:
		property VkDescriptorType Type
		{
			VkDescriptorType get()
			{
				return mType;
			}
			void set(VkDescriptorType value)
			{
				mType = value; 
			}
		}
		property UInt32 DescriptorCount
		{
			UInt32 get()
			{
				return mDescriptorCount;
			}
			void set(UInt32 value)
			{
				mDescriptorCount = value; 
			}
		}
	};

	public ref class DescriptorPoolCreateInfo
	{
	private:
		VkStructureType mSType;
		VkDescriptorPoolCreateFlags mFlags;
		UInt32 mMaxSets = 0;
		UInt32 mPoolSizeCount = 0;
		DescriptorPoolSize^ mPoolSizes = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDescriptorPoolCreateFlags Flags
		{
			VkDescriptorPoolCreateFlags get()
			{
				return mFlags;
			}
			void set(VkDescriptorPoolCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 MaxSets
		{
			UInt32 get()
			{
				return mMaxSets;
			}
			void set(UInt32 value)
			{
				mMaxSets = value; 
			}
		}
		property UInt32 PoolSizeCount
		{
			UInt32 get()
			{
				return mPoolSizeCount;
			}
			void set(UInt32 value)
			{
				mPoolSizeCount = value; 
			}
		}
		property DescriptorPoolSize^ PoolSizes
		{
			DescriptorPoolSize^ get()
			{
				return mPoolSizes;
			}
			void set(DescriptorPoolSize^ value)
			{
				mPoolSizes = value; 
			}
		}
	};

	public ref class DescriptorSetAllocateInfo
	{
	private:
		VkStructureType mSType;
		DescriptorPool^ mDescriptorPool = nullptr;
		UInt32 mDescriptorSetCount = 0;
		DescriptorSetLayout^ mSetLayouts = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property DescriptorPool^ DescriptorPool
		{
			DescriptorPool^ get()
			{
				return mDescriptorPool;
			}
			void set(DescriptorPool^ value)
			{
				mDescriptorPool = value; 
			}
		}
		property UInt32 DescriptorSetCount
		{
			UInt32 get()
			{
				return mDescriptorSetCount;
			}
			void set(UInt32 value)
			{
				mDescriptorSetCount = value; 
			}
		}
		property DescriptorSetLayout^ SetLayouts
		{
			DescriptorSetLayout^ get()
			{
				return mSetLayouts;
			}
			void set(DescriptorSetLayout^ value)
			{
				mSetLayouts = value; 
			}
		}
	};

	public ref class SpecializationMapEntry
	{
	private:
		UInt32 mConstantID = 0;
		UInt32 mOffset = 0;
		IntPtr mSize = 0;
	public:
		property UInt32 ConstantID
		{
			UInt32 get()
			{
				return mConstantID;
			}
			void set(UInt32 value)
			{
				mConstantID = value; 
			}
		}
		property UInt32 Offset
		{
			UInt32 get()
			{
				return mOffset;
			}
			void set(UInt32 value)
			{
				mOffset = value; 
			}
		}
		property IntPtr Size
		{
			IntPtr get()
			{
				return mSize;
			}
			void set(IntPtr value)
			{
				mSize = value; 
			}
		}
	};

	public ref class SpecializationInfo
	{
	private:
		UInt32 mMapEntryCount = 0;
		SpecializationMapEntry^ mMapEntries = nullptr;
		IntPtr mDataSize = 0;
		IntPtr mData = IntPtr.Zero;
	public:
		property UInt32 MapEntryCount
		{
			UInt32 get()
			{
				return mMapEntryCount;
			}
			void set(UInt32 value)
			{
				mMapEntryCount = value; 
			}
		}
		property SpecializationMapEntry^ MapEntries
		{
			SpecializationMapEntry^ get()
			{
				return mMapEntries;
			}
			void set(SpecializationMapEntry^ value)
			{
				mMapEntries = value; 
			}
		}
		property IntPtr DataSize
		{
			IntPtr get()
			{
				return mDataSize;
			}
			void set(IntPtr value)
			{
				mDataSize = value; 
			}
		}
		property IntPtr Data
		{
			IntPtr get()
			{
				return mData;
			}
			void set(IntPtr value)
			{
				mData = value; 
			}
		}
	};

	public ref class PipelineShaderStageCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineShaderStageCreateFlags mFlags;
		VkShaderStageFlagBits mStage;
		ShaderModule^ mModule = nullptr;
		String^ mName = nullptr;
		SpecializationInfo^ mSpecializationInfo = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineShaderStageCreateFlags Flags
		{
			VkPipelineShaderStageCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineShaderStageCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property VkShaderStageFlagBits Stage
		{
			VkShaderStageFlagBits get()
			{
				return mStage;
			}
			void set(VkShaderStageFlagBits value)
			{
				mStage = value; 
			}
		}
		property ShaderModule^ Module
		{
			ShaderModule^ get()
			{
				return mModule;
			}
			void set(ShaderModule^ value)
			{
				mModule = value; 
			}
		}
		property String^ Name
		{
			String^ get()
			{
				return mName;
			}
			void set(String^ value)
			{
				mName = value; 
			}
		}
		property SpecializationInfo^ SpecializationInfo
		{
			SpecializationInfo^ get()
			{
				return mSpecializationInfo;
			}
			void set(SpecializationInfo^ value)
			{
				mSpecializationInfo = value; 
			}
		}
	};

	public ref class ComputePipelineCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineCreateFlags mFlags;
		PipelineShaderStageCreateInfo^ mStage = nullptr;
		PipelineLayout^ mLayout = nullptr;
		Pipeline^ mBasePipelineHandle = nullptr;
		Int32 mBasePipelineIndex = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineCreateFlags Flags
		{
			VkPipelineCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property PipelineShaderStageCreateInfo^ Stage
		{
			PipelineShaderStageCreateInfo^ get()
			{
				return mStage;
			}
			void set(PipelineShaderStageCreateInfo^ value)
			{
				mStage = value; 
			}
		}
		property PipelineLayout^ Layout
		{
			PipelineLayout^ get()
			{
				return mLayout;
			}
			void set(PipelineLayout^ value)
			{
				mLayout = value; 
			}
		}
		property Pipeline^ BasePipelineHandle
		{
			Pipeline^ get()
			{
				return mBasePipelineHandle;
			}
			void set(Pipeline^ value)
			{
				mBasePipelineHandle = value; 
			}
		}
		property Int32 BasePipelineIndex
		{
			Int32 get()
			{
				return mBasePipelineIndex;
			}
			void set(Int32 value)
			{
				mBasePipelineIndex = value; 
			}
		}
	};

	public ref class VertexInputBindingDescription
	{
	private:
		UInt32 mBinding = 0;
		UInt32 mStride = 0;
		VkVertexInputRate mInputRate;
	public:
		property UInt32 Binding
		{
			UInt32 get()
			{
				return mBinding;
			}
			void set(UInt32 value)
			{
				mBinding = value; 
			}
		}
		property UInt32 Stride
		{
			UInt32 get()
			{
				return mStride;
			}
			void set(UInt32 value)
			{
				mStride = value; 
			}
		}
		property VkVertexInputRate InputRate
		{
			VkVertexInputRate get()
			{
				return mInputRate;
			}
			void set(VkVertexInputRate value)
			{
				mInputRate = value; 
			}
		}
	};

	public ref class VertexInputAttributeDescription
	{
	private:
		UInt32 mLocation = 0;
		UInt32 mBinding = 0;
		VkFormat mFormat;
		UInt32 mOffset = 0;
	public:
		property UInt32 Location
		{
			UInt32 get()
			{
				return mLocation;
			}
			void set(UInt32 value)
			{
				mLocation = value; 
			}
		}
		property UInt32 Binding
		{
			UInt32 get()
			{
				return mBinding;
			}
			void set(UInt32 value)
			{
				mBinding = value; 
			}
		}
		property VkFormat Format
		{
			VkFormat get()
			{
				return mFormat;
			}
			void set(VkFormat value)
			{
				mFormat = value; 
			}
		}
		property UInt32 Offset
		{
			UInt32 get()
			{
				return mOffset;
			}
			void set(UInt32 value)
			{
				mOffset = value; 
			}
		}
	};

	public ref class PipelineVertexInputStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineVertexInputStateCreateFlags mFlags;
		UInt32 mVertexBindingDescriptionCount = 0;
		VertexInputBindingDescription^ mVertexBindingDescriptions = nullptr;
		UInt32 mVertexAttributeDescriptionCount = 0;
		VertexInputAttributeDescription^ mVertexAttributeDescriptions = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineVertexInputStateCreateFlags Flags
		{
			VkPipelineVertexInputStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineVertexInputStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 VertexBindingDescriptionCount
		{
			UInt32 get()
			{
				return mVertexBindingDescriptionCount;
			}
			void set(UInt32 value)
			{
				mVertexBindingDescriptionCount = value; 
			}
		}
		property VertexInputBindingDescription^ VertexBindingDescriptions
		{
			VertexInputBindingDescription^ get()
			{
				return mVertexBindingDescriptions;
			}
			void set(VertexInputBindingDescription^ value)
			{
				mVertexBindingDescriptions = value; 
			}
		}
		property UInt32 VertexAttributeDescriptionCount
		{
			UInt32 get()
			{
				return mVertexAttributeDescriptionCount;
			}
			void set(UInt32 value)
			{
				mVertexAttributeDescriptionCount = value; 
			}
		}
		property VertexInputAttributeDescription^ VertexAttributeDescriptions
		{
			VertexInputAttributeDescription^ get()
			{
				return mVertexAttributeDescriptions;
			}
			void set(VertexInputAttributeDescription^ value)
			{
				mVertexAttributeDescriptions = value; 
			}
		}
	};

	public ref class PipelineInputAssemblyStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineInputAssemblyStateCreateFlags mFlags;
		VkPrimitiveTopology mTopology;
		bool mPrimitiveRestartEnable = false;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineInputAssemblyStateCreateFlags Flags
		{
			VkPipelineInputAssemblyStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineInputAssemblyStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property VkPrimitiveTopology Topology
		{
			VkPrimitiveTopology get()
			{
				return mTopology;
			}
			void set(VkPrimitiveTopology value)
			{
				mTopology = value; 
			}
		}
		property bool PrimitiveRestartEnable
		{
			bool get()
			{
				return mPrimitiveRestartEnable;
			}
			void set(bool value)
			{
				mPrimitiveRestartEnable = value; 
			}
		}
	};

	public ref class PipelineTessellationStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineTessellationStateCreateFlags mFlags;
		UInt32 mPatchControlPoints = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineTessellationStateCreateFlags Flags
		{
			VkPipelineTessellationStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineTessellationStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 PatchControlPoints
		{
			UInt32 get()
			{
				return mPatchControlPoints;
			}
			void set(UInt32 value)
			{
				mPatchControlPoints = value; 
			}
		}
	};

	public ref class PipelineViewportStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineViewportStateCreateFlags mFlags;
		UInt32 mViewportCount = 0;
		Viewport^ mViewports = nullptr;
		UInt32 mScissorCount = 0;
		Rect2D^ mScissors = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineViewportStateCreateFlags Flags
		{
			VkPipelineViewportStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineViewportStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 ViewportCount
		{
			UInt32 get()
			{
				return mViewportCount;
			}
			void set(UInt32 value)
			{
				mViewportCount = value; 
			}
		}
		property Viewport^ Viewports
		{
			Viewport^ get()
			{
				return mViewports;
			}
			void set(Viewport^ value)
			{
				mViewports = value; 
			}
		}
		property UInt32 ScissorCount
		{
			UInt32 get()
			{
				return mScissorCount;
			}
			void set(UInt32 value)
			{
				mScissorCount = value; 
			}
		}
		property Rect2D^ Scissors
		{
			Rect2D^ get()
			{
				return mScissors;
			}
			void set(Rect2D^ value)
			{
				mScissors = value; 
			}
		}
	};

	public ref class PipelineRasterizationStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineRasterizationStateCreateFlags mFlags;
		bool mDepthClampEnable = false;
		bool mRasterizerDiscardEnable = false;
		VkPolygonMode mPolygonMode;
		VkCullModeFlags mCullMode;
		VkFrontFace mFrontFace;
		bool mDepthBiasEnable = false;
		float mDepthBiasConstantFactor = 0f;
		float mDepthBiasClamp = 0f;
		float mDepthBiasSlopeFactor = 0f;
		float mLineWidth = 0f;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineRasterizationStateCreateFlags Flags
		{
			VkPipelineRasterizationStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineRasterizationStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property bool DepthClampEnable
		{
			bool get()
			{
				return mDepthClampEnable;
			}
			void set(bool value)
			{
				mDepthClampEnable = value; 
			}
		}
		property bool RasterizerDiscardEnable
		{
			bool get()
			{
				return mRasterizerDiscardEnable;
			}
			void set(bool value)
			{
				mRasterizerDiscardEnable = value; 
			}
		}
		property VkPolygonMode PolygonMode
		{
			VkPolygonMode get()
			{
				return mPolygonMode;
			}
			void set(VkPolygonMode value)
			{
				mPolygonMode = value; 
			}
		}
		property VkCullModeFlags CullMode
		{
			VkCullModeFlags get()
			{
				return mCullMode;
			}
			void set(VkCullModeFlags value)
			{
				mCullMode = value; 
			}
		}
		property VkFrontFace FrontFace
		{
			VkFrontFace get()
			{
				return mFrontFace;
			}
			void set(VkFrontFace value)
			{
				mFrontFace = value; 
			}
		}
		property bool DepthBiasEnable
		{
			bool get()
			{
				return mDepthBiasEnable;
			}
			void set(bool value)
			{
				mDepthBiasEnable = value; 
			}
		}
		property float DepthBiasConstantFactor
		{
			float get()
			{
				return mDepthBiasConstantFactor;
			}
			void set(float value)
			{
				mDepthBiasConstantFactor = value; 
			}
		}
		property float DepthBiasClamp
		{
			float get()
			{
				return mDepthBiasClamp;
			}
			void set(float value)
			{
				mDepthBiasClamp = value; 
			}
		}
		property float DepthBiasSlopeFactor
		{
			float get()
			{
				return mDepthBiasSlopeFactor;
			}
			void set(float value)
			{
				mDepthBiasSlopeFactor = value; 
			}
		}
		property float LineWidth
		{
			float get()
			{
				return mLineWidth;
			}
			void set(float value)
			{
				mLineWidth = value; 
			}
		}
	};

	public ref class PipelineMultisampleStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineMultisampleStateCreateFlags mFlags;
		VkSampleCountFlagBits mRasterizationSamples;
		bool mSampleShadingEnable = false;
		float mMinSampleShading = 0f;
		VkSampleMask* mSampleMask;
		bool mAlphaToCoverageEnable = false;
		bool mAlphaToOneEnable = false;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineMultisampleStateCreateFlags Flags
		{
			VkPipelineMultisampleStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineMultisampleStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property VkSampleCountFlagBits RasterizationSamples
		{
			VkSampleCountFlagBits get()
			{
				return mRasterizationSamples;
			}
			void set(VkSampleCountFlagBits value)
			{
				mRasterizationSamples = value; 
			}
		}
		property bool SampleShadingEnable
		{
			bool get()
			{
				return mSampleShadingEnable;
			}
			void set(bool value)
			{
				mSampleShadingEnable = value; 
			}
		}
		property float MinSampleShading
		{
			float get()
			{
				return mMinSampleShading;
			}
			void set(float value)
			{
				mMinSampleShading = value; 
			}
		}
		property VkSampleMask* SampleMask
		{
			VkSampleMask* get()
			{
				return mSampleMask;
			}
			void set(VkSampleMask* value)
			{
				mSampleMask = value; 
			}
		}
		property bool AlphaToCoverageEnable
		{
			bool get()
			{
				return mAlphaToCoverageEnable;
			}
			void set(bool value)
			{
				mAlphaToCoverageEnable = value; 
			}
		}
		property bool AlphaToOneEnable
		{
			bool get()
			{
				return mAlphaToOneEnable;
			}
			void set(bool value)
			{
				mAlphaToOneEnable = value; 
			}
		}
	};

	public ref class PipelineColorBlendAttachmentState
	{
	private:
		bool mBlendEnable = false;
		VkBlendFactor mSrcColorBlendFactor;
		VkBlendFactor mDstColorBlendFactor;
		VkBlendOp mColorBlendOp;
		VkBlendFactor mSrcAlphaBlendFactor;
		VkBlendFactor mDstAlphaBlendFactor;
		VkBlendOp mAlphaBlendOp;
		VkColorComponentFlags mColorWriteMask;
	public:
		property bool BlendEnable
		{
			bool get()
			{
				return mBlendEnable;
			}
			void set(bool value)
			{
				mBlendEnable = value; 
			}
		}
		property VkBlendFactor SrcColorBlendFactor
		{
			VkBlendFactor get()
			{
				return mSrcColorBlendFactor;
			}
			void set(VkBlendFactor value)
			{
				mSrcColorBlendFactor = value; 
			}
		}
		property VkBlendFactor DstColorBlendFactor
		{
			VkBlendFactor get()
			{
				return mDstColorBlendFactor;
			}
			void set(VkBlendFactor value)
			{
				mDstColorBlendFactor = value; 
			}
		}
		property VkBlendOp ColorBlendOp
		{
			VkBlendOp get()
			{
				return mColorBlendOp;
			}
			void set(VkBlendOp value)
			{
				mColorBlendOp = value; 
			}
		}
		property VkBlendFactor SrcAlphaBlendFactor
		{
			VkBlendFactor get()
			{
				return mSrcAlphaBlendFactor;
			}
			void set(VkBlendFactor value)
			{
				mSrcAlphaBlendFactor = value; 
			}
		}
		property VkBlendFactor DstAlphaBlendFactor
		{
			VkBlendFactor get()
			{
				return mDstAlphaBlendFactor;
			}
			void set(VkBlendFactor value)
			{
				mDstAlphaBlendFactor = value; 
			}
		}
		property VkBlendOp AlphaBlendOp
		{
			VkBlendOp get()
			{
				return mAlphaBlendOp;
			}
			void set(VkBlendOp value)
			{
				mAlphaBlendOp = value; 
			}
		}
		property VkColorComponentFlags ColorWriteMask
		{
			VkColorComponentFlags get()
			{
				return mColorWriteMask;
			}
			void set(VkColorComponentFlags value)
			{
				mColorWriteMask = value; 
			}
		}
	};

	public ref class PipelineColorBlendStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineColorBlendStateCreateFlags mFlags;
		bool mLogicOpEnable = false;
		VkLogicOp mLogicOp;
		UInt32 mAttachmentCount = 0;
		PipelineColorBlendAttachmentState^ mAttachments = nullptr;
		blendConstants m4;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineColorBlendStateCreateFlags Flags
		{
			VkPipelineColorBlendStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineColorBlendStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property bool LogicOpEnable
		{
			bool get()
			{
				return mLogicOpEnable;
			}
			void set(bool value)
			{
				mLogicOpEnable = value; 
			}
		}
		property VkLogicOp LogicOp
		{
			VkLogicOp get()
			{
				return mLogicOp;
			}
			void set(VkLogicOp value)
			{
				mLogicOp = value; 
			}
		}
		property UInt32 AttachmentCount
		{
			UInt32 get()
			{
				return mAttachmentCount;
			}
			void set(UInt32 value)
			{
				mAttachmentCount = value; 
			}
		}
		property PipelineColorBlendAttachmentState^ Attachments
		{
			PipelineColorBlendAttachmentState^ get()
			{
				return mAttachments;
			}
			void set(PipelineColorBlendAttachmentState^ value)
			{
				mAttachments = value; 
			}
		}
		property blendConstants 4
		{
			blendConstants get()
			{
				return m4;
			}
			void set(blendConstants value)
			{
				m4 = value; 
			}
		}
	};

	public ref class PipelineDynamicStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineDynamicStateCreateFlags mFlags;
		UInt32 mDynamicStateCount = 0;
		array<VkDynamicState>^ mDynamicStates = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineDynamicStateCreateFlags Flags
		{
			VkPipelineDynamicStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineDynamicStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 DynamicStateCount
		{
			UInt32 get()
			{
				return mDynamicStateCount;
			}
			void set(UInt32 value)
			{
				mDynamicStateCount = value; 
			}
		}
		property array<VkDynamicState>^ DynamicStates
		{
			array<VkDynamicState>^ get()
			{
				return mDynamicStates;
			}
			void set(array<VkDynamicState>^ value)
			{
				mDynamicStates = value; 
			}
		}
	};

	public ref class StencilOpState
	{
	private:
		VkStencilOp mFailOp;
		VkStencilOp mPassOp;
		VkStencilOp mDepthFailOp;
		VkCompareOp mCompareOp;
		UInt32 mCompareMask = 0;
		UInt32 mWriteMask = 0;
		UInt32 mReference = 0;
	public:
		property VkStencilOp FailOp
		{
			VkStencilOp get()
			{
				return mFailOp;
			}
			void set(VkStencilOp value)
			{
				mFailOp = value; 
			}
		}
		property VkStencilOp PassOp
		{
			VkStencilOp get()
			{
				return mPassOp;
			}
			void set(VkStencilOp value)
			{
				mPassOp = value; 
			}
		}
		property VkStencilOp DepthFailOp
		{
			VkStencilOp get()
			{
				return mDepthFailOp;
			}
			void set(VkStencilOp value)
			{
				mDepthFailOp = value; 
			}
		}
		property VkCompareOp CompareOp
		{
			VkCompareOp get()
			{
				return mCompareOp;
			}
			void set(VkCompareOp value)
			{
				mCompareOp = value; 
			}
		}
		property UInt32 CompareMask
		{
			UInt32 get()
			{
				return mCompareMask;
			}
			void set(UInt32 value)
			{
				mCompareMask = value; 
			}
		}
		property UInt32 WriteMask
		{
			UInt32 get()
			{
				return mWriteMask;
			}
			void set(UInt32 value)
			{
				mWriteMask = value; 
			}
		}
		property UInt32 Reference
		{
			UInt32 get()
			{
				return mReference;
			}
			void set(UInt32 value)
			{
				mReference = value; 
			}
		}
	};

	public ref class PipelineDepthStencilStateCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineDepthStencilStateCreateFlags mFlags;
		bool mDepthTestEnable = false;
		bool mDepthWriteEnable = false;
		VkCompareOp mDepthCompareOp;
		bool mDepthBoundsTestEnable = false;
		bool mStencilTestEnable = false;
		StencilOpState^ mFront = nullptr;
		StencilOpState^ mBack = nullptr;
		float mMinDepthBounds = 0f;
		float mMaxDepthBounds = 0f;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineDepthStencilStateCreateFlags Flags
		{
			VkPipelineDepthStencilStateCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineDepthStencilStateCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property bool DepthTestEnable
		{
			bool get()
			{
				return mDepthTestEnable;
			}
			void set(bool value)
			{
				mDepthTestEnable = value; 
			}
		}
		property bool DepthWriteEnable
		{
			bool get()
			{
				return mDepthWriteEnable;
			}
			void set(bool value)
			{
				mDepthWriteEnable = value; 
			}
		}
		property VkCompareOp DepthCompareOp
		{
			VkCompareOp get()
			{
				return mDepthCompareOp;
			}
			void set(VkCompareOp value)
			{
				mDepthCompareOp = value; 
			}
		}
		property bool DepthBoundsTestEnable
		{
			bool get()
			{
				return mDepthBoundsTestEnable;
			}
			void set(bool value)
			{
				mDepthBoundsTestEnable = value; 
			}
		}
		property bool StencilTestEnable
		{
			bool get()
			{
				return mStencilTestEnable;
			}
			void set(bool value)
			{
				mStencilTestEnable = value; 
			}
		}
		property StencilOpState^ Front
		{
			StencilOpState^ get()
			{
				return mFront;
			}
			void set(StencilOpState^ value)
			{
				mFront = value; 
			}
		}
		property StencilOpState^ Back
		{
			StencilOpState^ get()
			{
				return mBack;
			}
			void set(StencilOpState^ value)
			{
				mBack = value; 
			}
		}
		property float MinDepthBounds
		{
			float get()
			{
				return mMinDepthBounds;
			}
			void set(float value)
			{
				mMinDepthBounds = value; 
			}
		}
		property float MaxDepthBounds
		{
			float get()
			{
				return mMaxDepthBounds;
			}
			void set(float value)
			{
				mMaxDepthBounds = value; 
			}
		}
	};

	public ref class GraphicsPipelineCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineCreateFlags mFlags;
		UInt32 mStageCount = 0;
		PipelineShaderStageCreateInfo^ mStages = nullptr;
		PipelineVertexInputStateCreateInfo^ mVertexInputState = nullptr;
		PipelineInputAssemblyStateCreateInfo^ mInputAssemblyState = nullptr;
		PipelineTessellationStateCreateInfo^ mTessellationState = nullptr;
		PipelineViewportStateCreateInfo^ mViewportState = nullptr;
		PipelineRasterizationStateCreateInfo^ mRasterizationState = nullptr;
		PipelineMultisampleStateCreateInfo^ mMultisampleState = nullptr;
		PipelineDepthStencilStateCreateInfo^ mDepthStencilState = nullptr;
		PipelineColorBlendStateCreateInfo^ mColorBlendState = nullptr;
		PipelineDynamicStateCreateInfo^ mDynamicState = nullptr;
		PipelineLayout^ mLayout = nullptr;
		RenderPass^ mRenderPass = nullptr;
		UInt32 mSubpass = 0;
		Pipeline^ mBasePipelineHandle = nullptr;
		Int32 mBasePipelineIndex = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineCreateFlags Flags
		{
			VkPipelineCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 StageCount
		{
			UInt32 get()
			{
				return mStageCount;
			}
			void set(UInt32 value)
			{
				mStageCount = value; 
			}
		}
		property PipelineShaderStageCreateInfo^ Stages
		{
			PipelineShaderStageCreateInfo^ get()
			{
				return mStages;
			}
			void set(PipelineShaderStageCreateInfo^ value)
			{
				mStages = value; 
			}
		}
		property PipelineVertexInputStateCreateInfo^ VertexInputState
		{
			PipelineVertexInputStateCreateInfo^ get()
			{
				return mVertexInputState;
			}
			void set(PipelineVertexInputStateCreateInfo^ value)
			{
				mVertexInputState = value; 
			}
		}
		property PipelineInputAssemblyStateCreateInfo^ InputAssemblyState
		{
			PipelineInputAssemblyStateCreateInfo^ get()
			{
				return mInputAssemblyState;
			}
			void set(PipelineInputAssemblyStateCreateInfo^ value)
			{
				mInputAssemblyState = value; 
			}
		}
		property PipelineTessellationStateCreateInfo^ TessellationState
		{
			PipelineTessellationStateCreateInfo^ get()
			{
				return mTessellationState;
			}
			void set(PipelineTessellationStateCreateInfo^ value)
			{
				mTessellationState = value; 
			}
		}
		property PipelineViewportStateCreateInfo^ ViewportState
		{
			PipelineViewportStateCreateInfo^ get()
			{
				return mViewportState;
			}
			void set(PipelineViewportStateCreateInfo^ value)
			{
				mViewportState = value; 
			}
		}
		property PipelineRasterizationStateCreateInfo^ RasterizationState
		{
			PipelineRasterizationStateCreateInfo^ get()
			{
				return mRasterizationState;
			}
			void set(PipelineRasterizationStateCreateInfo^ value)
			{
				mRasterizationState = value; 
			}
		}
		property PipelineMultisampleStateCreateInfo^ MultisampleState
		{
			PipelineMultisampleStateCreateInfo^ get()
			{
				return mMultisampleState;
			}
			void set(PipelineMultisampleStateCreateInfo^ value)
			{
				mMultisampleState = value; 
			}
		}
		property PipelineDepthStencilStateCreateInfo^ DepthStencilState
		{
			PipelineDepthStencilStateCreateInfo^ get()
			{
				return mDepthStencilState;
			}
			void set(PipelineDepthStencilStateCreateInfo^ value)
			{
				mDepthStencilState = value; 
			}
		}
		property PipelineColorBlendStateCreateInfo^ ColorBlendState
		{
			PipelineColorBlendStateCreateInfo^ get()
			{
				return mColorBlendState;
			}
			void set(PipelineColorBlendStateCreateInfo^ value)
			{
				mColorBlendState = value; 
			}
		}
		property PipelineDynamicStateCreateInfo^ DynamicState
		{
			PipelineDynamicStateCreateInfo^ get()
			{
				return mDynamicState;
			}
			void set(PipelineDynamicStateCreateInfo^ value)
			{
				mDynamicState = value; 
			}
		}
		property PipelineLayout^ Layout
		{
			PipelineLayout^ get()
			{
				return mLayout;
			}
			void set(PipelineLayout^ value)
			{
				mLayout = value; 
			}
		}
		property RenderPass^ RenderPass
		{
			RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(RenderPass^ value)
			{
				mRenderPass = value; 
			}
		}
		property UInt32 Subpass
		{
			UInt32 get()
			{
				return mSubpass;
			}
			void set(UInt32 value)
			{
				mSubpass = value; 
			}
		}
		property Pipeline^ BasePipelineHandle
		{
			Pipeline^ get()
			{
				return mBasePipelineHandle;
			}
			void set(Pipeline^ value)
			{
				mBasePipelineHandle = value; 
			}
		}
		property Int32 BasePipelineIndex
		{
			Int32 get()
			{
				return mBasePipelineIndex;
			}
			void set(Int32 value)
			{
				mBasePipelineIndex = value; 
			}
		}
	};

	public ref class PipelineCacheCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineCacheCreateFlags mFlags;
		IntPtr mInitialDataSize = 0;
		IntPtr mInitialData = IntPtr.Zero;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineCacheCreateFlags Flags
		{
			VkPipelineCacheCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineCacheCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property IntPtr InitialDataSize
		{
			IntPtr get()
			{
				return mInitialDataSize;
			}
			void set(IntPtr value)
			{
				mInitialDataSize = value; 
			}
		}
		property IntPtr InitialData
		{
			IntPtr get()
			{
				return mInitialData;
			}
			void set(IntPtr value)
			{
				mInitialData = value; 
			}
		}
	};

	public ref class PushConstantRange
	{
	private:
		VkShaderStageFlags mStageFlags;
		UInt32 mOffset = 0;
		UInt32 mSize = 0;
	public:
		property VkShaderStageFlags StageFlags
		{
			VkShaderStageFlags get()
			{
				return mStageFlags;
			}
			void set(VkShaderStageFlags value)
			{
				mStageFlags = value; 
			}
		}
		property UInt32 Offset
		{
			UInt32 get()
			{
				return mOffset;
			}
			void set(UInt32 value)
			{
				mOffset = value; 
			}
		}
		property UInt32 Size
		{
			UInt32 get()
			{
				return mSize;
			}
			void set(UInt32 value)
			{
				mSize = value; 
			}
		}
	};

	public ref class PipelineLayoutCreateInfo
	{
	private:
		VkStructureType mSType;
		VkPipelineLayoutCreateFlags mFlags;
		UInt32 mSetLayoutCount = 0;
		DescriptorSetLayout^ mSetLayouts = nullptr;
		UInt32 mPushConstantRangeCount = 0;
		PushConstantRange^ mPushConstantRanges = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkPipelineLayoutCreateFlags Flags
		{
			VkPipelineLayoutCreateFlags get()
			{
				return mFlags;
			}
			void set(VkPipelineLayoutCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 SetLayoutCount
		{
			UInt32 get()
			{
				return mSetLayoutCount;
			}
			void set(UInt32 value)
			{
				mSetLayoutCount = value; 
			}
		}
		property DescriptorSetLayout^ SetLayouts
		{
			DescriptorSetLayout^ get()
			{
				return mSetLayouts;
			}
			void set(DescriptorSetLayout^ value)
			{
				mSetLayouts = value; 
			}
		}
		property UInt32 PushConstantRangeCount
		{
			UInt32 get()
			{
				return mPushConstantRangeCount;
			}
			void set(UInt32 value)
			{
				mPushConstantRangeCount = value; 
			}
		}
		property PushConstantRange^ PushConstantRanges
		{
			PushConstantRange^ get()
			{
				return mPushConstantRanges;
			}
			void set(PushConstantRange^ value)
			{
				mPushConstantRanges = value; 
			}
		}
	};

	public ref class SamplerCreateInfo
	{
	private:
		VkStructureType mSType;
		VkSamplerCreateFlags mFlags;
		VkFilter mMagFilter;
		VkFilter mMinFilter;
		VkSamplerMipmapMode mMipmapMode;
		VkSamplerAddressMode mAddressModeU;
		VkSamplerAddressMode mAddressModeV;
		VkSamplerAddressMode mAddressModeW;
		float mMipLodBias = 0f;
		bool mAnisotropyEnable = false;
		float mMaxAnisotropy = 0f;
		bool mCompareEnable = false;
		VkCompareOp mCompareOp;
		float mMinLod = 0f;
		float mMaxLod = 0f;
		VkBorderColor mBorderColor;
		bool mUnnormalizedCoordinates = false;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkSamplerCreateFlags Flags
		{
			VkSamplerCreateFlags get()
			{
				return mFlags;
			}
			void set(VkSamplerCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property VkFilter MagFilter
		{
			VkFilter get()
			{
				return mMagFilter;
			}
			void set(VkFilter value)
			{
				mMagFilter = value; 
			}
		}
		property VkFilter MinFilter
		{
			VkFilter get()
			{
				return mMinFilter;
			}
			void set(VkFilter value)
			{
				mMinFilter = value; 
			}
		}
		property VkSamplerMipmapMode MipmapMode
		{
			VkSamplerMipmapMode get()
			{
				return mMipmapMode;
			}
			void set(VkSamplerMipmapMode value)
			{
				mMipmapMode = value; 
			}
		}
		property VkSamplerAddressMode AddressModeU
		{
			VkSamplerAddressMode get()
			{
				return mAddressModeU;
			}
			void set(VkSamplerAddressMode value)
			{
				mAddressModeU = value; 
			}
		}
		property VkSamplerAddressMode AddressModeV
		{
			VkSamplerAddressMode get()
			{
				return mAddressModeV;
			}
			void set(VkSamplerAddressMode value)
			{
				mAddressModeV = value; 
			}
		}
		property VkSamplerAddressMode AddressModeW
		{
			VkSamplerAddressMode get()
			{
				return mAddressModeW;
			}
			void set(VkSamplerAddressMode value)
			{
				mAddressModeW = value; 
			}
		}
		property float MipLodBias
		{
			float get()
			{
				return mMipLodBias;
			}
			void set(float value)
			{
				mMipLodBias = value; 
			}
		}
		property bool AnisotropyEnable
		{
			bool get()
			{
				return mAnisotropyEnable;
			}
			void set(bool value)
			{
				mAnisotropyEnable = value; 
			}
		}
		property float MaxAnisotropy
		{
			float get()
			{
				return mMaxAnisotropy;
			}
			void set(float value)
			{
				mMaxAnisotropy = value; 
			}
		}
		property bool CompareEnable
		{
			bool get()
			{
				return mCompareEnable;
			}
			void set(bool value)
			{
				mCompareEnable = value; 
			}
		}
		property VkCompareOp CompareOp
		{
			VkCompareOp get()
			{
				return mCompareOp;
			}
			void set(VkCompareOp value)
			{
				mCompareOp = value; 
			}
		}
		property float MinLod
		{
			float get()
			{
				return mMinLod;
			}
			void set(float value)
			{
				mMinLod = value; 
			}
		}
		property float MaxLod
		{
			float get()
			{
				return mMaxLod;
			}
			void set(float value)
			{
				mMaxLod = value; 
			}
		}
		property VkBorderColor BorderColor
		{
			VkBorderColor get()
			{
				return mBorderColor;
			}
			void set(VkBorderColor value)
			{
				mBorderColor = value; 
			}
		}
		property bool UnnormalizedCoordinates
		{
			bool get()
			{
				return mUnnormalizedCoordinates;
			}
			void set(bool value)
			{
				mUnnormalizedCoordinates = value; 
			}
		}
	};

	public ref class CommandPoolCreateInfo
	{
	private:
		VkStructureType mSType;
		VkCommandPoolCreateFlags mFlags;
		UInt32 mQueueFamilyIndex = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkCommandPoolCreateFlags Flags
		{
			VkCommandPoolCreateFlags get()
			{
				return mFlags;
			}
			void set(VkCommandPoolCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 QueueFamilyIndex
		{
			UInt32 get()
			{
				return mQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndex = value; 
			}
		}
	};

	public ref class CommandBufferAllocateInfo
	{
	private:
		VkStructureType mSType;
		CommandPool^ mCommandPool = nullptr;
		VkCommandBufferLevel mLevel;
		UInt32 mCommandBufferCount = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property CommandPool^ CommandPool
		{
			CommandPool^ get()
			{
				return mCommandPool;
			}
			void set(CommandPool^ value)
			{
				mCommandPool = value; 
			}
		}
		property VkCommandBufferLevel Level
		{
			VkCommandBufferLevel get()
			{
				return mLevel;
			}
			void set(VkCommandBufferLevel value)
			{
				mLevel = value; 
			}
		}
		property UInt32 CommandBufferCount
		{
			UInt32 get()
			{
				return mCommandBufferCount;
			}
			void set(UInt32 value)
			{
				mCommandBufferCount = value; 
			}
		}
	};

	public ref class CommandBufferInheritanceInfo
	{
	private:
		VkStructureType mSType;
		RenderPass^ mRenderPass = nullptr;
		UInt32 mSubpass = 0;
		Framebuffer^ mFramebuffer = nullptr;
		bool mOcclusionQueryEnable = false;
		VkQueryControlFlags mQueryFlags;
		VkQueryPipelineStatisticFlags mPipelineStatistics;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property RenderPass^ RenderPass
		{
			RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(RenderPass^ value)
			{
				mRenderPass = value; 
			}
		}
		property UInt32 Subpass
		{
			UInt32 get()
			{
				return mSubpass;
			}
			void set(UInt32 value)
			{
				mSubpass = value; 
			}
		}
		property Framebuffer^ Framebuffer
		{
			Framebuffer^ get()
			{
				return mFramebuffer;
			}
			void set(Framebuffer^ value)
			{
				mFramebuffer = value; 
			}
		}
		property bool OcclusionQueryEnable
		{
			bool get()
			{
				return mOcclusionQueryEnable;
			}
			void set(bool value)
			{
				mOcclusionQueryEnable = value; 
			}
		}
		property VkQueryControlFlags QueryFlags
		{
			VkQueryControlFlags get()
			{
				return mQueryFlags;
			}
			void set(VkQueryControlFlags value)
			{
				mQueryFlags = value; 
			}
		}
		property VkQueryPipelineStatisticFlags PipelineStatistics
		{
			VkQueryPipelineStatisticFlags get()
			{
				return mPipelineStatistics;
			}
			void set(VkQueryPipelineStatisticFlags value)
			{
				mPipelineStatistics = value; 
			}
		}
	};

	public ref class CommandBufferBeginInfo
	{
	private:
		VkStructureType mSType;
		VkCommandBufferUsageFlags mFlags;
		CommandBufferInheritanceInfo^ mInheritanceInfo = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkCommandBufferUsageFlags Flags
		{
			VkCommandBufferUsageFlags get()
			{
				return mFlags;
			}
			void set(VkCommandBufferUsageFlags value)
			{
				mFlags = value; 
			}
		}
		property CommandBufferInheritanceInfo^ InheritanceInfo
		{
			CommandBufferInheritanceInfo^ get()
			{
				return mInheritanceInfo;
			}
			void set(CommandBufferInheritanceInfo^ value)
			{
				mInheritanceInfo = value; 
			}
		}
	};

	public ref class RenderPassBeginInfo
	{
	private:
		VkStructureType mSType;
		RenderPass^ mRenderPass = nullptr;
		Framebuffer^ mFramebuffer = nullptr;
		Rect2D^ mRenderArea = nullptr;
		UInt32 mClearValueCount = 0;
		VkClearValue* mClearValues;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property RenderPass^ RenderPass
		{
			RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(RenderPass^ value)
			{
				mRenderPass = value; 
			}
		}
		property Framebuffer^ Framebuffer
		{
			Framebuffer^ get()
			{
				return mFramebuffer;
			}
			void set(Framebuffer^ value)
			{
				mFramebuffer = value; 
			}
		}
		property Rect2D^ RenderArea
		{
			Rect2D^ get()
			{
				return mRenderArea;
			}
			void set(Rect2D^ value)
			{
				mRenderArea = value; 
			}
		}
		property UInt32 ClearValueCount
		{
			UInt32 get()
			{
				return mClearValueCount;
			}
			void set(UInt32 value)
			{
				mClearValueCount = value; 
			}
		}
		property VkClearValue* ClearValues
		{
			VkClearValue* get()
			{
				return mClearValues;
			}
			void set(VkClearValue* value)
			{
				mClearValues = value; 
			}
		}
	};

	public ref class ClearDepthStencilValue
	{
	private:
		float mDepth = 0f;
		UInt32 mStencil = 0;
	public:
		property float Depth
		{
			float get()
			{
				return mDepth;
			}
			void set(float value)
			{
				mDepth = value; 
			}
		}
		property UInt32 Stencil
		{
			UInt32 get()
			{
				return mStencil;
			}
			void set(UInt32 value)
			{
				mStencil = value; 
			}
		}
	};

	public ref class ClearAttachment
	{
	private:
		VkImageAspectFlags mAspectMask;
		UInt32 mColorAttachment = 0;
		VkClearValue mClearValue;
	public:
		property VkImageAspectFlags AspectMask
		{
			VkImageAspectFlags get()
			{
				return mAspectMask;
			}
			void set(VkImageAspectFlags value)
			{
				mAspectMask = value; 
			}
		}
		property UInt32 ColorAttachment
		{
			UInt32 get()
			{
				return mColorAttachment;
			}
			void set(UInt32 value)
			{
				mColorAttachment = value; 
			}
		}
		property VkClearValue ClearValue
		{
			VkClearValue get()
			{
				return mClearValue;
			}
			void set(VkClearValue value)
			{
				mClearValue = value; 
			}
		}
	};

	public ref class AttachmentDescription
	{
	private:
		VkAttachmentDescriptionFlags mFlags;
		VkFormat mFormat;
		VkSampleCountFlagBits mSamples;
		VkAttachmentLoadOp mLoadOp;
		VkAttachmentStoreOp mStoreOp;
		VkAttachmentLoadOp mStencilLoadOp;
		VkAttachmentStoreOp mStencilStoreOp;
		VkImageLayout mInitialLayout;
		VkImageLayout mFinalLayout;
	public:
		property VkAttachmentDescriptionFlags Flags
		{
			VkAttachmentDescriptionFlags get()
			{
				return mFlags;
			}
			void set(VkAttachmentDescriptionFlags value)
			{
				mFlags = value; 
			}
		}
		property VkFormat Format
		{
			VkFormat get()
			{
				return mFormat;
			}
			void set(VkFormat value)
			{
				mFormat = value; 
			}
		}
		property VkSampleCountFlagBits Samples
		{
			VkSampleCountFlagBits get()
			{
				return mSamples;
			}
			void set(VkSampleCountFlagBits value)
			{
				mSamples = value; 
			}
		}
		property VkAttachmentLoadOp LoadOp
		{
			VkAttachmentLoadOp get()
			{
				return mLoadOp;
			}
			void set(VkAttachmentLoadOp value)
			{
				mLoadOp = value; 
			}
		}
		property VkAttachmentStoreOp StoreOp
		{
			VkAttachmentStoreOp get()
			{
				return mStoreOp;
			}
			void set(VkAttachmentStoreOp value)
			{
				mStoreOp = value; 
			}
		}
		property VkAttachmentLoadOp StencilLoadOp
		{
			VkAttachmentLoadOp get()
			{
				return mStencilLoadOp;
			}
			void set(VkAttachmentLoadOp value)
			{
				mStencilLoadOp = value; 
			}
		}
		property VkAttachmentStoreOp StencilStoreOp
		{
			VkAttachmentStoreOp get()
			{
				return mStencilStoreOp;
			}
			void set(VkAttachmentStoreOp value)
			{
				mStencilStoreOp = value; 
			}
		}
		property VkImageLayout InitialLayout
		{
			VkImageLayout get()
			{
				return mInitialLayout;
			}
			void set(VkImageLayout value)
			{
				mInitialLayout = value; 
			}
		}
		property VkImageLayout FinalLayout
		{
			VkImageLayout get()
			{
				return mFinalLayout;
			}
			void set(VkImageLayout value)
			{
				mFinalLayout = value; 
			}
		}
	};

	public ref class AttachmentReference
	{
	private:
		UInt32 mAttachment = 0;
		VkImageLayout mLayout;
	public:
		property UInt32 Attachment
		{
			UInt32 get()
			{
				return mAttachment;
			}
			void set(UInt32 value)
			{
				mAttachment = value; 
			}
		}
		property VkImageLayout Layout
		{
			VkImageLayout get()
			{
				return mLayout;
			}
			void set(VkImageLayout value)
			{
				mLayout = value; 
			}
		}
	};

	public ref class SubpassDescription
	{
	private:
		VkSubpassDescriptionFlags mFlags;
		VkPipelineBindPoint mPipelineBindPoint;
		UInt32 mInputAttachmentCount = 0;
		AttachmentReference^ mInputAttachments = nullptr;
		UInt32 mColorAttachmentCount = 0;
		AttachmentReference^ mColorAttachments = nullptr;
		AttachmentReference^ mResolveAttachments = nullptr;
		AttachmentReference^ mDepthStencilAttachment = nullptr;
		UInt32 mPreserveAttachmentCount = 0;
		UInt32 mPreserveAttachments = 0;
	public:
		property VkSubpassDescriptionFlags Flags
		{
			VkSubpassDescriptionFlags get()
			{
				return mFlags;
			}
			void set(VkSubpassDescriptionFlags value)
			{
				mFlags = value; 
			}
		}
		property VkPipelineBindPoint PipelineBindPoint
		{
			VkPipelineBindPoint get()
			{
				return mPipelineBindPoint;
			}
			void set(VkPipelineBindPoint value)
			{
				mPipelineBindPoint = value; 
			}
		}
		property UInt32 InputAttachmentCount
		{
			UInt32 get()
			{
				return mInputAttachmentCount;
			}
			void set(UInt32 value)
			{
				mInputAttachmentCount = value; 
			}
		}
		property AttachmentReference^ InputAttachments
		{
			AttachmentReference^ get()
			{
				return mInputAttachments;
			}
			void set(AttachmentReference^ value)
			{
				mInputAttachments = value; 
			}
		}
		property UInt32 ColorAttachmentCount
		{
			UInt32 get()
			{
				return mColorAttachmentCount;
			}
			void set(UInt32 value)
			{
				mColorAttachmentCount = value; 
			}
		}
		property AttachmentReference^ ColorAttachments
		{
			AttachmentReference^ get()
			{
				return mColorAttachments;
			}
			void set(AttachmentReference^ value)
			{
				mColorAttachments = value; 
			}
		}
		property AttachmentReference^ ResolveAttachments
		{
			AttachmentReference^ get()
			{
				return mResolveAttachments;
			}
			void set(AttachmentReference^ value)
			{
				mResolveAttachments = value; 
			}
		}
		property AttachmentReference^ DepthStencilAttachment
		{
			AttachmentReference^ get()
			{
				return mDepthStencilAttachment;
			}
			void set(AttachmentReference^ value)
			{
				mDepthStencilAttachment = value; 
			}
		}
		property UInt32 PreserveAttachmentCount
		{
			UInt32 get()
			{
				return mPreserveAttachmentCount;
			}
			void set(UInt32 value)
			{
				mPreserveAttachmentCount = value; 
			}
		}
		property UInt32 PreserveAttachments
		{
			UInt32 get()
			{
				return mPreserveAttachments;
			}
			void set(UInt32 value)
			{
				mPreserveAttachments = value; 
			}
		}
	};

	public ref class SubpassDependency
	{
	private:
		UInt32 mSrcSubpass = 0;
		UInt32 mDstSubpass = 0;
		VkPipelineStageFlags mSrcStageMask;
		VkPipelineStageFlags mDstStageMask;
		VkAccessFlags mSrcAccessMask;
		VkAccessFlags mDstAccessMask;
		VkDependencyFlags mDependencyFlags;
	public:
		property UInt32 SrcSubpass
		{
			UInt32 get()
			{
				return mSrcSubpass;
			}
			void set(UInt32 value)
			{
				mSrcSubpass = value; 
			}
		}
		property UInt32 DstSubpass
		{
			UInt32 get()
			{
				return mDstSubpass;
			}
			void set(UInt32 value)
			{
				mDstSubpass = value; 
			}
		}
		property VkPipelineStageFlags SrcStageMask
		{
			VkPipelineStageFlags get()
			{
				return mSrcStageMask;
			}
			void set(VkPipelineStageFlags value)
			{
				mSrcStageMask = value; 
			}
		}
		property VkPipelineStageFlags DstStageMask
		{
			VkPipelineStageFlags get()
			{
				return mDstStageMask;
			}
			void set(VkPipelineStageFlags value)
			{
				mDstStageMask = value; 
			}
		}
		property VkAccessFlags SrcAccessMask
		{
			VkAccessFlags get()
			{
				return mSrcAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mSrcAccessMask = value; 
			}
		}
		property VkAccessFlags DstAccessMask
		{
			VkAccessFlags get()
			{
				return mDstAccessMask;
			}
			void set(VkAccessFlags value)
			{
				mDstAccessMask = value; 
			}
		}
		property VkDependencyFlags DependencyFlags
		{
			VkDependencyFlags get()
			{
				return mDependencyFlags;
			}
			void set(VkDependencyFlags value)
			{
				mDependencyFlags = value; 
			}
		}
	};

	public ref class RenderPassCreateInfo
	{
	private:
		VkStructureType mSType;
		VkRenderPassCreateFlags mFlags;
		UInt32 mAttachmentCount = 0;
		AttachmentDescription^ mAttachments = nullptr;
		UInt32 mSubpassCount = 0;
		SubpassDescription^ mSubpasses = nullptr;
		UInt32 mDependencyCount = 0;
		SubpassDependency^ mDependencies = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkRenderPassCreateFlags Flags
		{
			VkRenderPassCreateFlags get()
			{
				return mFlags;
			}
			void set(VkRenderPassCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property UInt32 AttachmentCount
		{
			UInt32 get()
			{
				return mAttachmentCount;
			}
			void set(UInt32 value)
			{
				mAttachmentCount = value; 
			}
		}
		property AttachmentDescription^ Attachments
		{
			AttachmentDescription^ get()
			{
				return mAttachments;
			}
			void set(AttachmentDescription^ value)
			{
				mAttachments = value; 
			}
		}
		property UInt32 SubpassCount
		{
			UInt32 get()
			{
				return mSubpassCount;
			}
			void set(UInt32 value)
			{
				mSubpassCount = value; 
			}
		}
		property SubpassDescription^ Subpasses
		{
			SubpassDescription^ get()
			{
				return mSubpasses;
			}
			void set(SubpassDescription^ value)
			{
				mSubpasses = value; 
			}
		}
		property UInt32 DependencyCount
		{
			UInt32 get()
			{
				return mDependencyCount;
			}
			void set(UInt32 value)
			{
				mDependencyCount = value; 
			}
		}
		property SubpassDependency^ Dependencies
		{
			SubpassDependency^ get()
			{
				return mDependencies;
			}
			void set(SubpassDependency^ value)
			{
				mDependencies = value; 
			}
		}
	};

	public ref class EventCreateInfo
	{
	private:
		VkStructureType mSType;
		VkEventCreateFlags mFlags;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkEventCreateFlags Flags
		{
			VkEventCreateFlags get()
			{
				return mFlags;
			}
			void set(VkEventCreateFlags value)
			{
				mFlags = value; 
			}
		}
	};

	public ref class FenceCreateInfo
	{
	private:
		VkStructureType mSType;
		VkFenceCreateFlags mFlags;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkFenceCreateFlags Flags
		{
			VkFenceCreateFlags get()
			{
				return mFlags;
			}
			void set(VkFenceCreateFlags value)
			{
				mFlags = value; 
			}
		}
	};

	public ref class PhysicalDeviceFeatures
	{
	private:
		bool mRobustBufferAccess = false;
		bool mFullDrawIndexUint32 = false;
		bool mImageCubeArray = false;
		bool mIndependentBlend = false;
		bool mGeometryShader = false;
		bool mTessellationShader = false;
		bool mSampleRateShading = false;
		bool mDualSrcBlend = false;
		bool mLogicOp = false;
		bool mMultiDrawIndirect = false;
		bool mDrawIndirectFirstInstance = false;
		bool mDepthClamp = false;
		bool mDepthBiasClamp = false;
		bool mFillModeNonSolid = false;
		bool mDepthBounds = false;
		bool mWideLines = false;
		bool mLargePoints = false;
		bool mAlphaToOne = false;
		bool mMultiViewport = false;
		bool mSamplerAnisotropy = false;
		bool mTextureCompressionETC2 = false;
		bool mTextureCompressionASTC_LDR = false;
		bool mTextureCompressionBC = false;
		bool mOcclusionQueryPrecise = false;
		bool mPipelineStatisticsQuery = false;
		bool mVertexPipelineStoresAndAtomics = false;
		bool mFragmentStoresAndAtomics = false;
		bool mShaderTessellationAndGeometryPointSize = false;
		bool mShaderImageGatherExtended = false;
		bool mShaderStorageImageExtendedFormats = false;
		bool mShaderStorageImageMultisample = false;
		bool mShaderStorageImageReadWithoutFormat = false;
		bool mShaderStorageImageWriteWithoutFormat = false;
		bool mShaderUniformBufferArrayDynamicIndexing = false;
		bool mShaderSampledImageArrayDynamicIndexing = false;
		bool mShaderStorageBufferArrayDynamicIndexing = false;
		bool mShaderStorageImageArrayDynamicIndexing = false;
		bool mShaderClipDistance = false;
		bool mShaderCullDistance = false;
		bool mShaderFloat64 = false;
		bool mShaderInt64 = false;
		bool mShaderInt16 = false;
		bool mShaderResourceResidency = false;
		bool mShaderResourceMinLod = false;
		bool mSparseBinding = false;
		bool mSparseResidencyBuffer = false;
		bool mSparseResidencyImage2D = false;
		bool mSparseResidencyImage3D = false;
		bool mSparseResidency2Samples = false;
		bool mSparseResidency4Samples = false;
		bool mSparseResidency8Samples = false;
		bool mSparseResidency16Samples = false;
		bool mSparseResidencyAliased = false;
		bool mVariableMultisampleRate = false;
		bool mInheritedQueries = false;
	public:
		property bool RobustBufferAccess
		{
			bool get()
			{
				return mRobustBufferAccess;
			}
			void set(bool value)
			{
				mRobustBufferAccess = value; 
			}
		}
		property bool FullDrawIndexUint32
		{
			bool get()
			{
				return mFullDrawIndexUint32;
			}
			void set(bool value)
			{
				mFullDrawIndexUint32 = value; 
			}
		}
		property bool ImageCubeArray
		{
			bool get()
			{
				return mImageCubeArray;
			}
			void set(bool value)
			{
				mImageCubeArray = value; 
			}
		}
		property bool IndependentBlend
		{
			bool get()
			{
				return mIndependentBlend;
			}
			void set(bool value)
			{
				mIndependentBlend = value; 
			}
		}
		property bool GeometryShader
		{
			bool get()
			{
				return mGeometryShader;
			}
			void set(bool value)
			{
				mGeometryShader = value; 
			}
		}
		property bool TessellationShader
		{
			bool get()
			{
				return mTessellationShader;
			}
			void set(bool value)
			{
				mTessellationShader = value; 
			}
		}
		property bool SampleRateShading
		{
			bool get()
			{
				return mSampleRateShading;
			}
			void set(bool value)
			{
				mSampleRateShading = value; 
			}
		}
		property bool DualSrcBlend
		{
			bool get()
			{
				return mDualSrcBlend;
			}
			void set(bool value)
			{
				mDualSrcBlend = value; 
			}
		}
		property bool LogicOp
		{
			bool get()
			{
				return mLogicOp;
			}
			void set(bool value)
			{
				mLogicOp = value; 
			}
		}
		property bool MultiDrawIndirect
		{
			bool get()
			{
				return mMultiDrawIndirect;
			}
			void set(bool value)
			{
				mMultiDrawIndirect = value; 
			}
		}
		property bool DrawIndirectFirstInstance
		{
			bool get()
			{
				return mDrawIndirectFirstInstance;
			}
			void set(bool value)
			{
				mDrawIndirectFirstInstance = value; 
			}
		}
		property bool DepthClamp
		{
			bool get()
			{
				return mDepthClamp;
			}
			void set(bool value)
			{
				mDepthClamp = value; 
			}
		}
		property bool DepthBiasClamp
		{
			bool get()
			{
				return mDepthBiasClamp;
			}
			void set(bool value)
			{
				mDepthBiasClamp = value; 
			}
		}
		property bool FillModeNonSolid
		{
			bool get()
			{
				return mFillModeNonSolid;
			}
			void set(bool value)
			{
				mFillModeNonSolid = value; 
			}
		}
		property bool DepthBounds
		{
			bool get()
			{
				return mDepthBounds;
			}
			void set(bool value)
			{
				mDepthBounds = value; 
			}
		}
		property bool WideLines
		{
			bool get()
			{
				return mWideLines;
			}
			void set(bool value)
			{
				mWideLines = value; 
			}
		}
		property bool LargePoints
		{
			bool get()
			{
				return mLargePoints;
			}
			void set(bool value)
			{
				mLargePoints = value; 
			}
		}
		property bool AlphaToOne
		{
			bool get()
			{
				return mAlphaToOne;
			}
			void set(bool value)
			{
				mAlphaToOne = value; 
			}
		}
		property bool MultiViewport
		{
			bool get()
			{
				return mMultiViewport;
			}
			void set(bool value)
			{
				mMultiViewport = value; 
			}
		}
		property bool SamplerAnisotropy
		{
			bool get()
			{
				return mSamplerAnisotropy;
			}
			void set(bool value)
			{
				mSamplerAnisotropy = value; 
			}
		}
		property bool TextureCompressionETC2
		{
			bool get()
			{
				return mTextureCompressionETC2;
			}
			void set(bool value)
			{
				mTextureCompressionETC2 = value; 
			}
		}
		property bool TextureCompressionASTC_LDR
		{
			bool get()
			{
				return mTextureCompressionASTC_LDR;
			}
			void set(bool value)
			{
				mTextureCompressionASTC_LDR = value; 
			}
		}
		property bool TextureCompressionBC
		{
			bool get()
			{
				return mTextureCompressionBC;
			}
			void set(bool value)
			{
				mTextureCompressionBC = value; 
			}
		}
		property bool OcclusionQueryPrecise
		{
			bool get()
			{
				return mOcclusionQueryPrecise;
			}
			void set(bool value)
			{
				mOcclusionQueryPrecise = value; 
			}
		}
		property bool PipelineStatisticsQuery
		{
			bool get()
			{
				return mPipelineStatisticsQuery;
			}
			void set(bool value)
			{
				mPipelineStatisticsQuery = value; 
			}
		}
		property bool VertexPipelineStoresAndAtomics
		{
			bool get()
			{
				return mVertexPipelineStoresAndAtomics;
			}
			void set(bool value)
			{
				mVertexPipelineStoresAndAtomics = value; 
			}
		}
		property bool FragmentStoresAndAtomics
		{
			bool get()
			{
				return mFragmentStoresAndAtomics;
			}
			void set(bool value)
			{
				mFragmentStoresAndAtomics = value; 
			}
		}
		property bool ShaderTessellationAndGeometryPointSize
		{
			bool get()
			{
				return mShaderTessellationAndGeometryPointSize;
			}
			void set(bool value)
			{
				mShaderTessellationAndGeometryPointSize = value; 
			}
		}
		property bool ShaderImageGatherExtended
		{
			bool get()
			{
				return mShaderImageGatherExtended;
			}
			void set(bool value)
			{
				mShaderImageGatherExtended = value; 
			}
		}
		property bool ShaderStorageImageExtendedFormats
		{
			bool get()
			{
				return mShaderStorageImageExtendedFormats;
			}
			void set(bool value)
			{
				mShaderStorageImageExtendedFormats = value; 
			}
		}
		property bool ShaderStorageImageMultisample
		{
			bool get()
			{
				return mShaderStorageImageMultisample;
			}
			void set(bool value)
			{
				mShaderStorageImageMultisample = value; 
			}
		}
		property bool ShaderStorageImageReadWithoutFormat
		{
			bool get()
			{
				return mShaderStorageImageReadWithoutFormat;
			}
			void set(bool value)
			{
				mShaderStorageImageReadWithoutFormat = value; 
			}
		}
		property bool ShaderStorageImageWriteWithoutFormat
		{
			bool get()
			{
				return mShaderStorageImageWriteWithoutFormat;
			}
			void set(bool value)
			{
				mShaderStorageImageWriteWithoutFormat = value; 
			}
		}
		property bool ShaderUniformBufferArrayDynamicIndexing
		{
			bool get()
			{
				return mShaderUniformBufferArrayDynamicIndexing;
			}
			void set(bool value)
			{
				mShaderUniformBufferArrayDynamicIndexing = value; 
			}
		}
		property bool ShaderSampledImageArrayDynamicIndexing
		{
			bool get()
			{
				return mShaderSampledImageArrayDynamicIndexing;
			}
			void set(bool value)
			{
				mShaderSampledImageArrayDynamicIndexing = value; 
			}
		}
		property bool ShaderStorageBufferArrayDynamicIndexing
		{
			bool get()
			{
				return mShaderStorageBufferArrayDynamicIndexing;
			}
			void set(bool value)
			{
				mShaderStorageBufferArrayDynamicIndexing = value; 
			}
		}
		property bool ShaderStorageImageArrayDynamicIndexing
		{
			bool get()
			{
				return mShaderStorageImageArrayDynamicIndexing;
			}
			void set(bool value)
			{
				mShaderStorageImageArrayDynamicIndexing = value; 
			}
		}
		property bool ShaderClipDistance
		{
			bool get()
			{
				return mShaderClipDistance;
			}
			void set(bool value)
			{
				mShaderClipDistance = value; 
			}
		}
		property bool ShaderCullDistance
		{
			bool get()
			{
				return mShaderCullDistance;
			}
			void set(bool value)
			{
				mShaderCullDistance = value; 
			}
		}
		property bool ShaderFloat64
		{
			bool get()
			{
				return mShaderFloat64;
			}
			void set(bool value)
			{
				mShaderFloat64 = value; 
			}
		}
		property bool ShaderInt64
		{
			bool get()
			{
				return mShaderInt64;
			}
			void set(bool value)
			{
				mShaderInt64 = value; 
			}
		}
		property bool ShaderInt16
		{
			bool get()
			{
				return mShaderInt16;
			}
			void set(bool value)
			{
				mShaderInt16 = value; 
			}
		}
		property bool ShaderResourceResidency
		{
			bool get()
			{
				return mShaderResourceResidency;
			}
			void set(bool value)
			{
				mShaderResourceResidency = value; 
			}
		}
		property bool ShaderResourceMinLod
		{
			bool get()
			{
				return mShaderResourceMinLod;
			}
			void set(bool value)
			{
				mShaderResourceMinLod = value; 
			}
		}
		property bool SparseBinding
		{
			bool get()
			{
				return mSparseBinding;
			}
			void set(bool value)
			{
				mSparseBinding = value; 
			}
		}
		property bool SparseResidencyBuffer
		{
			bool get()
			{
				return mSparseResidencyBuffer;
			}
			void set(bool value)
			{
				mSparseResidencyBuffer = value; 
			}
		}
		property bool SparseResidencyImage2D
		{
			bool get()
			{
				return mSparseResidencyImage2D;
			}
			void set(bool value)
			{
				mSparseResidencyImage2D = value; 
			}
		}
		property bool SparseResidencyImage3D
		{
			bool get()
			{
				return mSparseResidencyImage3D;
			}
			void set(bool value)
			{
				mSparseResidencyImage3D = value; 
			}
		}
		property bool SparseResidency2Samples
		{
			bool get()
			{
				return mSparseResidency2Samples;
			}
			void set(bool value)
			{
				mSparseResidency2Samples = value; 
			}
		}
		property bool SparseResidency4Samples
		{
			bool get()
			{
				return mSparseResidency4Samples;
			}
			void set(bool value)
			{
				mSparseResidency4Samples = value; 
			}
		}
		property bool SparseResidency8Samples
		{
			bool get()
			{
				return mSparseResidency8Samples;
			}
			void set(bool value)
			{
				mSparseResidency8Samples = value; 
			}
		}
		property bool SparseResidency16Samples
		{
			bool get()
			{
				return mSparseResidency16Samples;
			}
			void set(bool value)
			{
				mSparseResidency16Samples = value; 
			}
		}
		property bool SparseResidencyAliased
		{
			bool get()
			{
				return mSparseResidencyAliased;
			}
			void set(bool value)
			{
				mSparseResidencyAliased = value; 
			}
		}
		property bool VariableMultisampleRate
		{
			bool get()
			{
				return mVariableMultisampleRate;
			}
			void set(bool value)
			{
				mVariableMultisampleRate = value; 
			}
		}
		property bool InheritedQueries
		{
			bool get()
			{
				return mInheritedQueries;
			}
			void set(bool value)
			{
				mInheritedQueries = value; 
			}
		}
	};

	public ref class PhysicalDeviceSparseProperties
	{
	private:
		bool mResidencyStandard2DBlockShape = false;
		bool mResidencyStandard2DMultisampleBlockShape = false;
		bool mResidencyStandard3DBlockShape = false;
		bool mResidencyAlignedMipSize = false;
		bool mResidencyNonResidentStrict = false;
	public:
		property bool ResidencyStandard2DBlockShape
		{
			bool get()
			{
				return mResidencyStandard2DBlockShape;
			}
			void set(bool value)
			{
				mResidencyStandard2DBlockShape = value; 
			}
		}
		property bool ResidencyStandard2DMultisampleBlockShape
		{
			bool get()
			{
				return mResidencyStandard2DMultisampleBlockShape;
			}
			void set(bool value)
			{
				mResidencyStandard2DMultisampleBlockShape = value; 
			}
		}
		property bool ResidencyStandard3DBlockShape
		{
			bool get()
			{
				return mResidencyStandard3DBlockShape;
			}
			void set(bool value)
			{
				mResidencyStandard3DBlockShape = value; 
			}
		}
		property bool ResidencyAlignedMipSize
		{
			bool get()
			{
				return mResidencyAlignedMipSize;
			}
			void set(bool value)
			{
				mResidencyAlignedMipSize = value; 
			}
		}
		property bool ResidencyNonResidentStrict
		{
			bool get()
			{
				return mResidencyNonResidentStrict;
			}
			void set(bool value)
			{
				mResidencyNonResidentStrict = value; 
			}
		}
	};

	public ref class PhysicalDeviceLimits
	{
	private:
		UInt32 mMaxImageDimension1D = 0;
		UInt32 mMaxImageDimension2D = 0;
		UInt32 mMaxImageDimension3D = 0;
		UInt32 mMaxImageDimensionCube = 0;
		UInt32 mMaxImageArrayLayers = 0;
		UInt32 mMaxTexelBufferElements = 0;
		UInt32 mMaxUniformBufferRange = 0;
		UInt32 mMaxStorageBufferRange = 0;
		UInt32 mMaxPushConstantsSize = 0;
		UInt32 mMaxMemoryAllocationCount = 0;
		UInt32 mMaxSamplerAllocationCount = 0;
		UInt64 mBufferImageGranularity = 0;
		UInt64 mSparseAddressSpaceSize = 0;
		UInt32 mMaxBoundDescriptorSets = 0;
		UInt32 mMaxPerStageDescriptorSamplers = 0;
		UInt32 mMaxPerStageDescriptorUniformBuffers = 0;
		UInt32 mMaxPerStageDescriptorStorageBuffers = 0;
		UInt32 mMaxPerStageDescriptorSampledImages = 0;
		UInt32 mMaxPerStageDescriptorStorageImages = 0;
		UInt32 mMaxPerStageDescriptorInputAttachments = 0;
		UInt32 mMaxPerStageResources = 0;
		UInt32 mMaxDescriptorSetSamplers = 0;
		UInt32 mMaxDescriptorSetUniformBuffers = 0;
		UInt32 mMaxDescriptorSetUniformBuffersDynamic = 0;
		UInt32 mMaxDescriptorSetStorageBuffers = 0;
		UInt32 mMaxDescriptorSetStorageBuffersDynamic = 0;
		UInt32 mMaxDescriptorSetSampledImages = 0;
		UInt32 mMaxDescriptorSetStorageImages = 0;
		UInt32 mMaxDescriptorSetInputAttachments = 0;
		UInt32 mMaxVertexInputAttributes = 0;
		UInt32 mMaxVertexInputBindings = 0;
		UInt32 mMaxVertexInputAttributeOffset = 0;
		UInt32 mMaxVertexInputBindingStride = 0;
		UInt32 mMaxVertexOutputComponents = 0;
		UInt32 mMaxTessellationGenerationLevel = 0;
		UInt32 mMaxTessellationPatchSize = 0;
		UInt32 mMaxTessellationControlPerVertexInputComponents = 0;
		UInt32 mMaxTessellationControlPerVertexOutputComponents = 0;
		UInt32 mMaxTessellationControlPerPatchOutputComponents = 0;
		UInt32 mMaxTessellationControlTotalOutputComponents = 0;
		UInt32 mMaxTessellationEvaluationInputComponents = 0;
		UInt32 mMaxTessellationEvaluationOutputComponents = 0;
		UInt32 mMaxGeometryShaderInvocations = 0;
		UInt32 mMaxGeometryInputComponents = 0;
		UInt32 mMaxGeometryOutputComponents = 0;
		UInt32 mMaxGeometryOutputVertices = 0;
		UInt32 mMaxGeometryTotalOutputComponents = 0;
		UInt32 mMaxFragmentInputComponents = 0;
		UInt32 mMaxFragmentOutputAttachments = 0;
		UInt32 mMaxFragmentDualSrcAttachments = 0;
		UInt32 mMaxFragmentCombinedOutputResources = 0;
		UInt32 mMaxComputeSharedMemorySize = 0;
		maxComputeWorkGroupCount m3;
		UInt32 mMaxComputeWorkGroupInvocations = 0;
		maxComputeWorkGroupSize m3;
		UInt32 mSubPixelPrecisionBits = 0;
		UInt32 mSubTexelPrecisionBits = 0;
		UInt32 mMipmapPrecisionBits = 0;
		UInt32 mMaxDrawIndexedIndexValue = 0;
		UInt32 mMaxDrawIndirectCount = 0;
		float mMaxSamplerLodBias = 0f;
		float mMaxSamplerAnisotropy = 0f;
		UInt32 mMaxViewports = 0;
		maxViewportDimensions m2;
		viewportBoundsRange m2;
		UInt32 mViewportSubPixelBits = 0;
		IntPtr mMinMemoryMapAlignment = 0;
		UInt64 mMinTexelBufferOffsetAlignment = 0;
		UInt64 mMinUniformBufferOffsetAlignment = 0;
		UInt64 mMinStorageBufferOffsetAlignment = 0;
		Int32 mMinTexelOffset = 0;
		UInt32 mMaxTexelOffset = 0;
		Int32 mMinTexelGatherOffset = 0;
		UInt32 mMaxTexelGatherOffset = 0;
		float mMinInterpolationOffset = 0f;
		float mMaxInterpolationOffset = 0f;
		UInt32 mSubPixelInterpolationOffsetBits = 0;
		UInt32 mMaxFramebufferWidth = 0;
		UInt32 mMaxFramebufferHeight = 0;
		UInt32 mMaxFramebufferLayers = 0;
		VkSampleCountFlags mFramebufferColorSampleCounts;
		VkSampleCountFlags mFramebufferDepthSampleCounts;
		VkSampleCountFlags mFramebufferStencilSampleCounts;
		VkSampleCountFlags mFramebufferNoAttachmentsSampleCounts;
		UInt32 mMaxColorAttachments = 0;
		VkSampleCountFlags mSampledImageColorSampleCounts;
		VkSampleCountFlags mSampledImageIntegerSampleCounts;
		VkSampleCountFlags mSampledImageDepthSampleCounts;
		VkSampleCountFlags mSampledImageStencilSampleCounts;
		VkSampleCountFlags mStorageImageSampleCounts;
		UInt32 mMaxSampleMaskWords = 0;
		bool mTimestampComputeAndGraphics = false;
		float mTimestampPeriod = 0f;
		UInt32 mMaxClipDistances = 0;
		UInt32 mMaxCullDistances = 0;
		UInt32 mMaxCombinedClipAndCullDistances = 0;
		UInt32 mDiscreteQueuePriorities = 0;
		pointSizeRange m2;
		lineWidthRange m2;
		float mPointSizeGranularity = 0f;
		float mLineWidthGranularity = 0f;
		bool mStrictLines = false;
		bool mStandardSampleLocations = false;
		UInt64 mOptimalBufferCopyOffsetAlignment = 0;
		UInt64 mOptimalBufferCopyRowPitchAlignment = 0;
		UInt64 mNonCoherentAtomSize = 0;
	public:
		property UInt32 MaxImageDimension1D
		{
			UInt32 get()
			{
				return mMaxImageDimension1D;
			}
			void set(UInt32 value)
			{
				mMaxImageDimension1D = value; 
			}
		}
		property UInt32 MaxImageDimension2D
		{
			UInt32 get()
			{
				return mMaxImageDimension2D;
			}
			void set(UInt32 value)
			{
				mMaxImageDimension2D = value; 
			}
		}
		property UInt32 MaxImageDimension3D
		{
			UInt32 get()
			{
				return mMaxImageDimension3D;
			}
			void set(UInt32 value)
			{
				mMaxImageDimension3D = value; 
			}
		}
		property UInt32 MaxImageDimensionCube
		{
			UInt32 get()
			{
				return mMaxImageDimensionCube;
			}
			void set(UInt32 value)
			{
				mMaxImageDimensionCube = value; 
			}
		}
		property UInt32 MaxImageArrayLayers
		{
			UInt32 get()
			{
				return mMaxImageArrayLayers;
			}
			void set(UInt32 value)
			{
				mMaxImageArrayLayers = value; 
			}
		}
		property UInt32 MaxTexelBufferElements
		{
			UInt32 get()
			{
				return mMaxTexelBufferElements;
			}
			void set(UInt32 value)
			{
				mMaxTexelBufferElements = value; 
			}
		}
		property UInt32 MaxUniformBufferRange
		{
			UInt32 get()
			{
				return mMaxUniformBufferRange;
			}
			void set(UInt32 value)
			{
				mMaxUniformBufferRange = value; 
			}
		}
		property UInt32 MaxStorageBufferRange
		{
			UInt32 get()
			{
				return mMaxStorageBufferRange;
			}
			void set(UInt32 value)
			{
				mMaxStorageBufferRange = value; 
			}
		}
		property UInt32 MaxPushConstantsSize
		{
			UInt32 get()
			{
				return mMaxPushConstantsSize;
			}
			void set(UInt32 value)
			{
				mMaxPushConstantsSize = value; 
			}
		}
		property UInt32 MaxMemoryAllocationCount
		{
			UInt32 get()
			{
				return mMaxMemoryAllocationCount;
			}
			void set(UInt32 value)
			{
				mMaxMemoryAllocationCount = value; 
			}
		}
		property UInt32 MaxSamplerAllocationCount
		{
			UInt32 get()
			{
				return mMaxSamplerAllocationCount;
			}
			void set(UInt32 value)
			{
				mMaxSamplerAllocationCount = value; 
			}
		}
		property UInt64 BufferImageGranularity
		{
			UInt64 get()
			{
				return mBufferImageGranularity;
			}
			void set(UInt64 value)
			{
				mBufferImageGranularity = value; 
			}
		}
		property UInt64 SparseAddressSpaceSize
		{
			UInt64 get()
			{
				return mSparseAddressSpaceSize;
			}
			void set(UInt64 value)
			{
				mSparseAddressSpaceSize = value; 
			}
		}
		property UInt32 MaxBoundDescriptorSets
		{
			UInt32 get()
			{
				return mMaxBoundDescriptorSets;
			}
			void set(UInt32 value)
			{
				mMaxBoundDescriptorSets = value; 
			}
		}
		property UInt32 MaxPerStageDescriptorSamplers
		{
			UInt32 get()
			{
				return mMaxPerStageDescriptorSamplers;
			}
			void set(UInt32 value)
			{
				mMaxPerStageDescriptorSamplers = value; 
			}
		}
		property UInt32 MaxPerStageDescriptorUniformBuffers
		{
			UInt32 get()
			{
				return mMaxPerStageDescriptorUniformBuffers;
			}
			void set(UInt32 value)
			{
				mMaxPerStageDescriptorUniformBuffers = value; 
			}
		}
		property UInt32 MaxPerStageDescriptorStorageBuffers
		{
			UInt32 get()
			{
				return mMaxPerStageDescriptorStorageBuffers;
			}
			void set(UInt32 value)
			{
				mMaxPerStageDescriptorStorageBuffers = value; 
			}
		}
		property UInt32 MaxPerStageDescriptorSampledImages
		{
			UInt32 get()
			{
				return mMaxPerStageDescriptorSampledImages;
			}
			void set(UInt32 value)
			{
				mMaxPerStageDescriptorSampledImages = value; 
			}
		}
		property UInt32 MaxPerStageDescriptorStorageImages
		{
			UInt32 get()
			{
				return mMaxPerStageDescriptorStorageImages;
			}
			void set(UInt32 value)
			{
				mMaxPerStageDescriptorStorageImages = value; 
			}
		}
		property UInt32 MaxPerStageDescriptorInputAttachments
		{
			UInt32 get()
			{
				return mMaxPerStageDescriptorInputAttachments;
			}
			void set(UInt32 value)
			{
				mMaxPerStageDescriptorInputAttachments = value; 
			}
		}
		property UInt32 MaxPerStageResources
		{
			UInt32 get()
			{
				return mMaxPerStageResources;
			}
			void set(UInt32 value)
			{
				mMaxPerStageResources = value; 
			}
		}
		property UInt32 MaxDescriptorSetSamplers
		{
			UInt32 get()
			{
				return mMaxDescriptorSetSamplers;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetSamplers = value; 
			}
		}
		property UInt32 MaxDescriptorSetUniformBuffers
		{
			UInt32 get()
			{
				return mMaxDescriptorSetUniformBuffers;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetUniformBuffers = value; 
			}
		}
		property UInt32 MaxDescriptorSetUniformBuffersDynamic
		{
			UInt32 get()
			{
				return mMaxDescriptorSetUniformBuffersDynamic;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetUniformBuffersDynamic = value; 
			}
		}
		property UInt32 MaxDescriptorSetStorageBuffers
		{
			UInt32 get()
			{
				return mMaxDescriptorSetStorageBuffers;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetStorageBuffers = value; 
			}
		}
		property UInt32 MaxDescriptorSetStorageBuffersDynamic
		{
			UInt32 get()
			{
				return mMaxDescriptorSetStorageBuffersDynamic;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetStorageBuffersDynamic = value; 
			}
		}
		property UInt32 MaxDescriptorSetSampledImages
		{
			UInt32 get()
			{
				return mMaxDescriptorSetSampledImages;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetSampledImages = value; 
			}
		}
		property UInt32 MaxDescriptorSetStorageImages
		{
			UInt32 get()
			{
				return mMaxDescriptorSetStorageImages;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetStorageImages = value; 
			}
		}
		property UInt32 MaxDescriptorSetInputAttachments
		{
			UInt32 get()
			{
				return mMaxDescriptorSetInputAttachments;
			}
			void set(UInt32 value)
			{
				mMaxDescriptorSetInputAttachments = value; 
			}
		}
		property UInt32 MaxVertexInputAttributes
		{
			UInt32 get()
			{
				return mMaxVertexInputAttributes;
			}
			void set(UInt32 value)
			{
				mMaxVertexInputAttributes = value; 
			}
		}
		property UInt32 MaxVertexInputBindings
		{
			UInt32 get()
			{
				return mMaxVertexInputBindings;
			}
			void set(UInt32 value)
			{
				mMaxVertexInputBindings = value; 
			}
		}
		property UInt32 MaxVertexInputAttributeOffset
		{
			UInt32 get()
			{
				return mMaxVertexInputAttributeOffset;
			}
			void set(UInt32 value)
			{
				mMaxVertexInputAttributeOffset = value; 
			}
		}
		property UInt32 MaxVertexInputBindingStride
		{
			UInt32 get()
			{
				return mMaxVertexInputBindingStride;
			}
			void set(UInt32 value)
			{
				mMaxVertexInputBindingStride = value; 
			}
		}
		property UInt32 MaxVertexOutputComponents
		{
			UInt32 get()
			{
				return mMaxVertexOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxVertexOutputComponents = value; 
			}
		}
		property UInt32 MaxTessellationGenerationLevel
		{
			UInt32 get()
			{
				return mMaxTessellationGenerationLevel;
			}
			void set(UInt32 value)
			{
				mMaxTessellationGenerationLevel = value; 
			}
		}
		property UInt32 MaxTessellationPatchSize
		{
			UInt32 get()
			{
				return mMaxTessellationPatchSize;
			}
			void set(UInt32 value)
			{
				mMaxTessellationPatchSize = value; 
			}
		}
		property UInt32 MaxTessellationControlPerVertexInputComponents
		{
			UInt32 get()
			{
				return mMaxTessellationControlPerVertexInputComponents;
			}
			void set(UInt32 value)
			{
				mMaxTessellationControlPerVertexInputComponents = value; 
			}
		}
		property UInt32 MaxTessellationControlPerVertexOutputComponents
		{
			UInt32 get()
			{
				return mMaxTessellationControlPerVertexOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxTessellationControlPerVertexOutputComponents = value; 
			}
		}
		property UInt32 MaxTessellationControlPerPatchOutputComponents
		{
			UInt32 get()
			{
				return mMaxTessellationControlPerPatchOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxTessellationControlPerPatchOutputComponents = value; 
			}
		}
		property UInt32 MaxTessellationControlTotalOutputComponents
		{
			UInt32 get()
			{
				return mMaxTessellationControlTotalOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxTessellationControlTotalOutputComponents = value; 
			}
		}
		property UInt32 MaxTessellationEvaluationInputComponents
		{
			UInt32 get()
			{
				return mMaxTessellationEvaluationInputComponents;
			}
			void set(UInt32 value)
			{
				mMaxTessellationEvaluationInputComponents = value; 
			}
		}
		property UInt32 MaxTessellationEvaluationOutputComponents
		{
			UInt32 get()
			{
				return mMaxTessellationEvaluationOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxTessellationEvaluationOutputComponents = value; 
			}
		}
		property UInt32 MaxGeometryShaderInvocations
		{
			UInt32 get()
			{
				return mMaxGeometryShaderInvocations;
			}
			void set(UInt32 value)
			{
				mMaxGeometryShaderInvocations = value; 
			}
		}
		property UInt32 MaxGeometryInputComponents
		{
			UInt32 get()
			{
				return mMaxGeometryInputComponents;
			}
			void set(UInt32 value)
			{
				mMaxGeometryInputComponents = value; 
			}
		}
		property UInt32 MaxGeometryOutputComponents
		{
			UInt32 get()
			{
				return mMaxGeometryOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxGeometryOutputComponents = value; 
			}
		}
		property UInt32 MaxGeometryOutputVertices
		{
			UInt32 get()
			{
				return mMaxGeometryOutputVertices;
			}
			void set(UInt32 value)
			{
				mMaxGeometryOutputVertices = value; 
			}
		}
		property UInt32 MaxGeometryTotalOutputComponents
		{
			UInt32 get()
			{
				return mMaxGeometryTotalOutputComponents;
			}
			void set(UInt32 value)
			{
				mMaxGeometryTotalOutputComponents = value; 
			}
		}
		property UInt32 MaxFragmentInputComponents
		{
			UInt32 get()
			{
				return mMaxFragmentInputComponents;
			}
			void set(UInt32 value)
			{
				mMaxFragmentInputComponents = value; 
			}
		}
		property UInt32 MaxFragmentOutputAttachments
		{
			UInt32 get()
			{
				return mMaxFragmentOutputAttachments;
			}
			void set(UInt32 value)
			{
				mMaxFragmentOutputAttachments = value; 
			}
		}
		property UInt32 MaxFragmentDualSrcAttachments
		{
			UInt32 get()
			{
				return mMaxFragmentDualSrcAttachments;
			}
			void set(UInt32 value)
			{
				mMaxFragmentDualSrcAttachments = value; 
			}
		}
		property UInt32 MaxFragmentCombinedOutputResources
		{
			UInt32 get()
			{
				return mMaxFragmentCombinedOutputResources;
			}
			void set(UInt32 value)
			{
				mMaxFragmentCombinedOutputResources = value; 
			}
		}
		property UInt32 MaxComputeSharedMemorySize
		{
			UInt32 get()
			{
				return mMaxComputeSharedMemorySize;
			}
			void set(UInt32 value)
			{
				mMaxComputeSharedMemorySize = value; 
			}
		}
		property maxComputeWorkGroupCount 3
		{
			maxComputeWorkGroupCount get()
			{
				return m3;
			}
			void set(maxComputeWorkGroupCount value)
			{
				m3 = value; 
			}
		}
		property UInt32 MaxComputeWorkGroupInvocations
		{
			UInt32 get()
			{
				return mMaxComputeWorkGroupInvocations;
			}
			void set(UInt32 value)
			{
				mMaxComputeWorkGroupInvocations = value; 
			}
		}
		property maxComputeWorkGroupSize 3
		{
			maxComputeWorkGroupSize get()
			{
				return m3;
			}
			void set(maxComputeWorkGroupSize value)
			{
				m3 = value; 
			}
		}
		property UInt32 SubPixelPrecisionBits
		{
			UInt32 get()
			{
				return mSubPixelPrecisionBits;
			}
			void set(UInt32 value)
			{
				mSubPixelPrecisionBits = value; 
			}
		}
		property UInt32 SubTexelPrecisionBits
		{
			UInt32 get()
			{
				return mSubTexelPrecisionBits;
			}
			void set(UInt32 value)
			{
				mSubTexelPrecisionBits = value; 
			}
		}
		property UInt32 MipmapPrecisionBits
		{
			UInt32 get()
			{
				return mMipmapPrecisionBits;
			}
			void set(UInt32 value)
			{
				mMipmapPrecisionBits = value; 
			}
		}
		property UInt32 MaxDrawIndexedIndexValue
		{
			UInt32 get()
			{
				return mMaxDrawIndexedIndexValue;
			}
			void set(UInt32 value)
			{
				mMaxDrawIndexedIndexValue = value; 
			}
		}
		property UInt32 MaxDrawIndirectCount
		{
			UInt32 get()
			{
				return mMaxDrawIndirectCount;
			}
			void set(UInt32 value)
			{
				mMaxDrawIndirectCount = value; 
			}
		}
		property float MaxSamplerLodBias
		{
			float get()
			{
				return mMaxSamplerLodBias;
			}
			void set(float value)
			{
				mMaxSamplerLodBias = value; 
			}
		}
		property float MaxSamplerAnisotropy
		{
			float get()
			{
				return mMaxSamplerAnisotropy;
			}
			void set(float value)
			{
				mMaxSamplerAnisotropy = value; 
			}
		}
		property UInt32 MaxViewports
		{
			UInt32 get()
			{
				return mMaxViewports;
			}
			void set(UInt32 value)
			{
				mMaxViewports = value; 
			}
		}
		property maxViewportDimensions 2
		{
			maxViewportDimensions get()
			{
				return m2;
			}
			void set(maxViewportDimensions value)
			{
				m2 = value; 
			}
		}
		property viewportBoundsRange 2
		{
			viewportBoundsRange get()
			{
				return m2;
			}
			void set(viewportBoundsRange value)
			{
				m2 = value; 
			}
		}
		property UInt32 ViewportSubPixelBits
		{
			UInt32 get()
			{
				return mViewportSubPixelBits;
			}
			void set(UInt32 value)
			{
				mViewportSubPixelBits = value; 
			}
		}
		property IntPtr MinMemoryMapAlignment
		{
			IntPtr get()
			{
				return mMinMemoryMapAlignment;
			}
			void set(IntPtr value)
			{
				mMinMemoryMapAlignment = value; 
			}
		}
		property UInt64 MinTexelBufferOffsetAlignment
		{
			UInt64 get()
			{
				return mMinTexelBufferOffsetAlignment;
			}
			void set(UInt64 value)
			{
				mMinTexelBufferOffsetAlignment = value; 
			}
		}
		property UInt64 MinUniformBufferOffsetAlignment
		{
			UInt64 get()
			{
				return mMinUniformBufferOffsetAlignment;
			}
			void set(UInt64 value)
			{
				mMinUniformBufferOffsetAlignment = value; 
			}
		}
		property UInt64 MinStorageBufferOffsetAlignment
		{
			UInt64 get()
			{
				return mMinStorageBufferOffsetAlignment;
			}
			void set(UInt64 value)
			{
				mMinStorageBufferOffsetAlignment = value; 
			}
		}
		property Int32 MinTexelOffset
		{
			Int32 get()
			{
				return mMinTexelOffset;
			}
			void set(Int32 value)
			{
				mMinTexelOffset = value; 
			}
		}
		property UInt32 MaxTexelOffset
		{
			UInt32 get()
			{
				return mMaxTexelOffset;
			}
			void set(UInt32 value)
			{
				mMaxTexelOffset = value; 
			}
		}
		property Int32 MinTexelGatherOffset
		{
			Int32 get()
			{
				return mMinTexelGatherOffset;
			}
			void set(Int32 value)
			{
				mMinTexelGatherOffset = value; 
			}
		}
		property UInt32 MaxTexelGatherOffset
		{
			UInt32 get()
			{
				return mMaxTexelGatherOffset;
			}
			void set(UInt32 value)
			{
				mMaxTexelGatherOffset = value; 
			}
		}
		property float MinInterpolationOffset
		{
			float get()
			{
				return mMinInterpolationOffset;
			}
			void set(float value)
			{
				mMinInterpolationOffset = value; 
			}
		}
		property float MaxInterpolationOffset
		{
			float get()
			{
				return mMaxInterpolationOffset;
			}
			void set(float value)
			{
				mMaxInterpolationOffset = value; 
			}
		}
		property UInt32 SubPixelInterpolationOffsetBits
		{
			UInt32 get()
			{
				return mSubPixelInterpolationOffsetBits;
			}
			void set(UInt32 value)
			{
				mSubPixelInterpolationOffsetBits = value; 
			}
		}
		property UInt32 MaxFramebufferWidth
		{
			UInt32 get()
			{
				return mMaxFramebufferWidth;
			}
			void set(UInt32 value)
			{
				mMaxFramebufferWidth = value; 
			}
		}
		property UInt32 MaxFramebufferHeight
		{
			UInt32 get()
			{
				return mMaxFramebufferHeight;
			}
			void set(UInt32 value)
			{
				mMaxFramebufferHeight = value; 
			}
		}
		property UInt32 MaxFramebufferLayers
		{
			UInt32 get()
			{
				return mMaxFramebufferLayers;
			}
			void set(UInt32 value)
			{
				mMaxFramebufferLayers = value; 
			}
		}
		property VkSampleCountFlags FramebufferColorSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mFramebufferColorSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mFramebufferColorSampleCounts = value; 
			}
		}
		property VkSampleCountFlags FramebufferDepthSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mFramebufferDepthSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mFramebufferDepthSampleCounts = value; 
			}
		}
		property VkSampleCountFlags FramebufferStencilSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mFramebufferStencilSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mFramebufferStencilSampleCounts = value; 
			}
		}
		property VkSampleCountFlags FramebufferNoAttachmentsSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mFramebufferNoAttachmentsSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mFramebufferNoAttachmentsSampleCounts = value; 
			}
		}
		property UInt32 MaxColorAttachments
		{
			UInt32 get()
			{
				return mMaxColorAttachments;
			}
			void set(UInt32 value)
			{
				mMaxColorAttachments = value; 
			}
		}
		property VkSampleCountFlags SampledImageColorSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mSampledImageColorSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mSampledImageColorSampleCounts = value; 
			}
		}
		property VkSampleCountFlags SampledImageIntegerSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mSampledImageIntegerSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mSampledImageIntegerSampleCounts = value; 
			}
		}
		property VkSampleCountFlags SampledImageDepthSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mSampledImageDepthSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mSampledImageDepthSampleCounts = value; 
			}
		}
		property VkSampleCountFlags SampledImageStencilSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mSampledImageStencilSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mSampledImageStencilSampleCounts = value; 
			}
		}
		property VkSampleCountFlags StorageImageSampleCounts
		{
			VkSampleCountFlags get()
			{
				return mStorageImageSampleCounts;
			}
			void set(VkSampleCountFlags value)
			{
				mStorageImageSampleCounts = value; 
			}
		}
		property UInt32 MaxSampleMaskWords
		{
			UInt32 get()
			{
				return mMaxSampleMaskWords;
			}
			void set(UInt32 value)
			{
				mMaxSampleMaskWords = value; 
			}
		}
		property bool TimestampComputeAndGraphics
		{
			bool get()
			{
				return mTimestampComputeAndGraphics;
			}
			void set(bool value)
			{
				mTimestampComputeAndGraphics = value; 
			}
		}
		property float TimestampPeriod
		{
			float get()
			{
				return mTimestampPeriod;
			}
			void set(float value)
			{
				mTimestampPeriod = value; 
			}
		}
		property UInt32 MaxClipDistances
		{
			UInt32 get()
			{
				return mMaxClipDistances;
			}
			void set(UInt32 value)
			{
				mMaxClipDistances = value; 
			}
		}
		property UInt32 MaxCullDistances
		{
			UInt32 get()
			{
				return mMaxCullDistances;
			}
			void set(UInt32 value)
			{
				mMaxCullDistances = value; 
			}
		}
		property UInt32 MaxCombinedClipAndCullDistances
		{
			UInt32 get()
			{
				return mMaxCombinedClipAndCullDistances;
			}
			void set(UInt32 value)
			{
				mMaxCombinedClipAndCullDistances = value; 
			}
		}
		property UInt32 DiscreteQueuePriorities
		{
			UInt32 get()
			{
				return mDiscreteQueuePriorities;
			}
			void set(UInt32 value)
			{
				mDiscreteQueuePriorities = value; 
			}
		}
		property pointSizeRange 2
		{
			pointSizeRange get()
			{
				return m2;
			}
			void set(pointSizeRange value)
			{
				m2 = value; 
			}
		}
		property lineWidthRange 2
		{
			lineWidthRange get()
			{
				return m2;
			}
			void set(lineWidthRange value)
			{
				m2 = value; 
			}
		}
		property float PointSizeGranularity
		{
			float get()
			{
				return mPointSizeGranularity;
			}
			void set(float value)
			{
				mPointSizeGranularity = value; 
			}
		}
		property float LineWidthGranularity
		{
			float get()
			{
				return mLineWidthGranularity;
			}
			void set(float value)
			{
				mLineWidthGranularity = value; 
			}
		}
		property bool StrictLines
		{
			bool get()
			{
				return mStrictLines;
			}
			void set(bool value)
			{
				mStrictLines = value; 
			}
		}
		property bool StandardSampleLocations
		{
			bool get()
			{
				return mStandardSampleLocations;
			}
			void set(bool value)
			{
				mStandardSampleLocations = value; 
			}
		}
		property UInt64 OptimalBufferCopyOffsetAlignment
		{
			UInt64 get()
			{
				return mOptimalBufferCopyOffsetAlignment;
			}
			void set(UInt64 value)
			{
				mOptimalBufferCopyOffsetAlignment = value; 
			}
		}
		property UInt64 OptimalBufferCopyRowPitchAlignment
		{
			UInt64 get()
			{
				return mOptimalBufferCopyRowPitchAlignment;
			}
			void set(UInt64 value)
			{
				mOptimalBufferCopyRowPitchAlignment = value; 
			}
		}
		property UInt64 NonCoherentAtomSize
		{
			UInt64 get()
			{
				return mNonCoherentAtomSize;
			}
			void set(UInt64 value)
			{
				mNonCoherentAtomSize = value; 
			}
		}
	};

	public ref class SemaphoreCreateInfo
	{
	private:
		VkStructureType mSType;
		VkSemaphoreCreateFlags mFlags;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkSemaphoreCreateFlags Flags
		{
			VkSemaphoreCreateFlags get()
			{
				return mFlags;
			}
			void set(VkSemaphoreCreateFlags value)
			{
				mFlags = value; 
			}
		}
	};

	public ref class QueryPoolCreateInfo
	{
	private:
		VkStructureType mSType;
		VkQueryPoolCreateFlags mFlags;
		VkQueryType mQueryType;
		UInt32 mQueryCount = 0;
		VkQueryPipelineStatisticFlags mPipelineStatistics;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkQueryPoolCreateFlags Flags
		{
			VkQueryPoolCreateFlags get()
			{
				return mFlags;
			}
			void set(VkQueryPoolCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property VkQueryType QueryType
		{
			VkQueryType get()
			{
				return mQueryType;
			}
			void set(VkQueryType value)
			{
				mQueryType = value; 
			}
		}
		property UInt32 QueryCount
		{
			UInt32 get()
			{
				return mQueryCount;
			}
			void set(UInt32 value)
			{
				mQueryCount = value; 
			}
		}
		property VkQueryPipelineStatisticFlags PipelineStatistics
		{
			VkQueryPipelineStatisticFlags get()
			{
				return mPipelineStatistics;
			}
			void set(VkQueryPipelineStatisticFlags value)
			{
				mPipelineStatistics = value; 
			}
		}
	};

	public ref class FramebufferCreateInfo
	{
	private:
		VkStructureType mSType;
		VkFramebufferCreateFlags mFlags;
		RenderPass^ mRenderPass = nullptr;
		UInt32 mAttachmentCount = 0;
		ImageView^ mAttachments = nullptr;
		UInt32 mWidth = 0;
		UInt32 mHeight = 0;
		UInt32 mLayers = 0;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkFramebufferCreateFlags Flags
		{
			VkFramebufferCreateFlags get()
			{
				return mFlags;
			}
			void set(VkFramebufferCreateFlags value)
			{
				mFlags = value; 
			}
		}
		property RenderPass^ RenderPass
		{
			RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(RenderPass^ value)
			{
				mRenderPass = value; 
			}
		}
		property UInt32 AttachmentCount
		{
			UInt32 get()
			{
				return mAttachmentCount;
			}
			void set(UInt32 value)
			{
				mAttachmentCount = value; 
			}
		}
		property ImageView^ Attachments
		{
			ImageView^ get()
			{
				return mAttachments;
			}
			void set(ImageView^ value)
			{
				mAttachments = value; 
			}
		}
		property UInt32 Width
		{
			UInt32 get()
			{
				return mWidth;
			}
			void set(UInt32 value)
			{
				mWidth = value; 
			}
		}
		property UInt32 Height
		{
			UInt32 get()
			{
				return mHeight;
			}
			void set(UInt32 value)
			{
				mHeight = value; 
			}
		}
		property UInt32 Layers
		{
			UInt32 get()
			{
				return mLayers;
			}
			void set(UInt32 value)
			{
				mLayers = value; 
			}
		}
	};

	public ref class DrawIndirectCommand
	{
	private:
		UInt32 mVertexCount = 0;
		UInt32 mInstanceCount = 0;
		UInt32 mFirstVertex = 0;
		UInt32 mFirstInstance = 0;
	public:
		property UInt32 VertexCount
		{
			UInt32 get()
			{
				return mVertexCount;
			}
			void set(UInt32 value)
			{
				mVertexCount = value; 
			}
		}
		property UInt32 InstanceCount
		{
			UInt32 get()
			{
				return mInstanceCount;
			}
			void set(UInt32 value)
			{
				mInstanceCount = value; 
			}
		}
		property UInt32 FirstVertex
		{
			UInt32 get()
			{
				return mFirstVertex;
			}
			void set(UInt32 value)
			{
				mFirstVertex = value; 
			}
		}
		property UInt32 FirstInstance
		{
			UInt32 get()
			{
				return mFirstInstance;
			}
			void set(UInt32 value)
			{
				mFirstInstance = value; 
			}
		}
	};

	public ref class DrawIndexedIndirectCommand
	{
	private:
		UInt32 mIndexCount = 0;
		UInt32 mInstanceCount = 0;
		UInt32 mFirstIndex = 0;
		Int32 mVertexOffset = 0;
		UInt32 mFirstInstance = 0;
	public:
		property UInt32 IndexCount
		{
			UInt32 get()
			{
				return mIndexCount;
			}
			void set(UInt32 value)
			{
				mIndexCount = value; 
			}
		}
		property UInt32 InstanceCount
		{
			UInt32 get()
			{
				return mInstanceCount;
			}
			void set(UInt32 value)
			{
				mInstanceCount = value; 
			}
		}
		property UInt32 FirstIndex
		{
			UInt32 get()
			{
				return mFirstIndex;
			}
			void set(UInt32 value)
			{
				mFirstIndex = value; 
			}
		}
		property Int32 VertexOffset
		{
			Int32 get()
			{
				return mVertexOffset;
			}
			void set(Int32 value)
			{
				mVertexOffset = value; 
			}
		}
		property UInt32 FirstInstance
		{
			UInt32 get()
			{
				return mFirstInstance;
			}
			void set(UInt32 value)
			{
				mFirstInstance = value; 
			}
		}
	};

	public ref class DispatchIndirectCommand
	{
	private:
		UInt32 mX = 0;
		UInt32 mY = 0;
		UInt32 mZ = 0;
	public:
		property UInt32 X
		{
			UInt32 get()
			{
				return mX;
			}
			void set(UInt32 value)
			{
				mX = value; 
			}
		}
		property UInt32 Y
		{
			UInt32 get()
			{
				return mY;
			}
			void set(UInt32 value)
			{
				mY = value; 
			}
		}
		property UInt32 Z
		{
			UInt32 get()
			{
				return mZ;
			}
			void set(UInt32 value)
			{
				mZ = value; 
			}
		}
	};

	public ref class SubmitInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		Semaphore^ mWaitSemaphores = nullptr;
		VkPipelineStageFlags* mWaitDstStageMask;
		UInt32 mCommandBufferCount = 0;
		CommandBuffer^ mCommandBuffers = nullptr;
		UInt32 mSignalSemaphoreCount = 0;
		Semaphore^ mSignalSemaphores = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt32 WaitSemaphoreCount
		{
			UInt32 get()
			{
				return mWaitSemaphoreCount;
			}
			void set(UInt32 value)
			{
				mWaitSemaphoreCount = value; 
			}
		}
		property Semaphore^ WaitSemaphores
		{
			Semaphore^ get()
			{
				return mWaitSemaphores;
			}
			void set(Semaphore^ value)
			{
				mWaitSemaphores = value; 
			}
		}
		property VkPipelineStageFlags* WaitDstStageMask
		{
			VkPipelineStageFlags* get()
			{
				return mWaitDstStageMask;
			}
			void set(VkPipelineStageFlags* value)
			{
				mWaitDstStageMask = value; 
			}
		}
		property UInt32 CommandBufferCount
		{
			UInt32 get()
			{
				return mCommandBufferCount;
			}
			void set(UInt32 value)
			{
				mCommandBufferCount = value; 
			}
		}
		property CommandBuffer^ CommandBuffers
		{
			CommandBuffer^ get()
			{
				return mCommandBuffers;
			}
			void set(CommandBuffer^ value)
			{
				mCommandBuffers = value; 
			}
		}
		property UInt32 SignalSemaphoreCount
		{
			UInt32 get()
			{
				return mSignalSemaphoreCount;
			}
			void set(UInt32 value)
			{
				mSignalSemaphoreCount = value; 
			}
		}
		property Semaphore^ SignalSemaphores
		{
			Semaphore^ get()
			{
				return mSignalSemaphores;
			}
			void set(Semaphore^ value)
			{
				mSignalSemaphores = value; 
			}
		}
	};

	public ref class DisplayPropertiesKHR
	{
	private:
		DisplayKHR^ mDisplay = nullptr;
		String^ mDisplayName = nullptr;
		Extent2D^ mPhysicalDimensions = nullptr;
		Extent2D^ mPhysicalResolution = nullptr;
		VkSurfaceTransformFlagsKHR mSupportedTransforms;
		bool mPlaneReorderPossible = false;
		bool mPersistentContent = false;
	public:
		property DisplayKHR^ Display
		{
			DisplayKHR^ get()
			{
				return mDisplay;
			}
			void set(DisplayKHR^ value)
			{
				mDisplay = value; 
			}
		}
		property String^ DisplayName
		{
			String^ get()
			{
				return mDisplayName;
			}
			void set(String^ value)
			{
				mDisplayName = value; 
			}
		}
		property Extent2D^ PhysicalDimensions
		{
			Extent2D^ get()
			{
				return mPhysicalDimensions;
			}
			void set(Extent2D^ value)
			{
				mPhysicalDimensions = value; 
			}
		}
		property Extent2D^ PhysicalResolution
		{
			Extent2D^ get()
			{
				return mPhysicalResolution;
			}
			void set(Extent2D^ value)
			{
				mPhysicalResolution = value; 
			}
		}
		property VkSurfaceTransformFlagsKHR SupportedTransforms
		{
			VkSurfaceTransformFlagsKHR get()
			{
				return mSupportedTransforms;
			}
			void set(VkSurfaceTransformFlagsKHR value)
			{
				mSupportedTransforms = value; 
			}
		}
		property bool PlaneReorderPossible
		{
			bool get()
			{
				return mPlaneReorderPossible;
			}
			void set(bool value)
			{
				mPlaneReorderPossible = value; 
			}
		}
		property bool PersistentContent
		{
			bool get()
			{
				return mPersistentContent;
			}
			void set(bool value)
			{
				mPersistentContent = value; 
			}
		}
	};

	public ref class DisplayPlanePropertiesKHR
	{
	private:
		DisplayKHR^ mCurrentDisplay = nullptr;
		UInt32 mCurrentStackIndex = 0;
	public:
		property DisplayKHR^ CurrentDisplay
		{
			DisplayKHR^ get()
			{
				return mCurrentDisplay;
			}
			void set(DisplayKHR^ value)
			{
				mCurrentDisplay = value; 
			}
		}
		property UInt32 CurrentStackIndex
		{
			UInt32 get()
			{
				return mCurrentStackIndex;
			}
			void set(UInt32 value)
			{
				mCurrentStackIndex = value; 
			}
		}
	};

	public ref class DisplayModeParametersKHR
	{
	private:
		Extent2D^ mVisibleRegion = nullptr;
		UInt32 mRefreshRate = 0;
	public:
		property Extent2D^ VisibleRegion
		{
			Extent2D^ get()
			{
				return mVisibleRegion;
			}
			void set(Extent2D^ value)
			{
				mVisibleRegion = value; 
			}
		}
		property UInt32 RefreshRate
		{
			UInt32 get()
			{
				return mRefreshRate;
			}
			void set(UInt32 value)
			{
				mRefreshRate = value; 
			}
		}
	};

	public ref class DisplayModePropertiesKHR
	{
	private:
		DisplayModeKHR^ mDisplayMode = nullptr;
		DisplayModeParametersKHR^ mParameters = nullptr;
	public:
		property DisplayModeKHR^ DisplayMode
		{
			DisplayModeKHR^ get()
			{
				return mDisplayMode;
			}
			void set(DisplayModeKHR^ value)
			{
				mDisplayMode = value; 
			}
		}
		property DisplayModeParametersKHR^ Parameters
		{
			DisplayModeParametersKHR^ get()
			{
				return mParameters;
			}
			void set(DisplayModeParametersKHR^ value)
			{
				mParameters = value; 
			}
		}
	};

	public ref class DisplayModeCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		VkDisplayModeCreateFlagsKHR mFlags;
		DisplayModeParametersKHR^ mParameters = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDisplayModeCreateFlagsKHR Flags
		{
			VkDisplayModeCreateFlagsKHR get()
			{
				return mFlags;
			}
			void set(VkDisplayModeCreateFlagsKHR value)
			{
				mFlags = value; 
			}
		}
		property DisplayModeParametersKHR^ Parameters
		{
			DisplayModeParametersKHR^ get()
			{
				return mParameters;
			}
			void set(DisplayModeParametersKHR^ value)
			{
				mParameters = value; 
			}
		}
	};

	public ref class DisplayPlaneCapabilitiesKHR
	{
	private:
		VkDisplayPlaneAlphaFlagsKHR mSupportedAlpha;
		Offset2D^ mMinSrcPosition = nullptr;
		Offset2D^ mMaxSrcPosition = nullptr;
		Extent2D^ mMinSrcExtent = nullptr;
		Extent2D^ mMaxSrcExtent = nullptr;
		Offset2D^ mMinDstPosition = nullptr;
		Offset2D^ mMaxDstPosition = nullptr;
		Extent2D^ mMinDstExtent = nullptr;
		Extent2D^ mMaxDstExtent = nullptr;
	public:
		property VkDisplayPlaneAlphaFlagsKHR SupportedAlpha
		{
			VkDisplayPlaneAlphaFlagsKHR get()
			{
				return mSupportedAlpha;
			}
			void set(VkDisplayPlaneAlphaFlagsKHR value)
			{
				mSupportedAlpha = value; 
			}
		}
		property Offset2D^ MinSrcPosition
		{
			Offset2D^ get()
			{
				return mMinSrcPosition;
			}
			void set(Offset2D^ value)
			{
				mMinSrcPosition = value; 
			}
		}
		property Offset2D^ MaxSrcPosition
		{
			Offset2D^ get()
			{
				return mMaxSrcPosition;
			}
			void set(Offset2D^ value)
			{
				mMaxSrcPosition = value; 
			}
		}
		property Extent2D^ MinSrcExtent
		{
			Extent2D^ get()
			{
				return mMinSrcExtent;
			}
			void set(Extent2D^ value)
			{
				mMinSrcExtent = value; 
			}
		}
		property Extent2D^ MaxSrcExtent
		{
			Extent2D^ get()
			{
				return mMaxSrcExtent;
			}
			void set(Extent2D^ value)
			{
				mMaxSrcExtent = value; 
			}
		}
		property Offset2D^ MinDstPosition
		{
			Offset2D^ get()
			{
				return mMinDstPosition;
			}
			void set(Offset2D^ value)
			{
				mMinDstPosition = value; 
			}
		}
		property Offset2D^ MaxDstPosition
		{
			Offset2D^ get()
			{
				return mMaxDstPosition;
			}
			void set(Offset2D^ value)
			{
				mMaxDstPosition = value; 
			}
		}
		property Extent2D^ MinDstExtent
		{
			Extent2D^ get()
			{
				return mMinDstExtent;
			}
			void set(Extent2D^ value)
			{
				mMinDstExtent = value; 
			}
		}
		property Extent2D^ MaxDstExtent
		{
			Extent2D^ get()
			{
				return mMaxDstExtent;
			}
			void set(Extent2D^ value)
			{
				mMaxDstExtent = value; 
			}
		}
	};

	public ref class DisplaySurfaceCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		VkDisplaySurfaceCreateFlagsKHR mFlags;
		DisplayModeKHR^ mDisplayMode = nullptr;
		UInt32 mPlaneIndex = 0;
		UInt32 mPlaneStackIndex = 0;
		VkSurfaceTransformFlagBitsKHR mTransform;
		float mGlobalAlpha = 0f;
		VkDisplayPlaneAlphaFlagBitsKHR mAlphaMode;
		Extent2D^ mImageExtent = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDisplaySurfaceCreateFlagsKHR Flags
		{
			VkDisplaySurfaceCreateFlagsKHR get()
			{
				return mFlags;
			}
			void set(VkDisplaySurfaceCreateFlagsKHR value)
			{
				mFlags = value; 
			}
		}
		property DisplayModeKHR^ DisplayMode
		{
			DisplayModeKHR^ get()
			{
				return mDisplayMode;
			}
			void set(DisplayModeKHR^ value)
			{
				mDisplayMode = value; 
			}
		}
		property UInt32 PlaneIndex
		{
			UInt32 get()
			{
				return mPlaneIndex;
			}
			void set(UInt32 value)
			{
				mPlaneIndex = value; 
			}
		}
		property UInt32 PlaneStackIndex
		{
			UInt32 get()
			{
				return mPlaneStackIndex;
			}
			void set(UInt32 value)
			{
				mPlaneStackIndex = value; 
			}
		}
		property VkSurfaceTransformFlagBitsKHR Transform
		{
			VkSurfaceTransformFlagBitsKHR get()
			{
				return mTransform;
			}
			void set(VkSurfaceTransformFlagBitsKHR value)
			{
				mTransform = value; 
			}
		}
		property float GlobalAlpha
		{
			float get()
			{
				return mGlobalAlpha;
			}
			void set(float value)
			{
				mGlobalAlpha = value; 
			}
		}
		property VkDisplayPlaneAlphaFlagBitsKHR AlphaMode
		{
			VkDisplayPlaneAlphaFlagBitsKHR get()
			{
				return mAlphaMode;
			}
			void set(VkDisplayPlaneAlphaFlagBitsKHR value)
			{
				mAlphaMode = value; 
			}
		}
		property Extent2D^ ImageExtent
		{
			Extent2D^ get()
			{
				return mImageExtent;
			}
			void set(Extent2D^ value)
			{
				mImageExtent = value; 
			}
		}
	};

	public ref class DisplayPresentInfoKHR
	{
	private:
		VkStructureType mSType;
		Rect2D^ mSrcRect = nullptr;
		Rect2D^ mDstRect = nullptr;
		bool mPersistent = false;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property Rect2D^ SrcRect
		{
			Rect2D^ get()
			{
				return mSrcRect;
			}
			void set(Rect2D^ value)
			{
				mSrcRect = value; 
			}
		}
		property Rect2D^ DstRect
		{
			Rect2D^ get()
			{
				return mDstRect;
			}
			void set(Rect2D^ value)
			{
				mDstRect = value; 
			}
		}
		property bool Persistent
		{
			bool get()
			{
				return mPersistent;
			}
			void set(bool value)
			{
				mPersistent = value; 
			}
		}
	};

	public ref class SurfaceCapabilitiesKHR
	{
	private:
		UInt32 mMinImageCount = 0;
		UInt32 mMaxImageCount = 0;
		Extent2D^ mCurrentExtent = nullptr;
		Extent2D^ mMinImageExtent = nullptr;
		Extent2D^ mMaxImageExtent = nullptr;
		UInt32 mMaxImageArrayLayers = 0;
		VkSurfaceTransformFlagsKHR mSupportedTransforms;
		VkSurfaceTransformFlagBitsKHR mCurrentTransform;
		VkCompositeAlphaFlagsKHR mSupportedCompositeAlpha;
		VkImageUsageFlags mSupportedUsageFlags;
	public:
		property UInt32 MinImageCount
		{
			UInt32 get()
			{
				return mMinImageCount;
			}
			void set(UInt32 value)
			{
				mMinImageCount = value; 
			}
		}
		property UInt32 MaxImageCount
		{
			UInt32 get()
			{
				return mMaxImageCount;
			}
			void set(UInt32 value)
			{
				mMaxImageCount = value; 
			}
		}
		property Extent2D^ CurrentExtent
		{
			Extent2D^ get()
			{
				return mCurrentExtent;
			}
			void set(Extent2D^ value)
			{
				mCurrentExtent = value; 
			}
		}
		property Extent2D^ MinImageExtent
		{
			Extent2D^ get()
			{
				return mMinImageExtent;
			}
			void set(Extent2D^ value)
			{
				mMinImageExtent = value; 
			}
		}
		property Extent2D^ MaxImageExtent
		{
			Extent2D^ get()
			{
				return mMaxImageExtent;
			}
			void set(Extent2D^ value)
			{
				mMaxImageExtent = value; 
			}
		}
		property UInt32 MaxImageArrayLayers
		{
			UInt32 get()
			{
				return mMaxImageArrayLayers;
			}
			void set(UInt32 value)
			{
				mMaxImageArrayLayers = value; 
			}
		}
		property VkSurfaceTransformFlagsKHR SupportedTransforms
		{
			VkSurfaceTransformFlagsKHR get()
			{
				return mSupportedTransforms;
			}
			void set(VkSurfaceTransformFlagsKHR value)
			{
				mSupportedTransforms = value; 
			}
		}
		property VkSurfaceTransformFlagBitsKHR CurrentTransform
		{
			VkSurfaceTransformFlagBitsKHR get()
			{
				return mCurrentTransform;
			}
			void set(VkSurfaceTransformFlagBitsKHR value)
			{
				mCurrentTransform = value; 
			}
		}
		property VkCompositeAlphaFlagsKHR SupportedCompositeAlpha
		{
			VkCompositeAlphaFlagsKHR get()
			{
				return mSupportedCompositeAlpha;
			}
			void set(VkCompositeAlphaFlagsKHR value)
			{
				mSupportedCompositeAlpha = value; 
			}
		}
		property VkImageUsageFlags SupportedUsageFlags
		{
			VkImageUsageFlags get()
			{
				return mSupportedUsageFlags;
			}
			void set(VkImageUsageFlags value)
			{
				mSupportedUsageFlags = value; 
			}
		}
	};

	public ref class Win32SurfaceCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		VkWin32SurfaceCreateFlagsKHR mFlags;
		HINSTANCE mHinstance;
		HWND mHwnd;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkWin32SurfaceCreateFlagsKHR Flags
		{
			VkWin32SurfaceCreateFlagsKHR get()
			{
				return mFlags;
			}
			void set(VkWin32SurfaceCreateFlagsKHR value)
			{
				mFlags = value; 
			}
		}
		property HINSTANCE Hinstance
		{
			HINSTANCE get()
			{
				return mHinstance;
			}
			void set(HINSTANCE value)
			{
				mHinstance = value; 
			}
		}
		property HWND Hwnd
		{
			HWND get()
			{
				return mHwnd;
			}
			void set(HWND value)
			{
				mHwnd = value; 
			}
		}
	};

	public ref class SurfaceFormatKHR
	{
	private:
		VkFormat mFormat;
		VkColorSpaceKHR mColorSpace;
	public:
		property VkFormat Format
		{
			VkFormat get()
			{
				return mFormat;
			}
			void set(VkFormat value)
			{
				mFormat = value; 
			}
		}
		property VkColorSpaceKHR ColorSpace
		{
			VkColorSpaceKHR get()
			{
				return mColorSpace;
			}
			void set(VkColorSpaceKHR value)
			{
				mColorSpace = value; 
			}
		}
	};

	public ref class SwapchainCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		VkSwapchainCreateFlagsKHR mFlags;
		SurfaceKHR^ mSurface = nullptr;
		UInt32 mMinImageCount = 0;
		VkFormat mImageFormat;
		VkColorSpaceKHR mImageColorSpace;
		Extent2D^ mImageExtent = nullptr;
		UInt32 mImageArrayLayers = 0;
		VkImageUsageFlags mImageUsage;
		VkSharingMode mImageSharingMode;
		UInt32 mQueueFamilyIndexCount = 0;
		UInt32 mQueueFamilyIndices = 0;
		VkSurfaceTransformFlagBitsKHR mPreTransform;
		VkCompositeAlphaFlagBitsKHR mCompositeAlpha;
		VkPresentModeKHR mPresentMode;
		bool mClipped = false;
		SwapchainKHR^ mOldSwapchain = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkSwapchainCreateFlagsKHR Flags
		{
			VkSwapchainCreateFlagsKHR get()
			{
				return mFlags;
			}
			void set(VkSwapchainCreateFlagsKHR value)
			{
				mFlags = value; 
			}
		}
		property SurfaceKHR^ Surface
		{
			SurfaceKHR^ get()
			{
				return mSurface;
			}
			void set(SurfaceKHR^ value)
			{
				mSurface = value; 
			}
		}
		property UInt32 MinImageCount
		{
			UInt32 get()
			{
				return mMinImageCount;
			}
			void set(UInt32 value)
			{
				mMinImageCount = value; 
			}
		}
		property VkFormat ImageFormat
		{
			VkFormat get()
			{
				return mImageFormat;
			}
			void set(VkFormat value)
			{
				mImageFormat = value; 
			}
		}
		property VkColorSpaceKHR ImageColorSpace
		{
			VkColorSpaceKHR get()
			{
				return mImageColorSpace;
			}
			void set(VkColorSpaceKHR value)
			{
				mImageColorSpace = value; 
			}
		}
		property Extent2D^ ImageExtent
		{
			Extent2D^ get()
			{
				return mImageExtent;
			}
			void set(Extent2D^ value)
			{
				mImageExtent = value; 
			}
		}
		property UInt32 ImageArrayLayers
		{
			UInt32 get()
			{
				return mImageArrayLayers;
			}
			void set(UInt32 value)
			{
				mImageArrayLayers = value; 
			}
		}
		property VkImageUsageFlags ImageUsage
		{
			VkImageUsageFlags get()
			{
				return mImageUsage;
			}
			void set(VkImageUsageFlags value)
			{
				mImageUsage = value; 
			}
		}
		property VkSharingMode ImageSharingMode
		{
			VkSharingMode get()
			{
				return mImageSharingMode;
			}
			void set(VkSharingMode value)
			{
				mImageSharingMode = value; 
			}
		}
		property UInt32 QueueFamilyIndexCount
		{
			UInt32 get()
			{
				return mQueueFamilyIndexCount;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndexCount = value; 
			}
		}
		property UInt32 QueueFamilyIndices
		{
			UInt32 get()
			{
				return mQueueFamilyIndices;
			}
			void set(UInt32 value)
			{
				mQueueFamilyIndices = value; 
			}
		}
		property VkSurfaceTransformFlagBitsKHR PreTransform
		{
			VkSurfaceTransformFlagBitsKHR get()
			{
				return mPreTransform;
			}
			void set(VkSurfaceTransformFlagBitsKHR value)
			{
				mPreTransform = value; 
			}
		}
		property VkCompositeAlphaFlagBitsKHR CompositeAlpha
		{
			VkCompositeAlphaFlagBitsKHR get()
			{
				return mCompositeAlpha;
			}
			void set(VkCompositeAlphaFlagBitsKHR value)
			{
				mCompositeAlpha = value; 
			}
		}
		property VkPresentModeKHR PresentMode
		{
			VkPresentModeKHR get()
			{
				return mPresentMode;
			}
			void set(VkPresentModeKHR value)
			{
				mPresentMode = value; 
			}
		}
		property bool Clipped
		{
			bool get()
			{
				return mClipped;
			}
			void set(bool value)
			{
				mClipped = value; 
			}
		}
		property SwapchainKHR^ OldSwapchain
		{
			SwapchainKHR^ get()
			{
				return mOldSwapchain;
			}
			void set(SwapchainKHR^ value)
			{
				mOldSwapchain = value; 
			}
		}
	};

	public ref class PresentInfoKHR
	{
	private:
		VkStructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		Semaphore^ mWaitSemaphores = nullptr;
		UInt32 mSwapchainCount = 0;
		SwapchainKHR^ mSwapchains = nullptr;
		UInt32 mImageIndices = 0;
		array<VkResult>^ mResults = nullptr;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt32 WaitSemaphoreCount
		{
			UInt32 get()
			{
				return mWaitSemaphoreCount;
			}
			void set(UInt32 value)
			{
				mWaitSemaphoreCount = value; 
			}
		}
		property Semaphore^ WaitSemaphores
		{
			Semaphore^ get()
			{
				return mWaitSemaphores;
			}
			void set(Semaphore^ value)
			{
				mWaitSemaphores = value; 
			}
		}
		property UInt32 SwapchainCount
		{
			UInt32 get()
			{
				return mSwapchainCount;
			}
			void set(UInt32 value)
			{
				mSwapchainCount = value; 
			}
		}
		property SwapchainKHR^ Swapchains
		{
			SwapchainKHR^ get()
			{
				return mSwapchains;
			}
			void set(SwapchainKHR^ value)
			{
				mSwapchains = value; 
			}
		}
		property UInt32 ImageIndices
		{
			UInt32 get()
			{
				return mImageIndices;
			}
			void set(UInt32 value)
			{
				mImageIndices = value; 
			}
		}
		property array<VkResult>^ Results
		{
			array<VkResult>^ get()
			{
				return mResults;
			}
			void set(array<VkResult>^ value)
			{
				mResults = value; 
			}
		}
	};

	public ref class DebugReportCallbackCreateInfoEXT
	{
	private:
		VkStructureType mSType;
		VkDebugReportFlagsEXT mFlags;
		PFN_vkDebugReportCallbackEXT mPfnCallback;
		IntPtr mUserData = IntPtr.Zero;
	public:
		property VkStructureType SType
		{
			VkStructureType get()
			{
				return mSType;
			}
			void set(VkStructureType value)
			{
				mSType = value; 
			}
		}
		property VkDebugReportFlagsEXT Flags
		{
			VkDebugReportFlagsEXT get()
			{
				return mFlags;
			}
			void set(VkDebugReportFlagsEXT value)
			{
				mFlags = value; 
			}
		}
		property PFN_vkDebugReportCallbackEXT PfnCallback
		{
			PFN_vkDebugReportCallbackEXT get()
			{
				return mPfnCallback;
			}
			void set(PFN_vkDebugReportCallbackEXT value)
			{
				mPfnCallback = value; 
			}
		}
		property IntPtr UserData
		{
			IntPtr get()
			{
				return mUserData;
			}
			void set(IntPtr value)
			{
				mUserData = value; 
			}
		}
	};

}