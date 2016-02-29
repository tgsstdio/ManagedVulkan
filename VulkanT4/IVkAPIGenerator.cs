using System.Collections.Generic;
using System.Xml.Linq;

namespace VulkanT4
{
    public interface IVkAPIGenerator
    {
        IList<VkFunction> Functions { get; }
        IDictionary<string, VkProxy> Proxies { get; }
        IDictionary<string, VkStruct> Structs { get; }
        IList<VkEnum> Enums { get; }
        void Apply(XDocument doc);
    }
}