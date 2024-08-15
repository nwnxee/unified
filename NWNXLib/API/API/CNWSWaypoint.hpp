#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSWaypoint)
#endif

struct CExoString;
struct CNWSArea;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSWaypoint : CNWSObject
{
    BOOL m_bMapNote;
    BOOL m_bMapNoteEnabled;
    CExoLocString m_szMapNote;
    CExoLocString m_sLocalizedName;

    CNWSWaypoint(OBJECT_ID oidId = 0x7f000000);
    ~CNWSWaypoint();
    void AddToArea(CNWSArea * pArea, float fX, float fY, float fZ, BOOL bRunScripts = true);
    void AIUpdate();
    virtual CNWSWaypoint * AsNWSWaypoint();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void RemoveFromArea();
    BOOL LoadFromTemplate(CResRef cResRef, CExoString * pTag = nullptr);
    BOOL LoadWaypoint(CResGFF * pRes, CResStruct * cWaypointStruct, CExoString * pTag = nullptr);
    BOOL SaveWaypoint(CResGFF * pRes, CResStruct * cWaypointStruct);

    inline CExoLocString &GetFirstName() override { return m_sLocalizedName; }

#ifdef NWN_CLASS_EXTENSION_CNWSWaypoint
    NWN_CLASS_EXTENSION_CNWSWaypoint
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSWaypoint)
#endif

