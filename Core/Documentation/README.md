# Core Reference

## Description

The core of NWNXEE that does all the things.

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

# Plugin Management

## Environment Variable Configuration

Configuration of NWNX plugins are controlled by environment variables exported prior to starting the ``nwserver`` binary.  Typical usage would 
be in the script used to start the server.

Basic control of the plugin includes enabling/disabling the plugin and setting the logging level of the plugin.  The following format is used for
all plugins:

* NWNX_\<x>_LOG_LEVEL
* NWNX_\<x>_SKIP

## Plugin Loading

Inclusion or exclusion of the plugin at server startup time is contolled by the environment variable ``NWNX_<x>_SKIP`` where \<x> is the plugin name (all caps).

* Setting this to ``N`` will load the plugin (i.e. it will not be skipped) at startup (_default_).
* Setting this to ``Y`` will cause the plugin to _BE SKIPPED_ at startup.

__Example__
```
# Load the sql plugin at startup
export NWNX_SQL_SKIP=N
```

## Plugin Log Level

The default plugin log level is the same as the overall Core logging level.

It can be changed, however, by assinging a value to ``NWNX_<x>_LOG_LEVEL`` (where \<x> is the plugin name in all caps) in the same manner as the Core logging level.
See the Core documentation for a description of available logging levels.

__Example__
```
# Set the sql plugin to warning and above (warning, error, and fatal only)
export NWNX_SQL_LOG_LEVEL=4
```
