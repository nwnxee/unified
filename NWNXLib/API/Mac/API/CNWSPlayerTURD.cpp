#include "CNWSPlayerTURD.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCGameEffectPtr.hpp"
#include "CExoArrayListTemplatedCNWSPersonalReputation.hpp"
#include "CExoArrayListTemplatedint.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayerTURD::CNWSPlayerTURD(uint32_t a0)
{
    CNWSPlayerTURD__CNWSPlayerTURDCtor__0(this, a0);
}

CNWSPlayerTURD::~CNWSPlayerTURD()
{
    CNWSPlayerTURD__CNWSPlayerTURDDtor__0(this);
}

void CNWSPlayerTURD::AddToArea(CNWSArea* a0, int32_t a1)
{
    return CNWSPlayerTURD__AddToArea(this, a0, a1);
}

void CNWSPlayerTURD::AIUpdate()
{
    return CNWSPlayerTURD__AIUpdate(this);
}

CNWSPlayerTURD* CNWSPlayerTURD::AsNWSPlayerTURD()
{
    return CNWSPlayerTURD__AsNWSPlayerTURD(this);
}

void CNWSPlayerTURD::ClearAutomapData()
{
    return CNWSPlayerTURD__ClearAutomapData(this);
}

void CNWSPlayerTURD::CopyAutomapData(int32_t a0, CExoArrayListTemplatedunsignedlong* a1, unsigned char** a2)
{
    return CNWSPlayerTURD__CopyAutomapData(this, a0, a1, a2);
}

void CNWSPlayerTURD::CopyEffectList(CExoArrayListTemplatedCGameEffectPtr* a0)
{
    return CNWSPlayerTURD__CopyEffectList(this, a0);
}

void CNWSPlayerTURD::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSPlayerTURD__EventHandler(this, a0, a1, a2, a3, a4);
}

CExoLocString& CNWSPlayerTURD::GetFirstName()
{
    return CNWSPlayerTURD__GetFirstName(this);
}

CExoLocString& CNWSPlayerTURD::GetLastName()
{
    return CNWSPlayerTURD__GetLastName(this);
}

void CNWSPlayerTURD::LoadAutoMapData(CResGFF* a0, CResStruct* a1)
{
    return CNWSPlayerTURD__LoadAutoMapData(this, a0, a1);
}

int32_t CNWSPlayerTURD::LoadTURD(CResGFF* a0, CResStruct* a1)
{
    return CNWSPlayerTURD__LoadTURD(this, a0, a1);
}

void CNWSPlayerTURD::RemoveFromArea()
{
    return CNWSPlayerTURD__RemoveFromArea(this);
}

void CNWSPlayerTURD::SaveAutoMapData(CResGFF* a0, CResStruct* a1)
{
    return CNWSPlayerTURD__SaveAutoMapData(this, a0, a1);
}

void CNWSPlayerTURD::SaveTURD(CResGFF* a0, CResStruct* a1)
{
    return CNWSPlayerTURD__SaveTURD(this, a0, a1);
}

void CNWSPlayerTURD::SetPersonalReputation(CExoArrayListTemplatedCNWSPersonalReputation* a0)
{
    return CNWSPlayerTURD__SetPersonalReputation(this, a0);
}

void CNWSPlayerTURD::SetReputation(CExoArrayListTemplatedint* a0)
{
    return CNWSPlayerTURD__SetReputation(this, a0);
}

void CNWSPlayerTURD__CNWSPlayerTURDCtor__0(CNWSPlayerTURD* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__CNWSPlayerTURDCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSPlayerTURD__CNWSPlayerTURDDtor__0(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__CNWSPlayerTURDDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSPlayerTURD__AddToArea(CNWSPlayerTURD* thisPtr, CNWSArea* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CNWSArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerTURD__AIUpdate(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlayerTURD* CNWSPlayerTURD__AsNWSPlayerTURD(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = CNWSPlayerTURD*(__attribute__((cdecl)) *)(CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__AsNWSPlayerTURD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerTURD__ClearAutomapData(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__ClearAutomapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerTURD__CopyAutomapData(CNWSPlayerTURD* thisPtr, int32_t a0, CExoArrayListTemplatedunsignedlong* a1, unsigned char** a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, int32_t, CExoArrayListTemplatedunsignedlong*, unsigned char**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__CopyAutomapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSPlayerTURD__CopyEffectList(CNWSPlayerTURD* thisPtr, CExoArrayListTemplatedCGameEffectPtr* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CExoArrayListTemplatedCGameEffectPtr*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__CopyEffectList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerTURD__EventHandler(CNWSPlayerTURD* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

CExoLocString& CNWSPlayerTURD__GetFirstName(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSPlayerTURD__GetLastName(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__GetLastName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerTURD__LoadAutoMapData(CNWSPlayerTURD* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__LoadAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSPlayerTURD__LoadTURD(CNWSPlayerTURD* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__LoadTURD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerTURD__RemoveFromArea(CNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerTURD__SaveAutoMapData(CNWSPlayerTURD* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__SaveAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerTURD__SaveTURD(CNWSPlayerTURD* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__SaveTURD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerTURD__SetPersonalReputation(CNWSPlayerTURD* thisPtr, CExoArrayListTemplatedCNWSPersonalReputation* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CExoArrayListTemplatedCNWSPersonalReputation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__SetPersonalReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerTURD__SetReputation(CNWSPlayerTURD* thisPtr, CExoArrayListTemplatedint* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerTURD*, CExoArrayListTemplatedint*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerTURD__SetReputation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
