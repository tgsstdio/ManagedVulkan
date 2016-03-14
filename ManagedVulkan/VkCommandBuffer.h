#pragma once

#include <vulkan\vulkan.h>
#include <vulkan\vk_sdk_platform.h>

#include "VkHandles.h"
#include "VkEnums.h"
#include "VkDelegates.h"
#include "VkCommandBufferBeginInfo.h"
#include "VkViewport.h"
#include "VkRect2D.h"
#include "VkVec4f.h"
#include "VkBufferCopy.h"
#include "VkImageCopy.h"
#include "VkImageBlit.h"
#include "VkBufferImageCopy.h"
#include "VkImageSubresourceRange.h"
#include "VkClearColorValue.h"
#include "VkClearDepthStencilValue.h"
#include "VkClearAttachment.h"
#include "VkClearRect.h"
#include "VkImageResolve.h"
#include "VkBufferMemoryBarrier.h"
#include "VkMemoryBarrier.h"
#include "VkImageMemoryBarrier.h"
#include "VkRenderPassBeginInfo.h"

using namespace System;

namespace ManagedVulkan
{
	public ref class CommandBuffer
	{
	internal:
		VkCommandBuffer mHandle;
	public:
		ManagedVulkan::Result BeginCommandBuffer(ManagedVulkan::CommandBufferBeginInfo^ pBeginInfo);
		ManagedVulkan::Result EndCommandBuffer();
		ManagedVulkan::Result ResetCommandBuffer(CommandBufferResetFlagBits flags);
		void CmdBindPipeline(ManagedVulkan::PipelineBindPoint pipelineBindPoint, ManagedVulkan::Pipeline^ pipeline);
		void CmdSetViewport(UInt32 firstViewport, UInt32 viewportCount, array<ManagedVulkan::Viewport^>^ pViewports);
		void CmdSetScissor(UInt32 firstScissor, UInt32 scissorCount, array<ManagedVulkan::Rect2D^>^ pScissors);
		void CmdSetLineWidth(float lineWidth);
		void CmdSetDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor);
		void CmdSetBlendConstants(ManagedVulkan::Vec4f^ blendConstants);
		void CmdSetDepthBounds(float minDepthBounds, float maxDepthBounds);
		void CmdSetStencilCompareMask(ManagedVulkan::StencilFaceFlagBits faceMask, UInt32 compareMask);
		void CmdSetStencilWriteMask(ManagedVulkan::StencilFaceFlagBits faceMask, UInt32 writeMask);
		void CmdSetStencilReference(ManagedVulkan::StencilFaceFlagBits faceMask, UInt32 reference);
		void CmdBindDescriptorSets(ManagedVulkan::PipelineBindPoint pipelineBindPoint, ManagedVulkan::PipelineLayout^ layout, UInt32 firstSet, UInt32 descriptorSetCount, array<ManagedVulkan::DescriptorSet^>^ pDescriptorSets, array<UInt32>^ pDynamicOffsets);
		void CmdBindIndexBuffer(ManagedVulkan::Buffer^ buffer, UInt64 offset, ManagedVulkan::IndexType indexType);
		void CmdBindVertexBuffers(UInt32 firstBinding, UInt32 bindingCount, array<ManagedVulkan::Buffer^>^ pBuffers, array<UInt64>^ pOffsets);
		void CmdDraw(UInt32 vertexCount, UInt32 instanceCount, UInt32 firstVertex, UInt32 firstInstance);
		void CmdDrawIndexed(UInt32 indexCount, UInt32 instanceCount, UInt32 firstIndex, Int32 vertexOffset, UInt32 firstInstance);
		void CmdDrawIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride);
		void CmdDrawIndexedIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset, UInt32 drawCount, UInt32 stride);
		void CmdDispatch(UInt32 x, UInt32 y, UInt32 z);
		void CmdDispatchIndirect(ManagedVulkan::Buffer^ buffer, UInt64 offset);
		void CmdCopyBuffer(ManagedVulkan::Buffer^ srcBuffer, ManagedVulkan::Buffer^ dstBuffer, array<ManagedVulkan::BufferCopy^>^ pRegions);
		void CmdCopyImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::ImageCopy^>^ pRegions);
		void CmdBlitImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::ImageBlit^>^ pRegions, ManagedVulkan::Filter filter);
		void CmdCopyBufferToImage(ManagedVulkan::Buffer^ srcBuffer, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::BufferImageCopy^>^ pRegions);
		void CmdCopyImageToBuffer(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Buffer^ dstBuffer, array<ManagedVulkan::BufferImageCopy^>^ pRegions);
		void CmdUpdateBuffer(ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 dataSize, IntPtr^ pData);
		void CmdFillBuffer(ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 size, UInt32 data);
		void CmdClearColorImage(ManagedVulkan::Image^ image, ManagedVulkan::ImageLayout imageLayout, ManagedVulkan::ClearColorValue^ pColor, array<ManagedVulkan::ImageSubresourceRange^>^ pRanges);
		void CmdClearDepthStencilImage(ManagedVulkan::Image^ image, ManagedVulkan::ImageLayout imageLayout, ManagedVulkan::ClearDepthStencilValue^ pDepthStencil, array<ManagedVulkan::ImageSubresourceRange^>^ pRanges);
		void CmdClearAttachments(array<ManagedVulkan::ClearAttachment^>^ pAttachments, array<ManagedVulkan::ClearRect^>^ pRects);
		void CmdResolveImage(ManagedVulkan::Image^ srcImage, ManagedVulkan::ImageLayout srcImageLayout, ManagedVulkan::Image^ dstImage, ManagedVulkan::ImageLayout dstImageLayout, array<ManagedVulkan::ImageResolve^>^ pRegions);
		void CmdSetEvent(ManagedVulkan::Event^ event, ManagedVulkan::PipelineStageFlagBits stageMask);
		void CmdResetEvent(ManagedVulkan::Event^ event, ManagedVulkan::PipelineStageFlagBits stageMask);
		void CmdWaitEvents(array<ManagedVulkan::Event^>^ pEvents, ManagedVulkan::PipelineStageFlagBits srcStageMask, ManagedVulkan::PipelineStageFlagBits dstStageMask, array<ManagedVulkan::MemoryBarrier^>^ pMemoryBarriers, array<ManagedVulkan::BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ManagedVulkan::ImageMemoryBarrier^>^ pImageMemoryBarriers);
		void CmdPipelineBarrier(ManagedVulkan::PipelineStageFlagBits srcStageMask, ManagedVulkan::PipelineStageFlagBits dstStageMask, ManagedVulkan::DependencyFlagBits dependencyFlags, array<ManagedVulkan::MemoryBarrier^>^ pMemoryBarriers, array<ManagedVulkan::BufferMemoryBarrier^>^ pBufferMemoryBarriers, array<ManagedVulkan::ImageMemoryBarrier^>^ pImageMemoryBarriers);
		void CmdBeginQuery(ManagedVulkan::QueryPool^ queryPool, UInt32 query, ManagedVulkan::QueryControlFlagBits flags);
		void CmdEndQuery(ManagedVulkan::QueryPool^ queryPool, UInt32 query);
		void CmdResetQueryPool(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount);
		void CmdWriteTimestamp(ManagedVulkan::PipelineStageFlagBits pipelineStage, ManagedVulkan::QueryPool^ queryPool, UInt32 query);
		void CmdCopyQueryPoolResults(ManagedVulkan::QueryPool^ queryPool, UInt32 firstQuery, UInt32 queryCount, ManagedVulkan::Buffer^ dstBuffer, UInt64 dstOffset, UInt64 stride, UInt32 flags);
		void CmdPushConstants(ManagedVulkan::PipelineLayout^ layout, UInt32 stageFlags, UInt32 offset, UInt32 size, IntPtr^ pValues);
		void CmdBeginRenderPass(ManagedVulkan::RenderPassBeginInfo^ pRenderPassBegin, ManagedVulkan::SubpassContents contents);
		void CmdNextSubpass(ManagedVulkan::SubpassContents contents);
		void CmdEndRenderPass();
		void CmdExecuteCommands(array<ManagedVulkan::CommandBuffer^>^ pCommandBuffers);
	};
}