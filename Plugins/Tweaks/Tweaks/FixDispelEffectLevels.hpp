#pragma once

#include "nwnx.hpp"

namespace Tweaks
{

class FixDispelEffectLevels
{
public:
    FixDispelEffectLevels();

private:
    static int32_t CNWSEffectListHandler__OnApplyDispelAllMagic(CNWSEffectListHandler* thisPtr, CNWSObject* pObject, CGameEffect* pEffect, BOOL bLoadingGame);
    static int32_t CNWSEffectListHandler__OnApplyDispelBestMagic(CNWSEffectListHandler* thisPtr, CNWSObject* pObject, CGameEffect* pEffect, BOOL bLoadingGame);
};

}
