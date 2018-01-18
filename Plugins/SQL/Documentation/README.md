# SQL Plugin Reference

## Description

General data access, storage and manipulation of persistent data in a database.

## Environment Variables

### NWNX_SQL_TYPE

Controls the target database type used at runtime.  

Possible values (case insensitive):

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
