﻿// ManagedVulkan.h

#pragma once

using namespace System;

namespace ManagedVulkan 
{
	// ENUMS
	public enum class VkImageLayout : UInt32
	{
		VK_IMAGE_LAYOUT_UNDEFINED = 0, // Implicit layout an image is when its contents are undefined due to various reasons (e.g. right after creation)
		VK_IMAGE_LAYOUT_GENERAL = 1, // General layout when image can be used for any kind of access
		VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL = 2, // Optimal layout when image is only used for color attachment read/write
		VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL = 3, // Optimal layout when image is only used for depth/stencil attachment read/write
		VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL = 4, // Optimal layout when image is used for read only depth/stencil attachment and shader access
		VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL = 5, // Optimal layout when image is used for read only shader access
		VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL = 6, // Optimal layout when image is used only as source of transfer operations
		VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL = 7, // Optimal layout when image is used only as destination of transfer operations
		VK_IMAGE_LAYOUT_PREINITIALIZED = 8, // Initial layout used when the data is populated by the CPU
	};

	public enum class VkAttachmentLoadOp : UInt32
	{
		VK_ATTACHMENT_LOAD_OP_LOAD = 0, 
		VK_ATTACHMENT_LOAD_OP_CLEAR = 1, 
		VK_ATTACHMENT_LOAD_OP_DONT_CARE = 2, 
	};

	public enum class VkAttachmentStoreOp : UInt32
	{
		VK_ATTACHMENT_STORE_OP_STORE = 0, 
		VK_ATTACHMENT_STORE_OP_DONT_CARE = 1, 
	};

	public enum class VkImageType : UInt32
	{
		VK_IMAGE_TYPE_1D = 0, 
		VK_IMAGE_TYPE_2D = 1, 
		VK_IMAGE_TYPE_3D = 2, 
	};

	public enum class VkImageTiling : UInt32
	{
		VK_IMAGE_TILING_OPTIMAL = 0, 
		VK_IMAGE_TILING_LINEAR = 1, 
	};

	public enum class VkImageViewType : UInt32
	{
		VK_IMAGE_VIEW_TYPE_1D = 0, 
		VK_IMAGE_VIEW_TYPE_2D = 1, 
		VK_IMAGE_VIEW_TYPE_3D = 2, 
		VK_IMAGE_VIEW_TYPE_CUBE = 3, 
		VK_IMAGE_VIEW_TYPE_1D_ARRAY = 4, 
		VK_IMAGE_VIEW_TYPE_2D_ARRAY = 5, 
		VK_IMAGE_VIEW_TYPE_CUBE_ARRAY = 6, 
	};

	public enum class VkCommandBufferLevel : UInt32
	{
		VK_COMMAND_BUFFER_LEVEL_PRIMARY = 0, 
		VK_COMMAND_BUFFER_LEVEL_SECONDARY = 1, 
	};

	public enum class VkComponentSwizzle : UInt32
	{
		VK_COMPONENT_SWIZZLE_IDENTITY = 0, 
		VK_COMPONENT_SWIZZLE_ZERO = 1, 
		VK_COMPONENT_SWIZZLE_ONE = 2, 
		VK_COMPONENT_SWIZZLE_R = 3, 
		VK_COMPONENT_SWIZZLE_G = 4, 
		VK_COMPONENT_SWIZZLE_B = 5, 
		VK_COMPONENT_SWIZZLE_A = 6, 
	};

	public enum class VkDescriptorType : UInt32
	{
		VK_DESCRIPTOR_TYPE_SAMPLER = 0, 
		VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = 1, 
		VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE = 2, 
		VK_DESCRIPTOR_TYPE_STORAGE_IMAGE = 3, 
		VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER = 4, 
		VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER = 5, 
		VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER = 6, 
		VK_DESCRIPTOR_TYPE_STORAGE_BUFFER = 7, 
		VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC = 8, 
		VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC = 9, 
		VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT = 10, 
	};

	public enum class VkQueryType : UInt32
	{
		VK_QUERY_TYPE_OCCLUSION = 0, 
		VK_QUERY_TYPE_PIPELINE_STATISTICS = 1, // Optional
		VK_QUERY_TYPE_TIMESTAMP = 2, 
	};

	public enum class VkBorderColor : UInt32
	{
		VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK = 0, 
		VK_BORDER_COLOR_INT_TRANSPARENT_BLACK = 1, 
		VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK = 2, 
		VK_BORDER_COLOR_INT_OPAQUE_BLACK = 3, 
		VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE = 4, 
		VK_BORDER_COLOR_INT_OPAQUE_WHITE = 5, 
	};

	public enum class VkPipelineBindPoint : UInt32
	{
		VK_PIPELINE_BIND_POINT_GRAPHICS = 0, 
		VK_PIPELINE_BIND_POINT_COMPUTE = 1, 
	};

	public enum class VkPipelineCacheHeaderVersion : UInt32
	{
		VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1, 
	};

	public enum class VkPrimitiveTopology : UInt32
	{
		VK_PRIMITIVE_TOPOLOGY_POINT_LIST = 0, 
		VK_PRIMITIVE_TOPOLOGY_LINE_LIST = 1, 
		VK_PRIMITIVE_TOPOLOGY_LINE_STRIP = 2, 
		VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST = 3, 
		VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 4, 
		VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN = 5, 
		VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY = 6, 
		VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY = 7, 
		VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY = 8, 
		VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY = 9, 
		VK_PRIMITIVE_TOPOLOGY_PATCH_LIST = 10, 
	};

