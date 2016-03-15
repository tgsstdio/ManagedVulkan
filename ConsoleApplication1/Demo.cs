/**
C# translation of CUBE.C from LunarG Vulkan SDK demo
**/
using System;
using System.Diagnostics;
using ManagedVulkan;
using OpenTK;
using System.Collections.Specialized;
using System.Collections.Generic;

namespace ConsoleApplication1
{
    public class Demo
    {
        private const string KHR_SURFACE_EXTENSION_NAME = "VK_KHR_surface";
        private const string KHR_WIN32_SURFACE_EXTENSION_NAME = "VK_KHR_win32_surface";
        private const string KHR_XCB_SURFACE_EXTENSION_NAME = "VK_KHR_xcb_surface";
        private const string EXT_DEBUG_REPORT_EXTENSION_NAME = "VK_EXT_debug_report";
        private const string KHR_SWAPCHAIN_EXTENSION_NAME = "VK_KHR_swapchain";

        private Int32 mFrameCount;
        private bool mUseStagingBuffer;
        private bool mUseBreak;
        private bool mValidate;
        private int mWidth;
        private int mHeight;
        private float mSpinAngle;
        private float mSpinIncrement;
        private bool mPause;
        private Matrix4 mProjectionMatrix;
        private Matrix4 mViewMatrix;
        private Matrix4 mModelMatrix;
        private IntPtr mConnection;
        private IntPtr mWindow;
        private string[] mDeviceValidationLayers;
        private readonly string APP_SHORT_NAME = "Demo";
        private Instance mInstance;
        private PhysicalDevice mGPU;
        private int mEnabledLayerCount;


