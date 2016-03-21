// ManagedVulkan.h

#pragma once

#include "VkEnums.h"

using namespace System;

namespace ManagedVulkan
{
	// DELEGATES
	public delegate void vkInternalAllocationNotification(IntPtr pUserData, UIntPtr size, ManagedVulkan::InternalAllocationType allocationType, ManagedVulkan::SystemAllocationScope allocationScope);

	public delegate void vkInternalFreeNotification(IntPtr pUserData, UIntPtr size, ManagedVulkan::InternalAllocationType allocationType, ManagedVulkan::SystemAllocationScope allocationScope);

	public delegate void vkReallocationFunction(IntPtr pUserData, IntPtr pOriginal, UIntPtr size, UIntPtr alignment, ManagedVulkan::SystemAllocationScope allocationScope);

	public delegate void vkAllocationFunction(IntPtr pUserData, UIntPtr size, UIntPtr alignment, ManagedVulkan::SystemAllocationScope allocationScope);

	public delegate void vkFreeFunction(IntPtr pUserData, IntPtr pMemory);

	public delegate void vkVoidFunction();

	public delegate bool vkDebugReportCallbackEXT(ManagedVulkan::DebugReportFlagBitsEXT flags, ManagedVulkan::DebugReportObjectTypeEXT objectType, UInt64 object, UIntPtr location, Int32 messageCode, String^ pLayerPrefix, String^ pMessage, IntPtr pUserData);

}