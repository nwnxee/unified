#if defined(NWNX_SQL_MYSQL_SUPPORT)

#include "MySQL.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Log/Log.hpp"

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

NWNXLib::Maybe<ResultSet> MySQL::ExecuteQuery(const Query& query)
{
    bool success = mysql_real_query(&m_mysql, query.c_str(), query.size()) == 0;

    if (success)
    {
        MYSQL_RES* mysqlResult = mysql_store_result(&m_mysql);
        success = mysqlResult;

        if (success)
        {
            ResultSet results;
            const size_t columns = mysql_num_fields(mysqlResult);

            while (true)
            {
                ResultRow row;
                row.reserve(columns);

                MYSQL_ROW sqlRow = mysql_fetch_row(mysqlResult);
                unsigned long* sqlLengths = mysql_fetch_lengths(mysqlResult);

                if (!sqlRow || !sqlLengths)
                {
                    break;
                }

                for (size_t i = 0; i < columns; ++i)
                {
                    row.emplace_back(Result(sqlRow[i], sqlLengths[i]));
                }

                results.push(row);
            }

            mysql_free_result(mysqlResult);
            return NWNXLib::Maybe<ResultSet>(std::move(results)); // Succeeded query, succeeded results.
        }

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

        m_log->Warning("Query '%s' failed due to error '%s'", query.c_str(), error);
    }

    return NWNXLib::Maybe<ResultSet>(); // Failed query.
}

}

#endif