	public enum class VkSharingMode : UInt32
	{
		VK_SHARING_MODE_EXCLUSIVE = 0, 
		VK_SHARING_MODE_CONCURRENT = 1, 
	};

	public enum class VkIndexType : UInt32
	{
		VK_INDEX_TYPE_UINT16 = 0, 
		VK_INDEX_TYPE_UINT32 = 1, 
	};

	public enum class VkFilter : UInt32
	{
		VK_FILTER_NEAREST = 0, 
		VK_FILTER_LINEAR = 1, 
	};

	public enum class VkSamplerMipmapMode : UInt32
	{
		VK_SAMPLER_MIPMAP_MODE_NEAREST = 0, // Choose nearest mip level
		VK_SAMPLER_MIPMAP_MODE_LINEAR = 1, // Linear filter between mip levels
	};

	public enum class VkSamplerAddressMode : UInt32
	{
		VK_SAMPLER_ADDRESS_MODE_REPEAT = 0, 
		VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT = 1, 
		VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE = 2, 
		VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER = 3, 
		VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE = 4, 
	};

	public enum class VkCompareOp : UInt32
	{
		VK_COMPARE_OP_NEVER = 0, 
		VK_COMPARE_OP_LESS = 1, 
		VK_COMPARE_OP_EQUAL = 2, 
		VK_COMPARE_OP_LESS_OR_EQUAL = 3, 
		VK_COMPARE_OP_GREATER = 4, 
		VK_COMPARE_OP_NOT_EQUAL = 5, 
		VK_COMPARE_OP_GREATER_OR_EQUAL = 6, 
		VK_COMPARE_OP_ALWAYS = 7, 
	};

	public enum class VkPolygonMode : UInt32
	{
		VK_POLYGON_MODE_FILL = 0, 
		VK_POLYGON_MODE_LINE = 1, 
		VK_POLYGON_MODE_POINT = 2, 
	};

	[FlagsAttribute] public enum class VkCullModeFlagBits : UInt32
	{
		VK_CULL_MODE_NONE = 0, 
		VK_CULL_MODE_FRONT_BIT = 1 << 0, 
		VK_CULL_MODE_BACK_BIT = 1 << 1, 
		VK_CULL_MODE_FRONT_AND_BACK = 0x3, 
	};

	public enum class VkFrontFace : UInt32
	{
		VK_FRONT_FACE_COUNTER_CLOCKWISE = 0, 
		VK_FRONT_FACE_CLOCKWISE = 1, 
	};

	public enum class VkBlendFactor : UInt32
	{
		VK_BLEND_FACTOR_ZERO = 0, 
		VK_BLEND_FACTOR_ONE = 1, 
		VK_BLEND_FACTOR_SRC_COLOR = 2, 
		VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3, 
		VK_BLEND_FACTOR_DST_COLOR = 4, 
		VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR = 5, 
		VK_BLEND_FACTOR_SRC_ALPHA = 6, 
		VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 7, 
		VK_BLEND_FACTOR_DST_ALPHA = 8, 
		VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 9, 
		VK_BLEND_FACTOR_CONSTANT_COLOR = 10, 
		VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11, 
		VK_BLEND_FACTOR_CONSTANT_ALPHA = 12, 
		VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 13, 
		VK_BLEND_FACTOR_SRC_ALPHA_SATURATE = 14, 
		VK_BLEND_FACTOR_SRC1_COLOR = 15, 
		VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR = 16, 
		VK_BLEND_FACTOR_SRC1_ALPHA = 17, 
		VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA = 18, 
	};

	public enum class VkBlendOp : UInt32
	{
		VK_BLEND_OP_ADD = 0, 
		VK_BLEND_OP_SUBTRACT = 1, 
		VK_BLEND_OP_REVERSE_SUBTRACT = 2, 
		VK_BLEND_OP_MIN = 3, 
		VK_BLEND_OP_MAX = 4, 
	};

	public enum class VkStencilOp : UInt32
	{
		VK_STENCIL_OP_KEEP = 0, 
		VK_STENCIL_OP_ZERO = 1, 
		VK_STENCIL_OP_REPLACE = 2, 
		VK_STENCIL_OP_INCREMENT_AND_CLAMP = 3, 
		VK_STENCIL_OP_DECREMENT_AND_CLAMP = 4, 
		VK_STENCIL_OP_INVERT = 5, 
		VK_STENCIL_OP_INCREMENT_AND_WRAP = 6, 
		VK_STENCIL_OP_DECREMENT_AND_WRAP = 7, 
	};

	public enum class VkLogicOp : UInt32
	{
		VK_LOGIC_OP_CLEAR = 0, 
		VK_LOGIC_OP_AND = 1, 
		VK_LOGIC_OP_AND_REVERSE = 2, 
		VK_LOGIC_OP_COPY = 3, 
		VK_LOGIC_OP_AND_INVERTED = 4, 
		VK_LOGIC_OP_NO_OP = 5, 
		VK_LOGIC_OP_XOR = 6, 
		VK_LOGIC_OP_OR = 7, 
		VK_LOGIC_OP_NOR = 8, 
		VK_LOGIC_OP_EQUIVALENT = 9, 
		VK_LOGIC_OP_INVERT = 10, 
		VK_LOGIC_OP_OR_REVERSE = 11, 
		VK_LOGIC_OP_COPY_INVERTED = 12, 
		VK_LOGIC_OP_OR_INVERTED = 13, 
		VK_LOGIC_OP_NAND = 14, 
		VK_LOGIC_OP_SET = 15, 
	};

	public enum class VkInternalAllocationType : UInt32
	{
		VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE = 0, 
	};

