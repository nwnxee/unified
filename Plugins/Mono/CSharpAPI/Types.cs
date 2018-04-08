using System;

namespace NWN
{
    public class Object
    {
        public static NWN.Object OBJECT_SELF { get { return Internal.OBJECT_SELF; } }

        public uint m_ObjId = Internal.OBJECT_INVALID;

        public static implicit operator Object(uint objId)
        {
            return new Object { m_ObjId = objId };
        }

        public static bool operator==(Object lhs, Object rhs)
        {
            bool lhsNull = object.ReferenceEquals(lhs, null);
            bool rhsNull = object.ReferenceEquals(rhs, null);
            return (lhsNull && rhsNull) || (!lhsNull && !rhsNull && lhs.m_ObjId == rhs.m_ObjId);
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
            return (int)m_ObjId;
        }
    }

    public struct Vector
    {
        public float m_X;
        public float m_Y;
        public float m_Z;

        public Vector(float x, float y, float z)
        {
            m_X = x;
            m_Y = y;
            m_Z = z;
        }
    }

    public struct Effect
    {
        public IntPtr m_Handle;
    }

    public struct Event
    {
        public IntPtr m_Handle;
    }

    public struct Location
    {
        public IntPtr m_Handle;
    }

    public struct Talent
    {
        public IntPtr m_Handle;
    }

    public struct ItemProperty
    {
        public IntPtr m_Handle;
    }

    public class Action
    { }
}
