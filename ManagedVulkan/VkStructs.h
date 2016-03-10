#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkCommandBuffer.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class ApplicationInfo
	{
	private:
		StructureType mSType;
		String^ mApplicationName = nullptr;
		UInt32 mApplicationVersion = 0;
		String^ mEngineName = nullptr;
		UInt32 mEngineVersion = 0;
		UInt32 mApiVersion = 0;
	public:
		property StructureType SType
		{
			StructureType get()
			{
				return mSType;
			}
			void set(StructureType value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;

			IntPtr str_pApplicationName = Marshal::StringToHGlobalAnsi(mApplicationName);
			pins->Add(str_pApplicationName);
			dst->pApplicationName = static_cast <char*> (str_pApplicationName.ToPointer());

			dst->applicationVersion = mApplicationVersion;

			IntPtr str_pEngineName = Marshal::StringToHGlobalAnsi(mEngineName);
			pins->Add(str_pEngineName);
			dst->pEngineName = static_cast <char*> (str_pEngineName.ToPointer());

			dst->engineVersion = mEngineVersion;
			dst->apiVersion = mApiVersion;
		}

		void CopyFrom(VkApplicationInfo* src)
		{
			mSType = (ManagedVulkan::StructureType) src->sType;
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
			// TODO : HOOK DELEGATES TO C++
			//dst->pUserData = mUserData.ToPointer();
			//dst->pfnAllocation = (void*) mPfnAllocation;
			//dst->pfnReallocation = mPfnReallocation;
			//dst->pfnFree = mPfnFree;
			//dst->pfnInternalAllocation = mPfnInternalAllocation;
			//dst->pfnInternalFree = mPfnInternalFree;
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
			dst->width = mWidth;
			dst->height = mHeight;
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
			dst->width = mWidth;
			dst->height = mHeight;
			dst->depth = mDepth;
		}

		void CopyFrom(VkExtent3D* src)
		{
			mWidth = src->width;
			mHeight = src->height;
			mDepth = src->depth;
		}
	};


	public ref class DisplaySurfaceCreateInfoKHR
	{
	private:
		StructureType mSType;
		DisplaySurfaceCreateFlagsKHR mFlags;
		DisplayModeKHR^ mDisplayMode = nullptr;
		UInt32 mPlaneIndex = 0;
		UInt32 mPlaneStackIndex = 0;
		ManagedVulkan::SurfaceTransformFlagBitsKHR mTransform;
		float mGlobalAlpha = 0;
		ManagedVulkan::DisplayPlaneAlphaFlagBitsKHR mAlphaMode;
		Extent2D^ mImageExtent = gcnew Extent2D();
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property DisplaySurfaceCreateFlagsKHR Flags
		{
			DisplaySurfaceCreateFlagsKHR get()
			{
				return mFlags;
			}
			void set(DisplaySurfaceCreateFlagsKHR value)
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
		property ManagedVulkan::SurfaceTransformFlagBitsKHR Transform
		{
			ManagedVulkan::SurfaceTransformFlagBitsKHR get()
			{
				return mTransform;
			}
			void set(ManagedVulkan::SurfaceTransformFlagBitsKHR value)
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
		property ManagedVulkan::DisplayPlaneAlphaFlagBitsKHR AlphaMode
		{
			ManagedVulkan::DisplayPlaneAlphaFlagBitsKHR get()
			{
				return mAlphaMode;
			}
			void set(ManagedVulkan::DisplayPlaneAlphaFlagBitsKHR value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->displayMode = mDisplayMode->mHandle;
			dst->planeIndex = mPlaneIndex;
			dst->planeStackIndex = mPlaneStackIndex;
			dst->transform = (VkSurfaceTransformFlagBitsKHR) mTransform;
			dst->globalAlpha = mGlobalAlpha;
			dst->alphaMode = (VkDisplayPlaneAlphaFlagBitsKHR) mAlphaMode;
			mImageExtent->CopyTo(&dst->imageExtent, pins);
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
		void CopyFrom(VkExtensionProperties* src)
		{
			mExtensionName = gcnew String(src->extensionName);
			mSpecVersion = src->specVersion;
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
			dst->linearTilingFeatures = mLinearTilingFeatures;
			dst->optimalTilingFeatures = mOptimalTilingFeatures;
			dst->bufferFeatures = mBufferFeatures;
		}

		void CopyFrom(VkFormatProperties* src)
		{
			mLinearTilingFeatures = src->linearTilingFeatures;
			mOptimalTilingFeatures = src->optimalTilingFeatures;
			mBufferFeatures = src->bufferFeatures;
		}
	};


	public ref class InstanceCreateInfo
	{
	private:
		StructureType mSType;
		VkInstanceCreateFlags mFlags;
		ApplicationInfo^ mApplicationInfo = nullptr;
		UInt32 mEnabledLayerCount = 0;
		array<String^>^ mEnabledLayerNames = nullptr;
		UInt32 mEnabledExtensionCount = 0;
		array<String^>^ mEnabledExtensionNames = nullptr;
	public:
		property StructureType SType
		{
			StructureType get()
			{
				return mSType;
			}
			void set(StructureType value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
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
		void CopyFrom(VkLayerProperties* src)
		{
			mLayerName = gcnew String(src->layerName);
			mSpecVersion = src->specVersion;
			mImplementationVersion = src->implementationVersion;
			mDescription = gcnew String(src->description);
		}
	};

#ifdef VK_USE_PLATFORM_WIN32_KHR

	public ref class Win32SurfaceCreateInfoKHR
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
		IntPtr mHinstance;
		IntPtr mHwnd;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}

		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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

		property IntPtr Hinstance
		{
			IntPtr get()
			{
				return mHinstance;
			}
			void set(IntPtr value)
			{
				mHinstance = value;
			}
		}

		property IntPtr Hwnd
		{
			IntPtr get()
			{
				return mHwnd;
			}
			void set(IntPtr value)
			{
				mHwnd = value;
			}
		}
	internal:
		void CopyTo(VkWin32SurfaceCreateInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->hinstance = (HINSTANCE) mHinstance.ToPointer();
			dst->hwnd = (HWND) mHwnd.ToPointer();
		}

		//void CopyFrom(VkWin32SurfaceCreateInfoKHR* src)
		//{
		//	mSType = (StructureType) src->sType;
		//	mFlags = src->flags;
		//	mHinstance = src->hinstance;
		//	mHwnd = src->hwnd;
		//}
	};

#endif

	public ref class DebugReportCallbackCreateInfoEXT
	{
	private:
		StructureType mSType;
		ManagedVulkan::DebugReportFlagBitsEXT mFlags;
		PFN_vkDebugReportCallbackEXT^ mPfnCallback = nullptr;
		IntPtr mUserData = IntPtr::Zero;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property ManagedVulkan::DebugReportFlagBitsEXT Flags
		{
			ManagedVulkan::DebugReportFlagBitsEXT get()
			{
				return mFlags;
			}
			void set(ManagedVulkan::DebugReportFlagBitsEXT value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = (VkDebugReportFlagBitsEXT) mFlags;
			// TODO : callback functions
			// dst->pfnCallback = mPfnCallback;

			dst->pUserData = mUserData.ToPointer();
		}

		//void CopyFrom(VkDebugReportCallbackCreateInfoEXT* src)
		//{
		//	mSType = (StructureType) src->sType;
		//	mFlags = src->flags;
		//	mPfnCallback = src->pfnCallback;
		//	mUserData = src->pUserData;
		//}
	};

	public ref struct Vec2f
	{
	private:
		float mX;
		float mY;
	internal:
		void CopyTo(float* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
		}

		void CopyFrom(float* src)
		{
			mX = src[0];
			mY = src[1];
		}
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
	};

	public ref struct Vec3f
	{
	private:
		float mX;
		float mY;
		float mZ;
	internal:
		void CopyTo(float* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
			dst[2] = mZ;
		}

		void CopyFrom(float* src)
		{
			mX = src[0];
			mY = src[1];
			mZ = src[2];
		}
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

		property float Z
		{
			float get()
			{
				return mZ;
			}
			void set(float value)
			{
				mZ = value;
			}
		}
	};

	public ref struct Vec3Ui
	{
	private:
		UInt32 mX;
		UInt32 mY;
		UInt32 mZ;
	internal:
		void CopyTo(UInt32* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
			dst[2] = mZ;
		}

		void CopyFrom(UInt32* src)
		{
			mX = src[0];
			mY = src[1];
			mZ = src[2];
		}
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

	public ref struct Vec2Ui
	{
	private:
		UInt32 mX;
		UInt32 mY;
	internal:
		void CopyTo(UInt32* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
		}

		void CopyFrom(UInt32* src)
		{
			mX = src[0];
			mY = src[1];
		}
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
		Vec3Ui^ mMaxComputeWorkGroupCount = gcnew Vec3Ui();
		UInt32 mMaxComputeWorkGroupInvocations = 0;
		Vec3Ui^ mMaxComputeWorkGroupSize = gcnew Vec3Ui();
		UInt32 mSubPixelPrecisionBits = 0;
		UInt32 mSubTexelPrecisionBits = 0;
		UInt32 mMipmapPrecisionBits = 0;
		UInt32 mMaxDrawIndexedIndexValue = 0;
		UInt32 mMaxDrawIndirectCount = 0;
		float mMaxSamplerLodBias = 0;
		float mMaxSamplerAnisotropy = 0;
		UInt32 mMaxViewports = 0;
		Vec2Ui^ mMaxViewportDimensions = gcnew Vec2Ui();
		Vec2f^ mViewportBoundsRange = gcnew Vec2f();
		UInt32 mViewportSubPixelBits = 0;
		size_t mMinMemoryMapAlignment;
		UInt64 mMinTexelBufferOffsetAlignment = 0;
		UInt64 mMinUniformBufferOffsetAlignment = 0;
		UInt64 mMinStorageBufferOffsetAlignment = 0;
		Int32 mMinTexelOffset = 0;
		UInt32 mMaxTexelOffset = 0;
		Int32 mMinTexelGatherOffset = 0;
		UInt32 mMaxTexelGatherOffset = 0;
		float mMinInterpolationOffset = 0;
		float mMaxInterpolationOffset = 0;
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
		float mTimestampPeriod = 0;
		UInt32 mMaxClipDistances = 0;
		UInt32 mMaxCullDistances = 0;
		UInt32 mMaxCombinedClipAndCullDistances = 0;
		UInt32 mDiscreteQueuePriorities = 0;
		Vec2f^ mPointSizeRange = gcnew Vec2f();
		Vec2f^ mLineWidthRange = gcnew Vec2f();
		float mPointSizeGranularity = 0;
		float mLineWidthGranularity = 0;
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
		property Vec3Ui^ MaxComputeWorkGroupCount
		{
			Vec3Ui^ get()
			{
				return mMaxComputeWorkGroupCount;
			}
			void set(Vec3Ui^ value)
			{
				mMaxComputeWorkGroupCount = value;
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
		property Vec3Ui^ MaxComputeWorkGroupSize
		{
			Vec3Ui^ get()
			{
				return mMaxComputeWorkGroupSize;
			}
			void set(Vec3Ui^ value)
			{
				mMaxComputeWorkGroupSize = value;
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
		property Vec2Ui^ MaxViewportDimensions
		{
			Vec2Ui^ get()
			{
				return mMaxViewportDimensions;
			}
			void set(Vec2Ui^ value)
			{
				mMaxViewportDimensions = value;
			}
		}
		property Vec2f^ ViewportBoundsRange
		{
			Vec2f^ get()
			{
				return mViewportBoundsRange;
			}
			void set(Vec2f^ value)
			{
				mViewportBoundsRange = value;
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
		property size_t MinMemoryMapAlignment
		{
			size_t get()
			{
				return mMinMemoryMapAlignment;
			}
			void set(size_t value)
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
		property Vec2f^ PointSizeRange
		{
			Vec2f^ get()
			{
				return mPointSizeRange;
			}
			void set(Vec2f^ value)
			{
				mPointSizeRange = value;
			}
		}
		property Vec2f^ LineWidthRange
		{
			Vec2f^ get()
			{
				return mLineWidthRange;
			}
			void set(Vec2f^ value)
			{
				mLineWidthRange = value;
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
			dst->maxImageDimension1D = mMaxImageDimension1D;
			dst->maxImageDimension2D = mMaxImageDimension2D;
			dst->maxImageDimension3D = mMaxImageDimension3D;
			dst->maxImageDimensionCube = mMaxImageDimensionCube;
			dst->maxImageArrayLayers = mMaxImageArrayLayers;
			dst->maxTexelBufferElements = mMaxTexelBufferElements;
			dst->maxUniformBufferRange = mMaxUniformBufferRange;
			dst->maxStorageBufferRange = mMaxStorageBufferRange;
			dst->maxPushConstantsSize = mMaxPushConstantsSize;
			dst->maxMemoryAllocationCount = mMaxMemoryAllocationCount;
			dst->maxSamplerAllocationCount = mMaxSamplerAllocationCount;
			dst->bufferImageGranularity = mBufferImageGranularity;
			dst->sparseAddressSpaceSize = mSparseAddressSpaceSize;
			dst->maxBoundDescriptorSets = mMaxBoundDescriptorSets;
			dst->maxPerStageDescriptorSamplers = mMaxPerStageDescriptorSamplers;
			dst->maxPerStageDescriptorUniformBuffers = mMaxPerStageDescriptorUniformBuffers;
			dst->maxPerStageDescriptorStorageBuffers = mMaxPerStageDescriptorStorageBuffers;
			dst->maxPerStageDescriptorSampledImages = mMaxPerStageDescriptorSampledImages;
			dst->maxPerStageDescriptorStorageImages = mMaxPerStageDescriptorStorageImages;
			dst->maxPerStageDescriptorInputAttachments = mMaxPerStageDescriptorInputAttachments;
			dst->maxPerStageResources = mMaxPerStageResources;
			dst->maxDescriptorSetSamplers = mMaxDescriptorSetSamplers;
			dst->maxDescriptorSetUniformBuffers = mMaxDescriptorSetUniformBuffers;
			dst->maxDescriptorSetUniformBuffersDynamic = mMaxDescriptorSetUniformBuffersDynamic;
			dst->maxDescriptorSetStorageBuffers = mMaxDescriptorSetStorageBuffers;
			dst->maxDescriptorSetStorageBuffersDynamic = mMaxDescriptorSetStorageBuffersDynamic;
			dst->maxDescriptorSetSampledImages = mMaxDescriptorSetSampledImages;
			dst->maxDescriptorSetStorageImages = mMaxDescriptorSetStorageImages;
			dst->maxDescriptorSetInputAttachments = mMaxDescriptorSetInputAttachments;
			dst->maxVertexInputAttributes = mMaxVertexInputAttributes;
			dst->maxVertexInputBindings = mMaxVertexInputBindings;
			dst->maxVertexInputAttributeOffset = mMaxVertexInputAttributeOffset;
			dst->maxVertexInputBindingStride = mMaxVertexInputBindingStride;
			dst->maxVertexOutputComponents = mMaxVertexOutputComponents;
			dst->maxTessellationGenerationLevel = mMaxTessellationGenerationLevel;
			dst->maxTessellationPatchSize = mMaxTessellationPatchSize;
			dst->maxTessellationControlPerVertexInputComponents = mMaxTessellationControlPerVertexInputComponents;
			dst->maxTessellationControlPerVertexOutputComponents = mMaxTessellationControlPerVertexOutputComponents;
			dst->maxTessellationControlPerPatchOutputComponents = mMaxTessellationControlPerPatchOutputComponents;
			dst->maxTessellationControlTotalOutputComponents = mMaxTessellationControlTotalOutputComponents;
			dst->maxTessellationEvaluationInputComponents = mMaxTessellationEvaluationInputComponents;
			dst->maxTessellationEvaluationOutputComponents = mMaxTessellationEvaluationOutputComponents;
			dst->maxGeometryShaderInvocations = mMaxGeometryShaderInvocations;
			dst->maxGeometryInputComponents = mMaxGeometryInputComponents;
			dst->maxGeometryOutputComponents = mMaxGeometryOutputComponents;
			dst->maxGeometryOutputVertices = mMaxGeometryOutputVertices;
			dst->maxGeometryTotalOutputComponents = mMaxGeometryTotalOutputComponents;
			dst->maxFragmentInputComponents = mMaxFragmentInputComponents;
			dst->maxFragmentOutputAttachments = mMaxFragmentOutputAttachments;
			dst->maxFragmentDualSrcAttachments = mMaxFragmentDualSrcAttachments;
			dst->maxFragmentCombinedOutputResources = mMaxFragmentCombinedOutputResources;
			dst->maxComputeSharedMemorySize = mMaxComputeSharedMemorySize;
			mMaxComputeWorkGroupCount->CopyTo(dst->maxComputeWorkGroupCount);
			dst->maxComputeWorkGroupInvocations = mMaxComputeWorkGroupInvocations;
			mMaxComputeWorkGroupSize->CopyTo(dst->maxComputeWorkGroupSize);
			dst->subPixelPrecisionBits = mSubPixelPrecisionBits;
			dst->subTexelPrecisionBits = mSubTexelPrecisionBits;
			dst->mipmapPrecisionBits = mMipmapPrecisionBits;
			dst->maxDrawIndexedIndexValue = mMaxDrawIndexedIndexValue;
			dst->maxDrawIndirectCount = mMaxDrawIndirectCount;
			dst->maxSamplerLodBias = mMaxSamplerLodBias;
			dst->maxSamplerAnisotropy = mMaxSamplerAnisotropy;
			dst->maxViewports = mMaxViewports;
			mMaxViewportDimensions->CopyTo(dst->maxViewportDimensions);
			mViewportBoundsRange->CopyTo(dst->viewportBoundsRange);
			dst->viewportSubPixelBits = mViewportSubPixelBits;
			dst->minMemoryMapAlignment = mMinMemoryMapAlignment;
			dst->minTexelBufferOffsetAlignment = mMinTexelBufferOffsetAlignment;
			dst->minUniformBufferOffsetAlignment = mMinUniformBufferOffsetAlignment;
			dst->minStorageBufferOffsetAlignment = mMinStorageBufferOffsetAlignment;
			dst->minTexelOffset = mMinTexelOffset;
			dst->maxTexelOffset = mMaxTexelOffset;
			dst->minTexelGatherOffset = mMinTexelGatherOffset;
			dst->maxTexelGatherOffset = mMaxTexelGatherOffset;
			dst->minInterpolationOffset = mMinInterpolationOffset;
			dst->maxInterpolationOffset = mMaxInterpolationOffset;
			dst->subPixelInterpolationOffsetBits = mSubPixelInterpolationOffsetBits;
			dst->maxFramebufferWidth = mMaxFramebufferWidth;
			dst->maxFramebufferHeight = mMaxFramebufferHeight;
			dst->maxFramebufferLayers = mMaxFramebufferLayers;
			dst->framebufferColorSampleCounts = mFramebufferColorSampleCounts;
			dst->framebufferDepthSampleCounts = mFramebufferDepthSampleCounts;
			dst->framebufferStencilSampleCounts = mFramebufferStencilSampleCounts;
			dst->framebufferNoAttachmentsSampleCounts = mFramebufferNoAttachmentsSampleCounts;
			dst->maxColorAttachments = mMaxColorAttachments;
			dst->sampledImageColorSampleCounts = mSampledImageColorSampleCounts;
			dst->sampledImageIntegerSampleCounts = mSampledImageIntegerSampleCounts;
			dst->sampledImageDepthSampleCounts = mSampledImageDepthSampleCounts;
			dst->sampledImageStencilSampleCounts = mSampledImageStencilSampleCounts;
			dst->storageImageSampleCounts = mStorageImageSampleCounts;
			dst->maxSampleMaskWords = mMaxSampleMaskWords;
			dst->timestampComputeAndGraphics = mTimestampComputeAndGraphics;
			dst->timestampPeriod = mTimestampPeriod;
			dst->maxClipDistances = mMaxClipDistances;
			dst->maxCullDistances = mMaxCullDistances;
			dst->maxCombinedClipAndCullDistances = mMaxCombinedClipAndCullDistances;
			dst->discreteQueuePriorities = mDiscreteQueuePriorities;
			mPointSizeRange->CopyTo(dst->pointSizeRange);
			mLineWidthRange->CopyTo(dst->lineWidthRange);
			dst->pointSizeGranularity = mPointSizeGranularity;
			dst->lineWidthGranularity = mLineWidthGranularity;
			dst->strictLines = mStrictLines;
			dst->standardSampleLocations = mStandardSampleLocations;
			dst->optimalBufferCopyOffsetAlignment = mOptimalBufferCopyOffsetAlignment;
			dst->optimalBufferCopyRowPitchAlignment = mOptimalBufferCopyRowPitchAlignment;
			dst->nonCoherentAtomSize = mNonCoherentAtomSize;
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
			mMaxComputeWorkGroupCount->CopyFrom(src->maxComputeWorkGroupCount);
			mMaxComputeWorkGroupInvocations = src->maxComputeWorkGroupInvocations;
			mMaxComputeWorkGroupSize->CopyFrom(src->maxComputeWorkGroupSize);
			mSubPixelPrecisionBits = src->subPixelPrecisionBits;
			mSubTexelPrecisionBits = src->subTexelPrecisionBits;
			mMipmapPrecisionBits = src->mipmapPrecisionBits;
			mMaxDrawIndexedIndexValue = src->maxDrawIndexedIndexValue;
			mMaxDrawIndirectCount = src->maxDrawIndirectCount;
			mMaxSamplerLodBias = src->maxSamplerLodBias;
			mMaxSamplerAnisotropy = src->maxSamplerAnisotropy;
			mMaxViewports = src->maxViewports;
			mMaxViewportDimensions->CopyFrom(src->maxViewportDimensions);
			mViewportBoundsRange->CopyFrom(src->viewportBoundsRange);
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
			mPointSizeRange->CopyFrom(src->pointSizeRange);
			mLineWidthRange->CopyFrom(src->lineWidthRange);
			mPointSizeGranularity = src->pointSizeGranularity;
			mLineWidthGranularity = src->lineWidthGranularity;
			mStrictLines = src->strictLines != 0;
			mStandardSampleLocations = src->standardSampleLocations != 0;
			mOptimalBufferCopyOffsetAlignment = src->optimalBufferCopyOffsetAlignment;
			mOptimalBufferCopyRowPitchAlignment = src->optimalBufferCopyRowPitchAlignment;
			mNonCoherentAtomSize = src->nonCoherentAtomSize;
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
			dst->residencyStandard2DBlockShape = mResidencyStandard2DBlockShape ? 1 : 0;
			dst->residencyStandard2DMultisampleBlockShape = mResidencyStandard2DMultisampleBlockShape ? 1 : 0;;
			dst->residencyStandard3DBlockShape = mResidencyStandard3DBlockShape ? 1 : 0;;
			dst->residencyAlignedMipSize = mResidencyAlignedMipSize ? 1 : 0;
			dst->residencyNonResidentStrict = mResidencyNonResidentStrict ? 1 : 0;;
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


	public ref class PhysicalDeviceProperties
	{
	private:
		UInt32 mApiVersion = 0;
		UInt32 mDriverVersion = 0;
		UInt32 mVendorID = 0;
		UInt32 mDeviceID = 0;
		ManagedVulkan::PhysicalDeviceType mDeviceType;
		String^ mDeviceName = nullptr;
		const int UUID_SIZE = 16;
		array<Byte>^ mPipelineCacheUUID = gcnew array<Byte>(UUID_SIZE);
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
		property ManagedVulkan::PhysicalDeviceType DeviceType
		{
			ManagedVulkan::PhysicalDeviceType get()
			{
				return mDeviceType;
			}
			void set(ManagedVulkan::PhysicalDeviceType value)
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
		//void CopyTo(VkPhysicalDeviceProperties* dst, List<IntPtr>^ pins)
		//{
		//	dst->apiVersion = mApiVersion;
		//	dst->driverVersion = mDriverVersion;
		//	dst->vendorID = mVendorID;
		//	dst->deviceID = mDeviceID;
		//	dst->deviceType = (VkPhysicalDeviceType) mDeviceType;

		//	IntPtr str_deviceName = Marshal::StringToHGlobalAnsi(mDeviceName);
		//	pins->Add(str_deviceName);
		//	dst->deviceName = static_cast <char*> (str_deviceName.ToPointer());

		//	//dst->pipelineCacheUUID = mPipelineCacheUUID;
		//	//dst->limits = mLimits
		//	//dst->sparseProperties = mSparseProperties;
		//}

		void CopyFrom(VkPhysicalDeviceProperties* src)
		{
			mApiVersion = src->apiVersion;
			mDriverVersion = src->driverVersion;
			mVendorID = src->vendorID;
			mDeviceID = src->deviceID;
			mDeviceType = (PhysicalDeviceType) src->deviceType;
			mDeviceName = gcnew String(src->deviceName);			

			for (int i = 0; i < UUID_SIZE; ++i)
			{
				// TODO : probably needs byte copy
				mPipelineCacheUUID[i] = src->pipelineCacheUUID[i];
			}

			mLimits->CopyFrom(&src->limits);

			mSparseProperties->CopyFrom(&src->sparseProperties);
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
			dst->queueFlags = mQueueFlags;
			dst->queueCount = mQueueCount;
			dst->timestampValidBits = mTimestampValidBits;
			mMinImageTransferGranularity->CopyTo(&dst->minImageTransferGranularity, pins);
		}

		void CopyFrom(VkQueueFamilyProperties* src)
		{
			mQueueFlags = src->queueFlags;
			mQueueCount = src->queueCount;
			mTimestampValidBits = src->timestampValidBits;
			mMinImageTransferGranularity->CopyFrom(&src->minImageTransferGranularity);
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
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
			dst->size = mSize;
			dst->flags = mFlags;
		}

		void CopyFrom(VkMemoryHeap* src)
		{
			mSize = src->size;
			mFlags = src->flags;
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
			dst->propertyFlags = mPropertyFlags;
			dst->heapIndex = mHeapIndex;
		}

		void CopyFrom(VkMemoryType* src)
		{
			mPropertyFlags = src->propertyFlags;
			mHeapIndex = src->heapIndex;
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
			dst->robustBufferAccess = mRobustBufferAccess ? 1 : 0;
			dst->fullDrawIndexUint32 = mFullDrawIndexUint32 ? 1 : 0;
			dst->imageCubeArray = mImageCubeArray ? 1 : 0;
			dst->independentBlend = mIndependentBlend ? 1 : 0;
			dst->geometryShader = mGeometryShader ? 1 : 0;
			dst->tessellationShader = mTessellationShader ? 1 : 0;
			dst->sampleRateShading = mSampleRateShading ? 1 : 0;
			dst->dualSrcBlend = mDualSrcBlend ? 1 : 0;
			dst->logicOp = mLogicOp ? 1 : 0;
			dst->multiDrawIndirect = mMultiDrawIndirect ? 1 : 0;
			dst->drawIndirectFirstInstance = mDrawIndirectFirstInstance ? 1 : 0;
			dst->depthClamp = mDepthClamp ? 1 : 0;
			dst->depthBiasClamp = mDepthBiasClamp ? 1 : 0;
			dst->fillModeNonSolid = mFillModeNonSolid ? 1 : 0;
			dst->depthBounds = mDepthBounds ? 1 : 0;
			dst->wideLines = mWideLines ? 1 : 0;
			dst->largePoints = mLargePoints ? 1 : 0;
			dst->alphaToOne = mAlphaToOne ? 1 : 0;
			dst->multiViewport = mMultiViewport ? 1 : 0;
			dst->samplerAnisotropy = mSamplerAnisotropy ? 1 : 0;
			dst->textureCompressionETC2 = mTextureCompressionETC2 ? 1 : 0;
			dst->textureCompressionASTC_LDR = mTextureCompressionASTC_LDR ? 1 : 0;
			dst->textureCompressionBC = mTextureCompressionBC ? 1 : 0;
			dst->occlusionQueryPrecise = mOcclusionQueryPrecise ? 1 : 0;
			dst->pipelineStatisticsQuery = mPipelineStatisticsQuery ? 1 : 0;
			dst->vertexPipelineStoresAndAtomics = mVertexPipelineStoresAndAtomics ? 1 : 0;
			dst->fragmentStoresAndAtomics = mFragmentStoresAndAtomics ? 1 : 0;
			dst->shaderTessellationAndGeometryPointSize = mShaderTessellationAndGeometryPointSize ? 1 : 0;
			dst->shaderImageGatherExtended = mShaderImageGatherExtended ? 1 : 0;
			dst->shaderStorageImageExtendedFormats = mShaderStorageImageExtendedFormats ? 1 : 0;
			dst->shaderStorageImageMultisample = mShaderStorageImageMultisample ? 1 : 0;
			dst->shaderStorageImageReadWithoutFormat = mShaderStorageImageReadWithoutFormat ? 1 : 0;
			dst->shaderStorageImageWriteWithoutFormat = mShaderStorageImageWriteWithoutFormat ? 1 : 0;
			dst->shaderUniformBufferArrayDynamicIndexing = mShaderUniformBufferArrayDynamicIndexing ? 1 : 0;
			dst->shaderSampledImageArrayDynamicIndexing = mShaderSampledImageArrayDynamicIndexing ? 1 : 0;
			dst->shaderStorageBufferArrayDynamicIndexing = mShaderStorageBufferArrayDynamicIndexing ? 1 : 0;
			dst->shaderStorageImageArrayDynamicIndexing = mShaderStorageImageArrayDynamicIndexing ? 1 : 0;
			dst->shaderClipDistance = mShaderClipDistance ? 1 : 0;
			dst->shaderCullDistance = mShaderCullDistance ? 1 : 0;
			dst->shaderFloat64 = mShaderFloat64 ? 1 : 0;
			dst->shaderInt64 = mShaderInt64 ? 1 : 0;
			dst->shaderInt16 = mShaderInt16 ? 1 : 0;
			dst->shaderResourceResidency = mShaderResourceResidency ? 1 : 0;
			dst->shaderResourceMinLod = mShaderResourceMinLod ? 1 : 0;
			dst->sparseBinding = mSparseBinding ? 1 : 0;
			dst->sparseResidencyBuffer = mSparseResidencyBuffer ? 1 : 0;
			dst->sparseResidencyImage2D = mSparseResidencyImage2D ? 1 : 0;
			dst->sparseResidencyImage3D = mSparseResidencyImage3D ? 1 : 0;
			dst->sparseResidency2Samples = mSparseResidency2Samples ? 1 : 0;
			dst->sparseResidency4Samples = mSparseResidency4Samples ? 1 : 0;
			dst->sparseResidency8Samples = mSparseResidency8Samples ? 1 : 0;
			dst->sparseResidency16Samples = mSparseResidency16Samples ? 1 : 0;
			dst->sparseResidencyAliased = mSparseResidencyAliased ? 1 : 0;
			dst->variableMultisampleRate = mVariableMultisampleRate ? 1 : 0;
			dst->inheritedQueries = mInheritedQueries ? 1 : 0;
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
	
	public ref class PhysicalDeviceMemoryProperties
	{
	private:
		const int MAX_MEMORY_TYPES = 32;
		const int MAX_MEMORY_HEAPS = 16;

		UInt32 mMemoryTypeCount = 0;
		array<MemoryType^>^ mMemoryTypes = gcnew array<MemoryType^>(MAX_MEMORY_TYPES);
		UInt32 mMemoryHeapCount = 0;
		array<MemoryHeap^>^ mMemoryHeaps = gcnew array<MemoryHeap^>(MAX_MEMORY_HEAPS);
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
		property array<MemoryType^>^ MemoryTypes
		{
			array<MemoryType^>^ get()
			{
				return mMemoryTypes;
			}
			void set(array<MemoryType^>^ value)
			{
				mMemoryTypes = value;
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
		property array<MemoryHeap^>^ MemoryHeaps
		{
			array<MemoryHeap^>^ get()
			{
				return mMemoryHeaps;
			}
			void set(array<MemoryHeap^>^ value)
			{
				mMemoryHeaps = value;
			}
		}
	internal:
		void CopyTo(VkPhysicalDeviceMemoryProperties* dst, List<IntPtr>^ pins)
		{
			dst->memoryTypeCount = mMemoryTypeCount;

			for (UInt32 i = 0; i < mMemoryTypeCount; ++i)
			{
				mMemoryTypes[i]->CopyTo(dst->memoryTypes + i, pins);
			}

			dst->memoryHeapCount = mMemoryHeapCount;
			for (UInt32 i = 0; i < mMemoryHeapCount; ++i)
			{

				mMemoryHeaps[i]->CopyTo(dst->memoryHeaps + i, pins);
			}
		}

		void CopyFrom(VkPhysicalDeviceMemoryProperties* src)
		{
			mMemoryTypeCount = src->memoryTypeCount;

			for (UInt32 i = 0; i < mMemoryTypeCount; ++i)
			{
				mMemoryTypes[i]->CopyFrom(src->memoryTypes + i);
			}

			mMemoryHeapCount = src->memoryHeapCount;
			for (UInt32 i = 0; i < mMemoryHeapCount; ++i)
			{

				mMemoryHeaps[i]->CopyFrom(src->memoryHeaps + i);
			}
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
			mMaxExtent->CopyTo(&dst->maxExtent, pins);
			dst->maxMipLevels = mMaxMipLevels;
			dst->maxArrayLayers = mMaxArrayLayers;
			dst->sampleCounts = mSampleCounts;
			dst->maxResourceSize = mMaxResourceSize;
		}

		void CopyFrom(VkImageFormatProperties* src)
		{
			mMaxExtent->CopyFrom(&src->maxExtent);
			mMaxMipLevels = src->maxMipLevels;
			mMaxArrayLayers = src->maxArrayLayers;
			mSampleCounts = src->sampleCounts;
			mMaxResourceSize = src->maxResourceSize;
		}
	};

	public ref class DeviceQueueCreateInfo
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
		UInt32 mQueueFamilyIndex = 0;
		UInt32 mQueueCount = 0;
		array<float>^ mQueuePriorities = nullptr;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
		property array<float>^ QueuePriorities
		{
			array<float>^ get()
			{
				return mQueuePriorities;
			}
			void set(array<float>^ value)
			{
				mQueuePriorities = value;
			}
		}
	internal:
		void CopyTo(VkDeviceQueueCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->queueFamilyIndex = mQueueFamilyIndex;
			dst->queueCount = mQueueCount;
		}

		void CopyFrom(VkDeviceQueueCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = src->flags;
			mQueueFamilyIndex = src->queueFamilyIndex;
			mQueueCount = src->queueCount;
		}
	};


	public ref class DeviceCreateInfo
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
		UInt32 mQueueCreateInfoCount = 0;
		DeviceQueueCreateInfo^ mQueueCreateInfos = nullptr;
		UInt32 mEnabledLayerCount = 0;
		array<String^>^ mEnabledLayerNames = nullptr;
		UInt32 mEnabledExtensionCount = 0;
		array<String^>^ mEnabledExtensionNames = nullptr;
		PhysicalDeviceFeatures^ mEnabledFeatures = nullptr;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			//dst->queueCreateInfoCount = mQueueCreateInfoCount;
			//dst->pQueueCreateInfos = mQueueCreateInfos;
			//dst->enabledLayerCount = mEnabledLayerCount;
			//dst->ppEnabledLayerNames = mEnabledLayerNames;
			//dst->enabledExtensionCount = mEnabledExtensionCount;
			//dst->ppEnabledExtensionNames = mEnabledExtensionNames;
			//dst->pEnabledFeatures = mEnabledFeatures;
		}

		void CopyFrom(VkDeviceCreateInfo* src)
		{
			mSType = (StructureType) src->sType;
			mFlags = src->flags;
			//mQueueCreateInfoCount = src->queueCreateInfoCount;
			//mQueueCreateInfos = src->pQueueCreateInfos;
			//mEnabledLayerCount = src->enabledLayerCount;
			//mEnabledLayerNames = src->ppEnabledLayerNames;
			//mEnabledExtensionCount = src->enabledExtensionCount;
			//mEnabledExtensionNames = src->ppEnabledExtensionNames;
			//mEnabledFeatures = src->pEnabledFeatures;
		}
	};

	public ref class SparseImageFormatProperties
	{
	private:
		UInt32 mAspectMask;
		Extent3D^ mImageGranularity = gcnew Extent3D();
		ManagedVulkan::SparseMemoryBindFlagBits mFlags;
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
		property ManagedVulkan::SparseMemoryBindFlagBits Flags
		{
			ManagedVulkan::SparseMemoryBindFlagBits get()
			{
				return mFlags;
			}
			void set(ManagedVulkan::SparseMemoryBindFlagBits value)
			{
				mFlags = value;
			}
		}
	internal:
		void CopyTo(VkSparseImageFormatProperties* dst, List<IntPtr>^ pins)
		{
			dst->aspectMask = mAspectMask;
			mImageGranularity->CopyTo(&dst->imageGranularity, pins);
			dst->flags = (VkSparseMemoryBindFlagBits) mFlags;
		}

		void CopyFrom(VkSparseImageFormatProperties* src)
		{
			mAspectMask = src->aspectMask;
			mImageGranularity->CopyFrom(&src->imageGranularity);
			mFlags = (ManagedVulkan::SparseMemoryBindFlagBits) src->flags;
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
			dst->display = mDisplay->mHandle;

			IntPtr str_displayName = Marshal::StringToHGlobalAnsi(mDisplayName);
			pins->Add(str_displayName);
			dst->displayName = static_cast <char*> (str_displayName.ToPointer());

			mPhysicalDimensions->CopyTo(&dst->physicalDimensions, pins);
			mPhysicalResolution->CopyTo(&dst->physicalResolution, pins);
			dst->supportedTransforms = mSupportedTransforms ? 1 : 0;
			dst->planeReorderPossible = mPlaneReorderPossible ? 1 : 0;
			dst->persistentContent = mPersistentContent ? 1 : 0;
		}

		void CopyFrom(VkDisplayPropertiesKHR* src)
		{
			mDisplay->mHandle = src->display;
			mDisplayName = gcnew String(mDisplayName);
			mPhysicalDimensions->CopyFrom(&src->physicalDimensions);
			mPhysicalResolution->CopyFrom(&src->physicalResolution);
			mSupportedTransforms = src->supportedTransforms != 0;
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
			dst->currentDisplay = mCurrentDisplay->mHandle;
			dst->currentStackIndex = mCurrentStackIndex;
		}

		void CopyFrom(VkDisplayPlanePropertiesKHR* src)
		{
			mCurrentDisplay->mHandle = src->currentDisplay;
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
			mVisibleRegion->CopyTo(&dst->visibleRegion, pins);
			dst->refreshRate = mRefreshRate;
		}

		void CopyFrom(VkDisplayModeParametersKHR* src)
		{
			mVisibleRegion->CopyFrom(&src->visibleRegion);
			mRefreshRate = src->refreshRate;
		}
	};


	public ref class DisplayModePropertiesKHR
	{
	private:
		DisplayModeKHR^ mDisplayMode = gcnew DisplayModeKHR;
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
			dst->displayMode = mDisplayMode->mHandle;
			mParameters->CopyTo(&dst->parameters, pins);
		}

		void CopyFrom(VkDisplayModePropertiesKHR* src)
		{
			mDisplayMode->mHandle = src->displayMode;
			mParameters->CopyFrom(&src->parameters);
		}
	};

	public ref class DisplayModeCreateInfoKHR
	{
	private:
		StructureType mSType;
		UInt32	mFlags;
		DisplayModeParametersKHR^  mParameters = gcnew DisplayModeParametersKHR();
	public:
		property StructureType SType
		{
			StructureType get()
			{
				return mSType;
			}
			void set(StructureType value)
			{
				mSType = value;
			}			
		}
	
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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

	internal:
		void CopyTo(VkDisplayModeCreateInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			mParameters->CopyTo(&dst->parameters, pins);
		}

		void CopyFrom(VkDisplayModeCreateInfoKHR* src)
		{
			mSType = (StructureType) src->sType;
			mFlags = src->flags;
			mParameters->CopyFrom(&src->parameters);
		}
	};

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
			dst->x = mX;
			dst->y = mY;
		}

		void CopyFrom(VkOffset2D* src)
		{
			mX = src->x;
			mY = src->y;
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
			dst->supportedAlpha = mSupportedAlpha;
			mMinSrcPosition->CopyTo(&dst->minSrcPosition, pins);
			mMaxSrcPosition->CopyTo(&dst->maxSrcPosition, pins);
			mMinSrcExtent->CopyTo(&dst->minSrcExtent, pins);
			mMaxSrcExtent->CopyTo(&dst->maxSrcExtent, pins);
			mMinDstPosition->CopyTo(&dst->minDstPosition, pins);
			mMaxDstPosition->CopyTo(&dst->maxDstPosition, pins);
			mMinDstExtent->CopyTo(&dst->minDstExtent, pins);
			mMaxDstExtent->CopyTo(&dst->maxDstExtent, pins);
		}

		void CopyFrom(VkDisplayPlaneCapabilitiesKHR* src)
		{
			mSupportedAlpha = src->supportedAlpha;
			mMinSrcPosition->CopyFrom(&src->minSrcPosition);
			mMaxSrcPosition->CopyFrom(&src->maxSrcPosition);
			mMinSrcExtent->CopyFrom(&src->minSrcExtent);
			mMaxSrcExtent->CopyFrom(&src->maxSrcExtent);
			mMinDstPosition->CopyFrom(&src->minDstPosition);
			mMaxDstPosition->CopyFrom(&src->maxDstPosition);
			mMinDstExtent->CopyFrom(&src->minDstExtent);
			mMaxDstExtent->CopyFrom(&src->maxDstExtent);
		}
	};

	public ref class SurfaceCapabilitiesKHR 
	{
	private:
		UInt32	minImageCount;
		UInt32	mMaxImageCount;
		Extent2D^	mCurrentExtent = gcnew Extent2D();
		Extent2D^	mMinImageExtent = gcnew Extent2D();
		Extent2D^	mMaxImageExtent = gcnew Extent2D();
		UInt32	mMaxImageArrayLayers;
		UInt32	mSupportedTransforms;
		ManagedVulkan::SurfaceTransformFlagBitsKHR	mCurrentTransform;
		UInt32	mSupportedCompositeAlpha;
		UInt32	mSupportedUsageFlags;
	public:
		property UInt32 MinImageCount
		{
			UInt32 get()
			{
				return minImageCount;
			}
			void set(UInt32 value)
			{
				minImageCount = value;
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

		property ManagedVulkan::SurfaceTransformFlagBitsKHR CurrentTransform
		{
			ManagedVulkan::SurfaceTransformFlagBitsKHR get()
			{
				return mCurrentTransform;
			}
			void set(ManagedVulkan::SurfaceTransformFlagBitsKHR value)
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
			dst->minImageCount = minImageCount;
			dst->maxImageCount = mMaxImageCount;
			mCurrentExtent->CopyTo(&dst->currentExtent, pins);
			mMinImageExtent->CopyTo(&dst->minImageExtent, pins);
			mMaxImageExtent->CopyTo(&dst->maxImageExtent, pins);
			dst->maxImageArrayLayers = mMaxImageArrayLayers;
			dst->supportedTransforms = mSupportedTransforms;
			dst->currentTransform = (VkSurfaceTransformFlagBitsKHR) mCurrentTransform;
			dst->supportedCompositeAlpha = mSupportedCompositeAlpha;
			dst->supportedUsageFlags = mSupportedUsageFlags;
		}

		void CopyFrom(VkSurfaceCapabilitiesKHR* src)
		{
			minImageCount = src->minImageCount;
			mMaxImageCount = src->maxImageCount;
			mCurrentExtent->CopyFrom(&src->currentExtent);
			mMinImageExtent->CopyFrom(&src->minImageExtent);
			mMaxImageExtent->CopyFrom(&src->maxImageExtent);
			mMaxImageArrayLayers = src->maxImageArrayLayers;
			mSupportedTransforms = src->supportedTransforms;
			mCurrentTransform = (ManagedVulkan::SurfaceTransformFlagBitsKHR) src->currentTransform;
			mSupportedCompositeAlpha = src->supportedCompositeAlpha;
			mSupportedUsageFlags = src->supportedUsageFlags;
		}
	};

	public ref class SurfaceFormatKHR
	{
	private:
		ManagedVulkan::Format mFormat;
		ManagedVulkan::ColorSpaceKHR mColorSpace;
	public:
		property ManagedVulkan::Format Format
		{
			ManagedVulkan::Format get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::Format value)
			{
				mFormat = value;
			}
		}
		property ManagedVulkan::ColorSpaceKHR ColorSpace
		{
			ManagedVulkan::ColorSpaceKHR get()
			{
				return mColorSpace;
			}
			void set(ManagedVulkan::ColorSpaceKHR value)
			{
				mColorSpace = value;
			}
		}
	internal:
		void CopyTo(VkSurfaceFormatKHR* dst, List<IntPtr>^ pins)
		{
			dst->format = (VkFormat) mFormat;
			dst->colorSpace = (VkColorSpaceKHR) mColorSpace;
		}

		void CopyFrom(VkSurfaceFormatKHR* src)
		{
			mFormat = (ManagedVulkan::Format) src->format;
			mColorSpace = (ManagedVulkan::ColorSpaceKHR) src->colorSpace;
		}
	};

	public ref class SubmitInfo
	{
	private:
		StructureType mSType;
		UInt32 mWaitSemaphoreCount = 0;
		array<ManagedVulkan::Semaphore^>^ mWaitSemaphores = nullptr;
		array<UInt32>^ mWaitDstStageMask;
		array<ManagedVulkan::CommandBuffer^>^ mCommandBuffers = nullptr;
		array<ManagedVulkan::Semaphore^>^ mSignalSemaphores = nullptr;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
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
		property array<ManagedVulkan::Semaphore^>^ WaitSemaphores
		{
			array<ManagedVulkan::Semaphore^>^ get()
			{
				return mWaitSemaphores;
			}
			void set(array<ManagedVulkan::Semaphore^>^ value)
			{
				mWaitSemaphores = value;
			}
		}
		property array<UInt32>^ WaitDstStageMask
		{
			array<UInt32>^ get()
			{
				return mWaitDstStageMask;
			}
			void set(array<UInt32>^ value)
			{
				mWaitDstStageMask = value;
			}
		}

		property array<ManagedVulkan::CommandBuffer^>^ CommandBuffers
		{
			array<ManagedVulkan::CommandBuffer^>^ get()
			{
				return mCommandBuffers;
			}
			void set(array<ManagedVulkan::CommandBuffer^>^ value)
			{
				mCommandBuffers = value;
			}
		}

		property array<ManagedVulkan::Semaphore^>^  SignalSemaphores
		{
			array<ManagedVulkan::Semaphore^>^ get()
			{
				return mSignalSemaphores;
			}
			void set(array<ManagedVulkan::Semaphore^>^ value)
			{
				mSignalSemaphores = value;
			}
		}
	internal:
		void CopyTo(VkSubmitInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;

			//dst->waitSemaphoreCount = mWaitSemaphoreCount;
			//dst->pWaitSemaphores = mWaitSemaphores;
			//dst->pWaitDstStageMask = mWaitDstStageMask;

			//dst->commandBufferCount = mCommandBufferCount;
			//dst->pCommandBuffers = mCommandBuffers;
			//dst->signalSemaphoreCount = mSignalSemaphoreCount;
			//dst->pSignalSemaphores = mSignalSemaphores;
		}

		void CopyFrom(VkSubmitInfo* src)
		{
			mSType = (StructureType) src->sType;

			//mWaitSemaphoreCount = src->waitSemaphoreCount;
			//mWaitSemaphores = src->pWaitSemaphores;
			//mWaitDstStageMask = src->pWaitDstStageMask;

			//mCommandBufferCount = src->commandBufferCount;
			//mCommandBuffers = src->pCommandBuffers;

			//mSignalSemaphoreCount = src->signalSemaphoreCount;
			//mSignalSemaphores = src->pSignalSemaphores;
		}
	};

	public ref class SparseMemoryBind
	{
	private:
		UInt64 mResourceOffset = 0;
		UInt64 mSize = 0;
		ManagedVulkan::DeviceMemory^ mMemory = gcnew ManagedVulkan::DeviceMemory();
		UInt64 mMemoryOffset = 0;
		ManagedVulkan::SparseMemoryBindFlagBits mFlags;
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
		property ManagedVulkan::SparseMemoryBindFlagBits Flags
		{
			ManagedVulkan::SparseMemoryBindFlagBits get()
			{
				return mFlags;
			}
			void set(ManagedVulkan::SparseMemoryBindFlagBits value)
			{
				mFlags = value;
			}
		}
	internal:
		void CopyTo(VkSparseMemoryBind* dst, List<IntPtr>^ pins)
		{
			dst->resourceOffset = mResourceOffset;
			dst->size = mSize;
			dst->memory = mMemory->mHandle;
			dst->memoryOffset = mMemoryOffset;
			dst->flags = (VkSparseMemoryBindFlagBits) mFlags;
		}

		void CopyFrom(VkSparseMemoryBind* src)
		{
			mResourceOffset = src->resourceOffset;
			mSize = src->size;
			mMemory->mHandle = src->memory;
			mMemoryOffset = src->memoryOffset;
			mFlags = (ManagedVulkan::SparseMemoryBindFlagBits) src->flags;
		}
	};


	public ref class SparseBufferMemoryBindInfo
	{
	private:
		ManagedVulkan::Buffer^ mBuffer = gcnew ManagedVulkan::Buffer();
		array<ManagedVulkan::SparseMemoryBind^>^ mBinds = nullptr;
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

		property array<ManagedVulkan::SparseMemoryBind^>^ Binds
		{
			array<ManagedVulkan::SparseMemoryBind^>^ get()
			{
				return mBinds;
			}
			void set(array<ManagedVulkan::SparseMemoryBind^>^ value)
			{
				mBinds = value;
			}
		}
	internal:
		void CopyTo(VkSparseBufferMemoryBindInfo* dst, List<IntPtr>^ pins)
		{
			dst->buffer = mBuffer->mHandle;
			//dst->bindCount = mBindCount;
			//mBinds->CopyFrom(dst->pBinds, pins);
		}

		void CopyFrom(VkSparseBufferMemoryBindInfo* src)
		{
			mBuffer->mHandle = src->buffer;
			//mBindCount = src->bindCount;
			//mBinds->CopyTo(&src->pBinds);
		}
	};

	public ref class SparseImageOpaqueMemoryBindInfo
	{
	private:
		ManagedVulkan::Image^ mImage = gcnew ManagedVulkan::Image();
		array<ManagedVulkan::SparseMemoryBind^>^ mBinds = nullptr;
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
		property array<ManagedVulkan::SparseMemoryBind^>^ Binds
		{
			array<ManagedVulkan::SparseMemoryBind^>^ get()
			{
				return mBinds;
			}
			void set(array<ManagedVulkan::SparseMemoryBind^>^ value)
			{
				mBinds = value;
			}
		}
	internal:
		void CopyTo(VkSparseImageOpaqueMemoryBindInfo* dst, List<IntPtr>^ pins)
		{
			dst->image = mImage->mHandle;
			//dst->bindCount = mBindCount;
			//mBinds->CopyFrom(&dst->pBinds, pins);
		}

		void CopyFrom(VkSparseImageOpaqueMemoryBindInfo* src)
		{
			mImage->mHandle = src->image;
			//mBindCount = src->bindCount;
			//mBinds->CopyTo(&src->pBinds);
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
			dst->aspectMask = mAspectMask;
			dst->mipLevel = mMipLevel;
			dst->arrayLayer = mArrayLayer;
		}

		void CopyFrom(VkImageSubresource* src)
		{
			mAspectMask = src->aspectMask;
			mMipLevel = src->mipLevel;
			mArrayLayer = src->arrayLayer;
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
			dst->x = mX;
			dst->y = mY;
			dst->z = mZ;
		}

		void CopyFrom(VkOffset3D* src)
		{
			mX = src->x;
			mY = src->y;
			mZ = src->z;
		}
	};


	public ref class SparseImageMemoryBind
	{
	private:
		ManagedVulkan::ImageSubresource^ mSubresource = gcnew ManagedVulkan::ImageSubresource();
		ManagedVulkan::Offset3D^ mOffset = gcnew ManagedVulkan::Offset3D();
		ManagedVulkan::Extent3D^ mExtent = gcnew ManagedVulkan::Extent3D();
		ManagedVulkan::DeviceMemory^ mMemory = gcnew ManagedVulkan::DeviceMemory();
		UInt64 mMemoryOffset = 0;
		ManagedVulkan::SparseMemoryBindFlagBits mFlags;
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
		property ManagedVulkan::SparseMemoryBindFlagBits Flags
		{
			ManagedVulkan::SparseMemoryBindFlagBits get()
			{
				return mFlags;
			}
			void set(ManagedVulkan::SparseMemoryBindFlagBits value)
			{
				mFlags = value;
			}
		}
	internal:
		void CopyTo(VkSparseImageMemoryBind* dst, List<IntPtr>^ pins)
		{
			mSubresource->CopyTo(&dst->subresource, pins);
			mOffset->CopyTo(&dst->offset, pins);
			mExtent->CopyTo(&dst->extent, pins);
			dst->memory = mMemory->mHandle;
			dst->memoryOffset = mMemoryOffset;
			dst->flags = (VkSparseMemoryBindFlagBits) mFlags;
		}

		void CopyFrom(VkSparseImageMemoryBind* src)
		{
			mSubresource->CopyFrom(&src->subresource);
			mOffset->CopyFrom(&src->offset);
			mExtent->CopyFrom(&src->extent);
			mMemory->mHandle = src->memory;
			mMemoryOffset = src->memoryOffset;
			mFlags = (ManagedVulkan::SparseMemoryBindFlagBits) src->flags;
		}
	};


	public ref class SparseImageMemoryBindInfo
	{
	private:
		ManagedVulkan::Image^ mImage = gcnew ManagedVulkan::Image();
		array<ManagedVulkan::SparseImageMemoryBind^>^ mBinds = nullptr;
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
		property array<ManagedVulkan::SparseImageMemoryBind^>^ Binds
		{
			array<ManagedVulkan::SparseImageMemoryBind^>^ get()
			{
				return mBinds;
			}
			void set(array<ManagedVulkan::SparseImageMemoryBind^>^ value)
			{
				mBinds = value;
			}
		}
	internal:
		void CopyTo(VkSparseImageMemoryBindInfo* dst, List<IntPtr>^ pins)
		{
			dst->image = mImage->mHandle;
			//dst->bindCount = mBindCount;
			//mBinds->CopyFrom(&dst->pBinds, pins);
		}

		void CopyFrom(VkSparseImageMemoryBindInfo* src)
		{
			mImage->mHandle = src->image;
			//mBindCount = src->bindCount;
			//mBinds->CopyTo(&src->pBinds);
		}
	};



	public ref class BindSparseInfo
	{
	private:
		StructureType mSType;
		array<ManagedVulkan::Semaphore^>^ mWaitSemaphores = nullptr;
		array<ManagedVulkan::SparseBufferMemoryBindInfo^>^ mBufferBinds = nullptr;
		array<ManagedVulkan::SparseImageOpaqueMemoryBindInfo^>^ mImageOpaqueBinds = nullptr;
		array<ManagedVulkan::SparseImageMemoryBindInfo^>^ mImageBinds = nullptr;
		array<ManagedVulkan::Semaphore^>^ mSignalSemaphores = nullptr;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property array<ManagedVulkan::Semaphore^>^ WaitSemaphores
		{
			array<ManagedVulkan::Semaphore^>^ get()
			{
				return mWaitSemaphores;
			}
			void set(array<ManagedVulkan::Semaphore^>^ value)
			{
				mWaitSemaphores = value;
			}
		}
		property array<ManagedVulkan::SparseBufferMemoryBindInfo^>^ BufferBinds
		{
			array<ManagedVulkan::SparseBufferMemoryBindInfo^>^ get()
			{
				return mBufferBinds;
			}
			void set(array<ManagedVulkan::SparseBufferMemoryBindInfo^>^ value)
			{
				mBufferBinds = value;
			}
		}
		property array<ManagedVulkan::SparseImageOpaqueMemoryBindInfo^>^ ImageOpaqueBinds
		{
			array<ManagedVulkan::SparseImageOpaqueMemoryBindInfo^>^ get()
			{
				return mImageOpaqueBinds;
			}
			void set(array<ManagedVulkan::SparseImageOpaqueMemoryBindInfo^>^ value)
			{
				mImageOpaqueBinds = value;
			}
		}

		property array<ManagedVulkan::SparseImageMemoryBindInfo^>^ ImageBinds
		{
			array<ManagedVulkan::SparseImageMemoryBindInfo^>^ get()
			{
				return mImageBinds;
			}
			void set(array<ManagedVulkan::SparseImageMemoryBindInfo^>^ value)
			{
				mImageBinds = value;
			}
		}
		property array<ManagedVulkan::Semaphore^>^ SignalSemaphores
		{
			array<ManagedVulkan::Semaphore^>^ get()
			{
				return mSignalSemaphores;
			}
			void set(array<ManagedVulkan::Semaphore^>^ value)
			{
				mSignalSemaphores = value;
			}
		}
	internal:
		void CopyTo(VkBindSparseInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			//dst->waitSemaphoreCount = mWaitSemaphoreCount;
			//dst->pWaitSemaphores = mWaitSemaphores;
			//dst->bufferBindCount = mBufferBindCount;
			//mBufferBinds->CopyFrom(&dst->pBufferBinds, pins);
			//dst->imageOpaqueBindCount = mImageOpaqueBindCount;
			//mImageOpaqueBinds->CopyFrom(&dst->pImageOpaqueBinds, pins);
			//dst->imageBindCount = mImageBindCount;
			//mImageBinds->CopyFrom(&dst->pImageBinds, pins);
			//dst->signalSemaphoreCount = mSignalSemaphoreCount;
			//dst->pSignalSemaphores = mSignalSemaphores;
		}

		void CopyFrom(VkBindSparseInfo* src)
		{
			mSType = (StructureType)src->sType;

			//mWaitSemaphoreCount = src->waitSemaphoreCount;
			//mWaitSemaphores = src->pWaitSemaphores;
			//mBufferBindCount = src->bufferBindCount;
			//mBufferBinds->CopyTo(&src->pBufferBinds);
			//mImageOpaqueBindCount = src->imageOpaqueBindCount;
			//mImageOpaqueBinds->CopyTo(&src->pImageOpaqueBinds);
			//mImageBindCount = src->imageBindCount;
			//mImageBinds->CopyTo(&src->pImageBinds);
			//mSignalSemaphoreCount = src->signalSemaphoreCount;
			//mSignalSemaphores = src->pSignalSemaphores;
		}
	};

	public ref class PresentInfoKHR
	{
	private:
		StructureType mSType;
		array<ManagedVulkan::Semaphore^>^ mWaitSemaphores = nullptr;
		UInt32 mSwapchainCount = 0;
		array<ManagedVulkan::SwapchainKHR^>^ mSwapchains = nullptr;
		array<UInt32>^ mImageIndices = nullptr;
		// REMOVED AND MOVED TO METHOD SIGNATURE - QueuePresentKHR
		//array<Result>^ mResults = nullptr;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property array<ManagedVulkan::Semaphore^>^ WaitSemaphores
		{
			array<ManagedVulkan::Semaphore^>^ get()
			{
				return mWaitSemaphores;
			}
			void set(array<ManagedVulkan::Semaphore^>^ value)
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
		// TODO : Unify Swapchains and image indices into one class
		property array<ManagedVulkan::SwapchainKHR^>^ Swapchains
		{
			array<ManagedVulkan::SwapchainKHR^>^ get()
			{
				return mSwapchains;
			}
			void set(array<ManagedVulkan::SwapchainKHR^>^ value)
			{
				mSwapchains = value;
			}
		}
		property array<UInt32>^ ImageIndices
		{
			array<UInt32>^ get()
			{
				return mImageIndices;
			}
			void set(array<UInt32>^ value)
			{
				mImageIndices = value;
			}
		}
	internal:
		void CopyTo(VkPresentInfoKHR* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			//dst->waitSemaphoreCount = mWaitSemaphoreCount;
			//dst->pWaitSemaphores = mWaitSemaphores;
			//dst->swapchainCount = mSwapchainCount;
			//dst->pSwapchains = mSwapchains;
			//dst->pImageIndices = mImageIndices;
			//dst->pResults = mResults;
		}

		void CopyFrom(VkPresentInfoKHR* src)
		{
			mSType = (StructureType)src->sType;
	
			//mWaitSemaphoreCount = src->waitSemaphoreCount;
			//mWaitSemaphores = src->pWaitSemaphores;
			//mSwapchainCount = src->swapchainCount;
			//mSwapchains = src->pSwapchains;
			//mImageIndices = src->pImageIndices;
			//mResults = src->pResults;
		}
	};

	public ref class MemoryAllocateInfo
	{
	private:
		StructureType mSType;
		UInt64 mAllocationSize = 0;
		UInt32 mMemoryTypeIndex = 0;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->allocationSize = mAllocationSize;
			dst->memoryTypeIndex = mMemoryTypeIndex;
		}

		void CopyFrom(VkMemoryAllocateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mAllocationSize = src->allocationSize;
			mMemoryTypeIndex = src->memoryTypeIndex;
		}
	};

	public ref class MappedMemoryRange
	{
	private:
		StructureType mSType;
		DeviceMemory^ mMemory = gcnew DeviceMemory();
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->memory = mMemory->mHandle;
			dst->offset = mOffset;
			dst->size = mSize;
		}

		void CopyFrom(VkMappedMemoryRange* src)
		{
			mSType = (StructureType)src->sType;
			mMemory->mHandle = src->memory;
			mOffset = src->offset;
			mSize = src->size;
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
			dst->size = mSize;
			dst->alignment = mAlignment;
			dst->memoryTypeBits = mMemoryTypeBits;
		}

		void CopyFrom(VkMemoryRequirements* src)
		{
			mSize = src->size;
			mAlignment = src->alignment;
			mMemoryTypeBits = src->memoryTypeBits;
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
			mFormatProperties->CopyTo(&dst->formatProperties, pins);
			dst->imageMipTailFirstLod = mImageMipTailFirstLod;
			dst->imageMipTailSize = mImageMipTailSize;
			dst->imageMipTailOffset = mImageMipTailOffset;
			dst->imageMipTailStride = mImageMipTailStride;
		}

		void CopyFrom(VkSparseImageMemoryRequirements* src)
		{
			mFormatProperties->CopyFrom(&src->formatProperties);
			mImageMipTailFirstLod = src->imageMipTailFirstLod;
			mImageMipTailSize = src->imageMipTailSize;
			mImageMipTailOffset = src->imageMipTailOffset;
			mImageMipTailStride = src->imageMipTailStride;
		}
	};

	public ref class FenceCreateInfo
	{
	private:
		StructureType mSType;
		ManagedVulkan::FenceCreateFlagBits mFlags;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property ManagedVulkan::FenceCreateFlagBits Flags
		{
			ManagedVulkan::FenceCreateFlagBits get()
			{
				return mFlags;
			}
			void set(ManagedVulkan::FenceCreateFlagBits value)
			{
				mFlags = value;
			}
		}
	internal:
		void CopyTo(VkFenceCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = (VkFenceCreateFlagBits) mFlags;
		}

		void CopyFrom(VkFenceCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = (ManagedVulkan::FenceCreateFlagBits) src->flags;
		}
	};

	public ref class SemaphoreCreateInfo
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
		}

		void CopyFrom(VkSemaphoreCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = src->flags;
		}
	};

	public ref class EventCreateInfo
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
		}

		void CopyFrom(VkEventCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = src->flags;
		}
	};

	public ref class QueryPoolCreateInfo
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
		QueryType mQueryType;
		UInt32 mQueryCount = 0;
		UInt32 mPipelineStatistics;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
		property ManagedVulkan::QueryType QueryType
		{
			ManagedVulkan::QueryType get()
			{
				return mQueryType;
			}
			void set(ManagedVulkan::QueryType value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->queryType = (VkQueryType) mQueryType;
			dst->queryCount = mQueryCount;
			dst->pipelineStatistics = mPipelineStatistics;
		}

		void CopyFrom(VkQueryPoolCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = src->flags;
			mQueryType = (ManagedVulkan::QueryType) src->queryType;
			mQueryCount = src->queryCount;
			mPipelineStatistics = src->pipelineStatistics;
		}
	};

	public ref class BufferCreateInfo
	{
	private:
		StructureType mSType;
		ManagedVulkan::BufferCreateFlagBits mFlags;
		UInt64 mSize = 0;
		ManagedVulkan::BufferUsageFlagBits mUsage;
		SharingMode mSharingMode;
		array<UInt32>^ mQueueFamilyIndices = nullptr;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property ManagedVulkan::BufferCreateFlagBits Flags
		{
			ManagedVulkan::BufferCreateFlagBits get()
			{
				return mFlags;
			}
			void set(ManagedVulkan::BufferCreateFlagBits value)
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
		property ManagedVulkan::BufferUsageFlagBits Usage
		{
			ManagedVulkan::BufferUsageFlagBits get()
			{
				return mUsage;
			}
			void set(ManagedVulkan::BufferUsageFlagBits value)
			{
				mUsage = value;
			}
		}
		property ManagedVulkan::SharingMode SharingMode
		{
			ManagedVulkan::SharingMode get()
			{
				return mSharingMode;
			}
			void set(ManagedVulkan::SharingMode value)
			{
				mSharingMode = value;
			}
		}

		property array<UInt32>^ QueueFamilyIndices
		{
			array<UInt32>^ get()
			{
				return mQueueFamilyIndices;
			}
			void set(array<UInt32>^ value)
			{
				mQueueFamilyIndices = value;
			}
		}
	internal:
		void CopyTo(VkBufferCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = (VkBufferCreateFlagBits) mFlags;
			dst->size = mSize;
			dst->usage = (VkBufferUsageFlagBits) mUsage;
			dst->sharingMode = (VkSharingMode) mSharingMode;
			//dst->queueFamilyIndexCount = mQueueFamilyIndexCount;
			//dst->pQueueFamilyIndices = mQueueFamilyIndices;
		}

		void CopyFrom(VkBufferCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = (ManagedVulkan::BufferCreateFlagBits) src->flags;
			mSize = src->size;
			mUsage = (ManagedVulkan::BufferUsageFlagBits) src->usage;
			mSharingMode = (ManagedVulkan::SharingMode) src->sharingMode;
			//mQueueFamilyIndexCount = src->queueFamilyIndexCount;
			//mQueueFamilyIndices = src->pQueueFamilyIndices;
		}
	};

	public ref class BufferViewCreateInfo
	{
	private:
		StructureType mSType;
		UInt32 mFlags;
		ManagedVulkan::Buffer^ mBuffer = gcnew ManagedVulkan::Buffer();
		ManagedVulkan::Format mFormat;
		UInt64 mOffset = 0;
		UInt64 mRange = 0;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
		property ManagedVulkan::Format Format
		{
			ManagedVulkan::Format get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::Format value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->buffer = mBuffer->mHandle;
			dst->format = (VkFormat) mFormat;
			dst->offset = mOffset;
			dst->range = mRange;
		}

		void CopyFrom(VkBufferViewCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = src->flags;
			mBuffer->mHandle = src->buffer;
			mFormat = (ManagedVulkan::Format) src->format;
			mOffset = src->offset;
			mRange = src->range;
		}
	};

	public ref class ImageCreateInfo
	{
	private:
		ManagedVulkan::StructureType mSType;
		UInt32 mFlags;
		ManagedVulkan::ImageType mImageType;
		ManagedVulkan::Format mFormat;
		Extent3D^ mExtent = gcnew Extent3D();
		UInt32 mMipLevels = 0;
		UInt32 mArrayLayers = 0;
		ManagedVulkan::SampleCountFlagBits mSamples;
		ManagedVulkan::ImageTiling mTiling;
		UInt32 mUsage;
		ManagedVulkan::SharingMode mSharingMode;
		array<UInt32>^ mQueueFamilyIndices = nullptr;
		ManagedVulkan::ImageLayout mInitialLayout;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
		property ManagedVulkan::ImageType ImageType
		{
			ManagedVulkan::ImageType get()
			{
				return mImageType;
			}
			void set(ManagedVulkan::ImageType value)
			{
				mImageType = value;
			}
		}
		property ManagedVulkan::Format Format
		{
			ManagedVulkan::Format get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::Format value)
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
		property ManagedVulkan::SampleCountFlagBits Samples
		{
			ManagedVulkan::SampleCountFlagBits get()
			{
				return mSamples;
			}
			void set(ManagedVulkan::SampleCountFlagBits value)
			{
				mSamples = value;
			}
		}
		property ManagedVulkan::ImageTiling Tiling
		{
			ManagedVulkan::ImageTiling get()
			{
				return mTiling;
			}
			void set(ManagedVulkan::ImageTiling value)
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
		property ManagedVulkan::SharingMode SharingMode
		{
			ManagedVulkan::SharingMode get()
			{
				return mSharingMode;
			}
			void set(ManagedVulkan::SharingMode value)
			{
				mSharingMode = value;
			}
		}

		property array<UInt32>^ QueueFamilyIndices
		{
			array<UInt32>^ get()
			{
				return mQueueFamilyIndices;
			}
			void set(array<UInt32>^ value)
			{
				mQueueFamilyIndices = value;
			}
		}
		property ManagedVulkan::ImageLayout InitialLayout
		{
			ManagedVulkan::ImageLayout get()
			{
				return mInitialLayout;
			}
			void set(ManagedVulkan::ImageLayout value)
			{
				mInitialLayout = value;
			}
		}
	internal:
		void CopyTo(VkImageCreateInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->imageType = (VkImageType) mImageType;
			dst->format = (VkFormat) mFormat;
			mExtent->CopyTo(&dst->extent, pins);
			dst->mipLevels = mMipLevels;
			dst->arrayLayers = mArrayLayers;
			dst->samples = (VkSampleCountFlagBits) mSamples;
			dst->tiling = (VkImageTiling) mTiling;
			dst->usage = mUsage;
			dst->sharingMode = (VkSharingMode) mSharingMode;
			//dst->queueFamilyIndexCount = mQueueFamilyIndexCount;
			//dst->pQueueFamilyIndices = mQueueFamilyIndices;
			dst->initialLayout = (VkImageLayout) mInitialLayout;
		}

		void CopyFrom(VkImageCreateInfo* src)
		{
			mSType = (StructureType)src->sType;

			mFlags = src->flags;
			mImageType = (ManagedVulkan::ImageType) src->imageType;
			mFormat = (ManagedVulkan::Format) src->format;
			mExtent->CopyFrom(&src->extent);
			mMipLevels = src->mipLevels;
			mArrayLayers = src->arrayLayers;
			mSamples = (ManagedVulkan::SampleCountFlagBits) src->samples;
			mTiling = (ManagedVulkan::ImageTiling)src->tiling;
			mUsage = src->usage;
			mSharingMode = (ManagedVulkan::SharingMode) src->sharingMode;
			//mQueueFamilyIndexCount = src->queueFamilyIndexCount;
			//mQueueFamilyIndices = src->pQueueFamilyIndices;
			mInitialLayout = (ManagedVulkan::ImageLayout)src->initialLayout;
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
			dst->offset = mOffset;
			dst->size = mSize;
			dst->rowPitch = mRowPitch;
			dst->arrayPitch = mArrayPitch;
			dst->depthPitch = mDepthPitch;
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

	public ref class ComponentMapping
	{
	private:
		ManagedVulkan::ComponentSwizzle mR;
		ManagedVulkan::ComponentSwizzle mG;
		ManagedVulkan::ComponentSwizzle mB;
		ManagedVulkan::ComponentSwizzle mA;
	public:
		property ManagedVulkan::ComponentSwizzle R
		{
			ManagedVulkan::ComponentSwizzle get()
			{
				return mR;
			}
			void set(ManagedVulkan::ComponentSwizzle value)
			{
				mR = value;
			}
		}
		property ManagedVulkan::ComponentSwizzle G
		{
			ManagedVulkan::ComponentSwizzle get()
			{
				return mG;
			}
			void set(ManagedVulkan::ComponentSwizzle value)
			{
				mG = value;
			}
		}
		property ManagedVulkan::ComponentSwizzle B
		{
			ManagedVulkan::ComponentSwizzle get()
			{
				return mB;
			}
			void set(ManagedVulkan::ComponentSwizzle value)
			{
				mB = value;
			}
		}
		property ManagedVulkan::ComponentSwizzle A
		{
			ManagedVulkan::ComponentSwizzle get()
			{
				return mA;
			}
			void set(ManagedVulkan::ComponentSwizzle value)
			{
				mA = value;
			}
		}
	internal:
		void CopyTo(VkComponentMapping* dst, List<IntPtr>^ pins)
		{
			dst->r = (VkComponentSwizzle) mR;
			dst->g = (VkComponentSwizzle) mG;
			dst->b = (VkComponentSwizzle) mB;
			dst->a = (VkComponentSwizzle) mA;
		}

		void CopyFrom(VkComponentMapping* src)
		{
			mR = (ManagedVulkan::ComponentSwizzle) src->r;
			mG = (ManagedVulkan::ComponentSwizzle) src->g;
			mB = (ManagedVulkan::ComponentSwizzle) src->b;
			mA = (ManagedVulkan::ComponentSwizzle) src->a;
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
			dst->aspectMask = mAspectMask;
			dst->baseMipLevel = mBaseMipLevel;
			dst->levelCount = mLevelCount;
			dst->baseArrayLayer = mBaseArrayLayer;
			dst->layerCount = mLayerCount;
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

	public ref class ImageViewCreateInfo
	{
	private:
		ManagedVulkan::StructureType mSType;
		UInt32 mFlags;
		ManagedVulkan::Image^ mImage = gcnew ManagedVulkan::Image();
		ManagedVulkan::ImageViewType mViewType;
		ManagedVulkan::Format mFormat;
		ManagedVulkan::ComponentMapping^ mComponents = gcnew ManagedVulkan::ComponentMapping();
		ManagedVulkan::ImageSubresourceRange^ mSubresourceRange = gcnew ManagedVulkan::ImageSubresourceRange();
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property UInt32 Flags	// IGNORE - RESERVED / ALWAYS UInt32
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
		property ManagedVulkan::ImageViewType ViewType
		{
			ManagedVulkan::ImageViewType get()
			{
				return mViewType;
			}
			void set(ManagedVulkan::ImageViewType value)
			{
				mViewType = value;
			}
		}
		property ManagedVulkan::Format Format
		{
			ManagedVulkan::Format get()
			{
				return mFormat;
			}
			void set(ManagedVulkan::Format value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			dst->image = mImage->mHandle;
			dst->viewType = (VkImageViewType) mViewType;
			dst->format = (VkFormat) mFormat;
			mComponents->CopyTo(&dst->components, pins);
			mSubresourceRange->CopyTo(&dst->subresourceRange, pins);
		}

		void CopyFrom(VkImageViewCreateInfo* src)
		{
			mSType = (StructureType)src->sType;
			mFlags = src->flags;
			mImage->mHandle = src->image;
			mViewType = (ManagedVulkan::ImageViewType) src->viewType;
			mFormat = (ManagedVulkan::Format) src->format;
			mComponents->CopyFrom(&src->components);
			mSubresourceRange->CopyFrom(&src->subresourceRange);
		}
	};

}