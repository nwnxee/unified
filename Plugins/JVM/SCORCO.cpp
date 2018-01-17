#include "JVM.hpp"
#include "Internal.hpp"
#include "Util.h"
#include "ScopeGuard.hpp"

#include "Services/Log/Log.hpp"
#include "Services/Events/Events.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/CScriptLocation.hpp"
#include "API/Vector.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CVirtualMachineCmdImplementer.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/Functions.hpp"

#include <cmath>
#include <jni.h>

#define ENGINE_STRUCTURE_EFFECT 0
#define ENGINE_STRUCTURE_EVENT 1
#define ENGINE_STRUCTURE_LOCATION 2
#define ENGINE_STRUCTURE_TALENT 3
#define ENGINE_STRUCTURE_ITEMPROPERTY 4

#define STRREF_CVIRTUALMACHINE_ERROR_STACK_OVERFLOW                 -638
#define STRREF_CVIRTUALMACHINE_ERROR_STACK_UNDERFLOW                -639

namespace JVM
{

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Internal* g_internal;
static Hooking::FunctionHook* g_scoHook = nullptr;
static Hooking::FunctionHook* g_rcoHook = nullptr;

int32_t Internal::OnSCO(CCodeBase* thisptr, CExoString &sDatabase, CExoString &sVarName, CExoString &sPlayerId, const char cType, void *pData, int nDataLength)
{
    if (sDatabase == "NWNX" && sVarName == "org.nwnx.nwnx2.jvm.SCORCO") {
        g_internal->DoAttached([&](JavaVM* vm, JNIEnv* env) {
            jstring key_s = JNICHECKED(env, NewStringUTF(sVarName.CStr()));
            jbyteArray arr = JNICHECKED(env, NewByteArray(nDataLength));
            JNICHECKED(env, SetByteArrayRegion(arr, 0, nDataLength, (jbyte*) pData));
            JNICHECKED(env, CallStaticVoidMethod(g_internal->m_jclassSCORCOListener, g_internal->m_jmethodSCO, key_s, arr));
        });
        return true;
    }

    return g_scoHook->CallOriginal<int32_t>(sDatabase, sVarName, sPlayerId, cType, pData, nDataLength);
}

void* Internal::OnRCO(CCodeBase* thisptr, CExoString &sDatabase, CExoString &sVarName, CExoString &sPlayerId, char &cType, int &nDataLength)
{
    if (sDatabase == "NWNX" && sVarName == "org.nwnx.nwnx2.jvm.SCORCO") {
        void *returnVal = nullptr;

        g_internal->DoAttached([&](JavaVM* vm, JNIEnv* env) {
            jstring key_s = JNICHECKED(env, NewStringUTF(sVarName.CStr()));
            jbyteArray ret = (jbyteArray) JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassSCORCOListener,
                g_internal->m_jmethodRCO, key_s));

            if (ret != nullptr) { // No data from java side.
                nDataLength = JNICHECKED(env, GetArrayLength(ret));
                returnVal = (void*) new char[nDataLength];
                JNICHECKED(env, GetByteArrayRegion(ret, 0, nDataLength, (jbyte*) returnVal));
            }
        });

        return returnVal;
    }

    return g_rcoHook->CallOriginal<void*>(sDatabase, sVarName, sPlayerId, cType, nDataLength);
}

void Internal::BindSCORCO()
{
    g_internal = this;

    m_parent->GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CCodeBase__AddBinaryData>(&Internal::OnSCO);
    g_scoHook = m_parent->GetServices()->m_hooks->FindHookByAddress(API::Functions::CCodeBase__AddBinaryData);
    m_parent->GetServices()->m_hooks->RequestExclusiveHook<API::Functions::CCodeBase__GetBinaryData>(&Internal::OnRCO);
    g_rcoHook = m_parent->GetServices()->m_hooks->FindHookByAddress(API::Functions::CCodeBase__GetBinaryData);
}

void Internal::UnbindSCORCO()
{
    g_internal = nullptr;
}

}
