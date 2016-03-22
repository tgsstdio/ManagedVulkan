#pragma once

#pragma once

#include <vulkan/vulkan.h>
#include "VkClearColorValue.h"
#include "VkClearDepthStencilValue.h"

using namespace System;

namespace ManagedVulkan
{
	public ref class ClearValue
	{
	private:
		ManagedVulkan::ClearColorValue^ mColor = nullptr;
		ManagedVulkan::ClearDepthStencilValue^ mDepthStencil = nullptr;
	public:
		property ClearColorValue^ Color 
		{
			ClearColorValue^ get()
			{
				return mColor;
			}
			void set(ClearColorValue^ value)
			{
				mColor = value;
			}
		}

		property ClearDepthStencilValue^ DepthStencil
		{
			ClearDepthStencilValue^ get()
			{
				return mDepthStencil;
			}
			void set(ClearDepthStencilValue^ value)
			{
				mDepthStencil = value;
			}
		}

	internal:
		void CopyTo(VkClearValue* dst)
		{
			if (mColor != nullptr)
			{
				mColor->CopyTo(&dst->color);
			}
			else if (mDepthStencil != nullptr)
			{
				mDepthStencil->CopyTo(&dst->depthStencil);
			}
		}
	};
}
