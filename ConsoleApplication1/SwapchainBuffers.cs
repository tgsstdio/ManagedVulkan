namespace ConsoleApplication1
{
    public class SwapchainBuffers
    {
        public ManagedVulkan.Image Image { get; set; }
        public ManagedVulkan.CommandBuffer Cmd { get; set; }
        public ManagedVulkan.ImageView View { get; set; }
    }
}
