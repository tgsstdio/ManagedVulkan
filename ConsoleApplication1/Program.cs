using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    using vK = ManagedVulkan.Vulkan;

    class Program
    {
        static void Main(string[] args)
        {
            var extensions = vK.EnumerateInstanceExtensionProperties();

            foreach(var ext in extensions)
            {
                Console.WriteLine("Length : " + ext.SpecVersion + " - " + ext.ExtensionName);
            }
            
            /**
            ManagedVulkan.CreateInstanceInfo info = new ManagedVulkan.CreateInstanceInfo()
            {
                EnabledExtensionNames = extensions,
            };
            **/

            //ManagedVulkan.Instance inst = vK.CreateInstance(info);
        }
    }
}
