#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CWalkHitInfo)
#endif





class CWalkHitInfo
{
    int32_t m_nFailureReason;
    Vector m_vIntersectedAt;
    Vector m_vNormalOfIntersectedLine;
    Vector m_vVertex1;
    Vector m_vVertex2;
    int32_t m_nIntersectionType;



#ifdef NWN_CLASS_EXTENSION_CWalkHitInfo
    NWN_CLASS_EXTENSION_CWalkHitInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CWalkHitInfo)
#endif

