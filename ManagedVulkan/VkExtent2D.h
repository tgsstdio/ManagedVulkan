#pragma once

#include <vulkan\vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
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
}