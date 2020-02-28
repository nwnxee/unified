#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CWorldTimer)
#endif



typedef int BOOL;


struct CWorldTimer
{
    BOOL m_bFixedSnapshotRate;
    int32_t m_nFixedSnapshotsPerSecond;
    uint64_t m_nTimeSnapshot;
    uint64_t m_nLastTimeSnapshot;
    BOOL m_bPaused;
    uint32_t m_nPausedCalendarDay;
    uint32_t m_nPausedTimeOfDay;
    uint32_t m_nCalendarDayAdjustment;
    uint32_t m_nTimeOfDayAdjustment;
    uint8_t m_nMinutesPerHour;
    uint32_t m_nMillisecondsPerDay;
    uint32_t m_nSecondsPerDay;

    CWorldTimer();
    ~CWorldTimer();
    void SetSnapshotTime();
    uint64_t GetSnapshotTime();
    uint64_t GetSnapshotTimeDifference();
    uint32_t ConvertToCalendarDay(uint32_t nYear, uint32_t nMonth, uint32_t nDay);
    uint32_t ConvertToTimeOfDay(uint32_t nHour, uint32_t nMinute, uint32_t nSecond, uint32_t nMillisecond);
    void ConvertFromCalendarDay(uint32_t nCalendarDay, uint32_t * nYear, uint32_t * nMonth, uint32_t * nDay);
    void ConvertFromTimeOfDay(uint32_t nTimeOfDay, uint32_t * nHour, uint32_t * nMinute, uint32_t * nSecond, uint32_t * nMillisecond);
    void SetWorldTime(uint32_t nYear, uint32_t nMonth, uint32_t nDay, uint32_t nHour, uint32_t nMinute, uint32_t nSecond, uint32_t nMillisecond, BOOL bTakeSnapshot = false);
    void SetWorldTime(uint32_t nCalendarDay, uint32_t nTimeOfDay, BOOL bTakeSnapshot = false);
    uint32_t GetTimeDifferenceFromWorldTime(uint32_t nCalendarDay, uint32_t nTimeOfDay);
    uint64_t GetTimeDifference(uint32_t nCalendarDay1, uint32_t nTimeOfDay1, uint32_t nCalendarDay2, uint32_t nTimeOfDay2);
    void GetWorldTime(uint32_t * nCalendarDay, uint32_t * nTimeOfDay);
    uint32_t AddWorldTimes(uint32_t nCalendarDay1, uint32_t nTimeOfDay1, uint32_t nCalendarDay2, uint32_t nTimeOfDay2, uint32_t * nCalendarDayRes, uint32_t * nTimeOfDayRes);
    uint32_t SubtractWorldTimes(uint32_t nCalendarDay1, uint32_t nTimeOfDay1, uint32_t nCalendarDay2, uint32_t nTimeOfDay2, uint32_t * nCalendarDayRes, uint32_t * nTimeOfDayRes);
    int32_t CompareWorldTimes(uint32_t nCalendarDay1, uint32_t nTimeOfDay1, uint32_t nCalendarDay2, uint32_t nTimeOfDay2);
    void PauseWorldTimer();
    void UnpauseWorldTimer();
    uint32_t GetWorldTimeCalendarDay();
    CExoString GetWorldTimeCalendarDayString();
    uint32_t GetWorldTimeTimeOfDay();
    CExoString GetWorldTimeTimeOfDayString();
    CExoString TranslateWorldTimeToString(uint32_t nCalendarDay, uint32_t nTimeOfDay, CExoString & sTranslatedDayString, CExoString & sTranslatedMonthString);
    uint32_t GetWorldTimeYear();
    uint32_t GetWorldTimeMonth();
    uint32_t GetWorldTimeDay();
    uint32_t GetWorldTimeHour();
    uint32_t GetWorldTimeMinute();
    uint32_t GetWorldTimeSecond();
    uint32_t GetWorldTimeMillisecond();
    void SetFixedSnapshotRate(BOOL bActivate, int32_t nSnapshotsPerSecond);
    uint32_t GetCalendarDayFromSeconds(float fSeconds);
    uint32_t GetTimeOfDayFromSeconds(float fSeconds);
    void ResetTimer(CWorldTimer * pTimer);
    void SetMinutesPerHour(uint8_t nMinutesPerHour);
    void AdvanceToTime(int32_t nHour, int32_t nMinute, int32_t nSecond, int32_t nMillisecond);


#ifdef NWN_CLASS_EXTENSION_CWorldTimer
    NWN_CLASS_EXTENSION_CWorldTimer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CWorldTimer)
#endif

