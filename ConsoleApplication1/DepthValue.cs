using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public class DepthValue
    {
        public ManagedVulkan.Format Format { get; set; }
        public ManagedVulkan.Image Image { get; set; }
        public ManagedVulkan.MemoryAllocateInfo MemAlloc { get; set; }
        public ManagedVulkan.DeviceMemory Mem { get; set; }
        public ManagedVulkan.ImageView View { get; set; }
    }
}
