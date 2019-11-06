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
#include "ViewPtr.hpp"
#include "Serialize.hpp"
#include "Utils.hpp"

#include <cstring>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Object::Object> g_plugin;

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
    return pGameObject->AsNWSObject();
}

ArgumentStack Object::GetLocalVariableCount(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::GetLocalVariable(ArgumentStack&& args)
{
    ArgumentStack stack;
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
    Services::Events::InsertArgument(stack, type);
    Services::Events::InsertArgument(stack, key);
    return stack;
}

// NOTE: StringToObject does not receive an object argument.
ArgumentStack Object::StringToObject(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto id = Services::Events::ExtractArgument<std::string>(args);
    Types::ObjectID retval = static_cast<Types::ObjectID>(stoul(id, nullptr, 16));

    if (!Globals::AppManager()->m_pServerExoApp->GetGameObject(retval))
        retval = Constants::OBJECT_INVALID;

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::SetPosition(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pObject = object(args))
    {
        Vector pos;
        pos.z = Services::Events::ExtractArgument<float>(args);
        pos.y = Services::Events::ExtractArgument<float>(args);
        pos.x = Services::Events::ExtractArgument<float>(args);

        pObject->SetPosition(pos, true /*bUpdateInAreaArray*/);
    }
    return stack;
}

ArgumentStack Object::SetCurrentHitPoints(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pObject = object(args))
    {
        const auto hp = Services::Events::ExtractArgument<int32_t>(args);
        pObject->m_nCurrentHitPoints = hp;
    }
    return stack;
}

ArgumentStack Object::SetMaxHitPoints(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pObject = object(args))
    {
        const auto hp = Services::Events::ExtractArgument<int32_t>(args);
        pObject->m_nBaseHitPoints = hp;
    }
    return stack;
}

