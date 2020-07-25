#pragma once

#include "Plugin.hpp"
#include "API/ALL_CLASSES.hpp"

namespace DotNET {

class DotNET : public NWNXLib::Plugin
{
public:
    DotNET(NWNXLib::Services::ProxyServiceList* services);
    virtual ~DotNET();

private:
    static inline DotNET* Instance;

    static bool InitThunks();

    // Bootstrap functions
    using MainLoopHandlerType  = void (*)(uint64_t);
    using RunScriptHandlerType = int (*)(const char *, uint32_t);
    using ClosureHandlerType = void (*)(uint64_t, uint32_t);

    struct AllHandlers
    {
        MainLoopHandlerType  MainLoop;
        RunScriptHandlerType RunScript;
        ClosureHandlerType   Closure;
    };
    static inline AllHandlers Handlers;

    static uintptr_t GetFunctionPointer(const char *name);
    static void RegisterHandlers(AllHandlers *handlers, unsigned size);

    // NWScript VM functions
    static inline uint32_t PushedCount = 0;
    static void CallBuiltIn(int32_t id);
    static void StackPushInteger(int32_t value);
    static void StackPushFloat(float value);
    static void StackPushString(const char* value);
    static void StackPushObject(uint32_t value);
    static void StackPushVector(Vector value);
    static void StackPushEffect(CGameEffect* value);
    static void StackPushEvent(CScriptEvent* value);
    static void StackPushLocation(CScriptLocation* value);
    static void StackPushTalent(CScriptTalent* value);
    static void StackPushItemProperty(CGameEffect* value);
    static int32_t StackPopInteger();
    static float StackPopFloat();
    static const char* StackPopString();
    static uint32_t StackPopObject();
    static Vector StackPopVector();
    static CGameEffect* StackPopEffect();
    static CScriptEvent* StackPopEvent();
    static CScriptLocation* StackPopLocation();
    static CScriptTalent* StackPopTalent();
    static CGameEffect* StackPopItemProperty();
    static void FreeEffect(void* ptr);
    static void FreeEvent(void* ptr);
    static void FreeLocation(void* ptr);
    static void FreeTalent(void* ptr);
    static void FreeItemProperty(void* ptr);
    static int32_t ClosureAssignCommand(uint32_t oid, uint64_t eventId);
    static int32_t ClosureDelayCommand(uint32_t oid, float duration, uint64_t eventId);
    static int32_t ClosureActionDoCommand(uint32_t oid, uint64_t eventId);

    // NWNX interface functions
    static inline std::string nwnxActivePlugin;
    static inline std::string nwnxActiveFunction;
    static void nwnxSetFunction(const char *plugin, const char *function);
    static void nwnxPushInt(int32_t n);
    static void nwnxPushFloat(float f);
    static void nwnxPushObject(uint32_t o);
    static void nwnxPushString(const char *s);
    static void nwnxPushEffect(CGameEffect *e);
    static void nwnxPushItemProperty(CGameEffect *ip);
    static int32_t nwnxPopInt();
    static float nwnxPopFloat();
    static uint32_t nwnxPopObject();
    static const char* nwnxPopString();
    static CGameEffect* nwnxPopEffect();
    static CGameEffect* nwnxPopItemProperty();
    static void nwnxCallFunction();
};


}
