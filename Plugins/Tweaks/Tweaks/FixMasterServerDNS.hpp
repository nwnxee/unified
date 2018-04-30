#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixMasterServerDNS
{
public:
    FixMasterServerDNS(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t CExoNetInternal__TranslateAddressFromString__Hook(NWNXLib::API::CExoNetInternal*,
        char*, uint32_t*, uint8_t*, uint8_t*, uint32_t*);

    static NWNXLib::Hooking::FunctionHook* s_Hook;
};

}
