#include "nwnx_redis_lib"


// Skipping sub-command: BITFIELD/{"command"=>"OVERFLOW", "type"=>"enum", "enum"=>["WRAP", "SAT", "FAIL"], "optional"=>true} - not supported yet.
// Skipping sub-command: CLIENT_KILL/{"command"=>"TYPE", "type"=>"enum", "enum"=>["normal", "master", "slave", "pubsub"], "optional"=>true} - not supported yet.
// Skipping sub-command: CLIENT_LIST/{"command"=>"TYPE", "type"=>"enum", "enum"=>["normal", "master", "replica", "pubsub"], "optional"=>true} - not supported yet.
// Skipping sub-command: SET/{"command"=>"expiration", "type"=>"enum", "enum"=>["EX seconds", "PX milliseconds"], "optional"=>true} - not supported yet.
// Skipping XCLAIM, cannot parse argument: {"name"=>"force", "enum"=>["FORCE"], "optional"=>true} - not supported yet.
// Skipping XCLAIM, cannot parse argument: {"name"=>"justid", "enum"=>["JUSTID"], "optional"=>true} - not supported yet.
/**
 * APPEND
 *
 * Append a value to a key
 *
 * Time complexity: O(1). The amortized time complexity is O(1) assuming the appended value is
 * small and the already present value is of any size, since the dynamic string
 * library used by Redis will double the free space available on every
 * reallocation.
 * Annotated return value: integer
 */
int APPEND(
	string key,
	string value
);

/**
 * AUTH
 *
 * Authenticate to the server
 * Annotated return value: simple-string
 */
int AUTH(
	string password
);

/**
 * BGREWRITEAOF
 *
 * Asynchronously rewrite the append-only file
 * Annotated return value: simple-string
 */
int BGREWRITEAOF();

/**
 * BGSAVE
 *
 * Asynchronously save the dataset to disk
 * Annotated return value: simple-string
 */
int BGSAVE();

/**
 * BITCOUNT
 *
 * Count set bits in a string
 *
 * Time complexity: O(N)
 * Annotated return value: integer
 */
int BITCOUNT(
	string key,
	// Redis type: integer
	int start = 0,
	// Redis type: integer
	int end = 0
);

/**
 * BITFIELD
 *
 * Perform arbitrary bitfield integer operations on strings
 *
 * Time complexity: O(1) for each subcommand specified
 * Annotated return value:
 */
int BITFIELD(
	string key,
	// Redis type: type
	string get_type = "",
	// Redis type: integer
	int get_offset = 0,
	// Redis type: type
	string set_type = "",
	// Redis type: integer
	int set_offset = 0,
	// Redis type: integer
	int set_value = 0,
	// Redis type: type
	string incrby_type = "",
	// Redis type: integer
	int incrby_offset = 0,
	// Redis type: integer
	int incrby_increment = 0
);

/**
 * BITOP
 *
 * Perform bitwise operations between strings
 *
 * Time complexity: O(N)
 * Annotated return value: integer
 */
int BITOP(
	string operation,
	// Redis type: key
	string destkey,
	string key
);

/**
 * BITPOS
 *
 * Find first bit set or clear in a string
 *
 * Time complexity: O(N)
 * Annotated return value: integer
 */
int BITPOS(
	string key,
	// Redis type: integer
	int bit,
	// Redis type: integer
	int start = 0,
	// Redis type: integer
	int end = 0
);

/**
 * BLPOP
 *
 * Remove and get the first element in a list, or block until one is available
 *
 * Time complexity: O(1)
 * Annotated return value: array
 */
int BLPOP(
	string key,
	// Redis type: integer
	int timeout
);

/**
 * BRPOP
 *
 * Remove and get the last element in a list, or block until one is available
 *
 * Time complexity: O(1)
 * Annotated return value: array
 */
int BRPOP(
	string key,
	// Redis type: integer
	int timeout
);

/**
 * BRPOPLPUSH
 *
 * Pop a value from a list, push it to another list and return it; or block until one is available
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int BRPOPLPUSH(
	// Redis type: key
	string source,
	// Redis type: key
	string destination,
	// Redis type: integer
	int timeout
);

/**
 * BZPOPMIN
 *
 * Remove and return the member with the lowest score from one or more sorted sets, or block until one is available
 *
 * Time complexity: O(log(N)) with N being the number of elements in the sorted set.
 * Annotated return value: array
 */
int BZPOPMIN(
	string key,
	// Redis type: integer
	int timeout
);

/**
 * BZPOPMAX
 *
 * Remove and return the member with the highest score from one or more sorted sets, or block until one is available
 *
 * Time complexity: O(log(N)) with N being the number of elements in the sorted set.
 * Annotated return value: array
 */
int BZPOPMAX(
	string key,
	// Redis type: integer
	int timeout
);

/**
 * CLIENT_ID
 *
 * Returns the client ID for the current connection
 *
 * Time complexity: O(1)
 * Annotated return value:
 */
int CLIENT_ID();

/**
 * CLIENT_KILL
 *
 * Kill the connection of a client
 *
 * Time complexity: O(N) where N is the number of client connections
 * Annotated return value: simple-string
 */
int CLIENT_KILL(
	string ip_port = "",
	// Redis type: integer
	int id_client_id = 0,
	string addr_ip_port = "",
	string skipme_yes_no = ""
);

/**
 * CLIENT_LIST
 *
 * Get the list of client connections
 *
 * Time complexity: O(N) where N is the number of client connections
 * Annotated return value: bulk-string
 */
int CLIENT_LIST();

/**
 * CLIENT_GETNAME
 *
 * Get the current connection name
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int CLIENT_GETNAME();

/**
 * CLIENT_PAUSE
 *
 * Stop processing commands from clients for some time
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLIENT_PAUSE(
	// Redis type: integer
	int timeout
);

/**
 * CLIENT_REPLY
 *
 * Instruct the server whether to reply to commands
 *
 * Time complexity: O(1)

 * - Valid values for reply_mode: "ON", "OFF", "SKIP"
 * Annotated return value: simple-string
 */
int CLIENT_REPLY(
	// Redis type: enum
	string reply_mode
);

/**
 * CLIENT_SETNAME
 *
 * Set the current connection name
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLIENT_SETNAME(
	string connection_name
);

/**
 * CLIENT_UNBLOCK
 *
 * Unblock a client blocked in a blocking command from a different connection
 *
 * Time complexity: O(log N) where N is the number of client connections

 * - Valid values for unblock_type: "TIMEOUT", "ERROR"
 * Annotated return value:
 */
int CLIENT_UNBLOCK(
	string client_id,
	// Redis type: enum
	string unblock_type = ""
);

/**
 * CLUSTER_ADDSLOTS
 *
 * Assign new hash slots to receiving node
 *
 * Time complexity: O(N) where N is the total number of hash slot arguments
 * Annotated return value: simple-string
 */
int CLUSTER_ADDSLOTS(
	// Redis type: integer
	int slot
);

/**
 * CLUSTER_COUNT_FAILURE_REPORTS
 *
 * Return the number of failure reports active for a given node
 *
 * Time complexity: O(N) where N is the number of failure reports
 * Annotated return value: integer
 */
int CLUSTER_COUNT_FAILURE_REPORTS(
	string node_id
);

/**
 * CLUSTER_COUNTKEYSINSLOT
 *
 * Return the number of local keys in the specified hash slot
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int CLUSTER_COUNTKEYSINSLOT(
	// Redis type: integer
	int slot
);

/**
 * CLUSTER_DELSLOTS
 *
 * Set hash slots as unbound in receiving node
 *
 * Time complexity: O(N) where N is the total number of hash slot arguments
 * Annotated return value: simple-string
 */
int CLUSTER_DELSLOTS(
	// Redis type: integer
	int slot
);

/**
 * CLUSTER_FAILOVER
 *
 * Forces a replica to perform a manual failover of its master.
 *
 * Time complexity: O(1)

 * - Valid values for options: "FORCE", "TAKEOVER"
 * Annotated return value: simple-string
 */
int CLUSTER_FAILOVER(
	// Redis type: enum
	string options = ""
);

/**
 * CLUSTER_FORGET
 *
 * Remove a node from the nodes table
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLUSTER_FORGET(
	string node_id
);

/**
 * CLUSTER_GETKEYSINSLOT
 *
 * Return local key names in the specified hash slot
 *
 * Time complexity: O(log(N)) where N is the number of requested keys
 * Annotated return value: array
 */
int CLUSTER_GETKEYSINSLOT(
	// Redis type: integer
	int slot,
	// Redis type: integer
	int count
);

/**
 * CLUSTER_INFO
 *
 * Provides info about Redis Cluster node state
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int CLUSTER_INFO();

/**
 * CLUSTER_KEYSLOT
 *
 * Returns the hash slot of the specified key
 *
 * Time complexity: O(N) where N is the number of bytes in the key
 * Annotated return value: integer
 */
int CLUSTER_KEYSLOT(
	string key
);

/**
 * CLUSTER_MEET
 *
 * Force a node cluster to handshake with another node
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLUSTER_MEET(
	string ip,
	// Redis type: integer
	int port
);

/**
 * CLUSTER_NODES
 *
 * Get Cluster config for the node
 *
 * Time complexity: O(N) where N is the total number of Cluster nodes
 * Annotated return value: bulk-string
 */
int CLUSTER_NODES();

/**
 * CLUSTER_REPLICATE
 *
 * Reconfigure a node as a replica of the specified master node
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLUSTER_REPLICATE(
	string node_id
);

/**
 * CLUSTER_RESET
 *
 * Reset a Redis Cluster node
 *
 * Time complexity: O(N) where N is the number of known nodes. The command may execute a
 * FLUSHALL as a side effect.

 * - Valid values for reset_type: "HARD", "SOFT"
 * Annotated return value: simple-string
 */
int CLUSTER_RESET(
	// Redis type: enum
	string reset_type = ""
);

/**
 * CLUSTER_SAVECONFIG
 *
 * Forces the node to save cluster state on disk
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLUSTER_SAVECONFIG();

/**
 * CLUSTER_SET_CONFIG_EPOCH
 *
 * Set the configuration epoch in a new node
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CLUSTER_SET_CONFIG_EPOCH(
	// Redis type: integer
	int config_epoch
);

/**
 * CLUSTER_SETSLOT
 *
 * Bind a hash slot to a specific node
 *
 * Time complexity: O(1)

 * - Valid values for subcommand: "IMPORTING", "MIGRATING", "STABLE", "NODE"
 * Annotated return value: simple-string
 */
int CLUSTER_SETSLOT(
	// Redis type: integer
	int slot,
	// Redis type: enum
	string subcommand,
	string node_id = ""
);

/**
 * CLUSTER_SLAVES
 *
 * List replica nodes of the specified master node
 *
 * Time complexity: O(1)
 * Annotated return value:
 */
int CLUSTER_SLAVES(
	string node_id
);

/**
 * CLUSTER_REPLICAS
 *
 * List replica nodes of the specified master node
 *
 * Time complexity: O(1)
 * Annotated return value:
 */
int CLUSTER_REPLICAS(
	string node_id
);

/**
 * CLUSTER_SLOTS
 *
 * Get array of Cluster slot to node mappings
 *
 * Time complexity: O(N) where N is the total number of Cluster nodes
 * Annotated return value: array
 */
int CLUSTER_SLOTS();

/**
 * COMMAND
 *
 * Get array of Redis command details
 *
 * Time complexity: O(N) where N is the total number of Redis commands
 * Annotated return value: array
 */
int COMMAND();

/**
 * COMMAND_COUNT
 *
 * Get total number of Redis commands
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int COMMAND_COUNT();

/**
 * COMMAND_GETKEYS
 *
 * Extract keys given a full Redis command
 *
 * Time complexity: O(N) where N is the number of arguments to the command
 * Annotated return value: array
 */
int COMMAND_GETKEYS();

/**
 * COMMAND_INFO
 *
 * Get array of specific Redis command details
 *
 * Time complexity: O(N) when N is number of commands to look up
 * Annotated return value: array
 */
int COMMAND_INFO(
	string command_name
);

/**
 * CONFIG_GET
 *
 * Get the value of a configuration parameter
 * Annotated return value: array
 */
int CONFIG_GET(
	string parameter
);

/**
 * CONFIG_REWRITE
 *
 * Rewrite the configuration file with the in memory configuration
 * Annotated return value: simple-string
 */
int CONFIG_REWRITE();

/**
 * CONFIG_SET
 *
 * Set a configuration parameter to the given value
 * Annotated return value: simple-string
 */
int CONFIG_SET(
	string parameter,
	string value
);

