#include "JVM.hpp"
#include "Internal.hpp"
#include "Util.h"

#include "Services/Log/Log.hpp"
#include "Services/Events/Events.hpp"
#include "API/Globals.hpp"
#include "API/Constants.hpp"
#include "API/CScriptLocation.hpp"
#include "API/Vector.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CVirtualMachineCmdImplementer.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

#include <cmath>
#include <jni.h>

#define ENGINE_STRUCTURE_EFFECT 0
#define ENGINE_STRUCTURE_EVENT 1
#define ENGINE_STRUCTURE_LOCATION 2
#define ENGINE_STRUCTURE_TALENT 3
#define ENGINE_STRUCTURE_ITEMPROPERTY 4

namespace JVM
{

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

static Internal* g_internal;

JNIEXPORT jint JNICALL Internal::NWScriptPopInteger(JNIEnv* env, jobject obj)
{
    int32_t r;
    if (!Globals::VirtualMachine()->StackPopInteger(&r))
        throw std::runtime_error("Cannot pop a int off the VM stack.");
    return static_cast<jint>(r);
}

JNIEXPORT void JNICALL Internal::NWScriptPushInteger(JNIEnv* env, jobject obj, jint value)
{
    Globals::VirtualMachine()->StackPushInteger(value);
}

JNIEXPORT jfloat JNICALL Internal::NWScriptPopFloat(JNIEnv* env, jobject obj)
{
    float r;
    if (!Globals::VirtualMachine()->StackPopFloat(&r))
        throw std::runtime_error("Cannot pop a float off the VM stack.");
    return static_cast<jfloat>(r);
}

JNIEXPORT void JNICALL Internal::NWScriptPushFloat(JNIEnv* env, jobject obj, jfloat value)
{
    Globals::VirtualMachine()->StackPushFloat(value);
}

JNIEXPORT jstring JNICALL Internal::NWScriptPopString(JNIEnv* env, jobject obj)
{
    CExoString r;
    if (!Globals::VirtualMachine()->StackPopString(&r))
        throw std::runtime_error("Cannot pop a string off the VM stack.");

    jbyteArray myByteStuff = JNICHECKED(env, NewByteArray(r.GetLength()));

    JNICHECKED(env, SetByteArrayRegion(myByteStuff, 0, r.GetLength(), (jbyte*) r.CStr()));
    auto ret = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassConv,
        g_internal->m_jmethodConvFromNative, myByteStuff));
    return static_cast<jstring>(ret);
}

JNIEXPORT void JNICALL Internal::NWScriptPushString(JNIEnv* env, jobject obj, jstring value)
{
    jbyteArray toNative = (jbyteArray) JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassConv,
        g_internal->m_jmethodConvToNative, value));
    jbyte* converted = (jbyte*) JNICHECKED(env, GetByteArrayElements(toNative, 0));
    int32_t len = JNICHECKED(env, GetArrayLength(toNative));
    assert(len >= 0);

    CExoString toPush((char*) converted, len);
    Globals::VirtualMachine()->StackPushString(toPush);

    JNICHECKED(env, ReleaseByteArrayElements(toNative, converted, JNI_ABORT));
}

JNIEXPORT void JNICALL Internal::NWScriptPushObject(JNIEnv* env, jobject obj, jobject value)
{
    int32_t oid = Constants::OBJECT_INVALID;
    if (value != nullptr)
        oid = JNICHECKED(env, CallIntMethod(value, g_internal->m_jmethodNWObjectgetOid));

    Globals::VirtualMachine()->StackPushObject(oid);
}

JNIEXPORT jobject JNICALL Internal::NWScriptPopObject(JNIEnv* env, jobject obj)
{
    uint32_t oid;
    if (!Globals::VirtualMachine()->StackPopObject(&oid))
        throw std::runtime_error("Cannot pop a oid off the VM stack.");

    auto r = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassNWObject,
        g_internal->m_jmethodNWObjectCreate, oid));
    return r;
}

