#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CCodeBaseInternal;
struct CExoString;
struct CScriptLocation;
struct Vector;

struct CCodeBase
{
    CCodeBaseInternal* m_cbInternal;

    // The below are auto generated stubs.
    CCodeBase(const CCodeBase&) = default;
    CCodeBase& operator=(const CCodeBase&) = default;

    CCodeBase();
    ~CCodeBase();
    int32_t AddBinaryData(CExoString&, CExoString&, CExoString&, char, void*, int32_t);
    int32_t AddFloat(CExoString&, CExoString&, CExoString&, float);
    int32_t AddInt(CExoString&, CExoString&, CExoString&, int32_t);
    int32_t AddLocation(CExoString&, CExoString&, CExoString&, const CScriptLocation&);
    int32_t AddString(CExoString&, CExoString&, CExoString&, CExoString&);
    int32_t AddVector(CExoString&, CExoString&, CExoString&, const Vector&);
    void CloseAllFiles();
    int32_t DeleteVar(CExoString&, CExoString&, CExoString&);
    void DestroyDatabase(CExoString&);
    void* GetBinaryData(CExoString&, CExoString&, CExoString&, char&, int32_t&);
    float GetFloat(CExoString&, CExoString&, CExoString&);
    int32_t GetInt(CExoString&, CExoString&, CExoString&);
    CScriptLocation* GetLocation(CExoString&, CExoString&, CExoString&);
    CExoString* GetString(CExoString&, CExoString&, CExoString&);
    Vector* GetVector(CExoString&, CExoString&, CExoString&);
};

void CCodeBase__CCodeBaseCtor__0(CCodeBase* thisPtr);
void CCodeBase__CCodeBaseDtor__0(CCodeBase* thisPtr);
int32_t CCodeBase__AddBinaryData(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, char, void*, int32_t);
int32_t CCodeBase__AddFloat(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, float);
int32_t CCodeBase__AddInt(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, int32_t);
int32_t CCodeBase__AddLocation(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, const CScriptLocation&);
int32_t CCodeBase__AddString(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, CExoString&);
int32_t CCodeBase__AddVector(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, const Vector&);
void CCodeBase__CloseAllFiles(CCodeBase* thisPtr);
int32_t CCodeBase__DeleteVar(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&);
void CCodeBase__DestroyDatabase(CCodeBase* thisPtr, CExoString&);
void* CCodeBase__GetBinaryData(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&, char&, int32_t&);
float CCodeBase__GetFloat(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&);
int32_t CCodeBase__GetInt(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&);
CScriptLocation* CCodeBase__GetLocation(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&);
CExoString* CCodeBase__GetString(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&);
Vector* CCodeBase__GetVector(CCodeBase* thisPtr, CExoString&, CExoString&, CExoString&);

}

}
