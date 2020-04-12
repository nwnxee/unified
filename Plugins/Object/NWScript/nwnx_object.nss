/// @addtogroup object Object
/// @brief Functions exposing additional object properties.
/// @{
/// @file nwnx_object.nss
#include "nwnx"

const string NWNX_Object = "NWNX_Object"; ///< @private

/// @anchor object_localvar_types
/// @name Local Variable Types
/// @{
const int NWNX_OBJECT_LOCALVAR_TYPE_INT      = 1;
const int NWNX_OBJECT_LOCALVAR_TYPE_FLOAT    = 2;
const int NWNX_OBJECT_LOCALVAR_TYPE_STRING   = 3;
const int NWNX_OBJECT_LOCALVAR_TYPE_OBJECT   = 4;
const int NWNX_OBJECT_LOCALVAR_TYPE_LOCATION = 5;
/// @}

/// @anchor object_internal_types
/// @name Internal Object Types
/// @{
const int NWNX_OBJECT_TYPE_INTERNAL_INVALID = -1;
const int NWNX_OBJECT_TYPE_INTERNAL_GUI = 1;
const int NWNX_OBJECT_TYPE_INTERNAL_TILE = 2;
const int NWNX_OBJECT_TYPE_INTERNAL_MODULE = 3;
const int NWNX_OBJECT_TYPE_INTERNAL_AREA = 4;
const int NWNX_OBJECT_TYPE_INTERNAL_CREATURE = 5;
const int NWNX_OBJECT_TYPE_INTERNAL_ITEM = 6;
const int NWNX_OBJECT_TYPE_INTERNAL_TRIGGER = 7;
const int NWNX_OBJECT_TYPE_INTERNAL_PROJECTILE = 8;
const int NWNX_OBJECT_TYPE_INTERNAL_PLACEABLE = 9;
const int NWNX_OBJECT_TYPE_INTERNAL_DOOR = 10;
const int NWNX_OBJECT_TYPE_INTERNAL_AREAOFEFFECT = 11;
const int NWNX_OBJECT_TYPE_INTERNAL_WAYPOINT = 12;
const int NWNX_OBJECT_TYPE_INTERNAL_ENCOUNTER = 13;
const int NWNX_OBJECT_TYPE_INTERNAL_STORE = 14;
const int NWNX_OBJECT_TYPE_INTERNAL_PORTAL = 15;
const int NWNX_OBJECT_TYPE_INTERNAL_SOUND = 16;
/// @}

/// A local variable structure.
struct NWNX_Object_LocalVariable
{
    int type; ///< Int, String, Float, Object
    string key; ///< Name of the variable
};

/// @brief Gets the count of all local variables.
/// @param obj The object.
/// @return The count.
int NWNX_Object_GetLocalVariableCount(object obj);

/// @brief Gets the local variable at the provided index of the provided object.
/// @param obj The object.
/// @param index The index.
/// @note Index bounds: 0 >= index < NWNX_Object_GetLocalVariableCount().
/// @return An NWNX_Object_LocalVariable struct.
struct NWNX_Object_LocalVariable NWNX_Object_GetLocalVariable(object obj, int index);

/// @brief Convert an object id to the actual object.
/// @param id The object id.
/// @return An object from the provided object ID.
/// @remark This is the counterpart to ObjectToString.
object NWNX_Object_StringToObject(string id);

/// @brief Set an object's position.
/// @param obj The object.
/// @param pos A vector position.
void NWNX_Object_SetPosition(object obj, vector pos);

/// @brief Set an object's hit points.
/// @param obj The object.
/// @param hp The hit points.
void NWNX_Object_SetCurrentHitPoints(object obj, int hp);

/// @brief Adjust an object's maximum hit points
/// @note Will not work on PCs.
/// @param obj The object.
/// @param hp The maximum hit points.
void NWNX_Object_SetMaxHitPoints(object obj, int hp);

/// @brief Serialize a full object to a base64 string
/// @param obj The object.
/// @return A base64 string representation of the object.
/// @note includes locals, inventory, etc
string NWNX_Object_Serialize(object obj);

/// @brief Deserialize the object.
/// @note The object will be created outside of the world and needs to be manually positioned at a location/inventory.
/// @param serialized The base64 string.
/// @return The object.
object NWNX_Object_Deserialize(string serialized);

/// @brief Gets the dialog resref.
/// @param obj The object.
/// @return The name of the dialog resref.
string NWNX_Object_GetDialogResref(object obj);

/// @brief Sets the dialog resref.
/// @param obj The object.
/// @param dialog The name of the dialog resref.
void NWNX_Object_SetDialogResref(object obj, string dialog);

