#include "Object.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSScriptVar.hpp"
#include "API/CNWSScriptVarTable.hpp"
#include "API/CExoArrayListTemplatedCNWSScriptVar.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSTrigger.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CNWSAreaOfEffectObject.hpp"
#include "API/CNWSDoor.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "Services/Events/Events.hpp"
#include "ViewPtr.hpp"
#include "Serialize.hpp"

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
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Object::func, this, std::placeholders::_1))

    REGISTER(GetLocalVariableCount);
    REGISTER(GetLocalVariable);
    REGISTER(StringToObject);
    REGISTER(SetPosition);
    REGISTER(SetCurrentHitPoints);
    REGISTER(SetMaxHitPoints);
    REGISTER(GetPortrait);
    REGISTER(SetPortrait);
    REGISTER(Serialize);
    REGISTER(Deserialize);
    REGISTER(GetDialogResref);
    REGISTER(SetAppearance);
    REGISTER(GetAppearance);   

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
    return static_cast<CNWSObject*>(pGameObject);
}

static inline CNWSScriptVarTable *_getScriptVarTable(CGameObject *pObject)
{
    ASSERT(pObject);
    switch (pObject->m_nObjectType)
    {
        case Constants::OBJECT_TYPE_AREA:
            return &static_cast<CNWSArea*>(pObject)->m_ScriptVars;
        case Constants::OBJECT_TYPE_MODULE:
            return &static_cast<CNWSModule*>(pObject)->m_ScriptVars;
        default:
            return &static_cast<CNWSObject*>(pObject)->m_ScriptVars;
    }
}

ArgumentStack Object::GetLocalVariableCount(ArgumentStack&& args)
{
    ArgumentStack stack;
    int retval = -1;
    if (auto *pObject = object(args))
    {
        auto *pVarTable = _getScriptVarTable(pObject);
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
    if (auto *pObject = object(args))
    {
        const auto index = Services::Events::ExtractArgument<int32_t>(args);
        auto *pVarTable = _getScriptVarTable(pObject);
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

        pObject->SetPosition(pos, 1 /*bUpdateInAreaArray*/);
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

ArgumentStack Object::GetPortrait(ArgumentStack&& args)
{
    ArgumentStack stack;
    std::string retval = "";
    if (auto *pObject = object(args))
    {
        if (pObject->m_nObjectType == Constants::OBJECT_TYPE_CREATURE)
            retval = static_cast<CNWSCreature*>(pObject)->GetPortrait().GetResRefStr();
        else
            retval = pObject->GetPortrait().GetResRefStr();
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}

ArgumentStack Object::SetPortrait(ArgumentStack&&)
{
    ArgumentStack stack;

    LOG_ERROR("Cannot do SetPortrait: CResRef copy constructor results in a trap");
    LOG_NOTICE("SetPortrait-TODO: Update portrait directly");

    /*
    if (auto *pObject = object(args))
    {

        const auto portrait = Services::Events::ExtractArgument<std::string>(args);

        CResRef resref = CResRef(portrait.c_str());
        if (pObject->m_nObjectType == Constants::OBJECT_TYPE_CREATURE)
            static_cast<CNWSCreature*>(pObject)->SetPortrait(resref);
        else
            pObject->SetPortrait(resref);
    }
    */
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
        if (pObject->m_nObjectType == Constants::OBJECT_TYPE_CREATURE)
            retval = static_cast<CNWSCreature*>(pObject)->GetDialogResref().GetResRefStr();
        else if(pObject->m_nObjectType == Constants::OBJECT_TYPE_PLACEABLE)
            retval = static_cast<CNWSPlaceable*>(pObject)->GetDialogResref().GetResRefStr();
        else if(pObject->m_nObjectType == Constants::OBJECT_TYPE_DOOR)
            retval = static_cast<CNWSDoor*>(pObject)->GetDialogResref().GetResRefStr();
        else
            retval = pObject->GetDialogResref().GetResRefStr();
    }
    Services::Events::InsertArgument(stack, retval);
    return stack;
}


ArgumentStack Object::GetAppearance(ArgumentStack&& args)
{	  
    ArgumentStack stack;
    int32_t retval = 0;
    if (auto *pObject = object(args))
    {	       
        if(pObject->m_nObjectType == Constants::OBJECT_TYPE_PLACEABLE)
	{
	   retval = static_cast<CNWSPlaceable*>(pObject)->m_nAppearance;
	}
    }
   
   Services::Events::InsertArgument(stack, retval);
   return stack;
}     
   
ArgumentStack Object::SetAppearance(ArgumentStack&& args)
{	
   ArgumentStack stack;
   if (auto *pObject = object(args))
   {
       const auto app = Services::Events::ExtractArgument<int32_t>(args);  ASSERT(app <= 65535);
       if(pObject->m_nObjectType == Constants::OBJECT_TYPE_PLACEABLE)
       {		  
           static_cast<CNWSPlaceable*>(pObject)->m_nAppearance=app;
       }
	     
   }	
   return stack;
}
   
}