/**
 * CONFIG_RESETSTAT
 *
 * Reset the stats returned by INFO
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int CONFIG_RESETSTAT();

/**
 * DBSIZE
 *
 * Return the number of keys in the selected database
 * Annotated return value: integer
 */
int DBSIZE();

/**
 * DEBUG_OBJECT
 *
 * Get debugging information about a key
 * Annotated return value: simple-string
 */
int DEBUG_OBJECT(
	string key
);

/**
 * DEBUG_SEGFAULT
 *
 * Make the server crash
 * Annotated return value: simple-string
 */
int DEBUG_SEGFAULT();

/**
 * DECR
 *
 * Decrement the integer value of a key by one
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int DECR(
	string key
);

/**
 * DECRBY
 *
 * Decrement the integer value of a key by the given number
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int DECRBY(
	string key,
	// Redis type: integer
	int decrement
);

/**
 * DEL
 *
 * Delete a key
 *
 * Time complexity: O(N) where N is the number of keys that will be removed. When a key to
 * remove holds a value other than a string, the individual complexity for this
 * key is O(M) where M is the number of elements in the list, set, sorted set
 * or hash. Removing a single key that holds a string value is O(1).
 * Annotated return value: integer
 */
int DEL(
	string key
);

/**
 * DISCARD
 *
 * Discard all commands issued after MULTI
 * Annotated return value: simple-string
 */
int DISCARD();

/**
 * DUMP
 *
 * Return a serialized version of the value stored at the specified key.
 *
 * Time complexity: O(1) to access the key and additional O(N*M) to serialized it, where N is
 * the number of Redis objects composing the value and M their average size.
 * For small string values the time complexity is thus O(1)+O(1*M) where M is
 * small, so simply O(1).
 * Annotated return value: bulk-string
 */
int DUMP(
	string key
);

/**
 * ECHO
 *
 * Echo the given string
 * Annotated return value: bulk-string
 */
int ECHO(
	string message
);

/**
 * EVAL
 *
 * Execute a Lua script server side
 *
 * Time complexity: Depends on the script that is executed.
 * Annotated return value:
 */
int EVAL(
	string script,
	// Redis type: integer
	int numkeys,
	string key,
	string arg
);

/**
 * EVALSHA
 *
 * Execute a Lua script server side
 *
 * Time complexity: Depends on the script that is executed.
 * Annotated return value:
 */
int EVALSHA(
	string sha1,
	// Redis type: integer
	int numkeys,
	string key,
	string arg
);

/**
 * EXEC
 *
 * Execute all commands issued after MULTI
 * Annotated return value: array
 */
int EXEC();

/**
 * EXISTS
 *
 * Determine if a key exists
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int EXISTS(
	string key
);

/**
 * EXPIRE
 *
 * Set a key's time to live in seconds
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int EXPIRE(
	string key,
	// Redis type: integer
	int seconds
);

/**
 * EXPIREAT
 *
 * Set the expiration for a key as a UNIX timestamp
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int EXPIREAT(
	string key,
	// Redis type: posix time
	string timestamp
);

/**
 * FLUSHALL
 *
 * Remove all keys from all databases

 * - Valid values for async: "ASYNC"
 * Annotated return value: simple-string
 */
int FLUSHALL(
	// Redis type: enum
	string async = ""
);

/**
 * FLUSHDB
 *
 * Remove all keys from the current database

 * - Valid values for async: "ASYNC"
 * Annotated return value: simple-string
 */
int FLUSHDB(
	// Redis type: enum
	string async = ""
);

/**
 * GEOADD
 *
 * Add one or more geospatial items in the geospatial index represented using a sorted set
 *
 * Time complexity: O(log(N)) for each item added, where N is the number of elements in the
 * sorted set.
 * Annotated return value: integer
 */
int GEOADD(
	string key,
	// Redis type: double
	float longitude,
	// Redis type: double
	float latitude,
	string member
);

/**
 * GEOHASH
 *
 * Returns members of a geospatial index as standard geohash strings
 *
 * Time complexity: O(log(N)) for each member requested, where N is the number of elements in
 * the sorted set.
 * Annotated return value: array
 */
int GEOHASH(
	string key,
	string member
);

/**
 * GEOPOS
 *
 * Returns longitude and latitude of members of a geospatial index
 *
 * Time complexity: O(log(N)) for each member requested, where N is the number of elements in
 * the sorted set.
 * Annotated return value: array
 */
int GEOPOS(
	string key,
	string member
);

/**
 * GEODIST
 *
 * Returns the distance between two members of a geospatial index
 *
 * Time complexity: O(log(N))
 * Annotated return value: bulk-string
 */
int GEODIST(
	string key,
	string member1,
	string member2,
	string unit = ""
);

/**
 * GEORADIUS
 *
 * Query a sorted set representing a geospatial index to fetch members matching a given maximum distance from a point
 *
 * Time complexity: O(N+log(M)) where N is the number of elements inside the bounding box of the
 * circular area delimited by center and radius and M is the number of items
 * inside the index.

 * - Valid values for unit: "m", "km", "ft", "mi"

 * - Valid values for withcoord: "WITHCOORD"

 * - Valid values for withdist: "WITHDIST"

 * - Valid values for withhash: "WITHHASH"

 * - Valid values for order: "ASC", "DESC"
 * Annotated return value: array
 */
int GEORADIUS(
	string key,
	// Redis type: double
	float longitude,
	// Redis type: double
	float latitude,
	// Redis type: double
	float radius,
	// Redis type: enum
	string unit,
	// Redis type: enum
	string withcoord = "",
	// Redis type: enum
	string withdist = "",
	// Redis type: enum
	string withhash = "",
	// Redis type: integer
	int count_count = 0,
	// Redis type: enum
	string order = "",
	// Redis type: key
	string store_key = "",
	// Redis type: key
	string storedist_key = ""
);

/**
 * GEORADIUSBYMEMBER
 *
 * Query a sorted set representing a geospatial index to fetch members matching a given maximum distance from a member
 *
 * Time complexity: O(N+log(M)) where N is the number of elements inside the bounding box of the
 * circular area delimited by center and radius and M is the number of items
 * inside the index.

 * - Valid values for unit: "m", "km", "ft", "mi"

 * - Valid values for withcoord: "WITHCOORD"

 * - Valid values for withdist: "WITHDIST"

 * - Valid values for withhash: "WITHHASH"

 * - Valid values for order: "ASC", "DESC"
 * Annotated return value:
 */
int GEORADIUSBYMEMBER(
	string key,
	string member,
	// Redis type: double
	float radius,
	// Redis type: enum
	string unit,
	// Redis type: enum
	string withcoord = "",
	// Redis type: enum
	string withdist = "",
	// Redis type: enum
	string withhash = "",
	// Redis type: integer
	int count_count = 0,
	// Redis type: enum
	string order = "",
	// Redis type: key
	string store_key = "",
	// Redis type: key
	string storedist_key = ""
);

/**
 * GET
 *
 * Get the value of a key
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int GET(
	string key
);

/**
 * GETBIT
 *
 * Returns the bit value at offset in the string value stored at key
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int GETBIT(
	string key,
	// Redis type: integer
	int offset
);

/**
 * GETRANGE
 *
 * Get a substring of the string stored at a key
 *
 * Time complexity: O(N) where N is the length of the returned string. The complexity is
 * ultimately determined by the returned length, but because creating a
 * substring from an existing string is very cheap, it can be considered O(1)
 * for small strings.
 * Annotated return value: bulk-string
 */
int GETRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int end
);

/**
 * GETSET
 *
 * Set the string value of a key and return its old value
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int GETSET(
	string key,
	string value
);

/**
 * HDEL
 *
 * Delete one or more hash fields
 *
 * Time complexity: O(N) where N is the number of fields to be removed.
 * Annotated return value: integer
 */
int HDEL(
	string key,
	string field
);

/**
 * HEXISTS
 *
 * Determine if a hash field exists
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int HEXISTS(
	string key,
	string field
);

/**
 * HGET
 *
 * Get the value of a hash field
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int HGET(
	string key,
	string field
);

/**
 * HGETALL
 *
 * Get all the fields and values in a hash
 *
 * Time complexity: O(N) where N is the size of the hash.
 * Annotated return value: array
 */
int HGETALL(
	string key
);

/**
 * HINCRBY
 *
 * Increment the integer value of a hash field by the given number
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int HINCRBY(
	string key,
	string field,
	// Redis type: integer
	int increment
);

/**
 * HINCRBYFLOAT
 *
 * Increment the float value of a hash field by the given amount
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int HINCRBYFLOAT(
	string key,
	string field,
	// Redis type: double
	float increment
);

/**
 * HKEYS
 *
 * Get all the fields in a hash
 *
 * Time complexity: O(N) where N is the size of the hash.
 * Annotated return value: array
 */
int HKEYS(
	string key
);

/**
 * HLEN
 *
 * Get the number of fields in a hash
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int HLEN(
	string key
);

/**
 * HMGET
 *
 * Get the values of all the given hash fields
 *
 * Time complexity: O(N) where N is the number of fields being requested.
 * Annotated return value: array
 */
int HMGET(
	string key,
	string field
);

/**
 * HMSET
 *
 * Set multiple hash fields to multiple values
 *
 * Time complexity: O(N) where N is the number of fields being set.
 * Annotated return value: simple-string
 */
int HMSET(
	string key,
	string field,
	string value
);

/**
 * HSET
 *
 * Set the string value of a hash field
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int HSET(
	string key,
	string field,
	string value
);

/**
 * HSETNX
 *
 * Set the value of a hash field, only if the field does not exist
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int HSETNX(
	string key,
	string field,
	string value
);

/**
 * HSTRLEN
 *
 * Get the length of the value of a hash field
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int HSTRLEN(
	string key,
	string field
);

/**
 * HVALS
 *
 * Get all the values in a hash
 *
 * Time complexity: O(N) where N is the size of the hash.
 * Annotated return value: array
 */
int HVALS(
	string key
);

/**
 * INCR
 *
 * Increment the integer value of a key by one
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int INCR(
	string key
);

/**
 * INCRBY
 *
 * Increment the integer value of a key by the given amount
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int INCRBY(
	string key,
	// Redis type: integer
	int increment
);

/**
 * INCRBYFLOAT
 *
 * Increment the float value of a key by the given amount
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int INCRBYFLOAT(
	string key,
	// Redis type: double
	float increment
);

/**
 * INFO
 *
 * Get information and statistics about the server
 * Annotated return value: bulk-string
 */
int INFO(
	string section = ""
);

/**
 * KEYS
 *
 * Find all keys matching the given pattern
 *
 * Time complexity: O(N) with N being the number of keys in the database, under the assumption
 * that the key names in the database and the given pattern have limited
 * length.
 * Annotated return value: array
 */
int KEYS(
	string pattern
);

/**
 * LASTSAVE
 *
 * Get the UNIX time stamp of the last successful save to disk
 * Annotated return value: integer
 */
int LASTSAVE();

/**
 * LINDEX
 *
 * Get an element from a list by its index
 *
 * Time complexity: O(N) where N is the number of elements to traverse to get to the element at
 * index. This makes asking for the first or the last element of the list O(1).
 * Annotated return value: bulk-string
 */
int LINDEX(
	string key,
	// Redis type: integer
	int index
);

/**
 * LINSERT
 *
 * Insert an element before or after another element in a list
 *
 * Time complexity: O(N) where N is the number of elements to traverse before seeing the value
 * pivot. This means that inserting somewhere on the left end on the list
 * (head) can be considered O(1) and inserting somewhere on the right end
 * (tail) is O(N).

 * - Valid values for where: "BEFORE", "AFTER"
 * Annotated return value: integer
 */
int LINSERT(
	string key,
	// Redis type: enum
	string where,
	string pivot,
	string value
);

/**
 * LLEN
 *
 * Get the length of a list
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int LLEN(
	string key
);

/**
 * LPOP
 *
 * Remove and get the first element in a list
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int LPOP(
	string key
);

/**
 * LPUSH
 *
 * Prepend one or multiple values to a list
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int LPUSH(
	string key,
	string value
);

/**
 * LPUSHX
 *
 * Prepend a value to a list, only if the list exists
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int LPUSHX(
	string key,
	string value
);

/**
 * LRANGE
 *
 * Get a range of elements from a list
 *
 * Time complexity: O(S+N) where S is the distance of start offset from HEAD for small lists,
 * from nearest end (HEAD or TAIL) for large lists; and N is the number of
 * elements in the specified range.
 * Annotated return value: array
 */
int LRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
);

/**
 * LREM
 *
 * Remove elements from a list
 *
 * Time complexity: O(N) where N is the length of the list.
 * Annotated return value: integer
 */
