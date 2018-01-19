#include "CScriptTalent.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CScriptTalent::CScriptTalent()
{
    CScriptTalent__CScriptTalentCtor(this);
}

CScriptTalent::~CScriptTalent()
{
    CScriptTalent__CScriptTalentDtor(this);
}

void CScriptTalent::CopyScriptTalent(CScriptTalent* a0)
{
    return CScriptTalent__CopyScriptTalent(this, a0);
}

int32_t CScriptTalent::Equals(CScriptTalent* a0)
{
    return CScriptTalent__Equals(this, a0);
}

int32_t CScriptTalent::LoadTalent(CResGFF* a0, CResStruct* a1)
{
    return CScriptTalent__LoadTalent(this, a0, a1);
}

int32_t CScriptTalent::SaveTalent(CResGFF* a0, CResStruct* a1)
{
    return CScriptTalent__SaveTalent(this, a0, a1);
}

void CScriptTalent__CScriptTalentCtor(CScriptTalent* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptTalent*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptTalent__CScriptTalentCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CScriptTalent__CScriptTalentDtor(CScriptTalent* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptTalent*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptTalent__CScriptTalentDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CScriptTalent__CopyScriptTalent(CScriptTalent* thisPtr, CScriptTalent* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptTalent*, CScriptTalent*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptTalent__CopyScriptTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptTalent__Equals(CScriptTalent* thisPtr, CScriptTalent* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptTalent*, CScriptTalent*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptTalent__Equals);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptTalent__LoadTalent(CScriptTalent* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptTalent*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptTalent__LoadTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptTalent__SaveTalent(CScriptTalent* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptTalent*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptTalent__SaveTalent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
