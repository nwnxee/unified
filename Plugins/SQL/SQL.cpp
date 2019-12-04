#include "SQL.hpp"
#include "Targets/MySQL.hpp"
#include "Targets/PostgreSQL.hpp"
#include "Targets/SQLite.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "ViewPtr.hpp"
#include "Serialize.hpp"
#include "Utils.hpp"
#include "Encoding.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp" // Needed for static_cast from CGameObject
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstring>

using namespace NWNXLib;

static ViewPtr<SQL::SQL> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "SQL",
        "Execute queries and retrieve results from an SQL database.",
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

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(PrepareQuery);
    REGISTER(ExecutePreparedQuery);
    REGISTER(ReadyToReadNextRow);
    REGISTER(ReadNextRow);
    REGISTER(ReadDataInActiveRow);
    REGISTER(PreparedInt);
    REGISTER(PreparedString);
    REGISTER(PreparedFloat);
    REGISTER(PreparedObjectId);
    REGISTER(PreparedObjectFull);
    REGISTER(ReadFullObjectInActiveRow);
    REGISTER(GetAffectedRows);
    REGISTER(GetDatabaseType);
    REGISTER(DestroyPreparedQuery);
    REGISTER(GetLastError);
    REGISTER(GetPreparedQueryParamCount);

#undef REGISTER

    m_queryMetrics = GetServices()->m_config->Get<bool>("QUERY_METRICS", false);

    if (m_queryMetrics)
    {
        Resamplers::ResamplerFuncPtr sum = &Resamplers::template Sum<int64_t>;
        GetServices()->m_metrics->SetResampler("SQLQueries", sum, std::chrono::seconds(1));
    }

    auto type = GetServices()->m_config->Get<std::string>("TYPE", "MYSQL");
    std::transform(std::begin(type), std::end(type), std::begin(type), ::toupper);

    LOG_INFO("Connecting to type %s", type);
    if (type == "MYSQL")
    {
#if defined(NWNX_SQL_MYSQL_SUPPORT)
        m_target = std::make_unique<MySQL>();
#else
        throw std::runtime_error("Targeting MySQL, but no MySQL support built in.");
#endif
    }
    else if (type == "POSTGRESQL")
    {
#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)
        m_target = std::make_unique<PostgreSQL>();
#else
        throw std::runtime_error("Targeting PostgreSQL, but no PostgreSQL support built in.");
#endif
    }
    else if (type == "SQLITE")
    {
#if defined(NWNX_SQL_SQLITE_SUPPORT)
        m_target = std::make_unique<SQLite>();
#else
        throw std::runtime_error("Targeting SQLite3, but no SQLite3 support built in.");
#endif
    }
    else
    {
        throw std::runtime_error("Invalid database type selected.");
    }

    m_utf8 = GetServices()->m_config->Get<bool>("USE_UTF8", false);

    Reconnect(19);
}

SQL::~SQL()
{
}

bool SQL::Reconnect(int32_t attempts)
{
    LOG_WARNING("Database connection lost. Reconnecting..");

    for (int32_t i = 0; i < attempts; i++)
    {
        try
        {
            m_target->Connect(GetServices()->m_config);
            LOG_NOTICE("Reconnect successful.");
            break;
        }
        catch (std::runtime_error& e)
        {
            LOG_ERROR("Reconnect attempt %d out of %d failed: %s",
                i+1, attempts, e.what());

            // NOTE: We are on the main thread and cannot sleep for to long, as
            // it will stall the entire server. If a reconnect fails here, the
            // user requested operation will fail as well. It is then up to the
            // user to retry later (e.g. Use DelayCommand()), and another
            // reconnect attempt will be triggered automatically.
            if (i != attempts - 1)
                std::this_thread::sleep_for(std::chrono::milliseconds(1 << i));
        }
    }
    return m_target->IsConnected();
}

Events::ArgumentStack SQL::PrepareQuery(Events::ArgumentStack&& args)
{
    Events::ArgumentStack stack;

    m_activeQuery = Events::ExtractArgument<std::string>(args);

    if (m_utf8)
    {
        m_activeQuery = Encoding::ToUTF8(m_activeQuery);
    }

    m_activeResults = ResultSet();

    if (!m_target->IsConnected() && !Reconnect(3))
    {
        LOG_ERROR("Database connection lost. Aborting.");
        Events::InsertArgument(stack, 0);
        return stack;
    }

    m_queryPrepared = m_target->PrepareQuery(m_activeQuery);
    Events::InsertArgument(stack, static_cast<int32_t>(m_queryPrepared));
    return stack;
}

