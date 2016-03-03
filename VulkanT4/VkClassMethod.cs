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
            Name = func.Name;
            //Parameters = func.Parameters.Skip(1).ToList();
            Function = func;
            ReturnType = func.ReturnType;
        }

        public string ReturnType { get; set; }
        public VkTypeTranslation Translation { get; set; }
        public VkFunction Function { get; private set; }
        public string Name { get; set; }
        public List<VkFunctionParam> Parameters { get; set; }
        public VkArrayFunctionInfo ArrayInfo { get; set; }
    }
}
