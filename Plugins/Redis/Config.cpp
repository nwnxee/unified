#include "Redis.hpp"
#include "Internal.hpp"


namespace Redis
{

using namespace NWNXLib;
using namespace NWNXLib::Services;

std::unique_ptr<cpp_redis::redis_client> Redis::PoolMakeFunc()
{
    std::lock_guard<std::mutex> lock(m_internal->m_config_mtx);

    ASSERT(!m_internal->m_config.m_host.empty());
    ASSERT(m_internal->m_config.m_port >= 0);

    auto p = std::make_unique<cpp_redis::redis_client>();
    (*p).connect(m_internal->m_config.m_host, static_cast<size_t>(m_internal->m_config.m_port));

    // Pool ctor currently authenticates synchronously.
    // Invalid passwords aren't handled at all - you'll have to watch the server logs for that.
    if (!m_internal->m_config.m_password.empty())
    {
        (*p).auth(m_internal->m_config.m_password);
        (*p).sync_commit();    
    }
    
    return p;
}

void Redis::Reconfigure()
{
    using namespace std::placeholders;

    {
        std::lock_guard<std::mutex> lock(m_internal->m_config_mtx);

        // Redis server.
        m_internal->m_config.m_host = *Config::Get<std::string>("HOST");
        m_internal->m_config.m_port = Config::Get<int>("PORT", 6379);
        m_internal->m_config.m_password = Config::Get<std::string>("AUTH_PASSWORD", "");

        // Pubsub.
        m_internal->m_config.m_pubsub_script = Config::Get<std::string>("PUBSUB_SCRIPT", "on_pubsub");
        m_internal->m_config.m_pubsub_channels = String::Split(
            Config::Get<std::string>("PUBSUB_CHANNELS", ""), ',');

        LOG_INFO("Reconfiguring for redis at %s:%d",
                                   m_internal->m_config.m_host,
                                   m_internal->m_config.m_port);

        LOG_INFO("PubSub: Using NWScript: %s", m_internal->m_config.m_pubsub_script);

        try
        {
            m_internal->m_connection_pubsub.disconnect();
        }
        catch (cpp_redis::redis_error& e)
        {
            LOG_NOTICE("Error while reconfiguring pubsub client: %s", e.what());
        }
        m_internal->m_connection_pubsub.connect(
            m_internal->m_config.m_host, static_cast<size_t>(m_internal->m_config.m_port));

        if (!m_internal->m_config.m_password.empty())
        {
            m_internal->m_connection_pubsub.auth(m_internal->m_config.m_password);
            m_internal->m_connection_pubsub.commit();
        }

        auto bound = std::bind(&Redis::OnPubsub, this, _1, _2);
        for (auto& ch : m_internal->m_config.m_pubsub_channels)
        {
            LOG_INFO("PubSub: Subscribing to %s", ch);
            m_internal->m_connection_pubsub.psubscribe(ch, bound);
        }
        m_internal->m_connection_pubsub.commit();

        LOG_INFO("%s", "Connected!");
    }

    m_internal->m_redis_pool.Clean();
}

}
