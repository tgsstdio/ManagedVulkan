using System.Collections.Generic;

namespace VulkanT4
{
    public class VkEnum
    {
        public VkEnum()
        {
            Items = new List<VkEnumItem>();
        }

        public string Name { get; set; }
        public bool UseFlags { get; set; }
        public List<VkEnumItem> Items { get; private set; }
        public string Expand { get; set; }
    }
}