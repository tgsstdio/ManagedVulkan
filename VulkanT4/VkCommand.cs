using System;
using System.Collections.Generic;

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
        public string FieldPath { get; set; }
        public string NullCheck { get; set; }

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
                PriorStatements.Add(ArgumentName + " = new " + elementType + "[" + Parameter.LengthConditions[0] + "]");
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
                    PriorStatements.Add("IntPtr " + InstanceName + " = Marshal::StringToHGlobalAnsi(" + ArgumentName + ")");
                    PriorStatements.Add("pins->Add(" + InstanceName + ")");
                    valueStmt = "static_cast<char*>(" + InstanceName + ".ToPointer())";
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

            PriorStatements.Add("// FIELD - " + ArgumentName + " " + FieldPath);

            PriorStatements.Add(MemberType.CppType + " " + ArgumentName + " = nullptr;");

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
                PriorStatements.Add('\t' + FieldPath + " = " + ArgumentName + ";");
            }

            PriorStatements.Add("}\n");
        }
    }
}
