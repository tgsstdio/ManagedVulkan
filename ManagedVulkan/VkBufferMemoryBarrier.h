#pragma once

#include <vulkan/vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{

	public ref class BufferMemoryBarrier
	{
	private:
		ManagedVulkan::StructureType mSType;
		ManagedVulkan::AccessFlagBits mSrcAccessMask;
		ManagedVulkan::AccessFlagBits mDstAccessMask;
		UInt32 mSrcQueueFamilyIndex = 0;
		UInt32 mDstQueueFamilyIndex = 0;
		ManagedVulkan::Buffer^ mBuffer = gcnew ManagedVulkan::Buffer();
		UInt64 mOffset = 0;
		UInt64 mSize = 0;
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
		property ManagedVulkan::AccessFlagBits SrcAccessMask
		{
			ManagedVulkan::AccessFlagBits get()
			{
				return mSrcAccessMask;
			}
			void set(ManagedVulkan::AccessFlagBits value)
			{
				mSrcAccessMask = value;
			}
		}
		property ManagedVulkan::AccessFlagBits DstAccessMask
		{
			ManagedVulkan::AccessFlagBits get()
			{
				return mDstAccessMask;
			}
			void set(ManagedVulkan::AccessFlagBits value)
			{
				mDstAccessMask = value;
			}
		}
		property UInt32 SrcQueueFamilyIndex
		{
			UInt32 get()
			{
				return mSrcQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mSrcQueueFamilyIndex = value;
			}
		}
		property UInt32 DstQueueFamilyIndex
		{
			UInt32 get()
			{
				return mDstQueueFamilyIndex;
			}
			void set(UInt32 value)
			{
				mDstQueueFamilyIndex = value;
			}
		}
		property ManagedVulkan::Buffer^ Buffer
		{
			ManagedVulkan::Buffer^ get()
			{
				return mBuffer;
			}
			void set(ManagedVulkan::Buffer^ value)
			{
				mBuffer = value;
			}
		}
		property UInt64 Offset
		{
			UInt64 get()
			{
				return mOffset;
			}
			void set(UInt64 value)
			{
				mOffset = value;
			}
		}
		property UInt64 Size
		{
			UInt64 get()
			{
				return mSize;
			}
			void set(UInt64 value)
			{
				mSize = value;
			}
		}
	internal:
		void CopyTo(VkBufferMemoryBarrier* dst, List<IntPtr>^ pins)
		{
			dst->sType = (VkStructureType) mSType;
			dst->pNext = nullptr;
			dst->srcAccessMask = (VkAccessFlagBits) mSrcAccessMask;
			dst->dstAccessMask = (VkAccessFlagBits) mDstAccessMask;
			dst->srcQueueFamilyIndex = mSrcQueueFamilyIndex;
			dst->dstQueueFamilyIndex = mDstQueueFamilyIndex;
			dst->buffer = mBuffer->mHandle;
			dst->offset = mOffset;
			dst->size = mSize;
		}

		void CopyFrom(VkBufferMemoryBarrier* src)
		{
			mSType = (ManagedVulkan::StructureType)src->sType;
			//pNext = src->pNext;
			mSrcAccessMask = (ManagedVulkan::AccessFlagBits) src->srcAccessMask;
			mDstAccessMask = (ManagedVulkan::AccessFlagBits) src->dstAccessMask;
			mSrcQueueFamilyIndex = src->srcQueueFamilyIndex;
			mDstQueueFamilyIndex = src->dstQueueFamilyIndex;
			mBuffer->mHandle = src->buffer;
			mOffset = src->offset;
			mSize = src->size;
		}
	};


}