int LREM(
	string key,
	// Redis type: integer
	int count,
	string value
);

/**
 * LSET
 *
 * Set the value of an element in a list by its index
 *
 * Time complexity: O(N) where N is the length of the list. Setting either the first or the last
 * element of the list is O(1).
 * Annotated return value: simple-string
 */
int LSET(
	string key,
	// Redis type: integer
	int index,
	string value
);

/**
 * LTRIM
 *
 * Trim a list to the specified range
 *
 * Time complexity: O(N) where N is the number of elements to be removed by the operation.
 * Annotated return value: simple-string
 */
int LTRIM(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
);

/**
 * MEMORY_DOCTOR
 *
 * Outputs memory problems report
 * Annotated return value: bulk-string
 */
int MEMORY_DOCTOR();

/**
 * MEMORY_HELP
 *
 * Show helpful text about the different subcommands
 * Annotated return value: array
 */
int MEMORY_HELP();

/**
 * MEMORY_MALLOC_STATS
 *
 * Show allocator internal stats
 * Annotated return value: bulk-string
 */
int MEMORY_MALLOC_STATS();

/**
 * MEMORY_PURGE
 *
 * Ask the allocator to release memory
 * Annotated return value: simple-string
 */
int MEMORY_PURGE();

/**
 * MEMORY_STATS
 *
 * Show memory usage details
 * Annotated return value: array
 */
int MEMORY_STATS();

/**
 * MEMORY_USAGE
 *
 * Estimate the memory usage of a key
 *
 * Time complexity: O(N) where N is the number of samples.
 * Annotated return value: integer
 */
int MEMORY_USAGE(
	string key,
	// Redis type: integer
	int samples_count = 0
);

/**
 * MGET
 *
 * Get the values of all the given keys
 *
 * Time complexity: O(N) where N is the number of keys to retrieve.
 * Annotated return value: array
 */
int MGET(
	string key
);

/**
 * MIGRATE
 *
 * Atomically transfer a key from a Redis instance to another one.
 *
 * Time complexity: This command actually executes a DUMP+DEL in the source instance, and a
 * RESTORE in the target instance. See the pages of these commands for time
 * complexity. Also an O(N) data transfer between the two instances is
 * performed.

 * - Valid values for key: "key", "\"\""

 * - Valid values for copy: "COPY"

 * - Valid values for replace: "REPLACE"
 * Annotated return value: simple-string
 */
int MIGRATE(
	string host,
	string port,
	// Redis type: enum
	string key,
	// Redis type: integer
	int destination_db,
	// Redis type: integer
	int timeout,
	// Redis type: enum
	string copy = "",
	// Redis type: enum
	string replace = "",
	string auth_password = "",
	// Redis type: key
	string keys_key = ""
);

/**
 * MONITOR
 *
 * Listen for all requests received by the server in real time
 * Annotated return value:
 */
int MONITOR();

/**
 * MOVE
 *
 * Move a key to another database
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int MOVE(
	string key,
	// Redis type: integer
	int db
);

/**
 * MSET
 *
 * Set multiple keys to multiple values
 *
 * Time complexity: O(N) where N is the number of keys to set.
 * Annotated return value: simple-string
 */
int MSET(
	string key,
	string value
);

/**
 * MSETNX
 *
 * Set multiple keys to multiple values, only if none of the keys exist
 *
 * Time complexity: O(N) where N is the number of keys to set.
 * Annotated return value: integer
 */
int MSETNX(
	string key,
	string value
);

/**
 * MULTI
 *
 * Mark the start of a transaction block
 * Annotated return value: simple-string
 */
int MULTI();

/**
 * OBJECT
 *
 * Inspect the internals of Redis objects
 *
 * Time complexity: O(1) for all the currently implemented subcommands.
 * Annotated return value:
 */
int OBJECT(
	string subcommand,
	string arguments = ""
);

/**
 * PERSIST
 *
 * Remove the expiration from a key
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int PERSIST(
	string key
);

/**
 * PEXPIRE
 *
 * Set a key's time to live in milliseconds
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int PEXPIRE(
	string key,
	// Redis type: integer
	int milliseconds
);

/**
 * PEXPIREAT
 *
 * Set the expiration for a key as a UNIX timestamp specified in milliseconds
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int PEXPIREAT(
	string key,
	// Redis type: posix time
	string milliseconds_timestamp
);

/**
 * PFADD
 *
 * Adds the specified elements to the specified HyperLogLog.
 *
 * Time complexity: O(1) to add every element.
 * Annotated return value: integer
 */
int PFADD(
	string key,
	string element
);

/**
 * PFCOUNT
 *
 * Return the approximated cardinality of the set(s) observed by the HyperLogLog at key(s).
 *
 * Time complexity: O(1) with a very small average constant time when called with a single key.
 * O(N) with N being the number of keys, and much bigger constant times, when
 * called with multiple keys.
 * Annotated return value: integer
 */
int PFCOUNT(
	string key
);

/**
 * PFMERGE
 *
 * Merge N different HyperLogLogs into a single one.
 *
 * Time complexity: O(N) to merge N HyperLogLogs, but with high constant times.
 * Annotated return value: simple-string
 */
int PFMERGE(
	// Redis type: key
	string destkey,
	// Redis type: key
	string sourcekey
);

/**
 * PING
 *
 * Ping the server
 * Annotated return value: simple-string
 */
int PING(
	string message = ""
);

/**
 * PSETEX
 *
 * Set the value and expiration in milliseconds of a key
 *
 * Time complexity: O(1)
 * Annotated return value:
 */
int PSETEX(
	string key,
	// Redis type: integer
	int milliseconds,
	string value
);

/**
 * PUBSUB
 *
 * Inspect the state of the Pub/Sub subsystem
 *
 * Time complexity: O(N) for the CHANNELS subcommand, where N is the number of active channels,
 * and assuming constant time pattern matching (relatively short channels and
 * patterns). O(N) for the NUMSUB subcommand, where N is the number of
 * requested channels. O(1) for the NUMPAT subcommand.
 * Annotated return value: array
 */
int PUBSUB(
	string subcommand,
	string argument = ""
);

/**
 * PTTL
 *
 * Get the time to live for a key in milliseconds
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int PTTL(
	string key
);

/**
 * PUBLISH
 *
 * Post a message to a channel
 *
 * Time complexity: O(N+M) where N is the number of clients subscribed to the receiving channel
 * and M is the total number of subscribed patterns (by any client).
 * Annotated return value: integer
 */
int PUBLISH(
	string channel,
	string message
);

/**
 * QUIT
 *
 * Close the connection
 * Annotated return value: simple-string
 */
int QUIT();

/**
 * RANDOMKEY
 *
 * Return a random key from the keyspace
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int RANDOMKEY();

/**
 * READONLY
 *
 * Enables read queries for a connection to a cluster replica node
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int READONLY();

/**
 * READWRITE
 *
 * Disables read queries for a connection to a cluster replica node
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int READWRITE();

/**
 * RENAME
 *
 * Rename a key
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int RENAME(
	string key,
	// Redis type: key
	string newkey
);

/**
 * RENAMENX
 *
 * Rename a key, only if the new key does not exist
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int RENAMENX(
	string key,
	// Redis type: key
	string newkey
);

/**
 * RESTORE
 *
 * Create a key using the provided serialized value, previously obtained using DUMP.
 *
 * Time complexity: O(1) to create the new key and additional O(N*M) to reconstruct the
 * serialized value, where N is the number of Redis objects composing the value
 * and M their average size. For small string values the time complexity is
 * thus O(1)+O(1*M) where M is small, so simply O(1). However for sorted set
 * values the complexity is O(N*M*log(N)) because inserting values into sorted
 * sets is O(log(N)).

 * - Valid values for replace: "REPLACE"

 * - Valid values for absttl: "ABSTTL"
 * Annotated return value: simple-string
 */
int RESTORE(
	string key,
	// Redis type: integer
	int ttl,
	string serialized_value,
	// Redis type: enum
	string replace = "",
	// Redis type: enum
	string absttl = "",
	// Redis type: integer
	int idletime_seconds = 0,
	// Redis type: integer
	int freq_frequency = 0
);

/**
 * ROLE
 *
 * Return the role of the instance in the context of replication
 * Annotated return value: array
 */
int ROLE();

/**
 * RPOP
 *
 * Remove and get the last element in a list
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int RPOP(
	string key
);

/**
 * RPOPLPUSH
 *
 * Remove the last element in a list, prepend it to another list and return it
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int RPOPLPUSH(
	// Redis type: key
	string source,
	// Redis type: key
	string destination
);

/**
 * RPUSH
 *
 * Append one or multiple values to a list
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int RPUSH(
	string key,
	string value
);

/**
 * RPUSHX
 *
 * Append a value to a list, only if the list exists
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int RPUSHX(
	string key,
	string value
);

/**
 * SADD
 *
 * Add one or more members to a set
 *
 * Time complexity: O(1) for each element added, so O(N) to add N elements when the command is
 * called with multiple arguments.
 * Annotated return value: integer
 */
int SADD(
	string key,
	string member
);

/**
 * SAVE
 *
 * Synchronously save the dataset to disk
 * Annotated return value: simple-string
 */
int SAVE();

/**
 * SCARD
 *
 * Get the number of members in a set
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int SCARD(
	string key
);

/**
 * SCRIPT_DEBUG
 *
 * Set the debug mode for executed scripts.
 *
 * Time complexity: O(1)

 * - Valid values for mode: "YES", "SYNC", "NO"
 * Annotated return value: simple-string
 */
int SCRIPT_DEBUG(
	// Redis type: enum
	string mode
);

/**
 * SCRIPT_EXISTS
 *
 * Check existence of scripts in the script cache.
 *
 * Time complexity: O(N) with N being the number of scripts to check (so checking a single
 * script is an O(1) operation).
 * Annotated return value: array
 */
int SCRIPT_EXISTS(
	string sha1
);

/**
 * SCRIPT_FLUSH
 *
 * Remove all the scripts from the script cache.
 *
 * Time complexity: O(N) with N being the number of scripts in cache
 * Annotated return value: simple-string
 */
int SCRIPT_FLUSH();

/**
 * SCRIPT_KILL
 *
 * Kill the script currently in execution.
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int SCRIPT_KILL();

/**
 * SCRIPT_LOAD
 *
 * Load the specified Lua script into the script cache.
 *
 * Time complexity: O(N) with N being the length in bytes of the script body.
 * Annotated return value: bulk-string
 */
int SCRIPT_LOAD(
	string script
);

/**
 * SDIFF
 *
 * Subtract multiple sets
 *
 * Time complexity: O(N) where N is the total number of elements in all given sets.
 * Annotated return value: array
 */
int SDIFF(
	string key
);

/**
 * SDIFFSTORE
 *
 * Subtract multiple sets and store the resulting set in a key
 *
 * Time complexity: O(N) where N is the total number of elements in all given sets.
 * Annotated return value: integer
 */
int SDIFFSTORE(
	// Redis type: key
	string destination,
	string key
);

/**
 * SELECT
 *
 * Change the selected database for the current connection
 * Annotated return value: simple-string
 */
int SELECT(
	// Redis type: integer
	int index
);

/**
 * SET
 *
 * Set the string value of a key
 *
 * Time complexity: O(1)

 * - Valid values for condition: "NX", "XX"
 * Annotated return value: simple-string
 */
int SET(
	string key,
	string value,
	// Redis type: enum
	string condition = ""
);

/**
 * SETBIT
 *
 * Sets or clears the bit at offset in the string value stored at key
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int SETBIT(
	string key,
	// Redis type: integer
	int offset,
	string value
);

/**
 * SETEX
 *
 * Set the value and expiration of a key
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int SETEX(
	string key,
	// Redis type: integer
	int seconds,
	string value
);

/**
 * SETNX
 *
 * Set the value of a key, only if the key does not exist
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int SETNX(
	string key,
	string value
);

/**
 * SETRANGE
 *
 * Overwrite part of a string at key starting at the specified offset
 *
 * Time complexity: O(1), not counting the time taken to copy the new string in place. Usually,
 * this string is very small so the amortized complexity is O(1). Otherwise,
 * complexity is O(M) with M being the length of the value argument.
 * Annotated return value: integer
 */
int SETRANGE(
	string key,
	// Redis type: integer
	int offset,
	string value
);

/**
 * SHUTDOWN
 *
 * Synchronously save the dataset to disk and then shut down the server

 * - Valid values for save_mode: "NOSAVE", "SAVE"
 * Annotated return value: simple-string
 */
int SHUTDOWN(
	// Redis type: enum
	string save_mode = ""
);

