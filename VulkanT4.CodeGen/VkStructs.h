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
	internal:
		void CopyTo(VkOffset2D* dst, List<IntPtr>^ pins)
		{
			dst->x =	mX;
			dst->y =	mY;
		}

		void CopyFrom(VkOffset2D* src)
		{
			mX = src->x;
			mY = src->y;
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
	internal:
		void CopyTo(VkOffset3D* dst, List<IntPtr>^ pins)
		{
			dst->x =	mX;
			dst->y =	mY;
			dst->z =	mZ;
		}

		void CopyFrom(VkOffset3D* src)
		{
			mX = src->x;
			mY = src->y;
			mZ = src->z;
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
	internal:
		void CopyTo(VkExtent2D* dst, List<IntPtr>^ pins)
		{
			dst->width =	mWidth;
			dst->height =	mHeight;
		}

		void CopyFrom(VkExtent2D* src)
		{
			mWidth = src->width;
			mHeight = src->height;
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
	internal:
		void CopyTo(VkExtent3D* dst, List<IntPtr>^ pins)
		{
			dst->width =	mWidth;
			dst->height =	mHeight;
			dst->depth =	mDepth;
		}

		void CopyFrom(VkExtent3D* src)
		{
			mWidth = src->width;
			mHeight = src->height;
			mDepth = src->depth;
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
	internal:
		void CopyTo(VkViewport* dst, List<IntPtr>^ pins)
		{
			dst->x =	mX;
			dst->y =	mY;
			dst->width =	mWidth;
			dst->height =	mHeight;
			dst->minDepth =	mMinDepth;
			dst->maxDepth =	mMaxDepth;
		}

		void CopyFrom(VkViewport* src)
		{
			mX = src->x;
			mY = src->y;
			mWidth = src->width;
			mHeight = src->height;
			mMinDepth = src->minDepth;
			mMaxDepth = src->maxDepth;
		}
	};

	public ref class Rect2D
	{
	private:
		Offset2D^ mOffset = gcnew Offset2D();
		Extent2D^ mExtent = gcnew Extent2D();
	public:
		property ManagedVulkan::Offset2D^ Offset
		{
			ManagedVulkan::Offset2D^ get()
			{
				return mOffset;
			}
			void set(ManagedVulkan::Offset2D^ value)
			{
				mOffset = value; 
			}
		}
		property ManagedVulkan::Extent2D^ Extent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mExtent = value; 
			}
		}
	internal:
		void CopyTo(VkRect2D* dst, List<IntPtr>^ pins)
		{
			mOffset->CopyFrom(&dst->offset, pins);
			mExtent->CopyFrom(&dst->extent, pins);
		}

		void CopyFrom(VkRect2D* src)
		{
			mOffset->CopyTo(&src->offset);
			mExtent->CopyTo(&src->extent);
		}
	};

	public ref class Rect3D
	{
	private:
		Offset3D^ mOffset = gcnew Offset3D();
		Extent3D^ mExtent = gcnew Extent3D();
	public:
		property ManagedVulkan::Offset3D^ Offset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mOffset = value; 
			}
		}
		property ManagedVulkan::Extent3D^ Extent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mExtent = value; 
			}
		}
	internal:
		void CopyTo(VkRect3D* dst, List<IntPtr>^ pins)
		{
			mOffset->CopyFrom(&dst->offset, pins);
			mExtent->CopyFrom(&dst->extent, pins);
		}

		void CopyFrom(VkRect3D* src)
		{
			mOffset->CopyTo(&src->offset);
			mExtent->CopyTo(&src->extent);
		}
	};

	public ref class ClearRect
	{
	private:
		Rect2D^ mRect = gcnew Rect2D();
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property ManagedVulkan::Rect2D^ Rect
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mRect;
			}
			void set(ManagedVulkan::Rect2D^ value)
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
	internal:
		void CopyTo(VkClearRect* dst, List<IntPtr>^ pins)
		{
			mRect->CopyFrom(&dst->rect, pins);
			dst->baseArrayLayer =	mBaseArrayLayer;
			dst->layerCount =	mLayerCount;
		}

		void CopyFrom(VkClearRect* src)
		{
			mRect->CopyTo(&src->rect);
			mBaseArrayLayer = src->baseArrayLayer;
			mLayerCount = src->layerCount;
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
		property ManagedVulkan::VkComponentSwizzle R
		{
			ManagedVulkan::VkComponentSwizzle get()
			{
				return mR;
			}
			void set(ManagedVulkan::VkComponentSwizzle value)
			{
				mR = value; 
			}
		}
		property ManagedVulkan::VkComponentSwizzle G
		{
			ManagedVulkan::VkComponentSwizzle get()
			{
				return mG;
			}
			void set(ManagedVulkan::VkComponentSwizzle value)
			{
				mG = value; 
			}
		}
		property ManagedVulkan::VkComponentSwizzle B
		{
			ManagedVulkan::VkComponentSwizzle get()
			{
				return mB;
			}
			void set(ManagedVulkan::VkComponentSwizzle value)
			{
				mB = value; 
			}
		}
		property ManagedVulkan::VkComponentSwizzle A
		{
			ManagedVulkan::VkComponentSwizzle get()
			{
				return mA;
			}
			void set(ManagedVulkan::VkComponentSwizzle value)
			{
				mA = value; 
			}
		}
	internal:
		void CopyTo(VkComponentMapping* dst, List<IntPtr>^ pins)
		{
			dst->r =	mR;
			dst->g =	mG;
			dst->b =	mB;
			dst->a =	mA;
		}

		void CopyFrom(VkComponentMapping* src)
		{
			mR = src->r;
			mG = src->g;
			mB = src->b;
			mA = src->a;
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
		array<Byte>^ mPipelineCacheUUID = nullptr;
		PhysicalDeviceLimits^ mLimits = gcnew PhysicalDeviceLimits();
		PhysicalDeviceSparseProperties^ mSparseProperties = gcnew PhysicalDeviceSparseProperties();
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
		property ManagedVulkan::VkPhysicalDeviceType DeviceType
		{
			ManagedVulkan::VkPhysicalDeviceType get()
			{
				return mDeviceType;
			}
			void set(ManagedVulkan::VkPhysicalDeviceType value)
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
		property array<Byte>^ PipelineCacheUUID
		{
			array<Byte>^ get()
			{
				return mPipelineCacheUUID;
			}
			void set(array<Byte>^ value)
			{
				mPipelineCacheUUID = value; 
			}
		}
		property ManagedVulkan::PhysicalDeviceLimits^ Limits
		{
			ManagedVulkan::PhysicalDeviceLimits^ get()
			{
				return mLimits;
			}
			void set(ManagedVulkan::PhysicalDeviceLimits^ value)
			{
				mLimits = value; 
			}
		}
		property ManagedVulkan::PhysicalDeviceSparseProperties^ SparseProperties
		{
			ManagedVulkan::PhysicalDeviceSparseProperties^ get()
			{
				return mSparseProperties;
			}
			void set(ManagedVulkan::PhysicalDeviceSparseProperties^ value)
			{
				mSparseProperties = value; 
			}
		}
	internal:
		void CopyTo(VkPhysicalDeviceProperties* dst, List<IntPtr>^ pins)
		{
			dst->apiVersion =	mApiVersion;
			dst->driverVersion =	mDriverVersion;
			dst->vendorID =	mVendorID;
			dst->deviceID =	mDeviceID;
			dst->deviceType =	mDeviceType;

			IntPtr str_deviceName = Marshal::StringToHGlobalAnsi(mDeviceName);
			pins->Add(str_deviceName);			
			dst->deviceName = static_cast <char*> (str_deviceName.ToPointer());

			dst->pipelineCacheUUID =	mPipelineCacheUUID;
			mLimits->CopyFrom(&dst->limits, pins);
			mSparseProperties->CopyFrom(&dst->sparseProperties, pins);
		}

		void CopyFrom(VkPhysicalDeviceProperties* src)
		{
			mApiVersion = src->apiVersion;
			mDriverVersion = src->driverVersion;
			mVendorID = src->vendorID;
			mDeviceID = src->deviceID;
			mDeviceType = src->deviceType;
			mDeviceName = src->deviceName;
			mPipelineCacheUUID = src->pipelineCacheUUID;
			mLimits->CopyTo(&src->limits);
			mSparseProperties->CopyTo(&src->sparseProperties);
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
	internal:
		void CopyTo(VkExtensionProperties* dst, List<IntPtr>^ pins)
		{

			IntPtr str_extensionName = Marshal::StringToHGlobalAnsi(mExtensionName);
			pins->Add(str_extensionName);			
			dst->extensionName = static_cast <char*> (str_extensionName.ToPointer());

			dst->specVersion =	mSpecVersion;
		}

		void CopyFrom(VkExtensionProperties* src)
		{
			mExtensionName = src->extensionName;
			mSpecVersion = src->specVersion;
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
	internal:
		void CopyTo(VkLayerProperties* dst, List<IntPtr>^ pins)
		{

			IntPtr str_layerName = Marshal::StringToHGlobalAnsi(mLayerName);
			pins->Add(str_layerName);			
			dst->layerName = static_cast <char*> (str_layerName.ToPointer());

			dst->specVersion =	mSpecVersion;
			dst->implementationVersion =	mImplementationVersion;

			IntPtr str_description = Marshal::StringToHGlobalAnsi(mDescription);
			pins->Add(str_description);			
			dst->description = static_cast <char*> (str_description.ToPointer());

		}

		void CopyFrom(VkLayerProperties* src)
		{
			mLayerName = src->layerName;
			mSpecVersion = src->specVersion;
			mImplementationVersion = src->implementationVersion;
			mDescription = src->description;
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
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
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
	internal:
		void CopyTo(VkApplicationInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;

			IntPtr str_pApplicationName = Marshal::StringToHGlobalAnsi(mApplicationName);
			pins->Add(str_pApplicationName);			
			dst->pApplicationName = static_cast <char*> (str_pApplicationName.ToPointer());

			dst->applicationVersion =	mApplicationVersion;

			IntPtr str_pEngineName = Marshal::StringToHGlobalAnsi(mEngineName);
			pins->Add(str_pEngineName);			
			dst->pEngineName = static_cast <char*> (str_pEngineName.ToPointer());

			dst->engineVersion =	mEngineVersion;
			dst->apiVersion =	mApiVersion;
		}

		void CopyFrom(VkApplicationInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mApplicationName = gcnew String(mApplicationName);
			mApplicationVersion = src->applicationVersion;
			mEngineName = gcnew String(mEngineName);
			mEngineVersion = src->engineVersion;
			mApiVersion = src->apiVersion;
		}
	};

	public ref class AllocationCallbacks
	{
	private:
		IntPtr mUserData = IntPtr::Zero;
		PFN_vkAllocationFunction^ mPfnAllocation = nullptr;
		PFN_vkReallocationFunction^ mPfnReallocation = nullptr;
		PFN_vkFreeFunction^ mPfnFree = nullptr;
		PFN_vkInternalAllocationNotification^ mPfnInternalAllocation = nullptr;
		PFN_vkInternalFreeNotification^ mPfnInternalFree = nullptr;
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
		property ManagedVulkan::PFN_vkAllocationFunction^ PfnAllocation
		{
			ManagedVulkan::PFN_vkAllocationFunction^ get()
			{
				return mPfnAllocation;
			}
			void set(ManagedVulkan::PFN_vkAllocationFunction^ value)
			{
				mPfnAllocation = value; 
			}
		}
		property ManagedVulkan::PFN_vkReallocationFunction^ PfnReallocation
		{
			ManagedVulkan::PFN_vkReallocationFunction^ get()
			{
				return mPfnReallocation;
			}
			void set(ManagedVulkan::PFN_vkReallocationFunction^ value)
			{
				mPfnReallocation = value; 
			}
		}
		property ManagedVulkan::PFN_vkFreeFunction^ PfnFree
		{
			ManagedVulkan::PFN_vkFreeFunction^ get()
			{
				return mPfnFree;
			}
			void set(ManagedVulkan::PFN_vkFreeFunction^ value)
			{
				mPfnFree = value; 
			}
		}
		property ManagedVulkan::PFN_vkInternalAllocationNotification^ PfnInternalAllocation
		{
			ManagedVulkan::PFN_vkInternalAllocationNotification^ get()
			{
				return mPfnInternalAllocation;
			}
			void set(ManagedVulkan::PFN_vkInternalAllocationNotification^ value)
			{
				mPfnInternalAllocation = value; 
			}
		}
		property ManagedVulkan::PFN_vkInternalFreeNotification^ PfnInternalFree
		{
			ManagedVulkan::PFN_vkInternalFreeNotification^ get()
			{
				return mPfnInternalFree;
			}
			void set(ManagedVulkan::PFN_vkInternalFreeNotification^ value)
			{
				mPfnInternalFree = value; 
			}
		}
	internal:
		void CopyTo(VkAllocationCallbacks* dst, List<IntPtr>^ pins)
		{
			dst->pUserData =	mUserData;
			dst->pfnAllocation =	mPfnAllocation;
			dst->pfnReallocation =	mPfnReallocation;
			dst->pfnFree =	mPfnFree;
			dst->pfnInternalAllocation =	mPfnInternalAllocation;
			dst->pfnInternalFree =	mPfnInternalFree;
		}

		void CopyFrom(VkAllocationCallbacks* src)
		{
			mUserData = src->pUserData;
			mPfnAllocation = src->pfnAllocation;
			mPfnReallocation = src->pfnReallocation;
			mPfnFree = src->pfnFree;
			mPfnInternalAllocation = src->pfnInternalAllocation;
			mPfnInternalFree = src->pfnInternalFree;
		}
	};

	public ref class DeviceQueueCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mQueueFamilyIndex = 0;
		UInt32 mQueueCount = 0;
		float mQueuePriorities = 0f;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkDeviceQueueCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->queueFamilyIndex =	mQueueFamilyIndex;
			dst->queueCount =	mQueueCount;
			dst->pQueuePriorities =	mQueuePriorities;
		}

		void CopyFrom(VkDeviceQueueCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mQueueFamilyIndex = src->queueFamilyIndex;
			mQueueCount = src->queueCount;
			mQueuePriorities = src->pQueuePriorities;
		}
	};

	public ref class DeviceCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mQueueCreateInfoCount = 0;
		DeviceQueueCreateInfo^ mQueueCreateInfos = gcnew DeviceQueueCreateInfo();
		UInt32 mEnabledLayerCount = 0;
		array<String^>^ mEnabledLayerNames = nullptr;
		UInt32 mEnabledExtensionCount = 0;
		array<String^>^ mEnabledExtensionNames = nullptr;
		PhysicalDeviceFeatures^ mEnabledFeatures = gcnew PhysicalDeviceFeatures();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::DeviceQueueCreateInfo^ QueueCreateInfos
		{
			ManagedVulkan::DeviceQueueCreateInfo^ get()
			{
				return mQueueCreateInfos;
			}
			void set(ManagedVulkan::DeviceQueueCreateInfo^ value)
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
		property ManagedVulkan::PhysicalDeviceFeatures^ EnabledFeatures
		{
			ManagedVulkan::PhysicalDeviceFeatures^ get()
			{
				return mEnabledFeatures;
			}
			void set(ManagedVulkan::PhysicalDeviceFeatures^ value)
			{
				mEnabledFeatures = value; 
			}
		}
	internal:
		void CopyTo(VkDeviceCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->queueCreateInfoCount =	mQueueCreateInfoCount;
			mQueueCreateInfos->CopyFrom(&dst->pQueueCreateInfos, pins);
			dst->enabledLayerCount =	mEnabledLayerCount;
			dst->ppEnabledLayerNames =	mEnabledLayerNames;
			dst->enabledExtensionCount =	mEnabledExtensionCount;
			dst->ppEnabledExtensionNames =	mEnabledExtensionNames;
			mEnabledFeatures->CopyFrom(&dst->pEnabledFeatures, pins);
		}

		void CopyFrom(VkDeviceCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mQueueCreateInfoCount = src->queueCreateInfoCount;
			mQueueCreateInfos->CopyTo(&src->pQueueCreateInfos);
			mEnabledLayerCount = src->enabledLayerCount;
			mEnabledLayerNames = src->ppEnabledLayerNames;
			mEnabledExtensionCount = src->enabledExtensionCount;
			mEnabledExtensionNames = src->ppEnabledExtensionNames;
			mEnabledFeatures->CopyTo(&src->pEnabledFeatures);
		}
	};

	public ref class InstanceCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		ApplicationInfo^ mApplicationInfo = gcnew ApplicationInfo();
		UInt32 mEnabledLayerCount = 0;
		array<String^>^ mEnabledLayerNames = nullptr;
		UInt32 mEnabledExtensionCount = 0;
		array<String^>^ mEnabledExtensionNames = nullptr;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::ApplicationInfo^ ApplicationInfo
		{
			ManagedVulkan::ApplicationInfo^ get()
			{
				return mApplicationInfo;
			}
			void set(ManagedVulkan::ApplicationInfo^ value)
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
	internal:
		void CopyTo(VkInstanceCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			mApplicationInfo->CopyFrom(&dst->pApplicationInfo, pins);
			dst->enabledLayerCount =	mEnabledLayerCount;
			dst->ppEnabledLayerNames =	mEnabledLayerNames;
			dst->enabledExtensionCount =	mEnabledExtensionCount;
			dst->ppEnabledExtensionNames =	mEnabledExtensionNames;
		}

		void CopyFrom(VkInstanceCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mApplicationInfo->CopyTo(&src->pApplicationInfo);
			mEnabledLayerCount = src->enabledLayerCount;
			mEnabledLayerNames = src->ppEnabledLayerNames;
			mEnabledExtensionCount = src->enabledExtensionCount;
			mEnabledExtensionNames = src->ppEnabledExtensionNames;
		}
	};

	public ref class QueueFamilyProperties
	{
	private:
		UInt32 mQueueFlags;
		UInt32 mQueueCount = 0;
		UInt32 mTimestampValidBits = 0;
		Extent3D^ mMinImageTransferGranularity = gcnew Extent3D();
	public:
		property UInt32 QueueFlags
		{
			UInt32 get()
			{
				return mQueueFlags;
			}
			void set(UInt32 value)
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
		property ManagedVulkan::Extent3D^ MinImageTransferGranularity
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mMinImageTransferGranularity;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mMinImageTransferGranularity = value; 
			}
		}
	internal:
		void CopyTo(VkQueueFamilyProperties* dst, List<IntPtr>^ pins)
		{
			dst->queueFlags =	mQueueFlags;
			dst->queueCount =	mQueueCount;
			dst->timestampValidBits =	mTimestampValidBits;
			mMinImageTransferGranularity->CopyFrom(&dst->minImageTransferGranularity, pins);
		}

		void CopyFrom(VkQueueFamilyProperties* src)
		{
			mQueueFlags = src->queueFlags;
			mQueueCount = src->queueCount;
			mTimestampValidBits = src->timestampValidBits;
			mMinImageTransferGranularity->CopyTo(&src->minImageTransferGranularity);
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
	internal:
		void CopyTo(VkPhysicalDeviceMemoryProperties* dst, List<IntPtr>^ pins)
		{
			dst->memoryTypeCount =	mMemoryTypeCount;
			dst->VK_MAX_MEMORY_TYPES =	mVK_MAX_MEMORY_TYPES;
			dst->memoryHeapCount =	mMemoryHeapCount;
			dst->VK_MAX_MEMORY_HEAPS =	mVK_MAX_MEMORY_HEAPS;
		}

		void CopyFrom(VkPhysicalDeviceMemoryProperties* src)
		{
			mMemoryTypeCount = src->memoryTypeCount;
			mVK_MAX_MEMORY_TYPES = src->VK_MAX_MEMORY_TYPES;
			mMemoryHeapCount = src->memoryHeapCount;
			mVK_MAX_MEMORY_HEAPS = src->VK_MAX_MEMORY_HEAPS;
		}
	};

	public ref class MemoryAllocateInfo
	{
	private:
		VkStructureType mSType;
		UInt64 mAllocationSize = 0;
		UInt32 mMemoryTypeIndex = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
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
	internal:
		void CopyTo(VkMemoryAllocateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->allocationSize =	mAllocationSize;
			dst->memoryTypeIndex =	mMemoryTypeIndex;
		}

		void CopyFrom(VkMemoryAllocateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mAllocationSize = src->allocationSize;
			mMemoryTypeIndex = src->memoryTypeIndex;
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
	internal:
		void CopyTo(VkMemoryRequirements* dst, List<IntPtr>^ pins)
		{
			dst->size =	mSize;
			dst->alignment =	mAlignment;
			dst->memoryTypeBits =	mMemoryTypeBits;
		}

		void CopyFrom(VkMemoryRequirements* src)
		{
			mSize = src->size;
			mAlignment = src->alignment;
			mMemoryTypeBits = src->memoryTypeBits;
		}
	};

	public ref class SparseImageFormatProperties
	{
	private:
		UInt32 mAspectMask;
		Extent3D^ mImageGranularity = gcnew Extent3D();
		UInt32 mFlags;
	public:
		property UInt32 AspectMask
		{
			UInt32 get()
			{
				return mAspectMask;
			}
			void set(UInt32 value)
			{
				mAspectMask = value; 
			}
		}
		property ManagedVulkan::Extent3D^ ImageGranularity
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mImageGranularity;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mImageGranularity = value; 
			}
		}
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
	internal:
		void CopyTo(VkSparseImageFormatProperties* dst, List<IntPtr>^ pins)
		{
			dst->aspectMask =	mAspectMask;
			mImageGranularity->CopyFrom(&dst->imageGranularity, pins);
			dst->flags =	mFlags;
		}

		void CopyFrom(VkSparseImageFormatProperties* src)
		{
			mAspectMask = src->aspectMask;
			mImageGranularity->CopyTo(&src->imageGranularity);
			mFlags = src->flags;
		}
	};

	public ref class SparseImageMemoryRequirements
	{
	private:
		SparseImageFormatProperties^ mFormatProperties = gcnew SparseImageFormatProperties();
		UInt32 mImageMipTailFirstLod = 0;
		UInt64 mImageMipTailSize = 0;
		UInt64 mImageMipTailOffset = 0;
		UInt64 mImageMipTailStride = 0;
	public:
		property ManagedVulkan::SparseImageFormatProperties^ FormatProperties
		{
			ManagedVulkan::SparseImageFormatProperties^ get()
			{
				return mFormatProperties;
			}
			void set(ManagedVulkan::SparseImageFormatProperties^ value)
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
	internal:
		void CopyTo(VkSparseImageMemoryRequirements* dst, List<IntPtr>^ pins)
		{
			mFormatProperties->CopyFrom(&dst->formatProperties, pins);
			dst->imageMipTailFirstLod =	mImageMipTailFirstLod;
			dst->imageMipTailSize =	mImageMipTailSize;
			dst->imageMipTailOffset =	mImageMipTailOffset;
			dst->imageMipTailStride =	mImageMipTailStride;
		}

		void CopyFrom(VkSparseImageMemoryRequirements* src)
		{
			mFormatProperties->CopyTo(&src->formatProperties);
			mImageMipTailFirstLod = src->imageMipTailFirstLod;
			mImageMipTailSize = src->imageMipTailSize;
			mImageMipTailOffset = src->imageMipTailOffset;
			mImageMipTailStride = src->imageMipTailStride;
		}
	};

	public ref class MemoryType
	{
	private:
		UInt32 mPropertyFlags;
		UInt32 mHeapIndex = 0;
	public:
		property UInt32 PropertyFlags
		{
			UInt32 get()
			{
				return mPropertyFlags;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkMemoryType* dst, List<IntPtr>^ pins)
		{
			dst->propertyFlags =	mPropertyFlags;
			dst->heapIndex =	mHeapIndex;
		}

		void CopyFrom(VkMemoryType* src)
		{
			mPropertyFlags = src->propertyFlags;
			mHeapIndex = src->heapIndex;
		}
	};

	public ref class MemoryHeap
	{
	private:
		UInt64 mSize = 0;
		UInt32 mFlags;
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
	internal:
		void CopyTo(VkMemoryHeap* dst, List<IntPtr>^ pins)
		{
			dst->size =	mSize;
			dst->flags =	mFlags;
		}

		void CopyFrom(VkMemoryHeap* src)
		{
			mSize = src->size;
			mFlags = src->flags;
		}
	};

	public ref class MappedMemoryRange
	{
	private:
		VkStructureType mSType;
		DeviceMemory^ mMemory = gcnew DeviceMemory();
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::DeviceMemory^ Memory
		{
			ManagedVulkan::DeviceMemory^ get()
			{
				return mMemory;
			}
			void set(ManagedVulkan::DeviceMemory^ value)
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
	internal:
		void CopyTo(VkMappedMemoryRange* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->memory =	mMemory;
			dst->offset =	mOffset;
			dst->size =	mSize;
		}

		void CopyFrom(VkMappedMemoryRange* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mMemory = src->memory;
			mOffset = src->offset;
			mSize = src->size;
		}
	};

	public ref class FormatProperties
	{
	private:
		UInt32 mLinearTilingFeatures;
		UInt32 mOptimalTilingFeatures;
		UInt32 mBufferFeatures;
	public:
		property UInt32 LinearTilingFeatures
		{
			UInt32 get()
			{
				return mLinearTilingFeatures;
			}
			void set(UInt32 value)
			{
				mLinearTilingFeatures = value; 
			}
		}
		property UInt32 OptimalTilingFeatures
		{
			UInt32 get()
			{
				return mOptimalTilingFeatures;
			}
			void set(UInt32 value)
			{
				mOptimalTilingFeatures = value; 
			}
		}
		property UInt32 BufferFeatures
		{
			UInt32 get()
			{
				return mBufferFeatures;
			}
			void set(UInt32 value)
			{
				mBufferFeatures = value; 
			}
		}
	internal:
		void CopyTo(VkFormatProperties* dst, List<IntPtr>^ pins)
		{
			dst->linearTilingFeatures =	mLinearTilingFeatures;
			dst->optimalTilingFeatures =	mOptimalTilingFeatures;
			dst->bufferFeatures =	mBufferFeatures;
		}

		void CopyFrom(VkFormatProperties* src)
		{
			mLinearTilingFeatures = src->linearTilingFeatures;
			mOptimalTilingFeatures = src->optimalTilingFeatures;
			mBufferFeatures = src->bufferFeatures;
		}
	};

	public ref class ImageFormatProperties
	{
	private:
		Extent3D^ mMaxExtent = gcnew Extent3D();
		UInt32 mMaxMipLevels = 0;
		UInt32 mMaxArrayLayers = 0;
		UInt32 mSampleCounts;
		UInt64 mMaxResourceSize = 0;
	public:
		property ManagedVulkan::Extent3D^ MaxExtent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mMaxExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
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
		property UInt32 SampleCounts
		{
			UInt32 get()
			{
				return mSampleCounts;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkImageFormatProperties* dst, List<IntPtr>^ pins)
		{
			mMaxExtent->CopyFrom(&dst->maxExtent, pins);
			dst->maxMipLevels =	mMaxMipLevels;
			dst->maxArrayLayers =	mMaxArrayLayers;
			dst->sampleCounts =	mSampleCounts;
			dst->maxResourceSize =	mMaxResourceSize;
		}

		void CopyFrom(VkImageFormatProperties* src)
		{
			mMaxExtent->CopyTo(&src->maxExtent);
			mMaxMipLevels = src->maxMipLevels;
			mMaxArrayLayers = src->maxArrayLayers;
			mSampleCounts = src->sampleCounts;
			mMaxResourceSize = src->maxResourceSize;
		}
	};

	public ref class DescriptorBufferInfo
	{
	private:
		Buffer^ mBuffer = gcnew Buffer();
		UInt64 mOffset = 0;
		UInt64 mRange = 0;
	public:
		property ManagedVulkan::Buffer^ Buffer
		{
			ManagedVulkan::Buffer^ get()
			{
				return mBuffer;
			}
			void set(ManagedVulkan::Buffer^ value)
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
	internal:
		void CopyTo(VkDescriptorBufferInfo* dst, List<IntPtr>^ pins)
		{
			dst->buffer =	mBuffer;
			dst->offset =	mOffset;
			dst->range =	mRange;
		}

		void CopyFrom(VkDescriptorBufferInfo* src)
		{
			mBuffer = src->buffer;
			mOffset = src->offset;
			mRange = src->range;
		}
	};

	public ref class DescriptorImageInfo
	{
	private:
		Sampler^ mSampler = gcnew Sampler();
		ImageView^ mImageView = gcnew ImageView();
		VkImageLayout mImageLayout;
	public:
		property ManagedVulkan::Sampler^ Sampler
		{
			ManagedVulkan::Sampler^ get()
			{
				return mSampler;
			}
			void set(ManagedVulkan::Sampler^ value)
			{
				mSampler = value; 
			}
		}
		property ManagedVulkan::ImageView^ ImageView
		{
			ManagedVulkan::ImageView^ get()
			{
				return mImageView;
			}
			void set(ManagedVulkan::ImageView^ value)
			{
				mImageView = value; 
			}
		}
		property ManagedVulkan::VkImageLayout ImageLayout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mImageLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
			{
				mImageLayout = value; 
			}
		}
	internal:
		void CopyTo(VkDescriptorImageInfo* dst, List<IntPtr>^ pins)
		{
			dst->sampler =	mSampler;
			dst->imageView =	mImageView;
			dst->imageLayout =	mImageLayout;
		}

		void CopyFrom(VkDescriptorImageInfo* src)
		{
			mSampler = src->sampler;
			mImageView = src->imageView;
			mImageLayout = src->imageLayout;
		}
	};

	public ref class WriteDescriptorSet
	{
	private:
		VkStructureType mSType;
		DescriptorSet^ mDstSet = gcnew DescriptorSet();
		UInt32 mDstBinding = 0;
		UInt32 mDstArrayElement = 0;
		UInt32 mDescriptorCount = 0;
		VkDescriptorType mDescriptorType;
		DescriptorImageInfo^ mImageInfo = gcnew DescriptorImageInfo();
		DescriptorBufferInfo^ mBufferInfo = gcnew DescriptorBufferInfo();
		BufferView^ mTexelBufferView = gcnew BufferView();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::DescriptorSet^ DstSet
		{
			ManagedVulkan::DescriptorSet^ get()
			{
				return mDstSet;
			}
			void set(ManagedVulkan::DescriptorSet^ value)
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
		property ManagedVulkan::VkDescriptorType DescriptorType
		{
			ManagedVulkan::VkDescriptorType get()
			{
				return mDescriptorType;
			}
			void set(ManagedVulkan::VkDescriptorType value)
			{
				mDescriptorType = value; 
			}
		}
		property ManagedVulkan::DescriptorImageInfo^ ImageInfo
		{
			ManagedVulkan::DescriptorImageInfo^ get()
			{
				return mImageInfo;
			}
			void set(ManagedVulkan::DescriptorImageInfo^ value)
			{
				mImageInfo = value; 
			}
		}
		property ManagedVulkan::DescriptorBufferInfo^ BufferInfo
		{
			ManagedVulkan::DescriptorBufferInfo^ get()
			{
				return mBufferInfo;
			}
			void set(ManagedVulkan::DescriptorBufferInfo^ value)
			{
				mBufferInfo = value; 
			}
		}
		property ManagedVulkan::BufferView^ TexelBufferView
		{
			ManagedVulkan::BufferView^ get()
			{
				return mTexelBufferView;
			}
			void set(ManagedVulkan::BufferView^ value)
			{
				mTexelBufferView = value; 
			}
		}
	internal:
		void CopyTo(VkWriteDescriptorSet* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->dstSet =	mDstSet;
			dst->dstBinding =	mDstBinding;
			dst->dstArrayElement =	mDstArrayElement;
			dst->descriptorCount =	mDescriptorCount;
			dst->descriptorType =	mDescriptorType;
			mImageInfo->CopyFrom(&dst->pImageInfo, pins);
			mBufferInfo->CopyFrom(&dst->pBufferInfo, pins);
			dst->pTexelBufferView =	mTexelBufferView;
		}

		void CopyFrom(VkWriteDescriptorSet* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mDstSet = src->dstSet;
			mDstBinding = src->dstBinding;
			mDstArrayElement = src->dstArrayElement;
			mDescriptorCount = src->descriptorCount;
			mDescriptorType = src->descriptorType;
			mImageInfo->CopyTo(&src->pImageInfo);
			mBufferInfo->CopyTo(&src->pBufferInfo);
			mTexelBufferView = src->pTexelBufferView;
		}
	};

	public ref class CopyDescriptorSet
	{
	private:
		VkStructureType mSType;
		DescriptorSet^ mSrcSet = gcnew DescriptorSet();
		UInt32 mSrcBinding = 0;
		UInt32 mSrcArrayElement = 0;
		DescriptorSet^ mDstSet = gcnew DescriptorSet();
		UInt32 mDstBinding = 0;
		UInt32 mDstArrayElement = 0;
		UInt32 mDescriptorCount = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::DescriptorSet^ SrcSet
		{
			ManagedVulkan::DescriptorSet^ get()
			{
				return mSrcSet;
			}
			void set(ManagedVulkan::DescriptorSet^ value)
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
		property ManagedVulkan::DescriptorSet^ DstSet
		{
			ManagedVulkan::DescriptorSet^ get()
			{
				return mDstSet;
			}
			void set(ManagedVulkan::DescriptorSet^ value)
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
	internal:
		void CopyTo(VkCopyDescriptorSet* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->srcSet =	mSrcSet;
			dst->srcBinding =	mSrcBinding;
			dst->srcArrayElement =	mSrcArrayElement;
			dst->dstSet =	mDstSet;
			dst->dstBinding =	mDstBinding;
			dst->dstArrayElement =	mDstArrayElement;
			dst->descriptorCount =	mDescriptorCount;
		}

		void CopyFrom(VkCopyDescriptorSet* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mSrcSet = src->srcSet;
			mSrcBinding = src->srcBinding;
			mSrcArrayElement = src->srcArrayElement;
			mDstSet = src->dstSet;
			mDstBinding = src->dstBinding;
			mDstArrayElement = src->dstArrayElement;
			mDescriptorCount = src->descriptorCount;
		}
	};

	public ref class BufferCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt64 mSize = 0;
		UInt32 mUsage;
		VkSharingMode mSharingMode;
		UInt32 mQueueFamilyIndexCount = 0;
		UInt32 mQueueFamilyIndices = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property UInt32 Usage
		{
			UInt32 get()
			{
				return mUsage;
			}
			void set(UInt32 value)
			{
				mUsage = value; 
			}
		}
		property ManagedVulkan::VkSharingMode SharingMode
		{
			ManagedVulkan::VkSharingMode get()
			{
				return mSharingMode;
			}
			void set(ManagedVulkan::VkSharingMode value)
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
	internal:
		void CopyTo(VkBufferCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->size =	mSize;
			dst->usage =	mUsage;
			dst->sharingMode =	mSharingMode;
			dst->queueFamilyIndexCount =	mQueueFamilyIndexCount;
			dst->pQueueFamilyIndices =	mQueueFamilyIndices;
		}

		void CopyFrom(VkBufferCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mSize = src->size;
			mUsage = src->usage;
			mSharingMode = src->sharingMode;
			mQueueFamilyIndexCount = src->queueFamilyIndexCount;
			mQueueFamilyIndices = src->pQueueFamilyIndices;
		}
	};

	public ref class BufferViewCreateInfo
	{
	private:
		VkStructureType mSType;
		<TYPE> m<NAME>;
		Buffer^ mBuffer = gcnew Buffer();
		VkFormat mFormat;
		UInt64 mOffset = 0;
		UInt64 mRange = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
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
		property ManagedVulkan::Buffer^ Buffer
		{
			ManagedVulkan::Buffer^ get()
			{
				return mBuffer;
			}
			void set(ManagedVulkan::Buffer^ value)
			{
				mBuffer = value; 
			}
		}
		property ManagedVulkan::VkFormat Format
		{
			ManagedVulkan::VkFormat get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::VkFormat value)
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
	internal:
		void CopyTo(VkBufferViewCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst-><NAME> =	m<NAME>;
			dst->buffer =	mBuffer;
			dst->format =	mFormat;
			dst->offset =	mOffset;
			dst->range =	mRange;
		}

		void CopyFrom(VkBufferViewCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			m<NAME> = src-><NAME>;
			mBuffer = src->buffer;
			mFormat = src->format;
			mOffset = src->offset;
			mRange = src->range;
		}
	};

	public ref class ImageSubresource
	{
	private:
		UInt32 mAspectMask;
		UInt32 mMipLevel = 0;
		UInt32 mArrayLayer = 0;
	public:
		property UInt32 AspectMask
		{
			UInt32 get()
			{
				return mAspectMask;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkImageSubresource* dst, List<IntPtr>^ pins)
		{
			dst->aspectMask =	mAspectMask;
			dst->mipLevel =	mMipLevel;
			dst->arrayLayer =	mArrayLayer;
		}

		void CopyFrom(VkImageSubresource* src)
		{
			mAspectMask = src->aspectMask;
			mMipLevel = src->mipLevel;
			mArrayLayer = src->arrayLayer;
		}
	};

	public ref class ImageSubresourceLayers
	{
	private:
		UInt32 mAspectMask;
		UInt32 mMipLevel = 0;
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property UInt32 AspectMask
		{
			UInt32 get()
			{
				return mAspectMask;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkImageSubresourceLayers* dst, List<IntPtr>^ pins)
		{
			dst->aspectMask =	mAspectMask;
			dst->mipLevel =	mMipLevel;
			dst->baseArrayLayer =	mBaseArrayLayer;
			dst->layerCount =	mLayerCount;
		}

		void CopyFrom(VkImageSubresourceLayers* src)
		{
			mAspectMask = src->aspectMask;
			mMipLevel = src->mipLevel;
			mBaseArrayLayer = src->baseArrayLayer;
			mLayerCount = src->layerCount;
		}
	};

	public ref class ImageSubresourceRange
	{
	private:
		UInt32 mAspectMask;
		UInt32 mBaseMipLevel = 0;
		UInt32 mLevelCount = 0;
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property UInt32 AspectMask
		{
			UInt32 get()
			{
				return mAspectMask;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkImageSubresourceRange* dst, List<IntPtr>^ pins)
		{
			dst->aspectMask =	mAspectMask;
			dst->baseMipLevel =	mBaseMipLevel;
			dst->levelCount =	mLevelCount;
			dst->baseArrayLayer =	mBaseArrayLayer;
			dst->layerCount =	mLayerCount;
		}

		void CopyFrom(VkImageSubresourceRange* src)
		{
			mAspectMask = src->aspectMask;
			mBaseMipLevel = src->baseMipLevel;
			mLevelCount = src->levelCount;
			mBaseArrayLayer = src->baseArrayLayer;
			mLayerCount = src->layerCount;
		}
	};

	public ref class MemoryBarrier
	{
	private:
		VkStructureType mSType;
		UInt32 mSrcAccessMask;
		UInt32 mDstAccessMask;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt32 SrcAccessMask
		{
			UInt32 get()
			{
				return mSrcAccessMask;
			}
			void set(UInt32 value)
			{
				mSrcAccessMask = value; 
			}
		}
		property UInt32 DstAccessMask
		{
			UInt32 get()
			{
				return mDstAccessMask;
			}
			void set(UInt32 value)
			{
				mDstAccessMask = value; 
			}
		}
	internal:
		void CopyTo(VkMemoryBarrier* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->srcAccessMask =	mSrcAccessMask;
			dst->dstAccessMask =	mDstAccessMask;
		}

		void CopyFrom(VkMemoryBarrier* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mSrcAccessMask = src->srcAccessMask;
			mDstAccessMask = src->dstAccessMask;
		}
	};

	public ref class BufferMemoryBarrier
	{
	private:
		VkStructureType mSType;
		UInt32 mSrcAccessMask;
		UInt32 mDstAccessMask;
		UInt32 mSrcQueueFamilyIndex = 0;
		UInt32 mDstQueueFamilyIndex = 0;
		Buffer^ mBuffer = gcnew Buffer();
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt32 SrcAccessMask
		{
			UInt32 get()
			{
				return mSrcAccessMask;
			}
			void set(UInt32 value)
			{
				mSrcAccessMask = value; 
			}
		}
		property UInt32 DstAccessMask
		{
			UInt32 get()
			{
				return mDstAccessMask;
			}
			void set(UInt32 value)
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
		property ManagedVulkan::Buffer^ Buffer
		{
			ManagedVulkan::Buffer^ get()
			{
				return mBuffer;
			}
			void set(ManagedVulkan::Buffer^ value)
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
	internal:
		void CopyTo(VkBufferMemoryBarrier* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->srcAccessMask =	mSrcAccessMask;
			dst->dstAccessMask =	mDstAccessMask;
			dst->srcQueueFamilyIndex =	mSrcQueueFamilyIndex;
			dst->dstQueueFamilyIndex =	mDstQueueFamilyIndex;
			dst->buffer =	mBuffer;
			dst->offset =	mOffset;
			dst->size =	mSize;
		}

		void CopyFrom(VkBufferMemoryBarrier* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mSrcAccessMask = src->srcAccessMask;
			mDstAccessMask = src->dstAccessMask;
			mSrcQueueFamilyIndex = src->srcQueueFamilyIndex;
			mDstQueueFamilyIndex = src->dstQueueFamilyIndex;
			mBuffer = src->buffer;
			mOffset = src->offset;
			mSize = src->size;
		}
	};

	public ref class ImageMemoryBarrier
	{
	private:
		VkStructureType mSType;
		UInt32 mSrcAccessMask;
		UInt32 mDstAccessMask;
		VkImageLayout mOldLayout;
		VkImageLayout mNewLayout;
		UInt32 mSrcQueueFamilyIndex = 0;
		UInt32 mDstQueueFamilyIndex = 0;
		Image^ mImage = gcnew Image();
		ImageSubresourceRange^ mSubresourceRange = gcnew ImageSubresourceRange();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property UInt32 SrcAccessMask
		{
			UInt32 get()
			{
				return mSrcAccessMask;
			}
			void set(UInt32 value)
			{
				mSrcAccessMask = value; 
			}
		}
		property UInt32 DstAccessMask
		{
			UInt32 get()
			{
				return mDstAccessMask;
			}
			void set(UInt32 value)
			{
				mDstAccessMask = value; 
			}
		}
		property ManagedVulkan::VkImageLayout OldLayout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mOldLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
			{
				mOldLayout = value; 
			}
		}
		property ManagedVulkan::VkImageLayout NewLayout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mNewLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
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
		property ManagedVulkan::Image^ Image
		{
			ManagedVulkan::Image^ get()
			{
				return mImage;
			}
			void set(ManagedVulkan::Image^ value)
			{
				mImage = value; 
			}
		}
		property ManagedVulkan::ImageSubresourceRange^ SubresourceRange
		{
			ManagedVulkan::ImageSubresourceRange^ get()
			{
				return mSubresourceRange;
			}
			void set(ManagedVulkan::ImageSubresourceRange^ value)
			{
				mSubresourceRange = value; 
			}
		}
	internal:
		void CopyTo(VkImageMemoryBarrier* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->srcAccessMask =	mSrcAccessMask;
			dst->dstAccessMask =	mDstAccessMask;
			dst->oldLayout =	mOldLayout;
			dst->newLayout =	mNewLayout;
			dst->srcQueueFamilyIndex =	mSrcQueueFamilyIndex;
			dst->dstQueueFamilyIndex =	mDstQueueFamilyIndex;
			dst->image =	mImage;
			mSubresourceRange->CopyFrom(&dst->subresourceRange, pins);
		}

		void CopyFrom(VkImageMemoryBarrier* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mSrcAccessMask = src->srcAccessMask;
			mDstAccessMask = src->dstAccessMask;
			mOldLayout = src->oldLayout;
			mNewLayout = src->newLayout;
			mSrcQueueFamilyIndex = src->srcQueueFamilyIndex;
			mDstQueueFamilyIndex = src->dstQueueFamilyIndex;
			mImage = src->image;
			mSubresourceRange->CopyTo(&src->subresourceRange);
		}
	};

	public ref class ImageCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		VkImageType mImageType;
		VkFormat mFormat;
		Extent3D^ mExtent = gcnew Extent3D();
		UInt32 mMipLevels = 0;
		UInt32 mArrayLayers = 0;
		VkSampleCountFlagBits mSamples;
		VkImageTiling mTiling;
		UInt32 mUsage;
		VkSharingMode mSharingMode;
		UInt32 mQueueFamilyIndexCount = 0;
		UInt32 mQueueFamilyIndices = 0;
		VkImageLayout mInitialLayout;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkImageType ImageType
		{
			ManagedVulkan::VkImageType get()
			{
				return mImageType;
			}
			void set(ManagedVulkan::VkImageType value)
			{
				mImageType = value; 
			}
		}
		property ManagedVulkan::VkFormat Format
		{
			ManagedVulkan::VkFormat get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::VkFormat value)
			{
				mFormat = value; 
			}
		}
		property ManagedVulkan::Extent3D^ Extent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
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
		property ManagedVulkan::VkSampleCountFlagBits Samples
		{
			ManagedVulkan::VkSampleCountFlagBits get()
			{
				return mSamples;
			}
			void set(ManagedVulkan::VkSampleCountFlagBits value)
			{
				mSamples = value; 
			}
		}
		property ManagedVulkan::VkImageTiling Tiling
		{
			ManagedVulkan::VkImageTiling get()
			{
				return mTiling;
			}
			void set(ManagedVulkan::VkImageTiling value)
			{
				mTiling = value; 
			}
		}
		property UInt32 Usage
		{
			UInt32 get()
			{
				return mUsage;
			}
			void set(UInt32 value)
			{
				mUsage = value; 
			}
		}
		property ManagedVulkan::VkSharingMode SharingMode
		{
			ManagedVulkan::VkSharingMode get()
			{
				return mSharingMode;
			}
			void set(ManagedVulkan::VkSharingMode value)
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
		property ManagedVulkan::VkImageLayout InitialLayout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mInitialLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
			{
				mInitialLayout = value; 
			}
		}
	internal:
		void CopyTo(VkImageCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->imageType =	mImageType;
			dst->format =	mFormat;
			mExtent->CopyFrom(&dst->extent, pins);
			dst->mipLevels =	mMipLevels;
			dst->arrayLayers =	mArrayLayers;
			dst->samples =	mSamples;
			dst->tiling =	mTiling;
			dst->usage =	mUsage;
			dst->sharingMode =	mSharingMode;
			dst->queueFamilyIndexCount =	mQueueFamilyIndexCount;
			dst->pQueueFamilyIndices =	mQueueFamilyIndices;
			dst->initialLayout =	mInitialLayout;
		}

		void CopyFrom(VkImageCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mImageType = src->imageType;
			mFormat = src->format;
			mExtent->CopyTo(&src->extent);
			mMipLevels = src->mipLevels;
			mArrayLayers = src->arrayLayers;
			mSamples = src->samples;
			mTiling = src->tiling;
			mUsage = src->usage;
			mSharingMode = src->sharingMode;
			mQueueFamilyIndexCount = src->queueFamilyIndexCount;
			mQueueFamilyIndices = src->pQueueFamilyIndices;
			mInitialLayout = src->initialLayout;
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
	internal:
		void CopyTo(VkSubresourceLayout* dst, List<IntPtr>^ pins)
		{
			dst->offset =	mOffset;
			dst->size =	mSize;
			dst->rowPitch =	mRowPitch;
			dst->arrayPitch =	mArrayPitch;
			dst->depthPitch =	mDepthPitch;
		}

		void CopyFrom(VkSubresourceLayout* src)
		{
			mOffset = src->offset;
			mSize = src->size;
			mRowPitch = src->rowPitch;
			mArrayPitch = src->arrayPitch;
			mDepthPitch = src->depthPitch;
		}
	};

	public ref class ImageViewCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		Image^ mImage = gcnew Image();
		VkImageViewType mViewType;
		VkFormat mFormat;
		ComponentMapping^ mComponents = gcnew ComponentMapping();
		ImageSubresourceRange^ mSubresourceRange = gcnew ImageSubresourceRange();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::Image^ Image
		{
			ManagedVulkan::Image^ get()
			{
				return mImage;
			}
			void set(ManagedVulkan::Image^ value)
			{
				mImage = value; 
			}
		}
		property ManagedVulkan::VkImageViewType ViewType
		{
			ManagedVulkan::VkImageViewType get()
			{
				return mViewType;
			}
			void set(ManagedVulkan::VkImageViewType value)
			{
				mViewType = value; 
			}
		}
		property ManagedVulkan::VkFormat Format
		{
			ManagedVulkan::VkFormat get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::VkFormat value)
			{
				mFormat = value; 
			}
		}
		property ManagedVulkan::ComponentMapping^ Components
		{
			ManagedVulkan::ComponentMapping^ get()
			{
				return mComponents;
			}
			void set(ManagedVulkan::ComponentMapping^ value)
			{
				mComponents = value; 
			}
		}
		property ManagedVulkan::ImageSubresourceRange^ SubresourceRange
		{
			ManagedVulkan::ImageSubresourceRange^ get()
			{
				return mSubresourceRange;
			}
			void set(ManagedVulkan::ImageSubresourceRange^ value)
			{
				mSubresourceRange = value; 
			}
		}
	internal:
		void CopyTo(VkImageViewCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->image =	mImage;
			dst->viewType =	mViewType;
			dst->format =	mFormat;
			mComponents->CopyFrom(&dst->components, pins);
			mSubresourceRange->CopyFrom(&dst->subresourceRange, pins);
		}

		void CopyFrom(VkImageViewCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mImage = src->image;
			mViewType = src->viewType;
			mFormat = src->format;
			mComponents->CopyTo(&src->components);
			mSubresourceRange->CopyTo(&src->subresourceRange);
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
	internal:
		void CopyTo(VkBufferCopy* dst, List<IntPtr>^ pins)
		{
			dst->srcOffset =	mSrcOffset;
			dst->dstOffset =	mDstOffset;
			dst->size =	mSize;
		}

		void CopyFrom(VkBufferCopy* src)
		{
			mSrcOffset = src->srcOffset;
			mDstOffset = src->dstOffset;
			mSize = src->size;
		}
	};

	public ref class SparseMemoryBind
	{
	private:
		UInt64 mResourceOffset = 0;
		UInt64 mSize = 0;
		DeviceMemory^ mMemory = gcnew DeviceMemory();
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
		property ManagedVulkan::DeviceMemory^ Memory
		{
			ManagedVulkan::DeviceMemory^ get()
			{
				return mMemory;
			}
			void set(ManagedVulkan::DeviceMemory^ value)
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
	internal:
		void CopyTo(VkSparseMemoryBind* dst, List<IntPtr>^ pins)
		{
			dst->resourceOffset =	mResourceOffset;
			dst->size =	mSize;
			dst->memory =	mMemory;
			dst->memoryOffset =	mMemoryOffset;
			dst-><NAME> =	m<NAME>;
		}

		void CopyFrom(VkSparseMemoryBind* src)
		{
			mResourceOffset = src->resourceOffset;
			mSize = src->size;
			mMemory = src->memory;
			mMemoryOffset = src->memoryOffset;
			m<NAME> = src-><NAME>;
		}
	};

	public ref class SparseImageMemoryBind
	{
	private:
		ImageSubresource^ mSubresource = gcnew ImageSubresource();
		Offset3D^ mOffset = gcnew Offset3D();
		Extent3D^ mExtent = gcnew Extent3D();
		DeviceMemory^ mMemory = gcnew DeviceMemory();
		UInt64 mMemoryOffset = 0;
		<TYPE> m<NAME>;
	public:
		property ManagedVulkan::ImageSubresource^ Subresource
		{
			ManagedVulkan::ImageSubresource^ get()
			{
				return mSubresource;
			}
			void set(ManagedVulkan::ImageSubresource^ value)
			{
				mSubresource = value; 
			}
		}
		property ManagedVulkan::Offset3D^ Offset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mOffset = value; 
			}
		}
		property ManagedVulkan::Extent3D^ Extent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mExtent = value; 
			}
		}
		property ManagedVulkan::DeviceMemory^ Memory
		{
			ManagedVulkan::DeviceMemory^ get()
			{
				return mMemory;
			}
			void set(ManagedVulkan::DeviceMemory^ value)
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
	internal:
		void CopyTo(VkSparseImageMemoryBind* dst, List<IntPtr>^ pins)
		{
			mSubresource->CopyFrom(&dst->subresource, pins);
			mOffset->CopyFrom(&dst->offset, pins);
			mExtent->CopyFrom(&dst->extent, pins);
			dst->memory =	mMemory;
			dst->memoryOffset =	mMemoryOffset;
			dst-><NAME> =	m<NAME>;
		}

		void CopyFrom(VkSparseImageMemoryBind* src)
		{
			mSubresource->CopyTo(&src->subresource);
			mOffset->CopyTo(&src->offset);
			mExtent->CopyTo(&src->extent);
			mMemory = src->memory;
			mMemoryOffset = src->memoryOffset;
			m<NAME> = src-><NAME>;
		}
	};

	public ref class SparseBufferMemoryBindInfo
	{
	private:
		Buffer^ mBuffer = gcnew Buffer();
		UInt32 mBindCount = 0;
		SparseMemoryBind^ mBinds = gcnew SparseMemoryBind();
	public:
		property ManagedVulkan::Buffer^ Buffer
		{
			ManagedVulkan::Buffer^ get()
			{
				return mBuffer;
			}
			void set(ManagedVulkan::Buffer^ value)
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
		property ManagedVulkan::SparseMemoryBind^ Binds
		{
			ManagedVulkan::SparseMemoryBind^ get()
			{
				return mBinds;
			}
			void set(ManagedVulkan::SparseMemoryBind^ value)
			{
				mBinds = value; 
			}
		}
	internal:
		void CopyTo(VkSparseBufferMemoryBindInfo* dst, List<IntPtr>^ pins)
		{
			dst->buffer =	mBuffer;
			dst->bindCount =	mBindCount;
			mBinds->CopyFrom(&dst->pBinds, pins);
		}

		void CopyFrom(VkSparseBufferMemoryBindInfo* src)
		{
			mBuffer = src->buffer;
			mBindCount = src->bindCount;
			mBinds->CopyTo(&src->pBinds);
		}
	};

	public ref class SparseImageOpaqueMemoryBindInfo
	{
	private:
		Image^ mImage = gcnew Image();
		UInt32 mBindCount = 0;
		SparseMemoryBind^ mBinds = gcnew SparseMemoryBind();
	public:
		property ManagedVulkan::Image^ Image
		{
			ManagedVulkan::Image^ get()
			{
				return mImage;
			}
			void set(ManagedVulkan::Image^ value)
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
		property ManagedVulkan::SparseMemoryBind^ Binds
		{
			ManagedVulkan::SparseMemoryBind^ get()
			{
				return mBinds;
			}
			void set(ManagedVulkan::SparseMemoryBind^ value)
			{
				mBinds = value; 
			}
		}
	internal:
		void CopyTo(VkSparseImageOpaqueMemoryBindInfo* dst, List<IntPtr>^ pins)
		{
			dst->image =	mImage;
			dst->bindCount =	mBindCount;
			mBinds->CopyFrom(&dst->pBinds, pins);
		}

		void CopyFrom(VkSparseImageOpaqueMemoryBindInfo* src)
		{
			mImage = src->image;
			mBindCount = src->bindCount;
			mBinds->CopyTo(&src->pBinds);
		}
	};

	public ref class SparseImageMemoryBindInfo
	{
	private:
		Image^ mImage = gcnew Image();
		UInt32 mBindCount = 0;
		SparseImageMemoryBind^ mBinds = gcnew SparseImageMemoryBind();
	public:
		property ManagedVulkan::Image^ Image
		{
			ManagedVulkan::Image^ get()
			{
				return mImage;
			}
			void set(ManagedVulkan::Image^ value)
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
		property ManagedVulkan::SparseImageMemoryBind^ Binds
		{
			ManagedVulkan::SparseImageMemoryBind^ get()
			{
				return mBinds;
			}
			void set(ManagedVulkan::SparseImageMemoryBind^ value)
			{
				mBinds = value; 
			}
		}
	internal:
		void CopyTo(VkSparseImageMemoryBindInfo* dst, List<IntPtr>^ pins)
		{
			dst->image =	mImage;
			dst->bindCount =	mBindCount;
			mBinds->CopyFrom(&dst->pBinds, pins);
		}

		void CopyFrom(VkSparseImageMemoryBindInfo* src)
		{
			mImage = src->image;
			mBindCount = src->bindCount;
			mBinds->CopyTo(&src->pBinds);
		}
	};

	public ref class BindSparseInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		Semaphore^ mWaitSemaphores = gcnew Semaphore();
		UInt32 mBufferBindCount = 0;
		SparseBufferMemoryBindInfo^ mBufferBinds = gcnew SparseBufferMemoryBindInfo();
		UInt32 mImageOpaqueBindCount = 0;
		SparseImageOpaqueMemoryBindInfo^ mImageOpaqueBinds = gcnew SparseImageOpaqueMemoryBindInfo();
		UInt32 mImageBindCount = 0;
		SparseImageMemoryBindInfo^ mImageBinds = gcnew SparseImageMemoryBindInfo();
		UInt32 mSignalSemaphoreCount = 0;
		Semaphore^ mSignalSemaphores = gcnew Semaphore();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
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
		property ManagedVulkan::Semaphore^ WaitSemaphores
		{
			ManagedVulkan::Semaphore^ get()
			{
				return mWaitSemaphores;
			}
			void set(ManagedVulkan::Semaphore^ value)
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
		property ManagedVulkan::SparseBufferMemoryBindInfo^ BufferBinds
		{
			ManagedVulkan::SparseBufferMemoryBindInfo^ get()
			{
				return mBufferBinds;
			}
			void set(ManagedVulkan::SparseBufferMemoryBindInfo^ value)
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
		property ManagedVulkan::SparseImageOpaqueMemoryBindInfo^ ImageOpaqueBinds
		{
			ManagedVulkan::SparseImageOpaqueMemoryBindInfo^ get()
			{
				return mImageOpaqueBinds;
			}
			void set(ManagedVulkan::SparseImageOpaqueMemoryBindInfo^ value)
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
		property ManagedVulkan::SparseImageMemoryBindInfo^ ImageBinds
		{
			ManagedVulkan::SparseImageMemoryBindInfo^ get()
			{
				return mImageBinds;
			}
			void set(ManagedVulkan::SparseImageMemoryBindInfo^ value)
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
		property ManagedVulkan::Semaphore^ SignalSemaphores
		{
			ManagedVulkan::Semaphore^ get()
			{
				return mSignalSemaphores;
			}
			void set(ManagedVulkan::Semaphore^ value)
			{
				mSignalSemaphores = value; 
			}
		}
	internal:
		void CopyTo(VkBindSparseInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->waitSemaphoreCount =	mWaitSemaphoreCount;
			dst->pWaitSemaphores =	mWaitSemaphores;
			dst->bufferBindCount =	mBufferBindCount;
			mBufferBinds->CopyFrom(&dst->pBufferBinds, pins);
			dst->imageOpaqueBindCount =	mImageOpaqueBindCount;
			mImageOpaqueBinds->CopyFrom(&dst->pImageOpaqueBinds, pins);
			dst->imageBindCount =	mImageBindCount;
			mImageBinds->CopyFrom(&dst->pImageBinds, pins);
			dst->signalSemaphoreCount =	mSignalSemaphoreCount;
			dst->pSignalSemaphores =	mSignalSemaphores;
		}

		void CopyFrom(VkBindSparseInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mWaitSemaphoreCount = src->waitSemaphoreCount;
			mWaitSemaphores = src->pWaitSemaphores;
			mBufferBindCount = src->bufferBindCount;
			mBufferBinds->CopyTo(&src->pBufferBinds);
			mImageOpaqueBindCount = src->imageOpaqueBindCount;
			mImageOpaqueBinds->CopyTo(&src->pImageOpaqueBinds);
			mImageBindCount = src->imageBindCount;
			mImageBinds->CopyTo(&src->pImageBinds);
			mSignalSemaphoreCount = src->signalSemaphoreCount;
			mSignalSemaphores = src->pSignalSemaphores;
		}
	};

	public ref class ImageCopy
	{
	private:
		ImageSubresourceLayers^ mSrcSubresource = gcnew ImageSubresourceLayers();
		Offset3D^ mSrcOffset = gcnew Offset3D();
		ImageSubresourceLayers^ mDstSubresource = gcnew ImageSubresourceLayers();
		Offset3D^ mDstOffset = gcnew Offset3D();
		Extent3D^ mExtent = gcnew Extent3D();
	public:
		property ManagedVulkan::ImageSubresourceLayers^ SrcSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mSrcSubresource = value; 
			}
		}
		property ManagedVulkan::Offset3D^ SrcOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mSrcOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mSrcOffset = value; 
			}
		}
		property ManagedVulkan::ImageSubresourceLayers^ DstSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mDstSubresource = value; 
			}
		}
		property ManagedVulkan::Offset3D^ DstOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mDstOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mDstOffset = value; 
			}
		}
		property ManagedVulkan::Extent3D^ Extent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mExtent = value; 
			}
		}
	internal:
		void CopyTo(VkImageCopy* dst, List<IntPtr>^ pins)
		{
			mSrcSubresource->CopyFrom(&dst->srcSubresource, pins);
			mSrcOffset->CopyFrom(&dst->srcOffset, pins);
			mDstSubresource->CopyFrom(&dst->dstSubresource, pins);
			mDstOffset->CopyFrom(&dst->dstOffset, pins);
			mExtent->CopyFrom(&dst->extent, pins);
		}

		void CopyFrom(VkImageCopy* src)
		{
			mSrcSubresource->CopyTo(&src->srcSubresource);
			mSrcOffset->CopyTo(&src->srcOffset);
			mDstSubresource->CopyTo(&src->dstSubresource);
			mDstOffset->CopyTo(&src->dstOffset);
			mExtent->CopyTo(&src->extent);
		}
	};

	public ref class ImageBlit
	{
	private:
		ImageSubresourceLayers^ mSrcSubresource = gcnew ImageSubresourceLayers();
		srcOffsets m2;
		ImageSubresourceLayers^ mDstSubresource = gcnew ImageSubresourceLayers();
		dstOffsets m2;
	public:
		property ManagedVulkan::ImageSubresourceLayers^ SrcSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
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
		property ManagedVulkan::ImageSubresourceLayers^ DstSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
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
	internal:
		void CopyTo(VkImageBlit* dst, List<IntPtr>^ pins)
		{
			mSrcSubresource->CopyFrom(&dst->srcSubresource, pins);
			dst->2 =	m2;
			mDstSubresource->CopyFrom(&dst->dstSubresource, pins);
			dst->2 =	m2;
		}

		void CopyFrom(VkImageBlit* src)
		{
			mSrcSubresource->CopyTo(&src->srcSubresource);
			m2 = src->2;
			mDstSubresource->CopyTo(&src->dstSubresource);
			m2 = src->2;
		}
	};

	public ref class BufferImageCopy
	{
	private:
		UInt64 mBufferOffset = 0;
		UInt32 mBufferRowLength = 0;
		UInt32 mBufferImageHeight = 0;
		ImageSubresourceLayers^ mImageSubresource = gcnew ImageSubresourceLayers();
		Offset3D^ mImageOffset = gcnew Offset3D();
		Extent3D^ mImageExtent = gcnew Extent3D();
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
		property ManagedVulkan::ImageSubresourceLayers^ ImageSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mImageSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mImageSubresource = value; 
			}
		}
		property ManagedVulkan::Offset3D^ ImageOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mImageOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mImageOffset = value; 
			}
		}
		property ManagedVulkan::Extent3D^ ImageExtent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mImageExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mImageExtent = value; 
			}
		}
	internal:
		void CopyTo(VkBufferImageCopy* dst, List<IntPtr>^ pins)
		{
			dst->bufferOffset =	mBufferOffset;
			dst->bufferRowLength =	mBufferRowLength;
			dst->bufferImageHeight =	mBufferImageHeight;
			mImageSubresource->CopyFrom(&dst->imageSubresource, pins);
			mImageOffset->CopyFrom(&dst->imageOffset, pins);
			mImageExtent->CopyFrom(&dst->imageExtent, pins);
		}

		void CopyFrom(VkBufferImageCopy* src)
		{
			mBufferOffset = src->bufferOffset;
			mBufferRowLength = src->bufferRowLength;
			mBufferImageHeight = src->bufferImageHeight;
			mImageSubresource->CopyTo(&src->imageSubresource);
			mImageOffset->CopyTo(&src->imageOffset);
			mImageExtent->CopyTo(&src->imageExtent);
		}
	};

	public ref class ImageResolve
	{
	private:
		ImageSubresourceLayers^ mSrcSubresource = gcnew ImageSubresourceLayers();
		Offset3D^ mSrcOffset = gcnew Offset3D();
		ImageSubresourceLayers^ mDstSubresource = gcnew ImageSubresourceLayers();
		Offset3D^ mDstOffset = gcnew Offset3D();
		Extent3D^ mExtent = gcnew Extent3D();
	public:
		property ManagedVulkan::ImageSubresourceLayers^ SrcSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mSrcSubresource = value; 
			}
		}
		property ManagedVulkan::Offset3D^ SrcOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mSrcOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mSrcOffset = value; 
			}
		}
		property ManagedVulkan::ImageSubresourceLayers^ DstSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mDstSubresource = value; 
			}
		}
		property ManagedVulkan::Offset3D^ DstOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mDstOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mDstOffset = value; 
			}
		}
		property ManagedVulkan::Extent3D^ Extent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mExtent = value; 
			}
		}
	internal:
		void CopyTo(VkImageResolve* dst, List<IntPtr>^ pins)
		{
			mSrcSubresource->CopyFrom(&dst->srcSubresource, pins);
			mSrcOffset->CopyFrom(&dst->srcOffset, pins);
			mDstSubresource->CopyFrom(&dst->dstSubresource, pins);
			mDstOffset->CopyFrom(&dst->dstOffset, pins);
			mExtent->CopyFrom(&dst->extent, pins);
		}

		void CopyFrom(VkImageResolve* src)
		{
			mSrcSubresource->CopyTo(&src->srcSubresource);
			mSrcOffset->CopyTo(&src->srcOffset);
			mDstSubresource->CopyTo(&src->dstSubresource);
			mDstOffset->CopyTo(&src->dstOffset);
			mExtent->CopyTo(&src->extent);
		}
	};

	public ref class ShaderModuleCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		IntPtr mCodeSize = 0;
		UInt32 mCode = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkShaderModuleCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->codeSize =	mCodeSize;
			dst->pCode =	mCode;
		}

		void CopyFrom(VkShaderModuleCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mCodeSize = src->codeSize;
			mCode = src->pCode;
		}
	};

	public ref class DescriptorSetLayoutBinding
	{
	private:
		UInt32 mBinding = 0;
		VkDescriptorType mDescriptorType;
		UInt32 mDescriptorCount = 0;
		UInt32 mStageFlags;
		Sampler^ mImmutableSamplers = gcnew Sampler();
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
		property ManagedVulkan::VkDescriptorType DescriptorType
		{
			ManagedVulkan::VkDescriptorType get()
			{
				return mDescriptorType;
			}
			void set(ManagedVulkan::VkDescriptorType value)
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
		property UInt32 StageFlags
		{
			UInt32 get()
			{
				return mStageFlags;
			}
			void set(UInt32 value)
			{
				mStageFlags = value; 
			}
		}
		property ManagedVulkan::Sampler^ ImmutableSamplers
		{
			ManagedVulkan::Sampler^ get()
			{
				return mImmutableSamplers;
			}
			void set(ManagedVulkan::Sampler^ value)
			{
				mImmutableSamplers = value; 
			}
		}
	internal:
		void CopyTo(VkDescriptorSetLayoutBinding* dst, List<IntPtr>^ pins)
		{
			dst->binding =	mBinding;
			dst->descriptorType =	mDescriptorType;
			dst->descriptorCount =	mDescriptorCount;
			dst->stageFlags =	mStageFlags;
			dst->pImmutableSamplers =	mImmutableSamplers;
		}

		void CopyFrom(VkDescriptorSetLayoutBinding* src)
		{
			mBinding = src->binding;
			mDescriptorType = src->descriptorType;
			mDescriptorCount = src->descriptorCount;
			mStageFlags = src->stageFlags;
			mImmutableSamplers = src->pImmutableSamplers;
		}
	};

	public ref class DescriptorSetLayoutCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mBindingCount = 0;
		DescriptorSetLayoutBinding^ mBindings = gcnew DescriptorSetLayoutBinding();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::DescriptorSetLayoutBinding^ Bindings
		{
			ManagedVulkan::DescriptorSetLayoutBinding^ get()
			{
				return mBindings;
			}
			void set(ManagedVulkan::DescriptorSetLayoutBinding^ value)
			{
				mBindings = value; 
			}
		}
	internal:
		void CopyTo(VkDescriptorSetLayoutCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->bindingCount =	mBindingCount;
			mBindings->CopyFrom(&dst->pBindings, pins);
		}

		void CopyFrom(VkDescriptorSetLayoutCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mBindingCount = src->bindingCount;
			mBindings->CopyTo(&src->pBindings);
		}
	};

	public ref class DescriptorPoolSize
	{
	private:
		VkDescriptorType mType;
		UInt32 mDescriptorCount = 0;
	public:
		property ManagedVulkan::VkDescriptorType Type
		{
			ManagedVulkan::VkDescriptorType get()
			{
				return mType;
			}
			void set(ManagedVulkan::VkDescriptorType value)
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
	internal:
		void CopyTo(VkDescriptorPoolSize* dst, List<IntPtr>^ pins)
		{
			dst->type =	mType;
			dst->descriptorCount =	mDescriptorCount;
		}

		void CopyFrom(VkDescriptorPoolSize* src)
		{
			mType = src->type;
			mDescriptorCount = src->descriptorCount;
		}
	};

	public ref class DescriptorPoolCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mMaxSets = 0;
		UInt32 mPoolSizeCount = 0;
		DescriptorPoolSize^ mPoolSizes = gcnew DescriptorPoolSize();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::DescriptorPoolSize^ PoolSizes
		{
			ManagedVulkan::DescriptorPoolSize^ get()
			{
				return mPoolSizes;
			}
			void set(ManagedVulkan::DescriptorPoolSize^ value)
			{
				mPoolSizes = value; 
			}
		}
	internal:
		void CopyTo(VkDescriptorPoolCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->maxSets =	mMaxSets;
			dst->poolSizeCount =	mPoolSizeCount;
			mPoolSizes->CopyFrom(&dst->pPoolSizes, pins);
		}

		void CopyFrom(VkDescriptorPoolCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mMaxSets = src->maxSets;
			mPoolSizeCount = src->poolSizeCount;
			mPoolSizes->CopyTo(&src->pPoolSizes);
		}
	};

	public ref class DescriptorSetAllocateInfo
	{
	private:
		VkStructureType mSType;
		DescriptorPool^ mDescriptorPool = gcnew DescriptorPool();
		UInt32 mDescriptorSetCount = 0;
		DescriptorSetLayout^ mSetLayouts = gcnew DescriptorSetLayout();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::DescriptorPool^ DescriptorPool
		{
			ManagedVulkan::DescriptorPool^ get()
			{
				return mDescriptorPool;
			}
			void set(ManagedVulkan::DescriptorPool^ value)
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
		property ManagedVulkan::DescriptorSetLayout^ SetLayouts
		{
			ManagedVulkan::DescriptorSetLayout^ get()
			{
				return mSetLayouts;
			}
			void set(ManagedVulkan::DescriptorSetLayout^ value)
			{
				mSetLayouts = value; 
			}
		}
	internal:
		void CopyTo(VkDescriptorSetAllocateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->descriptorPool =	mDescriptorPool;
			dst->descriptorSetCount =	mDescriptorSetCount;
			dst->pSetLayouts =	mSetLayouts;
		}

		void CopyFrom(VkDescriptorSetAllocateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mDescriptorPool = src->descriptorPool;
			mDescriptorSetCount = src->descriptorSetCount;
			mSetLayouts = src->pSetLayouts;
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
	internal:
		void CopyTo(VkSpecializationMapEntry* dst, List<IntPtr>^ pins)
		{
			dst->constantID =	mConstantID;
			dst->offset =	mOffset;
			dst->size =	mSize;
		}

		void CopyFrom(VkSpecializationMapEntry* src)
		{
			mConstantID = src->constantID;
			mOffset = src->offset;
			mSize = src->size;
		}
	};

	public ref class SpecializationInfo
	{
	private:
		UInt32 mMapEntryCount = 0;
		SpecializationMapEntry^ mMapEntries = gcnew SpecializationMapEntry();
		IntPtr mDataSize = 0;
		IntPtr mData = IntPtr::Zero;
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
		property ManagedVulkan::SpecializationMapEntry^ MapEntries
		{
			ManagedVulkan::SpecializationMapEntry^ get()
			{
				return mMapEntries;
			}
			void set(ManagedVulkan::SpecializationMapEntry^ value)
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
	internal:
		void CopyTo(VkSpecializationInfo* dst, List<IntPtr>^ pins)
		{
			dst->mapEntryCount =	mMapEntryCount;
			mMapEntries->CopyFrom(&dst->pMapEntries, pins);
			dst->dataSize =	mDataSize;
			dst->pData =	mData;
		}

		void CopyFrom(VkSpecializationInfo* src)
		{
			mMapEntryCount = src->mapEntryCount;
			mMapEntries->CopyTo(&src->pMapEntries);
			mDataSize = src->dataSize;
			mData = src->pData;
		}
	};

	public ref class PipelineShaderStageCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		VkShaderStageFlagBits mStage;
		ShaderModule^ mModule = gcnew ShaderModule();
		String^ mName = nullptr;
		SpecializationInfo^ mSpecializationInfo = gcnew SpecializationInfo();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkShaderStageFlagBits Stage
		{
			ManagedVulkan::VkShaderStageFlagBits get()
			{
				return mStage;
			}
			void set(ManagedVulkan::VkShaderStageFlagBits value)
			{
				mStage = value; 
			}
		}
		property ManagedVulkan::ShaderModule^ Module
		{
			ManagedVulkan::ShaderModule^ get()
			{
				return mModule;
			}
			void set(ManagedVulkan::ShaderModule^ value)
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
		property ManagedVulkan::SpecializationInfo^ SpecializationInfo
		{
			ManagedVulkan::SpecializationInfo^ get()
			{
				return mSpecializationInfo;
			}
			void set(ManagedVulkan::SpecializationInfo^ value)
			{
				mSpecializationInfo = value; 
			}
		}
	internal:
		void CopyTo(VkPipelineShaderStageCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->stage =	mStage;
			dst->module =	mModule;

			IntPtr str_pName = Marshal::StringToHGlobalAnsi(mName);
			pins->Add(str_pName);			
			dst->pName = static_cast <char*> (str_pName.ToPointer());

			mSpecializationInfo->CopyFrom(&dst->pSpecializationInfo, pins);
		}

		void CopyFrom(VkPipelineShaderStageCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mStage = src->stage;
			mModule = src->module;
			mName = gcnew String(mName);
			mSpecializationInfo->CopyTo(&src->pSpecializationInfo);
		}
	};

	public ref class ComputePipelineCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		PipelineShaderStageCreateInfo^ mStage = gcnew PipelineShaderStageCreateInfo();
		PipelineLayout^ mLayout = gcnew PipelineLayout();
		Pipeline^ mBasePipelineHandle = gcnew Pipeline();
		Int32 mBasePipelineIndex = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::PipelineShaderStageCreateInfo^ Stage
		{
			ManagedVulkan::PipelineShaderStageCreateInfo^ get()
			{
				return mStage;
			}
			void set(ManagedVulkan::PipelineShaderStageCreateInfo^ value)
			{
				mStage = value; 
			}
		}
		property ManagedVulkan::PipelineLayout^ Layout
		{
			ManagedVulkan::PipelineLayout^ get()
			{
				return mLayout;
			}
			void set(ManagedVulkan::PipelineLayout^ value)
			{
				mLayout = value; 
			}
		}
		property ManagedVulkan::Pipeline^ BasePipelineHandle
		{
			ManagedVulkan::Pipeline^ get()
			{
				return mBasePipelineHandle;
			}
			void set(ManagedVulkan::Pipeline^ value)
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
	internal:
		void CopyTo(VkComputePipelineCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			mStage->CopyFrom(&dst->stage, pins);
			dst->layout =	mLayout;
			dst->basePipelineHandle =	mBasePipelineHandle;
			dst->basePipelineIndex =	mBasePipelineIndex;
		}

		void CopyFrom(VkComputePipelineCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mStage->CopyTo(&src->stage);
			mLayout = src->layout;
			mBasePipelineHandle = src->basePipelineHandle;
			mBasePipelineIndex = src->basePipelineIndex;
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
		property ManagedVulkan::VkVertexInputRate InputRate
		{
			ManagedVulkan::VkVertexInputRate get()
			{
				return mInputRate;
			}
			void set(ManagedVulkan::VkVertexInputRate value)
			{
				mInputRate = value; 
			}
		}
	internal:
		void CopyTo(VkVertexInputBindingDescription* dst, List<IntPtr>^ pins)
		{
			dst->binding =	mBinding;
			dst->stride =	mStride;
			dst->inputRate =	mInputRate;
		}

		void CopyFrom(VkVertexInputBindingDescription* src)
		{
			mBinding = src->binding;
			mStride = src->stride;
			mInputRate = src->inputRate;
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
		property ManagedVulkan::VkFormat Format
		{
			ManagedVulkan::VkFormat get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::VkFormat value)
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
	internal:
		void CopyTo(VkVertexInputAttributeDescription* dst, List<IntPtr>^ pins)
		{
			dst->location =	mLocation;
			dst->binding =	mBinding;
			dst->format =	mFormat;
			dst->offset =	mOffset;
		}

		void CopyFrom(VkVertexInputAttributeDescription* src)
		{
			mLocation = src->location;
			mBinding = src->binding;
			mFormat = src->format;
			mOffset = src->offset;
		}
	};

	public ref class PipelineVertexInputStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mVertexBindingDescriptionCount = 0;
		VertexInputBindingDescription^ mVertexBindingDescriptions = gcnew VertexInputBindingDescription();
		UInt32 mVertexAttributeDescriptionCount = 0;
		VertexInputAttributeDescription^ mVertexAttributeDescriptions = gcnew VertexInputAttributeDescription();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VertexInputBindingDescription^ VertexBindingDescriptions
		{
			ManagedVulkan::VertexInputBindingDescription^ get()
			{
				return mVertexBindingDescriptions;
			}
			void set(ManagedVulkan::VertexInputBindingDescription^ value)
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
		property ManagedVulkan::VertexInputAttributeDescription^ VertexAttributeDescriptions
		{
			ManagedVulkan::VertexInputAttributeDescription^ get()
			{
				return mVertexAttributeDescriptions;
			}
			void set(ManagedVulkan::VertexInputAttributeDescription^ value)
			{
				mVertexAttributeDescriptions = value; 
			}
		}
	internal:
		void CopyTo(VkPipelineVertexInputStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->vertexBindingDescriptionCount =	mVertexBindingDescriptionCount;
			mVertexBindingDescriptions->CopyFrom(&dst->pVertexBindingDescriptions, pins);
			dst->vertexAttributeDescriptionCount =	mVertexAttributeDescriptionCount;
			mVertexAttributeDescriptions->CopyFrom(&dst->pVertexAttributeDescriptions, pins);
		}

		void CopyFrom(VkPipelineVertexInputStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mVertexBindingDescriptionCount = src->vertexBindingDescriptionCount;
			mVertexBindingDescriptions->CopyTo(&src->pVertexBindingDescriptions);
			mVertexAttributeDescriptionCount = src->vertexAttributeDescriptionCount;
			mVertexAttributeDescriptions->CopyTo(&src->pVertexAttributeDescriptions);
		}
	};

	public ref class PipelineInputAssemblyStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		VkPrimitiveTopology mTopology;
		bool mPrimitiveRestartEnable = false;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkPrimitiveTopology Topology
		{
			ManagedVulkan::VkPrimitiveTopology get()
			{
				return mTopology;
			}
			void set(ManagedVulkan::VkPrimitiveTopology value)
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
	internal:
		void CopyTo(VkPipelineInputAssemblyStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->topology =	mTopology;
			dst->primitiveRestartEnable =	mPrimitiveRestartEnable ? 1 : 0;
		}

		void CopyFrom(VkPipelineInputAssemblyStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mTopology = src->topology;
			mPrimitiveRestartEnable = src->primitiveRestartEnable != 0;
		}
	};

	public ref class PipelineTessellationStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mPatchControlPoints = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkPipelineTessellationStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->patchControlPoints =	mPatchControlPoints;
		}

		void CopyFrom(VkPipelineTessellationStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mPatchControlPoints = src->patchControlPoints;
		}
	};

	public ref class PipelineViewportStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mViewportCount = 0;
		Viewport^ mViewports = gcnew Viewport();
		UInt32 mScissorCount = 0;
		Rect2D^ mScissors = gcnew Rect2D();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::Viewport^ Viewports
		{
			ManagedVulkan::Viewport^ get()
			{
				return mViewports;
			}
			void set(ManagedVulkan::Viewport^ value)
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
		property ManagedVulkan::Rect2D^ Scissors
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mScissors;
			}
			void set(ManagedVulkan::Rect2D^ value)
			{
				mScissors = value; 
			}
		}
	internal:
		void CopyTo(VkPipelineViewportStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->viewportCount =	mViewportCount;
			mViewports->CopyFrom(&dst->pViewports, pins);
			dst->scissorCount =	mScissorCount;
			mScissors->CopyFrom(&dst->pScissors, pins);
		}

		void CopyFrom(VkPipelineViewportStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mViewportCount = src->viewportCount;
			mViewports->CopyTo(&src->pViewports);
			mScissorCount = src->scissorCount;
			mScissors->CopyTo(&src->pScissors);
		}
	};

	public ref class PipelineRasterizationStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		bool mDepthClampEnable = false;
		bool mRasterizerDiscardEnable = false;
		VkPolygonMode mPolygonMode;
		UInt32 mCullMode;
		VkFrontFace mFrontFace;
		bool mDepthBiasEnable = false;
		float mDepthBiasConstantFactor = 0f;
		float mDepthBiasClamp = 0f;
		float mDepthBiasSlopeFactor = 0f;
		float mLineWidth = 0f;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkPolygonMode PolygonMode
		{
			ManagedVulkan::VkPolygonMode get()
			{
				return mPolygonMode;
			}
			void set(ManagedVulkan::VkPolygonMode value)
			{
				mPolygonMode = value; 
			}
		}
		property UInt32 CullMode
		{
			UInt32 get()
			{
				return mCullMode;
			}
			void set(UInt32 value)
			{
				mCullMode = value; 
			}
		}
		property ManagedVulkan::VkFrontFace FrontFace
		{
			ManagedVulkan::VkFrontFace get()
			{
				return mFrontFace;
			}
			void set(ManagedVulkan::VkFrontFace value)
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
	internal:
		void CopyTo(VkPipelineRasterizationStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->depthClampEnable =	mDepthClampEnable ? 1 : 0;
			dst->rasterizerDiscardEnable =	mRasterizerDiscardEnable ? 1 : 0;
			dst->polygonMode =	mPolygonMode;
			dst->cullMode =	mCullMode;
			dst->frontFace =	mFrontFace;
			dst->depthBiasEnable =	mDepthBiasEnable ? 1 : 0;
			dst->depthBiasConstantFactor =	mDepthBiasConstantFactor;
			dst->depthBiasClamp =	mDepthBiasClamp;
			dst->depthBiasSlopeFactor =	mDepthBiasSlopeFactor;
			dst->lineWidth =	mLineWidth;
		}

		void CopyFrom(VkPipelineRasterizationStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mDepthClampEnable = src->depthClampEnable != 0;
			mRasterizerDiscardEnable = src->rasterizerDiscardEnable != 0;
			mPolygonMode = src->polygonMode;
			mCullMode = src->cullMode;
			mFrontFace = src->frontFace;
			mDepthBiasEnable = src->depthBiasEnable != 0;
			mDepthBiasConstantFactor = src->depthBiasConstantFactor;
			mDepthBiasClamp = src->depthBiasClamp;
			mDepthBiasSlopeFactor = src->depthBiasSlopeFactor;
			mLineWidth = src->lineWidth;
		}
	};

	public ref class PipelineMultisampleStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		VkSampleCountFlagBits mRasterizationSamples;
		bool mSampleShadingEnable = false;
		float mMinSampleShading = 0f;
		VkSampleMask* mSampleMask;
		bool mAlphaToCoverageEnable = false;
		bool mAlphaToOneEnable = false;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkSampleCountFlagBits RasterizationSamples
		{
			ManagedVulkan::VkSampleCountFlagBits get()
			{
				return mRasterizationSamples;
			}
			void set(ManagedVulkan::VkSampleCountFlagBits value)
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
	internal:
		void CopyTo(VkPipelineMultisampleStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->rasterizationSamples =	mRasterizationSamples;
			dst->sampleShadingEnable =	mSampleShadingEnable ? 1 : 0;
			dst->minSampleShading =	mMinSampleShading;
			dst->pSampleMask =	mSampleMask;
			dst->alphaToCoverageEnable =	mAlphaToCoverageEnable ? 1 : 0;
			dst->alphaToOneEnable =	mAlphaToOneEnable ? 1 : 0;
		}

		void CopyFrom(VkPipelineMultisampleStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mRasterizationSamples = src->rasterizationSamples;
			mSampleShadingEnable = src->sampleShadingEnable != 0;
			mMinSampleShading = src->minSampleShading;
			mSampleMask = src->pSampleMask;
			mAlphaToCoverageEnable = src->alphaToCoverageEnable != 0;
			mAlphaToOneEnable = src->alphaToOneEnable != 0;
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
		UInt32 mColorWriteMask;
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
		property ManagedVulkan::VkBlendFactor SrcColorBlendFactor
		{
			ManagedVulkan::VkBlendFactor get()
			{
				return mSrcColorBlendFactor;
			}
			void set(ManagedVulkan::VkBlendFactor value)
			{
				mSrcColorBlendFactor = value; 
			}
		}
		property ManagedVulkan::VkBlendFactor DstColorBlendFactor
		{
			ManagedVulkan::VkBlendFactor get()
			{
				return mDstColorBlendFactor;
			}
			void set(ManagedVulkan::VkBlendFactor value)
			{
				mDstColorBlendFactor = value; 
			}
		}
		property ManagedVulkan::VkBlendOp ColorBlendOp
		{
			ManagedVulkan::VkBlendOp get()
			{
				return mColorBlendOp;
			}
			void set(ManagedVulkan::VkBlendOp value)
			{
				mColorBlendOp = value; 
			}
		}
		property ManagedVulkan::VkBlendFactor SrcAlphaBlendFactor
		{
			ManagedVulkan::VkBlendFactor get()
			{
				return mSrcAlphaBlendFactor;
			}
			void set(ManagedVulkan::VkBlendFactor value)
			{
				mSrcAlphaBlendFactor = value; 
			}
		}
		property ManagedVulkan::VkBlendFactor DstAlphaBlendFactor
		{
			ManagedVulkan::VkBlendFactor get()
			{
				return mDstAlphaBlendFactor;
			}
			void set(ManagedVulkan::VkBlendFactor value)
			{
				mDstAlphaBlendFactor = value; 
			}
		}
		property ManagedVulkan::VkBlendOp AlphaBlendOp
		{
			ManagedVulkan::VkBlendOp get()
			{
				return mAlphaBlendOp;
			}
			void set(ManagedVulkan::VkBlendOp value)
			{
				mAlphaBlendOp = value; 
			}
		}
		property UInt32 ColorWriteMask
		{
			UInt32 get()
			{
				return mColorWriteMask;
			}
			void set(UInt32 value)
			{
				mColorWriteMask = value; 
			}
		}
	internal:
		void CopyTo(VkPipelineColorBlendAttachmentState* dst, List<IntPtr>^ pins)
		{
			dst->blendEnable =	mBlendEnable ? 1 : 0;
			dst->srcColorBlendFactor =	mSrcColorBlendFactor;
			dst->dstColorBlendFactor =	mDstColorBlendFactor;
			dst->colorBlendOp =	mColorBlendOp;
			dst->srcAlphaBlendFactor =	mSrcAlphaBlendFactor;
			dst->dstAlphaBlendFactor =	mDstAlphaBlendFactor;
			dst->alphaBlendOp =	mAlphaBlendOp;
			dst->colorWriteMask =	mColorWriteMask;
		}

		void CopyFrom(VkPipelineColorBlendAttachmentState* src)
		{
			mBlendEnable = src->blendEnable != 0;
			mSrcColorBlendFactor = src->srcColorBlendFactor;
			mDstColorBlendFactor = src->dstColorBlendFactor;
			mColorBlendOp = src->colorBlendOp;
			mSrcAlphaBlendFactor = src->srcAlphaBlendFactor;
			mDstAlphaBlendFactor = src->dstAlphaBlendFactor;
			mAlphaBlendOp = src->alphaBlendOp;
			mColorWriteMask = src->colorWriteMask;
		}
	};

	public ref class PipelineColorBlendStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		bool mLogicOpEnable = false;
		VkLogicOp mLogicOp;
		UInt32 mAttachmentCount = 0;
		PipelineColorBlendAttachmentState^ mAttachments = gcnew PipelineColorBlendAttachmentState();
		blendConstants m4;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkLogicOp LogicOp
		{
			ManagedVulkan::VkLogicOp get()
			{
				return mLogicOp;
			}
			void set(ManagedVulkan::VkLogicOp value)
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
		property ManagedVulkan::PipelineColorBlendAttachmentState^ Attachments
		{
			ManagedVulkan::PipelineColorBlendAttachmentState^ get()
			{
				return mAttachments;
			}
			void set(ManagedVulkan::PipelineColorBlendAttachmentState^ value)
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
	internal:
		void CopyTo(VkPipelineColorBlendStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->logicOpEnable =	mLogicOpEnable ? 1 : 0;
			dst->logicOp =	mLogicOp;
			dst->attachmentCount =	mAttachmentCount;
			mAttachments->CopyFrom(&dst->pAttachments, pins);
			dst->4 =	m4;
		}

		void CopyFrom(VkPipelineColorBlendStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mLogicOpEnable = src->logicOpEnable != 0;
			mLogicOp = src->logicOp;
			mAttachmentCount = src->attachmentCount;
			mAttachments->CopyTo(&src->pAttachments);
			m4 = src->4;
		}
	};

	public ref class PipelineDynamicStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mDynamicStateCount = 0;
		VkDynamicState mDynamicStates;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkDynamicState DynamicStates
		{
			ManagedVulkan::VkDynamicState get()
			{
				return mDynamicStates;
			}
			void set(ManagedVulkan::VkDynamicState value)
			{
				mDynamicStates = value; 
			}
		}
	internal:
		void CopyTo(VkPipelineDynamicStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->dynamicStateCount =	mDynamicStateCount;
			dst->pDynamicStates =	mDynamicStates;
		}

		void CopyFrom(VkPipelineDynamicStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mDynamicStateCount = src->dynamicStateCount;
			mDynamicStates = src->pDynamicStates;
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
		property ManagedVulkan::VkStencilOp FailOp
		{
			ManagedVulkan::VkStencilOp get()
			{
				return mFailOp;
			}
			void set(ManagedVulkan::VkStencilOp value)
			{
				mFailOp = value; 
			}
		}
		property ManagedVulkan::VkStencilOp PassOp
		{
			ManagedVulkan::VkStencilOp get()
			{
				return mPassOp;
			}
			void set(ManagedVulkan::VkStencilOp value)
			{
				mPassOp = value; 
			}
		}
		property ManagedVulkan::VkStencilOp DepthFailOp
		{
			ManagedVulkan::VkStencilOp get()
			{
				return mDepthFailOp;
			}
			void set(ManagedVulkan::VkStencilOp value)
			{
				mDepthFailOp = value; 
			}
		}
		property ManagedVulkan::VkCompareOp CompareOp
		{
			ManagedVulkan::VkCompareOp get()
			{
				return mCompareOp;
			}
			void set(ManagedVulkan::VkCompareOp value)
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
	internal:
		void CopyTo(VkStencilOpState* dst, List<IntPtr>^ pins)
		{
			dst->failOp =	mFailOp;
			dst->passOp =	mPassOp;
			dst->depthFailOp =	mDepthFailOp;
			dst->compareOp =	mCompareOp;
			dst->compareMask =	mCompareMask;
			dst->writeMask =	mWriteMask;
			dst->reference =	mReference;
		}

		void CopyFrom(VkStencilOpState* src)
		{
			mFailOp = src->failOp;
			mPassOp = src->passOp;
			mDepthFailOp = src->depthFailOp;
			mCompareOp = src->compareOp;
			mCompareMask = src->compareMask;
			mWriteMask = src->writeMask;
			mReference = src->reference;
		}
	};

	public ref class PipelineDepthStencilStateCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		bool mDepthTestEnable = false;
		bool mDepthWriteEnable = false;
		VkCompareOp mDepthCompareOp;
		bool mDepthBoundsTestEnable = false;
		bool mStencilTestEnable = false;
		StencilOpState^ mFront = gcnew StencilOpState();
		StencilOpState^ mBack = gcnew StencilOpState();
		float mMinDepthBounds = 0f;
		float mMaxDepthBounds = 0f;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkCompareOp DepthCompareOp
		{
			ManagedVulkan::VkCompareOp get()
			{
				return mDepthCompareOp;
			}
			void set(ManagedVulkan::VkCompareOp value)
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
		property ManagedVulkan::StencilOpState^ Front
		{
			ManagedVulkan::StencilOpState^ get()
			{
				return mFront;
			}
			void set(ManagedVulkan::StencilOpState^ value)
			{
				mFront = value; 
			}
		}
		property ManagedVulkan::StencilOpState^ Back
		{
			ManagedVulkan::StencilOpState^ get()
			{
				return mBack;
			}
			void set(ManagedVulkan::StencilOpState^ value)
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
	internal:
		void CopyTo(VkPipelineDepthStencilStateCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->depthTestEnable =	mDepthTestEnable ? 1 : 0;
			dst->depthWriteEnable =	mDepthWriteEnable ? 1 : 0;
			dst->depthCompareOp =	mDepthCompareOp;
			dst->depthBoundsTestEnable =	mDepthBoundsTestEnable ? 1 : 0;
			dst->stencilTestEnable =	mStencilTestEnable ? 1 : 0;
			mFront->CopyFrom(&dst->front, pins);
			mBack->CopyFrom(&dst->back, pins);
			dst->minDepthBounds =	mMinDepthBounds;
			dst->maxDepthBounds =	mMaxDepthBounds;
		}

		void CopyFrom(VkPipelineDepthStencilStateCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mDepthTestEnable = src->depthTestEnable != 0;
			mDepthWriteEnable = src->depthWriteEnable != 0;
			mDepthCompareOp = src->depthCompareOp;
			mDepthBoundsTestEnable = src->depthBoundsTestEnable != 0;
			mStencilTestEnable = src->stencilTestEnable != 0;
			mFront->CopyTo(&src->front);
			mBack->CopyTo(&src->back);
			mMinDepthBounds = src->minDepthBounds;
			mMaxDepthBounds = src->maxDepthBounds;
		}
	};

	public ref class GraphicsPipelineCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mStageCount = 0;
		PipelineShaderStageCreateInfo^ mStages = gcnew PipelineShaderStageCreateInfo();
		PipelineVertexInputStateCreateInfo^ mVertexInputState = gcnew PipelineVertexInputStateCreateInfo();
		PipelineInputAssemblyStateCreateInfo^ mInputAssemblyState = gcnew PipelineInputAssemblyStateCreateInfo();
		PipelineTessellationStateCreateInfo^ mTessellationState = gcnew PipelineTessellationStateCreateInfo();
		PipelineViewportStateCreateInfo^ mViewportState = gcnew PipelineViewportStateCreateInfo();
		PipelineRasterizationStateCreateInfo^ mRasterizationState = gcnew PipelineRasterizationStateCreateInfo();
		PipelineMultisampleStateCreateInfo^ mMultisampleState = gcnew PipelineMultisampleStateCreateInfo();
		PipelineDepthStencilStateCreateInfo^ mDepthStencilState = gcnew PipelineDepthStencilStateCreateInfo();
		PipelineColorBlendStateCreateInfo^ mColorBlendState = gcnew PipelineColorBlendStateCreateInfo();
		PipelineDynamicStateCreateInfo^ mDynamicState = gcnew PipelineDynamicStateCreateInfo();
		PipelineLayout^ mLayout = gcnew PipelineLayout();
		RenderPass^ mRenderPass = gcnew RenderPass();
		UInt32 mSubpass = 0;
		Pipeline^ mBasePipelineHandle = gcnew Pipeline();
		Int32 mBasePipelineIndex = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::PipelineShaderStageCreateInfo^ Stages
		{
			ManagedVulkan::PipelineShaderStageCreateInfo^ get()
			{
				return mStages;
			}
			void set(ManagedVulkan::PipelineShaderStageCreateInfo^ value)
			{
				mStages = value; 
			}
		}
		property ManagedVulkan::PipelineVertexInputStateCreateInfo^ VertexInputState
		{
			ManagedVulkan::PipelineVertexInputStateCreateInfo^ get()
			{
				return mVertexInputState;
			}
			void set(ManagedVulkan::PipelineVertexInputStateCreateInfo^ value)
			{
				mVertexInputState = value; 
			}
		}
		property ManagedVulkan::PipelineInputAssemblyStateCreateInfo^ InputAssemblyState
		{
			ManagedVulkan::PipelineInputAssemblyStateCreateInfo^ get()
			{
				return mInputAssemblyState;
			}
			void set(ManagedVulkan::PipelineInputAssemblyStateCreateInfo^ value)
			{
				mInputAssemblyState = value; 
			}
		}
		property ManagedVulkan::PipelineTessellationStateCreateInfo^ TessellationState
		{
			ManagedVulkan::PipelineTessellationStateCreateInfo^ get()
			{
				return mTessellationState;
			}
			void set(ManagedVulkan::PipelineTessellationStateCreateInfo^ value)
			{
				mTessellationState = value; 
			}
		}
		property ManagedVulkan::PipelineViewportStateCreateInfo^ ViewportState
		{
			ManagedVulkan::PipelineViewportStateCreateInfo^ get()
			{
				return mViewportState;
			}
			void set(ManagedVulkan::PipelineViewportStateCreateInfo^ value)
			{
				mViewportState = value; 
			}
		}
		property ManagedVulkan::PipelineRasterizationStateCreateInfo^ RasterizationState
		{
			ManagedVulkan::PipelineRasterizationStateCreateInfo^ get()
			{
				return mRasterizationState;
			}
			void set(ManagedVulkan::PipelineRasterizationStateCreateInfo^ value)
			{
				mRasterizationState = value; 
			}
		}
		property ManagedVulkan::PipelineMultisampleStateCreateInfo^ MultisampleState
		{
			ManagedVulkan::PipelineMultisampleStateCreateInfo^ get()
			{
				return mMultisampleState;
			}
			void set(ManagedVulkan::PipelineMultisampleStateCreateInfo^ value)
			{
				mMultisampleState = value; 
			}
		}
		property ManagedVulkan::PipelineDepthStencilStateCreateInfo^ DepthStencilState
		{
			ManagedVulkan::PipelineDepthStencilStateCreateInfo^ get()
			{
				return mDepthStencilState;
			}
			void set(ManagedVulkan::PipelineDepthStencilStateCreateInfo^ value)
			{
				mDepthStencilState = value; 
			}
		}
		property ManagedVulkan::PipelineColorBlendStateCreateInfo^ ColorBlendState
		{
			ManagedVulkan::PipelineColorBlendStateCreateInfo^ get()
			{
				return mColorBlendState;
			}
			void set(ManagedVulkan::PipelineColorBlendStateCreateInfo^ value)
			{
				mColorBlendState = value; 
			}
		}
		property ManagedVulkan::PipelineDynamicStateCreateInfo^ DynamicState
		{
			ManagedVulkan::PipelineDynamicStateCreateInfo^ get()
			{
				return mDynamicState;
			}
			void set(ManagedVulkan::PipelineDynamicStateCreateInfo^ value)
			{
				mDynamicState = value; 
			}
		}
		property ManagedVulkan::PipelineLayout^ Layout
		{
			ManagedVulkan::PipelineLayout^ get()
			{
				return mLayout;
			}
			void set(ManagedVulkan::PipelineLayout^ value)
			{
				mLayout = value; 
			}
		}
		property ManagedVulkan::RenderPass^ RenderPass
		{
			ManagedVulkan::RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(ManagedVulkan::RenderPass^ value)
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
		property ManagedVulkan::Pipeline^ BasePipelineHandle
		{
			ManagedVulkan::Pipeline^ get()
			{
				return mBasePipelineHandle;
			}
			void set(ManagedVulkan::Pipeline^ value)
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
	internal:
		void CopyTo(VkGraphicsPipelineCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->stageCount =	mStageCount;
			mStages->CopyFrom(&dst->pStages, pins);
			mVertexInputState->CopyFrom(&dst->pVertexInputState, pins);
			mInputAssemblyState->CopyFrom(&dst->pInputAssemblyState, pins);
			mTessellationState->CopyFrom(&dst->pTessellationState, pins);
			mViewportState->CopyFrom(&dst->pViewportState, pins);
			mRasterizationState->CopyFrom(&dst->pRasterizationState, pins);
			mMultisampleState->CopyFrom(&dst->pMultisampleState, pins);
			mDepthStencilState->CopyFrom(&dst->pDepthStencilState, pins);
			mColorBlendState->CopyFrom(&dst->pColorBlendState, pins);
			mDynamicState->CopyFrom(&dst->pDynamicState, pins);
			dst->layout =	mLayout;
			dst->renderPass =	mRenderPass;
			dst->subpass =	mSubpass;
			dst->basePipelineHandle =	mBasePipelineHandle;
			dst->basePipelineIndex =	mBasePipelineIndex;
		}

		void CopyFrom(VkGraphicsPipelineCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mStageCount = src->stageCount;
			mStages->CopyTo(&src->pStages);
			mVertexInputState->CopyTo(&src->pVertexInputState);
			mInputAssemblyState->CopyTo(&src->pInputAssemblyState);
			mTessellationState->CopyTo(&src->pTessellationState);
			mViewportState->CopyTo(&src->pViewportState);
			mRasterizationState->CopyTo(&src->pRasterizationState);
			mMultisampleState->CopyTo(&src->pMultisampleState);
			mDepthStencilState->CopyTo(&src->pDepthStencilState);
			mColorBlendState->CopyTo(&src->pColorBlendState);
			mDynamicState->CopyTo(&src->pDynamicState);
			mLayout = src->layout;
			mRenderPass = src->renderPass;
			mSubpass = src->subpass;
			mBasePipelineHandle = src->basePipelineHandle;
			mBasePipelineIndex = src->basePipelineIndex;
		}
	};

	public ref class PipelineCacheCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		IntPtr mInitialDataSize = 0;
		IntPtr mInitialData = IntPtr::Zero;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkPipelineCacheCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->initialDataSize =	mInitialDataSize;
			dst->pInitialData =	mInitialData;
		}

		void CopyFrom(VkPipelineCacheCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mInitialDataSize = src->initialDataSize;
			mInitialData = src->pInitialData;
		}
	};

	public ref class PushConstantRange
	{
	private:
		UInt32 mStageFlags;
		UInt32 mOffset = 0;
		UInt32 mSize = 0;
	public:
		property UInt32 StageFlags
		{
			UInt32 get()
			{
				return mStageFlags;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkPushConstantRange* dst, List<IntPtr>^ pins)
		{
			dst->stageFlags =	mStageFlags;
			dst->offset =	mOffset;
			dst->size =	mSize;
		}

		void CopyFrom(VkPushConstantRange* src)
		{
			mStageFlags = src->stageFlags;
			mOffset = src->offset;
			mSize = src->size;
		}
	};

	public ref class PipelineLayoutCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mSetLayoutCount = 0;
		DescriptorSetLayout^ mSetLayouts = gcnew DescriptorSetLayout();
		UInt32 mPushConstantRangeCount = 0;
		PushConstantRange^ mPushConstantRanges = gcnew PushConstantRange();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::DescriptorSetLayout^ SetLayouts
		{
			ManagedVulkan::DescriptorSetLayout^ get()
			{
				return mSetLayouts;
			}
			void set(ManagedVulkan::DescriptorSetLayout^ value)
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
		property ManagedVulkan::PushConstantRange^ PushConstantRanges
		{
			ManagedVulkan::PushConstantRange^ get()
			{
				return mPushConstantRanges;
			}
			void set(ManagedVulkan::PushConstantRange^ value)
			{
				mPushConstantRanges = value; 
			}
		}
	internal:
		void CopyTo(VkPipelineLayoutCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->setLayoutCount =	mSetLayoutCount;
			dst->pSetLayouts =	mSetLayouts;
			dst->pushConstantRangeCount =	mPushConstantRangeCount;
			mPushConstantRanges->CopyFrom(&dst->pPushConstantRanges, pins);
		}

		void CopyFrom(VkPipelineLayoutCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mSetLayoutCount = src->setLayoutCount;
			mSetLayouts = src->pSetLayouts;
			mPushConstantRangeCount = src->pushConstantRangeCount;
			mPushConstantRanges->CopyTo(&src->pPushConstantRanges);
		}
	};

	public ref class SamplerCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
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
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkFilter MagFilter
		{
			ManagedVulkan::VkFilter get()
			{
				return mMagFilter;
			}
			void set(ManagedVulkan::VkFilter value)
			{
				mMagFilter = value; 
			}
		}
		property ManagedVulkan::VkFilter MinFilter
		{
			ManagedVulkan::VkFilter get()
			{
				return mMinFilter;
			}
			void set(ManagedVulkan::VkFilter value)
			{
				mMinFilter = value; 
			}
		}
		property ManagedVulkan::VkSamplerMipmapMode MipmapMode
		{
			ManagedVulkan::VkSamplerMipmapMode get()
			{
				return mMipmapMode;
			}
			void set(ManagedVulkan::VkSamplerMipmapMode value)
			{
				mMipmapMode = value; 
			}
		}
		property ManagedVulkan::VkSamplerAddressMode AddressModeU
		{
			ManagedVulkan::VkSamplerAddressMode get()
			{
				return mAddressModeU;
			}
			void set(ManagedVulkan::VkSamplerAddressMode value)
			{
				mAddressModeU = value; 
			}
		}
		property ManagedVulkan::VkSamplerAddressMode AddressModeV
		{
			ManagedVulkan::VkSamplerAddressMode get()
			{
				return mAddressModeV;
			}
			void set(ManagedVulkan::VkSamplerAddressMode value)
			{
				mAddressModeV = value; 
			}
		}
		property ManagedVulkan::VkSamplerAddressMode AddressModeW
		{
			ManagedVulkan::VkSamplerAddressMode get()
			{
				return mAddressModeW;
			}
			void set(ManagedVulkan::VkSamplerAddressMode value)
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
		property ManagedVulkan::VkCompareOp CompareOp
		{
			ManagedVulkan::VkCompareOp get()
			{
				return mCompareOp;
			}
			void set(ManagedVulkan::VkCompareOp value)
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
		property ManagedVulkan::VkBorderColor BorderColor
		{
			ManagedVulkan::VkBorderColor get()
			{
				return mBorderColor;
			}
			void set(ManagedVulkan::VkBorderColor value)
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
	internal:
		void CopyTo(VkSamplerCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->magFilter =	mMagFilter;
			dst->minFilter =	mMinFilter;
			dst->mipmapMode =	mMipmapMode;
			dst->addressModeU =	mAddressModeU;
			dst->addressModeV =	mAddressModeV;
			dst->addressModeW =	mAddressModeW;
			dst->mipLodBias =	mMipLodBias;
			dst->anisotropyEnable =	mAnisotropyEnable ? 1 : 0;
			dst->maxAnisotropy =	mMaxAnisotropy;
			dst->compareEnable =	mCompareEnable ? 1 : 0;
			dst->compareOp =	mCompareOp;
			dst->minLod =	mMinLod;
			dst->maxLod =	mMaxLod;
			dst->borderColor =	mBorderColor;
			dst->unnormalizedCoordinates =	mUnnormalizedCoordinates ? 1 : 0;
		}

		void CopyFrom(VkSamplerCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mMagFilter = src->magFilter;
			mMinFilter = src->minFilter;
			mMipmapMode = src->mipmapMode;
			mAddressModeU = src->addressModeU;
			mAddressModeV = src->addressModeV;
			mAddressModeW = src->addressModeW;
			mMipLodBias = src->mipLodBias;
			mAnisotropyEnable = src->anisotropyEnable != 0;
			mMaxAnisotropy = src->maxAnisotropy;
			mCompareEnable = src->compareEnable != 0;
			mCompareOp = src->compareOp;
			mMinLod = src->minLod;
			mMaxLod = src->maxLod;
			mBorderColor = src->borderColor;
			mUnnormalizedCoordinates = src->unnormalizedCoordinates != 0;
		}
	};

	public ref class CommandPoolCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mQueueFamilyIndex = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkCommandPoolCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->queueFamilyIndex =	mQueueFamilyIndex;
		}

		void CopyFrom(VkCommandPoolCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mQueueFamilyIndex = src->queueFamilyIndex;
		}
	};

	public ref class CommandBufferAllocateInfo
	{
	private:
		VkStructureType mSType;
		CommandPool^ mCommandPool = gcnew CommandPool();
		VkCommandBufferLevel mLevel;
		UInt32 mCommandBufferCount = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::CommandPool^ CommandPool
		{
			ManagedVulkan::CommandPool^ get()
			{
				return mCommandPool;
			}
			void set(ManagedVulkan::CommandPool^ value)
			{
				mCommandPool = value; 
			}
		}
		property ManagedVulkan::VkCommandBufferLevel Level
		{
			ManagedVulkan::VkCommandBufferLevel get()
			{
				return mLevel;
			}
			void set(ManagedVulkan::VkCommandBufferLevel value)
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
	internal:
		void CopyTo(VkCommandBufferAllocateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->commandPool =	mCommandPool;
			dst->level =	mLevel;
			dst->commandBufferCount =	mCommandBufferCount;
		}

		void CopyFrom(VkCommandBufferAllocateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mCommandPool = src->commandPool;
			mLevel = src->level;
			mCommandBufferCount = src->commandBufferCount;
		}
	};

	public ref class CommandBufferInheritanceInfo
	{
	private:
		VkStructureType mSType;
		RenderPass^ mRenderPass = gcnew RenderPass();
		UInt32 mSubpass = 0;
		Framebuffer^ mFramebuffer = gcnew Framebuffer();
		bool mOcclusionQueryEnable = false;
		UInt32 mQueryFlags;
		UInt32 mPipelineStatistics;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::RenderPass^ RenderPass
		{
			ManagedVulkan::RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(ManagedVulkan::RenderPass^ value)
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
		property ManagedVulkan::Framebuffer^ Framebuffer
		{
			ManagedVulkan::Framebuffer^ get()
			{
				return mFramebuffer;
			}
			void set(ManagedVulkan::Framebuffer^ value)
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
		property UInt32 QueryFlags
		{
			UInt32 get()
			{
				return mQueryFlags;
			}
			void set(UInt32 value)
			{
				mQueryFlags = value; 
			}
		}
		property UInt32 PipelineStatistics
		{
			UInt32 get()
			{
				return mPipelineStatistics;
			}
			void set(UInt32 value)
			{
				mPipelineStatistics = value; 
			}
		}
	internal:
		void CopyTo(VkCommandBufferInheritanceInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->renderPass =	mRenderPass;
			dst->subpass =	mSubpass;
			dst->framebuffer =	mFramebuffer;
			dst->occlusionQueryEnable =	mOcclusionQueryEnable ? 1 : 0;
			dst->queryFlags =	mQueryFlags;
			dst->pipelineStatistics =	mPipelineStatistics;
		}

		void CopyFrom(VkCommandBufferInheritanceInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mRenderPass = src->renderPass;
			mSubpass = src->subpass;
			mFramebuffer = src->framebuffer;
			mOcclusionQueryEnable = src->occlusionQueryEnable != 0;
			mQueryFlags = src->queryFlags;
			mPipelineStatistics = src->pipelineStatistics;
		}
	};

	public ref class CommandBufferBeginInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		CommandBufferInheritanceInfo^ mInheritanceInfo = gcnew CommandBufferInheritanceInfo();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::CommandBufferInheritanceInfo^ InheritanceInfo
		{
			ManagedVulkan::CommandBufferInheritanceInfo^ get()
			{
				return mInheritanceInfo;
			}
			void set(ManagedVulkan::CommandBufferInheritanceInfo^ value)
			{
				mInheritanceInfo = value; 
			}
		}
	internal:
		void CopyTo(VkCommandBufferBeginInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			mInheritanceInfo->CopyFrom(&dst->pInheritanceInfo, pins);
		}

		void CopyFrom(VkCommandBufferBeginInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mInheritanceInfo->CopyTo(&src->pInheritanceInfo);
		}
	};

	public ref class RenderPassBeginInfo
	{
	private:
		VkStructureType mSType;
		RenderPass^ mRenderPass = gcnew RenderPass();
		Framebuffer^ mFramebuffer = gcnew Framebuffer();
		Rect2D^ mRenderArea = gcnew Rect2D();
		UInt32 mClearValueCount = 0;
		ClearValue^ mClearValues = nullptr;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::RenderPass^ RenderPass
		{
			ManagedVulkan::RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(ManagedVulkan::RenderPass^ value)
			{
				mRenderPass = value; 
			}
		}
		property ManagedVulkan::Framebuffer^ Framebuffer
		{
			ManagedVulkan::Framebuffer^ get()
			{
				return mFramebuffer;
			}
			void set(ManagedVulkan::Framebuffer^ value)
			{
				mFramebuffer = value; 
			}
		}
		property ManagedVulkan::Rect2D^ RenderArea
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mRenderArea;
			}
			void set(ManagedVulkan::Rect2D^ value)
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
		property ManagedVulkan::ClearValue^ ClearValues
		{
			ManagedVulkan::ClearValue^ get()
			{
				return mClearValues;
			}
			void set(ManagedVulkan::ClearValue^ value)
			{
				mClearValues = value; 
			}
		}
	internal:
		void CopyTo(VkRenderPassBeginInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->renderPass =	mRenderPass;
			dst->framebuffer =	mFramebuffer;
			mRenderArea->CopyFrom(&dst->renderArea, pins);
			dst->clearValueCount =	mClearValueCount;
			mClearValues->CopyFrom(&dst->pClearValues, pins);
		}

		void CopyFrom(VkRenderPassBeginInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mRenderPass = src->renderPass;
			mFramebuffer = src->framebuffer;
			mRenderArea->CopyTo(&src->renderArea);
			mClearValueCount = src->clearValueCount;
			mClearValues->CopyTo(&src->pClearValues);
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
	internal:
		void CopyTo(VkClearDepthStencilValue* dst, List<IntPtr>^ pins)
		{
			dst->depth =	mDepth;
			dst->stencil =	mStencil;
		}

		void CopyFrom(VkClearDepthStencilValue* src)
		{
			mDepth = src->depth;
			mStencil = src->stencil;
		}
	};

	public ref class ClearAttachment
	{
	private:
		UInt32 mAspectMask;
		UInt32 mColorAttachment = 0;
		ClearValue^ mClearValue = nullptr;
	public:
		property UInt32 AspectMask
		{
			UInt32 get()
			{
				return mAspectMask;
			}
			void set(UInt32 value)
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
		property ManagedVulkan::ClearValue^ ClearValue
		{
			ManagedVulkan::ClearValue^ get()
			{
				return mClearValue;
			}
			void set(ManagedVulkan::ClearValue^ value)
			{
				mClearValue = value; 
			}
		}
	internal:
		void CopyTo(VkClearAttachment* dst, List<IntPtr>^ pins)
		{
			dst->aspectMask =	mAspectMask;
			dst->colorAttachment =	mColorAttachment;
			mClearValue->CopyFrom(&dst->clearValue, pins);
		}

		void CopyFrom(VkClearAttachment* src)
		{
			mAspectMask = src->aspectMask;
			mColorAttachment = src->colorAttachment;
			mClearValue->CopyTo(&src->clearValue);
		}
	};

	public ref class AttachmentDescription
	{
	private:
		UInt32 mFlags;
		VkFormat mFormat;
		VkSampleCountFlagBits mSamples;
		VkAttachmentLoadOp mLoadOp;
		VkAttachmentStoreOp mStoreOp;
		VkAttachmentLoadOp mStencilLoadOp;
		VkAttachmentStoreOp mStencilStoreOp;
		VkImageLayout mInitialLayout;
		VkImageLayout mFinalLayout;
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
		property ManagedVulkan::VkFormat Format
		{
			ManagedVulkan::VkFormat get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::VkFormat value)
			{
				mFormat = value; 
			}
		}
		property ManagedVulkan::VkSampleCountFlagBits Samples
		{
			ManagedVulkan::VkSampleCountFlagBits get()
			{
				return mSamples;
			}
			void set(ManagedVulkan::VkSampleCountFlagBits value)
			{
				mSamples = value; 
			}
		}
		property ManagedVulkan::VkAttachmentLoadOp LoadOp
		{
			ManagedVulkan::VkAttachmentLoadOp get()
			{
				return mLoadOp;
			}
			void set(ManagedVulkan::VkAttachmentLoadOp value)
			{
				mLoadOp = value; 
			}
		}
		property ManagedVulkan::VkAttachmentStoreOp StoreOp
		{
			ManagedVulkan::VkAttachmentStoreOp get()
			{
				return mStoreOp;
			}
			void set(ManagedVulkan::VkAttachmentStoreOp value)
			{
				mStoreOp = value; 
			}
		}
		property ManagedVulkan::VkAttachmentLoadOp StencilLoadOp
		{
			ManagedVulkan::VkAttachmentLoadOp get()
			{
				return mStencilLoadOp;
			}
			void set(ManagedVulkan::VkAttachmentLoadOp value)
			{
				mStencilLoadOp = value; 
			}
		}
		property ManagedVulkan::VkAttachmentStoreOp StencilStoreOp
		{
			ManagedVulkan::VkAttachmentStoreOp get()
			{
				return mStencilStoreOp;
			}
			void set(ManagedVulkan::VkAttachmentStoreOp value)
			{
				mStencilStoreOp = value; 
			}
		}
		property ManagedVulkan::VkImageLayout InitialLayout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mInitialLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
			{
				mInitialLayout = value; 
			}
		}
		property ManagedVulkan::VkImageLayout FinalLayout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mFinalLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
			{
				mFinalLayout = value; 
			}
		}
	internal:
		void CopyTo(VkAttachmentDescription* dst, List<IntPtr>^ pins)
		{
			dst->flags =	mFlags;
			dst->format =	mFormat;
			dst->samples =	mSamples;
			dst->loadOp =	mLoadOp;
			dst->storeOp =	mStoreOp;
			dst->stencilLoadOp =	mStencilLoadOp;
			dst->stencilStoreOp =	mStencilStoreOp;
			dst->initialLayout =	mInitialLayout;
			dst->finalLayout =	mFinalLayout;
		}

		void CopyFrom(VkAttachmentDescription* src)
		{
			mFlags = src->flags;
			mFormat = src->format;
			mSamples = src->samples;
			mLoadOp = src->loadOp;
			mStoreOp = src->storeOp;
			mStencilLoadOp = src->stencilLoadOp;
			mStencilStoreOp = src->stencilStoreOp;
			mInitialLayout = src->initialLayout;
			mFinalLayout = src->finalLayout;
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
		property ManagedVulkan::VkImageLayout Layout
		{
			ManagedVulkan::VkImageLayout get()
			{
				return mLayout;
			}
			void set(ManagedVulkan::VkImageLayout value)
			{
				mLayout = value; 
			}
		}
	internal:
		void CopyTo(VkAttachmentReference* dst, List<IntPtr>^ pins)
		{
			dst->attachment =	mAttachment;
			dst->layout =	mLayout;
		}

		void CopyFrom(VkAttachmentReference* src)
		{
			mAttachment = src->attachment;
			mLayout = src->layout;
		}
	};

	public ref class SubpassDescription
	{
	private:
		UInt32 mFlags;
		VkPipelineBindPoint mPipelineBindPoint;
		UInt32 mInputAttachmentCount = 0;
		AttachmentReference^ mInputAttachments = gcnew AttachmentReference();
		UInt32 mColorAttachmentCount = 0;
		AttachmentReference^ mColorAttachments = gcnew AttachmentReference();
		AttachmentReference^ mResolveAttachments = gcnew AttachmentReference();
		AttachmentReference^ mDepthStencilAttachment = gcnew AttachmentReference();
		UInt32 mPreserveAttachmentCount = 0;
		UInt32 mPreserveAttachments = 0;
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
		property ManagedVulkan::VkPipelineBindPoint PipelineBindPoint
		{
			ManagedVulkan::VkPipelineBindPoint get()
			{
				return mPipelineBindPoint;
			}
			void set(ManagedVulkan::VkPipelineBindPoint value)
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
		property ManagedVulkan::AttachmentReference^ InputAttachments
		{
			ManagedVulkan::AttachmentReference^ get()
			{
				return mInputAttachments;
			}
			void set(ManagedVulkan::AttachmentReference^ value)
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
		property ManagedVulkan::AttachmentReference^ ColorAttachments
		{
			ManagedVulkan::AttachmentReference^ get()
			{
				return mColorAttachments;
			}
			void set(ManagedVulkan::AttachmentReference^ value)
			{
				mColorAttachments = value; 
			}
		}
		property ManagedVulkan::AttachmentReference^ ResolveAttachments
		{
			ManagedVulkan::AttachmentReference^ get()
			{
				return mResolveAttachments;
			}
			void set(ManagedVulkan::AttachmentReference^ value)
			{
				mResolveAttachments = value; 
			}
		}
		property ManagedVulkan::AttachmentReference^ DepthStencilAttachment
		{
			ManagedVulkan::AttachmentReference^ get()
			{
				return mDepthStencilAttachment;
			}
			void set(ManagedVulkan::AttachmentReference^ value)
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
	internal:
		void CopyTo(VkSubpassDescription* dst, List<IntPtr>^ pins)
		{
			dst->flags =	mFlags;
			dst->pipelineBindPoint =	mPipelineBindPoint;
			dst->inputAttachmentCount =	mInputAttachmentCount;
			mInputAttachments->CopyFrom(&dst->pInputAttachments, pins);
			dst->colorAttachmentCount =	mColorAttachmentCount;
			mColorAttachments->CopyFrom(&dst->pColorAttachments, pins);
			mResolveAttachments->CopyFrom(&dst->pResolveAttachments, pins);
			mDepthStencilAttachment->CopyFrom(&dst->pDepthStencilAttachment, pins);
			dst->preserveAttachmentCount =	mPreserveAttachmentCount;
			dst->pPreserveAttachments =	mPreserveAttachments;
		}

		void CopyFrom(VkSubpassDescription* src)
		{
			mFlags = src->flags;
			mPipelineBindPoint = src->pipelineBindPoint;
			mInputAttachmentCount = src->inputAttachmentCount;
			mInputAttachments->CopyTo(&src->pInputAttachments);
			mColorAttachmentCount = src->colorAttachmentCount;
			mColorAttachments->CopyTo(&src->pColorAttachments);
			mResolveAttachments->CopyTo(&src->pResolveAttachments);
			mDepthStencilAttachment->CopyTo(&src->pDepthStencilAttachment);
			mPreserveAttachmentCount = src->preserveAttachmentCount;
			mPreserveAttachments = src->pPreserveAttachments;
		}
	};

	public ref class SubpassDependency
	{
	private:
		UInt32 mSrcSubpass = 0;
		UInt32 mDstSubpass = 0;
		UInt32 mSrcStageMask;
		UInt32 mDstStageMask;
		UInt32 mSrcAccessMask;
		UInt32 mDstAccessMask;
		UInt32 mDependencyFlags;
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
		property UInt32 SrcStageMask
		{
			UInt32 get()
			{
				return mSrcStageMask;
			}
			void set(UInt32 value)
			{
				mSrcStageMask = value; 
			}
		}
		property UInt32 DstStageMask
		{
			UInt32 get()
			{
				return mDstStageMask;
			}
			void set(UInt32 value)
			{
				mDstStageMask = value; 
			}
		}
		property UInt32 SrcAccessMask
		{
			UInt32 get()
			{
				return mSrcAccessMask;
			}
			void set(UInt32 value)
			{
				mSrcAccessMask = value; 
			}
		}
		property UInt32 DstAccessMask
		{
			UInt32 get()
			{
				return mDstAccessMask;
			}
			void set(UInt32 value)
			{
				mDstAccessMask = value; 
			}
		}
		property UInt32 DependencyFlags
		{
			UInt32 get()
			{
				return mDependencyFlags;
			}
			void set(UInt32 value)
			{
				mDependencyFlags = value; 
			}
		}
	internal:
		void CopyTo(VkSubpassDependency* dst, List<IntPtr>^ pins)
		{
			dst->srcSubpass =	mSrcSubpass;
			dst->dstSubpass =	mDstSubpass;
			dst->srcStageMask =	mSrcStageMask;
			dst->dstStageMask =	mDstStageMask;
			dst->srcAccessMask =	mSrcAccessMask;
			dst->dstAccessMask =	mDstAccessMask;
			dst->dependencyFlags =	mDependencyFlags;
		}

		void CopyFrom(VkSubpassDependency* src)
		{
			mSrcSubpass = src->srcSubpass;
			mDstSubpass = src->dstSubpass;
			mSrcStageMask = src->srcStageMask;
			mDstStageMask = src->dstStageMask;
			mSrcAccessMask = src->srcAccessMask;
			mDstAccessMask = src->dstAccessMask;
			mDependencyFlags = src->dependencyFlags;
		}
	};

	public ref class RenderPassCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		UInt32 mAttachmentCount = 0;
		AttachmentDescription^ mAttachments = gcnew AttachmentDescription();
		UInt32 mSubpassCount = 0;
		SubpassDescription^ mSubpasses = gcnew SubpassDescription();
		UInt32 mDependencyCount = 0;
		SubpassDependency^ mDependencies = gcnew SubpassDependency();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::AttachmentDescription^ Attachments
		{
			ManagedVulkan::AttachmentDescription^ get()
			{
				return mAttachments;
			}
			void set(ManagedVulkan::AttachmentDescription^ value)
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
		property ManagedVulkan::SubpassDescription^ Subpasses
		{
			ManagedVulkan::SubpassDescription^ get()
			{
				return mSubpasses;
			}
			void set(ManagedVulkan::SubpassDescription^ value)
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
		property ManagedVulkan::SubpassDependency^ Dependencies
		{
			ManagedVulkan::SubpassDependency^ get()
			{
				return mDependencies;
			}
			void set(ManagedVulkan::SubpassDependency^ value)
			{
				mDependencies = value; 
			}
		}
	internal:
		void CopyTo(VkRenderPassCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->attachmentCount =	mAttachmentCount;
			mAttachments->CopyFrom(&dst->pAttachments, pins);
			dst->subpassCount =	mSubpassCount;
			mSubpasses->CopyFrom(&dst->pSubpasses, pins);
			dst->dependencyCount =	mDependencyCount;
			mDependencies->CopyFrom(&dst->pDependencies, pins);
		}

		void CopyFrom(VkRenderPassCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mAttachmentCount = src->attachmentCount;
			mAttachments->CopyTo(&src->pAttachments);
			mSubpassCount = src->subpassCount;
			mSubpasses->CopyTo(&src->pSubpasses);
			mDependencyCount = src->dependencyCount;
			mDependencies->CopyTo(&src->pDependencies);
		}
	};

	public ref class EventCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkEventCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
		}

		void CopyFrom(VkEventCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
		}
	};

	public ref class FenceCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkFenceCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
		}

		void CopyFrom(VkFenceCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
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
	internal:
		void CopyTo(VkPhysicalDeviceFeatures* dst, List<IntPtr>^ pins)
		{
			dst->robustBufferAccess =	mRobustBufferAccess ? 1 : 0;
			dst->fullDrawIndexUint32 =	mFullDrawIndexUint32 ? 1 : 0;
			dst->imageCubeArray =	mImageCubeArray ? 1 : 0;
			dst->independentBlend =	mIndependentBlend ? 1 : 0;
			dst->geometryShader =	mGeometryShader ? 1 : 0;
			dst->tessellationShader =	mTessellationShader ? 1 : 0;
			dst->sampleRateShading =	mSampleRateShading ? 1 : 0;
			dst->dualSrcBlend =	mDualSrcBlend ? 1 : 0;
			dst->logicOp =	mLogicOp ? 1 : 0;
			dst->multiDrawIndirect =	mMultiDrawIndirect ? 1 : 0;
			dst->drawIndirectFirstInstance =	mDrawIndirectFirstInstance ? 1 : 0;
			dst->depthClamp =	mDepthClamp ? 1 : 0;
			dst->depthBiasClamp =	mDepthBiasClamp ? 1 : 0;
			dst->fillModeNonSolid =	mFillModeNonSolid ? 1 : 0;
			dst->depthBounds =	mDepthBounds ? 1 : 0;
			dst->wideLines =	mWideLines ? 1 : 0;
			dst->largePoints =	mLargePoints ? 1 : 0;
			dst->alphaToOne =	mAlphaToOne ? 1 : 0;
			dst->multiViewport =	mMultiViewport ? 1 : 0;
			dst->samplerAnisotropy =	mSamplerAnisotropy ? 1 : 0;
			dst->textureCompressionETC2 =	mTextureCompressionETC2 ? 1 : 0;
			dst->textureCompressionASTC_LDR =	mTextureCompressionASTC_LDR ? 1 : 0;
			dst->textureCompressionBC =	mTextureCompressionBC ? 1 : 0;
			dst->occlusionQueryPrecise =	mOcclusionQueryPrecise ? 1 : 0;
			dst->pipelineStatisticsQuery =	mPipelineStatisticsQuery ? 1 : 0;
			dst->vertexPipelineStoresAndAtomics =	mVertexPipelineStoresAndAtomics ? 1 : 0;
			dst->fragmentStoresAndAtomics =	mFragmentStoresAndAtomics ? 1 : 0;
			dst->shaderTessellationAndGeometryPointSize =	mShaderTessellationAndGeometryPointSize ? 1 : 0;
			dst->shaderImageGatherExtended =	mShaderImageGatherExtended ? 1 : 0;
			dst->shaderStorageImageExtendedFormats =	mShaderStorageImageExtendedFormats ? 1 : 0;
			dst->shaderStorageImageMultisample =	mShaderStorageImageMultisample ? 1 : 0;
			dst->shaderStorageImageReadWithoutFormat =	mShaderStorageImageReadWithoutFormat ? 1 : 0;
			dst->shaderStorageImageWriteWithoutFormat =	mShaderStorageImageWriteWithoutFormat ? 1 : 0;
			dst->shaderUniformBufferArrayDynamicIndexing =	mShaderUniformBufferArrayDynamicIndexing ? 1 : 0;
			dst->shaderSampledImageArrayDynamicIndexing =	mShaderSampledImageArrayDynamicIndexing ? 1 : 0;
			dst->shaderStorageBufferArrayDynamicIndexing =	mShaderStorageBufferArrayDynamicIndexing ? 1 : 0;
			dst->shaderStorageImageArrayDynamicIndexing =	mShaderStorageImageArrayDynamicIndexing ? 1 : 0;
			dst->shaderClipDistance =	mShaderClipDistance ? 1 : 0;
			dst->shaderCullDistance =	mShaderCullDistance ? 1 : 0;
			dst->shaderFloat64 =	mShaderFloat64 ? 1 : 0;
			dst->shaderInt64 =	mShaderInt64 ? 1 : 0;
			dst->shaderInt16 =	mShaderInt16 ? 1 : 0;
			dst->shaderResourceResidency =	mShaderResourceResidency ? 1 : 0;
			dst->shaderResourceMinLod =	mShaderResourceMinLod ? 1 : 0;
			dst->sparseBinding =	mSparseBinding ? 1 : 0;
			dst->sparseResidencyBuffer =	mSparseResidencyBuffer ? 1 : 0;
			dst->sparseResidencyImage2D =	mSparseResidencyImage2D ? 1 : 0;
			dst->sparseResidencyImage3D =	mSparseResidencyImage3D ? 1 : 0;
			dst->sparseResidency2Samples =	mSparseResidency2Samples ? 1 : 0;
			dst->sparseResidency4Samples =	mSparseResidency4Samples ? 1 : 0;
			dst->sparseResidency8Samples =	mSparseResidency8Samples ? 1 : 0;
			dst->sparseResidency16Samples =	mSparseResidency16Samples ? 1 : 0;
			dst->sparseResidencyAliased =	mSparseResidencyAliased ? 1 : 0;
			dst->variableMultisampleRate =	mVariableMultisampleRate ? 1 : 0;
			dst->inheritedQueries =	mInheritedQueries ? 1 : 0;
		}

		void CopyFrom(VkPhysicalDeviceFeatures* src)
		{
			mRobustBufferAccess = src->robustBufferAccess != 0;
			mFullDrawIndexUint32 = src->fullDrawIndexUint32 != 0;
			mImageCubeArray = src->imageCubeArray != 0;
			mIndependentBlend = src->independentBlend != 0;
			mGeometryShader = src->geometryShader != 0;
			mTessellationShader = src->tessellationShader != 0;
			mSampleRateShading = src->sampleRateShading != 0;
			mDualSrcBlend = src->dualSrcBlend != 0;
			mLogicOp = src->logicOp != 0;
			mMultiDrawIndirect = src->multiDrawIndirect != 0;
			mDrawIndirectFirstInstance = src->drawIndirectFirstInstance != 0;
			mDepthClamp = src->depthClamp != 0;
			mDepthBiasClamp = src->depthBiasClamp != 0;
			mFillModeNonSolid = src->fillModeNonSolid != 0;
			mDepthBounds = src->depthBounds != 0;
			mWideLines = src->wideLines != 0;
			mLargePoints = src->largePoints != 0;
			mAlphaToOne = src->alphaToOne != 0;
			mMultiViewport = src->multiViewport != 0;
			mSamplerAnisotropy = src->samplerAnisotropy != 0;
			mTextureCompressionETC2 = src->textureCompressionETC2 != 0;
			mTextureCompressionASTC_LDR = src->textureCompressionASTC_LDR != 0;
			mTextureCompressionBC = src->textureCompressionBC != 0;
			mOcclusionQueryPrecise = src->occlusionQueryPrecise != 0;
			mPipelineStatisticsQuery = src->pipelineStatisticsQuery != 0;
			mVertexPipelineStoresAndAtomics = src->vertexPipelineStoresAndAtomics != 0;
			mFragmentStoresAndAtomics = src->fragmentStoresAndAtomics != 0;
			mShaderTessellationAndGeometryPointSize = src->shaderTessellationAndGeometryPointSize != 0;
			mShaderImageGatherExtended = src->shaderImageGatherExtended != 0;
			mShaderStorageImageExtendedFormats = src->shaderStorageImageExtendedFormats != 0;
			mShaderStorageImageMultisample = src->shaderStorageImageMultisample != 0;
			mShaderStorageImageReadWithoutFormat = src->shaderStorageImageReadWithoutFormat != 0;
			mShaderStorageImageWriteWithoutFormat = src->shaderStorageImageWriteWithoutFormat != 0;
			mShaderUniformBufferArrayDynamicIndexing = src->shaderUniformBufferArrayDynamicIndexing != 0;
			mShaderSampledImageArrayDynamicIndexing = src->shaderSampledImageArrayDynamicIndexing != 0;
			mShaderStorageBufferArrayDynamicIndexing = src->shaderStorageBufferArrayDynamicIndexing != 0;
			mShaderStorageImageArrayDynamicIndexing = src->shaderStorageImageArrayDynamicIndexing != 0;
			mShaderClipDistance = src->shaderClipDistance != 0;
			mShaderCullDistance = src->shaderCullDistance != 0;
			mShaderFloat64 = src->shaderFloat64 != 0;
			mShaderInt64 = src->shaderInt64 != 0;
			mShaderInt16 = src->shaderInt16 != 0;
			mShaderResourceResidency = src->shaderResourceResidency != 0;
			mShaderResourceMinLod = src->shaderResourceMinLod != 0;
			mSparseBinding = src->sparseBinding != 0;
			mSparseResidencyBuffer = src->sparseResidencyBuffer != 0;
			mSparseResidencyImage2D = src->sparseResidencyImage2D != 0;
			mSparseResidencyImage3D = src->sparseResidencyImage3D != 0;
			mSparseResidency2Samples = src->sparseResidency2Samples != 0;
			mSparseResidency4Samples = src->sparseResidency4Samples != 0;
			mSparseResidency8Samples = src->sparseResidency8Samples != 0;
			mSparseResidency16Samples = src->sparseResidency16Samples != 0;
			mSparseResidencyAliased = src->sparseResidencyAliased != 0;
			mVariableMultisampleRate = src->variableMultisampleRate != 0;
			mInheritedQueries = src->inheritedQueries != 0;
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
	internal:
		void CopyTo(VkPhysicalDeviceSparseProperties* dst, List<IntPtr>^ pins)
		{
			dst->residencyStandard2DBlockShape =	mResidencyStandard2DBlockShape ? 1 : 0;
			dst->residencyStandard2DMultisampleBlockShape =	mResidencyStandard2DMultisampleBlockShape ? 1 : 0;
			dst->residencyStandard3DBlockShape =	mResidencyStandard3DBlockShape ? 1 : 0;
			dst->residencyAlignedMipSize =	mResidencyAlignedMipSize ? 1 : 0;
			dst->residencyNonResidentStrict =	mResidencyNonResidentStrict ? 1 : 0;
		}

		void CopyFrom(VkPhysicalDeviceSparseProperties* src)
		{
			mResidencyStandard2DBlockShape = src->residencyStandard2DBlockShape != 0;
			mResidencyStandard2DMultisampleBlockShape = src->residencyStandard2DMultisampleBlockShape != 0;
			mResidencyStandard3DBlockShape = src->residencyStandard3DBlockShape != 0;
			mResidencyAlignedMipSize = src->residencyAlignedMipSize != 0;
			mResidencyNonResidentStrict = src->residencyNonResidentStrict != 0;
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
		UInt32 mFramebufferColorSampleCounts;
		UInt32 mFramebufferDepthSampleCounts;
		UInt32 mFramebufferStencilSampleCounts;
		UInt32 mFramebufferNoAttachmentsSampleCounts;
		UInt32 mMaxColorAttachments = 0;
		UInt32 mSampledImageColorSampleCounts;
		UInt32 mSampledImageIntegerSampleCounts;
		UInt32 mSampledImageDepthSampleCounts;
		UInt32 mSampledImageStencilSampleCounts;
		UInt32 mStorageImageSampleCounts;
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
		property UInt32 FramebufferColorSampleCounts
		{
			UInt32 get()
			{
				return mFramebufferColorSampleCounts;
			}
			void set(UInt32 value)
			{
				mFramebufferColorSampleCounts = value; 
			}
		}
		property UInt32 FramebufferDepthSampleCounts
		{
			UInt32 get()
			{
				return mFramebufferDepthSampleCounts;
			}
			void set(UInt32 value)
			{
				mFramebufferDepthSampleCounts = value; 
			}
		}
		property UInt32 FramebufferStencilSampleCounts
		{
			UInt32 get()
			{
				return mFramebufferStencilSampleCounts;
			}
			void set(UInt32 value)
			{
				mFramebufferStencilSampleCounts = value; 
			}
		}
		property UInt32 FramebufferNoAttachmentsSampleCounts
		{
			UInt32 get()
			{
				return mFramebufferNoAttachmentsSampleCounts;
			}
			void set(UInt32 value)
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
		property UInt32 SampledImageColorSampleCounts
		{
			UInt32 get()
			{
				return mSampledImageColorSampleCounts;
			}
			void set(UInt32 value)
			{
				mSampledImageColorSampleCounts = value; 
			}
		}
		property UInt32 SampledImageIntegerSampleCounts
		{
			UInt32 get()
			{
				return mSampledImageIntegerSampleCounts;
			}
			void set(UInt32 value)
			{
				mSampledImageIntegerSampleCounts = value; 
			}
		}
		property UInt32 SampledImageDepthSampleCounts
		{
			UInt32 get()
			{
				return mSampledImageDepthSampleCounts;
			}
			void set(UInt32 value)
			{
				mSampledImageDepthSampleCounts = value; 
			}
		}
		property UInt32 SampledImageStencilSampleCounts
		{
			UInt32 get()
			{
				return mSampledImageStencilSampleCounts;
			}
			void set(UInt32 value)
			{
				mSampledImageStencilSampleCounts = value; 
			}
		}
		property UInt32 StorageImageSampleCounts
		{
			UInt32 get()
			{
				return mStorageImageSampleCounts;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkPhysicalDeviceLimits* dst, List<IntPtr>^ pins)
		{
			dst->maxImageDimension1D =	mMaxImageDimension1D;
			dst->maxImageDimension2D =	mMaxImageDimension2D;
			dst->maxImageDimension3D =	mMaxImageDimension3D;
			dst->maxImageDimensionCube =	mMaxImageDimensionCube;
			dst->maxImageArrayLayers =	mMaxImageArrayLayers;
			dst->maxTexelBufferElements =	mMaxTexelBufferElements;
			dst->maxUniformBufferRange =	mMaxUniformBufferRange;
			dst->maxStorageBufferRange =	mMaxStorageBufferRange;
			dst->maxPushConstantsSize =	mMaxPushConstantsSize;
			dst->maxMemoryAllocationCount =	mMaxMemoryAllocationCount;
			dst->maxSamplerAllocationCount =	mMaxSamplerAllocationCount;
			dst->bufferImageGranularity =	mBufferImageGranularity;
			dst->sparseAddressSpaceSize =	mSparseAddressSpaceSize;
			dst->maxBoundDescriptorSets =	mMaxBoundDescriptorSets;
			dst->maxPerStageDescriptorSamplers =	mMaxPerStageDescriptorSamplers;
			dst->maxPerStageDescriptorUniformBuffers =	mMaxPerStageDescriptorUniformBuffers;
			dst->maxPerStageDescriptorStorageBuffers =	mMaxPerStageDescriptorStorageBuffers;
			dst->maxPerStageDescriptorSampledImages =	mMaxPerStageDescriptorSampledImages;
			dst->maxPerStageDescriptorStorageImages =	mMaxPerStageDescriptorStorageImages;
			dst->maxPerStageDescriptorInputAttachments =	mMaxPerStageDescriptorInputAttachments;
			dst->maxPerStageResources =	mMaxPerStageResources;
			dst->maxDescriptorSetSamplers =	mMaxDescriptorSetSamplers;
			dst->maxDescriptorSetUniformBuffers =	mMaxDescriptorSetUniformBuffers;
			dst->maxDescriptorSetUniformBuffersDynamic =	mMaxDescriptorSetUniformBuffersDynamic;
			dst->maxDescriptorSetStorageBuffers =	mMaxDescriptorSetStorageBuffers;
			dst->maxDescriptorSetStorageBuffersDynamic =	mMaxDescriptorSetStorageBuffersDynamic;
			dst->maxDescriptorSetSampledImages =	mMaxDescriptorSetSampledImages;
			dst->maxDescriptorSetStorageImages =	mMaxDescriptorSetStorageImages;
			dst->maxDescriptorSetInputAttachments =	mMaxDescriptorSetInputAttachments;
			dst->maxVertexInputAttributes =	mMaxVertexInputAttributes;
			dst->maxVertexInputBindings =	mMaxVertexInputBindings;
			dst->maxVertexInputAttributeOffset =	mMaxVertexInputAttributeOffset;
			dst->maxVertexInputBindingStride =	mMaxVertexInputBindingStride;
			dst->maxVertexOutputComponents =	mMaxVertexOutputComponents;
			dst->maxTessellationGenerationLevel =	mMaxTessellationGenerationLevel;
			dst->maxTessellationPatchSize =	mMaxTessellationPatchSize;
			dst->maxTessellationControlPerVertexInputComponents =	mMaxTessellationControlPerVertexInputComponents;
			dst->maxTessellationControlPerVertexOutputComponents =	mMaxTessellationControlPerVertexOutputComponents;
			dst->maxTessellationControlPerPatchOutputComponents =	mMaxTessellationControlPerPatchOutputComponents;
			dst->maxTessellationControlTotalOutputComponents =	mMaxTessellationControlTotalOutputComponents;
			dst->maxTessellationEvaluationInputComponents =	mMaxTessellationEvaluationInputComponents;
			dst->maxTessellationEvaluationOutputComponents =	mMaxTessellationEvaluationOutputComponents;
			dst->maxGeometryShaderInvocations =	mMaxGeometryShaderInvocations;
			dst->maxGeometryInputComponents =	mMaxGeometryInputComponents;
			dst->maxGeometryOutputComponents =	mMaxGeometryOutputComponents;
			dst->maxGeometryOutputVertices =	mMaxGeometryOutputVertices;
			dst->maxGeometryTotalOutputComponents =	mMaxGeometryTotalOutputComponents;
			dst->maxFragmentInputComponents =	mMaxFragmentInputComponents;
			dst->maxFragmentOutputAttachments =	mMaxFragmentOutputAttachments;
			dst->maxFragmentDualSrcAttachments =	mMaxFragmentDualSrcAttachments;
			dst->maxFragmentCombinedOutputResources =	mMaxFragmentCombinedOutputResources;
			dst->maxComputeSharedMemorySize =	mMaxComputeSharedMemorySize;
			dst->3 =	m3;
			dst->maxComputeWorkGroupInvocations =	mMaxComputeWorkGroupInvocations;
			dst->3 =	m3;
			dst->subPixelPrecisionBits =	mSubPixelPrecisionBits;
			dst->subTexelPrecisionBits =	mSubTexelPrecisionBits;
			dst->mipmapPrecisionBits =	mMipmapPrecisionBits;
			dst->maxDrawIndexedIndexValue =	mMaxDrawIndexedIndexValue;
			dst->maxDrawIndirectCount =	mMaxDrawIndirectCount;
			dst->maxSamplerLodBias =	mMaxSamplerLodBias;
			dst->maxSamplerAnisotropy =	mMaxSamplerAnisotropy;
			dst->maxViewports =	mMaxViewports;
			dst->2 =	m2;
			dst->2 =	m2;
			dst->viewportSubPixelBits =	mViewportSubPixelBits;
			dst->minMemoryMapAlignment =	mMinMemoryMapAlignment;
			dst->minTexelBufferOffsetAlignment =	mMinTexelBufferOffsetAlignment;
			dst->minUniformBufferOffsetAlignment =	mMinUniformBufferOffsetAlignment;
			dst->minStorageBufferOffsetAlignment =	mMinStorageBufferOffsetAlignment;
			dst->minTexelOffset =	mMinTexelOffset;
			dst->maxTexelOffset =	mMaxTexelOffset;
			dst->minTexelGatherOffset =	mMinTexelGatherOffset;
			dst->maxTexelGatherOffset =	mMaxTexelGatherOffset;
			dst->minInterpolationOffset =	mMinInterpolationOffset;
			dst->maxInterpolationOffset =	mMaxInterpolationOffset;
			dst->subPixelInterpolationOffsetBits =	mSubPixelInterpolationOffsetBits;
			dst->maxFramebufferWidth =	mMaxFramebufferWidth;
			dst->maxFramebufferHeight =	mMaxFramebufferHeight;
			dst->maxFramebufferLayers =	mMaxFramebufferLayers;
			dst->framebufferColorSampleCounts =	mFramebufferColorSampleCounts;
			dst->framebufferDepthSampleCounts =	mFramebufferDepthSampleCounts;
			dst->framebufferStencilSampleCounts =	mFramebufferStencilSampleCounts;
			dst->framebufferNoAttachmentsSampleCounts =	mFramebufferNoAttachmentsSampleCounts;
			dst->maxColorAttachments =	mMaxColorAttachments;
			dst->sampledImageColorSampleCounts =	mSampledImageColorSampleCounts;
			dst->sampledImageIntegerSampleCounts =	mSampledImageIntegerSampleCounts;
			dst->sampledImageDepthSampleCounts =	mSampledImageDepthSampleCounts;
			dst->sampledImageStencilSampleCounts =	mSampledImageStencilSampleCounts;
			dst->storageImageSampleCounts =	mStorageImageSampleCounts;
			dst->maxSampleMaskWords =	mMaxSampleMaskWords;
			dst->timestampComputeAndGraphics =	mTimestampComputeAndGraphics ? 1 : 0;
			dst->timestampPeriod =	mTimestampPeriod;
			dst->maxClipDistances =	mMaxClipDistances;
			dst->maxCullDistances =	mMaxCullDistances;
			dst->maxCombinedClipAndCullDistances =	mMaxCombinedClipAndCullDistances;
			dst->discreteQueuePriorities =	mDiscreteQueuePriorities;
			dst->2 =	m2;
			dst->2 =	m2;
			dst->pointSizeGranularity =	mPointSizeGranularity;
			dst->lineWidthGranularity =	mLineWidthGranularity;
			dst->strictLines =	mStrictLines ? 1 : 0;
			dst->standardSampleLocations =	mStandardSampleLocations ? 1 : 0;
			dst->optimalBufferCopyOffsetAlignment =	mOptimalBufferCopyOffsetAlignment;
			dst->optimalBufferCopyRowPitchAlignment =	mOptimalBufferCopyRowPitchAlignment;
			dst->nonCoherentAtomSize =	mNonCoherentAtomSize;
		}

		void CopyFrom(VkPhysicalDeviceLimits* src)
		{
			mMaxImageDimension1D = src->maxImageDimension1D;
			mMaxImageDimension2D = src->maxImageDimension2D;
			mMaxImageDimension3D = src->maxImageDimension3D;
			mMaxImageDimensionCube = src->maxImageDimensionCube;
			mMaxImageArrayLayers = src->maxImageArrayLayers;
			mMaxTexelBufferElements = src->maxTexelBufferElements;
			mMaxUniformBufferRange = src->maxUniformBufferRange;
			mMaxStorageBufferRange = src->maxStorageBufferRange;
			mMaxPushConstantsSize = src->maxPushConstantsSize;
			mMaxMemoryAllocationCount = src->maxMemoryAllocationCount;
			mMaxSamplerAllocationCount = src->maxSamplerAllocationCount;
			mBufferImageGranularity = src->bufferImageGranularity;
			mSparseAddressSpaceSize = src->sparseAddressSpaceSize;
			mMaxBoundDescriptorSets = src->maxBoundDescriptorSets;
			mMaxPerStageDescriptorSamplers = src->maxPerStageDescriptorSamplers;
			mMaxPerStageDescriptorUniformBuffers = src->maxPerStageDescriptorUniformBuffers;
			mMaxPerStageDescriptorStorageBuffers = src->maxPerStageDescriptorStorageBuffers;
			mMaxPerStageDescriptorSampledImages = src->maxPerStageDescriptorSampledImages;
			mMaxPerStageDescriptorStorageImages = src->maxPerStageDescriptorStorageImages;
			mMaxPerStageDescriptorInputAttachments = src->maxPerStageDescriptorInputAttachments;
			mMaxPerStageResources = src->maxPerStageResources;
			mMaxDescriptorSetSamplers = src->maxDescriptorSetSamplers;
			mMaxDescriptorSetUniformBuffers = src->maxDescriptorSetUniformBuffers;
			mMaxDescriptorSetUniformBuffersDynamic = src->maxDescriptorSetUniformBuffersDynamic;
			mMaxDescriptorSetStorageBuffers = src->maxDescriptorSetStorageBuffers;
			mMaxDescriptorSetStorageBuffersDynamic = src->maxDescriptorSetStorageBuffersDynamic;
			mMaxDescriptorSetSampledImages = src->maxDescriptorSetSampledImages;
			mMaxDescriptorSetStorageImages = src->maxDescriptorSetStorageImages;
			mMaxDescriptorSetInputAttachments = src->maxDescriptorSetInputAttachments;
			mMaxVertexInputAttributes = src->maxVertexInputAttributes;
			mMaxVertexInputBindings = src->maxVertexInputBindings;
			mMaxVertexInputAttributeOffset = src->maxVertexInputAttributeOffset;
			mMaxVertexInputBindingStride = src->maxVertexInputBindingStride;
			mMaxVertexOutputComponents = src->maxVertexOutputComponents;
			mMaxTessellationGenerationLevel = src->maxTessellationGenerationLevel;
			mMaxTessellationPatchSize = src->maxTessellationPatchSize;
			mMaxTessellationControlPerVertexInputComponents = src->maxTessellationControlPerVertexInputComponents;
			mMaxTessellationControlPerVertexOutputComponents = src->maxTessellationControlPerVertexOutputComponents;
			mMaxTessellationControlPerPatchOutputComponents = src->maxTessellationControlPerPatchOutputComponents;
			mMaxTessellationControlTotalOutputComponents = src->maxTessellationControlTotalOutputComponents;
			mMaxTessellationEvaluationInputComponents = src->maxTessellationEvaluationInputComponents;
			mMaxTessellationEvaluationOutputComponents = src->maxTessellationEvaluationOutputComponents;
			mMaxGeometryShaderInvocations = src->maxGeometryShaderInvocations;
			mMaxGeometryInputComponents = src->maxGeometryInputComponents;
			mMaxGeometryOutputComponents = src->maxGeometryOutputComponents;
			mMaxGeometryOutputVertices = src->maxGeometryOutputVertices;
			mMaxGeometryTotalOutputComponents = src->maxGeometryTotalOutputComponents;
			mMaxFragmentInputComponents = src->maxFragmentInputComponents;
			mMaxFragmentOutputAttachments = src->maxFragmentOutputAttachments;
			mMaxFragmentDualSrcAttachments = src->maxFragmentDualSrcAttachments;
			mMaxFragmentCombinedOutputResources = src->maxFragmentCombinedOutputResources;
			mMaxComputeSharedMemorySize = src->maxComputeSharedMemorySize;
			m3 = src->3;
			mMaxComputeWorkGroupInvocations = src->maxComputeWorkGroupInvocations;
			m3 = src->3;
			mSubPixelPrecisionBits = src->subPixelPrecisionBits;
			mSubTexelPrecisionBits = src->subTexelPrecisionBits;
			mMipmapPrecisionBits = src->mipmapPrecisionBits;
			mMaxDrawIndexedIndexValue = src->maxDrawIndexedIndexValue;
			mMaxDrawIndirectCount = src->maxDrawIndirectCount;
			mMaxSamplerLodBias = src->maxSamplerLodBias;
			mMaxSamplerAnisotropy = src->maxSamplerAnisotropy;
			mMaxViewports = src->maxViewports;
			m2 = src->2;
			m2 = src->2;
			mViewportSubPixelBits = src->viewportSubPixelBits;
			mMinMemoryMapAlignment = src->minMemoryMapAlignment;
			mMinTexelBufferOffsetAlignment = src->minTexelBufferOffsetAlignment;
			mMinUniformBufferOffsetAlignment = src->minUniformBufferOffsetAlignment;
			mMinStorageBufferOffsetAlignment = src->minStorageBufferOffsetAlignment;
			mMinTexelOffset = src->minTexelOffset;
			mMaxTexelOffset = src->maxTexelOffset;
			mMinTexelGatherOffset = src->minTexelGatherOffset;
			mMaxTexelGatherOffset = src->maxTexelGatherOffset;
			mMinInterpolationOffset = src->minInterpolationOffset;
			mMaxInterpolationOffset = src->maxInterpolationOffset;
			mSubPixelInterpolationOffsetBits = src->subPixelInterpolationOffsetBits;
			mMaxFramebufferWidth = src->maxFramebufferWidth;
			mMaxFramebufferHeight = src->maxFramebufferHeight;
			mMaxFramebufferLayers = src->maxFramebufferLayers;
			mFramebufferColorSampleCounts = src->framebufferColorSampleCounts;
			mFramebufferDepthSampleCounts = src->framebufferDepthSampleCounts;
			mFramebufferStencilSampleCounts = src->framebufferStencilSampleCounts;
			mFramebufferNoAttachmentsSampleCounts = src->framebufferNoAttachmentsSampleCounts;
			mMaxColorAttachments = src->maxColorAttachments;
			mSampledImageColorSampleCounts = src->sampledImageColorSampleCounts;
			mSampledImageIntegerSampleCounts = src->sampledImageIntegerSampleCounts;
			mSampledImageDepthSampleCounts = src->sampledImageDepthSampleCounts;
			mSampledImageStencilSampleCounts = src->sampledImageStencilSampleCounts;
			mStorageImageSampleCounts = src->storageImageSampleCounts;
			mMaxSampleMaskWords = src->maxSampleMaskWords;
			mTimestampComputeAndGraphics = src->timestampComputeAndGraphics != 0;
			mTimestampPeriod = src->timestampPeriod;
			mMaxClipDistances = src->maxClipDistances;
			mMaxCullDistances = src->maxCullDistances;
			mMaxCombinedClipAndCullDistances = src->maxCombinedClipAndCullDistances;
			mDiscreteQueuePriorities = src->discreteQueuePriorities;
			m2 = src->2;
			m2 = src->2;
			mPointSizeGranularity = src->pointSizeGranularity;
			mLineWidthGranularity = src->lineWidthGranularity;
			mStrictLines = src->strictLines != 0;
			mStandardSampleLocations = src->standardSampleLocations != 0;
			mOptimalBufferCopyOffsetAlignment = src->optimalBufferCopyOffsetAlignment;
			mOptimalBufferCopyRowPitchAlignment = src->optimalBufferCopyRowPitchAlignment;
			mNonCoherentAtomSize = src->nonCoherentAtomSize;
		}
	};

	public ref class SemaphoreCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkSemaphoreCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
		}

		void CopyFrom(VkSemaphoreCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
		}
	};

	public ref class QueryPoolCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		VkQueryType mQueryType;
		UInt32 mQueryCount = 0;
		UInt32 mPipelineStatistics;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::VkQueryType QueryType
		{
			ManagedVulkan::VkQueryType get()
			{
				return mQueryType;
			}
			void set(ManagedVulkan::VkQueryType value)
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
		property UInt32 PipelineStatistics
		{
			UInt32 get()
			{
				return mPipelineStatistics;
			}
			void set(UInt32 value)
			{
				mPipelineStatistics = value; 
			}
		}
	internal:
		void CopyTo(VkQueryPoolCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->queryType =	mQueryType;
			dst->queryCount =	mQueryCount;
			dst->pipelineStatistics =	mPipelineStatistics;
		}

		void CopyFrom(VkQueryPoolCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mQueryType = src->queryType;
			mQueryCount = src->queryCount;
			mPipelineStatistics = src->pipelineStatistics;
		}
	};

	public ref class FramebufferCreateInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		RenderPass^ mRenderPass = gcnew RenderPass();
		UInt32 mAttachmentCount = 0;
		ImageView^ mAttachments = gcnew ImageView();
		UInt32 mWidth = 0;
		UInt32 mHeight = 0;
		UInt32 mLayers = 0;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::RenderPass^ RenderPass
		{
			ManagedVulkan::RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(ManagedVulkan::RenderPass^ value)
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
		property ManagedVulkan::ImageView^ Attachments
		{
			ManagedVulkan::ImageView^ get()
			{
				return mAttachments;
			}
			void set(ManagedVulkan::ImageView^ value)
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
	internal:
		void CopyTo(VkFramebufferCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->renderPass =	mRenderPass;
			dst->attachmentCount =	mAttachmentCount;
			dst->pAttachments =	mAttachments;
			dst->width =	mWidth;
			dst->height =	mHeight;
			dst->layers =	mLayers;
		}

		void CopyFrom(VkFramebufferCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mRenderPass = src->renderPass;
			mAttachmentCount = src->attachmentCount;
			mAttachments = src->pAttachments;
			mWidth = src->width;
			mHeight = src->height;
			mLayers = src->layers;
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
	internal:
		void CopyTo(VkDrawIndirectCommand* dst, List<IntPtr>^ pins)
		{
			dst->vertexCount =	mVertexCount;
			dst->instanceCount =	mInstanceCount;
			dst->firstVertex =	mFirstVertex;
			dst->firstInstance =	mFirstInstance;
		}

		void CopyFrom(VkDrawIndirectCommand* src)
		{
			mVertexCount = src->vertexCount;
			mInstanceCount = src->instanceCount;
			mFirstVertex = src->firstVertex;
			mFirstInstance = src->firstInstance;
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
	internal:
		void CopyTo(VkDrawIndexedIndirectCommand* dst, List<IntPtr>^ pins)
		{
			dst->indexCount =	mIndexCount;
			dst->instanceCount =	mInstanceCount;
			dst->firstIndex =	mFirstIndex;
			dst->vertexOffset =	mVertexOffset;
			dst->firstInstance =	mFirstInstance;
		}

		void CopyFrom(VkDrawIndexedIndirectCommand* src)
		{
			mIndexCount = src->indexCount;
			mInstanceCount = src->instanceCount;
			mFirstIndex = src->firstIndex;
			mVertexOffset = src->vertexOffset;
			mFirstInstance = src->firstInstance;
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
	internal:
		void CopyTo(VkDispatchIndirectCommand* dst, List<IntPtr>^ pins)
		{
			dst->x =	mX;
			dst->y =	mY;
			dst->z =	mZ;
		}

		void CopyFrom(VkDispatchIndirectCommand* src)
		{
			mX = src->x;
			mY = src->y;
			mZ = src->z;
		}
	};

	public ref class SubmitInfo
	{
	private:
		VkStructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		Semaphore^ mWaitSemaphores = gcnew Semaphore();
		VkPipelineStageFlags* mWaitDstStageMask;
		UInt32 mCommandBufferCount = 0;
		CommandBuffer mCommandBuffers = nullptr;
		UInt32 mSignalSemaphoreCount = 0;
		Semaphore^ mSignalSemaphores = gcnew Semaphore();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
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
		property ManagedVulkan::Semaphore^ WaitSemaphores
		{
			ManagedVulkan::Semaphore^ get()
			{
				return mWaitSemaphores;
			}
			void set(ManagedVulkan::Semaphore^ value)
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
		property ManagedVulkan::CommandBuffer CommandBuffers
		{
			ManagedVulkan::CommandBuffer get()
			{
				return mCommandBuffers;
			}
			void set(ManagedVulkan::CommandBuffer value)
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
		property ManagedVulkan::Semaphore^ SignalSemaphores
		{
			ManagedVulkan::Semaphore^ get()
			{
				return mSignalSemaphores;
			}
			void set(ManagedVulkan::Semaphore^ value)
			{
				mSignalSemaphores = value; 
			}
		}
	internal:
		void CopyTo(VkSubmitInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->waitSemaphoreCount =	mWaitSemaphoreCount;
			dst->pWaitSemaphores =	mWaitSemaphores;
			dst->pWaitDstStageMask =	mWaitDstStageMask;
			dst->commandBufferCount =	mCommandBufferCount;
			dst->pCommandBuffers =	mCommandBuffers;
			dst->signalSemaphoreCount =	mSignalSemaphoreCount;
			dst->pSignalSemaphores =	mSignalSemaphores;
		}

		void CopyFrom(VkSubmitInfo* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mWaitSemaphoreCount = src->waitSemaphoreCount;
			mWaitSemaphores = src->pWaitSemaphores;
			mWaitDstStageMask = src->pWaitDstStageMask;
			mCommandBufferCount = src->commandBufferCount;
			mCommandBuffers = src->pCommandBuffers;
			mSignalSemaphoreCount = src->signalSemaphoreCount;
			mSignalSemaphores = src->pSignalSemaphores;
		}
	};

	public ref class DisplayPropertiesKHR
	{
	private:
		DisplayKHR^ mDisplay = gcnew DisplayKHR();
		String^ mDisplayName = nullptr;
		Extent2D^ mPhysicalDimensions = gcnew Extent2D();
		Extent2D^ mPhysicalResolution = gcnew Extent2D();
		UInt32 mSupportedTransforms;
		bool mPlaneReorderPossible = false;
		bool mPersistentContent = false;
	public:
		property ManagedVulkan::DisplayKHR^ Display
		{
			ManagedVulkan::DisplayKHR^ get()
			{
				return mDisplay;
			}
			void set(ManagedVulkan::DisplayKHR^ value)
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
		property ManagedVulkan::Extent2D^ PhysicalDimensions
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mPhysicalDimensions;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mPhysicalDimensions = value; 
			}
		}
		property ManagedVulkan::Extent2D^ PhysicalResolution
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mPhysicalResolution;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mPhysicalResolution = value; 
			}
		}
		property UInt32 SupportedTransforms
		{
			UInt32 get()
			{
				return mSupportedTransforms;
			}
			void set(UInt32 value)
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
	internal:
		void CopyTo(VkDisplayPropertiesKHR* dst, List<IntPtr>^ pins)
		{
			dst->display =	mDisplay;

			IntPtr str_displayName = Marshal::StringToHGlobalAnsi(mDisplayName);
			pins->Add(str_displayName);			
			dst->displayName = static_cast <char*> (str_displayName.ToPointer());

			mPhysicalDimensions->CopyFrom(&dst->physicalDimensions, pins);
			mPhysicalResolution->CopyFrom(&dst->physicalResolution, pins);
			dst->supportedTransforms =	mSupportedTransforms;
			dst->planeReorderPossible =	mPlaneReorderPossible ? 1 : 0;
			dst->persistentContent =	mPersistentContent ? 1 : 0;
		}

		void CopyFrom(VkDisplayPropertiesKHR* src)
		{
			mDisplay = src->display;
			mDisplayName = gcnew String(mDisplayName);
			mPhysicalDimensions->CopyTo(&src->physicalDimensions);
			mPhysicalResolution->CopyTo(&src->physicalResolution);
			mSupportedTransforms = src->supportedTransforms;
			mPlaneReorderPossible = src->planeReorderPossible != 0;
			mPersistentContent = src->persistentContent != 0;
		}
	};

	public ref class DisplayPlanePropertiesKHR
	{
	private:
		DisplayKHR^ mCurrentDisplay = gcnew DisplayKHR();
		UInt32 mCurrentStackIndex = 0;
	public:
		property ManagedVulkan::DisplayKHR^ CurrentDisplay
		{
			ManagedVulkan::DisplayKHR^ get()
			{
				return mCurrentDisplay;
			}
			void set(ManagedVulkan::DisplayKHR^ value)
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
	internal:
		void CopyTo(VkDisplayPlanePropertiesKHR* dst, List<IntPtr>^ pins)
		{
			dst->currentDisplay =	mCurrentDisplay;
			dst->currentStackIndex =	mCurrentStackIndex;
		}

		void CopyFrom(VkDisplayPlanePropertiesKHR* src)
		{
			mCurrentDisplay = src->currentDisplay;
			mCurrentStackIndex = src->currentStackIndex;
		}
	};

	public ref class DisplayModeParametersKHR
	{
	private:
		Extent2D^ mVisibleRegion = gcnew Extent2D();
		UInt32 mRefreshRate = 0;
	public:
		property ManagedVulkan::Extent2D^ VisibleRegion
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mVisibleRegion;
			}
			void set(ManagedVulkan::Extent2D^ value)
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
	internal:
		void CopyTo(VkDisplayModeParametersKHR* dst, List<IntPtr>^ pins)
		{
			mVisibleRegion->CopyFrom(&dst->visibleRegion, pins);
			dst->refreshRate =	mRefreshRate;
		}

		void CopyFrom(VkDisplayModeParametersKHR* src)
		{
			mVisibleRegion->CopyTo(&src->visibleRegion);
			mRefreshRate = src->refreshRate;
		}
	};

	public ref class DisplayModePropertiesKHR
	{
	private:
		DisplayModeKHR^ mDisplayMode = gcnew DisplayModeKHR();
		DisplayModeParametersKHR^ mParameters = gcnew DisplayModeParametersKHR();
	public:
		property ManagedVulkan::DisplayModeKHR^ DisplayMode
		{
			ManagedVulkan::DisplayModeKHR^ get()
			{
				return mDisplayMode;
			}
			void set(ManagedVulkan::DisplayModeKHR^ value)
			{
				mDisplayMode = value; 
			}
		}
		property ManagedVulkan::DisplayModeParametersKHR^ Parameters
		{
			ManagedVulkan::DisplayModeParametersKHR^ get()
			{
				return mParameters;
			}
			void set(ManagedVulkan::DisplayModeParametersKHR^ value)
			{
				mParameters = value; 
			}
		}
	internal:
		void CopyTo(VkDisplayModePropertiesKHR* dst, List<IntPtr>^ pins)
		{
			dst->displayMode =	mDisplayMode;
			mParameters->CopyFrom(&dst->parameters, pins);
		}

		void CopyFrom(VkDisplayModePropertiesKHR* src)
		{
			mDisplayMode = src->displayMode;
			mParameters->CopyTo(&src->parameters);
		}
	};

	public ref class DisplayModeCreatefInfoKHR
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		DisplayModeParametersKHR^ mParameters = gcnew DisplayModeParametersKHR();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::DisplayModeParametersKHR^ Parameters
		{
			ManagedVulkan::DisplayModeParametersKHR^ get()
			{
				return mParameters;
			}
			void set(ManagedVulkan::DisplayModeParametersKHR^ value)
			{
				mParameters = value; 
			}
		}
	internal:
		void CopyTo(VkDisplayModeCreatefInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			mParameters->CopyFrom(&dst->parameters, pins);
		}

		void CopyFrom(VkDisplayModeCreatefInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mParameters->CopyTo(&src->parameters);
		}
	};

	public ref class DisplayPlaneCapabilitiesKHR
	{
	private:
		UInt32 mSupportedAlpha;
		Offset2D^ mMinSrcPosition = gcnew Offset2D();
		Offset2D^ mMaxSrcPosition = gcnew Offset2D();
		Extent2D^ mMinSrcExtent = gcnew Extent2D();
		Extent2D^ mMaxSrcExtent = gcnew Extent2D();
		Offset2D^ mMinDstPosition = gcnew Offset2D();
		Offset2D^ mMaxDstPosition = gcnew Offset2D();
		Extent2D^ mMinDstExtent = gcnew Extent2D();
		Extent2D^ mMaxDstExtent = gcnew Extent2D();
	public:
		property UInt32 SupportedAlpha
		{
			UInt32 get()
			{
				return mSupportedAlpha;
			}
			void set(UInt32 value)
			{
				mSupportedAlpha = value; 
			}
		}
		property ManagedVulkan::Offset2D^ MinSrcPosition
		{
			ManagedVulkan::Offset2D^ get()
			{
				return mMinSrcPosition;
			}
			void set(ManagedVulkan::Offset2D^ value)
			{
				mMinSrcPosition = value; 
			}
		}
		property ManagedVulkan::Offset2D^ MaxSrcPosition
		{
			ManagedVulkan::Offset2D^ get()
			{
				return mMaxSrcPosition;
			}
			void set(ManagedVulkan::Offset2D^ value)
			{
				mMaxSrcPosition = value; 
			}
		}
		property ManagedVulkan::Extent2D^ MinSrcExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mMinSrcExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mMinSrcExtent = value; 
			}
		}
		property ManagedVulkan::Extent2D^ MaxSrcExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mMaxSrcExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mMaxSrcExtent = value; 
			}
		}
		property ManagedVulkan::Offset2D^ MinDstPosition
		{
			ManagedVulkan::Offset2D^ get()
			{
				return mMinDstPosition;
			}
			void set(ManagedVulkan::Offset2D^ value)
			{
				mMinDstPosition = value; 
			}
		}
		property ManagedVulkan::Offset2D^ MaxDstPosition
		{
			ManagedVulkan::Offset2D^ get()
			{
				return mMaxDstPosition;
			}
			void set(ManagedVulkan::Offset2D^ value)
			{
				mMaxDstPosition = value; 
			}
		}
		property ManagedVulkan::Extent2D^ MinDstExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mMinDstExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mMinDstExtent = value; 
			}
		}
		property ManagedVulkan::Extent2D^ MaxDstExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mMaxDstExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mMaxDstExtent = value; 
			}
		}
	internal:
		void CopyTo(VkDisplayPlaneCapabilitiesKHR* dst, List<IntPtr>^ pins)
		{
			dst->supportedAlpha =	mSupportedAlpha;
			mMinSrcPosition->CopyFrom(&dst->minSrcPosition, pins);
			mMaxSrcPosition->CopyFrom(&dst->maxSrcPosition, pins);
			mMinSrcExtent->CopyFrom(&dst->minSrcExtent, pins);
			mMaxSrcExtent->CopyFrom(&dst->maxSrcExtent, pins);
			mMinDstPosition->CopyFrom(&dst->minDstPosition, pins);
			mMaxDstPosition->CopyFrom(&dst->maxDstPosition, pins);
			mMinDstExtent->CopyFrom(&dst->minDstExtent, pins);
			mMaxDstExtent->CopyFrom(&dst->maxDstExtent, pins);
		}

		void CopyFrom(VkDisplayPlaneCapabilitiesKHR* src)
		{
			mSupportedAlpha = src->supportedAlpha;
			mMinSrcPosition->CopyTo(&src->minSrcPosition);
			mMaxSrcPosition->CopyTo(&src->maxSrcPosition);
			mMinSrcExtent->CopyTo(&src->minSrcExtent);
			mMaxSrcExtent->CopyTo(&src->maxSrcExtent);
			mMinDstPosition->CopyTo(&src->minDstPosition);
			mMaxDstPosition->CopyTo(&src->maxDstPosition);
			mMinDstExtent->CopyTo(&src->minDstExtent);
			mMaxDstExtent->CopyTo(&src->maxDstExtent);
		}
	};

	public ref class DisplaySurfaceCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		DisplayModeKHR^ mDisplayMode = gcnew DisplayModeKHR();
		UInt32 mPlaneIndex = 0;
		UInt32 mPlaneStackIndex = 0;
		VkSurfaceTransformFlagBitsKHR mTransform;
		float mGlobalAlpha = 0f;
		VkDisplayPlaneAlphaFlagBitsKHR mAlphaMode;
		Extent2D^ mImageExtent = gcnew Extent2D();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::DisplayModeKHR^ DisplayMode
		{
			ManagedVulkan::DisplayModeKHR^ get()
			{
				return mDisplayMode;
			}
			void set(ManagedVulkan::DisplayModeKHR^ value)
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
		property ManagedVulkan::VkSurfaceTransformFlagBitsKHR Transform
		{
			ManagedVulkan::VkSurfaceTransformFlagBitsKHR get()
			{
				return mTransform;
			}
			void set(ManagedVulkan::VkSurfaceTransformFlagBitsKHR value)
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
		property ManagedVulkan::VkDisplayPlaneAlphaFlagBitsKHR AlphaMode
		{
			ManagedVulkan::VkDisplayPlaneAlphaFlagBitsKHR get()
			{
				return mAlphaMode;
			}
			void set(ManagedVulkan::VkDisplayPlaneAlphaFlagBitsKHR value)
			{
				mAlphaMode = value; 
			}
		}
		property ManagedVulkan::Extent2D^ ImageExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mImageExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mImageExtent = value; 
			}
		}
	internal:
		void CopyTo(VkDisplaySurfaceCreateInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->displayMode =	mDisplayMode;
			dst->planeIndex =	mPlaneIndex;
			dst->planeStackIndex =	mPlaneStackIndex;
			dst->transform =	mTransform;
			dst->globalAlpha =	mGlobalAlpha;
			dst->alphaMode =	mAlphaMode;
			mImageExtent->CopyFrom(&dst->imageExtent, pins);
		}

		void CopyFrom(VkDisplaySurfaceCreateInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mDisplayMode = src->displayMode;
			mPlaneIndex = src->planeIndex;
			mPlaneStackIndex = src->planeStackIndex;
			mTransform = src->transform;
			mGlobalAlpha = src->globalAlpha;
			mAlphaMode = src->alphaMode;
			mImageExtent->CopyTo(&src->imageExtent);
		}
	};

	public ref class DisplayPresentInfoKHR
	{
	private:
		VkStructureType mSType;
		Rect2D^ mSrcRect = gcnew Rect2D();
		Rect2D^ mDstRect = gcnew Rect2D();
		bool mPersistent = false;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
		property ManagedVulkan::Rect2D^ SrcRect
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mSrcRect;
			}
			void set(ManagedVulkan::Rect2D^ value)
			{
				mSrcRect = value; 
			}
		}
		property ManagedVulkan::Rect2D^ DstRect
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mDstRect;
			}
			void set(ManagedVulkan::Rect2D^ value)
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
	internal:
		void CopyTo(VkDisplayPresentInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			mSrcRect->CopyFrom(&dst->srcRect, pins);
			mDstRect->CopyFrom(&dst->dstRect, pins);
			dst->persistent =	mPersistent ? 1 : 0;
		}

		void CopyFrom(VkDisplayPresentInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mSrcRect->CopyTo(&src->srcRect);
			mDstRect->CopyTo(&src->dstRect);
			mPersistent = src->persistent != 0;
		}
	};

	public ref class SurfaceCapabilitiesKHR
	{
	private:
		UInt32 mMinImageCount = 0;
		UInt32 mMaxImageCount = 0;
		Extent2D^ mCurrentExtent = gcnew Extent2D();
		Extent2D^ mMinImageExtent = gcnew Extent2D();
		Extent2D^ mMaxImageExtent = gcnew Extent2D();
		UInt32 mMaxImageArrayLayers = 0;
		UInt32 mSupportedTransforms;
		VkSurfaceTransformFlagBitsKHR mCurrentTransform;
		UInt32 mSupportedCompositeAlpha;
		UInt32 mSupportedUsageFlags;
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
		property ManagedVulkan::Extent2D^ CurrentExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mCurrentExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mCurrentExtent = value; 
			}
		}
		property ManagedVulkan::Extent2D^ MinImageExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mMinImageExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mMinImageExtent = value; 
			}
		}
		property ManagedVulkan::Extent2D^ MaxImageExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mMaxImageExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
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
		property UInt32 SupportedTransforms
		{
			UInt32 get()
			{
				return mSupportedTransforms;
			}
			void set(UInt32 value)
			{
				mSupportedTransforms = value; 
			}
		}
		property ManagedVulkan::VkSurfaceTransformFlagBitsKHR CurrentTransform
		{
			ManagedVulkan::VkSurfaceTransformFlagBitsKHR get()
			{
				return mCurrentTransform;
			}
			void set(ManagedVulkan::VkSurfaceTransformFlagBitsKHR value)
			{
				mCurrentTransform = value; 
			}
		}
		property UInt32 SupportedCompositeAlpha
		{
			UInt32 get()
			{
				return mSupportedCompositeAlpha;
			}
			void set(UInt32 value)
			{
				mSupportedCompositeAlpha = value; 
			}
		}
		property UInt32 SupportedUsageFlags
		{
			UInt32 get()
			{
				return mSupportedUsageFlags;
			}
			void set(UInt32 value)
			{
				mSupportedUsageFlags = value; 
			}
		}
	internal:
		void CopyTo(VkSurfaceCapabilitiesKHR* dst, List<IntPtr>^ pins)
		{
			dst->minImageCount =	mMinImageCount;
			dst->maxImageCount =	mMaxImageCount;
			mCurrentExtent->CopyFrom(&dst->currentExtent, pins);
			mMinImageExtent->CopyFrom(&dst->minImageExtent, pins);
			mMaxImageExtent->CopyFrom(&dst->maxImageExtent, pins);
			dst->maxImageArrayLayers =	mMaxImageArrayLayers;
			dst->supportedTransforms =	mSupportedTransforms;
			dst->currentTransform =	mCurrentTransform;
			dst->supportedCompositeAlpha =	mSupportedCompositeAlpha;
			dst->supportedUsageFlags =	mSupportedUsageFlags;
		}

		void CopyFrom(VkSurfaceCapabilitiesKHR* src)
		{
			mMinImageCount = src->minImageCount;
			mMaxImageCount = src->maxImageCount;
			mCurrentExtent->CopyTo(&src->currentExtent);
			mMinImageExtent->CopyTo(&src->minImageExtent);
			mMaxImageExtent->CopyTo(&src->maxImageExtent);
			mMaxImageArrayLayers = src->maxImageArrayLayers;
			mSupportedTransforms = src->supportedTransforms;
			mCurrentTransform = src->currentTransform;
			mSupportedCompositeAlpha = src->supportedCompositeAlpha;
			mSupportedUsageFlags = src->supportedUsageFlags;
		}
	};

	public ref class Win32SurfaceCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		HINSTANCE mHinstance;
		HWND mHwnd;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
	internal:
		void CopyTo(VkWin32SurfaceCreateInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->hinstance =	mHinstance;
			dst->hwnd =	mHwnd;
		}

		void CopyFrom(VkWin32SurfaceCreateInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mHinstance = src->hinstance;
			mHwnd = src->hwnd;
		}
	};

	public ref class SurfaceFormatKHR
	{
	private:
		VkFormat mFormat;
		VkColorSpaceKHR mColorSpace;
	public:
		property ManagedVulkan::VkFormat Format
		{
			ManagedVulkan::VkFormat get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::VkFormat value)
			{
				mFormat = value; 
			}
		}
		property ManagedVulkan::VkColorSpaceKHR ColorSpace
		{
			ManagedVulkan::VkColorSpaceKHR get()
			{
				return mColorSpace;
			}
			void set(ManagedVulkan::VkColorSpaceKHR value)
			{
				mColorSpace = value; 
			}
		}
	internal:
		void CopyTo(VkSurfaceFormatKHR* dst, List<IntPtr>^ pins)
		{
			dst->format =	mFormat;
			dst->colorSpace =	mColorSpace;
		}

		void CopyFrom(VkSurfaceFormatKHR* src)
		{
			mFormat = src->format;
			mColorSpace = src->colorSpace;
		}
	};

	public ref class SwapchainCreateInfoKHR
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		SurfaceKHR^ mSurface = gcnew SurfaceKHR();
		UInt32 mMinImageCount = 0;
		VkFormat mImageFormat;
		VkColorSpaceKHR mImageColorSpace;
		Extent2D^ mImageExtent = gcnew Extent2D();
		UInt32 mImageArrayLayers = 0;
		UInt32 mImageUsage;
		VkSharingMode mImageSharingMode;
		UInt32 mQueueFamilyIndexCount = 0;
		UInt32 mQueueFamilyIndices = 0;
		VkSurfaceTransformFlagBitsKHR mPreTransform;
		VkCompositeAlphaFlagBitsKHR mCompositeAlpha;
		VkPresentModeKHR mPresentMode;
		bool mClipped = false;
		SwapchainKHR^ mOldSwapchain = gcnew SwapchainKHR();
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::SurfaceKHR^ Surface
		{
			ManagedVulkan::SurfaceKHR^ get()
			{
				return mSurface;
			}
			void set(ManagedVulkan::SurfaceKHR^ value)
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
		property ManagedVulkan::VkFormat ImageFormat
		{
			ManagedVulkan::VkFormat get()
			{
				return mImageFormat;
			}
			void set(ManagedVulkan::VkFormat value)
			{
				mImageFormat = value; 
			}
		}
		property ManagedVulkan::VkColorSpaceKHR ImageColorSpace
		{
			ManagedVulkan::VkColorSpaceKHR get()
			{
				return mImageColorSpace;
			}
			void set(ManagedVulkan::VkColorSpaceKHR value)
			{
				mImageColorSpace = value; 
			}
		}
		property ManagedVulkan::Extent2D^ ImageExtent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mImageExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
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
		property UInt32 ImageUsage
		{
			UInt32 get()
			{
				return mImageUsage;
			}
			void set(UInt32 value)
			{
				mImageUsage = value; 
			}
		}
		property ManagedVulkan::VkSharingMode ImageSharingMode
		{
			ManagedVulkan::VkSharingMode get()
			{
				return mImageSharingMode;
			}
			void set(ManagedVulkan::VkSharingMode value)
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
		property ManagedVulkan::VkSurfaceTransformFlagBitsKHR PreTransform
		{
			ManagedVulkan::VkSurfaceTransformFlagBitsKHR get()
			{
				return mPreTransform;
			}
			void set(ManagedVulkan::VkSurfaceTransformFlagBitsKHR value)
			{
				mPreTransform = value; 
			}
		}
		property ManagedVulkan::VkCompositeAlphaFlagBitsKHR CompositeAlpha
		{
			ManagedVulkan::VkCompositeAlphaFlagBitsKHR get()
			{
				return mCompositeAlpha;
			}
			void set(ManagedVulkan::VkCompositeAlphaFlagBitsKHR value)
			{
				mCompositeAlpha = value; 
			}
		}
		property ManagedVulkan::VkPresentModeKHR PresentMode
		{
			ManagedVulkan::VkPresentModeKHR get()
			{
				return mPresentMode;
			}
			void set(ManagedVulkan::VkPresentModeKHR value)
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
		property ManagedVulkan::SwapchainKHR^ OldSwapchain
		{
			ManagedVulkan::SwapchainKHR^ get()
			{
				return mOldSwapchain;
			}
			void set(ManagedVulkan::SwapchainKHR^ value)
			{
				mOldSwapchain = value; 
			}
		}
	internal:
		void CopyTo(VkSwapchainCreateInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->surface =	mSurface;
			dst->minImageCount =	mMinImageCount;
			dst->imageFormat =	mImageFormat;
			dst->imageColorSpace =	mImageColorSpace;
			mImageExtent->CopyFrom(&dst->imageExtent, pins);
			dst->imageArrayLayers =	mImageArrayLayers;
			dst->imageUsage =	mImageUsage;
			dst->imageSharingMode =	mImageSharingMode;
			dst->queueFamilyIndexCount =	mQueueFamilyIndexCount;
			dst->pQueueFamilyIndices =	mQueueFamilyIndices;
			dst->preTransform =	mPreTransform;
			dst->compositeAlpha =	mCompositeAlpha;
			dst->presentMode =	mPresentMode;
			dst->clipped =	mClipped ? 1 : 0;
			dst->oldSwapchain =	mOldSwapchain;
		}

		void CopyFrom(VkSwapchainCreateInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mSurface = src->surface;
			mMinImageCount = src->minImageCount;
			mImageFormat = src->imageFormat;
			mImageColorSpace = src->imageColorSpace;
			mImageExtent->CopyTo(&src->imageExtent);
			mImageArrayLayers = src->imageArrayLayers;
			mImageUsage = src->imageUsage;
			mImageSharingMode = src->imageSharingMode;
			mQueueFamilyIndexCount = src->queueFamilyIndexCount;
			mQueueFamilyIndices = src->pQueueFamilyIndices;
			mPreTransform = src->preTransform;
			mCompositeAlpha = src->compositeAlpha;
			mPresentMode = src->presentMode;
			mClipped = src->clipped != 0;
			mOldSwapchain = src->oldSwapchain;
		}
	};

	public ref class PresentInfoKHR
	{
	private:
		VkStructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		Semaphore^ mWaitSemaphores = gcnew Semaphore();
		UInt32 mSwapchainCount = 0;
		SwapchainKHR^ mSwapchains = gcnew SwapchainKHR();
		UInt32 mImageIndices = 0;
		VkResult mResults;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
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
		property ManagedVulkan::Semaphore^ WaitSemaphores
		{
			ManagedVulkan::Semaphore^ get()
			{
				return mWaitSemaphores;
			}
			void set(ManagedVulkan::Semaphore^ value)
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
		property ManagedVulkan::SwapchainKHR^ Swapchains
		{
			ManagedVulkan::SwapchainKHR^ get()
			{
				return mSwapchains;
			}
			void set(ManagedVulkan::SwapchainKHR^ value)
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
		property ManagedVulkan::VkResult Results
		{
			ManagedVulkan::VkResult get()
			{
				return mResults;
			}
			void set(ManagedVulkan::VkResult value)
			{
				mResults = value; 
			}
		}
	internal:
		void CopyTo(VkPresentInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->waitSemaphoreCount =	mWaitSemaphoreCount;
			dst->pWaitSemaphores =	mWaitSemaphores;
			dst->swapchainCount =	mSwapchainCount;
			dst->pSwapchains =	mSwapchains;
			dst->pImageIndices =	mImageIndices;
			dst->pResults =	mResults;
		}

		void CopyFrom(VkPresentInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mWaitSemaphoreCount = src->waitSemaphoreCount;
			mWaitSemaphores = src->pWaitSemaphores;
			mSwapchainCount = src->swapchainCount;
			mSwapchains = src->pSwapchains;
			mImageIndices = src->pImageIndices;
			mResults = src->pResults;
		}
	};

	public ref class DebugReportCallbackCreateInfoEXT
	{
	private:
		VkStructureType mSType;
		UInt32 mFlags;
		PFN_vkDebugReportCallbackEXT^ mPfnCallback = nullptr;
		IntPtr mUserData = IntPtr::Zero;
	public:
		property ManagedVulkan::VkStructureType SType
		{
			ManagedVulkan::VkStructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::VkStructureType value)
			{
				mSType = value; 
			}
		}
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
		property ManagedVulkan::PFN_vkDebugReportCallbackEXT^ PfnCallback
		{
			ManagedVulkan::PFN_vkDebugReportCallbackEXT^ get()
			{
				return mPfnCallback;
			}
			void set(ManagedVulkan::PFN_vkDebugReportCallbackEXT^ value)
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
	internal:
		void CopyTo(VkDebugReportCallbackCreateInfoEXT* dst, List<IntPtr>^ pins)
		{
			dst->sType =	mSType;
			dst->pNext =	pNext;
			dst->flags =	mFlags;
			dst->pfnCallback =	mPfnCallback;
			dst->pUserData =	mUserData;
		}

		void CopyFrom(VkDebugReportCallbackCreateInfoEXT* src)
		{
			mSType = (StructureType) src->sType;
			pNext = src->pNext;
			mFlags = src->flags;
			mPfnCallback = src->pfnCallback;
			mUserData = src->pUserData;
		}
	};

}