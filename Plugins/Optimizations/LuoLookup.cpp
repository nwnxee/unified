#include "nwnx.hpp"
#include "HashTable32.hpp"

#include "API/CNWSObject.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSPlaceable.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

using LuoTable = HashTable32<CLastUpdateObject>;
static HashTable32<LuoTable> s_playerluo;

static float s_UpdateDistances[Constants::ObjectType::MAX + 1];


static Hooks::Hook s_GetLastUpdateObject;
static Hooks::Hook s_CreateNewLastUpdateObject;
static Hooks::Hook s_TestObjectUpdateDifferences;
static Hooks::Hook s_DeleteLastUpdateObjectsForObject;
static Hooks::Hook s_DeleteLastUpdateObjectsInOtherAreas;
static Hooks::Hook s_DestroyPlayer1;
static Hooks::Hook s_SendServerToPlayerGameObjUpdate;
static CLastUpdateObject* GetLastUpdateObject(CNWSPlayer*, ObjectID) __attribute__((hot));
static CLastUpdateObject* CreateNewLastUpdateObject(CNWSMessage*, CNWSPlayer*, CNWSObject*, uint32_t*, uint32_t*);
static void TestObjectUpdateDifferences(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject**, uint32_t*, uint32_t*);
static void MessageDeleteLuo(CNWSMessage*, CLastUpdateObject*, CNWSPlayer*);
static void DeleteLastUpdateObjectsForObject(CNWSMessage*, CNWSPlayer*, OBJECT_ID);
static void DeleteLastUpdateObjectsInOtherAreas(CNWSMessage*, CNWSPlayer*);
static void DestroyPlayer1(CNWSPlayer* pThis);
static BOOL SendServerToPlayerGameObjUpdate(CNWSMessage*, CNWSPlayer*, ObjectID);


void LuoLookup() __attribute__((constructor));
void LuoLookup()
{
    if (Config::Get<bool>("LUO_LOOKUP", false))
    {
        LOG_INFO("LastUpdateObject lookup optimization enabled");
        s_playerluo.Initialize();

        s_CreateNewLastUpdateObject           = Hooks::HookFunction(&CNWSMessage::CreateNewLastUpdateObject, CreateNewLastUpdateObject, Hooks::Order::Early);
        s_DestroyPlayer1                      = Hooks::HookFunction(Functions::_ZN10CNWSPlayerD1Ev, (void*)DestroyPlayer1, Hooks::Order::Early);

        s_GetLastUpdateObject                 = Hooks::HookFunction(&CNWSPlayer::GetLastUpdateObject, GetLastUpdateObject, Hooks::Order::Final);
        s_TestObjectUpdateDifferences         = Hooks::HookFunction(&CNWSMessage::TestObjectUpdateDifferences, TestObjectUpdateDifferences, Hooks::Order::Final);
        s_DeleteLastUpdateObjectsForObject    = Hooks::HookFunction(&CNWSMessage::DeleteLastUpdateObjectsForObject, DeleteLastUpdateObjectsForObject, Hooks::Order::Final);
        s_DeleteLastUpdateObjectsInOtherAreas = Hooks::HookFunction(&CNWSMessage::DeleteLastUpdateObjectsInOtherAreas, DeleteLastUpdateObjectsInOtherAreas, Hooks::Order::Final);

        if (Config::Get<bool>("ALTERNATE_GAME_OBJECT_UPDATE", false))
        {
            LOG_INFO("Using alternative game object update mechanism");
            s_SendServerToPlayerGameObjUpdate = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerGameObjUpdate, SendServerToPlayerGameObjUpdate, Hooks::Order::Final);

            auto dist = Config::Get<float>("OBJECT_UPDATE_DISTANCE", 45.0);
            LOG_INFO("Object update distance is %f", dist);

            for (int32_t i = 0; i <= Constants::ObjectType::MAX; i++)
                s_UpdateDistances[i] = dist * dist;
        }
    }
}

static inline LuoTable& GetLuoTable(CNWSPlayer* player)
{
    auto* tbl = s_playerluo.Get(player->m_nPlayerID);
    if (tbl == nullptr)
    {
        tbl = new LuoTable();
        tbl->Initialize();
        s_playerluo.Add(player->m_nPlayerID, tbl);
    }
    return *tbl;
}

static void DestroyPlayer1(CNWSPlayer* pThis)
{
    auto id = pThis->m_nPlayerID;
    s_DestroyPlayer1->CallOriginal<void>(pThis);
    LuoTable* tbl = nullptr;
    s_playerluo.Delete(id, &tbl);
    delete tbl;
}

static CLastUpdateObject *GetLastUpdateObject(CNWSPlayer* pThis, ObjectID oidLastUpdateObject)
{
    return GetLuoTable(pThis).Get(oidLastUpdateObject);
}

