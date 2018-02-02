#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedSCodeBaseDataPtr.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;
struct CODE4St;
struct CScriptLocation;
struct SCodeBaseData;
struct Vector;

struct CCodeBaseInternal
{
    CODE4St* m_cb;
    CExoArrayListTemplatedSCodeBaseDataPtr m_lstDataFiles;

    // The below are auto generated stubs.
    CCodeBaseInternal(const CCodeBaseInternal&) = default;
    CCodeBaseInternal& operator=(const CCodeBaseInternal&) = default;

    CCodeBaseInternal();
    ~CCodeBaseInternal();
    int32_t AddBinaryData(CExoString&, CExoString&, CExoString&, char, void*, int32_t);
    int32_t AddFloat(CExoString&, CExoString&, CExoString&, float);
    int32_t AddInt(CExoString&, CExoString&, CExoString&, int32_t);
    int32_t AddLocation(CExoString&, CExoString&, CExoString&, const CScriptLocation&);
    int32_t AddString(CExoString&, CExoString&, CExoString&, CExoString&);
    int32_t AddVarEnd(SCodeBaseData*, int32_t);
    int32_t AddVarStart(SCodeBaseData*, CExoString&, CExoString&, int32_t&);
    int32_t AddVector(CExoString&, CExoString&, CExoString&, const Vector&);
    void CloseAllFiles();
    void CloseFile(int32_t);
    int32_t DeleteVar(CExoString&, CExoString&, CExoString&);
    void DestroyDatabase(CExoString&);
    void* GetBinaryData(CExoString&, CExoString&, CExoString&, char&, int32_t&);
    SCodeBaseData* GetFile(CExoString&, int32_t);
    float GetFloat(CExoString&, CExoString&, CExoString&);
    int32_t GetInt(CExoString&, CExoString&, CExoString&);
    CScriptLocation* GetLocation(CExoString&, CExoString&, CExoString&);
    CExoString* GetString(CExoString&, CExoString&, CExoString&);
    void GetVar(SCodeBaseData*, CExoString&, CExoString&);
    Vector* GetVector(CExoString&, CExoString&, CExoString&);
    int32_t OpenFile(CExoString&, int32_t);
};

void CCodeBaseInternal__CCodeBaseInternalCtor__0(CCodeBaseInternal* thisPtr);
void CCodeBaseInternal__CCodeBaseInternalDtor__0(CCodeBaseInternal* thisPtr);
int32_t CCodeBaseInternal__AddBinaryData(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, char, void*, int32_t);
int32_t CCodeBaseInternal__AddFloat(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, float);
int32_t CCodeBaseInternal__AddInt(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, int32_t);
int32_t CCodeBaseInternal__AddLocation(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, const CScriptLocation&);
int32_t CCodeBaseInternal__AddString(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, CExoString&);
int32_t CCodeBaseInternal__AddVarEnd(CCodeBaseInternal* thisPtr, SCodeBaseData*, int32_t);
int32_t CCodeBaseInternal__AddVarStart(CCodeBaseInternal* thisPtr, SCodeBaseData*, CExoString&, CExoString&, int32_t&);
int32_t CCodeBaseInternal__AddVector(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, const Vector&);
void CCodeBaseInternal__CloseAllFiles(CCodeBaseInternal* thisPtr);
void CCodeBaseInternal__CloseFile(CCodeBaseInternal* thisPtr, int32_t);
int32_t CCodeBaseInternal__DeleteVar(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&);
void CCodeBaseInternal__DestroyDatabase(CCodeBaseInternal* thisPtr, CExoString&);
void* CCodeBaseInternal__GetBinaryData(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&, char&, int32_t&);
SCodeBaseData* CCodeBaseInternal__GetFile(CCodeBaseInternal* thisPtr, CExoString&, int32_t);
float CCodeBaseInternal__GetFloat(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&);
int32_t CCodeBaseInternal__GetInt(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&);
CScriptLocation* CCodeBaseInternal__GetLocation(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&);
CExoString* CCodeBaseInternal__GetString(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&);
void CCodeBaseInternal__GetVar(CCodeBaseInternal* thisPtr, SCodeBaseData*, CExoString&, CExoString&);
Vector* CCodeBaseInternal__GetVector(CCodeBaseInternal* thisPtr, CExoString&, CExoString&, CExoString&);
int32_t CCodeBaseInternal__OpenFile(CCodeBaseInternal* thisPtr, CExoString&, int32_t);

}

}
