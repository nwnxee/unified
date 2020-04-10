#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "API/Types.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Util {

class Util : public NWNXLib::Plugin
{
public:
    Util(const Plugin::CreateParams& params);
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
    ArgumentStack RegisterServerConsoleCommand  (ArgumentStack&& args);
    ArgumentStack UnregisterServerConsoleCommand(ArgumentStack&& args);
    ArgumentStack PluginExists                  (ArgumentStack&& args);
    ArgumentStack GetUserDirectory              (ArgumentStack&&);
    ArgumentStack GetScriptReturnValue          (ArgumentStack&& args);

    size_t m_resRefIndex;
    std::vector<std::string> m_listResRefs;
    int m_tickCount;
    std::unique_ptr<CScriptCompiler> m_scriptCompiler;
    std::unordered_map<std::string, std::string> m_serverConsoleCommandMap;
};

}
