#pragma once

#include <cstdint>

#include "CExoLocString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoString;
struct CNWSArea;
struct CResGFF;
struct CResStruct;

struct CNWSWaypoint
    : CNWSObject
{
    int32_t m_bMapNote;
    int32_t m_bMapNoteEnabled;
    CExoLocString m_szMapNote;
    CExoLocString m_sLocalizedName;

    // The below are auto generated stubs.
    CNWSWaypoint() = default;
    CNWSWaypoint(const CNWSWaypoint&) = default;
    CNWSWaypoint& operator=(const CNWSWaypoint&) = default;

    CNWSWaypoint(uint32_t);
    ~CNWSWaypoint();
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    void AIUpdate();
    CNWSWaypoint* AsNWSWaypoint();
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    CExoLocString& GetFirstName();
    int32_t LoadFromTemplate(CResRef, CExoString*);
    int32_t LoadWaypoint(CResGFF*, CResStruct*, CExoString*);
    void RemoveFromArea();
    int32_t SaveWaypoint(CResGFF*, CResStruct*);
};

void CNWSWaypoint__CNWSWaypointCtor__0(CNWSWaypoint* thisPtr, uint32_t);
void CNWSWaypoint__CNWSWaypointDtor__0(CNWSWaypoint* thisPtr);
void CNWSWaypoint__AddToArea(CNWSWaypoint* thisPtr, CNWSArea*, float, float, float, int32_t);
void CNWSWaypoint__AIUpdate(CNWSWaypoint* thisPtr);
CNWSWaypoint* CNWSWaypoint__AsNWSWaypoint(CNWSWaypoint* thisPtr);
void CNWSWaypoint__EventHandler(CNWSWaypoint* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
CExoLocString& CNWSWaypoint__GetFirstName(CNWSWaypoint* thisPtr);
int32_t CNWSWaypoint__LoadFromTemplate(CNWSWaypoint* thisPtr, CResRef, CExoString*);
int32_t CNWSWaypoint__LoadWaypoint(CNWSWaypoint* thisPtr, CResGFF*, CResStruct*, CExoString*);
void CNWSWaypoint__RemoveFromArea(CNWSWaypoint* thisPtr);
int32_t CNWSWaypoint__SaveWaypoint(CNWSWaypoint* thisPtr, CResGFF*, CResStruct*);

}

}
