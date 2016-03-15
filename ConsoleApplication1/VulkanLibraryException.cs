using System;

namespace ConsoleApplication1
{
    public class VulkanLibraryException : Exception
    {
        public string Category { get; set; }

        public VulkanLibraryException(string category, string message) : base(message)
        {
            Category = category;            
        }
    }
}
