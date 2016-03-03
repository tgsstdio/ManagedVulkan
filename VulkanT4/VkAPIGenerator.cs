using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;

namespace VulkanT4
{
    public class VkAPIGenerator : IVkAPIGenerator
    {

        public VkAPIGenerator()
        {
            mFunctions = new List<VkFunction>();
            mProxies = new Dictionary<string, VkProxy>();
            mStructs = new Dictionary<string, VkStruct>();
            mEnums = new List<VkEnum>();
            mHandles = new Dictionary<string, VkHandle>();
            mDelegates = new List<VkFunction>();
            mUnions = new Dictionary<string, VkStruct>();
        }

        private List<VkFunction> mFunctions;
        public IList<VkFunction> Functions
        {
            get
            {
                return mFunctions;
            }

        }

        private Dictionary<string, VkProxy> mProxies;
        public IDictionary<string, VkProxy> Proxies
        {
            get
            {
                return mProxies;
            }               
        }

        private Dictionary<string, VkStruct> mStructs;
        public IDictionary<string, VkStruct> Structs
        {
            get
            {
                return mStructs;
            }
        }

        private List<VkEnum> mEnums;
        public IList<VkEnum> Enums
        {
            get
            {
                return mEnums;
            }
        }

        private Dictionary<string, VkHandle> mHandles;
        public IDictionary<string, VkHandle> Handles
        {
            get
            {
                return mHandles;
            }
        }

        private List<VkFunction> mDelegates;
        public IList<VkFunction> Delegates
        {
            get
            {
                return mDelegates;
            }
        }

        private Dictionary<string, VkStruct> mUnions;
        public IDictionary<string, VkStruct> Unions
        {
            get
            {
                return mUnions;
            }
        }

        /// <summary>
        /// YOU NEED TO SET THIS UP LATER
        /// </summary>
        private Vk_WindowingInterface mAllowableInterfaces = Vk_WindowingInterface.Windows;
        public void Apply(XDocument doc)
        {
            InitialiseLookups();
            GenerateTranslations();
            ExtractEnumsAndMasks(doc);
            ExtractStructs(doc);
            ExtractFunctions(doc);
            ExtractHandles(doc);
            ExtractDelegates(doc);
            RetranslateStructMembers();
            RetranslateProxies();
            RetranslateDelegates();
            RetranslateFunctions();
        }

        private void RetranslateFunctions()
        {
            foreach(var f in mFunctions)
            {
                foreach (var param in f.Parameters)
                {
                    if (param.Translation == null)
                    {
                        VkTypeTranslation translation = null;
                        if (mTranslations.TryGetValue(param.CppType, out translation))
                        {
                            param.Translation = translation;
                        }
                    }
                }
            }
        }

        private void RetranslateDelegates()
        {
            // second pass to match
            foreach (var s in mDelegates)
            {
                foreach (var m in s.Parameters)
                {
                    if (m.Translation == null)
                    {
                        VkTypeTranslation sharpType = null;
                        if (mTranslations.TryGetValue(m.CppType, out sharpType))
                        {
                            m.CSharpType = sharpType.CSharpType;
                            m.Translation = sharpType;
                        }
                    }
                }
            }
        }

