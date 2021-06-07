#pragma once

#include "nwnx.hpp"

#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CExoString.hpp"

#include <functional>

namespace cpp_redis
{
class redis_client;
class reply;
}

namespace Redis
{

// We hide all our crap behind this so you can use this plugin header
// without neccessarily pulling in cpp_redis.
struct Internal;

class Redis : public NWNXLib::Plugin
{
public:
    struct Configuration {
        // HOST
        std::string m_host;
        // PORT
        int m_port;

        // TODO:
        // Bridge the internal message bus to redis?
        bool m_bridge_message_bus;
        // The prefix to add to all internal messages (= server prefix)
        std::string m_bridge_message_bus_prefix;

        // PUBSUB_SCRIPT
        std::string m_pubsub_script;
        // PUBSUB_CHANNELS
        std::vector<std::string> m_pubsub_channels;
    };

    Redis(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Redis();

    // Retrieve a free connection to do stuff with. This could be a single
    // connection or one from a pool; no guarantees are made!
    //
    // This call is fully threadsafe.
    template <typename Ret>
    Ret WithConnection(std::function<Ret(cpp_redis::redis_client&)>);

    // Executes a raw redis command synchronously and returns the result.
    // Will raise a redis_cpp::redis_error if things go awry.
    // This call is fully threadsafe.
    cpp_redis::reply RawSync(const std::vector<std::string>&);

    // Executes a query asychronously and calls you when the result comes in.
    // Will raise a redis_cpp::redis_error if things go awry.
    void RawAsync(const std::vector<std::string>&,
                  std::function<void(cpp_redis::reply&)>);

    // Some simple helpers below.
    // These will not require you to pull in cpp_redis.
    // HOWEVER, they are rather lacking in error-handling; for all but the
    // simplest use-cases, using cpp_redis is strongly recommended.
    // I'm not happy with these; I might change or remove them in future releases.

    // Execute a query and return the results force-cast as a string.
    // Null values are returned as empty strings.
    // Values not castable to arrays will return a empty array.
    // Broken queries will result in a std::runtime_error.
    std::string Sync(const std::vector<std::string>&);

    // Execute a query and return the results force-cast as a list.
    // Example: "LRANGE key 0 5"
    // Broken queries will result in a std::runtime_error.
    std::vector<std::string> SyncList(const std::vector<std::string>&);

private:
    Internal* m_internal;

    void Reconfigure();
    void RegisterWithNWScript();
    void HookSCORCO();
    void OnPubsub(const std::string& channel, const std::string& message);
    void LogQuery(const std::vector<std::string>&, const cpp_redis::reply&,
                  const uint64_t ns);
    std::unique_ptr<cpp_redis::redis_client> PoolMakeFunc();

    static inline NWNXLib::Hooks::Hook m_ClearStackHook;
    static void CleanState(CVirtualMachineStack*);
};

}
