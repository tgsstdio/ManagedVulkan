#pragma once

#include "VkImageSubresourceLayers.h"
#include "VkOffset3D.h" 
#include "VkExtent3D.h"

namespace ManagedVulkan
{
	public ref class BufferImageCopy
	{
	private:
		UInt64 mBufferOffset = 0;
		UInt32 mBufferRowLength = 0;
		UInt32 mBufferImageHeight = 0;
		ManagedVulkan::ImageSubresourceLayers^ mImageSubresource = gcnew ManagedVulkan::ImageSubresourceLayers();
		ManagedVulkan::Offset3D^ mImageOffset = gcnew ManagedVulkan::Offset3D();
		ManagedVulkan::Extent3D^ mImageExtent = gcnew ManagedVulkan::Extent3D();
	public:
		property UInt64 BufferOffset
		{
			UInt64 get()
			{
				return mBufferOffset;
			}
			void set(UInt64 value)
			{
				mBufferOffset = value;
			}
		}
		property UInt32 BufferRowLength
		{
			UInt32 get()
			{
				return mBufferRowLength;
			}
			void set(UInt32 value)
			{
				mBufferRowLength = value;
			}
		}
		property UInt32 BufferImageHeight
		{
			UInt32 get()
			{
				return mBufferImageHeight;
			}
			void set(UInt32 value)
			{
				mBufferImageHeight = value;
			}
		}
		property ManagedVulkan::ImageSubresourceLayers^ ImageSubresource
		{
			ManagedVulkan::ImageSubresourceLayers^ get()
			{
				return mImageSubresource;
			}
			void set(ManagedVulkan::ImageSubresourceLayers^ value)
			{
				mImageSubresource = value;
			}
		}
		property ManagedVulkan::Offset3D^ ImageOffset
		{
			ManagedVulkan::Offset3D^ get()
			{
				return mImageOffset;
			}
			void set(ManagedVulkan::Offset3D^ value)
			{
				mImageOffset = value;
			}
		}
		property ManagedVulkan::Extent3D^ ImageExtent
		{
			ManagedVulkan::Extent3D^ get()
			{
				return mImageExtent;
			}
			void set(ManagedVulkan::Extent3D^ value)
			{
				mImageExtent = value;
			}
		}
	internal:
		void CopyTo(VkBufferImageCopy* dst, List<IntPtr>^ pins)
		{
			dst->bufferOffset = mBufferOffset;
			dst->bufferRowLength = mBufferRowLength;
			dst->bufferImageHeight = mBufferImageHeight;
			mImageSubresource->CopyTo(&dst->imageSubresource, pins);
			mImageOffset->CopyTo(&dst->imageOffset, pins);
			mImageExtent->CopyTo(&dst->imageExtent, pins);
		}

		void CopyFrom(VkBufferImageCopy* src)
		{
			mBufferOffset = src->bufferOffset;
			mBufferRowLength = src->bufferRowLength;
			mBufferImageHeight = src->bufferImageHeight;
			mImageSubresource->CopyFrom(&src->imageSubresource);
			mImageOffset->CopyFrom(&src->imageOffset);
			mImageExtent->CopyFrom(&src->imageExtent);
		}
	};
}