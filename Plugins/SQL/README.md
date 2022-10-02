@page sql Readme
@ingroup sql

General data access, storage and manipulation of persistent data in a database.

## Migration
@ref sql_migrate "Migration from Legacy NWNX"

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
export NWNX_SQL_HOST=localhost
```

### NWNX_SQL_PORT

The port for the database connection. If left unset it will use the default port.

Only used by MySQL.

__Example__

```
export NWNX_SQL_PORT=3307
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

### NWNX_SQL_USE_UTF8

Convert all strings going between the database and game to/from UTF8

This takes into account the core locale as well.

__Example__

```
export NWNX_SQL_USE_UTF8=true
```

### NWNX_SQL_CHARACTER_SET

Set the connection's character set to be used.

Only supported on mysql and pgsql. For sqlite this can be achieved with a query.

__Examples (MySQL)__

```
export NWNX_SQL_CHARACTER_SET=utf8
export NWNX_SQL_CHARACTER_SET=cp1251
```

__Examples (PostgreSQL)__

```
export NWNX_SQL_CHARACTER_SET=WIN1252
```

(see https://www.postgresql.org/docs/current/multibyte.html for list)
