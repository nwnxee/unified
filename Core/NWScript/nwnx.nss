/// @addtogroup nwnx NWNX
/// @brief Functions for plugin developers.
/// @{
/// @file nwnx.nss

/// @brief Scripting interface to NWNX.
/// @param pluginName The plugin name.
/// @param functionName The function name (do not include NWNX_Plugin_).
void NWNX_CallFunction(string pluginName, string functionName);
/// @brief Pushes the specified type to the c++ side
/// @param pluginName The plugin name.
/// @param functionName The function name (do not include NWNX_Plugin_).
/// @param value The value of specified type to push.
void NWNX_PushArgumentInt(string pluginName, string functionName, int value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentFloat(string pluginName, string functionName, float value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentObject(string pluginName, string functionName, object value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentString(string pluginName, string functionName, string value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentEffect(string pluginName, string functionName, effect value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentItemProperty(string pluginName, string functionName, itemproperty value);
/// @brief Returns the specified type from the c++ side
/// @param pluginName The plugin name.
/// @param functionName The function name (do not include NWNX_Plugin_).
/// @return The value of specified type.
int NWNX_GetReturnValueInt(string pluginName, string functionName);
/// @copydoc NWNX_GetReturnValueInt()
float NWNX_GetReturnValueFloat(string pluginName, string functionName);
/// @copydoc NWNX_GetReturnValueInt()
object NWNX_GetReturnValueObject(string pluginName, string functionName);
/// @copydoc NWNX_GetReturnValueInt()
string NWNX_GetReturnValueString(string pluginName, string functionName);
/// @copydoc NWNX_GetReturnValueInt()
effect NWNX_GetReturnValueEffect(string pluginName, string functionName);
/// @copydoc NWNX_GetReturnValueInt()
itemproperty NWNX_GetReturnValueItemProperty(string pluginName, string functionName);

/// @private
string NWNX_INTERNAL_BuildString(string pluginName, string functionName, string operation)
{
    return "NWNXEE!ABIv2!" + pluginName + "!" + functionName + "!" + operation;
}
/// @}

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
