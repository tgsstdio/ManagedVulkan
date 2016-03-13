#pragma once

#include <vulkan\vulkan.h>

using namespace System::Collections::Generic;

namespace ManagedVulkan
{
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

}