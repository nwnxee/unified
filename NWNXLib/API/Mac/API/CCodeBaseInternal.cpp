#include "CCodeBaseInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CODE4St.hpp"
#include "SCodeBaseData.hpp"

namespace NWNXLib {

namespace API {

CCodeBaseInternal::CCodeBaseInternal()
{
    CCodeBaseInternal__CCodeBaseInternalCtor__0(this);
}

CCodeBaseInternal::~CCodeBaseInternal()
{
    CCodeBaseInternal__CCodeBaseInternalDtor__0(this);
}

int32_t CCodeBaseInternal::AddBinaryData(CExoString& a0, CExoString& a1, CExoString& a2, char a3, void* a4, int32_t a5)
{
    return CCodeBaseInternal__AddBinaryData(this, a0, a1, a2, a3, a4, a5);
}

int32_t CCodeBaseInternal::AddFloat(CExoString& a0, CExoString& a1, CExoString& a2, float a3)
{
    return CCodeBaseInternal__AddFloat(this, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal::AddInt(CExoString& a0, CExoString& a1, CExoString& a2, int32_t a3)
{
    return CCodeBaseInternal__AddInt(this, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal::AddLocation(CExoString& a0, CExoString& a1, CExoString& a2, const CScriptLocation& a3)
{
    return CCodeBaseInternal__AddLocation(this, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal::AddString(CExoString& a0, CExoString& a1, CExoString& a2, CExoString& a3)
{
    return CCodeBaseInternal__AddString(this, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal::AddVarEnd(SCodeBaseData* a0, int32_t a1)
{
    return CCodeBaseInternal__AddVarEnd(this, a0, a1);
}

int32_t CCodeBaseInternal::AddVarStart(SCodeBaseData* a0, CExoString& a1, CExoString& a2, int32_t& a3)
{
    return CCodeBaseInternal__AddVarStart(this, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal::AddVector(CExoString& a0, CExoString& a1, CExoString& a2, const Vector& a3)
{
    return CCodeBaseInternal__AddVector(this, a0, a1, a2, a3);
}

void CCodeBaseInternal::CloseAllFiles()
{
    return CCodeBaseInternal__CloseAllFiles(this);
}

void CCodeBaseInternal::CloseFile(int32_t a0)
{
    return CCodeBaseInternal__CloseFile(this, a0);
}

int32_t CCodeBaseInternal::DeleteVar(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__DeleteVar(this, a0, a1, a2);
}

void CCodeBaseInternal::DestroyDatabase(CExoString& a0)
{
    return CCodeBaseInternal__DestroyDatabase(this, a0);
}

void* CCodeBaseInternal::GetBinaryData(CExoString& a0, CExoString& a1, CExoString& a2, char& a3, int32_t& a4)
{
    return CCodeBaseInternal__GetBinaryData(this, a0, a1, a2, a3, a4);
}

SCodeBaseData* CCodeBaseInternal::GetFile(CExoString& a0, int32_t a1)
{
    return CCodeBaseInternal__GetFile(this, a0, a1);
}

float CCodeBaseInternal::GetFloat(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__GetFloat(this, a0, a1, a2);
}

int32_t CCodeBaseInternal::GetInt(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__GetInt(this, a0, a1, a2);
}

CScriptLocation* CCodeBaseInternal::GetLocation(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__GetLocation(this, a0, a1, a2);
}

CExoString* CCodeBaseInternal::GetString(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__GetString(this, a0, a1, a2);
}

void CCodeBaseInternal::GetVar(SCodeBaseData* a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__GetVar(this, a0, a1, a2);
}

Vector* CCodeBaseInternal::GetVector(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBaseInternal__GetVector(this, a0, a1, a2);
}

int32_t CCodeBaseInternal::OpenFile(CExoString& a0, int32_t a1)
{
    return CCodeBaseInternal__OpenFile(this, a0, a1);
}

void CCodeBaseInternal__CCodeBaseInternalCtor__0(CCodeBaseInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBaseInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__CCodeBaseInternalCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CCodeBaseInternal__CCodeBaseInternalDtor__0(CCodeBaseInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBaseInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__CCodeBaseInternalDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CCodeBaseInternal__AddBinaryData(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, char a3, void* a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, char, void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddBinaryData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CCodeBaseInternal__AddFloat(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, float a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal__AddInt(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal__AddLocation(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, const CScriptLocation& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, const CScriptLocation&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal__AddString(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal__AddVarEnd(CCodeBaseInternal* thisPtr, SCodeBaseData* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, SCodeBaseData*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddVarEnd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CCodeBaseInternal__AddVarStart(CCodeBaseInternal* thisPtr, SCodeBaseData* a0, CExoString& a1, CExoString& a2, int32_t& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, SCodeBaseData*, CExoString&, CExoString&, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddVarStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBaseInternal__AddVector(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, const Vector& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__AddVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CCodeBaseInternal__CloseAllFiles(CCodeBaseInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBaseInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__CloseAllFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CCodeBaseInternal__CloseFile(CCodeBaseInternal* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBaseInternal*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__CloseFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CCodeBaseInternal__DeleteVar(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__DeleteVar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CCodeBaseInternal__DestroyDatabase(CCodeBaseInternal* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__DestroyDatabase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CCodeBaseInternal__GetBinaryData(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, char& a3, int32_t& a4)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&, char&, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetBinaryData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

SCodeBaseData* CCodeBaseInternal__GetFile(CCodeBaseInternal* thisPtr, CExoString& a0, int32_t a1)
{
    using FuncPtrType = SCodeBaseData*(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

float CCodeBaseInternal__GetFloat(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CCodeBaseInternal__GetInt(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CScriptLocation* CCodeBaseInternal__GetLocation(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = CScriptLocation*(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString* CCodeBaseInternal__GetString(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CCodeBaseInternal__GetVar(CCodeBaseInternal* thisPtr, SCodeBaseData* a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBaseInternal*, SCodeBaseData*, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetVar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

Vector* CCodeBaseInternal__GetVector(CCodeBaseInternal* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = Vector*(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__GetVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CCodeBaseInternal__OpenFile(CCodeBaseInternal* thisPtr, CExoString& a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBaseInternal*, CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBaseInternal__OpenFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
