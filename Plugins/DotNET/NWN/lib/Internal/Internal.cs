using System;
using System.Runtime.InteropServices;

namespace NWN
{
    public static partial class Internal
    {
        public delegate uint ObjectSelfDelegate();

        public static ObjectSelfDelegate ObjectSelf;
        public static NativeHandles NativeFunctions;
        public static ManagedHandles ManagedFunctions;
        private static NativeEventHandles eventHandles;

        public static int Bootstrap(IntPtr nativeHandlesPtr, int nativeHandlesLength, ObjectSelfDelegate objectSelf, NativeEventHandles nativeEventHandles, ManagedHandles managedHandles)
        {
            if (nativeHandlesPtr == IntPtr.Zero)
            {
                Console.WriteLine("Received NULL bootstrap structure");
                return 1;
            }

            int expectedLength = Marshal.SizeOf(typeof(NativeHandles));
            if (nativeHandlesLength < expectedLength)
            {
                Console.WriteLine($"Received bootstrap structure too small - actual={nativeHandlesLength}, expected={expectedLength}");
                return 1;
            }

            if (nativeHandlesLength > expectedLength)
            {
                Console.WriteLine($"WARNING: Received bootstrap structure bigger than expected - actual={nativeHandlesLength}, expected={expectedLength}");
                Console.WriteLine("         This usually means that native code version is ahead of the managed code");
            }

            ObjectSelf = objectSelf;
            NativeFunctions = Marshal.PtrToStructure<NativeHandles>(nativeHandlesPtr);
            ManagedFunctions = managedHandles;
            RegisterNativeHandlers(nativeEventHandles);

            return 0;
        }

        private static void RegisterNativeHandlers(NativeEventHandles eventHandles)
        {
            Internal.eventHandles = eventHandles;

            int size = Marshal.SizeOf(typeof(NativeEventHandles));
            IntPtr ptr = Marshal.AllocHGlobal(size);
            Marshal.StructureToPtr(Internal.eventHandles, ptr, false);
            NativeFunctions.RegisterHandlers(ptr, (uint) size);
            Marshal.FreeHGlobal(ptr);
        }
    }
}
