#pragma once

#if defined(NWNX_SQL_SQLITE_SUPPORT)

#include <sqlite3.h>
#include "Targets/ITarget.hpp"

namespace SQL {

class SQLite final : public ITarget
{
public:
    SQLite();
    virtual ~SQLite() override;

    virtual void Connect() override;
    virtual bool IsConnected() override;
    virtual bool PrepareQuery(const Query& query) override;
    virtual std::optional<ResultSet> ExecuteQuery() override;
    virtual void PrepareInt(int32_t position, int32_t value) override;
    virtual void PrepareFloat(int32_t position, float value) override;
    virtual void PrepareString(int32_t position, const std::string& value) override;
    virtual void PrepareBinary(int32_t position, const std::vector<uint8_t>& value) override;
    virtual void PrepareNULL(int32_t position) override;
    virtual int  GetAffectedRows() override;
    virtual std::string GetLastError(bool bClear = false) override;
    virtual int32_t GetPreparedQueryParamCount() override;
    virtual void DestroyPreparedQuery() override;


private:
    sqlite3 *m_dbConn;
    sqlite3_stmt *m_stmt;
    std::string m_dbName;
    size_t m_paramCount;
    std::string m_lastError;
    std::vector<std::optional<std::string>> m_paramValues;
    int m_affectedRows;
};

}

#endif
