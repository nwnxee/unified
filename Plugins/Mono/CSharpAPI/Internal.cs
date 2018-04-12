using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace NWN
{
    class Internal
    {
        public const uint OBJECT_INVALID = 0x7F000000;

        public static NWN.Object OBJECT_SELF { get; private set; }

        private static Stack<NWN.Object> s_ScriptContexts = new Stack<NWN.Object>();

        private static void PushScriptContext(uint oid)
        {
            s_ScriptContexts.Push(oid);
            OBJECT_SELF = oid;
        }

        private static void PopScriptContext()
        {
            s_ScriptContexts.Pop();
            OBJECT_SELF = s_ScriptContexts.Count == 0 ? OBJECT_INVALID : s_ScriptContexts.Peek();
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void CallBuiltIn(int id);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushInteger(int value);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushFloat(float value);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushString(string value);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushObject_Native(uint value);

        public static void StackPushObject(NWN.Object value, bool defAsObjSelf)
        {
            if (value == null)
            {
                value = defAsObjSelf ? OBJECT_SELF : OBJECT_INVALID;
            }

            StackPushObject_Native(value.m_ObjId);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushVector_Native(NWN.Vector value);

        public static void StackPushVector(NWN.Vector? value)
        {
            if (!value.HasValue)
            {
                value = new NWN.Vector(0.0f, 0.0f, 0.0f);
            }

            StackPushVector_Native(value.Value);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushEffect_Native(IntPtr value);

        public static void StackPushEffect(NWN.Effect value)
        {
            StackPushEffect_Native(value.m_Handle);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushEvent_Native(IntPtr value);

        public static void StackPushEvent(NWN.Event value)
        {
            StackPushEvent_Native(value.m_Handle);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushLocation_Native(IntPtr value);

        public static void StackPushLocation(NWN.Location value)
        {
            StackPushLocation_Native(value.m_Handle);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushTalent_Native(IntPtr value);

        public static void StackPushTalent(NWN.Talent value)
        {
            StackPushTalent_Native(value.m_Handle);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void StackPushItemProperty_Native(IntPtr value);

        public static void StackPushItemProperty(NWN.ItemProperty value)
        {
            StackPushItemProperty_Native(value.m_Handle);
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static int StackPopInteger();

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static float StackPopFloat();

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static string StackPopString();

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static uint StackPopObject_Native();

        public static NWN.Object StackPopObject()
        {
            return StackPopObject_Native();
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static NWN.Vector StackPopVector();

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static IntPtr StackPopEffect_Native();

        public static NWN.Effect StackPopEffect()
        {
            return new NWN.Effect { m_Handle = StackPopEffect_Native() };
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static IntPtr StackPopEvent_Native();

        public static NWN.Event StackPopEvent()
        {
            return new NWN.Event { m_Handle = StackPopEvent_Native() };
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static IntPtr StackPopLocation_Native();

        public static NWN.Location StackPopLocation()
        {
            return new NWN.Location { m_Handle = StackPopLocation_Native() };
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static IntPtr StackPopTalent_Native();

        public static NWN.Talent StackPopTalent()
        {
            return new NWN.Talent { m_Handle = StackPopTalent_Native() };
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static IntPtr StackPopItemProperty_Native();

        public static NWN.ItemProperty StackPopItemProperty()
        {
            return new NWN.ItemProperty { m_Handle = StackPopItemProperty_Native() };
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void BeginClosure(uint oid);

        public struct Closure
        {
            public NWN.Object m_Object;
            public float m_Delay;
            public long m_AddedAt;
            public ActionDelegate m_Func;
        }

        private static List<Closure> m_Closures = new List<Closure>();

        public static void EnqueueClosure(Closure closure)
        {
            if (closure.m_Delay != 0.0f)
            {
                closure.m_AddedAt = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;
            }

            m_Closures.Add(closure);
        }

        private static void ExecuteClosures()
        {
            // Take copy in case a closure adds more closures ...
            List<Closure> closuresCopy = new List<Closure>(m_Closures);
            m_Closures.Clear();

            foreach (Closure closure in closuresCopy)
            {
                if (closure.m_Delay != 0.0f)
                {
                    long now = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;
                    if (now - closure.m_AddedAt > closure.m_Delay * 1000)
                    {
                        // Not ready yet.
                        m_Closures.Add(closure);
                        continue;
                    }
                }

                OBJECT_SELF = closure.m_Object;
                BeginClosure(closure.m_Object.m_ObjId);
                closure.m_Func();
            }
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void FreeEffect(IntPtr ptr);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void FreeEvent(IntPtr ptr);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void FreeLocation(IntPtr ptr);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void FreeTalent(IntPtr ptr);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public extern static void FreeItemProperty(IntPtr ptr);
    }
}
