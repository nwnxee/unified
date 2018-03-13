#include "JVM.hpp"
#include "Internal.hpp"

#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "ViewPtr.hpp"

#include "API/Functions.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace JVM
{

using namespace NWNXLib::Services;
using namespace NWNXLib::Hooking;

Internal::Internal(JVM* parent) : m_parent(parent)
{
    LOG_INFO("%s", "Configuring up VM.");

    JavaVMInitArgs vmInitArgs;
    vmInitArgs.version = JNI_VERSION_1_6;

    constexpr int numOptions = 4;
    JavaVMOption* options = new JavaVMOption[numOptions];

    std::string classpath = std::string("-Djava.class.path=") + m_parent->m_config.m_classpath;
    LOG_INFO("Classpath: %s", classpath.c_str());
    options[0].optionString = const_cast<char*>(classpath.c_str());

    // Don't hook SIGINT, TERM, QUIT, as nwserver needs these to work.
    options[1].optionString = const_cast<char*>("-Xrs");
#ifdef JNICHECK
    options[2].optionString = const_cast<char*>("-Xcheck:jni");
    LOG_INFO("%s", "JNI checking turned on (Debug Build).");
#else
    options[2].optionString = const_cast<char*>("");
#endif
    options[3].optionString = const_cast<char*>(m_parent->m_config.m_addtional_arguments.c_str());

    vmInitArgs.nOptions = numOptions;
    vmInitArgs.options = options;

    LOG_INFO("%s", "Creating the Virtual Machine.");

    if (JNI_CreateJavaVM(&(this->m_vm), (void**) &(this->m_env), &(vmInitArgs)) != 0) {
        throw std::runtime_error("Cannot initialise Java VM.");
    }

    DoAttached([&](JavaVM*, JNIEnv* env) {
        LOG_INFO("%s", "Looking up required class and method IDs.");

        m_jclassInitListener                     = (jclass) NewGlobalClassRef(env, m_parent->m_config.m_classname_initListener);
        m_jmethodJavaSetup                       = FindClassMethod(env, m_jclassInitListener, "setup", "()V");
        m_jmethodJavaInit                        = FindClassMethod(env, m_jclassInitListener, "init", "()V");
        m_jmethodJavaShutdown                    = FindClassMethod(env, m_jclassInitListener, "shutdown", "()V");

        // setup() can set up additional classes via runtime loading.
        JNICHECKED(env, CallStaticVoidMethod(m_jclassInitListener, m_jmethodJavaSetup));

        m_jclassNwscript                         = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWScript");

        m_jclassSCORCOListener                   = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/SCORCO");
        m_jmethodSCO                             = FindClassMethod(env, m_jclassSCORCOListener, "sco", "(Ljava/lang/String;[B)V");
        m_jmethodRCO                             = FindClassMethod(env, m_jclassSCORCOListener, "rco", "(Ljava/lang/String;)[B");

        // TODO: resman

        m_jclassNWObject                         = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWObject");
        m_jmethodNWObjectCreate                  = FindClassMethod(env, m_jclassNWObject, "apply", "(I)Lorg/nwnx/nwnx2/jvm/NWObject;");
        m_jmethodNWObjectgetOid                  = FindMethod(env, m_jclassNWObject, "oid", "()I");

        m_jclassNWVector                         = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWVector");
        m_jmethodNWVectorCreate                  = FindClassMethod(env, m_jclassNWVector, "apply", "(FFF)Lorg/nwnx/nwnx2/jvm/NWVector;");
        m_jmethodNWVectorgetX                    = FindMethod(env, m_jclassNWVector, "x", "()F");
        m_jmethodNWVectorgetY                    = FindMethod(env, m_jclassNWVector, "y", "()F");
        m_jmethodNWVectorgetZ                    = FindMethod(env, m_jclassNWVector, "z", "()F");

        m_jclassNWLocation                       = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWLocation");
        m_jmethodNWLocationCreate                = FindClassMethod(env, m_jclassNWLocation, "apply", "(Lorg/nwnx/nwnx2/jvm/NWObject;FFFF)Lorg/nwnx/nwnx2/jvm/NWLocation;");
        m_jmethodNWLocationgetArea               = FindMethod(env, m_jclassNWLocation, "area", "()Lorg/nwnx/nwnx2/jvm/NWObject;");
        m_jmethodNWLocationgetX                  = FindMethod(env, m_jclassNWLocation, "x", "()F");
        m_jmethodNWLocationgetY                  = FindMethod(env, m_jclassNWLocation, "y", "()F");
        m_jmethodNWLocationgetZ                  = FindMethod(env, m_jclassNWLocation, "z", "()F");
        m_jmethodNWLocationgetFacing             = FindMethod(env, m_jclassNWLocation, "facing", "()F");

        m_jclassNWEffect                         = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWEffect");
        m_jmethodNWEffectCreate                  = FindClassMethod(env, m_jclassNWEffect, "apply", "(I)Lorg/nwnx/nwnx2/jvm/NWEffect;");
        m_jmethodNWEffectgetOid                  = FindMethod(env, m_jclassNWEffect, "oid", "()I");

        m_jclassNWItemProperty                   = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWItemProperty");
        m_jmethodNWItemPropertyCreate            = FindClassMethod(env, m_jclassNWItemProperty, "apply", "(I)Lorg/nwnx/nwnx2/jvm/NWItemProperty;");
        m_jmethodNWItemPropertygetOid            = FindMethod(env, m_jclassNWItemProperty, "oid", "()I");

        m_jclassNWNotInContextException          = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWNotInContextException");
        m_jclassNWInvalidObjectException         = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWInvalidObjectException");
        m_jclassNWInvalidEffectException         = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWInvalidEffectException");
        m_jclassNWInvalidItemPropertyException   = (jclass) NewGlobalClassRef(env, "org/nwnx/nwnx2/jvm/NWInvalidItemPropertyException");

        m_jclassEventListener                    = (jclass) NewGlobalClassRef(env, m_parent->m_config.m_classname_eventListener);
        m_jmethodJavaEvent                       = FindClassMethod(env, m_jclassEventListener, "event", "(Lorg/nwnx/nwnx2/jvm/NWObject;Ljava/lang/String;)V");

        m_jclassTokenListener                    = (jclass) NewGlobalClassRef(env, m_parent->m_config.m_classname_tokenListener);
        m_jmethodJavaToken                       = FindClassMethod(env, m_jclassTokenListener, "token", "(Lorg/nwnx/nwnx2/jvm/NWObject;Ljava/lang/String;)V");

        m_jclassConv                             = (jclass) NewGlobalClassRef(env, m_parent->m_config.m_classname_convClass);
        m_jmethodConvToNative                    = FindClassMethod(env, m_jclassConv, "toNative", "(Ljava/lang/String;)[B");
        m_jmethodConvFromNative                  = FindClassMethod(env, m_jclassConv, "fromNative", "([B)Ljava/lang/String;");

        // All done, tell them!
        JNICHECKED(env, CallStaticVoidMethod(m_jclassInitListener, m_jmethodJavaInit));
    });

    BindNWScript();
    BindSCORCO();

    LOG_INFO("%s", "We're up.");
}

Internal::~Internal()
{
    DoAttached([&](JavaVM*, JNIEnv* env) {
        JNICHECKED(env, CallStaticVoidMethod(m_jclassInitListener, m_jmethodJavaShutdown));
    });

    UnbindSCORCO();
    UnbindNWScript();
}

ArgumentStack Internal::OnEvent(ArgumentStack&& args)
{
    return EntryPoint(m_jmethodJavaEvent, args);
}

ArgumentStack Internal::OnToken(ArgumentStack&& args)
{
    return EntryPoint(m_jmethodJavaToken, args);
}

ArgumentStack Internal::EntryPoint(jmethodID method, ArgumentStack& args)
{
    ArgumentStack stack;
    const auto arg_event  = Services::Events::ExtractArgument<std::string>(args);
    const auto arg_oid    = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (!method)
        throw std::runtime_error("Cannot divine method to call. Event not hooked up properly.");

    DoAttached([&](JavaVM*, JNIEnv* env) {
        jobject objSelf = JNICHECKED(env, CallStaticObjectMethod(m_jclassNWObject, m_jmethodNWObjectCreate, arg_oid));

        jstring event = JNICHECKED(env, NewStringUTF(arg_event.c_str())); // TODO: convert to utf-8? unlikely to be needed.

        // TODO: NWScript calls for this invocation
        // static uint32_t nwscript_calls = 0;

        if (objSelf != nullptr) {
            JNICHECKED(env, CallStaticVoidMethod(m_jclassEventListener, method, objSelf, event));
        }
    });

    // reset event mappings
    if (m_contextDepth == 0) {
        m_touchedEffects.clear();
    }

    // TODO: stats

    return stack;
}

}
