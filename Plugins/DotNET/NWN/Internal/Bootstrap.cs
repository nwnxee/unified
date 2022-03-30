using System;
using System.Numerics;
using System.Runtime.InteropServices;
using System.Security;
using System.Diagnostics;
namespace NWN
{
    partial class Internal
    {
        public delegate void MainLoopHandlerDelegate(ulong frame);
        public delegate int RunScriptHandlerDelegate(string script, uint oid);
        public delegate void ClosureHandlerDelegate(ulong eid, uint oid);
        public delegate void SignalHandlerDelegate(string signal);

        [StructLayout(LayoutKind.Sequential)]
        public struct AllHandlers
        {
            public MainLoopHandlerDelegate  MainLoop;
            public RunScriptHandlerDelegate RunScript;
            public ClosureHandlerDelegate   Closure;
            public SignalHandlerDelegate    Signal;
        }

        [SuppressUnmanagedCodeSecurity]
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate NWNXExportedGlobals GetNWNXExportedGlobalsDelegate();

        [StructLayout(LayoutKind.Sequential)]
        public struct NWNXExportedGlobals
        {
            public IntPtr PSBuildNumber;
            public IntPtr PSBuildRevision;
            public IntPtr PPExoBase;
            public IntPtr PPExoResMan;
            public IntPtr PPVirtualMachine;
            public IntPtr PPScriptCompiler;
            public IntPtr PPAppManager;
            public IntPtr PPTlkTable;
            public IntPtr PPRules;
            public IntPtr PPExoTaskManager;
            public IntPtr PBEnableCombatDebugging;
            public IntPtr PBEnableSavingThrowDebugging;
            public IntPtr PBEnableMovementSpeedDebugging;
            public IntPtr PBEnableHitDieDebugging;
            public IntPtr PBExitProgram;
        }

        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr GetFunctionPointerDelegate(string name);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void RegisterHandlersDelegate(IntPtr handlers, uint size);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void CallBuiltInDelegate(int id);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushIntegerDelegate(int value);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushFloatDelegate(float value);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushStringDelegate(string value);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushStringUTF8Delegate(string value);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushObjectDelegate(uint value);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushVectorDelegate(Vector3 value);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushGameDefinedStructureDelegate(int type, IntPtr str);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int StackPopIntegerDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate float StackPopFloatDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate string StackPopStringDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate string StackPopStringUTF8Delegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate uint StackPopObjectDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate Vector3 StackPopVectorDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr StackPopGameDefinedStructureDelegate(int type);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FreeEffectDelegate(IntPtr ptr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FreeEventDelegate(IntPtr ptr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FreeLocationDelegate(IntPtr ptr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FreeTalentDelegate(IntPtr ptr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void FreeItemPropertyDelegate(IntPtr ptr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr FreeGameDefinedStructureDelegate(int type, IntPtr str);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int ClosureAssignCommandDelegate(uint oid, ulong eventId);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int ClosureDelayCommandDelegate(uint oid, float duration, ulong eventId);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int ClosureActionDoCommandDelegate(uint oid, ulong eventId);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxSetFunctionDelegate(string plugin, string function);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushIntDelegate(int n);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushFloatDelegate(float f);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushObjectDelegate(uint o);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushStringDelegate(string s);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushStringUTF8Delegate(string s);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushEffectDelegate(IntPtr e);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushItemPropertyDelegate(IntPtr ip);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int nwnxPopIntDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate float nwnxPopFloatDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate uint nwnxPopObjectDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate string nwnxPopStringDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate string nwnxPopStringUTF8Delegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr nwnxPopEffectDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr nwnxPopItemPropertyDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxCallFunctionDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr RequestHookDelegate(IntPtr address, IntPtr managedFuncPtr, int priority);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void ReturnHookDelegate(IntPtr hook);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void StackPushRawStringDelegate(IntPtr charPtr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr StackPopRawStringDelegate();
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void nwnxPushRawStringDelegate(IntPtr charPtr);
        [SuppressUnmanagedCodeSecurity][UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate IntPtr nwnxPopRawStringDelegate();

        [StructLayout(LayoutKind.Sequential)]
        public readonly struct BootstrapArgs
        {
            public readonly GetFunctionPointerDelegate            GetFunctionPointer;
            public readonly RegisterHandlersDelegate              RegisterHandlers;
            public readonly CallBuiltInDelegate                   CallBuiltIn;
            public readonly StackPushIntegerDelegate              StackPushInteger;
            public readonly StackPushFloatDelegate                StackPushFloat;
            public readonly StackPushStringDelegate               StackPushString;
            public readonly StackPushStringUTF8Delegate           StackPushStringUTF8;
            public readonly StackPushObjectDelegate               StackPushObject;
            public readonly StackPushVectorDelegate               StackPushVector;
            public readonly StackPushGameDefinedStructureDelegate StackPushGameDefinedStructure;
            public readonly StackPopIntegerDelegate               StackPopInteger;
            public readonly StackPopFloatDelegate                 StackPopFloat;
            public readonly StackPopStringDelegate                StackPopString;
            public readonly StackPopStringUTF8Delegate            StackPopStringUTF8;
            public readonly StackPopObjectDelegate                StackPopObject;
            public readonly StackPopVectorDelegate                StackPopVector;
            public readonly StackPopGameDefinedStructureDelegate  StackPopGameDefinedStructure;
            public readonly FreeGameDefinedStructureDelegate      FreeGameDefinedStructure;
            public readonly ClosureAssignCommandDelegate          ClosureAssignCommand;
            public readonly ClosureDelayCommandDelegate           ClosureDelayCommand;
            public readonly ClosureActionDoCommandDelegate        ClosureActionDoCommand;
            public readonly nwnxSetFunctionDelegate               nwnxSetFunction;
            public readonly nwnxPushIntDelegate                   nwnxPushInt;
            public readonly nwnxPushFloatDelegate                 nwnxPushFloat;
            public readonly nwnxPushObjectDelegate                nwnxPushObject;
            public readonly nwnxPushStringDelegate                nwnxPushString;
            public readonly nwnxPushStringUTF8Delegate            nwnxPushStringUTF8;
            public readonly nwnxPushEffectDelegate                nwnxPushEffect;
            public readonly nwnxPushItemPropertyDelegate          nwnxPushItemProperty;
            public readonly nwnxPopIntDelegate                    nwnxPopInt;
            public readonly nwnxPopFloatDelegate                  nwnxPopFloat;
            public readonly nwnxPopObjectDelegate                 nwnxPopObject;
            public readonly nwnxPopStringDelegate                 nwnxPopString;
            public readonly nwnxPopStringUTF8Delegate             nwnxPopStringUTF8;
            public readonly nwnxPopEffectDelegate                 nwnxPopEffect;
            public readonly nwnxPopItemPropertyDelegate           nwnxPopItemProperty;
            public readonly nwnxCallFunctionDelegate              nwnxCallFunction;
            public readonly GetNWNXExportedGlobalsDelegate        GetNWNXExportedGlobals;
            public readonly RequestHookDelegate                   RequestHook;
            public readonly ReturnHookDelegate                    ReturnHook;
            public readonly StackPushRawStringDelegate            StackPushRawString;
            public readonly StackPopRawStringDelegate             StackPopRawString;
            public readonly nwnxPushRawStringDelegate             nwnxPushRawString;
            public readonly nwnxPopRawStringDelegate              nwnxPopRawString;
        }
        public static BootstrapArgs NativeFunctions;
        private static AllHandlers _handlers;

        public static void RegisterHandlers(AllHandlers handlers)
        {
            _handlers = handlers;
            var size = System.Runtime.InteropServices.Marshal.SizeOf(typeof(AllHandlers));
            IntPtr ptr = Marshal.AllocHGlobal(size);
            Marshal.StructureToPtr(_handlers, ptr, false);
            NativeFunctions.RegisterHandlers(ptr, (uint)size);
            Marshal.FreeHGlobal(ptr);
        }

        public static int Bootstrap(IntPtr arg, int argLength)
        {
            if (arg == (IntPtr)0)
            {
                Console.WriteLine("Received NULL bootstrap structure");
                return 1;
            }
            int expectedLength = System.Runtime.InteropServices.Marshal.SizeOf(typeof(BootstrapArgs));
            if (argLength < expectedLength)
            {
                Console.WriteLine($"Received bootstrap structure too small - actual={argLength}, expected={expectedLength}");
                return 1;
            }
            if (argLength > expectedLength)
            {
                Console.WriteLine($"WARNING: Received bootstrap structure bigger than expected - actual={argLength}, expected={expectedLength}");
                Console.WriteLine($"         This usually means that native code version is ahead of the managed code");
            }

            NativeFunctions = Marshal.PtrToStructure<BootstrapArgs>(arg);

            AllHandlers handlers;
            handlers.MainLoop  = NWN.Internal.OnMainLoop;
            handlers.RunScript = NWN.Internal.OnRunScript;
            handlers.Closure   = NWN.Internal.OnClosure;
            handlers.Signal    = NWN.Internal.OnSignal;
            RegisterHandlers(handlers);

            try
            {
                NWN.Entrypoints.OnStart();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            return 0;
        }
    }
}