	public enum class VkSystemAllocationScope : UInt32
	{
		VK_SYSTEM_ALLOCATION_SCOPE_COMMAND = 0, 
		VK_SYSTEM_ALLOCATION_SCOPE_OBJECT = 1, 
		VK_SYSTEM_ALLOCATION_SCOPE_CACHE = 2, 
		VK_SYSTEM_ALLOCATION_SCOPE_DEVICE = 3, 
		VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE = 4, 
	};

	public enum class VkPhysicalDeviceType : UInt32
	{
		VK_PHYSICAL_DEVICE_TYPE_OTHER = 0, 
		VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1, 
		VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2, 
		VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3, 
		VK_PHYSICAL_DEVICE_TYPE_CPU = 4, 
	};

	public enum class VkVertexInputRate : UInt32
	{
		VK_VERTEX_INPUT_RATE_VERTEX = 0, 
		VK_VERTEX_INPUT_RATE_INSTANCE = 1, 
	};

	public enum class VkFormat : UInt32
	{
		VK_FORMAT_UNDEFINED = 0, 
		VK_FORMAT_R4G4_UNORM_PACK8 = 1, 
		VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2, 
		VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3, 
		VK_FORMAT_R5G6B5_UNORM_PACK16 = 4, 
		VK_FORMAT_B5G6R5_UNORM_PACK16 = 5, 
		VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6, 
		VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7, 
		VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8, 
		VK_FORMAT_R8_UNORM = 9, 
		VK_FORMAT_R8_SNORM = 10, 
		VK_FORMAT_R8_USCALED = 11, 
		VK_FORMAT_R8_SSCALED = 12, 
		VK_FORMAT_R8_UINT = 13, 
		VK_FORMAT_R8_SINT = 14, 
		VK_FORMAT_R8_SRGB = 15, 
		VK_FORMAT_R8G8_UNORM = 16, 
		VK_FORMAT_R8G8_SNORM = 17, 
		VK_FORMAT_R8G8_USCALED = 18, 
		VK_FORMAT_R8G8_SSCALED = 19, 
		VK_FORMAT_R8G8_UINT = 20, 
		VK_FORMAT_R8G8_SINT = 21, 
		VK_FORMAT_R8G8_SRGB = 22, 
		VK_FORMAT_R8G8B8_UNORM = 23, 
		VK_FORMAT_R8G8B8_SNORM = 24, 
		VK_FORMAT_R8G8B8_USCALED = 25, 
		VK_FORMAT_R8G8B8_SSCALED = 26, 
		VK_FORMAT_R8G8B8_UINT = 27, 
		VK_FORMAT_R8G8B8_SINT = 28, 
		VK_FORMAT_R8G8B8_SRGB = 29, 
		VK_FORMAT_B8G8R8_UNORM = 30, 
		VK_FORMAT_B8G8R8_SNORM = 31, 
		VK_FORMAT_B8G8R8_USCALED = 32, 
		VK_FORMAT_B8G8R8_SSCALED = 33, 
		VK_FORMAT_B8G8R8_UINT = 34, 
		VK_FORMAT_B8G8R8_SINT = 35, 
		VK_FORMAT_B8G8R8_SRGB = 36, 
		VK_FORMAT_R8G8B8A8_UNORM = 37, 
		VK_FORMAT_R8G8B8A8_SNORM = 38, 
		VK_FORMAT_R8G8B8A8_USCALED = 39, 
		VK_FORMAT_R8G8B8A8_SSCALED = 40, 
		VK_FORMAT_R8G8B8A8_UINT = 41, 
		VK_FORMAT_R8G8B8A8_SINT = 42, 
		VK_FORMAT_R8G8B8A8_SRGB = 43, 
		VK_FORMAT_B8G8R8A8_UNORM = 44, 
		VK_FORMAT_B8G8R8A8_SNORM = 45, 
		VK_FORMAT_B8G8R8A8_USCALED = 46, 
		VK_FORMAT_B8G8R8A8_SSCALED = 47, 
		VK_FORMAT_B8G8R8A8_UINT = 48, 
		VK_FORMAT_B8G8R8A8_SINT = 49, 
		VK_FORMAT_B8G8R8A8_SRGB = 50, 
		VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51, 
		VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52, 
		VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53, 
		VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54, 
		VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55, 
		VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56, 
		VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57, 
		VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58, 
		VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59, 
		VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60, 
		VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61, 
		VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62, 
		VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63, 
		VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64, 
		VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65, 
		VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66, 
		VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67, 
		VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68, 
		VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69, 
		VK_FORMAT_R16_UNORM = 70, 
		VK_FORMAT_R16_SNORM = 71, 
		VK_FORMAT_R16_USCALED = 72, 
		VK_FORMAT_R16_SSCALED = 73, 
		VK_FORMAT_R16_UINT = 74, 
		VK_FORMAT_R16_SINT = 75, 
		VK_FORMAT_R16_SFLOAT = 76, 
		VK_FORMAT_R16G16_UNORM = 77, 
		VK_FORMAT_R16G16_SNORM = 78, 
		VK_FORMAT_R16G16_USCALED = 79, 
		VK_FORMAT_R16G16_SSCALED = 80, 
		VK_FORMAT_R16G16_UINT = 81, 
		VK_FORMAT_R16G16_SINT = 82, 
		VK_FORMAT_R16G16_SFLOAT = 83, 
		VK_FORMAT_R16G16B16_UNORM = 84, 
		VK_FORMAT_R16G16B16_SNORM = 85, 
		VK_FORMAT_R16G16B16_USCALED = 86, 
		VK_FORMAT_R16G16B16_SSCALED = 87, 
		VK_FORMAT_R16G16B16_UINT = 88, 
		VK_FORMAT_R16G16B16_SINT = 89, 
		VK_FORMAT_R16G16B16_SFLOAT = 90, 
		VK_FORMAT_R16G16B16A16_UNORM = 91, 
		VK_FORMAT_R16G16B16A16_SNORM = 92, 
		VK_FORMAT_R16G16B16A16_USCALED = 93, 
		VK_FORMAT_R16G16B16A16_SSCALED = 94, 
		VK_FORMAT_R16G16B16A16_UINT = 95, 
		VK_FORMAT_R16G16B16A16_SINT = 96, 
		VK_FORMAT_R16G16B16A16_SFLOAT = 97, 
		VK_FORMAT_R32_UINT = 98, 
		VK_FORMAT_R32_SINT = 99, 
		VK_FORMAT_R32_SFLOAT = 100, 
		VK_FORMAT_R32G32_UINT = 101, 
		VK_FORMAT_R32G32_SINT = 102, 
		VK_FORMAT_R32G32_SFLOAT = 103, 
		VK_FORMAT_R32G32B32_UINT = 104, 
		VK_FORMAT_R32G32B32_SINT = 105, 
		VK_FORMAT_R32G32B32_SFLOAT = 106, 
		VK_FORMAT_R32G32B32A32_UINT = 107, 
		VK_FORMAT_R32G32B32A32_SINT = 108, 
		VK_FORMAT_R32G32B32A32_SFLOAT = 109, 
		VK_FORMAT_R64_UINT = 110, 
		VK_FORMAT_R64_SINT = 111, 
		VK_FORMAT_R64_SFLOAT = 112, 
		VK_FORMAT_R64G64_UINT = 113, 
		VK_FORMAT_R64G64_SINT = 114, 
		VK_FORMAT_R64G64_SFLOAT = 115, 
		VK_FORMAT_R64G64B64_UINT = 116, 
		VK_FORMAT_R64G64B64_SINT = 117, 
		VK_FORMAT_R64G64B64_SFLOAT = 118, 
		VK_FORMAT_R64G64B64A64_UINT = 119, 
		VK_FORMAT_R64G64B64A64_SINT = 120, 
		VK_FORMAT_R64G64B64A64_SFLOAT = 121, 
		VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122, 
		VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123, 
		VK_FORMAT_D16_UNORM = 124, 
		VK_FORMAT_X8_D24_UNORM_PACK32 = 125, 
		VK_FORMAT_D32_SFLOAT = 126, 
		VK_FORMAT_S8_UINT = 127, 
		VK_FORMAT_D16_UNORM_S8_UINT = 128, 
		VK_FORMAT_D24_UNORM_S8_UINT = 129, 
		VK_FORMAT_D32_SFLOAT_S8_UINT = 130, 
		VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131, 
		VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132, 
		VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133, 
		VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134, 
		VK_FORMAT_BC2_UNORM_BLOCK = 135, 
		VK_FORMAT_BC2_SRGB_BLOCK = 136, 
		VK_FORMAT_BC3_UNORM_BLOCK = 137, 
		VK_FORMAT_BC3_SRGB_BLOCK = 138, 
		VK_FORMAT_BC4_UNORM_BLOCK = 139, 
		VK_FORMAT_BC4_SNORM_BLOCK = 140, 
		VK_FORMAT_BC5_UNORM_BLOCK = 141, 
		VK_FORMAT_BC5_SNORM_BLOCK = 142, 
		VK_FORMAT_BC6H_UFLOAT_BLOCK = 143, 
		VK_FORMAT_BC6H_SFLOAT_BLOCK = 144, 
		VK_FORMAT_BC7_UNORM_BLOCK = 145, 
		VK_FORMAT_BC7_SRGB_BLOCK = 146, 
		VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147, 
		VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148, 
		VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149, 
		VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150, 
		VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151, 
		VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152, 
		VK_FORMAT_EAC_R11_UNORM_BLOCK = 153, 
		VK_FORMAT_EAC_R11_SNORM_BLOCK = 154, 
		VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155, 
		VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156, 
		VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157, 
		VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158, 
		VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159, 
		VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160, 
		VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161, 
		VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162, 
		VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163, 
		VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164, 
		VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165, 
		VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166, 
		VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167, 
		VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168, 
		VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169, 
		VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170, 
		VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171, 
		VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172, 
		VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173, 
		VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174, 
		VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175, 
		VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176, 
		VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177, 
		VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178, 
		VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179, 
		VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180, 
		VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181, 
		VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182, 
		VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183, 
		VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184, 
	};