static CLastUpdateObject *CreateNewLastUpdateObject(CNWSMessage* pThis, CNWSPlayer *pPlayer, CNWSObject *pAreaObject, uint32_t *nObjectUpdatesRequired, uint32_t *nObjectAppearanceUpdatesRequired)
{
    auto* luo = s_CreateNewLastUpdateObject->CallOriginal<CLastUpdateObject*>(pThis, pPlayer, pAreaObject, nObjectUpdatesRequired, nObjectAppearanceUpdatesRequired);
    pPlayer->m_lstActiveObjectsLastUpdate.Remove(luo);

    GetLuoTable(pPlayer).Add(luo->m_nId, luo);
    return luo;
}

static void TestObjectUpdateDifferences(CNWSMessage* pThis, CNWSPlayer *pPlayer, CNWSObject *pAreaObject, CLastUpdateObject **pLUO, uint32_t *nObjectUpdatesRequired, uint32_t *nObjectAppearanceUpdatesRequired)
{
    *pLUO = GetLastUpdateObject(pPlayer, pAreaObject->m_idSelf);
    if (*pLUO)
    {
        bool bPlayerObject = (pAreaObject->m_idSelf == pPlayer->GetGameObject()->m_idSelf);
        *nObjectUpdatesRequired           = pThis->ComputeUpdateRequired(pPlayer, pAreaObject, *pLUO, bPlayerObject);
        *nObjectAppearanceUpdatesRequired = pThis->ComputeAppearanceUpdateRequired(pAreaObject, *pLUO);
    }
    else
    {
        *pLUO = CreateNewLastUpdateObject(pThis, pPlayer, pAreaObject, nObjectUpdatesRequired, nObjectAppearanceUpdatesRequired);
    }
}

static void MessageDeleteLuo(CNWSMessage* msg, CLastUpdateObject* luo, CNWSPlayer *player)
{
    // Build Delete Message
    msg->WriteCHAR('D');
    msg->WriteBYTE(luo->m_nObjectType);
    msg->WriteOBJECTIDServer(luo->m_nId);

    if (luo->m_nObjectType == Constants::ObjectType::Item     ||
        luo->m_nObjectType == Constants::ObjectType::Creature ||
        luo->m_nObjectType == Constants::ObjectType::Placeable)
    {
        bool bDelete = true;
        if (auto obj = Utils::AsNWSObject(Utils::GetGameObject(luo->m_nId)))
        {
            auto pgo = player->GetGameObject();
            if (pgo && (obj->GetArea() == pgo->GetArea()))
                bDelete = false;
        }

        msg->WriteBOOL(bDelete);
    }
}

static void DeleteLastUpdateObjectsForObject(CNWSMessage* pThis, CNWSPlayer *pPlayer, OBJECT_ID oidTargetToRemove)
{
    // Never remove yourself..
    if (pPlayer->m_oidNWSObject == oidTargetToRemove)
        return;

    if (auto* luo = GetLastUpdateObject(pPlayer, oidTargetToRemove))
    {
        MessageDeleteLuo(pThis, luo, pPlayer);
        GetLuoTable(pPlayer).Delete(luo->m_nId);
        delete luo;
    }
}

static void DeleteLastUpdateObjectsInOtherAreas(CNWSMessage* pThis, CNWSPlayer *pPlayer)
{
    auto& tbl = GetLuoTable(pPlayer);

    auto* pPlayerCreature = Utils::AsNWSCreature(pPlayer->GetGameObject());
    auto oidArea          = pPlayerCreature ? pPlayerCreature->m_oidArea        : Constants::OBJECT_INVALID;
    auto oidDesiredArea   = pPlayerCreature ? pPlayerCreature->m_oidDesiredArea : Constants::OBJECT_INVALID;

    // if we're in some weird state where this is true, just delete everything
    bool bDeleteAll = (oidArea == Constants::OBJECT_INVALID && oidDesiredArea == Constants::OBJECT_INVALID);

    auto DeleteSingleLuo = [&](CLastUpdateObject* luo) -> bool
    {
        if (!luo) return false;

        bool bDelete = true;
        if (!bDeleteAll)
        {
            if (auto* obj = Utils::AsNWSObject(Utils::GetGameObject(luo->m_nId)))
            {
                if (obj->m_oidArea == oidArea || obj->m_oidArea == oidDesiredArea)
                    bDelete = false;
            }
        }
        if (bDelete)
        {
            MessageDeleteLuo(pThis, luo, pPlayer);
            tbl.Delete(luo->m_nId);
            delete luo;
        }
        return bDelete;
    };

    for (uint32_t b = 0; b < tbl.GetBucketCount(); b++)
    {
        auto& node = tbl.GetNode(b);
        for (uint32_t i = 0; i < tbl.ItemsInNode; i++)
        {
            if (DeleteSingleLuo(node.m_ptrs[i]))
                i--;
        }
        for (uint32_t i = 0; i < node.m_vecSize; i++)
        {
            if (DeleteSingleLuo(node.m_vec[i].m_ptr))
                i--;
        }
    }
}

