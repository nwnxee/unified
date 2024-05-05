using System;

namespace NWN
{
  public class Entrypoints
  {
    public const int SCRIPT_HANDLED = 0;
    public const int SCRIPT_NOT_HANDLED = -1;

    //
    // This is called once every main loop frame, outside of object context
    //
    public static void OnMainLoop(ulong frame)
    {
      Console.WriteLine($"MainLoop frame {frame}");
    }

    //
    // This is called every time a named script is scheduled to run.
    // oidSelf is the object running the script (OBJECT_SELF), and script
    // is the name given to the event handler (e.g. via SetEventScript).
    // If the script is not handled in the managed code, and needs to be
    // forwarded to the original NWScript VM, return SCRIPT_NOT_HANDLED.
    // Otherwise, return either 0/SCRIPT_HANDLED for void main() scripts,
    // or an int (0 or 1) for StartingConditionals
    //
    public static int OnRunScript(string script, uint oidSelf)
    {
      Console.WriteLine($"Runscript '{script}' on oid {oidSelf}");

      return SCRIPT_NOT_HANDLED; // passthrough
    }

    //
    // This is called once when the internal structures have been initialized
    // The module is not yet loaded, so most NWScript functions will fail if
    // called here.
    //
    public static void OnStart()
    {
      Console.WriteLine("OnStart() called");
    }

    //
    // This is called once, just before the module load script is called.
    // Unlike OnStart, NWScript functions are available to use here.
    //
    public static void OnModuleLoad()
    {
      Console.WriteLine("OnModuleLoad() called");
    }

    //
    // This is called once, just before the server will shutdown. In here, you should
    // save anything that might not be flushed to disk, and perform any last cleanup.
    // NWScript functions are available to use.
    //
    public static void OnShutdown()
    {
      Console.WriteLine("OnShutdown() called");
    }
  }
}
