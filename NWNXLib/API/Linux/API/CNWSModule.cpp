#include "CNWSModule.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CERFFile.hpp"
#include "CExoArrayListTemplatedNWPlayerCharacterList_stPtr.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CNWSArea.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSPlayerTURD.hpp"
#include "CPathfindInformation.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "NWModuleEntryInfo_st.hpp"
#include "NWModuleHeader_st.hpp"

namespace NWNXLib {

namespace API {

CNWSModule::CNWSModule(CExoString a0, int32_t a1, int32_t a2)
{
    CNWSModule__CNWSModuleCtor(this, a0, a1, a2);
}

CNWSModule::~CNWSModule()
{
    CNWSModule__CNWSModuleDtor__0(this);
}

void CNWSModule::AddObjectToLimbo(uint32_t a0)
{
    return CNWSModule__AddObjectToLimbo(this, a0);
}

int32_t CNWSModule::AddObjectToLookupTable(CExoString a0, uint32_t a1)
{
    return CNWSModule__AddObjectToLookupTable(this, a0, a1);
}

void CNWSModule::AddToTURDList(CNWSPlayerTURD* a0)
{
    return CNWSModule__AddToTURDList(this, a0);
}

void CNWSModule::AddTURDsToWorld()
{
    return CNWSModule__AddTURDsToWorld(this);
}

void CNWSModule::AddWorldJournalEntry(int32_t a0, CExoString a1, CExoString a2, uint32_t a3, uint32_t a4)
{
    return CNWSModule__AddWorldJournalEntry(this, a0, a1, a2, a3, a4);
}

void CNWSModule::AddWorldJournalEntryStrref(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    return CNWSModule__AddWorldJournalEntryStrref(this, a0, a1, a2, a3);
}

int32_t CNWSModule::AIUpdate()
{
    return CNWSModule__AIUpdate(this);
}

CNWSModule* CNWSModule::AsNWSModule()
{
    return CNWSModule__AsNWSModule(this);
}

void CNWSModule::CleanUpLimboList()
{
    return CNWSModule__CleanUpLimboList(this);
}

void CNWSModule::ClearAreaVisitedFlags()
{
    return CNWSModule__ClearAreaVisitedFlags(this);
}

int32_t CNWSModule::ComputeInterAreaPath(CPathfindInformation* a0)
{
    return CNWSModule__ComputeInterAreaPath(this, a0);
}

void CNWSModule::DeleteWorldJournalAllEntries()
{
    return CNWSModule__DeleteWorldJournalAllEntries(this);
}

void CNWSModule::DeleteWorldJournalEntry(int32_t a0)
{
    return CNWSModule__DeleteWorldJournalEntry(this, a0);
}

void CNWSModule::DeleteWorldJournalEntryStrref(uint32_t a0)
{
    return CNWSModule__DeleteWorldJournalEntryStrref(this, a0);
}

void CNWSModule::DoUpdate()
{
    return CNWSModule__DoUpdate(this);
}

void CNWSModule::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSModule__EventHandler(this, a0, a1, a2, a3, a4);
}

uint32_t CNWSModule::FindObjectByTagOrdinal(const CExoString& a0, uint32_t a1)
{
    return CNWSModule__FindObjectByTagOrdinal(this, a0, a1);
}

uint32_t CNWSModule::FindObjectByTagTypeOrdinal(const CExoString& a0, int32_t a1, uint32_t a2)
{
    return CNWSModule__FindObjectByTagTypeOrdinal(this, a0, a1, a2);
}

int32_t CNWSModule::FindTagPositionInTable(char* a0)
{
    return CNWSModule__FindTagPositionInTable(this, a0);
}

uint32_t CNWSModule::GenerateInterAreaDFSSuccessors(int32_t a0, CPathfindInformation* a1, uint32_t** a2)
{
    return CNWSModule__GenerateInterAreaDFSSuccessors(this, a0, a1, a2);
}

CNWSArea* CNWSModule::GetArea(uint32_t a0)
{
    return CNWSModule__GetArea__0(this, a0);
}

CNWSArea* CNWSModule::GetArea(CResRef a0)
{
    return CNWSModule__GetArea__1(this, a0);
}

CNWSArea* CNWSModule::GetAreaByName(CExoString& a0)
{
    return CNWSModule__GetAreaByName(this, a0);
}

CNWSArea* CNWSModule::GetAreaByTag(CExoString& a0)
{
    return CNWSModule__GetAreaByTag(this, a0);
}

unsigned char* CNWSModule::GetFullCipher(CExoString a0)
{
    return CNWSModule__GetFullCipher(this, a0);
}

uint32_t CNWSModule::GetPlayerIndexInPlayerList(CNWSPlayer* a0)
{
    return CNWSModule__GetPlayerIndexInPlayerList(this, a0);
}

CNWSPlayerTURD* CNWSModule::GetPlayerTURDFromList(CNWSPlayer* a0)
{
    return CNWSModule__GetPlayerTURDFromList(this, a0);
}

uint32_t CNWSModule::GetPrimaryPlayerIndex()
{
    return CNWSModule__GetPrimaryPlayerIndex(this);
}

void CNWSModule::GetTime(uint32_t* a0, uint32_t* a1, uint32_t* a2, uint32_t* a3, unsigned char* a4, uint32_t* a5)
{
    return CNWSModule__GetTime(this, a0, a1, a2, a3, a4, a5);
}

uint32_t CNWSModule::GetWaypoint(const CExoString& a0)
{
    return CNWSModule__GetWaypoint(this, a0);
}

uint32_t CNWSModule::GetWorldJournalIndexUnique()
{
    return CNWSModule__GetWorldJournalIndexUnique(this);
}

int32_t CNWSModule::InterAreaDFS(int32_t a0, int32_t a1, CPathfindInformation* a2)
{
    return CNWSModule__InterAreaDFS(this, a0, a1, a2);
}

int32_t CNWSModule::IsObjectInLimbo(uint32_t a0)
{
    return CNWSModule__IsObjectInLimbo(this, a0);
}

unsigned char CNWSModule::IsOfficialCampaign()
{
    return CNWSModule__IsOfficialCampaign(this);
}

int32_t CNWSModule::LoadLimboCreatures(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSModule__LoadLimboCreatures(this, a0, a1, a2);
}

uint32_t CNWSModule::LoadModuleFinish()
{
    return CNWSModule__LoadModuleFinish(this);
}

uint32_t CNWSModule::LoadModuleInProgress(int32_t a0, int32_t a1)
{
    return CNWSModule__LoadModuleInProgress(this, a0, a1);
}

uint32_t CNWSModule::LoadModuleStart(CExoString a0, int32_t a1)
{
    return CNWSModule__LoadModuleStart(this, a0, a1);
}

void CNWSModule::LoadTURDList(CResGFF* a0, CResStruct* a1)
{
    return CNWSModule__LoadTURDList(this, a0, a1);
}

void CNWSModule::PackModuleIntoMessage(uint32_t a0)
{
    return CNWSModule__PackModuleIntoMessage(this, a0);
}

void CNWSModule::PackModuleResourcesIntoMessage()
{
    return CNWSModule__PackModuleResourcesIntoMessage(this);
}

void CNWSModule::PackPlayerCharacterListIntoMessage(CNWSPlayer* a0, CExoArrayListTemplatedNWPlayerCharacterList_stPtr& a1)
{
    return CNWSModule__PackPlayerCharacterListIntoMessage(this, a0, a1);
}

uint32_t CNWSModule::PlotInterAreaPath(CPathfindInformation* a0, uint32_t a1)
{
    return CNWSModule__PlotInterAreaPath(this, a0, a1);
}

uint32_t CNWSModule::PlotPath(CPathfindInformation* a0, uint32_t a1)
{
    return CNWSModule__PlotPath(this, a0, a1);
}

uint32_t CNWSModule::PlotPathInArea(CPathfindInformation* a0, uint32_t a1)
{
    return CNWSModule__PlotPathInArea(this, a0, a1);
}

void CNWSModule::PostProcess()
{
    return CNWSModule__PostProcess(this);
}

void CNWSModule::RemoveFromTURDList(CNWSPlayer* a0)
{
    return CNWSModule__RemoveFromTURDList(this, a0);
}

void CNWSModule::RemoveObjectFromLimbo(uint32_t a0)
{
    return CNWSModule__RemoveObjectFromLimbo(this, a0);
}

int32_t CNWSModule::RemoveObjectFromLookupTable(CExoString a0, uint32_t a1)
{
    return CNWSModule__RemoveObjectFromLookupTable(this, a0, a1);
}

void CNWSModule::SaveLimboCreatures(CResGFF* a0, CResStruct* a1)
{
    return CNWSModule__SaveLimboCreatures(this, a0, a1);
}

int32_t CNWSModule::SaveModuleFAC(CERFFile* a0)
{
    return CNWSModule__SaveModuleFAC(this, a0);
}

int32_t CNWSModule::SaveModuleFinish(CExoString& a0, CExoString& a1)
{
    return CNWSModule__SaveModuleFinish(this, a0, a1);
}

int32_t CNWSModule::SaveModuleIFOFinish(CResGFF* a0, CResStruct* a1, CERFFile* a2, CExoString& a3, CExoArrayListTemplatedunsignedlong& a4)
{
    return CNWSModule__SaveModuleIFOFinish(this, a0, a1, a2, a3, a4);
}

int32_t CNWSModule::SaveModuleIFOStart(CResGFF* a0, CResStruct* a1)
{
    return CNWSModule__SaveModuleIFOStart(this, a0, a1);
}

int32_t CNWSModule::SaveModuleInProgress()
{
    return CNWSModule__SaveModuleInProgress(this);
}

void CNWSModule::SaveModuleStart(CExoString& a0, CExoString& a1)
{
    return CNWSModule__SaveModuleStart(this, a0, a1);
}

int32_t CNWSModule::SavePlayers(CResGFF* a0, CResStruct* a1, CExoString& a2, CExoArrayListTemplatedunsignedlong& a3)
{
    return CNWSModule__SavePlayers(this, a0, a1, a2, a3);
}

int32_t CNWSModule::SaveStatic(CERFFile* a0, CExoString a1, uint16_t a2, int32_t a3)
{
    return CNWSModule__SaveStatic(this, a0, a1, a2, a3);
}

void CNWSModule::SaveTURDList(CResGFF* a0, CResStruct* a1)
{
    return CNWSModule__SaveTURDList(this, a0, a1);
}

void CNWSModule::SetIntraAreaGoal(CPathfindInformation* a0)
{
    return CNWSModule__SetIntraAreaGoal(this, a0);
}

void CNWSModule::TimeStopSanityCheck()
{
    return CNWSModule__TimeStopSanityCheck(this);
}

void CNWSModule::UnloadModule()
{
    return CNWSModule__UnloadModule(this);
}

void CNWSModule::UpdateTime(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CNWSModule__UpdateTime(this, a0, a1, a2);
}

void CNWSModule__CNWSModuleCtor(CNWSModule* thisPtr, CExoString a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CExoString, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__CNWSModuleCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CNWSModule__CNWSModuleDtor__0(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__CNWSModuleDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSModule__AddObjectToLimbo(CNWSModule* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AddObjectToLimbo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSModule__AddObjectToLookupTable(CNWSModule* thisPtr, CExoString a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AddObjectToLookupTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSModule__AddToTURDList(CNWSModule* thisPtr, CNWSPlayerTURD* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CNWSPlayerTURD*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AddToTURDList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__AddTURDsToWorld(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AddTURDsToWorld);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__AddWorldJournalEntry(CNWSModule* thisPtr, int32_t a0, CExoString a1, CExoString a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, int32_t, CExoString, CExoString, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AddWorldJournalEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSModule__AddWorldJournalEntryStrref(CNWSModule* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AddWorldJournalEntryStrref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSModule__AIUpdate(CNWSModule* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSModule* CNWSModule__AsNWSModule(CNWSModule* thisPtr)
{
    using FuncPtrType = CNWSModule*(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__AsNWSModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__CleanUpLimboList(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__CleanUpLimboList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__ClearAreaVisitedFlags(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__ClearAreaVisitedFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSModule__ComputeInterAreaPath(CNWSModule* thisPtr, CPathfindInformation* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__ComputeInterAreaPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__DeleteWorldJournalAllEntries(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__DeleteWorldJournalAllEntries);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__DeleteWorldJournalEntry(CNWSModule* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__DeleteWorldJournalEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__DeleteWorldJournalEntryStrref(CNWSModule* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__DeleteWorldJournalEntryStrref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__DoUpdate(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__DoUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__EventHandler(CNWSModule* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CNWSModule__FindObjectByTagOrdinal(CNWSModule* thisPtr, const CExoString& a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, const CExoString&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__FindObjectByTagOrdinal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSModule__FindObjectByTagTypeOrdinal(CNWSModule* thisPtr, const CExoString& a0, int32_t a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, const CExoString&, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__FindObjectByTagTypeOrdinal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSModule__FindTagPositionInTable(CNWSModule* thisPtr, char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__FindTagPositionInTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSModule__GenerateInterAreaDFSSuccessors(CNWSModule* thisPtr, int32_t a0, CPathfindInformation* a1, uint32_t** a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, int32_t, CPathfindInformation*, uint32_t**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GenerateInterAreaDFSSuccessors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CNWSArea* CNWSModule__GetArea__0(CNWSModule* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSModule*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetArea__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSArea* CNWSModule__GetArea__1(CNWSModule* thisPtr, CResRef a0)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSModule*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetArea__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSArea* CNWSModule__GetAreaByName(CNWSModule* thisPtr, CExoString& a0)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSModule*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetAreaByName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSArea* CNWSModule__GetAreaByTag(CNWSModule* thisPtr, CExoString& a0)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSModule*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetAreaByTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char* CNWSModule__GetFullCipher(CNWSModule* thisPtr, CExoString a0)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CNWSModule*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetFullCipher);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSModule__GetPlayerIndexInPlayerList(CNWSModule* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetPlayerIndexInPlayerList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSPlayerTURD* CNWSModule__GetPlayerTURDFromList(CNWSModule* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = CNWSPlayerTURD*(__attribute__((cdecl)) *)(CNWSModule*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetPlayerTURDFromList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSModule__GetPrimaryPlayerIndex(CNWSModule* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetPrimaryPlayerIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__GetTime(CNWSModule* thisPtr, uint32_t* a0, uint32_t* a1, uint32_t* a2, uint32_t* a3, unsigned char* a4, uint32_t* a5)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t*, uint32_t*, uint32_t*, uint32_t*, unsigned char*, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

uint32_t CNWSModule__GetWaypoint(CNWSModule* thisPtr, const CExoString& a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetWaypoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSModule__GetWorldJournalIndexUnique(CNWSModule* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__GetWorldJournalIndexUnique);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSModule__InterAreaDFS(CNWSModule* thisPtr, int32_t a0, int32_t a1, CPathfindInformation* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, int32_t, int32_t, CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__InterAreaDFS);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSModule__IsObjectInLimbo(CNWSModule* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__IsObjectInLimbo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSModule__IsOfficialCampaign(CNWSModule* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__IsOfficialCampaign);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSModule__LoadLimboCreatures(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__LoadLimboCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CNWSModule__LoadModuleFinish(CNWSModule* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__LoadModuleFinish);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSModule__LoadModuleInProgress(CNWSModule* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__LoadModuleInProgress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSModule__LoadModuleStart(CNWSModule* thisPtr, CExoString a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, CExoString, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__LoadModuleStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSModule__LoadTURDList(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__LoadTURDList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSModule__PackModuleIntoMessage(CNWSModule* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PackModuleIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__PackModuleResourcesIntoMessage(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PackModuleResourcesIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__PackPlayerCharacterListIntoMessage(CNWSModule* thisPtr, CNWSPlayer* a0, CExoArrayListTemplatedNWPlayerCharacterList_stPtr& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CNWSPlayer*, CExoArrayListTemplatedNWPlayerCharacterList_stPtr&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PackPlayerCharacterListIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSModule__PlotInterAreaPath(CNWSModule* thisPtr, CPathfindInformation* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, CPathfindInformation*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PlotInterAreaPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSModule__PlotPath(CNWSModule* thisPtr, CPathfindInformation* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, CPathfindInformation*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PlotPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSModule__PlotPathInArea(CNWSModule* thisPtr, CPathfindInformation* a0, uint32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSModule*, CPathfindInformation*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PlotPathInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSModule__PostProcess(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__PostProcess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__RemoveFromTURDList(CNWSModule* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__RemoveFromTURDList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__RemoveObjectFromLimbo(CNWSModule* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__RemoveObjectFromLimbo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSModule__RemoveObjectFromLookupTable(CNWSModule* thisPtr, CExoString a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CExoString, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__RemoveObjectFromLookupTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSModule__SaveLimboCreatures(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveLimboCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSModule__SaveModuleFAC(CNWSModule* thisPtr, CERFFile* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CERFFile*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveModuleFAC);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSModule__SaveModuleFinish(CNWSModule* thisPtr, CExoString& a0, CExoString& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveModuleFinish);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSModule__SaveModuleIFOFinish(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1, CERFFile* a2, CExoString& a3, CExoArrayListTemplatedunsignedlong& a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*, CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveModuleIFOFinish);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSModule__SaveModuleIFOStart(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveModuleIFOStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSModule__SaveModuleInProgress(CNWSModule* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveModuleInProgress);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__SaveModuleStart(CNWSModule* thisPtr, CExoString& a0, CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CExoString&, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveModuleStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSModule__SavePlayers(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1, CExoString& a2, CExoArrayListTemplatedunsignedlong& a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*, CExoString&, CExoArrayListTemplatedunsignedlong&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SavePlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSModule__SaveStatic(CNWSModule* thisPtr, CERFFile* a0, CExoString a1, uint16_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSModule*, CERFFile*, CExoString, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveStatic);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSModule__SaveTURDList(CNWSModule* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SaveTURDList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSModule__SetIntraAreaGoal(CNWSModule* thisPtr, CPathfindInformation* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__SetIntraAreaGoal);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSModule__TimeStopSanityCheck(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__TimeStopSanityCheck);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__UnloadModule(CNWSModule* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__UnloadModule);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSModule__UpdateTime(CNWSModule* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSModule*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSModule__UpdateTime);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
