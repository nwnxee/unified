@addtogroup dotnet DotNET
@page dotnet Readme
@ingroup dotnet 

Implement your server scripts in C# (and other dotnet languages)

## Environment Variables

| Variable Name |  Type  | Description                                                                             | Default Value |
|---------------| :----: |-----------------------------------------------------------------------------------------|---------------|
| ASSEMBLY      | string | Full path to your assembly/dll (without extension)                                      | _none_        |
| ENTRYPOINT    | string | Full type name containing static entrypoint method.                                     | NWN.Internal  |
| METHOD        | string | Name of entrypoint method to call. Method must be `static void` without any parameters. | Bootstrap     |
| NETHOST_PATH  | string | Path where to load libnethost.so from                                                   | _none_        |

## Basic Setup

### Dependencies

You will need `dotnet-sdk` installed on the server to use this plugin. The same package is used to build the managed code.  Installation instructions are [here](https://dotnet.microsoft.com/download/linux-package-manager/sdk-current).

There are no compiletime dependencies for the unmanaged code.

### Compile managed code

Copy everything within [DotNET/NWN/...](NWN) into a folder that will be your module's root. Then, in that folder run `dotnet build`. This will produce several files, most notably:

 - `NWN.dll` - your compiled code
 - `NWN.runtimeconfig.json` - config file that tells nwnx how to run your code

### Run NWNX with your DLL

In your startup script, you need to minimally set up the assembly path (note: without .dll extension):

    export NWNX_DOTNET_ASSEMBLY=/full/path/to/your/compiled/NWN

And then start NWNX+NWServer.

### Troubleshooting

#### libnethost.so

If you get the following error:

    Unable to load libnethost.so. .NET plugin will be unavailable.

make sure you have `dotnet-sdk-3.1` (or later?) installed on your system. If it is present, run `locate libnethost.so` to find the location of the library. Then add it to:

    export NWNX_DOTNET_NETHOST_PATH=/full/path/to/libnethost.so

Please also open an issue showing the output of your `locate` command so that we can add the path to the auto-search code.

#### runtime config

If you get the following error:

    Unable to load runtime config [...]

verify your `NWNX_DOTNET_ASSEMBLY` variable - it needs to contain the path to your DLL, with the base name, but without the extension. So, if you have:

    /some/path/my/project/NWN.dll
    /some/path/my/project/NWN.runtimeconfig.json
    /some/path/my/project/NWN.deps.json
    /some/path/my/project/NWN.pdb

your `NWNX_DOTNET_ASSEMBLY` should be `/some/path/my/project/NWN`

#### Bootstrap Method

If you get the following error:

    Unable to get [something].[something]() function [...]

and you have changed the default entrypoint, verify that your `NWNX_DOTNET_ENTRYPOINT` contains the full `Namespace.Class.Subclass`,  and that `NWNX_DOTNET_METHOD` is declared as a `static void` method with no arguments.

E.g. `NWNX_DOTNET_METHOD=Bootstrap` -> `public static void Bootstrap()`

## How it works (basic)

In [Entrypoints.cs](NWN/Entrypoints.cs) you have three events that you need to implement:

### `OnStart`

```cs
    public static void OnStart()
```

This event is called only once, when the dotnet runtime has been initialized. Use this event to initialize any static data you might have.

@note At this time, the NWScript VM is not yet initialized, so you cannot use any nwscript functions. Even the module object does not exist yet.


### `OnRunScript`

```cs
    public static int OnRunScript(string script, uint oidSelf);
```

This event runs whenever a named script - i.e. event scripts set in the toolset, or with `SetEventScript` - is to be executed. This runs _before_ any nwscript scripts, and runs for all scripts, including stock bioware ones.

If you do not want to handle this script, and let the regular nwscript do it (e.g. for `nw_`,`x0_` and `x2_` scripts), you should just return `-1` or `SCRIPT_NOT_HANDLED`. Otherwise, it's up to you to dispatch however you want, and return `>=0`. The return value is used in case of `StartingConditional` scripts.

`oidSelf` is the handle of the object running the script. You can also access this object with `NWScript.OBJECT_SELF`.

@note A large switch (or if/else/if) statement to account for all scripts will get real unwieldy real fast, so you should set up some way to dispatch to the correct function based on a script. Some options are:

 - Use a `Dictionary<string, RunScriptHandlerDelegate>` to register functions that handle scripts
 - Use reflection to find functions with the same name as the script (precompute or cache results)
 - Use attributes on methods that are script handlers

### `OnMainLoop`

```cs
    public static void OnMainLoop(ulong frame);
```

This is called every main loop frame (approximately/ideally every 10ms). It runs in script context (so NWScript functions are available), but `OBJECT_SELF == OBJECT_INVALID`.

You should keep the processing in this function to a minimum, as it may have adverse effect on server performance.

### Using NWScript in C#

All classic NWScript functions are available in the [`NWN.NWScript`](NWN/NWScript/Functions.cs) class.

For example:

```cs
public static int OnRunScript(string script, uint oidSelf)
{
    var tag = NWScript.GetTag(NWScript.OBJECT_SELF);
    Console.WriteLine($"Running script '{script}' on object tag '{tag}'");
    NWScript.SendMessageToPC(NWScript.GetFirstPC(), "Hello!");

    // Note that DelayCommand/AssignCommand/ActionDoCommand have slightly different syntax:
    NWScript.DelayCommand(1.0f, () => NWScript.SendMessageToPC(NWScript.GetFirstPC(), "Hello! This is a delayed command."));
    NWScript.AssignCommand(NWScript.GetFirstPC(),
        () => NWScript.ActionDoCommand(() => NWScript.ActionSpeakString("Hello! I am speaking this string!")));
}
```

## Advanced stuff

All the managed code provided in this repo is meant just as a primer, You are encouraged to copy it and adapt to your own needs.

### NWN types

When talking to unmanaged code, we only deal with basic types. Objects are passed as `uint`s. Other engine structures, like `Effect`,`Location`, etc, all have `IntPtr Handle` which is passed instead.

Engine structures like `Effect`/`Location` have a backing unmanaged structure, and need to be cleaned up after usage.
It is recommended to have a wrapper like this to allow the native C# garbage collector to handle it for you:

```cs
  public partial class Effect
  {
    public IntPtr Handle;
    public Effect(IntPtr handle) => Handle = handle;
    ~Effect() { NWNXPInvoke.FreeGameDefinedStructure(NWScript.ENGINE_STRUCTURE_EFFECT, Handle); }

    public static implicit operator IntPtr(Effect effect) => effect.Handle;
    public static implicit operator Effect(IntPtr intPtr) => new Effect(intPtr);
  }
```

### Bootstrapping

The basic interop between unmanaged NWNX and managed module code is entirely contained within [Bootstrap.cs](NWN/Internal/Bootstrap.cs). Your managed DLL needs to have this function:

```cs
    public static void Bootstrap();
```

exposed. By default, NWNX will look for the `Bootstrap()` function in `NWN.Internal`, but you can override that through the `NWNX_DOTNET_ENTRYPOINT` and `NWNX_DOTNET_METHOD` environment variables.

In your bootstrap code, you will need to register a set of method handlers that will be called by NWNX/NWN to execute your C# code.

For this, we use the `RegisterHandler` methods exposed by NWNX_DotNET. This can be called through Platform Invoke (PInvoke).

At minimum, it is recommended to register the main loop, run script, closure and signal handlers:

```cs
// Handler functions exposed from NWNX_DotNET
[DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
public static extern void RegisterMainLoopHandler(delegate* unmanaged<ulong, void> handler);

[DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
public static extern void RegisterRunScriptHandler(delegate* unmanaged<byte*, uint, int> handler);

[DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
public static extern void RegisterClosureHandler(delegate* unmanaged<ulong, uint, void> handler);

[DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
public static extern void RegisterSignalHandler(delegate* unmanaged<byte*, void> handler);

//...in Bootstrap()...
public static void Bootstrap()
{
  NWNXPInvoke.RegisterMainLoopHandler(&OnMainLoop);
  NWNXPInvoke.RegisterRunScriptHandler(&OnRunScript);
  NWNXPInvoke.RegisterClosureHandler(&OnClosure);
  NWNXPInvoke.RegisterSignalHandler(&OnSignal);
}

// Your handler functions
[UnmanagedCallersOnly] // Indicates that this method will only be called by native code/NWNX.
public static void OnMainLoop(ulong frame)
{
  try
  {
    Entrypoints.OnMainLoop(frame);
  }
  catch (Exception e)
  {
    Console.WriteLine(e.ToString());
  }
}
```

### Using native NWNX_DotNET functions

This plugin exposes various functions and utilities that can be used through platform invoke.

Functions in [DotNETExports.cpp](DotNETExports.cpp) declared with `NWNX_EXPORT` can be accessed by declaring an extern function in C#, with an appropriate `DllImport` attribute.

Example:
```
// C++
NWNX_EXPORT void ReturnHook(void* trampoline)

// C#
[DllImport("NWNX_DotNET", CallingConvention = CallingConvention.Cdecl)]
public static extern void ReturnHook(IntPtr hook);
```

### OBJECT_SELF

The `OBJECT_SELF` global is handled in the managed code. In the `OnRunScript` handler, the argument `oidSelf` is assigned to the global. Before the handler finishes, the old value is restored.

You can find implementation details in [Internal.cs](NWN/Internal/Internal.cs), where a `Stack<>` is used to keep track of nested script calls.

### Closures

A closure is a script context that is saved to be executed at a later time - `DelayCommand`, `AssignCommand`, etc. The closure support in dotnet is almost entirely handled on the managed side. The three native functions you'd use to schedule a closure are:

```cs
public int ClosureAssignCommand(uint oid, ulong eventId);
public int ClosureDelayCommand(uint oid, float duration, ulong eventId);
public int ClosureActionDoCommand(uint oid, ulong eventId);

```
The `oid` is the ID of the object that will run the closure (usually `OBJECT_SELF` for `DelayCommand`). The `eventId` is any `ulong` tag given to this closure that will then be handed back.
The native code will then just schedule `{oid, eventId}` pair to execute at the given time. When it executes, it will call back into the closure handler that was registered with `RegisterClosureHandler`

The sample call implements closures in [Internal.cs](NWN/Internal/Internal.cs), as:

```cs
public delegate void ActionDelegate();
private struct Closure
{
    public uint OwnerObject;
    public ActionDelegate Run;
}
// Unique ID given to each event
private static ulong NextEventId = 0;
// Map of active closures: eventId->Closure
private static Dictionary<ulong, Closure> Closures = new Dictionary<ulong, Closure>();

// Scheduling a closure:
public static void ClosureDelayCommand(uint obj, float duration, ActionDelegate func)
{
    if (NWNXPInvoke.ClosureDelayCommand(obj, duration, NextEventId) != 0)
    {
        Closures.Add(NextEventId++, new Closure { OwnerObject = obj, Run = func });
    }
}
```

### Exceptions

Exceptions work within the managed code, however they do not cross the managed/unmanaged boundary. This means that uncaught exceptions will bring down the entire nwserver process. It is advisable to wrap most of your logic in `try...catch` blocks in all three entry points (See [Internal.cs](NWN/Internal/Internal.cs) for examples).

Errors which happen while executing unmanaged code invoked through one of the bootstrap delegates will also bring down the server (e.g. by passing invalid `IntPtr Handle` for engine structures)
