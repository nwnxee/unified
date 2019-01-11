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

    virtual void Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config) override;
    virtual bool IsConnected() override;
    virtual bool PrepareQuery(const Query& query) override;
    virtual NWNXLib::Maybe<ResultSet> ExecuteQuery() override;
    virtual void PrepareInt(int32_t position, int32_t value) override;
    virtual void PrepareFloat(int32_t position, float value) override;
    virtual void PrepareString(int32_t position, const std::string& value) override;
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

    // No std::variant available, and C++ really doesn't like strings in unions.
    struct Variant { float f; int32_t n; std::string s;
        Variant() { s = ""; }
    };
    std::vector<std::string> m_paramValues;
    int m_affectedRows;
};

}

#endif
