#include "Visibility.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;

static Visibility::Visibility* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Visibility::Visibility(services);
    return g_plugin;
}


namespace Visibility {

static NWNXLib::Hooks::Hook s_TestObjectVisibleHook;

Visibility::Visibility(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetVisibilityOverride);
    REGISTER(SetVisibilityOverride);

#undef REGISTER

    s_TestObjectVisibleHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage17TestObjectVisibleEP10CNWSObjectS1_,
            (void*)&Visibility::TestObjectVisibleHook, Hooks::Order::Late);
}

Visibility::~Visibility()
{
}

int32_t Visibility::TestObjectVisibleHook(CNWSMessage *pThis, CNWSObject *pAreaObject, CNWSObject *pPlayerGameObject)
{
    if (pAreaObject->m_idSelf == pPlayerGameObject->m_idSelf)
    {
        return s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
    }

    int32_t visiblityState;
    int32_t personalOverride = GetPersonalOverride(pPlayerGameObject->m_idSelf, pAreaObject->m_idSelf);
    int32_t globalOverride = GetGlobalOverride(pAreaObject->m_idSelf);
    int32_t visibilityOverride = personalOverride != -1 ? personalOverride : globalOverride != -1 ? globalOverride : -1;

    switch (visibilityOverride)
    {
        case 0: // NWNX_VISIBILITY_VISIBLE
            visiblityState = -1;
            break;

        case 1: // NWNX_VISIBILITY_HIDDEN
            visiblityState = false;
            break;

        case 2: // NWNX_VISIBILITY_DM_ONLY
            visiblityState = Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->GetIsDM() ? -1 : false;
            break;

        case 3: // NWNX_VISIBILITY_ALWAYS_VISIBLE
            visiblityState = true;
            break;

        case 4: // NWNX_VISIBILITY_ALWAYS_VISIBLE_DM_ONLY
            visiblityState = Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->GetIsDM();
            break;

        default:
            visiblityState = -1;
    }

    return visiblityState != -1 ? visiblityState : s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
}

int32_t Visibility::GetGlobalOverride(ObjectID targetId)
{
    int32_t retVal = -1;

    auto target = Utils::GetGameObject(targetId);
    if (auto globalOverride = target->nwnxGet<int>("GLOBAL_VISIBILITY_OVERRIDE"))
    {
        retVal = *globalOverride;
    }

    return retVal;
}

int32_t Visibility::GetPersonalOverride(ObjectID playerId, ObjectID targetId)
{
    int32_t retVal = -1;

    auto player = Utils::GetGameObject(playerId);
    if (auto personalOverride = player->nwnxGet<int>(Utils::ObjectIDToString(targetId)))
    {
        retVal = *personalOverride;
    }

    return retVal;
}

ArgumentStack Visibility::GetVisibilityOverride(ArgumentStack&& args)
{
    const auto playerId = Events::ExtractArgument<ObjectID>(args);
    const auto targetId = Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(targetId != Constants::OBJECT_INVALID);

    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalOverride(targetId) :
                                                               GetPersonalOverride(playerId, targetId);

    return Events::Arguments(retVal);
}

ArgumentStack Visibility::SetVisibilityOverride(ArgumentStack&& args)
{
    auto playerId = Events::ExtractArgument<ObjectID>(args);
    const auto targetId = Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(targetId != Constants::OBJECT_INVALID);
    const auto override = Events::ExtractArgument<int32_t>(args);

    std::string varName = Utils::ObjectIDToString(targetId);

    if (playerId == Constants::OBJECT_INVALID)
    {
        varName = "GLOBAL_VISIBILITY_OVERRIDE";
        playerId = targetId;
    }

    auto player = Utils::GetGameObject(playerId);
    if (override < 0)
        player->nwnxRemove(varName);
    else
        player->nwnxSet(varName, override);

    return Events::Arguments();
}

}
