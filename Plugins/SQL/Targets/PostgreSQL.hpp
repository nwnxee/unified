#pragma once

#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)

#include <libpq-fe.h>
#include "Targets/ITarget.hpp"

namespace SQL {

class PostgreSQL final : public ITarget
{
public:
    PostgreSQL();
    virtual ~PostgreSQL() override;

    virtual void Connect(NWNXLib::Services::ConfigProxy* config) override;
    virtual bool IsConnected() override;
    virtual bool PrepareQuery(const Query& query) override;
    virtual std::optional<ResultSet> ExecuteQuery() override;
    virtual void PrepareInt(int32_t position, int32_t value) override;
    virtual void PrepareFloat(int32_t position, float value) override;
    virtual void PrepareString(int32_t position, const std::string& value) override;
    virtual void PrepareBinary(int32_t position, const std::vector<uint8_t>& value) override;
    virtual int  GetAffectedRows() override;
    virtual std::string GetLastError(bool bClear = false) override;
    virtual int32_t GetPreparedQueryParamCount() override;
    virtual void DestroyPreparedQuery() override;

private:
    PGconn *m_conn;
    int m_affectedRows = -1;
    size_t m_paramCount = 0;
    std::vector<std::string> m_params;
    std::vector<int> m_lengths;
    std::vector<int> m_formats;
    std::string m_lastError;
    std::string m_connectString;
};

}

#endif

