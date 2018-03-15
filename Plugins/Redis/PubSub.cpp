#include "Redis.hpp"
#include "Internal.hpp"

#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Tasks/Tasks.hpp"

#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"

#include <cstring>

namespace Redis
{

using namespace NWNXLib;
using namespace NWNXLib::Services;
using namespace NWNXLib::Hooking;
using namespace NWNXLib::API;

void Redis::OnPubsub(const std::string& channel, const std::string& message)
{
    LOG_DEBUG("PubSub: channel='%s' message='%s'", channel.c_str(), message.c_str());

    m_internal->m_last_pubsub_channel = channel;
    m_internal->m_last_pubsub_message = message;

    std::string scr;

    {
        std::lock_guard<std::mutex> lock(m_internal->m_config_mtx);
        ASSERT(!m_internal->m_config.m_pubsub_script.empty());
        scr = m_internal->m_config.m_pubsub_script;
    }

    if (!scr.empty())
    {
        GetServices()->m_tasks->QueueOnMainThread([scr] {

            // Only ever deliver script events when a module is running.
            if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2) {
                // GetServices()->m_log->Debug("%s", "PubSub: event dropped, not in a running module");
                return;
            }

            CExoString script(scr.c_str());
            Globals::VirtualMachine()->RunScript(&script, 0, 1);
        });
    }

}

}
