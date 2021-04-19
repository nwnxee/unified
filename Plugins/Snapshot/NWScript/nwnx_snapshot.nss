/// @addtogroup snapshot Snapshot
/// @brief Functions to create cool object snapshots with filters!
/// @{
/// @file nwnx_snapshot.nss
#include "nwnx"

const string NWNX_Snapshot = "NWNX_Snapshot"; ///< @private

const int NWNX_SNAPSHOT_COMPARISON_EQUALS                           = 0;
const int NWNX_SNAPSHOT_COMPARISON_NOT_EQUALS                       = 1;
const int NWNX_SNAPSHOT_COMPARISON_GREATER_THAN                     = 2;
const int NWNX_SNAPSHOT_COMPARISON_LESSER_THAN                      = 3;
const int NWNX_SNAPSHOT_COMPARISON_GREATER_THAN_OR_EQUALS           = 4;
const int NWNX_SNAPSHOT_COMPARISON_LESSER_THAN_OR_EQUALS            = 5;

const int NWNX_SNAPSHOT_FILTER_TYPE_TAG                             = 1;
const int NWNX_SNAPSHOT_FILTER_TYPE_LOCALVAR                        = 2;
const int NWNX_SNAPSHOT_FILTER_TYPE_CREATURE                        = 3;
const int NWNX_SNAPSHOT_FILTER_TYPE_LOCATION                        = 4;
const int NWNX_SNAPSHOT_FILTER_TYPE_APPEARANCE                      = 5;
const int NWNX_SNAPSHOT_FILTER_TYPE_EFFECT                          = 6;
const int NWNX_SNAPSHOT_FILTER_TYPE_CUSTOM                          = 7;
const int NWNX_SNAPSHOT_FILTER_TYPE_REPUTATION                      = 8;

const int NWNX_SNAPSHOT_FILTER_SUBTYPE_DEFAULT                              = 0;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_STRING_REGEX                         = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCALVAR_INT                         = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCALVAR_FLOAT                       = 2;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCALVAR_OBJECT                      = 3;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCALVAR_STRING                      = 4;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_ABILITY                     = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_ABILITY_MOD                 = 2;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_HAS_CLASS                   = 3;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_HAS_CLASS_OF_LEVEL          = 4;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_IS_PLAYER_CHARACTER         = 5;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_RACIAL_TYPE                 = 6;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_LEVEL                       = 7;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_HAS_FEAT                    = 8;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_EXPERIENCE                  = 9;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_GOLD                        = 10;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_POISONED                    = 11;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_DISEASED                    = 12;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_SOUND_SET                   = 13;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CREATURE_PERCEPTION                  = 14;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCATION_AREA                        = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCATION_X                           = 2;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCATION_Y                           = 3;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCATION_Z                           = 4;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_LOCATION_ORIENTATION                 = 5;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_APPEARANCE_TYPE_CREATURE             = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_APPEARANCE_TYPE_PLACEABLE            = 2;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_EFFECT_HAS_SPELL_EFFECT              = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_EFFECT_HAS_FEAT_EFFECT               = 2;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_CUSTOM_RUN_CONDITIONAL_SCRIPT        = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_REPUTATION_GET_REPUTATION            = 1;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_REPUTATION_IS_FRIEND                 = 2;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_REPUTATION_IS_NEUTRAL                = 3;
const int NWNX_SNAPSHOT_FILTER_SUBTYPE_REPUTATION_IS_ENEMY                  = 4;

struct NWNX_Snapshot_Filter
{
    int nType;
    int nSubtype;
    int nComparison;
    int bInvert;

    int nParam1;
    int nParam2;
    string sParam1;
    string sParam2;
    float fParam1;
    float fParam2;
    object oParam1;
    object oParam2;
};

