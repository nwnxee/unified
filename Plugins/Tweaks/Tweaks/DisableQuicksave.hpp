#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class DisableQuicksave
{
public:
    DisableQuicksave(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t CServerExoAppInternal__SaveGame_hook(NWNXLib::API::CServerExoAppInternal*, uint32_t,
        NWNXLib::API::CExoString&, NWNXLib::API::CExoString&, NWNXLib::API::CNWSPlayer*, int32_t, NWNXLib::API::CExoString&);
    static NWNXLib::Hooking::FunctionHook* pSaveGame_hook;
};

}
