#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"


using namespace NWNXLib;
using namespace NWNXLib::API;
using ArgumentStack = Events::ArgumentStack;


namespace Visibility {

static int32_t GetGlobalOverride(ObjectID);
static int32_t GetPersonalOverride(ObjectID, ObjectID);

static Hooks::Hook s_TestObjectVisibleHook =
        Hooks::HookFunction(API::Functions::_ZN11CNWSMessage17TestObjectVisibleEP10CNWSObjectS1_,
        (void*)+[](CNWSMessage *pThis, CNWSObject *pAreaObject, CNWSObject *pPlayerGameObject) -> int32_t
        {
            if (pAreaObject->m_idSelf == pPlayerGameObject->m_idSelf)
            {
                return s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
            }

            int32_t visiblityState;
            int32_t personalOverride = GetPersonalOverride(pPlayerGameObject->m_idSelf, pAreaObject->m_idSelf);
            int32_t globalOverride = GetGlobalOverride(pAreaObject->m_idSelf);
            int32_t visibilityOverride = personalOverride != -1 ? personalOverride : globalOverride != -1 ? globalOverride : -1;

            switch (visibilityOverride)
            {
                case 0: // NWNX_VISIBILITY_VISIBLE
                    visiblityState = -1;
                    break;

                case 1: // NWNX_VISIBILITY_HIDDEN
                    visiblityState = false;
                    break;

                case 2: // NWNX_VISIBILITY_DM_ONLY
                    visiblityState = Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->GetIsDM() ? -1 : false;
                    break;

                case 3: // NWNX_VISIBILITY_ALWAYS_VISIBLE
                    visiblityState = true;
                    break;

                case 4: // NWNX_VISIBILITY_ALWAYS_VISIBLE_DM_ONLY
                    visiblityState = Utils::AsNWSCreature(pPlayerGameObject)->m_pStats->GetIsDM();
                    break;

                default:
                    visiblityState = -1;
            }

            return visiblityState != -1 ? visiblityState : s_TestObjectVisibleHook->CallOriginal<int32_t>(pThis, pAreaObject, pPlayerGameObject);
        }, Hooks::Order::Late);


static int32_t GetGlobalOverride(ObjectID targetId)
{
    int32_t retVal = -1;

    auto *target = Utils::GetGameObject(targetId);
    if (auto globalOverride = target->nwnxGet<int>("GLOBAL_VISIBILITY_OVERRIDE"))
    {
        retVal = *globalOverride;
    }

    return retVal;
}

static int32_t GetPersonalOverride(ObjectID playerId, ObjectID targetId)
{
    int32_t retVal = -1;

    auto *player = Utils::GetGameObject(playerId);
    if (auto personalOverride = player->nwnxGet<int>(Utils::ObjectIDToString(targetId)))
    {
        retVal = *personalOverride;
    }

    return retVal;
}

NWNX_EXPORT ArgumentStack GetVisibilityOverride(ArgumentStack&& args)
{
    const auto playerId = args.extract<ObjectID>();
    const auto targetId = args.extract<ObjectID>();
      ASSERT_OR_THROW(targetId != Constants::OBJECT_INVALID);

    int32_t retVal = (playerId == Constants::OBJECT_INVALID) ? GetGlobalOverride(targetId) :
                                                               GetPersonalOverride(playerId, targetId);

    return retVal;
}

NWNX_EXPORT ArgumentStack SetVisibilityOverride(ArgumentStack&& args)
{
    auto playerId = args.extract<ObjectID>();
    const auto targetId = args.extract<ObjectID>();
      ASSERT_OR_THROW(targetId != Constants::OBJECT_INVALID);
    const auto override = args.extract<int32_t>();

    std::string varName = Utils::ObjectIDToString(targetId);

    if (playerId == Constants::OBJECT_INVALID)
    {
        varName = "GLOBAL_VISIBILITY_OVERRIDE";
        playerId = targetId;
    }

    auto *player = Utils::GetGameObject(playerId);
    if (override < 0)
        player->nwnxRemove(varName);
    else
        player->nwnxSet(varName, override);

    return {};
}

}
