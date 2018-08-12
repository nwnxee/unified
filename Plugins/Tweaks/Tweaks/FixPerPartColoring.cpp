#include "Tweaks/FixPerPartColoring.hpp"
#include "API/CNWSItem.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/Version.hpp"

#include "Services/Hooks/Hooks.hpp"
#include "Utils.hpp"
#include <cstring>

NWNX_EXPECT_VERSION(8179); // Only needed for 8179, remove with API update.

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

Hooking::FunctionHook* FixPerPartColoring::pSetLayeredTextureColorPerPart_hook;
Hooking::FunctionHook* FixPerPartColoring::pGetLayeredTextureColorPerPart_hook;
FixPerPartColoring::FixPerPartColoring(ViewPtr<Services::HooksProxy> hooker)
{
    hooker->RequestExclusiveHook<Functions::CNWItem__SetLayeredTextureColorPerPart>
                                    (&CNWItem__SetLayeredTextureColorPerPart_hook);
    hooker->RequestExclusiveHook<Functions::CNWItem__GetLayeredTextureColorPerPart>
                                    (&CNWItem__GetLayeredTextureColorPerPart_hook);

    pSetLayeredTextureColorPerPart_hook = hooker->FindHookByAddress(Functions::CNWItem__SetLayeredTextureColorPerPart);
    pGetLayeredTextureColorPerPart_hook = hooker->FindHookByAddress(Functions::CNWItem__GetLayeredTextureColorPerPart);
}

void FixPerPartColoring::CNWItem__SetLayeredTextureColorPerPart_hook(CNWItem *pThis, uint8_t nTexture, uint8_t nPart, uint8_t nColor)
{
    if (pThis->m_pLayeredTextureColorsPerPart[nTexture] == 0)
    {
        if (nColor == 0xFF)
        {
            return;
        }

        pThis->m_pLayeredTextureColorsPerPart[nTexture] = new uint8_t[19];
        std::memset(pThis->m_pLayeredTextureColorsPerPart[nTexture], 0xFF, 19);
    }
    pThis->m_pLayeredTextureColorsPerPart[nTexture][nPart] = nColor;
}

uint8_t FixPerPartColoring::CNWItem__GetLayeredTextureColorPerPart_hook(CNWItem *pThis, uint8_t nTexture, uint8_t nPart)
{
    if (nTexture < 6 && nPart < 19 && pThis->m_pLayeredTextureColorsPerPart[nTexture])
        return pThis->m_pLayeredTextureColorsPerPart[nTexture][nPart];
    else
        return 0xFF;
}


}
