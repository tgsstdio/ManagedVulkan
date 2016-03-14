#pragma once

#include <vulkan/vulkan.h>

using namespace System;

namespace ManagedVulkan
{
	public ref class ClearDepthStencilValue
	{
	private:
		float mDepth = 0;
		UInt32 mStencil = 0;
	public:
		property float Depth
		{
			float get()
			{
				return mDepth;
			}
			void set(float value)
			{
				mDepth = value;
			}
		}

		property UInt32 Stencil
		{
			UInt32 get()
			{
				return mStencil;
			}
			void set(UInt32 value)
			{
				mStencil = value;
			}
		}
	internal:
		void CopyTo(VkClearDepthStencilValue* dest)
		{
			dest->depth = mDepth;
			dest->stencil = mStencil;
		}
	};
}