Events::ArgumentStack SQL::ExecutePreparedQuery(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;

    if (!m_queryPrepared)
    {
        LOG_WARNING("Trying to execute prepared query without successful PrepareQuery() call");
        Events::InsertArgument(stack, 0);
        return stack;
    }

    // NOTE: There is a time-of-check-to-time-of-use race condition here.
    // The target may be there at the check, but will go away afterwards.
    // In these cases the reconnect will not be attempted, and the call will fail.
    // It is up to the user to check the return value, and repeat the query if needed.
    if (!m_target->IsConnected())
    {
        LOG_DEBUG("Not Connected");
        if (!Reconnect())
        {
            LOG_ERROR("Database connection lost. Aborting.");
            Events::InsertArgument(stack, 0);
            return stack;
        }
        else
        {
            // Prepared queries are lost on reconnect.
            // Prepared arguments are not, however, so we can still recover
            if (!m_target->PrepareQuery(m_activeQuery))
            {
                LOG_ERROR("Recovery PrepareQuery() failed: %s", m_target->GetLastError());
                Events::InsertArgument(stack, 0);
                return stack;
            }

        }
    }

    const int32_t queryId = ++m_nextQueryId;

    std::optional<ResultSet> query;

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

    const bool querySucceeded = query.has_value();

    Events::InsertArgument(stack, querySucceeded ? queryId : 0);
    m_activeResults = query.value_or(ResultSet());

    if (querySucceeded)
    {
        // queries that execute commands return the number of affected rows.
        // queries that fetch results return a results size.
        if (m_target->GetAffectedRows() >= 0)
        {
            // this was not a result set type query
            LOG_INFO("Successful SQL query. Query ID: '%i', Query: '%s', Rows affected: '%u'.",
                queryId, m_activeQuery, m_target->GetAffectedRows());
        }
        else
        {
            LOG_INFO("Successful SQL query. Query ID: '%i', Query: '%s', Results Count: '%u'.",
                queryId, m_activeQuery, m_activeResults.size());
        }
    }
    else
    {
        LOG_WARNING("Failed SQL query. Query ID: '%i', Query: '%s'.", queryId, m_activeQuery);
        std::string lastError = m_target->GetLastError();
        LOG_WARNING("Failure Message. Query ID: '%i', \"%s\"", queryId, lastError);
    }

    return stack;
}

Events::ArgumentStack SQL::ReadyToReadNextRow(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_activeResults.empty() ? 0 : 1);
    return stack;
}

Events::ArgumentStack SQL::ReadNextRow(Events::ArgumentStack&&)
{
    if (m_activeResults.empty())
    {
        throw std::runtime_error("No more rows to read.");
    }

    m_activeRow = std::move(m_activeResults.front());
    m_activeResults.pop();
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::ReadDataInActiveRow(Events::ArgumentStack&& args)
{
    const auto column = static_cast<size_t>(Events::ExtractArgument<int32_t>(args));

    if (column >= m_activeRow.size())
    {
        throw std::runtime_error("Trying to access column outside of range.");
    }

    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_utf8 ? Encoding::FromUTF8(m_activeRow[column]) : m_activeRow[column]);
    return stack;
}
Events::ArgumentStack SQL::PreparedInt(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<int32_t>(args);
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        LOG_WARNING("Prepared argument (pos:%d, value:0x%08x) out of bounds", position, value);
    }
    else
    {
        m_target->PrepareInt(position, value);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::PreparedString(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<std::string>(args);
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        LOG_WARNING("Prepared argument (pos:%d, value:'%s') out of bounds", position, value);
    }
    else
    {
        m_target->PrepareString(position, m_utf8 ? Encoding::ToUTF8(value) : value);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::PreparedFloat(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<float>(args);
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        LOG_WARNING("Prepared argument (pos:%d, value:'%f') out of bounds", position, value);
    }
    else
    {
        m_target->PrepareFloat(position, value);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::PreparedObjectId(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<API::Types::ObjectID>(args);
    int32_t valInt;
    std::memcpy(&valInt, &value, sizeof(valInt)); static_assert(sizeof(valInt) == sizeof(value));
    if (position >= m_target->GetPreparedQueryParamCount())
    {
        LOG_WARNING("Prepared argument (pos:%d, value:ObjID-%08x) out of bounds", position, valInt);
    }
    else
    {
        m_target->PrepareInt(position, valInt);
    }
    return Events::ArgumentStack();
}
Events::ArgumentStack SQL::PreparedObjectFull(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<API::Types::ObjectID>(args);

    if (position >= m_target->GetPreparedQueryParamCount())
    {
        LOG_WARNING("Prepared argument (pos:%d, value:ObjID-%08x) out of bounds", position, static_cast<int32_t>(value));
    }
    else
    {
        CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(value);
        m_target->PrepareString(position, SerializeGameObjectB64(pObject));
    }
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::ReadFullObjectInActiveRow(Events::ArgumentStack&& args)
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
    if (CGameObject *pObject = DeserializeGameObjectB64(serialized))
    {
        retval = static_cast<API::Types::ObjectID>(pObject->m_idSelf);
        ASSERT(API::Globals::AppManager()->m_pServerExoApp->GetGameObject(retval));

        CGameObject *pOwner = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(owner);
        if (auto *pArea = Utils::AsNWSArea(pOwner))
        {
            if (!Utils::AddToArea(pObject, pArea, x, y, z))
                LOG_WARNING("Failed to add object %x to area %x (%f,%f,%f)", retval, owner, x, y, z);
        }
        else if (auto *pItem = Utils::AsNWSItem(pObject))
        {
            if (!Utils::AcquireItem(pItem, pOwner))
                LOG_WARNING("Failed to 'acquire' deserialized item %x by owner %x", retval, owner);
        }
        else
        {
            LOG_INFO("No valid owner given, object %x deserialized outside world bounds", retval);
        }
    }
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, retval);
    return stack;
}

Events::ArgumentStack SQL::GetAffectedRows(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_target->GetAffectedRows());
    return stack;
}

Events::ArgumentStack SQL::GetDatabaseType(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, GetServices()->m_config->Get<std::string>("TYPE", "MYSQL"));
    return stack;
}

Events::ArgumentStack SQL::DestroyPreparedQuery(Events::ArgumentStack&&)
{
    m_target->DestroyPreparedQuery();
    m_queryPrepared = false;
    return Events::ArgumentStack();
}

Events::ArgumentStack SQL::GetLastError(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_target->GetLastError(true));
    return stack;
}

Events::ArgumentStack SQL::GetPreparedQueryParamCount(Events::ArgumentStack&&)
{
    Events::ArgumentStack stack;
    Events::InsertArgument(stack, m_queryPrepared ? m_target->GetPreparedQueryParamCount() : -1);
    return stack;
}

}
