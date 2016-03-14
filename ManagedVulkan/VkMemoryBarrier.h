#pragma once

#include <vulkan/vulkan.h>

#include "VkEnums.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class MemoryBarrier
	{
	private:
		ManagedVulkan::StructureType mSType;
		ManagedVulkan::AccessFlagBits mSrcAccessMask;
		ManagedVulkan::AccessFlagBits mDstAccessMask;
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
	internal:
		void CopyTo(VkMemoryBarrier* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->srcAccessMask = (VkAccessFlagBits) mSrcAccessMask;
			dst->dstAccessMask = (VkAccessFlagBits) mDstAccessMask;
		}

		void CopyFrom(VkMemoryBarrier* src)
		{
			mSType = (ManagedVulkan::StructureType)src->sType;

			mSrcAccessMask = (ManagedVulkan::AccessFlagBits) src->srcAccessMask;
			mDstAccessMask = (ManagedVulkan::AccessFlagBits) src->dstAccessMask;
		}
	};

}
