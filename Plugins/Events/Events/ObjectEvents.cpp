#include "Events.hpp"
#include "API/CNWSObject.hpp"
#include "API/CNWSPlaceable.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_AddLockObjectActionHook;
static NWNXLib::Hooks::Hook s_AddUnlockObjectActionHook;
static NWNXLib::Hooks::Hook s_AddUseObjectActionHook;
static NWNXLib::Hooks::Hook s_OpenInventoryHook;
static NWNXLib::Hooks::Hook s_CloseInventoryHook;
static NWNXLib::Hooks::Hook s_BroadcastSafeProjectileHook;

static int32_t AddLockObjectActionHook(CNWSObject*, ObjectID);
static int32_t AddUnlockObjectActionHook(CNWSObject*, ObjectID, ObjectID, int32_t);
static int32_t AddUseObjectActionHook(CNWSObject*, ObjectID);
static void OpenInventoryHook(CNWSPlaceable*, ObjectID);
static void CloseInventoryHook(CNWSPlaceable*, ObjectID, BOOL);
static void BroadcastSafeProjectileHook(CNWSObject*, ObjectID, ObjectID, Vector, Vector, uint32_t, uint8_t, uint32_t, uint8_t, uint8_t);

void ObjectEvents() __attribute__((constructor));
void ObjectEvents()
{
    InitOnFirstSubscribe("NWNX_ON_OBJECT_LOCK_.*", []() {
        s_AddLockObjectActionHook = Hooks::HookFunction(&CNWSObject::AddLockObjectAction,
                                                 &AddLockObjectActionHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_OBJECT_UNLOCK_.*", []() {
        s_AddUnlockObjectActionHook = Hooks::HookFunction(&CNWSObject::AddUnlockObjectAction,
                                                   &AddUnlockObjectActionHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_OBJECT_USE_.*", []() {
        s_AddUseObjectActionHook = Hooks::HookFunction(&CNWSObject::AddUseObjectAction,
                                                   (void*)&AddUseObjectActionHook, Hooks::Order::Early);
    });
    
    InitOnFirstSubscribe("NWNX_ON_PLACEABLE_OPEN_.*", []() {
        s_OpenInventoryHook = Hooks::HookFunction(&CNWSPlaceable::OpenInventory,
                                                   (void*)&OpenInventoryHook, Hooks::Order::Early);
    });
    
    InitOnFirstSubscribe("NWNX_ON_PLACEABLE_CLOSE_.*", []() {
        s_CloseInventoryHook = Hooks::HookFunction(&CNWSPlaceable::CloseInventory,
                                                   (void*)&CloseInventoryHook, Hooks::Order::Early);
    });

    InitOnFirstSubscribe("NWNX_ON_BROADCAST_SAFE_PROJECTILE_.*", []() {
        s_BroadcastSafeProjectileHook = Hooks::HookFunction(&CNWSObject::BroadcastSafeProjectile,
                                             (void*)&BroadcastSafeProjectileHook, Hooks::Order::Early);
    });
}

int32_t AddLockObjectActionHook(CNWSObject *thisPtr, ObjectID oidDoor)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));

        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_LOCK_BEFORE"))
    {
        retVal = s_AddLockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_LOCK_AFTER");

    return retVal;
}

int32_t AddUnlockObjectActionHook(CNWSObject *thisPtr, ObjectID oidDoor, ObjectID oidThievesTool, int32_t nActivePropertyIndex)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("DOOR", Utils::ObjectIDToString(oidDoor));
        PushEventData("THIEVES_TOOL", Utils::ObjectIDToString(oidThievesTool));
        PushEventData("ACTIVE_PROPERTY_INDEX", std::to_string(nActivePropertyIndex));

        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_UNLOCK_BEFORE"))
    {
        retVal = s_AddUnlockObjectActionHook->CallOriginal<int32_t>(thisPtr, oidDoor, oidThievesTool, nActivePropertyIndex);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_UNLOCK_AFTER");

    return retVal;
}

