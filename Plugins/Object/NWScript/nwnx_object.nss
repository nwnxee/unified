#include "nwnx"

// Area event handlers
const int NWNX_OBJECT_SCRIPT_AREA_ON_HEARTBEAT                  = 0;
const int NWNX_OBJECT_SCRIPT_AREA_ON_USER_DEFINED               = 1;
const int NWNX_OBJECT_SCRIPT_AREA_ON_ENTER                      = 2;
const int NWNX_OBJECT_SCRIPT_AREA_ON_EXIT                       = 3;

// Module event handlers
const int NWNX_OBJECT_SCRIPT_MODULE_ON_HEARTBEAT                = 0;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_USER_DEFINED             = 1;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_LOAD                     = 2;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_ENTER                    = 4;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_LEAVE                    = 5;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_ACTIVATE                 = 6;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_ACQUIRE                  = 7;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_UNACQUIRE                = 8;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_DEATH                    = 9;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_DYING                    = 10;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_RESPAWN                  = 11;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_REST                     = 12;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_LEVEL_UP                 = 13;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_CUTSCENE_ABORT           = 14;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_EQUIP_ITEM               = 15;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_UNEQUIP_ITEM             = 16;
const int NWNX_OBJECT_SCRIPT_MODULE_ON_PLAYER_CHAT              = 17;

// Creature event handlers
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_HEARTBEAT              = 0;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_NOTICE                 = 1;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_SPELL_CAST_AT          = 2;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_MELEE_ATTACKED         = 3;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_DAMAGED                = 4;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_DISTURBED              = 5;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_END_COMBAT_ROUND       = 6;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_DIALOGUE               = 7;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_SPAWN_IN               = 8;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_RESTED                 = 9;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_DEATH                  = 10;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_USER_DEFINED_EVENT     = 11;
const int NWNX_OBJECT_SCRIPT_CREATURE_ON_BLOCKED                = 12;

// Placeable event handlers
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_CLOSED              = 0;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_DAMAGED             = 1;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_DEATH               = 2;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_DISARM              = 3;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_HEARTBEAT           = 4;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_INVENTORY_DISTURBED = 5;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_LOCK                = 6;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_MELEE_ATTACKED      = 7;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_OPEN                = 8;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_SPELL_CAST_AT       = 9;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_TRAP_TRIGGERED      = 10;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_UNLOCK              = 11;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_USED                = 12;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_USER_DEFINED_EVENT  = 13;
const int NWNX_OBJECT_SCRIPT_PLACEABLE_ON_DIALOGUE            = 14;


const int NWNX_OBJECT_LOCALVAR_TYPE_INT      = 1;
const int NWNX_OBJECT_LOCALVAR_TYPE_FLOAT    = 2;
const int NWNX_OBJECT_LOCALVAR_TYPE_STRING   = 3;
const int NWNX_OBJECT_LOCALVAR_TYPE_OBJECT   = 4;
const int NWNX_OBJECT_LOCALVAR_TYPE_LOCATION = 5;

struct NWNX_Object_LocalVariable
{
    int type;
    string key;
};

// Gets the count of all local variables on the provided object.
int NWNX_Object_GetLocalVariableCount(object obj);

//Gets the local variable at the provided index of the provided object.
// Index bounds: 0 >= index < GetLocalVariableCount(obj).
struct NWNX_Object_LocalVariable NWNX_Object_GetLocalVariable(object obj, int index);

// Returns an object from the provided object ID.
// This is the counterpart to ObjectToString.
object NWNX_Object_StringToObject(string id);

// Gets the provided event handler for the provided object.
// The constant used here will very depending on what type obj is. See NWNX_OBJECT_SCRIPT_* constants.
// DEPRECATED - Use GetEventScript() built-in function instead
string NWNX_Object_GetEventHandler(object obj, int handler);

// Sets the provided event handler for the provided object to the provided script.
// The constant used here will very depending on what type obj is. See NWNX_OBJECT_SCRIPT_* constants.
// DEPRECATED - Use SetEventScript() built-in function instead
void NWNX_Object_SetEventHandler(object obj, int handler, string script);

