#pragma once
#include "nwn_api.hpp"

#include "CNWSObject.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPortal)
#endif

struct CNWSMessage;
struct CResStruct;
struct CNWSArea;
struct CResGFF;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSPortal : CNWSObject
{

    CNWSPortal();
    ~CNWSPortal();
    virtual CNWSPortal * AsNWSPortal();
    void AIUpdate();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    BOOL Load(CResGFF * pRes, CResStruct * pSoundStruct);
    void Save(CResGFF * pRes, CResStruct * pStruct);
    void AddToArea(CNWSArea * pArea);
    void RemoveFromArea();
    void PackIntoMessage(CNWSMessage * pMessage);


#ifdef NWN_CLASS_EXTENSION_CNWSPortal
    NWN_CLASS_EXTENSION_CNWSPortal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPortal)
#endif

