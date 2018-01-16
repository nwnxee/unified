# SQL Plugin Basic Guide

## Environment Variable Configuration

Configuration of NWNX plugins are controlled by environment variables exported prior to starting the ``nwserver`` binary.  Typical usage would be in the script used to start the server

## Plugin Loading

Inclusion or exclusion of the plugin at server startup time is contolled by the environment variable ``NWNX_SQL_SKIP``.

Setting this to ``Y`` will cause the plugin to _BE SKIPPED_ at startup.
Setting this to ``N`` will load the plugin for use.

__Example__
```
# Load the sql plugin at startup
export NWNX_SQL_SKIP=N
```

### NWNX_SQL_TYPE

Controls the target database type used at runtime.  

Possible values:

*  ``MYSQL`` 
* ``POSTGRESQL``

__Example__

```
export NWNX_SQL_TYPE=POSTGRESQL
```

### NWNX_SQL_HOST

Host name where the database resides.  Typically ``localhost`` but can be any valid host name or IP address.

__Example__

```
export NWNX_SQL_HOSTNAME=localhost
```

### NWNX_SQL_USERNAME

Database username used for the connection.

__Example__

```
export NWNX_SQL_USERNAME=nwn_db
```

### NWNX_SQL_PASSWORD

Password for the database connection.

__Example__

```
export NWNX_SQL_PASSWORD=lathander_rulez
```
