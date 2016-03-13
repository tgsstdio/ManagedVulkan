#include "stdafx.h"

#include "VkCommandBuffer.h"

using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

// VkCommandBuffer
ManagedVulkan::Result ManagedVulkan::CommandBuffer::BeginCommandBuffer(ManagedVulkan::CommandBufferBeginInfo^ pBeginInfo)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - pBeginInfo		
		VkCommandBufferBeginInfo inst_1;
		VkCommandBufferBeginInfo* arg_1 = nullptr;
		if (pBeginInfo != nullptr)
		{
			arg_1 = &inst_1;
			pBeginInfo->CopyTo(arg_1, pins);
		}

		// FIELD - arg_1_3 pBeginInfo->InheritanceInfo		
		VkCommandBufferInheritanceInfo* arg_1_3 = nullptr;
		VkCommandBufferInheritanceInfo  inst_1_3;
		if (pBeginInfo != nullptr && pBeginInfo->InheritanceInfo != nullptr)
		{
			arg_1_3 = &inst_1_3;
			pBeginInfo->InheritanceInfo->CopyTo(arg_1_3, pins);
			arg_1->pInheritanceInfo = arg_1_3;
		}

		auto result = vkBeginCommandBuffer(arg_0, arg_1);

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

ManagedVulkan::Result ManagedVulkan::CommandBuffer::EndCommandBuffer()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;

		auto result = vkEndCommandBuffer(arg_0);

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

