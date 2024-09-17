#pragma once

#include "API/ALL_CLASSES.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"

#include <string>
#include <optional>
#include <vector>
#include <functional>
#include <memory>



namespace NWNXLib
{

#define NWNX_EXPORT       extern "C"

#define LOG_DEBUG(format, ...)   LOG_IMPL(SEV_DEBUG,   format, ##__VA_ARGS__)
#define LOG_INFO(format, ...)    LOG_IMPL(SEV_INFO,    format, ##__VA_ARGS__)
#define LOG_NOTICE(format, ...)  LOG_IMPL(SEV_NOTICE,  format, ##__VA_ARGS__)
#define LOG_WARNING(format, ...) LOG_IMPL(SEV_WARNING, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)   LOG_IMPL(SEV_ERROR,   format, ##__VA_ARGS__)
#define LOG_FATAL(format, ...)   LOG_IMPL(SEV_FATAL,   format, ##__VA_ARGS__)

#define ASSERT(condition)                   ASSERT_IMPL(condition)
#define ASSERT_MSG(condition, format, ...)  ASSERT_MSG_IMPL(condition, format, ##__VA_ARGS__)
#define ASSERT_FAIL()                       ASSERT_FAIL_IMPL()
#define ASSERT_FAIL_MSG(format, ...)        ASSERT_FAIL_MSG_IMPL(format, ##__VA_ARGS__)
#define ASSERT_OR_THROW(condition)          ASSERT_OR_THROW_IMPL(condition)
#define ASSERT_OR_RETURN(condition, retval) ASSERT_OR_RETURN_IMPL(condition, retval)

#define SCOPEGUARD(x) SCOPEGUARD_IMPL(x)

namespace Config
{
    // Retrieves a configuration value. Note that key is case-insensitive, but
    // configuration is expected to be defined all-upcase in ENV.
    std::optional<std::string> GetRaw(const std::string& key, const std::string& section);

    // Gets a config value.
    template<typename T>
    std::optional<T> Get(const std::string& key, const std::string& module = PLUGIN_NAME);

    template<typename T>
    T Get(const std::string& key, T&& def, const std::string& module = PLUGIN_NAME);
}

struct ScriptVariant;
struct ScriptVariantStack;
namespace ScriptAPI
{
    using Argument = ScriptVariant;
    using ArgumentStack = ScriptVariantStack;
    using FunctionCallback = std::function<ArgumentStack(ArgumentStack&& in)>;

    void RegisterEvent(const std::string& pluginName, const std::string& eventName, FunctionCallback&& cb);

    template <typename T> static void Push(T&& value);
    template <typename T> static std::optional<T> Pop();
    void Call(const std::string& pluginName, const std::string& eventName);
}
using ArgumentStack = ScriptVariantStack;

namespace Hooks
{
    namespace Order
    {
        constexpr int32_t SharedHook = INT32_MIN;
        constexpr int32_t Earliest   = -3000000;
        constexpr int32_t VeryEarly  = -2000000;
        constexpr int32_t Early      = -1000000;
        constexpr int32_t Default    = 0;
        constexpr int32_t Late       = 1000000;
        constexpr int32_t VeryLate   = 2000000;
        constexpr int32_t Latest     = 3000000;
        constexpr int32_t Final      = INT32_MAX;
    }

    class FunctionHook final
    {
    public:
        FunctionHook(void* originalFunction, void* newFunction, int32_t order = Order::Default);
        ~FunctionHook();

        void *GetOriginal() { return m_trampoline; }
        template <typename Ret, typename ... Params>
        Ret CallOriginal(Params ... args)
        {
            return reinterpret_cast<Ret(*)(Params...)>(GetOriginal())(args ...);
        }

    private:
        void*       m_originalFunction;
        void*       m_newFunction;
        int32_t     m_order;
        void*       m_funchook;
        void*       m_trampoline;

        static inline std::unordered_map<void*, std::vector<FunctionHook*>> s_hooks;
    };

    using Hook = std::unique_ptr<FunctionHook>;

    template <typename T1, typename T2>
    [[nodiscard]] Hook HookFunction(T1 original, T2 replacement, int32_t order = Order::Default)
    {
        return std::make_unique<FunctionHook>((void*)original, (void *)replacement, order);
    }
}

namespace MessageBus
{
    using Message = std::vector<std::string>;
    using Handler = std::function<void(const Message&)>;

    uint32_t Subscribe(const std::string& tag, const Handler& handler);
    void Unsubscribe(const uint32_t id);
    void Broadcast(const std::string& tag, const Message& message);
}

namespace Platform
{
    bool IsDebuggerPresent();
    std::string GetStackTrace(uint8_t levels);
}

namespace Commands
{
    bool Register(const std::string& cmd, std::function<void(std::string&, std::string&)> func);
    void Unregister(const std::string& cmd);