/**
 * SINTER
 *
 * Intersect multiple sets
 *
 * Time complexity: O(N*M) worst case where N is the cardinality of the smallest set and M is
 * the number of sets.
 * Annotated return value: array
 */
int SINTER(
	string key
);

/**
 * SINTERSTORE
 *
 * Intersect multiple sets and store the resulting set in a key
 *
 * Time complexity: O(N*M) worst case where N is the cardinality of the smallest set and M is
 * the number of sets.
 * Annotated return value: integer
 */
int SINTERSTORE(
	// Redis type: key
	string destination,
	string key
);

/**
 * SISMEMBER
 *
 * Determine if a given value is a member of a set
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int SISMEMBER(
	string key,
	string member
);

/**
 * SLAVEOF
 *
 * Make the server a replica of another instance, or promote it as master. Deprecated starting with Redis 5. Use REPLICAOF instead.
 * Annotated return value: simple-string
 */
int SLAVEOF(
	string host,
	string port
);

/**
 * REPLICAOF
 *
 * Make the server a replica of another instance, or promote it as master.
 * Annotated return value: simple-string
 */
int REPLICAOF(
	string host,
	string port
);

/**
 * SLOWLOG
 *
 * Manages the Redis slow queries log
 * Annotated return value:
 */
int SLOWLOG(
	string subcommand,
	string argument = ""
);

/**
 * SMEMBERS
 *
 * Get all the members in a set
 *
 * Time complexity: O(N) where N is the set cardinality.
 * Annotated return value: array
 */
int SMEMBERS(
	string key
);

/**
 * SMOVE
 *
 * Move a member from one set to another
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int SMOVE(
	// Redis type: key
	string source,
	// Redis type: key
	string destination,
	string member
);

/**
 * SORT
 *
 * Sort the elements in a list, set or sorted set
 *
 * Time complexity: O(N+M*log(M)) where N is the number of elements in the list or set to sort,
 * and M the number of returned elements. When the elements are not sorted,
 * complexity is currently O(N) as there is a copy step that will be avoided in
 * next releases.

 * - Valid values for order: "ASC", "DESC"

 * - Valid values for sorting: "ALPHA"
 * Annotated return value: array
 */
int SORT(
	string key,
	// Redis type: pattern
	string by_pattern = "",
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0,
	string get_pattern = "",
	// Redis type: enum
	string order = "",
	// Redis type: enum
	string sorting = "",
	// Redis type: key
	string store_destination = ""
);

/**
 * SPOP
 *
 * Remove and return one or multiple random members from a set
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int SPOP(
	string key,
	// Redis type: integer
	int count = 0
);

/**
 * SRANDMEMBER
 *
 * Get one or multiple random members from a set
 *
 * Time complexity: Without the count argument O(1), otherwise O(N) where N is the absolute
 * value of the passed count.
 * Annotated return value: bulk-string
 */
int SRANDMEMBER(
	string key,
	// Redis type: integer
	int count = 0
);

/**
 * SREM
 *
 * Remove one or more members from a set
 *
 * Time complexity: O(N) where N is the number of members to be removed.
 * Annotated return value: integer
 */
int SREM(
	string key,
	string member
);

/**
 * STRLEN
 *
 * Get the length of the value stored in a key
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int STRLEN(
	string key
);

/**
 * SUNION
 *
 * Add multiple sets
 *
 * Time complexity: O(N) where N is the total number of elements in all given sets.
 * Annotated return value: array
 */
int SUNION(
	string key
);

/**
 * SUNIONSTORE
 *
 * Add multiple sets and store the resulting set in a key
 *
 * Time complexity: O(N) where N is the total number of elements in all given sets.
 * Annotated return value: integer
 */
int SUNIONSTORE(
	// Redis type: key
	string destination,
	string key
);

/**
 * SWAPDB
 *
 * Swaps two Redis databases
 * Annotated return value: simple-string
 */
int SWAPDB(
	// Redis type: integer
	int index,
	// Redis type: integer
	int index_1
);

/**
 * SYNC
 *
 * Internal command used for replication
 * Annotated return value:
 */
int SYNC();

/**
 * TIME
 *
 * Return the current server time
 *
 * Time complexity: O(1)
 * Annotated return value: array
 */
int TIME();

/**
 * TOUCH
 *
 * Alters the last access time of a key(s). Returns the number of existing keys specified.
 *
 * Time complexity: O(N) where N is the number of keys that will be touched.
 * Annotated return value: integer
 */
int TOUCH(
	string key
);

/**
 * TTL
 *
 * Get the time to live for a key
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int TTL(
	string key
);

/**
 * TYPE
 *
 * Determine the type stored at key
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int TYPE(
	string key
);

/**
 * UNLINK
 *
 * Delete a key asynchronously in another thread. Otherwise it is just as DEL, but non blocking.
 *
 * Time complexity: O(1) for each key removed regardless of its size. Then the command does O(N)
 * work in a different thread in order to reclaim memory, where N is the number
 * of allocations the deleted objects where composed of.
 * Annotated return value: integer
 */
int UNLINK(
	string key
);

/**
 * UNWATCH
 *
 * Forget about all watched keys
 *
 * Time complexity: O(1)
 * Annotated return value: simple-string
 */
int UNWATCH();

/**
 * WAIT
 *
 * Wait for the synchronous replication of all the write commands sent in the context of the current connection
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int WAIT(
	// Redis type: integer
	int numreplicas,
	// Redis type: integer
	int timeout
);

/**
 * WATCH
 *
 * Watch the given keys to determine execution of the MULTI/EXEC block
 *
 * Time complexity: O(1) for every key.
 * Annotated return value: simple-string
 */
int WATCH(
	string key
);

/**
 * ZADD
 *
 * Add one or more members to a sorted set, or update its score if it already exists
 *
 * Time complexity: O(log(N)) for each item added, where N is the number of elements in the
 * sorted set.

 * - Valid values for condition: "NX", "XX"

 * - Valid values for change: "CH"

 * - Valid values for increment: "INCR"
 * Annotated return value: integer
 */
int ZADD(
	string key,
	// Redis type: enum
	string condition = "",
	// Redis type: enum
	string change = "",
	// Redis type: enum
	string increment = "",
	// Redis type: double
	float score = 0.0,
	string member = ""
);

/**
 * ZCARD
 *
 * Get the number of members in a sorted set
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int ZCARD(
	string key
);

/**
 * ZCOUNT
 *
 * Count the members in a sorted set with scores within the given values
 *
 * Time complexity: O(log(N)) with N being the number of elements in the sorted set.
 * Annotated return value: integer
 */
int ZCOUNT(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max
);

/**
 * ZINCRBY
 *
 * Increment the score of a member in a sorted set
 *
 * Time complexity: O(log(N)) where N is the number of elements in the sorted set.
 * Annotated return value: bulk-string
 */
int ZINCRBY(
	string key,
	// Redis type: integer
	int increment,
	string member
);

/**
 * ZINTERSTORE
 *
 * Intersect multiple sorted sets and store the resulting sorted set in a new key
 *
 * Time complexity: O(N*K)+O(M*log(M)) worst case with N being the smallest input sorted set, K
 * being the number of input sorted sets and M being the number of elements in
 * the resulting sorted set.

 * - Valid values for aggregate_aggregate: "SUM", "MIN", "MAX"
 * Annotated return value: integer
 */
int ZINTERSTORE(
	// Redis type: key
	string destination,
	// Redis type: integer
	int numkeys,
	string key,
	// Redis type: integer
	int weights_weight = 0,
	// Redis type: enum
	string aggregate_aggregate = ""
);

/**
 * ZLEXCOUNT
 *
 * Count the number of members in a sorted set between a given lexicographical range
 *
 * Time complexity: O(log(N)) with N being the number of elements in the sorted set.
 * Annotated return value: integer
 */
int ZLEXCOUNT(
	string key,
	string min,
	string max
);

/**
 * ZPOPMAX
 *
 * Remove and return members with the highest scores in a sorted set
 *
 * Time complexity: O(log(N)*M) with N being the number of elements in the sorted set, and M
 * being the number of elements popped.
 * Annotated return value: array
 */
int ZPOPMAX(
	string key,
	// Redis type: integer
	int count = 0
);

/**
 * ZPOPMIN
 *
 * Remove and return members with the lowest scores in a sorted set
 *
 * Time complexity: O(log(N)*M) with N being the number of elements in the sorted set, and M
 * being the number of elements popped.
 * Annotated return value: array
 */
int ZPOPMIN(
	string key,
	// Redis type: integer
	int count = 0
);

/**
 * ZRANGE
 *
 * Return a range of members in a sorted set, by index
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements returned.

 * - Valid values for withscores: "WITHSCORES"
 * Annotated return value: array
 */
int ZRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop,
	// Redis type: enum
	string withscores = ""
);

/**
 * ZRANGEBYLEX
 *
 * Return a range of members in a sorted set, by lexicographical range
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements being returned. If M is constant (e.g. always asking for
 * the first 10 elements with LIMIT), you can consider it O(log(N)).
 * Annotated return value: array
 */
int ZRANGEBYLEX(
	string key,
	string min,
	string max,
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
);

/**
 * ZREVRANGEBYLEX
 *
 * Return a range of members in a sorted set, by lexicographical range, ordered from higher to lower strings.
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements being returned. If M is constant (e.g. always asking for
 * the first 10 elements with LIMIT), you can consider it O(log(N)).
 * Annotated return value: array
 */
int ZREVRANGEBYLEX(
	string key,
	string max,
	string min,
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
);

/**
 * ZRANGEBYSCORE
 *
 * Return a range of members in a sorted set, by score
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements being returned. If M is constant (e.g. always asking for
 * the first 10 elements with LIMIT), you can consider it O(log(N)).

 * - Valid values for withscores: "WITHSCORES"
 * Annotated return value: array
 */
int ZRANGEBYSCORE(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max,
	// Redis type: enum
	string withscores = "",
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
);

/**
 * ZRANK
 *
 * Determine the index of a member in a sorted set
 *
 * Time complexity: O(log(N))
 * Annotated return value: integer
 */
int ZRANK(
	string key,
	string member
);

/**
 * ZREM
 *
 * Remove one or more members from a sorted set
 *
 * Time complexity: O(M*log(N)) with N being the number of elements in the sorted set and M the
 * number of elements to be removed.
 * Annotated return value: integer
 */
int ZREM(
	string key,
	string member
);

/**
 * ZREMRANGEBYLEX
 *
 * Remove all members in a sorted set between the given lexicographical range
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements removed by the operation.
 * Annotated return value: integer
 */
int ZREMRANGEBYLEX(
	string key,
	string min,
	string max
);

/**
 * ZREMRANGEBYRANK
 *
 * Remove all members in a sorted set within the given indexes
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements removed by the operation.
 * Annotated return value: integer
 */
int ZREMRANGEBYRANK(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
);

/**
 * ZREMRANGEBYSCORE
 *
 * Remove all members in a sorted set within the given scores
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements removed by the operation.
 * Annotated return value: integer
 */
int ZREMRANGEBYSCORE(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max
);

/**
 * ZREVRANGE
 *
 * Return a range of members in a sorted set, by index, with scores ordered from high to low
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements returned.

 * - Valid values for withscores: "WITHSCORES"
 * Annotated return value: array
 */
int ZREVRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop,
	// Redis type: enum
	string withscores = ""
);

/**
 * ZREVRANGEBYSCORE
 *
 * Return a range of members in a sorted set, by score, with scores ordered from high to low
 *
 * Time complexity: O(log(N)+M) with N being the number of elements in the sorted set and M the
 * number of elements being returned. If M is constant (e.g. always asking for
 * the first 10 elements with LIMIT), you can consider it O(log(N)).

 * - Valid values for withscores: "WITHSCORES"
 * Annotated return value: array
 */
int ZREVRANGEBYSCORE(
	string key,
	// Redis type: double
	float max,
	// Redis type: double
	float min,
	// Redis type: enum
	string withscores = "",
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
);

/**
 * ZREVRANK
 *
 * Determine the index of a member in a sorted set, with scores ordered from high to low
 *
 * Time complexity: O(log(N))
 * Annotated return value: integer
 */
int ZREVRANK(
	string key,
	string member
);

/**
 * ZSCORE
 *
 * Get the score associated with the given member in a sorted set
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int ZSCORE(
	string key,
	string member
);

/**
 * ZUNIONSTORE
 *
 * Add multiple sorted sets and store the resulting sorted set in a new key
 *
 * Time complexity: O(N)+O(M log(M)) with N being the sum of the sizes of the input sorted sets,
 * and M being the number of elements in the resulting sorted set.

 * - Valid values for aggregate_aggregate: "SUM", "MIN", "MAX"
 * Annotated return value: integer
 */