	public enum class VkStructureType : UInt32
	{
		VK_STRUCTURE_TYPE_APPLICATION_INFO = 0, 
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1, 
		VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO = 2, 
		VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO = 3, 
		VK_STRUCTURE_TYPE_SUBMIT_INFO = 4, 
		VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO = 5, 
		VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE = 6, 
		VK_STRUCTURE_TYPE_BIND_SPARSE_INFO = 7, 
		VK_STRUCTURE_TYPE_FENCE_CREATE_INFO = 8, 
		VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO = 9, 
		VK_STRUCTURE_TYPE_EVENT_CREATE_INFO = 10, 
		VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO = 11, 
		VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO = 12, 
		VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO = 13, 
		VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO = 14, 
		VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO = 15, 
		VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO = 16, 
		VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO = 17, 
		VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO = 18, 
		VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO = 19, 
		VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO = 20, 
		VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO = 21, 
		VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO = 22, 
		VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO = 23, 
		VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO = 24, 
		VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO = 25, 
		VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO = 26, 
		VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO = 27, 
		VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO = 28, 
		VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO = 29, 
		VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO = 30, 
		VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO = 31, 
		VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO = 32, 
		VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO = 33, 
		VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO = 34, 
		VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET = 35, 
		VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET = 36, 
		VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO = 37, 
		VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO = 38, 
		VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO = 39, 
		VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO = 40, 
		VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO = 41, 
		VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO = 42, 
		VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO = 43, 
		VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER = 44, 
		VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER = 45, 
		VK_STRUCTURE_TYPE_MEMORY_BARRIER = 46, 
		VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO = 47, 
		VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO = 48, 
	};

