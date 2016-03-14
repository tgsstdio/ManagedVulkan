#pragma once

#include <vulkan/vulkan.h>
#include "VkClearValue.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class ClearAttachment
	{
	private:
		UInt32 mAspectMask;
		UInt32 mColorAttachment = 0;
		ManagedVulkan::ClearValue^ mClearValue = nullptr;
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
			dst->aspectMask = mAspectMask;
			dst->colorAttachment = mColorAttachment;
			if (mClearValue != nullptr)
			{
				mClearValue->CopyTo(&dst->clearValue);
			}
		}
	};

}