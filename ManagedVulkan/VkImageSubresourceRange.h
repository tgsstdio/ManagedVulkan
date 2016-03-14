#pragma once

#include <vulkan/vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
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

}