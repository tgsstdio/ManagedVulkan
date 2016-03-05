using System;
using System.Collections.Generic;

namespace VulkanT4
{
    public class VariableDeclaration : IVariableDeclaration
    {
        private class VkCommandInput
        {
            public VkFunctionParam Parameter { get; set; }
            public int Index { get; internal set; }
            public VkTypeTranslation Translation { get; internal set; }
            public string Prefix { get; internal set; }
            public string NullCheck { get; set; }
            public string Parent { get; set; }
            public string FieldPath { get; set; }
            public int Children { get; set; }
            public bool NotGenerated { get; internal set; }
        }

        public List<VkCommand> Parse(VkFunction fn)
        {
            var commands = new List<VkCommand>();

            const string rootPrefix = "arg";
            var stack = new Stack<VkCommandInput>();
            foreach (var param in fn.Parameters)
            {

                var root = new VkCommandInput
                {
                    Parameter = param,
                    Prefix = rootPrefix + "_" + param.Index,
                    FieldPath = rootPrefix + "_" + param.Index,
                    NullCheck = param.Name + " != nullptr",
                    Parent = param.Name,
                    Index = param.Index,
                    Translation = param.Translation,
                    NotGenerated = true,
                };
                stack.Push(root);

                while (stack.Count > 0)
                {
                    var top = stack.Peek();

                    if (top.NotGenerated)
                    {
                        commands.Add(
                            new VkCommand
                            {
                                Parameter = top.Parameter,
                                ArgumentName = top.Prefix,
                                MemberType = top.Translation,
                                NullCheck = top.NullCheck,
                                InstanceName = top.Prefix.Replace("arg_", "inst_"),
                                FieldPath = top.FieldPath,
                            });
                        top.Children = DecomposeParam(stack, top.Prefix, top.Translation, top.FieldPath, top.NullCheck, top.Parent);
                        top.NotGenerated = false;
                    }
                    else
                    {
                        top.Children--;
                    }

                    if (top.Children == 0)
                    {
                        stack.Pop();
                    }
                }
            }

            return commands;
        }

        private static int DecomposeParam(Stack<VkCommandInput> stack, string prefix, VkTypeTranslation parentTranslation, string fieldPath, string nullCheck, string parent)
        {
            int count = 0;
            // structs 
            if (parentTranslation != null && parentTranslation.StructInfo != null)
            {
                var members = parentTranslation.StructInfo.Members;
                // feed in reverse                
                for (int i = parentTranslation.StructInfo.Members.Count - 1; i >= 0; --i)
                {
                    var translate = members[i].Translation;
                    if (translate != null && translate.StructInfo != null)
                    {
                        var fieldPrefix = prefix + "_" + i;
                        var command = new VkCommandInput
                        {
                            NotGenerated = true,
                            Prefix = fieldPrefix,
                            Parent = parent,
                            NullCheck = nullCheck + " && " + parent + "->" + members[i].Name + " != nullptr",
                            FieldPath = fieldPath + "->" + members[i].Name,
                            Index = i,
                            Translation = members[i].Translation
                        };
                        stack.Push(command);
                        ++count;
                    }
                }
            }
            return count;
        }
    }
}
