#pragma once

#include "Plugin.hpp"
#include "API/Constants.hpp"
#include "API/Types.hpp"

#include <stack>
#include <vector>

#include <mono/jit/jit.h>

namespace Mono {

struct GameDefinedStructure
{
    int m_Id;
    void* m_Ptr;
};

using FreeList = std::stack<std::vector<GameDefinedStructure>>;

class Mono : public NWNXLib::Plugin
{
public:
    Mono(const Plugin::CreateParams& params);
    virtual ~Mono();

private:
    MonoDomain* m_Domain;
    MonoAssembly* m_Assembly;

    MonoMethod* m_PushScriptContext;
    MonoMethod* m_PopScriptContext;

    std::unordered_map<std::string, MonoMethod*> m_ScriptMap;
    FreeList m_StructureFreeList;

    bool RunMonoScript(const char* scriptName,
        NWNXLib::API::Types::ObjectID objId = NWNXLib::API::Constants::OBJECT_INVALID,
        bool valid = true);

    MonoMethod* GetScriptEntryFromClass(const char* className);
    MonoMethod* GetInternalHandler(const char* handler, int paramCount);
};

}
