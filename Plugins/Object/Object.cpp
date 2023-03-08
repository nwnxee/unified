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
        Vector pos{};
        pos.z = args.extract<float>();
        pos.y = args.extract<float>();
        pos.x = args.extract<float>();
        auto bUpdateSubareas = !!args.extract<int32_t>();

        pObject->SetPosition(pos, false);

        if (bUpdateSubareas)
        {
            if (auto *pCreature = Utils::AsNWSCreature(pObject))
            {
                pCreature->UpdateSubareasOnJumpPosition(pos, pCreature->m_oidArea);
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
        const auto posX = args.extract<float>();
        const auto posY = args.extract<float>();
        const auto posZ = args.extract<float>();

        if (auto *pArea = Utils::AsNWSArea(Utils::GetGameObject(oidArea)))
        {
            if (!Utils::AddToArea(pObject, pArea, posX, posY, posZ))
                LOG_WARNING("Failed to add object %x to area %x (%f,%f,%f)", pObject->m_idSelf, oidArea, posX, posY, posZ);
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
                if (pTrigger->m_pnOutlineVertices)
                    delete[] pTrigger->m_pnOutlineVertices;

                pTrigger->m_nVertices = vecVerts.size();
                pTrigger->m_nOutlineVertices = vecVerts.size();

                pTrigger->m_pvVertices = new Vector[pTrigger->m_nVertices];
                pTrigger->m_pnOutlineVertices = new int32_t[pTrigger->m_nVertices];

                for(int i = 0; i < pTrigger->m_nVertices; i++)
                {
                    pTrigger->m_pvVertices[i] = vecVerts[i];
                    pTrigger->m_pnOutlineVertices[i] = i;
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
        std::string alias;
        try
        {
            alias = args.extract<std::string>();
        }
        catch(const std::runtime_error& e)
        {
            LOG_WARNING("NWNX_Object_Export() called from NWScript without sAlias parameter. Please update nwnx_object.nss");
            alias = "NWNX";
        }

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
        const auto fX = args.extract<float>();
        const auto fY = args.extract<float>();
        const auto fZ = args.extract<float>();

        Vector vPosition = {fX, fY, fZ};
        return pTrigger->InTrigger(vPosition);
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
            int32_t spellId;
            try
            {
                spellId = args.extract<int32_t>();
            }
            catch(const std::runtime_error& e)
            {
                LOG_WARNING("NWNX_Object_DoSpellImmunity() called from NWScript without new parameter. Please update nwnx_object.nss");
                spellId = -1;
            }

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
            int32_t spellId, spellLevel, spellSchool;
            try
            {
                spellId = args.extract<int32_t>();
                spellLevel = args.extract<int32_t>();
                spellSchool = args.extract<int32_t>();
            }
            catch(const std::runtime_error& e)
            {
                LOG_WARNING("NWNX_Object_DoSpellLevelAbsorption() called from NWScript without new parameters. Please update nwnx_object.nss");
                spellId = -1;
                spellLevel = -1;
                spellSchool = -1;
            }

            ASSERT_OR_THROW(spellLevel <= 10);
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
