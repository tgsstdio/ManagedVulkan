using System;

namespace VulkanT4
{
    [Flags]
    public enum VkClassMethodType
    {
        EnumerateMethod = 1 << 0,
        OutParameter = 1 << 2,
    }
}
