# ThreadWatchdog Plugin Reference

## Description

Monitors the server for stalls and kills it when it meets a threshold.

## Environment Variables

* `NWNX_THREADWATCHDOG_PERIOD`: Set the period at which the watchdog fires, in seconds
* `NWNX_THREADWATCHDOG_KILL_THRESHOLD`: Number of successive long stall detections needed to kill the server

