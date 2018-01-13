#pragma once

#if defined(NWNX_SQL_MYSQL_SUPPORT)

#include "mysql/mysql.h"
#include "mysql/errmsg.h"
#include "Targets/ITarget.hpp"

namespace SQL {

class MySQL final : public ITarget
{
public:
    MySQL(NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log);
    ~MySQL();

    virtual void Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config) override;
    virtual bool IsConnected() override;
    virtual bool PrepareQuery(const Query& query) override;
    virtual NWNXLib::Maybe<ResultSet> ExecuteQuery() override;
    virtual void PrepareInt(int32_t position, int32_t value) override;
    virtual void PrepareFloat(int32_t position, float value) override;
    virtual void PrepareString(int32_t position, const std::string& value) override;
    virtual int  GetAffectedRows() override;
    virtual std::string GetLastError() override;
    virtual int32_t GetPreparedQueryParamCount() override;
    virtual void DestroyPreparedQuery() override;


private:
    NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> m_log;
    MYSQL m_mysql;
    MYSQL_STMT *m_stmt;
    std::vector<MYSQL_BIND> m_params;
    size_t m_paramCount;
    std::string m_lastError;

    // No std::variant available, and C++ really doesn't like strings in unions.
    struct Variant { float f; int32_t n; std::string s;
        Variant() { s = ""; }
    };
    std::vector<Variant> m_paramValues;
    int affectedRows;
};

}

#endif
