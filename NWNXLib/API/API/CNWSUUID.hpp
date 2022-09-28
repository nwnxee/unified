#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSUUID)
#endif

struct CGameObject;
struct CResGFF;
struct CResStruct;




struct CNWSUUID
{
    CGameObject * m_parent;
    CExoString m_uuid;

    static void* GetMapPtr();

    CNWSUUID(CGameObject * );
    virtual ~CNWSUUID();
    static bool CanCarryUUID(int32_t objectType);
    bool CanCarryUUID();
    static CExoString MakeRandom();
    static OBJECT_ID LookupObjectIdByUUID(const CExoString& uuid);
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