int ZUNIONSTORE(
	// Redis type: key
	string destination,
	// Redis type: integer
	int numkeys,
	string key,
	// Redis type: integer
	int weights_weight = 0,
	// Redis type: enum
	string aggregate_aggregate = ""
);

/**
 * SCAN
 *
 * Incrementally iterate the keys space
 *
 * Time complexity: O(1) for every call. O(N) for a complete iteration, including enough command
 * calls for the cursor to return back to 0. N is the number of elements inside
 * the collection.
 * Annotated return value:
 */
int SCAN(
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0,
	string type_type = ""
);

/**
 * SSCAN
 *
 * Incrementally iterate Set elements
 *
 * Time complexity: O(1) for every call. O(N) for a complete iteration, including enough command
 * calls for the cursor to return back to 0. N is the number of elements inside
 * the collection..
 * Annotated return value:
 */
int SSCAN(
	string key,
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0
);

/**
 * HSCAN
 *
 * Incrementally iterate hash fields and associated values
 *
 * Time complexity: O(1) for every call. O(N) for a complete iteration, including enough command
 * calls for the cursor to return back to 0. N is the number of elements inside
 * the collection..
 * Annotated return value:
 */
int HSCAN(
	string key,
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0
);

/**
 * ZSCAN
 *
 * Incrementally iterate sorted sets elements and associated scores
 *
 * Time complexity: O(1) for every call. O(N) for a complete iteration, including enough command
 * calls for the cursor to return back to 0. N is the number of elements inside
 * the collection..
 * Annotated return value:
 */
int ZSCAN(
	string key,
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0
);

/**
 * XINFO
 *
 * Get information on streams and consumer groups
 *
 * Time complexity: O(N) with N being the number of returned items for the subcommands CONSUMERS
 * and GROUPS. The STREAM subcommand is O(log N) with N being the number of
 * items in the stream.

 * - Valid values for help: "HELP"
 * Annotated return value:
 */
int XINFO(
	// Redis type: key
	string consumers_key = "",
	string consumers_groupname = "",
	// Redis type: key
	string groups_key = "",
	// Redis type: key
	string stream_key = "",
	// Redis type: enum
	string help = ""
);

/**
 * XADD
 *
 * Appends a new entry to a stream
 *
 * Time complexity: O(1)
 * Annotated return value: bulk-string
 */
int XADD(
	string key,
	string ID,
	// Redis type: value
	string field,
	string str
);

/**
 * XTRIM
 *
 * Trims the stream to (approximately if '~' is passed) a certain size
 *
 * Time complexity: O(N), with N being the number of evicted entries. Constant times are very
 * small however, since entries are organized in macro nodes containing
 * multiple entries that can be released with a single deallocation.

 * - Valid values for strategy: "MAXLEN"

 * - Valid values for approx: "~"
 * Annotated return value: integer
 */
int XTRIM(
	string key,
	// Redis type: enum
	string strategy,
	// Redis type: enum
	string approx = "",
	// Redis type: integer
	int count = 0
);

/**
 * XDEL
 *
 * Removes the specified entries from the stream. Returns the number of items actually deleted, that may be different from the number of IDs passed in case certain IDs do not exist.
 *
 * Time complexity: O(1) for each single item to delete in the stream, regardless of the stream
 * size.
 * Annotated return value: integer
 */
int XDEL(
	string key,
	string ID
);

/**
 * XRANGE
 *
 * Return a range of elements in a stream, with IDs matching the specified IDs interval
 *
 * Time complexity: O(N) with N being the number of elements being returned. If N is constant
 * (e.g. always asking for the first 10 elements with COUNT), you can consider
 * it O(1).
 * Annotated return value: array
 */
int XRANGE(
	string key,
	string start,
	string end,
	// Redis type: integer
	int count_count = 0
);

/**
 * XREVRANGE
 *
 * Return a range of elements in a stream, with IDs matching the specified IDs interval, in reverse order (from greater to smaller IDs) compared to XRANGE
 *
 * Time complexity: O(N) with N being the number of elements returned. If N is constant (e.g.
 * always asking for the first 10 elements with COUNT), you can consider it
 * O(1).
 * Annotated return value: array
 */
int XREVRANGE(
	string key,
	string end,
	string start,
	// Redis type: integer
	int count_count = 0
);

/**
 * XLEN
 *
 * Return the number of entires in a stream
 *
 * Time complexity: O(1)
 * Annotated return value: integer
 */
int XLEN(
	string key
);

/**
 * XREAD
 *
 * Return never seen elements in multiple streams, with IDs greater than the ones reported by the caller for each stream. Can block.
 *
 * Time complexity: For each stream mentioned: O(N) with N being the number of elements being
 * returned, it menas that XREAD-ing with a fixed COUNT is O(1). Note that when
 * the BLOCK option is used, XADD will pay O(M) time in order to serve the M
 * clients blocked on the stream getting new data.

 * - Valid values for streams: "STREAMS"
 * Annotated return value: array
 */
int XREAD(
	// Redis type: integer
	int count_count = 0,
	// Redis type: integer
	int block_milliseconds = 0,
	// Redis type: enum
	string streams = "",
	string key = "",
	string ID = ""
);

/**
 * XGROUP
 *
 * Create, destroy, and manage consumer groups.
 *
 * Time complexity: O(1) for all the subcommands, with the exception of the DESTROY subcommand
 * which takes an additional O(M) time in order to delete the M entries inside
 * the consumer group pending entries list (PEL).
 * Annotated return value:
 */
int XGROUP(
	// Redis type: key
	string create_key = "",
	string create_groupname = "",
	string create_id_or__ = "",
	// Redis type: key
	string setid_key = "",
	string setid_groupname = "",
	string setid_id_or__ = "",
	// Redis type: key
	string destroy_key = "",
	string destroy_groupname = "",
	// Redis type: key
	string delconsumer_key = "",
	string delconsumer_groupname = "",
	string delconsumer_consumername = ""
);

/**
 * XREADGROUP
 *
 * Return new entries from a stream using a consumer group, or access the history of the pending entries for a given consumer. Can block.
 *
 * Time complexity: For each stream mentioned: O(M) with M being the number of elements
 * returned. If M is constant (e.g. always asking for the first 10 elements
 * with COUNT), you can consider it O(1). On the other side when XREADGROUP
 * blocks, XADD will pay the O(N) time in order to serve the N clients blocked
 * on the stream getting new data.

 * - Valid values for noack: "NOACK"

 * - Valid values for streams: "STREAMS"
 * Annotated return value:
 */
int XREADGROUP(
	string group_group,
	string group_consumer,
	// Redis type: integer
	int count_count = 0,
	// Redis type: integer
	int block_milliseconds = 0,
	// Redis type: enum
	string noack = "",
	// Redis type: enum
	string streams = "",
	string key = "",
	string ID = ""
);

/**
 * XACK
 *
 * Marks a pending message as correctly processed, effectively removing it from the pending entries list of the consumer group. Return value of the command is the number of messages successfully acknowledged, that is, the IDs we were actually able to resolve in the PEL.
 *
 * Time complexity: O(1) for each message ID processed.
 * Annotated return value: integer
 */
int XACK(
	string key,
	string group,
	string ID
);

/**
 * XCLAIM
 *
 * Changes (or acquires) ownership of a message in a consumer group, as if the message was delivered to the specified consumer.
 *
 * Time complexity: O(log N) with N being the number of messages in the PEL of the consumer
 * group.
 * Annotated return value: array
 */
int XCLAIM(
	string key,
	string group,
	string consumer,
	string min_idle_time,
	string ID,
	// Redis type: integer
	int idle_ms = 0,
	// Redis type: integer
	int time_ms_unix_time = 0,
	// Redis type: integer
	int retrycount_count = 0
);

/**
 * XPENDING
 *
 * Return information and entries from a stream consumer group pending entries list, that are messages fetched but never acknowledged.
 *
 * Time complexity: O(N) with N being the number of elements returned, so asking for a small
 * fixed number of entries per call is O(1). When the command returns just the
 * summary it runs in O(1) time assuming the list of consumers is small,
 * otherwise there is additional O(N) time needed to iterate every consumer.
 * Annotated return value: array
 */
int XPENDING(
	string key,
	string group,
	string start = "",
	string end = "",
	// Redis type: integer
	int count = 0,
	string consumer = ""
);



