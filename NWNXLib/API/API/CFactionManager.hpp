#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CFactionManager)
#endif

struct CExoString;
struct CNWSFaction;
struct CResGFF;
struct CResList;


typedef int BOOL;


struct CFactionManager
{
    CNWSFaction * m_pDefaultFactionDefender;
    CNWSFaction * m_pDefaultFactionCommoner;
    CNWSFaction * m_pDefaultFactionMerchant;
    CNWSFaction * m_pDefaultFactionHostile;
    CNWSFaction * m_pDefaultFactionPC;
    int32_t m_nNPCFactionCount;
    CExoArrayList<int32_t> * m_pNPCReputations;
    CExoArrayList<CNWSFaction *> * m_pFactionList;

    CFactionManager();
    ~CFactionManager();
    CNWSFaction * GetFaction(int32_t nFactionId);
    BOOL GetIsNPCFaction(int32_t nFactionId);
    int32_t GetNPCFactionReputation(int32_t nFactionId, int32_t nSubjectFactionId);
    void SetNPCFactionReputation(int32_t nFactionId, int32_t nSubjectFactionId, int32_t nReputation);
    CExoArrayList<int32_t> * GetDefaultPCReputation();
    void DeleteFaction(int32_t nFactionId);
    int32_t GetFactionIdByName(const CExoString & name);
    BOOL LoadFactions(CResGFF * pRes, CResList * cFactionList);
    BOOL LoadReputations(CResGFF * pRes, CResList * cReputationList);
    void CreateDefaultFactions();
    BOOL SaveFactions(CResGFF * pRes, CResList * pList);
    BOOL SaveReputations(CResGFF * pRes, CResList * pList);


#ifdef NWN_CLASS_EXTENSION_CFactionManager
    NWN_CLASS_EXTENSION_CFactionManager
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CFactionManager)
#endif
