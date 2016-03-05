using System.Collections.Generic;

namespace VulkanT4
{
    public interface IVariableDeclaration
    {
        List<VkCommand> Parse(VkFunction fn);
    }
}