/// @brief Set an object's appearance.
/// @note Will not update for PCs until they re-enter the area.
/// @param obj The object.
/// @param app The appearance id.
void NWNX_Object_SetAppearance(object obj, int app);

/// @brief Get an object's appearance.
/// @param obj The object.
/// @return The appearance id.
int NWNX_Object_GetAppearance(object obj);

/// @brief Determine if an object has a visual effect.
/// @param obj The object.
/// @param nVFX The visual effect id.
/// @return TRUE if the object has the visual effect applied to it
int NWNX_Object_GetHasVisualEffect(object obj, int nVFX);

/// @brief Check if an item can fit in an object's inventory.
/// @param obj The object with an inventory.
/// @param baseitem The base item id to check for a fit.
/// @return TRUE if an item of base item type can fit in object's inventory
int NWNX_Object_CheckFit(object obj, int baseitem);

/// @brief Get an object's damage immunity.
/// @param obj The object.
/// @param damageType The damage type to check for immunity. Use DAMAGE_TYPE_* constants.
/// @return Damage immunity as a percentage.
int NWNX_Object_GetDamageImmunity(object obj, int damageType);

/// @brief Add or move an object.
/// @param obj The object.
/// @param area The area.
/// @param pos The position.
void NWNX_Object_AddToArea(object obj, object area, vector pos);

/// @brief Get placeable's static setting
/// @param obj The object.
/// @return TRUE if placeable is static.
int NWNX_Object_GetPlaceableIsStatic(object obj);

/// @brief Set placeable as static or not.
/// @note Will not update for PCs until they re-enter the area.
/// @param obj The object.
/// @param isStatic TRUE/FALSE
void NWNX_Object_SetPlaceableIsStatic(object obj, int isStatic);

/// @brief Gets if a door/placeable auto-removes the key after use.
/// @param obj The object.
/// @return TRUE/FALSE or -1 on error.
int NWNX_Object_GetAutoRemoveKey(object obj);

/// @brief Sets if a door/placeable auto-removes the key after use.
/// @param obj The object.
/// @param bRemoveKey TRUE/FALSE
void NWNX_Object_SetAutoRemoveKey(object obj, int bRemoveKey);

/// @brief Get the geometry of a trigger
/// @param oTrigger The trigger object.
/// @return A string of vertex positions.
string NWNX_Object_GetTriggerGeometry(object oTrigger);

/// @brief Set the geometry of a trigger with a list of vertex positions
/// @param oTrigger The trigger object.
/// @param sGeometry Needs to be in the following format -> {x.x, y.y, z.z} or {x.x, y.y}
/// Example Geometry: "{1.0, 1.0, 0.0}{4.0, 1.0, 0.0}{4.0, 4.0, 0.0}{1.0, 4.0, 0.0}"
///
/// @remark The Z position is optional and will be calculated dynamically based
/// on terrain height if it's not provided.
///
/// @remark The minimum number of vertices is 3.
void NWNX_Object_SetTriggerGeometry(object oTrigger, string sGeometry);

/// @brief Add an effect to an object that displays an icon and has no other effect.
/// @remark See effecticons.2da for a list of possible effect icons.
/// @param obj The object to apply the effect.
/// @param nIcon The icon id.
/// @param fDuration If specified the effect will be temporary and last this length in seconds, otherwise the effect
/// will be permanent.
void NWNX_Object_AddIconEffect(object obj, int nIcon, float fDuration=0.0);

/// @brief Remove an icon effect from an object that was added by the NWNX_Object_AddIconEffect() function.
/// @param obj The object.
/// @param nIcon The icon id.
void NWNX_Object_RemoveIconEffect(object obj, int nIcon);

/// @brief Export an object to the UserDirectory/nwnx folder.
/// @param sFileName The filename without extension, 16 or less characters.
/// @param oObject The object to export. Valid object types: Creature, Item, Placeable, Waypoint, Door, Store, Trigger
void NWNX_Object_Export(string sFileName, object oObject);

/// @brief Get oObject's persistent integer variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @return The value or 0 on error.
/// @deprecated Please use NWNX_Object_GetInt()
int NWNX_Object_GetPersistentInt(object oObject, string sVarName);

/// @brief Set oObject's persistent integer variable sVarName to nValue.
/// @note The value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param nValue The integer value to to set
/// @deprecated Please use NWNX_Object_SetInt()
void NWNX_Object_SetPersistentInt(object oObject, string sVarName, int nValue);

/// @brief Delete oObject's persistent integer variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @deprecated Please use NWNX_Object_DeleteInt()
void NWNX_Object_DeletePersistentInt(object oObject, string sVarName);

