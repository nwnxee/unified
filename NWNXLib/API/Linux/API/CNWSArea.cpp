#include "CNWSArea.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CERFFile.hpp"
#include "CExoArrayListTemplatedCGameObjectPtr.hpp"
#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "CGameEffect.hpp"
#include "CNWSAmbientSound.hpp"
#include "CNWSAreaGridSuccessors.hpp"
#include "CNWSAreaGridTransTableEntry.hpp"
#include "CNWSAreaInterTileSuccessors.hpp"
#include "CNWSCreature.hpp"
#include "CNWSPlayer.hpp"
#include "CNWSTile.hpp"
#include "CNWTileSet.hpp"
#include "CPathfindInformation.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "NWAreaHeader_st.hpp"

namespace NWNXLib {

namespace API {

CNWSArea::CNWSArea(CResRef a0, int32_t a1, uint32_t a2)
{
    CNWSArea__CNWSAreaCtor(this, a0, a1, a2);
}

CNWSArea::~CNWSArea()
{
    CNWSArea__CNWSAreaDtor__0(this);
}

int32_t CNWSArea::AddObjectToArea(uint32_t a0, int32_t a1)
{
    return CNWSArea__AddObjectToArea(this, a0, a1);
}

int32_t CNWSArea::AIUpdate()
{
    return CNWSArea__AIUpdate(this);
}

void CNWSArea::ApplyEffect(CGameEffect* a0, Vector a1, Vector a2)
{
    return CNWSArea__ApplyEffect(this, a0, a1, a2);
}

CNWSArea* CNWSArea::AsNWSArea()
{
    return CNWSArea__AsNWSArea(this);
}

void CNWSArea::BudgeCreatures(const Vector& a0, const Vector& a1, const Vector& a2, uint32_t a3, int32_t a4)
{
    return CNWSArea__BudgeCreatures(this, a0, a1, a2, a3, a4);
}

int32_t CNWSArea::ClearLineOfSight(Vector a0, Vector a1, Vector* a2, uint32_t* a3, uint32_t a4, uint32_t a5, int32_t a6)
{
    return CNWSArea__ClearLineOfSight(this, a0, a1, a2, a3, a4, a5, a6);
}

Vector CNWSArea::ComputeAwayVector(Vector a0, Vector a1, float a2, CPathfindInformation* a3)
{
    return CNWSArea__ComputeAwayVector(this, a0, a1, a2, a3);
}

int32_t CNWSArea::ComputeBestCorner(float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float* a8, float* a9, float* a10, float* a11)
{
    return CNWSArea__ComputeBestCorner(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

float CNWSArea::ComputeHeight(Vector a0)
{
    return CNWSArea__ComputeHeight(this, a0);
}

int32_t CNWSArea::ComputeNonVisibleLocation(Vector a0, CPathfindInformation* a1, int32_t a2, Vector* a3, float a4)
{
    return CNWSArea__ComputeNonVisibleLocation(this, a0, a1, a2, a3, a4);
}

float CNWSArea::ComputePathDistance(int32_t a0, float* a1)
{
    return CNWSArea__ComputePathDistance(this, a0, a1);
}

int32_t CNWSArea::ComputeSafeLocation(Vector a0, float a1, CPathfindInformation* a2, int32_t a3, Vector* a4)
{
    return CNWSArea__ComputeSafeLocation(this, a0, a1, a2, a3, a4);
}

int32_t CNWSArea::ComputeSafeLocationInDirection(Vector a0, Vector a1, float a2, CPathfindInformation* a3, int32_t a4, Vector* a5)
{
    return CNWSArea__ComputeSafeLocationInDirection(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea::CountAreaTransitionTriggers(uint32_t* a0, int32_t a1, uint32_t* a2)
{
    return CNWSArea__CountAreaTransitionTriggers(this, a0, a1, a2);
}

int32_t CNWSArea::CountVisibleToPlayers(Vector a0, int32_t a1)
{
    return CNWSArea__CountVisibleToPlayers(this, a0, a1);
}

void CNWSArea::DecreaseAILevelPriority()
{
    return CNWSArea__DecreaseAILevelPriority(this);
}

void CNWSArea::DecrementPlayersInArea()
{
    return CNWSArea__DecrementPlayersInArea(this);
}

int32_t CNWSArea::EvaluateOverlappingTargets(CPathfindInformation* a0, Vector a1, uint32_t a2, float a3, float a4, float a5, int32_t a6, int32_t a7, uint32_t* a8)
{
    return CNWSArea__EvaluateOverlappingTargets(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

void CNWSArea::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSArea__EventHandler(this, a0, a1, a2, a3, a4);
}

int32_t CNWSArea::ExploreArea(CNWSCreature* a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSArea__ExploreArea(this, a0, a1, a2, a3);
}

int32_t CNWSArea::GenerateInterTilePath(int32_t* a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSArea__GenerateInterTilePath(this, a0, a1, a2, a3);
}

uint32_t CNWSArea::GetDoorCrossed(Vector a0, Vector a1)
{
    return CNWSArea__GetDoorCrossed(this, a0, a1);
}

int32_t CNWSArea::GetFirstObjectInArea(uint32_t& a0)
{
    return CNWSArea__GetFirstObjectInArea(this, a0);
}

int32_t CNWSArea::GetFirstObjectIndiceByX(int32_t* a0, float a1)
{
    return CNWSArea__GetFirstObjectIndiceByX(this, a0, a1);
}

int32_t CNWSArea::GetIsIDInExcludeList(uint32_t a0, CExoArrayListTemplatedCGameObjectPtr* a1)
{
    return CNWSArea__GetIsIDInExcludeList(this, a0, a1);
}

int32_t CNWSArea::GetNextObjectInArea(uint32_t& a0)
{
    return CNWSArea__GetNextObjectInArea(this, a0);
}

unsigned char CNWSArea::GetPVPSetting()
{
    return CNWSArea__GetPVPSetting(this);
}

int32_t CNWSArea::GetSurfaceMaterial(Vector a0)
{
    return CNWSArea__GetSurfaceMaterial(this, a0);
}

void CNWSArea::GetTile(Vector a0)
{
    return CNWSArea__GetTile(this, a0);
}

int32_t CNWSArea::GoalMoveDenied(int32_t a0, int32_t a1, int32_t a2)
{
    return CNWSArea__GoalMoveDenied(this, a0, a1, a2);
}

int32_t CNWSArea::GridDFSearch(int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    return CNWSArea__GridDFSearch(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea::GridDFSGenerateSuccessors(int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, CNWSAreaGridSuccessors** a5)
{
    return CNWSArea__GridDFSGenerateSuccessors(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea::GridDFSTransTableGet(int32_t a0, int32_t a1, int32_t* a2, int32_t* a3)
{
    return CNWSArea__GridDFSTransTableGet(this, a0, a1, a2, a3);
}

int32_t CNWSArea::GridDFSTransTableHash(int32_t a0, int32_t a1)
{
    return CNWSArea__GridDFSTransTableHash(this, a0, a1);
}

void CNWSArea::GridDFSTransTableInitialize()
{
    return CNWSArea__GridDFSTransTableInitialize(this);
}

void CNWSArea::GridDFSTransTablePut(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSArea__GridDFSTransTablePut(this, a0, a1, a2, a3);
}

int32_t CNWSArea::HandleTransparentDoors(float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    return CNWSArea__HandleTransparentDoors(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

void CNWSArea::IncreaseAILevelPriority()
{
    return CNWSArea__IncreaseAILevelPriority(this);
}

void CNWSArea::IncrementPlayersInArea()
{
    return CNWSArea__IncrementPlayersInArea(this);
}

int32_t CNWSArea::InSubAreas(Vector a0, CExoArrayListTemplatedunsignedlong* a1)
{
    return CNWSArea__InSubAreas(this, a0, a1);
}

int32_t CNWSArea::IntersectingLineSegment(Vector a0, Vector a1, CExoArrayListTemplatedunsignedlong* a2)
{
    return CNWSArea__IntersectingLineSegment(this, a0, a1, a2);
}

int32_t CNWSArea::InterTileDFS(int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    return CNWSArea__InterTileDFS(this, a0, a1, a2, a3, a4);
}

void CNWSArea::InterTileDFSExploreArea(unsigned char* a0, int32_t a1, int32_t a2, int32_t a3, float a4, float a5)
{
    return CNWSArea__InterTileDFSExploreArea(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea::InterTileDFSGenerateSuccessors(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSArea__InterTileDFSGenerateSuccessors(this, a0, a1, a2, a3);
}

int32_t CNWSArea::InterTileDFSSoundPath(unsigned char* a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    return CNWSArea__InterTileDFSSoundPath(this, a0, a1, a2, a3, a4);
}

int32_t CNWSArea::LoadArea(int32_t a0, CResGFF* a1, CResStruct* a2)
{
    return CNWSArea__LoadArea(this, a0, a1, a2);
}

int32_t CNWSArea::LoadAreaEffects(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadAreaEffects(this, a0, a1, a2);
}

int32_t CNWSArea::LoadAreaHeader(CResStruct* a0)
{
    return CNWSArea__LoadAreaHeader(this, a0);
}

int32_t CNWSArea::LoadCreatures(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadCreatures(this, a0, a1, a2);
}

int32_t CNWSArea::LoadDoors(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadDoors(this, a0, a1, a2);
}

int32_t CNWSArea::LoadEncounters(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadEncounters(this, a0, a1, a2);
}

int32_t CNWSArea::LoadGIT(int32_t a0)
{
    return CNWSArea__LoadGIT__0(this, a0);
}

void CNWSArea::LoadGIT(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadGIT__1(this, a0, a1, a2);
}

int32_t CNWSArea::LoadItems(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadItems(this, a0, a1, a2);
}

int32_t CNWSArea::LoadPlaceables(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadPlaceables(this, a0, a1, a2);
}

int32_t CNWSArea::LoadPlayers(CResGFF* a0, CResStruct* a1)
{
    return CNWSArea__LoadPlayers(this, a0, a1);
}

int32_t CNWSArea::LoadProperties(CResGFF* a0, CResStruct* a1)
{
    return CNWSArea__LoadProperties(this, a0, a1);
}

int32_t CNWSArea::LoadSounds(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadSounds(this, a0, a1, a2);
}

int32_t CNWSArea::LoadStores(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadStores(this, a0, a1, a2);
}

int32_t CNWSArea::LoadTileSetInfo(CResStruct* a0)
{
    return CNWSArea__LoadTileSetInfo(this, a0);
}

int32_t CNWSArea::LoadTriggers(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadTriggers(this, a0, a1, a2);
}

int32_t CNWSArea::LoadWaypoints(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSArea__LoadWaypoints(this, a0, a1, a2);
}

int32_t CNWSArea::NoCreaturesOnLine(float a0, float a1, float a2, float a3, CPathfindInformation* a4, int32_t a5, int32_t a6, uint32_t* a7, int32_t a8)
{
    return CNWSArea__NoCreaturesOnLine(this, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSArea::NoNoneWalkPolysInStaticObject(uint32_t a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, uint32_t a8, int32_t a9)
{
    return CNWSArea__NoNoneWalkPolysInStaticObject(this, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

CNWSArea* CNWSArea::NWAreaAsNWSArea()
{
    return CNWSArea__NWAreaAsNWSArea(this);
}

int32_t CNWSArea::PackAreaIntoMessage(int32_t a0, int32_t a1, int32_t a2, CNWSPlayer* a3)
{
    return CNWSArea__PackAreaIntoMessage(this, a0, a1, a2, a3);
}

void CNWSArea::PlayVisualEffect(uint16_t a0, Vector a1)
{
    return CNWSArea__PlayVisualEffect(this, a0, a1);
}

uint32_t CNWSArea::PlotGridPath(CPathfindInformation* a0, uint64_t a1)
{
    return CNWSArea__PlotGridPath(this, a0, a1);
}

uint32_t CNWSArea::PlotPath(CPathfindInformation* a0, uint64_t a1)
{
    return CNWSArea__PlotPath(this, a0, a1);
}

int32_t CNWSArea::PlotSoundPath(CPathfindInformation* a0)
{
    return CNWSArea__PlotSoundPath(this, a0);
}

int32_t CNWSArea::PositionWalkable(Vector a0)
{
    return CNWSArea__PositionWalkable(this, a0);
}

int32_t CNWSArea::RemoveInterTileExit(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSArea__RemoveInterTileExit(this, a0, a1, a2, a3);
}

int32_t CNWSArea::RemoveObjectFromArea(uint32_t a0)
{
    return CNWSArea__RemoveObjectFromArea(this, a0);
}

void CNWSArea::SaveArea(CERFFile* a0, CExoString& a1)
{
    return CNWSArea__SaveArea(this, a0, a1);
}

void CNWSArea::SaveAreaEffects(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveAreaEffects(this, a0, a1, a2, a3);
}

void CNWSArea::SaveCreatures(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveCreatures(this, a0, a1, a2, a3);
}

void CNWSArea::SaveDoors(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveDoors(this, a0, a1, a2, a3);
}

void CNWSArea::SaveEncounters(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveEncounters(this, a0, a1, a2, a3);
}

void CNWSArea::SaveGIT(CERFFile* a0, CExoString& a1, CExoArrayListTemplatedunsignedlong& a2)
{
    return CNWSArea__SaveGIT__0(this, a0, a1, a2);
}

void CNWSArea::SaveGIT(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveGIT__1(this, a0, a1, a2, a3);
}

void CNWSArea::SaveItems(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveItems(this, a0, a1, a2, a3);
}

void CNWSArea::SavePlaceables(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SavePlaceables(this, a0, a1, a2, a3);
}

void CNWSArea::SaveProperties(CResGFF* a0, CResStruct* a1)
{
    return CNWSArea__SaveProperties(this, a0, a1);
}

void CNWSArea::SaveSounds(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveSounds(this, a0, a1, a2, a3);
}

void CNWSArea::SaveStores(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveStores(this, a0, a1, a2, a3);
}

void CNWSArea::SaveTriggers(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveTriggers(this, a0, a1, a2, a3);
}

void CNWSArea::SaveWaypoints(CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    return CNWSArea__SaveWaypoints(this, a0, a1, a2, a3);
}

void CNWSArea::SetCurrentWeather(unsigned char a0, int32_t a1)
{
    return CNWSArea__SetCurrentWeather(this, a0, a1);
}

void CNWSArea::SmoothCornerOptimize(int32_t a0, float* a1, int32_t* a2, float** a3)
{
    return CNWSArea__SmoothCornerOptimize(this, a0, a1, a2, a3);
}

int32_t CNWSArea::SmoothPointsOnPath()
{
    return CNWSArea__SmoothPointsOnPath(this);
}

void CNWSArea::SmoothSelection(int32_t a0, float* a1, int32_t* a2, float** a3)
{
    return CNWSArea__SmoothSelection(this, a0, a1, a2, a3);
}

void CNWSArea::SmoothSelectNodes(int32_t a0, float* a1, int32_t* a2, float** a3, int32_t a4, int32_t a5)
{
    return CNWSArea__SmoothSelectNodes(this, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea::TestDirectLine(float a0, float a1, float a2, float a3, float a4, float a5, int32_t a6)
{
    return CNWSArea__TestDirectLine(this, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSArea::TestLineWalkable(float a0, float a1, float a2, float a3, float a4)
{
    return CNWSArea__TestLineWalkable(this, a0, a1, a2, a3, a4);
}

int32_t CNWSArea::TestSafeLocationPoint(Vector a0, CPathfindInformation* a1)
{
    return CNWSArea__TestSafeLocationPoint(this, a0, a1);
}

void CNWSArea::UnloadArea()
{
    return CNWSArea__UnloadArea(this);
}

void CNWSArea::UpdatePlayerAutomaps()
{
    return CNWSArea__UpdatePlayerAutomaps(this);
}

int32_t CNWSArea::UpdatePositionInObjectsArray(CGameObject* a0)
{
    return CNWSArea__UpdatePositionInObjectsArray(this, a0);
}

void CNWSArea__CNWSAreaCtor(CNWSArea* thisPtr, CResRef a0, int32_t a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResRef, int32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__CNWSAreaCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CNWSArea__CNWSAreaDtor__0(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__CNWSAreaDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSArea__AddObjectToArea(CNWSArea* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__AddObjectToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__AIUpdate(CNWSArea* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__ApplyEffect(CNWSArea* thisPtr, CGameEffect* a0, Vector a1, Vector a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CGameEffect*, Vector, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ApplyEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CNWSArea* CNWSArea__AsNWSArea(CNWSArea* thisPtr)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__AsNWSArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__BudgeCreatures(CNWSArea* thisPtr, const Vector& a0, const Vector& a1, const Vector& a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, const Vector&, const Vector&, const Vector&, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__BudgeCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSArea__ClearLineOfSight(CNWSArea* thisPtr, Vector a0, Vector a1, Vector* a2, uint32_t* a3, uint32_t a4, uint32_t a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, Vector, Vector*, uint32_t*, uint32_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ClearLineOfSight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

Vector CNWSArea__ComputeAwayVector(CNWSArea* thisPtr, Vector a0, Vector a1, float a2, CPathfindInformation* a3)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSArea*, Vector, Vector, float, CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputeAwayVector);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__ComputeBestCorner(CNWSArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, float* a8, float* a9, float* a10, float* a11)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, float, float, float, float, float, float, float, float, float*, float*, float*, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputeBestCorner);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

float CNWSArea__ComputeHeight(CNWSArea* thisPtr, Vector a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSArea*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputeHeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSArea__ComputeNonVisibleLocation(CNWSArea* thisPtr, Vector a0, CPathfindInformation* a1, int32_t a2, Vector* a3, float a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, CPathfindInformation*, int32_t, Vector*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputeNonVisibleLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

float CNWSArea__ComputePathDistance(CNWSArea* thisPtr, int32_t a0, float* a1)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSArea*, int32_t, float*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputePathDistance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__ComputeSafeLocation(CNWSArea* thisPtr, Vector a0, float a1, CPathfindInformation* a2, int32_t a3, Vector* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, float, CPathfindInformation*, int32_t, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputeSafeLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSArea__ComputeSafeLocationInDirection(CNWSArea* thisPtr, Vector a0, Vector a1, float a2, CPathfindInformation* a3, int32_t a4, Vector* a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, Vector, float, CPathfindInformation*, int32_t, Vector*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ComputeSafeLocationInDirection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea__CountAreaTransitionTriggers(CNWSArea* thisPtr, uint32_t* a0, int32_t a1, uint32_t* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t*, int32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__CountAreaTransitionTriggers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__CountVisibleToPlayers(CNWSArea* thisPtr, Vector a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__CountVisibleToPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSArea__DecreaseAILevelPriority(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__DecreaseAILevelPriority);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__DecrementPlayersInArea(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__DecrementPlayersInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSArea__EvaluateOverlappingTargets(CNWSArea* thisPtr, CPathfindInformation* a0, Vector a1, uint32_t a2, float a3, float a4, float a5, int32_t a6, int32_t a7, uint32_t* a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CPathfindInformation*, Vector, uint32_t, float, float, float, int32_t, int32_t, uint32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__EvaluateOverlappingTargets);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

void CNWSArea__EventHandler(CNWSArea* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSArea__ExploreArea(CNWSArea* thisPtr, CNWSCreature* a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CNWSCreature*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__ExploreArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__GenerateInterTilePath(CNWSArea* thisPtr, int32_t* a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GenerateInterTilePath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint32_t CNWSArea__GetDoorCrossed(CNWSArea* thisPtr, Vector a0, Vector a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetDoorCrossed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__GetFirstObjectInArea(CNWSArea* thisPtr, uint32_t& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetFirstObjectInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSArea__GetFirstObjectIndiceByX(CNWSArea* thisPtr, int32_t* a0, float a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t*, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetFirstObjectIndiceByX);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__GetIsIDInExcludeList(CNWSArea* thisPtr, uint32_t a0, CExoArrayListTemplatedCGameObjectPtr* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t, CExoArrayListTemplatedCGameObjectPtr*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetIsIDInExcludeList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__GetNextObjectInArea(CNWSArea* thisPtr, uint32_t& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetNextObjectInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSArea__GetPVPSetting(CNWSArea* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetPVPSetting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSArea__GetSurfaceMaterial(CNWSArea* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetSurfaceMaterial);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSArea__GetTile(CNWSArea* thisPtr, Vector a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GetTile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

int32_t CNWSArea__GoalMoveDenied(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GoalMoveDenied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__GridDFSearch(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GridDFSearch);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea__GridDFSGenerateSuccessors(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4, CNWSAreaGridSuccessors** a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, int32_t, int32_t, CNWSAreaGridSuccessors**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GridDFSGenerateSuccessors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea__GridDFSTransTableGet(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t* a2, int32_t* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t*, int32_t*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GridDFSTransTableGet);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__GridDFSTransTableHash(CNWSArea* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GridDFSTransTableHash);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSArea__GridDFSTransTableInitialize(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GridDFSTransTableInitialize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__GridDFSTransTablePut(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__GridDFSTransTablePut);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__HandleTransparentDoors(CNWSArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, float a6, uint32_t a7, uint32_t& a8, int32_t a9, CExoArrayListTemplatedCGameObjectPtr* a10, int32_t a11)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, float, float, float, float, float, float, float, uint32_t, uint32_t&, int32_t, CExoArrayListTemplatedCGameObjectPtr*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__HandleTransparentDoors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
}

void CNWSArea__IncreaseAILevelPriority(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__IncreaseAILevelPriority);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__IncrementPlayersInArea(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__IncrementPlayersInArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSArea__InSubAreas(CNWSArea* thisPtr, Vector a0, CExoArrayListTemplatedunsignedlong* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__InSubAreas);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__IntersectingLineSegment(CNWSArea* thisPtr, Vector a0, Vector a1, CExoArrayListTemplatedunsignedlong* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, Vector, CExoArrayListTemplatedunsignedlong*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__IntersectingLineSegment);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__InterTileDFS(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__InterTileDFS);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSArea__InterTileDFSExploreArea(CNWSArea* thisPtr, unsigned char* a0, int32_t a1, int32_t a2, int32_t a3, float a4, float a5)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, unsigned char*, int32_t, int32_t, int32_t, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__InterTileDFSExploreArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea__InterTileDFSGenerateSuccessors(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__InterTileDFSGenerateSuccessors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__InterTileDFSSoundPath(CNWSArea* thisPtr, unsigned char* a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, unsigned char*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__InterTileDFSSoundPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSArea__LoadArea(CNWSArea* thisPtr, int32_t a0, CResGFF* a1, CResStruct* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadAreaEffects(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadAreaEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadAreaHeader(CNWSArea* thisPtr, CResStruct* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadAreaHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSArea__LoadCreatures(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadDoors(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadDoors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadEncounters(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadEncounters);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadGIT__0(CNWSArea* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadGIT__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSArea__LoadGIT__1(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadGIT__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadItems(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadPlaceables(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadPlaceables);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadPlayers(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__LoadProperties(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__LoadSounds(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadSounds);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadStores(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadStores);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadTileSetInfo(CNWSArea* thisPtr, CResStruct* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadTileSetInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSArea__LoadTriggers(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadTriggers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__LoadWaypoints(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__LoadWaypoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSArea__NoCreaturesOnLine(CNWSArea* thisPtr, float a0, float a1, float a2, float a3, CPathfindInformation* a4, int32_t a5, int32_t a6, uint32_t* a7, int32_t a8)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, float, float, float, float, CPathfindInformation*, int32_t, int32_t, uint32_t*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__NoCreaturesOnLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8);
}

int32_t CNWSArea__NoNoneWalkPolysInStaticObject(CNWSArea* thisPtr, uint32_t a0, float a1, float a2, float a3, float a4, float a5, float a6, float a7, uint32_t a8, int32_t a9)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t, float, float, float, float, float, float, float, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__NoNoneWalkPolysInStaticObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9);
}

CNWSArea* CNWSArea__NWAreaAsNWSArea(CNWSArea* thisPtr)
{
    using FuncPtrType = CNWSArea*(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__NWAreaAsNWSArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSArea__PackAreaIntoMessage(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, CNWSPlayer* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__PackAreaIntoMessage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__PlayVisualEffect(CNWSArea* thisPtr, uint16_t a0, Vector a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, uint16_t, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__PlayVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSArea__PlotGridPath(CNWSArea* thisPtr, CPathfindInformation* a0, uint64_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSArea*, CPathfindInformation*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__PlotGridPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSArea__PlotPath(CNWSArea* thisPtr, CPathfindInformation* a0, uint64_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSArea*, CPathfindInformation*, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__PlotPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSArea__PlotSoundPath(CNWSArea* thisPtr, CPathfindInformation* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__PlotSoundPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSArea__PositionWalkable(CNWSArea* thisPtr, Vector a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__PositionWalkable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSArea__RemoveInterTileExit(CNWSArea* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__RemoveInterTileExit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__RemoveObjectFromArea(CNWSArea* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__RemoveObjectFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSArea__SaveArea(CNWSArea* thisPtr, CERFFile* a0, CExoString& a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CERFFile*, CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSArea__SaveAreaEffects(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveAreaEffects);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveCreatures(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveCreatures);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveDoors(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveDoors);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveEncounters(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveEncounters);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveGIT__0(CNWSArea* thisPtr, CERFFile* a0, CExoString& a1, CExoArrayListTemplatedunsignedlong& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CERFFile*, CExoString&, CExoArrayListTemplatedunsignedlong&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveGIT__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSArea__SaveGIT__1(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveGIT__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveItems(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SavePlaceables(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SavePlaceables);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveProperties(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSArea__SaveSounds(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveSounds);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveStores(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveStores);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveTriggers(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveTriggers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SaveWaypoints(CNWSArea* thisPtr, CResGFF* a0, CResStruct* a1, CExoArrayListTemplatedunsignedlong& a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, CResGFF*, CResStruct*, CExoArrayListTemplatedunsignedlong&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SaveWaypoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SetCurrentWeather(CNWSArea* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SetCurrentWeather);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSArea__SmoothCornerOptimize(CNWSArea* thisPtr, int32_t a0, float* a1, int32_t* a2, float** a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, int32_t, float*, int32_t*, float**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SmoothCornerOptimize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CNWSArea__SmoothPointsOnPath(CNWSArea* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SmoothPointsOnPath);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__SmoothSelection(CNWSArea* thisPtr, int32_t a0, float* a1, int32_t* a2, float** a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, int32_t, float*, int32_t*, float**);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SmoothSelection);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSArea__SmoothSelectNodes(CNWSArea* thisPtr, int32_t a0, float* a1, int32_t* a2, float** a3, int32_t a4, int32_t a5)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*, int32_t, float*, int32_t*, float**, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__SmoothSelectNodes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

int32_t CNWSArea__TestDirectLine(CNWSArea* thisPtr, float a0, float a1, float a2, float a3, float a4, float a5, int32_t a6)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, float, float, float, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__TestDirectLine);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5, a6);
}

int32_t CNWSArea__TestLineWalkable(CNWSArea* thisPtr, float a0, float a1, float a2, float a3, float a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, float, float, float, float, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__TestLineWalkable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSArea__TestSafeLocationPoint(CNWSArea* thisPtr, Vector a0, CPathfindInformation* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, Vector, CPathfindInformation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__TestSafeLocationPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSArea__UnloadArea(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__UnloadArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSArea__UpdatePlayerAutomaps(CNWSArea* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSArea*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__UpdatePlayerAutomaps);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSArea__UpdatePositionInObjectsArray(CNWSArea* thisPtr, CGameObject* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSArea*, CGameObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSArea__UpdatePositionInObjectsArray);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
