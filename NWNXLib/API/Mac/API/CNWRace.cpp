#include "CNWRace.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWRace::CNWRace()
{
    CNWRace__CNWRaceCtor__0(this);
}

CNWRace::~CNWRace()
{
    CNWRace__CNWRaceDtor__0(this);
}

CExoString CNWRace::GetConverNameLowerText()
{
    return CNWRace__GetConverNameLowerText(this);
}

CExoString CNWRace::GetConverNameText()
{
    return CNWRace__GetConverNameText(this);
}

CExoString CNWRace::GetDefaultBiographyText()
{
    return CNWRace__GetDefaultBiographyText(this);
}

CExoString CNWRace::GetDescriptionText()
{
    return CNWRace__GetDescriptionText(this);
}

CExoString CNWRace::GetNamePluralText()
{
    return CNWRace__GetNamePluralText(this);
}

CExoString CNWRace::GetNameText()
{
    return CNWRace__GetNameText(this);
}

int32_t CNWRace::IsFirstLevelGrantedFeat(uint16_t a0)
{
    return CNWRace__IsFirstLevelGrantedFeat(this, a0);
}

void CNWRace::LoadFeatsTable(CExoString a0)
{
    return CNWRace__LoadFeatsTable(this, a0);
}

void CNWRace__CNWRaceCtor__0(CNWRace* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__CNWRaceCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWRace__CNWRaceDtor__0(CNWRace* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRace*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__CNWRaceDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

CExoString CNWRace__GetConverNameLowerText(CNWRace* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__GetConverNameLowerText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWRace__GetConverNameText(CNWRace* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__GetConverNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWRace__GetDefaultBiographyText(CNWRace* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__GetDefaultBiographyText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWRace__GetDescriptionText(CNWRace* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__GetDescriptionText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWRace__GetNamePluralText(CNWRace* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__GetNamePluralText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWRace__GetNameText(CNWRace* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRace*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__GetNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWRace__IsFirstLevelGrantedFeat(CNWRace* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWRace*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__IsFirstLevelGrantedFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWRace__LoadFeatsTable(CNWRace* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRace*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRace__LoadFeatsTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
