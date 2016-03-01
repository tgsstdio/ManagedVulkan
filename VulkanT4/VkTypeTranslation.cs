namespace VulkanT4
{
    public class VkTypeTranslation
    {
        public string AsOut { get; internal set; }
        public string CppType { get; set; }
        public string CSharpType { get; set; }
        public string Default { get; set; }
        public string MethodOnly { get; set; }
        public bool NeedsNamespace { get; set; }
    }
}
