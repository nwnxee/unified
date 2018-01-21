# Redis Plugin Reference

## Description

This plugin allows you to connect to a redis server. If you don't know what redis is, I'd suggest reading up here in detail: redis.io.

Key features:

* This plugin supports almost all commands
* Including pubsub with script callbacks. You can use this to connect external services, even websites, to your nwserver in a non-blocking way.
* Also great for linking servers.
* Redis makes for a very good and fast key-value store, with some advanced data structures available. You can even use it as a queue if so desired.

TODO:

* SCO/RCO, so resman can automatically load resources from redis without user intervention. This requires a more generic interface/hook in core.

## Hints

* There are two includes, `nwnx_redis` and `nwnx_redis_short`. They do the same, but `_short` is not prefixed with `NWNX_Redis`.

## Getting started with PubSub

* Set up redis-server. Start it. This should be as simple as apt-get install redis. There's also a docker image.
* Configure `REDIS_HOST` and `REDIS_PORT` for nwnx.
* Include the .nss files in NWScript/ into your module.
* Create a script called "on_pubsub" (or rename it through `PUBSUB_SCRIPT`). An example is included in NWScript/.
* Configure `PUBSUB_CHANNELS` to be "test".
* Hint: Subscriptions support wildcards.
* Start your module.
* Use `redis-cli` to connect to your running redis server and type `PUBLISH test hi there`.
* Hint: `redis-cli monitor` in a separate shell is a great way to figure out what's going on.
* Your script should trigger with the payload available through `NWNX_Redis_GetPubSubMessageData()`.

### Moving on

* Now think of a good naming scheme for your various pubsub channels. Keep traffic as low as feasible, since each incoming message will trigger a script run. There is no batching yet.
* Hint: By convention, a good namespace separator for channels is "."; for keys ":".
* Example: `NWNX_Redis_PUBLISH("nwserver.players.join", GetPCPlayerName(..));`
* Hint: A good pattern is to store data in a redis key named after the channel and object identifier (i.e. `HSET nwserver:players:PlayerName:.lastSeen 1234`) and then trigger a PubSub message with the same subject (`PUBLISH nwserver.players.joins PlayerName`). This cuts down on wire overhead.

## Environment Variables

| Variable Name     |  Type                   | Default Value                      |
| ----------------- | :---------------------: | ---------------------------------- |
| `REDIS_HOST`      | string                  | (none)                             |
| `REDIS_PORT`      | int16                   | 6379                               |
| `PUBSUB_SCRIPT`   | string                  | on_pubsub                          |
| `PUBSUB_CHANNELS` | comma-separated strings | ""                                 |

