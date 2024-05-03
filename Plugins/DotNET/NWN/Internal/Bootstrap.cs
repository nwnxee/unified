using System;
using System.Runtime.InteropServices;

namespace NWN
{
  internal partial class Internal
  {
    public delegate void MainLoopHandlerDelegate(ulong frame);
    public delegate int RunScriptHandlerDelegate(string script, uint oid);
    public delegate void ClosureHandlerDelegate(ulong eid, uint oid);
    public delegate void SignalHandlerDelegate(string signal);
    public delegate void AssertHandlerDelegate(string message, string stackTrace);
    public delegate void CrashHandlerDelegate(int signal, string stackTrace);

    [StructLayout(LayoutKind.Sequential)]
    public struct AllHandlers
    {
      public MainLoopHandlerDelegate  MainLoop;
      public RunScriptHandlerDelegate RunScript;
      public ClosureHandlerDelegate   Closure;
      public SignalHandlerDelegate    Signal;
      public AssertHandlerDelegate    AssertFail;
      public CrashHandlerDelegate     CrashHandler;
    }

    private static AllHandlers _handlers;

    public static void RegisterHandlers(AllHandlers handlers)
    {
      _handlers = handlers;
      var size = Marshal.SizeOf(typeof(AllHandlers));
      IntPtr ptr = Marshal.AllocHGlobal(size);
      Marshal.StructureToPtr(_handlers, ptr, false);
      NWNXPInvoke.RegisterHandlers(ptr, (uint)size);
      Marshal.FreeHGlobal(ptr);
    }

    public static void Bootstrap()
    {
      AllHandlers handlers = new AllHandlers();
      handlers.MainLoop  = OnMainLoop;
      handlers.RunScript = OnRunScript;
      handlers.Closure   = OnClosure;
      handlers.Signal    = OnSignal;
      RegisterHandlers(handlers);

      try
      {
        Entrypoints.OnStart();
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }
    }
  }
}
