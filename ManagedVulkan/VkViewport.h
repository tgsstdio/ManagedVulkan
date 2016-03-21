#pragma once

#include <vulkan\vulkan.h>

using namespace System::Collections::Generic;

namespace ManagedVulkan
{

	public ref class Viewport
	{
	private:
		float mX;
		float mY;
		float mWidth;
		float mHeight;
		float mMinDepth;
		float mMaxDepth;
	public:
		Viewport() : Viewport(0, 0, 0, 0, 0, 0)
		{

		}

		Viewport(float x, float y, float width, float height, float minDepth, float maxDepth)
		{
			mX = x;
			mY = y;
			mWidth = width;
			mHeight = height;
			mMinDepth = minDepth;
			mMaxDepth = maxDepth;
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
		property float Width
		{
			float get()
			{
				return mWidth;
			}
			void set(float value)
			{
				mWidth = value;
			}
		}
		property float Height
		{
			float get()
			{
				return mHeight;
			}
			void set(float value)
			{
				mHeight = value;
			}
		}
		property float MinDepth
		{
			float get()
			{
				return mMinDepth;
			}
			void set(float value)
			{
				mMinDepth = value;
			}
		}
		property float MaxDepth
		{
			float get()
			{
				return mMaxDepth;
			}
			void set(float value)
			{
				mMaxDepth = value;
			}
		}
	internal:
		void CopyTo(VkViewport* dst, List<IntPtr>^ pins)
		{
			dst->x = mX;
			dst->y = mY;
			dst->width = mWidth;
			dst->height = mHeight;
			dst->minDepth = mMinDepth;
			dst->maxDepth = mMaxDepth;
		}

		void CopyFrom(VkViewport* src)
		{
			mX = src->x;
			mY = src->y;
			mWidth = src->width;
			mHeight = src->height;
			mMinDepth = src->minDepth;
			mMaxDepth = src->maxDepth;
		}
	};
}