#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)

#include <iostream>
#include <cstdlib>
#include <regex>

#include "PostgreSQL.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Log/Log.hpp"

namespace SQL {

PostgreSQL::PostgreSQL(NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log)
    : m_log(log)
{
    // Not sure if we need to do anything here.
}

PostgreSQL::~PostgreSQL()
{
    PQfinish(m_conn);
}

void PostgreSQL::Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config)
{
    const std::string host = "host=" + config->Get<std::string>("HOST", "localhost");
    const std::string user = "user=" + config->Require<std::string>("USERNAME");
    const std::string pass = "password=" + config->Require<std::string>("PASSWORD");

    const NWNXLib::Maybe<std::string> DB = config->Get<std::string>("DATABASE");
    if (DB)
    {
        m_log->Debug("DB set to %s", (*DB).c_str());
    }
    const std::string db   = DB ? "dbname=" + (*DB) : nullptr;

    const std::string port = "port=" + config->Get<std::string>("PORT", "5432");

    // Build the m_connection string
    std::string m_connectstring = host + " " + port + " " + db + " " + user + " " + pass;

    m_log->Info("Connect String:  %s\n", m_connectstring.c_str());

    // Connect attempt
    m_conn = PQconnectdb(m_connectstring.c_str());

    if (PQstatus(m_conn) != CONNECTION_OK)
    {
        throw std::runtime_error("Error m_connecting to Postgres DB");
    }
}

bool PostgreSQL::IsConnected()
{
    if (PQstatus(m_conn) != CONNECTION_OK)
    {
        return false;
    }
    return true;
}

bool PostgreSQL::PrepareQuery(const Query& query)
{
    m_log->Info("Preparing query %s\n", query.c_str());

    m_affectedRows = -1;

    /* Determine the number of parameters in the query */
    std::regex words_regex("[^\\\\]\\$\\d+");
    auto words_begin = std::sregex_iterator(
        query.begin(), query.end(), words_regex);
    auto words_end = std::sregex_iterator();

    m_paramCount = std::distance(words_begin, words_end);

    m_params.resize(m_paramCount);

    PGresult *res = PQprepare(m_conn,      // connection
                        "",                // statement name, blank in this case.
                        query.c_str(),     // query string
                        m_paramCount,      // param count
                        NULL);             // param types (can be null to infer)

    if (res == NULL)
    {
        m_log->Warning("Possible out of memory condition on DB server.");
        return false;
    }

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        PQclear(res);
        m_log->Warning("Query '%s' failed due to error '%s'", query.c_str(), PQresultErrorMessage(res));

        return false;
    }

    PQclear(res);
    return true;
}

NWNXLib::Maybe<ResultSet> PostgreSQL::ExecuteQuery()
{

    m_affectedRows = -1;

    char** paramValues = nullptr;

    // convert the m_params vector into a char ** required by Postgres.
    if (m_paramCount > 0)
    {
        paramValues = new char*[m_params.size()];

        const unsigned int sz = m_params.size();
        for (unsigned int i=0; i<sz; i++)
        {
            paramValues[i] = new char[m_params[i].size()+1];
            strcpy(paramValues[i], m_params[i].c_str());
        }
    }

    PGresult *res = PQexecPrepared(
        m_conn,                                 // connection
        "",                                     // statement name (same as in the prepare above)
        m_paramCount,                           // m_paramCount from previous
        paramValues,                            // param data (can be null)
        NULL,                                   // param lengths - only for binary data
        NULL,                                   // param formats - server will infer text
        0);                                     // result format, 0=text, 1=binary

    // done with parameters.
    if (paramValues != nullptr)
    {
        for (unsigned i = 0; i < m_params.size(); i++)
        {
            delete [] paramValues[i];
        }
        delete [] paramValues;
    }

    // Rows returned - collect and pass on
    if (PQresultStatus(res) == PGRES_TUPLES_OK)
    {
        ResultSet results;
        const size_t rows = PQntuples(res);
        const size_t cols = PQnfields(res);

        for(int i=0; i<(int)rows; i++)
        {
            ResultRow row;
            row.reserve(cols);
            for (int j=0; j<(int)cols; j++)
            {
                row.emplace_back(Result(PQgetvalue(res, i, j), PQgetlength(res, i, j)));
            }
            results.push(row);
        }

        PQclear(res);
        return NWNXLib::Maybe<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
    }

    // DML that doesn't return rows (inserts, updates, etc.)
    // Capture the rows affected if applicable.
    if (PQresultStatus(res) == PGRES_COMMAND_OK)
    {
        const char *cnt = PQcmdTuples(res);
        if (*cnt != '\0')
        {
            m_affectedRows = atoi(cnt);
        }
        PQclear(res);
        return NWNXLib::Maybe<ResultSet>(ResultSet()); // Succeeded query, no results.
    }

    // Else.. something unexpected happened.

    const char* error = PQresultErrorField(res, PG_DIAG_MESSAGE_PRIMARY);

    if (*error == '\0')
    {
        // No valid error.
        error = "Undefined/unknown";
    }

    // Save a copy of the error.  In PgSQL, the error comes from the result we got from the server,
    // which we're about to clear.
    m_lastError.assign(error);

    PQclear(res);
    return NWNXLib::Maybe<ResultSet>();
}

// Parameters are just passed as strings.  PgSQL figures out what it's supposed to be and casts if necessary.
void PostgreSQL::PrepareInt(int32_t position, int32_t value)
{
    m_params[position] = std::to_string(value);
}
void PostgreSQL::PrepareFloat(int32_t position, float value)
{
    m_params[position] = std::to_string(value);
}
void PostgreSQL::PrepareString(int32_t position, const std::string& value)
{
    m_params[position] = value;
}

int PostgreSQL::GetAffectedRows()
{
    return m_affectedRows;
}

std::string PostgreSQL::GetLastError()
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

void PostgreSQL::DestroyPreparedQuery()
{
    // No way or need to deallocate the anonymous prepared statement in PgSQL.

    // Force deallocation
    std::vector<std::string>().swap(m_params);
    m_paramCount = 0;
}

}
#endif
