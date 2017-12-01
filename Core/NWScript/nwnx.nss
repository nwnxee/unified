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
int NWNX_GetReturnValueInt(string pluginName, string functionName);
float NWNX_GetReturnValueFloat(string pluginName, string functionName);
object NWNX_GetReturnValueObject(string pluginName, string functionName);
string NWNX_GetReturnValueString(string pluginName, string functionName);

void NWNX_INTERNAL_CallFunction(string pluginName, string functionName);
void NWNX_INTERNAL_PushArgument(string pluginName, string functionName, string value);
string NWNX_INTERNAL_GetReturnValueString(string pluginName, string functionName, string type);
object NWNX_INTERNAL_GetReturnValueObject(string pluginName, string functionName, string type);

void NWNX_CallFunction(string pluginName, string functionName)
{
    NWNX_INTERNAL_CallFunction(pluginName, functionName);
}

void NWNX_PushArgumentInt(string pluginName, string functionName, int value)
{
    NWNX_INTERNAL_PushArgument(pluginName, functionName, "0 " + IntToString(value));
}

void NWNX_PushArgumentFloat(string pluginName, string functionName, float value)
{
    NWNX_INTERNAL_PushArgument(pluginName, functionName, "1 " + FloatToString(value));
}

void NWNX_PushArgumentObject(string pluginName, string functionName, object value)
{
    NWNX_INTERNAL_PushArgument(pluginName, functionName, "2 " + ObjectToString(value));
}

void NWNX_PushArgumentString(string pluginName, string functionName, string value)
{
    NWNX_INTERNAL_PushArgument(pluginName, functionName, "3 " + value);
}

int NWNX_GetReturnValueInt(string pluginName, string functionName)
{
    return StringToInt(NWNX_INTERNAL_GetReturnValueString(pluginName, functionName, "0 "));
}

float NWNX_GetReturnValueFloat(string pluginName, string functionName)
{
    return StringToFloat(NWNX_INTERNAL_GetReturnValueString(pluginName, functionName, "1 "));
}

object NWNX_GetReturnValueObject(string pluginName, string functionName)
{
    return NWNX_INTERNAL_GetReturnValueObject(pluginName, functionName, "2 ");
}

string NWNX_GetReturnValueString(string pluginName, string functionName)
{
    return NWNX_INTERNAL_GetReturnValueString(pluginName, functionName, "3 ");
}

void NWNX_INTERNAL_CallFunction(string pluginName, string functionName)
{
    SetLocalString(GetModule(), "NWNX!CALL_FUNCTION!" + pluginName + "!" + functionName, "1");
}

void NWNX_INTERNAL_PushArgument(string pluginName, string functionName, string value)
{
    SetLocalString(GetModule(), "NWNX!PUSH_ARGUMENT!" + pluginName + "!" + functionName, value);
}

string NWNX_INTERNAL_GetReturnValueString(string pluginName, string functionName, string type)
{
    return GetLocalString(GetModule(), "NWNX!GET_RETURN_VALUE!" + pluginName + "!" + functionName + "!" + type);
}

object NWNX_INTERNAL_GetReturnValueObject(string pluginName, string functionName, string type)
{
    return GetLocalObject(GetModule(), "NWNX!GET_RETURN_VALUE!" + pluginName + "!" + functionName + "!" + type);
}
