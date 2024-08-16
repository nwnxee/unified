using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace NWN
{
  internal unsafe partial class Internal
  {
    public const uint OBJECT_INVALID = 0x7F000000;
    public static uint OBJECT_SELF { get; private set; } = OBJECT_INVALID;

    private static readonly Encoding Encoding;

    static Internal()
    {
      Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
      Encoding = Encoding.GetEncoding("windows-1252");
    }

    [UnmanagedCallersOnly]
    public static void OnMainLoop(ulong frame)
    {
      try
      {
        Entrypoints.OnMainLoop(frame);
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }
    }

    private struct ScriptContext
    {
      public uint OwnerObject;
      public string ScriptName;
    }

    private static Stack<ScriptContext> ScriptContexts = new Stack<ScriptContext>();

    [UnmanagedCallersOnly]
    public static int OnRunScript(byte* pScript, uint oidSelf)
    {
      int ret = 0;
      OBJECT_SELF = oidSelf;
      string script = ReadNullTerminatedString(pScript);

      ScriptContexts.Push(new ScriptContext { OwnerObject = oidSelf, ScriptName = script });
      try
      {
        ret = Entrypoints.OnRunScript(script, oidSelf);
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }

      ScriptContexts.Pop();
      OBJECT_SELF = ScriptContexts.Count == 0 ? OBJECT_INVALID : ScriptContexts.Peek().OwnerObject;
      return ret;
    }

    private struct Closure
    {
      public uint OwnerObject;
      public ActionDelegate Run;
    }

    private static ulong NextEventId = 0;
    private static Dictionary<ulong, Closure> Closures = new Dictionary<ulong, Closure>();

    [UnmanagedCallersOnly]
    public static void OnClosure(ulong eventId, uint oidSelf)
    {
      uint old = OBJECT_SELF;
      OBJECT_SELF = oidSelf;
      try
      {
        Closures[eventId].Run();
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }

      Closures.Remove(eventId);
      OBJECT_SELF = old;
    }

    [UnmanagedCallersOnly]
    public static void OnSignal(byte* pSignal)
    {
      string signal = ReadNullTerminatedString(pSignal);
      try
      {
        switch (signal)
        {
          case "ON_MODULE_LOAD_FINISH":
            Entrypoints.OnModuleLoad();
            break;
          case "ON_DESTROY_SERVER":
            Entrypoints.OnShutdown();
            break;
        }
      }
      catch (Exception e)
      {
        Console.WriteLine(e.ToString());
      }
    }

    public static void ClosureAssignCommand(uint obj, ActionDelegate func)
    {
      if (NWNXPInvoke.ClosureAssignCommand(obj, NextEventId) != 0)
      {
        Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
      }
    }

    public static void ClosureDelayCommand(uint obj, float duration, ActionDelegate func)
    {
      if (NWNXPInvoke.ClosureDelayCommand(obj, duration, NextEventId) != 0)
      {
        Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
      }
    }

    public static void ClosureActionDoCommand(uint obj, ActionDelegate func)
    {
      if (NWNXPInvoke.ClosureActionDoCommand(obj, NextEventId) != 0)
      {
        Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
      }
    }

    private static string ReadNullTerminatedString(byte* cString)
    {
      return Encoding.GetString(cString, GetStringLength(cString));
    }

    private static int GetStringLength(byte* cString, int? maxLength = null)
    {
      byte* walk = cString;
      while (*walk != 0 && (maxLength == null || walk - cString < maxLength))
      {
        walk++;
      }

      return (int)(walk - cString);
    }
  }
}