	public enum class VkSubpassContents : UInt32
	{
		VK_SUBPASS_CONTENTS_INLINE = 0, 
		VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS = 1, 
	};

	public enum class VkResult : UInt32
	{
		VK_SUCCESS = 0, // Command completed successfully
		VK_NOT_READY = 1, // A fence or query has not yet completed
		VK_TIMEOUT = 2, // A wait operation has not completed in the specified time
		VK_EVENT_SET = 3, // An event is signaled
		VK_EVENT_RESET = 4, // An event is unsignalled
		VK_INCOMPLETE = 5, // A return array was too small for the resul
		VK_ERROR_OUT_OF_HOST_MEMORY = -1, // A host memory allocation has failed
		VK_ERROR_OUT_OF_DEVICE_MEMORY = -2, // A device memory allocation has failed
		VK_ERROR_INITIALIZATION_FAILED = -3, // The logical device has been lost. See <<devsandqueues-lost-device>>
		VK_ERROR_DEVICE_LOST = -4, // Initialization of a object has failed
		VK_ERROR_MEMORY_MAP_FAILED = -5, // Mapping of a memory object has failed
		VK_ERROR_LAYER_NOT_PRESENT = -6, // Layer specified does not exist
		VK_ERROR_EXTENSION_NOT_PRESENT = -7, // Extension specified does not exist
		VK_ERROR_FEATURE_NOT_PRESENT = -8, // Requested feature is not available on this device
		VK_ERROR_INCOMPATIBLE_DRIVER = -9, // Unable to find a Vulkan driver
		VK_ERROR_TOO_MANY_OBJECTS = -10, // Too many objects of the type have already been created
		VK_ERROR_FORMAT_NOT_SUPPORTED = -11, // Requested format is not supported on this device
	};

	public enum class VkDynamicState : UInt32
	{
		VK_DYNAMIC_STATE_VIEWPORT = 0, 
		VK_DYNAMIC_STATE_SCISSOR = 1, 
		VK_DYNAMIC_STATE_LINE_WIDTH = 2, 
		VK_DYNAMIC_STATE_DEPTH_BIAS = 3, 
		VK_DYNAMIC_STATE_BLEND_CONSTANTS = 4, 
		VK_DYNAMIC_STATE_DEPTH_BOUNDS = 5, 
		VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK = 6, 
		VK_DYNAMIC_STATE_STENCIL_WRITE_MASK = 7, 
		VK_DYNAMIC_STATE_STENCIL_REFERENCE = 8, 
	};

	[FlagsAttribute] public enum class VkQueueFlagBits : UInt32
	{
		VK_QUEUE_GRAPHICS_BIT = 1 << 0, // Queue supports graphics operations
		VK_QUEUE_COMPUTE_BIT = 1 << 1, // Queue supports compute operations
		VK_QUEUE_TRANSFER_BIT = 1 << 2, // Queue supports transfer operations
		VK_QUEUE_SPARSE_BINDING_BIT = 1 << 3, // Queue supports sparse resource memory management operations
	};

	[FlagsAttribute] public enum class VkMemoryPropertyFlagBits : UInt32
	{
		VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 1 << 0, // If otherwise stated, then allocate memory on device
		VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 1 << 1, // Memory is mappable by host
		VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 1 << 2, // Memory will have i/o coherency. If not set, application may need to use vkFlushMappedMemoryRanges and vkInvalidateMappedMemoryRanges to flush/invalidate host cache
		VK_MEMORY_PROPERTY_HOST_CACHED_BIT = 1 << 3, // Memory will be cached by the host
		VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT = 1 << 4, // Memory may be allocated by the driver when it is required
	};

	[FlagsAttribute] public enum class VkMemoryHeapFlagBits : UInt32
	{
		VK_MEMORY_HEAP_DEVICE_LOCAL_BIT = 1 << 0, // If set, heap represents device memory
	};

