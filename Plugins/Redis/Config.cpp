#include "Redis.hpp"
#include "Internal.hpp"

#include "Services/Config/Config.hpp"

#include "Util.h"

namespace Redis
{

using namespace NWNXLib;
using namespace NWNXLib::Services;
using namespace NWNXLib::Hooking;

std::unique_ptr<cpp_redis::redis_client> Redis::PoolMakeFunc()
{
    std::lock_guard<std::mutex> lock(m_internal->m_config_mtx);

    ASSERT(!m_internal->m_config.m_host.empty());
    ASSERT(m_internal->m_config.m_port >= 0);

    auto p = std::make_unique<cpp_redis::redis_client>();
    (*p).connect(m_internal->m_config.m_host, static_cast<size_t>(m_internal->m_config.m_port));
    return p;
}

void Redis::Reconfigure()
{
    using namespace std::placeholders;

    {
        std::lock_guard<std::mutex> lock(m_internal->m_config_mtx);

        // Redis server.
        m_internal->m_config.m_host = GetServices()->m_config->Require<std::string>("HOST");
        m_internal->m_config.m_port = GetServices()->m_config->Get<int>("PORT", 6379);

        // Pubsub.
        m_internal->m_config.m_pubsub_script = GetServices()->m_config->Get<std::string>("PUBSUB_SCRIPT", "on_pubsub");
        m_internal->m_config.m_pubsub_channels = str_explode(GetServices()->m_config->
                Get<std::string>("PUBSUB_CHANNELS", ""), ',');

        LOG_INFO("Reconfiguring for redis at %s:%d",
                                   m_internal->m_config.m_host.c_str(),
                                   m_internal->m_config.m_port);

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

        auto bound = std::bind(&Redis::OnPubsub, this, _1, _2);
        for (auto& ch : m_internal->m_config.m_pubsub_channels)
        {
            LOG_INFO("PubSub: Subscribing to %s", ch.c_str());
            m_internal->m_connection_pubsub.psubscribe(ch, bound);
        }
        m_internal->m_connection_pubsub.commit();

        LOG_INFO("%s", "Connected!");
    }

    m_internal->m_redis_pool.Clean();
}

}