        public bool Init(string[] args)
        {
            mFrameCount = Int32.MaxValue;
            mUseStagingBuffer = false;
            mUseBreak = false;
            mValidate = false;

            for (int i = 0; i < args.Length; ++i)
            {
                var arg = args[i];
                if (arg == "--use_staging")
                {
                    mUseStagingBuffer = true;
                }
                else if (arg == "--use_break")
                {
                    mUseBreak = true;
                }
                else if (arg == "--validate")
                {
                    mValidate = true;
                }
                else if (arg == "--c" && mFrameCount == Int32.MaxValue && i < args.Length - 1)
                {
                    Int32 result;
                    if (Int32.TryParse(args[i + 1], out result))
                    {
                        if (result > 0)
                        {
                            mFrameCount = result;
                        }
                    }
                }
                else
                {
                    Debug.WriteLine(
                       @"Usage:\n  %s [--use_staging] [--validate] [--break] 
                        [--c <framecount>]");
                    return false;
                }
            }

            InitConnection();
            InitVk();

            mWidth = 500;
            mHeight = 500;

            mSpinAngle = 0.01f;
            mSpinIncrement = 0.01f;
            mPause = false;

            var eye = new OpenTK.Vector3(0.0f, 3.0f, 5.0f);
            var origin = new OpenTK.Vector3(0, 0, 0);
            var up = new OpenTK.Vector3(0.0f, 1.0f, 0.0f);

            mProjectionMatrix = OpenTK.Matrix4.CreatePerspectiveFieldOfView(OpenTK.MathHelper.DegreesToRadians(45.0f), 1.0f, 0.1f, 100.0f);
            mViewMatrix = OpenTK.Matrix4.LookAt(eye, origin, up);
            mModelMatrix = OpenTK.Matrix4.Identity;

            return true;
        }

        private void InitVk()
        {
            ManagedVulkan.Result err;

            UInt32 enabled_layer_count = 0;
            bool validation_found = false;

            var instance_validation_layers = new[] {
                    "VK_LAYER_GOOGLE_threading",
                    "VK_LAYER_LUNARG_param_checker",
                    "VK_LAYER_LUNARG_device_limits",
                    "VK_LAYER_LUNARG_object_tracker",
                    "VK_LAYER_LUNARG_image",
                    "VK_LAYER_LUNARG_mem_tracker",
                    "VK_LAYER_LUNARG_draw_state",
                    "VK_LAYER_LUNARG_swapchain",
                    "VK_LAYER_GOOGLE_unique_objects"
                };

            mDeviceValidationLayers = new string[] {
                "VK_LAYER_GOOGLE_threading",
                "VK_LAYER_LUNARG_param_checker",
                "VK_LAYER_LUNARG_device_limits",
                "VK_LAYER_LUNARG_object_tracker",
                "VK_LAYER_LUNARG_image",
                "VK_LAYER_LUNARG_mem_tracker",
                "VK_LAYER_LUNARG_draw_state",
                "VK_LAYER_LUNARG_swapchain",
                "VK_LAYER_GOOGLE_unique_objects",
            };

            UInt32 device_validation_layer_count = (UInt32)mDeviceValidationLayers.Length;

            ManagedVulkan.LayerProperties[] instance_layers;
            err = ManagedVulkan.Vulkan.EnumerateInstanceLayerProperties(out instance_layers);

            Debug.Assert(err != 0);

            if (mValidate)
            {
                validation_found = CheckLayers(instance_validation_layers, instance_layers);
                enabled_layer_count = (UInt32)instance_validation_layers.Length;
            }

            if (mValidate && !validation_found)
            {
                const string message =
@"vkEnumerateInstanceLayerProperties failed to find required validation layer.
        
Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkCreateInstance Failure", message);
            }

            bool surfaceExtFound = false;
            bool platformSurfaceExtFound = false;
            var enabled_extensions = new List<string>();

            ManagedVulkan.ExtensionProperties[] instance_extensions;
            err = ManagedVulkan.Vulkan.EnumerateInstanceExtensionProperties(null, out instance_extensions);

            foreach (var extension in instance_extensions)
            {
                if (extension.ExtensionName == KHR_SURFACE_EXTENSION_NAME)
                {
                    surfaceExtFound = true;
                    enabled_extensions.Add(KHR_SURFACE_EXTENSION_NAME);
                }
                // #ifdef _WIN32
                if (extension.ExtensionName == KHR_WIN32_SURFACE_EXTENSION_NAME)
                {
                    platformSurfaceExtFound = true;
                    enabled_extensions.Add(KHR_WIN32_SURFACE_EXTENSION_NAME);
                }
                // #else 
                if (extension.ExtensionName == KHR_XCB_SURFACE_EXTENSION_NAME)
                {
                    platformSurfaceExtFound = true;
                    enabled_extensions.Add(KHR_XCB_SURFACE_EXTENSION_NAME);
                }

                if (extension.ExtensionName == EXT_DEBUG_REPORT_EXTENSION_NAME)
                {
                    if (mValidate)
                    {
                        enabled_extensions.Add(EXT_DEBUG_REPORT_EXTENSION_NAME);
                    }
                }
                Debug.Assert(enabled_extensions.Count < 64);
            }

            if (!surfaceExtFound)
            {
                string message =
 @"vkEnumerateInstanceExtensionProperties failed to find the " + KHR_SURFACE_EXTENSION_NAME + @" extension.
                         
Do you have a compatible Vulkan installable client driver (ICD) installed?
Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkCreateInstance Failure", message);
            }

            if (!platformSurfaceExtFound)
            {
                var platformExt = KHR_WIN32_SURFACE_EXTENSION_NAME != null ? KHR_WIN32_SURFACE_EXTENSION_NAME : KHR_XCB_SURFACE_EXTENSION_NAME;

                // #ifdef _WIN32
                string message =
@"vkEnumerateInstanceExtensionProperties failed to find the " + platformExt + @" extension.

Do you have a compatible Vulkan installable client driver (ICD) installed?
Please look at the Getting Started guide for additional information.";
                // #else

                // endif
                throw new VulkanLibraryException("vkCreateInstance Failure", message);
            }

            var app = new ManagedVulkan.ApplicationInfo
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_APPLICATION_INFO,
                ApplicationName = APP_SHORT_NAME,
                ApplicationVersion = 0,
                EngineName = APP_SHORT_NAME,
                EngineVersion = 0,
                ApiVersion = ManagedVulkan.Vulkan.MakeVersion(1, 0, 0),
            };

            var inst_info = new ManagedVulkan.InstanceCreateInfo
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                ApplicationInfo = app,
                EnabledLayerNames = (mValidate) ? instance_validation_layers : null,
                EnabledExtensionNames = enabled_extensions.ToArray(),
            };

