#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CItemRepository;
struct CNWSCreature;
struct CNWSPlayerLUOInventory;

struct CNWSBarter
{
    CItemRepository* m_pBarterList;
    CNWSPlayerLUOInventory* m_pLastUpdate;
    CNWSPlayerLUOInventory* m_pOtherLastUpdate;
    int32_t m_bListLocked;
    int32_t m_bListAccepted;
    int32_t m_bInitiator;
    int32_t m_bWindowOpen;
    uint32_t m_oidBarrator;
    CNWSCreature* m_pOwner;
    int32_t m_bDoReset;

    // The below are auto generated stubs.
    CNWSBarter() = default;
    CNWSBarter(const CNWSBarter&) = default;
    CNWSBarter& operator=(const CNWSBarter&) = default;

    CNWSBarter(CNWSCreature*);
    ~CNWSBarter();
    int32_t AddItem(uint32_t, unsigned char&, unsigned char&);
    void CleanUp();
    unsigned char GetState();
    int32_t MoveItem(uint32_t, unsigned char&, unsigned char&);
    int32_t PullItemOut(uint32_t);
    int32_t RemoveItem(uint32_t, unsigned char&, unsigned char&);
    void Reset(uint32_t, int32_t);
    int32_t SetListAccepted(int32_t);
    int32_t SetListLocked(int32_t);
};

void CNWSBarter__CNWSBarterCtor__0(CNWSBarter* thisPtr, CNWSCreature*);
void CNWSBarter__CNWSBarterDtor__0(CNWSBarter* thisPtr);
int32_t CNWSBarter__AddItem(CNWSBarter* thisPtr, uint32_t, unsigned char&, unsigned char&);
void CNWSBarter__CleanUp(CNWSBarter* thisPtr);
unsigned char CNWSBarter__GetState(CNWSBarter* thisPtr);
int32_t CNWSBarter__MoveItem(CNWSBarter* thisPtr, uint32_t, unsigned char&, unsigned char&);
int32_t CNWSBarter__PullItemOut(CNWSBarter* thisPtr, uint32_t);
int32_t CNWSBarter__RemoveItem(CNWSBarter* thisPtr, uint32_t, unsigned char&, unsigned char&);
void CNWSBarter__Reset(CNWSBarter* thisPtr, uint32_t, int32_t);
int32_t CNWSBarter__SetListAccepted(CNWSBarter* thisPtr, int32_t);
int32_t CNWSBarter__SetListLocked(CNWSBarter* thisPtr, int32_t);

}

}
