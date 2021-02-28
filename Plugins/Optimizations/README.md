@addtogroup optimizations Optimizations
@page optimizations Readme
@ingroup optimizations

Game optimizations. Improves performance of various game elements.

## Environment Variables

| Variable Name | Value | Notes |
| -------------   | :----: | ------------------------------------ |
| `NWNX_OPTIMIZATIONS_ASYNC_LOG_FLUSH` | true/false | Flushes the game log on an async thread, potentially improving performance |
| `NWNX_OPTIMIZATIONS_GAME_OBJECT_LOOKUP` | true/false | Optimizes object lookup code, improving performance |
| `NWNX_OPTIMIZATIONS_PLAYER_LOOKUP` | true/false | Optimizes Player client lookup from object IDs, improving performance |
| `NWNX_OPTIMIZATIONS_LUO_LOOKUP` | true/false | Optimizes LastUpdateObject lookup code, improving performance |
| `NWNX_OPTIMIZATIONS_ALTERNATE_GAME_OBJECT_UPDATE` | true/false | Uses an experimental alternative update mechanism. Requires `LUO_LOOKUP`. |
| `NWNX_OPTIMIZATIONS_RECONCILE_AUTOMAP_DATA` | true/false | Reduces the number of checks for mismatches between players' and module's area list |
