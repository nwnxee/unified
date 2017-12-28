#pragma once

#if defined(NWNX_SQL_POSTGRESQL_SUPPORT)

#include <libpq-fe.h>
#include "Targets/ITarget.hpp"

namespace SQL {

class PostgreSQL final : public ITarget
{
public:
	PostgreSQL(NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> log);
    ~PostgreSQL();

    virtual void Connect(NWNXLib::ViewPtr<NWNXLib::Services::ConfigProxy> config) override;
    virtual bool IsConnected() override;
    virtual NWNXLib::Maybe<ResultSet> ExecuteQuery(const Query& query) override;

private:
    NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> m_log;
    PGconn *conn;
    int affectedRows;
};

}

#endif
