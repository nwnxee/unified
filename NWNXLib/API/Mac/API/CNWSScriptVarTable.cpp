#include "CNWSScriptVarTable.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSCreature.hpp"
#include "CNWSScriptVar.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSScriptVarTable::~CNWSScriptVarTable()
{
    CNWSScriptVarTable__CNWSScriptVarTableDtor__0(this);
}

void CNWSScriptVarTable::DeleteIndex(CExoString& a0, uint32_t a1)
{
    return CNWSScriptVarTable__DeleteIndex(this, a0, a1);
}

void CNWSScriptVarTable::DestroyFloat(CExoString& a0)
{
    return CNWSScriptVarTable__DestroyFloat(this, a0);
}

void CNWSScriptVarTable::DestroyInt(CExoString& a0)
{
    return CNWSScriptVarTable__DestroyInt(this, a0);
}

void CNWSScriptVarTable::DestroyLocation(CExoString& a0)
{
    return CNWSScriptVarTable__DestroyLocation(this, a0);
}

void CNWSScriptVarTable::DestroyObject(CExoString& a0)
{
    return CNWSScriptVarTable__DestroyObject(this, a0);
}

void CNWSScriptVarTable::DestroyString(CExoString& a0)
{
    return CNWSScriptVarTable__DestroyString(this, a0);
}

float CNWSScriptVarTable::GetFloat(CExoString& a0)
{
    return CNWSScriptVarTable__GetFloat(this, a0);
}

int32_t CNWSScriptVarTable::GetInt(CExoString& a0)
{
    return CNWSScriptVarTable__GetInt(this, a0);
}

CScriptLocation CNWSScriptVarTable::GetLocation(CExoString& a0)
{
    return CNWSScriptVarTable__GetLocation(this, a0);
}

uint32_t CNWSScriptVarTable::GetObject(CExoString& a0)
{
    return CNWSScriptVarTable__GetObject(this, a0);
}

CExoString CNWSScriptVarTable::GetString(CExoString& a0)
{
    return CNWSScriptVarTable__GetString(this, a0);
}

void CNWSScriptVarTable::LoadVarTable(CResGFF* a0, CResStruct* a1)
{
    return CNWSScriptVarTable__LoadVarTable(this, a0, a1);
}

CNWSScriptVar* CNWSScriptVarTable::MatchIndex(CExoString& a0, uint32_t a1, int32_t a2)
{
    return CNWSScriptVarTable__MatchIndex(this, a0, a1, a2);
}

void CNWSScriptVarTable::SaveVarTable(CResGFF* a0, CResStruct* a1)
{
    return CNWSScriptVarTable__SaveVarTable(this, a0, a1);
}

void CNWSScriptVarTable::SetFloat(CExoString& a0, float a1)
{
    return CNWSScriptVarTable__SetFloat(this, a0, a1);
}

void CNWSScriptVarTable::SetInt(CExoString& a0, int32_t a1, int32_t a2)
{
    return CNWSScriptVarTable__SetInt(this, a0, a1, a2);
}

void CNWSScriptVarTable::SetLocation(CExoString& a0, CScriptLocation a1)
{
    return CNWSScriptVarTable__SetLocation(this, a0, a1);
}

void CNWSScriptVarTable::SetObject(CExoString& a0, uint32_t a1)
{
    return CNWSScriptVarTable__SetObject(this, a0, a1);
}

void CNWSScriptVarTable::SetString(CExoString& a0, CExoString& a1)
{
    return CNWSScriptVarTable__SetString(this, a0, a1);
}

void CNWSScriptVarTable__CNWSScriptVarTableDtor__0(CNWSScriptVarTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__CNWSScriptVarTableDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSScriptVarTable__DeleteIndex(CNWSScriptVarTable* thisPtr, CExoString& a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__DeleteIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSScriptVarTable__DestroyFloat(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__DestroyFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSScriptVarTable__DestroyInt(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__DestroyInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSScriptVarTable__DestroyLocation(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__DestroyLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSScriptVarTable__DestroyObject(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__DestroyObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSScriptVarTable__DestroyString(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__DestroyString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CNWSScriptVarTable__GetFloat(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__GetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSScriptVarTable__GetInt(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__GetInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CScriptLocation CNWSScriptVarTable__GetLocation(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = CScriptLocation(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__GetLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSScriptVarTable__GetObject(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__GetObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSScriptVarTable__GetString(CNWSScriptVarTable* thisPtr, CExoString& a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSScriptVarTable__LoadVarTable(CNWSScriptVarTable* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__LoadVarTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSScriptVar* CNWSScriptVarTable__MatchIndex(CNWSScriptVarTable* thisPtr, CExoString& a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = CNWSScriptVar*(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__MatchIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSScriptVarTable__SaveVarTable(CNWSScriptVarTable* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__SaveVarTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSScriptVarTable__SetFloat(CNWSScriptVarTable* thisPtr, CExoString& a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__SetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSScriptVarTable__SetInt(CNWSScriptVarTable* thisPtr, CExoString& a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__SetInt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSScriptVarTable__SetLocation(CNWSScriptVarTable* thisPtr, CExoString& a0, CScriptLocation a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, CScriptLocation);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__SetLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSScriptVarTable__SetObject(CNWSScriptVarTable* thisPtr, CExoString& a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__SetObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSScriptVarTable__SetString(CNWSScriptVarTable* thisPtr, CExoString& a0, CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSScriptVarTable*, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSScriptVarTable__SetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