/// @brief Create a snapshot of objects that are within a shape.
/// @note Filters for nSnapshotID=0 will be automatically cleared after this call.
/// @param nShape One of SHAPE_*
/// @param fSize Depends on nShape:
///     SHAPE_SPHERE: the radius of the sphere.
///     SHAPE_SPELLCYLINDER: the length of the cylinder. Spell Cylinder's always have a radius of 1.5m.
///     SHAPE_CONE: the widest radius of the cone.
///     SHAPE_SPELLCONE: the length of the cone in the direction of locTarget. Spell cones are always 60 degrees with the origin at OBJECT_SELF.
///     SHAPE_CUBE: half the length of one of the sides of the cube.
/// @param locTarget This is the centre of the effect, usually GetSpellTargetLocation(), or the end of a cylinder or cone.
/// @param bLineOfSight Controls whether to do a line-of-sight check on the object returned. The line of sight check is done from origin to target object at a height 1m above the ground.
/// @param nObjectFilter This allows you to filter out undesired object types, using bitwise "or". For example, to return only creatures and doors, the value for this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR.
/// @param vOrigin This is only used for cylinders and cones, and specifies the origin of the effect(normally the spell-caster's position).
/// @param nSnapshotID An optional ID for this snapshot. Useful if you want to nest calls to this function.
/// @return The amount of objects in the snapshot.
int NWNX_Snapshot_CreateAreaShapeSnapshot(int nShape, float fSize, location locTarget, int bLineOfSight, int nObjectFilter, vector vOrigin, int nSnapshotID = 0);

/// @brief Create a snapshot of objects that are within an area.
/// @note Filters for nSnapshotID=0 will be automatically cleared after this call.
/// @param oArea The area.
/// @param nObjectFilter This allows you to filter out undesired object types, using bitwise "or". For example, to return only creatures and doors, the value for this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR.
/// @param nSnapshotID An optional ID for this snapshot. Useful if you want to nest calls to this function.
/// @return The amount of objects in the snapshot.
int NWNX_Snapshot_CreateAreaSnapshot(object oArea, int nObjectFilter = OBJECT_TYPE_CREATURE, int nSnapshotID = 0);

/// @brief Create a snapshot of objects that are within the whole module.
/// @note Filters for nSnapshotID=0 will be automatically cleared after this call.
/// @note Does not include player characters.
/// @param nObjectFilter This allows you to filter out undesired object types, using bitwise "or". For example, to return only creatures and doors, the value for this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR.
/// @param nSnapshotID An optional ID for this snapshot. Useful if you want to nest calls to this function.
/// @return The amount of objects in the snapshot.
int NWNX_Snapshot_CreateModuleSnapshot(int nObjectFilter = OBJECT_TYPE_CREATURE, int nSnapshotID = 0);

/// @brief Create a snapshot of player objects.
/// @note Filters for nSnapshotID=0 will be automatically cleared after this call.
/// @param nSnapshotID An optional ID for this snapshot. Useful if you want to nest calls to this function.
/// @return The amount of objects in the snapshot.
int NWNX_Snapshot_CreatePlayerSnapshot(int nSnapshotID = 0);

/// @brief Gets the object at nIndex from a snapshot.
/// @param nIndex The index of the object to get.
/// @param nSnapshotID An optional ID to get objects from a specific snapshot.
/// @return The object at nIndex or OBJECT_INVALID;
object NWNX_Snapshot_GetObjectFromSnapshot(int nIndex, int nSnapshotID = 0);

/// @brief Prune all invalid objects from a snapshot.
/// @param nSnapshotID An optional ID to prune a specific snapshot.
/// @return The number of objects in the snapshot after pruning.
int NWNX_Snapshot_PruneSnapshot(int nSnapshotID = 0);

/// @brief Clear a snapshot, removing all objects.
/// @param nSnapshotID An optional snapshot ID to clear a specific snapshot.
void NWNX_Snapshot_ClearSnapshot(int nSnapshotID = 0);

/// @brief Sort a snapshot by distance to oTarget.
/// @note When sorting by descending, objects in a different area than oTarget will be at the front.
/// @param oTarget The target.
/// @param bAscending TRUE to sort ascending, FALSE for descending.
/// @param nSnapshotID An optional snapshot ID.
void NWNX_Snapshot_SortSnapshotByDistance(object oTarget, int bAscending = TRUE, int nSnapshotID = 0);

/// @brief Add a filter to nSnapshotID, should be called before creating a snapshot.
/// @param nSnapshotID A snapshot ID.
/// @param strFilter A NWNX_Snapshot_Filter struct.
void NWNX_Snapshot_AddFilter(int nSnapshotID, struct NWNX_Snapshot_Filter strFilter);