	[FlagsAttribute] public enum class VkAccessFlagBits : UInt32
	{
		VK_ACCESS_INDIRECT_COMMAND_READ_BIT = 1 << 0, // Controls coherency of indirect command reads
		VK_ACCESS_INDEX_READ_BIT = 1 << 1, // Controls coherency of index reads
		VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT = 1 << 2, // Controls coherency of vertex attribute reads
		VK_ACCESS_UNIFORM_READ_BIT = 1 << 3, // Controls coherency of uniform buffer reads
		VK_ACCESS_INPUT_ATTACHMENT_READ_BIT = 1 << 4, // Controls coherency of input attachment reads
		VK_ACCESS_SHADER_READ_BIT = 1 << 5, // Controls coherency of shader reads
		VK_ACCESS_SHADER_WRITE_BIT = 1 << 6, // Controls coherency of shader writes
		VK_ACCESS_COLOR_ATTACHMENT_READ_BIT = 1 << 7, // Controls coherency of color attachment reads
		VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT = 1 << 8, // Controls coherency of color attachment writes
		VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT = 1 << 9, // Controls coherency of depth/stencil attachment reads
		VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT = 1 << 10, // Controls coherency of depth/stencil attachment writes
		VK_ACCESS_TRANSFER_READ_BIT = 1 << 11, // Controls coherency of transfer reads
		VK_ACCESS_TRANSFER_WRITE_BIT = 1 << 12, // Controls coherency of transfer writes
		VK_ACCESS_HOST_READ_BIT = 1 << 13, // Controls coherency of host reads
		VK_ACCESS_HOST_WRITE_BIT = 1 << 14, // Controls coherency of host writes
		VK_ACCESS_MEMORY_READ_BIT = 1 << 15, // Controls coherency of memory reads
		VK_ACCESS_MEMORY_WRITE_BIT = 1 << 16, // Controls coherency of memory writes
	};

	[FlagsAttribute] public enum class VkBufferUsageFlagBits : UInt32
	{
		VK_BUFFER_USAGE_TRANSFER_SRC_BIT = 1 << 0, // Can be used as a source of transfer operations
		VK_BUFFER_USAGE_TRANSFER_DST_BIT = 1 << 1, // Can be used as a destination of transfer operations
		VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT = 1 << 2, // Can be used as TBO
		VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT = 1 << 3, // Can be used as IBO
		VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT = 1 << 4, // Can be used as UBO
		VK_BUFFER_USAGE_STORAGE_BUFFER_BIT = 1 << 5, // Can be used as SSBO
		VK_BUFFER_USAGE_INDEX_BUFFER_BIT = 1 << 6, // Can be used as source of fixed-function index fetch (index buffer)
		VK_BUFFER_USAGE_VERTEX_BUFFER_BIT = 1 << 7, // Can be used as source of fixed-function vertex fetch (VBO)
		VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT = 1 << 8, // Can be the source of indirect parameters (e.g. indirect buffer, parameter buffer)
	};

	[FlagsAttribute] public enum class VkBufferCreateFlagBits : UInt32
	{
		VK_BUFFER_CREATE_SPARSE_BINDING_BIT = 1 << 0, // Buffer should support sparse backing
		VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT = 1 << 1, // Buffer should support sparse backing with partial residency
		VK_BUFFER_CREATE_SPARSE_ALIASED_BIT = 1 << 2, // Buffer should support constent data access to physical memory blocks mapped into multiple locations of sparse buffers
	};

	[FlagsAttribute] public enum class VkShaderStageFlagBits : UInt32
	{
		VK_SHADER_STAGE_VERTEX_BIT = 1 << 0, 
		VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT = 1 << 1, 
		VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT = 1 << 2, 
		VK_SHADER_STAGE_GEOMETRY_BIT = 1 << 3, 
		VK_SHADER_STAGE_FRAGMENT_BIT = 1 << 4, 
		VK_SHADER_STAGE_COMPUTE_BIT = 1 << 5, 
		VK_SHADER_STAGE_ALL_GRAPHICS = 0x1F, 
		VK_SHADER_STAGE_ALL = 0x7FFFFFFF, 
	};

	[FlagsAttribute] public enum class VkImageUsageFlagBits : UInt32
	{
		VK_IMAGE_USAGE_TRANSFER_SRC_BIT = 1 << 0, // Can be used as a source of transfer operations
		VK_IMAGE_USAGE_TRANSFER_DST_BIT = 1 << 1, // Can be used as a destination of transfer operations
		VK_IMAGE_USAGE_SAMPLED_BIT = 1 << 2, // Can be sampled from (SAMPLED_IMAGE and COMBINED_IMAGE_SAMPLER descriptor types)
		VK_IMAGE_USAGE_STORAGE_BIT = 1 << 3, // Can be used as storage image (STORAGE_IMAGE descriptor type)
		VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT = 1 << 4, // Can be used as framebuffer color attachment
		VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT = 1 << 5, // Can be used as framebuffer depth/stencil attachment
		VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT = 1 << 6, // Image data not needed outside of rendering
		VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT = 1 << 7, // Can be used as framebuffer input attachment
	};

	[FlagsAttribute] public enum class VkImageCreateFlagBits : UInt32
	{
		VK_IMAGE_CREATE_SPARSE_BINDING_BIT = 1 << 0, // Image should support sparse backing
		VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT = 1 << 1, // Image should support sparse backing with partial residency
		VK_IMAGE_CREATE_SPARSE_ALIASED_BIT = 1 << 2, // Image should support constent data access to physical memory blocks mapped into multiple locations of sparse images
		VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT = 1 << 3, // Allows image views to have different format than the base image
		VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT = 1 << 4, // Allows creating image views with cube type from the created image
	};

	[FlagsAttribute] public enum class VkPipelineCreateFlagBits : UInt32
	{
		VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT = 1 << 0, 
		VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT = 1 << 1, 
		VK_PIPELINE_CREATE_DERIVATIVE_BIT = 1 << 2, 
	};

	[FlagsAttribute] public enum class VkColorComponentFlagBits : UInt32
	{
		VK_COLOR_COMPONENT_R_BIT = 1 << 0, 
		VK_COLOR_COMPONENT_G_BIT = 1 << 1, 
		VK_COLOR_COMPONENT_B_BIT = 1 << 2, 
		VK_COLOR_COMPONENT_A_BIT = 1 << 3, 
	};

