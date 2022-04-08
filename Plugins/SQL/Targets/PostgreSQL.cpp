#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)

#include "nwnx.hpp"
#include <iostream>
#include <cstdlib>
#include <regex>

#include "PostgreSQL.hpp"
using namespace NWNXLib;
namespace SQL {

PostgreSQL::PostgreSQL()
{
    // Not sure if we need to do anything here.
}

PostgreSQL::~PostgreSQL()
{
    PQfinish(m_conn);
}

void PostgreSQL::Connect()
{
    const std::string host = "host=" + Config::Get<std::string>("HOST", "localhost");
    const std::string user = "user=" + *Config::Get<std::string>("USERNAME");
    const std::string pass = "password=" + *Config::Get<std::string>("PASSWORD");

    // Database technically is optional.  If not given, it will connect to the default
    // database of the given USERNAME.
    const auto DB = Config::Get<std::string>("DATABASE");
    if (DB)
    {
        LOG_DEBUG("DB set to %s", (*DB));
    }
    const std::string db   = DB ? "dbname=" + (*DB) : nullptr;

    const std::string port = "port=" + Config::Get<std::string>("PORT", "5432");

    // Build the m_connection string - this is used later in the PQping (PQping doesn't need the password).
    m_connectString = host + " " + port + " " + db + " " + user ;

    // hide the password in the log file
    LOG_INFO("Connect String:  %s password=xxxxxxxx", m_connectString);
    // but add it if we're in debug logging.
    LOG_DEBUG("              :  %s", pass);

    m_connectString += " " + pass;

    // Connect attempt
    m_conn = PQconnectdb(m_connectString.c_str());

    if (PQstatus(m_conn) != CONNECTION_OK)
    {
        throw std::runtime_error("Error connecting to Postgres DB");
    }
}

bool PostgreSQL::IsConnected()
{
    /*
     * Executing a query between a unmamed prepare and execute apparently resets the
     * unnamed query.  Using a named query forces you to execute a DEALLOCATE after you're
     * done or old queries will pile up forever.
     *
     * PQping is simpler, but probably less robust.  It does actively ping the server, though.
     */
    bool bConnected = true;

    PGPing ping = PQping(m_connectString.c_str());
    if (ping != PQPING_OK)
    {
        LOG_WARNING("Disconnected state identified.");
        bConnected = false;
    }
    return bConnected;
}

bool PostgreSQL::PrepareQuery(const Query& query)
{
    LOG_DEBUG("Preparing query %s\n", query);

    m_affectedRows = -1;

    /*
     * Determine the number of parameters in the query.
     *
     * Note this is kind of a hack.  Postgres doesn't support a "get number of bind parameters"
     * function like MySQL does, so we're counting the things in the query that, to the parser
     * should also look like bind parameters:  non-escaped dollar digit combinations.
     * */
    std::regex words_regex("[^\\\\]\\$\\d+");
    auto words_begin = std::sregex_iterator(
        query.begin(), query.end(), words_regex);
    auto words_end = std::sregex_iterator();

    m_paramCount = std::distance(words_begin, words_end);

    LOG_DEBUG("Detected %d parameters.", m_paramCount);

    m_params.resize(m_paramCount);
    m_formats.resize(m_paramCount);
    m_lengths.resize(m_paramCount);

    PGresult *res = PQprepare(m_conn,      // connection
                        "",                // statement name, blank in this case.
                        query.c_str(),     // query string
                        m_paramCount,      // param count
                        NULL);             // param types (can be null to infer)

    if (res == NULL)
    {
        LOG_WARNING("Possible out of memory condition on DB server.");
        return false;
    }

    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        PQclear(res);
        LOG_WARNING("Query '%s' failed due to error '%s'", query, PQresultErrorMessage(res));

        return false;
    }

    PQclear(res);
    return true;
}

std::optional<ResultSet> PostgreSQL::ExecuteQuery()
{

    m_affectedRows = -1;

    char** paramValues = nullptr;

    // convert the m_params vector into a char ** required by Postgres.
    if (m_paramCount > 0)
    {
        LOG_DEBUG("Preparing query with %d parameters", m_paramCount);
        paramValues = new char*[m_params.size()];

        const unsigned int sz = m_params.size();
        for (unsigned int i=0; i<sz; i++)
        {
            if (m_params[i])
            {
                paramValues[i] = new char[m_params[i]->size()+1];
                strcpy(paramValues[i], m_params[i]->c_str());
            }
            else
            {
                paramValues[i] = nullptr;
            }
        }
    }

    PGresult *res = PQexecPrepared(
        m_conn,                                 // connection
        "",                                     // statement name (same as in the prepare above)
        m_paramCount,                           // m_paramCount from previous
        paramValues,                            // param data (can be null)
        m_lengths.data(),                                   // param lengths - only for binary data
        m_formats.data(),                                   // param formats - server will infer text
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
        LOG_DEBUG("Returning %d rows of %d columns.", rows, cols);

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
        return std::make_optional<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
    }

    // DML that doesn't return rows (inserts, updates, etc.)
    // Capture the rows affected if applicable.
    if (PQresultStatus(res) == PGRES_COMMAND_OK)
    {
        LOG_DEBUG("Fetching rows affected by command.");
        const char *cnt = PQcmdTuples(res);
        if (*cnt != '\0')
        {
            m_affectedRows = atoi(cnt);
        }
        PQclear(res);
        return std::make_optional<ResultSet>(ResultSet()); // Succeeded query, no results.
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
    return std::optional<ResultSet>();
}

// Parameters are just passed as strings.  PgSQL figures out what it's supposed to be and casts if necessary.
void PostgreSQL::PrepareInt(int32_t position, int32_t value)
{
    LOG_DEBUG("Assigning position %d to value '%d'", position, value);
    m_params[position] = std::to_string(value);
    m_formats[position] = 0;
}
void PostgreSQL::PrepareFloat(int32_t position, float value)
{
    LOG_DEBUG("Assigning position %d to value '%f'", position, value);
    m_params[position] = std::to_string(value);
    m_formats[position] = 0;
}
void PostgreSQL::PrepareString(int32_t position, const std::string& value)
{
    LOG_DEBUG("Assigning position %d to value '%s'", position, value);
    m_params[position] = value;
    m_formats[position] = 0;
}

void PostgreSQL::PrepareBinary(int32_t position, const std::vector<uint8_t> &value)
{
    LOG_DEBUG("Assigning position %d to value '%s'", position, value.data());
    m_params[position] = std::string(value.begin(), value.end());
    m_lengths[position] = value.size();
    m_formats[position] = 1;
}
void PostgreSQL::PrepareNULL(int32_t position)
{
    LOG_DEBUG("Assigning position %d to value NULL", position);
    m_params[position] = std::nullopt;
    m_formats[position] = 0;
}

int PostgreSQL::GetAffectedRows()
{
    return m_affectedRows;
}

std::string PostgreSQL::GetLastError(bool bClear)
{
    // This might be overkill, but copy the string here so the class stored string can be cleared
    // before returning.
    std::string temp = m_lastError;
    if (bClear)
        m_lastError.clear();
    return temp;
}

int32_t PostgreSQL::GetPreparedQueryParamCount()
{
    return m_paramCount;
}

void PostgreSQL::DestroyPreparedQuery()
{
    // No way or need to deallocate the anonymous prepared statement in PgSQL.

    // Force deallocation
    std::vector<std::optional<std::string>>().swap(m_params);
    m_paramCount = 0;
}

}
#endif
