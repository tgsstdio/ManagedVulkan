// ManagedVulkan.h

#pragma once

#include <vulkan\vulkan.h>

using namespace System;

namespace ManagedVulkan
{
	// DELEGATES
	public delegate void PFN_vkInternalAllocationNotification(IntPtr pUserData, IntPtr size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkInternalFreeNotification(IntPtr pUserData, IntPtr size, VkInternalAllocationType allocationType, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkReallocationFunction(IntPtr pUserData, IntPtr pOriginal, IntPtr size, IntPtr alignment, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkAllocationFunction(IntPtr pUserData, IntPtr size, IntPtr alignment, VkSystemAllocationScope allocationScope);

	public delegate void PFN_vkFreeFunction(IntPtr pUserData, IntPtr pMemory);

	public delegate void PFN_vkVoidFunction();

	public delegate void PFN_vkDebugReportCallbackEXT(VkDebugReportFlagsEXT flags, DebugReportObjectTypeEXT objectType, UInt64 object, IntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage, IntPtr pUserData);

}