#include "nwnx.hpp"
#include "NWNXCore.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/Constants.hpp"
#include "API/nwn_api.hpp"
#include "API/Globals.hpp"
#include "API/Vector.hpp"
#include "API/CExoString.hpp"
#include "API/CScriptLocation.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/CNWSObject.hpp"

#include <cstring>
#include <optional>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

namespace {

struct Command
{
    std::string plugin;
    std::string event;
    std::string operation;
};

std::optional<Command> ProcessNWNX(const CExoString& str)
{
    static const int  NWNX_ABI_VERSION = 2;

    auto startsWith = [](const CExoString& str, const char *prefix) -> bool
    {
        auto len = std::strlen(prefix);
        return str.m_sString && str.m_nBufferLength >= len && std::strncmp(prefix, str.m_sString, len) == 0;
    };

    if (startsWith(str, "NWNXEE!"))
    {
        int abi;
        char plugin[256];
        char event[256];
        char operation[256];

        int scanned = std::sscanf(str.m_sString,
                            "NWNXEE!ABIv%d!%255[A-Za-z0-9_]!%255[A-Za-z0-9_]!%255[A-Za-z0-9_]",
                            &abi, plugin, event, operation);

        if (scanned == 4 && abi == NWNX_ABI_VERSION)
        {
            Command cmd;
            cmd.plugin    = plugin;
            cmd.event     = event;
            cmd.operation = operation;
            return std::make_optional<>(cmd);
        }
    }

    return {};
}

}

