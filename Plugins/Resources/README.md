@page resources Readme
@ingroup resources 

This plugin implements additional resource sources and customization.

## Resource Providers

| Variable Name                         |     Value     | Default | Notes                                                                                                                                                                 |
|---------------------------------------|:-------------:|:-------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `NWNX_RESOURCES_USE_NWSYNC`           | true or false |  false  | Causes the server to synchronise to a standard nwsync repository, and load the referenced content.                                                                    |
| `NWNX_RESOURCES_USE_CUSTOM_HAK_LIST`  | true or false |  false  | Clears or replaces the hak list defined in module properties with a custom list.                                                                                      |
| `NWNX_RESOURCES_THREADWATCHDOG_GRACE` |      int      |    2    | Sets the timeout grace period for the thread watchdog. Only increase this if you are experiencing issues with the server exiting too quickly during resource loading. |

## NWSync

The following environment variables are required if `NWNX_RESOURCES_USE_NWSYNC` is set to `true`.

| Variable Name                    | Value  | Default | Notes                                                |
|----------------------------------|:------:|:-------:|------------------------------------------------------|
| `NWNX_RESOURCES_NWSYNC_HOST`     | string |  none   | The root URL containing the NWSync repository.       |
| `NWNX_RESOURCES_NWSYNC_MANIFEST` | string |  none   | The manifest hash to load. Does not support "latest" |

## Custom HAK List

The following environment variables are configurable if `NWNX_RESOURCES_USE_CUSTOM_HAK_LIST` is set to `true`.

| Variable Name                    | Value  | Default | Notes                                                                                                                                                                         |
|----------------------------------|:------:|:-------:|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `NWNX_RESOURCES_CUSTOM_HAK_LIST` | string |  none   | A comma (,) separated list of hak files to load. Replaces the list defined in the module properties.<br/>If left empty, this will cause the module to not load any hak files. |
