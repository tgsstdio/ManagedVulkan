#pragma once

#include <vulkan/vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class Offset3D
	{
	private:
		Int32 mX = 0;
		Int32 mY = 0;
		Int32 mZ = 0;
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
		property Int32 Z
		{
			Int32 get()
			{
				return mZ;
			}
			void set(Int32 value)
			{
				mZ = value;
			}
		}
	internal:
		void CopyTo(VkOffset3D* dst, List<IntPtr>^ pins)
		{
			dst->x = mX;
			dst->y = mY;
			dst->z = mZ;
		}

		void CopyFrom(VkOffset3D* src)
		{
			mX = src->x;
			mY = src->y;
			mZ = src->z;
		}
	};
}