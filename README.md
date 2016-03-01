# Managed Vulkan

*2 March 2016*

## NOTE : most likely a leaky messy Vulkan prototype library for C# applications

My own managed C++ / CLI interface for Vulkan (on my Windows machines compiled with Visual Studio 2015 Community Edition) generated from VulkanSharp's VK_XML_URL = https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/1.0/src/spec/vk.xml

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
 

### Todos
 - Full C# managed type implementation for all 190+ functions via T4 code generation 

## License
MIT 2016 David Young