#if defined(NWNX_SQL_MYSQL_SUPPORT)

#include "MySQL.hpp"

#include <string.h>

using namespace NWNXLib;

namespace SQL {

MySQL::MySQL()
{
    mysql_init(&m_mysql);
    m_stmt = nullptr;
    m_lastError = "";
    m_paramCount = 0;
}

MySQL::~MySQL()
{
    mysql_close(&m_mysql);
}

void MySQL::Connect()
{
    const auto host     =  Config::Get<std::string>("HOST", "localhost");
    const auto port     =  Config::Get<int32_t>("PORT", 0);
    const auto username = *Config::Get<std::string>("USERNAME");
    const auto password = *Config::Get<std::string>("PASSWORD");
    const auto database =  Config::Get<std::string>("DATABASE");
    if (database)
    {
        LOG_DEBUG("DB set to %s", (*database));
    }

    LOG_INFO("Connection info:  host=%s port=%i username=%s", host, port == 0 ? 3306 : port, username);
    LOG_DEBUG("               :  password=%s", password);

    if (!mysql_real_connect(&m_mysql, host.c_str(), username.c_str(), password.c_str(),
            database ? (*database).c_str() : nullptr, port >= 0 ? port : 0, nullptr, 0))
    {
        throw std::runtime_error(std::string(mysql_error(&m_mysql)));
    }

    if (auto charset = Config::Get<std::string>("CHARACTER_SET"))
    {
        LOG_INFO("Connection character set is '%s'", *charset);
        if (mysql_set_character_set(&m_mysql, charset->c_str()))
            LOG_ERROR("Unable to set the character set");
    }
}

bool MySQL::IsConnected()
{
    bool bConnected = mysql_query(&m_mysql, "SELECT 1") == 0;

    // Need to read the result before running any other queries.
    mysql_free_result(mysql_store_result(&m_mysql));

    if (!bConnected)
    {
        LOG_WARNING("Disconnected state identified.");
    }
    return bConnected;
}

bool MySQL::PrepareQuery(const Query& query)
{
    LOG_DEBUG("Preparing query %s\n", query);

    if (m_stmt)
        mysql_stmt_close(m_stmt);

    m_stmt = mysql_stmt_init(&m_mysql);
    if (!m_stmt)
    {
        m_lastError.assign(mysql_error(&m_mysql));
        LOG_WARNING("Failed to initialize statement: %s", m_lastError);
        return false;
    }

    bool success = !mysql_stmt_prepare(m_stmt, query.c_str(), query.size());
    if (success)
    {
        m_paramCount = mysql_stmt_param_count(m_stmt);
        LOG_DEBUG("Detected %d parameters.", m_paramCount);
        m_params.resize(m_paramCount);
        m_paramValues.resize(m_paramCount);
    }
    else
    {
        m_lastError.assign(mysql_stmt_error(m_stmt));
        LOG_WARNING("Failed to prepare statement: %s", m_lastError);
        mysql_stmt_close(m_stmt);
        m_stmt = nullptr;
    }
    return success;
}

std::optional<ResultSet> MySQL::ExecuteQuery()
{
    affectedRows = -1;

    bool success = !mysql_stmt_bind_param(m_stmt, m_params.data());
    if (!success)
    {
        LOG_WARNING("Failed to bind params");
        m_lastError.assign(mysql_error(&m_mysql));
        return std::optional<ResultSet>(); // Failed query.
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
                memset(lengths, 0, sizeof(lengths));
                for (unsigned i = 0; i < columns; i++)
                    binds[i].length = &lengths[i];
                mysql_stmt_bind_result(m_stmt, binds);

                int fetchResult = mysql_stmt_fetch(m_stmt);
                if (fetchResult == MYSQL_NO_DATA) {
                    break;
                }
                else if (fetchResult == 1) {
                    LOG_WARNING("Error executing mysql_stmt_fetch - error: '%s'", mysql_error(&m_mysql));
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
            return std::make_optional<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
        }
        // Statement returned no rows (INSERT, UPDATE, DELETE, etc.)
        affectedRows = static_cast<int>(mysql_affected_rows(&m_mysql));
        return std::make_optional<ResultSet>(ResultSet()); // Succeeded query, no results.
    }

    if (!success)
    {
        const char* error = mysql_error(&m_mysql);

        if (*error == '\0')
        {
            // No valid error.
            error = "Undefined/unknown";
        }

        LOG_WARNING("Query failed due to error '%s'", error);
        m_lastError.assign(error);

    }

    return std::optional<ResultSet>(); // Failed query.
}

void MySQL::PrepareInt(int32_t position, int32_t value)
{
    LOG_DEBUG("Assigning position %d to value '%d'", position, value);

    ASSERT_OR_THROW(position >= 0);
    size_t pos = static_cast<size_t>(position);

    MYSQL_BIND *pBind = &m_params[pos];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[pos].n = value;

    pBind->buffer_type = MYSQL_TYPE_LONG;
    pBind->buffer = &m_paramValues[pos].n;
}
void MySQL::PrepareFloat(int32_t position, float value)
{
    LOG_DEBUG("Assigning position %d to value '%f'", position, value);

    ASSERT_OR_THROW(position >= 0);
    size_t pos = static_cast<size_t>(position);

    MYSQL_BIND *pBind = &m_params[pos];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[pos].f = value;

    pBind->buffer_type = MYSQL_TYPE_FLOAT;
    pBind->buffer = &m_paramValues[pos].f;
}
void MySQL::PrepareString(int32_t position, const std::string& value)
{
    LOG_DEBUG("Assigning position %d to value '%s'", position, value);

    ASSERT_OR_THROW(position >= 0);
    size_t pos = static_cast<size_t>(position);

    MYSQL_BIND *pBind = &m_params[pos];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[pos].s = value.c_str();

    pBind->buffer_type = MYSQL_TYPE_STRING;
    pBind->buffer = (void*)m_paramValues[pos].s.c_str();
    pBind->buffer_length = m_paramValues[pos].s.size();
}

void MySQL::PrepareBinary(int32_t position, const std::vector<uint8_t>& value)
{
    LOG_DEBUG("Assigning position %d to value '%s'", position, value.data());

    ASSERT_OR_THROW(position >= 0);
    size_t pos = static_cast<size_t>(position);

    MYSQL_BIND *pBind = &m_params[pos];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[pos].b = value;

    pBind->buffer_type = MYSQL_TYPE_BLOB;
    pBind->buffer = (void*)m_paramValues[pos].b.data();
    pBind->buffer_length = m_paramValues[pos].b.size();
}

int MySQL::GetAffectedRows()
{
    return affectedRows;
}

std::string MySQL::GetLastError(bool bClear)
{
    // This might be overkill, but copy the string  here so the class stored string can be cleared
    // before returning.
    std::string temp = m_lastError;
    if (bClear)
        m_lastError.clear();
    return temp;
}

int32_t MySQL::GetPreparedQueryParamCount()
{
    return static_cast<int32_t>(m_paramCount);
}

void MySQL::DestroyPreparedQuery()
{
    if (m_stmt)
    {
        mysql_stmt_close(m_stmt);
        m_stmt = nullptr;

        // Force deallocation
        std::vector<MYSQL_BIND>().swap(m_params);
        std::vector<Variant>().swap(m_paramValues);
        m_paramCount = 0;
    }
}

}

#endif
