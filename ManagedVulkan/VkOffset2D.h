#pragma once

#include <vulkan\vulkan.h>

using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class Offset2D
	{
	private:
		Int32 mX;
		Int32 mY;
	public:
		Offset2D() : Offset2D(0, 0)
		{
				
		}

		Offset2D(Int32 x, Int32 y)
		{
			mX = x;
			mY = y;
		}

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