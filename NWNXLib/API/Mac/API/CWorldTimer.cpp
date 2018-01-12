#include "CWorldTimer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CWorldTimer::CWorldTimer()
{
    CWorldTimer__CWorldTimerCtor__0(this);
}

CWorldTimer::~CWorldTimer()
{
    CWorldTimer__CWorldTimerDtor__0(this);
}

uint32_t CWorldTimer::AddWorldTimes(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t* a4, uint32_t* a5)
{
    return CWorldTimer__AddWorldTimes(this, a0, a1, a2, a3, a4, a5);
}

void CWorldTimer::AdvanceToTime(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CWorldTimer__AdvanceToTime(this, a0, a1, a2, a3);
}

int32_t CWorldTimer::CompareWorldTimes(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CWorldTimer__CompareWorldTimes(this, a0, a1, a2, a3);
}

void CWorldTimer::ConvertFromCalendarDay(uint32_t a0, uint32_t* a1, uint32_t* a2, uint32_t* a3)
{
    return CWorldTimer__ConvertFromCalendarDay(this, a0, a1, a2, a3);
}

void CWorldTimer::ConvertFromTimeOfDay(uint32_t a0, uint32_t* a1, uint32_t* a2, uint32_t* a3, uint32_t* a4)
{
    return CWorldTimer__ConvertFromTimeOfDay(this, a0, a1, a2, a3, a4);
}

uint32_t CWorldTimer::ConvertToCalendarDay(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CWorldTimer__ConvertToCalendarDay(this, a0, a1, a2);
}

uint32_t CWorldTimer::ConvertToTimeOfDay(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CWorldTimer__ConvertToTimeOfDay(this, a0, a1, a2, a3);
}

uint32_t CWorldTimer::GetCalendarDayFromSeconds(float a0)
{
    return CWorldTimer__GetCalendarDayFromSeconds(this, a0);
}

uint64_t CWorldTimer::GetSnapshotTime()
{
    return CWorldTimer__GetSnapshotTime(this);
}

uint64_t CWorldTimer::GetSnapshotTimeDifference()
{
    return CWorldTimer__GetSnapshotTimeDifference(this);
}

uint32_t CWorldTimer::GetTimeDifferenceFromWorldTime(uint32_t a0, uint32_t a1)
{
    return CWorldTimer__GetTimeDifferenceFromWorldTime(this, a0, a1);
}

uint32_t CWorldTimer::GetTimeOfDayFromSeconds(float a0)
{
    return CWorldTimer__GetTimeOfDayFromSeconds(this, a0);
}

void CWorldTimer::GetWorldTime(uint32_t* a0, uint32_t* a1)
{
    return CWorldTimer__GetWorldTime(this, a0, a1);
}

uint32_t CWorldTimer::GetWorldTimeCalendarDay()
{
    return CWorldTimer__GetWorldTimeCalendarDay(this);
}

CExoString CWorldTimer::GetWorldTimeCalendarDayString()
{
    return CWorldTimer__GetWorldTimeCalendarDayString(this);
}

uint32_t CWorldTimer::GetWorldTimeDay()
{
    return CWorldTimer__GetWorldTimeDay(this);
}

uint32_t CWorldTimer::GetWorldTimeHour()
{
    return CWorldTimer__GetWorldTimeHour(this);
}

uint32_t CWorldTimer::GetWorldTimeMillisecond()
{
    return CWorldTimer__GetWorldTimeMillisecond(this);
}

uint32_t CWorldTimer::GetWorldTimeMinute()
{
    return CWorldTimer__GetWorldTimeMinute(this);
}

uint32_t CWorldTimer::GetWorldTimeMonth()
{
    return CWorldTimer__GetWorldTimeMonth(this);
}

uint32_t CWorldTimer::GetWorldTimeSecond()
{
    return CWorldTimer__GetWorldTimeSecond(this);
}

uint32_t CWorldTimer::GetWorldTimeTimeOfDay()
{
    return CWorldTimer__GetWorldTimeTimeOfDay(this);
}

CExoString CWorldTimer::GetWorldTimeTimeOfDayString()
{
    return CWorldTimer__GetWorldTimeTimeOfDayString(this);
}

uint32_t CWorldTimer::GetWorldTimeYear()
{
    return CWorldTimer__GetWorldTimeYear(this);
}

void CWorldTimer::PauseWorldTimer()
{
    return CWorldTimer__PauseWorldTimer(this);
}

void CWorldTimer::ResetTimer(CWorldTimer* a0)
{
    return CWorldTimer__ResetTimer(this, a0);
}

void CWorldTimer::SetFixedSnapshotRate(int32_t a0, int32_t a1)
{
    return CWorldTimer__SetFixedSnapshotRate(this, a0, a1);
}

