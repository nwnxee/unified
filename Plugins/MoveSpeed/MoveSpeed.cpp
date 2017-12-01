#include "MoveSpeed.hpp"

#include "API/CAppManager.hpp"
#include "API/Constants.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"
#include "Services/Events/Events.cpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Patching/Patching.hpp"
#include "ViewPtr.hpp"
#include <cstring>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static ViewPtr<MoveSpeed::MoveSpeed> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "MoveSpeed",
        "TODO",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new MoveSpeed::MoveSpeed(params);
    return g_plugin;
}

namespace MoveSpeed {

static Hooking::FunctionHook* g_walkRateHook = nullptr;

MoveSpeed::MoveSpeed(const Plugin::CreateParams& params)
    : Plugin(params)
{
    {
        // First, we patch the function that calculates whether we're in walk or run mode.
        // This patch allows us to simulate walk mode.

        using namespace NWNXLib::Platform::Assembly;

        auto data = ChainOperationsFromAddr(0x0813939E,
            PushRegInstruction(Register::EAX),
            PushRegInstruction(Register::ECX),
            PushRegInstruction(Register::EDX),

            MovRegRegInstruction(Register::EAX, Register::EBP), // Move EBP into EAX.
            SubRegImmByteInstruction(Register::EAX, 16), // Subtract offset for the stack variable we want.
            PushRegInstruction(Register::EAX), // Push EAX, which contains a pointer to the stack var we need.
            PushRegMemByteInstruction(Register::EBP, 8), // Push creature.
            CallRelInstruction(&SimulateDetectInlineHook),
            AddRegImmByteInstruction(Register::ESP, 8), // Clean up!

            PopRegInstruction(Register::EDX),
            PopRegInstruction(Register::ECX),
            PopRegInstruction(Register::EAX)
        ); NWNX_EXPECT_VERSION(8109);

        // Onto our data, now we append the original instructions.
        data.push_back(0x8B); NWNX_EXPECT_VERSION(8109);
        data.push_back(0x7D); NWNX_EXPECT_VERSION(8109);
        data.push_back(0xF0); NWNX_EXPECT_VERSION(8109);
        data.push_back(0x85); NWNX_EXPECT_VERSION(8109);
        data.push_back(0xFF); NWNX_EXPECT_VERSION(8109);

        GetServices()->m_patching->PatchWithTrampoline(0x0813939E, 0x081393A3 - 0x0813939E, data); NWNX_EXPECT_VERSION(8109);
    }

    // Then, we hook the function that returns the walk rate.
    // This allows us to cap the walk rate.
    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__GetWalkRate, float, CNWSCreature*>(&GetWalkRateHook);
    g_walkRateHook = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCreature__GetWalkRate);

    GetServices()->m_events->RegisterEvent("SIMULATE_DETECT_MODE", [this](Events::ArgumentStack&& args)
    {
        Types::ObjectID oid = Events::ExtractArgument<Types::ObjectID>(args);
        bool value = Events::ExtractArgument<int32_t>(args) == 1;
        m_simulateDetectMap[oid] = value;

        CGameObject* obj = Globals::AppManager()->m_pServerExoApp->GetGameObject(oid);
        if (obj && obj->m_nObjectType == Constants::OBJECT_TYPE_CREATURE)
        {
            reinterpret_cast<CNWSCreature*>(obj)->ComputeModifiedMovementRate();
        }

        return Events::ArgumentStack();
    });

    GetServices()->m_events->RegisterEvent("CAP_WALK_RATE", [this](Events::ArgumentStack&& args)
    {
        Types::ObjectID oid = Events::ExtractArgument<Types::ObjectID>(args);
        bool value = Events::ExtractArgument<int32_t>(args) == 1;
        m_capWalkSpeedMap[oid] = value;
        return Events::ArgumentStack();
    });
}

MoveSpeed::~MoveSpeed()
{
}

void MoveSpeed::SimulateDetectInlineHook(CNWSCreature* creature, int* limitCount)
{
    // limitCount will be 0 if nothing is forcing a drop into walk mode, else is may be 1 or more.
    if (!(*limitCount) && g_plugin->m_simulateDetectMap[creature->m_idSelf])
    {
        // If we're flagged to force run as walk, we emulate toggling a mode of some description.
        *limitCount = 1;
    }
}

float MoveSpeed::GetWalkRateHook(CNWSCreature* creature)
{
    static constexpr float baseWalkRate = 1000.0f * 2.0f * 1.0f; // 1000.0f * fMovementWalkSpeed (base) * m_fMovementScaleFactor (base)

    float originalWalkRate = g_walkRateHook->CallOriginal<float>(creature);

    if (originalWalkRate > baseWalkRate && g_plugin->m_capWalkSpeedMap[creature->m_idSelf])
    {
        return baseWalkRate;
    }

    return originalWalkRate;
}

}
