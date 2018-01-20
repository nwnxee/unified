# Optimizations Plugin Reference

## Description

Offers a series of useful performance optimizations.

## Environment Variables

| Variable Name                               |   Type   | Default Value |
| -------------                               | :------: | ------------- |
| ENABLE_AI_MASTER_OPTIMIZATIONS              | bool     | true    |
| ENABLE_BROADCAST_COMBAT_STATE_OPTIMIZATION  | bool     | true    |
| ENABLE_OBJCACHE_OPTIMIZATION                | bool     | true    |
| OBJCACHE_SIZE                               | uint32_t | 64000   |
| OBJCACHE_METRICS                            | bool     | false   |
| ENABLE_GET_CLIENT_OBJECT_OPTIMIZATION       | bool     | true    |
| ENABLE_HAS_FEAT_OPTIMIZATION                | bool     | true    |
| ENABLE_HRT_OPTIMIZATION                     | bool     | true    |
| HRT_FLUSH_COUNT                             | uint32_t | 8       |
| ENABLE_SLEEP_OPTIMIZATION                   | bool     | true    |
| SLEEP_THRESHOLD                             | uint32_t | 1       |
| SLEEP_LOW_RATE                              | uint32_t | 5       |
| SLEEP_HIGH_RATE                             | uint32_t | 0       |
| SLEEP_TYPE                                  | uint32_t | 0       |
| ENABLE_SORT_LAST_UPDATE_OBJECT_OPTIMIZATION | bool     | true    |
| SORT_LAST_UPDATE_FLUSH_COUNT                | uint32_t | 8       |
