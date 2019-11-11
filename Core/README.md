@page nwnx Core Functionality
@ingroup nwnx

The core of NWNX:EE that does all the things.

## Environment Variables

| Variable Name | Value | Default | Notes |
| ------------- | :---: | ------- | ----- |
| `NWNX_CORE_SKIP` | 0-1 | 0 | Set whether to load NWNX or not.
| `NWNX_CORE_LOAD_PATH` | string | Unset | The directory from where plugins are loaded. Defaults to where NWNX_Core is located.
| `NWNX_CORE_SKIP_ALL` | 0-1 | 0 | Changes the default plugin load state from 'load all' to 'skip all'. Use `NWNX_{PLUGIN}_SKIP=n` to enable specific plugins in this case.
| `NWNX_CORE_LOG_LEVEL` | 0-7 | 0| Sets the default log level. `6` is a good level for live servers. `7`  includes debug messages which can be helpful if you're having issues.
| `NWNX_CORE_LOAD_EXPERIMENTAL_PLUGIN` | 0-1 | 0 | Allows loading of NWNX_Experimental, use at your own risk.
| `NWNX_CORE_LOCALE` | ru | Unset | Set the locale NWNX will use when encoding. Currently only supports Russian/Cyrillic (`ru`)
| `NWNX_CORE_CRASH_ON_ASSERT_FAILURE` | 0-1 | 0 | Sets whether an ASSERT failure hard crashes the server.
| `NWNX_CORE_SHUTDOWN_SCRIPT` | string | Unset | Sets which NWScript to run when the module shuts down.
| `NWNX_CORE_ALLOW_NWNX_FUNCTIONS_IN_EXECUTE_SCRIPT_CHUNK` | 0-1 | 0 | When enabled, allows the ExecuteScriptChunk() function to call NWScript NWNX functions.
| `NWNX_CORE_CLEAN_UP_NWNX_RESOURCE_DIRECTORY` | 0-1 | 0 | When enabled, the UserDirectory/nwnx folder will be cleaned on startup, meaning all contents will be deleted.
| `NWNX_CORE_NWNX_RESOURCE_DIRECTORY_PRIORITY` | int | 70000000 | Sets the resman priority of the UserDirectory/nwnx folder.
| `NWNX_CORE_LOG_TIMESTAMP` | 0-1 | 1 | Set whether to show timestamp in logs printed by NWNX.
| `NWNX_CORE_LOG_PLUGIN` | 0-1 | 1 | Set whether to show plugin name in logs printed by NWNX.
| `NWNX_CORE_LOG_SOURCE` | 0-1 | 1 | Set whether to show source code location in logs printed by NWNX.
| `NWNX_CORE_LOG_COLOR` | 0-1 | 1 | Set whether to show logs printed by NWNX in color (only when printing to a TTY).
| `NWNX_CORE_LOG_FORCE_COLOR` | 0-1| 0 | Sets whether to force color output.

## Console Commands

| Command | Description |
| ------- | ----------- |
| `runscript <script name>` | Executes the given nwscript. Example: `runscript dm_killallplayers`
| `eval <script chunk>` | Executes the given nwscript chunk. Example: `eval ApplyEffectToObject(DURATION_TYPE_INSTANT, EffectDeath(), GetFirstPC());`
| `evalx <script chunk>` | Executes the given nwscript chunk, this command already includes all nwnx headers available in the module. Example: `evalx NWNX_Administration_ShutdownServer();`
| `loglevel <plugin> [<loglevel>]` | Sets the log level of the given plugin. Example: `loglevel Events 7`
| `logformat [timestamp\|notimestamp] [plugin\|noplugin] [source\|nosource] [color\|nocolor] [force\|noforce]` | Control the output format of logs. Example: `logformat color timestamp noplugin nosource`

## Plugin Management

### Environment Variable Configuration

Configuration of NWNX plugins are controlled by environment variables exported prior to starting the ``nwserver`` binary.  Typical usage would 
be in the script used to start the server.

Basic control of the plugin includes enabling/disabling the plugin and setting the logging level of the plugin.  The following format is used for
all plugins:

* NWNX_\<x>_LOG_LEVEL
* NWNX_\<x>_SKIP

### Plugin Loading

Inclusion or exclusion of the plugin at server startup time is contolled by the environment variable ``NWNX_<x>_SKIP`` where \<x> is the plugin name (all caps).

* Setting this to ``N`` will load the plugin (i.e. it will not be skipped) at startup (_default_).
* Setting this to ``Y`` will cause the plugin to _BE SKIPPED_ at startup.

__Example__
```bash
# Load the sql plugin at startup
export NWNX_SQL_SKIP=N
```

### Plugin Log Level

The default plugin log level is the same as the overall Core logging level.

It can be changed, however, by assinging a value to ``NWNX_<x>_LOG_LEVEL`` (where \<x> is the plugin name in all caps) in the same manner as the Core logging level.
See the Core documentation for a description of available logging levels.

__Example__
```bash
# Set the sql plugin to warning and above (warning, error, and fatal only)
export NWNX_SQL_LOG_LEVEL=4
```
## Core Functions For Plugin Developers
The core functions in nwnx.nss should be called by NWNX plugin developers, who should expose their own, more friendly headers.

#### Sample
This following function would wrap a call which passes three parameters, receives three back, and constructs a vector from the result.
```c
    vector GetVectorFromCoords(float x, float y, float z)
    {
        string pluginName = "NWNX_TestPlugin";
        string funcName = "GiveMeBackTheSameValues";

        // Note the inverse argument push order.
        // C++-side, arguments will be consumed from right to left.
        NWNX_PushArgumentFloat(pluginName, funcName, z);
        NWNX_PushArgumentFloat(pluginName, funcName, y);
        NWNX_PushArgumentFloat(pluginName, funcName, x);

        // This calls the function, which will prepare the return values.
        NWNX_CallFunction(pluginName, funcName);

        // C++-side pushes the return values in reverse order so we can consume them naturally here.
        float _x = NWNX_GetReturnValueFloat(pluginName, funcName);
        float _y = NWNX_GetReturnValueFloat(pluginName, funcName);
        float _z = NWNX_GetReturnValueFloat(pluginName, funcName);

        return vector(_x, _y, _z);
    }
```
