#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CExoArrayList.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSWaypoint.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CItemRepository.hpp"
#include "API/CExoFile.hpp"
#include "API/CNWSUUID.hpp"
#include "API/CLoopingVisualEffect.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSSpellScriptData.hpp"
#include "API/CNWSStore.hpp"
#include "API/CNWSFaction.hpp"
#include "API/CVirtualMachine.hpp"
#include <cstring>

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_EXPORT ArgumentStack GetLocalVariableCount(ArgumentStack&& args)
{
    if (auto *pGameObject = Utils::PopGameObject(args))
    {
        auto *pVarTable = Utils::GetScriptVarTable(pGameObject);
        return (int)pVarTable->m_vars.size();
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetLocalVariable(ArgumentStack&& args)
{
    std::string key = "";
    int type = -1;
    if (auto *pGameObject = Utils::PopGameObject(args))
    {
        const uint32_t index = args.extract<int32_t>();
        auto *pVarTable = Utils::GetScriptVarTable(pGameObject);
        if (index < pVarTable->m_vars.size())
        {
            uint32_t i = 0;
            for (auto& it : pVarTable->m_vars)
            {
                if (i == index)
                {
                    key = it.first.CStr();
                         if (it.second.HasInt())      type = 1;
                    else if (it.second.HasFloat())    type = 2;
                    else if (it.second.HasString())   type = 3;
                    else if (it.second.HasObject())   type = 4;
                    else if (it.second.HasLocation()) type = 5;
                    else if (it.second.HasJson())     type = 6;
                    else type = 0;
                    break;
                }
                i++;
            }
        }
    }
    return {type, key};
}

NWNX_EXPORT ArgumentStack SetPosition(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto vPosition = args.extract<Vector>();
        const auto bUpdateSubareas = !!args.extract<int32_t>();

        pObject->SetPosition(vPosition, false);

        if (bUpdateSubareas)
        {
            if (auto *pCreature = Utils::AsNWSCreature(pObject))
            {
                pCreature->UpdateSubareasOnJumpPosition(vPosition, pCreature->m_oidArea);
            }
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCurrentHitPoints(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        return pObject->m_nCurrentHitPoints;

    return 0;
}

NWNX_EXPORT ArgumentStack SetCurrentHitPoints(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        pObject->m_nCurrentHitPoints = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack SetMaxHitPoints(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        pObject->m_nBaseHitPoints = args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack Serialize(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
        return Utils::SerializeGameObjectB64(pObject);

    return "";
}

// NOTE: Deserialize does not receive an object argument.
NWNX_EXPORT ArgumentStack Deserialize(ArgumentStack&& args)
{
    ObjectID retval = Constants::OBJECT_INVALID;

    const auto serialized = args.extract<std::string>();

    if (CGameObject *pObject = Utils::DeserializeGameObjectB64(serialized))
    {
        retval = static_cast<ObjectID>(pObject->m_idSelf);
        ASSERT(Utils::GetGameObject(retval));
    }

    return retval;
}

NWNX_EXPORT ArgumentStack GetDialogResref(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        if (auto *pCreature = Utils::AsNWSCreature(pObject))
            return pCreature->GetDialogResref().GetResRefStr();
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            return pPlaceable->GetDialogResref().GetResRefStr();
        else if (auto *pDoor = Utils::AsNWSDoor(pObject))
            return pDoor->GetDialogResref().GetResRefStr();
        else
            return pObject->GetDialogResref().GetResRefStr();
    }
    return "";
}

NWNX_EXPORT ArgumentStack SetDialogResref(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto dialog = args.extract<std::string>();
        CResRef resref = CResRef(dialog.c_str());

        if (auto *pCreature = Utils::AsNWSCreature(pObject))
            pCreature->m_pStats->m_cDialog = resref;
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            pPlaceable->m_cDialog = resref;
        else if (auto *pDoor = Utils::AsNWSDoor(pObject))
            pDoor->m_cDialog = resref;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetAppearance(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::PopPlaceable(args))
        return pPlaceable->m_nAppearance;

    return 0;
}

NWNX_EXPORT ArgumentStack SetAppearance(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::PopPlaceable(args))
    {
        const auto app = args.extract<int32_t>();
          ASSERT_OR_THROW(app <= 65535);

        pPlaceable->m_nAppearance = app;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetHasVisualEffect(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto nVfx = args.extract<int32_t>();

        auto& vfx = pObject->m_lstLoopingVisualEffects;
        for (int k = 0; k < vfx.num; k++)
        {
            if (vfx.element[k].m_nId == nVfx)
            {
                return true;
            }
        }
    }

    return false;
}

NWNX_EXPORT ArgumentStack GetDamageImmunity(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const int32_t damageFlags = args.extract<int32_t>();
        ASSERT_OR_THROW(damageFlags >= 0);
        return pObject->GetDamageImmunityByFlags(damageFlags);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack AddToArea(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto oidArea = args.extract<ObjectID>();
          ASSERT_OR_THROW(oidArea != Constants::OBJECT_INVALID);
        const auto vPosition = args.extract<Vector>();

        if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(oidArea)))
        {
            if (!Utils::AddToArea(pObject, pArea, vPosition.x, vPosition.y, vPosition.z))
                LOG_WARNING("Failed to add object %x to area %x (%f,%f,%f)", pObject->m_idSelf, oidArea, vPosition.x, vPosition.y, vPosition.z);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetPlaceableIsStatic(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::PopPlaceable(args))
        return pPlaceable->m_bStaticObject;

    return -1;
}

NWNX_EXPORT ArgumentStack SetPlaceableIsStatic(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::PopPlaceable(args))
    {
        const auto isStatic = !!args.extract<int32_t>();

        // Not sure if this is even needed
        pPlaceable->m_bNeverMakeIntoStaticObject = false;
        pPlaceable->m_bStaticObject = isStatic;
        // These are settings the engine makes if the placeable is static on area load so
        // just mimicking them.
        if (isStatic)
        {
            pPlaceable->m_bPlotObject = true;
            pPlaceable->m_bUseable = false;
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetAutoRemoveKey(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        switch (pObject->m_nObjectType)
        {
            case Constants::ObjectType::Door:
                return Utils::AsNWSDoor(pObject)->m_bAutoRemoveKey;
            case Constants::ObjectType::Placeable:
                return Utils::AsNWSPlaceable(pObject)->m_bAutoRemoveKey;
            default:
                LOG_WARNING("NWNX_Object_GetAutoRemoveKey() called on non door/placeable object.");
                break;
        }
    }

    return -1;
}

NWNX_EXPORT ArgumentStack SetAutoRemoveKey(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto bRemoveKey = !!args.extract<int32_t>();

        switch (pObject->m_nObjectType)
        {
            case Constants::ObjectType::Door:
                Utils::AsNWSDoor(pObject)->m_bAutoRemoveKey = bRemoveKey;
                break;
            case Constants::ObjectType::Placeable:
                Utils::AsNWSPlaceable(pObject)->m_bAutoRemoveKey = bRemoveKey;
                break;
            default:
                LOG_WARNING("NWNX_Object_SetAutoRemoveKey() called on non door/placeable object.");
                break;
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetTriggerGeometry(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pObject = Utils::PopObject(args))
    {
        if (auto *pTrigger = Utils::AsNWSTrigger(pObject))
        {
            retVal.reserve(32 * pTrigger->m_nVertices);

            for(int i = 0; i < pTrigger->m_nVertices; i++)
            {
                retVal += "{" + std::to_string(pTrigger->m_pvVertices[i].x) + ", " +
                                std::to_string(pTrigger->m_pvVertices[i].y) + ", " +
                                std::to_string(pTrigger->m_pvVertices[i].z) + "}";
            }
        }
        else
        {
            LOG_WARNING("NWNX_Object_GetTriggerGeometry() called on non trigger object.");
        }
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack SetTriggerGeometry(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto sGeometry = args.extract<std::string>();

        if (auto *pTrigger = Utils::AsNWSTrigger(pObject))
        {
            auto str = sGeometry.c_str();
            std::vector<Vector> vecVerts;
            Vector vec = {};

            do {
                int cnt = std::sscanf(str, "{%f,%f,%f", &vec.x, &vec.y, &vec.z);

                if (cnt != 2 && cnt != 3)
                {
                    LOG_NOTICE("NWNX_Object_SetTriggerGeometry() invalid geometry string at: %s", str);
                    break;
                }

                if (cnt == 2)
                    vec.z = pTrigger->GetArea()->ComputeHeight(vec);

                vecVerts.push_back(vec);
            } while ((str = std::strstr(str + 1, "{")));

            if (vecVerts.size() > 2)
            {
                CNWSArea *pArea = pTrigger->GetArea();
                pTrigger->RemoveFromArea();

                if (pTrigger->m_pvVertices)
                    delete[] pTrigger->m_pvVertices;

                pTrigger->m_nVertices = vecVerts.size();
                pTrigger->m_pvVertices = new Vector[pTrigger->m_nVertices];

                for(int i = 0; i < pTrigger->m_nVertices; i++)
                {
                    pTrigger->m_pvVertices[i] = vecVerts[i];
                }

                Utils::AddToArea(pTrigger, pArea, pTrigger->m_pvVertices[0].x, pTrigger->m_pvVertices[0].y, pTrigger->m_pvVertices[0].z);
            }
            else
            {
                LOG_WARNING("NWNX_Object_SetTriggerGeometry() called with less than 3 vertices.");
            }
        }
        else
        {
            LOG_WARNING("NWNX_Object_SetTriggerGeometry() called on non trigger object.");
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack Export(ArgumentStack&& args)
{
    if (auto *pGameObject = Utils::PopObject(args))
    {
        const auto fileName = args.extract<std::string>();
          ASSERT_OR_THROW(!fileName.empty());
          ASSERT_OR_THROW(fileName.size() <= 16);
        auto alias = args.extract<std::string>();

        if (!Utils::IsValidCustomResourceDirectoryAlias(alias))
        {
            LOG_WARNING("NWNX_Object_Export() called with an invalid alias: %s, defaulting to 'NWNX'", alias);
            alias = "NWNX";
        }

        auto ExportObject = [&](RESTYPE resType) -> void
        {
            std::vector<uint8_t> serialized = Utils::SerializeGameObject(pGameObject, true);

            if (!serialized.empty())
            {
                auto file = CExoFile((alias + ":" + fileName).c_str(), resType, "wb");

                if (file.FileOpened())
                {
                    file.Write(serialized.data(), serialized.size(), 1);
                    file.Flush();
                }
            }
        };

        switch (pGameObject->m_nObjectType)
        {
            case Constants::ObjectType::Creature:   ExportObject(Constants::ResRefType::UTC); break;
            case Constants::ObjectType::Item:       ExportObject(Constants::ResRefType::UTI); break;
            case Constants::ObjectType::Placeable:  ExportObject(Constants::ResRefType::UTP); break;
            case Constants::ObjectType::Waypoint:   ExportObject(Constants::ResRefType::UTW); break;
            case Constants::ObjectType::Store:      ExportObject(Constants::ResRefType::UTM); break;
            case Constants::ObjectType::Door:       ExportObject(Constants::ResRefType::UTD); break;
            case Constants::ObjectType::Trigger:    ExportObject(Constants::ResRefType::UTT); break;
            default:
                LOG_ERROR("Invalid object type for ExportObject");
                break;
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetInt(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());

        return pObject->nwnxGet<int32_t>("PERINT!" + varName).value_or(0);
    }
    return 0;
}

NWNX_EXPORT ArgumentStack SetInt(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());
        const auto value = args.extract<int32_t>();
        const bool persist = args.extract<int32_t>() != 0;

        pObject->nwnxSet("PERINT!" + varName, value, persist);
    }

    return {};
}

NWNX_EXPORT ArgumentStack DeleteInt(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());

        pObject->nwnxRemove("PERINT!" + varName);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetString(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());

        return pObject->nwnxGet<std::string>("PERSTR!" + varName).value_or("");
    }
    return "";
}

NWNX_EXPORT ArgumentStack SetString(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());
        const auto value = args.extract<std::string>();
        const bool persist = args.extract<int32_t>() != 0;

        pObject->nwnxSet("PERSTR!" + varName, value, persist);
    }

    return {};
}

NWNX_EXPORT ArgumentStack DeleteString(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());

        pObject->nwnxRemove("PERSTR!" + varName);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetFloat(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());

        return pObject->nwnxGet<float>("PERFLT!" + varName).value_or(0.0f);
    }

    return 0.0f;
}

NWNX_EXPORT ArgumentStack SetFloat(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());
        const auto value = args.extract<float>();
        const bool persist = args.extract<int32_t>() != 0;

        pObject->nwnxSet("PERFLT!" + varName, value, persist);
    }

    return {};
}


NWNX_EXPORT ArgumentStack DeleteFloat(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto varName = args.extract<std::string>();
          ASSERT_OR_THROW(!varName.empty());

        pObject->nwnxRemove("PERFLT!" + varName);
    }

    return {};
}

NWNX_EXPORT ArgumentStack DeleteVarRegex(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto regex = args.extract<std::string>();
          ASSERT_OR_THROW(!regex.empty());

        pObject->nwnxRemoveRegex("((?:PERINT!)|(?:PERSTR!)|(?:PERFLT!))" + regex);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetPositionIsInTrigger(ArgumentStack&& args)
{
    if (auto *pTrigger = Utils::PopTrigger(args))
    {
        return pTrigger->InTrigger(args.extract<Vector>());
    }

    return false;
}

NWNX_EXPORT ArgumentStack GetInternalObjectType(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopGameObject(args))
        return pObject->m_nObjectType;

    return -1;
}

NWNX_EXPORT ArgumentStack AcquireItem(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto oidItem = args.extract<ObjectID>();
          ASSERT_OR_THROW(oidItem != Constants::OBJECT_INVALID);

        if (auto *pItem = Utils::AsNWSItem(Utils::GetGameObject(oidItem)))
            return Utils::AcquireItem(pItem, pObject);
    }

    return false;
}

