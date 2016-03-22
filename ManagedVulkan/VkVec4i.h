#pragma once

using namespace System;

namespace ManagedVulkan
{
	public ref class Vec4i
	{
	private:
		Int32 mX;
		Int32 mY;
		Int32 mZ;
		Int32 mW;
	internal:
		void CopyTo(Int32* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
			dst[2] = mZ;
		}

		void CopyFrom(Int32* src)
		{
			mX = src[0];
			mY = src[1];
			mZ = src[2];
		}
	public:
		Vec4i() : Vec4i(0,0,0,0)
		{

		}

		Vec4i(Int32 x, Int32 y, Int32 z, Int32 w)
		{
			mX = x;
			mY = y;
			mZ = z;
			mW = w;
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

		property Int32 W
		{
			Int32 get()
			{
				return mW;
			}
			void set(Int32 value)
			{
				mW = value;
			}
		}
	};
}