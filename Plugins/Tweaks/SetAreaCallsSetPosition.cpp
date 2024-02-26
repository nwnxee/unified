#include "nwnx.hpp"
#include "API/CNWSArea.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

void SetAreaCallsSetPosition() __attribute__((constructor));
void SetAreaCallsSetPosition()
{
    if (!Config::Get<bool>("SETAREA_CALLS_SETPOSITION", false))
        return;

    LOG_INFO("Calling SetPosition() after SetArea().");

    static Hooks::Hook s_SetAreaHook = Hooks::HookFunction(&CNWSObject::SetArea,+[](CNWSObject *pThis, CNWSArea *pArea) -> void
    {
        s_SetAreaHook->CallOriginal<void>(pThis, pArea);

        if (pThis->GetArea())
        {
            if (auto *pCreature = Utils::AsNWSCreature(pThis))
                pCreature->SetPosition(pCreature->m_vPosition);
        }
    }, Hooks::Order::Early);
}

}
