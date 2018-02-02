#pragma once

#include <cstdint>

#include "CExoArrayListTemplatedlongunsignedint.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSObject.hpp"
#include "CResRef.hpp"
#include "Vector.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CItemRepository;
struct CNWSArea;
struct CNWSItem;
struct CNWSObjectActionNode;
struct CResGFF;
struct CResStruct;

struct CNWSPlaceable
    : CNWSObject
{
    CExoLocString m_sLocName;
    CExoString m_sDisplayName;
    int32_t m_bUpdateDisplayName;
    uint16_t m_nAppearance;
    CExoLocString m_sDescription;
    CExoString m_sDescriptionOverride;
    int32_t m_nFactionId;
    CResRef m_cDialog;
    uint8_t m_nType;
    int32_t m_bGroundPile;
    uint32_t m_oidSittingCreature;
    uint8_t m_nHardness;
    float m_fBearing;
    int32_t m_bLocked;
    CExoString m_sKeyName;
    CExoString m_sKeyRequiredFeedbackMessage;
    int32_t m_bKeyRequired;
    int32_t m_bAutoRemoveKey;
    uint8_t m_nOpenLockDC;
    uint8_t m_nCloseLockDC;
    uint32_t m_oidTrapCreator;
    uint8_t m_nTrapDetectionDC;
    int32_t m_bTrapFlag;
    uint8_t m_nDisarmDC;
    int32_t m_bDisarmable;
    int32_t m_bDetectable;
    int32_t m_bOneShot;
    int32_t m_bRecoverable;
    int32_t m_bFlagged;
    uint8_t m_nBaseType;
    int32_t m_bTrapIsActive;
    int32_t m_nTrapFaction;
    CExoString m_sScripts[16];
    uint8_t m_nFortSave;
    uint8_t m_nWillSave;
    uint8_t m_nReflexSave;
    CExoArrayListTemplatedlongunsignedint m_poidCreatures;
    int32_t m_bHasInventory;
    int32_t m_bUseable;
    int32_t m_bPickable;
    int32_t m_bLockable;
    int32_t m_bDieWhenEmpty;
    uint32_t m_nOpenCount;
    int32_t m_nStaticObjectPosition;
    uint32_t m_oidLootCreature;
    int32_t m_bIsBodyBag;
    uint32_t m_nLastHeartbeatScriptCalendarDay;
    uint32_t m_nLastHeartbeatScriptTimeOfDay;
    uint32_t m_oidLastOpened;
    uint32_t m_oidLastClosed;
    uint32_t m_oidLastUser;
    uint32_t m_oidLastDefaultClickedBy;
    uint32_t m_oidLastTriggered;
    uint32_t m_oidLastDisarmed;
    uint32_t m_oidLastLocked;
    uint32_t m_oidLastUnlocked;
    CItemRepository* m_pcItemRepository;
    uint16_t m_nRepositoryArrayIndex;
    uint16_t m_nItemContainerArrayIndex;
    uint32_t m_oidCurrentItemContainer;
    Vector m_pvActionPoints[2];
    CResRef m_cTemplateResRef;
    CExoString m_szPortalInfo;
    uint32_t m_nEffectSpellId;
    int32_t m_bLightIsOn;
    int32_t m_bLightStateChange;
    uint8_t m_nBodyBag;
    int32_t m_bStaticObject;
    int32_t m_bNeverMakeIntoStaticObject;

    // The below are auto generated stubs.
    CNWSPlaceable() = default;
    CNWSPlaceable(const CNWSPlaceable&) = default;
    CNWSPlaceable& operator=(const CNWSPlaceable&) = default;

    CNWSPlaceable(uint32_t);
    ~CNWSPlaceable();
    int32_t AcquireItem(CNWSItem**, uint32_t, unsigned char, unsigned char, int32_t);
    uint32_t AcquireItemsFromObject(uint32_t, int32_t);
    int32_t AddCastSpellActions(uint32_t, int32_t, Vector, uint32_t, int32_t, unsigned char);
    void AddToArea(CNWSArea*, float, float, float, int32_t);
    uint32_t AIActionCastSpell(CNWSObjectActionNode*);
    void AIUpdate();
    CNWSPlaceable* AsNWSPlaceable();
    void CalculateActionPoints();
    void CloseInventory(uint32_t, int32_t);
    void ClosePlaceableForAllPlayers();
    void DoDamage(int32_t);
    void DropItemsIntoArea();
    void EventHandler(uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uint16_t GetBodyBagAppearance();
    CResRef GetDialogResref();
    uint32_t GetEffectSpellId();
    CExoLocString& GetFirstName();
    uint32_t GetItemCount(int32_t);
    int32_t GetLightIsOn();
    Vector GetNearestActionPoint(const Vector&);
    int32_t LoadBodyBag(uint16_t);
    int32_t LoadFromTemplate(CResRef, CExoString*);
    int32_t LoadPlaceable(CResGFF*, CResStruct*, CExoString*);
    void OpenInventory(uint32_t);
    void PostProcess();
    void RemoveFromArea();
    int32_t RemoveItem(CNWSItem*, int32_t);
    int32_t SavePlaceable(CResGFF*, CResStruct*, int32_t);
    void SetEffectSpellId(uint32_t);
    void SetLightIsOn(int32_t);
    void SetOrientation(Vector);
};

void CNWSPlaceable__CNWSPlaceableCtor__0(CNWSPlaceable* thisPtr, uint32_t);
void CNWSPlaceable__CNWSPlaceableDtor__0(CNWSPlaceable* thisPtr);
int32_t CNWSPlaceable__AcquireItem(CNWSPlaceable* thisPtr, CNWSItem**, uint32_t, unsigned char, unsigned char, int32_t);
uint32_t CNWSPlaceable__AcquireItemsFromObject(CNWSPlaceable* thisPtr, uint32_t, int32_t);
int32_t CNWSPlaceable__AddCastSpellActions(CNWSPlaceable* thisPtr, uint32_t, int32_t, Vector, uint32_t, int32_t, unsigned char);
void CNWSPlaceable__AddToArea(CNWSPlaceable* thisPtr, CNWSArea*, float, float, float, int32_t);
uint32_t CNWSPlaceable__AIActionCastSpell(CNWSPlaceable* thisPtr, CNWSObjectActionNode*);
void CNWSPlaceable__AIUpdate(CNWSPlaceable* thisPtr);
CNWSPlaceable* CNWSPlaceable__AsNWSPlaceable(CNWSPlaceable* thisPtr);
void CNWSPlaceable__CalculateActionPoints(CNWSPlaceable* thisPtr);
void CNWSPlaceable__CloseInventory(CNWSPlaceable* thisPtr, uint32_t, int32_t);
void CNWSPlaceable__ClosePlaceableForAllPlayers(CNWSPlaceable* thisPtr);
void CNWSPlaceable__DoDamage(CNWSPlaceable* thisPtr, int32_t);
void CNWSPlaceable__DropItemsIntoArea(CNWSPlaceable* thisPtr);
void CNWSPlaceable__EventHandler(CNWSPlaceable* thisPtr, uint32_t, uint32_t, void*, uint32_t, uint32_t);
uint16_t CNWSPlaceable__GetBodyBagAppearance(CNWSPlaceable* thisPtr);
CResRef CNWSPlaceable__GetDialogResref(CNWSPlaceable* thisPtr);
uint32_t CNWSPlaceable__GetEffectSpellId(CNWSPlaceable* thisPtr);
CExoLocString& CNWSPlaceable__GetFirstName(CNWSPlaceable* thisPtr);
uint32_t CNWSPlaceable__GetItemCount(CNWSPlaceable* thisPtr, int32_t);
int32_t CNWSPlaceable__GetLightIsOn(CNWSPlaceable* thisPtr);
Vector CNWSPlaceable__GetNearestActionPoint(CNWSPlaceable* thisPtr, const Vector&);
int32_t CNWSPlaceable__LoadBodyBag(CNWSPlaceable* thisPtr, uint16_t);
int32_t CNWSPlaceable__LoadFromTemplate(CNWSPlaceable* thisPtr, CResRef, CExoString*);
int32_t CNWSPlaceable__LoadPlaceable(CNWSPlaceable* thisPtr, CResGFF*, CResStruct*, CExoString*);
void CNWSPlaceable__OpenInventory(CNWSPlaceable* thisPtr, uint32_t);
void CNWSPlaceable__PostProcess(CNWSPlaceable* thisPtr);
void CNWSPlaceable__RemoveFromArea(CNWSPlaceable* thisPtr);
int32_t CNWSPlaceable__RemoveItem(CNWSPlaceable* thisPtr, CNWSItem*, int32_t);
int32_t CNWSPlaceable__SavePlaceable(CNWSPlaceable* thisPtr, CResGFF*, CResStruct*, int32_t);
void CNWSPlaceable__SetEffectSpellId(CNWSPlaceable* thisPtr, uint32_t);
void CNWSPlaceable__SetLightIsOn(CNWSPlaceable* thisPtr, int32_t);
void CNWSPlaceable__SetOrientation(CNWSPlaceable* thisPtr, Vector);

}

}