/// @brief Remove all filters associated with nSnapshotID.
/// @param nSnapshotID A snapshot ID.
void NWNX_Snapshot_ClearFilters(int nSnapshotID);

/// @}

int NWNX_Snapshot_CreateAreaShapeSnapshot(int nShape, float fSize, location locTarget, int bLineOfSight, int nObjectFilter, vector vOrigin, int nSnapshotID = 0)
{
    object oArea = GetAreaFromLocation(locTarget);
    vector vPosition = GetPositionFromLocation(locTarget);

    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_PushArgumentFloat(vOrigin.z);
    NWNX_PushArgumentFloat(vOrigin.y);
    NWNX_PushArgumentFloat(vOrigin.x);
    NWNX_PushArgumentInt(nObjectFilter);
    NWNX_PushArgumentInt(bLineOfSight);
    NWNX_PushArgumentFloat(vPosition.z);
    NWNX_PushArgumentFloat(vPosition.y);
    NWNX_PushArgumentFloat(vPosition.x);
    NWNX_PushArgumentObject(oArea);
    NWNX_PushArgumentFloat(fSize);
    NWNX_PushArgumentInt(nShape);
    NWNX_CallFunction(NWNX_Snapshot, "CreateAreaShapeSnapshot");

    return NWNX_GetReturnValueInt();
}

int NWNX_Snapshot_CreateAreaSnapshot(object oArea, int nObjectFilter = OBJECT_TYPE_CREATURE, int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_PushArgumentInt(nObjectFilter);
    NWNX_PushArgumentObject(oArea);
    NWNX_CallFunction(NWNX_Snapshot, "CreateAreaSnapshot");

    return NWNX_GetReturnValueInt();
}

int NWNX_Snapshot_CreateModuleSnapshot(int nObjectFilter = OBJECT_TYPE_CREATURE, int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_PushArgumentInt(nObjectFilter);
    NWNX_CallFunction(NWNX_Snapshot, "CreateModuleSnapshot");

    return NWNX_GetReturnValueInt();
}

int NWNX_Snapshot_CreatePlayerSnapshot(int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_CallFunction(NWNX_Snapshot, "CreatePlayerSnapshot");

    return NWNX_GetReturnValueInt();
}

object NWNX_Snapshot_GetObjectFromSnapshot(int nIndex, int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_PushArgumentInt(nIndex);
    NWNX_CallFunction(NWNX_Snapshot, "GetObjectFromSnapshot");

    return NWNX_GetReturnValueObject();
}

int NWNX_Snapshot_PruneSnapshot(int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_CallFunction(NWNX_Snapshot, "PruneSnapshot");

    return NWNX_GetReturnValueInt();
}

void NWNX_Snapshot_ClearSnapshot(int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_CallFunction(NWNX_Snapshot, "ClearSnapshot");
}

void NWNX_Snapshot_SortSnapshotByDistance(object oTarget, int bAscending = TRUE, int nSnapshotID = 0)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_PushArgumentInt(bAscending);
    NWNX_PushArgumentObject(oTarget);
    NWNX_CallFunction(NWNX_Snapshot, "SortSnapshotByDistance");
}

void NWNX_Snapshot_AddFilter(int nSnapshotID, struct NWNX_Snapshot_Filter strFilter)
{
    NWNX_PushArgumentObject(strFilter.oParam2);
    NWNX_PushArgumentObject(strFilter.oParam1);
    NWNX_PushArgumentFloat(strFilter.fParam2);
    NWNX_PushArgumentFloat(strFilter.fParam1);
    NWNX_PushArgumentString(strFilter.sParam2);
    NWNX_PushArgumentString(strFilter.sParam1);
    NWNX_PushArgumentInt(strFilter.nParam2);
    NWNX_PushArgumentInt(strFilter.nParam1);
    NWNX_PushArgumentInt(strFilter.bInvert);
    NWNX_PushArgumentInt(strFilter.nComparison);
    NWNX_PushArgumentInt(strFilter.nSubtype);
    NWNX_PushArgumentInt(strFilter.nType);
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_CallFunction(NWNX_Snapshot, "AddFilter");
}

void NWNX_Snapshot_ClearFilters(int nSnapshotID)
{
    NWNX_PushArgumentInt(nSnapshotID);
    NWNX_CallFunction(NWNX_Snapshot, "ClearFilters");
}
