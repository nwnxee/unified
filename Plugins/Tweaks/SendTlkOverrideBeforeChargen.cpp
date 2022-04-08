#include "nwnx.hpp"

#include "API/CNWSMessage.hpp"
#include "API/CNWSPlayer.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void SendTlkOverrideBeforeChargen() __attribute__((constructor));
void SendTlkOverrideBeforeChargen()
{
    if (!Config::Get<bool>("SEND_TLK_OVERRIDE_BEFORE_CHARGEN", false))
        return;

    LOG_INFO("Sending Tlk Overrides before Character Generation.");

   static Hooks::Hook s_SendServerToPlayerCharListHook = Hooks::HookFunction(
            API::Functions::_ZN11CNWSMessage26SendServerToPlayerCharListEP10CNWSPlayer,
            (void*)+[](CNWSMessage *thisPtr, CNWSPlayer *pPlayer) -> int32_t
            {
                auto retVal = s_SendServerToPlayerCharListHook->CallOriginal<int32_t>(thisPtr, pPlayer);

                thisPtr->SendServerToPlayerSetTlkOverrideList(pPlayer->m_nPlayerID);

                return retVal;
            }, Hooks::Order::Late);
}

}