NWNX_EXPORT ArgumentStack ClearSpellEffectsOnOthers(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        pObject->ClearSpellEffectsOnOthers();

    return {};
}

NWNX_EXPORT ArgumentStack PeekUUID(ArgumentStack&& args)
{
    if (auto *pGameObject = Utils::PopGameObject(args))
    {
        if (CNWSUUID::CanCarryUUID(pGameObject->m_nObjectType))
        {
            if (auto *pArea = Utils::AsNWSArea(pGameObject))
                return pArea->m_pUUID.m_uuid.CStr();
            else if (auto *pObject = Utils::AsNWSObject(pGameObject))
                return pObject->m_pUUID.m_uuid.CStr();
        }
    }

    return "";
}

NWNX_EXPORT ArgumentStack GetDoorHasVisibleModel(ArgumentStack&& args)
{
    if (auto *pDoor = Utils::PopDoor(args))
        return pDoor->m_bVisibleModel;

    return false;
}

NWNX_EXPORT ArgumentStack GetIsDestroyable(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        return pObject->m_bDestroyable;

    return false;
}

NWNX_EXPORT ArgumentStack DoSpellImmunity(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        if(auto *pVersus = Utils::PopObject(args))
        {
            const auto spellId = args.extract<int32_t>();
            uint32_t prevSpellId;
            auto pAoEObject = Utils::AsNWSAreaOfEffectObject(pVersus);
            if(spellId>=0)
            {
                if(pAoEObject)
                {
                    prevSpellId = pAoEObject->m_nSpellId;
                    pAoEObject->m_nSpellId = spellId;
                }
                else
                {
                    prevSpellId = pVersus->m_nLastSpellId;
                    pVersus->m_nLastSpellId = spellId;
                }
            }

            auto ret = pObject->DoSpellImmunity(pVersus);

            if(spellId>=0)
            {
                if(pAoEObject)
                {
                    pAoEObject->m_nSpellId = prevSpellId;
                }
                else
                {
                    pVersus->m_nLastSpellId = prevSpellId;
                }
            }

            return ret;
        }
    }

    return -1;
}

