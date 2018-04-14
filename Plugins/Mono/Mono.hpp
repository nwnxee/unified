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
    MonoMethod* m_ExecuteClosure;
    MonoMethod* m_OnMainLoopTick;

    bool m_ScriptMetrics;
    bool m_ClosureMetrics;
    bool m_MainLoopMetrics;

    std::unordered_map<std::string, MonoMethod*> m_ScriptMap;

    bool RunMonoScript(const char* scriptName,
        NWNXLib::API::Types::ObjectID objId = NWNXLib::API::Constants::OBJECT_INVALID,
        bool valid = true);

    MonoMethod* GetScriptEntryFromClass(const char* className);
    MonoMethod* GetHandler(const char* clsName, const char* handler, int paramCount);
    void ExecuteClosure(uint64_t eventId);
    void ExecuteMainLoopTick(uint64_t frame);
};

}
