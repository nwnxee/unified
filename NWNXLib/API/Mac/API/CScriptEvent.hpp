#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedCExoString.hpp"
#include "CExoArrayListTemplatedfloat.hpp"
#include "CExoArrayListTemplatedint.hpp"
#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;

struct CScriptEvent
{
    uint16_t m_nType;
    CExoArrayListTemplatedint m_nParamInteger;
    CExoArrayListTemplatedfloat m_fParamFloat;
    CExoArrayListTemplatedCExoString m_sParamString;
    CExoArrayListTemplatedlongunsignedint m_oidParamObjectID;

    // The below are auto generated stubs.
    CScriptEvent(const CScriptEvent&) = default;
    CScriptEvent& operator=(const CScriptEvent&) = default;

    CScriptEvent();
    ~CScriptEvent();
    void CopyScriptEvent(CScriptEvent*);
    float GetFloat(int32_t);
    int32_t GetInteger(int32_t);
    uint32_t GetObjectID(int32_t);
    CExoString GetString(int32_t);
    int32_t LoadEvent(CResGFF*, CResStruct*);
    int32_t operator!=(const CScriptEvent&);
    int32_t operator==(const CScriptEvent&);
    int32_t SaveEvent(CResGFF*, CResStruct*);
    void SetFloat(int32_t, float);
    void SetInteger(int32_t, int32_t);
    void SetObjectID(int32_t, uint32_t);
    void SetString(int32_t, CExoString);
};

void CScriptEvent__CScriptEventCtor__0(CScriptEvent* thisPtr);
void CScriptEvent__CScriptEventDtor__0(CScriptEvent* thisPtr);
void CScriptEvent__CopyScriptEvent(CScriptEvent* thisPtr, CScriptEvent*);
float CScriptEvent__GetFloat(CScriptEvent* thisPtr, int32_t);
int32_t CScriptEvent__GetInteger(CScriptEvent* thisPtr, int32_t);
uint32_t CScriptEvent__GetObjectID(CScriptEvent* thisPtr, int32_t);
CExoString CScriptEvent__GetString(CScriptEvent* thisPtr, int32_t);
int32_t CScriptEvent__LoadEvent(CScriptEvent* thisPtr, CResGFF*, CResStruct*);
int32_t CScriptEvent__OperatorNotEqualTo(CScriptEvent* thisPtr, const CScriptEvent&);
int32_t CScriptEvent__OperatorEqualTo(CScriptEvent* thisPtr, const CScriptEvent&);
int32_t CScriptEvent__SaveEvent(CScriptEvent* thisPtr, CResGFF*, CResStruct*);
void CScriptEvent__SetFloat(CScriptEvent* thisPtr, int32_t, float);
void CScriptEvent__SetInteger(CScriptEvent* thisPtr, int32_t, int32_t);
void CScriptEvent__SetObjectID(CScriptEvent* thisPtr, int32_t, uint32_t);
void CScriptEvent__SetString(CScriptEvent* thisPtr, int32_t, CExoString);

}

}
