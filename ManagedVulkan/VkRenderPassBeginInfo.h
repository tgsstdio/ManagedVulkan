#pragma once

#include <vulkan\vulkan.h>

#include "VkEnums.h"
#include "VkHandles.h"
#include "VkRect2D.h"
#include "VkClearValue.h"

namespace ManagedVulkan
{

	public ref class RenderPassBeginInfo
	{
	private:
		ManagedVulkan::StructureType mSType;
		ManagedVulkan::RenderPass^ mRenderPass = gcnew ManagedVulkan::RenderPass();
		ManagedVulkan::Framebuffer^ mFramebuffer = gcnew ManagedVulkan::Framebuffer();
		ManagedVulkan::Rect2D^ mRenderArea = gcnew ManagedVulkan::Rect2D();
		array<ManagedVulkan::ClearValue^>^ mClearValues = nullptr;
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
		property ManagedVulkan::Rect2D^ RenderArea
		{
			ManagedVulkan::Rect2D^ get()
			{
				return mRenderArea;
			}
			void set(ManagedVulkan::Rect2D^ value)
			{
				mRenderArea = value;
			}
		}
		property array<ManagedVulkan::ClearValue^>^ ClearValues
		{
			array<ManagedVulkan::ClearValue^>^ get()
			{
				return mClearValues;
			}
			void set(array<ManagedVulkan::ClearValue^>^ value)
			{
				mClearValues = value;
			}
		}
	internal:
		void CopyTo(VkRenderPassBeginInfo* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->renderPass = mRenderPass->mHandle;
			dst->framebuffer = mFramebuffer->mHandle;
			mRenderArea->CopyTo(&dst->renderArea, pins);
			//dst->clearValueCount = mClearValueCount;
			//mClearValues->CopyTo(&dst->pClearValues, pins);
		}

		void CopyFrom(VkRenderPassBeginInfo* src)
		{
			mSType = (StructureType)src->sType;

			mRenderPass->mHandle = src->renderPass;
			mFramebuffer->mHandle = src->framebuffer;
			mRenderArea->CopyFrom(&src->renderArea);
			//mClearValueCount = src->clearValueCount;
			//mClearValues->CopyFrom(&src->pClearValues);
		}
	};

}