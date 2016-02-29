using System.Collections.Generic;

namespace VulkanT4
{
    public class VkEnum
    {
        public VkEnum()
        {
            Items = new List<VkEnumItem>();
        }

        public string Name { get; internal set; }
        public bool UseFlags { get; internal set; }
        public List<VkEnumItem> Items { get; private set; }
        public string Expand { get; internal set; }
    }
}