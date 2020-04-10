#include "Object.hpp"

#include "API/CAppManager.hpp"
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
#include "API/CNWRules.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CItemRepository.hpp"
#include "API/CExoFile.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CLoopingVisualEffect.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Serialize.hpp"
#include "Utils.hpp"

#include <cstring>
#include <math.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

static Object::Object* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Object",
        "Functions exposing additional object properties",
        "various / sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Object::Object(params);
    return g_plugin;
}


namespace Object {

Object::Object(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetLocalVariableCount);
    REGISTER(GetLocalVariable);
    REGISTER(StringToObject);
    REGISTER(SetPosition);
    REGISTER(SetCurrentHitPoints);
    REGISTER(SetMaxHitPoints);
    REGISTER(Serialize);
    REGISTER(Deserialize);
    REGISTER(GetDialogResref);
    REGISTER(SetDialogResref);
    REGISTER(SetAppearance);
    REGISTER(GetAppearance);
    REGISTER(GetHasVisualEffect);
    REGISTER(CheckFit);
    REGISTER(GetDamageImmunity);
    REGISTER(AddToArea);
    REGISTER(GetPlaceableIsStatic);
    REGISTER(SetPlaceableIsStatic);
    REGISTER(GetAutoRemoveKey);
    REGISTER(SetAutoRemoveKey);
    REGISTER(GetTriggerGeometry);
    REGISTER(SetTriggerGeometry);
    REGISTER(RemoveIconEffect);
    REGISTER(AddIconEffect);
    REGISTER(Export);
    REGISTER(GetInt);
    REGISTER(SetInt);
    REGISTER(DeleteInt);
    REGISTER(GetString);
    REGISTER(SetString);
    REGISTER(DeleteString);
    REGISTER(GetFloat);
    REGISTER(SetFloat);
    REGISTER(DeleteFloat);
    REGISTER(DeleteVarRegex);
    REGISTER(GetPositionIsInTrigger);
    REGISTER(GetInternalObjectType);
    REGISTER(AcquireItem);
    REGISTER(SetFacing);

#undef REGISTER
}

Object::~Object()
{
}

CNWSObject *Object::object(ArgumentStack& args)
{
    const auto objectId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (objectId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Object function called on OBJECT_INVALID");
        return nullptr;
    }

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    return Utils::AsNWSObject(pGameObject);
}

ArgumentStack Object::GetLocalVariableCount(ArgumentStack&& args)
{
    int retval = -1;
    const auto objectId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (objectId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Object function called on OBJECT_INVALID");
    }
    else if (auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId))
    {
        auto *pVarTable = Utils::GetScriptVarTable(pGameObject);
        retval = pVarTable->m_lVarList.num;
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Object::GetLocalVariable(ArgumentStack&& args)
{
    std::string key = "";
    int type = -1;
    const auto objectId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (objectId == Constants::OBJECT_INVALID)
    {
        LOG_NOTICE("NWNX_Object function called on OBJECT_INVALID");
    }
    else if (auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        auto *pVarTable = Utils::GetScriptVarTable(pGameObject);
        if (index < pVarTable->m_lVarList.num)
        {
            type = static_cast<int>(pVarTable->m_lVarList.element[index].m_nType);
            key  = pVarTable->m_lVarList.element[index].m_sName.CStr();
        }
    }
    return Services::Events::Arguments(type, key);
}

// NOTE: StringToObject does not receive an object argument.
ArgumentStack Object::StringToObject(ArgumentStack&& args)
{
    Types::ObjectID retVal;

    const auto id = Services::Events::ExtractArgument<std::string>(args);

    if (id.empty())
        retVal = Constants::OBJECT_INVALID;
    else
    {
        retVal = static_cast<Types::ObjectID>(stoul(id, nullptr, 16));

        if (!Globals::AppManager()->m_pServerExoApp->GetGameObject(retVal))
            retVal = Constants::OBJECT_INVALID;
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetPosition(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        Vector pos;
        pos.z = Services::Events::ExtractArgument<float>(args);
        pos.y = Services::Events::ExtractArgument<float>(args);
        pos.x = Services::Events::ExtractArgument<float>(args);

        pObject->SetPosition(pos, true /*bUpdateInAreaArray*/);
    }
    return Services::Events::Arguments();
}

ArgumentStack Object::SetCurrentHitPoints(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto hp = Services::Events::ExtractArgument<int32_t>(args);
        pObject->m_nCurrentHitPoints = hp;
    }
    return Services::Events::Arguments();
}

ArgumentStack Object::SetMaxHitPoints(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto hp = Services::Events::ExtractArgument<int32_t>(args);
        pObject->m_nBaseHitPoints = hp;
    }
    return Services::Events::Arguments();
}

