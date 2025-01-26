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
static Hooks::Hook s_JumpToPointHook;
static Hooks::Hook s_JumpToObjectHook;
static Hooks::Hook s_SetPositionAreaEdgeHook;

static void SetPositionMaterialChangeHook(CNWSObject*, Vector, int32_t);
static void SetPositionTileChangeHook(CNWSObject*, Vector, int32_t);
static int32_t ActionJumpToPointHook(CNWSCreature*, CNWSObjectActionNode*);
static int32_t ActionJumpToObjectHook(CNWSCreature*, CNWSObjectActionNode*);
static void SetPositionAreaEdgeHook(CNWSObject*, Vector, int32_t);

static bool s_InSetAreaCall = false;
void InitSetAreaHook()
{
    static Hooks::Hook s_SetAreaHook = Hooks::HookFunction(&CNWSObject::SetArea,
    +[](CNWSObject *pThis, CNWSArea *pArea) -> void
    {
        s_InSetAreaCall = true;
        s_SetAreaHook->CallOriginal<void>(pThis, pArea);
        s_InSetAreaCall = false;
    }, Hooks::Order::Earliest);
}

void MovementEvents() __attribute__((constructor));
void MovementEvents()
{
    InitOnFirstSubscribe("NWNX_ON_MATERIALCHANGE_.*", []() {
        InitSetAreaHook();
        s_SetPositionMaterialChangeHook = Hooks::HookFunction(&CNWSObject::SetPosition,
            &SetPositionMaterialChangeHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_CREATURE_TILE_CHANGE_.*", []() {
        InitSetAreaHook();
        s_SetPositionTileChangeHook = Hooks::HookFunction(&CNWSObject::SetPosition,
            &SetPositionTileChangeHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_CREATURE_JUMP_TO_POINT_.*", []() {
        s_JumpToPointHook = Hooks::HookFunction(&CNWSCreature::AIActionJumpToPoint,
            &ActionJumpToPointHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_CREATURE_JUMP_TO_OBJECT_.*", []() {
        s_JumpToObjectHook = Hooks::HookFunction(&CNWSCreature::AIActionJumpToObject,
            &ActionJumpToObjectHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_CREATURE_ON_AREA_EDGE_ENTER", []() {
        s_SetPositionAreaEdgeHook = Hooks::HookFunction(&CNWSObject::SetPosition,
            &SetPositionAreaEdgeHook, Hooks::Order::Earliest);
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

            if (oldMaterial != newMaterial || (s_InSetAreaCall && pCreature->m_vPosition == vPosition))
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

            if (pOldTile && pNewTile && (pOldTile != pNewTile || (s_InSetAreaCall && pCreature->m_vPosition == vPosition)))
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

int32_t ActionJumpToPointHook(CNWSCreature* thisPtr, CNWSObjectActionNode* pActionNode)
{
    int32_t retVal;
    std::string result;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET_AREA", Utils::ObjectIDToString((uint32_t)pActionNode->m_pParameter[3]));
        PushEventData("POS_X", std::to_string(*(float*)&pActionNode->m_pParameter[0]));
        PushEventData("POS_Y", std::to_string(*(float*)&pActionNode->m_pParameter[1]));
        PushEventData("POS_Z", std::to_string(*(float*)&pActionNode->m_pParameter[2]));
        return SignalEvent(ev, thisPtr->m_idSelf, &result);
    };

    if (PushAndSignal("NWNX_ON_CREATURE_JUMP_TO_POINT_BEFORE"))
    {
        retVal = s_JumpToPointHook->CallOriginal<int32_t>(thisPtr, pActionNode);
    }
    else
    {
        retVal = atoi(result.c_str()) == 1;
    }

    PushAndSignal("NWNX_ON_CREATURE_JUMP_TO_POINT_AFTER");

    return retVal;
}

int32_t ActionJumpToObjectHook(CNWSCreature* thisPtr, CNWSObjectActionNode* pActionNode)
{
    int32_t retVal;
    std::string result;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("OBJECT", Utils::ObjectIDToString((uint32_t)pActionNode->m_pParameter[0]));
        return SignalEvent(ev, thisPtr->m_idSelf, &result);
    };

    if (PushAndSignal("NWNX_ON_CREATURE_JUMP_TO_OBJECT_BEFORE"))
    {
        retVal = s_JumpToObjectHook->CallOriginal<int32_t>(thisPtr, pActionNode);
    }
    else
    {
        retVal = atoi(result.c_str()) == 1;
    }

    PushAndSignal("NWNX_ON_CREATURE_JUMP_TO_OBJECT_AFTER");

    return retVal;
}

void SetPositionAreaEdgeHook(CNWSObject* thisPtr, Vector vPosition, BOOL bDoingCharacterCopy)
{
    if (thisPtr->m_nObjectType != API::Constants::ObjectType::Creature)
    {
        s_SetPositionAreaEdgeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
        return;
    }

    if (auto *pCreature = Utils::AsNWSCreature(thisPtr))
    {
        CNWSArea *pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(pCreature->m_oidArea);
        if (!pArea)
            pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(pCreature->m_oidDesiredArea);

        if (pArea)
        {
            constexpr float fTileSize = 10.0f;
            constexpr float fOffset = 0.5f;
            const bool bTopPrevious = thisPtr->m_vPosition.y >= (pArea->m_nHeight * fTileSize) - fOffset;
            const bool bRightPrevious= thisPtr->m_vPosition.x >= (pArea->m_nWidth * fTileSize) - fOffset;
            const bool bBottomPrevious = thisPtr->m_vPosition.y <= fOffset;
            const bool bLeftPrevious = thisPtr->m_vPosition.x <= fOffset;

            s_SetPositionAreaEdgeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);

            const bool bTopNow = thisPtr->m_vPosition.y >= (pArea->m_nHeight * fTileSize) - fOffset;
            const bool bRightNow = thisPtr->m_vPosition.x >= (pArea->m_nWidth * fTileSize) - fOffset;
            const bool bBottomNow = thisPtr->m_vPosition.y <= fOffset;
            const bool bLeftNow = thisPtr->m_vPosition.x <= fOffset;

            if ((bTopPrevious != bTopNow) ||
                (bRightPrevious != bRightNow) ||
                (bBottomPrevious != bBottomNow) ||
                (bLeftPrevious != bLeftNow))
            {
                PushEventData("TOP", bTopNow ? "1" : "0");
                PushEventData("RIGHT", bRightNow ? "1" : "0");
                PushEventData("BOTTOM", bBottomNow ? "1" : "0");
                PushEventData("LEFT", bLeftNow ? "1" : "0");
                PushEventData("AREA", Utils::ObjectIDToString(pArea->m_idSelf));
                SignalEvent("NWNX_ON_CREATURE_ON_AREA_EDGE_ENTER", pCreature->m_idSelf);
            }

            return;
        }
    }

    s_SetPositionAreaEdgeHook->CallOriginal<void>(thisPtr, vPosition, bDoingCharacterCopy);
}

}
