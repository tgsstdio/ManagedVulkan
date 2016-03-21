using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    public class UniformData
    {
        public ManagedVulkan.Buffer Buf { get; set; }
        public ManagedVulkan.MemoryAllocateInfo MemAlloc { get; set; }
        public ManagedVulkan.DeviceMemory Mem { get; set; }
        public ManagedVulkan.DescriptorBufferInfo BufferInfo { get; set; }
    }
}
