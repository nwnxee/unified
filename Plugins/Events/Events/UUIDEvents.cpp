#include "Events/UUIDEvents.hpp"
#include "API/CNWSUUID.hpp"
#include "API/CResGFF.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "Events.hpp"
#include "Utils.hpp"


namespace Events {

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Hooking::FunctionHook *s_UUIDLoadFromGffHook;

UUIDEvents::UUIDEvents(Services::HooksProxy* hooker)
{
    Events::InitOnFirstSubscribe("NWNX_ON_UUID_COLLISION_.*", [hooker]() {
        s_UUIDLoadFromGffHook = hooker->Hook(API::Functions::_ZN8CNWSUUID11LoadFromGffEP7CResGFFP10CResStruct,
                                             (void*)&LoadFromGffHook, Hooking::Order::Earliest);
    });
}

bool UUIDEvents::LoadFromGffHook(CNWSUUID *thisPtr, CResGFF *pResGFF, CResStruct *pResStruct)
{
    bool bCollided;
    int32_t success;
    CExoString uuid = pResGFF->ReadFieldCExoString(pResStruct, UUIDGffFieldName, success);

    if (success && !uuid.IsEmpty())
    {
        auto LookupObjectIdByUUID = reinterpret_cast<ObjectID(*)(CExoString&)>(
                Platform::ASLR::GetRelocatedAddress(API::Functions::_ZN8CNWSUUID20LookupObjectIdByUUIDERK10CExoString));

        bCollided = LookupObjectIdByUUID(uuid) != Constants::OBJECT_INVALID;

        if (bCollided)
        {
            Events::PushEventData("UUID", uuid.CStr());
            Events::SignalEvent("NWNX_ON_UUID_COLLISION_BEFORE", thisPtr->m_parent->m_idSelf);
        }
    }
    else
    {
        bCollided = false;
    }

    auto retVal = s_UUIDLoadFromGffHook->CallOriginal<bool>(thisPtr, pResGFF, pResStruct);

    if (bCollided)
    {
        Events::PushEventData("UUID", uuid.CStr());
        Events::SignalEvent("NWNX_ON_UUID_COLLISION_AFTER", thisPtr->m_parent->m_idSelf);
    }

    return retVal;
}

}