        private void ExtractDelegates(XDocument doc)
        {
            foreach (var child in doc.Root.Descendants("type"))
            {
                var category = child.Attribute("category");

                if (category != null && category.Value == "funcpointer")
                {
                    var name = child.Element("name");
                    if (name != null)
                    {
                        var key = name.Value;
                        var del = new VkFunction(key);

                        // remove extra white spaces
                        string fullText = string.Join(" ", child.Value.Split(new[] { " ", "\n" }, StringSplitOptions.RemoveEmptyEntries));
                        var bracketTokens = fullText.Split(new[] { "(", ")" }, StringSplitOptions.RemoveEmptyEntries);
                        var paramTokens = bracketTokens[2].Split(',');

                        foreach (var token in paramTokens)
                        {
                            var argStmt = token.Trim();
                            var arguments = argStmt.Split(' ');

                            if (arguments.Length > 1)
                            {
                                var p = new VkFunctionParam();
                                p.Text = argStmt;
                                p.Tokens = arguments;

                                if (p.Tokens.Length == 2)
                                {
                                    p.CppType = p.Tokens[0];
                                    p.Name = p.Tokens[1];
                                }
                                else if (p.Tokens.Length == 3)
                                {
                                    p.CppType = p.Tokens[1];
                                    p.Name = p.Tokens[2];
                                }

                                del.Parameters.Add(p);
                            }
                        }

                        mDelegates.Add(del);

                        if (!mTranslations.ContainsKey(del.Key))
                        {
                            mTranslations.Add(del.Key,
                                new VkTypeTranslation {
                                    CppType = del.Key,
                                    CSharpType = del.Name + "^",
                                    Default = " = nullptr;",
                                    MethodOnly = del.Name + "^",
                                    NeedsNamespace = true,
                                    DelegateInfo = del });
                        }
                    }
                }
            }
        }

        private void ExtractHandles(XDocument doc)
        {
            foreach (var child in doc.Root.Descendants("type"))
            {
                var category = child.Attribute("category");

                if (category != null && category.Value == "handle")
                {
                    var name = child.Element("name");
                    if (name != null && !(mTranslations.ContainsKey(name.Value) || mTranslations.ContainsKey(name.Value + "*")))
                    {
                        var h = new VkHandle(name.Value);
                        mHandles.Add(h.Key, h);

                        if (!mTranslations.ContainsKey(h.Key))
                        {
                            mTranslations.Add(h.Key, new VkTypeTranslation { CppType = h.Key, CSharpType = h.Name + "^", Default = " = nullptr;", MethodOnly = h.Name + "^", NeedsNamespace = true, HandleInfo = h });
                        }

                        var pointerStmt = h.Key + "*";
                        if (!mTranslations.ContainsKey(pointerStmt))
                        {
                            mTranslations.Add(pointerStmt, new VkTypeTranslation { CppType = pointerStmt, CSharpType = h.Name + "^", Default = " = nullptr;", MethodOnly = h.Name + "^", NeedsNamespace = true, HandleInfo = h });
                        }
                    }
                }
            }
        }

        private void ExtractEnumsAndMasks(XDocument doc)
        {
            // get all commands
            foreach (var child in doc.Root.Descendants("enums"))
            {
                var type = child.Attribute("type");
                if (type != null)
                {
                    string enumType = type.Value;
                    if (enumType == "enum" || enumType == "bitmask")
                    {
                        var el = new VkEnum();
                        el.Name = child.Attribute("name").Value;
                        el.UseFlags = enumType == "bitmask";

                        var expand = child.Attribute("expand");
                        if (expand != null)
                        {
                            el.Expand = expand.Value;
                        }

                        foreach (var element in child.Descendants("enum"))
                        {
                            var item = new VkEnumItem();
                            item.Name = element.Attribute("name").Value;

                            var valueAttr = element.Attribute("value");
                            if (valueAttr != null)
                                item.Value = valueAttr.Value;

                            var bitPos = element.Attribute("bitpos");
                            if (bitPos != null)
                                item.BitPosition = bitPos.Value;

                            var comment = element.Attribute("comment");
                            if (comment != null)
                                item.Comment = comment.Value;

                            el.Items.Add(item);
                        }
                        mEnums.Add(el);

                        var pointerType = el.Name + "*";
                        // POINTER TYPE
                        mTranslations.Add(pointerType, new VkTypeTranslation { CppType = pointerType, CSharpType = el.Name, Default = " = nullptr;", MethodOnly = el.Name, EnumInfo = el });

                        // PLAIN TYPE
                        mTranslations.Add(el.Name, new VkTypeTranslation { CppType = el.Name, CSharpType = el.Name, Default = " = nullptr;", MethodOnly = el.Name, EnumInfo = el });
                    }
                    
                }
            }
        }

        private static bool CheckForStringArray(string[] tokens)
        {
            return tokens.Length == 4 && tokens[0] == "const" && tokens[1] == "char*" && tokens[2] ==  "const*";
        }

