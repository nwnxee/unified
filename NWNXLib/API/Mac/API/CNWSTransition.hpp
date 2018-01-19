#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSObject;
struct CResGFF;
struct CResStruct;

struct CNWSTransition
{
    CExoString m_sTransitionTarget;
    uint32_t m_oidCachedTransitionTarget;

    void LoadFromGff(CResGFF*, CResStruct*);
    CNWSObject* LookupTarget();
    void SaveToGff(CResGFF*, CResStruct*);
    void SetTarget(const CExoString&);
    void SetTarget(CNWSObject*);
    void Unlink(int32_t);
};

void CNWSTransition__LoadFromGff(CNWSTransition* thisPtr, CResGFF*, CResStruct*);
CNWSObject* CNWSTransition__LookupTarget(CNWSTransition* thisPtr);
void CNWSTransition__SaveToGff(CNWSTransition* thisPtr, CResGFF*, CResStruct*);
void CNWSTransition__SetTarget__0(CNWSTransition* thisPtr, const CExoString&);
void CNWSTransition__SetTarget__1(CNWSTransition* thisPtr, CNWSObject*);
void CNWSTransition__Unlink(CNWSTransition* thisPtr, int32_t);

}

}
