#pragma once

#include "nwnx.hpp"

namespace Tweaks {

class ClearSpellEffectsOnTURDs
{
public:
    ClearSpellEffectsOnTURDs(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSObject__ClearSpellEffectsOnOthers_hook(CNWSObject*);
};

}
