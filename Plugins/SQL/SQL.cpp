#include "SQL.hpp"
#include "Targets/MySQL.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "ViewPtr.hpp"
#include <algorithm>
#include <chrono>

using namespace NWNXLib;

static ViewPtr<SQL::SQL> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "SQL",
        "Execute queries and retrieve results from an SQL database..",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new SQL::SQL(params);
    return g_plugin;
}

using namespace NWNXLib::Services;

namespace SQL {

SQL::SQL(const Plugin::CreateParams& params)
    : Plugin(params), m_nextQueryId(0), m_queryMetrics(false)
{
    GetServices()->m_events->RegisterEvent("PREPARE_QUERY", std::bind(&SQL::OnPrepareQuery, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("EXECUTE_QUERY", std::bind(&SQL::OnExecuteQuery, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READY_TO_READ_NEXT_ROW", std::bind(&SQL::OnReadyToReadNextRow, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READ_NEXT_ROW", std::bind(&SQL::OnReadNextRow, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READ_DATA_IN_ACTIVE_ROW", std::bind(&SQL::OnReadDataInActiveRow, this, std::placeholders::_1));

    m_queryMetrics = GetServices()->m_config->Get<bool>("QUERY_METRICS", false);

    if (m_queryMetrics)
    {
        Resamplers::ResamplerFuncPtr sum = &Resamplers::template Sum<int64_t>;
        GetServices()->m_metrics->SetResampler("SQLQueries", sum, std::chrono::seconds(1));
    }

    std::string type = GetServices()->m_config->Get<std::string>("TYPE", "MYSQL");
    std::transform(std::begin(type), std::end(type), std::begin(type), ::toupper);

    if (type == "MYSQL")
    {
#if defined(NWNX_SQL_MYSQL_SUPPORT)
        m_target = std::make_unique<MySQL>(GetServices()->m_log);
#else
        throw std::runtime_error("Targetting MySQL, but no MySQL support built in.");
#endif
    }
    else
    {
        throw std::runtime_error("Invalid database type selected.");
    }

    m_target->Connect(GetServices()->m_config);
}

SQL::~SQL()
{
}

Events::ArgumentStack SQL::OnPrepareQuery(Events::ArgumentStack&& args)
{
    m_activeQuery = Events::ExtractArgument<std::string>(args);
    m_activeResults = ResultSet();
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::OnExecuteQuery(Events::ArgumentStack&&)
{
    const int32_t queryId = ++m_nextQueryId;

    Maybe<ResultSet> query;

    if (m_queryMetrics)
    {
        const auto timeBefore = std::chrono::high_resolution_clock::now();
        query = m_target->ExecuteQuery(m_activeQuery);
        const auto timeAfter = std::chrono::high_resolution_clock::now();

        using namespace std::chrono;
        nanoseconds dur = duration_cast<nanoseconds>(timeAfter - timeBefore);

        GetServices()->m_metrics->Push(
            "SQLQueries",
            { { "ns", std::to_string(dur.count()) } },
            { { "ID", std::to_string(queryId) } });
    }
    else
    {
        query = m_target->ExecuteQuery(m_activeQuery);
    }

    const bool querySucceeded = query;

    Events::ArgumentStack stack;
    Events::InsertArgument(stack, querySucceeded ? queryId : 0);
    m_activeResults = query.Extract(ResultSet());

    GetServices()->m_log->Info("%s SQL query. Query ID: '%i', Query: '%s', Results Count: '%u'.",
        querySucceeded ? "Succeeded" : "Failed", queryId, m_activeQuery.c_str(), m_activeResults.size());

    return stack;
}

Events::ArgumentStack SQL::OnReadyToReadNextRow(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_activeResults.empty() ? 0 : 1);
    return stack;
}

Events::ArgumentStack SQL::OnReadNextRow(Events::ArgumentStack&&)
{
    if (m_activeResults.empty())
    {
        throw std::runtime_error("No more rows to read.");
    }

    m_activeRow = std::move(m_activeResults.front());
    m_activeResults.pop();
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::OnReadDataInActiveRow(Events::ArgumentStack&& args)
{
    const auto column = static_cast<size_t>(Events::ExtractArgument<int32_t>(args));

    if (column >= m_activeRow.size())
    {
        throw std::runtime_error("Trying to access column outside of range.");
    }

    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_activeRow[column]);
    return stack;
}

}
