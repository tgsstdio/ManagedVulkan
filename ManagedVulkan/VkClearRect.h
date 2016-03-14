#pragma once

#include <vulkan/vulkan.h>
#include "VkRect2D.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{

	public ref class ClearRect
	{
	private:
		ManagedVulkan::Rect2D^ mRect = gcnew ManagedVulkan::Rect2D();
		UInt32 mBaseArrayLayer = 0;
		UInt32 mLayerCount = 0;
	public:
		property ManagedVulkan::Rect2D^ Rect
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mRect;
			}
			void set(ManagedVulkan::Rect2D^ value)
			{
				mRect = value;
			}
		}
		property UInt32 BaseArrayLayer
		{
			UInt32 get()
			{
				return mBaseArrayLayer;
			}
			void set(UInt32 value)
			{
				mBaseArrayLayer = value;
			}
		}
		property UInt32 LayerCount
		{
			UInt32 get()
			{
				return mLayerCount;
			}
			void set(UInt32 value)
			{
				mLayerCount = value;
			}
		}
	internal:
		void CopyTo(VkClearRect* dst, List<IntPtr>^ pins)
		{
			mRect->CopyTo(&dst->rect, pins);
			dst->baseArrayLayer = mBaseArrayLayer;
			dst->layerCount = mLayerCount;
		}

		void CopyFrom(VkClearRect* src)
		{
			mRect->CopyFrom(&src->rect);
			mBaseArrayLayer = src->baseArrayLayer;
			mLayerCount = src->layerCount;
		}
	};
}
