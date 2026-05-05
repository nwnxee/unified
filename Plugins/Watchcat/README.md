@addtogroup watchcat Watchcat
@page Watchcat Readme
@ingroup Watchcat

Monitors the server for stalls and kills it when it meets a threshold. Automatically restarting the server must be done outside of the process; this plugin only kills the process.

During stalls, the plugin samples the main thread for stacks, tries to bucket them into similar stacks, and prints the top offenders on stall or process exit to the logfile/stdout.

## Environment Variables

* `NWNX_WATCHCAT_WARMUP_MSEC` (int): Do not engage watchcat until this many msec have passed after plugin load.
* `NWNX_WATCHCAT_STALL_MSEC` (int): If the mainloop stalls for this many msec, we start sampling callstacks.
* `NWNX_WATCHCAT_STALL_SAMPLE_RATE_MSEC` (int): While stalling, sample stacks at this rate.
* `NWNX_WATCHCAT_KILL_MSEC` (int): Kill server with a FATAL message when a stall lasts longer than this many msec. This assumes the thing is thoroughly wedged with no hope of recovery.
* `NWNX_WATCHCAT_TEST_MODE` (bool): Turn this on to stall the server every 100 ticks for 5 seconds (for debugging Watchcat).
