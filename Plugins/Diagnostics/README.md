@addtogroup diagnostics Diagnostics
@page diagnostics Readme
@ingroup diagnostics

Game diagnostics.

## Memory Sanitizer

The memory sanitizer catches a few classes of memory corruptions in NWN and NWNX:

* Buffer overrun for heap buffers (writing outside the bounds of allocation)
* Use after free
* Double free

To use, you must preload NWNX_Diagnostics.so along with NWNX_Core.so, like:

    LD_PRELOAD=/path/to/NWNX_Core.so:/path/to/NWNX_Diagnostics.so

NOTE: Enabling the sanitizer will make it impossible to cleanly shut down the server. When the plugins unload, the server will crash. This is an unavoidable side effect.
