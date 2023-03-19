#include "SQLite.hpp"
#include "API/Globals.hpp"
#include "API/CExoBase.hpp"


namespace SQL {

using namespace NWNXLib;
using namespace NWNXLib::API;

SQLite::SQLite()
{
    m_dbName = "database";
    m_stmt = nullptr;
    m_lastError = "";
    m_paramCount = 0;
}

SQLite::~SQLite()
{
    sqlite3_finalize(m_stmt);
    sqlite3_close(m_dbConn);
}

void SQLite::Connect()
{
    if (auto database = Config::Get<std::string>("DATABASE"))
    {
        m_dbName = database->c_str();

        LOG_INFO("SQLite Database name set to %s", m_dbName);
    }

    // Save the database file to UserDirectory/database
    static std::string dbPath = Globals::ExoBase()->m_sUserDirectory.CStr() + std::string("/database/")
            + m_dbName + std::string(".sqlite3nwnxee");

    if (sqlite3_open(dbPath.c_str(), &m_dbConn))
    {
        throw std::runtime_error(std::string(sqlite3_errmsg(m_dbConn)));
    }

}

bool SQLite::IsConnected()
{
    bool bConnected = sqlite3_exec(m_dbConn, "SELECT 1", nullptr, nullptr, nullptr) == SQLITE_OK;

    if (!bConnected)
    {
        LOG_WARNING("Disconnected state identified.");
    }

    return bConnected;
}

bool SQLite::PrepareQuery(const Query& query)
{
    LOG_DEBUG("Preparing query: %s", query);

    sqlite3_finalize(m_stmt);

    bool success = sqlite3_prepare_v2(m_dbConn, query.c_str(), -1, &m_stmt, nullptr) == SQLITE_OK;

    if (success)
    {
        m_paramCount = sqlite3_bind_parameter_count(m_stmt);
        LOG_DEBUG("Detected %d parameters.", m_paramCount);
        m_paramValues.resize(m_paramCount);
    }
    else
    {
        m_lastError.assign(sqlite3_errmsg(m_dbConn));
        LOG_WARNING("Failed to prepare statement: %s", m_lastError);
        sqlite3_finalize(m_stmt);
        m_stmt = nullptr;
    }

    return success;
}

std::optional<ResultSet> SQLite::ExecuteQuery()
{
    int stepState;
    m_affectedRows = -1;

    sqlite3_reset(m_stmt);
    sqlite3_clear_bindings(m_stmt);

    for (unsigned int i = 0; i < m_paramCount; i++)
    {
        const char* param = m_paramValues[i].has_value() ? m_paramValues[i]->c_str() : nullptr;
        LOG_DEBUG("Binding value '%s' to param '%u'", param, i);
        // Params in SQLite are 1 based
        int bindStatus = sqlite3_bind_text(m_stmt, i + 1, param, -1, nullptr);

        if (bindStatus != SQLITE_OK)
        {
            m_lastError.assign(sqlite3_errmsg(m_dbConn));

            LOG_WARNING("Failed to bind params: %s", m_lastError);

            return std::optional<ResultSet>(); // Failed query, bind error.
        }
    }

    int columnCount = sqlite3_column_count(m_stmt);

    if (!columnCount)
    {// Statement returns no rows (INSERT, UPDATE, DELETE, etc.)
        stepState = sqlite3_step(m_stmt);

        if (stepState == SQLITE_DONE)
        {
            m_affectedRows = sqlite3_changes(m_dbConn);
            return std::make_optional<ResultSet>(ResultSet()); // Succeeded query, no results.
        }
    }
    else
    {
        ResultSet results;

        stepState = sqlite3_step(m_stmt);
        while (stepState == SQLITE_ROW)
        {
            ResultRow row;

            row.reserve(columnCount);

            for (int col = 0; col < columnCount; col++)
            {
                const char* value = reinterpret_cast<const char*>(sqlite3_column_text(m_stmt, col));
                LOG_DEBUG("Got value '%s' from column '%i'", value, col);
                row.emplace_back(Result(value, sqlite3_column_bytes(m_stmt, col)));
            }

            results.push(row);

            stepState = sqlite3_step(m_stmt);
        }

        if (stepState == SQLITE_DONE)
        {
            LOG_DEBUG("Returning Result Set");
            return std::make_optional<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
        }
    }

    m_lastError.assign(sqlite3_errmsg(m_dbConn));
    LOG_WARNING("Query failed due to error '%s'", m_lastError);

    return std::optional<ResultSet>(); // Failed query.
}

void SQLite::PrepareInt(int32_t position, int32_t value)
{
    LOG_DEBUG("Assigning position %d to value '%d'", position, value);

    ASSERT_OR_THROW(position >= 0);

    m_paramValues[position] = std::to_string(value);
}

void SQLite::PrepareFloat(int32_t position, float value)
{
    LOG_DEBUG("Assigning position %d to value '%f'", position, value);

    ASSERT_OR_THROW(position >= 0);

    m_paramValues[position] = std::to_string(value);
}

void SQLite::PrepareString(int32_t position, const std::string& value)
{
    LOG_DEBUG("Assigning position %d to value '%s'", position, value);

    ASSERT_OR_THROW(position >= 0);

    m_paramValues[position] = value;
}

void SQLite::PrepareBinary(int32_t position, const std::vector<uint8_t> &value)
{
    (void)position; (void)value;
    ASSERT_FAIL_MSG("Binary format not implemented for SQLite");
}

void SQLite::PrepareNULL(int32_t position)
{
    LOG_DEBUG("Assigning position %d to value NULL", position);

    ASSERT_OR_THROW(position >= 0);

    m_paramValues[position] = std::nullopt;
}

int SQLite::GetAffectedRows()
{
    return m_affectedRows;
}

std::string SQLite::GetLastError(bool bClear)
{
    // This might be overkill, but copy the string here so the class stored string can be cleared
    // before returning.
    std::string temp = m_lastError;
    if (bClear)
        m_lastError.clear();
    return temp;
}

int32_t SQLite::GetPreparedQueryParamCount()
{
    return static_cast<int32_t>(m_paramCount);
}

void SQLite::DestroyPreparedQuery()
{
    sqlite3_finalize(m_stmt);
    m_stmt = nullptr;

    // Force deallocation
    std::vector<std::optional<std::string>>().swap(m_paramValues);
    m_paramCount = 0;
}

}