// Implementation below
int APPEND(
	string key,
	string value
) {
  NWNXPushString("APPEND");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int AUTH(
	string password
) {
  NWNXPushString("AUTH");
  NWNXPushString(password);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BGREWRITEAOF() {
  NWNXPushString("BGREWRITEAOF");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BGSAVE() {
  NWNXPushString("BGSAVE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BITCOUNT(
	string key,
	// Redis type: integer
	int start = 0,
	// Redis type: integer
	int end = 0
) {
  NWNXPushString("BITCOUNT");
  NWNXPushString(key);
  if (start != 0) NWNXPushString(IntToString(start));
  if (end != 0) NWNXPushString(IntToString(end));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BITFIELD(
	string key,
	// Redis type: type
	string get_type = "",
	// Redis type: integer
	int get_offset = 0,
	// Redis type: type
	string set_type = "",
	// Redis type: integer
	int set_offset = 0,
	// Redis type: integer
	int set_value = 0,
	// Redis type: type
	string incrby_type = "",
	// Redis type: integer
	int incrby_offset = 0,
	// Redis type: integer
	int incrby_increment = 0
) {
  NWNXPushString("BITFIELD");
  NWNXPushString(key);
  if (get_type != "") NWNXPushString(get_type);
  if (get_offset != 0) NWNXPushString(IntToString(get_offset));
  if (set_type != "") NWNXPushString(set_type);
  if (set_offset != 0) NWNXPushString(IntToString(set_offset));
  if (set_value != 0) NWNXPushString(IntToString(set_value));
  if (incrby_type != "") NWNXPushString(incrby_type);
  if (incrby_offset != 0) NWNXPushString(IntToString(incrby_offset));
  if (incrby_increment != 0) NWNXPushString(IntToString(incrby_increment));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BITOP(
	string operation,
	// Redis type: key
	string destkey,
	string key
) {
  NWNXPushString("BITOP");
  NWNXPushString(operation);
  NWNXPushString(destkey);
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BITPOS(
	string key,
	// Redis type: integer
	int bit,
	// Redis type: integer
	int start = 0,
	// Redis type: integer
	int end = 0
) {
  NWNXPushString("BITPOS");
  NWNXPushString(key);
  NWNXPushString(IntToString(bit));
  if (start != 0) NWNXPushString(IntToString(start));
  if (end != 0) NWNXPushString(IntToString(end));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BLPOP(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNXPushString("BLPOP");
  NWNXPushString(key);
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BRPOP(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNXPushString("BRPOP");
  NWNXPushString(key);
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BRPOPLPUSH(
	// Redis type: key
	string source,
	// Redis type: key
	string destination,
	// Redis type: integer
	int timeout
) {
  NWNXPushString("BRPOPLPUSH");
  NWNXPushString(source);
  NWNXPushString(destination);
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BZPOPMIN(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNXPushString("BZPOPMIN");
  NWNXPushString(key);
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int BZPOPMAX(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNXPushString("BZPOPMAX");
  NWNXPushString(key);
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_ID() {
  NWNXPushString("CLIENT_ID");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_KILL(
	string ip_port = "",
	// Redis type: integer
	int id_client_id = 0,
	string addr_ip_port = "",
	string skipme_yes_no = ""
) {
  NWNXPushString("CLIENT_KILL");
  if (ip_port != "") NWNXPushString(ip_port);
  if (id_client_id != 0) NWNXPushString(IntToString(id_client_id));
  if (addr_ip_port != "") NWNXPushString(addr_ip_port);
  if (skipme_yes_no != "") NWNXPushString(skipme_yes_no);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_LIST() {
  NWNXPushString("CLIENT_LIST");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_GETNAME() {
  NWNXPushString("CLIENT_GETNAME");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_PAUSE(
	// Redis type: integer
	int timeout
) {
  NWNXPushString("CLIENT_PAUSE");
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_REPLY(
	// Redis type: enum
	string reply_mode
) {
  NWNXPushString("CLIENT_REPLY");
  NWNXPushString(reply_mode);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_SETNAME(
	string connection_name
) {
  NWNXPushString("CLIENT_SETNAME");
  NWNXPushString(connection_name);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLIENT_UNBLOCK(
	string client_id,
	// Redis type: enum
	string unblock_type = ""
) {
  NWNXPushString("CLIENT_UNBLOCK");
  NWNXPushString(client_id);
  if (unblock_type != "") NWNXPushString(unblock_type);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_ADDSLOTS(
	// Redis type: integer
	int slot
) {
  NWNXPushString("CLUSTER_ADDSLOTS");
  NWNXPushString(IntToString(slot));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_COUNT_FAILURE_REPORTS(
	string node_id
) {
  NWNXPushString("CLUSTER_COUNT_FAILURE_REPORTS");
  NWNXPushString(node_id);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_COUNTKEYSINSLOT(
	// Redis type: integer
	int slot
) {
  NWNXPushString("CLUSTER_COUNTKEYSINSLOT");
  NWNXPushString(IntToString(slot));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_DELSLOTS(
	// Redis type: integer
	int slot
) {
  NWNXPushString("CLUSTER_DELSLOTS");
  NWNXPushString(IntToString(slot));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_FAILOVER(
	// Redis type: enum
	string options = ""
) {
  NWNXPushString("CLUSTER_FAILOVER");
  if (options != "") NWNXPushString(options);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_FORGET(
	string node_id
) {
  NWNXPushString("CLUSTER_FORGET");
  NWNXPushString(node_id);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_GETKEYSINSLOT(
	// Redis type: integer
	int slot,
	// Redis type: integer
	int count
) {
  NWNXPushString("CLUSTER_GETKEYSINSLOT");
  NWNXPushString(IntToString(slot));
  NWNXPushString(IntToString(count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_INFO() {
  NWNXPushString("CLUSTER_INFO");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_KEYSLOT(
	string key
) {
  NWNXPushString("CLUSTER_KEYSLOT");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_MEET(
	string ip,
	// Redis type: integer
	int port
) {
  NWNXPushString("CLUSTER_MEET");
  NWNXPushString(ip);
  NWNXPushString(IntToString(port));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_NODES() {
  NWNXPushString("CLUSTER_NODES");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_REPLICATE(
	string node_id
) {
  NWNXPushString("CLUSTER_REPLICATE");
  NWNXPushString(node_id);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_RESET(
	// Redis type: enum
	string reset_type = ""
) {
  NWNXPushString("CLUSTER_RESET");
  if (reset_type != "") NWNXPushString(reset_type);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_SAVECONFIG() {
  NWNXPushString("CLUSTER_SAVECONFIG");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_SET_CONFIG_EPOCH(
	// Redis type: integer
	int config_epoch
) {
  NWNXPushString("CLUSTER_SET_CONFIG_EPOCH");
  NWNXPushString(IntToString(config_epoch));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_SETSLOT(
	// Redis type: integer
	int slot,
	// Redis type: enum
	string subcommand,
	string node_id = ""
) {
  NWNXPushString("CLUSTER_SETSLOT");
  NWNXPushString(IntToString(slot));
  NWNXPushString(subcommand);
  if (node_id != "") NWNXPushString(node_id);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_SLAVES(
	string node_id
) {
  NWNXPushString("CLUSTER_SLAVES");
  NWNXPushString(node_id);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_REPLICAS(
	string node_id
) {
  NWNXPushString("CLUSTER_REPLICAS");
  NWNXPushString(node_id);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CLUSTER_SLOTS() {
  NWNXPushString("CLUSTER_SLOTS");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int COMMAND() {
  NWNXPushString("COMMAND");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int COMMAND_COUNT() {
  NWNXPushString("COMMAND_COUNT");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int COMMAND_GETKEYS() {
  NWNXPushString("COMMAND_GETKEYS");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int COMMAND_INFO(
	string command_name
) {
  NWNXPushString("COMMAND_INFO");
  NWNXPushString(command_name);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CONFIG_GET(
	string parameter
) {
  NWNXPushString("CONFIG_GET");
  NWNXPushString(parameter);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CONFIG_REWRITE() {
  NWNXPushString("CONFIG_REWRITE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CONFIG_SET(
	string parameter,
	string value
) {
  NWNXPushString("CONFIG_SET");
  NWNXPushString(parameter);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int CONFIG_RESETSTAT() {
  NWNXPushString("CONFIG_RESETSTAT");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DBSIZE() {
  NWNXPushString("DBSIZE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DEBUG_OBJECT(
	string key
) {
  NWNXPushString("DEBUG_OBJECT");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DEBUG_SEGFAULT() {
  NWNXPushString("DEBUG_SEGFAULT");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DECR(
	string key
) {
  NWNXPushString("DECR");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DECRBY(
	string key,
	// Redis type: integer
	int decrement
) {
  NWNXPushString("DECRBY");
  NWNXPushString(key);
  NWNXPushString(IntToString(decrement));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DEL(
	string key
) {
  NWNXPushString("DEL");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DISCARD() {
  NWNXPushString("DISCARD");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int DUMP(
	string key
) {
  NWNXPushString("DUMP");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ECHO(
	string message
) {
  NWNXPushString("ECHO");
  NWNXPushString(message);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int EVAL(
	string script,
	// Redis type: integer
	int numkeys,
	string key,
	string arg
) {
  NWNXPushString("EVAL");
  NWNXPushString(script);
  NWNXPushString(IntToString(numkeys));
  NWNXPushString(key);
  NWNXPushString(arg);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int EVALSHA(
	string sha1,
	// Redis type: integer
	int numkeys,
	string key,
	string arg
) {
  NWNXPushString("EVALSHA");
  NWNXPushString(sha1);
  NWNXPushString(IntToString(numkeys));
  NWNXPushString(key);
  NWNXPushString(arg);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int EXEC() {
  NWNXPushString("EXEC");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int EXISTS(
	string key
) {
  NWNXPushString("EXISTS");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int EXPIRE(
	string key,
	// Redis type: integer
	int seconds
) {
  NWNXPushString("EXPIRE");
  NWNXPushString(key);
  NWNXPushString(IntToString(seconds));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int EXPIREAT(
	string key,
	// Redis type: posix time
	string timestamp
) {
  NWNXPushString("EXPIREAT");
  NWNXPushString(key);
  NWNXPushString(timestamp);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int FLUSHALL(
	// Redis type: enum
	string async = ""
) {
  NWNXPushString("FLUSHALL");
  if (async != "") NWNXPushString(async);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int FLUSHDB(
	// Redis type: enum
	string async = ""
) {
  NWNXPushString("FLUSHDB");
  if (async != "") NWNXPushString(async);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GEOADD(
	string key,
	// Redis type: double
	float longitude,
	// Redis type: double
	float latitude,
	string member
) {
  NWNXPushString("GEOADD");
  NWNXPushString(key);
  NWNXPushString(FloatToString(longitude, 0));
  NWNXPushString(FloatToString(latitude, 0));
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GEOHASH(
	string key,
	string member
) {
  NWNXPushString("GEOHASH");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GEOPOS(
	string key,
	string member
) {
  NWNXPushString("GEOPOS");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GEODIST(
	string key,
	string member1,
	string member2,
	string unit = ""
) {
  NWNXPushString("GEODIST");
  NWNXPushString(key);
  NWNXPushString(member1);
  NWNXPushString(member2);
  if (unit != "") NWNXPushString(unit);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GEORADIUS(
	string key,
	// Redis type: double
	float longitude,
	// Redis type: double
	float latitude,
	// Redis type: double
	float radius,
	// Redis type: enum
	string unit,
	// Redis type: enum
	string withcoord = "",
	// Redis type: enum
	string withdist = "",
	// Redis type: enum
	string withhash = "",
	// Redis type: integer
	int count_count = 0,
	// Redis type: enum
	string order = "",
	// Redis type: key
	string store_key = "",
	// Redis type: key
	string storedist_key = ""
) {
  NWNXPushString("GEORADIUS");
  NWNXPushString(key);
  NWNXPushString(FloatToString(longitude, 0));
  NWNXPushString(FloatToString(latitude, 0));
  NWNXPushString(FloatToString(radius, 0));
  NWNXPushString(unit);
  if (withcoord != "") NWNXPushString(withcoord);
  if (withdist != "") NWNXPushString(withdist);
  if (withhash != "") NWNXPushString(withhash);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  if (order != "") NWNXPushString(order);
  if (store_key != "") NWNXPushString(store_key);
  if (storedist_key != "") NWNXPushString(storedist_key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GEORADIUSBYMEMBER(
	string key,
	string member,
	// Redis type: double
	float radius,
	// Redis type: enum
	string unit,
	// Redis type: enum
	string withcoord = "",
	// Redis type: enum
	string withdist = "",
	// Redis type: enum
	string withhash = "",
	// Redis type: integer
	int count_count = 0,
	// Redis type: enum
	string order = "",
	// Redis type: key
	string store_key = "",
	// Redis type: key
	string storedist_key = ""
) {
  NWNXPushString("GEORADIUSBYMEMBER");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXPushString(FloatToString(radius, 0));
  NWNXPushString(unit);
  if (withcoord != "") NWNXPushString(withcoord);
  if (withdist != "") NWNXPushString(withdist);
  if (withhash != "") NWNXPushString(withhash);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  if (order != "") NWNXPushString(order);
  if (store_key != "") NWNXPushString(store_key);
  if (storedist_key != "") NWNXPushString(storedist_key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GET(
	string key
) {
  NWNXPushString("GET");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GETBIT(
	string key,
	// Redis type: integer
	int offset
) {
  NWNXPushString("GETBIT");
  NWNXPushString(key);
  NWNXPushString(IntToString(offset));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GETRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int end
) {
  NWNXPushString("GETRANGE");
  NWNXPushString(key);
  NWNXPushString(IntToString(start));
  NWNXPushString(IntToString(end));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int GETSET(
	string key,
	string value
) {
  NWNXPushString("GETSET");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HDEL(
	string key,
	string field
) {
  NWNXPushString("HDEL");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HEXISTS(
	string key,
	string field
) {
  NWNXPushString("HEXISTS");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HGET(
	string key,
	string field
) {
  NWNXPushString("HGET");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HGETALL(
	string key
) {
  NWNXPushString("HGETALL");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HINCRBY(
	string key,
	string field,
	// Redis type: integer
	int increment
) {
  NWNXPushString("HINCRBY");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXPushString(IntToString(increment));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HINCRBYFLOAT(
	string key,
	string field,
	// Redis type: double
	float increment
) {
  NWNXPushString("HINCRBYFLOAT");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXPushString(FloatToString(increment, 0));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HKEYS(
	string key
) {
  NWNXPushString("HKEYS");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HLEN(
	string key
) {
  NWNXPushString("HLEN");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HMGET(
	string key,
	string field
) {
  NWNXPushString("HMGET");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HMSET(
	string key,
	string field,
	string value
) {
  NWNXPushString("HMSET");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HSET(
	string key,
	string field,
	string value
) {
  NWNXPushString("HSET");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HSETNX(
	string key,
	string field,
	string value
) {
  NWNXPushString("HSETNX");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HSTRLEN(
	string key,
	string field
) {
  NWNXPushString("HSTRLEN");
  NWNXPushString(key);
  NWNXPushString(field);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HVALS(
	string key
) {
  NWNXPushString("HVALS");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int INCR(
	string key
) {
  NWNXPushString("INCR");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int INCRBY(
	string key,
	// Redis type: integer
	int increment
) {
  NWNXPushString("INCRBY");
  NWNXPushString(key);
  NWNXPushString(IntToString(increment));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int INCRBYFLOAT(
	string key,
	// Redis type: double
	float increment
) {
  NWNXPushString("INCRBYFLOAT");
  NWNXPushString(key);
  NWNXPushString(FloatToString(increment, 0));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int INFO(
	string section = ""
) {
  NWNXPushString("INFO");
  if (section != "") NWNXPushString(section);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int KEYS(
	string pattern
) {
  NWNXPushString("KEYS");
  NWNXPushString(pattern);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LASTSAVE() {
  NWNXPushString("LASTSAVE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LINDEX(
	string key,
	// Redis type: integer
	int index
) {
  NWNXPushString("LINDEX");
  NWNXPushString(key);
  NWNXPushString(IntToString(index));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LINSERT(
	string key,
	// Redis type: enum
	string where,
	string pivot,
	string value
) {
  NWNXPushString("LINSERT");
  NWNXPushString(key);
  NWNXPushString(where);
  NWNXPushString(pivot);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LLEN(
	string key
) {
  NWNXPushString("LLEN");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LPOP(
	string key
) {
  NWNXPushString("LPOP");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LPUSH(
	string key,
	string value
) {
  NWNXPushString("LPUSH");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LPUSHX(
	string key,
	string value
) {
  NWNXPushString("LPUSHX");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
) {
  NWNXPushString("LRANGE");
  NWNXPushString(key);
  NWNXPushString(IntToString(start));
  NWNXPushString(IntToString(stop));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LREM(
	string key,
	// Redis type: integer
	int count,
	string value
) {
  NWNXPushString("LREM");
  NWNXPushString(key);
  NWNXPushString(IntToString(count));
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LSET(
	string key,
	// Redis type: integer
	int index,
	string value
) {
  NWNXPushString("LSET");
  NWNXPushString(key);
  NWNXPushString(IntToString(index));
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int LTRIM(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
) {
  NWNXPushString("LTRIM");
  NWNXPushString(key);
  NWNXPushString(IntToString(start));
  NWNXPushString(IntToString(stop));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MEMORY_DOCTOR() {
  NWNXPushString("MEMORY_DOCTOR");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MEMORY_HELP() {
  NWNXPushString("MEMORY_HELP");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MEMORY_MALLOC_STATS() {
  NWNXPushString("MEMORY_MALLOC_STATS");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MEMORY_PURGE() {
  NWNXPushString("MEMORY_PURGE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MEMORY_STATS() {
  NWNXPushString("MEMORY_STATS");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MEMORY_USAGE(
	string key,
	// Redis type: integer
	int samples_count = 0
) {
  NWNXPushString("MEMORY_USAGE");
  NWNXPushString(key);
  if (samples_count != 0) NWNXPushString(IntToString(samples_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MGET(
	string key
) {
  NWNXPushString("MGET");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MIGRATE(
	string host,
	string port,
	// Redis type: enum
	string key,
	// Redis type: integer
	int destination_db,
	// Redis type: integer
	int timeout,
	// Redis type: enum
	string copy = "",
	// Redis type: enum
	string replace = "",
	string auth_password = "",
	// Redis type: key
	string keys_key = ""
) {
  NWNXPushString("MIGRATE");
  NWNXPushString(host);
  NWNXPushString(port);
  NWNXPushString(key);
  NWNXPushString(IntToString(destination_db));
  NWNXPushString(IntToString(timeout));
  if (copy != "") NWNXPushString(copy);
  if (replace != "") NWNXPushString(replace);
  if (auth_password != "") NWNXPushString(auth_password);
  if (keys_key != "") NWNXPushString(keys_key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MONITOR() {
  NWNXPushString("MONITOR");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MOVE(
	string key,
	// Redis type: integer
	int db
) {
  NWNXPushString("MOVE");
  NWNXPushString(key);
  NWNXPushString(IntToString(db));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MSET(
	string key,
	string value
) {
  NWNXPushString("MSET");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MSETNX(
	string key,
	string value
) {
  NWNXPushString("MSETNX");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int MULTI() {
  NWNXPushString("MULTI");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int OBJECT(
	string subcommand,
	string arguments = ""
) {
  NWNXPushString("OBJECT");
  NWNXPushString(subcommand);
  if (arguments != "") NWNXPushString(arguments);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PERSIST(
	string key
) {
  NWNXPushString("PERSIST");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PEXPIRE(
	string key,
	// Redis type: integer
	int milliseconds
) {
  NWNXPushString("PEXPIRE");
  NWNXPushString(key);
  NWNXPushString(IntToString(milliseconds));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PEXPIREAT(
	string key,
	// Redis type: posix time
	string milliseconds_timestamp
) {
  NWNXPushString("PEXPIREAT");
  NWNXPushString(key);
  NWNXPushString(milliseconds_timestamp);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PFADD(
	string key,
	string element
) {
  NWNXPushString("PFADD");
  NWNXPushString(key);
  NWNXPushString(element);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PFCOUNT(
	string key
) {
  NWNXPushString("PFCOUNT");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PFMERGE(
	// Redis type: key
	string destkey,
	// Redis type: key
	string sourcekey
) {
  NWNXPushString("PFMERGE");
  NWNXPushString(destkey);
  NWNXPushString(sourcekey);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PING(
	string message = ""
) {
  NWNXPushString("PING");
  if (message != "") NWNXPushString(message);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PSETEX(
	string key,
	// Redis type: integer
	int milliseconds,
	string value
) {
  NWNXPushString("PSETEX");
  NWNXPushString(key);
  NWNXPushString(IntToString(milliseconds));
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PUBSUB(
	string subcommand,
	string argument = ""
) {
  NWNXPushString("PUBSUB");
  NWNXPushString(subcommand);
  if (argument != "") NWNXPushString(argument);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PTTL(
	string key
) {
  NWNXPushString("PTTL");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int PUBLISH(
	string channel,
	string message
) {
  NWNXPushString("PUBLISH");
  NWNXPushString(channel);
  NWNXPushString(message);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int QUIT() {
  NWNXPushString("QUIT");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RANDOMKEY() {
  NWNXPushString("RANDOMKEY");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int READONLY() {
  NWNXPushString("READONLY");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int READWRITE() {
  NWNXPushString("READWRITE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RENAME(
	string key,
	// Redis type: key
	string newkey
) {
  NWNXPushString("RENAME");
  NWNXPushString(key);
  NWNXPushString(newkey);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RENAMENX(
	string key,
	// Redis type: key
	string newkey
) {
  NWNXPushString("RENAMENX");
  NWNXPushString(key);
  NWNXPushString(newkey);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RESTORE(
	string key,
	// Redis type: integer
	int ttl,
	string serialized_value,
	// Redis type: enum
	string replace = "",
	// Redis type: enum
	string absttl = "",
	// Redis type: integer
	int idletime_seconds = 0,
	// Redis type: integer
	int freq_frequency = 0
) {
  NWNXPushString("RESTORE");
  NWNXPushString(key);
  NWNXPushString(IntToString(ttl));
  NWNXPushString(serialized_value);
  if (replace != "") NWNXPushString(replace);
  if (absttl != "") NWNXPushString(absttl);
  if (idletime_seconds != 0) NWNXPushString(IntToString(idletime_seconds));
  if (freq_frequency != 0) NWNXPushString(IntToString(freq_frequency));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ROLE() {
  NWNXPushString("ROLE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RPOP(
	string key
) {
  NWNXPushString("RPOP");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RPOPLPUSH(
	// Redis type: key
	string source,
	// Redis type: key
	string destination
) {
  NWNXPushString("RPOPLPUSH");
  NWNXPushString(source);
  NWNXPushString(destination);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RPUSH(
	string key,
	string value
) {
  NWNXPushString("RPUSH");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int RPUSHX(
	string key,
	string value
) {
  NWNXPushString("RPUSHX");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SADD(
	string key,
	string member
) {
  NWNXPushString("SADD");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SAVE() {
  NWNXPushString("SAVE");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCARD(
	string key
) {
  NWNXPushString("SCARD");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCRIPT_DEBUG(
	// Redis type: enum
	string mode
) {
  NWNXPushString("SCRIPT_DEBUG");
  NWNXPushString(mode);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCRIPT_EXISTS(
	string sha1
) {
  NWNXPushString("SCRIPT_EXISTS");
  NWNXPushString(sha1);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCRIPT_FLUSH() {
  NWNXPushString("SCRIPT_FLUSH");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCRIPT_KILL() {
  NWNXPushString("SCRIPT_KILL");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCRIPT_LOAD(
	string script
) {
  NWNXPushString("SCRIPT_LOAD");
  NWNXPushString(script);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SDIFF(
	string key
) {
  NWNXPushString("SDIFF");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SDIFFSTORE(
	// Redis type: key
	string destination,
	string key
) {
  NWNXPushString("SDIFFSTORE");
  NWNXPushString(destination);
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SELECT(
	// Redis type: integer
	int index
) {
  NWNXPushString("SELECT");
  NWNXPushString(IntToString(index));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SET(
	string key,
	string value,
	// Redis type: enum
	string condition = ""
) {
  NWNXPushString("SET");
  NWNXPushString(key);
  NWNXPushString(value);
  if (condition != "") NWNXPushString(condition);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SETBIT(
	string key,
	// Redis type: integer
	int offset,
	string value
) {
  NWNXPushString("SETBIT");
  NWNXPushString(key);
  NWNXPushString(IntToString(offset));
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SETEX(
	string key,
	// Redis type: integer
	int seconds,
	string value
) {
  NWNXPushString("SETEX");
  NWNXPushString(key);
  NWNXPushString(IntToString(seconds));
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SETNX(
	string key,
	string value
) {
  NWNXPushString("SETNX");
  NWNXPushString(key);
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SETRANGE(
	string key,
	// Redis type: integer
	int offset,
	string value
) {
  NWNXPushString("SETRANGE");
  NWNXPushString(key);
  NWNXPushString(IntToString(offset));
  NWNXPushString(value);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SHUTDOWN(
	// Redis type: enum
	string save_mode = ""
) {
  NWNXPushString("SHUTDOWN");
  if (save_mode != "") NWNXPushString(save_mode);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SINTER(
	string key
) {
  NWNXPushString("SINTER");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SINTERSTORE(
	// Redis type: key
	string destination,
	string key
) {
  NWNXPushString("SINTERSTORE");
  NWNXPushString(destination);
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SISMEMBER(
	string key,
	string member
) {
  NWNXPushString("SISMEMBER");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SLAVEOF(
	string host,
	string port
) {
  NWNXPushString("SLAVEOF");
  NWNXPushString(host);
  NWNXPushString(port);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int REPLICAOF(
	string host,
	string port
) {
  NWNXPushString("REPLICAOF");
  NWNXPushString(host);
  NWNXPushString(port);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SLOWLOG(
	string subcommand,
	string argument = ""
) {
  NWNXPushString("SLOWLOG");
  NWNXPushString(subcommand);
  if (argument != "") NWNXPushString(argument);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SMEMBERS(
	string key
) {
  NWNXPushString("SMEMBERS");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SMOVE(
	// Redis type: key
	string source,
	// Redis type: key
	string destination,
	string member
) {
  NWNXPushString("SMOVE");
  NWNXPushString(source);
  NWNXPushString(destination);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SORT(
	string key,
	// Redis type: pattern
	string by_pattern = "",
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0,
	string get_pattern = "",
	// Redis type: enum
	string order = "",
	// Redis type: enum
	string sorting = "",
	// Redis type: key
	string store_destination = ""
) {
  NWNXPushString("SORT");
  NWNXPushString(key);
  if (by_pattern != "") NWNXPushString(by_pattern);
  if (limit_offset != 0) NWNXPushString(IntToString(limit_offset));
  if (limit_count != 0) NWNXPushString(IntToString(limit_count));
  if (get_pattern != "") NWNXPushString(get_pattern);
  if (order != "") NWNXPushString(order);
  if (sorting != "") NWNXPushString(sorting);
  if (store_destination != "") NWNXPushString(store_destination);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SPOP(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNXPushString("SPOP");
  NWNXPushString(key);
  if (count != 0) NWNXPushString(IntToString(count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SRANDMEMBER(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNXPushString("SRANDMEMBER");
  NWNXPushString(key);
  if (count != 0) NWNXPushString(IntToString(count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SREM(
	string key,
	string member
) {
  NWNXPushString("SREM");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int STRLEN(
	string key
) {
  NWNXPushString("STRLEN");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SUNION(
	string key
) {
  NWNXPushString("SUNION");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SUNIONSTORE(
	// Redis type: key
	string destination,
	string key
) {
  NWNXPushString("SUNIONSTORE");
  NWNXPushString(destination);
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SWAPDB(
	// Redis type: integer
	int index,
	// Redis type: integer
	int index_1
) {
  NWNXPushString("SWAPDB");
  NWNXPushString(IntToString(index));
  NWNXPushString(IntToString(index_1));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SYNC() {
  NWNXPushString("SYNC");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int TIME() {
  NWNXPushString("TIME");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int TOUCH(
	string key
) {
  NWNXPushString("TOUCH");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int TTL(
	string key
) {
  NWNXPushString("TTL");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int TYPE(
	string key
) {
  NWNXPushString("TYPE");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int UNLINK(
	string key
) {
  NWNXPushString("UNLINK");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int UNWATCH() {
  NWNXPushString("UNWATCH");
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int WAIT(
	// Redis type: integer
	int numreplicas,
	// Redis type: integer
	int timeout
) {
  NWNXPushString("WAIT");
  NWNXPushString(IntToString(numreplicas));
  NWNXPushString(IntToString(timeout));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int WATCH(
	string key
) {
  NWNXPushString("WATCH");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZADD(
	string key,
	// Redis type: enum
	string condition = "",
	// Redis type: enum
	string change = "",
	// Redis type: enum
	string increment = "",
	// Redis type: double
	float score = 0.0,
	string member = ""
) {
  NWNXPushString("ZADD");
  NWNXPushString(key);
  if (condition != "") NWNXPushString(condition);
  if (change != "") NWNXPushString(change);
  if (increment != "") NWNXPushString(increment);
  NWNXPushString(FloatToString(score, 0));
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZCARD(
	string key
) {
  NWNXPushString("ZCARD");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZCOUNT(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max
) {
  NWNXPushString("ZCOUNT");
  NWNXPushString(key);
  NWNXPushString(FloatToString(min, 0));
  NWNXPushString(FloatToString(max, 0));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZINCRBY(
	string key,
	// Redis type: integer
	int increment,
	string member
) {
  NWNXPushString("ZINCRBY");
  NWNXPushString(key);
  NWNXPushString(IntToString(increment));
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZINTERSTORE(
	// Redis type: key
	string destination,
	// Redis type: integer
	int numkeys,
	string key,
	// Redis type: integer
	int weights_weight = 0,
	// Redis type: enum
	string aggregate_aggregate = ""
) {
  NWNXPushString("ZINTERSTORE");
  NWNXPushString(destination);
  NWNXPushString(IntToString(numkeys));
  NWNXPushString(key);
  if (weights_weight != 0) NWNXPushString(IntToString(weights_weight));
  if (aggregate_aggregate != "") NWNXPushString(aggregate_aggregate);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZLEXCOUNT(
	string key,
	string min,
	string max
) {
  NWNXPushString("ZLEXCOUNT");
  NWNXPushString(key);
  NWNXPushString(min);
  NWNXPushString(max);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZPOPMAX(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNXPushString("ZPOPMAX");
  NWNXPushString(key);
  if (count != 0) NWNXPushString(IntToString(count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZPOPMIN(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNXPushString("ZPOPMIN");
  NWNXPushString(key);
  if (count != 0) NWNXPushString(IntToString(count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop,
	// Redis type: enum
	string withscores = ""
) {
  NWNXPushString("ZRANGE");
  NWNXPushString(key);
  NWNXPushString(IntToString(start));
  NWNXPushString(IntToString(stop));
  if (withscores != "") NWNXPushString(withscores);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZRANGEBYLEX(
	string key,
	string min,
	string max,
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
) {
  NWNXPushString("ZRANGEBYLEX");
  NWNXPushString(key);
  NWNXPushString(min);
  NWNXPushString(max);
  if (limit_offset != 0) NWNXPushString(IntToString(limit_offset));
  if (limit_count != 0) NWNXPushString(IntToString(limit_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREVRANGEBYLEX(
	string key,
	string max,
	string min,
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
) {
  NWNXPushString("ZREVRANGEBYLEX");
  NWNXPushString(key);
  NWNXPushString(max);
  NWNXPushString(min);
  if (limit_offset != 0) NWNXPushString(IntToString(limit_offset));
  if (limit_count != 0) NWNXPushString(IntToString(limit_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZRANGEBYSCORE(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max,
	// Redis type: enum
	string withscores = "",
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
) {
  NWNXPushString("ZRANGEBYSCORE");
  NWNXPushString(key);
  NWNXPushString(FloatToString(min, 0));
  NWNXPushString(FloatToString(max, 0));
  if (withscores != "") NWNXPushString(withscores);
  if (limit_offset != 0) NWNXPushString(IntToString(limit_offset));
  if (limit_count != 0) NWNXPushString(IntToString(limit_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZRANK(
	string key,
	string member
) {
  NWNXPushString("ZRANK");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREM(
	string key,
	string member
) {
  NWNXPushString("ZREM");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREMRANGEBYLEX(
	string key,
	string min,
	string max
) {
  NWNXPushString("ZREMRANGEBYLEX");
  NWNXPushString(key);
  NWNXPushString(min);
  NWNXPushString(max);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREMRANGEBYRANK(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
) {
  NWNXPushString("ZREMRANGEBYRANK");
  NWNXPushString(key);
  NWNXPushString(IntToString(start));
  NWNXPushString(IntToString(stop));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREMRANGEBYSCORE(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max
) {
  NWNXPushString("ZREMRANGEBYSCORE");
  NWNXPushString(key);
  NWNXPushString(FloatToString(min, 0));
  NWNXPushString(FloatToString(max, 0));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREVRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop,
	// Redis type: enum
	string withscores = ""
) {
  NWNXPushString("ZREVRANGE");
  NWNXPushString(key);
  NWNXPushString(IntToString(start));
  NWNXPushString(IntToString(stop));
  if (withscores != "") NWNXPushString(withscores);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREVRANGEBYSCORE(
	string key,
	// Redis type: double
	float max,
	// Redis type: double
	float min,
	// Redis type: enum
	string withscores = "",
	// Redis type: integer
	int limit_offset = 0,
	// Redis type: integer
	int limit_count = 0
) {
  NWNXPushString("ZREVRANGEBYSCORE");
  NWNXPushString(key);
  NWNXPushString(FloatToString(max, 0));
  NWNXPushString(FloatToString(min, 0));
  if (withscores != "") NWNXPushString(withscores);
  if (limit_offset != 0) NWNXPushString(IntToString(limit_offset));
  if (limit_count != 0) NWNXPushString(IntToString(limit_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZREVRANK(
	string key,
	string member
) {
  NWNXPushString("ZREVRANK");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZSCORE(
	string key,
	string member
) {
  NWNXPushString("ZSCORE");
  NWNXPushString(key);
  NWNXPushString(member);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZUNIONSTORE(
	// Redis type: key
	string destination,
	// Redis type: integer
	int numkeys,
	string key,
	// Redis type: integer
	int weights_weight = 0,
	// Redis type: enum
	string aggregate_aggregate = ""
) {
  NWNXPushString("ZUNIONSTORE");
  NWNXPushString(destination);
  NWNXPushString(IntToString(numkeys));
  NWNXPushString(key);
  if (weights_weight != 0) NWNXPushString(IntToString(weights_weight));
  if (aggregate_aggregate != "") NWNXPushString(aggregate_aggregate);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SCAN(
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0,
	string type_type = ""
) {
  NWNXPushString("SCAN");
  NWNXPushString(IntToString(cursor));
  if (match_pattern != "") NWNXPushString(match_pattern);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  if (type_type != "") NWNXPushString(type_type);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int SSCAN(
	string key,
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0
) {
  NWNXPushString("SSCAN");
  NWNXPushString(key);
  NWNXPushString(IntToString(cursor));
  if (match_pattern != "") NWNXPushString(match_pattern);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int HSCAN(
	string key,
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0
) {
  NWNXPushString("HSCAN");
  NWNXPushString(key);
  NWNXPushString(IntToString(cursor));
  if (match_pattern != "") NWNXPushString(match_pattern);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int ZSCAN(
	string key,
	// Redis type: integer
	int cursor,
	// Redis type: pattern
	string match_pattern = "",
	// Redis type: integer
	int count_count = 0
) {
  NWNXPushString("ZSCAN");
  NWNXPushString(key);
  NWNXPushString(IntToString(cursor));
  if (match_pattern != "") NWNXPushString(match_pattern);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XINFO(
	// Redis type: key
	string consumers_key = "",
	string consumers_groupname = "",
	// Redis type: key
	string groups_key = "",
	// Redis type: key
	string stream_key = "",
	// Redis type: enum
	string help = ""
) {
  NWNXPushString("XINFO");
  if (consumers_key != "") NWNXPushString(consumers_key);
  if (consumers_groupname != "") NWNXPushString(consumers_groupname);
  if (groups_key != "") NWNXPushString(groups_key);
  if (stream_key != "") NWNXPushString(stream_key);
  if (help != "") NWNXPushString(help);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XADD(
	string key,
	string ID,
	// Redis type: value
	string field,
	string str
) {
  NWNXPushString("XADD");
  NWNXPushString(key);
  NWNXPushString(ID);
  NWNXPushString(field);
  NWNXPushString(str);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XTRIM(
	string key,
	// Redis type: enum
	string strategy,
	// Redis type: enum
	string approx = "",
	// Redis type: integer
	int count = 0
) {
  NWNXPushString("XTRIM");
  NWNXPushString(key);
  NWNXPushString(strategy);
  if (approx != "") NWNXPushString(approx);
  NWNXPushString(IntToString(count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XDEL(
	string key,
	string ID
) {
  NWNXPushString("XDEL");
  NWNXPushString(key);
  NWNXPushString(ID);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XRANGE(
	string key,
	string start,
	string end,
	// Redis type: integer
	int count_count = 0
) {
  NWNXPushString("XRANGE");
  NWNXPushString(key);
  NWNXPushString(start);
  NWNXPushString(end);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XREVRANGE(
	string key,
	string end,
	string start,
	// Redis type: integer
	int count_count = 0
) {
  NWNXPushString("XREVRANGE");
  NWNXPushString(key);
  NWNXPushString(end);
  NWNXPushString(start);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XLEN(
	string key
) {
  NWNXPushString("XLEN");
  NWNXPushString(key);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XREAD(
	// Redis type: integer
	int count_count = 0,
	// Redis type: integer
	int block_milliseconds = 0,
	// Redis type: enum
	string streams = "",
	string key = "",
	string ID = ""
) {
  NWNXPushString("XREAD");
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  if (block_milliseconds != 0) NWNXPushString(IntToString(block_milliseconds));
  NWNXPushString(streams);
  NWNXPushString(key);
  NWNXPushString(ID);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XGROUP(
	// Redis type: key
	string create_key = "",
	string create_groupname = "",
	string create_id_or__ = "",
	// Redis type: key
	string setid_key = "",
	string setid_groupname = "",
	string setid_id_or__ = "",
	// Redis type: key
	string destroy_key = "",
	string destroy_groupname = "",
	// Redis type: key
	string delconsumer_key = "",
	string delconsumer_groupname = "",
	string delconsumer_consumername = ""
) {
  NWNXPushString("XGROUP");
  if (create_key != "") NWNXPushString(create_key);
  if (create_groupname != "") NWNXPushString(create_groupname);
  if (create_id_or__ != "") NWNXPushString(create_id_or__);
  if (setid_key != "") NWNXPushString(setid_key);
  if (setid_groupname != "") NWNXPushString(setid_groupname);
  if (setid_id_or__ != "") NWNXPushString(setid_id_or__);
  if (destroy_key != "") NWNXPushString(destroy_key);
  if (destroy_groupname != "") NWNXPushString(destroy_groupname);
  if (delconsumer_key != "") NWNXPushString(delconsumer_key);
  if (delconsumer_groupname != "") NWNXPushString(delconsumer_groupname);
  if (delconsumer_consumername != "") NWNXPushString(delconsumer_consumername);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XREADGROUP(
	string group_group,
	string group_consumer,
	// Redis type: integer
	int count_count = 0,
	// Redis type: integer
	int block_milliseconds = 0,
	// Redis type: enum
	string noack = "",
	// Redis type: enum
	string streams = "",
	string key = "",
	string ID = ""
) {
  NWNXPushString("XREADGROUP");
  NWNXPushString(group_group);
  NWNXPushString(group_consumer);
  if (count_count != 0) NWNXPushString(IntToString(count_count));
  if (block_milliseconds != 0) NWNXPushString(IntToString(block_milliseconds));
  if (noack != "") NWNXPushString(noack);
  NWNXPushString(streams);
  NWNXPushString(key);
  NWNXPushString(ID);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XACK(
	string key,
	string group,
	string ID
) {
  NWNXPushString("XACK");
  NWNXPushString(key);
  NWNXPushString(group);
  NWNXPushString(ID);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XCLAIM(
	string key,
	string group,
	string consumer,
	string min_idle_time,
	string ID,
	// Redis type: integer
	int idle_ms = 0,
	// Redis type: integer
	int time_ms_unix_time = 0,
	// Redis type: integer
	int retrycount_count = 0
) {
  NWNXPushString("XCLAIM");
  NWNXPushString(key);
  NWNXPushString(group);
  NWNXPushString(consumer);
  NWNXPushString(min_idle_time);
  NWNXPushString(ID);
  if (idle_ms != 0) NWNXPushString(IntToString(idle_ms));
  if (time_ms_unix_time != 0) NWNXPushString(IntToString(time_ms_unix_time));
  if (retrycount_count != 0) NWNXPushString(IntToString(retrycount_count));
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}

int XPENDING(
	string key,
	string group,
	string start = "",
	string end = "",
	// Redis type: integer
	int count = 0,
	string consumer = ""
) {
  NWNXPushString("XPENDING");
  NWNXPushString(key);
  NWNXPushString(group);
  if (start != "") NWNXPushString(start);
  if (end != "") NWNXPushString(end);
  if (count != 0) NWNXPushString(IntToString(count));
  if (consumer != "") NWNXPushString(consumer);
  NWNXCall("NWNX_Redis", "Deferred");
  return NWNXPopInt();
}
