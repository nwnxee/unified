#include "SQL.hpp"
#include "Targets/MySQL.hpp"
#include "Targets/PostgreSQL.hpp"
#include "Targets/SQLite.hpp"
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

static SQL::SQL* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new SQL::SQL(services);
    return g_plugin;
}

using namespace NWNXLib::Services;

namespace SQL {

SQL::SQL(Services::ProxyServiceList* services)
    : Plugin(services), m_nextQueryId(0), m_queryMetrics(false)
{

#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
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

    m_queryMetrics = Config::Get<bool>("QUERY_METRICS", false);

    if (m_queryMetrics)
    {
        Resamplers::ResamplerFuncPtr sum = &Resamplers::template Sum<int64_t>;
        GetServices()->m_metrics->SetResampler("SQLQueries", sum, std::chrono::seconds(1));
    }

    auto type = Config::Get<std::string>("TYPE", "MYSQL");
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

    m_utf8 = Config::Get<bool>("USE_UTF8", false);

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
            m_target->Connect();
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
    m_activeQuery = Events::ExtractArgument<std::string>(args);

    if (m_utf8)
    {
        m_activeQuery = String::ToUTF8(m_activeQuery);
    }

    m_activeResults = ResultSet();

    if (!m_target->IsConnected() && !Reconnect(3))
    {
        LOG_ERROR("Database connection lost. Aborting.");
        return Events::Arguments(0);
    }

    m_queryPrepared = m_target->PrepareQuery(m_activeQuery);
    return Events::Arguments(static_cast<int32_t>(m_queryPrepared));
}

Events::ArgumentStack SQL::ExecutePreparedQuery(Events::ArgumentStack&&)
{
    if (!m_queryPrepared)
    {
        LOG_WARNING("Trying to execute prepared query without successful PrepareQuery() call");
        return Events::Arguments(0);
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
            return Events::Arguments(0);
        }
        else
        {
            // Prepared queries are lost on reconnect.
            // Prepared arguments are not, however, so we can still recover
            if (!m_target->PrepareQuery(m_activeQuery))
            {
                LOG_ERROR("Recovery PrepareQuery() failed: %s", m_target->GetLastError());
                return Events::Arguments(0);
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

    return Events::Arguments(querySucceeded ? queryId : 0);
}

Events::ArgumentStack SQL::ReadyToReadNextRow(Events::ArgumentStack&&)
{
    return Events::Arguments(m_activeResults.empty() ? 0 : 1);
}

Events::ArgumentStack SQL::ReadNextRow(Events::ArgumentStack&&)
{
    if (m_activeResults.empty())
    {
        throw std::runtime_error("No more rows to read.");
    }

    m_activeRow = std::move(m_activeResults.front());
    m_activeResults.pop();
    return Events::Arguments();
}

Events::ArgumentStack SQL::ReadDataInActiveRow(Events::ArgumentStack&& args)
{
    const auto column = static_cast<size_t>(Events::ExtractArgument<int32_t>(args));

    if (column >= m_activeRow.size())
    {
        throw std::runtime_error("Trying to access column outside of range.");
    }

    return Events::Arguments(m_utf8 ? String::FromUTF8(m_activeRow[column]) : m_activeRow[column]);
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
    return Events::Arguments();
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
        m_target->PrepareString(position, m_utf8 ? String::ToUTF8(value) : value);
    }
    return Events::Arguments();
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
    return Events::Arguments();
}
Events::ArgumentStack SQL::PreparedObjectId(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<ObjectID>(args);
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
    return Events::Arguments();
}
Events::ArgumentStack SQL::PreparedObjectFull(Events::ArgumentStack&& args)
{
    auto position = Events::ExtractArgument<int32_t>(args);
    auto value = Events::ExtractArgument<ObjectID>(args);
    int32_t base64 = true;
    try
    {
        base64 = Events::ExtractArgument<int32_t>(args);
    }
    catch (std::runtime_error& e){}

    if (position >= m_target->GetPreparedQueryParamCount())
    {
        LOG_WARNING("Prepared argument (pos:%d, value:ObjID-%08x) out of bounds", position, static_cast<int32_t>(value));
    }
    else
    {
        CGameObject *pObject = API::Globals::AppManager()->m_pServerExoApp->GetGameObject(value);
        if (base64) {
            std::string serializedObject = Utils::SerializeGameObjectB64(pObject);
            m_target->PrepareString(position, serializedObject);
        } else {
            std::vector<uint8_t> serializedObjectVec = Utils::SerializeGameObject(pObject);
            m_target->PrepareBinary(position, serializedObjectVec);
        }
    }
    return Events::Arguments();
}

Events::ArgumentStack SQL::ReadFullObjectInActiveRow(Events::ArgumentStack&& args)
{
    const auto column = static_cast<size_t>(Events::ExtractArgument<int32_t>(args));
    const auto owner = Events::ExtractArgument<ObjectID>(args);
    const auto x = Events::ExtractArgument<float>(args);
    const auto y = Events::ExtractArgument<float>(args);
    const auto z = Events::ExtractArgument<float>(args);
    int32_t base64 = true;
    try
    {
        base64 = Events::ExtractArgument<int32_t>(args);
    }
    catch (std::runtime_error& e){}

    if (column >= m_activeRow.size())
    {
        throw std::runtime_error("Trying to access column outside of range.");
    }

    std::string serialized = m_activeRow[column];
    ObjectID retval = API::Constants::OBJECT_INVALID;
    CGameObject *pObject = base64 ? Utils::DeserializeGameObjectB64(serialized) : Utils::DeserializeGameObject(std::vector<uint8_t>(serialized.begin(), serialized.end()));
    if (pObject)
    {
        retval = static_cast<ObjectID>(pObject->m_idSelf);
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
    return Events::Arguments(retval);
}

Events::ArgumentStack SQL::GetAffectedRows(Events::ArgumentStack&&)
{
    return Events::Arguments(m_target->GetAffectedRows());
}

Events::ArgumentStack SQL::GetDatabaseType(Events::ArgumentStack&&)
{
    return Events::Arguments(Config::Get<std::string>("TYPE", "MYSQL"));
}

Events::ArgumentStack SQL::DestroyPreparedQuery(Events::ArgumentStack&&)
{
    m_target->DestroyPreparedQuery();
    m_queryPrepared = false;
    return Events::Arguments();
}

Events::ArgumentStack SQL::GetLastError(Events::ArgumentStack&&)
{
    return Events::Arguments(m_target->GetLastError(true));
}

Events::ArgumentStack SQL::GetPreparedQueryParamCount(Events::ArgumentStack&&)
{
    return Events::Arguments(m_queryPrepared ? m_target->GetPreparedQueryParamCount() : -1);
}

}
