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

void ManagedVulkan::Device::GetBufferMemoryRequirements(ManagedVulkan::Buffer^ buffer, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - pMemoryRequirements		
		VkMemoryRequirements inst_2;
		VkMemoryRequirements* arg_2 = &inst_2;

		vkGetBufferMemoryRequirements(arg_0, arg_1, arg_2);

		pMemoryRequirements = gcnew MemoryRequirements();
		pMemoryRequirements->CopyFrom(arg_2);
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

ManagedVulkan::Result ManagedVulkan::Device::BindBufferMemory(ManagedVulkan::Buffer^ buffer, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - memory		
		VkDeviceMemory arg_2 = memory->mHandle;
		// INITS 3 - memoryOffset		
		VkDeviceSize arg_3 = memoryOffset;

		auto result = vkBindBufferMemory(arg_0, arg_1, arg_2, arg_3);

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

void ManagedVulkan::Device::GetImageMemoryRequirements(ManagedVulkan::Image^ image, [Out] ManagedVulkan::MemoryRequirements^% pMemoryRequirements)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;
		// INITS 2 - pMemoryRequirements		
		VkMemoryRequirements inst_2;
		VkMemoryRequirements* arg_2 = &inst_2;

		vkGetImageMemoryRequirements(arg_0, arg_1, arg_2);

		pMemoryRequirements = gcnew MemoryRequirements();
		pMemoryRequirements->CopyFrom(arg_2);

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

ManagedVulkan::Result ManagedVulkan::Device::BindImageMemory(ManagedVulkan::Image^ image, ManagedVulkan::DeviceMemory^ memory, UInt64 memoryOffset)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;
		// INITS 2 - memory		
		VkDeviceMemory arg_2 = memory->mHandle;
		// INITS 3 - memoryOffset		
		VkDeviceSize arg_3 = memoryOffset;

		auto result = vkBindImageMemory(arg_0, arg_1, arg_2, arg_3);

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

void ManagedVulkan::Device::GetImageSparseMemoryRequirements(ManagedVulkan::Image^ image, [Out] array<ManagedVulkan::SparseImageMemoryRequirements^>^% pSparseMemoryRequirements)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSparseImageMemoryRequirements* arg_3 = nullptr;
	try
	{

		// 1ST CALL		
		// 0 - device		
		VkDevice arg_0 = this->mHandle;
		// 1 - image		
		VkImage arg_1 = image->mHandle;
		// 2 - pSparseMemoryRequirementCount		
		UInt32 pSparseMemoryRequirementCount = 0;
		UInt32* arg_2 = &pSparseMemoryRequirementCount;

		vkGetImageSparseMemoryRequirements(arg_0, arg_1, arg_2, nullptr);
		// MAIN INIT

		// INITS 3 - pSparseMemoryRequirements		
		arg_3 = new VkSparseImageMemoryRequirements[pSparseMemoryRequirementCount];

		vkGetImageSparseMemoryRequirements(arg_0, arg_1, arg_2, arg_3);

		int count = (int)pSparseMemoryRequirementCount;
		pSparseMemoryRequirements = gcnew array<SparseImageMemoryRequirements^>(count);
		for (int i = 0; i < count; ++i)
		{
			pSparseMemoryRequirements[i] = gcnew SparseImageMemoryRequirements();
			pSparseMemoryRequirements[i]->CopyFrom(arg_3 + i);
		}


	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::CreateFence(ManagedVulkan::FenceCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Fence^% pFence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkFenceCreateInfo inst_1;
		VkFenceCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pFence		
		VkFence inst_3;
		VkFence* arg_3 = &inst_3;

		auto result = vkCreateFence(arg_0, arg_1, arg_2, arg_3);

		pFence = gcnew Fence();
		pFence->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroyFence(ManagedVulkan::Fence^ fence, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - fence		
		VkFence arg_1 = fence->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyFence(arg_0, arg_1, arg_2);
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

ManagedVulkan::Result ManagedVulkan::Device::ResetFences(array<ManagedVulkan::Fence^>^ pFences)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkFence* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - fenceCount		
		uint32_t arg_1 = 0;
		if (pFences != nullptr)
		{
			arg_1 = pFences->Length;

			// INITS 2 - pFences		
			arg_2 = new VkFence[arg_1];
			for (uint32_t i = 0; i < arg_1; ++i)
			{
				ManagedVulkan::Fence^ src = pFences[i];
				//TODO : null check for array members
				arg_2[i] = src->mHandle;
			}
		}

		auto result = vkResetFences(arg_0, arg_1, arg_2);

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

ManagedVulkan::Result ManagedVulkan::Device::GetFenceStatus(ManagedVulkan::Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - fence		
		VkFence arg_1 = fence->mHandle;

		auto result = vkGetFenceStatus(arg_0, arg_1);

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

ManagedVulkan::Result ManagedVulkan::Device::WaitForFences(array<ManagedVulkan::Fence^>^ pFences, bool waitAll, UInt64 timeout)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkFence* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;

		// INITS 1 - fenceCount		
		uint32_t arg_1 = 0;
		if (pFences != nullptr)
		{
			arg_1 = pFences->Length;

			// INITS 2 - pFences		
			arg_2 = new VkFence[arg_1];
			for (uint32_t i = 0; i < arg_1; ++i)
			{
				ManagedVulkan::Fence^ src = pFences[i];
				//TODO : null check for array members
				arg_2[i] = src->mHandle;
			}
		}

		// INITS 3 - waitAll		
		VkBool32 arg_3 = waitAll;
		// INITS 4 - timeout		
		uint64_t arg_4 = timeout;

		auto result = vkWaitForFences(arg_0, arg_1, arg_2, arg_3, arg_4);

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

ManagedVulkan::Result ManagedVulkan::Device::CreateSemaphore(ManagedVulkan::SemaphoreCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Semaphore^% pSemaphore)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkSemaphoreCreateInfo inst_1;
		VkSemaphoreCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pSemaphore		
		VkSemaphore inst_3;
		VkSemaphore* arg_3 = &inst_3;

		auto result = vkCreateSemaphore(arg_0, arg_1, arg_2, arg_3);

		pSemaphore = gcnew Semaphore();
		pSemaphore->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroySemaphore(ManagedVulkan::Semaphore^ semaphore, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - semaphore		
		VkSemaphore arg_1 = semaphore->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroySemaphore(arg_0, arg_1, arg_2);


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

ManagedVulkan::Result ManagedVulkan::Device::CreateEvent(ManagedVulkan::EventCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Event^% pEvent)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkEventCreateInfo inst_1;
		VkEventCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pEvent		
		VkEvent inst_3;
		VkEvent* arg_3 = &inst_3;

		auto result = vkCreateEvent(arg_0, arg_1, arg_2, arg_3);

		pEvent = gcnew Event();
		pEvent->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroyEvent(ManagedVulkan::Event^ event, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyEvent(arg_0, arg_1, arg_2);


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

ManagedVulkan::Result ManagedVulkan::Device::GetEventStatus(ManagedVulkan::Event^ event)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;

		auto result = vkGetEventStatus(arg_0, arg_1);

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

ManagedVulkan::Result ManagedVulkan::Device::SetEvent(ManagedVulkan::Event^ event)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;

		auto result = vkSetEvent(arg_0, arg_1);

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

ManagedVulkan::Result ManagedVulkan::Device::ResetEvent(ManagedVulkan::Event^ event)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;

		auto result = vkResetEvent(arg_0, arg_1);

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

ManagedVulkan::Result ManagedVulkan::Device::CreateQueryPool(ManagedVulkan::QueryPoolCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::QueryPool^% pQueryPool)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkQueryPoolCreateInfo inst_1;
		VkQueryPoolCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		// INITS 3 - pQueryPool		
		VkQueryPool inst_3;
		VkQueryPool* arg_3 = &inst_3;

		auto result = vkCreateQueryPool(arg_0, arg_1, arg_2, arg_3);

		pQueryPool = gcnew QueryPool();
		pQueryPool->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroyQueryPool(ManagedVulkan::QueryPool^ queryPool, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyQueryPool(arg_0, arg_1, arg_2);


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


ManagedVulkan::Result ManagedVulkan::Device::GetQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, size_t dataSize, IntPtr pData, UInt64 stride, UInt32 flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;
		// INITS 2 - firstQuery		
		uint32_t arg_2 = firstQuery;
		// INITS 3 - queryCount		
		uint32_t arg_3 = queryCount;
		// INITS 4 - dataSize		
		size_t arg_4 = (size_t)dataSize;
		// INITS 5 - pData		
		void* arg_5 = 0;
		// INITS 6 - stride		
		VkDeviceSize arg_6 = stride;
		// INITS 7 - flags		
		VkQueryResultFlags arg_7 = flags;

		auto result = vkGetQueryPoolResults(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);

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

ManagedVulkan::Result ManagedVulkan::Device::CreateBuffer(ManagedVulkan::BufferCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Buffer^% pBuffer)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	UInt32* arg_1_0 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkBufferCreateInfo inst_1;
		VkBufferCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
			
			if (pCreateInfo->QueueFamilyIndices != nullptr)
			{
				UInt32 count = pCreateInfo->QueueFamilyIndices->Length;
				if (count > 0)
				{
					arg_1_0 = new UInt32[count];
					for (UInt32 i = 0; i < count; ++i)
					{
						arg_1_0[i] = (UInt32)pCreateInfo->QueueFamilyIndices[i];
					}
				}
				arg_1->queueFamilyIndexCount = count;
				arg_1->pQueueFamilyIndices = arg_1_0;
			}			
			else
			{
				arg_1->queueFamilyIndexCount = 0;
				arg_1->pQueueFamilyIndices = nullptr;
			}

		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pBuffer		
		VkBuffer inst_3;
		VkBuffer* arg_3 = &inst_3;

		auto result = vkCreateBuffer(arg_0, arg_1, arg_2, arg_3);

		pBuffer = gcnew Buffer();
		pBuffer->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		if (arg_1_0 != nullptr)
		{
			delete[] arg_1_0;
		}

		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyBuffer(ManagedVulkan::Buffer^ buffer, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyBuffer(arg_0, arg_1, arg_2);


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

ManagedVulkan::Result ManagedVulkan::Device::CreateBufferView(ManagedVulkan::BufferViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::BufferView^% pView)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkBufferViewCreateInfo inst_1;
		VkBufferViewCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pView		
		VkBufferView inst_3;
		VkBufferView* arg_3 = &inst_3;

		auto result = vkCreateBufferView(arg_0, arg_1, arg_2, arg_3);

		pView = gcnew BufferView();
		pView->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroyBufferView(ManagedVulkan::BufferView^ bufferView, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - bufferView		
		VkBufferView arg_1 = bufferView->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyBufferView(arg_0, arg_1, arg_2);


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

ManagedVulkan::Result ManagedVulkan::Device::CreateImage(ManagedVulkan::ImageCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::Image^% pImage)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	UInt32* arg_1_0 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkImageCreateInfo inst_1;
		VkImageCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);

			if (pCreateInfo->QueueFamilyIndices != nullptr)
			{
				UInt32 count = pCreateInfo->QueueFamilyIndices->Length;
				arg_1->queueFamilyIndexCount = count;
				if (count > 0)
				{
					arg_1_0 = new UInt32[count];
					for (UInt32 i = 0; i < count; ++i)
					{
						arg_1_0[i] = (UInt32) pCreateInfo->QueueFamilyIndices[i];
					}
				}
				arg_1->pQueueFamilyIndices = arg_1_0;
			}
			else
			{
				arg_1->queueFamilyIndexCount = 0;
				arg_1->pQueueFamilyIndices = nullptr;
			}

		}

		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		// INITS 3 - pImage		
		VkImage inst_3;
		VkImage* arg_3 = &inst_3;

		auto result = vkCreateImage(arg_0, arg_1, arg_2, arg_3);

		pImage = gcnew Image();
		pImage->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		if (arg_1_0 != nullptr)
		{
			delete[] arg_1_0;
		}

		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


void ManagedVulkan::Device::DestroyImage(ManagedVulkan::Image^ image, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyImage(arg_0, arg_1, arg_2);


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

void ManagedVulkan::Device::GetImageSubresourceLayout(ManagedVulkan::Image^ image, ManagedVulkan::ImageSubresource^ pSubresource, [Out] ManagedVulkan::SubresourceLayout^% pLayout)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;
		// INITS 2 - pSubresource		
		VkImageSubresource inst_2;
		VkImageSubresource* arg_2 = nullptr;
		if (pSubresource != nullptr)
		{
			arg_2 = &inst_2;
			pSubresource->CopyTo(arg_2, pins);
		}
		// INITS 3 - pLayout		
		VkSubresourceLayout inst_3;
		VkSubresourceLayout* arg_3 = &inst_3;

		vkGetImageSubresourceLayout(arg_0, arg_1, arg_2, arg_3);

		pLayout = gcnew ManagedVulkan::SubresourceLayout();
		pLayout->CopyFrom(arg_3);


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

ManagedVulkan::Result ManagedVulkan::Device::CreateImageView(ManagedVulkan::ImageViewCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ImageView^% pView)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkImageViewCreateInfo inst_1;
		VkImageViewCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}

		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pView		
		VkImageView inst_3;
		VkImageView* arg_3 = &inst_3;

		auto result = vkCreateImageView(arg_0, arg_1, arg_2, arg_3);

		pView = gcnew ImageView();
		pView->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroyImageView(ManagedVulkan::ImageView^ imageView, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - imageView		
		VkImageView arg_1 = imageView->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyImageView(arg_0, arg_1, arg_2);
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

ManagedVulkan::Result ManagedVulkan::Device::CreateShaderModule(ManagedVulkan::ShaderModuleCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::ShaderModule^% pShaderModule)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	UInt32* arg_1_0 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkShaderModuleCreateInfo inst_1;
		VkShaderModuleCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);

			//TODO : copy SPIRV UInt32 array
			// TODO : array check / multiple of 4
			
			if (pCreateInfo->Code != nullptr)
			{
				UInt32 count = pCreateInfo->Code->Length;
				arg_1->codeSize = count;
				if (count > 0)
				{
					arg_1_0 = new UInt32[count];

					// TODO : UInt32 bulk copy
					for (UInt32 i = 0; i < count; ++i)
					{
						arg_1_0[i] = (UInt32) pCreateInfo->Code[i];
					}
					arg_1->pCode = arg_1_0;
				}
				else
				{
					arg_1->pCode = nullptr;
				}
			}
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}
		// INITS 3 - pShaderModule		
		VkShaderModule inst_3;
		VkShaderModule* arg_3 = &inst_3;

		auto result = vkCreateShaderModule(arg_0, arg_1, arg_2, arg_3);

		pShaderModule = gcnew ShaderModule();
		pShaderModule->mHandle = inst_3;

		return (Result)result;
	}
	finally
	{
		if (arg_1_0 != nullptr)
		{
			delete[] arg_1_0;
		}

		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::Device::DestroyShaderModule(ManagedVulkan::ShaderModule^ shaderModule, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - shaderModule		
		VkShaderModule arg_1 = shaderModule->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyShaderModule(arg_0, arg_1, arg_2);


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

ManagedVulkan::Result ManagedVulkan::Device::CreatePipelineCache(ManagedVulkan::PipelineCacheCreateInfo^ pCreateInfo, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] ManagedVulkan::PipelineCache^% pPipelineCache)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pCreateInfo		
		VkPipelineCacheCreateInfo inst_1;
		VkPipelineCacheCreateInfo* arg_1 = nullptr;
		if (pCreateInfo != nullptr)
		{
			arg_1 = &inst_1;
			pCreateInfo->CopyTo(arg_1, pins);
		}
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		// INITS 3 - pPipelineCache		
		VkPipelineCache inst_3;
		VkPipelineCache* arg_3 = &inst_3;

		auto result = vkCreatePipelineCache(arg_0, arg_1, arg_2, arg_3);

		pPipelineCache = gcnew PipelineCache();
		pPipelineCache->mHandle = inst_3;

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

void ManagedVulkan::Device::DestroyPipelineCache(ManagedVulkan::PipelineCache^ pipelineCache, ManagedVulkan::AllocationCallbacks^ pAllocator)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;
		// INITS 2 - pAllocator		
		VkAllocationCallbacks inst_2;
		VkAllocationCallbacks* arg_2 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_2 = &inst_2;
			pAllocator->CopyTo(arg_2, pins);
		}

		vkDestroyPipelineCache(arg_0, arg_1, arg_2);

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

ManagedVulkan::Result ManagedVulkan::Device::GetPipelineCacheData(ManagedVulkan::PipelineCache^ pipelineCache,[In,Out] size_t^% pDataSize, IntPtr^ pData)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;
		// INITS 2 - pDataSize		
		size_t inst_2 = *pDataSize;
		size_t* arg_2 = &inst_2;
		// INITS 3 - pData		
		void* arg_3 = pData->ToPointer();

		auto result = vkGetPipelineCacheData(arg_0, arg_1, arg_2, arg_3);
		pDataSize = inst_2;

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

ManagedVulkan::Result ManagedVulkan::Device::MergePipelineCaches(ManagedVulkan::PipelineCache^ dstCache, array<ManagedVulkan::PipelineCache^>^ pSrcCaches)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkPipelineCache* arg_3 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - dstCache		
		VkPipelineCache arg_1 = dstCache->mHandle;
		// INITS 2 - srcCacheCount		
		uint32_t arg_2 = 0;
		// INITS 3 - pSrcCaches
		if (pSrcCaches != nullptr)
		{
			arg_2 = pSrcCaches->Length;
			if (arg_2 > 0)
			{
				arg_3 = new VkPipelineCache[arg_2];
				for (UInt32 i = 0; i < arg_2; ++i)
				{
					arg_3[i] = pSrcCaches[i]->mHandle;
				}
			}
		}

		auto result = vkMergePipelineCaches(arg_0, arg_1, arg_2, arg_3);

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Device::CreateGraphicsPipelines(ManagedVulkan::PipelineCache^ pipelineCache, array<ManagedVulkan::GraphicsPipelineCreateInfo^>^ pCreateInfos, ManagedVulkan::AllocationCallbacks^ pAllocator, [Out] array<ManagedVulkan::Pipeline^>^% pPipelines)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	// INITS 2 - createInfoCount
	uint32_t arg_2 = 0;
	VkGraphicsPipelineCreateInfo* arg_3 = nullptr;
	VkPipeline* arg_5 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - device		
		VkDevice arg_0 = this->mHandle;
		// INITS 1 - pipelineCache		
		VkPipelineCache arg_1 = pipelineCache->mHandle;		

		// INITS 3 - pCreateInfos
		if (pCreateInfos != nullptr)
		{
			arg_2 = pCreateInfos->Length;
			if (arg_2 > 0)
			{
				arg_3 = new VkGraphicsPipelineCreateInfo[arg_2];
				
				for (UInt32 i = 0; i < arg_2; ++i) // FOREACH CREATEINFO
				{
					auto src = (ManagedVulkan::GraphicsPipelineCreateInfo^) pCreateInfos[i];
					VkGraphicsPipelineCreateInfo* dest = arg_3 + i;

					if (src == nullptr)
					{
						throw gcnew NullReferenceException("pCreateInfos[" + i + "] is null");
					}

					{
						// FIELD - arg_3_4 pCreateInfos->Stages		
						VkPipelineShaderStageCreateInfo* arg_3_4 = nullptr;
						UInt32 stageCount = 0;

						if (src->Stages != nullptr)
						{
							stageCount = src->Stages->Length;

							if (stageCount > 0)
							{
								arg_3_4 = new VkPipelineShaderStageCreateInfo[stageCount];
								for (UInt32 j = 0; j < stageCount; ++j)
								{
									auto stageSrc = (ManagedVulkan::PipelineShaderStageCreateInfo^) src->Stages[j];
									VkPipelineShaderStageCreateInfo* stageDst = arg_3_4 + j;
									stageSrc->CopyTo(stageDst, pins);

									// FIELD - arg_3_4_6 pCreateInfos->Stages->SpecializationInfo		
									VkSpecializationInfo* arg_3_4_6 = nullptr;
									if (stageSrc->SpecializationInfo != nullptr)
									{
										arg_3_4_6 = new VkSpecializationInfo();
										stageSrc->SpecializationInfo->CopyTo(arg_3_4_6, pins);
										// FIELD - arg_3_4_6_1 pCreateInfos->Stages->SpecializationInfo->MapEntries
										VkSpecializationMapEntry* arg_3_4_6_1 = nullptr;
										UInt32 entryCount = 0;
										if (stageSrc->SpecializationInfo->MapEntries != nullptr)
										{
											UInt32 entryCount = stageSrc->SpecializationInfo->MapEntries->Length;

											if (entryCount > 0)
											{
												arg_3_4_6_1 = new VkSpecializationMapEntry[entryCount];
												for (UInt32 k = 0; k < entryCount; ++k)
												{
													auto srcEntry = (ManagedVulkan::SpecializationMapEntry^) stageSrc->SpecializationInfo->MapEntries[k];
													VkSpecializationMapEntry* dstEntry = arg_3_4_6_1 + k;
													srcEntry->CopyTo(dstEntry, pins);
												}
											}
										}
										arg_3_4_6->mapEntryCount = entryCount;
										arg_3_4_6->pMapEntries = arg_3_4_6_1;

										// TODO : data
									}
									stageDst->pSpecializationInfo = arg_3_4_6;
								}
							}
						}
						dest->stageCount = stageCount;
						dest->pStages = arg_3_4;						
					}

					// FIELD - arg_3_5 pCreateInfos->VertexInputState
					{
						VkPipelineVertexInputStateCreateInfo* arg_3_5 = nullptr;
						if (src->VertexInputState != nullptr)
						{
							arg_3_5 = new VkPipelineVertexInputStateCreateInfo();
							auto srcVertexInput = (ManagedVulkan::PipelineVertexInputStateCreateInfo^) src->VertexInputState;
							srcVertexInput->CopyTo(arg_3_5, pins);

							// FIELD - arg_3_5_4 pCreateInfos->VertexInputState->VertexBindingDescriptions	
							{
								VkVertexInputBindingDescription* arg_3_5_4 = nullptr;
								UInt32 bindingDescriptions = 0;
								if (srcVertexInput->VertexBindingDescriptions != nullptr)
								{
									bindingDescriptions = srcVertexInput->VertexBindingDescriptions->Length;
									if (bindingDescriptions > 0)
									{
										arg_3_5_4 = new VkVertexInputBindingDescription[bindingDescriptions];
										for (UInt32 j = 0; j < bindingDescriptions; ++j)
										{
											auto srcBinding = (ManagedVulkan::VertexInputBindingDescription^) srcVertexInput->VertexBindingDescriptions[j];
											VkVertexInputBindingDescription* dstBinding = arg_3_5_4 + j;
											srcBinding->CopyTo(dstBinding, pins);
										}
									}
								}
								arg_3_5->vertexBindingDescriptionCount = bindingDescriptions;
								arg_3_5->pVertexBindingDescriptions = arg_3_5_4;
							}

							// FIELD - arg_3_5_6 pCreateInfos->VertexInputState->VertexAttributeDescriptions		
							{
								VkVertexInputAttributeDescription* arg_3_5_6 = nullptr;
								UInt32 attributeDescriptions = 0;
								if (srcVertexInput->VertexAttributeDescriptions != nullptr)
								{
									attributeDescriptions = srcVertexInput->VertexAttributeDescriptions->Length;
									if (attributeDescriptions > 0)
									{
										arg_3_5_6 = new VkVertexInputAttributeDescription[attributeDescriptions];
										for (UInt32 j = 0; j < attributeDescriptions; ++j)
										{
											auto srcAttribute = (ManagedVulkan::VertexInputAttributeDescription^) srcVertexInput->VertexAttributeDescriptions[j];
											VkVertexInputAttributeDescription* dstAttribute = arg_3_5_6 + j;
											srcAttribute->CopyTo(dstAttribute, pins);
										}
									}
								}
								arg_3_5->vertexAttributeDescriptionCount = attributeDescriptions;
								arg_3_5->pVertexAttributeDescriptions = arg_3_5_6;

							}
						}
						dest->pVertexInputState = arg_3_5;
					}

					// FIELD - arg_3_6 pCreateInfos->InputAssemblyState	
					{
						VkPipelineInputAssemblyStateCreateInfo* arg_3_6 = nullptr;
						if (src->InputAssemblyState != nullptr)
						{
							arg_3_6 = new VkPipelineInputAssemblyStateCreateInfo();
							src->InputAssemblyState->CopyTo(arg_3_6, pins);
						}
						dest->pInputAssemblyState = arg_3_6;
					}

					// FIELD - arg_3_7 pCreateInfos->TessellationState		
					{
						VkPipelineTessellationStateCreateInfo* arg_3_7 = nullptr;
						if (src->TessellationState != nullptr)
						{
							arg_3_7 = new VkPipelineTessellationStateCreateInfo();
							src->TessellationState->CopyTo(arg_3_7, pins);
						}
						dest->pTessellationState = arg_3_7;
					}

					// FIELD - arg_3_8 pCreateInfos->ViewportState
					{
						VkPipelineViewportStateCreateInfo* arg_3_8 = nullptr;
						if (src->ViewportState != nullptr)
						{
							arg_3_8 = new VkPipelineViewportStateCreateInfo();
							src->ViewportState->CopyTo(arg_3_8, pins);
							{
								{
									// FIELD - arg_3_8_4 pCreateInfos->ViewportState->Viewports		
									VkViewport* arg_3_8_4 = nullptr;
									UInt32 noOfViewPorts = 0;

									if (src->ViewportState->Viewports != nullptr)
									{
										noOfViewPorts = src->ViewportState->Viewports->Length;
										if (noOfViewPorts > 0)
										{
											arg_3_8_4 = new VkViewport[noOfViewPorts];
											for (UInt32 j = 0; j < noOfViewPorts; ++j)
											{
												auto srcVP = (ManagedVulkan::Viewport^) src->ViewportState->Viewports[j];
												srcVP->CopyTo(arg_3_8_4 + j, pins);
											}
										}
									}
									arg_3_8->pViewports = arg_3_8_4;
									arg_3_8->viewportCount = noOfViewPorts;
								}

								{
									// FIELD - arg_3_8_6 pCreateInfos->ViewportState->Scissors	
									VkRect2D* arg_3_8_6 = nullptr;
									UInt32 noOfScissors = 0;

									if (src->ViewportState->Scissors != nullptr)
									{
										noOfScissors = src->ViewportState->Scissors->Length;

										arg_3_8_6 = new VkRect2D[noOfScissors];
										for (UInt32 j = 0; j < noOfScissors; ++j)
										{
											auto scissor = (ManagedVulkan::Rect2D^) src->ViewportState->Scissors[j];
											scissor->CopyTo(arg_3_8_6 + j, pins);
										}
									}
									arg_3_8->pScissors = arg_3_8_6;
									arg_3_8->scissorCount = noOfScissors;
								}
							}
						}
						dest->pViewportState = arg_3_8;
					}

					// FIELD - arg_3_9 pCreateInfos->RasterizationState	
					{
						VkPipelineRasterizationStateCreateInfo* arg_3_9 = nullptr;
						if (src->RasterizationState != nullptr)
						{
							arg_3_9 = new VkPipelineRasterizationStateCreateInfo();
							src->RasterizationState->CopyTo(arg_3_9, pins);
						}
						dest->pRasterizationState = arg_3_9;
					}

					// FIELD - arg_3_10 pCreateInfos->MultisampleState	
					{
						VkPipelineMultisampleStateCreateInfo* arg_3_10 = nullptr;
						if (src->MultisampleState != nullptr)
						{
							arg_3_10 = new VkPipelineMultisampleStateCreateInfo();
							src->MultisampleState->CopyTo(arg_3_10, pins);
						}
						dest->pMultisampleState = arg_3_10;
					}	

					// FIELD - arg_3_11 pCreateInfos->DepthStencilState		
					{
						VkPipelineDepthStencilStateCreateInfo* arg_3_11 = nullptr;
						if (src->DepthStencilState != nullptr)
						{
							arg_3_11 = new VkPipelineDepthStencilStateCreateInfo();
							src->DepthStencilState->CopyTo(arg_3_11, pins);
						}
						dest->pDepthStencilState = arg_3_11;
					}


					// FIELD - arg_3_12 pCreateInfos->ColorBlendState		
					{
						VkPipelineColorBlendStateCreateInfo* arg_3_12 = nullptr;
						if (src->ColorBlendState != nullptr)
						{
							arg_3_12 = new VkPipelineColorBlendStateCreateInfo();
							src->ColorBlendState->CopyTo(arg_3_12, pins);

							// FIELD - arg_3_12_6 pCreateInfos->ColorBlendState->Attachments	
							{
								VkPipelineColorBlendAttachmentState* arg_3_12_6 = nullptr;
								UInt32 noOfAttachments = 0;

								if (src->ColorBlendState->Attachments != nullptr)
								{
									noOfAttachments = src->ColorBlendState->Attachments->Length;
									if (noOfAttachments > 0)
									{
										arg_3_12_6 = new VkPipelineColorBlendAttachmentState[noOfAttachments];
										for (UInt32 j = 0; j < noOfAttachments; ++j)
										{
											auto attachment = (ManagedVulkan::PipelineColorBlendAttachmentState^) src->ColorBlendState->Attachments[j];
											attachment->CopyTo(arg_3_12_6 + j, pins);
										}
									}
								}

								arg_3_12->attachmentCount = noOfAttachments;
								arg_3_12->pAttachments = arg_3_12_6;
							}
						}
						dest->pColorBlendState = arg_3_12;
					}

					{
						// FIELD - arg_3_13 pCreateInfos->DynamicState		
						VkPipelineDynamicStateCreateInfo* arg_3_13 = nullptr;
						if (src->DynamicState != nullptr)
						{
							arg_3_13 = new VkPipelineDynamicStateCreateInfo();
							src->DynamicState->CopyTo(arg_3_13, pins);
							
							// FIELD - arg_3_13 pCreateInfos->DynamicState->DynamicStates	
							{
								VkDynamicState* arg_3_13_1 = nullptr;
								UInt32 noOfStates = 0;
								if (src->DynamicState->DynamicStates != nullptr)
								{
									noOfStates = src->DynamicState->DynamicStates->Length;
									if (noOfStates > 0)
									{
										arg_3_13_1 = new VkDynamicState[noOfStates];
										for (UInt32 j = 0; j < noOfStates; ++j)
										{
											arg_3_13_1[j] = (VkDynamicState)src->DynamicState->DynamicStates[j];
										}
									}
								}
								arg_3_13->dynamicStateCount = noOfStates;
								arg_3_13->pDynamicStates = arg_3_13_1;
							}
							//array<ManagedVulkan::DynamicState>^ mDynamicStates = nullptr;
						}
						dest->pDynamicState = arg_3_13;
					}

				} // END FOREACH CREATEINFO
			} 
		}

		// INITS 4 - pAllocator		
		VkAllocationCallbacks inst_4;
		VkAllocationCallbacks* arg_4 = nullptr;
		if (pAllocator != nullptr)
		{
			arg_4 = &inst_4;
			pAllocator->CopyTo(arg_4, pins);
		}

		// INITS 5 - pPipelines		
		arg_5 = new VkPipeline[arg_2];

		auto result = vkCreateGraphicsPipelines(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);

		pPipelines = gcnew array<Pipeline^>(arg_2);
		for (UInt32 i = 0; i < arg_2; ++i)
		{
			pPipelines[i] = gcnew Pipeline();
			pPipelines[i]->mHandle = arg_5[i];
		}

		return (Result)result;
	}
	finally
	{
		if (arg_3 != nullptr)
		{
			for (UInt32 i = 0; i < arg_2; ++i)
			{
				auto parent = (VkGraphicsPipelineCreateInfo*)arg_3 + i;

				if (parent->pStages != nullptr)
				{
					{
						UInt32 noOfStages = parent->stageCount;
						for (UInt32 j = 0; j < noOfStages; ++j)
						{
							auto parentStage = parent->pStages + j;
							if (parentStage->pSpecializationInfo != nullptr)
							{
								if (parentStage->pSpecializationInfo->pMapEntries != nullptr)
								{
									delete[] parentStage->pSpecializationInfo->pMapEntries;
								}
								delete parentStage->pSpecializationInfo;
							}
						}
					}
					delete[] parent->pStages;
				}

				if (parent->pVertexInputState != nullptr)
				{
					if (parent->pVertexInputState->pVertexBindingDescriptions != nullptr)
					{
						delete[] parent->pVertexInputState->pVertexBindingDescriptions;
					}

					if (parent->pVertexInputState->pVertexAttributeDescriptions != nullptr)
					{
						delete[] parent->pVertexInputState->pVertexAttributeDescriptions;
					}

					delete parent->pVertexInputState;
				}

				if (parent->pInputAssemblyState != nullptr)
				{
					delete parent->pInputAssemblyState;
				}

				if (parent->pTessellationState != nullptr)
				{
					delete parent->pTessellationState;
				}

				if (parent->pViewportState != nullptr)
				{
					if (parent->pViewportState->pViewports != nullptr)
					{
						delete[] parent->pViewportState->pViewports;
					}

					if (parent->pViewportState->pScissors != nullptr)
					{
						delete[] parent->pViewportState->pScissors;
					}
					delete parent->pViewportState;
				}

				if (parent->pRasterizationState != nullptr)
				{
					delete parent->pRasterizationState;
				}

				if (parent->pRasterizationState != nullptr)
				{
					delete parent->pRasterizationState;
				}

				if (parent->pMultisampleState != nullptr)
				{
					delete parent->pMultisampleState;
				}

				if (parent->pDepthStencilState != nullptr)
				{
					delete parent->pDepthStencilState;
				}

				if (parent->pColorBlendState != nullptr)
				{
					if (parent->pColorBlendState->pAttachments != nullptr)
					{
						delete[] parent->pColorBlendState->pAttachments;
					}

					delete parent->pColorBlendState;
				}

				if (parent->pDynamicState != nullptr)
				{
					if (parent->pDynamicState->pDynamicStates != nullptr)
					{
						delete[] parent->pDynamicState->pDynamicStates;
					}

					delete parent->pDynamicState;
				}
			}

			delete[] arg_3;
		}
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}