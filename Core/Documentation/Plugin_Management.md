# Plugin Management

## Environment Variable Configuration

Configuration of NWNX plugins are controlled by environment variables exported prior to starting the ``nwserver`` binary.  Typical usage would 
be in the script used to start the server.

Basic control of the plugin includes enabling/disabling the plugin and setting the logging level of the plugin.  The following format is used for
all plugins:

* NWNX_<x>_LOG_LEVEL
* NWNX_<x>_SKIP

## Plugin Loading

Inclusion or exclusion of the plugin at server startup time is contolled by the environment variable ``NWNX_<x>_SKIP`` where <x> is the plugin name (all caps).

* Setting this to ``N`` will load the plugin (i.e. it will not be skipped) at startup (_default_).
* Setting this to ``Y`` will cause the plugin to _BE SKIPPED_ at startup.

__Example__
```
# Load the sql plugin at startup
export NWNX_SQL_SKIP=N
```

## Plugin Log Level

TBD