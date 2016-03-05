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

        public void Initialise(VkProxy proxy)
        {
            string valueStmt = "0";

            if (Parameter != null)
            {
                return;
            }

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

            //command.IsInitialised = true;

            PriorStatements.Add("// " + Parameter.Index + " - " + Parameter.Name);

            if (Parameter.IsArray)
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
                    Parameter.Translation != null
                    && (
                        Parameter.Translation.StructInfo != null
                        || Parameter.Translation.HandleInfo != null
                        || Parameter.Translation.ProxyInfo != null
                    )
                    &&
                    (
                            (Parameter.UseOutStatement)
                        || (!Parameter.UseOutStatement && !proxy.RequiresInstance)
                        || (!Parameter.UseOutStatement && proxy.RequiresInstance && Parameter.Index > 0 && !Parameter.IsHandle())
                    );

                if (needCallVariable)
                {
                    // NEED TO INITIALISE PINNED DATA
                    var pinnedVariable = InstanceName;
                    var pinnedType = Parameter.CppType;

                    if (Parameter.Translation.StructInfo != null)
                    {
                        pinnedType = Parameter.Translation.StructInfo.Key;
                    }
                    else if (Parameter.Translation.HandleInfo != null)
                    {
                        pinnedType = Parameter.Translation.HandleInfo.Key;
                    }
                    else if (Parameter.Translation.ProxyInfo != null)
                    {
                        pinnedType = Parameter.Translation.ProxyInfo.Key;
                    }
                    valueStmt = "&" + pinnedVariable;
                    PriorStatements.Add(pinnedType + "  " + pinnedVariable);
                }
                else if (Parameter.Translation.CSharpType == "String^")
                {
                    PriorStatements.Add("IntPtr " + InstanceName + " = Marshal::StringToHGlobalAnsi(" + ArgumentName + ")");
                    PriorStatements.Add("pins->Add(" + InstanceName + ")");
                    valueStmt = "static_cast<char*>(" + InstanceName + ".ToPointer())";
                }

                PriorStatements.Add(Parameter.CppType + " " + ArgumentName + " " + valueStmt + ";");
                if (Parameter.Translation != null && Parameter.Translation.StructInfo != null)
                {
                    PriorStatements.Add(Parameter.Name + "->CopyTo(" + ArgumentName + ");");
                }
            }

        }

    }
}
