#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CEncounterSpawnPoint)
#endif





class CEncounterSpawnPoint
{
    Vector m_vPosition;
    float m_fOrientation;



#ifdef NWN_CLASS_EXTENSION_CEncounterSpawnPoint
    NWN_CLASS_EXTENSION_CEncounterSpawnPoint
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CEncounterSpawnPoint)
#endif