	[FlagsAttribute] public enum class VkFenceCreateFlagBits : UInt32
	{
		VK_FENCE_CREATE_SIGNALED_BIT = 1 << 0, 
	};

	[FlagsAttribute] public enum class VkFormatFeatureFlagBits : UInt32
	{
		VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT = 1 << 0, // Format can be used for sampled images (SAMPLED_IMAGE and COMBINED_IMAGE_SAMPLER descriptor types)
		VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT = 1 << 1, // Format can be used for storage images (STORAGE_IMAGE descriptor type)
		VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT = 1 << 2, // Format supports atomic operations in case it's used for storage images
		VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT = 1 << 3, // Format can be used for uniform texel buffers (TBOs)
		VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT = 1 << 4, // Format can be used for storage texel buffers (IBOs)
		VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT = 1 << 5, // Format supports atomic operations in case it's used for storage texel buffers
		VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT = 1 << 6, // Format can be used for vertex buffers (VBOs)
		VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT = 1 << 7, // Format can be used for color attachment images
		VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT = 1 << 8, // Format supports blending in case it's used for color attachment images
		VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT = 1 << 9, // Format can be used for depth/stencil attachment images
		VK_FORMAT_FEATURE_BLIT_SRC_BIT = 1 << 10, // Format can be used as the source image of blits with vkCmdBlitImage
		VK_FORMAT_FEATURE_BLIT_DST_BIT = 1 << 11, // Format can be used as the destination image of blits with vkCmdBlitImage
		VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT = 1 << 12, // Format can be filtered with VK_FILTER_LINEAR when being sampled
	};

	[FlagsAttribute] public enum class VkQueryControlFlagBits : UInt32
	{
		VK_QUERY_CONTROL_PRECISE_BIT = 1 << 0, // Require precise results to be collected by the query
	};

	[FlagsAttribute] public enum class VkQueryResultFlagBits : UInt32
	{
		VK_QUERY_RESULT_64_BIT = 1 << 0, // Results of the queries are written to the destination buffer as 64-bit values
		VK_QUERY_RESULT_WAIT_BIT = 1 << 1, // Results of the queries are waited on before proceeding with the result copy
		VK_QUERY_RESULT_WITH_AVAILABILITY_BIT = 1 << 2, // Besides the results of the query, the availability of the results is also written
		VK_QUERY_RESULT_PARTIAL_BIT = 1 << 3, // Copy the partial results of the query even if the final results aren't available
	};

	[FlagsAttribute] public enum class VkCommandBufferUsageFlagBits : UInt32
	{
		VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT = 1 << 0, 
		VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT = 1 << 1, 
		VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT = 1 << 2, // Command buffer may be submitted/executed more than once simultaneously
	};

	[FlagsAttribute] public enum class VkQueryPipelineStatisticFlagBits : UInt32
	{
		VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT = 1 << 0, // Optional
		VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT = 1 << 1, // Optional
		VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT = 1 << 2, // Optional
		VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT = 1 << 3, // Optional
		VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT = 1 << 4, // Optional
		VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT = 1 << 5, // Optional
		VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT = 1 << 6, // Optional
		VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT = 1 << 7, // Optional
		VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT = 1 << 8, // Optional
		VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT = 1 << 9, // Optional
		VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT = 1 << 10, // Optional
	};

	[FlagsAttribute] public enum class VkImageAspectFlagBits : UInt32
	{
		VK_IMAGE_ASPECT_COLOR_BIT = 1 << 0, 
		VK_IMAGE_ASPECT_DEPTH_BIT = 1 << 1, 
		VK_IMAGE_ASPECT_STENCIL_BIT = 1 << 2, 
		VK_IMAGE_ASPECT_METADATA_BIT = 1 << 3, 
	};

	[FlagsAttribute] public enum class VkSparseImageFormatFlagBits : UInt32
	{
		VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT = 1 << 0, // Image uses a single miptail region for all array layers
		VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT = 1 << 1, // Image requires mip levels to be an exact multiple of the sparse image block size for non-miptail levels.
		VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT = 1 << 2, // Image uses a non-standard sparse block size
	};

	[FlagsAttribute] public enum class VkSparseMemoryBindFlagBits : UInt32
	{
		VK_SPARSE_MEMORY_BIND_METADATA_BIT = 1 << 0, // Operation binds resource metadata to memory
	};

	[FlagsAttribute] public enum class VkPipelineStageFlagBits : UInt32
	{
		VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT = 1 << 0, // Before subsequent commands are processed
		VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT = 1 << 1, // Draw/DispatchIndirect command fetch
		VK_PIPELINE_STAGE_VERTEX_INPUT_BIT = 1 << 2, // Vertex/index fetch
		VK_PIPELINE_STAGE_VERTEX_SHADER_BIT = 1 << 3, // Vertex shading
		VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT = 1 << 4, // Tessellation control shading
		VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT = 1 << 5, // Tessellation evaluation shading
		VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT = 1 << 6, // Geometry shading
		VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT = 1 << 7, // Fragment shading
		VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT = 1 << 8, // Early fragment (depth and stencil) tests
		VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT = 1 << 9, // Late fragment (depth and stencil) tests
		VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT = 1 << 10, // Color attachment writes
		VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT = 1 << 11, // Compute shading
		VK_PIPELINE_STAGE_TRANSFER_BIT = 1 << 12, // Transfer/copy operations
		VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT = 1 << 13, // After previous commands have completed
		VK_PIPELINE_STAGE_HOST_BIT = 1 << 14, // Indicates host (CPU) is a source/sink of the dependency
		VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT = 1 << 15, // All stages of the graphics pipeline
		VK_PIPELINE_STAGE_ALL_COMMANDS_BIT = 1 << 16, // All stages supported on the queue
	};

