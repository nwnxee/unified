#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixPerPartColoring
{
public:
    FixPerPartColoring(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void    CNWItem__SetLayeredTextureColorPerPart_hook(NWNXLib::API::CNWItem*, uint8_t, uint8_t, uint8_t);
    static uint8_t CNWItem__GetLayeredTextureColorPerPart_hook(NWNXLib::API::CNWItem*, uint8_t, uint8_t);
    static NWNXLib::Hooking::FunctionHook* pSetLayeredTextureColorPerPart_hook;
    static NWNXLib::Hooking::FunctionHook* pGetLayeredTextureColorPerPart_hook;

};

}
