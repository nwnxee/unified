#pragma once

#include <cstdint>

#include "CExoMemHeapStats.hpp"
#include "CMemRecord.hpp"
#include "unknown__IO_FILE.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoMemHeap;

struct CExoMemman
{
    uint32_t m_iMemUsed;
    uint32_t m_iTrueMemUsed;
    uint32_t m_iMaxMemUsed;
    CMemRecord m_pRecords[400000];
    CMemRecord* m_ppRecords[400000];
    int32_t m_iUsedRecordCount;
    uint32_t m_pMemTypeTrackingData[256];
    uint8_t m_pMemTypeTrackingStack[1024];
    uint32_t m_nMemTypeTrackingTop;
    uint32_t m_piFreeRecordIndexes[400000];
    int32_t m_iFreeRecordIndex;
    int32_t m_bLogAll;
    _IO_FILE* fp;

    // The below are auto generated stubs.
    CExoMemman() = default;
    CExoMemman(const CExoMemman&) = default;
    CExoMemman& operator=(const CExoMemman&) = default;

    ~CExoMemman();
    void AddFreeRecord(uint32_t);
    void* Alloc(uint32_t, int32_t);
    void CheckHeaps();
    void Clear();
    void Destroy();
    CExoMemHeapStats DoHeapWalk();
    void FillRecordPtrArray();
    void FinalReport();
    void Free(void*);
    uint32_t GetFreeRecord();
    CExoMemHeap* GetHeaps();
    void OutputTypeTrackingReport();
    int32_t PopType(uint32_t);
    int32_t PushType(uint32_t);
    void ReportEntry(CMemRecord&);
    void ReportRemoval(CMemRecord&, int32_t);
    void SnapShotReportPrint();
    void SnapShotReportWithSort();
    void StartReport();
};

void CExoMemman__CExoMemmanDtor(CExoMemman* thisPtr);
void CExoMemman__AddFreeRecord(CExoMemman* thisPtr, uint32_t);
void* CExoMemman__Alloc(CExoMemman* thisPtr, uint32_t, int32_t);
void CExoMemman__CheckHeaps(CExoMemman* thisPtr);
void CExoMemman__Clear(CExoMemman* thisPtr);
void CExoMemman__Destroy(CExoMemman* thisPtr);
CExoMemHeapStats CExoMemman__DoHeapWalk(CExoMemman* thisPtr);
void CExoMemman__FillRecordPtrArray(CExoMemman* thisPtr);
void CExoMemman__FinalReport(CExoMemman* thisPtr);
void CExoMemman__Free(CExoMemman* thisPtr, void*);
uint32_t CExoMemman__GetFreeRecord(CExoMemman* thisPtr);
CExoMemHeap* CExoMemman__GetHeaps(CExoMemman* thisPtr);
void CExoMemman__OutputTypeTrackingReport(CExoMemman* thisPtr);
int32_t CExoMemman__PopType(CExoMemman* thisPtr, uint32_t);
int32_t CExoMemman__PushType(CExoMemman* thisPtr, uint32_t);
void CExoMemman__ReportEntry(CExoMemman* thisPtr, CMemRecord&);
void CExoMemman__ReportRemoval(CExoMemman* thisPtr, CMemRecord&, int32_t);
void CExoMemman__SnapShotReportPrint(CExoMemman* thisPtr);
void CExoMemman__SnapShotReportWithSort(CExoMemman* thisPtr);
void CExoMemman__StartReport(CExoMemman* thisPtr);

}

}