            ManagedVulkan.Instance inst;
            err = ManagedVulkan.Vulkan.CreateInstance(inst_info, null, out inst);

            if (err == Result.VK_ERROR_INCOMPATIBLE_DRIVER)
            {
                const string errMsg =
@"Cannot find a compatible Vulkan installable client driver (ICD).

Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkCreateInstance Failure", errMsg);
            }
            else if (err == Result.VK_ERROR_EXTENSION_NOT_PRESENT)
            {
                string message =
@"Cannot find a specified extension library
Make sure your layers path is set appropriately.";
                throw new VulkanLibraryException("vkCreateInstance Failure", message);
            }
            else if (err != 0)
            {
                const string message =
@"vkCreateInstance failed.

Do you have a compatible Vulkan installable client driver (ICD) installed?
Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkCreateInstance Failure", message);
            }
            mInstance = inst;

            ManagedVulkan.PhysicalDevice[] physicalDevices;
            err = mInstance.EnumeratePhysicalDevices(out physicalDevices);
            Debug.Assert(err != 0);

            if (physicalDevices != null && physicalDevices.Length > 0)
            {
                /* For cube demo we just grab the first physical device */
                mGPU = physicalDevices[0];
            }
            else
            {
                const string message =
@"vkEnumeratePhysicalDevices reported zero accessible devices.

Do you have a compatible Vulkan installable client driver (ICD) installed?
Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkEnumeratePhysicalDevices Failure", message);
            }

            /* Look for validation layers */
            validation_found = false;
            mEnabledLayerCount = 0;

            ManagedVulkan.LayerProperties[] device_layers;
            err = mGPU.EnumerateDeviceLayerProperties(out device_layers);
            Debug.Assert(err != 0);

            if (device_layers != null)
            {
                if (mValidate)
                {
                    validation_found = CheckLayers(mDeviceValidationLayers, device_layers);
                    mEnabledLayerCount = mDeviceValidationLayers.Length;
                }
            }

            if (mValidate && !validation_found)
            {
                const string errMsg =
 @"vkEnumerateDeviceLayerProperties failed to find a required validation layer.

Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkCreateDevice Failure", errMsg);
            }

            /* Look for device extensions */
            bool swapchainExtFound = false;
            var extension_names = new List<string>();

            ManagedVulkan.ExtensionProperties[] device_extensions;
            err = mGPU.EnumerateDeviceExtensionProperties(null, out device_extensions);
            Debug.Assert(err != 0);

            if (device_extensions != null)
            {
                foreach (var extension in device_extensions)
                {
                    if (extension.ExtensionName == KHR_SWAPCHAIN_EXTENSION_NAME)
                    {
                        swapchainExtFound = true;
                        extension_names.Add(KHR_SWAPCHAIN_EXTENSION_NAME);
                    }
                    Debug.Assert(extension_names.Count < 64);
                }
            }

            if (!swapchainExtFound)
            {
                string message =
@"vkEnumerateDeviceExtensionProperties failed to find the " + KHR_SWAPCHAIN_EXTENSION_NAME + @" extension.

Do you have a compatible Vulkan installable client driver (ICD) installed?
Please look at the Getting Started guide for additional information.";
                throw new VulkanLibraryException("vkCreateInstance Failure", message);
            }

            if (mValidate)
            {

            }
        }

        private bool CheckLayers(string[] instance_validation_layers, LayerProperties[] instance_layers)
        {
            var collection = new StringCollection();
            foreach(var layer in instance_layers)
            {
                collection.Add(layer.LayerName);
            }

            foreach (var item in instance_validation_layers)
            {
                if (!collection.Contains(item))
                {
                    Debug.WriteLine("Cannot find layer" + item);
                    return false;
                }
            }

            return true;
        }

        private void InitConnection()
        {
            // ONLY FOR NON-WIN32 implementation
        }

        public void CreateWindow()
        {

        }

        public void InitVkSwapchain()
        {

        }

        public void Prepare()
        {

        }

        public void Cleanup()
        {

        }

    }
}
