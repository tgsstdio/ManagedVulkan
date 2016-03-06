using System;
using System.Collections.Generic;
using System.Collections.Specialized;

namespace VulkanT4
{
    public class VkCommand
    {
        public VkCommand()
        {
            IsInitialised = false;
            PriorStatements = new List<string>();
        }

        public bool IsInitialised { get; set; }
        public VkFunctionParam Parameter { get; set; }
        public string ArgumentName { get; set; }
        public string InstanceName { get; set; }
        public VkTypeTranslation MemberType { get; set; }
        public List<string> PriorStatements { get; private set; }
        public string SourcePath { get; set; }
        public string NullCheck { get; set; }
        public string DestinationPath { get; internal set; }
        public string[] LengthConditions { get; set; }
        public string Parent { get; set; }

        public void Initialise(VkProxy proxy)
        {
            string valueStmt = "0";

            if (Parameter == null)
            {
                ParseFieldOnly(proxy);
                return;
            }

            if (Parameter != null)
            {
                var validTypes = new StringCollection();
                validTypes.AddRange(new[] { "bool", "UInt32", "float", "UInt64", "Int32" });

                if (Parameter.Index == 0 && proxy.RequiresInstance)
                {
                    valueStmt = "this->mHandle";
                }
                // IS METHOD PARAMETER A HANDLE => STRAIGHT COPY
                else if (Parameter.Translation.HandleInfo != null)
                {
                    valueStmt = Parameter.Name + "->mHandle";
                }
                else if (Parameter.Translation.EnumInfo != null)
                {
                    valueStmt = Parameter.Name;
                }
                // STRAIGHT COPY 
                else if (validTypes.Contains(Parameter.Translation.CSharpType))
                {
                    valueStmt = Parameter.Name;
                }
                else if (Parameter.Translation.CppType == "size_t")
                {
                    valueStmt = "(size_t)  " + Parameter.Name;
                }


                PriorStatements.Add("// " + Parameter.Index + " - " + Parameter.Name);
            }

            //command.IsInitialised = true;

            if (Parameter != null && Parameter.IsArray)
            {
                var elementType = "<TYPE>";
                if (Parameter.Translation != null)
                {
                    if (Parameter.Translation.StructInfo != null)
                    {
                        elementType = Parameter.Translation.StructInfo.Key;
                    }
                    else if (Parameter.Translation.HandleInfo != null)
                    {
                        elementType = Parameter.Translation.HandleInfo.Key;
                    }
                    else if (Parameter.Translation.ProxyInfo != null)
                    {
                        elementType = Parameter.Translation.ProxyInfo.Key;
                    }
                }
                PriorStatements.Add(ArgumentName + " = new " + elementType + "[" + Parameter.LengthConditions[0] + "];");
            }
            else
            {
                bool needCallVariable =
                    MemberType != null
                    && (
                        MemberType.StructInfo != null
                        || MemberType.HandleInfo != null
                        || MemberType.ProxyInfo != null
                    )
                    &&
                    (
                            (Parameter != null && Parameter.UseOutStatement)
                        || (Parameter != null && !Parameter.UseOutStatement && !proxy.RequiresInstance)
                        || (Parameter != null && !Parameter.UseOutStatement && proxy.RequiresInstance && Parameter.Index > 0 && !Parameter.IsHandle())
                    );

                if (needCallVariable)
                {
                    // NEED TO INITIALISE PINNED DATA
                    var pinnedVariable = InstanceName;
                    var pinnedType = MemberType.CppType;

                    if (MemberType.StructInfo != null)
                    {
                        pinnedType = MemberType.StructInfo.Key;
                    }
                    else if (MemberType.HandleInfo != null)
                    {
                        pinnedType = MemberType.HandleInfo.Key;
                    }
                    else if (MemberType.ProxyInfo != null)
                    {
                        pinnedType = MemberType.ProxyInfo.Key;
                    }
                    valueStmt = "&" + pinnedVariable;
                    PriorStatements.Add(pinnedType + "  " + pinnedVariable);
                }
                else if (MemberType.CSharpType == "String^")
                {
                    PriorStatements.Add("IntPtr " + InstanceName + " = Marshal::StringToHGlobalAnsi(" + (Parameter.Name != null ? Parameter.Name : ArgumentName)  + ");");
                    PriorStatements.Add("pins->Add(" + InstanceName + ");");
                    valueStmt = "static_cast<char*>(" + InstanceName + ".ToPointer());";
                }

                PriorStatements.Add(MemberType.CppType + " " + ArgumentName + " = " + valueStmt + ";");
                if (Parameter.Translation != null && MemberType.StructInfo != null)
                {
                    PriorStatements.Add(Parameter.Name + "->CopyTo(" + ArgumentName + ", pins);");
                }
            }

        }

