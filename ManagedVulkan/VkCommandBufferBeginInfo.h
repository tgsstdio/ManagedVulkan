#pragma once

#include <vulkan/vulkan.h>
#include "VkEnums.h"
#include "VkCommandBufferInheritenceInfo.h"

namespace ManagedVulkan
{
	public ref class CommandBufferBeginInfo
	{
	private:
		ManagedVulkan::StructureType mSType;
		UInt32 mFlags;
		ManagedVulkan::CommandBufferInheritanceInfo^ mInheritanceInfo = nullptr;
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
			dst->sType = (VkStructureType)mSType;
			dst->pNext = nullptr;
			dst->flags = mFlags;
			//mInheritanceInfo->CopyTo(&dst->pInheritanceInfo, pins);
		}

		void CopyFrom(VkCommandBufferBeginInfo* src)
		{
			mSType = (ManagedVulkan::StructureType) src->sType;

			mFlags = src->flags;
			//mInheritanceInfo->CopyFrom(src->pInheritanceInfo);
		}
	};
}