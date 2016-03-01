namespace VulkanT4
{
    public class VkHandle
    {
        public VkHandle(string key)
        {
            this.Key = key;
            this.Name = key.StartsWith("Vk") ? key.Substring(2) : key;
        }

        public string Key { get; private set; }
        public string Name { get; private set; }
    }
}