#pragma once

#include "nwnx.hpp"
#include "Pool.hpp"

#include "Targets/ITarget.hpp"

#include <atomic>
#include <memory>
#include <chrono>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace SQL {

class SQL : public NWNXLib::Plugin
{
public:
    SQL(NWNXLib::Services::ProxyServiceList* services);
    virtual ~SQL();

    ArgumentStack PrepareQuery                  (ArgumentStack&& args);
    ArgumentStack ExecutePreparedQuery          (ArgumentStack&& args);
    ArgumentStack ExecutePreparedQueryAsync     (ArgumentStack&& args);
    ArgumentStack ReadyToReadNextRow            (ArgumentStack&& args);
    ArgumentStack ReadNextRow                   (ArgumentStack&& args);
    ArgumentStack ReadDataInActiveRow           (ArgumentStack&& args);
    ArgumentStack PreparedInt                   (ArgumentStack&& args);
    ArgumentStack PreparedString                (ArgumentStack&& args);
    ArgumentStack PreparedFloat                 (ArgumentStack&& args);
    ArgumentStack PreparedObjectId              (ArgumentStack&& args);
    ArgumentStack PreparedObjectFull            (ArgumentStack&& args);
    ArgumentStack PreparedNULL                  (ArgumentStack&& args);
    ArgumentStack ReadFullObjectInActiveRow     (ArgumentStack&& args);
    ArgumentStack GetAffectedRows               (ArgumentStack&& args);
    ArgumentStack GetDatabaseType               (ArgumentStack&& args);
    ArgumentStack DestroyPreparedQuery          (ArgumentStack&& args);
    ArgumentStack GetLastError                  (ArgumentStack&& args);
    ArgumentStack GetPreparedQueryParamCount    (ArgumentStack&& args);

private:
    std::string m_type;

    NWNXLib::Pool<ITarget> m_pool;

    std::unique_ptr<ITarget> MakeInstance();

    struct QueryContext {
        explicit QueryContext(SQL* parent) :
            m_queryId(0),
            m_parent(parent),
            m_target(parent->m_pool.Take()),
            m_activeQuery(""),
            m_queryPrepared(false)
        {
        }

        virtual ~QueryContext()
        {
            m_parent->m_pool.Give(std::move(m_target));
        }

        bool ExecuteQuery();

        bool Reconnect(int32_t attempts = 1);

        uint32_t m_queryId;
        SQL* m_parent;

        std::unique_ptr<ITarget> m_target;
        std::string m_scriptWhenComplete;

        Query m_activeQuery;
        ResultSet m_activeResults;
        ResultRow m_activeRow;
        bool m_queryPrepared;
        std::chrono::nanoseconds m_duration;
    };

    std::shared_ptr<QueryContext> m_context;

    std::atomic_uint32_t m_nextQueryId;

    bool m_queryMetrics;

    bool m_utf8;
};

}