        private static bool IsNextPointer(string[] tokens)
        {
            return tokens.Length == 3 && tokens[0] == "const" && tokens[1] == "void*" && tokens[2] == "pNext";
        }


        private class CleanPrefixRule
        {
            public Func<string, bool> Rule { get; set; }
            public int Length { get; set; }
        }

        private void ExtractStructs(XDocument doc)
        {
            // get all commands
            foreach (var child in doc.Root.Descendants("type"))
            {
                var category = child.Attribute("category");

                if (category != null)
                {
                    if (category.Value == "struct")
                    {

                        var name = child.Attribute("name");

                        string keyValue = name.Value;

                        Vk_WindowingInterface match;
                        bool isWindowingStruct = mWindowingStructs.TryGetValue(keyValue, out match);

                        /// ONLY SPECIFIC WINDOWING FUNCTIONS ALLOWED
                        if (!isWindowingStruct || (isWindowingStruct && match == mAllowableInterfaces))
                        {
                            var s = ExtractStruct(child, keyValue);
                            mStructs.Add(keyValue, s);

                            // POINTERS
                            var pointerStmt = s.Key + "*";
                            if (!mTranslations.ContainsKey(pointerStmt))
                            {
                                var item = new VkTypeTranslation
                                {
                                    CppType = s.Key + "*",
                                    CSharpType = s.Name + "^",
                                    Default = " = nullptr;",
                                    MethodOnly = s.Name + "^",
                                    NeedsNamespace = true,
                                    StructInfo = s
                                };
                                mTranslations.Add(pointerStmt, item);
                            }

                            if (!mTranslations.ContainsKey(s.Key))
                            {
                                var item2 = new VkTypeTranslation
                                {
                                    CppType = s.Key,
                                    CSharpType = s.Name + "^",
                                    Default = " = nullptr;",
                                    MethodOnly = s.Name + "^",
                                    NeedsNamespace = true,
                                    StructInfo = s
                                };
                                mTranslations.Add(item2.CppType, item2);
                            }
                        }
                    }
                    else if (category.Value == "union")
                    {
                        var name = child.Attribute("name");

                        string keyValue = name.Value;

                        var s = ExtractStruct(child, keyValue);
                        mUnions.Add(keyValue, s);                        

                        // POINTERS
                        var pointerStmt = s.Key + "*";
                        if (!mTranslations.ContainsKey(pointerStmt))
                        {
                            var item = new VkTypeTranslation
                            {
                                CppType = s.Key + "*",
                                CSharpType = s.Name + "^",
                                Default = " = nullptr;",
                                MethodOnly = s.Name + "^",
                                NeedsNamespace = true,
                                StructInfo = s
                            };
                            mTranslations.Add(pointerStmt, item);
                        }

                        if (!mTranslations.ContainsKey(s.Key))
                        {
                            var item2 = new VkTypeTranslation
                            {
                                CppType = s.Key,
                                CSharpType = s.Name + "^",
                                Default = " = nullptr;",
                                MethodOnly = s.Name + "^",
                                NeedsNamespace = true,
                                StructInfo = s
                            };
                            mTranslations.Add(item2.CppType, item2);
                        }
                    }
                }

            }
        }

