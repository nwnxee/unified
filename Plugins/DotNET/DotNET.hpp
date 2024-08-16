#pragma once

namespace DotNET {
    using MainLoopHandler =  void (*)(uint64_t);
    using RunScriptHandler = int (*)(const char*, uint32_t);
    using ClosureHandler =   void (*)(uint64_t, uint32_t);
    using SignalHandler =    void (*)(const char*);
    using AssertHandler =    void (*)(const char*, const char*);
    using CrashHandler =     void (*)(int, const char*);

    struct AllHandlers
    {
        MainLoopHandler      MainLoop;
        RunScriptHandler     RunScript;
        ClosureHandler       Closure;
        SignalHandler        Signal;
        AssertHandler        Assert;
        CrashHandler         Crash;
    };
}
