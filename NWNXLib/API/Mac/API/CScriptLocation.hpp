#pragma once

#include <cstdint>

#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CScriptLocation
{
    Vector m_vPosition;
    Vector m_vOrientation;
    uint32_t m_oArea;

    // The below are auto generated stubs.
    CScriptLocation(const CScriptLocation&) = default;
    CScriptLocation& operator=(const CScriptLocation&) = default;

    CScriptLocation();
    ~CScriptLocation();
    void CopyScriptLocation(CScriptLocation*);
    int32_t LoadLocation(CResGFF*, CResStruct*);
    int32_t SaveLocation(CResGFF*, CResStruct*);
};

void CScriptLocation__CScriptLocationCtor__0(CScriptLocation* thisPtr);
void CScriptLocation__CScriptLocationDtor__0(CScriptLocation* thisPtr);
void CScriptLocation__CopyScriptLocation(CScriptLocation* thisPtr, CScriptLocation*);
int32_t CScriptLocation__LoadLocation(CScriptLocation* thisPtr, CResGFF*, CResStruct*);
int32_t CScriptLocation__SaveLocation(CScriptLocation* thisPtr, CResGFF*, CResStruct*);

}

}
