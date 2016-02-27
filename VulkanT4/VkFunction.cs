using System.Collections.Generic;

namespace VulkanT4
{
    public class VkFunction
    {
        public VkFunction(string name)
        {
            Name = name;
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
