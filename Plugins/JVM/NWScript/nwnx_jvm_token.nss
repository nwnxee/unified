#include "nwnx_jvm"

void call_token(string token, object caller = OBJECT_SELF) 
{
    string sFunc = "Event";
    NWNX_PushArgumentObject(NWNX_JVM, sFunc, caller);
    NWNX_PushArgumentString(NWNX_JVM, sFunc, token);
    NWNX_CallFunction(NWNX_JVM, "Token");
}

void main() 
{
    string t = GetLocalString(GetModule(), "NWNX_JVM_TOKEN");
    string type = GetLocalString(GetModule(), "NWNX_JVM_TOKEN_TYPE");
    float delay = GetLocalFloat(GetModule(), "NWNX_JVM_TOKEN_DELAY");

    if ("execute" == type)
        call_token(t, OBJECT_SELF);
    else if ("delay" == type)
        DelayCommand(delay, call_token(t, OBJECT_SELF));
}

