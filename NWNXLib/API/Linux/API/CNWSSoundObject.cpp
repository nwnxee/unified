#include "CNWSSoundObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSArea.hpp"
#include "CNWSMessage.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSSoundObject::CNWSSoundObject(uint32_t a0)
{
    CNWSSoundObject__CNWSSoundObjectCtor(this, a0);
}

CNWSSoundObject::~CNWSSoundObject()
{
    CNWSSoundObject__CNWSSoundObjectDtor__0(this);
}

void CNWSSoundObject::AddToArea(CNWSArea* a0, int32_t a1)
{
    return CNWSSoundObject__AddToArea(this, a0, a1);
}

void CNWSSoundObject::AIUpdate()
{
    return CNWSSoundObject__AIUpdate(this);
}

CNWSSoundObject* CNWSSoundObject::AsNWSSoundObject()
{
    return CNWSSoundObject__AsNWSSoundObject(this);
}

void CNWSSoundObject::ChangePosition(Vector a0)
{
    return CNWSSoundObject__ChangePosition(this, a0);
}

void CNWSSoundObject::ChangeVolume(int32_t a0)
{
    return CNWSSoundObject__ChangeVolume(this, a0);
}

void CNWSSoundObject::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSSoundObject__EventHandler(this, a0, a1, a2, a3, a4);
}

CExoArrayListTemplatedunsignedlong CNWSSoundObject::GetPeopleInSoundRange()
{
    return CNWSSoundObject__GetPeopleInSoundRange(this);
}

int32_t CNWSSoundObject::Load(CResGFF* a0, CResStruct* a1)
{
    return CNWSSoundObject__Load(this, a0, a1);
}

void CNWSSoundObject::PackIntoMessage(CNWSMessage* a0)
{
    return CNWSSoundObject__PackIntoMessage(this, a0);
}

void CNWSSoundObject::Play()
{
    return CNWSSoundObject__Play(this);
}

void CNWSSoundObject::RemoveFromArea()
{
    return CNWSSoundObject__RemoveFromArea(this);
}

void CNWSSoundObject::Save(CResGFF* a0, CResStruct* a1)
{
    return CNWSSoundObject__Save(this, a0, a1);
}

void CNWSSoundObject::Stop()
{
    return CNWSSoundObject__Stop(this);
}

void CNWSSoundObject__CNWSSoundObjectCtor(CNWSSoundObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__CNWSSoundObjectCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSSoundObject__CNWSSoundObjectDtor__0(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__CNWSSoundObjectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSSoundObject__AddToArea(CNWSSoundObject* thisPtr, CNWSArea* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, CNWSArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSSoundObject__AIUpdate(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSSoundObject* CNWSSoundObject__AsNWSSoundObject(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = CNWSSoundObject*(__attribute__((cdecl)) *)(CNWSSoundObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__AsNWSSoundObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSSoundObject__ChangePosition(CNWSSoundObject* thisPtr, Vector a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__ChangePosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSSoundObject__ChangeVolume(CNWSSoundObject* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__ChangeVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSSoundObject__EventHandler(CNWSSoundObject* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

CExoArrayListTemplatedunsignedlong CNWSSoundObject__GetPeopleInSoundRange(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = CExoArrayListTemplatedunsignedlong(__attribute__((cdecl)) *)(CNWSSoundObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__GetPeopleInSoundRange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSSoundObject__Load(CNWSSoundObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSSoundObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__Load);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSSoundObject__PackIntoMessage(CNWSSoundObject* thisPtr, CNWSMessage* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, CNWSMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__PackIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSSoundObject__Play(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__Play);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSSoundObject__RemoveFromArea(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSSoundObject__Save(CNWSSoundObject* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__Save);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSSoundObject__Stop(CNWSSoundObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSSoundObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSoundObject__Stop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
