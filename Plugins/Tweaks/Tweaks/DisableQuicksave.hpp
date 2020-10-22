#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class DisableQuicksave
{
public:
    DisableQuicksave(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CServerExoAppInternal__SaveGame_hook(CServerExoAppInternal*, uint32_t,
        CExoString&, CExoString&, CNWSPlayer*, int32_t, CExoString&);
    static NWNXLib::Hooking::FunctionHook* pSaveGame_hook;
};

}
