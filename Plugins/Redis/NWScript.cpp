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

        m_last_nwscript_reply = RawSync(v);

        Events::ArgumentStack st;
        // Return value: a simple string for now to cut down on call
        // count.
        Events::InsertArgument(st, RedisReplyAsString(m_last_nwscript_reply));

        // Events::InsertArgument(st, std::to_string(RedisReplyTypeToInt(
        // m_last_nwscript_reply.get_type())));
        return st;
    });

    // NWScript: Returns the last query result as a string.
    // Values returned: last reply as a string
    GetServices()->m_events->RegisterEvent("GetLastReplyAsString",
    [&](Events::ArgumentStack &&)
    {
        Events::ArgumentStack st;
        Events::InsertArgument(st, RedisReplyAsString(m_last_nwscript_reply));
        return st;
    });

    // NWScript: Get list length.
    // N.B: Redis can return multi-list results.

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
