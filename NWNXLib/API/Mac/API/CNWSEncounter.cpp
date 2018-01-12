#include "CNWSEncounter.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CEncounterSpawnPoint.hpp"
#include "CExoArrayListTemplatedfloat.hpp"
#include "CNWSArea.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSEncounter::CNWSEncounter(uint32_t a0)
{
    CNWSEncounter__CNWSEncounterCtor__0(this, a0);
}

CNWSEncounter::~CNWSEncounter()
{
    CNWSEncounter__CNWSEncounterDtor__0(this);
}

void CNWSEncounter::AddCreaturesToSpawnList(CEncounterListEntry* a0, int32_t& a1, int32_t a2, CEncounterListEntry a3)
{
    return CNWSEncounter__AddCreaturesToSpawnList(this, a0, a1, a2, a3);
}

void CNWSEncounter::AddToActivateAreaList(uint32_t a0)
{
    return CNWSEncounter__AddToActivateAreaList(this, a0);
}

void CNWSEncounter::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSEncounter__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSEncounter::AIUpdate()
{
    return CNWSEncounter__AIUpdate(this);
}

CNWSEncounter* CNWSEncounter::AsNWSEncounter()
{
    return CNWSEncounter__AsNWSEncounter(this);
}

float CNWSEncounter::CalculatePointsFromCR(float a0)
{
    return CNWSEncounter__CalculatePointsFromCR(this, a0);
}

void CNWSEncounter::CalculateSpawnPool(float a0)
{
    return CNWSEncounter__CalculateSpawnPool(this, a0);
}

void CNWSEncounter::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSEncounter__EventHandler(this, a0, a1, a2, a3, a4);
}

CExoLocString& CNWSEncounter::GetFirstName()
{
    return CNWSEncounter__GetFirstName(this);
}

int32_t CNWSEncounter::GetInActivateArea(Vector a0)
{
    return CNWSEncounter__GetInActivateArea(this, a0);
}

int32_t CNWSEncounter::GetInActivateAreaList(uint32_t a0)
{
    return CNWSEncounter__GetInActivateAreaList(this, a0);
}

int32_t CNWSEncounter::LineSegmentIntersectActivateArea(Vector a0, Vector a1)
{
    return CNWSEncounter__LineSegmentIntersectActivateArea(this, a0, a1);
}

int32_t CNWSEncounter::LoadEncounter(CResGFF* a0, CResStruct* a1)
{
    return CNWSEncounter__LoadEncounter(this, a0, a1);
}

void CNWSEncounter::LoadFractionalCRData()
{
    return CNWSEncounter__LoadFractionalCRData(this);
}

void CNWSEncounter::LoadFromTemplate(CResRef a0, int32_t a1, Vector* a2)
{
    return CNWSEncounter__LoadFromTemplate(this, a0, a1, a2);
}

void CNWSEncounter::MakeSpawnList(CEncounterListEntry* a0, int32_t& a1)
{
    return CNWSEncounter__MakeSpawnList(this, a0, a1);
}

void CNWSEncounter::PadOutCreatureCount(CEncounterListEntry* a0, int32_t& a1)
{
    return CNWSEncounter__PadOutCreatureCount(this, a0, a1);
}

int32_t CNWSEncounter::ReadEncounterFromGff(CResGFF* a0, CResStruct* a1, int32_t a2, Vector* a3)
{
    return CNWSEncounter__ReadEncounterFromGff(this, a0, a1, a2, a3);
}

void CNWSEncounter::ReadEncounterScriptsFromGff(CResGFF* a0, CResStruct* a1)
{
    return CNWSEncounter__ReadEncounterScriptsFromGff(this, a0, a1);
}

void CNWSEncounter::RemoveFromActivateAreaList(uint32_t a0)
{
    return CNWSEncounter__RemoveFromActivateAreaList(this, a0);
}

void CNWSEncounter::RemoveFromActiveCreatureCount(float a0, int32_t a1)
{
    return CNWSEncounter__RemoveFromActiveCreatureCount(this, a0, a1);
}

void CNWSEncounter::RemoveFromArea()
{
    return CNWSEncounter__RemoveFromArea(this);
}

int32_t CNWSEncounter::SaveEncounter(CResGFF* a0, CResStruct* a1)
{
    return CNWSEncounter__SaveEncounter(this, a0, a1);
}

void CNWSEncounter::SetActive(int32_t a0)
{
    return CNWSEncounter__SetActive(this, a0);
}

