# Mono Plugin Reference

## Description

Allow users to see sharp. More specifically, this plugin enables developers to write scripts in C# using the Mono framework.

## How to see sharp?

- Make sure you have the mono-complete package installed.
- Make sure you have a binary compiled that exports one or more scripts.

- To export a script, follow this structure, where the class name is the name of the .nss script you want to replace. If I had m_hb set to the module heartbeat script, with the following code, when the m_hb would be called in nwscript, it is instead called in C#:

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

- This also works for StartingConditionals. Just give your main function a return value as such, and return NWScript.TRUE or NWScript.FALSE.

    static int Main()
    {
        return NWScript.GetLevelByClass(NWScript.CLASS_TYPE_CLERIC, NWScript.GetPCSpeaker()) != 0 ? NWScript.TRUE : NWScript.FALSE;
    }

- If you want to use the nwscript API, make sure to compile the various INTERNAL_*.cs files in the CSharpAPI folder. Here are some examples of using the API:

    NWScript.SendMessageToPC(NWScript.GetFirstPC(), "Rawr! It is me! Mario");
    NWScript.DelayCommand(1.0f, () => NWScript.SendMessageToPC(NWScript.GetFirstPC(), "Hello! This is a delayed command."));
    NWScript.AssignCommand(NWScript.GetFirstPC(), () => NWScript.ActionDoCommand(
                () => NWScript.ActionSpeakString("Hello! I am speaking this string!")));

- To compile your scripts, invoke csc as such:

    csc -platform:x86 -t:library -out:test.dll INTERNAL_Events.cs INTERNAL_Internal.cs INTERNAL_nwscript.cs INTERNAL_nwscript.intrinsics.cs INTERNAL_Types.cs [the rest of your scripts go here ...]

- If something goes wrong, try setting the log level to 7. There is expensive debug logging available.

## Limitations

There is no support for hotloading yet.

## Environment Variables

ASSEMBLY [mandatory]: The path to the compiled binary containing your C# code. Mandatory.
SCRIPT_METRICS [optional]: Whether metrics are exported for script execution timings.
CLOSURE_METRICS [optional]: Whether metrics are exported for closure timings.
MAIN_LOOP_METRICS [optional]: Whether metrics are exported for main loop tick timings.
CONFIG_PATH [optional]: The path to the Mono config file. Advanced users only.
