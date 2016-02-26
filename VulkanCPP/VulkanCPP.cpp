// VulkanCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vulkan\vulkan.h>
#include <assert.h>
#include <iostream>

int main()
{

	uint32_t instance_extension_count = 0;
	auto err = vkEnumerateInstanceExtensionProperties(
		NULL, &instance_extension_count, NULL);

	VkExtensionProperties* instance_extensions = new VkExtensionProperties[ instance_extension_count];
	err = vkEnumerateInstanceExtensionProperties(
		NULL, &instance_extension_count, instance_extensions);
	assert(!err);

	std::cout << "inst_count" << instance_extension_count << std::endl;

    return 0;
}

