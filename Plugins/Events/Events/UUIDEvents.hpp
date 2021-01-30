#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

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