        private VkStruct ExtractStruct(XElement child, string keyValue)
        {
            var s = new VkStruct(keyValue);

            var returnedOnly = child.Attribute("returnedonly");
            s.IsOut = (returnedOnly != null);

            foreach (var member in child.Descendants("member"))
            {
                var m = new VkStructMember();
                m.IncludeInDeclaration = true;
                var memberTokens = member.Value.Split(new[] { ' ', '[', ']' }, StringSplitOptions.RemoveEmptyEntries);

                if (IsNextPointer(memberTokens))
                {
                    m.IncludeInDeclaration = false;
                    m.FieldName = m.Name = m.Key = "pNext";
                    m.CppType = "void*";
                    m.CSharpType = "IntPtr";
                    m.LengthConditions = new string[0];
                }
                else if (memberTokens.Length == 2)
                {
                    m.CppType = memberTokens[0];
                    m.Key = memberTokens[1];
                }
                else if (memberTokens.Length == 3)
                {
                    var enumAttr = member.Element("enum");
                    // fixed char buffer for strings
                    if (enumAttr != null && memberTokens[0] == "char")
                    {
                        m.CppType = "char[]";
                        m.Key = memberTokens[1];
                        m.EnumValue = enumAttr.Value;
                    }
                    else
                    {
                        m.CppType = memberTokens[1];
                        m.Key = memberTokens[2];
                    }

                }
                else if (CheckForStringArray(memberTokens))
                {
                    m.CppType = "const char* const*";
                    m.Key = memberTokens[3];
                }
                else
                {
                    m.CppType = "<TYPE>";
                    m.Key = "<NAME>";
                }

                if (m.IncludeInDeclaration)
                {

                    VkTypeTranslation sharpType = null;
                    if (mTranslations.TryGetValue(m.CppType, out sharpType))
                    {
                        m.CSharpType = sharpType.CSharpType;
                        m.Translation = sharpType;
                    }
                    else
                    {
                        m.CSharpType = m.CppType;
                    }

                    var fieldName = m.Key;

                    var prefixes = new CleanPrefixRule[]{
                                new CleanPrefixRule { Rule = (str) => str.StartsWith("pp"), Length = 2 },
                                new CleanPrefixRule { Rule = (str) => str[0] == 'p' && char.IsUpper(str[1]), Length = 1 },
                            };

                    foreach (var pre in prefixes)
                    {
                        if (pre.Rule(fieldName))
                        {
                            fieldName = fieldName.Substring(pre.Length);
                            break;
                        }
                    }
                    m.Name = fieldName.Substring(0, 1).ToUpperInvariant() + fieldName.Substring(1);

                    m.FieldName = "m" + m.Name;

                    var optional = member.Attribute("optional");
                    m.Optional = (optional != null);

                    var len = member.Attribute("len");
                    if (len != null)
                    {
                        m.LengthConditions = len.Value.Split(new[] { ',' });
                    }
                    else
                    {
                        m.LengthConditions = new string[0];
                    }
                }

                s.Members.Add(m);
            }

            return s;
        }

        private void RetranslateStructMembers()
        {
            // second pass to match
            foreach (var s in mStructs.Values)
            {
                foreach (var m in s.Members)
                {
                    if (m.Translation == null)
                    {
                        VkTypeTranslation sharpType = null;
                        if (mTranslations.TryGetValue(m.CppType, out sharpType))
                        {
                            m.CSharpType = sharpType.CSharpType;
                            m.Translation = sharpType;
                        }
                    }
                }
            }
        }

        private void RetranslateProxies()
        {
            // second pass to match
            foreach (var proxy in mProxies.Values)
            {
                foreach (var method in proxy.Methods)
                {
                    if (!string.IsNullOrEmpty(method.ReturnType))
                    {
                        VkTypeTranslation sharpType = null;
                        if (mTranslations.TryGetValue(method.ReturnType, out sharpType))
                        {
                            method.Translation = sharpType;
                        }
                    }

                    foreach (var param in method.Parameters)
                    {
                        if (!string.IsNullOrEmpty(param.CppType))
                        {
                            VkTypeTranslation paramType = null;
                            if (mTranslations.TryGetValue(param.CppType, out paramType))
                            {
                                param.CSharpType = paramType.CSharpType;
                                param.Translation = paramType;
                            }
                        }
                    }
                }

                foreach (var method in proxy.Methods)
                {
                    FixCreateDisplayModeKHR(method);
                    ParseEnumerateMethods(method);
                    SetLastParameterAsOut(method);
                }
            }
        }

