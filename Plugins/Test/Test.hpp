#pragma once

#include "Plugin.hpp"

#include "API/Constants.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

#include <map>
#include <set>
#include <vector>

namespace Test
{

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

class Test : public NWNXLib::Plugin
{
public:
    Test(const Plugin::CreateParams& params);
    virtual ~Test();

    // NWScript Events
    ArgumentStack AddTestScript(ArgumentStack&& args);
    ArgumentStack Context(ArgumentStack&& args);
    ArgumentStack Flush(ArgumentStack&& args);
    ArgumentStack ReportFailure(ArgumentStack&& args);

    // Unexposed
    bool CompileTestScript(const char* name, const char* script);
    void HooverTestScripts();
    void ExecuteTestScript(const std::string& script);
    void RunTests();

    // Hooks
    static void LoadCharacterFinishHook(bool, CServerExoAppInternal*, CNWSPlayer*, int32_t, int32_t);
    static void LoadModuleEndHook(bool before, CNWSModule* module);

    // Data
    std::unique_ptr<CScriptCompiler> m_compiler;
    std::set<std::string> m_extraScripts;
    std::vector<std::pair<std::string, bool>> m_output;
    std::map<std::string, NWNXLib::API::Constants::ResRefType::TYPE> m_resManFiles;
    std::string m_sourceDir;
    std::map<std::string, std::string> m_sourceFiles;
    bool m_testsComplete = false;
    bool m_waitForPC = false;
};

} // namespace Test
