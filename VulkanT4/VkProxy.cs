using System.Collections.Generic;

namespace VulkanT4
{
    public class VkProxy
    {
        public VkProxy(string key)
        {
            Key = key;
            Methods = new List<VkClassMethod>();
        }

        public string Key { get; set; }
        public string Name { get; set; }
        public List<VkClassMethod> Methods { get; private set; }
    }
}
