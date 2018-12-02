#include "Redis.hpp"
#include "Internal.hpp"

#include "Services/Events/Events.hpp"

#include "Util.h"

namespace Redis
{

using namespace NWNXLib;
using namespace NWNXLib::Services;

void Redis::RegisterWithNWScript()
{
    // Full reply data of the last command executed for nwscript purposes.
    // Reason to keep it around is so that nwscript can, for example, iterate lists.
    static cpp_redis::reply m_last_nwscript_reply;

    // NWScript: Executes a raw redis command with a variable argument list.
    // Returns the reply type (as a constant, see RedisReplyTypeToInt).
    GetServices()->m_events->RegisterEvent("RawCommand",
    [&](Events::ArgumentStack && arg)
    {
        std::vector<std::string> v;
        while (!arg.empty())
        {
            // be ignorant about type and just strip it, since we take
            // raw values (integers, strings) and shove them as strings straight
            // to redis.
            v.push_back(arg.top().substr(2));
            arg.pop();
        }
        reverse(v.begin(), v.end());

        auto ret = RawSync(v);

        if (ret.is_array())
        {
            m_last_nwscript_reply = ret;
        }

        Events::ArgumentStack st;
        // Return value: a simple string for now to cut down on call count.
        Events::InsertArgument(st, RedisReplyAsString(ret));

        // Events::InsertArgument(st, std::to_string(RedisReplyTypeToInt(
        // m_last_nwscript_reply.get_type())));
        return st;
    });

    // NWScript: Returns the last query result type as a int.
    // Values returned: last reply as a string
    GetServices()->m_events->RegisterEvent("GetLastReplyType",
    [&](Events::ArgumentStack &&)
    {
        Events::ArgumentStack st;
        Events::InsertArgument(st, RedisReplyTypeToInt(m_last_nwscript_reply.get_type()));
        return st;
    });

    // NWScript: Get list length of result. Returns 0 if not a list.
    // N.B: Redis can return multi-list results. This is not handled here
    GetServices()->m_events->RegisterEvent("GetLastReplyArrayLength",
    [&](Events::ArgumentStack &&)
    {
        int32_t len = 0;
        if (m_last_nwscript_reply.is_array())
        {
            len = static_cast<int32_t>(m_last_nwscript_reply.as_array().size());
        }

        Events::ArgumentStack st;
        Events::InsertArgument(st, len);
        return st;
    });

    // NWScript: Get array element (as string) of result.
    // Will return 0 if the last command wasn't a list.
    // N.B: Redis can return multi-list results.
    //      This is not yet properly handled here.
    GetServices()->m_events->RegisterEvent("GetLastReplyArrayElement",
    [&](Events::ArgumentStack && arg)
    {
        const auto idx = Services::Events::ExtractArgument<int32_t>(arg);

        std::string ret;
        if (m_last_nwscript_reply.is_array() &&
            idx >= 0 &&
            idx < static_cast<int32_t>(m_last_nwscript_reply.as_array().size()))
        {
            ret = RedisReplyAsString(m_last_nwscript_reply.as_array()[idx]);
        }

        Events::ArgumentStack st;
        Events::InsertArgument(st, ret);
        return st;
    });

    // NWScript: Get the last pubsub message.
    // Values returned: channel, message
    GetServices()->m_events->RegisterEvent("GetPubSubData",
    [&](Events::ArgumentStack &&)
    {
        Events::ArgumentStack st;
        Events::InsertArgument(st, m_internal->m_last_pubsub_channel);
        Events::InsertArgument(st, m_internal->m_last_pubsub_message);
        return st;
    });
}


}
