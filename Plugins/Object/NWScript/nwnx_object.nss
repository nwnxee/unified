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
int NWNX_Object_GetPersistentInt(object oObject, string sVarName);

/// @brief Set oObject's persistent integer variable sVarName to nValue.
/// @note The value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param nValue The integer value to to set
void NWNX_Object_SetPersistentInt(object oObject, string sVarName, int nValue);

/// @brief Delete oObject's persistent integer variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
void NWNX_Object_DeletePersistentInt(object oObject, string sVarName);

/// @brief Get oObject's persistent string variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @return The value or "" on error.
string NWNX_Object_GetPersistentString(object oObject, string sVarName);

/// @brief Set oObject's persistent string variable sVarName to sValue.
/// @note The value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param sValue The string value to to set
void NWNX_Object_SetPersistentString(object oObject, string sVarName, string sValue);

/// @brief Delete oObject's persistent string variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
void NWNX_Object_DeletePersistentString(object oObject, string sVarName);

/// @brief Get oObject's persistent float variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @return The value or 0.0f on error.
float NWNX_Object_GetPersistentFloat(object oObject, string sVarName);

/// @brief Set oObject's persistent float variable sVarName to sValue.
/// @note The value is persisted to GFF, this means that it'll be saved in the .bic file of a player's character or when an object is serialized.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
/// @param fValue The float value to to set
void NWNX_Object_SetPersistentFloat(object oObject, string sVarName, float fValue);

/// @brief Delete oObject's persistent float variable sVarName.
/// @param oObject The object to set the variable on.
/// @param sVarName The variable name.
void NWNX_Object_DeletePersistentFloat(object oObject, string sVarName);

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
    string sFunc = "GetPersistentInt";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueInt(NWNX_Object, sFunc);
}

void NWNX_Object_SetPersistentInt(object oObject, string sVarName, int nValue)
{
    string sFunc = "SetPersistentInt";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, nValue);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeletePersistentInt(object oObject, string sVarName)
{
    string sFunc = "DeletePersistentInt";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

string NWNX_Object_GetPersistentString(object oObject, string sVarName)
{
    string sFunc = "GetPersistentString";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

void NWNX_Object_SetPersistentString(object oObject, string sVarName, string sValue)
{
    string sFunc = "SetPersistentString";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sValue);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeletePersistentString(object oObject, string sVarName)
{
    string sFunc = "DeletePersistentString";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

float NWNX_Object_GetPersistentFloat(object oObject, string sVarName)
{
    string sFunc = "GetPersistentFloat";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueFloat(NWNX_Object, sFunc);
}

void NWNX_Object_SetPersistentFloat(object oObject, string sVarName, float fValue)
{
    string sFunc = "SetPersistentFloat";

    NWNX_PushArgumentFloat(NWNX_Object, sFunc, fValue);
    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}

void NWNX_Object_DeletePersistentFloat(object oObject, string sVarName)
{
    string sFunc = "DeletePersistentFloat";

    NWNX_PushArgumentString(NWNX_Object, sFunc, sVarName);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, oObject);
    NWNX_CallFunction(NWNX_Object, sFunc);
}
