using System;
using System.Runtime.InteropServices;
using System.Text;

namespace NWN.Native.API
{
  public sealed class NativeStringMarshaler : ICustomMarshaler
  {
    private static readonly Encoding NativeEncoding;
    private static NativeStringMarshaler instance;

    static NativeStringMarshaler()
    {
      Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
      NativeEncoding = Encoding.GetEncoding("windows-1252");
    }

    public IntPtr MarshalManagedToNative(object managedObj)
    {
      if (managedObj == null)
      {
        return IntPtr.Zero;
      }

      if (managedObj is not string data)
      {
        throw new MarshalDirectiveException($"{nameof(NativeStringMarshaler)} must be used on a string.");
      }

      byte[] bytes = NativeEncoding.GetBytes(data);
      IntPtr buffer = Marshal.AllocHGlobal(bytes.Length + 1);
      Marshal.Copy(bytes, 0, buffer, bytes.Length);

      // Write null terminator
      Marshal.WriteByte(buffer + bytes.Length, 0);
      return buffer;
    }

    public unsafe object MarshalNativeToManaged(IntPtr pNativeData)
    {
      byte* walk = (byte*)pNativeData;

      // Find the end of the string
      while (*walk != 0)
      {
        walk++;
      }

      int length = (int)(walk - (byte*)pNativeData);

      // Skip the trailing null
      byte[] buffer = new byte[length];
      Marshal.Copy(pNativeData, buffer, 0, length);

      string data = NativeEncoding.GetString(buffer);
      return data;
    }

    public void CleanUpNativeData(IntPtr pNativeData)
    {
      Marshal.FreeHGlobal(pNativeData);
    }

    public void CleanUpManagedData(object managedObj) {}

    public int GetNativeDataSize()
    {
      return -1;
    }

    public static ICustomMarshaler GetInstance(string pstrCookie)
    {
      if (instance == null)
      {
        return instance = new NativeStringMarshaler();
      }

      return instance;
    }
  }
}
