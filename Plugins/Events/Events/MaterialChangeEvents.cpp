#include "Events/MaterialChangeEvents.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Events.hpp"

namespace Events {

using namespace NWNXLib;

static std::unordered_map<ObjectID, int32_t> m_objectCurrentMaterial;
static Hooks::Hook s_SetPositionHook;

MaterialChangeEvents::MaterialChangeEvents()
{
    Events::InitOnFirstSubscribe("NWNX_ON_MATERIALCHANGE_.*", []() {
        s_SetPositionHook = Hooks::HookFunction(API::Functions::_ZN10CNWSObject11SetPositionE6Vectori,
                                         (void*)&SetPositionHook, Hooks::Order::Earliest);
    });
}

void MaterialChangeEvents::SetPositionHook(CNWSObject* thisPtr, Vector vPosition, BOOL bDoingCharacterCopy)
{
    if (thisPtr->m_nObjectType != API::Constants::ObjectType::Creature)
    {
        s_SetPositionHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
        return;
    }

    if (auto *pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(thisPtr->m_oidArea))
    {
        auto iMat = pArea->GetSurfaceMaterial(vPosition);
        if (!m_objectCurrentMaterial.count(thisPtr->m_idSelf) || iMat != m_objectCurrentMaterial[thisPtr->m_idSelf])
        {
            Events::PushEventData("MATERIAL_TYPE", std::to_string(iMat));
            Events::SignalEvent("NWNX_ON_MATERIALCHANGE_BEFORE", thisPtr->m_idSelf);

            s_SetPositionHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);

            Events::PushEventData("MATERIAL_TYPE", std::to_string(iMat));
            Events::SignalEvent("NWNX_ON_MATERIALCHANGE_AFTER", thisPtr->m_idSelf);

            m_objectCurrentMaterial[thisPtr->m_idSelf] = iMat;
            return;
        }
    }

    s_SetPositionHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
}

}
