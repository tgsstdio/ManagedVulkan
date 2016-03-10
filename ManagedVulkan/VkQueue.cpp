#include "stdafx.h"
#include "VkQueue.h"
#include "VkCommandBuffer.h"

// VkQueue
ManagedVulkan::Result ManagedVulkan::Queue::QueueSubmit(array<ManagedVulkan::SubmitInfo^>^ pSubmits, ManagedVulkan::Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSubmitInfo* arg_2 = nullptr;

	UInt32 submitCount = 0;
	try
	{
		// MAIN INIT

		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;
		// INITS 1 - submitCount
		uint32_t arg_1 = 0;

		// INITS 2 - pSubmits	
		if (pSubmits != nullptr)
		{
			submitCount = pSubmits->Length;
			arg_1 = submitCount;

			arg_2 = new VkSubmitInfo[submitCount];
			for (UInt32 i = 0; i < submitCount; ++i)
			{
				VkSubmitInfo* dest = (arg_2 + i);
				ManagedVulkan::SubmitInfo^ src = pSubmits[i];
				src->CopyTo(dest, pins);

				{
					UInt32 waitCount = src->WaitSemaphoreCount;
					dest->waitSemaphoreCount = waitCount;
					if (waitCount > 0)
					{
						UInt32* waitMask = new UInt32[waitCount];
						VkSemaphore* waitSemaphores = new VkSemaphore[waitCount];
						for (UInt32 j = 0; j < waitCount; ++j)
						{
							waitMask[j] = (UInt32)src->WaitDstStageMask[j];
							ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) src->WaitSemaphores[j];
							waitSemaphores[j] = semiphore->mHandle;
						}
						dest->pWaitDstStageMask = waitMask;
						dest->pWaitSemaphores = waitSemaphores;
					}
					else
					{
						dest->pWaitDstStageMask = nullptr;
						dest->pWaitSemaphores = nullptr;
					}
				}

				{
					UInt32 bufferCount = src->CommandBuffers != nullptr ? src->CommandBuffers->Length : 0;
					dest->commandBufferCount = bufferCount;
					if (bufferCount > 0)
					{
						VkCommandBuffer* buffers = new VkCommandBuffer[bufferCount];
						for (UInt32 j = 0; j < bufferCount; ++j)
						{
							ManagedVulkan::CommandBuffer^ cb = (ManagedVulkan::CommandBuffer^) src->CommandBuffers[j];
							buffers[j] = cb->mHandle;
						}
						dest->pCommandBuffers = buffers;
					}
					else
					{
						dest->pCommandBuffers = nullptr;
					}
				}
				
				{
					UInt32 signalCount = src->SignalSemaphores != nullptr ? src->SignalSemaphores->Length : 0;
					dest->signalSemaphoreCount = signalCount;
					if (signalCount > 0)
					{
						VkSemaphore* signals = new VkSemaphore[signalCount];
						for (UInt32 j = 0; j < signalCount; ++j)
						{
							ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) src->SignalSemaphores[j];
							signals[j] = semiphore->mHandle;
						}
						dest->pSignalSemaphores = signals;
					}
					else
					{
						dest->pSignalSemaphores = nullptr;
					}
				}
			}
		}


		// INITS 3 - fence		
		VkFence arg_3 = fence->mHandle;

		int result = vkQueueSubmit(arg_0, arg_1, arg_2, arg_3);

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			for (UInt32 i = 0; i < submitCount; ++i)
			{
				if ((arg_2 + i)->pWaitSemaphores != nullptr)
				{
					delete[](arg_2 + i)->pWaitSemaphores;
				}

				if ((arg_2 + i)->pWaitDstStageMask != nullptr)
				{
					delete[](arg_2 + i)->pWaitDstStageMask;
				}

				if ((arg_2 + i)->pCommandBuffers != nullptr)
				{
					delete[](arg_2 + i)->pCommandBuffers;
				}

				if ((arg_2 + i)->pSignalSemaphores != nullptr)
				{
					delete[](arg_2 + i)->pSignalSemaphores;
				}
			}

			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Queue::QueueWaitIdle()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;

		auto result = vkQueueWaitIdle(arg_0);

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

