using System;
using System.Runtime.InteropServices;

namespace NWN
{
  internal unsafe partial class Internal
  {
    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void RegisterMainLoopHandler(delegate* unmanaged<ulong, void> handler);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void RegisterRunScriptHandler(delegate* unmanaged<byte*, uint, int> handler);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void RegisterClosureHandler(delegate* unmanaged<ulong, uint, void> handler);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void RegisterSignalHandler(delegate* unmanaged<byte*, void> handler);

    public static void Bootstrap()
    {
      NWNXPInvoke.RegisterMainLoopHandler(&OnMainLoop);
      NWNXPInvoke.RegisterRunScriptHandler(&OnRunScript);
      NWNXPInvoke.RegisterClosureHandler(&OnClosure);
      NWNXPInvoke.RegisterSignalHandler(&OnSignal);

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
