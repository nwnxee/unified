#include "CNWSPlayer.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListTemplatedCLastUpdateObject.hpp"
#include "CExoLinkedListTemplatedCLastUpdatePartyObject.hpp"
#include "CLastUpdateObject.hpp"
#include "CNWSCreature.hpp"
#include "CNWSItem.hpp"
#include "CNWSObject.hpp"
#include "CNWSPlayerCharSheetGUI.hpp"
#include "CNWSPlayerInventoryGUI.hpp"
#include "CNWSPlayerJournalQuest.hpp"
#include "CNWSPlayerLastUpdateObject.hpp"
#include "CNWSPlayerStoreGUI.hpp"
#include "CNWSPlayerTURD.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayer::CNWSPlayer(uint32_t a0)
{
    CNWSPlayer__CNWSPlayerCtor__0(this, a0);
}

CNWSPlayer::~CNWSPlayer()
{
    CNWSPlayer__CNWSPlayerDtor__0(this);
}

int32_t CNWSPlayer::AddArea(uint32_t a0)
{
    return CNWSPlayer__AddArea(this, a0);
}

void CNWSPlayer::AddDMAbilities(CNWSCreature* a0)
{
    return CNWSPlayer__AddDMAbilities(this, a0);
}

void CNWSPlayer::AllocateAreas(int32_t a0)
{
    return CNWSPlayer__AllocateAreas(this, a0);
}

CNWSPlayer* CNWSPlayer::AsNWSPlayer()
{
    return CNWSPlayer__AsNWSPlayer(this);
}

int32_t CNWSPlayer::BackupServerCharacter(const CExoString& a0)
{
    return CNWSPlayer__BackupServerCharacter(this, a0);
}

void CNWSPlayer::CleanMyTURDs()
{
    return CNWSPlayer__CleanMyTURDs(this);
}

void CNWSPlayer::ClearPlayerLastUpdateObject()
{
    return CNWSPlayer__ClearPlayerLastUpdateObject(this);
}

void CNWSPlayer::ClearPlayerOnDestroyGame()
{
    return CNWSPlayer__ClearPlayerOnDestroyGame(this);
}

CNWSPlayerLastUpdateObject* CNWSPlayer::CreateNewPlayerLastUpdateObject()
{
    return CNWSPlayer__CreateNewPlayerLastUpdateObject(this);
}

void CNWSPlayer::DropTURD()
{
    return CNWSPlayer__DropTURD(this);
}

void CNWSPlayer::EatTURD(CNWSPlayerTURD* a0)
{
    return CNWSPlayer__EatTURD(this, a0);
}

int32_t CNWSPlayer::GetCharacterInfoFromIFO(unsigned char& a0, int32_t* a1, unsigned char* a2, uint32_t& a3)
{
    return CNWSPlayer__GetCharacterInfoFromIFO(this, a0, a1, a2, a3);
}

CNWSObject* CNWSPlayer::GetGameObject()
{
    return CNWSPlayer__GetGameObject(this);
}

int32_t CNWSPlayer::GetIsAllowedToSave()
{
    return CNWSPlayer__GetIsAllowedToSave(this);
}

CLastUpdateObject* CNWSPlayer::GetLastUpdateObject(uint32_t a0)
{
    return CNWSPlayer__GetLastUpdateObject(this, a0);
}

CExoString CNWSPlayer::GetPlayerName()
{
    return CNWSPlayer__GetPlayerName(this);
}

int32_t CNWSPlayer::HasExpansionPack(unsigned char a0, int32_t a1)
{
    return CNWSPlayer__HasExpansionPack(this, a0, a1);
}

CNWSCreature* CNWSPlayer::LoadCharacterFromIFO(uint32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    return CNWSPlayer__LoadCharacterFromIFO(this, a0, a1, a2, a3, a4);
}

uint32_t CNWSPlayer::LoadCreatureData(CResRef a0, CNWSCreature* a1)
{
    return CNWSPlayer__LoadCreatureData(this, a0, a1);
}

uint32_t CNWSPlayer::LoadDMCharacter()
{
    return CNWSPlayer__LoadDMCharacter(this);
}

uint32_t CNWSPlayer::LoadLocalCharacter()
{
    return CNWSPlayer__LoadLocalCharacter(this);
}

uint32_t CNWSPlayer::LoadServerCharacter(CResRef a0, int32_t a1)
{
    return CNWSPlayer__LoadServerCharacter(this, a0, a1);
}

void CNWSPlayer::LoadTURDInfoFromIFO(uint32_t a0)
{
    return CNWSPlayer__LoadTURDInfoFromIFO(this, a0);
}

int32_t CNWSPlayer::PackCreatureIntoMessage()
{
    return CNWSPlayer__PackCreatureIntoMessage(this);
}

int32_t CNWSPlayer::PermittedToDisplayCharacterSheet(uint32_t a0)
{
    return CNWSPlayer__PermittedToDisplayCharacterSheet(this, a0);
}

void CNWSPlayer::RestoreCameraSettings()
{
    return CNWSPlayer__RestoreCameraSettings(this);
}

int32_t CNWSPlayer::SaveServerCharacter(int32_t a0)
{
    return CNWSPlayer__SaveServerCharacter(this, a0);
}

void CNWSPlayer::SetAreaTransitionBMP(int32_t a0, CExoString a1)
{
    return CNWSPlayer__SetAreaTransitionBMP(this, a0, a1);
}

void CNWSPlayer::SetGameObject(CNWSObject* a0)
{
    return CNWSPlayer__SetGameObject(this, a0);
}