/// @brief Get oObject's persistent string variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @return The value or "" on error.
/// @deprecated Please use NWNX_Object_GetString()
string NWNX_Object_GetPersistentString(object oObject, string sVarName);

/// @brief Set oObject's persistent string variable sVarName to sValue.
/// @note The value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param sValue The string value to to set
/// @deprecated Please use NWNX_Object_SetString()
void NWNX_Object_SetPersistentString(object oObject, string sVarName, string sValue);

/// @brief Delete oObject's persistent string variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @deprecated Please use NWNX_Object_DeleteString()
void NWNX_Object_DeletePersistentString(object oObject, string sVarName);

/// @brief Get oObject's persistent float variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @return The value or 0.0f on error.
/// @deprecated Please use NWNX_Object_GetFloat()
float NWNX_Object_GetPersistentFloat(object oObject, string sVarName);

/// @brief Set oObject's persistent float variable sVarName to fValue.
/// @note The value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param fValue The float value to to set
/// @deprecated Please use NWNX_Object_SetFloat()
void NWNX_Object_SetPersistentFloat(object oObject, string sVarName, float fValue);

/// @brief Delete oObject's persistent float variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @deprecated Please use NWNX_Object_DeleteFloat()
void NWNX_Object_DeletePersistentFloat(object oObject, string sVarName);

/// @brief Get oObject's integer variable sVarName.
/// @param oObject The object to get the variable from.
/// @param sVarName The variable name.
/// @return The value or 0 on error.
int NWNX_Object_GetInt(object oObject, string sVarName);

/// @brief Set oObject's integer variable sVarName to nValue.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param nValue The integer value to to set
/// @param bPersist When TRUE, the value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
void NWNX_Object_SetInt(object oObject, string sVarName, int nValue, int bPersist);

/// @brief Delete oObject's integer variable sVarName.
/// @param oObject The object to delete the variable from.
/// @param sVarName The variable name.
void NWNX_Object_DeleteInt(object oObject, string sVarName);

/// @brief Get oObject's string variable sVarName.
/// @param oObject The object to get the variable from.
/// @param sVarName The variable name.
/// @return The value or "" on error.
string NWNX_Object_GetString(object oObject, string sVarName);

/// @brief Set oObject's string variable sVarName to sValue.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param sValue The string value to to set
/// @param bPersist When TRUE, the value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
void NWNX_Object_SetString(object oObject, string sVarName, string sValue, int bPersist);

/// @brief Delete oObject's string variable sVarName.
/// @param oObject The object to delete the variable from.
/// @param sVarName The variable name.
void NWNX_Object_DeleteString(object oObject, string sVarName);

/// @brief Get oObject's float variable sVarName.
/// @param oObject The object to get the variable from.
/// @param sVarName The variable name.
/// @return The value or 0.0f on error.
float NWNX_Object_GetFloat(object oObject, string sVarName);

/// @brief Set oObject's float variable sVarName to fValue.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param fValue The float value to to set
/// @param bPersist When TRUE, the value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
void NWNX_Object_SetFloat(object oObject, string sVarName, float fValue, int bPersist);

/// @brief Delete oObject's persistent float variable sVarName.
/// @param oObject The object to delete the variable from.
/// @param sVarName The variable name.
void NWNX_Object_DeleteFloat(object oObject, string sVarName);

/// @brief Delete any variables that match sRegex
/// @note It will only remove variables set by NWNX_Object_Set{Int|String|Float}()
/// @param oObject The object to delete the variables from.
/// @param sRegex The regular expression, for example .*Test.* removes every variable that has Test in it.
void NWNX_Object_DeleteVarRegex(object oObject, string sRegex);

/// @brief Get if vPosition is inside oTrigger's geometry.
/// @note The Z value of vPosition is ignored.
/// @param oTrigger The trigger.
/// @param vPosition The position.
/// @return TRUE if vPosition is inside oTrigger's geometry.
int NWNX_Object_GetPositionIsInTrigger(object oTrigger, vector vPosition);

/// @brief Gets the given object's internal type (NWNX_OBJECT_TYPE_INTERNAL_*)
/// @param oObject The object.
/// @return The object's type (NWNX_OBJECT_TYPE_INTERNAL_*)
int NWNX_Object_GetInternalObjectType(object oObject);

/// @brief Have oObject acquire oItem.
/// @note Useful to give deserialized items to an object, may not work if oItem is already possessed by an object.
/// @param oObject The object receiving oItem, must be a Creature, Placeable, Store or Item
/// @param oItem The item.
/// @return TRUE on success.
int NWNX_Object_AcquireItem(object oObject, object oItem);

