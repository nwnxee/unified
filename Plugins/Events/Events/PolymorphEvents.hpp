#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class PolymorphEvents
{
public:
    PolymorphEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t PolymorphHook(NWNXLib::API::CNWSCreature*, int32_t, NWNXLib::API::CGameEffect*, int32_t);
    static int32_t UnPolymorphHook(NWNXLib::API::CNWSCreature*, NWNXLib::API::CGameEffect*);

};

}
