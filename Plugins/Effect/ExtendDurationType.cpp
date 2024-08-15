#include "nwnx.hpp"

#include "API/Constants.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/CNWSObject.hpp"
#include "API/CGameEffect.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static void ExtendDurationType() __attribute__((constructor));

static void ExtendDurationType()
{
    if (!Config::Get<bool>("EXTEND_DURATION_TYPE"))
        return;

    static int32_t nextEffectDurationType;

    static Hooks::Hook pCNWSObjectApplyEffect = Hooks::HookFunction(
        &CNWSObject::ApplyEffect,
        +[](CNWSObject* pThis, CGameEffect* e, BOOL bLoadingGame, BOOL bInitialApplication)
        {
            if (nextEffectDurationType == 3 || // EQUIPPED
                nextEffectDurationType == 4) // INNATE
            {
                LOG_DEBUG("ApplyEffectOnObject(%x, %p): Overriding DURATION_TYPE=%d\n",
                    pThis->m_idSelf, e, nextEffectDurationType);

                e->SetDurationType(nextEffectDurationType);
            }

            pCNWSObjectApplyEffect->CallOriginal<void>(pThis, e, bLoadingGame,
                bInitialApplication);

        }, Hooks::Order::VeryEarly);

    static Hooks::Hook pExecuteCommandApplyEffectOnObjectHook = Hooks::HookFunction(
        &CNWSVirtualMachineCommands::ExecuteCommandApplyEffectOnObject,
        +[](CNWSVirtualMachineCommands *pThis, int32_t nCommandId, int32_t nParameters) -> int32_t
        {
            // At this point in the original game code, this is the comment pasted here verbatim:
            //
	        // don't want to inadvertantly give people the ability to apply 'innate' or 'equipped' durations
	        // so we're going to do this carefully rather than just assigning the value.
            //
            // It follows with basically this code:
            //
	        // switch ( nDurationType )
	        // {
	        //     case CGAMEEFFECT_DURATION_TYPE_INSTANTANEOUS:
            //         pEffect->SetDurationType(CGAMEEFFECT_DURATION_TYPE_INSTANTANEOUS);
            // ..
            //     default:
	        //         pEffect->SetDurationType(CGAMEEFFECT_DURATION_TYPE_PERMANENT);
            // }
            //
            // So we just fix it in ApplyEffect instead: We grab the intended duration type
            // off the stack and save it for the immediately-following invocation of ApplyEffect.

            if (!g_pVirtualMachine->StackPopInteger(&nextEffectDurationType))
                return Constants::VMError::StackUnderflow;

            if (!g_pVirtualMachine->StackPushInteger(nextEffectDurationType))
                return Constants::VMError::StackOverflow;

            int32_t ret = pExecuteCommandApplyEffectOnObjectHook->CallOriginal<int32_t>(pThis,
                nCommandId, nParameters);

            nextEffectDurationType = 0;

            return ret;

        }, Hooks::Order::VeryEarly);
}

NWNX_EXPORT ArgumentStack GetIsEffectValid(ArgumentStack&& args)
{
    auto* pEffect = args.extract<CGameEffect*>();
    ASSERT_OR_THROW(pEffect);
    SCOPEGUARD(Utils::DestroyGameEffect(pEffect));

    return pEffect->m_nType != Constants::EffectTrueType::Invalid;
}

NWNX_EXPORT ArgumentStack GetAppliedEffectCount(ArgumentStack&& args)
{
    if (auto* pObj = Utils::PopObject(args))
    {
        return pObj->m_appliedEffects.num;
    }

    return 0;
}

NWNX_EXPORT ArgumentStack GetAppliedEffect(ArgumentStack&& args)
{
    auto* pEffect = new CGameEffect;
    pEffect->m_nType = Constants::EffectTrueType::Invalid;

    if (auto* pObj = Utils::PopObject(args))
    {
        int32_t nNth = args.extract<int32_t>();
        if (nNth >= 0 && nNth < pObj->m_appliedEffects.num)
        {
            *pEffect = *pObj->m_appliedEffects.element[nNth];
        }
    }

    return pEffect;
}