NWNX_EXPORT ArgumentStack DoSpellLevelAbsorption(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        if(auto *pVersus = Utils::PopObject(args))
        {
            const auto spellId = args.extract<int32_t>();
            const auto spellLevel = args.extract<int32_t>();
              ASSERT_OR_THROW(spellLevel <= 10);
            const auto spellSchool = args.extract<int32_t>();
              ASSERT_OR_THROW(spellSchool <= 8);

            auto pCaster = Utils::AsNWSCreature(pVersus);
            if(!pCaster)
                return -1;

            if(pObject->m_appliedEffects.num < 1)
                return -1;

            uint32_t prevSpellId = pVersus->m_nLastSpellId;
            if(spellId >= 0)
            {
                pVersus->m_nLastSpellId = spellId;
            }

            auto *pSpellArray = Globals::Rules()->m_pSpellArray;
            auto *pSpell = pSpellArray->GetSpell(pVersus->m_nLastSpellId);

            uint8_t prevSpellSchool;
            if(pSpell && spellSchool >= 0)
            {
                prevSpellSchool = pSpell->m_nSchool;
                pSpell->m_nSchool = spellSchool;
            }

            uint8_t prevSpellLevel;
            BOOL prevLastItemCastSpell;
            if(pSpell && spellLevel >= 0)
            {
                prevLastItemCastSpell = pCaster->m_bLastItemCastSpell;
                prevSpellLevel = pSpell->m_nInnateLevel;

                pCaster->m_bLastItemCastSpell = 1; // DoSpellLevelAbsorption uses innate level in case of item spells
                pSpell->m_nInnateLevel = spellLevel;
            }

            auto ret = pObject->DoSpellLevelAbsorption(pVersus);

            if(pSpell && spellLevel >= 0)
            {
                pCaster->m_bLastItemCastSpell = prevLastItemCastSpell;
                pSpell->m_nInnateLevel = prevSpellLevel;
            }

            if(pSpell && spellSchool >= 0)
            {
                pSpell->m_nSchool = prevSpellSchool;
            }

            if(spellId > 0)
            {
                pVersus->m_nLastSpellId = prevSpellId;
            }

            return ret;
        }
    }

    return -1;
}

