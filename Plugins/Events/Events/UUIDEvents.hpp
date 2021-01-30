#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class UUIDEvents
{
public:
    UUIDEvents();

private:
    static bool LoadFromGffHook(CNWSUUID*, CResGFF*, CResStruct*);
    static inline char UUIDGffFieldName[] = "UUID";
};

}