jobject JNIEXPORT JNICALL Internal::NWScriptPopVector(JNIEnv* env, jobject obj)
{
    Vector vRetVal;
    if (!Globals::VirtualMachine()->StackPopVector(&vRetVal))
        throw std::runtime_error("Cannot pop a Vector off the VM stack.");
    auto r = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassNWVector,
        g_internal->m_jmethodNWVectorCreate, vRetVal.x, vRetVal.y, vRetVal.z));
    return r;
}

void JNIEXPORT JNICALL Internal::NWScriptPushVector(JNIEnv* env, jobject obj, jobject value)
{
  Vector vec;
  vec.x = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWVectorgetX));
  vec.y = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWVectorgetY));
  vec.z = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWVectorgetZ));
  Globals::VirtualMachine()->StackPushVector(vec);
}

jobject JNIEXPORT JNICALL Internal::NWScriptPopLocation(JNIEnv* env, jobject obj)
{
    CScriptLocation *pRetVal;
    if (!Globals::VirtualMachine()->StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal))
        throw std::runtime_error("Cannot pop a Location off the VM stack.");
    jobject ret_area = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassNWObject,
        g_internal->m_jmethodNWObjectCreate, pRetVal->m_oArea));
    float facing = std::atan2(pRetVal->m_vOrientation.y, pRetVal->m_vOrientation.x) * (180 / 3.1415927);
    while (facing > 360.0)
        facing -= 360.0;
    while (facing < 0.0)
        facing += 360.0;

    auto r = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassNWLocation,
        g_internal->m_jmethodNWLocationCreate,
        ret_area, pRetVal->m_vPosition.x, pRetVal->m_vPosition.y, pRetVal->m_vPosition.z, facing));
    return r;
}

void JNIEXPORT JNICALL Internal::NWScriptPushLocation(JNIEnv* env, jobject obj, jobject value)
{
    jobject area = JNICHECKED(env, CallObjectMethod(value, g_internal->m_jmethodNWLocationgetArea));
    float facing = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWLocationgetFacing));
    Vector vv;
    vv.x = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWLocationgetX));
    vv.y = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWLocationgetY));
    vv.z = JNICHECKED(env, CallFloatMethod(value, g_internal->m_jmethodNWLocationgetZ));

    // This could use some love. We're letting the VM construct the engine_structure, but
    // doing it on this side would be faster.
    Globals::VirtualMachine()->StackPushFloat(facing);
    Globals::VirtualMachine()->StackPushVector(vv);
    NWScriptPushObject(env, obj, area);
    NWScriptCallFunction(env, obj, 215, 3);
}

jobject JNIEXPORT JNICALL Internal::NWScriptPopEffect(JNIEnv* env, jobject obj)
{
    CGameEffect *pRetVal;
    if (!Globals::VirtualMachine()->StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal))
        throw std::runtime_error("Cannot pop effect off the VM stack.");
    g_internal->TouchEffectAddress(pRetVal);
    // j_touchedEffects.insert(pRetVal);
    auto r = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassNWEffect,
        g_internal->m_jmethodNWEffectCreate, (long) pRetVal));
    return r;
}

void JNIEXPORT JNICALL Internal::NWScriptPushEffect(JNIEnv* env, jobject obj, jobject value)
{
    jint jid = JNICHECKED(env, CallIntMethod(value, g_internal->m_jmethodNWEffectgetOid));
    CGameEffect* ptr = reinterpret_cast<CGameEffect*>(jid);
    if (!g_internal->IsEffectTouched(ptr)) {
        JNICHECKED(env, ThrowNew(g_internal->m_jclassNWInvalidEffectException, "Do not reuse effects from past context switches."));
        return;
    }

    Globals::VirtualMachine()->StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ptr);
}

jobject JNIEXPORT JNICALL Internal::NWScriptPopItemProperty(JNIEnv* env, jobject obj)
{
    CGameEffect *pRetVal;
    if (!Globals::VirtualMachine()->StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal))
        throw std::runtime_error("Cannot pop itemproperty off the VM stack.");

    g_internal->TouchEffectAddress(pRetVal);
    auto r = JNICHECKED(env, CallStaticObjectMethod(g_internal->m_jclassNWEffect,
        g_internal->m_jmethodNWEffectCreate, (long) pRetVal));
    return r;
}

