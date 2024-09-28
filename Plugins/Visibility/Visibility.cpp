#include "nwnx.hpp"
#include "API/CNWSMessage.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::unordered_map<ObjectID, std::unordered_map<ObjectID, int32_t>> s_PersonalOverrides;
static std::unordered_map<ObjectID, int32_t> s_GlobalOverrides;

NWNX_EXPORT ArgumentStack GetVisibilityOverride(ArgumentStack&& args)
{
    const auto oidPlayer = args.extract<ObjectID>();
    const auto oidTarget = args.extract<ObjectID>();
      ASSERT_OR_THROW(oidTarget != Constants::OBJECT_INVALID);

    int32_t retVal = -1;
    if (oidPlayer == Constants::OBJECT_INVALID)
    {
        auto globalIt = s_GlobalOverrides.find(oidTarget);
        if (globalIt != s_GlobalOverrides.end())
            return globalIt->second;
    }
    else
    {
        auto personalIt = s_PersonalOverrides.find(oidPlayer);
        if (personalIt != s_PersonalOverrides.end())
        {
            auto targetIt = personalIt->second.find(oidTarget);
            if (targetIt != personalIt->second.end())
                return targetIt->second;
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
        auto personalIt = s_PersonalOverrides.find(pPlayerGameObject->m_idSelf);
        if (personalIt != s_PersonalOverrides.end())
        {
            auto targetIt = personalIt->second.find(pAreaObject->m_idSelf);
            if (targetIt != personalIt->second.end())
                visibilityOverride = targetIt->second;
        }
        if (visibilityOverride == -1)
        {
            auto globalIt = s_GlobalOverrides.find(pAreaObject->m_idSelf);
            if (globalIt != s_GlobalOverrides.end())
                visibilityOverride = globalIt->second;
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
                s_GlobalOverrides.erase(oidTarget);
            else
                s_GlobalOverrides[oidTarget] = override;
        }
    }
    else
    {
        if (auto *pPlayerGO = Utils::GetGameObject(oidPlayer))
        {
            if (override < 0)
                s_PersonalOverrides[oidPlayer].erase(oidTarget);
            else
                s_PersonalOverrides[oidPlayer][oidTarget] = override;
        }
    }

    return {};
}
