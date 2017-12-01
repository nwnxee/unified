#include "Events/DMActionEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Version.hpp"
#include "Events.hpp"
#include "Services/Patching/Patching.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Platform;

DMActionEvents::DMActionEvents(NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patching)
{
    patching->PatchWithCall(0x0818C825, 0x0818C82A - 0x0818C825, &SetExperiencePatch); NWNX_EXPECT_VERSION(8109);
    patching->PatchWithCall(0x0818C8E2, 0x0818C8E7 - 0x0818C8E2, &AddGoldPatch); NWNX_EXPECT_VERSION(8109);
}

void DMActionEvents::SetExperiencePatch(CNWSCreatureStats* stats, uint32_t exp, int32_t doLevel)
{
    const uint32_t oldExp = stats->m_nExperience;
    stats->SetExperience(exp, doLevel);
    Events::PushEventData("OLD_EXP", std::to_string(oldExp));
    Events::PushEventData("NEW_EXP", std::to_string(exp));
    Events::SignalEvent("NWNX_ON_DM_SET_EXP", stats->m_pBaseCreature->m_idSelf);
}

void DMActionEvents::AddGoldPatch(CNWSCreature* target, int32_t gold, int32_t display)
{
    target->AddGold(gold, display);
    Events::PushEventData("GOLD", std::to_string(gold));
    Events::SignalEvent("NWNX_ON_DM_GIVE_GOLD", target->m_idSelf);
}

}
