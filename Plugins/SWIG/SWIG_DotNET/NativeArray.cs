using System;
using System.Collections;
using System.Collections.Generic;

namespace NWN.Native.API
{
  public unsafe class NativeArray<T> : IEnumerable<T>, IEquatable<NativeArray<T>> where T : unmanaged
  {
    /// <summary>
    /// Gets the length of this array.
    /// </summary>
    public int Length { get; }

    private readonly T* arrayPtr;

    public NativeArray(IntPtr arrayPtr, int length)
    {
      this.arrayPtr = (T*)arrayPtr;
      this.Length = length;
    }

    public T this[int index]
    {
      get
      {
        if (index < 0 || index >= Length)
        {
          throw new IndexOutOfRangeException("Index was out of range. Must be non-negative and less than the size of the array.");
        }

        return arrayPtr[index];
      }
      set
      {
        if (index < 0 || index >= Length)
        {
          throw new IndexOutOfRangeException("Index was out of range. Must be non-negative and less than the size of the array.");
        }

        arrayPtr[index] = value;
      }
    }

    public IEnumerator<T> GetEnumerator()
    {
      for (int i = 0; i < Length; i++)
      {
        yield return this[i];
      }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
      return GetEnumerator();
    }

    public bool Equals(NativeArray<T> other)
    {
      if (ReferenceEquals(null, other))
      {
        return false;
      }

      if (ReferenceEquals(this, other))
      {
        return true;
      }

      return arrayPtr == other.arrayPtr;
    }

    public override bool Equals(object obj)
    {
      if (ReferenceEquals(null, obj))
      {
        return false;
      }

      if (ReferenceEquals(this, obj))
      {
        return true;
      }

      if (obj.GetType() != this.GetType())
      {
        return false;
      }

      return Equals((NativeArray<T>)obj);
    }

    public override int GetHashCode()
    {
      return unchecked((int)(long)arrayPtr);
    }

    public static bool operator ==(NativeArray<T> left, NativeArray<T> right)
    {
      return Equals(left, right);
    }

    public static bool operator !=(NativeArray<T> left, NativeArray<T> right)
    {
      return !Equals(left, right);
    }

    public static implicit operator IntPtr(NativeArray<T> nativeArray)
    {
      return (IntPtr)nativeArray.arrayPtr;
    }
  }
}
