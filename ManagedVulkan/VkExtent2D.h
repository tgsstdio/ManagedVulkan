#pragma once

#include <vulkan\vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class Extent2D
	{
	private:
		UInt32 mWidth;
		UInt32 mHeight;
	public:
		Extent2D() : Extent2D(0, 0)
		{
			
		}

		Extent2D(UInt32 width, UInt32 height)
		{
			mWidth = width;
			mHeight = height;
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