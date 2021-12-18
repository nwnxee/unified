using System;
using System.Collections;
using System.Collections.Generic;

namespace NWN.Native.API
{
  public unsafe class TwoDimNativeArray<T> : IReadOnlyList<NativeArray<T>>, IEquatable<TwoDimNativeArray<T>> where T : unmanaged
  {
    /// <summary>
    /// Gets the pointer to this array.
    /// </summary>
    public T* Pointer { get; }

    /// <summary>
    /// Gets the length of this array.
    /// </summary>
    public int Length { get; }

    /// <summary>
    /// Gets the length of the second dimension of this array.
    /// </summary>
    public int LengthDim2 { get; }

    int IReadOnlyCollection<NativeArray<T>>.Count => Length;

    public TwoDimNativeArray(IntPtr pointer, int lengthDim1, int lengthDim2)
    {
      this.Pointer = (T*)pointer;
      this.Length = lengthDim1;
      this.LengthDim2 = lengthDim2;
    }

    public TwoDimNativeArray(T* pointer, int lengthDim1, int lengthDim2)
    {
      this.Pointer = pointer;
      this.Length = lengthDim1;
      this.LengthDim2 = lengthDim2;
    }

    public NativeArray<T> this[int index]
    {
      get
      {
        if (index < 0 || index >= Length)
        {
          throw new IndexOutOfRangeException("Index was out of range. Must be non-negative and less than the size of the array.");
        }

        return new NativeArray<T>(Pointer + index * sizeof(T) * LengthDim2, LengthDim2);
      }
    }

    public IEnumerator<NativeArray<T>> GetEnumerator()
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

    public bool Equals(TwoDimNativeArray<T> other)
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

    public static bool operator ==(TwoDimNativeArray<T> left, TwoDimNativeArray<T> right)
    {
      return Equals(left, right);
    }

    public static bool operator !=(TwoDimNativeArray<T> left, TwoDimNativeArray<T> right)
    {
      return !Equals(left, right);
    }

    public static implicit operator IntPtr(TwoDimNativeArray<T> nativeArray)
    {
      return (IntPtr)nativeArray.Pointer;
    }
  }
}