int32_t AddUseObjectActionHook(CNWSObject *thisPtr, ObjectID oidObjectToUse)
{
    int32_t retVal;

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("OBJECT", Utils::ObjectIDToString(oidObjectToUse));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_OBJECT_USE_BEFORE"))
    {
        retVal = s_AddUseObjectActionHook->CallOriginal<int32_t>(thisPtr, oidObjectToUse);
    }
    else
    {
        retVal = false;
    }

    PushEventData("ACTION_RESULT", std::to_string(retVal));
    PushAndSignal("NWNX_ON_OBJECT_USE_AFTER");

    return retVal;
}

void OpenInventoryHook(CNWSPlaceable *thisPtr, ObjectID oidOpener)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("OBJECT", Utils::ObjectIDToString(oidOpener));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    bool skipped = false;
    if (PushAndSignal("NWNX_ON_PLACEABLE_OPEN_BEFORE"))
    {
        s_OpenInventoryHook->CallOriginal<int32_t>(thisPtr, oidOpener);
    } 
    else 
    {
        skipped = true;
    }

    PushEventData("BEFORE_SKIPPED", std::to_string(skipped));
    PushAndSignal("NWNX_ON_PLACEABLE_OPEN_AFTER");
}

void CloseInventoryHook(CNWSPlaceable *thisPtr, ObjectID oidCloser, BOOL bUpdatePlayer = true)
{
    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("OBJECT", Utils::ObjectIDToString(oidCloser));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    // don't allow SkipEvent on close event, otherwise it hangs client ui.
    PushAndSignal("NWNX_ON_PLACEABLE_CLOSE_BEFORE");
    s_CloseInventoryHook->CallOriginal<int32_t>(thisPtr, oidCloser, bUpdatePlayer);
    PushAndSignal("NWNX_ON_PLACEABLE_CLOSE_AFTER");
}

void BroadcastSafeProjectileHook(CNWSObject *thisPtr, ObjectID oidOriginator, ObjectID oidTarget, Vector vOriginator, Vector vTarget, uint32_t nDelta,
                                    uint8_t nProjectileType, uint32_t nSpellID, uint8_t nAttackResult, uint8_t nProjectilePathType)
{
    if (!IsIDInWhitelist("NWNX_ON_BROADCAST_SAFE_PROJECTILE_TYPE", nProjectileType) || !IsIDInWhitelist("NWNX_ON_BROADCAST_SAFE_PROJECTILE_SPELL_ID", nSpellID))
    {
        s_BroadcastSafeProjectileHook->CallOriginal<void>(thisPtr, oidOriginator, oidTarget, vOriginator, vTarget, nDelta, nProjectileType, nSpellID, nAttackResult, nProjectilePathType);
        return;
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("TARGET_OBJECT_ID", Utils::ObjectIDToString(oidTarget));
        PushEventData("TARGET_POSITION_X", std::to_string(vTarget.x));
        PushEventData("TARGET_POSITION_Y", std::to_string(vTarget.y));
        PushEventData("TARGET_POSITION_Z", std::to_string(vTarget.z));
        PushEventData("DELTA", std::to_string(nDelta));
        PushEventData("PROJECTILE_TYPE", std::to_string(nProjectileType));
        PushEventData("SPELL_ID", std::to_string(nSpellID));
        PushEventData("ATTACK_RESULT", std::to_string(nAttackResult));
        PushEventData("PROJECTILE_PATH_TYPE", std::to_string(nProjectilePathType));
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignal("NWNX_ON_BROADCAST_SAFE_PROJECTILE_BEFORE"))
    {
        s_BroadcastSafeProjectileHook->CallOriginal<void>(thisPtr, oidOriginator, oidTarget, vOriginator, vTarget, nDelta, nProjectileType, nSpellID, nAttackResult, nProjectilePathType);
    }

    PushAndSignal("NWNX_ON_BROADCAST_SAFE_PROJECTILE_AFTER");
}

}
