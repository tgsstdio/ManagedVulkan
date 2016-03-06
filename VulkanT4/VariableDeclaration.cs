using System;
using System.Collections.Generic;
using System.Linq;

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
            public string SourceRoot { get; set; }
            public string SourcePath { get; set; }
            public string DestinationPath { get; set; }
            public int Children { get; set; }
            public bool NotGenerated { get; internal set; }
            public string[] LengthConditions { get; internal set; }
            public string Parent { get; set; }
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
                    SourcePath = param.Name,
                    DestinationPath  = rootPrefix + "_" + param.Index,
                    NullCheck = param.Name + " != nullptr",
                    SourceRoot = param.Name,
                    Index = param.Index,
                    Translation = param.Translation,
                    NotGenerated = true,
                    LengthConditions = param.LengthConditions.Where((l) => l != "null-terminated").ToArray(),
                    Parent = rootPrefix + "_" + param.Index,
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
                                SourcePath = top.SourcePath,
                                DestinationPath = top.DestinationPath,
                                LengthConditions = top.LengthConditions.Where((l) => l != "null-terminated").ToArray(),
                                Parent = top.Parent,
                            });
                        top.Children = DecomposeParam(stack, top.Prefix, top.Translation, top.SourceRoot, top.SourcePath, top.NullCheck, top.DestinationPath);
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

        private static int DecomposeParam(Stack<VkCommandInput> stack, string prefix, VkTypeTranslation parentTranslation, string sourceRoot, string sourcePath, string nullCheck, string destinationPath)
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
                            SourceRoot = sourceRoot,
                            NullCheck = nullCheck + " && " + sourceRoot + "->" + members[i].Name + " != nullptr",
                            SourcePath = sourcePath + "->" + members[i].Name,
                            DestinationPath = destinationPath + "->" + members[i].Key,
                            Index = i,
                            Translation = translate,
                            LengthConditions = members[i].LengthConditions,
                            Parent = destinationPath,
                        };
                        stack.Push(command);
                        ++count;
                    }
                    else if (translate != null && translate.CppType == "const char* const*")
                    {
                        var fieldPrefix = prefix + "_" + i;
                        var command = new VkCommandInput
                        {
                            NotGenerated = true,
                            Prefix = fieldPrefix,
                            SourceRoot = sourceRoot,
                            NullCheck = nullCheck + " && " + sourceRoot + "->" + members[i].Name + " != nullptr",
                            SourcePath = sourcePath + "->" + members[i].Name,
                            DestinationPath = destinationPath + "->" + members[i].Key,
                            Index = i,
                            Translation = translate,
                            LengthConditions = members[i].LengthConditions,
                            Parent = destinationPath,
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
