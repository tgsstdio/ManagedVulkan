using System.Globalization;

namespace VulkanT4
{
    public class VkStructMember
    {
        public VkStructMember()
        {
            Optional = false;
            IncludeInDeclaration = true;
        }

        public string CppType { get; set; }
        public string CSharpType { get; set; }
        public string Key { get; set; }
        public string Name { get; set; }
        public string FieldName { get; set; }
        public bool Optional { get; set; }
        public string[] LengthConditions { get; set; }
        public string EnumValue { get; internal set; }

        public bool IncludeInDeclaration { get; set; }
        public VkTypeTranslation Translation { get; set; }
    }
}