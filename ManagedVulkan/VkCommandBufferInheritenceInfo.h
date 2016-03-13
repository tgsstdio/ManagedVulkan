#pragma once

#include <vulkan\vulkan.h>

#include "VkEnums.h"
#include "VkHandles.h"

using namespace System::Collections::Generic;

namespace ManagedVulkan
{

	public ref class CommandBufferInheritanceInfo
	{
	private:
		ManagedVulkan::StructureType mSType;
		ManagedVulkan::RenderPass^ mRenderPass = gcnew ManagedVulkan::RenderPass();
		UInt32 mSubpass = 0;
		ManagedVulkan::Framebuffer^ mFramebuffer = gcnew ManagedVulkan::Framebuffer();
		bool mOcclusionQueryEnable = false;
		ManagedVulkan::QueryControlFlagBits mQueryFlags;
		UInt32 mPipelineStatistics;
	public:
		property ManagedVulkan::StructureType SType
		{
			ManagedVulkan::StructureType get()
			{
				return mSType;
			}
			void set(ManagedVulkan::StructureType value)
			{
				mSType = value;
			}
		}
		property ManagedVulkan::RenderPass^ RenderPass
		{
			ManagedVulkan::RenderPass^ get()
			{
				return mRenderPass;
			}
			void set(ManagedVulkan::RenderPass^ value)
			{
				mRenderPass = value;
			}
		}
		property UInt32 Subpass
		{
			UInt32 get()
			{
				return mSubpass;
			}
			void set(UInt32 value)
			{
				mSubpass = value;
			}
		}
		property ManagedVulkan::Framebuffer^ Framebuffer
		{
			ManagedVulkan::Framebuffer^ get()
			{
				return mFramebuffer;
			}
			void set(ManagedVulkan::Framebuffer^ value)
			{
				mFramebuffer = value;
			}
		}
		property bool OcclusionQueryEnable
		{
			bool get()
			{
				return mOcclusionQueryEnable;
			}
			void set(bool value)
			{
				mOcclusionQueryEnable = value;
			}
		}
		property ManagedVulkan::QueryControlFlagBits QueryFlags
		{
			ManagedVulkan::QueryControlFlagBits get()
			{
				return mQueryFlags;
			}
			void set(ManagedVulkan::QueryControlFlagBits value)
			{
				mQueryFlags = value;
			}
		}
		property UInt32 PipelineStatistics
		{
			UInt32 get()
			{
				return mPipelineStatistics;
			}
			void set(UInt32 value)
			{
				mPipelineStatistics = value;
			}
		}
	internal:
		void CopyTo(VkCommandBufferInheritanceInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType)mSType;
			dst->pNext = nullptr;
			dst->renderPass = mRenderPass->mHandle;
			dst->subpass = mSubpass;
			dst->framebuffer = mFramebuffer->mHandle;
			dst->occlusionQueryEnable = mOcclusionQueryEnable ? 1 : 0;
			dst->queryFlags = (VkQueryControlFlagBits)mQueryFlags;
			dst->pipelineStatistics = mPipelineStatistics;
		}

		void CopyFrom(VkCommandBufferInheritanceInfo* src)
		{
			mSType = (ManagedVulkan::StructureType) src->sType;

			mRenderPass->mHandle = src->renderPass;
			mSubpass = src->subpass;
			mFramebuffer->mHandle = src->framebuffer;
			mOcclusionQueryEnable = src->occlusionQueryEnable != 0;
			mQueryFlags = (ManagedVulkan::QueryControlFlagBits) src->queryFlags;
			mPipelineStatistics = src->pipelineStatistics;
		}
	};
}