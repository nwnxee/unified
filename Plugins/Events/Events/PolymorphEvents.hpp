#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class PolymorphEvents
{
public:
    PolymorphEvents();

private:
    static int32_t OnApplyPolymorphHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t);
    static int32_t OnRemovePolymorphHook(CNWSEffectListHandler*, CNWSObject*, CGameEffect*);
};

}
