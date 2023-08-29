#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSTransition)
#endif

class CNWSObject;
class CResGFF;
class CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


class CNWSTransition
{
public:
    CExoString m_sTransitionTarget;
    OBJECT_ID m_oidCachedTransitionTarget;

    CNWSObject * LookupTarget();
    void SetTarget(CNWSObject * const target);
    void SetTarget(const CExoString & target);
    void Unlink(BOOL unlinkBothEnds = false);
    void LoadFromGff(CResGFF * pRes, CResStruct * pStruct);
    void SaveToGff(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSTransition
    NWN_CLASS_EXTENSION_CNWSTransition
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSTransition)
#endif

