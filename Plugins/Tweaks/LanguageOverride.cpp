#include "nwnx.hpp"

#include "API/CServerExoAppInternal.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static int s_Lang;

void LanguageOverride() __attribute__((constructor));
void LanguageOverride()
{
    s_Lang = Config::Get<int>("LANGUAGE_OVERRIDE", 0);
    if (s_Lang==0)
        return;
    else if (!((s_Lang>=1 && s_Lang<=6) || (s_Lang>=128 && s_Lang<=131)))
    {
        LOG_INFO("Unknown value for NWNX_TWEAKS_LANGUAGE_OVERRIDE.");
        return;
    }

    LOG_INFO("Language override set to %d", s_Lang);

    static Hooks::Hook s_GetPlayerLanguage_hook = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal17GetPlayerLanguageEj,
        (void*)+[](CServerExoAppInternal*, uint32_t) -> int32_t
        {
            return s_Lang;
        }, Hooks::Order::Final);
}

}
