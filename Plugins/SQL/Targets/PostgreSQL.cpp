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
    const std::string db   = DB ? "dbname=" + config->Get<std::string>("DATABASE") : nullptr;

    const std::string port = "port=" + config->Get<std::string>("PORT", "5432");

    // Build the m_connection string
    std::string m_connectstring = host + " " + port + " " + db + " " + user + " " + pass;

    // Connect attempt
    m_conn = PQconnectdb(m_connectstring.c_str());

    if (PQstatus(m_conn) != CONNECTION_OK) {
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

int GetParamCount(std::string query)
{
    std::regex words_regex("[^\\\\]\\$\\d+");
    auto words_begin = std::sregex_iterator(
        query.begin(), query.end(), words_regex);
    auto words_end = std::sregex_iterator();

    return std::distance(words_begin, words_end);
}

bool PostgreSQL::PrepareQuery(const Query& query)
{
    affectedRows = -1;
    paramCount = GetParamCount(query);
    m_params.resize(paramCount);

    PGresult *res = PQprepare(m_conn,    // connection
                        "pqstmt",        // statement name
                        query.c_str(),   // query string
                        paramCount,      // param count
                        NULL);           // param types (can be null to infer)

    std::cout << "PostgreSQL.cpp - 76" << std::endl;
    if (res == NULL) {
        m_log->Warning("Possible out of memory condition on DB server.");
        return false;
    }

    std::cout << "PostgreSQL.cpp - 82" << std::endl;
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        PQclear(res);
        m_log->Warning("Query '%s' failed due to error '%s'", query.c_str(), PQresultErrorMessage(res));

        return false;
    }

    std::cout << "PostgreSQL.cpp - 89" << std::endl;

    return true;
}

NWNXLib::Maybe<ResultSet> PostgreSQL::ExecuteQuery()
{

	affectedRows = -1;

	char *paramValues[m_params.size()];

	if (paramCount > 0) {
		const unsigned int sz = m_params.size();

		//std::array<std::string> temp_params = new std::array<std::string>(sz);
		for (unsigned int i=0; i<sz; i++) {
			paramValues[i] = (char *)malloc(m_params[i].size()+1);
			strcpy(paramValues[i], m_params[i].c_str());
		}
	}

    PGresult *res = PQexecPrepared(
        m_conn,                                         // connection
        "pqstmt",                                       // statement name (same as in the prepare above)
        paramCount,                                     // paramCount from previous
        (paramCount == 0) ? nullptr : paramValues,      // param data
        NULL,                                           // param lengths - only for binary data
        NULL,                                           // param formats - server will infer text
        0);                                             // result format, 0=text, 1=binary


    // done with parameters.
    m_params.clear();

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
            affectedRows = atoi(cnt);
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

    // TODO:  Query should be saved between Prepare and Execute so if failures occur, it can be
    //        printed to the logs with a coherent message.
    //m_log->Warning("Query '%s' failed due to error '%s'", query.c_str(), error);

    m_log->Warning("Some suery failed due to error '%s'", error);

    PQclear(res);
    return NWNXLib::Maybe<ResultSet>();
}

void PostgreSQL::PrepareInt(int32_t position, int32_t value)
{
    m_params[--position] = std::to_string(value);
}
void PostgreSQL::PrepareFloat(int32_t position, float value)
{
	m_params[--position] = std::to_string(value);
}
void PostgreSQL::PrepareString(int32_t position, const std::string& value)
{
	m_params[--position] = value;
}

int PostgreSQL::GetAffectedRows() {
	return affectedRows;
}

}
#endif
