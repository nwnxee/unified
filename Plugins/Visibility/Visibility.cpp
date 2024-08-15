#include "nwnx.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_EXPORT ArgumentStack GetVisibilityOverride(ArgumentStack&& args)
{
    const auto oidPlayer = args.extract<ObjectID>();
    const auto oidTarget = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);

    int32_t retVal = -1;
    if (oidPlayer == Constants::OBJECT_INVALID)
    {
        if (auto *pTargetGO = Utils::GetGameObject(oidTarget))
        {
            if (auto globalOverride = pTargetGO->nwnxGet<int32_t>("GLOBAL_VISIBILITY_OVERRIDE"))
                retVal = *globalOverride;
        }
    }
    else
    {
        if (auto *pPlayerGO = Utils::GetGameObject(oidPlayer))
        {
            if (auto personalOverride = pPlayerGO->nwnxGet<int32_t>("PERSONAL_VISIBILITY_OVERRIDE_" + std::to_string(oidTarget)))
                retVal = *personalOverride;
        }
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack SetVisibilityOverride(ArgumentStack&& args)
{
    static Hooks::Hook s_TestObjectVisibleHook = Hooks::HookFunction(&CNWSMessage::TestObjectVisible,
    +[](CNWSMessage *pThis, CNWSObject *pAreaObject, CNWSObject *pPlayerGameObject) -> int32_t
    {
        if (pAreaObject->m_idSelf == pPlayerGameObject->m_idSelf)
            return s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);

        int32_t visibilityOverride = -1;
        if (auto personalOverride = pPlayerGameObject->nwnxGet<int32_t>("PERSONAL_VISIBILITY_OVERRIDE_" + std::to_string(pAreaObject->m_idSelf)))
            visibilityOverride = *personalOverride;
        if (visibilityOverride == -1)
        {
            if (auto globalOverride = pAreaObject->nwnxGet<int32_t>("GLOBAL_VISIBILITY_OVERRIDE"))
                visibilityOverride = *globalOverride;
        }

        switch (visibilityOverride)
        {
            case 1: // NWNX_VISIBILITY_HIDDEN:
                return false;
            case 2: // NWNX_VISIBILITY_DM_ONLY:
                return Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->GetIsDM() && s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
            case 3: // NWNX_VISIBILITY_ALWAYS_VISIBLE:
                return true;
            case 4: // NWNX_VISIBILITY_ALWAYS_VISIBLE_DM_ONLY:
                return Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->GetIsDM();
            default:
                return s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
        }
    }, Hooks::Order::Late);

    const auto oidPlayer = args.extract<ObjectID>();
    const auto oidTarget = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);
    const auto override = args.extract<int32_t>();
      ASSERT_OR_THROW(override <= 4);

    if (oidPlayer == Constants::OBJECT_INVALID)
    {
        if (auto *pTargetGO = Utils::GetGameObject(oidTarget))
        {
            if (override < 0)
                pTargetGO->nwnxRemove("GLOBAL_VISIBILITY_OVERRIDE");
            else
                pTargetGO->nwnxSet("GLOBAL_VISIBILITY_OVERRIDE", override);
        }
    }
    else
    {
        if (auto *pPlayerGO = Utils::GetGameObject(oidPlayer))
        {
            if (override < 0)
                pPlayerGO->nwnxRemove("PERSONAL_VISIBILITY_OVERRIDE_" + std::to_string(oidTarget));
            else
                pPlayerGO->nwnxSet("PERSONAL_VISIBILITY_OVERRIDE_" + std::to_string(oidTarget), override);
        }
    }

    return {};
}
