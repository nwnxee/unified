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
    CPathfindInfoIntraTileSuccessors(const CPathfindInfoIntraTileSuccessors&);
    CPathfindInfoIntraTileSuccessors& operator=(const CPathfindInfoIntraTileSuccessors&);

    CPathfindInfoIntraTileSuccessors();
};

void CPathfindInfoIntraTileSuccessors__CPathfindInfoIntraTileSuccessorsCtor(CPathfindInfoIntraTileSuccessors* thisPtr);

}

}