namespace Core {

extern NWNXCore* g_core;

int32_t NWNXCore::PlaySoundHandler(CNWSVirtualMachineCommands* thisPtr, int32_t nCommandId, int32_t nParameters)
{
    ASSERT(thisPtr); ASSERT(nCommandId == VMCommand::PlaySound); ASSERT(nParameters == 1);

    CExoString sound;
    if (!Globals::VirtualMachine()->StackPopString(&sound))
        return VMError::StackUnderflow;

    if (auto nwnx = ProcessNWNX(sound))
    {
        LOG_WARNING("Bad NWNX ABI call detected: \"%s_%s\" from %s.nss - ignored", nwnx->plugin, nwnx->event, Utils::GetCurrentScript());
        LOG_WARNING("NWNX ABI has changed. Please update your \"nwnx_*.nss\" files and recompile all scripts.");
        return VMError::Success;
    }

    if (thisPtr->m_bValidObjectRunScript)
    {
        if (auto *obj = Utils::AsNWSObject(Utils::GetGameObject(thisPtr->m_oidObjectRunScript)))
        {
            if (obj->m_bAbleToModifyActionQueue)
            {
                obj->AddAction(23, -1, 4, (CExoString*)&sound);
            }

        }
    }

    return VMError::Success;
}

int32_t NWNXCore::NWNXFunctionManagementHandler(CNWSVirtualMachineCommands* thisPtr, int32_t nCommandId, int32_t)
{
    ASSERT(thisPtr);

    auto *pVirtualMachine = Globals::VirtualMachine();
    switch (nCommandId)
    {
        case VMCommand::NWNXGetIsAvailable:
        {
            if (!pVirtualMachine->StackPushInteger(1))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXCall:
        {
            CExoString sPlugin;
            CExoString sFunction;
            if (!pVirtualMachine->StackPopString(&sPlugin) ||
                !pVirtualMachine->StackPopString(&sFunction))
                return VMError::StackUnderflow;

            if (g_core->m_ScriptChunkRecursion == 0)
                ScriptAPI::Call(sPlugin, sFunction);
            else
                LOG_NOTICE("NWNX function '%s_%s' in ExecuteScriptChunk() was blocked due to configuration", sFunction, sFunction);
            break;
        }

        case VMCommand::NWNXPushInt:
        {
            int32_t value;
            if (!pVirtualMachine->StackPopInteger(&value))
                return VMError::StackUnderflow;
            ScriptAPI::Push(value);
            break;
        }

        case VMCommand::NWNXPushFloat:
        {
            float value;
            if (!pVirtualMachine->StackPopFloat(&value))
                return VMError::StackUnderflow;
            ScriptAPI::Push(value);
            break;
        }

        case VMCommand::NWNXPushObject:
        {
            ObjectID value;
            if (!pVirtualMachine->StackPopObject(&value))
                return VMError::StackUnderflow;
            ScriptAPI::Push(value);
            break;
        }

        case VMCommand::NWNXPushString:
        {
            CExoString value;
            if (!pVirtualMachine->StackPopString(&value))
                return VMError::StackUnderflow;
            ScriptAPI::Push(value);
            break;
        }

        case VMCommand::NWNXPushVector:
        {
            Vector value;
            if (!pVirtualMachine->StackPopVector(&value))
                return VMError::StackUnderflow;
            ScriptAPI::Push(value);
            break;
        }

        case VMCommand::NWNXPushLocation:
        {
            CScriptLocation *pLocation;
            SCOPEGUARD(delete pLocation);
            if (!pVirtualMachine->StackPopEngineStructure(VMStructure::Location, (void**)&pLocation))
                return VMError::StackUnderflow;
            ScriptAPI::Push(*pLocation);
            break;
        }

        case VMCommand::NWNXPushEffect:
        {
            CGameEffect *pEffect;
            if (!pVirtualMachine->StackPopEngineStructure(VMStructure::Effect, (void**)&pEffect))
                return VMError::StackUnderflow;
            ScriptAPI::Push(pEffect);
            break;
        }

        case VMCommand::NWNXPushItemproperty:
        {
            CGameEffect *pItemProperty;
            if (!pVirtualMachine->StackPopEngineStructure(VMStructure::ItemProperty, (void**)&pItemProperty))
                return VMError::StackUnderflow;
            ScriptAPI::Push(pItemProperty);
            break;
        }

        case VMCommand::NWNXPushJson:
        {
            JsonEngineStructure *j = nullptr;
            SCOPEGUARD(delete j);
            if (!pVirtualMachine->StackPopEngineStructure(VMStructure::Json, (void**)&j))
                return VMError::StackUnderflow;
            ScriptAPI::Push(*j);
            break;
        }

        case VMCommand::NWNXPopInt:
        {
            if (!pVirtualMachine->StackPushInteger(ScriptAPI::Pop<int32_t>().value_or(0)))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopFloat:
        {
            if (!pVirtualMachine->StackPushFloat(ScriptAPI::Pop<float>().value_or(0.0f)))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopObject:
        {
            if (!pVirtualMachine->StackPushObject(ScriptAPI::Pop<ObjectID>().value_or(OBJECT_INVALID)))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopString:
        {
            if (!pVirtualMachine->StackPushString(ScriptAPI::Pop<std::string>().value_or("")))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopVector:
        {
            if (!pVirtualMachine->StackPushVector(ScriptAPI::Pop<Vector>().value_or(Vector())))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopLocation:
        {
            CScriptLocation location = ScriptAPI::Pop<CScriptLocation>().value_or(CScriptLocation());
            if (!pVirtualMachine->StackPushEngineStructure(VMStructure::Location, &location))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopEffect:
        {
            CGameEffect *pEffect = nullptr;
            SCOPEGUARD(delete pEffect);
            if (auto effect = ScriptAPI::Pop<CGameEffect*>())
                pEffect = *effect;
            if (!pVirtualMachine->StackPushEngineStructure(VMStructure::Effect, pEffect))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopItemproperty:
        {
            CGameEffect *pItemProperty = nullptr;
            SCOPEGUARD(delete pItemProperty);
            if (auto effect = ScriptAPI::Pop<CGameEffect*>())
                pItemProperty = *effect;
            if (!pVirtualMachine->StackPushEngineStructure(VMStructure::ItemProperty, pItemProperty))
                return VMError::StackOverflow;
            break;
        }

        case VMCommand::NWNXPopJson:
        {
            JsonEngineStructure j = ScriptAPI::Pop<JsonEngineStructure>().value_or(JsonEngineStructure{});
            if (!pVirtualMachine->StackPushEngineStructure(VMStructure::Json, &j))
                return VMError::StackOverflow;
            break;
        }

        default:
        {
            pVirtualMachine->m_sAbortCustomError = "Unused NWNX VM Function Called :(";
            return VMError::FakeAbortScript;
        }
    }

    return VMError::Success;
}

}
