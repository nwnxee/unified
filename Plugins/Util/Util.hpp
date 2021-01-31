#pragma once

#include "nwnx.hpp"
using ArgumentStack = NWNXLib::Events::ArgumentStack;

namespace Util {

class Util : public NWNXLib::Plugin
{
public:
    Util(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Util();

private:
    ArgumentStack GetCurrentScriptName          (ArgumentStack&& args);
    ArgumentStack GetAsciiTableString           (ArgumentStack&& args);
    ArgumentStack Hash                          (ArgumentStack&& args);
    ArgumentStack GetCustomToken                (ArgumentStack&& args);
    ArgumentStack EffectTypeCast                (ArgumentStack&& args);
    ArgumentStack StripColors                   (ArgumentStack&& args);
    ArgumentStack IsValidResRef                 (ArgumentStack&& args);
    ArgumentStack GetEnvironmentVariable        (ArgumentStack&& args);
    ArgumentStack GetMinutesPerHour             (ArgumentStack&& args);
    ArgumentStack SetMinutesPerHour             (ArgumentStack&& args);
    ArgumentStack EncodeStringForURL            (ArgumentStack&& args);
    ArgumentStack Get2DARowCount                (ArgumentStack&& args);
    ArgumentStack GetFirstResRef                (ArgumentStack&& args);
    ArgumentStack GetNextResRef                 (ArgumentStack&& args);
    ArgumentStack GetServerTicksPerSecond       (ArgumentStack&& args);
    ArgumentStack GetLastCreatedObject          (ArgumentStack&& args);
    ArgumentStack AddScript                     (ArgumentStack&& args);
    ArgumentStack GetNSSContents                (ArgumentStack&& args);
    ArgumentStack AddNSSFile                    (ArgumentStack&& args);
    ArgumentStack RemoveNWNXResourceFile        (ArgumentStack&& args);
    ArgumentStack SetInstructionLimit           (ArgumentStack&& args);
    ArgumentStack GetInstructionLimit           (ArgumentStack&& args);
    ArgumentStack SetInstructionsExecuted       (ArgumentStack&& args);
    ArgumentStack GetInstructionsExecuted       (ArgumentStack&& args);
    ArgumentStack RegisterServerConsoleCommand  (ArgumentStack&& args);
    ArgumentStack UnregisterServerConsoleCommand(ArgumentStack&& args);
    ArgumentStack PluginExists                  (ArgumentStack&& args);
    ArgumentStack GetUserDirectory              (ArgumentStack&& args);
    ArgumentStack GetScriptReturnValue          (ArgumentStack&& args);
    ArgumentStack CreateDoor                    (ArgumentStack&& args);
    ArgumentStack SetItemActivator              (ArgumentStack&& args);
    ArgumentStack GetWorldTime                  (ArgumentStack&& args);
    ArgumentStack SetResourceOverride           (ArgumentStack&& args);
    ArgumentStack GetResourceOverride           (ArgumentStack&& args);
    ArgumentStack GetScriptParamIsSet           (ArgumentStack&& args);
    ArgumentStack SetDawnHour                   (ArgumentStack&& args);
    ArgumentStack SetDuskHour                   (ArgumentStack&& args);
    ArgumentStack GetHighResTimeStamp           (ArgumentStack&& args);

    size_t m_resRefIndex;
    std::vector<std::string> m_listResRefs;
    int m_tickCount;
    std::unique_ptr<CScriptCompiler> m_scriptCompiler;
    std::unordered_map<std::string, std::string> m_serverConsoleCommandMap;
};

}
