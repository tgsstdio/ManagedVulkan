﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VulkanT4
{
    public class VkFunctionParam
    {
        public VkFunctionParam()
        {
            UseOutStatement = false;
            IsArray = false;
        }

        public string Text { get; set; }
        public string[] Tokens { get; set; }
        public string CppType { get; set; }
        public string Name { get; set; }
        public string CSharpType { get; set; }
        public VkTypeTranslation Translation { get; set; }
        public string[] LengthConditions { get; set; }
        public bool UseOutStatement { get; set; }
        public bool IsArray { get; set; }
        public int Index { get; set; }

        public bool IsStruct()
        {
            return (Translation != null && Translation.StructInfo != null);
        }

        public bool IsEnum()
        {
            return (Translation != null && Translation.EnumInfo != null);
        }

        public bool IsHandle()
        {
            return (Translation != null && Translation.HandleInfo != null);
        }

        public bool IsProxy()
        {
            return (Translation != null && Translation.ProxyInfo != null);
        }
    }
}
