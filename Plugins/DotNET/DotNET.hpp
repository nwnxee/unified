#pragma once

#include "nwnx.hpp"
#include "API/ALL_CLASSES.hpp"
#include "API/Globals.hpp"

namespace DotNET {

class DotNET : public NWNXLib::Plugin
{
public:
    DotNET(NWNXLib::Services::ProxyServiceList* services);
    virtual ~DotNET();

private:
    static inline DotNET* Instance;

    static bool InitThunks();

    static inline std::vector<std::unique_ptr<NWNXLib::Hooks::FunctionHook>> s_managed_hooks;

    // Bootstrap functions
    using MainLoopHandlerType  = void (*)(uint64_t);
    using RunScriptHandlerType = int (*)(const char *, uint32_t);
    using ClosureHandlerType = void (*)(uint64_t, uint32_t);
    using SignalHandlerType = void (*)(const char*);

    struct AllHandlers
    {
        MainLoopHandlerType  MainLoop;
        RunScriptHandlerType RunScript;
        ClosureHandlerType   Closure;
        SignalHandlerType    SignalHandler;
    };
    static inline AllHandlers Handlers;

    static void RegisterHandlers(AllHandlers* handlers, unsigned size);

    // Interop functions
    static uintptr_t GetFunctionPointer(const char *name);
    static void* RequestHook(uintptr_t address, void* managedFuncPtr, int32_t order);
    static void ReturnHook(void* trampoline);
    static NWNXLib::API::Globals::NWNXExportedGlobals GetNWNXExportedGlobals();

    // NWScript VM functions
    static inline uint32_t PushedCount = 0;
    static void CallBuiltIn(int32_t id);
    static void StackPushInteger(int32_t value);
    static void StackPushFloat(float value);
    static void StackPushString(const char* value);
    static void StackPushObject(uint32_t value);
    static void StackPushVector(Vector value);
    static void StackPushGameDefinedStructure(int32_t structId, void* value);
    static int32_t StackPopInteger();
    static float StackPopFloat();
    static const char* StackPopString();
    static uint32_t StackPopObject();
    static Vector StackPopVector();
    static void* StackPopGameDefinedStructure(int32_t structId);
    static void FreeGameDefinedStructure(int32_t structId, void* ptr);
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
