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
    virtual NWNXLib::Maybe<ResultSet> ExecuteQuery(const Query& query) override;

private:
    NWNXLib::ViewPtr<NWNXLib::Services::LogProxy> m_log;
    MYSQL m_mysql;
};

}

#endif
