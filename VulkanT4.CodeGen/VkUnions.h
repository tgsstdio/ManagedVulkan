// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan 
{
	// UNIONS
	public union ClearColorValue
	{
	public:
		float32 m4;
		int32 m4;
		uint32 m4;
	};

	public union ClearValue
	{
	public:
		ClearColorValue^ mColor;
		ClearDepthStencilValue^ mDepthStencil;
	};

}