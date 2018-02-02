#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedCNWSFactionPtr;
struct CExoArrayListTemplatedint;
struct CExoString;
struct CNWSFaction;
struct CResGFF;
struct CResList;

struct CFactionManager
{
    CNWSFaction* m_pDefaultFactionDefender;
    CNWSFaction* m_pDefaultFactionCommoner;
    CNWSFaction* m_pDefaultFactionMerchant;
    CNWSFaction* m_pDefaultFactionHostile;
    CNWSFaction* m_pDefaultFactionPC;
    int32_t m_nNPCFactionCount;
    CExoArrayListTemplatedint* m_pNPCReputations;
    CExoArrayListTemplatedCNWSFactionPtr* m_pFactionList;

    // The below are auto generated stubs.
    CFactionManager(const CFactionManager&) = default;
    CFactionManager& operator=(const CFactionManager&) = default;

    CFactionManager();
    ~CFactionManager();
    void CreateDefaultFactions();
    void DeleteFaction(int32_t);
    CExoArrayListTemplatedint* GetDefaultPCReputation();
    CNWSFaction* GetFaction(int32_t);
    int32_t GetFactionIdByName(const CExoString&);
    int32_t GetIsNPCFaction(int32_t);
    int32_t GetNPCFactionReputation(int32_t, int32_t);
    int32_t LoadFactions(CResGFF*, CResList*);
    int32_t LoadReputations(CResGFF*, CResList*);
    int32_t SaveFactions(CResGFF*, CResList*);
    int32_t SaveReputations(CResGFF*, CResList*);
    void SetNPCFactionReputation(int32_t, int32_t, int32_t);
};

void CFactionManager__CFactionManagerCtor(CFactionManager* thisPtr);
void CFactionManager__CFactionManagerDtor(CFactionManager* thisPtr);
void CFactionManager__CreateDefaultFactions(CFactionManager* thisPtr);
void CFactionManager__DeleteFaction(CFactionManager* thisPtr, int32_t);
CExoArrayListTemplatedint* CFactionManager__GetDefaultPCReputation(CFactionManager* thisPtr);
CNWSFaction* CFactionManager__GetFaction(CFactionManager* thisPtr, int32_t);
int32_t CFactionManager__GetFactionIdByName(CFactionManager* thisPtr, const CExoString&);
int32_t CFactionManager__GetIsNPCFaction(CFactionManager* thisPtr, int32_t);
int32_t CFactionManager__GetNPCFactionReputation(CFactionManager* thisPtr, int32_t, int32_t);
int32_t CFactionManager__LoadFactions(CFactionManager* thisPtr, CResGFF*, CResList*);
int32_t CFactionManager__LoadReputations(CFactionManager* thisPtr, CResGFF*, CResList*);
int32_t CFactionManager__SaveFactions(CFactionManager* thisPtr, CResGFF*, CResList*);
int32_t CFactionManager__SaveReputations(CFactionManager* thisPtr, CResGFF*, CResList*);
void CFactionManager__SetNPCFactionReputation(CFactionManager* thisPtr, int32_t, int32_t, int32_t);

}

}
