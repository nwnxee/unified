@page data Readme
@ingroup data 

Provides a number of data structures for NWN code to use (simulated arrays)

# Notes

As of 8193.16, the Array provider has been re-written using the internal SQLite database instead of via the NWNX plugin.

Two files are provided:  `inc_array` which includes a re-implementation of the data structure into SQLite, and `nwnx_data`, which is a shim to provide backwards compatibility for people still using NWNX_Array to provide time to migrate to the new version.  Included in the NWScript folder is an example implementation showing usage of Data_Array in comparison with NWNX_Data_Array.

