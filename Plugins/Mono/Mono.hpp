#pragma once

#include "Plugin.hpp"
#include <mono/jit/jit.h>

namespace Mono {

class Mono : public NWNXLib::Plugin
{
public:
    Mono(const Plugin::CreateParams& params);
    virtual ~Mono();

private:
    MonoDomain* m_Domain;
    MonoAssembly* m_Assembly;

    std::unordered_map<std::string, MonoMethod*> m_ScriptMap;

    bool RunMonoScript(const char* scriptName);
    MonoMethod* GetScriptEntryFromClass(const char* className);
};

}
