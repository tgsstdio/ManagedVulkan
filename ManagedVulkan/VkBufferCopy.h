#pragma once

#include <vulkan/vulkan.h>

using namespace System;
using namespace System::Collections::Generic;

namespace ManagedVulkan
{
	public ref class BufferCopy
	{
	private:
		UInt64 mSrcOffset = 0;
		UInt64 mDstOffset = 0;
		UInt64 mSize = 0;
	public:
		property UInt64 SrcOffset
		{
			UInt64 get()
			{
				return mSrcOffset;
			}
			void set(UInt64 value)
			{
				mSrcOffset = value;
			}
		}
		property UInt64 DstOffset
		{
			UInt64 get()
			{
				return mDstOffset;
			}
			void set(UInt64 value)
			{
				mDstOffset = value;
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
		void CopyTo(VkBufferCopy* dst, List<IntPtr>^ pins)
		{
			dst->srcOffset = mSrcOffset;
			dst->dstOffset = mDstOffset;
			dst->size = mSize;
		}

		void CopyFrom(VkBufferCopy* src)
		{
			mSrcOffset = src->srcOffset;
			mDstOffset = src->dstOffset;
			mSize = src->size;
		}
	};
}