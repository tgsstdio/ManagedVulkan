﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    using vK = ManagedVulkan.Vulkan;

    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            Demo d = new Demo();
            try
            {
                d.Init(args);
                d.CreateWindow();
                d.InitVkSwapchain();
                d.Prepare();
                d.Run();
            }
            catch (VulkanLibraryException vlex)
            {
                Console.WriteLine(vlex.Category);
                Console.WriteLine(vlex.Message);
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                d.Cleanup();
            }
        }
    }
}
