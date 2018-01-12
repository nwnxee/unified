#pragma once

#include <cstdint>

#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "unknown_CExoArrayListTemplatedunsignedlong.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedCGameEffectPtr;
struct CExoArrayListTemplatedCNWSPersonalReputation;
struct CExoArrayListTemplatedint;
struct CNWSArea;
struct CResGFF;
struct CResStruct;

struct CNWSPlayerTURD
    : CNWSObject
{
    CExoString m_sCommunityName;
    CExoLocString m_lsFirstName;
    CExoLocString m_lsLastName;
    uint32_t m_oidPlayer;
    uint32_t m_nCalendarDay;
    uint32_t m_nCalendarTimeOfDay;
    CExoArrayListTemplatedint* m_pReputation;
    CExoArrayListTemplatedCNWSPersonalReputation* m_pPersonalReputationList;
    int32_t m_nNumAutomapAreas;
    uint32_t* m_poidAutomapAreasList;
    uint8_t** m_pAutoMapTileData;

    // The below are auto generated stubs.
    CNWSPlayerTURD() = default;
    CNWSPlayerTURD(const CNWSPlayerTURD&) = default;
    CNWSPlayerTURD& operator=(const CNWSPlayerTURD&) = default;

    CNWSPlayerTURD(uint32_t);
    ~CNWSPlayerTURD();
    void AddToArea(CNWSArea*, int32_t);
    void AIUpdate();
    CNWSPlayerTURD* AsNWSPlayerTURD();
    void ClearAutomapData();
    void CopyAutomapData(int32_t, CExoArrayListTemplatedunsignedlong*, unsigned char**);
    void CopyEffectList(CExoArrayListTemplatedCGameEffectPtr*);
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    CExoLocString& GetFirstName();
    CExoLocString& GetLastName();
    void LoadAutoMapData(CResGFF*, CResStruct*);
    int32_t LoadTURD(CResGFF*, CResStruct*);
    void RemoveFromArea();
    void SaveAutoMapData(CResGFF*, CResStruct*);
    void SaveTURD(CResGFF*, CResStruct*);
    void SetPersonalReputation(CExoArrayListTemplatedCNWSPersonalReputation*);
    void SetReputation(CExoArrayListTemplatedint*);
};

void CNWSPlayerTURD__CNWSPlayerTURDCtor__0(CNWSPlayerTURD* thisPtr, uint32_t);
void CNWSPlayerTURD__CNWSPlayerTURDDtor__0(CNWSPlayerTURD* thisPtr);
void CNWSPlayerTURD__AddToArea(CNWSPlayerTURD* thisPtr, CNWSArea*, int32_t);
void CNWSPlayerTURD__AIUpdate(CNWSPlayerTURD* thisPtr);
CNWSPlayerTURD* CNWSPlayerTURD__AsNWSPlayerTURD(CNWSPlayerTURD* thisPtr);
void CNWSPlayerTURD__ClearAutomapData(CNWSPlayerTURD* thisPtr);
void CNWSPlayerTURD__CopyAutomapData(CNWSPlayerTURD* thisPtr, int32_t, CExoArrayListTemplatedunsignedlong*, unsigned char**);
void CNWSPlayerTURD__CopyEffectList(CNWSPlayerTURD* thisPtr, CExoArrayListTemplatedCGameEffectPtr*);
void CNWSPlayerTURD__EventHandler(CNWSPlayerTURD* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
CExoLocString& CNWSPlayerTURD__GetFirstName(CNWSPlayerTURD* thisPtr);
CExoLocString& CNWSPlayerTURD__GetLastName(CNWSPlayerTURD* thisPtr);
void CNWSPlayerTURD__LoadAutoMapData(CNWSPlayerTURD* thisPtr, CResGFF*, CResStruct*);
int32_t CNWSPlayerTURD__LoadTURD(CNWSPlayerTURD* thisPtr, CResGFF*, CResStruct*);
void CNWSPlayerTURD__RemoveFromArea(CNWSPlayerTURD* thisPtr);
void CNWSPlayerTURD__SaveAutoMapData(CNWSPlayerTURD* thisPtr, CResGFF*, CResStruct*);
void CNWSPlayerTURD__SaveTURD(CNWSPlayerTURD* thisPtr, CResGFF*, CResStruct*);
void CNWSPlayerTURD__SetPersonalReputation(CNWSPlayerTURD* thisPtr, CExoArrayListTemplatedCNWSPersonalReputation*);
void CNWSPlayerTURD__SetReputation(CNWSPlayerTURD* thisPtr, CExoArrayListTemplatedint*);

}

}
