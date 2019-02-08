# SQL Plugin Reference

## Description

General data access, storage and manipulation of persistent data in a database.

## Environment Variables

### NWNX_SQL_TYPE

Controls the target database type used at runtime.  

Possible values (case insensitive):

* ``MYSQL`` 
* ``POSTGRESQL``
* ``SQLITE``

__Example__

```
export NWNX_SQL_TYPE=POSTGRESQL
```

### NWNX_SQL_HOST

Host name where the database resides.  Typically ``localhost`` but can be any valid host name or IP address.

Not used if using SQLite.

__Example__

```
export NWNX_SQL_HOSTNAME=localhost
```

### NWNX_SQL_USERNAME

Database username used for the connection.

Not used if using SQLite.

__Example__

```
export NWNX_SQL_USERNAME=nwn_db
```

### NWNX_SQL_PASSWORD

Password for the database connection.

Not used if using SQLite.

__Example__

```
export NWNX_SQL_PASSWORD=lathander_rulez
```

### NWNX_SQL_DATABASE

The database to connect to.

The filename of the database when using SQLite, it is stored in the UserDirectory/database folder.

__Example__

```
export NWNX_SQL_DATABASE=mymodulename
```

### NWNX_SQL_QUERY_METRICS

Export query execution metrics. 

The Metrics_InfluxDB plugin and a visualizer like Grafana are required to view these metrics.

__Example__

```
export NWNX_SQL_QUERY_METRICS=true
```
