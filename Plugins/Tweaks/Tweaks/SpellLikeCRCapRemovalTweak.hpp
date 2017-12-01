#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Tweaks {

class SpellLikeCRCapRemovalTweak
{
public:
    SpellLikeCRCapRemovalTweak(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooks, NWNXLib::ViewPtr<NWNXLib::Services::PatchingProxy> patching);

private:
    int ComputeLastUpdate_CompareSpellLikeAbilityHook(CNWSMessage* thisPtr, CNWSCreature* creature, CNWSPlayerLastUpdateObject* luo);
    void ComputeLastUpdate_WriteSpellLikeAbilityHook(CNWSCreature *pCreature, CNWSPlayerLastUpdateObject* luo);
    void ComputeLastUpdate_StoreUpdateSpellLikeAbility(HookCNWSCreature *pCreature, CNWSPlayerLastUpdateObject* luo);
};

}
