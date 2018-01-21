#pragma once

#include <cpp_redis/cpp_redis>
#include "Redis.hpp"
#include "Pool.hpp"
#include <mutex>

namespace Redis
{

struct Internal {
    Internal(Pool<cpp_redis::redis_client>::MakeFunc m) :
        m_redis_pool(m) {}

    // Connection pool for redis, used both for nwscript and for
    // external consumers (like other Plugins).
    Pool<cpp_redis::redis_client> m_redis_pool;

    // The pubsub connection.
    cpp_redis::redis_subscriber m_connection_pubsub;
    std::string m_last_pubsub_channel;
    std::string m_last_pubsub_message;

    // Config update mutex. Pool could run into this!
    std::mutex m_config_mtx;

    // Aaand the config
    Redis::Configuration m_config;
};

}
