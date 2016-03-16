# Managed Vulkan

*17 March 2016*

## NOTE : most likely a leaky messy Vulkan prototype library for C# applications

My own managed C++ / CLI interface for Vulkan (on my Windows machines compiled with Visual Studio 2015 Community Edition) generated from VulkanSharp's VK_XML_URL = https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/1.0/src/spec/vk.xml

# Version 2.0.0
 - Using Windows LunarG 1.0.5 Vulkan SDK implementation
 - BREAKING CHANGES to ManagedVulkan classes & functions
 - Added utility function ManagedVulkan.Vulkan.MakeVersion
 - Using run-time lookups (e.g. GetInstanceProcAddr, GetDeviceProcAddr) to fill out missing implementations of 
   - vkGetPhysicalDeviceDisplayPropertiesKHR
   - vkGetPhysicalDeviceDisplayPlanePropertiesKHR
   - vkGetDisplayPlaneSupportedDisplaysKHR
   - vkGetDisplayModePropertiesKHR
   - vkCreateDisplayModeKHR
   - vkGetDisplayPlaneCapabilitiesKHR
   - vkCreateSharedSwapchainsKHR
 - C# translation of cube.c from Windows LunarG 1.0.5 Vulkan SDK
 
## Implementation
  - Enums 
	- All enums - **Done**
	- Remove common prefixes  *TODO*
 - Delegates -  **Done**
 - Unions - **Done**
 - Bitmasks
	-  All Bitmasks - **Done**
	-  Remove common prefixes  *TODO*
 - Helper Structs (really classes) for managed types - **DONE**
 - Header file for Windows only windowing functions - **DONE**
 - Group class (proxies) for similar instances - **DONE**
 - External synchronization ?? *TODO*

# Version 1.1.0
 - Using Windows LunarG 1.0.3.1 Vulkan SDK implementation
 - All functions are implemented except for GetDeviceProcAddr(String pName) & AllocationCallbacks

# Version 1.0.0

 - Now using Semantic Versioning v2.0.0 (http://semver.org/)
 - Code based on Vulkan T4 codegen; Heavily hand modified.

# Version 0.0.1


### Project: ManagedVulkan

Prototype C++ / CLI library using LunarG's vulkan-1.lib provided in the Windows version of the Developer SDK with only two methods implemented
 - VkCreateInstance
 - VkEnumerateInstanceExtensionProperties

### Project : VulkanT4

T4 text templating to generate C++ / CLI interfaces using managed types 

#### Code generation 
 - Enums 
	- All enums - **Done**
	- Remove common prefixes  *TODO*
 - Delegates -  **Done**
 - Unions - *TODO*
 - Bitmasks
	-  All Bitmasks - **Done**
	-  Remove common prefixes  *TODO*
 - Helper Structs (really classes) for managed types - **DONE**
 - Header file for Windows only windowing functions - **DONE**
 - Group class (proxies) for similar instances - **DONE**
 - External synchronization ?? *TODO*
 

### Todos
 - Full C# managed type implementation for all 190+ functions via T4 code generation 

## License
MIT 2016 David Young