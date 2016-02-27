using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VulkanT4
{
    public class VkClassMethod
    {
        public VkClassMethod(VkFunction func)
        {
            Name = func.Name.Substring(2);
            Parameters = func.Parameters.Skip(1).ToList();
        }

        public string Name { get; set; }
        public List<VkFunctionParam> Parameters { get; set; }
    }
}
