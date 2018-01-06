#include "SQL.hpp"
#include "Targets/MySQL.hpp"
#include "Targets/PostgreSQL.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "ViewPtr.hpp"
#include "Serialize.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp" // Needed for static_cast from CGameObject
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
    GetServices()->m_events->RegisterEvent("EXECUTE_PREPARED_QUERY", std::bind(&SQL::OnExecutePreparedQuery, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READY_TO_READ_NEXT_ROW", std::bind(&SQL::OnReadyToReadNextRow, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READ_NEXT_ROW", std::bind(&SQL::OnReadNextRow, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READ_DATA_IN_ACTIVE_ROW", std::bind(&SQL::OnReadDataInActiveRow, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PREPARED_INT", std::bind(&SQL::OnPreparedInt, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PREPARED_STRING", std::bind(&SQL::OnPreparedString, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PREPARED_FLOAT", std::bind(&SQL::OnPreparedFloat, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PREPARED_OBJECT_ID", std::bind(&SQL::OnPreparedObjectId, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("PREPARED_OBJECT_FULL", std::bind(&SQL::OnPreparedObjectFull, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("READ_FULL_OBJECT_IN_ACTIVE_ROW", std::bind(&SQL::OnReadFullObjectInActiveRow, this, std::placeholders::_1));
    GetServices()->m_events->RegisterEvent("GET_AFFECTED_ROWS", std::bind(&SQL::OnGetAffectedRows, this, std::placeholders::_1));

    m_queryMetrics = GetServices()->m_config->Get<bool>("QUERY_METRICS", false);

    if (m_queryMetrics)
    {
        Resamplers::ResamplerFuncPtr sum = &Resamplers::template Sum<int64_t>;
        GetServices()->m_metrics->SetResampler("SQLQueries", sum, std::chrono::seconds(1));
    }

    std::string type = GetServices()->m_config->Get<std::string>("TYPE", "MYSQL");
    std::transform(std::begin(type), std::end(type), std::begin(type), ::toupper);

    GetServices()->m_log->Info("Connecting to type %s", type.c_str());
    if (type == "MYSQL")
    {
#if defined(NWNX_SQL_MYSQL_SUPPORT)
        m_target = std::make_unique<MySQL>(GetServices()->m_log);
#else
        throw std::runtime_error("Targeting MySQL, but no MySQL support built in.");
#endif
    }
    else if (type == "POSTGRESQL")
    {
#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)
        m_target = std::make_unique<PostgreSQL>(GetServices()->m_log);
#else
        throw std::runtime_error("Targeting PostgreSQL, but no PostgreSQL support built in.");
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
    Events::ArgumentStack stack;

    m_activeQuery = Events::ExtractArgument<std::string>(args);
    m_activeResults = ResultSet();

    Events::InsertArgument(stack, static_cast<int32_t>(m_target->PrepareQuery(m_activeQuery)));
    return stack;
}

Events::ArgumentStack SQL::OnExecutePreparedQuery(Events::ArgumentStack&&)
{
    const int32_t queryId = ++m_nextQueryId;

    Maybe<ResultSet> query;

    if (m_queryMetrics)
    {
        const auto timeBefore = std::chrono::high_resolution_clock::now();
        query = m_target->ExecuteQuery();
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
        query = m_target->ExecuteQuery();
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
Events::ArgumentStack SQL::OnPreparedInt(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    int32_t value = Events::ExtractArgument<int32_t>(args);
    m_target->PrepareInt(position, value);
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedString(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    std::string value = Events::ExtractArgument<std::string>(args);
    m_target->PrepareString(position, value);
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedFloat(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    float value = Events::ExtractArgument<float>(args);
    m_target->PrepareFloat(position, value);
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedObjectId(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    API::Types::ObjectID value = Events::ExtractArgument<API::Types::ObjectID>(args);
    m_target->PrepareInt(position, static_cast<int32_t>(value));
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedObjectFull(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    API::Types::ObjectID value = Events::ExtractArgument<API::Types::ObjectID>(args);

    API::CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(value);
    m_target->PrepareString(position, SerializeGameObjectB64(pObject));
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::OnReadFullObjectInActiveRow(Events::ArgumentStack&& args)
{
    const auto column = static_cast<size_t>(Events::ExtractArgument<int32_t>(args));
    const auto owner = Events::ExtractArgument<API::Types::ObjectID>(args);
    const auto x = Events::ExtractArgument<float>(args);
    const auto y = Events::ExtractArgument<float>(args);
    const auto z = Events::ExtractArgument<float>(args);

    if (column >= m_activeRow.size())
    {
        throw std::runtime_error("Trying to access column outside of range.");
    }

    std::string serialized = m_activeRow[column];
    API::Types::ObjectID retval = API::Constants::OBJECT_INVALID;
    if (API::CGameObject *pObject = DeserializeGameObjectB64(serialized))
    {
        retval = static_cast<API::Types::ObjectID>(pObject->m_idSelf);
        assert(API::Globals::AppManager()->m_pServerExoApp->GetGameObject(retval));
        if (pObject->m_nObjectType == API::Constants::OBJECT_TYPE_ITEM)
        {
            API::CGameObject *pOwner = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(owner);
            if (!AcquireDeserializedItem(static_cast<API::CNWSItem*>(pObject), pOwner, x, y, z))
            {
                GetServices()->m_log->Warning("Failed to 'acquire' deserialized item %x", retval);
            }
        }
    }
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, retval);
    return stack;
}

Events::ArgumentStack SQL::OnGetAffectedRows(Events::ArgumentStack&&)
{
	Events::ArgumentStack stack;
	Events::InsertArgument(stack, m_target->GetAffectedRows());
	return stack;
}

}
