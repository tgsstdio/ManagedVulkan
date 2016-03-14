#pragma once

#include <vulkan/vulkan.h>
#include "VkImageSubresourceLayers.h"
#include "VkOffset3D.h"
#include "VkExtent3D.h"

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class ImageResolve
	{
	private:
		ManagedVulkan::ImageSubresourceLayers^ mSrcSubresource = gcnew ManagedVulkan::ImageSubresourceLayers();
		ManagedVulkan::Offset3D^ mSrcOffset = gcnew ManagedVulkan::Offset3D();
		ManagedVulkan::ImageSubresourceLayers^ mDstSubresource = gcnew ManagedVulkan::ImageSubresourceLayers();
		ManagedVulkan::Offset3D^ mDstOffset = gcnew ManagedVulkan::Offset3D();
		ManagedVulkan::Extent3D^ mExtent = gcnew ManagedVulkan::Extent3D();
	public:
		property ManagedVulkan::ImageSubresourceLayers^ SrcSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mSrcSubresource = value;
			}
		}
		property ManagedVulkan::Offset3D^ SrcOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mSrcOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mSrcOffset = value;
			}
		}
		property ManagedVulkan::ImageSubresourceLayers^ DstSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mDstSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mDstSubresource = value;
			}
		}
		property ManagedVulkan::Offset3D^ DstOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mDstOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mDstOffset = value;
			}
		}
		property ManagedVulkan::Extent3D^ Extent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mExtent = value;
			}
		}
	internal:
		void CopyTo(VkImageResolve* dst, List<IntPtr>^ pins)
		{
			mSrcSubresource->CopyTo(&dst->srcSubresource, pins);
			mSrcOffset->CopyTo(&dst->srcOffset, pins);
			mDstSubresource->CopyTo(&dst->dstSubresource, pins);
			mDstOffset->CopyTo(&dst->dstOffset, pins);
			mExtent->CopyTo(&dst->extent, pins);
		}

		void CopyFrom(VkImageResolve* src)
		{
			mSrcSubresource->CopyFrom(&src->srcSubresource);
			mSrcOffset->CopyFrom(&src->srcOffset);
			mDstSubresource->CopyFrom(&src->dstSubresource);
			mDstOffset->CopyFrom(&src->dstOffset);
			mExtent->CopyFrom(&src->extent);
		}
	};
}