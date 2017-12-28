#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)

#include <cstdlib>
#include "PostgreSQL.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Log/Log.hpp"

#define HOST	"host="
#define PORT	"port="
#define DB		"dbname="
#define USR		"user="
#define PW		"password="
#define PORT_NUM	5432


namespace SQL {

PostgreSQL::PostgreSQL(NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log)
    : m_log(log)
{
    // Not sure if we need to do anything here.
}

PostgreSQL::~PostgreSQL()
{
    PQfinish(conn);
}

void PostgreSQL::Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config)
{
    const std::string host = config->Get<std::string>("HOST", "localhost");
    const std::string user = config->Require<std::string>("USERNAME");
    const std::string pass = config->Require<std::string>("PASSWORD");
    const NWNXLib::Maybe<std::string> db = config->Get<std::string>("DATABASE");

    char *connstring = (char *)malloc(strlen(HOST)
                                       + strlen(PORT_NUM)
                                       + strlen(DB)
                                       + strlen(USR)
                                       + strlen(PW)
                                       + 20
                                       + strlen(host)
                                       + strlen(db)
                                       + strlen(user)
                                       + strlen(pass));
     // Build the connection string
     sprintf(connstring, HOST "%s " PORT "%hu " DB "%s " USR "%s " PW "%s", host, PORT_NUM, db, user, pass);

     // Connect attempt
     conn = PQconnectdb(connstring);
     free(connectstring);
     if (PQstatus(conn) != CONNECTION_OK) {
    	 throw std::runtime_error("Error connecting to Postgres DB");
     }
}

bool PostgreSQL::IsConnected()
{
    if (PQstatus(pgsql) != CONNECTION_OK)
    {
        return false;
    }
    return true;
}

NWNXLib::Maybe<ResultSet> PostgreSQL::ExecuteQuery(const Query& query)
{

    PGresult *res = PQexec(conn, query.c_str());

    // Rows returned - collect and pass on
    if (PQresultStatus(res) == PGRES_TUPLES_OK)
    {
		ResultSet results;
		const size_t rows = PQntuples(res);
		const size_t cols = PQnfields(res);

		for(int i=0; i<rows; i++)
		{
			ResultRow row;
			row.reserve(cols);
			for (int j=0; j<cols; j++)
			{
				row.emplace_back(Result(PQgetvalue(res, i, j), PQgetlength(res, i, j));
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
    	affectedRows = 0;
    	const char *cnt = PQcmdTuples(res);
    	if (*cnt != '\0')
    	{
    		affectedRows = atoi(cnt);
    	}
    	PQClear(res);
    	return NWNXLib::Maybe<ResultSet>(ResultSet()); // Succeeded query, no results.
    }

    // Else.. something unexpected happened.

	const char* error = PQresultErrorField(res, PG_DIAG_MESSAGE_PRIMARY);
	if (*error == '\0')
	{
		// No valid error.
		error = "Undefined/unknown";
	}

	m_log->Warning("Query '%s' failed due to error '%s'", query.c_str(), error);

	PQclear(res);
	return NWNXLib::Maybe<ResultSet>();

}

void PostgreSQL::PrepareInt(int32_t position, int32_t value)
{
    MYSQL_BIND *pBind = &m_params[--position];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[position].n = value;

    pBind->buffer_type = MYSQL_TYPE_LONG;
    pBind->buffer = &m_paramValues[position].n;
}
void PostgreSQL::PrepareFloat(int32_t position, float value)
{
    MYSQL_BIND *pBind = &m_params[--position];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[position].f = value;

    pBind->buffer_type = MYSQL_TYPE_FLOAT;
    pBind->buffer = &m_paramValues[position].f;
}
void PostgreSQL::PrepareString(int32_t position, const std::string& value)
{
    MYSQL_BIND *pBind = &m_params[--position];
    memset(pBind, 0, sizeof(*pBind));

    m_paramValues[position].s = value.c_str();

    pBind->buffer_type = MYSQL_TYPE_STRING;
    pBind->buffer = (void*)m_paramValues[position].s.c_str();
    pBind->buffer_length = m_paramValues[position].s.size();
}

}

#endif
