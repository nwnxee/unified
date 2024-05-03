#pragma once

namespace DotNET {
    using MainLoopHandlerType =  void (*)(uint64_t);
    using RunScriptHandlerType = int (*)(const char*, uint32_t);
    using ClosureHandlerType =   void (*)(uint64_t, uint32_t);
    using SignalHandlerType =    void (*)(const char*);
    using AssertHandlerType =    void (*)(const char*, const char*);
    using CrashHandlerType =     void (*)(int, const char*);

    struct AllHandlers
    {
        MainLoopHandlerType      MainLoop;
        RunScriptHandlerType     RunScript;
        ClosureHandlerType       Closure;
        SignalHandlerType        SignalHandler;
        AssertHandlerType        AssertHandler;
        CrashHandlerType         CrashHandler;
    };
}
