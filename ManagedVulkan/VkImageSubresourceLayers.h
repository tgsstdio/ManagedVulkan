#pragma once

#include <vulkan/vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{

	public ref class ImageSubresourceLayers
	{
	private:
		ManagedVulkan::ImageAspectFlagBits mAspectMask;
		UInt32 mMipLevel = 0;
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		ImageSubresourceLayers()
		{
			// parameterless				
		}

		ImageSubresourceLayers(ManagedVulkan::ImageAspectFlagBits aspectMask, UInt32 mipLevel, UInt32 baseArrayLayer, UInt32 layerCount)
		{
			mAspectMask = aspectMask;
			mMipLevel = mipLevel;
			mBaseArrayLayer = baseArrayLayer;
			mLayerCount = layerCount;
		}

		property ManagedVulkan::ImageAspectFlagBits AspectMask
		{
			ManagedVulkan::ImageAspectFlagBits get()
			{
				return mAspectMask;
			}
			void set(ManagedVulkan::ImageAspectFlagBits value)
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
			dst->aspectMask = (VkImageAspectFlagBits) mAspectMask;
			dst->mipLevel = mMipLevel;
			dst->baseArrayLayer = mBaseArrayLayer;
			dst->layerCount = mLayerCount;
		}

		void CopyFrom(VkImageSubresourceLayers* src)
		{
			mAspectMask = (ManagedVulkan::ImageAspectFlagBits) src->aspectMask;
			mMipLevel = src->mipLevel;
			mBaseArrayLayer = src->baseArrayLayer;
			mLayerCount = src->layerCount;
		}
	};
}