static inline void UpdateSingleObject(CNWSMessage* msg, CNWSPlayer* player, CNWSObject* pPlayerObj, CNWSObject *obj)
{
    if (msg->TestObjectVisible(obj, pPlayerObj))
    {
        CLastUpdateObject* luo;
        uint32_t update = 0, appearance = 0;
        msg->TestObjectUpdateDifferences(player, obj, &luo, &update, &appearance);
        if (update || appearance)
        {
            msg->WriteGameObjUpdate_UpdateObject(player, obj, luo, update, appearance);
        }
        msg->StoreValuesInLastUpdateObject(player, luo, obj, update, appearance);
    }
    else
    {
        msg->DeleteLastUpdateObjectsForObject(player, obj->m_idSelf);
    }
}

static BOOL SendServerToPlayerGameObjUpdate(CNWSMessage* msg, CNWSPlayer *pPlayer, ObjectID)
{
    auto* pPlayerObj = Utils::AsNWSCreature(pPlayer->GetGameObject());
    if (!pPlayerObj)
        return false;

    static uint32_t msgLimit = Config::Get<uint32_t>("GAMEOBJUPDATE_MESSAGE_LIMIT", 1024);
    msg->CreateWriteMessage(msgLimit + 1024, pPlayer->m_nPlayerID, true);

    DeleteLastUpdateObjectsInOtherAreas(msg, pPlayer);
    auto& tbl = GetLuoTable(pPlayer);

    CNWSArea* area = pPlayerObj->GetArea();
    Vector vPos = pPlayerObj->m_vPosition;
    if (!area)
    {
        area = Utils::AsNWSArea(Utils::GetGameObject(pPlayerObj->m_oidDesiredArea));
        vPos = pPlayerObj->m_vDesiredAreaLocation;
    }

    const uint32_t specialStages = 40;
    const uint32_t objectCount = area ? area->m_aGameObjects.num : 0;
    const uint32_t totalStages = specialStages + objectCount;

    uint32_t stage = 0;
    while (msg->PeekAtWriteMessageSize() < msgLimit && stage != totalStages)
    {
        switch (stage)
        {
            case 0:
            {
                UpdateSingleObject(msg, pPlayer, pPlayerObj, pPlayerObj);
                stage += 10;
                break;
            }
            case 10:
            {
                msg->WriteGameObjUpdate_MajorGUIPanels(pPlayer);
                stage += 10;
                break;
            }
            case 20:
            {
                msg->WriteGameObjUpdate_MinorGUIPanels(pPlayer);
                stage += 10;
                break;
            }
            case 30:
            {
                if (pPlayer->GetIsDM() && !pPlayer->GetIsPlayerDM())
                    msg->WriteGameObjUpdate_DungeonMasterAIState(pPlayer);
                else
                    msg->WriteGameObjUpdate_PartyAIState(pPlayer);
                stage += 10;
                break;
            }
            default:
            {
                // ASSERT(area); // This really should not be possible.
                auto ShouldUpdateObject = [&](CNWSObject* obj) -> bool
                {
                    if (tbl.Get(obj->m_idSelf))
                        return true;

                    if (auto* plc = Utils::AsNWSPlaceable(obj))
                        if (plc->m_bStaticObject)
                            return false;

                    float x = obj->m_vPosition.x - vPos.x;
                    float y = obj->m_vPosition.y - vPos.y;
                    return (x*x + y*y) <= s_UpdateDistances[obj->m_nObjectType];
                };

                auto index = stage - specialStages;
                if (auto* obj = Utils::AsNWSObject(Utils::GetGameObject(area->m_aGameObjects[index])))
                {
                    if (ShouldUpdateObject(obj))
                        UpdateSingleObject(msg, pPlayer, pPlayerObj, obj);
                }
                stage++;
                break;
            }
        }
    }

    msg->WriteGameObjUpdate_WorkRemaining(pPlayerObj, pPlayerObj->GetArea(), stage, totalStages);

    uint8_t *pMessage;
    uint32_t nSize;
    if (msg->GetWriteMessage(&pMessage, &nSize))
    {
        if (nSize)
        {
            return msg->SendServerToPlayerMessage(pPlayer->m_nPlayerID,
                       Constants::MessageMajor::GameObjectUpdate,
                       Constants::MessageGameObjectUpdateMinor::ObjectList,
                       pMessage, nSize);
        }
        return true;
    }
    return false;
}

// No nwscript export, call it manually.
extern "C" ArgumentStack SetObjectUpdateDistance(ArgumentStack&& args)
{
    const auto dist = args.extract<float>();
    const auto objtype = args.extract<int32_t>();
      ASSERT_OR_THROW(objtype >= 0);
      ASSERT_OR_THROW(objtype <= Constants::ObjectType::MAX);

    s_UpdateDistances[objtype] = dist * dist;
    return {};
}


}