	[FlagsAttribute] public enum class VkCommandPoolCreateFlagBits : UInt32
	{
		VK_COMMAND_POOL_CREATE_TRANSIENT_BIT = 1 << 0, // Command buffers have a short lifetime
		VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT = 1 << 1, // Command buffers may release their memory individually
	};

	[FlagsAttribute] public enum class VkCommandPoolResetFlagBits : UInt32
	{
		VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT = 1 << 0, // Release resources owned by the pool
	};

	[FlagsAttribute] public enum class VkCommandBufferResetFlagBits : UInt32
	{
		VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT = 1 << 0, // Release resources owned by the buffer
	};

	[FlagsAttribute] public enum class VkSampleCountFlagBits : UInt32
	{
		VK_SAMPLE_COUNT_1_BIT = 1 << 0, // Sample count 1 supported
		VK_SAMPLE_COUNT_2_BIT = 1 << 1, // Sample count 2 supported
		VK_SAMPLE_COUNT_4_BIT = 1 << 2, // Sample count 4 supported
		VK_SAMPLE_COUNT_8_BIT = 1 << 3, // Sample count 8 supported
		VK_SAMPLE_COUNT_16_BIT = 1 << 4, // Sample count 16 supported
		VK_SAMPLE_COUNT_32_BIT = 1 << 5, // Sample count 32 supported
		VK_SAMPLE_COUNT_64_BIT = 1 << 6, // Sample count 64 supported
	};

	[FlagsAttribute] public enum class VkAttachmentDescriptionFlagBits : UInt32
	{
		VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT = 1 << 0, // The attachment may alias physical memory of another attachment in the same render pass
	};

	[FlagsAttribute] public enum class VkStencilFaceFlagBits : UInt32
	{
		VK_STENCIL_FACE_FRONT_BIT = 1 << 0, // Front face
		VK_STENCIL_FACE_BACK_BIT = 1 << 1, // Back face
		VK_STENCIL_FRONT_AND_BACK = 0x3, // Front and back faces
	};

	[FlagsAttribute] public enum class VkDescriptorPoolCreateFlagBits : UInt32
	{
		VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT = 1 << 0, // Descriptor sets may be freed individually
	};

	[FlagsAttribute] public enum class VkDependencyFlagBits : UInt32
	{
		VK_DEPENDENCY_BY_REGION_BIT = 1 << 0, // Dependency is per pixel region 
	};

	public enum class VkPresentModeKHR : UInt32
	{
		VK_PRESENT_MODE_IMMEDIATE_KHR = 0, 
		VK_PRESENT_MODE_MAILBOX_KHR = 1, 
		VK_PRESENT_MODE_FIFO_KHR = 2, 
		VK_PRESENT_MODE_FIFO_RELAXED_KHR = 3, 
	};

	public enum class VkColorSpaceKHR : UInt32
	{
		VK_COLORSPACE_SRGB_NONLINEAR_KHR = 0, 
	};

	[FlagsAttribute] public enum class VkDisplayPlaneAlphaFlagBitsKHR : UInt32
	{
		VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR = 1 << 0, 
		VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR = 1 << 1, 
		VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR = 1 << 2, 
		VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR = 1 << 3, 
	};

	[FlagsAttribute] public enum class VkCompositeAlphaFlagBitsKHR : UInt32
	{
		VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR = 1 << 0, 
		VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR = 1 << 1, 
		VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR = 1 << 2, 
		VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR = 1 << 3, 
	};

	[FlagsAttribute] public enum class VkSurfaceTransformFlagBitsKHR : UInt32
	{
		VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR = 1 << 0, 
		VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR = 1 << 1, 
		VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR = 1 << 2, 
		VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR = 1 << 3, 
		VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR = 1 << 4, 
		VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR = 1 << 5, 
		VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR = 1 << 6, 
		VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR = 1 << 7, 
		VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR = 1 << 8, 
	};

	[FlagsAttribute] public enum class VkDebugReportFlagBitsEXT : UInt32
	{
		VK_DEBUG_REPORT_INFORMATION_BIT_EXT = 1 << 0, 
		VK_DEBUG_REPORT_WARNING_BIT_EXT = 1 << 1, 
		VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT = 1 << 2, 
		VK_DEBUG_REPORT_ERROR_BIT_EXT = 1 << 3, 
		VK_DEBUG_REPORT_DEBUG_BIT_EXT = 1 << 4, 
	};

	public enum class VkDebugReportObjectTypeEXT : UInt32
	{
		VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT = 0, 
		VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT = 1, 
		VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT = 2, 
		VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT = 3, 
		VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT = 4, 
		VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT = 5, 
		VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT = 6, 
		VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT = 7, 
		VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT = 8, 
		VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT = 9, 
		VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT = 10, 
		VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT = 11, 
		VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT = 12, 
		VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT = 13, 
		VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT = 14, 
		VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT = 15, 
		VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT = 16, 
		VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT = 17, 
		VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT = 18, 
		VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT = 19, 
		VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT = 20, 
		VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT = 21, 
		VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT = 22, 
		VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT = 23, 
		VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT = 24, 
		VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT = 25, 
		VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT = 26, 
		VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT = 27, 
		VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT = 28, 
	};

	public enum class VkDebugReportErrorEXT : UInt32
	{
		VK_DEBUG_REPORT_ERROR_NONE_EXT = 0, 
		VK_DEBUG_REPORT_ERROR_CALLBACK_REF_EXT = 1, 
	};

}