        private void ParseFieldOnly(VkProxy proxy)
        {
            string valueStmt = "0";

            PriorStatements.Add("// FIELD - " + ArgumentName + " " + SourcePath);

            if (!IsInitialised)
            {
                PriorStatements.Add(MemberType.CppType + " " + ArgumentName + " = nullptr;");
            }

            bool needCallVariable =
                MemberType != null
                && (
                    MemberType.StructInfo != null
                    || MemberType.HandleInfo != null
                    || MemberType.ProxyInfo != null
                );

            if (needCallVariable)
            {
                // NEED TO INITIALISE PINNED DATA
                var pinnedVariable = InstanceName;
                var pinnedType = MemberType.CppType;

                if (MemberType.StructInfo != null)
                {
                    pinnedType = MemberType.StructInfo.Key;
                }
                else if (MemberType.HandleInfo != null)
                {
                    pinnedType = MemberType.HandleInfo.Key;
                }
                else if (MemberType.ProxyInfo != null)
                {
                    pinnedType = MemberType.ProxyInfo.Key;
                }
                valueStmt = "&" + pinnedVariable;
                PriorStatements.Add(pinnedType + "  " + pinnedVariable + ";");
            }

            PriorStatements.Add("if (" + NullCheck + ")");
            PriorStatements.Add("{");
            
            if (needCallVariable)
            {
                PriorStatements.Add('\t' + ArgumentName + " = " + valueStmt + ";");
                PriorStatements.Add('\t' + SourcePath + "->CopyTo(" + ArgumentName + ", pins);");
                PriorStatements.Add('\t' + DestinationPath + " = " + ArgumentName + ";");
            }
            else if (MemberType.CppType == "const char* const*")
            {
                var lengthVariable = "count";
                if (LengthConditions.Length == 1)
                {
                    lengthVariable = LengthConditions[0];
                }
                var lengthDest = Parent + "->" + lengthVariable;

                PriorStatements.Add("\t" + "int " + lengthVariable + " = (int) " + SourcePath + "->Length;");
                PriorStatements.Add("\t" + ArgumentName + " = new char*[" + lengthVariable + "];");
                PriorStatements.Add("\t" + "for (int j = 0; j < " + lengthVariable + "; ++j)");
                PriorStatements.Add("\t" + "{");
                PriorStatements.Add("\t\t" + "IntPtr " + InstanceName + " = Marshal::StringToHGlobalAnsi((String^)" + SourcePath + "[j]);");
                PriorStatements.Add("\t\t" + "pins->Add(" + InstanceName + ");");
                PriorStatements.Add("\t\t" + ArgumentName + "[j] = static_cast<char*>(" + InstanceName + ".ToPointer());");
                PriorStatements.Add("\t" + "}");
                PriorStatements.Add("\t" + DestinationPath + " = " + ArgumentName + ";");
                PriorStatements.Add("\t" + lengthDest + " = " + lengthVariable + ";");
            }            

            PriorStatements.Add("}");
        }
    }
}
