#include "nwnx.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CGameEffect.hpp"
#include "API/CGameObject.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void UncapDamageResistanceDamageFlags() __attribute__((constructor));
void UncapDamageResistanceDamageFlags()
{
    if (!Config::Get<bool>("UNCAP_DAMAGE_RESISTANCE_DAMAGE_FLAGS", false))
        return;

    LOG_INFO("Damage flags for EffectDamageResistance will be uncapped.");

    static Hooks::Hook s_ExecuteCommandEffectDamageResistanceHook =
            Hooks::HookFunction(&CNWVirtualMachineCommands::ExecuteCommandEffectDamageResistance,
    +[](CNWVirtualMachineCommands *thisPtr, int32_t, int32_t) -> int32_t
            {
                auto *pVM = Globals::VirtualMachine();
                int32_t nDamageFlags, nAmount, nLimit;

                if (!pVM->StackPopInteger(&nDamageFlags) ||
                    !pVM->StackPopInteger(&nAmount) ||
                    !pVM->StackPopInteger(&nLimit))
                    return Constants::VMError::StackUnderflow;

                if (nDamageFlags < 0)
                    nDamageFlags = Constants::DamageType::Magical;

                auto *pEffect = new CGameEffect(true);
                  SCOPEGUARD(delete pEffect);
                pEffect->m_nType = Constants::EffectTrueType::DamageResistance;
                pEffect->SetSubType_Magical();
                pEffect->SetInteger(0, nDamageFlags);
                pEffect->SetInteger(1, nAmount);
                pEffect->SetInteger(2, nLimit);

                if (auto *pGO = Utils::GetGameObject(thisPtr->m_oidObjectRunScript))
                    pEffect->SetCreator(pGO->m_idSelf);

                if (!pVM->StackPushEngineStructure(Constants::VMStructure::Effect, (void*)pEffect))
                    return Constants::VMError::StackOverflow;

                return 0;
            }, Hooks::Order::Final);
}

}
