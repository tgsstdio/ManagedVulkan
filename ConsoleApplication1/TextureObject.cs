namespace ConsoleApplication1
{
    public class TextureObject
    {
        public ManagedVulkan.Sampler Sampler { get; set; }
        public ManagedVulkan.Image Image { get; set; }
        public ManagedVulkan.ImageLayout ImageLayout { get; set; }
        public ManagedVulkan.MemoryAllocateInfo MemAlloc { get; set; }
        public ManagedVulkan.DeviceMemory Mem { get; set; }
        public ManagedVulkan.ImageView View { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
    }
}