        private Dictionary<string, Vk_WindowingInterface> mWindowFunctions;
        private Dictionary<string, Vk_WindowingInterface> mWindowingStructs;
        private Dictionary<string, VkArrayFunctionInfo> mEnumerationFns;
        private void InitialiseLookups()
        {
            mWindowFunctions = new Dictionary<string, Vk_WindowingInterface>();
            mWindowingStructs = new Dictionary<string, Vk_WindowingInterface>();

            // STRUCTS
            mWindowingStructs.Add("VkAndroidSurfaceCreateInfoKHR", Vk_WindowingInterface.Android);
            mWindowingStructs.Add("VkMirSurfaceCreateInfoKHR", Vk_WindowingInterface.Mir);
            mWindowingStructs.Add("VkWaylandSurfaceCreateInfoKHR", Vk_WindowingInterface.Wayland);
            mWindowingStructs.Add("VkWin32SurfaceCreateInfoKHR", Vk_WindowingInterface.Windows);
            mWindowingStructs.Add("VkXlibSurfaceCreateInfoKHR", Vk_WindowingInterface.X11);
            mWindowingStructs.Add("VkXcbSurfaceCreateInfoKHR", Vk_WindowingInterface.XCB);

            // FUNCTIONS
            mWindowFunctions.Add("vkCreateAndroidSurfaceKHR", Vk_WindowingInterface.Android);
            mWindowFunctions.Add("vkCreateMirSurfaceKHR", Vk_WindowingInterface.Mir);
            mWindowFunctions.Add("vkCreateWaylandSurfaceKHR", Vk_WindowingInterface.Wayland);
            mWindowFunctions.Add("vkCreateWin32SurfaceKHR", Vk_WindowingInterface.Windows);
            mWindowFunctions.Add("vkCreateXlibSurfaceKHR", Vk_WindowingInterface.X11);
            mWindowFunctions.Add("vkCreateXcbSurfaceKHR", Vk_WindowingInterface.XCB);

            mWindowFunctions.Add("vkGetPhysicalDeviceWin32PresentationSupportKHR", Vk_WindowingInterface.Windows);           
            mWindowFunctions.Add("vkGetPhysicalDeviceWaylandPresentationSupportKHR", Vk_WindowingInterface.Wayland);
            mWindowFunctions.Add("vkGetPhysicalDeviceXcbPresentationSupportKHR", Vk_WindowingInterface.XCB);
            mWindowFunctions.Add("vkGetPhysicalDeviceXlibPresentationSupportKHR", Vk_WindowingInterface.X11);
            mWindowFunctions.Add("vkGetPhysicalDeviceMirPresentationSupportKHR", Vk_WindowingInterface.Mir);
         
            mEnumerationFns = new Dictionary<string, VkArrayFunctionInfo>();
            var arrayFn = new VkArrayFunctionInfo("vkGetImageSparseMemoryRequirements", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetSwapchainImagesKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetPhysicalDeviceQueueFamilyProperties", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetPhysicalDeviceSparseImageFormatProperties", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetPhysicalDeviceDisplayPropertiesKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetDisplayModePropertiesKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetPhysicalDeviceSurfaceFormatsKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkGetPhysicalDeviceSurfacePresentModesKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdPipelineBarrier", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdExecuteCommands", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdWaitEvents", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdResolveImage", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdClearAttachments", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdClearDepthStencilImage", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdClearColorImage", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdCopyImageToBuffer", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdCopyBufferToImage", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdBlitImage", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdCopyImage", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdCopyBuffer", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdBindVertexBuffers", true);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdBindDescriptorSets", true);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdSetScissor", true);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCmdSetViewport", true);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkFreeCommandBuffers", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkFlushMappedMemoryRanges", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkInvalidateMappedMemoryRanges", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCreateGraphicsPipelines", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCreateComputePipelines", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkMergePipelineCaches", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkCreateSharedSwapchainsKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkEnumerateInstanceLayerProperties", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkEnumerateInstanceExtensionProperties", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkEnumeratePhysicalDevices", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkEnumerateDeviceLayerProperties", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkEnumerateDeviceExtensionProperties", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);            

