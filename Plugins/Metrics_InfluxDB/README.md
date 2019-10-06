# Metrics_InfluxDB Plugin Reference

## Description

Exports profiling information to Influx DB.

## InfluxDB setup

Install InfluxDB and create a database called "nwn".  (You can call it what you like, but the database name needs to match in the next section.

In the influxdb.conf file, in the "udp" section, enable the UDP port and set it's default database to ``nwn``

    [[udp]]
      enabled = true
      bind-address = ":8089"
      database = "nwn"
      # retention-policy = ""

## Environment Variables

| Variable Name                       |  Type  | Default Value |
| ----------------------------------- | :----: | ------------- |
| NWNX_METRICS_INFLUXDB_HOST          | string | _none_        |
| NWNX_METRICS_INFLUXDB_PORT          | string | _none_        |
