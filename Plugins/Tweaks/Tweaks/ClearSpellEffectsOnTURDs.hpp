#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class ClearSpellEffectsOnTURDs
{
public:
    ClearSpellEffectsOnTURDs();

private:
    static void CNWSObject__ClearSpellEffectsOnOthers_hook(CNWSObject*);
};

}
