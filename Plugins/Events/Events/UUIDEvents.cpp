#include "Events.hpp"
#include "API/CNWSUUID.hpp"
#include "API/CResGFF.hpp"
#include "API/CGameObject.hpp"

namespace Events {

using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static NWNXLib::Hooks::Hook s_UUIDLoadFromGffHook;
static inline char UUIDGffFieldName[] = "UUID";

static bool LoadFromGffHook(CNWSUUID*, CResGFF*, CResStruct*);

void UUIDEvents() __attribute__((constructor));
void UUIDEvents()
{
    InitOnFirstSubscribe("NWNX_ON_UUID_COLLISION_.*", []() {
        s_UUIDLoadFromGffHook = NWNXLib::Hooks::HookFunction(Functions::_ZN8CNWSUUID11LoadFromGffEP7CResGFFP10CResStruct,
                                             (void*)&LoadFromGffHook, NWNXLib::Hooks::Order::Earliest);
    });
}

bool LoadFromGffHook(CNWSUUID *thisPtr, CResGFF *pResGFF, CResStruct *pResStruct)
{
    bool bCollided;
    int32_t success;
    CExoString uuid = pResGFF->ReadFieldCExoString(pResStruct, UUIDGffFieldName, success);

    if (success && !uuid.IsEmpty())
    {
        auto LookupObjectIdByUUID = reinterpret_cast<ObjectID(*)(CExoString&)>(
                NWNXLib::Platform::GetRelocatedAddress(Functions::_ZN8CNWSUUID20LookupObjectIdByUUIDERK10CExoString));

        bCollided = LookupObjectIdByUUID(uuid) != Constants::OBJECT_INVALID;

        if (bCollided)
        {
            PushEventData("UUID", uuid.CStr());
            SignalEvent("NWNX_ON_UUID_COLLISION_BEFORE", thisPtr->m_parent->m_idSelf);
        }
    }
    else
    {
        bCollided = false;
    }

    auto retVal = s_UUIDLoadFromGffHook->CallOriginal<bool>(thisPtr, pResGFF, pResStruct);

    if (bCollided)
    {
        PushEventData("UUID", uuid.CStr());
        SignalEvent("NWNX_ON_UUID_COLLISION_AFTER", thisPtr->m_parent->m_idSelf);
    }

    return retVal;
}

}
