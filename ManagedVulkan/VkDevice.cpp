#include "stdafx.h"
#include "VkDevice.h"

#ifdef VK_DEBUG_REPORT
ManagedVulkan::PFN_vkVoidFunction^ ManagedVulkan::Device::GetDeviceProcAddr(String^ pName)
{
	throw gcnew NotImplementedException();

	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pName		
		IntPtr inst_1 = Marshal::StringToHGlobalAnsi(pName);
		pins->Add(inst_1);
		char* arg_1 = static_cast<char*>(inst_1.ToPointer());;

		int result = vkGetDeviceProcAddr(arg_0, arg_1);



		return (PFN_vkVoidFunction)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}
#endif

void ManagedVulkan::Device::DestroyDevice(ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pAllocator		
		VkAllocationCallbacks inst_1;
		VkAllocationCallbacks* arg_1 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_1 = &inst_1;
			pAllocator->CopyTo(arg_1, pins);
		}

		vkDestroyDevice(arg_0, arg_1);

	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetDeviceQueue(UInt32 queueFamilyIndex, UInt32 queueIndex, [Out] ManagedVulkan::Queue^% pQueue)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - queueFamilyIndex		
		uint32_t arg_1 = queueFamilyIndex;
		// INITS 2 - queueIndex		
		uint32_t arg_2 = queueIndex;
		// INITS 3 - pQueue		
		VkQueue inst_3;
		VkQueue* arg_3 = &inst_3;

		vkGetDeviceQueue(arg_0, arg_1, arg_2, arg_3);

		pQueue = gcnew Queue();
		pQueue->mHandle = inst_3;

	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::DeviceWaitIdle()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;

		auto result = vkDeviceWaitIdle(arg_0);

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::AllocateMemory(ManagedVulkan::MemoryAllocateInfo^ pAllocateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator,[Out] ManagedVulkan::DeviceMemory^% pMemory)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pAllocateInfo		
		VkMemoryAllocateInfo inst_1;
		VkMemoryAllocateInfo* arg_1 = nullptr;
		if (pAllocateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pAllocateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pMemory
		VkDeviceMemory inst_3;
		VkDeviceMemory* arg_3 = &inst_3;

		auto result = vkAllocateMemory(arg_0, arg_1, arg_2, arg_3);

		pMemory = gcnew ManagedVulkan::DeviceMemory();
		pMemory->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::FreeMemory(ManagedVulkan::DeviceMemory^ memory, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkFreeMemory(arg_0, arg_1, arg_2);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::MapMemory(ManagedVulkan::DeviceMemory^ memory, UInt64 offset, UInt64 size, UInt32 flags,[Out] IntPtr^% ppData)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;
		// INITS 3 - size		
		VkDeviceSize arg_3 = size;
		// INITS 4 - flags		
		VkMemoryMapFlags arg_4 = flags;
		// INITS 5 - ppData		
		void* inst_5;
		void** arg_5 = &inst_5;

		auto result = vkMapMemory(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		ppData = gcnew IntPtr(inst_5);

		return (Result)result;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::UnmapMemory(ManagedVulkan::DeviceMemory^ memory)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;

		vkUnmapMemory(arg_0, arg_1);


	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::FlushMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkMappedMemoryRange* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		
		// INITS 1 - memoryRangeCount
		uint32_t arg_1 = 0;
		if (pMemoryRanges != nullptr)
		{
			arg_1 = pMemoryRanges->Length;

			// INITS 2 - pMemoryRanges		
			arg_2 = new VkMappedMemoryRange[arg_1];
			for (uint32_t i = 0; i < arg_1; ++i)
			{
				ManagedVulkan::MappedMemoryRange^ src = (ManagedVulkan::MappedMemoryRange^) pMemoryRanges[i];
				VkMappedMemoryRange* dest = arg_2 + i;
				src->CopyTo(dest, pins);
			}
		}

		auto result = vkFlushMappedMemoryRanges(arg_0, arg_1, arg_2);

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::InvalidateMappedMemoryRanges(array<ManagedVulkan::MappedMemoryRange^>^ pMemoryRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkMappedMemoryRange* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - memoryRangeCount		
		uint32_t arg_1 = 0;

		if (pMemoryRanges != nullptr)
		{
			arg_1 = pMemoryRanges->Length;

			// INITS 2 - pMemoryRanges		
			arg_2 = new VkMappedMemoryRange[arg_1];
			for (uint32_t i = 0; i < arg_1; ++i)
			{
				ManagedVulkan::MappedMemoryRange^ src = (ManagedVulkan::MappedMemoryRange^) pMemoryRanges[i];
				VkMappedMemoryRange* dest = arg_2 + i;
				src->CopyTo(dest, pins);
			}
		}

		// INITS 2 - pMemoryRanges		
		arg_2 = new VkMappedMemoryRange[arg_1];

		auto result = vkInvalidateMappedMemoryRanges(arg_0, arg_1, arg_2);

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::GetDeviceMemoryCommitment(ManagedVulkan::DeviceMemory^ memory,[Out] UInt64^% pCommittedMemoryInBytes)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - memory		
		VkDeviceMemory arg_1 = memory->mHandle;
		// INITS 2 - pCommittedMemoryInBytes		
		UInt64 inst_2;
		VkDeviceSize* arg_2 = &inst_2;

		vkGetDeviceMemoryCommitment(arg_0, arg_1, arg_2);

		pCommittedMemoryInBytes = inst_2;
	}
	finally
	{
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}