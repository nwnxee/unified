#include "nwnx"

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
string NWNX_Object_GetEventHandler(object obj, int handler);

// Sets the provided event handler for the provided object to the provided script.
// The constant used here will very depending on what type obj is. See NWNX_OBJECT_SCRIPT_* constants.
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
    string sFunc = "GetEventHandler";

    NWNX_PushArgumentInt(NWNX_Object, sFunc, handler);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);

    return NWNX_GetReturnValueString(NWNX_Object, sFunc);
}

void NWNX_Object_SetEventHandler(object obj, int handler, string script)
{
    string sFunc = "SetEventHandler";

    NWNX_PushArgumentString(NWNX_Object, sFunc, script);
    NWNX_PushArgumentInt(NWNX_Object, sFunc, handler);
    NWNX_PushArgumentObject(NWNX_Object, sFunc, obj);
    NWNX_CallFunction(NWNX_Object, sFunc);

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
