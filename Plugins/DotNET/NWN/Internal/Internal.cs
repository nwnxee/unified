using System;
using System.Collections.Generic;
namespace NWN
{
    partial class Internal
    {
        public const uint OBJECT_INVALID = 0x7F000000;
        public static NWN.Object OBJECT_SELF { get; private set; } = OBJECT_INVALID;

        public static void OnMainLoop(ulong frame)
        {
            NWN.Entrypoints.OnMainLoop(frame);
        }

        private static Stack<NWN.Object> ScriptContexts = new Stack<NWN.Object>();
        public static int OnRunScript(string script, uint oidSelf)
        {
            OBJECT_SELF = oidSelf;
            ScriptContexts.Push(oidSelf);
              int ret = NWN.Entrypoints.OnRunScript(script, oidSelf);
            ScriptContexts.Pop();
            OBJECT_SELF = ScriptContexts.Count == 0 ? OBJECT_INVALID : ScriptContexts.Peek();
            return ret;
        }

        private struct Closure
        {
            public NWN.Object OwnerObject;
            public ActionDelegate Run;
        }
        private static ulong NextEventId = 0;
        private static Dictionary<ulong, Closure> Closures = new Dictionary<ulong, Closure>();

        public static void OnClosure(ulong eid, uint oidSelf)
        {
            Closures[eid].Run();
            Closures.Remove(eid);
        }

        public static void ClosureAssignCommand(NWN.Object obj, ActionDelegate func)
        {
            if (NativeFunctions.ClosureAssignCommand(obj.Self, NextEventId) != 0)
            {
                Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
            }
        }

        public static void ClosureDelayCommand(NWN.Object obj, float duration, ActionDelegate func)
        {
            if (NativeFunctions.ClosureDelayCommand(obj.Self, duration, NextEventId) != 0)
            {
                Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
            }
        }

        public static void ClosureActionDoCommand(NWN.Object obj, ActionDelegate func)
        {
            if (NativeFunctions.ClosureActionDoCommand(obj.Self, NextEventId) != 0)
            {
                Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
            }
        }
    }
}
