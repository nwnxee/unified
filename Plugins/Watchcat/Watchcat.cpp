#include "nwnx.hpp"

#include "API/CServerExoAppInternal.hpp"
#include "API/CVirtualMachine.hpp"
#include "Globals.hpp"

#include <atomic>
#include <chrono>
#include <cstdint>
#include <execinfo.h>
#include <pthread.h>
#include <signal.h>
#include <sys/prctl.h>
#include <sys/resource.h>
#include <thread>
#include <unordered_map>

using namespace NWNXLib;

// Do not engage watchcat until this many msec have passed after module load.
#define WATCHCAT_WARMUP_MSEC            60000
// If the mainloop stalls for this many msec, we start sampling callstacks.
#define WATCHCAT_STALL_MSEC             1000
// While stalling, sample stacks at this rate.
#define WATCHCAT_STALL_SAMPLE_RATE_MSEC 16
// Print this many stacks, by occurence desc.
#define WATCHCAT_TOP_N_STACKS           10
// Kill server with a FATAL message when a stall lasts longer than this many msec.
// This assumes the thing is thoroughly wedged with no hope of recovery.
#define WATCHCAT_KILL_MSEC              120000

// Turn this on to stall the server every 100 ticks for 5 seconds (for debugging Watchcat).
// #define WATCHCAT_SIMULATE_STALL

// Don't change the signal unless you are already using USR2 for something else.
#define CALLSTACK_SIG  SIGUSR2
// Max depth collected.
#define CALLSTACK_SIZE 32

using Callstack = std::vector<void*>;

