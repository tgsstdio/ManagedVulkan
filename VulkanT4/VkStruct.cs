using System.Collections.Generic;

namespace VulkanT4
{
    public class VkStruct
    {
        public VkStruct(string key)
        {
            Key = key;
            Name = key.StartsWith("Vk") ? key.Substring(2) : key;
            Members = new List<VkStructMember>();
        }

        public string Key { get; private set; }
        public string Name { get; set; }
        public List<VkStructMember> Members { get; private set; }
        public bool IsOut { get; internal set; }
    }
}