#pragma once

#include <vulkan/vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class Offset3D
	{
	private:
		Int32 mX;
		Int32 mY;
		Int32 mZ;
	public:
		Offset3D() : Offset3D(0, 0, 0)
		{

		}

		Offset3D(Int32 x, Int32 y, Int32 z)
		{
			mX = x;
			mY = y;
			mZ = z;
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