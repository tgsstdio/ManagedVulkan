// ManagedVulkan.Windows.h

#pragma once

using namespace System;

namespace ManagedVulkan {



	public ref class Win32WindowInstance
	{
		ManagedVulkan::VkResult CreateWin32SurfaceKHR(ManagedVulkan::Instance^instance, ManagedVulkan::Win32SurfaceCreateInfoKHR^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::SurfaceKHR^% pSurface);
	};
}
