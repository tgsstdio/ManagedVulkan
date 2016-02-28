using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;

namespace VulkanT4
{
    public class VkAPIGenerator : IVkAPIGenerator
    {
        private IDictionary<string, string> mTranslations;
        public VkAPIGenerator()
        {
            mFunctions = new List<VkFunction>();
            mProxies = new Dictionary<string, VkProxy>();

            mTranslations = new Dictionary<string, string>();
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

        public void Apply(XDocument doc)
        {
            GenerateTranslations();
            ExtractFunctions(doc);
        }

        private void GenerateTranslations()
        {
            mTranslations.Add("char*", "String^");
            mTranslations.Add("uint32_t", "UInt32");
            mTranslations.Add("uint32_t*", "ref UInt32");
            mTranslations.Add("uint64_t", "UInt64");
            mTranslations.Add("VkBool32", "bool");
            mTranslations.Add("size_t", "IntPtr");
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
                        var p = new VkFunctionParam();
                        p.Text = param.Value;
                        p.Tokens = p.Text.Split(' ');

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

                    mFunctions.Add(fn);
                }
            }

            // group them in classes

            // including catch all
            var notMatching = new VkProxy("Vulkan");
            notMatching.Name = "Vulkan";
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
    }
}
