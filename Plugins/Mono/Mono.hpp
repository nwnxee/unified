#pragma once

#include "Plugin.hpp"
#include "API/Constants.hpp"
#include "API/Types.hpp"
#include "Mono_Handlers.hpp"

#include <mono/jit/jit.h>

namespace Mono {

class Mono : public NWNXLib::Plugin
{
public:
    Mono(const Plugin::CreateParams& params);
    virtual ~Mono();

private:
    MonoMethod* m_PushScriptContext;
    MonoMethod* m_PopScriptContext;
    MonoMethod* m_ExecuteClosures;

    bool m_ScriptMetrics;

    std::unordered_map<std::string, MonoMethod*> m_ScriptMap;

    bool RunMonoScript(const char* scriptName,
        NWNXLib::API::Types::ObjectID objId = NWNXLib::API::Constants::OBJECT_INVALID,
        bool valid = true);

    MonoMethod* GetScriptEntryFromClass(const char* className);
    MonoMethod* GetInternalHandler(const char* handler, int paramCount);
};

}
