#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

using namespace NWNXLib;

static Hooks::Hook s_SetPositionMaterialChangeHook;

static void SetPositionMaterialChangeHook(CNWSObject*, Vector, int32_t);

void TileEvents() __attribute__((constructor));
void TileEvents()
{
    InitOnFirstSubscribe("NWNX_ON_MATERIALCHANGE_.*", []() {
        s_SetPositionMaterialChangeHook = Hooks::HookFunction(&CNWSObject::SetPosition,
            &SetPositionMaterialChangeHook, Hooks::Order::Earliest);
    });
}

void SetPositionMaterialChangeHook(CNWSObject* thisPtr, Vector vPosition, BOOL bDoingCharacterCopy)
{
    if (thisPtr->m_nObjectType != API::Constants::ObjectType::Creature)
    {
        s_SetPositionMaterialChangeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
        return;
    }

    if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
    {
        CNWSArea *pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(pCreature->m_oidArea);
        if (!pArea)
            pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(pCreature->m_oidDesiredArea);

        if (pArea)
        {
            int32_t oldMaterial = pArea->GetSurfaceMaterial(pCreature->m_vPosition);
            int32_t newMaterial = pArea->GetSurfaceMaterial(vPosition);

            if (oldMaterial != newMaterial || pCreature->m_vPosition == vPosition)
            {
                PushEventData("MATERIAL_TYPE", std::to_string(newMaterial));
                SignalEvent("NWNX_ON_MATERIALCHANGE_BEFORE", thisPtr->m_idSelf);

                s_SetPositionMaterialChangeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);

                PushEventData("MATERIAL_TYPE", std::to_string(newMaterial));
                SignalEvent("NWNX_ON_MATERIALCHANGE_AFTER", thisPtr->m_idSelf);

                return;
            }
        }
    }

    s_SetPositionMaterialChangeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
}

}
