using System;
using System.Runtime.InteropServices;
using System.Security;
using System.Diagnostics;
namespace NWN
{
    [StructLayout(LayoutKind.Sequential)]
    public struct Vector
    {
        public float x;
        public float y;
        public float z;

        public Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    public partial class Object
    {
        public const uint OBJECT_INVALID = 0x7F000000;

        public static Object OBJECT_SELF { get { return Internal.OBJECT_SELF; } }

        public uint Self = OBJECT_INVALID;

        public static implicit operator Object(uint objId)
        {
            return new Object { Self = objId };
        }

        public static bool operator ==(Object lhs, Object rhs)
        {
            bool lhsNull = object.ReferenceEquals(lhs, null);
            bool rhsNull = object.ReferenceEquals(rhs, null);
            return (lhsNull && rhsNull) || (!lhsNull && !rhsNull && lhs.Self == rhs.Self);
        }

        public static bool operator !=(Object lhs, Object rhs)
        {
            return !(lhs == rhs);
        }

        public override bool Equals(object o)
        {
            Object other = o as Object;
            return other != null && other == this;
        }

        public override int GetHashCode()
        {
            return (int)Self;
        }
    }

    public partial class Effect
    {
        public IntPtr Handle;
        public Effect(IntPtr handle) { Handle = handle; }
        ~Effect() { Internal.NativeFunctions.FreeEffect(Handle); }
    }

    public partial class Event
    {
        public IntPtr Handle;
        public Event(IntPtr handle) { Handle = handle; }
        ~Event() { Internal.NativeFunctions.FreeEvent(Handle); }
    }

    public partial class Location
    {
        public IntPtr Handle;
        public Location(IntPtr handle) { Handle = handle; }
        ~Location() { Internal.NativeFunctions.FreeLocation(Handle); }
    }

    public partial class Talent
    {
        public IntPtr Handle;
        public Talent(IntPtr handle) { Handle = handle; }
        ~Talent() { Internal.NativeFunctions.FreeTalent(Handle); }
    }

    public partial class ItemProperty
    {
        public IntPtr Handle;
        public ItemProperty(IntPtr handle) { Handle = handle; }
        ~ItemProperty() { Internal.NativeFunctions.FreeItemProperty(Handle); }
    }

    public delegate void ActionDelegate();


}
