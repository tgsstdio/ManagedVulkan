#pragma once

#include <vulkan/vulkan.h>
#include "VkVec4f.h"
#include "VkVec4Ui.h"
#include "VkVec4i.h"

using namespace System;

namespace ManagedVulkan
{
	public ref class ClearColorValue
	{
	private:
		Vec4f^ mFloat32s = nullptr;
		Vec4Ui^ mUInt32s = nullptr;
		Vec4i^ mInt32s = nullptr;
	public:
		property Vec4f^ Floats
		{
			Vec4f^ get()
			{
				return mFloat32s;
			}
			void set(Vec4f^ value)
			{
				mFloat32s = value;
			}
		}

		property Vec4Ui^ UInt32s
		{
			Vec4Ui^ get()
			{
				return mUInt32s;
			}
			void set(Vec4Ui^ value)
			{
				mUInt32s = value;
			}
		}

		property Vec4i^ Int32s
		{
			Vec4i^ get()
			{
				return mInt32s;
			}
			void set(Vec4i^ value)
			{
				mInt32s = value;
			}
		}

	internal:
		void CopyTo(VkClearColorValue* handle)
		{
			if (mFloat32s != nullptr)
			{
				float* dest = handle->float32;
				dest[0] = mFloat32s->X;
				dest[1] = mFloat32s->Y;
				dest[2] = mFloat32s->Z;
				dest[3] = mFloat32s->W;
			}
			else if (mUInt32s != nullptr)
			{
				UInt32* dest = handle->uint32;
				dest[0] = mUInt32s->X;
				dest[1] = mUInt32s->Y;
				dest[2] = mUInt32s->Z;
				dest[3] = mUInt32s->W;
			}
			else if (mInt32s != nullptr)
			{
				Int32* dest = handle->int32;
				dest[0] = mInt32s->X;
				dest[1] = mInt32s->Y;
				dest[2] = mInt32s->Z;
				dest[3] = mInt32s->W;
			}
		}
	};
}