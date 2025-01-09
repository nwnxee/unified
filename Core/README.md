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
| `NWNX_CORE_LOCALE` | string | Unset | Set the locale NWNX will use when encoding. Supported are cp1250, cp1251, cp1252 (default). Can also use two letter country codes (e.g. `"ru"`)
| `NWNX_CORE_CRASH_ON_ASSERT_FAILURE` | 0-1 | 0 | Sets whether an ASSERT failure hard crashes the server.
| `NWNX_CORE_SHUTDOWN_SCRIPT` | string | Unset | Sets which NWScript to run when the module shuts down.
| `NWNX_CORE_ALLOW_NWNX_FUNCTIONS_IN_EXECUTE_SCRIPT_CHUNK` | 0-1 | 0 | When enabled, allows the ExecuteScriptChunk() function to call NWScript NWNX functions.
| `NWNX_CORE_NWNX_RESOURCE_DIRECTORY_PATH` | string | UserDirectory/nwnx | The path of the /nwnx resource directory
| `NWNX_CORE_CUSTOM_RESMAN_DEFINITION` | string | Unset | A path to a file with custom resource directory aliases, see below for more info
| `NWNX_CORE_NWNX_RESOURCE_DIRECTORY_PRIORITY` | int | 70000000 | Sets the resman priority of the UserDirectory/nwnx folder.
| `NWNX_CORE_LOG_TIMESTAMP` | 0-1 | 1 | Set whether to show timestamp in logs printed by NWNX.
| `NWNX_CORE_LOG_DATE` | 0-1 | 0 | Set whether to show date(Y-M-D) in logs printed by NWNX. Timestamps must be enabled.
| `NWNX_CORE_LOG_PLUGIN` | 0-1 | 1 | Set whether to show plugin name in logs printed by NWNX.
| `NWNX_CORE_LOG_SOURCE` | 0-1 | 1 | Set whether to show source code location in logs printed by NWNX.
| `NWNX_CORE_LOG_COLOR` | 0-1 | 1 | Set whether to show logs printed by NWNX in color (only when printing to a TTY).
| `NWNX_CORE_LOG_FORCE_COLOR` | 0-1| 0 | Sets whether to force color output.
| `NWNX_CORE_LOG_FILE_PATH` | string | Unset | Sets the secondary (in addition to `stdout`) log file.
| `NWNX_CORE_HARD_EXIT` | 0-1| 0 | If set, NWNX will hard kill the process after it unloads.
| `NWNX_CORE_BASE_GAME_CRASH_HANDLER` | 0-1 | 0 | Sets whether to also call the base game handler in case of crash.

## Console Commands

| Command | Description |
| ------- | ----------- |
| `runscript <script name>` | Executes the given nwscript. Example: `runscript dm_killallplayers`
| `eval <script chunk>` | Executes the given nwscript chunk. Example: `eval ApplyEffectToObject(DURATION_TYPE_INSTANT, EffectDeath(), GetFirstPC());`
| `evalx <script chunk>` | Executes the given nwscript chunk, this command already includes all nwnx headers available in the module. Example: `evalx NWNX_Administration_ShutdownServer();`
| `loglevel <plugin> [<loglevel>]` | Sets the log level of the given plugin. `<plugin>` should not have the `NWNX_` prefix.  Example: `loglevel Events 7`
| `logformat [timestamp\|notimestamp] [plugin\|noplugin] [source\|nosource] [color\|nocolor] [force\|noforce]` | Control the output format of logs. Example: `logformat color timestamp noplugin nosource`

## Custom Resman Definition File

A file that lets you specify additional resource directories that act the same as the `/development` and `/nwnx` folders.

Each line in the file must contain the following: `ALIASNAME /full/path/to/folder <priority>`

Example:

```
TEST /home/nwnx/test 70000001
STUFF /home/nwnx/stuff 70000002
```

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
