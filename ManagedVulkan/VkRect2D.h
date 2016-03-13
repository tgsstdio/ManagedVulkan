#pragma once

#include <vulkan\vulkan.h>
#include "VkOffset2D.h"
#include "VkExtent2D.h"

using namespace System::Collections::Generic;

namespace ManagedVulkan
{

	public ref class Rect2D
	{
	private:
		Offset2D^ mOffset = gcnew Offset2D();
		Extent2D^ mExtent = gcnew Extent2D();
	public:
		property ManagedVulkan::Offset2D^ Offset
		{
			ManagedVulkan::Offset2D^ get()
			{
				return mOffset;
			}
			void set(ManagedVulkan::Offset2D^ value)
			{
				mOffset = value;
			}
		}
		property ManagedVulkan::Extent2D^ Extent
		{
			ManagedVulkan::Extent2D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent2D^ value)
			{
				mExtent = value;
			}
		}
	internal:
		void CopyTo(VkRect2D* dst, List<IntPtr>^ pins)
		{
			mOffset->CopyTo(&dst->offset, pins);
			mExtent->CopyTo(&dst->extent, pins);
		}

		void CopyFrom(VkRect2D* src)
		{
			mOffset->CopyFrom(&src->offset);
			mExtent->CopyFrom(&src->extent);
		}
	};

}