/// @brief Cause oObject to face fDirection.
/// @note This function is almost identical to SetFacing(), the only difference being that it allows you to specify
/// the target object without the use of AssignCommand(). This is useful when you want to change the facing of an object
/// in an ExecuteScriptChunk() call where AssignCommand() does not work.
/// @param oObject The object to change its facing of
/// @param fDirection The direction the object should face
void NWNX_Object_SetFacing(object oObject, float fDirection);

/// @}

int NWNX_Object_GetLocalVariableCount(object obj)
{
    string sFunc = "GetLocalVariableCount";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

struct NWNX_Object_LocalVariable NWNX_Object_GetLocalVariable(object obj, int index)
{
    string sFunc = "GetLocalVariable";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, index);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);

    struct NWNX_Object_LocalVariable var;
    var.key  = NWNX_GetReturnValueString(NWNX_Object, sFunc);
    var.type = NWNX_GetReturnValueInt(NWNX_Object, sFunc);
    return var;
}

object NWNX_Object_StringToObject(string id)
{
    string sFunc = "StringToObject";

    NWNX_PushArgumentString(NWNX_Object, sFunc, id);
    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueObject(NWNX_Object, sFunc);
}

void NWNX_Object_SetPosition(object obj, vector pos)
{
    string sFunc = "SetPosition";

    NWNX_PushArgumentFloat(NWNX_Object, sFunc, pos.x);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, pos.y);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, pos.z);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);

}

void NWNX_Object_SetCurrentHitPoints(object creature, int hp)
{
    string sFunc = "SetCurrentHitPoints";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, hp);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, creature);

    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_SetMaxHitPoints(object creature, int hp)
{
    string sFunc = "SetMaxHitPoints";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, hp);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, creature);

    NWNX_CallFunction(NWNX_Object, sFunc);
}

string NWNX_Object_Serialize(object obj)
{
    string sFunc = "Serialize";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

object NWNX_Object_Deserialize(string serialized)
{
    string sFunc = "Deserialize";

    NWNX_PushArgumentString(NWNX_Object, sFunc, serialized);

    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueObject(NWNX_Object, sFunc);
}

string NWNX_Object_GetDialogResref(object obj)
{
    string sFunc = "GetDialogResref";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

void NWNX_Object_SetDialogResref(object obj, string dialog)
{
    string sFunc = "SetDialogResref";

    NWNX_PushArgumentString(NWNX_Object, sFunc, dialog);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_SetAppearance(object obj, int app)
{
    string sFunc = "SetAppearance";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, app);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
}

int NWNX_Object_GetAppearance(object obj)
{
    string sFunc = "GetAppearance";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

int NWNX_Object_GetHasVisualEffect(object obj, int nVFX)
{
    string sFunc = "GetHasVisualEffect";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, nVFX);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

int NWNX_Object_CheckFit(object obj, int baseitem)
{
    string sFunc = "CheckFit";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, baseitem);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

int NWNX_Object_GetDamageImmunity(object obj, int damageType)
{
    string sFunc = "GetDamageImmunity";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, damageType);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

void NWNX_Object_AddToArea(object obj, object area, vector pos)
{
    string sFunc = "AddToArea";

    NWNX_PushArgumentFloat(NWNX_Object, sFunc, pos.z);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, pos.y);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, pos.x);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, area);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

int NWNX_Object_GetPlaceableIsStatic(object obj)
{
    string sFunc = "GetPlaceableIsStatic";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

void NWNX_Object_SetPlaceableIsStatic(object obj, int isStatic)
{
    string sFunc = "SetPlaceableIsStatic";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, isStatic);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
}

int NWNX_Object_GetAutoRemoveKey(object obj)
{
    string sFunc = "GetAutoRemoveKey";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

void NWNX_Object_SetAutoRemoveKey(object obj, int bRemoveKey)
{
    string sFunc = "SetAutoRemoveKey";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, bRemoveKey);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);

    NWNX_CallFunction(NWNX_Object, sFunc);
}

string NWNX_Object_GetTriggerGeometry(object oTrigger)
{
    string sFunc = "GetTriggerGeometry";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, oTrigger);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

void NWNX_Object_SetTriggerGeometry(object oTrigger, string sGeometry)
{
    string sFunc = "SetTriggerGeometry";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sGeometry);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oTrigger);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_AddIconEffect(object obj, int nIcon, float fDuration=0.0)
{
    string sFunc = "AddIconEffect";

    NWNX_PushArgumentFloat(NWNX_Object, sFunc, fDuration);
    NWNX_PushArgumentInt(NWNX_Object, sFunc, nIcon);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_RemoveIconEffect(object obj, int nIcon)
{
    string sFunc = "RemoveIconEffect";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, nIcon);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_Export(string sFileName, object oObject)
{
    string sFunc = "Export";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sFileName);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

int NWNX_Object_GetPersistentInt(object oObject, string sVarName)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_GetPersistentInt() is deprecated, please use NWNX_Object_GetInt()");

    return NWNX_Object_GetInt(oObject, sVarName);
}

