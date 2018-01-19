#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CWorldTimer
{
    int32_t m_bFixedSnapshotRate;
    int32_t m_nFixedSnapshotsPerSecond;
    uint64_t m_nTimeSnapshot;
    uint64_t m_nLastTimeSnapshot;
    int32_t m_bPaused;
    uint32_t m_nPausedCalendarDay;
    uint32_t m_nPausedTimeOfDay;
    uint32_t m_nCalendarDayAdjustment;
    uint32_t m_nTimeOfDayAdjustment;
    uint8_t m_nMinutesPerHour;
    uint32_t m_nMillisecondsPerDay;
    uint32_t m_nSecondsPerDay;

    // The below are auto generated stubs.
    CWorldTimer(const CWorldTimer&) = default;
    CWorldTimer& operator=(const CWorldTimer&) = default;

    CWorldTimer();
    ~CWorldTimer();
    uint32_t AddWorldTimes(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t*);
    void AdvanceToTime(int32_t, int32_t, int32_t, int32_t);
    int32_t CompareWorldTimes(uint32_t, uint32_t, uint32_t, uint32_t);
    void ConvertFromCalendarDay(uint32_t, uint32_t*, uint32_t*, uint32_t*);
    void ConvertFromTimeOfDay(uint32_t, uint32_t*, uint32_t*, uint32_t*, uint32_t*);
    uint32_t ConvertToCalendarDay(uint32_t, uint32_t, uint32_t);
    uint32_t ConvertToTimeOfDay(uint32_t, uint32_t, uint32_t, uint32_t);
    uint32_t GetCalendarDayFromSeconds(float);
    uint64_t GetSnapshotTime();
    uint64_t GetSnapshotTimeDifference();
    uint32_t GetTimeDifferenceFromWorldTime(uint32_t, uint32_t);
    uint32_t GetTimeOfDayFromSeconds(float);
    void GetWorldTime(uint32_t*, uint32_t*);
    uint32_t GetWorldTimeCalendarDay();
    CExoString GetWorldTimeCalendarDayString();
    uint32_t GetWorldTimeDay();
    uint32_t GetWorldTimeHour();
    uint32_t GetWorldTimeMillisecond();
    uint32_t GetWorldTimeMinute();
    uint32_t GetWorldTimeMonth();
    uint32_t GetWorldTimeSecond();
    uint32_t GetWorldTimeTimeOfDay();
    CExoString GetWorldTimeTimeOfDayString();
    uint32_t GetWorldTimeYear();
    void PauseWorldTimer();
    void ResetTimer(CWorldTimer*);
    void SetFixedSnapshotRate(int32_t, int32_t);
    void SetMinutesPerHour(unsigned char);
    void SetSnapshotTime();
    void SetWorldTime(uint32_t, uint32_t, int32_t);
    void SetWorldTime(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
    uint32_t SubtractWorldTimes(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t*);
    CExoString TranslateWorldTimeToString(uint32_t, uint32_t, CExoString&, CExoString&);
    void UnpauseWorldTimer();
};

void CWorldTimer__CWorldTimerCtor__0(CWorldTimer* thisPtr);
void CWorldTimer__CWorldTimerDtor__0(CWorldTimer* thisPtr);
uint32_t CWorldTimer__AddWorldTimes(CWorldTimer* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t*);
void CWorldTimer__AdvanceToTime(CWorldTimer* thisPtr, int32_t, int32_t, int32_t, int32_t);
int32_t CWorldTimer__CompareWorldTimes(CWorldTimer* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t);
void CWorldTimer__ConvertFromCalendarDay(CWorldTimer* thisPtr, uint32_t, uint32_t*, uint32_t*, uint32_t*);
void CWorldTimer__ConvertFromTimeOfDay(CWorldTimer* thisPtr, uint32_t, uint32_t*, uint32_t*, uint32_t*, uint32_t*);
uint32_t CWorldTimer__ConvertToCalendarDay(CWorldTimer* thisPtr, uint32_t, uint32_t, uint32_t);
uint32_t CWorldTimer__ConvertToTimeOfDay(CWorldTimer* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t);
uint32_t CWorldTimer__GetCalendarDayFromSeconds(CWorldTimer* thisPtr, float);
uint64_t CWorldTimer__GetSnapshotTime(CWorldTimer* thisPtr);
uint64_t CWorldTimer__GetSnapshotTimeDifference(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetTimeDifferenceFromWorldTime(CWorldTimer* thisPtr, uint32_t, uint32_t);
uint32_t CWorldTimer__GetTimeOfDayFromSeconds(CWorldTimer* thisPtr, float);
void CWorldTimer__GetWorldTime(CWorldTimer* thisPtr, uint32_t*, uint32_t*);
uint32_t CWorldTimer__GetWorldTimeCalendarDay(CWorldTimer* thisPtr);
CExoString CWorldTimer__GetWorldTimeCalendarDayString(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeDay(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeHour(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeMillisecond(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeMinute(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeMonth(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeSecond(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeTimeOfDay(CWorldTimer* thisPtr);
CExoString CWorldTimer__GetWorldTimeTimeOfDayString(CWorldTimer* thisPtr);
uint32_t CWorldTimer__GetWorldTimeYear(CWorldTimer* thisPtr);
void CWorldTimer__PauseWorldTimer(CWorldTimer* thisPtr);
void CWorldTimer__ResetTimer(CWorldTimer* thisPtr, CWorldTimer*);
void CWorldTimer__SetFixedSnapshotRate(CWorldTimer* thisPtr, int32_t, int32_t);
void CWorldTimer__SetMinutesPerHour(CWorldTimer* thisPtr, unsigned char);
void CWorldTimer__SetSnapshotTime(CWorldTimer* thisPtr);
void CWorldTimer__SetWorldTime__0(CWorldTimer* thisPtr, uint32_t, uint32_t, int32_t);
void CWorldTimer__SetWorldTime__1(CWorldTimer* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, int32_t);
uint32_t CWorldTimer__SubtractWorldTimes(CWorldTimer* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t*, uint32_t*);
CExoString CWorldTimer__TranslateWorldTimeToString(CWorldTimer* thisPtr, uint32_t, uint32_t, CExoString&, CExoString&);
void CWorldTimer__UnpauseWorldTimer(CWorldTimer* thisPtr);

}

}
