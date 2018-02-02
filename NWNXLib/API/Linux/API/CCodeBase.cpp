#include "CCodeBase.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CCodeBaseInternal.hpp"
#include "CExoString.hpp"
#include "CScriptLocation.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

CCodeBase::CCodeBase()
{
    CCodeBase__CCodeBaseCtor(this);
}

CCodeBase::~CCodeBase()
{
    CCodeBase__CCodeBaseDtor(this);
}

int32_t CCodeBase::AddBinaryData(CExoString& a0, CExoString& a1, CExoString& a2, char a3, void* a4, int32_t a5)
{
    return CCodeBase__AddBinaryData(this, a0, a1, a2, a3, a4, a5);
}

int32_t CCodeBase::AddFloat(CExoString& a0, CExoString& a1, CExoString& a2, float a3)
{
    return CCodeBase__AddFloat(this, a0, a1, a2, a3);
}

int32_t CCodeBase::AddInt(CExoString& a0, CExoString& a1, CExoString& a2, int32_t a3)
{
    return CCodeBase__AddInt(this, a0, a1, a2, a3);
}

int32_t CCodeBase::AddLocation(CExoString& a0, CExoString& a1, CExoString& a2, const CScriptLocation& a3)
{
    return CCodeBase__AddLocation(this, a0, a1, a2, a3);
}

int32_t CCodeBase::AddString(CExoString& a0, CExoString& a1, CExoString& a2, CExoString& a3)
{
    return CCodeBase__AddString(this, a0, a1, a2, a3);
}

int32_t CCodeBase::AddVector(CExoString& a0, CExoString& a1, CExoString& a2, const Vector& a3)
{
    return CCodeBase__AddVector(this, a0, a1, a2, a3);
}

void CCodeBase::CloseAllFiles()
{
    return CCodeBase__CloseAllFiles(this);
}

int32_t CCodeBase::DeleteVar(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBase__DeleteVar(this, a0, a1, a2);
}

void CCodeBase::DestroyDatabase(CExoString& a0)
{
    return CCodeBase__DestroyDatabase(this, a0);
}

void* CCodeBase::GetBinaryData(CExoString& a0, CExoString& a1, CExoString& a2, char& a3, int32_t& a4)
{
    return CCodeBase__GetBinaryData(this, a0, a1, a2, a3, a4);
}

float CCodeBase::GetFloat(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBase__GetFloat(this, a0, a1, a2);
}

int32_t CCodeBase::GetInt(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBase__GetInt(this, a0, a1, a2);
}

CScriptLocation* CCodeBase::GetLocation(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBase__GetLocation(this, a0, a1, a2);
}

CExoString* CCodeBase::GetString(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBase__GetString(this, a0, a1, a2);
}

Vector* CCodeBase::GetVector(CExoString& a0, CExoString& a1, CExoString& a2)
{
    return CCodeBase__GetVector(this, a0, a1, a2);
}

void CCodeBase__CCodeBaseCtor(CCodeBase* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBase*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__CCodeBaseCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CCodeBase__CCodeBaseDtor(CCodeBase* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBase*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__CCodeBaseDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CCodeBase__AddBinaryData(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, char a3, void* a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, char, void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__AddBinaryData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CCodeBase__AddFloat(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, float a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__AddFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBase__AddInt(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__AddInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBase__AddLocation(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, const CScriptLocation& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, const CScriptLocation&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__AddLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBase__AddString(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, CExoString& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__AddString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CCodeBase__AddVector(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, const Vector& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__AddVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CCodeBase__CloseAllFiles(CCodeBase* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBase*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__CloseAllFiles);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CCodeBase__DeleteVar(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__DeleteVar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CCodeBase__DestroyDatabase(CCodeBase* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCodeBase*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__DestroyDatabase);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CCodeBase__GetBinaryData(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2, char& a3, int32_t& a4)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&, char&, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__GetBinaryData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

float CCodeBase__GetFloat(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__GetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CCodeBase__GetInt(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__GetInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CScriptLocation* CCodeBase__GetLocation(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = CScriptLocation*(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__GetLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CExoString* CCodeBase__GetString(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

Vector* CCodeBase__GetVector(CCodeBase* thisPtr, CExoString& a0, CExoString& a1, CExoString& a2)
{
    using FuncPtrType = Vector*(__attribute__((cdecl)) *)(CCodeBase*, CExoString&, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCodeBase__GetVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
