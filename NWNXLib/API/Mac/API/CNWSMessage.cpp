#include "CNWSMessage.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCEffectIconObjectPtr.hpp"
#include "CExoArrayListTemplatedCLoopingVisualEffectPtr.hpp"
#include "CExoLinkedListNode.hpp"
#include "CGameObject.hpp"
#include "CGameObjectArray.hpp"
#include "CItemRepository.hpp"
#include "CLastUpdateObject.hpp"
#include "CLastUpdatePartyObject.hpp"
#include "CNWCCMessageData.hpp"
#include "CNWSArea.hpp"
#include "CNWSAreaOfEffectObject.hpp"
#include "CNWSCombatAttackData.hpp"
#include "CNWSCreature.hpp"
#include "CNWSDoor.hpp"
#include "CNWSItem.hpp"
#include "CNWSObject.hpp"
#include "CNWSPlaceable.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSPlayerInventoryGUI.hpp"
#include "CNWSPlayerLUOInventory.hpp"
#include "CNWSPlayerLUOSortedObjectList.hpp"
#include "CNWSPlayerLastUpdateObject.hpp"
#include "CNWSStore.hpp"
#include "CNWSTrigger.hpp"

namespace NWNXLib {

namespace API {

CNWSMessage::CNWSMessage()
{
    CNWSMessage__CNWSMessageCtor__0(this);
}

CNWSMessage::~CNWSMessage()
{
    CNWSMessage__CNWSMessageDtor__0(this);
}

void CNWSMessage::AddActiveItemPropertiesToMessage(CNWSItem* a0, CNWSCreature* a1)
{
    return CNWSMessage__AddActiveItemPropertiesToMessage(this, a0, a1);
}

void CNWSMessage::AddAreaOfEffectObjectToMessage(CNWSAreaOfEffectObject* a0)
{
    return CNWSMessage__AddAreaOfEffectObjectToMessage(this, a0);
}

void CNWSMessage::AddDoorAppearanceToMessage(CNWSDoor* a0)
{
    return CNWSMessage__AddDoorAppearanceToMessage(this, a0);
}

void CNWSMessage::AddItemAppearanceToMessage(CNWSItem* a0)
{
    return CNWSMessage__AddItemAppearanceToMessage(this, a0);
}

void CNWSMessage::AddPlaceableAppearanceToMessage(CNWSPlaceable* a0)
{
    return CNWSMessage__AddPlaceableAppearanceToMessage(this, a0);
}

void CNWSMessage::AddTriggerGeometryToMessage(CNWSTrigger* a0)
{
    return CNWSMessage__AddTriggerGeometryToMessage(this, a0);
}

void CNWSMessage::AssignCreatureLists(CExoArrayListTemplatedunsignedlong* a0, CExoArrayListTemplatedunsignedlong* a1)
{
    return CNWSMessage__AssignCreatureLists(this, a0, a1);
}

void CNWSMessage::AssignVisualEffectLists(CExoArrayListTemplatedCLoopingVisualEffectPtr* a0, CExoArrayListTemplatedCLoopingVisualEffectPtr* a1)
{
    return CNWSMessage__AssignVisualEffectLists(this, a0, a1);
}

int32_t CNWSMessage::CompareCreatureLists(CExoArrayListTemplatedunsignedlong* a0, CExoArrayListTemplatedunsignedlong* a1)
{
    return CNWSMessage__CompareCreatureLists(this, a0, a1);
}

int32_t CNWSMessage::CompareVisualEffectLists(CExoArrayListTemplatedCLoopingVisualEffectPtr* a0, CExoArrayListTemplatedCLoopingVisualEffectPtr* a1)
{
    return CNWSMessage__CompareVisualEffectLists(this, a0, a1);
}

uint32_t CNWSMessage::ComputeAppearanceUpdateRequired(CNWSObject* a0, CLastUpdateObject* a1)
{
    return CNWSMessage__ComputeAppearanceUpdateRequired(this, a0, a1);
}

int32_t CNWSMessage::ComputeGameObjectUpdateForCategory(uint32_t a0, uint32_t a1, CNWSPlayer* a2, CNWSObject* a3, CGameObjectArray* a4, CNWSPlayerLUOSortedObjectList* a5, int32_t a6)
{
    return CNWSMessage__ComputeGameObjectUpdateForCategory(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSMessage::ComputeGameObjectUpdateForObject(CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, uint32_t a3)
{
    return CNWSMessage__ComputeGameObjectUpdateForObject(this, a0, a1, a2, a3);
}

void CNWSMessage::ComputeGameObjectUpdateForYourself(CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, uint32_t a3)
{
    return CNWSMessage__ComputeGameObjectUpdateForYourself(this, a0, a1, a2, a3);
}

void CNWSMessage::ComputeGameObjectUpdateForYourselfToo(CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, uint32_t a3)
{
    return CNWSMessage__ComputeGameObjectUpdateForYourselfToo(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::ComputeInventoryUpdateRequired(CNWSPlayer* a0, uint32_t a1, CNWSPlayerInventoryGUI* a2)
{
    return CNWSMessage__ComputeInventoryUpdateRequired(this, a0, a1, a2);
}

int32_t CNWSMessage::ComputeLastUpdate_ActionQueue(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_ActionQueue(this, a0, a1);
}

uint16_t CNWSMessage::ComputeLastUpdate_AssociateState(CNWSCreature* a0)
{
    return CNWSMessage__ComputeLastUpdate_AssociateState(this, a0);
}

int32_t CNWSMessage::ComputeLastUpdate_AutoMap(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_AutoMap(this, a0, a1);
}

int32_t CNWSMessage::ComputeLastUpdate_CompareSpellLikeAbility(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_CompareSpellLikeAbility(this, a0, a1);
}

int32_t CNWSMessage::ComputeLastUpdate_GuiEffectIcons(CNWSCreature* a0, CExoArrayListTemplatedCEffectIconObjectPtr* a1, int32_t a2)
{
    return CNWSMessage__ComputeLastUpdate_GuiEffectIcons(this, a0, a1, a2);
}

int32_t CNWSMessage::ComputeLastUpdate_GuiFeats(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_GuiFeats(this, a0, a1);
}

int32_t CNWSMessage::ComputeLastUpdate_GuiKnownSpells(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_GuiKnownSpells(this, a0, a1);
}

int32_t CNWSMessage::ComputeLastUpdate_GuiKnownSpellUses(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_GuiKnownSpellUses(this, a0, a1);
}

int32_t CNWSMessage::ComputeLastUpdate_GuiMemorizedSpells(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_GuiMemorizedSpells(this, a0, a1);
}

int32_t CNWSMessage::ComputeLastUpdate_GuiNumberMemorizedSpells(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_GuiNumberMemorizedSpells(this, a0, a1);
}

uint32_t CNWSMessage::ComputeLastUpdate_GuiSkills(CNWSCreature* a0)
{
    return CNWSMessage__ComputeLastUpdate_GuiSkills(this, a0);
}

uint32_t CNWSMessage::ComputeLastUpdate_PlayerState(CNWSCreature* a0)
{
    return CNWSMessage__ComputeLastUpdate_PlayerState(this, a0);
}

void CNWSMessage::ComputeLastUpdate_StoreUpdateSpellLikeAbility(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_StoreUpdateSpellLikeAbility(this, a0, a1);
}

void CNWSMessage::ComputeLastUpdate_WriteSpellLikeAbility(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeLastUpdate_WriteSpellLikeAbility(this, a0, a1);
}

uint32_t CNWSMessage::ComputeNumAutoMapUpdatesRequired(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1, uint32_t* a2)
{
    return CNWSMessage__ComputeNumAutoMapUpdatesRequired(this, a0, a1, a2);
}

int32_t CNWSMessage::ComputeQuickbarItemUseCountUpdateRequired(CNWSObject* a0, CLastUpdateObject* a1)
{
    return CNWSMessage__ComputeQuickbarItemUseCountUpdateRequired(this, a0, a1);
}

int32_t CNWSMessage::ComputeRepositoryUpdateRequired(CNWSPlayer* a0, CExoLinkedListNode* a1, CExoLinkedListNode* a2)
{
    return CNWSMessage__ComputeRepositoryUpdateRequired(this, a0, a1, a2);
}

uint32_t CNWSMessage::ComputeUpdateRequired(CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject* a2, int32_t a3)
{
    return CNWSMessage__ComputeUpdateRequired(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::ComputeVisibilityLists(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__ComputeVisibilityLists(this, a0, a1);
}

CLastUpdateObject* CNWSMessage::CreateNewLastUpdateObject(CNWSPlayer* a0, CNWSObject* a1, uint32_t* a2, uint32_t* a3)
{
    return CNWSMessage__CreateNewLastUpdateObject(this, a0, a1, a2, a3);
}

void CNWSMessage::DeleteLastUpdateObjectsForObject(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__DeleteLastUpdateObjectsForObject(this, a0, a1);
}

void CNWSMessage::DeleteLastUpdateObjectsInOtherAreas(CNWSPlayer* a0)
{
    return CNWSMessage__DeleteLastUpdateObjectsInOtherAreas(this, a0);
}

int32_t CNWSMessage::GetLocStringServer(uint32_t a0, CExoLocString a1, CExoLocString a2, CExoString& a3, float& a4, unsigned char a5)
{
    return CNWSMessage__GetLocStringServer(a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage::HandlePlayerToServerAreaMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerAreaMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerBarter(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerBarter(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_AcceptTrade(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_AcceptTrade(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_AddItem(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_AddItem(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_CloseBarter(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_CloseBarter(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_LockList(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_LockList(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_MoveItem(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_MoveItem(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_RemoveItem(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_RemoveItem(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_StartBarter(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_StartBarter(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerBarter_Window(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerBarter_Window(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerCharacterDownload(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerCharacterDownload(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerCharacterSheetMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerCharacterSheetMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerCharListMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerCharListMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerChatMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerChatMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerCheatMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerCheatMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerCutscene(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerCutscene(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerDialogMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerDialogMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerDungeonMasterMessage(CNWSPlayer* a0, unsigned char a1, int32_t a2)
{
    return CNWSMessage__HandlePlayerToServerDungeonMasterMessage(this, a0, a1, a2);
}

int32_t CNWSMessage::HandlePlayerToServerGameObjectUpdate(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerGameObjectUpdate(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerGoldMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerGoldMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerGroupInputMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerGroupInputMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerGroupInputWalkToWaypoint(CNWSPlayer* a0, CNWSCreature* a1, uint32_t a2, float a3, float a4, float a5, unsigned char a6, int32_t a7, int32_t a8, uint32_t a9)
{
    return CNWSMessage__HandlePlayerToServerGroupInputWalkToWaypoint(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage::HandlePlayerToServerGuiContainerMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerGuiContainerMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerGuiInventoryMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerGuiInventoryMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerGuiQuickbar(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerGuiQuickbar(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerGuiQuickbar_SetButton(CNWSPlayer* a0, unsigned char a1, unsigned char a2)
{
    return CNWSMessage__HandlePlayerToServerGuiQuickbar_SetButton(this, a0, a1, a2);
}

int32_t CNWSMessage::HandlePlayerToServerInputAbortDriveControl(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerInputAbortDriveControl(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerInputCancelGuiTimingEvent(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerInputDriveControl(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerInputDriveControl(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerInputMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerInputMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerInputWalkToWaypoint(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerInputWalkToWaypoint(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerInventoryMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerInventoryMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerJournalMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerJournalMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerLevelUpMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerLevelUpMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerLoginMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerLoginMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerMapPinChangePin(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerMapPinChangePin(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerMapPinDestroyMapPin(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerMapPinDestroyMapPin(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerMapPinMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerMapPinMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerMapPinSetMapPinAt(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerMapPinSetMapPinAt(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNWSMessage__HandlePlayerToServerMessage(this, a0, a1, a2);
}

int32_t CNWSMessage::HandlePlayerToServerModuleMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerModuleMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerParty(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerParty(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerPlayerDeath(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerPlayerDeath(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerPlayerList(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerPlayerList(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerPlayModuleCharacterList(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerPlayModuleCharacterList(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerPlayModuleCharacterList_Start(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Start(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerPlayModuleCharacterList_Stop(CNWSPlayer* a0)
{
    return CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Stop(this, a0);
}

int32_t CNWSMessage::HandlePlayerToServerPortal(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerPortal(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerPVPListOperations(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerPVPListOperations(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerQuickChatMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerQuickChatMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerServerChatMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerServerChatMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerServerStatusMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerServerStatusMessage(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerShutDownServer(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerShutDownServer(this, a0, a1);
}

int32_t CNWSMessage::HandlePlayerToServerStoreMessage(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__HandlePlayerToServerStoreMessage(this, a0, a1);
}

int32_t CNWSMessage::HandleServerAdminToServerMessage(uint32_t a0, unsigned char* a1, uint32_t a2)
{
    return CNWSMessage__HandleServerAdminToServerMessage(this, a0, a1, a2);
}

int32_t CNWSMessage::HasValidString(CExoLocString& a0, unsigned char a1)
{
    return CNWSMessage__HasValidString(this, a0, a1);
}

int32_t CNWSMessage::ParseGetBool(unsigned char* a0, uint32_t a1, int32_t& a2)
{
    return CNWSMessage__ParseGetBool(this, a0, a1, a2);
}

int32_t CNWSMessage::ParseGetString(unsigned char* a0, uint32_t a1, CExoString& a2, uint32_t a3)
{
    return CNWSMessage__ParseGetString(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::ParseToken(const char* a0, unsigned char** a1, uint32_t& a2, int32_t a3)
{
    return CNWSMessage__ParseToken(this, a0, a1, a2, a3);
}

uint32_t CNWSMessage::ReadOBJECTIDServer()
{
    return CNWSMessage__ReadOBJECTIDServer(this);
}

uint32_t CNWSMessage::SelectCategoryForGameObject(CGameObject* a0, CNWSObject* a1)
{
    return CNWSMessage__SelectCategoryForGameObject(this, a0, a1);
}

int32_t CNWSMessage::SendPlayerToServerGuiInventory_Status(CNWSPlayer* a0, int32_t a1, uint32_t a2)
{
    return CNWSMessage__SendPlayerToServerGuiInventory_Status(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerPlayerItemUpdate_DestroyItem(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerPlayerItemUpdate_DestroyItem(this, a0, a1);
}

int32_t CNWSMessage::SendServerToAllPlayersCreatureUpdate_StripEquippedItems(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToAllPlayersCreatureUpdate_StripEquippedItems(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerActivatePortal(uint32_t a0, CExoString a1, CExoString a2, CExoString a3, int32_t a4)
{
    return CNWSMessage__SendServerToPlayerActivatePortal(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerAIActionPlaySound(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerAIActionPlaySound(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerAmbientBattleMusicChange(uint32_t a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerAmbientBattleMusicChange(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerAmbientBattleMusicPlay(uint32_t a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerAmbientBattleMusicPlay(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerAmbientMusicChangeTrack(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerAmbientMusicChangeTrack(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerAmbientMusicPlay(uint32_t a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerAmbientMusicPlay(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerAmbientMusicSetDelay(uint32_t a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerAmbientMusicSetDelay(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerAmbientSoundLoopChange(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerAmbientSoundLoopChange(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerAmbientSoundLoopPlay(uint32_t a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerAmbientSoundLoopPlay(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerAmbientSoundVolumeChange(uint32_t a0, int32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerAmbientSoundVolumeChange(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerArea_ChangeDayNight(CNWSPlayer* a0, int32_t a1, float a2)
{
    return CNWSMessage__SendServerToPlayerArea_ChangeDayNight(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerArea_ClientArea(CNWSPlayer* a0, CNWSArea* a1, float a2, float a3, float a4, const Vector& a5, int32_t a6)
{
    return CNWSMessage__SendServerToPlayerArea_ClientArea(this, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSMessage::SendServerToPlayerArea_RecomputeStaticLighting(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerArea_RecomputeStaticLighting(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerArea_SetName(CNWSPlayer* a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerArea_SetName(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerArea_VisualEffect(CNWSPlayer* a0, uint16_t a1, Vector a2)
{
    return CNWSMessage__SendServerToPlayerArea_VisualEffect(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerArea_Weather(CNWSPlayer* a0, unsigned char a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerArea_Weather(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerBarterAcceptTrade(uint32_t a0, uint32_t a1, int32_t a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerBarterAcceptTrade(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerBarterCloseBarter(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerBarterCloseBarter(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerBarterLockList(uint32_t a0, uint32_t a1, int32_t a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerBarterLockList(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerBarterReject(uint32_t a0, unsigned char a1, unsigned char a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerBarterReject(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerBarterStartBarter(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerBarterStartBarter(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerCamera_ChangeLocation(CNWSPlayer* a0, int32_t a1, float a2, float a3, float a4, int32_t a5)
{
    return CNWSMessage__SendServerToPlayerCamera_ChangeLocation(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage::SendServerToPlayerCamera_LockDistance(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerCamera_LockDistance(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCamera_LockPitch(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerCamera_LockPitch(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCamera_LockYaw(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerCamera_LockYaw(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCamera_Restore(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCamera_Restore(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCamera_SetHeight(CNWSPlayer* a0, float a1)
{
    return CNWSMessage__SendServerToPlayerCamera_SetHeight(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCamera_SetMode(CNWSPlayer* a0, unsigned char a1)
{
    return CNWSMessage__SendServerToPlayerCamera_SetMode(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCamera_Store(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCamera_Store(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCCMessage(uint32_t a0, unsigned char a1, CNWCCMessageData* a2, CNWSCombatAttackData* a3)
{
    return CNWSMessage__SendServerToPlayerCCMessage(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerCharacterDownloadFail(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCharacterDownloadFail(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCharacterDownloadReply(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCharacterDownloadReply(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCharList(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCharList(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerChat_DM_Silent_Shout(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_DM_Silent_Shout(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_DM_Talk(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_DM_Talk(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_DM_Whisper(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_DM_Whisper(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_Party(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_Party(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_ServerTell(uint32_t a0, CExoString a1)
{
    return CNWSMessage__SendServerToPlayerChat_ServerTell(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerChat_Shout(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_Shout(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_Silent_Shout(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_Silent_Shout(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_StrRef(uint32_t a0, uint32_t a1, unsigned char a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerChat_StrRef(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerChat_Talk(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_Talk(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_Tell(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_Tell(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChat_Whisper(uint32_t a0, uint32_t a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerChat_Whisper(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerChatMessage(unsigned char a0, uint32_t a1, CExoString a2, uint32_t a3, const CExoString& a4)
{
    return CNWSMessage__SendServerToPlayerChatMessage(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerChatMultiLang_Helper(uint32_t a0, unsigned char a1, uint32_t a2, CExoLocString a3, uint32_t a4, unsigned char a5, int32_t a6, const CResRef& a7, int32_t a8, uint32_t a9)
{
    return CNWSMessage__SendServerToPlayerChatMultiLang_Helper(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage::SendServerToPlayerChatMultiLangMessage(unsigned char a0, uint32_t a1, CExoLocString a2, uint32_t a3, unsigned char a4, uint32_t* a5, uint32_t a6, int32_t a7, const CResRef& a8, int32_t a9, uint32_t a10)
{
    return CNWSMessage__SendServerToPlayerChatMultiLangMessage(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int32_t CNWSMessage::SendServerToPlayerChatStrRefMessage(unsigned char a0, uint32_t a1, uint32_t a2)
{
    return CNWSMessage__SendServerToPlayerChatStrRefMessage(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerCheatDebugMode(int32_t a0)
{
    return CNWSMessage__SendServerToPlayerCheatDebugMode(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCheatNasty(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerCheatNasty(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCheatPonyRide(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerCheatPonyRide(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCheatRainOfCows(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerCheatRainOfCows(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCloseStoreInventory(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCloseStoreInventory(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCombatRoundStarted(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCombatRoundStarted(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCutscene_BlackScreen(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCutscene_BlackScreen(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerCutscene_FadeFromBlack(CNWSPlayer* a0, float a1)
{
    return CNWSMessage__SendServerToPlayerCutscene_FadeFromBlack(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCutscene_FadeToBlack(CNWSPlayer* a0, float a1)
{
    return CNWSMessage__SendServerToPlayerCutscene_FadeToBlack(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCutscene_HideGui(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerCutscene_HideGui(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerCutscene_Status(CNWSPlayer* a0, int32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerCutscene_Status(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerCutscene_StopFade(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerCutscene_StopFade(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDebugInfo_Area(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerDebugInfo_Area(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerDebugInfo_Creature(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerDebugInfo_Creature(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerDebugInfo_Door(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerDebugInfo_Door(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerDebugInfo_Item(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerDebugInfo_Item(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerDebugInfo_Placeable(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerDebugInfo_Placeable(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerDebugInfo_Trigger(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerDebugInfo_Trigger(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerDestroyDeathGUI(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerDestroyDeathGUI(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDialogClose(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerDialogClose(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDialogEntry(uint32_t a0, uint32_t a1, uint32_t a2, CExoLocString a3, uint32_t a4, unsigned char a5)
{
    return CNWSMessage__SendServerToPlayerDialogEntry(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage::SendServerToPlayerDialogReplies(uint32_t a0, CExoLocString* a1, uint32_t* a2, uint32_t a3, uint32_t a4, uint32_t a5, unsigned char a6, int32_t a7, uint32_t a8, int32_t a9)
{
    return CNWSMessage__SendServerToPlayerDialogReplies(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage::SendServerToPlayerDialogReplyChosen(uint32_t a0, uint32_t a1, uint32_t a2, CExoLocString a3, uint32_t a4, unsigned char a5, int32_t a6)
{
    return CNWSMessage__SendServerToPlayerDialogReplyChosen(this, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterAreaList(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterAreaList__0(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterAreaList(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterAreaList__1(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterCreatorLists(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterCreatorLists(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterObjectList(CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterObjectList(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMastersDifficultyChange(int32_t a0)
{
    return CNWSMessage__SendServerToPlayerDungeonMastersDifficultyChange(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterSearchByIdResult(CNWSPlayer* a0, uint32_t a1, int32_t a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterSearchByIdResult(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterSearchByTagResult(CNWSPlayer* a0, const CExoString& a1, int32_t a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterSearchByTagResult(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyList(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__0(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerDungeonMasterUpdatePartyList(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__1(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerExamineGui_CreatureData(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerExamineGui_CreatureData(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerExamineGui_DoorData(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerExamineGui_DoorData(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerExamineGui_ItemData(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerExamineGui_ItemData(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerExamineGui_PlaceableData(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerExamineGui_PlaceableData(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerExamineGui_TrapData(CNWSPlayer* a0, uint32_t a1, CNWSCreature* a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerExamineGui_TrapData(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerGameObjUpdate(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerGameObjUpdate__0(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerGameObjUpdate(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerGameObjUpdate__1(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerGameObjUpdate_ObjControl(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerGameObjUpdate_ObjControl(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerGameObjUpdateFloatyText(CNWSPlayer* a0, uint32_t a1, uint32_t a2)
{
    return CNWSMessage__SendServerToPlayerGameObjUpdateFloatyText(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerGameObjUpdateVisEffect(CNWSPlayer* a0, uint16_t a1, uint32_t a2, uint32_t a3, unsigned char a4, unsigned char a5, Vector a6, float a7)
{
    return CNWSMessage__SendServerToPlayerGameObjUpdateVisEffect(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWSMessage::SendServerToPlayerGUICharacterSheet_NotPermitted(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerGUICharacterSheet_NotPermitted(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerGuiContainerObject_Status(CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerGuiContainerObject_Status(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerGuiQuickbar_SetButton(CNWSPlayer* a0, unsigned char a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerGuiTimingEvent(CNWSPlayer* a0, int32_t a1, unsigned char a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerGuiTimingEvent(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerInventory_ConfirmDrop(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_ConfirmDrop(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_Drop(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_Drop(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_DropCancel(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_DropCancel(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_Equip(uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerInventory_Equip(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerInventory_EquipCancel(uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerInventory_EquipCancel(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerInventory_LearnScroll(uint32_t a0, uint32_t a1, unsigned char a2)
{
    return CNWSMessage__SendServerToPlayerInventory_LearnScroll(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_Pickup(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_Pickup(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_PickupCancel(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_PickupCancel(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_RepositoryMove(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_RepositoryMove(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_RepositoryMoveCancel(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_RepositoryMoveCancel(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_SelectPage(uint32_t a0, unsigned char a1)
{
    return CNWSMessage__SendServerToPlayerInventory_SelectPage(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerInventory_SelectPanel(uint32_t a0, unsigned char a1)
{
    return CNWSMessage__SendServerToPlayerInventory_SelectPanel(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerInventory_Unequip(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_Unequip(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerInventory_UnequipCancel(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerInventory_UnequipCancel(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerJournalAddQuest(CNWSPlayer* a0, CExoString a1, int32_t a2, uint32_t a3, uint16_t a4, int32_t a5, uint32_t a6, uint32_t a7, CExoLocString a8, CExoLocString a9)
{
    return CNWSMessage__SendServerToPlayerJournalAddQuest(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage::SendServerToPlayerJournalAddWorld(CNWSPlayer* a0, int32_t a1, CExoString a2, CExoString a3, uint32_t a4, uint32_t a5)
{
    return CNWSMessage__SendServerToPlayerJournalAddWorld(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage::SendServerToPlayerJournalAddWorldStrref(CNWSPlayer* a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
    return CNWSMessage__SendServerToPlayerJournalAddWorldStrref(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerJournalDeleteWorld(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerJournalDeleteWorld(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerJournalDeleteWorldAll(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerJournalDeleteWorldAll(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerJournalDeleteWorldStrref(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerJournalDeleteWorldStrref(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerJournalFullUpdate(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerJournalFullUpdate(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerJournalFullUpdateNotNeeded(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerJournalFullUpdateNotNeeded(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerJournalRemoveQuest(CNWSPlayer* a0, CExoString a1)
{
    return CNWSMessage__SendServerToPlayerJournalRemoveQuest(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerJournalSetQuestPicture(CNWSPlayer* a0, CExoString a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerJournalSetQuestPicture(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerJournalUpdated(CNWSPlayer* a0, int32_t a1, int32_t a2, CExoLocString a3)
{
    return CNWSMessage__SendServerToPlayerJournalUpdated(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerLevelUp_Begin(uint32_t a0, CNWSCreature* a1)
{
    return CNWSMessage__SendServerToPlayerLevelUp_Begin(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerLevelUp_Confirmation(uint32_t a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerLevelUp_Confirmation(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerLoadBar_EndStallEvent(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerLoadBar_EndStallEvent(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerLoadBar_StartStallEvent(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerLoadBar_StartStallEvent(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerLoadBar_UpdateStallEvent(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerLoadBar_UpdateStallEvent(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerLogin_CharacterQuery(CNWSPlayer* a0, unsigned char& a1, int32_t* a2, unsigned char* a3, uint32_t& a4)
{
    return CNWSMessage__SendServerToPlayerLogin_CharacterQuery(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerLogin_Confirm(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerLogin_Confirm(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerLogin_Fail(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerLogin_Fail(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerLogin_GetWaypoint(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerLogin_GetWaypoint(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerLogin_NeedCharacter(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerLogin_NeedCharacter(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerMapPinAdded(CNWSPlayer* a0, Vector a1, CExoString a2, uint32_t a3)
{
    return CNWSMessage__SendServerToPlayerMapPinAdded(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerMapPinCreated(CNWSPlayer* a0, uint32_t a1, Vector a2, CExoLocString a3, int32_t a4)
{
    return CNWSMessage__SendServerToPlayerMapPinCreated(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerMapPinEnabled(CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerMapPinEnabled(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerMessage(uint32_t a0, unsigned char a1, unsigned char a2, unsigned char* a3, uint32_t a4)
{
    return CNWSMessage__SendServerToPlayerMessage(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerModule_DumpPlayer(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerModule_DumpPlayer(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerModule_EndGame(uint32_t a0, const CExoString& a1)
{
    return CNWSMessage__SendServerToPlayerModule_EndGame(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerModule_EndStartNewModule(int32_t a0)
{
    return CNWSMessage__SendServerToPlayerModule_EndStartNewModule(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerModule_ExportReply(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerModule_ExportReply(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerModule_Info(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerModule_Info(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerModule_Loading(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerModule_Loading(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerModule_SaveGameStatus(unsigned char a0)
{
    return CNWSMessage__SendServerToPlayerModule_SaveGameStatus(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerModule_SetPauseState(unsigned char a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerModule_SetPauseState(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerModule_StartStartNewModule()
{
    return CNWSMessage__SendServerToPlayerModule_StartStartNewModule(this);
}

int32_t CNWSMessage::SendServerToPlayerModuleUpdate_Time(CNWSPlayer* a0, unsigned char a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, unsigned char a6, uint32_t a7)
{
    return CNWSMessage__SendServerToPlayerModuleUpdate_Time(this, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWSMessage::SendServerToPlayerOpenStoreInventory(CNWSPlayer* a0, uint32_t a1, unsigned char a2)
{
    return CNWSMessage__SendServerToPlayerOpenStoreInventory(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerParty_Invite(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerParty_Invite(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerParty_List(uint32_t a0, int32_t a1, uint32_t* a2, unsigned char a3, uint32_t a4)
{
    return CNWSMessage__SendServerToPlayerParty_List(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerParty_TransferObjectControl(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CNWSMessage__SendServerToPlayerParty_TransferObjectControl(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerPartyBar_PanelButtonFlash(uint32_t a0, unsigned char a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerPartyBar_PanelButtonFlash(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerPlaceableUpdate_Useable(CNWSPlaceable* a0)
{
    return CNWSMessage__SendServerToPlayerPlaceableUpdate_Useable(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerPlayerList_Add(uint32_t a0, CNWSPlayer* a1)
{
    return CNWSMessage__SendServerToPlayerPlayerList_Add(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerPlayerList_All(CNWSPlayer* a0)
{
    return CNWSMessage__SendServerToPlayerPlayerList_All(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerPlayerList_Delete(uint32_t a0, CNWSPlayer* a1)
{
    return CNWSMessage__SendServerToPlayerPlayerList_Delete(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerPlayerList_ReauthorizeCDKey(uint32_t a0, const CExoString& a1, const CExoString& a2)
{
    return CNWSMessage__SendServerToPlayerPlayerList_ReauthorizeCDKey(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerPlayModuleCharacterListResponse(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerPolymorph(CNWSPlayer* a0, uint32_t a1, int32_t a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerPolymorph(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerPopUpGUIPanel(uint32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, CExoString a5)
{
    return CNWSMessage__SendServerToPlayerPopUpGUIPanel(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage::SendServerToPlayerPVP_Attitude_Change(uint32_t a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerPVP_Attitude_Change(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerQuickChat(uint32_t a0, uint32_t a1, uint16_t a2)
{
    return CNWSMessage__SendServerToPlayerQuickChat(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerQuickChatMessage(uint32_t a0, uint16_t a1)
{
    return CNWSMessage__SendServerToPlayerQuickChatMessage(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerSafeProjectile(CNWSPlayer* a0, uint32_t a1, uint32_t a2, Vector a3, Vector a4, uint32_t a5, unsigned char a6, uint32_t a7, unsigned char a8, unsigned char a9, unsigned char a10)
{
    return CNWSMessage__SendServerToPlayerSafeProjectile(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int32_t CNWSMessage::SendServerToPlayerSaveLoad_Status(CNWSPlayer* a0, unsigned char a1, uint32_t a2)
{
    return CNWSMessage__SendServerToPlayerSaveLoad_Status(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerServerStatus_Status(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerServerStatus_Status(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerSetCustomToken(uint32_t a0, int32_t a1, const CExoString& a2)
{
    return CNWSMessage__SendServerToPlayerSetCustomToken(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerSetCustomTokenList(uint32_t a0)
{
    return CNWSMessage__SendServerToPlayerSetCustomTokenList(this, a0);
}

int32_t CNWSMessage::SendServerToPlayerShutDownServer(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerShutDownServer(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerSoundObject_ChangePosition(CNWSPlayer* a0, uint32_t a1, Vector a2)
{
    return CNWSMessage__SendServerToPlayerSoundObject_ChangePosition(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerSoundObject_ChangeVolume(CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    return CNWSMessage__SendServerToPlayerSoundObject_ChangeVolume(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerSoundObject_Play(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerSoundObject_Play(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerSoundObject_Stop(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerSoundObject_Stop(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerStoreConfirmTransaction(CNWSPlayer* a0, int32_t a1, uint32_t a2, int32_t a3)
{
    return CNWSMessage__SendServerToPlayerStoreConfirmTransaction(this, a0, a1, a2, a3);
}

int32_t CNWSMessage::SendServerToPlayerStringMessage(uint32_t a0, unsigned char a1, CExoString a2)
{
    return CNWSMessage__SendServerToPlayerStringMessage(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerUpdateActiveItemProperties(CNWSPlayer* a0, CNWSItem* a1)
{
    return CNWSMessage__SendServerToPlayerUpdateActiveItemProperties(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerUpdateActiveItemPropertiesUses(CNWSPlayer* a0, uint32_t a1, unsigned char a2, unsigned char a3, unsigned char* a4)
{
    return CNWSMessage__SendServerToPlayerUpdateActiveItemPropertiesUses(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::SendServerToPlayerUpdateBlackoutEffect(CNWSPlayer* a0, int32_t a1)
{
    return CNWSMessage__SendServerToPlayerUpdateBlackoutEffect(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerUpdateCharResponse(CNWSPlayer* a0, unsigned char a1, CResRef a2)
{
    return CNWSMessage__SendServerToPlayerUpdateCharResponse(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerUpdateFogAmount(unsigned char a0, unsigned char a1, uint32_t a2)
{
    return CNWSMessage__SendServerToPlayerUpdateFogAmount(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerUpdateFogColor(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CNWSMessage__SendServerToPlayerUpdateFogColor(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerUpdateItemHidden(CNWSPlayer* a0, CNWSItem* a1)
{
    return CNWSMessage__SendServerToPlayerUpdateItemHidden(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerUpdateItemName(CNWSPlayer* a0, CNWSItem* a1)
{
    return CNWSMessage__SendServerToPlayerUpdateItemName(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerUpdateSkyBox(int32_t a0, uint32_t a1)
{
    return CNWSMessage__SendServerToPlayerUpdateSkyBox(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerVoiceChat_Play(CNWSPlayer* a0, uint32_t a1, unsigned char a2)
{
    return CNWSMessage__SendServerToPlayerVoiceChat_Play(this, a0, a1, a2);
}

int32_t CNWSMessage::SendServerToPlayerWhirlwindAttack(CNWSPlayer* a0, CNWSCreature* a1)
{
    return CNWSMessage__SendServerToPlayerWhirlwindAttack(this, a0, a1);
}

int32_t CNWSMessage::SendServerToPlayerWhirlwindAttackDamage(CNWSPlayer* a0, CNWSCreature* a1)
{
    return CNWSMessage__SendServerToPlayerWhirlwindAttackDamage(this, a0, a1);
}

void CNWSMessage::SendServerToServerAdminBannedList(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminBannedList(this, a0);
}

int32_t CNWSMessage::SendServerToServerAdminMessage(uint32_t a0, CExoString a1)
{
    return CNWSMessage__SendServerToServerAdminMessage(this, a0, a1);
}

void CNWSMessage::SendServerToServerAdminModuleList(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminModuleList(this, a0);
}

void CNWSMessage::SendServerToServerAdminPlayerList(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminPlayerList(this, a0);
}

void CNWSMessage::SendServerToServerAdminPortalList(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminPortalList(this, a0);
}

void CNWSMessage::SendServerToServerAdminSaveGameList(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminSaveGameList(this, a0);
}

void CNWSMessage::SendServerToServerAdminSaveStatus(uint32_t a0, unsigned char a1)
{
    return CNWSMessage__SendServerToServerAdminSaveStatus(this, a0, a1);
}

void CNWSMessage::SendServerToServerAdminServerSettings(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminServerSettings(this, a0);
}

void CNWSMessage::SendServerToServerAdminServerStatus(uint32_t a0)
{
    return CNWSMessage__SendServerToServerAdminServerStatus(this, a0);
}

CNWSPlayerLUOSortedObjectList* CNWSMessage::SortObjectsForGameObjectUpdate(CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, int32_t* a3)
{
    return CNWSMessage__SortObjectsForGameObjectUpdate(this, a0, a1, a2, a3);
}

void CNWSMessage::StoreValuesInLastPlayerUpdateObject(CNWSPlayer* a0, CNWSPlayerLastUpdateObject* a1, CLastUpdateObject* a2, uint16_t a3)
{
    return CNWSMessage__StoreValuesInLastPlayerUpdateObject(this, a0, a1, a2, a3);
}

void CNWSMessage::StoreValuesInLastUpdateObject(CNWSPlayer* a0, CLastUpdateObject* a1, CNWSObject* a2, uint32_t a3, uint32_t a4)
{
    return CNWSMessage__StoreValuesInLastUpdateObject(this, a0, a1, a2, a3, a4);
}

void CNWSMessage::StoreValuesInLastUpdatePartyObject(CNWSCreature* a0, CLastUpdatePartyObject* a1, CNWSCreature* a2, uint32_t a3)
{
    return CNWSMessage__StoreValuesInLastUpdatePartyObject(this, a0, a1, a2, a3);
}

void CNWSMessage::TestObjectUpdateDifferences(CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject** a2, uint32_t* a3, uint32_t* a4)
{
    return CNWSMessage__TestObjectUpdateDifferences(this, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage::TestObjectVisible(CNWSObject* a0, CNWSObject* a1)
{
    return CNWSMessage__TestObjectVisible(this, a0, a1);
}

void CNWSMessage::TestPartyObjectUpdateDifferences(CNWSPlayer* a0, CNWSCreature* a1, CLastUpdatePartyObject** a2, uint32_t* a3)
{
    return CNWSMessage__TestPartyObjectUpdateDifferences(this, a0, a1, a2, a3);
}

void CNWSMessage::TestPlayerUpdateDifferences(CNWSPlayer* a0, CNWSPlayerLastUpdateObject* a1, CLastUpdateObject* a2, uint16_t& a3)
{
    return CNWSMessage__TestPlayerUpdateDifferences(this, a0, a1, a2, a3);
}

void CNWSMessage::UpdateLastUpdate_GuiEffectIcons(CNWSCreature* a0, CExoArrayListTemplatedCEffectIconObjectPtr* a1, int32_t a2)
{
    return CNWSMessage__UpdateLastUpdate_GuiEffectIcons(this, a0, a1, a2);
}

void CNWSMessage::UpdateLastUpdateActionQueue(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__UpdateLastUpdateActionQueue(this, a0, a1);
}

void CNWSMessage::UpdateLastUpdateAutoMap(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__UpdateLastUpdateAutoMap(this, a0, a1);
}

void CNWSMessage::UpdateLastUpdateInventory(CNWSPlayer* a0, uint32_t a1, CNWSPlayerInventoryGUI* a2)
{
    return CNWSMessage__UpdateLastUpdateInventory(this, a0, a1, a2);
}

void CNWSMessage::UpdateLastUpdateObject(CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject* a2, uint32_t a3)
{
    return CNWSMessage__UpdateLastUpdateObject(this, a0, a1, a2, a3);
}

void CNWSMessage::UpdateLastUpdateObjectAppearance(CNWSObject* a0, CLastUpdateObject* a1, uint32_t a2)
{
    return CNWSMessage__UpdateLastUpdateObjectAppearance(this, a0, a1, a2);
}

void CNWSMessage::UpdateLastUpdateVisibilityList(CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    return CNWSMessage__UpdateLastUpdateVisibilityList(this, a0, a1);
}

void CNWSMessage::WriteCExoLocStringServer(CExoLocString& a0, unsigned char a1)
{
    return CNWSMessage__WriteCExoLocStringServer(this, a0, a1);
}

void CNWSMessage::WriteGameObjUpdate_CharacterSheet(CNWSPlayer* a0, uint32_t a1)
{
    return CNWSMessage__WriteGameObjUpdate_CharacterSheet(this, a0, a1);
}

int32_t CNWSMessage::WriteGameObjUpdate_DungeonMasterAIState(CNWSPlayer* a0)
{
    return CNWSMessage__WriteGameObjUpdate_DungeonMasterAIState(this, a0);
}

void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels(CNWSPlayer* a0)
{
    return CNWSMessage__WriteGameObjUpdate_MajorGUIPanels(this, a0);
}

void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryData(CNWSPlayer* a0)
{
    return CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryData(this, a0);
}

void CNWSMessage::WriteGameObjUpdate_MajorGUIPanels_Inventory(CNWSPlayer* a0, CNWSPlayerInventoryGUI* a1)
{
    return CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_Inventory(this, a0, a1);
}

void CNWSMessage::WriteGameObjUpdate_MinorGUIPanels(CNWSPlayer* a0)
{
    return CNWSMessage__WriteGameObjUpdate_MinorGUIPanels(this, a0);
}

int32_t CNWSMessage::WriteGameObjUpdate_PartyAIState(CNWSPlayer* a0)
{
    return CNWSMessage__WriteGameObjUpdate_PartyAIState(this, a0);
}

void CNWSMessage::WriteGameObjUpdate_PlayerUpdate(CNWSPlayer* a0, CNWSPlayerLastUpdateObject* a1, CLastUpdateObject* a2, uint16_t a3)
{
    return CNWSMessage__WriteGameObjUpdate_PlayerUpdate(this, a0, a1, a2, a3);
}

void CNWSMessage::WriteGameObjUpdate_UpdateAppearance(CNWSObject* a0, CLastUpdateObject* a1, uint32_t a2)
{
    return CNWSMessage__WriteGameObjUpdate_UpdateAppearance(this, a0, a1, a2);
}

void CNWSMessage::WriteGameObjUpdate_UpdateObject(CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject* a2, uint32_t a3, uint32_t a4)
{
    return CNWSMessage__WriteGameObjUpdate_UpdateObject(this, a0, a1, a2, a3, a4);
}

void CNWSMessage::WriteGameObjUpdate_UpdateQuickbarItemUseCount(CNWSObject* a0, CLastUpdateObject* a1)
{
    return CNWSMessage__WriteGameObjUpdate_UpdateQuickbarItemUseCount(this, a0, a1);
}

void CNWSMessage::WriteGameObjUpdate_WorkRemaining(CNWSObject* a0, CNWSArea* a1, int32_t a2, int32_t a3)
{
    return CNWSMessage__WriteGameObjUpdate_WorkRemaining(this, a0, a1, a2, a3);
}

void CNWSMessage::WriteGameObjUpdate_WriteInventorySlotAdd(CNWSCreature* a0, CNWSItem* a1, uint32_t a2)
{
    return CNWSMessage__WriteGameObjUpdate_WriteInventorySlotAdd(this, a0, a1, a2);
}

void CNWSMessage::WriteGameObjUpdate_WriteInventorySlotDelete(CNWSCreature* a0, uint32_t a1)
{
    return CNWSMessage__WriteGameObjUpdate_WriteInventorySlotDelete(this, a0, a1);
}

void CNWSMessage::WriteGameObjUpdate_WriteInventorySlotUpdate(uint32_t a0, uint32_t a1)
{
    return CNWSMessage__WriteGameObjUpdate_WriteInventorySlotUpdate(this, a0, a1);
}

void CNWSMessage::WriteGuiEffectIconsUpdate(CNWSCreature* a0, CExoArrayListTemplatedCEffectIconObjectPtr* a1, int32_t a2)
{
    return CNWSMessage__WriteGuiEffectIconsUpdate(this, a0, a1, a2);
}

void CNWSMessage::WriteOBJECTIDServer(uint32_t a0)
{
    return CNWSMessage__WriteOBJECTIDServer(this, a0);
}

void CNWSMessage::WriteRepositoryUpdate(CNWSPlayer* a0, CNWSObject* a1, CItemRepository* a2, CNWSPlayerLUOInventory* a3, unsigned char a4, char a5, unsigned char a6)
{
    return CNWSMessage__WriteRepositoryUpdate(this, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSMessage::WriteStoreInventoryUpdate(CNWSPlayer* a0, CNWSStore* a1)
{
    return CNWSMessage__WriteStoreInventoryUpdate(this, a0, a1);
}

void CNWSMessage__CNWSMessageCtor__0(CNWSMessage* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__CNWSMessageCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSMessage__CNWSMessageDtor__0(CNWSMessage* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__CNWSMessageDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSMessage__AddActiveItemPropertiesToMessage(CNWSMessage* thisPtr, CNWSItem* a0, CNWSCreature* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSItem*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AddActiveItemPropertiesToMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__AddAreaOfEffectObjectToMessage(CNWSMessage* thisPtr, CNWSAreaOfEffectObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSAreaOfEffectObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AddAreaOfEffectObjectToMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__AddDoorAppearanceToMessage(CNWSMessage* thisPtr, CNWSDoor* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSDoor*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AddDoorAppearanceToMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__AddItemAppearanceToMessage(CNWSMessage* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AddItemAppearanceToMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__AddPlaceableAppearanceToMessage(CNWSMessage* thisPtr, CNWSPlaceable* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AddPlaceableAppearanceToMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__AddTriggerGeometryToMessage(CNWSMessage* thisPtr, CNWSTrigger* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSTrigger*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AddTriggerGeometryToMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__AssignCreatureLists(CNWSMessage* thisPtr, CExoArrayListTemplatedunsignedlong* a0, CExoArrayListTemplatedunsignedlong* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CExoArrayListTemplatedunsignedlong*, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AssignCreatureLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__AssignVisualEffectLists(CNWSMessage* thisPtr, CExoArrayListTemplatedCLoopingVisualEffectPtr* a0, CExoArrayListTemplatedCLoopingVisualEffectPtr* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CExoArrayListTemplatedCLoopingVisualEffectPtr*, CExoArrayListTemplatedCLoopingVisualEffectPtr*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__AssignVisualEffectLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__CompareCreatureLists(CNWSMessage* thisPtr, CExoArrayListTemplatedunsignedlong* a0, CExoArrayListTemplatedunsignedlong* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CExoArrayListTemplatedunsignedlong*, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__CompareCreatureLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__CompareVisualEffectLists(CNWSMessage* thisPtr, CExoArrayListTemplatedCLoopingVisualEffectPtr* a0, CExoArrayListTemplatedCLoopingVisualEffectPtr* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CExoArrayListTemplatedCLoopingVisualEffectPtr*, CExoArrayListTemplatedCLoopingVisualEffectPtr*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__CompareVisualEffectLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSMessage__ComputeAppearanceUpdateRequired(CNWSMessage* thisPtr, CNWSObject* a0, CLastUpdateObject* a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeAppearanceUpdateRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeGameObjectUpdateForCategory(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CNWSPlayer* a2, CNWSObject* a3, CGameObjectArray* a4, CNWSPlayerLUOSortedObjectList* a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CNWSPlayer*, CNWSObject*, CGameObjectArray*, CNWSPlayerLUOSortedObjectList*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeGameObjectUpdateForCategory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSMessage__ComputeGameObjectUpdateForObject(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CGameObjectArray*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeGameObjectUpdateForObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__ComputeGameObjectUpdateForYourself(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CGameObjectArray*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeGameObjectUpdateForYourself);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__ComputeGameObjectUpdateForYourselfToo(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CGameObjectArray*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeGameObjectUpdateForYourselfToo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__ComputeInventoryUpdateRequired(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, CNWSPlayerInventoryGUI* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, CNWSPlayerInventoryGUI*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeInventoryUpdateRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__ComputeLastUpdate_ActionQueue(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_ActionQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint16_t CNWSMessage__ComputeLastUpdate_AssociateState(CNWSMessage* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_AssociateState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__ComputeLastUpdate_AutoMap(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_AutoMap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeLastUpdate_CompareSpellLikeAbility(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_CompareSpellLikeAbility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeLastUpdate_GuiEffectIcons(CNWSMessage* thisPtr, CNWSCreature* a0, CExoArrayListTemplatedCEffectIconObjectPtr* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CExoArrayListTemplatedCEffectIconObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiEffectIcons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__ComputeLastUpdate_GuiFeats(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeLastUpdate_GuiKnownSpells(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiKnownSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeLastUpdate_GuiKnownSpellUses(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiKnownSpellUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeLastUpdate_GuiMemorizedSpells(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiMemorizedSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeLastUpdate_GuiNumberMemorizedSpells(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiNumberMemorizedSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSMessage__ComputeLastUpdate_GuiSkills(CNWSMessage* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_GuiSkills);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSMessage__ComputeLastUpdate_PlayerState(CNWSMessage* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_PlayerState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__ComputeLastUpdate_StoreUpdateSpellLikeAbility(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_StoreUpdateSpellLikeAbility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__ComputeLastUpdate_WriteSpellLikeAbility(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeLastUpdate_WriteSpellLikeAbility);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSMessage__ComputeNumAutoMapUpdatesRequired(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1, uint32_t* a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeNumAutoMapUpdatesRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__ComputeQuickbarItemUseCountUpdateRequired(CNWSMessage* thisPtr, CNWSObject* a0, CLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeQuickbarItemUseCountUpdateRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ComputeRepositoryUpdateRequired(CNWSMessage* thisPtr, CNWSPlayer* a0, CExoLinkedListNode* a1, CExoLinkedListNode* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CExoLinkedListNode*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeRepositoryUpdateRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CNWSMessage__ComputeUpdateRequired(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject* a2, int32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeUpdateRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__ComputeVisibilityLists(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ComputeVisibilityLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CLastUpdateObject* CNWSMessage__CreateNewLastUpdateObject(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, uint32_t* a2, uint32_t* a3)
{
    using FuncPtrType = CLastUpdateObject*(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__CreateNewLastUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__DeleteLastUpdateObjectsForObject(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__DeleteLastUpdateObjectsForObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__DeleteLastUpdateObjectsInOtherAreas(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__DeleteLastUpdateObjectsInOtherAreas);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__GetLocStringServer(uint32_t a0, CExoLocString a1, CExoLocString a2, CExoString& a3, float& a4, unsigned char a5)
{
    using FuncPtrType = int32_t(*)(uint32_t, CExoLocString, CExoLocString, CExoString&, float&, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__GetLocStringServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage__HandlePlayerToServerAreaMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerAreaMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerBarter(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_AcceptTrade(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_AcceptTrade);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_AddItem(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_AddItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_CloseBarter(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_CloseBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_LockList(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_LockList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_MoveItem(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_MoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_RemoveItem(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_StartBarter(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_StartBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerBarter_Window(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerBarter_Window);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerCharacterDownload(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerCharacterDownload);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerCharacterSheetMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerCharacterSheetMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerCharListMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerCharListMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerChatMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerCheatMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerCheatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerCutscene(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerCutscene);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerDialogMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerDialogMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerDungeonMasterMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerDungeonMasterMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__HandlePlayerToServerGameObjectUpdate(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGameObjectUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerGoldMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGoldMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerGroupInputMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGroupInputMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerGroupInputWalkToWaypoint(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSCreature* a1, uint32_t a2, float a3, float a4, float a5, unsigned char a6, int32_t a7, int32_t a8, uint32_t a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSCreature*, uint32_t, float, float, float, unsigned char, int32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGroupInputWalkToWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage__HandlePlayerToServerGuiContainerMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGuiContainerMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerGuiInventoryMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGuiInventoryMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerGuiQuickbar(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGuiQuickbar);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerGuiQuickbar_SetButton(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerGuiQuickbar_SetButton);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__HandlePlayerToServerInputAbortDriveControl(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerInputAbortDriveControl);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerInputCancelGuiTimingEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerInputDriveControl(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerInputDriveControl);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerInputMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerInputMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerInputWalkToWaypoint(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerInputWalkToWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerInventoryMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerInventoryMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerJournalMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerJournalMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerLevelUpMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerLevelUpMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerLoginMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerLoginMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerMapPinChangePin(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerMapPinChangePin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerMapPinDestroyMapPin(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerMapPinDestroyMapPin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerMapPinMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerMapPinMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerMapPinSetMapPinAt(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerMapPinSetMapPinAt);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerMessage(CNWSMessage* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__HandlePlayerToServerModuleMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerModuleMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerParty(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerParty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerPlayerDeath(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPlayerDeath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerPlayerList(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPlayerList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerPlayModuleCharacterList(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPlayModuleCharacterList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Start(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Start);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Stop(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPlayModuleCharacterList_Stop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__HandlePlayerToServerPortal(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPortal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerPVPListOperations(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerPVPListOperations);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerQuickChatMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerQuickChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerServerChatMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerServerChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerServerStatusMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerServerStatusMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerShutDownServer(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerShutDownServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandlePlayerToServerStoreMessage(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandlePlayerToServerStoreMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__HandleServerAdminToServerMessage(CNWSMessage* thisPtr, uint32_t a0, unsigned char* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HandleServerAdminToServerMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__HasValidString(CNWSMessage* thisPtr, CExoLocString& a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CExoLocString&, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__HasValidString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__ParseGetBool(CNWSMessage* thisPtr, unsigned char* a0, uint32_t a1, int32_t& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char*, uint32_t, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ParseGetBool);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__ParseGetString(CNWSMessage* thisPtr, unsigned char* a0, uint32_t a1, CExoString& a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char*, uint32_t, CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ParseGetString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__ParseToken(CNWSMessage* thisPtr, const char* a0, unsigned char** a1, uint32_t& a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, const char*, unsigned char**, uint32_t&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ParseToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint32_t CNWSMessage__ReadOBJECTIDServer(CNWSMessage* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__ReadOBJECTIDServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSMessage__SelectCategoryForGameObject(CNWSMessage* thisPtr, CGameObject* a0, CNWSObject* a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSMessage*, CGameObject*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SelectCategoryForGameObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendPlayerToServerGuiInventory_Status(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendPlayerToServerGuiInventory_Status);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerPlayerItemUpdate_DestroyItem(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerPlayerItemUpdate_DestroyItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToAllPlayersCreatureUpdate_StripEquippedItems(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToAllPlayersCreatureUpdate_StripEquippedItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerActivatePortal(CNWSMessage* thisPtr, uint32_t a0, CExoString a1, CExoString a2, CExoString a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CExoString, CExoString, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerActivatePortal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerAIActionPlaySound(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAIActionPlaySound);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerAmbientBattleMusicChange(CNWSMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientBattleMusicChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerAmbientBattleMusicPlay(CNWSMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientBattleMusicPlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerAmbientMusicChangeTrack(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientMusicChangeTrack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerAmbientMusicPlay(CNWSMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientMusicPlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerAmbientMusicSetDelay(CNWSMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientMusicSetDelay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerAmbientSoundLoopChange(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientSoundLoopChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerAmbientSoundLoopPlay(CNWSMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientSoundLoopPlay);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerAmbientSoundVolumeChange(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerAmbientSoundVolumeChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerArea_ChangeDayNight(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, float a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerArea_ChangeDayNight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerArea_ClientArea(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSArea* a1, float a2, float a3, float a4, const Vector& a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSArea*, float, float, float, const Vector&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerArea_ClientArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSMessage__SendServerToPlayerArea_RecomputeStaticLighting(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerArea_RecomputeStaticLighting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerArea_SetName(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerArea_SetName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerArea_VisualEffect(CNWSMessage* thisPtr, CNWSPlayer* a0, uint16_t a1, Vector a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint16_t, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerArea_VisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerArea_Weather(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerArea_Weather);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerBarterAcceptTrade(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerBarterAcceptTrade);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerBarterCloseBarter(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerBarterCloseBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerBarterLockList(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerBarterLockList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerBarterReject(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerBarterReject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerBarterStartBarter(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerBarterStartBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerCamera_ChangeLocation(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, float a2, float a3, float a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_ChangeLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage__SendServerToPlayerCamera_LockDistance(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_LockDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCamera_LockPitch(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_LockPitch);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCamera_LockYaw(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_LockYaw);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCamera_Restore(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_Restore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCamera_SetHeight(CNWSMessage* thisPtr, CNWSPlayer* a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_SetHeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCamera_SetMode(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_SetMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCamera_Store(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCamera_Store);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCCMessage(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1, CNWCCMessageData* a2, CNWSCombatAttackData* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char, CNWCCMessageData*, CNWSCombatAttackData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCCMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerCharacterDownloadFail(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCharacterDownloadFail);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCharacterDownloadReply(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCharacterDownloadReply);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCharList(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCharList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerChat_DM_Silent_Shout(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_DM_Silent_Shout);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_DM_Talk(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_DM_Talk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_DM_Whisper(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_DM_Whisper);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_Party(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_Party);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_ServerTell(CNWSMessage* thisPtr, uint32_t a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_ServerTell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerChat_Shout(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_Shout);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_Silent_Shout(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_Silent_Shout);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_StrRef(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, unsigned char a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_StrRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerChat_Talk(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_Talk);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_Tell(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_Tell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChat_Whisper(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChat_Whisper);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerChatMessage(CNWSMessage* thisPtr, unsigned char a0, uint32_t a1, CExoString a2, uint32_t a3, const CExoString& a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char, uint32_t, CExoString, uint32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerChatMultiLang_Helper(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1, uint32_t a2, CExoLocString a3, uint32_t a4, unsigned char a5, int32_t a6, const CResRef& a7, int32_t a8, uint32_t a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char, uint32_t, CExoLocString, uint32_t, unsigned char, int32_t, const CResRef&, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChatMultiLang_Helper);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage__SendServerToPlayerChatMultiLangMessage(CNWSMessage* thisPtr, unsigned char a0, uint32_t a1, CExoLocString a2, uint32_t a3, unsigned char a4, uint32_t* a5, uint32_t a6, int32_t a7, const CResRef& a8, int32_t a9, uint32_t a10)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char, uint32_t, CExoLocString, uint32_t, unsigned char, uint32_t*, uint32_t, int32_t, const CResRef&, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChatMultiLangMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int32_t CNWSMessage__SendServerToPlayerChatStrRefMessage(CNWSMessage* thisPtr, unsigned char a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerChatStrRefMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerCheatDebugMode(CNWSMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCheatDebugMode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCheatNasty(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCheatNasty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCheatPonyRide(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCheatPonyRide);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCheatRainOfCows(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCheatRainOfCows);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCloseStoreInventory(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCloseStoreInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCombatRoundStarted(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCombatRoundStarted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCutscene_BlackScreen(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCutscene_BlackScreen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerCutscene_FadeFromBlack(CNWSMessage* thisPtr, CNWSPlayer* a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCutscene_FadeFromBlack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCutscene_FadeToBlack(CNWSMessage* thisPtr, CNWSPlayer* a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCutscene_FadeToBlack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCutscene_HideGui(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCutscene_HideGui);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerCutscene_Status(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCutscene_Status);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerCutscene_StopFade(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerCutscene_StopFade);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDebugInfo_Area(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDebugInfo_Area);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerDebugInfo_Creature(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDebugInfo_Creature);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerDebugInfo_Door(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDebugInfo_Door);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerDebugInfo_Item(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDebugInfo_Item);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerDebugInfo_Placeable(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDebugInfo_Placeable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerDebugInfo_Trigger(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDebugInfo_Trigger);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerDestroyDeathGUI(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDestroyDeathGUI);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDialogClose(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDialogClose);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDialogEntry(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, CExoLocString a3, uint32_t a4, unsigned char a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t, CExoLocString, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDialogEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage__SendServerToPlayerDialogReplies(CNWSMessage* thisPtr, uint32_t a0, CExoLocString* a1, uint32_t* a2, uint32_t a3, uint32_t a4, uint32_t a5, unsigned char a6, int32_t a7, uint32_t a8, int32_t a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CExoLocString*, uint32_t*, uint32_t, uint32_t, uint32_t, unsigned char, int32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDialogReplies);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage__SendServerToPlayerDialogReplyChosen(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, CExoLocString a3, uint32_t a4, unsigned char a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t, CExoLocString, uint32_t, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDialogReplyChosen);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterAreaList__0(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterAreaList__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterAreaList__1(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterAreaList__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterCreatorLists(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterCreatorLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterObjectList(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterObjectList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMastersDifficultyChange(CNWSMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMastersDifficultyChange);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterSearchByIdResult(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterSearchByIdResult);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterSearchByTagResult(CNWSMessage* thisPtr, CNWSPlayer* a0, const CExoString& a1, int32_t a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, const CExoString&, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterSearchByTagResult);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__0(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__1(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerDungeonMasterUpdatePartyList__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerExamineGui_CreatureData(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerExamineGui_CreatureData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerExamineGui_DoorData(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerExamineGui_DoorData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerExamineGui_ItemData(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerExamineGui_ItemData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerExamineGui_PlaceableData(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerExamineGui_PlaceableData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerExamineGui_TrapData(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, CNWSCreature* a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, CNWSCreature*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerExamineGui_TrapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerGameObjUpdate__0(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGameObjUpdate__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerGameObjUpdate__1(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGameObjUpdate__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerGameObjUpdate_ObjControl(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGameObjUpdate_ObjControl);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerGameObjUpdateFloatyText(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGameObjUpdateFloatyText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerGameObjUpdateVisEffect(CNWSMessage* thisPtr, CNWSPlayer* a0, uint16_t a1, uint32_t a2, uint32_t a3, unsigned char a4, unsigned char a5, Vector a6, float a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint16_t, uint32_t, uint32_t, unsigned char, unsigned char, Vector, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGameObjUpdateVisEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWSMessage__SendServerToPlayerGUICharacterSheet_NotPermitted(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGUICharacterSheet_NotPermitted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerGuiContainerObject_Status(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGuiContainerObject_Status);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGuiQuickbar_SetButton);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerGuiTimingEvent(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, unsigned char a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerGuiTimingEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerInventory_ConfirmDrop(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_ConfirmDrop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_Drop(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_Drop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_DropCancel(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_DropCancel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_Equip(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_Equip);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerInventory_EquipCancel(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_EquipCancel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerInventory_LearnScroll(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_LearnScroll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_Pickup(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_Pickup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_PickupCancel(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_PickupCancel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_RepositoryMove(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_RepositoryMove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_RepositoryMoveCancel(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_RepositoryMoveCancel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_SelectPage(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_SelectPage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerInventory_SelectPanel(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_SelectPanel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerInventory_Unequip(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_Unequip);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerInventory_UnequipCancel(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerInventory_UnequipCancel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerJournalAddQuest(CNWSMessage* thisPtr, CNWSPlayer* a0, CExoString a1, int32_t a2, uint32_t a3, uint16_t a4, int32_t a5, uint32_t a6, uint32_t a7, CExoLocString a8, CExoLocString a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CExoString, int32_t, uint32_t, uint16_t, int32_t, uint32_t, uint32_t, CExoLocString, CExoLocString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalAddQuest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

int32_t CNWSMessage__SendServerToPlayerJournalAddWorld(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, CExoString a2, CExoString a3, uint32_t a4, uint32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, CExoString, CExoString, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalAddWorld);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage__SendServerToPlayerJournalAddWorldStrref(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalAddWorldStrref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerJournalDeleteWorld(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalDeleteWorld);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerJournalDeleteWorldAll(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalDeleteWorldAll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerJournalDeleteWorldStrref(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalDeleteWorldStrref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerJournalFullUpdate(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalFullUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerJournalFullUpdateNotNeeded(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalFullUpdateNotNeeded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerJournalRemoveQuest(CNWSMessage* thisPtr, CNWSPlayer* a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalRemoveQuest);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerJournalSetQuestPicture(CNWSMessage* thisPtr, CNWSPlayer* a0, CExoString a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalSetQuestPicture);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerJournalUpdated(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, int32_t a2, CExoLocString a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, int32_t, CExoLocString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerJournalUpdated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerLevelUp_Begin(CNWSMessage* thisPtr, uint32_t a0, CNWSCreature* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLevelUp_Begin);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerLevelUp_Confirmation(CNWSMessage* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLevelUp_Confirmation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerLoadBar_EndStallEvent(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLoadBar_EndStallEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerLoadBar_StartStallEvent(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLoadBar_StartStallEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerLoadBar_UpdateStallEvent(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLoadBar_UpdateStallEvent);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerLogin_CharacterQuery(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char& a1, int32_t* a2, unsigned char* a3, uint32_t& a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char&, int32_t*, unsigned char*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLogin_CharacterQuery);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerLogin_Confirm(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLogin_Confirm);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerLogin_Fail(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLogin_Fail);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerLogin_GetWaypoint(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLogin_GetWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerLogin_NeedCharacter(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerLogin_NeedCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerMapPinAdded(CNWSMessage* thisPtr, CNWSPlayer* a0, Vector a1, CExoString a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, Vector, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerMapPinAdded);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerMapPinCreated(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, Vector a2, CExoLocString a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, Vector, CExoLocString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerMapPinCreated);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerMapPinEnabled(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerMapPinEnabled);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerMessage(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, unsigned char* a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char, unsigned char, unsigned char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerModule_DumpPlayer(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_DumpPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerModule_EndGame(CNWSMessage* thisPtr, uint32_t a0, const CExoString& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_EndGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerModule_EndStartNewModule(CNWSMessage* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_EndStartNewModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerModule_ExportReply(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_ExportReply);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerModule_Info(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_Info);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerModule_Loading(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_Loading);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerModule_SaveGameStatus(CNWSMessage* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_SaveGameStatus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerModule_SetPauseState(CNWSMessage* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_SetPauseState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerModule_StartStartNewModule(CNWSMessage* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModule_StartStartNewModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSMessage__SendServerToPlayerModuleUpdate_Time(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, uint32_t a2, uint32_t a3, uint32_t a4, uint32_t a5, unsigned char a6, uint32_t a7)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, uint32_t, uint32_t, uint32_t, uint32_t, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerModuleUpdate_Time);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7);
}

int32_t CNWSMessage__SendServerToPlayerOpenStoreInventory(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerOpenStoreInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerParty_Invite(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerParty_Invite);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerParty_List(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, uint32_t* a2, unsigned char a3, uint32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, uint32_t*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerParty_List);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerParty_TransferObjectControl(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerParty_TransferObjectControl);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerPartyBar_PanelButtonFlash(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPartyBar_PanelButtonFlash);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerPlaceableUpdate_Useable(CNWSMessage* thisPtr, CNWSPlaceable* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPlaceableUpdate_Useable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerPlayerList_Add(CNWSMessage* thisPtr, uint32_t a0, CNWSPlayer* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPlayerList_Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerPlayerList_All(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPlayerList_All);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerPlayerList_Delete(CNWSMessage* thisPtr, uint32_t a0, CNWSPlayer* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPlayerList_Delete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerPlayerList_ReauthorizeCDKey(CNWSMessage* thisPtr, uint32_t a0, const CExoString& a1, const CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPlayerList_ReauthorizeCDKey);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPlayModuleCharacterListResponse);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerPolymorph(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPolymorph);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerPopUpGUIPanel(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, CExoString a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, int32_t, int32_t, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPopUpGUIPanel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSMessage__SendServerToPlayerPVP_Attitude_Change(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerPVP_Attitude_Change);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerQuickChat(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint16_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerQuickChat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerQuickChatMessage(CNWSMessage* thisPtr, uint32_t a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerQuickChatMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerSafeProjectile(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, uint32_t a2, Vector a3, Vector a4, uint32_t a5, unsigned char a6, uint32_t a7, unsigned char a8, unsigned char a9, unsigned char a10)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, uint32_t, Vector, Vector, uint32_t, unsigned char, uint32_t, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSafeProjectile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

int32_t CNWSMessage__SendServerToPlayerSaveLoad_Status(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSaveLoad_Status);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerServerStatus_Status(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerServerStatus_Status);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerSetCustomToken(CNWSMessage* thisPtr, uint32_t a0, int32_t a1, const CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, int32_t, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSetCustomToken);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerSetCustomTokenList(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSetCustomTokenList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToPlayerShutDownServer(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerShutDownServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerSoundObject_ChangePosition(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, Vector a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSoundObject_ChangePosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerSoundObject_ChangeVolume(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSoundObject_ChangeVolume);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerSoundObject_Play(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSoundObject_Play);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerSoundObject_Stop(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerSoundObject_Stop);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerStoreConfirmTransaction(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerStoreConfirmTransaction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSMessage__SendServerToPlayerStringMessage(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1, CExoString a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerStringMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerUpdateActiveItemProperties(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSItem* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateActiveItemProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerUpdateActiveItemPropertiesUses(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, unsigned char a2, unsigned char a3, unsigned char* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, unsigned char, unsigned char, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateActiveItemPropertiesUses);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__SendServerToPlayerUpdateBlackoutEffect(CNWSMessage* thisPtr, CNWSPlayer* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateBlackoutEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerUpdateCharResponse(CNWSMessage* thisPtr, CNWSPlayer* a0, unsigned char a1, CResRef a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, unsigned char, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateCharResponse);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerUpdateFogAmount(CNWSMessage* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, unsigned char, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateFogAmount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerUpdateFogColor(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateFogColor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerUpdateItemHidden(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSItem* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateItemHidden);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerUpdateItemName(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSItem* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateItemName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerUpdateSkyBox(CNWSMessage* thisPtr, int32_t a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerUpdateSkyBox);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerVoiceChat_Play(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerVoiceChat_Play);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSMessage__SendServerToPlayerWhirlwindAttack(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSCreature* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerWhirlwindAttack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__SendServerToPlayerWhirlwindAttackDamage(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSCreature* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToPlayerWhirlwindAttackDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__SendServerToServerAdminBannedList(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminBannedList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__SendServerToServerAdminMessage(CNWSMessage* thisPtr, uint32_t a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__SendServerToServerAdminModuleList(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminModuleList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__SendServerToServerAdminPlayerList(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminPlayerList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__SendServerToServerAdminPortalList(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminPortalList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__SendServerToServerAdminSaveGameList(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminSaveGameList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__SendServerToServerAdminSaveStatus(CNWSMessage* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminSaveStatus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__SendServerToServerAdminServerSettings(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminServerSettings);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__SendServerToServerAdminServerStatus(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SendServerToServerAdminServerStatus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSPlayerLUOSortedObjectList* CNWSMessage__SortObjectsForGameObjectUpdate(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CGameObjectArray* a2, int32_t* a3)
{
    using FuncPtrType = CNWSPlayerLUOSortedObjectList*(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CGameObjectArray*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__SortObjectsForGameObjectUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__StoreValuesInLastPlayerUpdateObject(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSPlayerLastUpdateObject* a1, CLastUpdateObject* a2, uint16_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSPlayerLastUpdateObject*, CLastUpdateObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__StoreValuesInLastPlayerUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__StoreValuesInLastUpdateObject(CNWSMessage* thisPtr, CNWSPlayer* a0, CLastUpdateObject* a1, CNWSObject* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CLastUpdateObject*, CNWSObject*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__StoreValuesInLastUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSMessage__StoreValuesInLastUpdatePartyObject(CNWSMessage* thisPtr, CNWSCreature* a0, CLastUpdatePartyObject* a1, CNWSCreature* a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CLastUpdatePartyObject*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__StoreValuesInLastUpdatePartyObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__TestObjectUpdateDifferences(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject** a2, uint32_t* a3, uint32_t* a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject**, uint32_t*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__TestObjectUpdateDifferences);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSMessage__TestObjectVisible(CNWSMessage* thisPtr, CNWSObject* a0, CNWSObject* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__TestObjectVisible);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__TestPartyObjectUpdateDifferences(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSCreature* a1, CLastUpdatePartyObject** a2, uint32_t* a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSCreature*, CLastUpdatePartyObject**, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__TestPartyObjectUpdateDifferences);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__TestPlayerUpdateDifferences(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSPlayerLastUpdateObject* a1, CLastUpdateObject* a2, uint16_t& a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSPlayerLastUpdateObject*, CLastUpdateObject*, uint16_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__TestPlayerUpdateDifferences);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__UpdateLastUpdate_GuiEffectIcons(CNWSMessage* thisPtr, CNWSCreature* a0, CExoArrayListTemplatedCEffectIconObjectPtr* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CExoArrayListTemplatedCEffectIconObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdate_GuiEffectIcons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSMessage__UpdateLastUpdateActionQueue(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdateActionQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__UpdateLastUpdateAutoMap(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdateAutoMap);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__UpdateLastUpdateInventory(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1, CNWSPlayerInventoryGUI* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t, CNWSPlayerInventoryGUI*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdateInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSMessage__UpdateLastUpdateObject(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject* a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__UpdateLastUpdateObjectAppearance(CNWSMessage* thisPtr, CNWSObject* a0, CLastUpdateObject* a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CLastUpdateObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdateObjectAppearance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSMessage__UpdateLastUpdateVisibilityList(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSPlayerLastUpdateObject* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__UpdateLastUpdateVisibilityList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__WriteCExoLocStringServer(CNWSMessage* thisPtr, CExoLocString& a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CExoLocString&, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteCExoLocStringServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__WriteGameObjUpdate_CharacterSheet(CNWSMessage* thisPtr, CNWSPlayer* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_CharacterSheet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSMessage__WriteGameObjUpdate_DungeonMasterAIState(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_DungeonMasterAIState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__WriteGameObjUpdate_MajorGUIPanels(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_MajorGUIPanels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryData(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_HenchmanInventoryData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_Inventory(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSPlayerInventoryGUI* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSPlayerInventoryGUI*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_MajorGUIPanels_Inventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__WriteGameObjUpdate_MinorGUIPanels(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_MinorGUIPanels);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSMessage__WriteGameObjUpdate_PartyAIState(CNWSMessage* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_PartyAIState);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__WriteGameObjUpdate_PlayerUpdate(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSPlayerLastUpdateObject* a1, CLastUpdateObject* a2, uint16_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSPlayerLastUpdateObject*, CLastUpdateObject*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_PlayerUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__WriteGameObjUpdate_UpdateAppearance(CNWSMessage* thisPtr, CNWSObject* a0, CLastUpdateObject* a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CLastUpdateObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_UpdateAppearance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSMessage__WriteGameObjUpdate_UpdateObject(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CLastUpdateObject* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CLastUpdateObject*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_UpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSMessage__WriteGameObjUpdate_UpdateQuickbarItemUseCount(CNWSMessage* thisPtr, CNWSObject* a0, CLastUpdateObject* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_UpdateQuickbarItemUseCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__WriteGameObjUpdate_WorkRemaining(CNWSMessage* thisPtr, CNWSObject* a0, CNWSArea* a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSObject*, CNWSArea*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_WorkRemaining);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSMessage__WriteGameObjUpdate_WriteInventorySlotAdd(CNWSMessage* thisPtr, CNWSCreature* a0, CNWSItem* a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_WriteInventorySlotAdd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSMessage__WriteGameObjUpdate_WriteInventorySlotDelete(CNWSMessage* thisPtr, CNWSCreature* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_WriteInventorySlotDelete);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__WriteGameObjUpdate_WriteInventorySlotUpdate(CNWSMessage* thisPtr, uint32_t a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGameObjUpdate_WriteInventorySlotUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSMessage__WriteGuiEffectIconsUpdate(CNWSMessage* thisPtr, CNWSCreature* a0, CExoArrayListTemplatedCEffectIconObjectPtr* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSCreature*, CExoArrayListTemplatedCEffectIconObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteGuiEffectIconsUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSMessage__WriteOBJECTIDServer(CNWSMessage* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteOBJECTIDServer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSMessage__WriteRepositoryUpdate(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSObject* a1, CItemRepository* a2, CNWSPlayerLUOInventory* a3, unsigned char a4, char a5, unsigned char a6)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSObject*, CItemRepository*, CNWSPlayerLUOInventory*, unsigned char, char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteRepositoryUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

void CNWSMessage__WriteStoreInventoryUpdate(CNWSMessage* thisPtr, CNWSPlayer* a0, CNWSStore* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSMessage*, CNWSPlayer*, CNWSStore*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSMessage__WriteStoreInventoryUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
