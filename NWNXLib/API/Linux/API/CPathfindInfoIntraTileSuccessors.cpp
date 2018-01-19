#include "CPathfindInfoIntraTileSuccessors.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CPathfindInfoIntraTileSuccessors::CPathfindInfoIntraTileSuccessors()
{
    CPathfindInfoIntraTileSuccessors__CPathfindInfoIntraTileSuccessorsCtor(this);
}

void CPathfindInfoIntraTileSuccessors__CPathfindInfoIntraTileSuccessorsCtor(CPathfindInfoIntraTileSuccessors* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CPathfindInfoIntraTileSuccessors*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CPathfindInfoIntraTileSuccessors__CPathfindInfoIntraTileSuccessorsCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
