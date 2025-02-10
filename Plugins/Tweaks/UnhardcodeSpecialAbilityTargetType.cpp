#include "nwnx.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void UnhardcodeSpecialAbilityTargetType() __attribute__((constructor));
void UnhardcodeSpecialAbilityTargetType()
{
    if (!Config::Get<bool>("UNHARDCODE_SPECIAL_ABILITY_TARGET_TYPE", false))
        return;

    LOG_INFO("Special abilities can also be used on target types other than creatures.");

    static Hooks::Hook s_AddUseTalentOnObjectActionsHook = Hooks::HookFunction(&CNWSCreature::AddUseTalentOnObjectActions,
        +[](CNWSCreature *pThis, int32_t nType, int32_t nId, OBJECT_ID oidTarget, uint8_t nMultiClass, OBJECT_ID oidItem,
            int32_t nItemPropertyIndex, uint8_t nCasterLevel, uint8_t nMetaType) -> int32_t
        {
            auto *pTargetObject = Utils::AsNWSObject(Utils::GetGameObject(oidTarget));
            if ((nType == 0 && !pTargetObject) || (nType != 0 && !Utils::AsNWSCreature(pTargetObject)))
                return false;
            if (!pThis->m_bAbleToModifyActionQueue)
                return false;

            const Vector vTargetLocation = pTargetObject->m_vPosition;
            ObjectID oidTargetArea;
            if (auto *pArea = pThis->GetArea())
                oidTargetArea = pArea->m_idSelf;
            else
                oidTargetArea = Constants::OBJECT_INVALID;

            switch (nType)
            {
                case 0: // TALENT_TYPE_SPELL
                {
                    if (oidItem != Constants::OBJECT_INVALID && nItemPropertyIndex != -1)
                        pThis->UseItem(oidItem, nItemPropertyIndex, 0, oidTarget, vTargetLocation, oidTargetArea);
                    else
                    {
                        pThis->AddCastSpellActions(nId, nMultiClass, 0, nMetaType, false, vTargetLocation, oidTarget,
                            false, false, false, 0, false, false, -1, nCasterLevel);
                    }
                    break;
                }
                case 1: // TALENT_TYPE_FEAT
                {
                    uint16_t nSubFeat = 0;
                    if (nId == Constants::Feat::CalledShot)
                        nSubFeat = rand() % 2 ? 65001 : 65000;
                    pThis->UseFeat(nId, nSubFeat, oidTarget, oidTargetArea);
                    break;
                }
                case 2: // TALENT_TYPE_SKILL
                {
                    pThis->UseSkill(nId, 0, oidTarget, vTargetLocation, oidTargetArea);
                    break;
                }
                default: break;
            }

            return true;
        }, Hooks::Order::Final);
}

}
