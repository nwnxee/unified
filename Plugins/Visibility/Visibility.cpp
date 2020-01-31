#include "Visibility.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "Services/Events/Events.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Visibility::Visibility* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Visibility",
        "Allows the visibility of objects to be overridden globally or per player",
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
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetVisibilityOverride);
    REGISTER(SetVisibilityOverride);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<API::Functions::_ZN11CNWSMessage17TestObjectVisibleEP10CNWSObjectS1_>(&Visibility::TestObjectVisibleHook);
    m_TestObjectVisibilityHook = GetServices()->m_hooks->FindHookByAddress(API::Functions::_ZN11CNWSMessage17TestObjectVisibleEP10CNWSObjectS1_);
}

Visibility::~Visibility()
{
}

int32_t Visibility::TestObjectVisibleHook(
    CNWSMessage *pThis,
    CNWSObject *pAreaObject,
    CNWSObject *pPlayerGameObject)
{
    if (pAreaObject->m_idSelf == pPlayerGameObject->m_idSelf)
    {
        return g_plugin->m_TestObjectVisibilityHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
    }

    bool bInvisible = false;
    int32_t personalOverride = GetPersonalOverride(pPlayerGameObject->m_idSelf, pAreaObject->m_idSelf);
    int32_t globalOverride = GetGlobalOverride(pAreaObject->m_idSelf);

    if (personalOverride != -1)
    {
        bInvisible = !!personalOverride;
    }
    else if (globalOverride != -1)
    {
        bInvisible = (globalOverride == 2) ? !Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->m_bIsDM : !!globalOverride;
    }

    return bInvisible ? false : g_plugin->m_TestObjectVisibilityHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
}

int32_t Visibility::GetGlobalOverride(Types::ObjectID targetId)
{
    int32_t retVal = -1;

    if (auto globalOverride = g_plugin->GetServices()->m_perObjectStorage->Get<int>(targetId, "GLOBAL_VISIBILITY_OVERRIDE"))
    {
        retVal = *globalOverride;
    }

    return retVal;
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
    const auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto targetId = Services::Events::ExtractArgument<Types::ObjectID>(args);

    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalOverride(targetId) :
                                                               GetPersonalOverride(playerId, targetId);

    return Services::Events::Arguments(retVal);
}

ArgumentStack Visibility::SetVisibilityOverride(ArgumentStack&& args)
{
    auto playerId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto targetId = Services::Events::ExtractArgument<Types::ObjectID>(args);
    const auto override = Services::Events::ExtractArgument<int32_t>(args);
    std::string varName = Utils::ObjectIDToString(targetId);

    if (playerId == Constants::OBJECT_INVALID)
    {
        varName = "GLOBAL_VISIBILITY_OVERRIDE";
        playerId = targetId;
    }

    if (override == -1)
    {
        g_plugin->GetServices()->m_perObjectStorage->Remove(playerId, varName);
    }
    else
    {
        g_plugin->GetServices()->m_perObjectStorage->Set(playerId, varName, override);
    }

    return Services::Events::Arguments();
}

}
