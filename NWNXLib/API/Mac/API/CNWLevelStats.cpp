#include "CNWLevelStats.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWLevelStats::CNWLevelStats()
{
    CNWLevelStats__CNWLevelStatsCtor__0(this);
}

CNWLevelStats::~CNWLevelStats()
{
    CNWLevelStats__CNWLevelStatsDtor__0(this);
}

void CNWLevelStats::AddFeat(uint16_t a0)
{
    return CNWLevelStats__AddFeat(this, a0);
}

void CNWLevelStats::ClearFeats()
{
    return CNWLevelStats__ClearFeats(this);
}

char CNWLevelStats::GetSkillRankChange(uint16_t a0)
{
    return CNWLevelStats__GetSkillRankChange(this, a0);
}

void CNWLevelStats::SetSkillRankChange(uint16_t a0, char a1)
{
    return CNWLevelStats__SetSkillRankChange(this, a0, a1);
}

void CNWLevelStats__CNWLevelStatsCtor__0(CNWLevelStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWLevelStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWLevelStats__CNWLevelStatsCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWLevelStats__CNWLevelStatsDtor__0(CNWLevelStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWLevelStats*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWLevelStats__CNWLevelStatsDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWLevelStats__AddFeat(CNWLevelStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWLevelStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWLevelStats__AddFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWLevelStats__ClearFeats(CNWLevelStats* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWLevelStats*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWLevelStats__ClearFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

char CNWLevelStats__GetSkillRankChange(CNWLevelStats* thisPtr, uint16_t a0)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CNWLevelStats*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWLevelStats__GetSkillRankChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWLevelStats__SetSkillRankChange(CNWLevelStats* thisPtr, uint16_t a0, char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWLevelStats*, uint16_t, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWLevelStats__SetSkillRankChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
