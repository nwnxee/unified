#pragma once

#include <mutex>
#include <set>
#include <jni.h>

#include "JVM.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;


// omg jni, thanks for making me do this ..
#ifndef NDEBUG
#define JNICHECK 1
#endif

#ifdef JNICHECK
#define DO_JNI_CHECK(Env, Code) { \
    if (Env->ExceptionCheck()) { \
        Env->ExceptionDescribe(); \
        Env->FatalError("While executing native code: " #Code); \
    } \
}

#define JNICHECKED(Env,Call) Env->Call; DO_JNI_CHECK(Env, Call);
#else
#define JNICHECKED(Env,Call) Env->Call;
#endif

namespace JVM
{

class Internal {
    friend class JVM;
    friend class NWScript;

    Internal(JVM* parent);
    ~Internal();

    JVM* m_parent;

    void BindSCORCO();
    static int OnSCO(CCodeBase* thisptr, CExoString &sDatabase, CExoString &sVarName, CExoString &sPlayerId, const char cType, void *pData, int nDataLength);
    static void* OnRCO(CCodeBase* thisptr, CExoString &sDatabase, CExoString &sVarName, CExoString &sPlayerId, char &cType, int &nDataLength);
    void UnbindSCORCO();

    ArgumentStack OnEvent(ArgumentStack&& args);
    ArgumentStack OnToken(ArgumentStack&& args);
    ArgumentStack EntryPoint(jmethodID method, ArgumentStack& args);

    std::set<const CGameEffect*> m_touchedEffects;
    void TouchEffectAddress(const CGameEffect* address) {
        m_touchedEffects.insert(address);
    }
    bool IsEffectTouched(const CGameEffect* address) {
        return m_touchedEffects.find(address) != m_touchedEffects.end();
    }

    void DoAttached(std::function<void(JavaVM* vm, JNIEnv* env)> cb) {
        if (m_contextDepth == 0 && this->m_vm->AttachCurrentThread((void**) & (this->m_env), nullptr) < 0) {
            LOG_DEBUG("Attaching current thread; depth: %d.\n", m_contextDepth);
            this->m_env->FatalError("Attaching native NWN thread to JVM failed.");
        }

        m_contextDepth += 1;
        cb(m_vm, m_env);
        m_contextDepth -= 1;

        // Exceptions?
        if (m_env->ExceptionCheck()) {
            m_env->ExceptionDescribe();
            m_env->FatalError("while executing native code.");
        }

        if (m_contextDepth == 0 && this->m_vm->DetachCurrentThread() < 0) {
            LOG_DEBUG("%s", "Detaching current thread.\n");
            this->m_env->FatalError("Detaching native NWN thread from JVM failed.");
        }
    }

    jobject NewGlobalClassRef(JNIEnv* env, const std::string& clz) {
        LOG_INFO("Looking up class: %s", clz.c_str());
        jclass local = JNICHECKED(env, FindClass(clz.c_str()));
        if (!local)
            throw std::runtime_error("Class not found: " + clz);
        auto r = JNICHECKED(env, NewGlobalRef(local));
        return r;
    }

    jmethodID FindClassMethod(JNIEnv* env, jclass clz, const std::string& meth, const std::string& sig) {
        LOG_INFO("Looking up static method: %s", meth.c_str());
        jmethodID ret = JNICHECKED(env, GetStaticMethodID(clz, meth.c_str(), sig.c_str()));
        if (!ret)
            throw std::runtime_error("Static method not found: " + meth);
        return ret;
    }

    jmethodID FindMethod(JNIEnv* env, jclass clz, const std::string& meth, const std::string& sig) {
        LOG_INFO("Looking up method: %s", meth.c_str());
        jmethodID ret = JNICHECKED(env, GetMethodID(clz, meth.c_str(), sig.c_str()));
        if (!ret)
            throw std::runtime_error("Method not found: " + meth);
        return ret;
    }

    JavaVM* m_vm;
    JNIEnv* m_env;

    int m_contextDepth = 0;

    // NWScript
    void BindNWScript();
    static jint JNIEXPORT JNICALL NWScriptPopInteger(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushInteger(JNIEnv* env, jobject obj, jint value);
    static jfloat JNIEXPORT JNICALL NWScriptPopFloat(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushFloat(JNIEnv* env, jobject obj, jfloat value);
    static jstring JNIEXPORT JNICALL NWScriptPopString(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushString(JNIEnv* env, jobject obj, jstring value);
    static jobject JNIEXPORT JNICALL NWScriptPopObject(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushObject(JNIEnv* env, jobject obj, jobject value);
    static jobject JNIEXPORT JNICALL NWScriptPopVector(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushVector(JNIEnv* env, jobject obj, jobject value);
    static jobject JNIEXPORT JNICALL NWScriptPopLocation(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushLocation(JNIEnv* env, jobject obj, jobject value);
    static jobject JNIEXPORT JNICALL NWScriptPopEffect(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushEffect(JNIEnv* env, jobject obj, jobject value);
    static jobject JNIEXPORT JNICALL NWScriptPopItemProperty(JNIEnv* env, jobject obj);
    static void JNIEXPORT JNICALL NWScriptPushItemProperty(JNIEnv* env, jobject obj, jobject value);
    static void JNIEXPORT JNICALL NWScriptCallFunction(JNIEnv* env, jobject obj, jint functionId, jint argc);
    static jboolean JNIEXPORT JNICALL NWScriptCanCallVM(JNIEnv* env, jobject obj);
    void UnbindNWScript();

    jclass m_jclassInitListener;
    jmethodID m_jmethodJavaSetup;
    jmethodID m_jmethodJavaInit;
    jmethodID m_jmethodJavaShutdown;
    jmethodID m_jmethodJavaEvent;
    jmethodID m_jmethodJavaToken;

    jclass    m_jclassNwscript;

    jclass    m_jclassEventListener;
    jclass    m_jclassTokenListener;

    jclass    m_jclassNWObject;
    jmethodID m_jmethodNWObjectCreate;
    jmethodID m_jmethodNWObjectgetOid;

    jclass m_jclassNWVector;
    jmethodID m_jmethodNWVectorCreate;
    jmethodID m_jmethodNWVectorgetX;
    jmethodID m_jmethodNWVectorgetY;
    jmethodID m_jmethodNWVectorgetZ;

    jclass m_jclassNWLocation;
    jmethodID m_jmethodNWLocationCreate;
    jmethodID m_jmethodNWLocationgetArea;
    jmethodID m_jmethodNWLocationgetX;
    jmethodID m_jmethodNWLocationgetY;
    jmethodID m_jmethodNWLocationgetZ;
    jmethodID m_jmethodNWLocationgetFacing;

    jclass m_jclassNWEffect;
    jmethodID m_jmethodNWEffectCreate;
    jmethodID m_jmethodNWEffectgetOid;
    jclass m_jclassNWItemProperty;
    jmethodID m_jmethodNWItemPropertyCreate;
    jmethodID m_jmethodNWItemPropertygetOid;

    jclass m_jclassNWNotInContextException;
    jclass m_jclassNWInvalidObjectException;
    jclass m_jclassNWInvalidEffectException;
    jclass m_jclassNWInvalidItemPropertyException;

    jclass m_jclassSCORCOListener;
    jmethodID m_jmethodSCO;
    jmethodID m_jmethodRCO;

    jclass m_jclassResmanListener;
    jmethodID m_jmethodResmanExists;
    jmethodID m_jmethodResmanDemand;

    jclass m_jclassConv;
    jmethodID m_jmethodConvToNative;
    jmethodID m_jmethodConvFromNative;
};

}
