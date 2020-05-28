using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;

namespace NWN
{
    public static class Main
    {
        public const uint OBJECT_INVALID = 0x7F000000;
        public static uint OBJECT_SELF { get; private set; } = OBJECT_INVALID;

        private static Stack<ScriptContext> ScriptContexts = new Stack<ScriptContext>();

        private static ulong NextEventId = 0;
        private static Dictionary<ulong, Closure> Closures = new Dictionary<ulong, Closure>();

        private struct ScriptContext
        {
            public uint OwnerObject;
            public string ScriptName;
        }

        private struct Closure
        {
            public uint OwnerObject;
            public ActionDelegate Run;
        }

        //
        // Entry point from NWNX
        //
        public static int Bootstrap(IntPtr arg, int argLength)
        {
            Console.WriteLine("Beginning Bootstrap");

            // We register our handles with functions defined below in this class.
            Internal.NativeEventHandles nativeEventHandles;
            nativeEventHandles.MainLoop = OnMainLoop;
            nativeEventHandles.Closure = OnClosure;
            nativeEventHandles.RunScript = OnRunScript;

            Internal.ManagedHandles managedHandles;
            managedHandles.ClosureAssignCommand = ClosureAssignCommand;
            managedHandles.ClosureDelayCommand = ClosureDelayCommand;
            managedHandles.ClosureActionDoCommand = ClosureActionDoCommand;

            int retVal = Internal.Bootstrap(arg, argLength, () => OBJECT_SELF, nativeEventHandles, managedHandles);

            if (retVal == 0)
            {
                AppendAssemblyToPath();
            }

            return retVal;
        }

        // Needed to allow native libs to be loaded.
        private static void AppendAssemblyToPath()
        {
            string envPath = Environment.GetEnvironmentVariable("PATH", EnvironmentVariableTarget.Process);
            string assemblyDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);

            Environment.SetEnvironmentVariable("PATH", $"{envPath}; {assemblyDir}");
        }

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

        public static int OnRunScript(string script, uint oidSelf)
        {
            int ret = 0;
            OBJECT_SELF = oidSelf;
            ScriptContexts.Push(new ScriptContext {OwnerObject = oidSelf, ScriptName = script});
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

        public static void OnClosure(ulong eid, uint oidSelf)
        {
            uint old = OBJECT_SELF;
            OBJECT_SELF = oidSelf;
            try
            {
                Closures[eid].Run();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }

            Closures.Remove(eid);
            OBJECT_SELF = old;
        }

        public static void ClosureAssignCommand(uint obj, ActionDelegate func)
        {
            if (Internal.NativeFunctions.ClosureAssignCommand(obj, NextEventId) != 0)
            {
                Closures.Add(NextEventId++, new Closure {OwnerObject = obj, Run = func});
            }
        }

        public static void ClosureDelayCommand(uint obj, float duration, ActionDelegate func)
        {
            if (Internal.NativeFunctions.ClosureDelayCommand(obj, duration, NextEventId) != 0)
            {
                Closures.Add(NextEventId++, new Closure {OwnerObject = obj, Run = func});
            }
        }

        public static void ClosureActionDoCommand(uint obj, ActionDelegate func)
        {
            if (Internal.NativeFunctions.ClosureActionDoCommand(obj, NextEventId) != 0)
            {
                Closures.Add(NextEventId++, new Closure {OwnerObject = obj, Run = func});
            }
        }
    }
}
