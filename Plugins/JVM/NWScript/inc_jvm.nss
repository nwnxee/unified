#include "nwnx"

/*
  This sends event 'ev' to your JVM. Does not return anything.
*/
void JVM_EVENT(string ev, object caller = OBJECT_SELF);


void JVM_EVENT(string ev, object caller = OBJECT_SELF) {
    NWNX_PushArgumentObject("NWNX_JVM", "Event", caller);
    NWNX_PushArgumentString("NWNX_JVM", "Event", ev);
    NWNX_CallFunction("NWNX_JVM", "Event");
}
