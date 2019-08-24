#include "nwnx"

const string NWNX_JVM = "NWNX_JVM";

/*
  This sends event 'ev' to your JVM. Does not return anything.
*/
void NWNX_JVM_EVENT(string ev, object caller = OBJECT_SELF);


void NWNX_JVM_EVENT(string ev, object caller = OBJECT_SELF)
{
    string sFunc = "Event";

    NWNX_PushArgumentObject(NWNX_JVM, sFunc, caller);
    NWNX_PushArgumentString(NWNX_JVM, sFunc, ev);
    NWNX_CallFunction(NWNX_JVM, sFunc);
}