void CNWSPlayer::StoreCameraSettings()
{
    return CNWSPlayer__StoreCameraSettings(this);
}

void CNWSPlayer::StripAllInvalidItemPropertiesInInventory(CNWSCreature* a0)
{
    return CNWSPlayer__StripAllInvalidItemPropertiesInInventory(this, a0);
}

void CNWSPlayer::StripAllInvalidItemPropertiesOnItem(CNWSItem* a0)
{
    return CNWSPlayer__StripAllInvalidItemPropertiesOnItem(this, a0);
}

uint32_t CNWSPlayer::ValidateCharacter(int32_t* a0)
{
    return CNWSPlayer__ValidateCharacter(this, a0);
}

void CNWSPlayer::ValidateCharacter_SetNormalBonusFlags(uint16_t a0, int32_t& a1, int32_t& a2, unsigned char a3)
{
    return CNWSPlayer__ValidateCharacter_SetNormalBonusFlags(this, a0, a1, a2, a3);
}

void CNWSPlayer__CNWSPlayerCtor__0(CNWSPlayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__CNWSPlayerCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSPlayer__CNWSPlayerDtor__0(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__CNWSPlayerDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSPlayer__AddArea(CNWSPlayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__AddArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__AddDMAbilities(CNWSPlayer* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__AddDMAbilities);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__AllocateAreas(CNWSPlayer* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__AllocateAreas);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSPlayer* CNWSPlayer__AsNWSPlayer(CNWSPlayer* thisPtr)
{
    using FuncPtrType = CNWSPlayer*(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__AsNWSPlayer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlayer__BackupServerCharacter(CNWSPlayer* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__BackupServerCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__CleanMyTURDs(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__CleanMyTURDs);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayer__ClearPlayerLastUpdateObject(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__ClearPlayerLastUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayer__ClearPlayerOnDestroyGame(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__ClearPlayerOnDestroyGame);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlayerLastUpdateObject* CNWSPlayer__CreateNewPlayerLastUpdateObject(CNWSPlayer* thisPtr)
{
    using FuncPtrType = CNWSPlayerLastUpdateObject*(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__CreateNewPlayerLastUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayer__DropTURD(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__DropTURD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayer__EatTURD(CNWSPlayer* thisPtr, CNWSPlayerTURD* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__EatTURD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSPlayer__GetCharacterInfoFromIFO(CNWSPlayer* thisPtr, unsigned char& a0, int32_t* a1, unsigned char* a2, uint32_t& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*, unsigned char&, int32_t*, unsigned char*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__GetCharacterInfoFromIFO);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

CNWSObject* CNWSPlayer__GetGameObject(CNWSPlayer* thisPtr)
{
    using FuncPtrType = CNWSObject*(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__GetGameObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlayer__GetIsAllowedToSave(CNWSPlayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__GetIsAllowedToSave);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CLastUpdateObject* CNWSPlayer__GetLastUpdateObject(CNWSPlayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = CLastUpdateObject*(__attribute__((cdecl)) *)(CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__GetLastUpdateObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWSPlayer__GetPlayerName(CNWSPlayer* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__GetPlayerName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlayer__HasExpansionPack(CNWSPlayer* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__HasExpansionPack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSCreature* CNWSPlayer__LoadCharacterFromIFO(CNWSPlayer* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = CNWSCreature*(__attribute__((cdecl)) *)(CNWSPlayer*, uint32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__LoadCharacterFromIFO);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CNWSPlayer__LoadCreatureData(CNWSPlayer* thisPtr, CResRef a0, CNWSCreature* a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayer*, CResRef, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__LoadCreatureData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSPlayer__LoadDMCharacter(CNWSPlayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__LoadDMCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSPlayer__LoadLocalCharacter(CNWSPlayer* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__LoadLocalCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSPlayer__LoadServerCharacter(CNWSPlayer* thisPtr, CResRef a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayer*, CResRef, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__LoadServerCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayer__LoadTURDInfoFromIFO(CNWSPlayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__LoadTURDInfoFromIFO);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSPlayer__PackCreatureIntoMessage(CNWSPlayer* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__PackCreatureIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlayer__PermittedToDisplayCharacterSheet(CNWSPlayer* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__PermittedToDisplayCharacterSheet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__RestoreCameraSettings(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__RestoreCameraSettings);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlayer__SaveServerCharacter(CNWSPlayer* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayer*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__SaveServerCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__SetAreaTransitionBMP(CNWSPlayer* thisPtr, int32_t a0, CExoString a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, int32_t, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__SetAreaTransitionBMP);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayer__SetGameObject(CNWSPlayer* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__SetGameObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__StoreCameraSettings(CNWSPlayer* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__StoreCameraSettings);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayer__StripAllInvalidItemPropertiesInInventory(CNWSPlayer* thisPtr, CNWSCreature* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, CNWSCreature*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__StripAllInvalidItemPropertiesInInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__StripAllInvalidItemPropertiesOnItem(CNWSPlayer* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__StripAllInvalidItemPropertiesOnItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSPlayer__ValidateCharacter(CNWSPlayer* thisPtr, int32_t* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayer*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__ValidateCharacter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayer__ValidateCharacter_SetNormalBonusFlags(CNWSPlayer* thisPtr, uint16_t a0, int32_t& a1, int32_t& a2, unsigned char a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayer*, uint16_t, int32_t&, int32_t&, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayer__ValidateCharacter_SetNormalBonusFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
