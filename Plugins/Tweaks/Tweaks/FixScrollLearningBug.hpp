#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Tweaks {

class FixScrollLearningBug
{
public:
    FixScrollLearningBug(NWNXLib::Services::HooksProxy* hooker);

private:
    static BOOL CNWSCreature__LearnScroll_hook(CNWSCreature *, OBJECT_ID);
};

}
