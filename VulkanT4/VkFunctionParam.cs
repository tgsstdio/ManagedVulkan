using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VulkanT4
{
    public class VkFunctionParam
    {
        public string Text { get; set; }
        public string[] Tokens { get; set; }
        public string CppType { get; set; }
        public string Name { get; set; }
        public string CSharpType { get; set; }
    }
}
