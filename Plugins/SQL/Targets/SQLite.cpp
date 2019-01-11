#if defined(NWNX_SQL_SQLITE_SUPPORT)

#include "SQLite.hpp"
#include "Services/Config/Config.hpp"

#include <string.h>
#include <sqlite3.h>

namespace SQL {

SQLite::SQLite()
{
    m_dbName = "database";
    m_stmt = nullptr;
    m_lastError = "";
    m_paramCount = 0;
}

SQLite::~SQLite()
{
    sqlite3_close(m_dbConn);
}

void SQLite::Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config)
{ 
    if (auto database = config->Get<std::string>("DATABASE"))
    {
        m_dbName = (*database).c_str();

        LOG_DEBUG("DB set to %s", m_dbName.c_str());
    }

    // BAD: This just dumps the DB file in the executable folder, should be user directory
    std::string dbPath = m_dbName + ".sqlite3";
    
    if (sqlite3_open(dbPath.c_str(), &m_dbConn))
    {
        throw std::runtime_error(std::string(sqlite3_errmsg(m_dbConn)));
    }
    
}

bool SQLite::IsConnected()
{
    bool bConnected = sqlite3_exec(m_dbConn, "SELECT 1", NULL, NULL, NULL) == SQLITE_OK; 

    if (!bConnected)
    {
        LOG_WARNING("Disconnected state identified.");
    }

    return bConnected;
}

bool SQLite::PrepareQuery(const Query& query)
{
    LOG_DEBUG("Preparing query %s\n", query.c_str());

    bool success = sqlite3_prepare_v2(m_dbConn, query.c_str(), -1, &m_stmt, NULL) == SQLITE_OK;

    if(success)
    {
        m_paramCount = sqlite3_bind_parameter_count(m_stmt);
        LOG_DEBUG("Detected %d parameters.", m_paramCount);
        m_paramValues.resize(m_paramCount);        
    }
    else
    {
        m_lastError.assign(sqlite3_errmsg(m_dbConn));
        LOG_WARNING("Failed to prepare statement: %s", m_lastError.c_str());
        sqlite3_finalize(m_stmt);
        m_stmt = nullptr;        
    }

    return success;
}

NWNXLib::Maybe<ResultSet> SQLite::ExecuteQuery()
{
    int stepState;
    int columnCount;
    m_affectedRows = -1;

    sqlite3_reset(m_stmt);
    sqlite3_clear_bindings(m_stmt);

    for(unsigned int i = 0; i < m_paramCount; i++)
    {
        int j = i + 1;
        int bindStatus;

        LOG_DEBUG("Binding Text '%i' to: %s", j, m_paramValues[i].c_str());
        bindStatus = sqlite3_bind_text(m_stmt, j, m_paramValues[i].c_str(), -1, NULL);  
        
        if(bindStatus != SQLITE_OK)
        {
            LOG_WARNING("Failed to bind params");
            m_lastError.assign(sqlite3_errmsg(m_dbConn));

            return NWNXLib::Maybe<ResultSet>(); // Failed query.
        }
    }

    columnCount = sqlite3_column_count(m_stmt);
    
    if (!columnCount)
    {// Statement returns no rows (INSERT, UPDATE, DELETE, etc.)
        stepState = sqlite3_step(m_stmt);

        if(stepState == SQLITE_DONE)
        {
            m_affectedRows = sqlite3_changes(m_dbConn);
            return NWNXLib::Maybe<ResultSet>(ResultSet()); // Succeeded query, no results. 
        }   
    }
    else
    {
        ResultSet results;
        
        stepState = sqlite3_step(m_stmt);
        while (stepState == SQLITE_ROW)
        {
            ResultRow row;

            columnCount = sqlite3_column_count(m_stmt);

            row.reserve(columnCount);
            
            for (int col = 0; col < columnCount; col++)
            {
                const char* value = reinterpret_cast<const char*>(sqlite3_column_text(m_stmt, col));
                LOG_DEBUG("Got text = %s", value);
                row.emplace_back(Result(value, sqlite3_column_bytes(m_stmt, col)));
            }

            results.push(row);            

            stepState = sqlite3_step(m_stmt);
        }

        if (stepState == SQLITE_DONE)
        {
            LOG_DEBUG("Returning Result Set");
            return NWNXLib::Maybe<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
        }
    }

    return NWNXLib::Maybe<ResultSet>(); // Failed query.
}

void SQLite::PrepareInt(int32_t position, int32_t value)
{
    LOG_DEBUG("Assigning position %d to value '%d'", position, value);

    ASSERT(position >= 0);
    size_t pos = static_cast<size_t>(position);

    m_paramValues[pos] = std::to_string(value);
    //m_paramValues[pos].n = value;
}

void SQLite::PrepareFloat(int32_t position, float value)
{
    LOG_DEBUG("Assigning position %d to value '%f'", position, value); 

    ASSERT(position >= 0);
    size_t pos = static_cast<size_t>(position);

    m_paramValues[pos] = std::to_string(value);
    //m_paramValues[pos].f = value;  
}

void SQLite::PrepareString(int32_t position, const std::string& value)
{
    LOG_DEBUG("Assigning position %d to value '%s'", position, value.c_str());

    ASSERT(position >= 0);
    size_t pos = static_cast<size_t>(position);

    m_paramValues[pos] = value.c_str();
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
}

}

#endif
