#include "Events.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSTile.hpp"

namespace Events {

using namespace NWNXLib;

static Hooks::Hook s_SetPositionMaterialChangeHook;
static Hooks::Hook s_SetPositionTileChangeHook;

static void SetPositionMaterialChangeHook(CNWSObject*, Vector, int32_t);
static void SetPositionTileChangeHook(CNWSObject*, Vector, int32_t);

void TileEvents() __attribute__((constructor));
void TileEvents()
{
    InitOnFirstSubscribe("NWNX_ON_MATERIALCHANGE_.*", []() {
        s_SetPositionMaterialChangeHook = Hooks::HookFunction(&CNWSObject::SetPosition,
            &SetPositionMaterialChangeHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_CREATURE_TILE_CHANGE_.*", []() {
        s_SetPositionTileChangeHook = Hooks::HookFunction(&CNWSObject::SetPosition,
            &SetPositionTileChangeHook, Hooks::Order::Earliest);
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

void SetPositionTileChangeHook(CNWSObject* thisPtr, Vector vPosition, BOOL bDoingCharacterCopy)
{
    if (thisPtr->m_nObjectType != API::Constants::ObjectType::Creature)
    {
        s_SetPositionTileChangeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
        return;
    }

    if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
    {
        CNWSArea *pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(pCreature->m_oidArea);
        if (!pArea)
            pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(pCreature->m_oidDesiredArea);

        if (pArea)
        {
            CNWSTile *pOldTile = pArea->GetTile(pCreature->m_vPosition);
            CNWSTile *pNewTile = pArea->GetTile(vPosition);

            if (pOldTile && pNewTile && (pOldTile != pNewTile || pCreature->m_vPosition == vPosition))
            {
                PushEventData("OLD_TILE_INDEX", std::to_string(pOldTile->m_nGridX + (pArea->m_nWidth * pOldTile->m_nGridY)));
                PushEventData("OLD_TILE_X", std::to_string(pOldTile->m_nGridX));
                PushEventData("OLD_TILE_Y", std::to_string(pOldTile->m_nGridY));
                PushEventData("NEW_TILE_INDEX", std::to_string(pNewTile->m_nGridX + (pArea->m_nWidth * pNewTile->m_nGridY)));
                PushEventData("NEW_TILE_X", std::to_string(pNewTile->m_nGridX));
                PushEventData("NEW_TILE_Y", std::to_string(pNewTile->m_nGridY));
                SignalEvent("NWNX_ON_CREATURE_TILE_CHANGE_BEFORE", pCreature->m_idSelf);

                s_SetPositionTileChangeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);

                PushEventData("OLD_TILE_INDEX", std::to_string(pOldTile->m_nGridX + (pArea->m_nWidth * pOldTile->m_nGridY)));
                PushEventData("OLD_TILE_X", std::to_string(pOldTile->m_nGridX));
                PushEventData("OLD_TILE_Y", std::to_string(pOldTile->m_nGridY));
                PushEventData("NEW_TILE_INDEX", std::to_string(pNewTile->m_nGridX + (pArea->m_nWidth * pNewTile->m_nGridY)));
                PushEventData("NEW_TILE_X", std::to_string(pNewTile->m_nGridX));
                PushEventData("NEW_TILE_Y", std::to_string(pNewTile->m_nGridY));
                SignalEvent("NWNX_ON_CREATURE_TILE_CHANGE_AFTER", pCreature->m_idSelf);

                return;
            }
        }
    }

    s_SetPositionTileChangeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
}

}
