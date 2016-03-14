#pragma once

#pragma once

#include <vulkan/vulkan.h>

#include "VkOffset3D.h"
#include "VkImageSubresourceLayers.h"

namespace ManagedVulkan
{
	public ref class ImageBlit
	{
	private:
		ManagedVulkan::ImageSubresourceLayers^ mSrcSubresource = gcnew ManagedVulkan::ImageSubresourceLayers();
		array<ManagedVulkan::Offset3D^>^ mSrcOffsets = nullptr;
		ManagedVulkan::ImageSubresourceLayers^ mDstSubresource = gcnew ManagedVulkan::ImageSubresourceLayers();
		array<ManagedVulkan::Offset3D^>^ mDstOffsets = nullptr;
	public:
		ImageBlit()
		{
			// FIXED SIZE
			mSrcOffsets = gcnew array<ManagedVulkan::Offset3D^>(2);
			mDstOffsets = gcnew array<ManagedVulkan::Offset3D^>(2);
		}

		property ManagedVulkan::ImageSubresourceLayers^ SrcSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mSrcSubresource;
			}
		}
		property array<ManagedVulkan::Offset3D^>^ SrcOffsets
		{
			array<ManagedVulkan::Offset3D^>^ get()
			{
				return mSrcOffsets;
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
		property array<ManagedVulkan::Offset3D^>^ DstOffsets
		{
			array<ManagedVulkan::Offset3D^>^ get()
			{
				return mDstOffsets;
			}
		}
	internal:
		void CopyTo(VkImageBlit* dst, List<IntPtr>^ pins)
		{
			mSrcSubresource->CopyTo(&dst->srcSubresource, pins);
			mSrcOffsets[0]->CopyTo(dst->srcOffsets + 0, pins);
			mSrcOffsets[1]->CopyTo(dst->srcOffsets + 1, pins);
			mDstSubresource->CopyTo(&dst->dstSubresource, pins);
			mDstOffsets[0]->CopyTo(dst->dstOffsets + 0, pins);
			mDstOffsets[1]->CopyTo(dst->dstOffsets + 1, pins);
		}

		void CopyFrom(VkImageBlit* src)
		{
			mSrcSubresource->CopyFrom(&src->srcSubresource);
			mSrcOffsets[0]->CopyFrom(src->srcOffsets + 0);
			mSrcOffsets[1]->CopyFrom(src->srcOffsets + 1);
			mDstSubresource->CopyFrom(&src->dstSubresource);
			mDstOffsets[0]->CopyFrom(src->dstOffsets + 0);
			mDstOffsets[1]->CopyFrom(src->dstOffsets + 1);
		}
	};

}