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
                        <param optional=""true"">const <type>VkAllocationCallbacks</type>* <name> pAllocator </name></param>
                        <param><type>VkInstance</type>* <name> pInstance </name></param>
                    </command>
                </commands>";
            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Functions.Count);
            var fn = generator.Functions.ElementAt(0);
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
            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
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

            Assert.AreEqual(1, generator.Proxies.Keys.Count);
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
            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
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

            Assert.AreEqual(1, generator.Proxies.Keys.Count);

        }

        [TestMethod]
        public void ParseStruct1()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkExtent3D"">
                        <member><type>uint32_t</type>        <name>width</name></member>
                        <member optional=""true""><type>uint32_t</type>        <name>height</name></member>
                        <member optional=""true"" len=""null - terminated"">const <type>char</type>*     <name>pEngineName</name></member>

                        </type>
                </registry>";
            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(0, generator.Functions.Count);
            Assert.AreEqual(1, generator.Structs.Keys.Count);
            var item = generator.Structs.Values.ElementAt(0);
            Assert.AreEqual("VkExtent3D", item.Key);
            Assert.AreEqual("Extent3D", item.Name);
            Assert.AreEqual(3, item.Members.Count);

            var member_0 = item.Members[0];
            Assert.AreEqual("width", member_0.Key);
            Assert.AreEqual("Width", member_0.Name);
            Assert.AreEqual("mWidth", member_0.FieldName);
            Assert.AreEqual("uint32_t", member_0.CppType);
            Assert.AreEqual("UInt32", member_0.CSharpType);
            Assert.IsFalse(member_0.Optional);
            Assert.IsNotNull(member_0.LengthConditions);
            Assert.AreEqual(0, member_0.LengthConditions.Length);

            var member_1 = item.Members[1];
            Assert.AreEqual("height", member_1.Key);
            Assert.AreEqual("Height", member_1.Name);
            Assert.AreEqual("mHeight", member_1.FieldName);
            Assert.AreEqual("uint32_t", member_1.CppType);
            Assert.AreEqual("UInt32", member_1.CSharpType);
            Assert.IsTrue(member_1.Optional);
            Assert.IsNotNull(member_1.LengthConditions);
            Assert.AreEqual(0, member_1.LengthConditions.Length);

            var member_2 = item.Members[2];
            Assert.AreEqual("pEngineName", member_2.Key);
            Assert.AreEqual("EngineName", member_2.Name);
            Assert.AreEqual("mEngineName", member_2.FieldName);
            Assert.AreEqual("char*", member_2.CppType);
            Assert.AreEqual("String^", member_2.CSharpType);
            Assert.IsTrue(member_2.Optional);
            Assert.IsNotNull(member_2.LengthConditions);
            Assert.AreEqual(1, member_2.LengthConditions.Length);
            Assert.AreEqual("null - terminated", member_2.LengthConditions[0]);
        }

        [TestMethod]
        public void ParseStruct2()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkExtent3D"">
                        <member><type>char</type>            <name>layerName</name>[<enum>VK_MAX_EXTENSION_NAME_SIZE</enum>]</member> <!-- layer name -->
                    </type>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(0, generator.Functions.Count);
            Assert.AreEqual(1, generator.Structs.Keys.Count);
            var item = generator.Structs.Values.ElementAt(0);
            Assert.AreEqual("VkExtent3D", item.Key);
            Assert.AreEqual("Extent3D", item.Name);
            Assert.AreEqual(1, item.Members.Count);

            var member = item.Members[0];
            Assert.AreEqual("layerName", member.Key);
            Assert.AreEqual("LayerName", member.Name);
            Assert.AreEqual("mLayerName", member.FieldName);
            Assert.AreEqual("char[]", member.CppType);
            Assert.AreEqual("String^", member.CSharpType);
            Assert.IsFalse(member.Optional);
            Assert.IsNotNull(member.LengthConditions);
            Assert.AreEqual(0, member.LengthConditions.Length);
        }

        [TestMethod]
        public void ParseStruct3()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkExtent3D"">
                        <member len=""enabledExtensionCount,null - terminated"">const <type>char</type>* const*      <name>ppEnabledExtensionNames</name></member>
                    </type>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(0, generator.Functions.Count);
            Assert.AreEqual(1, generator.Structs.Keys.Count);
            var item = generator.Structs.Values.ElementAt(0);
            Assert.AreEqual("VkExtent3D", item.Key);
            Assert.AreEqual("Extent3D", item.Name);
            Assert.AreEqual(1, item.Members.Count);

            var member = item.Members[0];
            Assert.AreEqual("ppEnabledExtensionNames", member.Key);
            Assert.AreEqual("EnabledExtensionNames", member.Name);
            Assert.AreEqual("mEnabledExtensionNames", member.FieldName);
            Assert.AreEqual("const char* const*", member.CppType);
            Assert.AreEqual("array<String^>^", member.CSharpType);
            Assert.IsFalse(member.Optional);
            Assert.IsNotNull(member.LengthConditions);
            Assert.AreEqual(2, member.LengthConditions.Length);
            Assert.AreEqual("enabledExtensionCount", member.LengthConditions[0]);
            Assert.AreEqual("null - terminated", member.LengthConditions[1]);
        }

        [TestMethod]
        public void IgnoreInDeclaration()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkExtent3D"">
                        <member>const <type>void</type>*            <name>pNext</name></member>
                    </type>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(0, generator.Functions.Count);
            Assert.AreEqual(1, generator.Structs.Keys.Count);
            var item = generator.Structs.Values.ElementAt(0);
            Assert.AreEqual("VkExtent3D", item.Key);
            Assert.AreEqual("Extent3D", item.Name);
            Assert.AreEqual(1, item.Members.Count);

            var member = item.Members[0];
            Assert.AreEqual("pNext", member.Key);
            Assert.AreEqual("pNext", member.Name);
            Assert.AreEqual("pNext", member.FieldName);
            Assert.AreEqual("void*", member.CppType);
            Assert.AreEqual("IntPtr", member.CSharpType);
            Assert.IsFalse(member.Optional);
            Assert.IsNotNull(member.LengthConditions);
            Assert.AreEqual(0, member.LengthConditions.Length);
            Assert.IsFalse(member.IncludeInDeclaration);
        }

        [TestMethod]
        public void ParseUnion()
        {
            string xml =
               @"<registry>
                    <type category=""union"" name=""VkClearColorValue"" comment=""// Union allowing specification of floating point, integer, or unsigned integer color data. Actual value selected is based on image/attachment being cleared."">
                        <member><type>float</type>                  <name>float32</name>[4]</member>
                        <member><type>int32_t</type>                <name>int32</name>[4]</member>
                        <member><type>uint32_t</type>               <name>uint32</name>[4]</member>
                    </type>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Unions.Keys.Count);
            var item = generator.Unions.Values.ElementAt(0);
            Assert.AreEqual("VkClearColorValue", item.Key);
            Assert.AreEqual("ClearColorValue", item.Name);
            // TODO : PARSE ALL VALUES

            Assert.AreEqual(3, item.Members.Count);
        }

        [TestMethod]
        public void StructReusedForHandleTranslated()
        {
            string xml =
               @"<registry>
                    <type category=""handle""><type>VK_DEFINE_HANDLE</type>(<name>VkInstance</name>)</type>
                    <command>
                        <proto><type>VkBool32</type> <name>vkGetDeviceQueue</name></proto>
                        <param><type>VkInstance</type> <name>instance</name></param>
                    </command>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(0, generator.Handles.Keys.Count);
            Assert.AreEqual(2, generator.Proxies.Keys.Count);
            Assert.AreEqual(1, generator.Functions.Count);
            var proxy = generator.Proxies.Values.ElementAt(0);
            Assert.AreEqual("Vulkan", proxy.Key);
            var function = generator.Functions.ElementAt(0);
            Assert.AreEqual("vkGetDeviceQueue", function.Key);
            Assert.AreEqual(1, function.Parameters.Count);
            proxy = generator.Proxies.Values.ElementAt(1);
            Assert.AreEqual("VkInstance", proxy.Key);
            Assert.AreEqual(1, proxy.Methods.Count);
            var method = proxy.Methods[0];
            Assert.AreEqual("GetDeviceQueue", method.Name);
            Assert.AreSame(method.Function, function);

            var param = function.Parameters[0];
            Assert.IsNotNull(param.Translation);
            Assert.IsNull(param.Translation.StructInfo);
            Assert.IsNotNull(param.Translation.ProxyInfo);
            Assert.AreSame(proxy, param.Translation.ProxyInfo);
        }

        [TestMethod]
        public void ParseDelegate()
        {
            string xml =
               @"<registry>
                    <type category=""funcpointer"">typedef void (VKAPI_PTR *<name>PFN_vkInternalAllocationNotification</name>)(
                    <type>void</type>*                                       pUserData,
                    <type>size_t</type>                                      size,
                    <type>VkInternalAllocationType</type>                    allocationType,
                    <type>VkSystemAllocationScope</type>                     allocationScope);</type>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Delegates.Count);
        }

        [TestMethod]
        public void ParseBool()
        {
            string xml =
               @"<registry>
                    <command>
                        <proto><type>VkBool32</type> <name>vkGetDeviceQueue</name></proto>
                    </command>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Proxies.Keys.Count);
            var proxy = generator.Proxies.Values.First();
            Assert.AreEqual(1, proxy.Methods.Count);
            var method = proxy.Methods[0];
            Assert.IsNotNull(method.Translation);
            Assert.IsNotNull(method.ReturnType);
            Assert.AreEqual("VkBool32", method.ReturnType);
            Assert.AreEqual("VkBool32", method.Translation.CppType);
        }

        [TestMethod]
        public void ParseCharArray()
        {
            string xml =
               @"<registry>
                    <command>
                        <proto><type>VkBool32</type> <name>vkGetDeviceQueue</name></proto>
                    </command>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Proxies.Keys.Count);
            var proxy = generator.Proxies.Values.First();
            Assert.AreEqual(1, proxy.Methods.Count);
            var method = proxy.Methods[0];
            Assert.IsNotNull(method.Translation);
            Assert.IsNotNull(method.ReturnType);
            Assert.AreEqual("VkBool32", method.ReturnType);
            Assert.AreEqual("VkBool32", method.Translation.CppType);
        }

        [TestMethod]
        public void ParseOddPointer()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkDisplayModeCreateInfoKHR""></type>
                    <command>
                        <proto><type>VkResult</type> <name>vkCreateDisplayModeKHR</name></proto>
                        <param><type>VkPhysicalDevice</type> <name>physicalDevice</name></param>
                        <param>const <type>VkDisplayModeCreateInfoKHR</type>*<name>pCreateInfo</name></param>
                    </command>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Structs.Keys.Count);
            Assert.AreEqual(2, generator.Proxies.Keys.Count);
            var proxy = generator.Proxies.Values.First();
            Assert.AreEqual("Vulkan", proxy.Name);
            Assert.AreEqual(0, proxy.Methods.Count);
            proxy = generator.Proxies.Values.ElementAt(1);
            Assert.AreEqual("PhysicalDevice", proxy.Name);
            Assert.AreEqual(1, proxy.Methods.Count);
            var method = proxy.Methods[0];
            Assert.AreEqual(1, method.Parameters.Count);
            var parameter = method.Parameters[0];
            Assert.IsNotNull(parameter.Translation);
            Assert.IsNotNull("VkDisplayModeCreateInfoKHR*", parameter.Translation.CppType);
        }

        [TestMethod]
        public void ParseByteArray()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkInfoStruct"" returnedonly=""true"">
                        <member><type>uint8_t</type>        <name>pipelineCacheUUID</name>[<enum>VK_UUID_SIZE</enum>]</member>
                        <member><type>char</type>           <name>deviceName</name>[<enum>VK_MAX_PHYSICAL_DEVICE_NAME_SIZE</enum>]</member>
                    </type>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Structs.Keys.Count);
            var item = generator.Structs.Values.ElementAt(0);
            Assert.AreEqual("VkInfoStruct", item.Key);
            Assert.AreEqual("InfoStruct", item.Name);
            Assert.AreEqual(2, item.Members.Count);

            var member = item.Members[0];
            Assert.AreEqual("pipelineCacheUUID", member.Key);
            Assert.AreEqual("PipelineCacheUUID", member.Name);
            Assert.AreEqual("mPipelineCacheUUID", member.FieldName);
            Assert.AreEqual("byte[]", member.CppType);
            Assert.AreEqual("array<byte>^", member.CSharpType);

            member = item.Members[1];
            Assert.AreEqual("deviceName", member.Key);
            Assert.AreEqual("DeviceName", member.Name);
            Assert.AreEqual("mDeviceName", member.FieldName);
            Assert.AreEqual("char[]", member.CppType);
            Assert.AreEqual("String^", member.CSharpType);
        }

        [TestMethod]
        public void ParseNullTerminatorParam()
        {
            string xml =
               @"<registry>
                    <type category=""struct"" name=""VkExtensionProperties"" returnedonly=""true"">
                    </type>
                    <command>
                        <proto><type>VkResult</type> <name>vkEnumerateInstanceExtensionProperties</name></proto>
                        <param optional=""true"" len=""null-terminated"">const <type>char</type>* <name>pLayerName</name></param>
                        <param optional=""false,true""><type>uint32_t</type>* <name>pPropertyCount</name></param>
                        <param optional=""true"" len=""pPropertyCount""><type>VkExtensionProperties</type>* <name>pProperties</name></param>
                    </command>
                </registry>";

            var doc = XDocument.Parse(xml, LoadOptions.PreserveWhitespace);
            IVkAPIGenerator generator = new VkAPIGenerator();
            generator.Apply(doc);
            Assert.AreEqual(1, generator.Proxies.Keys.Count);
            var proxy = generator.Proxies.Values.ElementAt(0);
            Assert.AreEqual("Vulkan", proxy.Name);
            Assert.AreEqual(1, proxy.Methods.Count);
            var method = proxy.Methods[0];
            Assert.AreEqual(2, method.Parameters.Count);
            var param = method.Parameters[0];
            Assert.AreEqual("char*", param.CppType);
            Assert.IsNotNull(param.Translation);
            Assert.AreEqual("String^", param.Translation.CSharpType);
            Assert.AreEqual("pLayerName", param.Name);
            param = method.Parameters[1];
            Assert.AreEqual("VkExtensionProperties*", param.CppType);
            Assert.IsNotNull(param.Translation);
            Assert.AreEqual("ExtensionProperties^", param.CSharpType);
            Assert.IsTrue(param.IsArray);
            Assert.AreEqual("pProperties", param.Name);
            Assert.IsTrue(param.UseOutStatement);
        }

        [TestMethod]
        public void ParseVkXML()
        {
            var doc = XDocument.Load("vk.xml", LoadOptions.PreserveWhitespace);
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
            Assert.AreEqual(73, generator.Enums.Count);
        }
    }
}