            arrayFn = new VkArrayFunctionInfo("vkGetPhysicalDeviceDisplayPlanePropertiesKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);            

            arrayFn = new VkArrayFunctionInfo("vkGetDisplayPlaneSupportedDisplaysKHR", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkResetFences", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkWaitForFences", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);            

            arrayFn = new VkArrayFunctionInfo("vkQueueBindSparse", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);

            arrayFn = new VkArrayFunctionInfo("vkQueueSubmit", false);
            mEnumerationFns.Add(arrayFn.Key, arrayFn);            

            string[] outMethods =
            {
                "vkEnumerateInstanceLayerProperties",
                "vkEnumerateInstanceExtensionProperties",
                "vkEnumeratePhysicalDevices",
                "vkEnumerateDeviceLayerProperties",
                "vkEnumerateDeviceExtensionProperties",

                "vkGetPhysicalDeviceSurfaceFormatsKHR",
                "vkGetPhysicalDeviceSurfacePresentModesKHR",
                "vkGetSwapchainImagesKHR",
                "vkGetImageSparseMemoryRequirements",
                "vkGetDisplayPlaneSupportedDisplaysKHR",
                "vkGetPhysicalDeviceDisplayPlanePropertiesKHR",
                "vkGetPhysicalDeviceDisplayPropertiesKHR",
                "vkGetPhysicalDeviceQueueFamilyProperties",
                "vkGetPhysicalDeviceFormatProperties",
                "vkGetPhysicalDeviceFeatures",
                "vkGetDisplayModePropertiesKHR",
                "vkGetPhysicalDeviceSurfaceCapabilitiesKHR",
                "vkGetDisplayPlaneCapabilitiesKHR",
                "vkGetPhysicalDeviceMemoryProperties",
                "vkGetPhysicalDeviceProperties",
                "vkGetRenderAreaGranularity",
                "vkGetImageSubresourceLayout",
                "vkGetBufferMemoryRequirements",
                "vkGetImageMemoryRequirements",
                "vkGetDeviceQueue",
                "vkGetPhysicalDeviceImageFormatProperties",

                "vkCreateInstance",
                "vkCreateDisplayPlaneSurfaceKHR",

                "vkCreateAndroidSurfaceKHR",
                "vkCreateMirSurfaceKHR",
                "vkCreateWaylandSurfaceKHR",
                "vkCreateWin32SurfaceKHR",
                "vkCreateXlibSurfaceKHR",
                "vkCreateXcbSurfaceKHR",

                "vkCreateDebugReportCallbackEXT",
                "vkCreateFence",
                "vkCreateSemaphore",
                "vkCreateEvent",
                "vkCreateQueryPool",
                "vkCreateBuffer",
                "vkCreateBufferView",
                "vkCreateImage",
                "vkCreateImageView",
                "vkCreateShaderModule",
                "vkCreatePipelineCache",
                "vkCreateGraphicsPipelines",
                "vkCreateComputePipelines",
                "vkCreatePipelineLayout",
                "vkCreateSampler",
                "vkCreateDescriptorSetLayout",
                "vkCreateDescriptorPool",
                "vkCreateFramebuffer",
                "vkCreateRenderPass",
                "vkCreateCommandPool",
                "vkCreateSharedSwapchainsKHR",
                "vkCreateSwapchainKHR",
                "vkCreateDevice",
                "vkCreateDisplayModeKHR",
                "vkGetPhysicalDeviceSparseImageFormatProperties",
            };

            mOutMethods = new HashSet<string>(outMethods);


        }

        private void FixCreateDisplayModeKHR(VkClassMethod method)
        {
            if (method.Function.Key == "vkCreateDisplayModeKHR")
            {
                foreach (var parameter in method.Parameters)
                {
                    // INCORRECT
                    if (parameter.Name == "VkDisplayModeCreateInfoKHR*pCreateInfo")
                    {
                        // MANUAL OVERWRITE
                        parameter.Name = "pCreateInfo";
                        parameter.CppType = "VkDisplayModeCreateInfoKHR*";
                        parameter.Text = "const VkDisplayModeCreateInfoKHR* pCreateInfo";
                        parameter.Tokens = parameter.Text.Split(' ');

                        VkTypeTranslation translation = null;
                        if (mTranslations.TryGetValue(parameter.CppType, out translation))
                        {
                            parameter.Translation = translation;
                        }

                        break;
                    }
                }
            }
        }


