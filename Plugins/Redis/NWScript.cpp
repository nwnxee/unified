#include <unordered_map>

#include "Redis.hpp"
#include "Internal.hpp"

#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CExoString.hpp"

namespace Redis
{

using namespace NWNXLib;
using namespace NWNXLib::Services;
using namespace NWNXLib::API;

// We cache all results until the end of the current script invocation.
static std::vector<cpp_redis::reply> s_results;

void Redis::CleanState(CVirtualMachineStack *pVirtualMachineStack)
{
    m_ClearStackHook->CallOriginal<void>(pVirtualMachineStack);

    if (pVirtualMachineStack->m_pVMachine->m_nRecursionLevel == 0)
    {
        LOG_DEBUG("Clearing all results after script exit.");
        s_results.clear();
    }
}

void Redis::RegisterWithNWScript()
{
    // NWScript: Executes a raw redis command with a variable argument list.
    // Returns a opaque identifier you can use to access the result
    Events::RegisterEvent(GetName(), "Deferred",
            [&](Events::ArgumentStack && arg)
            {
                std::vector<std::string> v;
                while (!arg.empty())
                {
                    // be ignorant about type and just strip it, since we take
                    // raw values (integers, strings) and shove them as strings straight
                    // to redis.
                    v.push_back(arg.top().toString());
                    arg.pop();
                }
                reverse(v.begin(), v.end());

                auto ret = RawSync(v);

                s_results.emplace_back(ret);

                // We return the assigned opaque value. Ignore that this is an array index.
                return Events::Arguments(static_cast<int32_t>(s_results.size() - 1));
            });

    // NWScript: Returns the last query result type as a int.
    Events::RegisterEvent(GetName(), "GetResultType",
            [&](Events::ArgumentStack && arg)
            {
                const auto resultId = static_cast<uint32_t>(Events::ExtractArgument<int32_t>(arg));

                int type = 0;
                if (resultId < s_results.size())
                {
                    type = RedisReplyTypeToInt(s_results[resultId].get_type());
                }
                else
                {
                    LOG_ERROR("Result %d was not found. This is a error on your side.", resultId);
                }

                return Events::Arguments(type);
            });

    // NWScript: Get list length of result. Returns 0 if not a list.
    // N.B: Redis can return multi-list results. This is not handled here
    Events::RegisterEvent(GetName(), "GetResultArrayLength",
            [&](Events::ArgumentStack && arg)
            {
                const auto resultId = static_cast<uint32_t>(Events::ExtractArgument<int32_t>(arg));

                int32_t len = 0;
                if (resultId < s_results.size() && s_results[resultId].is_array())
                {
                    len = static_cast<int32_t>(s_results[resultId].as_array().size());
                }
                else
                {
                    LOG_ERROR("Result %d was not found or is not an array. "
                              "This is a error on your side.", resultId);
                }

                return Events::Arguments(len);
            });

    // NWScript: Get array element as a new result.
    Events::RegisterEvent(GetName(), "GetResultArrayElement",
            [&](Events::ArgumentStack && arg)
            {
                const auto arrayIndex = static_cast<uint32_t>(Events::ExtractArgument<int32_t>(arg));
                const auto resultId = static_cast<uint32_t>(Events::ExtractArgument<int32_t>(arg));

                int32_t newResultId = 0;
                std::string ret;

                if (resultId < s_results.size() &&
                    s_results[resultId].is_array() &&
                    arrayIndex < s_results[resultId].as_array().size())
                {
                    s_results.push_back(s_results[resultId].as_array()[arrayIndex]);
                    newResultId = static_cast<int32_t>(s_results.size() - 1);
                }
                else
                {
                    LOG_ERROR("Result %d, not an array or index %d was out of bounds. "
                              "This is a error on your side.", resultId, arrayIndex);
                }

                return Events::Arguments(newResultId);
            });

    // NWScript: Get a result force-cast to string.
    Events::RegisterEvent(GetName(), "GetResultAsString",
            [&](Events::ArgumentStack && arg)
            {
                const auto resultId = static_cast<uint32_t>(Events::ExtractArgument<int32_t>(arg));

                std::string ret;

                if (resultId < s_results.size())
                {
                    auto& res = s_results[resultId];
                    ret = RedisReplyAsString(res);
                }
                else
                {
                    LOG_ERROR("Result %d was not found or isn't representable as a string. "
                              "This is a error on your side.", resultId);
                }

                return Events::Arguments(ret);
            });

    // NWScript: Get the last pubsub message.
    // Values returned: channel, message
    Events::RegisterEvent(GetName(), "GetPubSubData",
            [&](Events::ArgumentStack &&)
            {
                return Events::Arguments(m_internal->m_last_pubsub_channel, m_internal->m_last_pubsub_message);
            });
}


}
