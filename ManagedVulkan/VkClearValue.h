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
