/// @addtogroup jvm JVM
/// @brief Java Virtual Machine support for NWNXEE
/// @{
/// @file nwnx_jvm.nss
#include "nwnx"

const string NWNX_JVM = "NWNX_JVM"; ///< @private

/// @brief Sends an event to your JVM.
/// @param ev The event name.
/// @param caller The caller object.
void NWNX_JVM_EVENT(string ev, object caller = OBJECT_SELF);

/// @}

void NWNX_JVM_EVENT(string ev, object caller = OBJECT_SELF)
{
    string sFunc = "Event";

    NWNX_PushArgumentObject(NWNX_JVM, sFunc, caller);
    NWNX_PushArgumentString(NWNX_JVM, sFunc, ev);
    NWNX_CallFunction(NWNX_JVM, sFunc);
}
