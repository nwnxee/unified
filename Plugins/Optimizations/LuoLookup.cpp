#include "nwnx.hpp"
#include "HashTable32.hpp"

#include "API/CNWSObject.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSCreature.hpp"

namespace Optimizations {

using namespace NWNXLib;
using namespace NWNXLib::API;

using LuoTable = HashTable32<CLastUpdateObject>;
static HashTable32<LuoTable> s_playerluo;


static Hooks::Hook s_GetLastUpdateObject;
static Hooks::Hook s_CreateNewLastUpdateObject;
static Hooks::Hook s_TestObjectUpdateDifferences;
static Hooks::Hook s_DeleteLastUpdateObjectsForObject;
static Hooks::Hook s_DeleteLastUpdateObjectsInOtherAreas;
static Hooks::Hook s_DestroyPlayer0;
static Hooks::Hook s_DestroyPlayer1;
static CLastUpdateObject* GetLastUpdateObject(CNWSPlayer*, ObjectID) __attribute__((hot));
static CLastUpdateObject* CreateNewLastUpdateObject(CNWSMessage*, CNWSPlayer*, CNWSObject*, uint32_t*, uint32_t*);
static void TestObjectUpdateDifferences(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject**, uint32_t*, uint32_t*);
static void MessageDeleteLuo(CNWSMessage*, CLastUpdateObject*, CNWSPlayer*);
static void DeleteLastUpdateObjectsForObject(CNWSMessage*, CNWSPlayer*, OBJECT_ID);
static void DeleteLastUpdateObjectsInOtherAreas(CNWSMessage*, CNWSPlayer*);
static void DestroyPlayer0(CNWSPlayer* pThis);
static void DestroyPlayer1(CNWSPlayer* pThis);

void LuoLookup() __attribute__((constructor));
void LuoLookup()
{
    if (Config::Get<bool>("LUO_LOOKUP", false))
    {
        LOG_INFO("LastUpdateObject lookup optimization enabled");
        s_playerluo.Initialize();

        s_CreateNewLastUpdateObject           = Hooks::HookFunction(Functions::_ZN11CNWSMessage25CreateNewLastUpdateObjectEP10CNWSPlayerP10CNWSObjectPjS4_, (void*)CreateNewLastUpdateObject, Hooks::Order::Early);
        s_DestroyPlayer0                      = Hooks::HookFunction(Functions::_ZN10CNWSPlayerD0Ev, (void*)DestroyPlayer0, Hooks::Order::Early);
        s_DestroyPlayer1                      = Hooks::HookFunction(Functions::_ZN10CNWSPlayerD1Ev, (void*)DestroyPlayer1, Hooks::Order::Early);

        s_GetLastUpdateObject                 = Hooks::HookFunction(Functions::_ZN10CNWSPlayer19GetLastUpdateObjectEj, (void*)GetLastUpdateObject, Hooks::Order::Final);
        s_TestObjectUpdateDifferences         = Hooks::HookFunction(Functions::_ZN11CNWSMessage27TestObjectUpdateDifferencesEP10CNWSPlayerP10CNWSObjectPP17CLastUpdateObjectPjS7_, (void*)TestObjectUpdateDifferences, Hooks::Order::Final);
        s_DeleteLastUpdateObjectsForObject    = Hooks::HookFunction(Functions::_ZN11CNWSMessage32DeleteLastUpdateObjectsForObjectEP10CNWSPlayerj, (void*)DeleteLastUpdateObjectsForObject, Hooks::Order::Final);
        s_DeleteLastUpdateObjectsInOtherAreas = Hooks::HookFunction(Functions::_ZN11CNWSMessage35DeleteLastUpdateObjectsInOtherAreasEP10CNWSPlayer, (void*)DeleteLastUpdateObjectsInOtherAreas, Hooks::Order::Final);
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

static void DestroyPlayer0(CNWSPlayer* pThis)
{
    auto id = pThis->m_nPlayerID;
    s_DestroyPlayer0->CallOriginal<void>(pThis);
    LuoTable* tbl = nullptr;
    s_playerluo.Delete(id, &tbl);
    delete tbl;
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
    pPlayer->m_pActiveObjectsLastUpdate->RemoveHead();

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
            if (obj->GetArea() == player->GetGameObject()->GetArea())
                bDelete = false;
        }
        msg->WriteBOOL(bDelete);
    }
}

static void DeleteLastUpdateObjectsForObject(CNWSMessage* pThis, CNWSPlayer *pPlayer, OBJECT_ID oidTargetToRemove)
{
    // Never remove yourself..
    if (pPlayer->GetGameObject()->m_idSelf == oidTargetToRemove)
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
    bool bDeleteAll = !pPlayerCreature || (oidArea == Constants::OBJECT_INVALID && oidDesiredArea == Constants::OBJECT_INVALID);

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


}
