using System.Collections.Generic;

namespace VulkanT4
{
    public class VkClassObject
    {
        public VkClassObject(string key)
        {
            Key = key;
            Name = Key.Substring(2);
            Functions = new List<VkFunction>();
        }

        public string Key { get; set; }
        public string Name { get; set; }
        public List<VkFunction> Functions { get; private set; }
    }
}
