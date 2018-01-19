#include "CScriptEvent.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CScriptEvent::CScriptEvent()
{
    CScriptEvent__CScriptEventCtor(this);
}

CScriptEvent::~CScriptEvent()
{
    CScriptEvent__CScriptEventDtor(this);
}

void CScriptEvent::CopyScriptEvent(CScriptEvent* a0)
{
    return CScriptEvent__CopyScriptEvent(this, a0);
}

float CScriptEvent::GetFloat(int32_t a0)
{
    return CScriptEvent__GetFloat(this, a0);
}

int32_t CScriptEvent::GetInteger(int32_t a0)
{
    return CScriptEvent__GetInteger(this, a0);
}

uint32_t CScriptEvent::GetObjectID(int32_t a0)
{
    return CScriptEvent__GetObjectID(this, a0);
}

CExoString CScriptEvent::GetString(int32_t a0)
{
    return CScriptEvent__GetString(this, a0);
}

int32_t CScriptEvent::LoadEvent(CResGFF* a0, CResStruct* a1)
{
    return CScriptEvent__LoadEvent(this, a0, a1);
}

int32_t CScriptEvent::operator!=(const CScriptEvent& a0)
{
    return CScriptEvent__OperatorNotEqualTo(this, a0);
}

int32_t CScriptEvent::operator==(const CScriptEvent& a0)
{
    return CScriptEvent__OperatorEqualTo(this, a0);
}

int32_t CScriptEvent::SaveEvent(CResGFF* a0, CResStruct* a1)
{
    return CScriptEvent__SaveEvent(this, a0, a1);
}

void CScriptEvent::SetFloat(int32_t a0, float a1)
{
    return CScriptEvent__SetFloat(this, a0, a1);
}

void CScriptEvent::SetInteger(int32_t a0, int32_t a1)
{
    return CScriptEvent__SetInteger(this, a0, a1);
}

void CScriptEvent::SetObjectID(int32_t a0, uint32_t a1)
{
    return CScriptEvent__SetObjectID(this, a0, a1);
}

void CScriptEvent::SetString(int32_t a0, CExoString a1)
{
    return CScriptEvent__SetString(this, a0, a1);
}

void CScriptEvent__CScriptEventCtor(CScriptEvent* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__CScriptEventCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CScriptEvent__CScriptEventDtor(CScriptEvent* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__CScriptEventDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CScriptEvent__CopyScriptEvent(CScriptEvent* thisPtr, CScriptEvent* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*, CScriptEvent*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__CopyScriptEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

float CScriptEvent__GetFloat(CScriptEvent* thisPtr, int32_t a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CScriptEvent*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__GetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptEvent__GetInteger(CScriptEvent* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptEvent*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__GetInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CScriptEvent__GetObjectID(CScriptEvent* thisPtr, int32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CScriptEvent*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__GetObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CScriptEvent__GetString(CScriptEvent* thisPtr, int32_t a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CScriptEvent*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__GetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptEvent__LoadEvent(CScriptEvent* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptEvent*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__LoadEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptEvent__OperatorNotEqualTo(CScriptEvent* thisPtr, const CScriptEvent& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptEvent*, const CScriptEvent&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__OperatorNotEqualTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptEvent__OperatorEqualTo(CScriptEvent* thisPtr, const CScriptEvent& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptEvent*, const CScriptEvent&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__OperatorEqualTo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptEvent__SaveEvent(CScriptEvent* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptEvent*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__SaveEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptEvent__SetFloat(CScriptEvent* thisPtr, int32_t a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__SetFloat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptEvent__SetInteger(CScriptEvent* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__SetInteger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptEvent__SetObjectID(CScriptEvent* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__SetObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CScriptEvent__SetString(CScriptEvent* thisPtr, int32_t a0, CExoString a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptEvent*, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptEvent__SetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
