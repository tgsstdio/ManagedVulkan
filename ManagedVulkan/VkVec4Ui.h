#pragma once

using namespace System;

namespace ManagedVulkan
{

	public ref class Vec4Ui
	{
	private:
		UInt32 mX;
		UInt32 mY;
		UInt32 mZ;
		UInt32 mW;
	internal:
		void CopyTo(UInt32* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
			dst[2] = mZ;
		}

		void CopyFrom(UInt32* src)
		{
			mX = src[0];
			mY = src[1];
			mZ = src[2];
		}
	public:
		Vec4Ui() : Vec4Ui(0,0,0,0)
		{

		}

		Vec4Ui(UInt32 x, UInt32 y, UInt32 z, UInt32 w)
		{
			mX = x;
			mY = y;
			mZ = z;
			mW = w;
		}

		property UInt32 X
		{
			UInt32 get()
			{
				return mX;
			}
			void set(UInt32 value)
			{
				mX = value;
			}
		}

		property UInt32 Y
		{
			UInt32 get()
			{
				return mY;
			}
			void set(UInt32 value)
			{
				mY = value;
			}
		}

		property UInt32 Z
		{
			UInt32 get()
			{
				return mZ;
			}
			void set(UInt32 value)
			{
				mZ = value;
			}
		}

		property UInt32 W
		{
			UInt32 get()
			{
				return mW;
			}
			void set(UInt32 value)
			{
				mW = value;
			}
		}
	};
}