ManagedVulkan::Result ManagedVulkan::Queue::QueueBindSparse(array<ManagedVulkan::BindSparseInfo^>^ pBindInfo, ManagedVulkan::Fence^ fence)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBindSparseInfo* arg_2 = nullptr;

	UInt32 bindInfoCount = 0;
	try
	{
		// MAIN INIT

		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;

		// INITS 1 - bindInfoCount	
		uint32_t arg_1 = 0;

		if (pBindInfo != nullptr)
		{
			bindInfoCount = pBindInfo->Length; \
				arg_1 = bindInfoCount;

			arg_2 = new VkBindSparseInfo[bindInfoCount];
			for (UInt32 i = 0; i < bindInfoCount; ++i)
			{
				VkBindSparseInfo* dest = (arg_2 + i);
				ManagedVulkan::BindSparseInfo^ src = pBindInfo[i];

				src->CopyTo(dest, pins);

				/// FOREACH ARRAY MEMBER

				{
					UInt32 waitCount = src->WaitSemaphores != nullptr ? src->WaitSemaphores->Length : 0;
					dest->waitSemaphoreCount = waitCount;
					if (waitCount > 0)
					{
						VkSemaphore* waitSemaphores = new VkSemaphore[waitCount];
						for (UInt32 j = 0; j < waitCount; ++j)
						{
							ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) src->WaitSemaphores[j];
							waitSemaphores[j] = semiphore->mHandle;
						}
						dest->pWaitSemaphores = waitSemaphores;
					}
					else
					{
						dest->pWaitSemaphores = nullptr;
					}
				}

				{
					UInt32 opaqueBinds = src->ImageOpaqueBinds != nullptr ? src->ImageOpaqueBinds->Length : 0;

					dest->imageOpaqueBindCount = opaqueBinds;
					if (opaqueBinds > 0)
					{
						VkSparseImageOpaqueMemoryBindInfo* binds = new VkSparseImageOpaqueMemoryBindInfo[opaqueBinds];
						for (UInt32 j = 0; j < opaqueBinds; ++j)
						{
							ManagedVulkan::SparseImageOpaqueMemoryBindInfo^ sourceImageBind = (ManagedVulkan::SparseImageOpaqueMemoryBindInfo^) src->ImageOpaqueBinds[j];
							VkSparseImageOpaqueMemoryBindInfo* destImageBind = binds + j;
							
							// NOT SURE WHAT SHOULD HAPPEN HERE
							if (sourceImageBind == nullptr)
							{
								destImageBind->bindCount = 0;
								destImageBind->pBinds = nullptr;
							}
							else
							{
								sourceImageBind->CopyTo(destImageBind, pins);

								UInt32 grandChildren = sourceImageBind->Binds != nullptr ? sourceImageBind->Binds->Length : 0;
								destImageBind->bindCount = 0;
								if (grandChildren > 0)
								{
									VkSparseMemoryBind* memoryBinds = new VkSparseMemoryBind[grandChildren];
									for (UInt32 k = 0; k < grandChildren; ++k)
									{
										ManagedVulkan::SparseMemoryBind^ sourceMemBind = (ManagedVulkan::SparseMemoryBind^) sourceImageBind->Binds[k];
										VkSparseMemoryBind* destMemBind = memoryBinds + k;
										if (sourceMemBind != nullptr)
										{
											sourceMemBind->CopyTo(destMemBind, pins);
										}
									}
									destImageBind->pBinds = memoryBinds;
								}
							}

						}
						dest->pImageOpaqueBinds = binds;
					}
					else
					{
						dest->pImageOpaqueBinds = nullptr;
					}

				}

				{
					UInt32 imageBinds = src->ImageBinds != nullptr ? src->ImageBinds->Length : 0;

					dest->imageBindCount = imageBinds;
					if (imageBinds > 0)
					{
						VkSparseImageMemoryBindInfo* binds = new VkSparseImageMemoryBindInfo[imageBinds];
						for (UInt32 j = 0; j < imageBinds; ++j)
						{
							ManagedVulkan::SparseImageMemoryBindInfo^ sourceImageBind = (ManagedVulkan::SparseImageMemoryBindInfo^) src->ImageBinds[j];
							VkSparseImageMemoryBindInfo* destImageBind = binds + j;

							// NOT SURE WHAT SHOULD HAPPEN HERE
							if (sourceImageBind == nullptr)
							{
								destImageBind->bindCount = 0;
								destImageBind->pBinds = nullptr;
							}
							else
							{
								sourceImageBind->CopyTo(destImageBind, pins);

								UInt32 grandChildren = sourceImageBind->Binds != nullptr ? sourceImageBind->Binds->Length : 0;
								destImageBind->bindCount = 0;
								if (grandChildren > 0)
								{
									VkSparseImageMemoryBind* memoryBinds = new VkSparseImageMemoryBind[grandChildren];
									for (UInt32 k = 0; k < grandChildren; ++k)
									{
										ManagedVulkan::SparseImageMemoryBind^ sourceMemBind = (ManagedVulkan::SparseImageMemoryBind^) sourceImageBind->Binds[k];
										VkSparseImageMemoryBind* destMemBind = memoryBinds + k;
										if (sourceMemBind != nullptr)
										{
											sourceMemBind->CopyTo(destMemBind, pins);
										}
									}
									destImageBind->pBinds = memoryBinds;
								}
							}

						}
						dest->pImageBinds = binds;
					}
					else
					{
						dest->pImageBinds = nullptr;
					}

				}

				{
					UInt32 bufferBinds = src->BufferBinds != nullptr ? src->BufferBinds->Length : 0;
					dest->bufferBindCount = bufferBinds;

					if (bufferBinds > 0)
					{
						VkSparseBufferMemoryBindInfo* buffers = new VkSparseBufferMemoryBindInfo[bufferBinds];
						for (UInt32 j = 0; j < bufferBinds; ++j)
						{
							ManagedVulkan::SparseBufferMemoryBindInfo^ sourceBuffer = (ManagedVulkan::SparseBufferMemoryBindInfo^) src->BufferBinds[j];
							VkSparseBufferMemoryBindInfo* destBuffer = buffers + j;

							// NOT SURE WHAT SHOULD HAPPEN HERE
							if (sourceBuffer == nullptr)
							{
								destBuffer->bindCount = 0;
								destBuffer->pBinds = nullptr;
							}
							else
							{
								sourceBuffer->CopyTo(destBuffer, pins);

								UInt32 grandChildren = sourceBuffer->Binds != nullptr ? sourceBuffer->Binds->Length : 0;
								destBuffer->bindCount = 0;
								if (grandChildren > 0)
								{
									VkSparseMemoryBind* memoryBinds = new VkSparseMemoryBind[grandChildren];
									for (UInt32 k = 0; k < grandChildren; ++k)
									{
										ManagedVulkan::SparseMemoryBind^ sourceBufferBind = (ManagedVulkan::SparseMemoryBind^) sourceBuffer->Binds[k];
										VkSparseMemoryBind* destBufferBind = memoryBinds + k;
										if (sourceBufferBind != nullptr)
										{
											sourceBufferBind->CopyTo(destBufferBind, pins);
										}
									}
									destBuffer->pBinds = memoryBinds;
								}
							}
						}
						dest->pBufferBinds = buffers;
					}
					else
					{
						dest->pBufferBinds = nullptr;
					}
				}

				{
					// SIGNAL SEMAPHORES
					UInt32 signalsCount = src->SignalSemaphores != nullptr ? src->SignalSemaphores->Length : 0;
					dest->signalSemaphoreCount = signalsCount;
					if (signalsCount > 0)
					{
						VkSemaphore* signals = new VkSemaphore[signalsCount];
						for (UInt32 j = 0; j < signalsCount; ++j)
						{
							ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) src->SignalSemaphores[j];
							signals[j] = semiphore->mHandle;
						}
						dest->pSignalSemaphores = signals;
					}
					else
					{
						dest->pSignalSemaphores = nullptr;
					}
				}

			}
		}

		// INITS 3 - fence		
		VkFence arg_3 = fence->mHandle;

		auto result = vkQueueBindSparse(arg_0, arg_1, arg_2, arg_3);

		return (Result)result;
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			for (UInt32 i = 0; i < bindInfoCount; ++i)
			{
				VkBindSparseInfo* parent = &arg_2[i];

				if (parent->pWaitSemaphores != nullptr)
				{
					delete[] parent->pWaitSemaphores;
				}

				if (parent->pBufferBinds != nullptr)
				{
					for (UInt32 j = 0; j < parent->bufferBindCount; ++j)
					{
						const VkSparseBufferMemoryBindInfo* child = (parent->pBufferBinds + j);
						delete[] child->pBinds;
					}

					delete[]parent->pBufferBinds;
				}

				if (parent->pImageBinds != nullptr)
				{
					for (UInt32 j = 0; j < parent->imageBindCount; ++j)
					{
						const VkSparseImageMemoryBindInfo* child = (parent->pImageBinds + j);
						delete[] child->pBinds;
					}

					delete[] parent->pImageBinds;
				}

				if (parent->pImageOpaqueBinds != nullptr)
				{
					for (UInt32 j = 0; j < parent->imageOpaqueBindCount; ++j)
					{
						const VkSparseImageOpaqueMemoryBindInfo* child = (parent->pImageOpaqueBinds + j);
						delete[] child->pBinds;
					}

					delete[] parent->pImageOpaqueBinds;
				}

				if (parent->pSignalSemaphores != nullptr)
				{
					delete[] parent->pSignalSemaphores;
				}
			}

			delete[] arg_2;
		}
		// FREE ALL PINNED STRINGS
		for each(IntPtr str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

ManagedVulkan::Result ManagedVulkan::Queue::QueuePresentKHR(ManagedVulkan::PresentInfoKHR^ pPresentInfo, [Out] array<ManagedVulkan::Result>^% results)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkSemaphore* waitSemaphores = nullptr;
	UInt32* imageIndices = nullptr;
	VkSwapchainKHR* swapChains = nullptr;
	VkResult* queryResults = nullptr;
	UInt32 swapchainCount = 0;

	try
	{
		// MAIN INIT

		// INITS 0 - queue		
		VkQueue arg_0 = this->mHandle;
		// INITS 1 - pPresentInfo		
		VkPresentInfoKHR inst_1;
		VkPresentInfoKHR* arg_1 = nullptr;
		if (pPresentInfo != nullptr)
		{
			arg_1 = &inst_1;
			pPresentInfo->CopyTo(arg_1, pins);
			{
				UInt32 waitCount = pPresentInfo->WaitSemaphores != nullptr ? pPresentInfo->WaitSemaphores->Length : 0;
				arg_1->waitSemaphoreCount = waitCount;
				if (waitCount > 0)
				{
					UInt32* waitMask = new UInt32[waitCount];
					VkSemaphore* waitSemaphores = new VkSemaphore[waitCount];
					for (UInt32 j = 0; j < waitCount; ++j)
					{
						ManagedVulkan::Semaphore^ semiphore = (ManagedVulkan::Semaphore^) pPresentInfo->WaitSemaphores[j];
						waitSemaphores[j] = semiphore->mHandle;
					}
					arg_1->pWaitSemaphores = waitSemaphores;
				}
				else
				{
					arg_1->pWaitSemaphores = nullptr;
				}
			}

			{
				swapchainCount = pPresentInfo->SwapchainCount;
				arg_1->swapchainCount = swapchainCount;
				if (swapchainCount > 0)
				{
					imageIndices = new UInt32[swapchainCount];
					swapChains = new VkSwapchainKHR[swapchainCount];
					queryResults = new VkResult[swapchainCount];
					for (UInt32 j = 0; j < swapchainCount; ++j)
					{
						imageIndices[j] = (UInt32) pPresentInfo->ImageIndices[j];
						ManagedVulkan::SwapchainKHR^ source = (ManagedVulkan::SwapchainKHR^) pPresentInfo->Swapchains[j];
						swapChains[j] = source->mHandle;
					}
					arg_1->pImageIndices = imageIndices;
					arg_1->pSwapchains = swapChains;
					arg_1->pResults = queryResults;
				}
				else
				{
					arg_1->pSwapchains = nullptr;
					arg_1->pImageIndices = nullptr;
					arg_1->pResults = nullptr;
				}

			}
		}

		auto outcome = vkQueuePresentKHR(arg_0, arg_1);

		results = gcnew array<ManagedVulkan::Result>(swapchainCount);
		for (UInt32 i = 0; i < swapchainCount; ++i)
		{
			results[i] = (ManagedVulkan::Result) queryResults[i];
		}

		return (ManagedVulkan::Result)outcome;
	}
	finally
	{
		if (waitSemaphores != nullptr)
		{
			delete[] waitSemaphores;
		}

		if (imageIndices != nullptr)
		{
			delete[] imageIndices;
		}

		if (swapChains != nullptr)
		{
			delete[] swapChains;
		}

		if (queryResults != nullptr)
		{
			delete[] queryResults;
		}

		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}