    bool Schedule(std::string&& cmdline);
    void RunScheduled();
}

namespace String
{
    enum Locale
    {
        Default,
        cp1250,
        cp1251,
        cp1252,
    };
    Locale GetDefaultLocale();
    void SetDefaultLocale(Locale locale);
    void SetDefaultLocale(const std::string& locale);

    std::string ToUTF8(const char *str, Locale locale = Default);
    std::string ToUTF8(const std::string& str, Locale locale = Default);
    std::string FromUTF8(const char *str, Locale locale = Default);
    std::string FromUTF8(const std::string& str, Locale locale = Default);

    std::string ToBase64(const std::vector<uint8_t>& in);
    std::vector<uint8_t> FromBase64(const std::string &in);

    template <typename T>
    std::optional<T> FromString(const std::string& str);

    // Modifies str
    std::string& LTrim(std::string& str);
    std::string& RTrim(std::string& str);
    std::string& Trim(std::string& str);

    std::string Join(const std::vector<std::string>& str, const char* delim = " ");
    std::vector<std::string> Split(const std::string& str, char delim, bool skipEmpty = true, bool trimmed = true);

    std::string Basename(const std::string& path);
    bool EndsWith(const std::string& str, const std::string& suffix);
}

namespace Utils
{
    std::string ObjectIDToString(const ObjectID id);
    ObjectID StringToObjectID(const std::string idStr);

    std::string GetCurrentScript();
    void ExecuteScript(const std::string& script, ObjectID oidOwner);

    // Since there's no RTTI, and NWN's dynamic casts don't work in NWNX.
    // These return nullptr if the object type isn't right.
    CNWSArea*               AsNWSArea(CGameObject* obj);
    CNWSAreaOfEffectObject* AsNWSAreaOfEffectObject(CGameObject* obj);
    CNWSCreature*           AsNWSCreature(CGameObject* obj);
    CNWSDoor*               AsNWSDoor(CGameObject* obj);
    CNWSEncounter*          AsNWSEncounter(CGameObject* obj);
    CNWSItem*               AsNWSItem(CGameObject* obj);
    CNWSModule*             AsNWSModule(CGameObject* obj);
    CNWSObject*             AsNWSObject(CGameObject* obj);
    CNWSPlaceable*          AsNWSPlaceable(CGameObject* obj);
    CNWSSoundObject*        AsNWSSoundObject(CGameObject* obj);
    CNWSStore*              AsNWSStore(CGameObject* obj);
    CNWSTrigger*            AsNWSTrigger(CGameObject* obj);
    CNWSWaypoint*           AsNWSWaypoint(CGameObject* obj);

    CGameObject* GetGameObject(ObjectID objectId);
    CNWSModule* GetModule();

    // Wrappers around non-virtual methods repeated for all NWS types
    bool AcquireItem(CNWSItem *pItem, CGameObject *pOwner);
    bool AddToArea(CGameObject *pObject, CNWSArea *pArea, float x, float y, float z);

    // Returns TRUE if the var tables have the same variables with same values
    bool CompareVariables(CNWSScriptVarTable *pVars1, CNWSScriptVarTable *pVars2);
    CNWSScriptVarTable *GetScriptVarTable(CGameObject *pObject);

    void DestroyGameEffect(CGameEffect* pEffect);

    std::string ExtractLocString(CExoLocString& locStr, int32_t nID = 0, uint8_t bGender = 0);
    CExoLocString CreateLocString(const std::string& str, int32_t nID = 0, uint8_t bGender = 0);

    template <typename T>
    T PeekMessage(CNWSMessage *pMessage, int32_t offset);

    void AddStealthEvent(int32_t which, ObjectID oidSelf, ObjectID oidTarget);
    void AddObjectEnterAreaEvent(ObjectID oid, ObjectID oidArea);
    void AddObjectExitAreaEvent(ObjectID oid, ObjectID oidArea);
    void AddOnAcquireItemEvent(ObjectID oidItem, ObjectID oidBy, ObjectID oidFrom, int32_t stackSize);
    void AddOnLoseItemEvent(ObjectID oidItem, ObjectID oidBy);
    void AddDestroyObjectEvent(ObjectID oid);

    // Returns the SP
    int PushScriptContext(ObjectID oid, int32_t scriptEventId, bool valid = true);
    int PopScriptContext();

    void SetOrientation(CNWSObject *pObject, float facing);
    bool IsValidCustomResourceDirectoryAlias(const std::string& filename);

    // bStripPCFlags - A serialized PC creature will have the bIsPC set to false,
    // so that when deserialized as a new CGameObject, it becomes destroyable.
    std::vector<uint8_t> SerializeGameObject(CGameObject *pObject, bool bStripPCFlags = true);
    std::string SerializeGameObjectB64(CGameObject *pObject, bool bStripPCFlags = true);

