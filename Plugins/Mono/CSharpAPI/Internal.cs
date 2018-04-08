using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace NWN
{
    class Internal
    {
        public const uint OBJECT_INVALID = 0x7F000000;

        public static NWN.Object OBJECT_SELF { get; private set; }

        private static Stack<NWN.Object> s_ObjSelfStack = new Stack<NWN.Object>();

        static void PushScriptContext(uint objId)
        {
            s_ObjSelfStack.Push(new NWN.Object { m_ObjId = objId });
            OBJECT_SELF = s_ObjSelfStack.Peek();
        }

        static void PopScriptContext(uint objId)
        {
            s_ObjSelfStack.Pop();
            OBJECT_SELF = s_ObjSelfStack.Count == 0 ? null : s_ObjSelfStack.Peek();
        }

        [DllImport("NWNX_Mono.so")]
        public extern static void CallBuiltIn(int id);

        [DllImport("NWNX_Mono.so")]
        public extern static void StackPushInteger(int value);

        [DllImport("NWNX_Mono.so")]
        public extern static void StackPushFloat(float value);

        [DllImport("NWNX_Mono.so")]
        public extern static void StackPushString(string value);

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushObject")]
        public extern static void StackPushObject_Native(uint value);

        public static void StackPushObject(NWN.Object value, bool defAsObjSelf)
        {
            if (value == null)
            {
                value = defAsObjSelf ? OBJECT_SELF : OBJECT_INVALID;
            }

            StackPushObject_Native(value.m_ObjId);
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushVector")]
        public extern static void StackPushVector_Native(NWN.Vector value);

        public static void StackPushVector(NWN.Vector? value)
        {
            if (!value.HasValue)
            {
                value = new NWN.Vector(0.0f, 0.0f, 0.0f);
            }

            StackPushVector_Native(value.Value);
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushEffect")]
        public extern static void StackPushEffect_Native(IntPtr value);

        public static void StackPushEffect(NWN.Effect value)
        {
            StackPushEffect_Native(value.m_Handle);
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushEvent")]
        public extern static void StackPushEvent_Native(IntPtr value);

        public static void StackPushEvent(NWN.Event value)
        {
            StackPushEvent_Native(value.m_Handle);
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushLocation")]
        public extern static void StackPushLocation_Native(IntPtr value);

        public static void StackPushLocation(NWN.Location value)
        {
            StackPushLocation_Native(value.m_Handle);
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushTalent")]
        public extern static void StackPushTalent_Native(IntPtr value);

        public static void StackPushTalent(NWN.Talent value)
        {
            StackPushTalent_Native(value.m_Handle);
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPushItemProperty")]
        public extern static void StackPushItemProperty_Native(IntPtr value);

        public static void StackPushItemProperty(NWN.ItemProperty value)
        {
            StackPushItemProperty_Native(value.m_Handle);
        }

        [DllImport("NWNX_Mono.so")]
        public extern static int StackPopInteger();

        [DllImport("NWNX_Mono.so")]
        public extern static float StackPopFloat();

        [DllImport("NWNX_Mono.so")]
        public extern static string StackPopString();

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPopObject")]
        public extern static uint StackPopObject_Native();

        public static NWN.Object StackPopObject()
        {
            return StackPopObject_Native();
        }

        [DllImport("NWNX_Mono.so")]
        public extern static NWN.Vector StackPopVector();

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPopEffect")]
        public extern static IntPtr StackPopEffect_Native();

        public static NWN.Effect StackPopEffect()
        {
            return new NWN.Effect { m_Handle = StackPopEffect_Native() };
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPopEvent")]
        public extern static IntPtr StackPopEvent_Native();

        public static NWN.Event StackPopEvent()
        {
            return new NWN.Event { m_Handle = StackPopEvent_Native() };
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPopLocation")]
        public extern static IntPtr StackPopLocation_Native();

        public static NWN.Location StackPopLocation()
        {
            return new NWN.Location { m_Handle = StackPopLocation_Native() };
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPopTalent")]
        public extern static IntPtr StackPopTalent_Native();

        public static NWN.Talent StackPopTalent()
        {
            return new NWN.Talent { m_Handle = StackPopTalent_Native() };
        }

        [DllImport("NWNX_Mono.so", EntryPoint = "StackPopItemProperty")]
        public extern static IntPtr StackPopItemProperty_Native();

        public static NWN.ItemProperty StackPopItemProperty()
        {
            return new NWN.ItemProperty { m_Handle = StackPopItemProperty_Native() };
        }
    }
}