ArgumentStack Object::Serialize(ArgumentStack&& args)
{
    std::string retval = "";
    if (CGameObject *pObject = static_cast<CGameObject*>(object(args)))
    {
        retval = SerializeGameObjectB64(pObject);
    }
    return Services::Events::Arguments(retval);
}

// NOTE: Deserialize does not receive an object argument.
ArgumentStack Object::Deserialize(ArgumentStack&& args)
{
    Types::ObjectID retval = Constants::OBJECT_INVALID;

    const auto serialized = Services::Events::ExtractArgument<std::string>(args);

    if (CGameObject *pObject = DeserializeGameObjectB64(serialized))
    {
        retval = static_cast<Types::ObjectID>(pObject->m_idSelf);
        ASSERT(Globals::AppManager()->m_pServerExoApp->GetGameObject(retval));
    }

    return Services::Events::Arguments(retval);
}

ArgumentStack Object::GetDialogResref(ArgumentStack&& args)
{
    std::string retval = "";
    if (auto *pObject = object(args))
    {
        if (auto *pCreature = Utils::AsNWSCreature(pObject))
            retval = pCreature->GetDialogResref().GetResRefStr();
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            retval = pPlaceable->GetDialogResref().GetResRefStr();
        else if (auto *pDoor = Utils::AsNWSDoor(pObject))
            retval = pDoor->GetDialogResref().GetResRefStr();
        else
            retval = pObject->GetDialogResref().GetResRefStr();
    }
    return Services::Events::Arguments(retval);
}

ArgumentStack Object::SetDialogResref(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto dialog = Services::Events::ExtractArgument<std::string>(args);
        CResRef resref = CResRef(dialog.c_str());

        if (auto *pCreature = Utils::AsNWSCreature(pObject))
            pCreature->m_pStats->m_cDialog = resref;
        else if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            pPlaceable->m_cDialog = resref;
        else if (auto *pDoor = Utils::AsNWSDoor(pObject))
            pDoor->m_cDialog = resref;
    }

    return Services::Events::Arguments();
}

ArgumentStack Object::GetAppearance(ArgumentStack&& args)
{
    int32_t retval = 0;
    if (auto *pPlaceable = Utils::AsNWSPlaceable(object(args)))
    {
        retval = pPlaceable->m_nAppearance;
    }

    return Services::Events::Arguments(retval);
}

ArgumentStack Object::SetAppearance(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::AsNWSPlaceable(object(args)))
    {
        const auto app = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(app <= 65535);

        pPlaceable->m_nAppearance=app;
    }
    return Services::Events::Arguments();
}