    // A deserialized object is added to the world at its location when it was serialized
    // The location may not be valid, so it is best to explictly move the object immediately
    // afterwards. The new object has a unique ObjectID
    CGameObject* DeserializeGameObject(const std::vector<uint8_t>& serialized);
    CGameObject* DeserializeGameObjectB64(const std::string& serializedB64);

    CGameObject*   PopGameObject(ArgumentStack& args, bool throwOnFail=false);
    CNWSObject*    PopObject(ArgumentStack& args, bool throwOnFail=false);
    CNWSCreature*  PopCreature(ArgumentStack& args, bool throwOnFail=false);
    CNWSArea*      PopArea(ArgumentStack& args, bool throwOnFail=false);
    CNWSPlayer*    PopPlayer(ArgumentStack& args, bool throwOnFail=false);
    CNWSItem*      PopItem(ArgumentStack& args, bool throwOnFail=false);
    CNWSEncounter* PopEncounter(ArgumentStack& args, bool throwOnFail=false);
    CNWSPlaceable* PopPlaceable(ArgumentStack& args, bool throwOnFail=false);
    CNWSWaypoint*  PopWaypoint(ArgumentStack& args, bool throwOnFail=false);
    CNWSTrigger*   PopTrigger(ArgumentStack& args, bool throwOnFail=false);
    CNWSDoor*      PopDoor(ArgumentStack& args, bool throwOnFail=false);
    CNWSStore*     PopStore(ArgumentStack& args, bool throwOnFail=false);

    int32_t NWScriptObjectTypeToEngineObjectType(int32_t nwscriptObjectType);
    void UpdateClientObject(ObjectID oidObject);
    void UpdateClientObjectForPlayer(ObjectID oidObject, CNWSPlayer* oidPlayer);
}

namespace POS
{
    using CleanupFunc = std::function<void(void*)>;
    void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, int value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, float value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, std::string value, bool persist = false);
    void Set(CGameObject *pGameObject, const std::string& prefix, const std::string& key, void *value, std::optional<CleanupFunc> cleanup);

    // Gets the value, but doesn't remove it
    template <typename T> std::optional<T>
    Get(CGameObject *pGameObject, const std::string& prefix, const std::string& key);

    // Removes without cleanup
    void Remove(CGameObject *pGameObject, const std::string& prefix, const std::string& key);
    void RemoveRegex(CGameObject *pGameObject, const std::string& prefix, const std::string& regex);
}

namespace Tasks
{
    using WorkItem = std::function<void()>;
    void QueueOnMainThread(WorkItem&& work);
    void QueueOnAsyncThread(WorkItem&& work);
    void ProcessMainThreadWork();
}

}

#include "Assert.hpp"
#include "ScriptVariant.hpp"
#include "Config.hpp"
#include "ScriptAPI.hpp"
#include "Utils.hpp"

namespace NWNXLib
{
struct ScopeGuard {
    template<class C> ScopeGuard(C&& func) : f(std::forward<C>(func)) {}
    ScopeGuard(ScopeGuard&& sg) : f(std::move(sg.f)) {
        sg.f = nullptr;
    }
    ~ScopeGuard() {
        if (f) f();
    }
    void dismiss() noexcept {
        f = nullptr;
    }
    ScopeGuard(const ScopeGuard&) = delete;
    void operator=(const ScopeGuard&) = delete;
    std::function<void()> f;
};

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a,b)
#define SCOPEGUARD_IMPL(x) ::NWNXLib::ScopeGuard CAT(_scopeguard_, __LINE__) ([&]{x;})
}

#include "Instrumentation.hpp"

// TODO: Remove entry points
//todo: remove with Plugin
#include "Services/Services.hpp"
#define NWNX_PLUGIN_ENTRY extern "C"
namespace NWNXLib {
class Plugin
{
public:
    using EntryFunction = Plugin*(*)(Services::ProxyServiceList*);

    Plugin(Services::ProxyServiceList*);
    virtual ~Plugin() {}

    Services::ProxyServiceList* GetServices() { return m_services; }
    std::string GetName() { return m_name; }

    void* GetExportedSymbol(const std::string& symbolName);

    static Plugin* Find(const std::string& pluginName);
    static Plugin* Load(const std::string& path, std::unique_ptr<Services::ProxyServiceList>&& services);
    static void UnloadAll();

private:
    std::string m_name;
    std::string m_path;
    void* m_handle;
    // HACK: While the API is migrated, we need both of these..
    Services::ProxyServiceList* m_services;
    std::unique_ptr<Services::ProxyServiceList> m_servicesOwning;

    static inline std::vector<Plugin*> s_plugins;
};
}