ArgumentStack Object::Serialize(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retval = "";
    if (CGameObject *pObject = static_cast<CGameObject*>(object(args)))
    {
        retval = SerializeGameObjectB64(pObject);
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

// NOTE: Deserialize does not receive an object argument.
ArgumentStack Object::Deserialize(ArgumentStack&& args)
{
    ArgumentStack stack;
    Types::ObjectID retval = Constants::OBJECT_INVALID;

    const auto serialized = Services::Events::ExtractArgument<std::string>(args);

    if (CGameObject *pObject = DeserializeGameObjectB64(serialized))
    {
        retval = static_cast<Types::ObjectID>(pObject->m_idSelf);
        ASSERT(Globals::AppManager()->m_pServerExoApp->GetGameObject(retval));
    }

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::GetDialogResref(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retval = "";
    if (auto *pObject = object(args))
    {
        if (auto *pCreature = pObject->AsNWSCreature())
            retval = pCreature->GetDialogResref().GetResRefStr();
        else if (auto *pPlaceable = pObject->AsNWSPlaceable())
            retval = pPlaceable->GetDialogResref().GetResRefStr();
        else if (auto *pDoor = pObject->AsNWSDoor())
            retval = pDoor->GetDialogResref().GetResRefStr();
        else
            retval = pObject->GetDialogResref().GetResRefStr();
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::SetDialogResref(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pObject = object(args))
    {
        const auto dialog = Services::Events::ExtractArgument<std::string>(args);
        CResRef resref = CResRef(dialog.c_str());

        if (auto *pCreature = pObject->AsNWSCreature())
            pCreature->m_pStats->m_cDialog = resref;
        else if (auto *pPlaceable = pObject->AsNWSPlaceable())
            pPlaceable->m_cDialog = resref;
        else if (auto *pDoor = pObject->AsNWSDoor())
            pDoor->m_cDialog = resref;
    }

    return stack;
}

ArgumentStack Object::GetAppearance(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = 0;
    if (auto *pPlaceable = object(args)->AsNWSPlaceable())
    {
        retval = pPlaceable->m_nAppearance;
    }

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::SetAppearance(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlaceable = object(args)->AsNWSPlaceable())
    {
        const auto app = Services::Events::ExtractArgument<int32_t>(args);
          ASSERT_OR_THROW(app <= 65535);

        pPlaceable->m_nAppearance=app;
    }
    return stack;
}

ArgumentStack Object::GetHasVisualEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal=0;

    if (auto *pObject = object(args))
    {
        const auto nVfx = Services::Events::ExtractArgument<int32_t>(args);

        auto& vfx = pObject->m_lstLoopingVisualEffects;
        for (int k = 0; k< vfx.num; k++)
        {
            if (vfx.element[k] && vfx.element[k]->m_nId == nVfx)
            {
                retVal=1;
                break;
            }
        }
    }

    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Object::CheckFit(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;

    if (auto *pObject = object(args))
    {
        CItemRepository *pRepo;

        if (auto *pCreature = pObject->AsNWSCreature())
            pRepo = pCreature->m_pcItemRepository;
        else if (auto *pPlaceable = pObject->AsNWSPlaceable())
            pRepo = pPlaceable->m_pcItemRepository;
        else if (auto *pItem = pObject->AsNWSItem())
            pRepo = pItem->m_pItemRepository;
        else
        {
            Services::Events::InsertArgument(stack, retVal);
            return stack;
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
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Object::GetDamageImmunity(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;

    if (auto *pObject = object(args))
    {
        const int32_t damageFlags = Services::Events::ExtractArgument<int32_t>(args);
        ASSERT_OR_THROW(damageFlags >= 0);
        retVal = pObject->GetDamageImmunityByFlags(damageFlags);
    }
    Services::Events::InsertArgument(stack, retVal);
    return stack;
}

ArgumentStack Object::AddToArea(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
}

ArgumentStack Object::GetPlaceableIsStatic(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retval = -1;
    if (auto *pPlaceable = object(args)->AsNWSPlaceable())
    {
        retval = pPlaceable->m_bStaticObject;
    }

    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::SetPlaceableIsStatic(ArgumentStack&& args)
{
    ArgumentStack stack;
    if (auto *pPlaceable = object(args)->AsNWSPlaceable())
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
    return stack;
}

ArgumentStack Object::GetAutoRemoveKey(ArgumentStack&& args)
{
    ArgumentStack stack;
    int32_t retVal = -1;

    if (auto *pObject = object(args))
    {
        switch (pObject->m_nObjectType)
        {
            case Constants::ObjectType::Door:
                retVal = pObject->AsNWSDoor()->m_bAutoRemoveKey;
                break;

            case Constants::ObjectType::Placeable:
                retVal = pObject->AsNWSPlaceable()->m_bAutoRemoveKey;
                break;

            default:
                LOG_WARNING("NWNX_Object_GetAutoRemoveKey() called on non door/placeable object.");
                break;
        }
    }

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Object::SetAutoRemoveKey(ArgumentStack&& args)
{
    ArgumentStack stack;

    if (auto *pObject = object(args))
    {
        const auto bRemoveKey = !!Services::Events::ExtractArgument<int32_t>(args);

        switch (pObject->m_nObjectType)
        {
            case Constants::ObjectType::Door:
                pObject->AsNWSDoor()->m_bAutoRemoveKey = bRemoveKey;
                break;

            case Constants::ObjectType::Placeable:
                pObject->AsNWSPlaceable()->m_bAutoRemoveKey = bRemoveKey;
                break;

            default:
                LOG_WARNING("NWNX_Object_SetAutoRemoveKey() called on non door/placeable object.");
                break;
        }
    }

    return stack;
}

ArgumentStack Object::GetTriggerGeometry(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retVal;

    if (auto *pObject = object(args))
    {
        if (auto *pTrigger = pObject->AsNWSTrigger())
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

    Services::Events::InsertArgument(stack, retVal);

    return stack;
}

ArgumentStack Object::SetTriggerGeometry(ArgumentStack&& args)
{
    ArgumentStack stack;

    if (auto *pObject = object(args))
    {
        const auto sGeometry = Services::Events::ExtractArgument<std::string>(args);

        if (auto *pTrigger = pObject->AsNWSTrigger())
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

    return stack;
}

ArgumentStack Object::RemoveIconEffect(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
}

ArgumentStack Object::AddIconEffect(ArgumentStack&& args)
{
    ArgumentStack stack;

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

    return stack;
}

ArgumentStack Object::Export(ArgumentStack&& args)
{
    ArgumentStack stack;

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
            case Constants::ObjectType::Creature:   ExportObject(2027); break;
            case Constants::ObjectType::Item:       ExportObject(2025); break;
            case Constants::ObjectType::Placeable:  ExportObject(2044); break;
            case Constants::ObjectType::Waypoint:   ExportObject(2058); break;
            case Constants::ObjectType::Store:      ExportObject(2051); break;
            case Constants::ObjectType::Door:       ExportObject(2042); break;
            case Constants::ObjectType::Trigger:    ExportObject(2032); break;
            default:
                LOG_ERROR("Invalid object type for ExportObject");
                break;
        }
    }

    return stack;
}

}
