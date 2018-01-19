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

struct CNWCCMessageData
{
    uint8_t m_nType;
    CExoArrayListTemplatedint m_nParamInteger;
    CExoArrayListTemplatedfloat m_nParamFloat;
    CExoArrayListTemplatedCExoString m_sParamString;
    CExoArrayListTemplatedlongunsignedint m_oidParamObjectID;

    // The below are auto generated stubs.
    CNWCCMessageData(const CNWCCMessageData&) = default;
    CNWCCMessageData& operator=(const CNWCCMessageData&) = default;

    CNWCCMessageData();
    ~CNWCCMessageData();
    void ClearData();
    void CopyTo(CNWCCMessageData*);
    float GetFloat(int32_t);
    int32_t GetInteger(int32_t);
    uint32_t GetObjectID(int32_t);
    CExoString GetString(int32_t);
    int32_t LoadData(CResGFF*, CResStruct*);
    int32_t SaveData(CResGFF*, CResStruct*);
    void SetFloat(int32_t, float);
    void SetInteger(int32_t, int32_t);
    void SetObjectID(int32_t, uint32_t);
    void SetString(int32_t, CExoString);
};

void CNWCCMessageData__CNWCCMessageDataCtor(CNWCCMessageData* thisPtr);
void CNWCCMessageData__CNWCCMessageDataDtor(CNWCCMessageData* thisPtr);
void CNWCCMessageData__ClearData(CNWCCMessageData* thisPtr);
void CNWCCMessageData__CopyTo(CNWCCMessageData* thisPtr, CNWCCMessageData*);
float CNWCCMessageData__GetFloat(CNWCCMessageData* thisPtr, int32_t);
int32_t CNWCCMessageData__GetInteger(CNWCCMessageData* thisPtr, int32_t);
uint32_t CNWCCMessageData__GetObjectID(CNWCCMessageData* thisPtr, int32_t);
CExoString CNWCCMessageData__GetString(CNWCCMessageData* thisPtr, int32_t);
int32_t CNWCCMessageData__LoadData(CNWCCMessageData* thisPtr, CResGFF*, CResStruct*);
int32_t CNWCCMessageData__SaveData(CNWCCMessageData* thisPtr, CResGFF*, CResStruct*);
void CNWCCMessageData__SetFloat(CNWCCMessageData* thisPtr, int32_t, float);
void CNWCCMessageData__SetInteger(CNWCCMessageData* thisPtr, int32_t, int32_t);
void CNWCCMessageData__SetObjectID(CNWCCMessageData* thisPtr, int32_t, uint32_t);
void CNWCCMessageData__SetString(CNWCCMessageData* thisPtr, int32_t, CExoString);

}

}
