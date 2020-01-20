#include "nwnx"
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "APPEND");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int AUTH(
	string password
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "AUTH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", password);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BGREWRITEAOF() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BGREWRITEAOF");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BGSAVE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BGSAVE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BITCOUNT(
	string key,
	// Redis type: integer
	int start = 0,
	// Redis type: integer
	int end = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BITCOUNT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (start != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  if (end != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(end));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BITFIELD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (get_type != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", get_type);
  if (get_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(get_offset));
  if (set_type != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", set_type);
  if (set_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(set_offset));
  if (set_value != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(set_value));
  if (incrby_type != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", incrby_type);
  if (incrby_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(incrby_offset));
  if (incrby_increment != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(incrby_increment));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BITOP(
	string operation,
	// Redis type: key
	string destkey,
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BITOP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", operation);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destkey);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BITPOS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(bit));
  if (start != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  if (end != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(end));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BLPOP(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BLPOP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BRPOP(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BRPOP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BRPOPLPUSH(
	// Redis type: key
	string source,
	// Redis type: key
	string destination,
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BRPOPLPUSH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", source);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BZPOPMIN(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BZPOPMIN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int BZPOPMAX(
	string key,
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "BZPOPMAX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_ID() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_ID");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_KILL(
	string ip_port = "",
	// Redis type: integer
	int id_client_id = 0,
	string addr_ip_port = "",
	string skipme_yes_no = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_KILL");
  if (ip_port != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", ip_port);
  if (id_client_id != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(id_client_id));
  if (addr_ip_port != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", addr_ip_port);
  if (skipme_yes_no != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", skipme_yes_no);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_LIST() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_LIST");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_GETNAME() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_GETNAME");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_PAUSE(
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_PAUSE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_REPLY(
	// Redis type: enum
	string reply_mode
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_REPLY");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", reply_mode);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_SETNAME(
	string connection_name
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_SETNAME");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", connection_name);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLIENT_UNBLOCK(
	string client_id,
	// Redis type: enum
	string unblock_type = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLIENT_UNBLOCK");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", client_id);
  if (unblock_type != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", unblock_type);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_ADDSLOTS(
	// Redis type: integer
	int slot
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_ADDSLOTS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(slot));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_COUNT_FAILURE_REPORTS(
	string node_id
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_COUNT_FAILURE_REPORTS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", node_id);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_COUNTKEYSINSLOT(
	// Redis type: integer
	int slot
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_COUNTKEYSINSLOT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(slot));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_DELSLOTS(
	// Redis type: integer
	int slot
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_DELSLOTS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(slot));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_FAILOVER(
	// Redis type: enum
	string options = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_FAILOVER");
  if (options != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", options);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_FORGET(
	string node_id
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_FORGET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", node_id);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_GETKEYSINSLOT(
	// Redis type: integer
	int slot,
	// Redis type: integer
	int count
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_GETKEYSINSLOT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(slot));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_INFO() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_INFO");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_KEYSLOT(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_KEYSLOT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_MEET(
	string ip,
	// Redis type: integer
	int port
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_MEET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ip);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(port));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_NODES() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_NODES");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_REPLICATE(
	string node_id
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_REPLICATE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", node_id);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_RESET(
	// Redis type: enum
	string reset_type = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_RESET");
  if (reset_type != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", reset_type);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_SAVECONFIG() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_SAVECONFIG");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_SET_CONFIG_EPOCH(
	// Redis type: integer
	int config_epoch
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_SET_CONFIG_EPOCH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(config_epoch));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_SETSLOT(
	// Redis type: integer
	int slot,
	// Redis type: enum
	string subcommand,
	string node_id = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_SETSLOT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(slot));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", subcommand);
  if (node_id != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", node_id);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_SLAVES(
	string node_id
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_SLAVES");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", node_id);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_REPLICAS(
	string node_id
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_REPLICAS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", node_id);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CLUSTER_SLOTS() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CLUSTER_SLOTS");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int COMMAND() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "COMMAND");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int COMMAND_COUNT() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "COMMAND_COUNT");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int COMMAND_GETKEYS() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "COMMAND_GETKEYS");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int COMMAND_INFO(
	string command_name
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "COMMAND_INFO");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", command_name);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CONFIG_GET(
	string parameter
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CONFIG_GET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", parameter);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CONFIG_REWRITE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CONFIG_REWRITE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CONFIG_SET(
	string parameter,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CONFIG_SET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", parameter);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int CONFIG_RESETSTAT() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "CONFIG_RESETSTAT");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DBSIZE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DBSIZE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DEBUG_OBJECT(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DEBUG_OBJECT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DEBUG_SEGFAULT() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DEBUG_SEGFAULT");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DECR(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DECR");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DECRBY(
	string key,
	// Redis type: integer
	int decrement
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DECRBY");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(decrement));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DEL(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DEL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DISCARD() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DISCARD");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int DUMP(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "DUMP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ECHO(
	string message
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ECHO");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", message);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int EVAL(
	string script,
	// Redis type: integer
	int numkeys,
	string key,
	string arg
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "EVAL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", script);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(numkeys));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", arg);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int EVALSHA(
	string sha1,
	// Redis type: integer
	int numkeys,
	string key,
	string arg
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "EVALSHA");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", sha1);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(numkeys));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", arg);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int EXEC() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "EXEC");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int EXISTS(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "EXISTS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int EXPIRE(
	string key,
	// Redis type: integer
	int seconds
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "EXPIRE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(seconds));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int EXPIREAT(
	string key,
	// Redis type: posix time
	string timestamp
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "EXPIREAT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", timestamp);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int FLUSHALL(
	// Redis type: enum
	string async = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "FLUSHALL");
  if (async != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", async);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int FLUSHDB(
	// Redis type: enum
	string async = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "FLUSHDB");
  if (async != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", async);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GEOADD(
	string key,
	// Redis type: double
	float longitude,
	// Redis type: double
	float latitude,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GEOADD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(longitude, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(latitude, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GEOHASH(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GEOHASH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GEOPOS(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GEOPOS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GEODIST(
	string key,
	string member1,
	string member2,
	string unit = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GEODIST");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member1);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member2);
  if (unit != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", unit);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GEORADIUS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(longitude, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(latitude, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(radius, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", unit);
  if (withcoord != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withcoord);
  if (withdist != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withdist);
  if (withhash != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withhash);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  if (order != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", order);
  if (store_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", store_key);
  if (storedist_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", storedist_key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GEORADIUSBYMEMBER");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(radius, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", unit);
  if (withcoord != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withcoord);
  if (withdist != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withdist);
  if (withhash != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withhash);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  if (order != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", order);
  if (store_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", store_key);
  if (storedist_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", storedist_key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GET(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GETBIT(
	string key,
	// Redis type: integer
	int offset
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GETBIT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(offset));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GETRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int end
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GETRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(end));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int GETSET(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "GETSET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HDEL(
	string key,
	string field
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HDEL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HEXISTS(
	string key,
	string field
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HEXISTS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HGET(
	string key,
	string field
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HGET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HGETALL(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HGETALL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HINCRBY(
	string key,
	string field,
	// Redis type: integer
	int increment
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HINCRBY");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(increment));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HINCRBYFLOAT(
	string key,
	string field,
	// Redis type: double
	float increment
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HINCRBYFLOAT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(increment, 0));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HKEYS(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HKEYS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HLEN(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HLEN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HMGET(
	string key,
	string field
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HMGET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HMSET(
	string key,
	string field,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HMSET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HSET(
	string key,
	string field,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HSET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HSETNX(
	string key,
	string field,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HSETNX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HSTRLEN(
	string key,
	string field
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HSTRLEN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int HVALS(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HVALS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int INCR(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "INCR");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int INCRBY(
	string key,
	// Redis type: integer
	int increment
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "INCRBY");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(increment));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int INCRBYFLOAT(
	string key,
	// Redis type: double
	float increment
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "INCRBYFLOAT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(increment, 0));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int INFO(
	string section = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "INFO");
  if (section != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", section);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int KEYS(
	string pattern
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "KEYS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", pattern);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LASTSAVE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LASTSAVE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LINDEX(
	string key,
	// Redis type: integer
	int index
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LINDEX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(index));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LINSERT(
	string key,
	// Redis type: enum
	string where,
	string pivot,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LINSERT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", where);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", pivot);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LLEN(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LLEN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LPOP(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LPOP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LPUSH(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LPUSH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LPUSHX(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LPUSHX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LRANGE(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(stop));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LREM(
	string key,
	// Redis type: integer
	int count,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LREM");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LSET(
	string key,
	// Redis type: integer
	int index,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LSET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(index));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int LTRIM(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "LTRIM");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(stop));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MEMORY_DOCTOR() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MEMORY_DOCTOR");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MEMORY_HELP() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MEMORY_HELP");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MEMORY_MALLOC_STATS() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MEMORY_MALLOC_STATS");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MEMORY_PURGE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MEMORY_PURGE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MEMORY_STATS() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MEMORY_STATS");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MEMORY_USAGE(
	string key,
	// Redis type: integer
	int samples_count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MEMORY_USAGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (samples_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(samples_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MGET(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MGET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MIGRATE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", host);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", port);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(destination_db));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  if (copy != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", copy);
  if (replace != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", replace);
  if (auth_password != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", auth_password);
  if (keys_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", keys_key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MONITOR() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MONITOR");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MOVE(
	string key,
	// Redis type: integer
	int db
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MOVE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(db));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MSET(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MSET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MSETNX(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MSETNX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int MULTI() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "MULTI");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int OBJECT(
	string subcommand,
	string arguments = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "OBJECT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", subcommand);
  if (arguments != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", arguments);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PERSIST(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PERSIST");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PEXPIRE(
	string key,
	// Redis type: integer
	int milliseconds
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PEXPIRE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(milliseconds));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PEXPIREAT(
	string key,
	// Redis type: posix time
	string milliseconds_timestamp
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PEXPIREAT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", milliseconds_timestamp);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PFADD(
	string key,
	string element
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PFADD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", element);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PFCOUNT(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PFCOUNT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PFMERGE(
	// Redis type: key
	string destkey,
	// Redis type: key
	string sourcekey
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PFMERGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destkey);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", sourcekey);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PING(
	string message = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PING");
  if (message != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", message);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PSETEX(
	string key,
	// Redis type: integer
	int milliseconds,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PSETEX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(milliseconds));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PUBSUB(
	string subcommand,
	string argument = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PUBSUB");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", subcommand);
  if (argument != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", argument);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PTTL(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PTTL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int PUBLISH(
	string channel,
	string message
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "PUBLISH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", channel);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", message);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int QUIT() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "QUIT");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RANDOMKEY() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RANDOMKEY");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int READONLY() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "READONLY");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int READWRITE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "READWRITE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RENAME(
	string key,
	// Redis type: key
	string newkey
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RENAME");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", newkey);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RENAMENX(
	string key,
	// Redis type: key
	string newkey
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RENAMENX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", newkey);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RESTORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(ttl));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", serialized_value);
  if (replace != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", replace);
  if (absttl != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", absttl);
  if (idletime_seconds != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(idletime_seconds));
  if (freq_frequency != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(freq_frequency));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ROLE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ROLE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RPOP(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RPOP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RPOPLPUSH(
	// Redis type: key
	string source,
	// Redis type: key
	string destination
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RPOPLPUSH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", source);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RPUSH(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RPUSH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int RPUSHX(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "RPUSHX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SADD(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SADD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SAVE() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SAVE");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SCARD(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCARD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SCRIPT_DEBUG(
	// Redis type: enum
	string mode
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCRIPT_DEBUG");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", mode);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SCRIPT_EXISTS(
	string sha1
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCRIPT_EXISTS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", sha1);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SCRIPT_FLUSH() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCRIPT_FLUSH");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SCRIPT_KILL() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCRIPT_KILL");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SCRIPT_LOAD(
	string script
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCRIPT_LOAD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", script);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SDIFF(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SDIFF");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SDIFFSTORE(
	// Redis type: key
	string destination,
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SDIFFSTORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SELECT(
	// Redis type: integer
	int index
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SELECT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(index));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SET(
	string key,
	string value,
	// Redis type: enum
	string condition = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SET");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  if (condition != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", condition);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SETBIT(
	string key,
	// Redis type: integer
	int offset,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SETBIT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(offset));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SETEX(
	string key,
	// Redis type: integer
	int seconds,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SETEX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(seconds));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SETNX(
	string key,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SETNX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SETRANGE(
	string key,
	// Redis type: integer
	int offset,
	string value
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SETRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(offset));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", value);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SHUTDOWN(
	// Redis type: enum
	string save_mode = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SHUTDOWN");
  if (save_mode != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", save_mode);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SINTER(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SINTER");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SINTERSTORE(
	// Redis type: key
	string destination,
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SINTERSTORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SISMEMBER(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SISMEMBER");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SLAVEOF(
	string host,
	string port
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SLAVEOF");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", host);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", port);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int REPLICAOF(
	string host,
	string port
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "REPLICAOF");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", host);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", port);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SLOWLOG(
	string subcommand,
	string argument = ""
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SLOWLOG");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", subcommand);
  if (argument != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", argument);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SMEMBERS(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SMEMBERS");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SMOVE(
	// Redis type: key
	string source,
	// Redis type: key
	string destination,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SMOVE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", source);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SORT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (by_pattern != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", by_pattern);
  if (limit_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_offset));
  if (limit_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_count));
  if (get_pattern != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", get_pattern);
  if (order != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", order);
  if (sorting != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", sorting);
  if (store_destination != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", store_destination);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SPOP(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SPOP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SRANDMEMBER(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SRANDMEMBER");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SREM(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SREM");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int STRLEN(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "STRLEN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SUNION(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SUNION");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SUNIONSTORE(
	// Redis type: key
	string destination,
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SUNIONSTORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SWAPDB(
	// Redis type: integer
	int index,
	// Redis type: integer
	int index_1
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SWAPDB");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(index));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(index_1));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int SYNC() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SYNC");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int TIME() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "TIME");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int TOUCH(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "TOUCH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int TTL(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "TTL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int TYPE(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "TYPE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int UNLINK(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "UNLINK");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int UNWATCH() {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "UNWATCH");
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int WAIT(
	// Redis type: integer
	int numreplicas,
	// Redis type: integer
	int timeout
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "WAIT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(numreplicas));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(timeout));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int WATCH(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "WATCH");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZADD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (condition != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", condition);
  if (change != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", change);
  if (increment != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", increment);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(score, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZCARD(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZCARD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZCOUNT(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZCOUNT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(min, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(max, 0));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZINCRBY(
	string key,
	// Redis type: integer
	int increment,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZINCRBY");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(increment));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZINTERSTORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(numkeys));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (weights_weight != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(weights_weight));
  if (aggregate_aggregate != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", aggregate_aggregate);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZLEXCOUNT(
	string key,
	string min,
	string max
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZLEXCOUNT");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", min);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", max);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZPOPMAX(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZPOPMAX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZPOPMIN(
	string key,
	// Redis type: integer
	int count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZPOPMIN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(stop));
  if (withscores != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withscores);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZRANGEBYLEX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", min);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", max);
  if (limit_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_offset));
  if (limit_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREVRANGEBYLEX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", max);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", min);
  if (limit_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_offset));
  if (limit_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZRANGEBYSCORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(min, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(max, 0));
  if (withscores != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withscores);
  if (limit_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_offset));
  if (limit_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZRANK(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZRANK");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZREM(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREM");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZREMRANGEBYLEX(
	string key,
	string min,
	string max
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREMRANGEBYLEX");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", min);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", max);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZREMRANGEBYRANK(
	string key,
	// Redis type: integer
	int start,
	// Redis type: integer
	int stop
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREMRANGEBYRANK");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(stop));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZREMRANGEBYSCORE(
	string key,
	// Redis type: double
	float min,
	// Redis type: double
	float max
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREMRANGEBYSCORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(min, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(max, 0));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREVRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(start));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(stop));
  if (withscores != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withscores);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREVRANGEBYSCORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(max, 0));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", FloatToString(min, 0));
  if (withscores != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", withscores);
  if (limit_offset != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_offset));
  if (limit_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(limit_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZREVRANK(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZREVRANK");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int ZSCORE(
	string key,
	string member
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZSCORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", member);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZUNIONSTORE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", destination);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(numkeys));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  if (weights_weight != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(weights_weight));
  if (aggregate_aggregate != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", aggregate_aggregate);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SCAN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(cursor));
  if (match_pattern != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", match_pattern);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  if (type_type != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", type_type);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "SSCAN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(cursor));
  if (match_pattern != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", match_pattern);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "HSCAN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(cursor));
  if (match_pattern != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", match_pattern);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "ZSCAN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(cursor));
  if (match_pattern != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", match_pattern);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XINFO");
  if (consumers_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", consumers_key);
  if (consumers_groupname != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", consumers_groupname);
  if (groups_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", groups_key);
  if (stream_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", stream_key);
  if (help != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", help);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int XADD(
	string key,
	string ID,
	// Redis type: value
	string field,
	string str
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XADD");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ID);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", field);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", str);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XTRIM");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", strategy);
  if (approx != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", approx);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int XDEL(
	string key,
	string ID
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XDEL");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ID);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int XRANGE(
	string key,
	string start,
	string end,
	// Redis type: integer
	int count_count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", start);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", end);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int XREVRANGE(
	string key,
	string end,
	string start,
	// Redis type: integer
	int count_count = 0
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XREVRANGE");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", end);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", start);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int XLEN(
	string key
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XLEN");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XREAD");
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  if (block_milliseconds != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(block_milliseconds));
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", streams);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ID);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XGROUP");
  if (create_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", create_key);
  if (create_groupname != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", create_groupname);
  if (create_id_or__ != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", create_id_or__);
  if (setid_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", setid_key);
  if (setid_groupname != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", setid_groupname);
  if (setid_id_or__ != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", setid_id_or__);
  if (destroy_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", destroy_key);
  if (destroy_groupname != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", destroy_groupname);
  if (delconsumer_key != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", delconsumer_key);
  if (delconsumer_groupname != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", delconsumer_groupname);
  if (delconsumer_consumername != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", delconsumer_consumername);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XREADGROUP");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", group_group);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", group_consumer);
  if (count_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count_count));
  if (block_milliseconds != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(block_milliseconds));
  if (noack != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", noack);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", streams);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ID);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

int XACK(
	string key,
	string group,
	string ID
) {
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XACK");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", group);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ID);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XCLAIM");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", group);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", consumer);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", min_idle_time);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", ID);
  if (idle_ms != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(idle_ms));
  if (time_ms_unix_time != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(time_ms_unix_time));
  if (retrycount_count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(retrycount_count));
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
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
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", "XPENDING");
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", key);
  NWNX_PushArgumentString("NWNX_Redis", "Deferred", group);
  if (start != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", start);
  if (end != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", end);
  if (count != 0) NWNX_PushArgumentString("NWNX_Redis", "Deferred", IntToString(count));
  if (consumer != "") NWNX_PushArgumentString("NWNX_Redis", "Deferred", consumer);
  NWNX_CallFunction("NWNX_Redis", "Deferred");
  return NWNX_GetReturnValueInt("NWNX_Redis", "Deferred");
}

