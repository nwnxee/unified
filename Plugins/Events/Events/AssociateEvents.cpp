#include "Events.hpp"
#include "API/CNWSCreature.hpp"

namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;

static Hooks::Hook s_AddAssociateHook;
static Hooks::Hook s_RemoveAssociateHook;
static Hooks::Hook s_UnpossessFamiliarHook;
static Hooks::Hook s_PossessFamiliarHook;

static void AddAssociateHook(CNWSCreature*, ObjectID, uint16_t);
static void RemoveAssociateHook(CNWSCreature*, ObjectID);
static void UnpossessFamiliarHook(CNWSCreature*);
static void PossessFamiliarHook(CNWSCreature*);

void AssociateEvents() __attribute__((constructor));
void AssociateEvents()
{
    InitOnFirstSubscribe("NWNX_ON_ADD_ASSOCIATE_.*", []() {
        s_AddAssociateHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature12AddAssociateEjt,
            (void*)&AddAssociateHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_REMOVE_ASSOCIATE_.*", []() {
        s_RemoveAssociateHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature15RemoveAssociateEj,
            (void*)&RemoveAssociateHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_UNPOSSESS_FAMILIAR_.*", []() {
        s_UnpossessFamiliarHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature17UnpossessFamiliarEv,
            (void*)&UnpossessFamiliarHook, Hooks::Order::Earliest);
    });

    InitOnFirstSubscribe("NWNX_ON_POSSESS_FAMILIAR_.*", []() {
        s_PossessFamiliarHook = Hooks::HookFunction(API::Functions::_ZN12CNWSCreature15PossessFamiliarEv,
            (void*)&PossessFamiliarHook, Hooks::Order::Earliest);
    });
}

void AddAssociateHook(CNWSCreature* thisPtr, ObjectID oidAssociate, uint16_t nAssociateType)
{
    PushEventData("ASSOCIATE_OBJECT_ID", NWNXLib::Utils::ObjectIDToString(oidAssociate));
    SignalEvent("NWNX_ON_ADD_ASSOCIATE_BEFORE", thisPtr->m_idSelf);
    s_AddAssociateHook->CallOriginal<void>(thisPtr, oidAssociate, nAssociateType);
    PushEventData("ASSOCIATE_OBJECT_ID", NWNXLib::Utils::ObjectIDToString(oidAssociate));
    SignalEvent("NWNX_ON_ADD_ASSOCIATE_AFTER", thisPtr->m_idSelf);
}

void RemoveAssociateHook(CNWSCreature* thisPtr, ObjectID oidAssociate)
{
    PushEventData("ASSOCIATE_OBJECT_ID", NWNXLib::Utils::ObjectIDToString(oidAssociate));
    SignalEvent("NWNX_ON_REMOVE_ASSOCIATE_BEFORE", thisPtr->m_idSelf);
    s_RemoveAssociateHook->CallOriginal<void>(thisPtr, oidAssociate);
    PushEventData("ASSOCIATE_OBJECT_ID", NWNXLib::Utils::ObjectIDToString(oidAssociate));
    SignalEvent("NWNX_ON_REMOVE_ASSOCIATE_AFTER", thisPtr->m_idSelf);
}

void UnpossessFamiliarHook(CNWSCreature *thisPtr)
{
    std::string sFamiliarOID = Utils::ObjectIDToString(thisPtr->GetAssociateId(Constants::AssociateType::Familiar));

    auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
        PushEventData("FAMILIAR", sFamiliarOID);
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignalEvent("NWNX_ON_UNPOSSESS_FAMILIAR_BEFORE"))
    {
        s_UnpossessFamiliarHook->CallOriginal<void>(thisPtr);
    }

    PushAndSignalEvent("NWNX_ON_UNPOSSESS_FAMILIAR_AFTER");
}

void PossessFamiliarHook(CNWSCreature* thisPtr)
{
    std::string sFamiliarOID = Utils::ObjectIDToString(thisPtr->GetAssociateId(Constants::AssociateType::Familiar));

    auto PushAndSignalEvent = [&](const std::string& ev) -> bool {
        PushEventData("FAMILIAR", sFamiliarOID);
        return SignalEvent(ev, thisPtr->m_idSelf);
    };

    if (PushAndSignalEvent("NWNX_ON_POSSESS_FAMILIAR_BEFORE"))
    {
        s_PossessFamiliarHook->CallOriginal<void>(thisPtr);
    }

    PushAndSignalEvent("NWNX_ON_POSSESS_FAMILIAR_AFTER");
}

}
