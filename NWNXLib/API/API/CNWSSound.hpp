#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSSound)
#endif

struct CResGFF;
struct CResStruct;


typedef int BOOL;


struct CNWSSound
{
    float m_fX;
    float m_fY;
    float m_fZ;
    BOOL m_bMute;
    float m_fMinDistance;
    float m_fMaxDistance;
    float m_fGain;
    float m_fElevation;
    CResRef m_cResRef;

    CNWSSound();
    ~CNWSSound();
    BOOL LoadFromTemplate(CResRef cResRef);
    BOOL LoadSound(CResGFF * pRes, CResStruct * cSoundStruct);
    void LoadDataFromGff(CResGFF * pRes, CResStruct * pSoundStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSSound
    NWN_CLASS_EXTENSION_CNWSSound
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSSound)
#endif

