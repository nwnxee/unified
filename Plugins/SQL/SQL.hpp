#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Targets/ITarget.hpp"

#include <memory>

namespace SQL {

class SQL : public NWNXLib::Plugin
{
public:
    SQL(const Plugin::CreateParams& params);
    virtual ~SQL();

    NWNXLib::Services::Events::ArgumentStack OnPrepareQuery(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnExecuteQuery(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnReadyToReadNextRow(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnReadNextRow(NWNXLib::Services::Events::ArgumentStack&& args);
    NWNXLib::Services::Events::ArgumentStack OnReadDataInActiveRow(NWNXLib::Services::Events::ArgumentStack&& args);

private:
    std::unique_ptr<ITarget> m_target;
    Query m_activeQuery;
    ResultSet m_activeResults;
    ResultRow m_activeRow;
    int32_t m_nextQueryId;
    bool m_queryMetrics;
};

}
