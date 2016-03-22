#pragma once

namespace ManagedVulkan
{
	public ref class Vec4f
	{
	private:
		float mX;
		float mY;
		float mZ;
		float mW;
	internal:
		void CopyTo(float* dst)
		{
			dst[0] = mX;
			dst[1] = mY;
			dst[2] = mZ;
			dst[3] = mW;
		}

		void CopyFrom(float* src)
		{
			mX = src[0];
			mY = src[1];
			mZ = src[2];
			mW = src[3];
		}
	public:
		Vec4f() : Vec4f(0.0, 0.0, 0.0, 0.0)
		{
			
		}

		Vec4f(float x, float y, float z, float w)
		{
			mX = x;
			mY = y;
			mZ = z;
			mW = w;
		}

		property float X
		{
			float get()
			{
				return mX;
			}
			void set(float value)
			{
				mX = value;
			}
		}

		property float Y
		{
			float get()
			{
				return mY;
			}
			void set(float value)
			{
				mY = value;
			}
		}

		property float Z
		{
			float get()
			{
				return mZ;
			}
			void set(float value)
			{
				mZ = value;
			}
		}

		property float W
		{
			float get()
			{
				return mW;
			}
			void set(float value)
			{
				mW = value;
			}
		}
	};
}