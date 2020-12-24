#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class ClearSpellEffectsOnTURDs
{
public:
    ClearSpellEffectsOnTURDs(NWNXLib::Services::HooksProxy* hooker);

private:
    static void CNWSObject__ClearSpellEffectsOnOthers_hook(bool, CNWSObject*);
};

}
