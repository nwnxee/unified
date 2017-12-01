#include "AOO.hpp"
#include "API/Constants.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Version.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Patching/Patching.hpp"
#include "ViewPtr.hpp"
#include <unordered_map>

using namespace NWNXLib;

static ViewPtr<AOO::AOO> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "AOO",
        "Allows disabling AOOs for certain creatures.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new AOO::AOO(params);
    return g_plugin;
}

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace AOO {

void AOO::PerformAOO(CNWSCreature* target, CNWSCreature* attacker)
{
    const uint8_t flags = g_plugin->m_AOOMap[attacker->m_idSelf];
    const bool targetIsPlayer = target->m_bPlayerCharacter;

    constexpr uint8_t pve = 1 << 0;
    constexpr uint8_t pvp = 1 << 1;

    const bool performAoo = targetIsPlayer ? (flags & pvp) == 0 : (flags & pve) == 0;

    if (performAoo)
    {
        if (attacker->GetAttemptedAttackTarget() == Constants::OBJECT_INVALID)
        {
            attacker->AddAttackActions(target->m_idSelf, false, true, false);
        }

        attacker->m_pcCombatRound->AddAttackOfOpportunity(target->m_idSelf);
        attacker->m_pcCombatRound->m_nAttacksOfOpportunity -= 1;
        attacker->SetBroadcastedAOOTo(true);
    }
}

AOO::AOO(const Plugin::CreateParams& params)
    : Plugin(params)
{
    using namespace NWNXLib::Platform::Assembly;

    // CNWSCreature::BroadcastAttackOfOpportunity ...
    GetServices()->m_patching->PatchWithInstructions(0x081293EE,
        PushRegMemByteInstruction(Register::EBP, 8), // thisPtr (target)
        PushRegMemDwordInstruction(Register::EBP, -0x120), // pAOOCreature (attacker)
        CallRelInstruction(&PerformAOO),
        AddRegImmByteInstruction(Register::ESP, 8),
        JmpRelInstruction(0x0812945B)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_patching->PatchWithInstructions(0x08129819,
        PushRegMemByteInstruction(Register::EBP, 8), // thisPtr (target)
        PushRegMemDwordInstruction(Register::EBP, -0x120), // pAOOCreature (attacker)
        CallRelInstruction(&PerformAOO),
        AddRegImmByteInstruction(Register::ESP, 8),
        JmpRelInstruction(0x081298A8)
    ); NWNX_EXPECT_VERSION(8109);

    GetServices()->m_events->RegisterEvent("SET_AOO_FLAGS", [this](Services::Events::ArgumentStack&& args)
    {
        const auto object = Services::Events::ExtractArgument<Types::ObjectID>(args);
        const auto flags = Services::Events::ExtractArgument<int32_t>(args);
        m_AOOMap[object] = flags;
        return Services::Events::ArgumentStack();
    });
}

AOO::~AOO()
{
}

}
