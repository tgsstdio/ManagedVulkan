namespace VulkanT4
{
    public class VkArrayFunctionInfo
    {
        public VkArrayFunctionInfo(string key, bool keepCounts)
        {
            Key = key;
            KeepCounts = keepCounts;
        }
        public string Key { get; private set; }
        public bool KeepCounts { get; private set; }
    }
}