void JNIEXPORT JNICALL Internal::NWScriptPushItemProperty(JNIEnv* env, jobject obj, jobject value)
{
    jint jid = JNICHECKED(env, CallIntMethod(value, g_internal->m_jmethodNWItemPropertygetOid));
    CGameEffect* ptr = reinterpret_cast<CGameEffect*>(jid);
    if (!g_internal->IsEffectTouched(ptr)) {
        JNICHECKED(env, ThrowNew(g_internal->m_jclassNWInvalidEffectException, "Do not reuse itemproperties from past context switches."));
        return;
    }

    Globals::VirtualMachine()->StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ptr);
}

JNIEXPORT void JNICALL Internal::NWScriptCallFunction(JNIEnv* env, jobject obj, jint functionId, jint argc)
{
    int r = reinterpret_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer)->
        ExecuteCommand(functionId, argc);
    if (r != 0)
        throw std::runtime_error("CallFunction failed: " + std::to_string(r));
}

JNIEXPORT jboolean JNICALL Internal::NWScriptCanCallVM(JNIEnv* env, jobject obj)
{
    // TODO: We are in the VM when:
    // - the calling thread the main thread.
    return true;
}

void Internal::BindNWScript()
{
    g_internal = this;

    DoAttached([&](JavaVM* vm, JNIEnv* env) {
        const JNINativeMethod methods[] = {
            { (char*) "popInteger", (char*) "()I", (void*) Internal::NWScriptPopInteger },
            { (char*) "pushInteger", (char*) "(I)V", (void*) Internal::NWScriptPushInteger },
            { (char*) "popFloat", (char*) "()F", (void*) Internal::NWScriptPopFloat },
            { (char*) "pushFloat", (char*) "(F)V", (void*) Internal::NWScriptPushFloat },
            { (char*) "popString", (char*) "()Ljava/lang/String;", (void*) Internal::NWScriptPopString },
            { (char*) "pushString", (char*) "(Ljava/lang/String;)V", (void*) Internal::NWScriptPushString },
            { (char*) "popObject", (char*) "()Lorg/nwnx/nwnx2/jvm/NWObject;", (void*) Internal::NWScriptPopObject },
            { (char*) "pushObject", (char*) "(Lorg/nwnx/nwnx2/jvm/NWObject;)V", (void*) Internal::NWScriptPushObject },
            { (char*) "popVector", (char*) "()Lorg/nwnx/nwnx2/jvm/NWVector;", (void*) Internal::NWScriptPopVector },
            { (char*) "pushVector", (char*) "(Lorg/nwnx/nwnx2/jvm/NWVector;)V", (void*) Internal::NWScriptPushVector },
            { (char*) "popLocation", (char*) "()Lorg/nwnx/nwnx2/jvm/NWLocation;", (void*) Internal::NWScriptPopLocation },
            { (char*) "pushLocation", (char*) "(Lorg/nwnx/nwnx2/jvm/NWLocation;)V", (void*) Internal::NWScriptPushLocation },
            { (char*) "popEffect", (char*) "()Lorg/nwnx/nwnx2/jvm/NWEffect;", (void*) Internal::NWScriptPopEffect },
            { (char*) "pushEffect", (char*) "(Lorg/nwnx/nwnx2/jvm/NWEffect;)V", (void*) Internal::NWScriptPushEffect },
            { (char*) "popItemProperty", (char*) "()Lorg/nwnx/nwnx2/jvm/NWItemProperty;", (void*) Internal::NWScriptPopItemProperty },
            { (char*) "pushItemProperty", (char*) "(Lorg/nwnx/nwnx2/jvm/NWItemProperty;)V", (void*) Internal::NWScriptPushItemProperty },
            { (char*) "callFunction", (char*) "(II)V", (void*) Internal::NWScriptCallFunction },
            { (char*) "canCallVM", (char*) "()Z", (void*) Internal::NWScriptCanCallVM },
        };

        JNICHECKED(env, RegisterNatives(m_jclassNwscript, methods, 18));
    });
}

void Internal::UnbindNWScript()
{
    DoAttached([&](JavaVM* vm, JNIEnv* env) {
        JNICHECKED(env, UnregisterNatives(m_jclassNwscript));
    });
    g_internal = nullptr;
}

}
