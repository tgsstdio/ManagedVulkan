using System.Collections.Generic;
using System.Xml.Linq;

namespace VulkanT4
{
    public interface IVkAPIGenerator
    {
        List<VkFunction> Functions { get; }

        void Apply(XDocument doc);
    }
}