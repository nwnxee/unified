#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CPathfindInfoIntraTileSuccessors
{
    float fXTransit;
    float fYTransit;
    float fNewX;
    float fNewY;
    float fNewDistance;
    int32_t nNewTriangle;

    // The below are auto generated stubs.
    CPathfindInfoIntraTileSuccessors(const CPathfindInfoIntraTileSuccessors&) = default;
    CPathfindInfoIntraTileSuccessors& operator=(const CPathfindInfoIntraTileSuccessors&) = default;

    CPathfindInfoIntraTileSuccessors();
};

void CPathfindInfoIntraTileSuccessors__CPathfindInfoIntraTileSuccessorsCtor__0(CPathfindInfoIntraTileSuccessors* thisPtr);

}

}
