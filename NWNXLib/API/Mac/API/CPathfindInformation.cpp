#include "CPathfindInformation.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CPathfindInfoIntraTileSuccessors.hpp"

namespace NWNXLib {

namespace API {

CPathfindInformation::CPathfindInformation()
{
    CPathfindInformation__CPathfindInformationCtor__0(this);
}

CPathfindInformation::~CPathfindInformation()
{
    CPathfindInformation__CPathfindInformationDtor__0(this);
}

void CPathfindInformation::ComputeStepTolerance()
{
    return CPathfindInformation__ComputeStepTolerance(this);
}

void CPathfindInformation::CreateFirstTileFValueAlternatives(int32_t a0)
{
    return CPathfindInformation__CreateFirstTileFValueAlternatives(this, a0);
}

void CPathfindInformation::DeleteFirstTileFValueAlternatives()
{
    return CPathfindInformation__DeleteFirstTileFValueAlternatives(this);
}

void CPathfindInformation::FlipStartEndPoints()
{
    return CPathfindInformation__FlipStartEndPoints(this);
}

void CPathfindInformation::FlipTempEndPoints()
{
    return CPathfindInformation__FlipTempEndPoints(this);
}

void CPathfindInformation::GetFirstTileFValueAlternatives(int32_t a0, int32_t* a1, int32_t* a2, CPathfindInfoIntraTileSuccessors** a3)
{
    return CPathfindInformation__GetFirstTileFValueAlternatives(this, a0, a1, a2, a3);
}

void CPathfindInformation::Initialize()
{
    return CPathfindInformation__Initialize(this);
}

void CPathfindInformation::ResetAtEndOfPath()
{
    return CPathfindInformation__ResetAtEndOfPath(this);
}

void CPathfindInformation::ResetGridSearchData()
{
    return CPathfindInformation__ResetGridSearchData(this);
}

void CPathfindInformation::ResetInterAreaPathSearchData()
{
    return CPathfindInformation__ResetInterAreaPathSearchData(this);
}

void CPathfindInformation::ResetInterAreaSearchData()
{
    return CPathfindInformation__ResetInterAreaSearchData(this);
}

void CPathfindInformation::ResetInterTileSearchData()
{
    return CPathfindInformation__ResetInterTileSearchData(this);
}

void CPathfindInformation::ResetIntraTileSearchData()
{
    return CPathfindInformation__ResetIntraTileSearchData(this);
}

void CPathfindInformation::ResetWayPointData()
{
    return CPathfindInformation__ResetWayPointData(this);
}

void CPathfindInformation::SetFirstTileFValueAlternatives(int32_t a0, int32_t a1, int32_t a2, CPathfindInfoIntraTileSuccessors* a3)
{
    return CPathfindInformation__SetFirstTileFValueAlternatives(this, a0, a1, a2, a3);
}

void CPathfindInformation::Shutdown()
{
    return CPathfindInformation__Shutdown(this);
}

void CPathfindInformation__CPathfindInformationCtor__0(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__CPathfindInformationCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CPathfindInformation__CPathfindInformationDtor__0(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__CPathfindInformationDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CPathfindInformation__ComputeStepTolerance(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ComputeStepTolerance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__CreateFirstTileFValueAlternatives(CPathfindInformation* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__CreateFirstTileFValueAlternatives);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CPathfindInformation__DeleteFirstTileFValueAlternatives(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__DeleteFirstTileFValueAlternatives);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__FlipStartEndPoints(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__FlipStartEndPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__FlipTempEndPoints(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__FlipTempEndPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__GetFirstTileFValueAlternatives(CPathfindInformation* thisPtr, int32_t a0, int32_t* a1, int32_t* a2, CPathfindInfoIntraTileSuccessors** a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*, int32_t, int32_t*, int32_t*, CPathfindInfoIntraTileSuccessors**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__GetFirstTileFValueAlternatives);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CPathfindInformation__Initialize(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__Initialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetAtEndOfPath(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetAtEndOfPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetGridSearchData(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetGridSearchData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetInterAreaPathSearchData(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetInterAreaPathSearchData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetInterAreaSearchData(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetInterAreaSearchData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetInterTileSearchData(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetInterTileSearchData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetIntraTileSearchData(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetIntraTileSearchData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__ResetWayPointData(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__ResetWayPointData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CPathfindInformation__SetFirstTileFValueAlternatives(CPathfindInformation* thisPtr, int32_t a0, int32_t a1, int32_t a2, CPathfindInfoIntraTileSuccessors* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*, int32_t, int32_t, int32_t, CPathfindInfoIntraTileSuccessors*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__SetFirstTileFValueAlternatives);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CPathfindInformation__Shutdown(CPathfindInformation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInformation__Shutdown);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
