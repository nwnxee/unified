#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class UUIDEvents
{
public:
    UUIDEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static void LoadFromGffHook(bool, CNWSUUID*, CResGFF*, CResStruct*);
    static inline char UUIDGffFieldName[] = "UUID";
};

}
