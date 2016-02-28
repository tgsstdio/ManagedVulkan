using System.Collections.Generic;
using System.Xml.Linq;

namespace VulkanT4
{
    public class VkAPIGenerator : IVkAPIGenerator
    {
        public VkAPIGenerator()
        {
            Functions = new List<VkFunction>();
        }

        public List<VkFunction> Functions { get; private set; }

        public void Apply(XDocument doc)
        {
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

                    Functions.Add(fn);
                }


            }
        }

    }
}
