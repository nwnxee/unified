#include "nwnx"

void call_token(string token, object caller = OBJECT_SELF) {
    NWNX_PushArgumentObject("NWNX_JVM", "Event", caller);
    NWNX_PushArgumentString("NWNX_JVM", "Event", token);
    NWNX_CallFunction("NWNX_JVM", "Token");
}

void main() {
    string t = GetLocalString(GetModule(), "jvm_token");
    string type = GetLocalString(GetModule(), "jvm_token_type");
    float delay = GetLocalFloat(GetModule(), "jvm_token_delay");

    if ("execute" == type)
        call_token(t, OBJECT_SELF);
    else if ("delay" == type)
        DelayCommand(delay, call_token(t, OBJECT_SELF));
}
