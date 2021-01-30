#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class DisableQuicksave
{
public:
    DisableQuicksave(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CServerExoAppInternal__SaveGame_hook(CServerExoAppInternal*, uint32_t,
        CExoString&, CExoString&, CNWSPlayer*, int32_t, CExoString&);
};

}