ArgumentStack Object::GetHasVisualEffect(ArgumentStack&& args)
{
    int32_t retVal = 0;

    if (auto *pObject = object(args))
    {
        const auto nVfx = Services::Events::ExtractArgument<int32_t>(args);

        auto& vfx = pObject->m_lstLoopingVisualEffects;
        for (int k = 0; k < vfx.num; k++)
        {
            if (vfx.element[k] && vfx.element[k]->m_nId == nVfx)
            {
                retVal = 1;
                break;
            }
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::CheckFit(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pObject = object(args))
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
            return Services::Events::Arguments(retVal);
        }
        retVal = 0;
        const auto baseitem = Services::Events::ExtractArgument<int32_t>(args);
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
                    retVal = 1;
                    break;
                }
            }
            if (retVal)
                break;
        }
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::GetDamageImmunity(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pObject = object(args))
    {
        const int32_t damageFlags = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(damageFlags >= 0);
        retVal = pObject->GetDamageImmunityByFlags(damageFlags);
    }
    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::AddToArea(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto oidArea = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidArea != Constants::OBJECT_INVALID);
        const auto posX = Services::Events::ExtractArgument<float>(args);
        const auto posY = Services::Events::ExtractArgument<float>(args);
        const auto posZ = Services::Events::ExtractArgument<float>(args);

        CNWSArea *pArea = API::Globals::AppManager()->m_pServerExoApp->GetAreaByGameObjectID(oidArea);

        if (pArea)
        {
            if (!Utils::AddToArea(pObject, pArea, posX, posY, posZ))
                LOG_WARNING("Failed to add object %x to area %x (%f,%f,%f)", pObject->m_idSelf, oidArea, posX, posY, posZ);
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Object::GetPlaceableIsStatic(ArgumentStack&& args)
{
    int32_t retval = -1;
    if (auto *pPlaceable = Utils::AsNWSPlaceable(object(args)))
    {
        retval = pPlaceable->m_bStaticObject;
    }

    return Services::Events::Arguments(retval);
}

ArgumentStack Object::SetPlaceableIsStatic(ArgumentStack&& args)
{
    if (auto *pPlaceable = Utils::AsNWSPlaceable(object(args)))
    {
        const auto isStatic = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(isStatic >= 0);
        ASSERT_OR_THROW(isStatic <= 1);

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
    return Services::Events::Arguments();
}

ArgumentStack Object::GetAutoRemoveKey(ArgumentStack&& args)
{
    int32_t retVal = -1;

    if (auto *pObject = object(args))
    {
        switch (pObject->m_nObjectType)
        {
            case Constants::ObjectType::Door:
                retVal = Utils::AsNWSDoor(pObject)->m_bAutoRemoveKey;
                break;

            case Constants::ObjectType::Placeable:
                retVal = Utils::AsNWSPlaceable(pObject)->m_bAutoRemoveKey;
                break;

            default:
                LOG_WARNING("NWNX_Object_GetAutoRemoveKey() called on non door/placeable object.");
                break;
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetAutoRemoveKey(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto bRemoveKey = !!Services::Events::ExtractArgument<int32_t>(args);

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

    return Services::Events::Arguments();
}

ArgumentStack Object::GetTriggerGeometry(ArgumentStack&& args)
{
    std::string retVal;

    if (auto *pObject = object(args))
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

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetTriggerGeometry(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto sGeometry = Services::Events::ExtractArgument<std::string>(args);

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

    return Services::Events::Arguments();
}

ArgumentStack Object::RemoveIconEffect(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto nIcon = Services::Events::ExtractArgument<int32_t>(args);

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

    return Services::Events::Arguments();
}

ArgumentStack Object::AddIconEffect(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto nIcon = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(nIcon > 0);
        const auto fDuration = Services::Events::ExtractArgument<float>(args);

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

        effIcon->SetNumIntegers(1);
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

    return Services::Events::Arguments();
}

ArgumentStack Object::Export(ArgumentStack&& args)
{
    const auto fileName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!fileName.empty());
      ASSERT_OR_THROW(fileName.size() <= 16);
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);

    if (auto *pGameObject = Utils::GetGameObject(oidObject))
    {
        auto ExportObject = [&](RESTYPE resType) -> void
        {
            std::vector<uint8_t> serialized = SerializeGameObject(pGameObject, true);

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
            case Constants::ObjectType::Store:      ExportObject(Constants::ResRefType::UTS); break;
            case Constants::ObjectType::Door:       ExportObject(Constants::ResRefType::UTD); break;
            case Constants::ObjectType::Trigger:    ExportObject(Constants::ResRefType::UTT); break;
            default:
                LOG_ERROR("Invalid object type for ExportObject");
                break;
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Object::GetInt(ArgumentStack&& args)
{
    int32_t retVal = 0;

    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());

    if (auto value = g_plugin->GetServices()->m_perObjectStorage->Get<int32_t>(oidObject, "PERINT!" + varName))
        retVal = *value;

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetInt(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());
    const auto value = Services::Events::ExtractArgument<int32_t>(args);
    bool persist = Services::Events::ExtractArgument<int32_t>(args) != 0;

    g_plugin->GetServices()->m_perObjectStorage->Set(oidObject, "PERINT!" + varName, value, persist);

    return Services::Events::Arguments();
}

ArgumentStack Object::DeleteInt(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());

    g_plugin->GetServices()->m_perObjectStorage->Remove(oidObject, "PERINT!" + varName);

    return Services::Events::Arguments();
}

ArgumentStack Object::GetString(ArgumentStack&& args)
{
    std::string retVal;

    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());

    if (auto value = g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(oidObject, "PERSTR!" + varName))
        retVal = *value;

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetString(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());
    const auto value = Services::Events::ExtractArgument<std::string>(args);
    bool persist = Services::Events::ExtractArgument<int32_t>(args) != 0;

    g_plugin->GetServices()->m_perObjectStorage->Set(oidObject, "PERSTR!" + varName, value, persist);

    return Services::Events::Arguments();
}

ArgumentStack Object::DeleteString(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());

    g_plugin->GetServices()->m_perObjectStorage->Remove(oidObject, "PERSTR!" + varName);

    return Services::Events::Arguments();
}

ArgumentStack Object::GetFloat(ArgumentStack&& args)
{
    float retVal = 0.0f;

    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());

    if (auto value = g_plugin->GetServices()->m_perObjectStorage->Get<float>(oidObject, "PERFLT!" + varName))
        retVal = *value;

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetFloat(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());
    const auto value = Services::Events::ExtractArgument<float>(args);
    bool persist = Services::Events::ExtractArgument<int32_t>(args) != 0;

    g_plugin->GetServices()->m_perObjectStorage->Set(oidObject, "PERFLT!" + varName, value, persist);

    return Services::Events::Arguments();
}


ArgumentStack Object::DeleteFloat(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto varName = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!varName.empty());

    g_plugin->GetServices()->m_perObjectStorage->Remove(oidObject, "PERFLT!" + varName);

    return Services::Events::Arguments();
}

ArgumentStack Object::DeleteVarRegex(ArgumentStack&& args)
{
    const auto oidObject = Services::Events::ExtractArgument<Types::ObjectID >(args);
      ASSERT_OR_THROW(oidObject != Constants::OBJECT_INVALID);
    const auto regex = Services::Events::ExtractArgument<std::string>(args);
      ASSERT_OR_THROW(!regex.empty());

    g_plugin->GetServices()->m_perObjectStorage->RemoveRegex(oidObject, "((?:PERINT!)|(?:PERSTR!)|(?:PERFLT!))" + regex);

    return Services::Events::Arguments();
}

ArgumentStack Object::GetPositionIsInTrigger(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pTrigger = Utils::AsNWSTrigger(object(args)))
    {
        const auto fX = Services::Events::ExtractArgument<float>(args);
        const auto fY = Services::Events::ExtractArgument<float>(args);
        const auto fZ = Services::Events::ExtractArgument<float>(args);

        Vector vPosition = {fX, fY, fZ};
        retVal = pTrigger->InTrigger(vPosition);
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::GetInternalObjectType(ArgumentStack&& args)
{
    const auto objectId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (auto* go = Utils::GetGameObject(objectId))
    {
        return Services::Events::Arguments(go->m_nObjectType);
    }

    return Services::Events::Arguments(-1);
}

ArgumentStack Object::AcquireItem(ArgumentStack&& args)
{
    int32_t retVal = false;

    if (auto *pObject = object(args))
    {
        const auto oidItem = Services::Events::ExtractArgument<Types::ObjectID>(args);
          ASSERT_OR_THROW(oidItem != Constants::OBJECT_INVALID);

        if (auto *pItem = API::Globals::AppManager()->m_pServerExoApp->GetItemByGameObjectID(oidItem))
        {
            retVal = Utils::AcquireItem(pItem, pObject);
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Object::SetFacing(ArgumentStack&& args)
{
    if (auto *pObject = object(args))
    {
        const auto degrees = Services::Events::ExtractArgument<float>(args);

        float radians = degrees * (M_PI / 180);
        auto vOrientation = Vector{cos(radians), sin(radians), 0.0f};

        if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            pPlaceable->SetOrientation(vOrientation);
        else
            pObject->SetOrientation(vOrientation);
    }

    return Services::Events::Arguments();
}

}
