#include "CServerAIMaster.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedint.hpp"
#include "CGameEffect.hpp"
#include "CGameEffectApplierRemover.hpp"
#include "CItemPropertyApplierRemover.hpp"
#include "CNWItemProperty.hpp"
#include "CNWSCreature.hpp"
#include "CNWSItem.hpp"
#include "CNWSObject.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "CServerExoAppInternal.hpp"

namespace NWNXLib {

namespace API {

CServerAIMaster::CServerAIMaster()
{
    CServerAIMaster__CServerAIMasterCtor__0(this);
}

CServerAIMaster::~CServerAIMaster()
{
    CServerAIMaster__CServerAIMasterDtor__0(this);
}

int32_t CServerAIMaster::AddEventAbsoluteTime(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, void* a5)
{
    return CServerAIMaster__AddEventAbsoluteTime(this, a0, a1, a2, a3, a4, a5);
}

int32_t CServerAIMaster::AddEventAbsoluteTimeViaTail(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, void* a5)
{
    return CServerAIMaster__AddEventAbsoluteTimeViaTail(this, a0, a1, a2, a3, a4, a5);
}

int32_t CServerAIMaster::AddEventDeltaTime(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, void* a5)
{
    return CServerAIMaster__AddEventDeltaTime(this, a0, a1, a2, a3, a4, a5);
}

int32_t CServerAIMaster::AddObject(CNWSObject* a0, int32_t a1)
{
    return CServerAIMaster__AddObject(this, a0, a1);
}

void CServerAIMaster::AdjustTargetAndWitnessReputations(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CServerAIMaster__AdjustTargetAndWitnessReputations(this, a0, a1, a2);
}

void CServerAIMaster::AppendToScriptsRun(CExoString a0)
{
    return CServerAIMaster__AppendToScriptsRun(this, a0);
}

void CServerAIMaster::ClearEventQueue()
{
    return CServerAIMaster__ClearEventQueue(this);
}

void CServerAIMaster::ClearScriptsRun()
{
    return CServerAIMaster__ClearScriptsRun(this);
}

void CServerAIMaster::DeleteEventData(uint32_t a0, void* a1)
{
    return CServerAIMaster__DeleteEventData(this, a0, a1);
}

int32_t CServerAIMaster::EventPending(uint32_t a0, uint32_t a1)
{
    return CServerAIMaster__EventPending(this, a0, a1);
}

int32_t CServerAIMaster::GetPendingEvent(uint32_t* a0, uint32_t* a1, uint32_t* a2, uint32_t* a3, uint32_t* a4, void** a5)
{
    return CServerAIMaster__GetPendingEvent(this, a0, a1, a2, a3, a4, a5);
}

CExoString* CServerAIMaster::GetScriptsRun()
{
    return CServerAIMaster__GetScriptsRun(this);
}

int32_t CServerAIMaster::LoadEventQueue(CResGFF* a0, CResStruct* a1)
{
    return CServerAIMaster__LoadEventQueue(this, a0, a1);
}

void CServerAIMaster::LoadReputationAdjustments()
{
    return CServerAIMaster__LoadReputationAdjustments(this);
}

int32_t CServerAIMaster::OnEffectApplied(CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    return CServerAIMaster__OnEffectApplied(this, a0, a1, a2);
}

int32_t CServerAIMaster::OnEffectRemoved(CNWSObject* a0, CGameEffect* a1)
{
    return CServerAIMaster__OnEffectRemoved(this, a0, a1);
}

int32_t CServerAIMaster::OnItemPropertyApplied(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    return CServerAIMaster__OnItemPropertyApplied(this, a0, a1, a2, a3, a4);
}

int32_t CServerAIMaster::OnItemPropertyRemoved(CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    return CServerAIMaster__OnItemPropertyRemoved(this, a0, a1, a2, a3);
}

int32_t CServerAIMaster::RemoveObject(CNWSObject* a0)
{
    return CServerAIMaster__RemoveObject(this, a0);
}

int32_t CServerAIMaster::SaveEventQueue(CResGFF* a0, CResStruct* a1)
{
    return CServerAIMaster__SaveEventQueue(this, a0, a1);
}

int32_t CServerAIMaster::SetAILevel(CNWSObject* a0, int32_t a1)
{
    return CServerAIMaster__SetAILevel(this, a0, a1);
}

void CServerAIMaster::SetExoAppInternal(CServerExoAppInternal* a0)
{
    return CServerAIMaster__SetExoAppInternal(this, a0);
}

void CServerAIMaster::UpdateState()
{
    return CServerAIMaster__UpdateState(this);
}

void CServerAIMaster__CServerAIMasterCtor__0(CServerAIMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__CServerAIMasterCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CServerAIMaster__CServerAIMasterDtor__0(CServerAIMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__CServerAIMasterDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CServerAIMaster__AddEventAbsoluteTime(CServerAIMaster* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, void* a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__AddEventAbsoluteTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CServerAIMaster__AddEventAbsoluteTimeViaTail(CServerAIMaster* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, void* a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__AddEventAbsoluteTimeViaTail);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CServerAIMaster__AddEventDeltaTime(CServerAIMaster* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, void* a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__AddEventDeltaTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CServerAIMaster__AddObject(CServerAIMaster* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__AddObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerAIMaster__AdjustTargetAndWitnessReputations(CServerAIMaster* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__AdjustTargetAndWitnessReputations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CServerAIMaster__AppendToScriptsRun(CServerAIMaster* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__AppendToScriptsRun);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerAIMaster__ClearEventQueue(CServerAIMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__ClearEventQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerAIMaster__ClearScriptsRun(CServerAIMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__ClearScriptsRun);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CServerAIMaster__DeleteEventData(CServerAIMaster* thisPtr, uint32_t a0, void* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__DeleteEventData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerAIMaster__EventPending(CServerAIMaster* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__EventPending);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerAIMaster__GetPendingEvent(CServerAIMaster* thisPtr, uint32_t* a0, uint32_t* a1, uint32_t* a2, uint32_t* a3, uint32_t* a4, void** a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, void**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__GetPendingEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

CExoString* CServerAIMaster__GetScriptsRun(CServerAIMaster* thisPtr)
{
    using FuncPtrType = CExoString*(__attribute__((cdecl)) *)(CServerAIMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__GetScriptsRun);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerAIMaster__LoadEventQueue(CServerAIMaster* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__LoadEventQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerAIMaster__LoadReputationAdjustments(CServerAIMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__LoadReputationAdjustments);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CServerAIMaster__OnEffectApplied(CServerAIMaster* thisPtr, CNWSObject* a0, CGameEffect* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSObject*, CGameEffect*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__OnEffectApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CServerAIMaster__OnEffectRemoved(CServerAIMaster* thisPtr, CNWSObject* a0, CGameEffect* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSObject*, CGameEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__OnEffectRemoved);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerAIMaster__OnItemPropertyApplied(CServerAIMaster* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__OnItemPropertyApplied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CServerAIMaster__OnItemPropertyRemoved(CServerAIMaster* thisPtr, CNWSItem* a0, CNWItemProperty* a1, CNWSCreature* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__OnItemPropertyRemoved);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CServerAIMaster__RemoveObject(CServerAIMaster* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__RemoveObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CServerAIMaster__SaveEventQueue(CServerAIMaster* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__SaveEventQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerAIMaster__SetAILevel(CServerAIMaster* thisPtr, CNWSObject* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIMaster*, CNWSObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__SetAILevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerAIMaster__SetExoAppInternal(CServerAIMaster* thisPtr, CServerExoAppInternal* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*, CServerExoAppInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__SetExoAppInternal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CServerAIMaster__UpdateState(CServerAIMaster* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerAIMaster*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIMaster__UpdateState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
