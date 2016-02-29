using System.Collections.Generic;

namespace VulkanT4
{
    public class VkFunction
    {
        public VkFunction(string key)
        {
            Key = key;
            Name = key.StartsWith("vk") ? key.Substring(2) : key;
            Parameters = new List<VkFunctionParam>();
        }

        public string Name { get; set; }
        public string Key { get; set; }
        public List<VkFunctionParam> Parameters { get; private set; }
        public string ReturnType { get; set; }
        public string[] SuccessCodes { get; set; }
        public string[] FailureCodes { get; set; }
    }
}
