#include "Events/AssociateEvents.hpp"
#include "API/CNWSCreature.hpp"
#include "API/Functions.hpp"
#include "Events.hpp"
#include "Utils.hpp"

namespace Events {

using namespace NWNXLib;

AssociateEvents::AssociateEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_ADD_ASSOCIATE_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN12CNWSCreature12AddAssociateEjt, void,
            CNWSCreature*, ObjectID, uint16_t>(&AddAssociateHook);
    });

    Events::InitOnFirstSubscribe("NWNX_ON_REMOVE_ASSOCIATE_.*", [hooker]() {
        hooker->RequestSharedHook<API::Functions::_ZN12CNWSCreature15RemoveAssociateEj, void,
            CNWSCreature*, ObjectID>(&RemoveAssociateHook);
    });
}

void AssociateEvents::AddAssociateHook(bool before, CNWSCreature* thisPtr, ObjectID assocId, uint16_t)
{
    Events::PushEventData("ASSOCIATE_OBJECT_ID", NWNXLib::Utils::ObjectIDToString(assocId));
    Events::SignalEvent(before ? "NWNX_ON_ADD_ASSOCIATE_BEFORE" : "NWNX_ON_ADD_ASSOCIATE_AFTER", thisPtr->m_idSelf);
}

void AssociateEvents::RemoveAssociateHook(bool before, CNWSCreature* thisPtr, ObjectID assocId)
{
    Events::PushEventData("ASSOCIATE_OBJECT_ID", NWNXLib::Utils::ObjectIDToString(assocId));
    Events::SignalEvent(before ? "NWNX_ON_REMOVE_ASSOCIATE_BEFORE" : "NWNX_ON_REMOVE_ASSOCIATE_AFTER", thisPtr->m_idSelf);
}

}
