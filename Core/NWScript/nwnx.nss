/// @addtogroup nwnx NWNX
/// @brief Functions for plugin developers.
/// @{
/// @file nwnx.nss

/// @brief Scripting interface to NWNX.
/// @param pluginName The plugin name.
/// @param functionName The function name (do not include NWNX_Plugin_).
void NWNX_CallFunction(string pluginName, string functionName);
/// @brief Pushes the specified type to the c++ side
/// @param value The value of specified type to push.
void NWNX_PushArgumentInt(int value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentFloat(float value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentObject(object value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentString(string value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentEffect(effect value);
/// @copydoc NWNX_PushArgumentInt()
void NWNX_PushArgumentItemProperty(itemproperty value);
/// @brief Returns the specified type from the c++ side
/// @return The value of specified type.
int NWNX_GetReturnValueInt();
/// @copydoc NWNX_GetReturnValueInt()
float NWNX_GetReturnValueFloat();
/// @copydoc NWNX_GetReturnValueInt()
object NWNX_GetReturnValueObject();
/// @copydoc NWNX_GetReturnValueInt()
string NWNX_GetReturnValueString();
/// @copydoc NWNX_GetReturnValueInt()
effect NWNX_GetReturnValueEffect();
/// @copydoc NWNX_GetReturnValueInt()
itemproperty NWNX_GetReturnValueItemProperty();

/// @private
const string NWNX_PUSH          = "NWNXEE!ABIv2!X!Y!PUSH";
const string NWNX_POP           = "NWNXEE!ABIv2!X!Y!POP";
/// @}

void NWNX_CallFunction(string pluginName, string functionName)
{
    PlaySound("NWNXEE!ABIv2!" + pluginName + "!" + functionName + "!CALL");
}

void NWNX_PushArgumentInt(int value)
{
    SetLocalInt(OBJECT_INVALID, NWNX_PUSH, value);
}

void NWNX_PushArgumentFloat(float value)
{
    SetLocalFloat(OBJECT_INVALID, NWNX_PUSH, value);
}

void NWNX_PushArgumentObject(object value)
{
    SetLocalObject(OBJECT_INVALID, NWNX_PUSH, value);
}

void NWNX_PushArgumentString(string value)
{
    SetLocalString(OBJECT_INVALID, NWNX_PUSH, value);
}

void NWNX_PushArgumentEffect(effect value)
{
    TagEffect(value, NWNX_PUSH);
}

void NWNX_PushArgumentItemProperty(itemproperty value)
{
    TagItemProperty(value, NWNX_PUSH);
}

int NWNX_GetReturnValueInt()
{
    return GetLocalInt(OBJECT_INVALID, NWNX_POP);
}

float NWNX_GetReturnValueFloat()
{
    return GetLocalFloat(OBJECT_INVALID, NWNX_POP);
}

object NWNX_GetReturnValueObject()
{
    return GetLocalObject(OBJECT_INVALID, NWNX_POP);
}

string NWNX_GetReturnValueString()
{
    return GetLocalString(OBJECT_INVALID, NWNX_POP);
}

effect NWNX_GetReturnValueEffect()
{
    effect e;
    return TagEffect(e, NWNX_POP);
}

itemproperty NWNX_GetReturnValueItemProperty()
{
    itemproperty ip;
    return TagItemProperty(ip, NWNX_POP);
}
