using System;
using System.Text;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace VulkanT4.UnitTests
{
    /// <summary>
    /// Summary description for UnitTest2
    /// </summary>
    [TestClass]
    public class FunctionStackTest
    {
        public FunctionStackTest()
        {
            //
            // TODO: Add constructor logic here
            //
        }

        private TestContext testContextInstance;

        /// <summary>
        ///Gets or sets the test context which provides
        ///information about and functionality for the current test run.
        ///</summary>
        public TestContext TestContext
        {
            get
            {
                return testContextInstance;
            }
            set
            {
                testContextInstance = value;
            }
        }

        #region Additional test attributes
        //
        // You can use the following additional attributes as you write your tests:
        //
        // Use ClassInitialize to run code before running the first test in the class
        // [ClassInitialize()]
        // public static void MyClassInitialize(TestContext testContext) { }
        //
        // Use ClassCleanup to run code after all tests in a class have run
        // [ClassCleanup()]
        // public static void MyClassCleanup() { }
        //
        // Use TestInitialize to run code before running each test 
        // [TestInitialize()]
        // public void MyTestInitialize() { }
        //
        // Use TestCleanup to run code after each test has run
        // [TestCleanup()]
        // public void MyTestCleanup() { }
        //
        #endregion

        /// <summary>
        /// 
        /// </summary>
        [TestMethod]
        public void TestMethod1()
        {
            var subLevel = new VkStruct("VkApplicationInfo");
            var enumType = new VkEnum { Name = "VkStructureType" };

            var enumTypeTranslation = new VkTypeTranslation { CppType = "VkStructureType*", EnumInfo = enumType, NeedsNamespace = true, };
            var subLevelTranslation = new VkTypeTranslation { CppType = "VkApplicationInfo*", StructInfo = subLevel, NeedsNamespace = true, };
            var charArrayTranslation = new VkTypeTranslation { CppType = "const char* const*", NeedsNamespace = false };

            var topLevel = new VkStruct("VkInstanceCreateInfo");
            var member = new VkStructMember { Key = "sType", Translation = enumTypeTranslation };
            Assert.IsNotNull(member.Translation);
            topLevel.Members.Add(member);
            member = new VkStructMember { Key = "pApplicationInfo", Translation = subLevelTranslation };
            Assert.IsNotNull(member.Translation);
            topLevel.Members.Add(member);
            member = new VkStructMember { Key = "ppEnabledExtensionNames", Translation = charArrayTranslation };
            topLevel.Members.Add(member);
            Assert.IsNotNull(member.Translation);
            Assert.AreEqual(3, topLevel.Members.Count);

            var topLevelTranslation = new VkTypeTranslation { CppType = "VkInstanceCreateInfo*", NeedsNamespace = false, StructInfo = topLevel };
            Assert.IsNotNull(topLevelTranslation.StructInfo);

            var fn = new VkFunction("vkCreateInstance");

            VkFunctionParam input = null;

            input = new VkFunctionParam { Index = 0, Name = "pCreateInfo", Translation = topLevelTranslation };
            Assert.IsNotNull(input.Translation);
            fn.Parameters.Add(input);

            var callback = new VkStruct("VkAllocationCallbacks");
            var callBackTranslation = new VkTypeTranslation { CppType = "VkAllocationCallbacks*", StructInfo = callback };

            input = new VkFunctionParam { Index = 1, Name = "pAllocator", Translation = callBackTranslation };
            Assert.IsNotNull(input.Translation);
            fn.Parameters.Add(input);

            var instanceType = new VkProxy("VkInstance");
            var instTranslation = new VkTypeTranslation { CppType = "VkInstance*", NeedsNamespace = true, ProxyInfo = instanceType };
            Assert.IsNotNull(instTranslation.ProxyInfo);

            input = new VkFunctionParam { Index = 2, Name = "pInstance", UseOutStatement = true, Translation = instTranslation };
            Assert.IsNotNull(input.Translation);
            fn.Parameters.Add(input);

            Assert.AreEqual(3, fn.Parameters.Count);

            IVariableDeclaration declarer = new VariableDeclaration();
            List<VkCommand> commands = declarer.Parse(fn);

            Assert.AreEqual(5, commands.Count);
            var command = commands[0];
            Assert.AreEqual("arg_0", command.ArgumentName);
            Assert.AreSame(topLevelTranslation, command.MemberType);

            command = commands[1];
            Assert.AreEqual("arg_0_1", command.ArgumentName);
            Assert.AreSame(subLevelTranslation, command.MemberType);

            command = commands[2];
            Assert.AreEqual("arg_0_2", command.ArgumentName);
            Assert.AreSame(charArrayTranslation, command.MemberType);

            command = commands[3];
            Assert.AreEqual("arg_1", command.ArgumentName);
            Assert.AreSame(callBackTranslation, command.MemberType);

            command = commands[4];
            Assert.AreEqual("arg_2", command.ArgumentName);
            Assert.AreSame(instTranslation, command.MemberType);
        }

    }
}
