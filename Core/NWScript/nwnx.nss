// These following functions should be called by NWNX plugin developers, who should expose
// their own, more friendly headers.
//
// For example, this following function would wrap a call which passes three parameters,
// receives three back, and constructs a vector frm the result.
//
//     vector GetVectorFromCoords(float x, float y, float z)
//     {
//         string pluginName = "NWNX_TestPlugin";
//         string funcName = "GiveMeBackTheSameValues";
//
//         // Note the inverse argument push order.
//         // C++-side, arguments will be consumed from right to left.
//         NWNX_PushArgumentFloat(pluginName, funcName, z);
//         NWNX_PushArgumentFloat(pluginName, funcName, y);
//         NWNX_PushArgumentFloat(pluginName, funcName, x);
//
//         // This calls the function, which will prepare the return values.
//         NWNX_CallFunction(pluginName, funcName);
//
//         // C++-side pushes the return values in reverse order so we can consume them naturally here.
//         float _x = NWNX_GetReturnValueFloat(pluginName, funcName);
//         float _y = NWNX_GetReturnValueFloat(pluginName, funcName);
//         float _z = NWNX_GetReturnValueFloat(pluginName, funcName);
//
//         return vector(_x, _y, _z);
//     }

void NWNX_CallFunction(string pluginName, string functionName);
void NWNX_PushArgumentInt(string pluginName, string functionName, int value);
void NWNX_PushArgumentFloat(string pluginName, string functionName, float value);
void NWNX_PushArgumentObject(string pluginName, string functionName, object value);
void NWNX_PushArgumentString(string pluginName, string functionName, string value);
void NWNX_PushArgumentEffect(string pluginName, string functionName, effect value);
void NWNX_PushArgumentItemProperty(string pluginName, string functionName, itemproperty value);
int NWNX_GetReturnValueInt(string pluginName, string functionName);
float NWNX_GetReturnValueFloat(string pluginName, string functionName);
object NWNX_GetReturnValueObject(string pluginName, string functionName);
string NWNX_GetReturnValueString(string pluginName, string functionName);
effect NWNX_GetReturnValueEffect(string pluginName, string functionName);
itemproperty NWNX_GetReturnValueItemProperty(string pluginName, string functionName);

string NWNX_INTERNAL_BuildString(string pluginName, string functionName, string operation)
{
    return "NWNXEE!ABIv2!" + pluginName + "!" + functionName + "!" + operation;
}

void NWNX_CallFunction(string pluginName, string functionName)
{
    PlaySound(NWNX_INTERNAL_BuildString(pluginName, functionName, "CALL"));
}

void NWNX_PushArgumentInt(string pluginName, string functionName, int value)
{
    SetLocalInt(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "PUSH"), value);
}

void NWNX_PushArgumentFloat(string pluginName, string functionName, float value)
{
    SetLocalFloat(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "PUSH"), value);
}

void NWNX_PushArgumentObject(string pluginName, string functionName, object value)
{
    SetLocalObject(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "PUSH"), value);
}

void NWNX_PushArgumentString(string pluginName, string functionName, string value)
{
    SetLocalString(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "PUSH"), value);
}

void NWNX_PushArgumentEffect(string pluginName, string functionName, effect value)
{
    TagEffect(value, NWNX_INTERNAL_BuildString(pluginName, functionName, "PUSH"));
}

void NWNX_PushArgumentItemProperty(string pluginName, string functionName, itemproperty value)
{
    TagItemProperty(value, NWNX_INTERNAL_BuildString(pluginName, functionName, "PUSH"));
}

int NWNX_GetReturnValueInt(string pluginName, string functionName)
{
    return GetLocalInt(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "POP"));
}

float NWNX_GetReturnValueFloat(string pluginName, string functionName)
{
    return GetLocalFloat(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "POP"));
}

object NWNX_GetReturnValueObject(string pluginName, string functionName)
{
    return GetLocalObject(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "POP"));
}

string NWNX_GetReturnValueString(string pluginName, string functionName)
{
    return GetLocalString(OBJECT_INVALID, NWNX_INTERNAL_BuildString(pluginName, functionName, "POP"));
}

effect NWNX_GetReturnValueEffect(string pluginName, string functionName)
{
    effect e;
    return TagEffect(e, NWNX_INTERNAL_BuildString(pluginName, functionName, "POP"));
}

itemproperty NWNX_GetReturnValueItemProperty(string pluginName, string functionName)
{
    itemproperty ip;
    return TagItemProperty(ip, NWNX_INTERNAL_BuildString(pluginName, functionName, "POP"));
}
