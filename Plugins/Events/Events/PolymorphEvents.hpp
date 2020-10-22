#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class PolymorphEvents
{
public:
    PolymorphEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t OnApplyPolymorphHook(CNWSEffectListHandler*,CNWSObject*, CGameEffect*, int32_t bLoadingGame);
    static int32_t OnRemovePolymorphHook(CNWSEffectListHandler*,CNWSObject*, CGameEffect*);
};

}
