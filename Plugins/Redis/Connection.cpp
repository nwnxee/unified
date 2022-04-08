#include "Redis.hpp"
#include "Internal.hpp"

#include "Services/Metrics/MetricData.hpp"

#include <thread>
#include <mutex>
#include <chrono>

namespace Redis
{

using namespace NWNXLib;
using namespace NWNXLib::Services;
using namespace std::chrono;


void Redis::LogQuery(const std::vector<std::string>& v, const cpp_redis::reply& r,
                     const uint64_t ns)
{
    if (v.size() == 0)
        return;

    MetricData::Fields fields;
    std::string cmd = v[0];
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
    fields.push_back({"cmd", cmd});

    // This pushes the redis key operated on, unless it's a two-word
    // command, in which case, sorry! (TODO)
    if (v.size() > 1) {
        fields.push_back({"arg0", v[1]});
    }

    fields.push_back({"reply_type", RedisReplyTypeToString(r.get_type())});

    // XXX: this pushes ALL queries. Probably a bad idea.
    // if (v.size() > 2) {
    //     std::vector<std::string> va(&v[2], &v[v.size()-1]);
    //     auto astr = str_implode(va);
    //     fields.push_back({"arg", astr});
    // }

    // Fields:
    // - cmd (extract cmd from query string)
    // - originator (TODO: who requested the query?)
    // - reply_type (redis type to str)
    // Tags:
    // - ns (time taken in ns)
    // - error (for queries resulting in errors only)

    MetricData::Tags tags;
    tags.push_back({"ns", std::to_string(ns)});

    if (r.get_type() == cpp_redis::reply::type::error)
        tags.push_back({"error", r.as_string()});

    GetServices()->m_metrics->Push(
        "Command",
        std::move(fields),
        std::move(tags));

    auto qstr = String::Join(v);
    auto rstr = RedisReplyAsString(r);

    if (r.is_error())
    {
        LOG_ERROR("Query failed: '%s' -> '%s'", qstr, rstr);
    }
    else
    {
        LOG_DEBUG("Query: '%s' -> '%s'", qstr, rstr);
    }
}

template <typename Ret>
Ret Redis::WithConnection(std::function<Ret(cpp_redis::redis_client&)> callmemaybe)
{
    return m_internal->m_redis_pool.Borrow<Ret>(callmemaybe);
}

void Redis::RawAsync(const std::vector<std::string>& v,
                     std::function<void(cpp_redis::reply&)> results)
{
    const auto start = steady_clock::now();

    m_internal->m_redis_pool.Borrow<void>([&](auto & c) {
        c.send(v, [&](auto & r) {
            const auto end = steady_clock::now();
            const auto diff = duration_cast<nanoseconds>(end - start).count();
            this->LogQuery(v, r, static_cast<uint64_t>(diff));

            results(r);
        }).commit();
    });
}

cpp_redis::reply Redis::RawSync(const std::vector<std::string>& v)
{
    const auto start = steady_clock::now();

    return m_internal->m_redis_pool.Borrow<cpp_redis::reply>([&](auto & c) {
        cpp_redis::reply rt;
        c.send(v, [&](auto & r) {
            const auto end = steady_clock::now();
            const auto diff = duration_cast<nanoseconds>(end - start).count();
            this->LogQuery(v, r, static_cast<uint64_t>(diff));

            rt = r;
        }).sync_commit();
        return rt;
    });
}

std::string Redis::Sync(const std::vector<std::string>& v)
{
    return RedisReplyAsString(RawSync(v));
}

std::vector<std::string> Redis::SyncList(const std::vector<std::string>& v)
{
    std::vector<std::string> r;
    auto p = RawSync(v).as_array();
    for (auto& k : p)
        r.push_back(RedisReplyAsString(k));
    return r;
}

}
