#pragma once

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan {

	[FlagsAttribute] public enum class VkMemoryPropertyFlagBits : int
	{
		VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 1 << 0, // If otherwise stated, then allocate memory on device
		VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 1 << 1, // Memory is mappable by host
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 1 << 2, // Memory will have i/o coherency. If not set, application may need to use vkFlushMappedMemoryRanges and vkInvalidateMappedMemoryRanges to flush/invalidate host cache
		VK_MEMORY_PROPERTY_HOST_CACHED_BIT = 1 << 3, // Memory will be cached by the host
		VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT = 1 << 4, // Memory may be allocated by the driver when it is required
	};
}