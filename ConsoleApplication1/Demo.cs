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

        internal void Run()
        {
            while (!mQuit)
            {
                mNativeWindow.ProcessEvents();

                ++mCurrentFrame;
                if (mFrameCount != Int32.MaxValue && mCurrentFrame >= mFrameCount)
                {
                    mQuit = true;
                }
            }
        }

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
        private readonly string Name = "Cube";

        private ManagedVulkan.Instance mInstance;
        private ManagedVulkan.PhysicalDevice mGPU;

        private int mEnabledLayerCount;
        //private vkCreateDebugReportCallbackEXT mCreateDebugReportCallback;
        //private vkDestroyDebugReportCallbackEXT mDestroyDebugReportCallback;
        //private vkDebugReportCallbackEXT mDebugReportMessage;
        private DebugReportCallbackEXT mMsgCallback;
        private bool mPrepared;

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

            Debug.Assert(err == Result.VK_SUCCESS);

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
            Debug.Assert(err == Result.VK_SUCCESS);

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
            Debug.Assert(err == Result.VK_SUCCESS);

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
            Debug.Assert(err == Result.VK_SUCCESS);

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
            mExtensionNames = extension_names.ToArray();

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
                //ManagedVulkan.vkCreateDebugReportCallbackEXT createDebugReportCallback;
                //if (mInstance.GetInstanceProcAddr("vkCreateDebugReportCallbackEXT", out createDebugReportCallback))
                //{
                //    mCreateDebugReportCallback = createDebugReportCallback;
                //}
                //else
                //{
                //    throw new VulkanLibraryException("vkGetProcAddr Failure", "GetProcAddr: Unable to find vkCreateDebugReportCallbackEXT");
                //}

                //ManagedVulkan.vkDestroyDebugReportCallbackEXT destroyDebugReportCallback;
                //if (mInstance.GetInstanceProcAddr("vkDestroyDebugReportCallbackEXT", out destroyDebugReportCallback))
                //{
                //    mDestroyDebugReportCallback = destroyDebugReportCallback;
                //}
                //else
                //{
                //    throw new VulkanLibraryException("vkGetProcAddr Failure", "GetProcAddr: Unable to find vkDestroyDebugReportCallbackEXT");
                //}

                //ManagedVulkan.vkDebugReportCallbackEXT debugReportMessageCallback;
                //if (mInstance.GetInstanceProcAddr("vkDestroyDebugReportCallbackEXT", out debugReportMessageCallback))
                //{
                //    mDebugReportMessage = debugReportMessageCallback;
                //}
                //else
                //{
                //    throw new VulkanLibraryException("vkGetProcAddr Failure", "GetProcAddr: Unable to find vkDebugReportMessageEXT");
                //}

                vkDebugReportCallbackEXT callback = this.dbgFunc;

                var dbgCreateInfo = new ManagedVulkan.DebugReportCallbackCreateInfoEXT()
                {
                    SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT,
                    PfnCallback = callback,
                    UserData = IntPtr.Zero,
                    Flags = DebugReportFlagBitsEXT.VK_DEBUG_REPORT_ERROR_BIT_EXT | DebugReportFlagBitsEXT.VK_DEBUG_REPORT_WARNING_BIT_EXT,
                };

                ManagedVulkan.DebugReportCallbackEXT msgCallback;
                err = mInstance.CreateDebugReportCallbackEXT(dbgCreateInfo, null, out msgCallback);
                switch (err)
                {
                    case Result.VK_SUCCESS:
                        break;
                    case Result.VK_ERROR_OUT_OF_HOST_MEMORY:
                        throw new VulkanLibraryException("CreateDebugReportCallback Failure", "CreateDebugReportCallback: out of host memory");
                    default:
                        throw new VulkanLibraryException("CreateDebugReportCallback Failure", "CreateDebugReportCallback: unknown failure");
                }
                mMsgCallback = msgCallback;
            }

            ManagedVulkan.QueueFamilyProperties[] queue_props;
            mGPU.GetPhysicalDeviceQueueFamilyProperties(out queue_props);

            Debug.Assert(queue_props.Length > 1);
            mQueueProperties = queue_props;

            QueueFamilyProperties found = null;
            foreach (var queue in queue_props)
            {
                // Find a queue that supports gfx
                if ((queue.QueueFlags & ManagedVulkan.QueueFlagBits.VK_QUEUE_GRAPHICS_BIT) == ManagedVulkan.QueueFlagBits.VK_QUEUE_GRAPHICS_BIT)
                {
                    found = queue;
                    break;
                }
            }
            Debug.Assert(found != null);

            //  If app has specific feature requirements it should check supported
            //  features based on this query
            ManagedVulkan.PhysicalDeviceFeatures physDevFeatures;
            mGPU.GetPhysicalDeviceFeatures(out physDevFeatures);

            // NOT NEEDED AS IMPLEMENTED IN LUNAR SDK
            //GET_INSTANCE_PROC_ADDR(demo->inst, GetPhysicalDeviceSurfaceSupportKHR);
            //GET_INSTANCE_PROC_ADDR(demo->inst, GetPhysicalDeviceSurfaceCapabilitiesKHR);
            //GET_INSTANCE_PROC_ADDR(demo->inst, GetPhysicalDeviceSurfaceFormatsKHR);
            //GET_INSTANCE_PROC_ADDR(demo->inst, GetPhysicalDeviceSurfacePresentModesKHR);
            //GET_INSTANCE_PROC_ADDR(demo->inst, GetSwapchainImagesKHR);
        }

        private bool dbgFunc(
                ManagedVulkan.DebugReportFlagBitsEXT flags,
                ManagedVulkan.DebugReportObjectTypeEXT objectType,
                ulong srcObject, ulong location, int msgCode,
                string pLayerPrefix, string pMsg, IntPtr userData)
        {
            string message = "";

            if ((flags & ManagedVulkan.DebugReportFlagBitsEXT.VK_DEBUG_REPORT_ERROR_BIT_EXT)
                == ManagedVulkan.DebugReportFlagBitsEXT.VK_DEBUG_REPORT_ERROR_BIT_EXT)
            {
                message = string.Format("ERROR: [{0}] Code {1} : {2}", pLayerPrefix, msgCode, pMsg);
            }
            else if ((flags & ManagedVulkan.DebugReportFlagBitsEXT.VK_DEBUG_REPORT_WARNING_BIT_EXT)
                == ManagedVulkan.DebugReportFlagBitsEXT.VK_DEBUG_REPORT_WARNING_BIT_EXT)
            {
                // We know that we're submitting queues without fences, ignore this
                // warning
                if (pMsg == "vkQueueSubmit parameter, VkFence fence, is null pointer")
                {
                    return false;
                }
                Debug.WriteLine(string.Format("WARNING: [{0}] Code {1} : {2}", pLayerPrefix, msgCode, pMsg));
            }
            else
            {
                return false;
            }

            Debug.WriteLine(message);
            /*
             * false indicates that layer should not bail-out of an
             * API call that had validation failures. This may mean that the
             * app dies inside the driver due to invalid parameter(s).
             * That's what would happen without validation layers, so we'll
             * keep that behavior here.
             */
            return false;
        }

        private bool CheckLayers(string[] instance_validation_layers, LayerProperties[] instance_layers)
        {
            var collection = new StringCollection();
            foreach (var layer in instance_layers)
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

        private OpenTK.INativeWindow mNativeWindow;
        private bool mQuit;
        private ManagedVulkan.SurfaceKHR mSurface;
        private ManagedVulkan.QueueFamilyProperties[] mQueueProperties;
        private uint mGraphicsQueueNodeIndex;
        private string[] mExtensionNames;
        private ManagedVulkan.Device mDevice;
        private ManagedVulkan.Format mFormat;
        private ManagedVulkan.ColorSpaceKHR mColorSpace;
        private int mCurrentFrame;
        private ManagedVulkan.PhysicalDeviceMemoryProperties mMemoryProperties;
        private CommandPool mCommandPool;
        private SwapchainKHR mSwapchain;

        private SwapchainBuffers[] mBuffers;

        public void CreateWindow()
        {
            mNativeWindow = new OpenTK.NativeWindow();
            mNativeWindow.Width = mWidth;
            mNativeWindow.Height = mHeight;
            mNativeWindow.WindowBorder = WindowBorder.Resizable;
            mNativeWindow.KeyDown += new EventHandler<OpenTK.Input.KeyboardKeyEventArgs>(Keyboard_KeyDown);
            mNativeWindow.Visible = true;

            mQuit = false;
        }


        private void Keyboard_KeyDown(object sender, OpenTK.Input.KeyboardKeyEventArgs e)
        {
            if (e.Key == OpenTK.Input.Key.Escape)
            {
                mNativeWindow.Close();
                mQuit = true;
                return;
            }
        }

        public void InitVkSwapchain()
        {
            ManagedVulkan.Result err;

            // #ifdef _WIN32
            var createInfo = new ManagedVulkan.Win32SurfaceCreateInfoKHR
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
                Flags = 0,
                Hinstance = Process.GetCurrentProcess().Handle,
                Hwnd = mNativeWindow.WindowInfo.Handle,
            };

            ManagedVulkan.SurfaceKHR surface;
            err = mInstance.CreateWin32SurfaceKHR(createInfo, null, out surface);
            Debug.Assert(err == Result.VK_SUCCESS);
            mSurface = surface;

            bool[] supportsPresent = new bool[mQueueProperties.Length];

            // Iterate over each queue to learn whether it supports presenting:
            for (UInt32 i = 0; i < mQueueProperties.Length; ++i)
            {
                mGPU.GetPhysicalDeviceSurfaceSupportKHR(i, mSurface, out supportsPresent[i]);
            }

            // Search for a graphics and a present queue in the array of queue
            // families, try to find one that supports both
            UInt32 graphicsQueueNodeIndex = UInt32.MaxValue;
            UInt32 presentQueueNodeIndex = UInt32.MaxValue;
            for (UInt32 i = 0; i < mQueueProperties.Length; i++)
            {
                var queue = mQueueProperties[i];

                if ((queue.QueueFlags & QueueFlagBits.VK_QUEUE_GRAPHICS_BIT) != 0)
                {
                    if (graphicsQueueNodeIndex == UInt32.MaxValue)
                    {
                        graphicsQueueNodeIndex = i;
                    }

                    if (supportsPresent[i])
                    {
                        graphicsQueueNodeIndex = i;
                        presentQueueNodeIndex = i;
                        break;
                    }
                }
            }

            if (presentQueueNodeIndex == UInt32.MaxValue)
            {
                // If didn't find a queue that supports both graphics and present, then
                // find a separate present queue.
                for (UInt32 i = 0; i < mQueueProperties.Length; ++i)
                {
                    if (supportsPresent[i])
                    {
                        presentQueueNodeIndex = i;
                        break;
                    }
                }
            }

            // Generate error if could not find both a graphics and a present queue
            if (graphicsQueueNodeIndex == UInt32.MaxValue ||
                presentQueueNodeIndex == UInt32.MaxValue)
            {
                throw new VulkanLibraryException("Swapchain Initialization Failure", "Could not find a graphics and a present queue");
            }

            // VERBATIM from cube.c
            // TODO: Add support for separate queues, including presentation,
            //       synchronization, and appropriate tracking for QueueSubmit.
            // NOTE: While it is possible for an application to use a separate graphics
            //       and a present queues, this demo program assumes it is only using
            //       one:
            if (graphicsQueueNodeIndex != presentQueueNodeIndex)
            {
                throw new VulkanLibraryException("Swapchain Initialization Failure", "Could not find a common graphics and a present queue");
            }

            mGraphicsQueueNodeIndex = graphicsQueueNodeIndex;
            CreateDevice();

            ManagedVulkan.Queue deviceQueue;
            mDevice.GetDeviceQueue(mGraphicsQueueNodeIndex, 0, out deviceQueue);

            // Get the list of VkFormat's that are supported:
            ManagedVulkan.SurfaceFormatKHR[] surfFormats;
            err = mGPU.GetPhysicalDeviceSurfaceFormatsKHR(mSurface, out surfFormats);
            Debug.Assert(err == Result.VK_SUCCESS);

            // If the format list includes just one entry of VK_FORMAT_UNDEFINED,
            // the surface has no preferred format.  Otherwise, at least one
            // supported format will be returned.
            if (surfFormats.Length == 1 && surfFormats[0].Format == ManagedVulkan.Format.VK_FORMAT_UNDEFINED)
            {
                mFormat = Format.VK_FORMAT_B8G8R8A8_UNORM;
            }
            else
            {
                Debug.Assert(surfFormats.Length >= 1);
                mFormat = surfFormats[0].Format;
            }
            mColorSpace = surfFormats[0].ColorSpace;

            mQuit = false;
            mCurrentFrame = 0;

            // Get Memory information and properties

            ManagedVulkan.PhysicalDeviceMemoryProperties props;
            mGPU.GetPhysicalDeviceMemoryProperties(out props);
            mMemoryProperties = props;
        }

        private void CreateDevice()
        {
            float[] queue_priorities = new float[]{ 0.0f };
            var queue = new ManagedVulkan.DeviceQueueCreateInfo
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
                QueueFamilyIndex = mGraphicsQueueNodeIndex,
                QueuePriorities = queue_priorities,
            };

            var deviceInfo = new ManagedVulkan.DeviceCreateInfo
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
                QueueCreateInfos = new[] { queue },
                EnabledLayerNames = (mValidate) ? mDeviceValidationLayers : null,
                EnabledExtensionNames = mExtensionNames,
                EnabledFeatures = null,
            };
            ManagedVulkan.Device device;
            ManagedVulkan.Result err = mGPU.CreateDevice(deviceInfo, null, out device);
            Debug.Assert(err == ManagedVulkan.Result.VK_SUCCESS);
            mDevice = device;
        }

        public void Prepare()
        {
            ManagedVulkan.Result err;

            var cmd_pool_info = new ManagedVulkan.CommandPoolCreateInfo
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                QueueFamilyIndex = mGraphicsQueueNodeIndex,
                Flags = 0,
            };
            ManagedVulkan.CommandPool cmd_pool;
            err = mDevice.CreateCommandPool(cmd_pool_info, null, out cmd_pool);
            Debug.Assert(err == Result.VK_SUCCESS);
            mCommandPool = cmd_pool;

            var cmd = new ManagedVulkan.CommandBufferAllocateInfo
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                CommandPool = mCommandPool,
                Level = CommandBufferLevel.VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                CommandBufferCount = 1,                
            };

            PrepareBuffers();
            PrepareDepth();
            PrepareTextures();
            PrepareCubeDataBuffer();

            PrepareDescriptorLayout();
            PrepareRenderPass();
            PreparePipeline();
        }

        private void PrepareBuffers()
        {
            ManagedVulkan.Result err;
            ManagedVulkan.SwapchainKHR oldSwapchain = mSwapchain;

            SurfaceCapabilitiesKHR surfCapabilities;
            err = mGPU.GetPhysicalDeviceSurfaceCapabilitiesKHR(mSurface, out surfCapabilities);
            Debug.Assert(err == Result.VK_SUCCESS);

            ManagedVulkan.PresentModeKHR[] presentModes;
            err = mGPU.GetPhysicalDeviceSurfacePresentModesKHR(mSurface, out presentModes);
            Debug.Assert(err == Result.VK_SUCCESS);

            var swapchainExtent = new ManagedVulkan.Extent2D();
            // width and height are either both -1, or both not -1.
            if ((int) surfCapabilities.CurrentExtent.Width == -1)
            {
                // If the surface size is undefined, the size is set to
                // the size of the images requested.
                swapchainExtent.Width = (UInt32) mWidth;
                swapchainExtent.Height = (UInt32) mHeight;
            }
            else
            {
                // If the surface size is defined, the swap chain size must match
                swapchainExtent = surfCapabilities.CurrentExtent;
                mWidth = (int) swapchainExtent.Width;
                mHeight = (int) swapchainExtent.Height;
            }

            // If mailbox mode is available, use it, as is the lowest-latency non-
            // tearing mode.  If not, try IMMEDIATE which will usually be available,
            // and is fastest (though it tears).  If not, fall back to FIFO which is
            // always available.
            PresentModeKHR swapchainPresentMode = PresentModeKHR.VK_PRESENT_MODE_FIFO_KHR;
            foreach(var mode in presentModes)
            {
                if (mode == PresentModeKHR.VK_PRESENT_MODE_MAILBOX_KHR)
                {
                    swapchainPresentMode = PresentModeKHR.VK_PRESENT_MODE_MAILBOX_KHR;
                    break;
                }

                if (swapchainPresentMode != PresentModeKHR.VK_PRESENT_MODE_MAILBOX_KHR && mode == PresentModeKHR.VK_PRESENT_MODE_IMMEDIATE_KHR)
                {
                    swapchainPresentMode = PresentModeKHR.VK_PRESENT_MODE_IMMEDIATE_KHR;
                }
            }

            // Determine the number of VkImage's to use in the swap chain (we desire to
            // own only 1 image at a time, besides the images being displayed and
            // queued for display):
            UInt32 desiredNumberOfSwapchainImages =  surfCapabilities.MinImageCount + 1;
            if ((surfCapabilities.MaxImageCount > 0) &&
                (desiredNumberOfSwapchainImages > surfCapabilities.MaxImageCount))
            {
                // Application must settle for fewer images than desired:
                desiredNumberOfSwapchainImages = surfCapabilities.MaxImageCount;
            }

            ManagedVulkan.SurfaceTransformFlagBitsKHR preTransform;
            if ((surfCapabilities.SupportedTransforms & SurfaceTransformFlagBitsKHR.VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR) != 0)
            {
                preTransform = SurfaceTransformFlagBitsKHR.VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
            }
            else
            {
                preTransform = surfCapabilities.CurrentTransform;
            }

            var swapchain = new ManagedVulkan.SwapchainCreateInfoKHR
            {
                SType = ManagedVulkan.StructureType.VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
                Surface = mSurface,
                MinImageCount = desiredNumberOfSwapchainImages,
                ImageFormat = mFormat,
                ImageColorSpace = mColorSpace,
                ImageExtent = swapchainExtent,
                ImageUsage = ManagedVulkan.ImageUsageFlagBits.VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                PreTransform = preTransform,
                CompositeAlpha = CompositeAlphaFlagBitsKHR.VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
                ImageArrayLayers = 1,
                ImageSharingMode = SharingMode.VK_SHARING_MODE_EXCLUSIVE,
                QueueFamilyIndices = null,
                PresentMode = swapchainPresentMode,
                OldSwapchain = (oldSwapchain == null) ? new ManagedVulkan.SwapchainKHR() : oldSwapchain,
                Clipped = true,
            };

            SwapchainKHR output;
            err = mDevice.CreateSwapchainKHR(swapchain, null, out output);
            Debug.Assert(err == Result.VK_SUCCESS);
            mSwapchain = output;

            // If we just re-created an existing swapchain, we should destroy the old
            // swapchain at this point.
            // Note: destroying the swapchain also cleans up all its associated
            // presentable images once the platform is done with them.
            if (oldSwapchain != null && !oldSwapchain.IsNullHandle())
            {
                mDevice.DestroySwapchainKHR(oldSwapchain, null);
            }

            ManagedVulkan.Image[] swapchainImages;
            err = mDevice.GetSwapchainImagesKHR(mSwapchain, out swapchainImages);
            Debug.Assert(err == Result.VK_SUCCESS);

            int swapchainImageCount = swapchainImages.Length;
            mBuffers = new SwapchainBuffers[swapchainImageCount];

            for (int i = 0; i < swapchainImageCount; ++i)
            {
                var color_image_view = new ManagedVulkan.ImageViewCreateInfo
                {
                    SType = StructureType.VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
                    Format = mFormat,
                    Components = new ComponentMapping
                    {
                        R = ComponentSwizzle.VK_COMPONENT_SWIZZLE_R,
                        G = ComponentSwizzle.VK_COMPONENT_SWIZZLE_G,
                        B = ComponentSwizzle.VK_COMPONENT_SWIZZLE_B,
                        A = ComponentSwizzle.VK_COMPONENT_SWIZZLE_A,
                    },
                    SubresourceRange = new ImageSubresourceRange
                    {
                        AspectMask = ImageAspectFlagBits.VK_IMAGE_ASPECT_COLOR_BIT,
                        BaseMipLevel = 0,
                        LevelCount = 0,
                        BaseArrayLayer = 0,
                        LayerCount = 1,
                    },
                    ViewType = ImageViewType.VK_IMAGE_VIEW_TYPE_2D,
                    Flags = 0,
                };

                mBuffers[i].Image = swapchainImages[i];

                // Render loop will expect image to have been used before and in
                // VK_IMAGE_LAYOUT_PRESENT_SRC_KHR
                // layout and will change to COLOR_ATTACHMENT_OPTIMAL, so init the image
                // to that state
                SetImageLayout(mBuffers[i].Image, ImageAspectFlagBits.VK_IMAGE_ASPECT_COLOR_BIT,
                    ImageLayout.VK_IMAGE_LAYOUT_UNDEFINED, ImageLayout.VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, 0);
            }
        }

        CommandBuffer mCmd = new CommandBuffer(); // Buffer for initialization commands

        private void SetImageLayout(Image image, ImageAspectFlagBits aspectMask, ImageLayout old_image_layout, ImageLayout new_image_layout, AccessFlagBits srcAccessMask)
        {
            ManagedVulkan.Result err;

            if (mCmd.IsNullHandle())
            {
                var cmdInfo = new ManagedVulkan.CommandBufferAllocateInfo
                {
                    SType = StructureType.VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                    CommandPool = mCommandPool,
                    Level = CommandBufferLevel.VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                    CommandBufferCount = 1,
                };

                CommandBuffer[] cmdBuffers;
                err = mDevice.AllocateCommandBuffers(cmdInfo,out cmdBuffers);
                Debug.Assert(err == Result.VK_SUCCESS);
                Debug.Assert(cmdBuffers != null);
                Debug.Assert(cmdBuffers.Length == 1);
                mCmd = cmdBuffers[0];

                var cmd_buf_hinfo = new ManagedVulkan.CommandBufferInheritanceInfo
                {
                    SType = StructureType.VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO,
                    RenderPass = new ManagedVulkan.RenderPass(),
                    Subpass = 0,
                    Framebuffer = new ManagedVulkan.Framebuffer(),
                    OcclusionQueryEnable = false,
                    QueryFlags = 0,
                    PipelineStatistics = 0,
                };
                var cmd_buf_info = new ManagedVulkan.CommandBufferBeginInfo
                {
                    SType = StructureType.VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
                    Flags = 0,
                    InheritanceInfo = cmd_buf_hinfo,
                };

                err = mCmd.BeginCommandBuffer(cmd_buf_info);
                Debug.Assert(err == Result.VK_SUCCESS);
            }

            var image_memory_barrier = new ManagedVulkan.ImageMemoryBarrier
            {
                SType = StructureType.VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
                SrcAccessMask = srcAccessMask,
                DstAccessMask = 0,
                OldLayout = old_image_layout,
                NewLayout = new_image_layout,
                Image = image,
                SubresourceRange = new ImageSubresourceRange
                {
                    AspectMask = aspectMask,
                    BaseMipLevel = 0,
                    LevelCount = 1,
                    BaseArrayLayer = 0,
                    LayerCount = 1,
                },
            };

            if (new_image_layout == ImageLayout.VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL)
            {
                /* Make sure anything that was copying from this image has completed */
                image_memory_barrier.DstAccessMask = AccessFlagBits.VK_ACCESS_TRANSFER_READ_BIT;
            }

            if (new_image_layout == ImageLayout.VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL)
            {
                image_memory_barrier.DstAccessMask = AccessFlagBits.VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            }

            if (new_image_layout == ImageLayout.VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL)
            {
                image_memory_barrier.DstAccessMask = AccessFlagBits.VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
            }

            if (new_image_layout == ImageLayout.VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL)
            {
                /* Make sure any Copy or CPU writes to image are flushed */
                image_memory_barrier.DstAccessMask =
                    AccessFlagBits.VK_ACCESS_SHADER_READ_BIT | AccessFlagBits.VK_ACCESS_INPUT_ATTACHMENT_READ_BIT;
            }

            PipelineStageFlagBits src_stages = PipelineStageFlagBits.VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
            PipelineStageFlagBits dest_stages = PipelineStageFlagBits.VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;

            mCmd.CmdPipelineBarrier(src_stages, dest_stages, 0, null, null, new[] { image_memory_barrier });

        }

        private void PreparePipeline()
        {
            throw new NotImplementedException();
        }

        private void PrepareRenderPass()
        {
            throw new NotImplementedException();
        }

        private void PrepareDescriptorLayout()
        {
            throw new NotImplementedException();
        }

        private void PrepareCubeDataBuffer()
        {
            throw new NotImplementedException();
        }

        private void PrepareTextures()
        {
            throw new NotImplementedException();
        }

        private void PrepareDepth()
        {
            throw new NotImplementedException();
        }



        public void Cleanup()
        {
            mPrepared = false;

            if (mSwapchain != null)
            {
                mDevice.DestroySwapchainKHR(mSwapchain, null);
            }


            if (mBuffers != null)
            {
                foreach (var buffer in mBuffers)
                {
                    if (buffer != null)
                    {
                        if (buffer.View != null)
                        {
                            mDevice.DestroyImageView(buffer.View, null);
                        }
                        if (buffer.Cmd != null)
                        {
                            mDevice.FreeCommandBuffers(mCommandPool, new[] { buffer.Cmd });
                        }
                    }
                }
            }


            if (mCommandPool != null)
            {
                mDevice.DestroyCommandPool(mCommandPool, null);
            }

            if (mDevice != null)
            {
                mDevice.DestroyDevice(null);
            }

            if (mValidate)
            {
                mInstance.DestroyDebugReportCallbackEXT(mMsgCallback, null);
            }

            if (mSurface != null)
            {
                mInstance.DestroySurfaceKHR(mSurface, null);
            }

            if (mInstance != null)
            {
                mInstance.DestroyInstance(null);
            }
        }
    }
}
