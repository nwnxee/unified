@page test Readme
@ingroup test

This plugin adds some basic testing infrastructure for NWScript.  The fundamental design is Shericall's.

If the `NWNX_TEST_SOURCE_DIR` environment variable isn't set, the plugin will attempt to use the source tree that you built the plugin in.

If a source directory can be found, all NWNX nss files are copied and test scripts compiled to NWNUserDirectory/nwnx.

From there, whether a NWNX repo was found or not, test scripts are run directly from whatever is in ResMan

The following environmental variable is required to load the plugin:

`NWNX_CORE_LOAD_TEST_PLUGIN=y`

## Environment Variables
| Variable Name           | Type   | Default | Notes |
| ----------------------- | :----: | :-----: | ----- |
| `NWNX_TEST_SOURCE_DIR`  | string | ""      | Path to your nwnxee/unified source git repo.
| `NWNX_TEST_WAIT_FOR_PC` | bool   | false   | If true, the test runner will wait for the first PC to enter the module.  If false, tests are run after the module loads

## Example
```c++
#include "nwnx_test"
#include "nwnx_util"

void main()
{
    while(TEST("MyTestCase")) // The while loops are to aid in scoping, they never run more than one iteration.
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Util"))); // A good general practice to always assert the plugins your test script depends on.
        EXPECT(IS_EQUAL_INT(2+2, 4), "Mathematical Reassurances");

        while(TEST("MySubTestCaseForPCs"))
        {
            object pc = GetFirstPC();
            ASSERT(IS_VALID(pc), "GetFirstPC()");
            // If there is no valid PC in game, the following test will be considered skipped.
            EXPECT(IS_EQUAL_STRING(GetSkyColor(), "blue"));
        }
    }
}
```

## Notes
* Some test script require the existance of a PC and must be run in game with at least one PC.
* In light of the above, test case failure isn't necessarily an indication that a feature isn't working.  Some notes have been added in a few test scripts to explain other such issues.
* This is not a general purpose NWScript testing framework, NWNX:EE is required to use it.
* Due to the limitations of NWScript 'skipped' tests are still run, their failure simply isn't reported.  So be mindful of side effects in tests.
* It's probably best not to use this in a production environment.