struct CallstackHash
{
    std::size_t operator()(const Callstack& callstack) const
    {
        std::size_t hash = 0;
        std::hash<void*> hasher;
        for (void* ptr : callstack)
        {
            hash ^= hasher(ptr) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct CallstackEqual
{
    bool operator()(const Callstack& lhs, const Callstack& rhs) const { return lhs == rhs; }
};

using CallstackMap = std::unordered_map<Callstack, size_t, CallstackHash, CallstackEqual>;

static pthread_t s_mainThreadId;
static pthread_t s_watchcatThreadId;

// Written by the signal handler on the main thread.
static void* s_mainThreadStack[CALLSTACK_SIZE];
static int s_mainThreadStackLen = 0;
// Guarded by this.
static std::atomic<bool> s_callstackCallback;

static std::atomic<bool> s_watchcatDisabledUntilScriptExit;

static uint64_t s_mainThreadCounter = 0;

std::unique_ptr<struct WatchThread> s_watchcatThread;

[[gnu::noinline]]
static void callstack_signal_handler(int, siginfo_t*, void*)
{
    if (pthread_self() == s_watchcatThreadId)
    {
        assert(!s_callstackCallback.load());
        s_callstackCallback.store(true);
        return;
    }

    assert(pthread_self() == s_mainThreadId);

    s_mainThreadStackLen = backtrace(s_mainThreadStack, CALLSTACK_SIZE);

    const void* backtrace_addr = (void*)backtrace;
    const void* backtrace_symbols_addr = (void*)backtrace_symbols;

    int frames_to_skip = 1; // this signal handler
    for (int i = 0; i < s_mainThreadStackLen; ++i)
    {
        if (s_mainThreadStack[i] == backtrace_addr || s_mainThreadStack[i] == backtrace_symbols_addr)
        {
            frames_to_skip += i;
            break;
        }
    }

    if (frames_to_skip > 0 && s_mainThreadStackLen > frames_to_skip)
    {
        s_mainThreadStackLen -= frames_to_skip;
        memmove(s_mainThreadStack, s_mainThreadStack + frames_to_skip,
            s_mainThreadStackLen * sizeof(void*));
    }

    pthread_kill(s_watchcatThreadId, CALLSTACK_SIG);
}

static void callstack_register_handler()
{
    LOG_INFO("Thread %d, setting up callstack signal handler", pthread_self());
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = callstack_signal_handler;
    sigfillset(&sa.sa_mask);
    sigaction(CALLSTACK_SIG, &sa, NULL);
}

static void DumpStacks(const CallstackMap& callstacks)
{
    std::vector<std::pair<Callstack, size_t>> sortedCallstacks(callstacks.begin(),
        callstacks.end());
    std::sort(sortedCallstacks.begin(), sortedCallstacks.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });

    const size_t numstacks = std::min(WATCHCAT_TOP_N_STACKS,
        static_cast<int>(sortedCallstacks.size()));
    for (size_t i = 0; i < numstacks; ++i)
    {
        const auto& [callstack, occurs] = sortedCallstacks.at(i);
        char** strstack = backtrace_symbols(callstack.data(), callstack.size());
        LOG_ERROR("Callstack %d: %d occurences", i, occurs);
        for (size_t k = 0; k < callstack.size(); ++k)
        {
            LOG_ERROR("  %s", strstack[k]);
        }
        free(strstack);
    }
    if (numstacks < sortedCallstacks.size())
    {
        LOG_WARNING("... and %d more", sortedCallstacks.size() - numstacks);
    }
}

static void WatchcatThread()
{
    using namespace std::chrono;

    s_watchcatThreadId = pthread_self();
    callstack_register_handler();

    // Warmup delay to prevent false positives when the server is starting up.
    LOG_INFO("Watchcat ^.^~ sleeping for %dms before arming", WATCHCAT_WARMUP_MSEC);
    std::this_thread::sleep_for(milliseconds(WATCHCAT_WARMUP_MSEC));
    LOG_INFO("Watchcat ^.^~ thread starting");

    // Last count and time we saw the main thread tick over.
    uint64_t lastObservedCounter = 0;
    time_point<steady_clock> lastObservedAt;

    while (!g_bExitProgram)
    {
        std::this_thread::sleep_for(milliseconds(16));

        const auto now = steady_clock::now();
        const uint64_t mainThreadAt = s_mainThreadCounter;

        // All is well, main thread seems to be running.
        if (mainThreadAt > lastObservedCounter)
        {
            lastObservedCounter = mainThreadAt;
            lastObservedAt = now;
            continue;
        }

        if (now - lastObservedAt < milliseconds(WATCHCAT_STALL_MSEC))
        {
            continue;
        }

        if (s_watchcatDisabledUntilScriptExit.load())
        {
            continue;
        }

        LOG_ERROR("Watchcat ^.^~ detected a stall.");

        CallstackMap callstacks;

        while (s_mainThreadCounter == lastObservedCounter && !g_bExitProgram)
        {
            LOG_DEBUG("Still stalling: Sampling main thread.");

            assert(s_callstackCallback.is_lock_free());

            // Send a signal to the main thread to get a callstack.
            // The signal handler will send the same signal back at us and WE will
            // handle the stack store.
            s_callstackCallback.store(false);
            ASSERT(pthread_kill(s_mainThreadId, CALLSTACK_SIG) == 0);
            while (!s_callstackCallback.load()) {}

            const Callstack callstack(s_mainThreadStack, s_mainThreadStack + s_mainThreadStackLen);
            callstacks[callstack]++;

            if (steady_clock::now() - lastObservedAt >
                milliseconds(WATCHCAT_STALL_MSEC + WATCHCAT_KILL_MSEC))
            {
                DumpStacks(callstacks);
                if (prctl(PR_SET_DUMPABLE, 1) != 0)
                {
                    LOG_WARNING("Failed to set PR_SET_DUMPABLE, errno=%d", errno);
                }
                LOG_FATAL("Watchcat ^.^~ ran out of patience.");
            }

            std::this_thread::sleep_for(milliseconds(WATCHCAT_STALL_SAMPLE_RATE_MSEC));
        }

        LOG_ERROR("Stall recovered after %lums",
            duration_cast<milliseconds>(now - lastObservedAt).count());

        DumpStacks(callstacks);

        continue;
    }

    LOG_DEBUG("Watchcat thread exiting");
}

struct WatchThread
{
    explicit WatchThread() : m_thread(&WatchcatThread) {}
    ~WatchThread() { m_thread.join(); }
    std::thread m_thread;
};

static std::atomic<uint32_t> s_watchcatDisabledUntilScriptExitLevel = 0;

static void WatchcatCtor() __attribute__((constructor));
static void WatchcatCtor()
{
    struct rlimit core_limit;
    if (getrlimit(RLIMIT_CORE, &core_limit) == 0)
    {
        if (core_limit.rlim_cur == RLIM_INFINITY)
        {
            LOG_INFO("Core dump limit is correctly set to unlimited.");
        }
        else
        {
            LOG_WARNING("Core dump limit is not set to unlimited. Current limit: %ld bytes.",
                core_limit.rlim_cur);
        }
    }
    else
    {
        LOG_ERROR("Unable to get core dump limit.");
    }

    s_mainThreadId = pthread_self();
    callstack_register_handler();

    static Hooks::Hook mainLoopHook = Hooks::HookFunction(
        &CServerExoAppInternal::MainLoop,
        +[](CServerExoAppInternal* thisPtr)
        {
            ++s_mainThreadCounter;

            if (!s_watchcatThread)
            {
                s_watchcatThread = std::make_unique<WatchThread>();
            }

#ifdef WATCHCAT_SIMULATE_STALL
            if (s_mainThreadCounter % 100 == 0)
            {
                LOG_INFO("Simulating long stall");
                std::this_thread::sleep_for(std::chrono::seconds(5));
                LOG_INFO("Simulated long stall complete");
            }
#endif

            return mainLoopHook->CallOriginal<int32_t>(thisPtr);
        },
        Hooks::Order::Earliest);

    static Hooks::Hook runScript = Hooks::HookFunction(
        &CVirtualMachine::RunScript,
        +[](CVirtualMachine* thisPtr, CExoString* script, OBJECT_ID oid, BOOL valid, int32_t id)
        {
            const BOOL ret = runScript->CallOriginal<BOOL>(thisPtr, script, oid, valid, id);
            if (s_watchcatDisabledUntilScriptExit.load())
            {
                assert(s_watchcatDisabledUntilScriptExitLevel > 0);
                s_watchcatDisabledUntilScriptExit.store(false);
                s_watchcatDisabledUntilScriptExitLevel--;
            }
            return ret;
        });
}

NWNX_EXPORT ArgumentStack DisableUntilScriptExit(ArgumentStack&&)
{
    s_watchcatDisabledUntilScriptExitLevel++;
    s_watchcatDisabledUntilScriptExit.store(true);
    return {};
}
