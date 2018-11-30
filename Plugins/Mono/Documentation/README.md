# Mono Plugin Reference

## Description

Allow users to see sharp. More specifically, this plugin enables developers to write scripts in C# using the Mono framework.

## How to see sharp?

- Follow these instructions to add the Mono repository to your apt sources: https://www.mono-project.com/download/stable/#download-lin-debian
- Make sure the version at the top of the above page is 5.16.0 Stable (5.16.0.220). If it isn't, install libmono-2.0-dev:i386, then find libmono-2.0.a and copy it to the Plugins/Mono/lib folder.
- Make sure you have the mono-complete package installed. The version of the package MUST match the version of the 32-bit shared library from the step above. If it doesn't, you may encounter run-time failures.

- Make sure you have a binary compiled that exports one or more scripts.

- To export a script, follow this structure, where the class name is the name of the .nss script you want to replace. If I had m_hb set to the module heartbeat script, with the following code, when the m_hb would be called in nwscript, it is instead called in C#:

```
namespace NWN.Scripts
{
    class m_hb
    {
        static void Main()
        {
            Console.WriteLine("I wrote this line from Mono!");
        }
    }
}
```

-- This also works for StartingConditionals. Just give your main function a return value as such, and return NWScript.TR
UE or NWScript.FALSE.

```
static int Main()
{
    return NWScript.GetLevelByClass(NWScript.CLASS_TYPE_CLERIC, NWScript.GetPCSpeaker()) != 0 ? NWScript.TRUE : NWScript.FALSE;
}
```

- If you want to use the nwscript API, make sure to compile the various INTERNAL_*.cs files in the CSharpAPI folder. Here are some examples of using the API:

```
NWScript.SendMessageToPC(NWScript.GetFirstPC(), "Rawr! It is me! Mario");
NWScript.DelayCommand(1.0f, () => NWScript.SendMessageToPC(NWScript.GetFirstPC(), "Hello! This is a delayed command."));
NWScript.AssignCommand(NWScript.GetFirstPC(), () => NWScript.ActionDoCommand(
            () => NWScript.ActionSpeakString("Hello! I am speaking this string!")));
```

- To compile your scripts, invoke csc as such:

```
    csc -platform:x86 -t:library -out:[yourbinarypathgoeshere.so] INTERNAL_Internal.cs [other INTERNAL_*.cs scripts go here ...] [your scripts go here ...]
```

- If something goes wrong, try setting the log level to 7. There is extensive (and slow, so don't always leave it on) debug logging available.

## Remote Debugging

It is possible to remotely debug running code on your server through Visual Studio 2017.

- Install VSMonoDebugger extension. (https://marketplace.visualstudio.com/items?itemName=GordianDotNet.VSMonoDebugger0d62)
- Setup the VSMonoDebugger options within VS2017 (Mono -> Settings...) such that it has the correct Remote Host IP. Change the Mono Debug Port to 10000. The rest of the options do not matter.
- Build your solution.
- Generate MDB files from PDB files. (Mono -> Build Startup Project with MDB Files)
- Run NWNX with ALLOW_REMOTE_DEBUGGING set to true.
- Attach. (Mono -> Attach to mono debugger).
- If your breakpoints are not hit, the MDB and PDB files may be out of sync. On your server, invoke `pdb2mdb dll_name` to generate an up to date MDB.

## Limitations

There is no support for hotloading yet.

## Environment Variables

```
ASSEMBLY [mandatory]: The path to the compiled binary containing your C# code. Mandatory.
SCRIPT_METRICS [optional]: Whether metrics are exported for script execution timings.
CLOSURE_METRICS [optional]: Whether metrics are exported for closure timings.
MAIN_LOOP_METRICS [optional]: Whether metrics are exported for main loop tick timings.
CONFIG_PATH [optional]: The path to the Mono config file. Advanced users only.
BASE_DIRECTORY [optional]: The path to the directory where your code lives. This is necessary if you need to access App.config files. Used in conjunction with the APP_CONFIG environment variable. Both must be set to use App.config files.
APP_CONFIG [optional]: The path to the App.config file used for your project. Used in conjunction with the BASE_DIRECTORY environment variable. Both must be set to use App.config files.
ALLOW_REMOTE_DEBUGGING [optional]: If specified to true, will block until a remote debugger has been attached.

```
