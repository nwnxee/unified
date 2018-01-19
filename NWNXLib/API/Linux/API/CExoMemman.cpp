#include "CExoMemman.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoMemHeap.hpp"

namespace NWNXLib {

namespace API {

CExoMemman::~CExoMemman()
{
    CExoMemman__CExoMemmanDtor(this);
}

void CExoMemman::AddFreeRecord(uint32_t a0)
{
    return CExoMemman__AddFreeRecord(this, a0);
}

void* CExoMemman::Alloc(uint32_t a0, int32_t a1)
{
    return CExoMemman__Alloc(this, a0, a1);
}

void CExoMemman::CheckHeaps()
{
    return CExoMemman__CheckHeaps(this);
}

void CExoMemman::Clear()
{
    return CExoMemman__Clear(this);
}

void CExoMemman::Destroy()
{
    return CExoMemman__Destroy(this);
}

CExoMemHeapStats CExoMemman::DoHeapWalk()
{
    return CExoMemman__DoHeapWalk(this);
}

void CExoMemman::FillRecordPtrArray()
{
    return CExoMemman__FillRecordPtrArray(this);
}

void CExoMemman::FinalReport()
{
    return CExoMemman__FinalReport(this);
}

void CExoMemman::Free(void* a0)
{
    return CExoMemman__Free(this, a0);
}

uint32_t CExoMemman::GetFreeRecord()
{
    return CExoMemman__GetFreeRecord(this);
}

CExoMemHeap* CExoMemman::GetHeaps()
{
    return CExoMemman__GetHeaps(this);
}

void CExoMemman::OutputTypeTrackingReport()
{
    return CExoMemman__OutputTypeTrackingReport(this);
}

int32_t CExoMemman::PopType(uint32_t a0)
{
    return CExoMemman__PopType(this, a0);
}

int32_t CExoMemman::PushType(uint32_t a0)
{
    return CExoMemman__PushType(this, a0);
}

void CExoMemman::ReportEntry(CMemRecord& a0)
{
    return CExoMemman__ReportEntry(this, a0);
}

void CExoMemman::ReportRemoval(CMemRecord& a0, int32_t a1)
{
    return CExoMemman__ReportRemoval(this, a0, a1);
}

void CExoMemman::SnapShotReportPrint()
{
    return CExoMemman__SnapShotReportPrint(this);
}

void CExoMemman::SnapShotReportWithSort()
{
    return CExoMemman__SnapShotReportWithSort(this);
}

void CExoMemman::StartReport()
{
    return CExoMemman__StartReport(this);
}

void CExoMemman__CExoMemmanDtor(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__CExoMemmanDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CExoMemman__AddFreeRecord(CExoMemman* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__AddFreeRecord);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void* CExoMemman__Alloc(CExoMemman* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CExoMemman*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__Alloc);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoMemman__CheckHeaps(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__CheckHeaps);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__Clear(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__Clear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__Destroy(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__Destroy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoMemHeapStats CExoMemman__DoHeapWalk(CExoMemman* thisPtr)
{
    using FuncPtrType = CExoMemHeapStats(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__DoHeapWalk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__FillRecordPtrArray(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__FillRecordPtrArray);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__FinalReport(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__FinalReport);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__Free(CExoMemman* thisPtr, void* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__Free);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CExoMemman__GetFreeRecord(CExoMemman* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__GetFreeRecord);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoMemHeap* CExoMemman__GetHeaps(CExoMemman* thisPtr)
{
    using FuncPtrType = CExoMemHeap*(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__GetHeaps);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__OutputTypeTrackingReport(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__OutputTypeTrackingReport);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CExoMemman__PopType(CExoMemman* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoMemman*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__PopType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoMemman__PushType(CExoMemman* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoMemman*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__PushType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoMemman__ReportEntry(CExoMemman* thisPtr, CMemRecord& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*, CMemRecord&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__ReportEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoMemman__ReportRemoval(CExoMemman* thisPtr, CMemRecord& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*, CMemRecord&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__ReportRemoval);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CExoMemman__SnapShotReportPrint(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__SnapShotReportPrint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__SnapShotReportWithSort(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__SnapShotReportWithSort);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CExoMemman__StartReport(CExoMemman* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoMemman*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoMemman__StartReport);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
