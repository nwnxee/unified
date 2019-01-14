#include "Visibility.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSObject.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "ViewPtr.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Visibility::Visibility> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Visibility",
        "Allows the visibility of objects to be overriden globally or per player",
        "Daz",
        "daztek@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Visibility::Visibility(params);
    return g_plugin;
}


namespace Visibility {

Visibility::Visibility(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Visibility::func, this, std::placeholders::_1))

    REGISTER(GetVisibilityOverride);
    REGISTER(SetVisibilityOverride);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CNWSMessage__TestObjectVisible>(&Visibility::TestObjectVisibleHook);
    m_TestObjectVisibilityHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::CNWSMessage__TestObjectVisible);   
}

Visibility::~Visibility()
{
}

int32_t Visibility::TestObjectVisibleHook(
    CNWSMessage *pThis,
    CNWSObject *pAreaObject,
    CNWSObject *pPlayerGameObject)
{
    auto personalOverride = GetPersonalOverride(pPlayerGameObject->m_idSelf, pAreaObject->m_idSelf);
    bool bInvisible = (personalOverride == -1) ? GetGlobalOverride(pAreaObject->m_idSelf) : personalOverride;
    
    return bInvisible ? false : g_plugin->m_TestObjectVisibilityHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
}

bool Visibility::GetGlobalOverride(Types::ObjectID targetId)
{
    return g_plugin->m_GlobalVisibilityOverrideSet.find(targetId) != g_plugin->m_GlobalVisibilityOverrideSet.end();
}

int32_t Visibility::GetPersonalOverride(Types::ObjectID playerId, Types::ObjectID targetId) 
{
    int32_t retVal = -1;
 
    if (auto personalOverride = g_plugin->GetServices()->m_perObjectStorage->Get<int>(playerId, Utils::ObjectIDToString(targetId)))
    {
        retVal = !!*personalOverride;
    }
    
    return retVal;    
}

ArgumentStack Visibility::GetVisibilityOverride(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto targetId = Services::Events::ExtractArgument<Types::ObjectID>(args);
  
    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalOverride(targetId) : 
                                                               GetPersonalOverride(playerId, targetId);

    Services::Events::InsertArgument(stack, retVal);
    
    return stack;
}

ArgumentStack Visibility::SetVisibilityOverride(ArgumentStack&& args)
{
    ArgumentStack stack;

    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto targetId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto override = Services::Events::ExtractArgument<int32_t>(args);

    if (playerId == Constants::OBJECT_INVALID)
    {      
        if (!!override)
        {
            m_GlobalVisibilityOverrideSet.insert(targetId);    
        }
        else
        {
            auto index = m_GlobalVisibilityOverrideSet.find(targetId);
            if (index != m_GlobalVisibilityOverrideSet.end())
            {
                m_GlobalVisibilityOverrideSet.erase(index);
            }
        }
    }
    else
    {
        if (override == -1)
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(playerId, Utils::ObjectIDToString(targetId));
        }
        else
        {            
            g_plugin->GetServices()->m_perObjectStorage->Set(playerId, Utils::ObjectIDToString(targetId), !!override);
        }
    }       
        
    return stack;
}

}