void CNWSEncounter::SetDifficulty(int32_t a0)
{
    return CNWSEncounter__SetDifficulty(this, a0);
}

void CNWSEncounter::SpawnEncounterCreatures()
{
    return CNWSEncounter__SpawnEncounterCreatures(this);
}

void CNWSEncounter::SpawnIfAppropriate(uint32_t a0, float a1)
{
    return CNWSEncounter__SpawnIfAppropriate(this, a0, a1);
}

void CNWSEncounter::TallyEnemyRadiusPoints()
{
    return CNWSEncounter__TallyEnemyRadiusPoints(this);
}

void CNWSEncounter::UpdateActivateAreaList(uint32_t a0)
{
    return CNWSEncounter__UpdateActivateAreaList(this, a0);
}

void CNWSEncounter__CNWSEncounterCtor__0(CNWSEncounter* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__CNWSEncounterCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSEncounter__CNWSEncounterDtor__0(CNWSEncounter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__CNWSEncounterDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSEncounter__AddCreaturesToSpawnList(CNWSEncounter* thisPtr, CEncounterListEntry* a0, int32_t& a1, int32_t a2, CEncounterListEntry a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, CEncounterListEntry*, int32_t&, int32_t, CEncounterListEntry);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__AddCreaturesToSpawnList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSEncounter__AddToActivateAreaList(CNWSEncounter* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__AddToActivateAreaList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSEncounter__AddToArea(CNWSEncounter* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSEncounter__AIUpdate(CNWSEncounter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSEncounter* CNWSEncounter__AsNWSEncounter(CNWSEncounter* thisPtr)
{
    using FuncPtrType = CNWSEncounter*(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__AsNWSEncounter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWSEncounter__CalculatePointsFromCR(CNWSEncounter* thisPtr, float a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSEncounter*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__CalculatePointsFromCR);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSEncounter__CalculateSpawnPool(CNWSEncounter* thisPtr, float a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__CalculateSpawnPool);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSEncounter__EventHandler(CNWSEncounter* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

CExoLocString& CNWSEncounter__GetFirstName(CNWSEncounter* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSEncounter__GetInActivateArea(CNWSEncounter* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEncounter*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__GetInActivateArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSEncounter__GetInActivateAreaList(CNWSEncounter* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__GetInActivateAreaList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSEncounter__LineSegmentIntersectActivateArea(CNWSEncounter* thisPtr, Vector a0, Vector a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEncounter*, Vector, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__LineSegmentIntersectActivateArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEncounter__LoadEncounter(CNWSEncounter* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEncounter*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__LoadEncounter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEncounter__LoadFractionalCRData(CNWSEncounter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__LoadFractionalCRData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSEncounter__LoadFromTemplate(CNWSEncounter* thisPtr, CResRef a0, int32_t a1, Vector* a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, CResRef, int32_t, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSEncounter__MakeSpawnList(CNWSEncounter* thisPtr, CEncounterListEntry* a0, int32_t& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, CEncounterListEntry*, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__MakeSpawnList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEncounter__PadOutCreatureCount(CNWSEncounter* thisPtr, CEncounterListEntry* a0, int32_t& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, CEncounterListEntry*, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__PadOutCreatureCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSEncounter__ReadEncounterFromGff(CNWSEncounter* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2, Vector* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEncounter*, CResGFF*, CResStruct*, int32_t, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__ReadEncounterFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSEncounter__ReadEncounterScriptsFromGff(CNWSEncounter* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__ReadEncounterScriptsFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEncounter__RemoveFromActivateAreaList(CNWSEncounter* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__RemoveFromActivateAreaList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSEncounter__RemoveFromActiveCreatureCount(CNWSEncounter* thisPtr, float a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__RemoveFromActiveCreatureCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEncounter__RemoveFromArea(CNWSEncounter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSEncounter__SaveEncounter(CNWSEncounter* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSEncounter*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__SaveEncounter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEncounter__SetActive(CNWSEncounter* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__SetActive);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSEncounter__SetDifficulty(CNWSEncounter* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__SetDifficulty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSEncounter__SpawnEncounterCreatures(CNWSEncounter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__SpawnEncounterCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSEncounter__SpawnIfAppropriate(CNWSEncounter* thisPtr, uint32_t a0, float a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__SpawnIfAppropriate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSEncounter__TallyEnemyRadiusPoints(CNWSEncounter* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__TallyEnemyRadiusPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSEncounter__UpdateActivateAreaList(CNWSEncounter* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSEncounter*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSEncounter__UpdateActivateAreaList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
