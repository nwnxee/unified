using System.Runtime.InteropServices;

namespace NWN
{
    public static partial class Internal
    {
        public delegate void MainLoopHandlerDelegate(ulong frame);

        public delegate int RunScriptHandlerDelegate(string script, uint oid);

        public delegate void ClosureHandlerDelegate(ulong eid, uint oid);

        [StructLayout(LayoutKind.Sequential)]
        public struct NativeEventHandles
        {
            public MainLoopHandlerDelegate MainLoop;
            public RunScriptHandlerDelegate RunScript;
            public ClosureHandlerDelegate Closure;
        }
    }
}
