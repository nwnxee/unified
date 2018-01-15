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

#define REGISTER(name, func) \
    GetServices()->m_events->RegisterEvent(name, std::bind(&SQL::func, this, std::placeholders::_1))

    REGISTER("PREPARE_QUERY",                  OnPrepareQuery);
    REGISTER("EXECUTE_PREPARED_QUERY",         OnExecutePreparedQuery);
    REGISTER("READY_TO_READ_NEXT_ROW",         OnReadyToReadNextRow);
    REGISTER("READ_NEXT_ROW",                  OnReadNextRow);
    REGISTER("READ_DATA_IN_ACTIVE_ROW",        OnReadDataInActiveRow);
    REGISTER("PREPARED_INT",                   OnPreparedInt);
    REGISTER("PREPARED_STRING",                OnPreparedString);
    REGISTER("PREPARED_FLOAT",                 OnPreparedFloat);
    REGISTER("PREPARED_OBJECT_ID",             OnPreparedObjectId);
    REGISTER("PREPARED_OBJECT_FULL",           OnPreparedObjectFull);
    REGISTER("READ_FULL_OBJECT_IN_ACTIVE_ROW", OnReadFullObjectInActiveRow);
    REGISTER("GET_AFFECTED_ROWS",              OnGetAffectedRows);
    REGISTER("GET_DATABASE_TYPE",              OnGetDatabaseType);
    REGISTER("DESTROY_PREPARED_QUERY",         OnDestroyPreparedQuery);
    REGISTER("GET_LAST_ERROR",                 OnGetLastError);
    REGISTER("GET_PREPARED_QUERY_PARAM_COUNT", OnGetPreparedQueryParamCount);
#undef REGISTER

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

    m_queryPrepared = m_target->PrepareQuery(m_activeQuery);
    Events::InsertArgument(stack, static_cast<int32_t>(m_queryPrepared));
    return stack;
}

Events::ArgumentStack SQL::OnExecutePreparedQuery(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;

    if (!m_queryPrepared)
    {
        GetServices()->m_log->Warning("Trying to execute prepared query without successful PrepareQuery() call");
        Events::InsertArgument(stack, 0);
        return stack;
    }

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

    Events::InsertArgument(stack, querySucceeded ? queryId : 0);
    m_activeResults = query.Extract(ResultSet());

    if (querySucceeded)
    {
        GetServices()->m_log->Info("Successful SQL query. Query ID: '%i', Query: '%s', Results Count: '%u'.",
            queryId, m_activeQuery.c_str(), m_activeResults.size());
    }
    else
    {
        GetServices()->m_log->Warning("Failed SQL query. Query ID: '%i', Query: '%s'.",
            queryId, m_activeQuery.c_str());
        std::string lastError = m_target->GetLastError();
        GetServices()->m_log->Warning("Failure Message. Query ID: '%i', \"%s\"",
            queryId, lastError.c_str());
    }

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
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        GetServices()->m_log->Warning("Prepared argument (pos:%d, value:0x%08x) out of bounds",
            position, value);
    }
    else
    {
        m_target->PrepareInt(position, value);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedString(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    std::string value = Events::ExtractArgument<std::string>(args);
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        GetServices()->m_log->Warning("Prepared argument (pos:%d, value:'%s') out of bounds",
            position, value.c_str());
    }
    else
    {
        m_target->PrepareString(position, value);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedFloat(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    float value = Events::ExtractArgument<float>(args);
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        GetServices()->m_log->Warning("Prepared argument (pos:%d, value:'%f') out of bounds",
            position, value);
    }
    else
    {
        m_target->PrepareFloat(position, value);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedObjectId(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    API::Types::ObjectID value = Events::ExtractArgument<API::Types::ObjectID>(args);
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        GetServices()->m_log->Warning("Prepared argument (pos:%d, value:ObjID-%08x) out of bounds",
            position, static_cast<int32_t>(value));
    }
    else
    {
        m_target->PrepareInt(position, static_cast<int32_t>(value));
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::OnPreparedObjectFull(Events::ArgumentStack&& args)
{
    int32_t position = Events::ExtractArgument<int32_t>(args);
    API::Types::ObjectID value = Events::ExtractArgument<API::Types::ObjectID>(args);

    if (position >= m_target->GetPreparedQueryParamCount())
    {
        GetServices()->m_log->Warning("Prepared argument (pos:%d, value:ObjID-%08x) out of bounds",
            position, static_cast<int32_t>(value));
    }
    else
    {
        API::CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(value);
        m_target->PrepareString(position, SerializeGameObjectB64(pObject));
    }
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

Events::ArgumentStack SQL::OnGetDatabaseType(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, GetServices()->m_config->Get<std::string>("TYPE", "MYSQL"));
    return stack;
}

Events::ArgumentStack SQL::OnDestroyPreparedQuery(Events::ArgumentStack&&)
{
    m_target->DestroyPreparedQuery();
    m_queryPrepared = false;
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::OnGetLastError(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_target->GetLastError());
    return stack;
}


Events::ArgumentStack SQL::OnGetPreparedQueryParamCount(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_queryPrepared ? m_target->GetPreparedQueryParamCount() : -1);
    return stack;
}

}
