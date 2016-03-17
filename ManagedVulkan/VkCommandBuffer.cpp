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
					arg_7[i] = pDynamicOffsets[i];
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
					auto srcRegion = pRegions[i];
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

void ManagedVulkan::CommandBuffer::CmdCopyImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::ImageCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageCopy* arg_6 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = (VkImageLayout)srcImageLayout;
		// INITS 3 - dstImage		
		VkImage arg_3 = dstImage->mHandle;
		// INITS 4 - dstImageLayout		
		VkImageLayout arg_4 = (VkImageLayout)dstImageLayout;
		// INITS 5 - regionCount		
		uint32_t arg_5 = 0;
		// INITS 6 - pRegions	
		if (pRegions != nullptr)
		{
			arg_5 = pRegions->Length;
			if (arg_5 > 0)
			{
				arg_6 = new VkImageCopy[arg_5];
				for (UInt32 i = 0; i < arg_5; ++i)
				{
					auto srcImgCopy = pRegions[i];
					srcImgCopy->CopyTo(arg_6 + i, pins);
				}
			}
		}

		vkCmdCopyImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6);


	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdBlitImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::ImageBlit^>^ pRegions, ManagedVulkan::Filter filter)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageBlit* arg_6 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = (VkImageLayout) srcImageLayout;
		// INITS 3 - dstImage		
		VkImage arg_3 = dstImage->mHandle;
		// INITS 4 - dstImageLayout		
		VkImageLayout arg_4 = (VkImageLayout) dstImageLayout;
		// INITS 5 - regionCount		
		uint32_t arg_5 = 0;
		// INITS 6 - pRegions		
		if (pRegions != nullptr)
		{
			arg_5 = pRegions->Length;
			if (arg_5 > 0)
			{
				arg_6 = new VkImageBlit[arg_5];
				for (UInt32 i = 0; i < arg_5; ++i)
				{
					auto srcBlit = pRegions[i];
					srcBlit->CopyTo(arg_6 + i, pins);
				}
			}
		}

		// INITS 7 - filter		
		VkFilter arg_7 = (VkFilter) filter;

		vkCmdBlitImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdCopyBufferToImage(ManagedVulkan::Buffer^ srcBuffer, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::BufferImageCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBufferImageCopy* arg_5 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcBuffer		
		VkBuffer arg_1 = srcBuffer->mHandle;
		// INITS 2 - dstImage		
		VkImage arg_2 = dstImage->mHandle;
		// INITS 3 - dstImageLayout		
		VkImageLayout arg_3 = (VkImageLayout) dstImageLayout;
		// INITS 4 - regionCount		
		uint32_t arg_4 = 0;
		// INITS 5 - pRegions		
		if (pRegions != nullptr)
		{
			arg_4 = pRegions->Length;
			if (arg_4 > 0)
			{
				arg_5 = new VkBufferImageCopy[arg_4];
				for (UInt32 i = 0; i < arg_4; ++i)
				{
					auto srcCopy = pRegions[i];
					srcCopy->CopyTo(arg_5 + i, pins);
				}
			}
		}

		vkCmdCopyBufferToImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


	}
	finally
	{
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

void ManagedVulkan::CommandBuffer::CmdCopyImageToBuffer(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Buffer^ dstBuffer, array<ManagedVulkan::BufferImageCopy^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkBufferImageCopy* arg_5 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = (VkImageLayout) srcImageLayout;
		// INITS 3 - dstBuffer		
		VkBuffer arg_3 = dstBuffer->mHandle;
		// INITS 4 - regionCount		
		uint32_t arg_4 = 0;
		// INITS 5 - pRegions		
		if (pRegions != nullptr)
		{
			arg_4 = pRegions->Length;
			if (arg_4 > 0)
			{
				arg_5 = new VkBufferImageCopy[arg_4];
				for (UInt32 i = 0; i < arg_4; ++i)
				{
					auto srcCopy = pRegions[i];
					srcCopy->CopyTo(arg_5 + i, pins);
				}
			}
		}

		vkCmdCopyImageToBuffer(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


	}
	finally
	{
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

void ManagedVulkan::CommandBuffer::CmdUpdateBuffer(ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 dataSize, IntPtr^ pData)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - dstBuffer		
		VkBuffer arg_1 = dstBuffer->mHandle;
		// INITS 2 - dstOffset		
		VkDeviceSize arg_2 = dstOffset;
		// INITS 3 - dataSize		
		VkDeviceSize arg_3 = dataSize;
		// INITS 4 - pData		
		uint32_t* arg_4 = (uint32_t*) pData->ToPointer();

		vkCmdUpdateBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);


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


void ManagedVulkan::CommandBuffer::CmdFillBuffer(ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 size, UInt32 data)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - dstBuffer		
		VkBuffer arg_1 = dstBuffer->mHandle;
		// INITS 2 - dstOffset		
		VkDeviceSize arg_2 = dstOffset;
		// INITS 3 - size		
		VkDeviceSize arg_3 = size;
		// INITS 4 - data		
		uint32_t arg_4 = data;

		vkCmdFillBuffer(arg_0, arg_1, arg_2, arg_3, arg_4);


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

void ManagedVulkan::CommandBuffer::CmdClearColorImage(ManagedVulkan::Image^ image, ManagedVulkan::ImageLayout imageLayout, ManagedVulkan::ClearColorValue^ pColor, array<ManagedVulkan::ImageSubresourceRange^>^ pRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageSubresourceRange* arg_5 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;
		// INITS 2 - imageLayout		
		VkImageLayout arg_2 = (VkImageLayout) imageLayout;
		// INITS 3 - pColor		
		VkClearColorValue inst_3;
		VkClearColorValue* arg_3 = &inst_3;
		if (pColor != nullptr)
		{
			arg_3 = &inst_3;
			pColor->CopyTo(arg_3);
		}
		// INITS 4 - rangeCount		
		uint32_t arg_4 = 0;
		// INITS 5 - pRanges		
		if (pRanges != nullptr)
		{
			arg_4 = pRanges->Length;
			if (arg_4 > 0)
			{
				arg_5 = new VkImageSubresourceRange[arg_4];
				for (UInt32 i = 0; i < arg_4; ++i)
				{
					auto srcCopy = pRanges[i];
					srcCopy->CopyTo(arg_5 + i, pins);
				}
			}
		}

		vkCmdClearColorImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);
	}
	finally
	{
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

void ManagedVulkan::CommandBuffer::CmdClearDepthStencilImage(ManagedVulkan::Image^ image, ManagedVulkan::ImageLayout imageLayout, ManagedVulkan::ClearDepthStencilValue^ pDepthStencil, array<ManagedVulkan::ImageSubresourceRange^>^ pRanges)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageSubresourceRange* arg_5 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - image		
		VkImage arg_1 = image->mHandle;
		// INITS 2 - imageLayout		
		VkImageLayout arg_2 = (VkImageLayout) imageLayout;
		// INITS 3 - pDepthStencil		
		VkClearDepthStencilValue inst_3;
		VkClearDepthStencilValue* arg_3 = &inst_3;
		if (pDepthStencil != nullptr)
		{			
			pDepthStencil->CopyTo(arg_3);
		}

		// INITS 4 - rangeCount		
		uint32_t arg_4 = 0;
		// INITS 5 - pRanges		
		if (pRanges != nullptr)
		{
			arg_4 = pRanges->Length;
			if (arg_4 > 0)
			{
				arg_5 = new VkImageSubresourceRange[arg_4];
				for (UInt32 i = 0; i < arg_4; ++i)
				{
					auto srcCopy = pRanges[i];
					srcCopy->CopyTo(arg_5 + i, pins);
				}
			}
		}

		vkCmdClearDepthStencilImage(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


	}
	finally
	{
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

void ManagedVulkan::CommandBuffer::CmdClearAttachments(array<ManagedVulkan::ClearAttachment^>^ pAttachments, array<ManagedVulkan::ClearRect^>^ pRects)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkClearAttachment* arg_2 = nullptr;
	VkClearRect* arg_4 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - attachmentCount		
		uint32_t attachmentCount = 0;
		// INITS 2 - pAttachments	
		if (pAttachments != nullptr)
		{
			attachmentCount = pAttachments->Length;
			if (attachmentCount > 0)
			{
				arg_2 = new VkClearAttachment[attachmentCount];
				for (UInt32 i = 0; i < attachmentCount; ++i)
				{
					auto srcAttachment = pAttachments[i];
					srcAttachment->CopyTo(arg_2 + i, pins);
				}
			}
		}

		// INITS 3 - rectCount		
		uint32_t rectCount = 0;
		// INITS 4 - pRects		
		if (pRects != nullptr)
		{
			rectCount = pRects->Length;
			if (rectCount > 0)
			{
				arg_4 = new VkClearRect[rectCount];
				for (UInt32 i = 0; i < rectCount; ++i)
				{
					auto srcRect = pRects[i];
					srcRect->CopyTo(arg_4 + i, pins);
				}
			}
		}

		vkCmdClearAttachments(arg_0, attachmentCount, arg_2, rectCount, arg_4);
	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
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

void ManagedVulkan::CommandBuffer::CmdResolveImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::ImageResolve^>^ pRegions)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkImageResolve* arg_6 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcImage		
		VkImage arg_1 = srcImage->mHandle;
		// INITS 2 - srcImageLayout		
		VkImageLayout arg_2 = (VkImageLayout)srcImageLayout;
		// INITS 3 - dstImage		
		VkImage arg_3 = dstImage->mHandle;
		// INITS 4 - dstImageLayout		
		VkImageLayout arg_4 = (VkImageLayout)dstImageLayout;
		// INITS 5 - regionCount		
		uint32_t regionCount = 0;
		// INITS 6 - pRegions	
		if (pRegions != nullptr)
		{
			regionCount = pRegions->Length;
			if (regionCount > 0)
			{
				arg_6 = new VkImageResolve[regionCount];
				for (UInt32 i = 0; i < regionCount; ++i)
				{
					auto srcImgResolve = pRegions[i];
					srcImgResolve->CopyTo(arg_6 + i, pins);
				}
			}
		}

		vkCmdResolveImage(arg_0, arg_1, arg_2, arg_3, arg_4, regionCount, arg_6);


	}
	finally
	{
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdSetEvent(ManagedVulkan::Event^ event, ManagedVulkan::PipelineStageFlagBits stageMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;
		// INITS 2 - stageMask		
		VkPipelineStageFlags arg_2 = (VkPipelineStageFlags) stageMask;

		vkCmdSetEvent(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdResetEvent(ManagedVulkan::Event^ event, ManagedVulkan::PipelineStageFlagBits stageMask)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - event		
		VkEvent arg_1 = event->mHandle;
		// INITS 2 - stageMask		
		VkPipelineStageFlags arg_2 = (VkPipelineStageFlags) stageMask;

		vkCmdResetEvent(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdWaitEvents(array<ManagedVulkan::Event^>^ pEvents, ManagedVulkan::PipelineStageFlagBits srcStageMask, ManagedVulkan::PipelineStageFlagBits dstStageMask, array<ManagedVulkan::MvMemoryBarrier^>^ pMemoryBarriers, array<ManagedVulkan::BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ManagedVulkan::ImageMemoryBarrier^>^ pImageMemoryBarriers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkEvent* arg_2 = nullptr;
	VkMemoryBarrier* arg_6 = nullptr;
	VkBufferMemoryBarrier* arg_8 = nullptr;
	VkImageMemoryBarrier* arg_10 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - eventCount	
		UInt32 arg_1 = 0;
		{
			uint32_t eventCount = 0;
			// INITS 2 - pEvents		
			if (pEvents != nullptr)
			{
				eventCount = pEvents->Length;
				if (eventCount > 0)
				{
					arg_2 = new VkEvent[eventCount];
					for (UInt32 i = 0; i < eventCount; ++i)
					{
						auto srcEvent = pEvents[i];
						arg_2[i] = srcEvent->mHandle;
					}
				}
			}
			arg_1 = eventCount;
		}

		// INITS 3 - srcStageMask		
		VkPipelineStageFlags arg_3 = (VkPipelineStageFlags)srcStageMask;
		// INITS 4 - dstStageMask		
		VkPipelineStageFlags arg_4 = (VkPipelineStageFlags)dstStageMask;
		// INITS 5 - memoryBarrierCount		
		UInt32 arg_5 = 0;
		{
			uint32_t memoryBarrierCount = 0;
			// INITS 6 - pMemoryBarriers		
			if (pMemoryBarriers != nullptr)
			{
				memoryBarrierCount = pMemoryBarriers->Length;
				if (memoryBarrierCount > 0)
				{
					arg_6 = new VkMemoryBarrier[memoryBarrierCount];
					for (UInt32 i = 0; i < memoryBarrierCount; ++i)
					{
						auto srcBarrier = pMemoryBarriers[i];
						srcBarrier->CopyTo(arg_6 + i, pins);
					}
				}
			}
			arg_5 = memoryBarrierCount;
		}

		// INITS 7 - bufferMemoryBarrierCount
		UInt32 arg_7 = 0;
		{	
			uint32_t bufferMemoryBarrierCount = 0;
			// INITS 8 - pBufferMemoryBarriers
			if (pBufferMemoryBarriers != nullptr)
			{
				bufferMemoryBarrierCount = pBufferMemoryBarriers->Length;
				if (bufferMemoryBarrierCount > 0)
				{
					arg_8 = new VkBufferMemoryBarrier[bufferMemoryBarrierCount];
					for (UInt32 i = 0; i < bufferMemoryBarrierCount; ++i)
					{
						auto srcBarrier = pBufferMemoryBarriers[i];
						srcBarrier->CopyTo(arg_8 + i, pins);
					}
				}
			}
			arg_7 = bufferMemoryBarrierCount;
		}

		// INITS 9 - imageMemoryBarrierCount
		UInt32 arg_9 = 0;
		{
			uint32_t imageMemoryBarrierCount = 0;
			// INITS 10 - pImageMemoryBarriers
			if (pImageMemoryBarriers != nullptr)
			{
				imageMemoryBarrierCount = pImageMemoryBarriers->Length;
				if (imageMemoryBarrierCount > 0)
				{
					arg_10 = new VkImageMemoryBarrier[imageMemoryBarrierCount];
					for (UInt32 i = 0; i < imageMemoryBarrierCount; ++i)
					{
						auto srcBarrier = pImageMemoryBarriers[i];
						srcBarrier->CopyTo(arg_10 + i, pins);
					}
				}
			}
			arg_9 = imageMemoryBarrierCount;
		}

		vkCmdWaitEvents(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7, arg_8, arg_9, arg_10);


	}
	finally
	{
		if (arg_2 != nullptr)
		{
			delete[] arg_2;
		}
		if (arg_6 != nullptr)
		{
			delete[] arg_6;
		}
		if (arg_8 != nullptr)
		{
			delete[] arg_8;
		}
		if (arg_10 != nullptr)
		{
			delete[] arg_10;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


void ManagedVulkan::CommandBuffer::CmdPipelineBarrier(ManagedVulkan::PipelineStageFlagBits srcStageMask, ManagedVulkan::PipelineStageFlagBits dstStageMask, ManagedVulkan::DependencyFlagBits dependencyFlags, array<ManagedVulkan::MvMemoryBarrier^>^ pMemoryBarriers, array<ManagedVulkan::BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ManagedVulkan::ImageMemoryBarrier^>^ pImageMemoryBarriers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkMemoryBarrier* arg_5 = nullptr;
	VkBufferMemoryBarrier* arg_7 = nullptr;
	VkImageMemoryBarrier* arg_9 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - srcStageMask		
		VkPipelineStageFlags arg_1 = (VkPipelineStageFlags) srcStageMask;
		// INITS 2 - dstStageMask		
		VkPipelineStageFlags arg_2 = (VkPipelineStageFlags) dstStageMask;
		// INITS 3 - dependencyFlags		
		VkDependencyFlags arg_3 = (VkDependencyFlags) dependencyFlags;
		// INITS 4 - memoryBarrierCount		
		uint32_t arg_4 = 0;
		{
			uint32_t memoryBarrierCount = 0;
			if (pMemoryBarriers != nullptr)
			{
				memoryBarrierCount = pMemoryBarriers->Length;
				if (memoryBarrierCount > 0)
				{
					// INITS 5 - pMemoryBarriers		
					arg_5 = new VkMemoryBarrier[memoryBarrierCount];
					for (UInt32 i = 0; i < memoryBarrierCount; ++i)
					{
						auto srcBarrier = pMemoryBarriers[i];
						srcBarrier->CopyTo(arg_5, pins);
					}
				}

			}
			arg_4 = memoryBarrierCount;
		}
		// INITS 6 - bufferMemoryBarrierCount		
		uint32_t arg_6 = 0;
		{
			uint32_t bufferMemoryBarrierCount = 0;
			if (pBufferMemoryBarriers != nullptr)
			{
				bufferMemoryBarrierCount = pBufferMemoryBarriers->Length;
				if (bufferMemoryBarrierCount > 0)
				{
					// INITS 7 - pBufferMemoryBarriers		
					arg_7 = new VkBufferMemoryBarrier[bufferMemoryBarrierCount];
					for (UInt32 i = 0; i < bufferMemoryBarrierCount; ++i)
					{
						auto srcBarrier = pBufferMemoryBarriers[i];
						srcBarrier->CopyTo(arg_7, pins);
					}
				}
			}
			arg_6 = bufferMemoryBarrierCount;
		}

		// INITS 8 - imageMemoryBarrierCount		
		uint32_t arg_8 = 0;
		{
			uint32_t imageMemoryBarrierCount = 0;
			if (pImageMemoryBarriers != nullptr)
			{
				imageMemoryBarrierCount = pImageMemoryBarriers->Length;
				if (imageMemoryBarrierCount > 0)
				{
					// INITS 9 - pImageMemoryBarriers		
					arg_9 = new VkImageMemoryBarrier[imageMemoryBarrierCount];
					for (UInt32 i = 0; i < imageMemoryBarrierCount; ++i)
					{
						auto srcBarrier = pImageMemoryBarriers[i];
						srcBarrier->CopyTo(arg_9 + i, pins);
					}
				}
			}
			arg_8 = imageMemoryBarrierCount;
		}

		vkCmdPipelineBarrier(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7, arg_8, arg_9);


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
		if (arg_9 != nullptr)
		{
			delete[] arg_9;
		}
		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}


void ManagedVulkan::CommandBuffer::CmdBeginQuery(ManagedVulkan::QueryPool^ queryPool, UInt32 query, ManagedVulkan::QueryControlFlagBits flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;
		// INITS 2 - query		
		uint32_t arg_2 = query;
		// INITS 3 - flags		
		VkQueryControlFlags arg_3 = (VkQueryControlFlags) flags;

		vkCmdBeginQuery(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdEndQuery(ManagedVulkan::QueryPool^ queryPool, UInt32 query)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;
		// INITS 2 - query		
		uint32_t arg_2 = query;

		vkCmdEndQuery(arg_0, arg_1, arg_2);


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

void ManagedVulkan::CommandBuffer::CmdResetQueryPool(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;
		// INITS 2 - firstQuery		
		uint32_t arg_2 = firstQuery;
		// INITS 3 - queryCount		
		uint32_t arg_3 = queryCount;

		vkCmdResetQueryPool(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdWriteTimestamp(ManagedVulkan::PipelineStageFlagBits pipelineStage, ManagedVulkan::QueryPool^ queryPool, UInt32 query)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - pipelineStage		
		VkPipelineStageFlagBits arg_1 = (VkPipelineStageFlagBits) pipelineStage;
		// INITS 2 - queryPool		
		VkQueryPool arg_2 = queryPool->mHandle;
		// INITS 3 - query		
		uint32_t arg_3 = query;

		vkCmdWriteTimestamp(arg_0, arg_1, arg_2, arg_3);


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

void ManagedVulkan::CommandBuffer::CmdCopyQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 stride, UInt32 flags)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - queryPool		
		VkQueryPool arg_1 = queryPool->mHandle;
		// INITS 2 - firstQuery		
		uint32_t arg_2 = firstQuery;
		// INITS 3 - queryCount		
		uint32_t arg_3 = queryCount;
		// INITS 4 - dstBuffer		
		VkBuffer arg_4 = dstBuffer->mHandle;
		// INITS 5 - dstOffset		
		VkDeviceSize arg_5 = dstOffset;
		// INITS 6 - stride		
		VkDeviceSize arg_6 = stride;
		// INITS 7 - flags		
		VkQueryResultFlags arg_7 = flags;

		vkCmdCopyQueryPoolResults(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5, arg_6, arg_7);


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

void ManagedVulkan::CommandBuffer::CmdPushConstants(ManagedVulkan::PipelineLayout^ layout, UInt32 stageFlags, UInt32 offset, UInt32 size, IntPtr^ pValues)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - layout		
		VkPipelineLayout arg_1 = layout->mHandle;
		// INITS 2 - stageFlags		
		VkShaderStageFlags arg_2 = stageFlags;
		// INITS 3 - offset		
		uint32_t arg_3 = offset;
		// INITS 4 - size		
		uint32_t arg_4 = size;
		// INITS 5 - pValues		
		void* arg_5 = pValues->ToPointer();

		vkCmdPushConstants(arg_0, arg_1, arg_2, arg_3, arg_4, arg_5);


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

void ManagedVulkan::CommandBuffer::CmdBeginRenderPass(ManagedVulkan::RenderPassBeginInfo^ pRenderPassBegin, ManagedVulkan::SubpassContents contents)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkClearValue* arg_1_6 = nullptr;

	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - pRenderPassBegin		
		VkRenderPassBeginInfo inst_1;
		VkRenderPassBeginInfo* arg_1 = nullptr;
		if (pRenderPassBegin != nullptr)
		{
			arg_1 = &inst_1;
			pRenderPassBegin->CopyTo(arg_1, pins);
			UInt32 noOfClearValues = 0;
			if (pRenderPassBegin->ClearValues != nullptr)
			{
				noOfClearValues = pRenderPassBegin->ClearValues->Length;
				if (noOfClearValues > 0)
				{
					arg_1_6 = new VkClearValue[noOfClearValues];
					for (UInt32 i = 0; i < noOfClearValues; ++i)
					{
						auto srcValue = (ManagedVulkan::ClearValue^) pRenderPassBegin->ClearValues[i];
						srcValue->CopyTo(arg_1_6 + i);
					}
				}

			}
			arg_1->pClearValues = arg_1_6;
			arg_1->clearValueCount = noOfClearValues;
		}


		// INITS 2 - contents		
		VkSubpassContents arg_2 = (VkSubpassContents) contents;

		vkCmdBeginRenderPass(arg_0, arg_1, arg_2);


	}
	finally
	{
		if (arg_1_6 != nullptr)
		{
			delete[] arg_1_6;
		}

		// FREE ALL PINNED STRINGS
		for each(auto str in pins)
		{
			Marshal::FreeHGlobal(str);
		}
	}
}

void ManagedVulkan::CommandBuffer::CmdNextSubpass(ManagedVulkan::SubpassContents contents)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - contents		
		VkSubpassContents arg_1 = (VkSubpassContents) contents;

		vkCmdNextSubpass(arg_0, arg_1);


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


void ManagedVulkan::CommandBuffer::CmdEndRenderPass()
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;

		vkCmdEndRenderPass(arg_0);


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

void ManagedVulkan::CommandBuffer::CmdExecuteCommands(array<ManagedVulkan::CommandBuffer^>^ pCommandBuffers)
{
	List<IntPtr>^ pins = gcnew List<IntPtr>();
	VkCommandBuffer* arg_2 = nullptr;
	try
	{
		// MAIN INIT

		// INITS 0 - commandBuffer		
		VkCommandBuffer arg_0 = this->mHandle;
		// INITS 1 - commandBufferCount		
		uint32_t arg_1 = 0;
		{
			uint32_t commandBufferCount = 0;
			if (pCommandBuffers != nullptr)
			{
				commandBufferCount = pCommandBuffers->Length;
				if (commandBufferCount > 0)
				{
					// INITS 2 - pCommandBuffers		
					arg_2 = new VkCommandBuffer[commandBufferCount];
					for (UInt32 i = 0; i < commandBufferCount; ++i)
					{
						auto srcBuffer = pCommandBuffers[i];
						arg_2[i] = srcBuffer->mHandle;
					}
				}
			}

			arg_1 = commandBufferCount;
		}

		vkCmdExecuteCommands(arg_0, arg_1, arg_2);


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