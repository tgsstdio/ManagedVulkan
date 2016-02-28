using System;
using System.Linq;
using System.Xml.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace VulkanT4.UnitTests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void Example()
        {
            string xml =
               @"<commands>
                    <command successcodes=""VK_SUCCESS"" errorcodes=""VK_ERROR_OUT_OF_HOST_MEMORY,VK_ERROR_OUT_OF_DEVICE_MEMORY,VK_ERROR_INITIALIZATION_FAILED,VK_ERROR_LAYER_NOT_PRESENT,VK_ERROR_EXTENSION_NOT_PRESENT,VK_ERROR_INCOMPATIBLE_DRIVER"">
                        <proto><type>VkResult</type> <name>vkCreateInstance</name></proto>
                        <param>const <type>VkInstanceCreateInfo</type>* <name>pCreateInfo</name></param>
                        <param optional=""true"">const <type> VkAllocationCallbacks </type> * <name> pAllocator </name></param>
                        <param><type> VkInstance </type> * <name> pInstance </name></param>
                    </command>
                </commands>";
            var doc = XDocument.Parse(xml);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Functions.Count);
            var fn = generator.Functions[0];
            Assert.AreEqual("vkCreateInstance", fn.Key);
            Assert.AreEqual("CreateInstance", fn.Name);
            Assert.AreEqual("VkResult", fn.ReturnType);
            Assert.IsNotNull(fn.SuccessCodes);
            Assert.AreEqual(1, fn.SuccessCodes.Length);
            Assert.IsNotNull(fn.FailureCodes);
            Assert.AreEqual(6, fn.FailureCodes.Length);
            Assert.AreEqual(3, fn.Parameters.Count);
        }

        [TestMethod]
        public void ConstPointerParam()
        {
            string xml =
               @"<commands>
                    <command>
                        <proto><type>VkResult</type> <name>vkCreateInstance</name></proto>
                        <param>const <type>VkInstanceCreateInfo</type>* <name>pCreateInfo</name></param>
                    </command>
                </commands>";
            var doc = XDocument.Parse(xml);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Functions.Count);
            var fn = generator.Functions[0];
            Assert.AreEqual("vkCreateInstance", fn.Key);
            Assert.AreEqual("CreateInstance", fn.Name);
            Assert.AreEqual("VkResult", fn.ReturnType);
            Assert.IsNotNull(fn.SuccessCodes);
            Assert.AreEqual(0, fn.SuccessCodes.Length);
            Assert.IsNotNull(fn.FailureCodes);
            Assert.AreEqual(0, fn.FailureCodes.Length);
            Assert.AreEqual(1, fn.Parameters.Count);

            var param = fn.Parameters[0];
            Assert.AreEqual("const VkInstanceCreateInfo* pCreateInfo", param.Text);
            Assert.AreEqual(3, param.Tokens.Length);
            Assert.AreEqual("const", param.Tokens[0]);
            Assert.AreEqual("VkInstanceCreateInfo*", param.Tokens[1]);
            Assert.AreEqual("pCreateInfo", param.Tokens[2]);
        }


        [TestMethod]
        public void InXmlFile()
        {
            string xml =
               @"<?xml version=""1.0"" encoding=""UTF - 8""?>
                <registry>
                    <commands>
                        <command>
                            <proto><type>VkResult</type> <name>vkCreateInstance</name></proto>
                            <param>const <type>VkInstanceCreateInfo</type>* <name>pCreateInfo</name></param>
                        </command>
                        <command>
                            <proto><type>VkResult</type> <name>vkDeleteInstance</name></proto>
                        </command>
                    </commands>                    
                </registry>";
            var doc = XDocument.Parse(xml);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(2, generator.Functions.Count);

            var first = generator.Functions[0];
            Assert.AreEqual("vkCreateInstance", first.Key);
            Assert.AreEqual("CreateInstance", first.Name);
            Assert.AreEqual("VkResult", first.ReturnType);
            Assert.IsNotNull(first.SuccessCodes);
            Assert.AreEqual(0, first.SuccessCodes.Length);
            Assert.IsNotNull(first.FailureCodes);
            Assert.AreEqual(0, first.FailureCodes.Length);
            Assert.AreEqual(1, first.Parameters.Count);

            var second = generator.Functions[1];
            Assert.AreEqual("vkDeleteInstance", second.Key);
            Assert.AreEqual("DeleteInstance", second.Name);
            Assert.AreEqual("VkResult", second.ReturnType);
            Assert.IsNotNull(second.SuccessCodes);
            Assert.AreEqual(0, second.SuccessCodes.Length);
            Assert.IsNotNull(second.FailureCodes);
            Assert.AreEqual(0, second.FailureCodes.Length);
            Assert.AreEqual(0, second.Parameters.Count);

        }

        [TestMethod]
        public void ParseVkXML()
        {
            var doc = XDocument.Load("vk.xml");
            IVkAPIGenerator generator = new VkAPIGenerator();

            bool hasFailed = false;
            try
            {
                generator.Apply(doc);
            }
            catch (Exception ex)
            {
                hasFailed = true;
            }
            Assert.IsFalse(hasFailed);
        }
    }
}
