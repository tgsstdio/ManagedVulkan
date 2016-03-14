#pragma once

#include <vulkan/vulkan.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkImageSubresourceRange.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class ImageMemoryBarrier
	{
	private:
		ManagedVulkan::StructureType mSType;
		ManagedVulkan::AccessFlagBits mSrcAccessMask;
		ManagedVulkan::AccessFlagBits mDstAccessMask;
		ManagedVulkan::ImageLayout mOldLayout;
		ManagedVulkan::ImageLayout mNewLayout;
		UInt32 mSrcQueueFamilyIndex = 0;
		UInt32 mDstQueueFamilyIndex = 0;
		ManagedVulkan::Image^ mImage = gcnew ManagedVulkan::Image();
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
		property ManagedVulkan::AccessFlagBits SrcAccessMask
		{
			ManagedVulkan::AccessFlagBits get()
			{
				return mSrcAccessMask;
			}
			void set(ManagedVulkan::AccessFlagBits value)
			{
				mSrcAccessMask = value;
			}
		}
		property ManagedVulkan::AccessFlagBits DstAccessMask
		{
			ManagedVulkan::AccessFlagBits get()
			{
				return mDstAccessMask;
			}
			void set(ManagedVulkan::AccessFlagBits value)
			{
				mDstAccessMask = value;
			}
		}
		property ManagedVulkan::ImageLayout OldLayout
		{
			ManagedVulkan::ImageLayout get()
			{
				return mOldLayout;
			}
			void set(ManagedVulkan::ImageLayout value)
			{
				mOldLayout = value;
			}
		}
		property ManagedVulkan::ImageLayout NewLayout
		{
			ManagedVulkan::ImageLayout get()
			{
				return mNewLayout;
			}
			void set(ManagedVulkan::ImageLayout value)
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
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->srcAccessMask = (VkAccessFlags) mSrcAccessMask;
			dst->dstAccessMask = (VkAccessFlags) mDstAccessMask;
			dst->oldLayout = (VkImageLayout) mOldLayout;
			dst->newLayout = (VkImageLayout) mNewLayout;
			dst->srcQueueFamilyIndex = mSrcQueueFamilyIndex;
			dst->dstQueueFamilyIndex = mDstQueueFamilyIndex;
			dst->image = mImage->mHandle;
			mSubresourceRange->CopyTo(&dst->subresourceRange, pins);
		}

		void CopyFrom(VkImageMemoryBarrier* src)
		{
			mSType = (StructureType)src->sType;

			mSrcAccessMask = (ManagedVulkan::AccessFlagBits) src->srcAccessMask;
			mDstAccessMask = (ManagedVulkan::AccessFlagBits) src->dstAccessMask;
			mOldLayout = (ManagedVulkan::ImageLayout) src->oldLayout;
			mNewLayout = (ManagedVulkan::ImageLayout) src->newLayout;
			mSrcQueueFamilyIndex = src->srcQueueFamilyIndex;
			mDstQueueFamilyIndex = src->dstQueueFamilyIndex;
			mImage->mHandle = src->image;
			mSubresourceRange->CopyFrom(&src->subresourceRange);
		}
	};

}
