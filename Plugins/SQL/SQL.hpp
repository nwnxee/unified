#pragma once

#include "nwnx.hpp"
#include "Targets/ITarget.hpp"

#include <memory>

using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace SQL {

class SQL : public NWNXLib::Plugin
{
public:
    SQL(NWNXLib::Services::ProxyServiceList* services);
    virtual ~SQL();

    ArgumentStack PrepareQuery                  (ArgumentStack&& args);
    ArgumentStack ExecutePreparedQuery          (ArgumentStack&& args);
    ArgumentStack ReadyToReadNextRow            (ArgumentStack&& args);
    ArgumentStack ReadNextRow                   (ArgumentStack&& args);
    ArgumentStack ReadDataInActiveRow           (ArgumentStack&& args);
    ArgumentStack PreparedInt                   (ArgumentStack&& args);
    ArgumentStack PreparedString                (ArgumentStack&& args);
    ArgumentStack PreparedFloat                 (ArgumentStack&& args);
    ArgumentStack PreparedObjectId              (ArgumentStack&& args);
    ArgumentStack PreparedObjectFull            (ArgumentStack&& args);
    ArgumentStack PreparedNULL                  (ArgumentStack&& args);
    ArgumentStack ReadFullObjectInActiveRow     (ArgumentStack&& args);
    ArgumentStack GetAffectedRows               (ArgumentStack&& args);
    ArgumentStack GetDatabaseType               (ArgumentStack&& args);
    ArgumentStack DestroyPreparedQuery          (ArgumentStack&& args);
    ArgumentStack GetLastError                  (ArgumentStack&& args);
    ArgumentStack GetPreparedQueryParamCount    (ArgumentStack&& args);
private:
    bool Reconnect(int32_t attempts = 1);

    std::unique_ptr<ITarget> m_target;
    Query m_activeQuery;
    ResultSet m_activeResults;
    ResultRow m_activeRow;
    int32_t m_nextQueryId;
    bool m_queryMetrics;
    bool m_queryPrepared;
    bool m_utf8;
};

}

