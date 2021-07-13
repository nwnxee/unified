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
            if (vfx.element[k] && vfx.element[k]->m_nId == nVfx)
            {
                return true;
            }
        }
    }

    return false;
}

NWNX_EXPORT ArgumentStack CheckFit(ArgumentStack&& args)
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
        else
        {
            return -1;
        }
        const auto baseitem = args.extract<int32_t>();

        if (pRepo == nullptr || Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseitem) == nullptr)
        {
            LOG_ERROR("Base Item or Object Repository not found.");
            return -1;
        }

        static CNWSItem *tmp = new CNWSItem(Constants::OBJECT_INVALID);
        tmp->m_nBaseItem = baseitem;

        uint8_t width  = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseitem)->m_nInvSlotWidth;
        uint8_t height = Globals::Rules()->m_pBaseItemArray->GetBaseItem(baseitem)->m_nInvSlotHeight;

        for (uint8_t y = 0; y < (pRepo->m_nHeight - height + 1); y++)
        {
            for (uint8_t x = 0; x < (pRepo->m_nWidth - width + 1); x++)
            {
                if (pRepo->CheckFit(tmp, x, y))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    return -1;
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

NWNX_EXPORT ArgumentStack RemoveIconEffect(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto nIcon = args.extract<int32_t>();

        for (int i = 0; i < pObject->m_appliedEffects.num; i++)
        {
            auto *eff = pObject->m_appliedEffects.element[i];

            if (eff->m_sCustomTag == "NWNX_Object_IconEffect" && eff->m_nParamInteger[0] == nIcon)
            {
                pObject->RemoveEffect(eff);
                break;
            }
        }
    }

    return {};
}

NWNX_EXPORT ArgumentStack AddIconEffect(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto nIcon = args.extract<int32_t>();
        ASSERT_OR_THROW(nIcon > 0);
        const auto fDuration = args.extract<float>();

        for (int i = 0; i < pObject->m_appliedEffects.num; i++)
        {
            auto *eff = pObject->m_appliedEffects.element[i];

            if (eff->m_sCustomTag == "NWNX_Object_IconEffect" && eff->m_nParamInteger[0] == nIcon)
            {
                pObject->RemoveEffect(eff);
                break;
            }
        }

        auto *effIcon = new CGameEffect(true);
        effIcon->m_oidCreator = 0;
        effIcon->m_nType      = Constants::EffectTrueType::Icon;
        effIcon->m_nSubType   = Constants::EffectSubType::Supernatural;
        effIcon->m_bShowIcon  = true;
        effIcon->m_bExpose    = true;
        effIcon->m_sCustomTag = "NWNX_Object_IconEffect";

        effIcon->m_nParamInteger[0] = nIcon;

        if (fDuration > 0.0)
        {
            effIcon->m_nSubType |= Constants::EffectDurationType::Temporary;
            effIcon->m_fDuration = fDuration;
        }
        else
        {
            effIcon->m_nSubType |= Constants::EffectDurationType::Permanent;
        }

        pObject->ApplyEffect(effIcon, false, true);
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
        auto ExportObject = [&](RESTYPE resType) -> void
        {
            std::vector<uint8_t> serialized = Utils::SerializeGameObject(pGameObject, true);

            if (!serialized.empty())
            {
                auto file = CExoFile(("NWNX:" + fileName).c_str(), resType, "wb");

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

NWNX_EXPORT ArgumentStack SetFacing(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        const auto degrees = args.extract<float>();
        Utils::SetOrientation(pObject, degrees);
    }

    return {};
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
        static auto CanCarryUUID = reinterpret_cast<bool(*)(int32_t)>(
                Platform::GetRelocatedAddress(API::Functions::_ZN8CNWSUUID12CanCarryUUIDEi));

        if (CanCarryUUID(pGameObject->m_nObjectType))
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
            return pObject->DoSpellImmunity(pVersus);
    }

    return -1;
}

NWNX_EXPORT ArgumentStack DoSpellLevelAbsorption(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        if(auto *pVersus = Utils::PopObject(args))
            return pObject->DoSpellLevelAbsorption(pVersus);
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