ManagedVulkan::Result ManagedVulkan::CommandBuffer::ResetCommandBuffer(CommandBufferResetFlagBits flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - flags		
		VkCommandBufferResetFlags arg_1 = (VkCommandBufferResetFlagBits) flags;

		auto result = vkResetCommandBuffer(arg_0, arg_1);

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

void ManagedVulkan::CommandBuffer::CmdBindPipeline(ManagedVulkan::PipelineBindPoint pipelineBindPoint, ManagedVulkan::Pipeline^ pipeline)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - pipelineBindPoint		
		VkPipelineBindPoint arg_1 = (VkPipelineBindPoint) pipelineBindPoint;
		// INITS 2 - pipeline		
		VkPipeline arg_2 = pipeline->mHandle;

		vkCmdBindPipeline(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdSetViewport(UInt32 firstViewport, UInt32 viewportCount, array<ManagedVulkan::Viewport^>^ pViewports)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkViewport* arg_3 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - firstViewport		
		uint32_t arg_1 = firstViewport;
		// INITS 2 - viewportCount		
		uint32_t arg_2 = viewportCount;
		// INITS 3 - pViewports		

		if (pViewports != nullptr)
		{
			UInt32 noOfViewports = pViewports->Length;
			if (noOfViewports > 0)
			{
				arg_3 = new VkViewport[viewportCount];
				for (UInt32 i = 0; i < noOfViewports; ++i)
				{
					auto srcViewport = (ManagedVulkan::Viewport^) pViewports[i];
					srcViewport->CopyTo(arg_3 + i, pins);
				}
			}
		}

		vkCmdSetViewport(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdSetScissor(UInt32 firstScissor, UInt32 scissorCount, array<ManagedVulkan::Rect2D^>^ pScissors)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkRect2D* arg_3 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - firstScissor		
		uint32_t arg_1 = firstScissor;
		// INITS 2 - scissorCount		
		uint32_t arg_2 = scissorCount;
		// INITS 3 - pScissors
		if (pScissors != nullptr)
		{
			UInt32 noOfScissors = pScissors->Length;
			if (noOfScissors > 0)
			{
				arg_3 = new VkRect2D[scissorCount];
				for (UInt32 i = 0; i < noOfScissors; ++i)
				{
					auto srcViewport = (ManagedVulkan::Rect2D^) pScissors[i];
					srcViewport->CopyTo(arg_3 + i, pins);
				}
			}
		}


		vkCmdSetScissor(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdSetLineWidth(float lineWidth)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - lineWidth		
		float arg_1 = lineWidth;

		vkCmdSetLineWidth(arg_0, arg_1);


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

void ManagedVulkan::CommandBuffer::CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - depthBiasConstantFactor		
		float arg_1 = depthBiasConstantFactor;
		// INITS 2 - depthBiasClamp		
		float arg_2 = depthBiasClamp;
		// INITS 3 - depthBiasSlopeFactor		
		float arg_3 = depthBiasSlopeFactor;

		vkCmdSetDepthBias(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdSetBlendConstants(ManagedVulkan::Vec4f^ blendConstants)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	float arg_1[4];
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - blendConstants[4]		
		if (blendConstants != nullptr)
		{
			blendConstants->CopyTo(arg_1);
		}

		vkCmdSetBlendConstants(arg_0, arg_1);


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

void ManagedVulkan::CommandBuffer::CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - minDepthBounds		
		float arg_1 = minDepthBounds;
		// INITS 2 - maxDepthBounds		
		float arg_2 = maxDepthBounds;

		vkCmdSetDepthBounds(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdSetStencilCompareMask(ManagedVulkan::StencilFaceFlagBits faceMask, UInt32 compareMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - faceMask		
		VkStencilFaceFlags arg_1 = (VkStencilFaceFlags) faceMask;
		// INITS 2 - compareMask		
		uint32_t arg_2 = compareMask;

		vkCmdSetStencilCompareMask(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdSetStencilWriteMask(ManagedVulkan::StencilFaceFlagBits faceMask, UInt32 writeMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - faceMask		
		VkStencilFaceFlags arg_1 = (VkStencilFaceFlags) faceMask;
		// INITS 2 - writeMask		
		uint32_t arg_2 = writeMask;

		vkCmdSetStencilWriteMask(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdSetStencilReference(ManagedVulkan::StencilFaceFlagBits faceMask, UInt32 reference)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - faceMask		
		VkStencilFaceFlags arg_1 = (VkStencilFaceFlags) faceMask;
		// INITS 2 - reference		
		uint32_t arg_2 = reference;

		vkCmdSetStencilReference(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdBindDescriptorSets(ManagedVulkan::PipelineBindPoint pipelineBindPoint, ManagedVulkan::PipelineLayout^ layout, UInt32 firstSet, UInt32 descriptorSetCount, array<ManagedVulkan::DescriptorSet^>^ pDescriptorSets, array<UInt32>^ pDynamicOffsets)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkDescriptorSet* arg_5 = nullptr;
	UInt32* arg_7 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - pipelineBindPoint		
		VkPipelineBindPoint arg_1 = (VkPipelineBindPoint) pipelineBindPoint;
		// INITS 2 - layout		
		VkPipelineLayout arg_2 = layout->mHandle;
		// INITS 3 - firstSet		
		uint32_t arg_3 = firstSet;
		// INITS 4 - descriptorSetCount		
		uint32_t arg_4 = descriptorSetCount;
		// INITS 5 - pDescriptorSets
		
		UInt32 noOfSets = (pDescriptorSets != nullptr) ? pDescriptorSets->Length : 0;

		if (firstSet + descriptorSetCount >= noOfSets)
		{
			throw gcnew InvalidOperationException("firstSet + descriptorSetCount >= pDescriptorSets->Length");
		}

		if (pDescriptorSets != nullptr)
		{
			if (noOfSets > 0)
			{
				arg_5 = new VkDescriptorSet[noOfSets];
				for (UInt32 i = 0; i < noOfSets; ++i)
				{
					auto srcSet = (ManagedVulkan::DescriptorSet^) pDescriptorSets[i];
					arg_5[i] = srcSet->mHandle;
				}
			}
		}
		// INITS 6 - dynamicOffsetCount		
		uint32_t arg_6 = 0;
		// INITS 7 - pDynamicOffsets		
		if (pDynamicOffsets != nullptr)
		{
			arg_6 = pDynamicOffsets->Length;
			if (arg_6 > 0)
			{
				arg_7 = new UInt32[arg_6];
				for (UInt32 i = 0; i < arg_6; ++i)
				{					
					arg_7[i] = (UInt32)pDynamicOffsets[i];
				}
			}
		}

		vkCmdBindDescriptorSets(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


	}
	finally
	{
		if (arg_5 != nullptr)
		{
			delete[] arg_5;
		}
		if (arg_7 != nullptr)
		{
			delete[] arg_7;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBindIndexBuffer(ManagedVulkan::Buffer^ buffer, UInt64 offset, ManagedVulkan::IndexType indexType)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;
		// INITS 3 - indexType		
		VkIndexType arg_3 = (VkIndexType) indexType;

		vkCmdBindIndexBuffer(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdBindVertexBuffers(UInt32 firstBinding, UInt32 bindingCount, array<ManagedVulkan::Buffer^>^ pBuffers, array<UInt64>^ pOffsets)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBuffer* arg_3 = nullptr;
	UInt64* arg_4 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - firstBinding		
		uint32_t arg_1 = firstBinding;
		// INITS 2 - bindingCount		
		uint32_t arg_2 = bindingCount;

		UInt32 noOfBuffers = (pBuffers != nullptr) ? pBuffers->Length : 0;
		UInt32 noOfOffsets = (pOffsets != nullptr) ? pOffsets->Length : 0;

		// INITS 3 - pBuffers
		if (pBuffers != nullptr)
		{	
			if (noOfBuffers > 0)
			{
				arg_3 = new VkBuffer[noOfBuffers];
				for (UInt32 i = 0; i < noOfBuffers; ++i)
				{
					arg_3[i] = pBuffers[i]->mHandle;
				}
			}
		}
		// INITS 4 - pOffsets
		if (pOffsets != nullptr)
		{
			if (noOfOffsets > 0)
			{
				arg_4 = new UInt64[bindingCount];
				for (UInt32 i = 0; i < noOfBuffers; ++i)
				{
					arg_4[i] = pOffsets[i];
				}
			}
		}

		vkCmdBindVertexBuffers(arg_0, arg_1, arg_2, arg_3, arg_4);


	}
	finally
	{
		if (arg_3 != nullptr)
		{
			delete[] arg_3;
		}
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdDraw(UInt32 vertexCount, UInt32 instanceCount, UInt32 firstVertex, UInt32 firstInstance)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - vertexCount		
		uint32_t arg_1 = vertexCount;
		// INITS 2 - instanceCount		
		uint32_t arg_2 = instanceCount;
		// INITS 3 - firstVertex		
		uint32_t arg_3 = firstVertex;
		// INITS 4 - firstInstance		
		uint32_t arg_4 = firstInstance;

		vkCmdDraw(arg_0, arg_1, arg_2, arg_3, arg_4);


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


void ManagedVulkan::CommandBuffer::CmdDrawIndexed(UInt32 indexCount, UInt32 instanceCount, UInt32 firstIndex, Int32 vertexOffset, UInt32 firstInstance)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - indexCount		
		uint32_t arg_1 = indexCount;
		// INITS 2 - instanceCount		
		uint32_t arg_2 = instanceCount;
		// INITS 3 - firstIndex		
		uint32_t arg_3 = firstIndex;
		// INITS 4 - vertexOffset		
		int32_t arg_4 = vertexOffset;
		// INITS 5 - firstInstance		
		uint32_t arg_5 = firstInstance;

		vkCmdDrawIndexed(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


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

void ManagedVulkan::CommandBuffer::CmdDrawIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;
		// INITS 3 - drawCount		
		uint32_t arg_3 = drawCount;
		// INITS 4 - stride		
		uint32_t arg_4 = stride;

		vkCmdDrawIndirect(arg_0, arg_1, arg_2, arg_3, arg_4);


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

void ManagedVulkan::CommandBuffer::CmdDrawIndexedIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;
		// INITS 3 - drawCount		
		uint32_t arg_3 = drawCount;
		// INITS 4 - stride		
		uint32_t arg_4 = stride;

		vkCmdDrawIndexedIndirect(arg_0, arg_1, arg_2, arg_3, arg_4);


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

void ManagedVulkan::CommandBuffer::CmdDispatch(UInt32 x, UInt32 y, UInt32 z)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - x		
		uint32_t arg_1 = x;
		// INITS 2 - y		
		uint32_t arg_2 = y;
		// INITS 3 - z		
		uint32_t arg_3 = z;

		vkCmdDispatch(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdDispatchIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - buffer		
		VkBuffer arg_1 = buffer->mHandle;
		// INITS 2 - offset		
		VkDeviceSize arg_2 = offset;

		vkCmdDispatchIndirect(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdCopyBuffer(ManagedVulkan::Buffer^ srcBuffer, ManagedVulkan::Buffer^ dstBuffer, array<ManagedVulkan::BufferCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBufferCopy* arg_4 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcBuffer		
		VkBuffer arg_1 = srcBuffer->mHandle;
		// INITS 2 - dstBuffer		
		VkBuffer arg_2 = dstBuffer->mHandle;
		// INITS 3 - regionCount		
		uint32_t arg_3 = 0;
		// INITS 4 - pRegions		
		if (pRegions != nullptr)
		{
			UInt32 regionCount = pRegions->Length;
			if (regionCount > 0)
			{
				arg_4 = new VkBufferCopy[regionCount];
				for (UInt32 i = 0; i < regionCount; ++i)
				{
					auto srcRegion = (ManagedVulkan::BufferCopy^) pRegions[i];
					srcRegion->CopyTo(arg_4 + i, pins);
				}
			}
		}

		vkCmdCopyBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);


	}
	finally
	{
		if (arg_4 != nullptr)
		{
			delete[] arg_4;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}