void NWNX_Object_SetPersistentInt(object oObject, string sVarName, int nValue)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_SetPersistentInt() is deprecated, please use NWNX_Object_SetInt()");

    NWNX_Object_SetInt(oObject, sVarName, nValue, TRUE);
}

void NWNX_Object_DeletePersistentInt(object oObject, string sVarName)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_DeletePersistentInt() is deprecated, please use NWNX_Object_DeleteInt()");

    NWNX_Object_DeleteInt(oObject, sVarName);
}

string NWNX_Object_GetPersistentString(object oObject, string sVarName)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_GetPersistentString() is deprecated, please use NWNX_Object_GetString()");

    return NWNX_Object_GetString(oObject, sVarName);
}

void NWNX_Object_SetPersistentString(object oObject, string sVarName, string sValue)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_SetPersistentString() is deprecated, please use NWNX_Object_SetString()");

    NWNX_Object_SetString(oObject, sVarName, sValue, TRUE);
}

void NWNX_Object_DeletePersistentString(object oObject, string sVarName)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_DeletePersistentString() is deprecated, please use NWNX_Object_DeleteString()");

    NWNX_Object_DeleteString(oObject, sVarName);
}

float NWNX_Object_GetPersistentFloat(object oObject, string sVarName)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_GetPersistentFloat() is deprecated, please use NWNX_Object_GetFloat()");

    return NWNX_Object_GetFloat(oObject, sVarName);
}

void NWNX_Object_SetPersistentFloat(object oObject, string sVarName, float fValue)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_SetPersistentFloat() is deprecated, please use NWNX_Object_SetFloat()");

    NWNX_Object_SetFloat(oObject, sVarName, fValue, TRUE);
}

void NWNX_Object_DeletePersistentFloat(object oObject, string sVarName)
{
    WriteTimestampedLogEntry("WARNING: NWNX_Object_DeletePersistentFloat() is deprecated, please use NWNX_Object_DeleteFloat()");

    NWNX_Object_DeleteFloat(oObject, sVarName);
}

int NWNX_Object_GetInt(object oObject, string sVarName)
{
    string sFunc = "GetInt";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

void NWNX_Object_SetInt(object oObject, string sVarName, int nValue, int bPersist)
{
    string sFunc = "SetInt";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, bPersist);
    NWNX_PushArgumentInt(NWNX_Object, sFunc, nValue);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeleteInt(object oObject, string sVarName)
{
    string sFunc = "DeleteInt";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

string NWNX_Object_GetString(object oObject, string sVarName)
{
    string sFunc = "GetString";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

void NWNX_Object_SetString(object oObject, string sVarName, string sValue, int bPersist)
{
    string sFunc = "SetString";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, bPersist);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sValue);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeleteString(object oObject, string sVarName)
{
    string sFunc = "DeleteString";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

float NWNX_Object_GetFloat(object oObject, string sVarName)
{
    string sFunc = "GetFloat";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueFloat(NWNX_Object, sFunc);
}

void NWNX_Object_SetFloat(object oObject, string sVarName, float fValue, int bPersist)
{
    string sFunc = "SetFloat";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, bPersist);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, fValue);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeleteFloat(object oObject, string sVarName)
{
    string sFunc = "DeleteFloat";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeleteVarRegex(object oObject, string sRegex)
{
    string sFunc = "DeleteVarRegex";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sRegex);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

int NWNX_Object_GetPositionIsInTrigger(object oTrigger, vector vPosition)
{
    string sFunc = "GetPositionIsInTrigger";

    NWNX_PushArgumentFloat(NWNX_Object, sFunc, vPosition.z);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, vPosition.y);
    NWNX_PushArgumentFloat(NWNX_Object, sFunc, vPosition.x);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oTrigger);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

int NWNX_Object_GetInternalObjectType(object oObject)
{
    string sFunc = "GetInternalObjectType";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

int NWNX_Object_AcquireItem(object oObject, object oItem)
{
    string sFunc = "AcquireItem";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, oItem);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

void NWNX_Object_SetFacing(object oObject, float fDirection)
{
    string sFunc = "SetFacing";

    NWNX_PushArgumentFloat(NWNX_Object, sFunc, fDirection);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}