        /// <summary>
        /// The last parameter should be an out parameter
        /// </summary>
        /// <param name="method"></param>
        private void SetLastParameterAsOut(VkClassMethod method)
        {
            if (mOutMethods.Contains(method.Function.Key))
            {
                var count = method.Parameters.Count;

                if (count >= 1)
                {
                    var lastParameter = method.Parameters[count - 1];
                    lastParameter.UseOutStatement = true;
                }
            }
        }

        private IDictionary<string, VkTypeTranslation> mTranslations;

        private HashSet<string> mOutMethods;

        private void GenerateTranslations()
        {
            mTranslations = new Dictionary<string, VkTypeTranslation>();

            VkTypeTranslation item = null;

            item = new VkTypeTranslation { CppType = "char*", CSharpType = "String^", Default = " = nullptr;", MethodOnly = "String^", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint32_t", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "UInt32", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint32_t*", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "ref UInt32", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint64_t", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "UInt64", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint64_t*", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "UInt64", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "size_t", CSharpType = "IntPtr", Default = " = 0;", MethodOnly = "IntPtr", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "size_t*", CSharpType = "IntPtr", Default = " = 0;", MethodOnly = "ref IntPtr", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "float", CSharpType = "float", Default = " = 0f;", MethodOnly = "float", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "float*", CSharpType = "float", Default = " = 0f;", MethodOnly = "ref float", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "int32_t", CSharpType = "Int32", Default = " = 0;", MethodOnly = "Int32", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "char[]", CSharpType = "String^", Default = " = nullptr;", MethodOnly = "String^", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "const char* const*", CSharpType = "array<String^>^", Default = " = nullptr;", MethodOnly = "array<String^>^", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            // need to check VKBool32
            item = new VkTypeTranslation { CppType = "VkBool32", CSharpType = "bool", Default = " = false;", MethodOnly = "bool", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkBool32*", CSharpType = "bool", Default = " = false;", MethodOnly = "ref bool", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkSampleMask", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "UInt32", NeedsNamespace = true };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkFlags", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "UInt32", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkDeviceSize", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "UInt64", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkDeviceSize*", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "ref UInt64", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "void*", CSharpType = "IntPtr", Default = " = IntPtr.Zero;", MethodOnly = "IntPtr", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "void**", CSharpType = "array<IntPtr>", Default = " = null;", MethodOnly = "ref IntPtr", NeedsNamespace = false };
            mTranslations.Add(item.CppType, item);
        }

        private void ExtractFunctions(XDocument doc)
        {
            // get all commands
            foreach (var child in doc.Root.Descendants("command"))
            {
                var proto = child.Element("proto");
                if (proto != null)
                {
                    var key = proto.Element("name");

                    string keyValue = key.Value;

                    Vk_WindowingInterface match;
                    bool isWindowingFunction = mWindowFunctions.TryGetValue(keyValue, out match);

                    /// ONLY SPECIFIC WINDOWING FUNCTIONS ALLOWED
                    if (!isWindowingFunction || (isWindowingFunction && match == mAllowableInterfaces))
                    {
                        VkFunction fn = ExtractFunction(child, proto, keyValue);
                        mFunctions.Add(fn);
                    }
                }
            }

            // group them in classes

            // including catch all
            var notMatching = new VkProxy("Vulkan");
            notMatching.Name = "Vulkan";
            notMatching.RequiresInstance = false;
            mProxies[notMatching.Key] = notMatching;

            Func<VkFunction, bool> instFn = (a) => a.Parameters.Count >= 1 && a.Parameters[0].Tokens.Length == 2 && !a.Parameters[0].Tokens[0].EndsWith("*");

            foreach (var fn in Functions)
            {
                if (instFn(fn))
                {
                    var first = fn.Parameters[0];

                    VkProxy proxy = null;
                    if (!mProxies.TryGetValue(first.CppType, out proxy))
                    {
                        proxy = new VkProxy(first.CppType);
                        proxy.Name = first.CppType.Substring(2);
                        mProxies[first.CppType] = proxy;

                        var pointerStmt = first.CppType + "*";
                        if (!mTranslations.ContainsKey(pointerStmt))
                        {
                            var pointer = new VkTypeTranslation {
                                CppType = pointerStmt,
                                CSharpType = proxy.Name + "^",
                                Default = " = nullptr;",
                                MethodOnly = proxy.Name + "^",
                                NeedsNamespace = true,
                                ProxyInfo = proxy };
                            mTranslations.Add(pointerStmt, pointer);
                        }

                        if (!mTranslations.ContainsKey(first.CppType))
                        {
                            var classRef = new VkTypeTranslation {
                                CppType = first.CppType,
                                CSharpType = proxy.Name + "^",
                                Default = " = nullptr;",
                                MethodOnly = proxy.Name + "^",
                                NeedsNamespace = true,
                                ProxyInfo = proxy};
                            mTranslations.Add(classRef.CppType, classRef);
                        }
                    }

                    var method = new VkClassMethod(fn);                              
                    method.Parameters = fn.Parameters.Skip(1).ToList();
                    proxy.Methods.Add(method);
                }
                else
                {
                    var wrapper = new VkClassMethod(fn);
                    wrapper.Parameters = fn.Parameters;
                    notMatching.Methods.Add(wrapper);
                }
            }            
        }

        private static VkFunction ExtractFunction(XElement child, XElement proto, string key)
        {
            var returnType = proto.Element("type");

            var fn = new VkFunction(key);
            fn.ReturnType = returnType.Value;

            var success = child.Attribute("successcodes");
            if (success != null)
            {
                fn.SuccessCodes = success.Value.Split(',');
            }
            else
            {
                fn.SuccessCodes = new string[0];
            }


            var failed = child.Attribute("errorcodes");
            if (failed != null)
            {
                fn.FailureCodes = failed.Value.Split(',');
            }
            else
            {
                fn.FailureCodes = new string[0];
            }

            var index = 0;
            foreach (var param in child.Descendants("param"))
            {
                var paramType = param.Element("type");
                if (paramType != null)
                {
                    var p = new VkFunctionParam();
                    p.Index = index;
                    ++index;
                    p.Tokens = param.Value.Split(new[] { " " }, StringSplitOptions.RemoveEmptyEntries);
                    p.Text = string.Join(" ", p.Tokens);

                    var len = param.Attribute("len");
                    if (len != null)
                    {
                        p.LengthConditions = len.Value.Split(new[] { ',' });
                    }
                    else
                    {
                        p.LengthConditions = new string[0];
                    }

                    if (p.Tokens.Length == 2)
                    {
                        p.CppType = p.Tokens[0];
                        p.Name = p.Tokens[1];
                    }
                    else if (p.Tokens.Length == 3)
                    {
                        p.CppType = p.Tokens[1];
                        p.Name = p.Tokens[2];
                    }
                    fn.Parameters.Add(p);
                }
            }

            return fn;
        }

        private void ParseEnumerateMethods(VkClassMethod method)
        {
            VkArrayFunctionInfo found;
            if (mEnumerationFns.TryGetValue(method.Function.Key, out found))
            {
                method.ArrayInfo = found;

                var lengthParams = new HashSet<string>();
                var finalParams = new List<VkFunctionParam>();
                for (int i = method.Parameters.Count - 1; i >= 0; --i)
                {
                    var param = method.Parameters[i];

                    if (found.KeepCounts || !lengthParams.Contains(param.Name))
                    {
                        bool isArray = false;
                        foreach (var l in param.LengthConditions)
                        {
                            if (l != "null-terminated")
                            {
                                lengthParams.Add(l);
                                isArray = true;
                            }
                        }

                        if (isArray)
                        {
                            param.IsArray = true;
                        }

                        finalParams.Add(param);                        
                    }                           
                }
               
                finalParams.Reverse();
                method.Parameters = finalParams;                
            }
        }
    }
}
