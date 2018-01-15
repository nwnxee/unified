#if defined(NWNX_SQL_MYSQL_SUPPORT)

#include "MySQL.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Log/Log.hpp"

#include <string.h>

namespace SQL {

MySQL::MySQL(NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log)
    : m_log(log)
{
    mysql_init(&m_mysql);
}

MySQL::~MySQL()
{
    mysql_close(&m_mysql);
}

void MySQL::Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config)
{
    const std::string host = config->Get<std::string>("HOST", "localhost");
    const std::string username = config->Require<std::string>("USERNAME");
    const std::string password = config->Require<std::string>("PASSWORD");
    const NWNXLib::Maybe<std::string> database = config->Get<std::string>("DATABASE");

    if (!mysql_real_connect(&m_mysql, host.c_str(), username.c_str(), password.c_str(), database ? (*database).c_str() : nullptr, 0, nullptr, 0))
    {
        throw std::runtime_error(std::string(mysql_error(&m_mysql)));
    }
}

bool MySQL::IsConnected()
{
    return mysql_query(&m_mysql, "SELECT 1") == 0;
}

bool MySQL::PrepareQuery(const Query& query)
{
    if (m_stmt)
        mysql_stmt_close(m_stmt);

    m_stmt = mysql_stmt_init(&m_mysql);
    if (!m_stmt)
    {
        m_lastError.assign(mysql_error(&m_mysql));
        m_log->Warning("Failed to prepare statement: %s", m_lastError.c_str());
        return false;
    }

    bool success = !mysql_stmt_prepare(m_stmt, query.c_str(), query.size());
    if (success)
    {
        m_paramCount = mysql_stmt_param_count(m_stmt);
        m_params.resize(m_paramCount);
        m_paramValues.resize(m_paramCount);
    }
    else
    {
        m_lastError.assign(mysql_stmt_error(m_stmt));
        m_log->Warning("Failed to prepare statement: %s", m_lastError.c_str());
        mysql_stmt_close(m_stmt);
        m_stmt = 0;
    }
    return success;
}

NWNXLib::Maybe<ResultSet> MySQL::ExecuteQuery()
{
    affectedRows = -1;

    bool success = !mysql_stmt_bind_param(m_stmt, m_params.data());
    if (!success)
    {
        m_log->Warning("Failed to bind params");
        m_lastError.assign(mysql_error(&m_mysql));
        return NWNXLib::Maybe<ResultSet>(); // Failed query.
    }

    success = !mysql_stmt_execute(m_stmt);

    if (success)
    {
        MYSQL_RES* mysqlResult = mysql_stmt_result_metadata(m_stmt);

        if (mysqlResult)
        {
            ResultSet results;
            const unsigned columns = mysql_num_fields(mysqlResult);
            mysql_stmt_store_result(m_stmt);

            std::vector<char> buffer(64);
            while (true)
            {
                ResultRow row;
                row.reserve(columns);

                MYSQL_BIND binds[columns];
                memset(binds, 0, sizeof(binds));
                unsigned long lengths[columns];
                for (unsigned i = 0; i < columns; i++)
                    binds[i].length = &lengths[i];
                mysql_stmt_bind_result(m_stmt, binds);

                int fetchResult = mysql_stmt_fetch(m_stmt);
                if (fetchResult == MYSQL_NO_DATA) {
                    break;
                }
                else if (fetchResult == 1) {
                    m_log->Warning("Error executing mysql_stmt_fetch - error: '%s'", mysql_error(&m_mysql));
                    m_lastError.assign(mysql_error(&m_mysql));
                    break;
                }

                for (unsigned i = 0; i < columns; i++)
                {
                    buffer.reserve(lengths[i]);
                    binds[i].buffer = buffer.data();
                    binds[i].buffer_length = buffer.capacity();
                    mysql_stmt_fetch_column(m_stmt, &binds[i], i, 0);
                    row.emplace_back(Result(buffer.data(), lengths[i]));
                }
                results.push(row);
            }
            mysql_free_result(mysqlResult);
            mysql_stmt_free_result(m_stmt);
            return NWNXLib::Maybe<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
        }
        // Statement returned no rows (INSERT, UPDATE, DELETE, etc.)
        affectedRows = mysql_affected_rows(&m_mysql);
        return NWNXLib::Maybe<ResultSet>(ResultSet()); // Succeeded query, no results.
    }

    if (!success)
    {
        const char* error = mysql_error(&m_mysql);

        if (*error == '\0')
        {
            // No valid error.
            error = "Undefined/unknown";
        }

        m_log->Warning("Query failed due to error '%s'", error);
        m_lastError.assign(error);

    }

    return NWNXLib::Maybe<ResultSet>(); // Failed query.
}

void MySQL::PrepareInt(int32_t position, int32_t value)
{
    MYSQL_BIND *pBind = &m_params[position];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[position].n = value;

    pBind->buffer_type = MYSQL_TYPE_LONG;
    pBind->buffer = &m_paramValues[position].n;
}
void MySQL::PrepareFloat(int32_t position, float value)
{
    MYSQL_BIND *pBind = &m_params[position];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[position].f = value;

    pBind->buffer_type = MYSQL_TYPE_FLOAT;
    pBind->buffer = &m_paramValues[position].f;
}
void MySQL::PrepareString(int32_t position, const std::string& value)
{
    MYSQL_BIND *pBind = &m_params[position];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[position].s = value.c_str();

    pBind->buffer_type = MYSQL_TYPE_STRING;
    pBind->buffer = (void*)m_paramValues[position].s.c_str();
    pBind->buffer_length = m_paramValues[position].s.size();
}

int MySQL::GetAffectedRows()
{
    return affectedRows;
}

std::string MySQL::GetLastError()
{
    // This might be overkill, but copy the string  here so the class stored string can be cleared
    // before returning.
    std::string temp = m_lastError;
    m_lastError.clear();
    return temp;
}

int32_t MySQL::GetPreparedQueryParamCount()
{
    return m_paramCount;
}

void MySQL::DestroyPreparedQuery()
{
    if (m_stmt)
    {
        mysql_stmt_close(m_stmt);
        m_stmt = 0;

        // Force deallocation
        std::vector<MYSQL_BIND>().swap(m_params);
        std::vector<Variant>().swap(m_paramValues);
        m_paramCount = 0;
    }
}

}

#endif
