#pragma once

#include <vulkan\vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
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
}
