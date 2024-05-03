using System;
using System.Numerics;
using System.Runtime.InteropServices;

namespace NWN
{
  public static class NWNXPInvoke
  {
    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void CallBuiltIn(int id);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void RegisterHandlers(IntPtr handlers, uint size);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushInteger(int value);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushFloat(float value);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushString(string value);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushObject(uint value);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushVector(Vector3 value);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushGameDefinedStructure(int type, IntPtr str);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern int StackPopInteger();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern float StackPopFloat();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern string StackPopString();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern uint StackPopObject();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern Vector3 StackPopVector();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr StackPopGameDefinedStructure(int type);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr FreeGameDefinedStructure(int type, IntPtr str);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern int ClosureAssignCommand(uint oid, ulong eventId);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern int ClosureDelayCommand(uint oid, float duration, ulong eventId);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern int ClosureActionDoCommand(uint oid, ulong eventId);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXSetFunction(string plugin, string function);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushInt(int n);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushFloat(float f);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushObject(uint o);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushString(string s);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushEffect(IntPtr e);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushItemProperty(IntPtr ip);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern int NWNXPopInt();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern float NWNXPopFloat();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern uint NWNXPopObject();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern string NWNXPopString();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr NWNXPopEffect();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr NWNXPopItemProperty();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXCallFunction();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr RequestHook(IntPtr address, IntPtr managedFuncPtr, int priority);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void ReturnHook(IntPtr hook);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void StackPushRawString(IntPtr charPtr);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr StackPopRawString();

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern void NWNXPushRawString(IntPtr charPtr);

    [DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
    public static extern IntPtr NWNXPopRawString();
  }
}