void CWorldTimer::SetMinutesPerHour(unsigned char a0)
{
    return CWorldTimer__SetMinutesPerHour(this, a0);
}

void CWorldTimer::SetSnapshotTime()
{
    return CWorldTimer__SetSnapshotTime(this);
}

void CWorldTimer::SetWorldTime(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CWorldTimer__SetWorldTime__0(this, a0, a1, a2);
}

void CWorldTimer::SetWorldTime(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, int32_t a7)
{
    return CWorldTimer__SetWorldTime__1(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

uint32_t CWorldTimer::SubtractWorldTimes(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t* a4, uint32_t* a5)
{
    return CWorldTimer__SubtractWorldTimes(this, a0, a1, a2, a3, a4, a5);
}

CExoString CWorldTimer::TranslateWorldTimeToString(uint32_t a0, uint32_t a1, CExoString& a2, CExoString& a3)
{
    return CWorldTimer__TranslateWorldTimeToString(this, a0, a1, a2, a3);
}

void CWorldTimer::UnpauseWorldTimer()
{
    return CWorldTimer__UnpauseWorldTimer(this);
}

void CWorldTimer__CWorldTimerCtor__0(CWorldTimer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__CWorldTimerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CWorldTimer__CWorldTimerDtor__0(CWorldTimer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__CWorldTimerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

uint32_t CWorldTimer__AddWorldTimes(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t* a4, uint32_t* a5)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__AddWorldTimes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CWorldTimer__AdvanceToTime(CWorldTimer* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__AdvanceToTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CWorldTimer__CompareWorldTimes(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__CompareWorldTimes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CWorldTimer__ConvertFromCalendarDay(CWorldTimer* thisPtr, uint32_t a0, uint32_t* a1, uint32_t* a2, uint32_t* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t*, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__ConvertFromCalendarDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CWorldTimer__ConvertFromTimeOfDay(CWorldTimer* thisPtr, uint32_t a0, uint32_t* a1, uint32_t* a2, uint32_t* a3, uint32_t* a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t*, uint32_t*, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__ConvertFromTimeOfDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CWorldTimer__ConvertToCalendarDay(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__ConvertToCalendarDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CWorldTimer__ConvertToTimeOfDay(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__ConvertToTimeOfDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint32_t CWorldTimer__GetCalendarDayFromSeconds(CWorldTimer* thisPtr, float a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetCalendarDayFromSeconds);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint64_t CWorldTimer__GetSnapshotTime(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetSnapshotTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint64_t CWorldTimer__GetSnapshotTimeDifference(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetSnapshotTimeDifference);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetTimeDifferenceFromWorldTime(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetTimeDifferenceFromWorldTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CWorldTimer__GetTimeOfDayFromSeconds(CWorldTimer* thisPtr, float a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetTimeOfDayFromSeconds);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CWorldTimer__GetWorldTime(CWorldTimer* thisPtr, uint32_t* a0, uint32_t* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CWorldTimer__GetWorldTimeCalendarDay(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeCalendarDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CWorldTimer__GetWorldTimeCalendarDayString(CWorldTimer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeCalendarDayString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeDay(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeHour(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeHour);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeMillisecond(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeMillisecond);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeMinute(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeMinute);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeMonth(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeMonth);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeSecond(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeSecond);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeTimeOfDay(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeTimeOfDay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CWorldTimer__GetWorldTimeTimeOfDayString(CWorldTimer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeTimeOfDayString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CWorldTimer__GetWorldTimeYear(CWorldTimer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__GetWorldTimeYear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CWorldTimer__PauseWorldTimer(CWorldTimer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__PauseWorldTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CWorldTimer__ResetTimer(CWorldTimer* thisPtr, CWorldTimer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__ResetTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CWorldTimer__SetFixedSnapshotRate(CWorldTimer* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__SetFixedSnapshotRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CWorldTimer__SetMinutesPerHour(CWorldTimer* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__SetMinutesPerHour);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CWorldTimer__SetSnapshotTime(CWorldTimer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__SetSnapshotTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CWorldTimer__SetWorldTime__0(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__SetWorldTime__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CWorldTimer__SetWorldTime__1(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, uint32_t a6, int32_t a7)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__SetWorldTime__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

uint32_t CWorldTimer__SubtractWorldTimes(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t* a4, uint32_t* a5)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__SubtractWorldTimes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

CExoString CWorldTimer__TranslateWorldTimeToString(CWorldTimer* thisPtr, uint32_t a0, uint32_t a1, CExoString& a2, CExoString& a3)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CWorldTimer*, uint32_t, uint32_t, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__TranslateWorldTimeToString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CWorldTimer__UnpauseWorldTimer(CWorldTimer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CWorldTimer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CWorldTimer__UnpauseWorldTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