NWNX_EXPORT ArgumentStack SetHasInventory(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::PopPlaceable(args))
        pPlaceable->m_bHasInventory = !!args.extract<int32_t>();

    return {};
}

NWNX_EXPORT ArgumentStack GetCurrentAnimation(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        return pObject->m_nAnimation;

    return -1;
}

NWNX_EXPORT ArgumentStack GetAILevel(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        return pObject->m_nAILevel;

    return -1;
}

NWNX_EXPORT ArgumentStack SetAILevel(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto nLevel = args.extract<int32_t>();
        ASSERT_OR_THROW(nLevel >= -1);
        ASSERT_OR_THROW(nLevel <= 4);
        auto *ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->SetAILevel(pObject, nLevel);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetMapNote(ArgumentStack&& args)
{
    if (auto *pWaypoint = Utils::PopWaypoint(args))
    {
        auto nGender = args.extract<int32_t>();
        auto nID = args.extract<int32_t>();

        return Utils::ExtractLocString(pWaypoint->m_szMapNote, nID, nGender);
    }

    return "";
}

NWNX_EXPORT ArgumentStack SetMapNote(ArgumentStack&& args)
{
    if (auto *pWaypoint = Utils::PopWaypoint(args))
    {
        auto sMapNote = args.extract<std::string>();
        auto nGender = args.extract<int32_t>();
        auto nID = args.extract<int32_t>();

        pWaypoint->m_bMapNote = true;
        pWaypoint->m_szMapNote = Utils::CreateLocString(sMapNote, nID, nGender);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetLastSpellCastFeat(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        return pObject->m_nLastSpellCastFeat;
    }

    return -1;
}

NWNX_EXPORT ArgumentStack SetLastTriggered(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        auto lastObject = args.extract<ObjectID>();

        if (auto *pDoor = Utils::AsNWSDoor(pObject))
            pDoor->m_oidLastTriggered = lastObject;
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            pPlaceable->m_oidLastTriggered = lastObject;
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetAoEObjectDurationRemaining(ArgumentStack&& args)
{
    auto *pAoEObject = Utils::AsNWSAreaOfEffectObject(Utils::PopObject(args));
    return pAoEObject ? float(pAoEObject->m_nDuration) / 1000 : 0.0f;
}

NWNX_EXPORT ArgumentStack SetConversationPrivate(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        pObject->m_bPrivateConversation = !!args.extract<int32_t>();
    }

    return {};
}

NWNX_EXPORT ArgumentStack SetAoEObjectRadius(ArgumentStack&& args)
{
    if (auto *pAoE = Utils::AsNWSAreaOfEffectObject(Utils::PopObject(args)))
    {
        const auto radius = args.extract<float>();
          ASSERT_OR_THROW(radius > 0.0f);

        if (pAoE->m_nShape == 0)
            pAoE->SetShape(0, radius);
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetAoEObjectRadius(ArgumentStack&& args)
{
    if (auto *pAoE = Utils::AsNWSAreaOfEffectObject(Utils::PopObject(args)))
    {
        if (pAoE->m_nShape == 0)
            return pAoE->m_fRadius;
    }

    return 0.0f;
}

NWNX_EXPORT ArgumentStack GetLastSpellCastSpontaneous(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        return pObject->m_bLastSpellCastSpontaneous;
    }

    return 0;
}

NWNX_EXPORT ArgumentStack GetLastSpellCastDomainLevel(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        return pObject->m_nLastDomainLevel;
    }

    return 0;
}

NWNX_EXPORT ArgumentStack ForceAssignUUID(ArgumentStack&& args)
{
    if (auto *pGameObject = Utils::PopGameObject(args))
    {
        auto GetUUIDPtr = [](CGameObject* obj) -> CNWSUUID*
        {
            if (auto *nwo = Utils::AsNWSObject(obj)) return &nwo->m_pUUID;
            else if (auto *are = Utils::AsNWSArea(obj)) return &are->m_pUUID;
            else return nullptr;
        };

        auto sUUID = args.extract<std::string>();

        // Internal UUID references in the game are all in exactly this format.
        const auto cUUID = CUUID::rebuild(sUUID);
        ASSERT_OR_THROW(cUUID.str() == sUUID);

        auto *newuuid = GetUUIDPtr(pGameObject);
        ASSERT_OR_THROW(newuuid);

        using MapType = std::unordered_map<std::string, CGameObject*>;
        auto& map = *reinterpret_cast<MapType*>(CNWSUUID::GetMapPtr());

        if (map.find(sUUID) != map.end())
        {
            auto *old = GetUUIDPtr(map.at(sUUID));
            ASSERT_OR_THROW(old);
            old->m_uuid = "";
            map.erase(sUUID);
        }

        newuuid->TryAssign(sUUID);
    }

    return {};
}

int32_t GetItemRepositoryCount(CItemRepository *pRepo)
{
    auto nItems = 0;
    for (auto *pNode = pRepo->m_oidItems.m_pcExoLinkedListInternal->pHead; pNode; pNode = pNode->pNext)
    {
        if (auto *pItem = pRepo->ItemListGetItem(pNode))
        {
            nItems++;
            if (auto *pItemRepo = pItem->m_pItemRepository)
                nItems += pItemRepo->m_oidItems.Count();
            }
        }

    return nItems;
}

NWNX_EXPORT ArgumentStack GetInventoryItemCount(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        CItemRepository *pRepo;

        if (auto *pCreature = Utils::AsNWSCreature(pObject))
            pRepo = pCreature->m_pcItemRepository;
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            pRepo = pPlaceable->m_pcItemRepository;
        else if (auto *pItem = Utils::AsNWSItem(pObject))
            pRepo = pItem->m_pItemRepository;
        else if (auto *pStore = Utils::AsNWSStore(pObject))
        {
            auto nItems = 0;
            for (int n = 0; n < 5; n++)
            {
                pRepo = pStore->m_aInventory[n];
                nItems += GetItemRepositoryCount (pRepo);
            }
            return nItems;
        }
        else
            return 0;

        auto nItems = GetItemRepositoryCount(pRepo);
        return nItems;
    }

    return 0;
}

NWNX_EXPORT ArgumentStack OverrideSpellProjectileVFX(ArgumentStack&& args)
{
    static Hooks::Hook s_BroadcastSafeProjectileHook =
            Hooks::HookFunction(&CNWSObject::BroadcastSafeProjectile,
            (void*)+[](CNWSObject *pThis, ObjectID oidOriginator, ObjectID oidTarget, Vector vOriginator, Vector vTarget, uint32_t nDelta,
                       uint8_t nProjectileType, uint32_t nSpellID, uint8_t nAttackResult, uint8_t nProjectilePathType) -> void
            {
                if (nProjectileType >= 6)
                {
                    if (auto *pOriginator = Utils::AsNWSObject(Utils::GetGameObject(oidOriginator)))
                    {
                        if (auto projectileVfxOverride = pOriginator->nwnxGet<int32_t>("OSPVFX_TYPE"))
                            nProjectileType = *projectileVfxOverride;

                        if (auto projectilePathOverride = pOriginator->nwnxGet<int32_t>("OSPVFX_PATH"))
                            nProjectilePathType = *projectilePathOverride;

                        if (auto spellIDOverride = pOriginator->nwnxGet<int32_t>("OSPVFX_SPELLID"))
                            nSpellID = *spellIDOverride;
                    }
                }

                s_BroadcastSafeProjectileHook->CallOriginal<void>(pThis, oidOriginator, oidTarget, vOriginator, vTarget, nDelta, nProjectileType, nSpellID, nAttackResult, nProjectilePathType);
            }, Hooks::Order::Late);

    if (auto *pObject = Utils::PopGameObject(args))
    {
        const auto nProjectileVfx = args.extract<int32_t>();
          ASSERT_OR_THROW(nProjectileVfx >= 6 || nProjectileVfx < 0);
          ASSERT_OR_THROW(nProjectileVfx <= 7);
        const auto nProjectilePath = args.extract<int32_t>();
          ASSERT_OR_THROW(nProjectilePath <= 4);
        const auto nSpellId = args.extract<int32_t>();
          ASSERT_OR_THROW(nSpellId < Globals::Rules()->m_pSpellArray->m_nNumSpells);
        const auto bPersist = !!args.extract<int32_t>();

        if (nProjectileVfx < 0)
        {
            pObject->nwnxRemove("OSPVFX_TYPE");
            pObject->nwnxRemove("OSPVFX_PATH");
            pObject->nwnxRemove("OSPVFX_SPELLID");
        }
        else
        {
            pObject->nwnxSet("OSPVFX_TYPE", nProjectileVfx, bPersist);
            pObject->nwnxSet("OSPVFX_PATH", nProjectilePath, bPersist);
            pObject->nwnxSet("OSPVFX_SPELLID", nSpellId, bPersist);
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack GetLastSpellInstant(ArgumentStack&&)
{
    static bool s_LastSpellInstant = false;
    static bool s_IsInstantSpell = false;

    struct SpellScriptData
    {
        CNWSSpellScriptData *pSpellScriptData = nullptr;
        bool bInstantSpell = false;
        ~SpellScriptData() { delete pSpellScriptData; }
    };

    static Hooks::Hook pSpellCastAndImpactHook = Hooks::HookFunction(&CNWSObject::SpellCastAndImpact,
    (void*)+[](CNWSObject *pThis, uint32_t nSpellId, Vector vTargetPosition, ObjectID oidTarget, uint8_t nMultiClass, ObjectID oidItem,
               BOOL bSpellCountered, BOOL bCounteringSpell, uint8_t nProjectilePathType, BOOL bInstantSpell) -> void
    {
        s_IsInstantSpell = bInstantSpell;
        pSpellCastAndImpactHook->CallOriginal<void>(pThis, nSpellId, vTargetPosition, oidTarget, nMultiClass, oidItem, bSpellCountered, bCounteringSpell, nProjectilePathType, bInstantSpell);
        s_IsInstantSpell = false;
    }, Hooks::Order::Earliest);

    static Hooks::Hook pAddEventDeltaTimeHook = Hooks::HookFunction(&CServerAIMaster::AddEventDeltaTime,
    (void*)+[](CServerAIMaster *pThis, uint32_t nDaysFromNow, uint32_t nTimeFromNow, ObjectID nCallerObjectId, ObjectID nObjectId, uint32_t nEventId, void *pEventData) -> BOOL
    {
        if (pEventData && (nEventId == Constants::AIMasterEvent::SpellImpact || nEventId == Constants::AIMasterEvent::ItemOnHitSpellImpact))
        {
            auto *pNewSpellScriptData = new SpellScriptData;
            pNewSpellScriptData->pSpellScriptData = (CNWSSpellScriptData*)pEventData;
            pNewSpellScriptData->bInstantSpell = s_IsInstantSpell;
            return pAddEventDeltaTimeHook->CallOriginal<BOOL>(pThis, nDaysFromNow, nTimeFromNow, nCallerObjectId, nObjectId, nEventId, pNewSpellScriptData);
        }
        return pAddEventDeltaTimeHook->CallOriginal<BOOL>(pThis, nDaysFromNow, nTimeFromNow, nCallerObjectId, nObjectId, nEventId, pEventData);
    }, Hooks::Order::Early);

    static Hooks::Hook pCreatureEventHandlerHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature12EventHandlerEjjPvjj,
    (void*)+[](CNWSCreature *pThis, uint32_t nEventId, ObjectID nCallerObjectId, void *pEventData, uint32_t nCalendarDay, uint32_t nTimeOfDay) -> void
    {
        if (nEventId == Constants::AIMasterEvent::SpellImpact || nEventId == Constants::AIMasterEvent::ItemOnHitSpellImpact)
        {
            if (!pEventData) return;
            auto *pSpellScriptData = (SpellScriptData*)pEventData;

            if (pSpellScriptData->pSpellScriptData->m_oidCaster == nCallerObjectId)
            {
                uint32_t lastSpellId;
                uint32_t lastSpellObjectTarget;
                Vector lastSpellLocationTarget;
                uint32_t lastSpellCastItem;
                uint16_t lastSpellCastFeat;
                BOOL lastItemCastSpell;
                int32_t lastItemCastSpellLevel;
                bool lastSpellInstant;

                if (nEventId == Constants::AIMasterEvent::ItemOnHitSpellImpact)
                {
                    lastSpellId = pThis->m_nLastSpellId;
                    lastSpellObjectTarget = pThis->m_oidLastSpellTarget;
                    lastSpellLocationTarget = pThis->m_vLastSpellTarget;
                    lastSpellCastItem = pThis->m_oidLastSpellCastItem;
                    lastSpellCastFeat = pThis->m_nLastSpellCastFeat;
                    lastItemCastSpell = pThis->m_bLastItemCastSpell;
                    lastItemCastSpellLevel = pThis->m_nLastItemCastSpellLevel;
                    lastSpellInstant = s_LastSpellInstant;
                }

                pThis->m_nLastSpellId = pSpellScriptData->pSpellScriptData->m_nSpellId;
                pThis->m_oidLastSpellTarget = pSpellScriptData->pSpellScriptData->m_oidTarget;
                pThis->m_vLastSpellTarget = pSpellScriptData->pSpellScriptData->m_vTargetPosition;
                pThis->m_oidLastSpellCastItem = pSpellScriptData->pSpellScriptData->m_oidItem;
                pThis->m_nLastSpellCastFeat = pSpellScriptData->pSpellScriptData->m_nFeatId;
                if (auto *pTarget = Utils::AsNWSObject(Utils::GetGameObject(pSpellScriptData->pSpellScriptData->m_oidTarget)))
                {
                    if (pThis->GetArea() == pTarget->GetArea())
                        pThis->m_vLastSpellTarget = pTarget->m_vPosition;
                }
                pThis->m_nEffectSpellId = pSpellScriptData->pSpellScriptData->m_nSpellId;
                pThis->m_nSavingThrowSpellId = pSpellScriptData->pSpellScriptData->m_nSpellId;
                if (nEventId == Constants::AIMasterEvent::ItemOnHitSpellImpact)
                {
                    pThis->m_bLastItemCastSpell = true;
                    pThis->m_nLastItemCastSpellLevel = pSpellScriptData->pSpellScriptData->m_nItemCastLevel;
                    pThis->CalculateLastSpellProjectileTime();
                }
                s_LastSpellInstant = pSpellScriptData->bInstantSpell;

                Globals::VirtualMachine()->RunScript(&pSpellScriptData->pSpellScriptData->m_sScript, pThis->m_idSelf, true);

                pThis->m_nEffectSpellId = 0xFFFFFFFF;
                pThis->m_nSavingThrowSpellId = 0xFFFFFFFF;
                pThis->m_bLastItemCastSpell = false;
                pThis->m_nLastItemCastSpellLevel = -1;
                s_LastSpellInstant = false;
                if (nEventId == Constants::AIMasterEvent::ItemOnHitSpellImpact)
                {
                    pThis->m_nLastSpellId = lastSpellId;
                    pThis->m_oidLastSpellTarget = lastSpellObjectTarget;
                    pThis->m_vLastSpellTarget = lastSpellLocationTarget;
                    pThis->m_oidLastSpellCastItem = lastSpellCastItem;
                    pThis->m_nLastSpellCastFeat = lastSpellCastFeat;
                    pThis->m_bLastItemCastSpell = lastItemCastSpell;
                    pThis->m_nLastItemCastSpellLevel = lastItemCastSpellLevel;
                    s_LastSpellInstant = lastSpellInstant;
                }
            }

            delete pSpellScriptData;
        }
        else
            pCreatureEventHandlerHook->CallOriginal<void>(pThis, nEventId, nCallerObjectId, pEventData, nCalendarDay, nTimeOfDay);
    }, Hooks::Order::Late);

    static Hooks::Hook pPlaceableEventHandlerHook = Hooks::HookFunction(API::Functions::_ZN13CNWSPlaceable12EventHandlerEjjPvjj,
    (void*)+[](CNWSPlaceable *pThis, uint32_t nEventId, ObjectID nCallerObjectId, void *pEventData, uint32_t nCalendarDay, uint32_t nTimeOfDay) -> void
    {
        if (nEventId == Constants::AIMasterEvent::SpellImpact)
        {
            if (!pEventData) return;
            auto *pSpellScriptData = (SpellScriptData*)pEventData;

            if (pSpellScriptData->pSpellScriptData->m_oidCaster == nCallerObjectId)
            {
                pThis->m_nLastSpellId = pSpellScriptData->pSpellScriptData->m_nSpellId;
                pThis->m_oidLastSpellTarget = pSpellScriptData->pSpellScriptData->m_oidTarget;
                pThis->m_vLastSpellTarget = pSpellScriptData->pSpellScriptData->m_vTargetPosition;
                if (auto *pTarget = Utils::AsNWSObject(Utils::GetGameObject(pSpellScriptData->pSpellScriptData->m_oidTarget)))
                {
                    if (pThis->GetArea() == pTarget->GetArea())
                        pThis->m_vLastSpellTarget = pTarget->m_vPosition;
                }
                pThis->m_nEffectSpellId = pSpellScriptData->pSpellScriptData->m_nSpellId;
                pThis->m_nSavingThrowSpellId = pSpellScriptData->pSpellScriptData->m_nSpellId;
                s_LastSpellInstant = pSpellScriptData->bInstantSpell;

                Globals::VirtualMachine()->RunScript(&pSpellScriptData->pSpellScriptData->m_sScript, pThis->m_idSelf, true);

                pThis->m_nEffectSpellId = 0xFFFFFFFF;
                pThis->m_nSavingThrowSpellId = 0xFFFFFFFF;
                s_LastSpellInstant = false;
            }
            delete pSpellScriptData;
        }
        else
            pPlaceableEventHandlerHook->CallOriginal<void>(pThis, nEventId, nCallerObjectId, pEventData, nCalendarDay, nTimeOfDay);
    }, Hooks::Order::Late);

    return s_LastSpellInstant;
}

NWNX_EXPORT ArgumentStack SetTrapCreator(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        auto newCreator = Constants::OBJECT_INVALID;
        auto newFaction = 1; //STANDARD_FACTION_HOSTILE

        if(auto *pCreator = Utils::PopCreature(args))
        {
            newCreator = pCreator->m_idSelf;
            if (auto *pFaction = pCreator->GetFaction())
                newFaction = pFaction->m_nFactionId;
        }

        if (auto *pDoor = Utils::AsNWSDoor(pObject))
        {
            pDoor->m_oidTrapCreator = newCreator;
            pDoor->m_nTrapFactionId = newFaction;
        }
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
        {
            pPlaceable->m_oidTrapCreator = newCreator;
            pPlaceable->m_nTrapFaction = newFaction;
        }
        else if (auto *pTrigger = Utils::AsNWSTrigger(pObject))
        {
            pTrigger->m_oidCreator = newCreator;
            pTrigger->m_nFactionId = newFaction;
        }
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetLocalizedName(ArgumentStack&& args)
{
    if (auto *pGameObject = Utils::PopGameObject(args))
    {
        const auto nLanguage = args.extract<int32_t>();
        const auto nGender   = args.extract<int32_t>();

        CExoString myString;

        if (auto *pArea = Utils::AsNWSArea(pGameObject))
            pArea->m_lsName.GetString(nLanguage, &myString, nGender);
        else if (auto *pStore = Utils::AsNWSStore(pGameObject))
            pStore->m_sName.GetString(nLanguage, &myString, nGender);
        else if (auto *pObject = Utils::AsNWSObject(pGameObject))
            pObject->GetFirstName().GetString(nLanguage, &myString, nGender);

        return myString;
    }
    return {};
}

NWNX_EXPORT ArgumentStack SetLocalizedName(ArgumentStack&& args)
{
    if (auto *pGameObject = Utils::PopGameObject(args))
    {
        const auto sName     = args.extract<std::string>();
        const auto nLanguage = args.extract<int32_t>();
        const auto nGender   = args.extract<int32_t>();

        CExoString myString(sName);
        if (auto *pArea = Utils::AsNWSArea(pGameObject))
        {
            pArea->m_lsName.RemoveString(nLanguage, nGender);
            pArea->m_lsName.AddString(nLanguage, myString, nGender);
        }
        else if (auto *pStore = Utils::AsNWSStore(pGameObject))
        {
            pStore->m_sName.RemoveString(nLanguage, nGender);
            pStore->m_sName.AddString(nLanguage, myString, nGender);
        }
        else if (auto *pObject = Utils::AsNWSObject(pGameObject))
        {
            pObject->GetFirstName().RemoveString(nLanguage, nGender);
            pObject->GetFirstName().AddString(nLanguage, myString, nGender);
        }
    }

    return {};
}
