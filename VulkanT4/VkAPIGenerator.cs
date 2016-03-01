using System;
using System.Collections.Generic;
using System.Globalization;
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

        public void Apply(XDocument doc)
        {
            GenerateTranslations();
            ExtractEnumsAndMasks(doc);
            ExtractStructs(doc);
            ExtractFunctions(doc);
            ExtractHandles(doc);
            ExtractDelegates(doc);
            RetranslateMembers();
            RetranslateProxies();
            RetranslateDelegates();
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
                            mTranslations.Add(h.Key, new VkTypeTranslation { CppType = h.Key, CSharpType = h.Name + "^", Default = " = nullptr;", MethodOnly = h.Name + "^" });
                        }

                        var pointerStmt = h.Key + "*";
                        if (!mTranslations.ContainsKey(pointerStmt))
                        {
                            mTranslations.Add(pointerStmt, new VkTypeTranslation { CppType = pointerStmt, CSharpType = h.Name + "^", Default = " = nullptr;", MethodOnly = h.Name + "^" });
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

                        var arrayType = "array<" + el.Name + ">^";
                        var pointerType = el.Name + "*";
                        mTranslations.Add(pointerType, new VkTypeTranslation { CppType = pointerType, CSharpType = arrayType, Default = " = nullptr;", MethodOnly = el.Name });
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

                if (category != null && category.Value == "struct")
                {
                    var name = child.Attribute("name");
                    var key = name != null ? name.Value : "<NAME>";
                    var s = new VkStruct(key);

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

                    mStructs.Add(key, s);

                    // POINTERS
                    var pointerStmt = s.Key + "*";
                    if (!mTranslations.ContainsKey(pointerStmt))
                    {
                        var item = new VkTypeTranslation { CppType = s.Key + "*", CSharpType = s.Name + "^", Default = " = nullptr;", MethodOnly = s.Name + "^" };
                        mTranslations.Add(pointerStmt, item);
                    }

                    if (!mTranslations.ContainsKey(s.Key))
                    {
                        var item2 = new VkTypeTranslation { CppType = s.Key, CSharpType = s.Name + "^", Default = " = nullptr;", MethodOnly = s.Name + "^" };
                        mTranslations.Add(item2.CppType, item2);
                    }
                }
            }
        }

        private void RetranslateMembers()
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
                    ParseEnumerateMethods(method);
                }
            }
        }

        private IDictionary<string, VkTypeTranslation> mTranslations;
        private void GenerateTranslations()
        {
            mTranslations = new Dictionary<string, VkTypeTranslation>();

            VkTypeTranslation item = null;

            item = new VkTypeTranslation { CppType = "char*", CSharpType = "String^", Default = " = nullptr;", MethodOnly = "String^" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint32_t", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "UInt32" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint32_t*", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "ref UInt32" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint64_t", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "UInt64" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "uint64_t*", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "UInt64" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "size_t", CSharpType = "IntPtr", Default = " = 0;", MethodOnly = "IntPtr" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "float", CSharpType = "float", Default = " = 0f;", MethodOnly = "float" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "float*", CSharpType = "float", Default = " = 0f;", MethodOnly = "ref float" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "int32_t", CSharpType = "Int32", Default = " = 0;", MethodOnly = "Int32" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "char[]", CSharpType = "String^", Default = " = nullptr;", MethodOnly = "String^" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "const char* const*", CSharpType = "array<String^>^", Default = " = nullptr;", MethodOnly = "array<String^>^" };
            mTranslations.Add(item.CppType, item);

            // need to check VKBool32
            item = new VkTypeTranslation { CppType = "VkBool32", CSharpType = "bool", Default = " = false;", MethodOnly = "bool" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkSampleMask", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "UInt32" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkFlags", CSharpType = "UInt32", Default = " = 0;", MethodOnly = "UInt32" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkDeviceSize", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "UInt64" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "VkDeviceSize*", CSharpType = "UInt64", Default = " = 0;", MethodOnly = "ref UInt64" };
            mTranslations.Add(item.CppType, item);

            item = new VkTypeTranslation { CppType = "void*", CSharpType = "IntPtr", Default = " = IntPtr.Zero;", MethodOnly = "IntPtr" };
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
                    var returnType = proto.Element("type");

                    var fn = new VkFunction(key.Value);
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

                    foreach (var param in child.Descendants("param"))
                    {
                        var paramType = param.Element("type");
                        if (paramType != null)
                        {
                            var p = new VkFunctionParam();
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

                    mFunctions.Add(fn);
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

                    VkProxy found = null;
                    if (!mProxies.TryGetValue(first.CppType, out found))
                    {
                        found = new VkProxy(first.CppType);
                        found.Name = first.CppType.Substring(2);
                        mProxies[first.CppType] = found;

                        var pointerStmt = first.CppType + "*";
                        if (!mTranslations.ContainsKey(pointerStmt))
                        {
                            var pointer = new VkTypeTranslation { CppType = pointerStmt, CSharpType = found.Name + "^", Default = " = nullptr;", MethodOnly = found.Name + "^" };
                            mTranslations.Add(pointerStmt, pointer);
                        }

                        if (!mTranslations.ContainsKey(first.CppType))
                        {
                            var classRef = new VkTypeTranslation { CppType = first.CppType, CSharpType = found.Name + "^", Default = " = nullptr;", MethodOnly = found.Name + "^" };
                            mTranslations.Add(classRef.CppType, classRef);
                        }
                    }

                    var method = new VkClassMethod(fn);                              
                    method.Parameters = fn.Parameters.Skip(1).ToList();
                    found.Methods.Add(method);
                }
                else
                {
                    var wrapper = new VkClassMethod(fn);
                    wrapper.Parameters = fn.Parameters;
                    notMatching.Methods.Add(wrapper);
                }
            }            
        }

        private void ParseEnumerateMethods(VkClassMethod method)
        {
            string[] actualFunctions = new string[] {
                "vkGetImageSparseMemoryRequirements",
                "vkGetSwapchainImagesKHR",
                "vkGetPhysicalDeviceQueueFamilyProperties",
                "vkGetPhysicalDeviceSparseImageFormatProperties",
                "vkGetPhysicalDeviceDisplayPropertiesKHR",
                "vkGetDisplayModePropertiesKHR",
                "vkGetPhysicalDeviceSurfaceFormatsKHR",
                "vkGetPhysicalDeviceSurfacePresentModesKHR",
            };
            var exceptions = new HashSet<string>(actualFunctions);

            if (method.Name.StartsWith("Enumerate") || exceptions.Contains(method.Function.Key))
            {
                var lengthParams = new HashSet<string>();
                var finalParams = new List<VkFunctionParam>();
                for (int i = method.Parameters.Count - 1; i > 0; --i)
                {
                    var param = method.Parameters[i];

                    if (param.LengthConditions.Length > 0)
                    {
                        foreach (var l in param.LengthConditions)
                        {
                            lengthParams.Add(l);
                        }
                        var a = new VkFunctionParam();
                        a.Name = param.Name;
                        a.CppType = param.CppType;

                        VkTypeTranslation paramType = null;
                        if (mTranslations.TryGetValue(param.CppType, out paramType))
                        {
                            a.CSharpType = "array<" + paramType.MethodOnly + ">^";
                        }
                        else
                        {
                            a.CSharpType = "<ARRAY TYPE>";
                        }

                        a.Text = string.Join(" ", new[] { a.CSharpType, a.Name });
                        a.Tokens = a.Text.Split(' ');
                        a.LengthConditions = param.LengthConditions;
                        finalParams.Add(a);
                    }                    
                    else if (!lengthParams.Contains(param.Name))
                    {
                        finalParams.Add(param);
                    }
                }
               
                finalParams.Reverse();
                method.Parameters = finalParams;                
            }
        }
    }
}