// Set the provided object's position to the provided vector.
void NWNX_Object_SetPosition(object obj, vector pos);

// Sets the provided object's current hit points to the provided value.
void NWNX_Object_SetCurrentHitPoints(object obj, int hp);

// Set object's maximum hit points; will not work on PCs.
void NWNX_Object_SetMaxHitPoints(object obj, int hp);

// Get the name of the portrait object is using.
string NWNX_Object_GetPortrait(object obj);

// Set the portrait object is using. The portrait string must be no more
// than 15 characters long.
void NWNX_Object_SetPortrait(object obj, string portrait);

// Serialize the full object (including locals, inventory, etc) to base64 string
// Only works on Creatures and Items currently.
string NWNX_Object_Serialize(object obj);

// Deserialize the object. The object will be created outside of the world and
// needs to be manually positioned at a location/inventory.
object NWNX_Object_Deserialize(string serialized);

// Returns the dialog resref of the object.
string NWNX_Object_GetDialogResref(object obj);

// Sets the dialog resref of the object.
void NWNX_Object_SetDialogResref(object obj, string dialog);

// Set obj's appearance. Will not update for PCs until they
// re-enter the area.
void NWNX_Object_SetAppearance(object obj, int app);

// Get obj's appearance
int NWNX_Object_GetAppearance(object obj);


const string NWNX_Object = "NWNX_Object";


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

string NWNX_Object_GetEventHandler(object obj, int handler)
{
    WriteTimestampedLogEntry("NWNX_Object: GetEventHandler() is deprecated. Use native GetEventScript() instead");
    switch (GetObjectType(obj))
    {
        case OBJECT_TYPE_CREATURE:       handler += 5000;  break;
        case OBJECT_TYPE_TRIGGER:        handler += 7000;  break;
        case OBJECT_TYPE_DOOR:           handler += 10000; break;
        case OBJECT_TYPE_AREA_OF_EFFECT: handler += 11000; break;
        case OBJECT_TYPE_PLACEABLE:      handler += 9000;  break;
        case OBJECT_TYPE_STORE:          handler += 14000; break;
        case OBJECT_TYPE_ENCOUNTER:      handler += 13000; break;
        default:
            if (obj == GetModule())
                handler += 3000;
            else if (GetIsAreaNatural(obj) != AREA_INVALID)
                handler += 4000;
            else
                return "";
    }
    return GetEventScript(obj, handler);
}

void NWNX_Object_SetEventHandler(object obj, int handler, string script)
{
    WriteTimestampedLogEntry("NWNX_Object: SetEventHandler() is deprecated. Use native SetEventScript() instead");
    switch (GetObjectType(obj))
    {
        case OBJECT_TYPE_CREATURE:       handler += 5000;  break;
        case OBJECT_TYPE_TRIGGER:        handler += 7000;  break;
        case OBJECT_TYPE_DOOR:           handler += 10000; break;
        case OBJECT_TYPE_AREA_OF_EFFECT: handler += 11000; break;
        case OBJECT_TYPE_PLACEABLE:      handler += 9000;  break;
        case OBJECT_TYPE_STORE:          handler += 14000; break;
        case OBJECT_TYPE_ENCOUNTER:      handler += 13000; break;
        default:
            if (obj == GetModule())
                handler += 3000;
            else if (GetIsAreaNatural(obj) != AREA_INVALID)
                handler += 4000;
            else
                return;
    }
    SetEventScript(obj, handler, script);
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
string NWNX_Object_GetPortrait(object creature)
{
    string sFunc = "GetPortrait";

    NWNX_PushArgumentObject(NWNX_Object, sFunc, creature);

    NWNX_CallFunction(NWNX_Object, sFunc);
    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

void NWNX_Object_SetPortrait(object creature, string portrait)
{
    string sFunc = "SetPortrait";

    NWNX_PushArgumentString(NWNX_Object, sFunc, portrait);
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
