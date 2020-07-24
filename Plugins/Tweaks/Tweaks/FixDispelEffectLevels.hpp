#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks
{

class FixDispelEffectLevels
{
public:
    FixDispelEffectLevels(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CNWSEffectListHandler__OnApplyDispelAllMagic(CNWSEffectListHandler* thisPtr, CNWSObject* pObject, CGameEffect* pEffect, BOOL bLoadingGame);
    static int32_t CNWSEffectListHandler__OnApplyDispelBestMagic(CNWSEffectListHandler* thisPtr, CNWSObject* pObject, CGameEffect* pEffect, BOOL bLoadingGame);
};

}
