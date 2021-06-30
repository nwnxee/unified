using System;
using System.Collections;
using System.Collections.Generic;

namespace NWN.Native.API
{
  public unsafe class NativeArray<T> : IReadOnlyList<T>, IEquatable<NativeArray<T>> where T : unmanaged
  {
    /// <summary>
    /// Gets the pointer to this array.
    /// </summary>
    public T* Pointer { get; }

    /// <summary>
    /// Gets the length of this array.
    /// </summary>
    public int Length { get; }

    int IReadOnlyCollection<T>.Count => Length;

    public NativeArray(IntPtr pointer, int length)
    {
      this.Pointer = (T*)pointer;
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

        return Pointer[index];
      }
      set
      {
        if (index < 0 || index >= Length)
        {
          throw new IndexOutOfRangeException("Index was out of range. Must be non-negative and less than the size of the array.");
        }

        Pointer[index] = value;
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

      return Pointer == other.Pointer;
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
      return unchecked((int)(long)Pointer);
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
      return (IntPtr)nativeArray.Pointer;
    }
  }
}
