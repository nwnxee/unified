#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CNWSObjectActionNode.hpp"
#include "CNWSPersonalReputation.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSPlayerTURD)
#endif

struct CGameEffect;
struct CNWSArea;
struct CResGFF;
struct CResStruct;


typedef int BOOL;
typedef uint32_t OBJECT_ID;


struct CNWSPlayerTURD : CNWSObject
{
    CExoString m_sCommunityName;
    CExoLocString m_lsFirstName;
    CExoLocString m_lsLastName;
    OBJECT_ID m_oidPlayer;
    uint32_t m_nCalendarDay;
    uint32_t m_nCalendarTimeOfDay;
    CExoArrayList<int32_t> * m_pReputation;
    CExoArrayList<CNWSPersonalReputation> * m_pPersonalReputationList;
    int32_t m_nNumAutomapAreas;
    OBJECT_ID * m_poidAutomapAreasList;
    uint8_t * * m_pAutoMapTileData;

    CNWSPlayerTURD(OBJECT_ID oidId = 0x7f000000);
    ~CNWSPlayerTURD();
    virtual CNWSPlayerTURD * AsNWSPlayerTURD();
    void AIUpdate();
    void EventHandler(uint32_t nEventId, OBJECT_ID nCallerObjectId, void * pScript, uint32_t nCalendarDay, uint32_t nTimeOfDay);
    void AddToArea(CNWSArea * pArea, BOOL bRunScripts = true);
    void RemoveFromArea();
    void SaveTURD(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadTURD(CResGFF * pRes, CResStruct * pStruct);
    void SetReputation(CExoArrayList<int32_t> * pRep);
    void SetPersonalReputation(CExoArrayList<CNWSPersonalReputation> * pRep);
    void CopyEffectList(CExoArrayList<CGameEffect *> * pEffectList);
    void CopyAutomapData(int32_t nNumAreas, CExoArrayList<OBJECT_ID> * pAreaList, uint8_t * * pAreaData);
    void ClearAutomapData();
    void LoadAutoMapData(CResGFF * pRes, CResStruct * pStruct);
    void SaveAutoMapData(CResGFF * pRes, CResStruct * pStruct);


#ifdef NWN_CLASS_EXTENSION_CNWSPlayerTURD
    NWN_CLASS_EXTENSION_CNWSPlayerTURD
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSPlayerTURD)
#endif

