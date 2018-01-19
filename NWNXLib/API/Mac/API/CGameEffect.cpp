#include "CGameEffect.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CGameEffect::CGameEffect(int32_t a0)
{
    CGameEffect__CGameEffectCtor__0(this, a0);
}

CGameEffect::CGameEffect(CGameEffect* a0, int32_t a1)
{
    CGameEffect__CGameEffectCtor__2(this, a0, a1);
}

CGameEffect::~CGameEffect()
{
    CGameEffect__CGameEffectDtor__0(this);
}

void CGameEffect::CopyEffect(CGameEffect* a0, int32_t a1)
{
    return CGameEffect__CopyEffect(this, a0, a1);
}

CExoString CGameEffect::GetCustomTag()
{
    return CGameEffect__GetCustomTag(this);
}

void CGameEffect::GetExpiryTime(uint32_t* a0, uint32_t* a1)
{
    return CGameEffect__GetExpiryTime(this, a0, a1);
}

float CGameEffect::GetFloat(int32_t a0)
{
    return CGameEffect__GetFloat(this, a0);
}

int32_t CGameEffect::GetInteger(int32_t a0)
{
    return CGameEffect__GetInteger(this, a0);
}

uint32_t CGameEffect::GetObjectID(int32_t a0)
{
    return CGameEffect__GetObjectID(this, a0);
}

int32_t CGameEffect::GetScriptEffectType()
{
    return CGameEffect__GetScriptEffectType(this);
}

CExoString CGameEffect::GetString(int32_t a0)
{
    return CGameEffect__GetString(this, a0);
}

void CGameEffect::LoadGameEffect(CResGFF* a0, CResStruct* a1)
{
    return CGameEffect__LoadGameEffect(this, a0, a1);
}

int32_t CGameEffect::operator!=(const CGameEffect& a0)
{
    return CGameEffect__OperatorNotEqualTo(this, a0);
}

CGameEffect& CGameEffect::operator=(const CGameEffect& a0)
{
    return CGameEffect__OperatorAssignment(this, a0);
}

int32_t CGameEffect::operator==(const CGameEffect& a0)
{
    return CGameEffect__OperatorEqualTo(this, a0);
}

void CGameEffect::SaveGameEffect(CResGFF* a0, CResStruct* a1)
{
    return CGameEffect__SaveGameEffect(this, a0, a1);
}

void CGameEffect::SetCreator(uint32_t a0)
{
    return CGameEffect__SetCreator(this, a0);
}

void CGameEffect::SetCustomTag(const CExoString& a0)
{
    return CGameEffect__SetCustomTag(this, a0);
}

void CGameEffect::SetExpiryTime(uint32_t a0, uint32_t a1)
{
    return CGameEffect__SetExpiryTime(this, a0, a1);
}

void CGameEffect::SetFloat(int32_t a0, float a1)
{
    return CGameEffect__SetFloat(this, a0, a1);
}

void CGameEffect::SetInteger(int32_t a0, int32_t a1)
{
    return CGameEffect__SetInteger(this, a0, a1);
}

void CGameEffect::SetLinked(CGameEffect* a0, CGameEffect* a1)
{
    return CGameEffect__SetLinked(this, a0, a1);
}

void CGameEffect::SetNumIntegers(int32_t a0)
{
    return CGameEffect__SetNumIntegers(this, a0);
}

void CGameEffect::SetNumIntegersInitializeToNegativeOne(int32_t a0)
{
    return CGameEffect__SetNumIntegersInitializeToNegativeOne(this, a0);
}

void CGameEffect::SetObjectID(int32_t a0, uint32_t a1)
{
    return CGameEffect__SetObjectID(this, a0, a1);
}

void CGameEffect::SetString(int32_t a0, CExoString a1)
{
    return CGameEffect__SetString(this, a0, a1);
}

void CGameEffect::UpdateLinked()
{
    return CGameEffect__UpdateLinked(this);
}

void CGameEffect__CGameEffectCtor__0(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__CGameEffectCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CGameEffect__CGameEffectCtor__2(CGameEffect* thisPtr, CGameEffect* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__CGameEffectCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

void CGameEffect__CGameEffectDtor__0(CGameEffect* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__CGameEffectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CGameEffect__CopyEffect(CGameEffect* thisPtr, CGameEffect* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__CopyEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CExoString CGameEffect__GetCustomTag(CGameEffect* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetCustomTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CGameEffect__GetExpiryTime(CGameEffect* thisPtr, uint32_t* a0, uint32_t* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetExpiryTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

float CGameEffect__GetFloat(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CGameEffect__GetInteger(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CGameEffect__GetObjectID(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CGameEffect__GetScriptEffectType(CGameEffect* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetScriptEffectType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CGameEffect__GetString(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGameEffect__LoadGameEffect(CGameEffect* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__LoadGameEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CGameEffect__OperatorNotEqualTo(CGameEffect* thisPtr, const CGameEffect& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGameEffect*, const CGameEffect&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__OperatorNotEqualTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CGameEffect& CGameEffect__OperatorAssignment(CGameEffect* thisPtr, const CGameEffect& a0)
{
    using FuncPtrType = CGameEffect&(__attribute__((cdecl)) *)(CGameEffect*, const CGameEffect&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__OperatorAssignment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CGameEffect__OperatorEqualTo(CGameEffect* thisPtr, const CGameEffect& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CGameEffect*, const CGameEffect&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__OperatorEqualTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGameEffect__SaveGameEffect(CGameEffect* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SaveGameEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__SetCreator(CGameEffect* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetCreator);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGameEffect__SetCustomTag(CGameEffect* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetCustomTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGameEffect__SetExpiryTime(CGameEffect* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetExpiryTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__SetFloat(CGameEffect* thisPtr, int32_t a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__SetInteger(CGameEffect* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__SetLinked(CGameEffect* thisPtr, CGameEffect* a0, CGameEffect* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, CGameEffect*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetLinked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__SetNumIntegers(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetNumIntegers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGameEffect__SetNumIntegersInitializeToNegativeOne(CGameEffect* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetNumIntegersInitializeToNegativeOne);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CGameEffect__SetObjectID(CGameEffect* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__SetString(CGameEffect* thisPtr, int32_t a0, CExoString a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__SetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CGameEffect__UpdateLinked(CGameEffect* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CGameEffect__UpdateLinked);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
