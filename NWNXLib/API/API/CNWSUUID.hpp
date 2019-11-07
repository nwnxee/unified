#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSUUID)
#endif

struct CResStruct;
struct CGameObject;
struct CResGFF;




struct CNWSUUID
{
    CGameObject * m_parent;
    CExoString m_uuid;

    CNWSUUID(CGameObject * );
    virtual ~CNWSUUID();
    bool CanCarryUUID();
    bool TryAssign(const CExoString & uuid);
    void AssignRandom();
    CExoString GetOrAssignRandom();
    bool LoadFromGff(CResGFF * pRes, CResStruct * pStruct);
    void SaveToGff(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSUUID
    NWN_CLASS_EXTENSION_CNWSUUID
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSUUID)
#endif

