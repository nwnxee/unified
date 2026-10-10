#include "nwnx.hpp"

#include "API/CAppManager.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CVirtualMachine.hpp"
#include "Globals.hpp"

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <dlfcn.h>
#include <execinfo.h>
#include <pthread.h>
#include <signal.h>
#include <thread>
#include <type_traits>
#include <unordered_map>

using namespace NWNXLib;

struct WatchcatConfig
{
    // Do not engage watchcat until this many msec have passed after plugin load.
    uint32_t warmup_msec = 5000;

    // If the mainloop stalls for this many msec, we start sampling callstacks.
    uint32_t stall_msec = 1000;

    // While stalling, sample stacks at this rate.
    uint32_t stall_sample_rate_msec = 16;

    // Kill server with a FATAL message when a stall lasts longer than this many msec.
    // This assumes the thing is thoroughly wedged with no hope of recovery.
    uint32_t kill_msec = 120000;

    // Turn this on to stall the server every 100 ticks for 5 seconds (for debugging Watchcat).
    bool test_mode = false;

    explicit WatchcatConfig()
    {
        warmup_msec = Config::Get<uint32_t>("WARMUP_MSEC").value_or(warmup_msec);
        stall_msec = Config::Get<uint32_t>("STALL_MSEC").value_or(stall_msec);
        stall_sample_rate_msec = Config::Get<uint32_t>("STALL_SAMPLE_RATE_MSEC")
                                     .value_or(stall_sample_rate_msec);
        kill_msec = Config::Get<uint32_t>("KILL_MSEC").value_or(kill_msec);
        test_mode = Config::Get<bool>("TEST_MODE").value_or(test_mode);
    }
};

// Print this many stacks, by occurence desc.
#define WATCHCAT_TOP_N_STACKS 10

// Don't change the signal unless you are already using USR2 for something else.
#define CALLSTACK_SIG         SIGUSR2
// Max depth collected.
#define CALLSTACK_SIZE        32

struct StackFrame
{
    // The raw pointer from the backtrace, which may be an offset into the function.
    void* raw_ptr;
    // The resolved function base address, or the raw pointer if resolution failed.
    // Used for hashing and display.
    void* func_base;
};

using Callstack = std::vector<StackFrame>;

struct CallstackHash
{
    std::size_t operator()(const Callstack& callstack) const
    {
        std::size_t hash = 0;
        std::hash<void*> hasher;
        for (const auto& frame : callstack)
        {
            hash ^= hasher(frame.func_base) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

struct CallstackEqual
{
    bool operator()(const Callstack& lhs, const Callstack& rhs) const
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); ++i)
        {
            if (lhs[i].func_base != rhs[i].func_base)
                return false;
        }
        return true;
    }
};

using CallstackMap = std::unordered_map<Callstack, size_t, CallstackHash, CallstackEqual>;

static pthread_t s_mainThreadId;
static pthread_t s_watchcatThreadId;

// Written by the signal handler on the main thread:
static void* s_mainThreadStack[CALLSTACK_SIZE];
static int s_mainThreadStackLen = 0;
// Guarded by this:
static std::atomic<bool> s_callstackCallback { false };

static std::atomic<uint32_t> s_watchcatDisabledUntilScriptExitLevel { 0 };
static std::atomic<uint64_t> s_mainThreadCounter { 0 };
static std::atomic<bool> s_watchcatDisabledUntilScriptExit { false };

static std::unique_ptr<struct WatchThread> s_watchcatThread;

static std::unique_ptr<const WatchcatConfig> g_config;

static_assert(std::is_integral<pthread_t>::value,
    "pthread_t must be integral for this code to work");

[[gnu::noinline]]
static void callstack_signal_handler(int, siginfo_t*, void*)
{
    if (!pthread_equal(pthread_self(), s_mainThreadId))
    {
        s_callstackCallback.store(true);
        return;
    }

    s_mainThreadStackLen = backtrace(s_mainThreadStack, CALLSTACK_SIZE);

    const void* backtrace_addr = (void*)backtrace;
    const void* backtrace_symbols_addr = (void*)backtrace_symbols;

    int frames_to_skip = 1; // this signal handler
    for (int i = 0; i < s_mainThreadStackLen; ++i)
    {
        if (s_mainThreadStack[i] == backtrace_addr ||
            s_mainThreadStack[i] == backtrace_symbols_addr)
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
    std::memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sa.sa_sigaction = callstack_signal_handler;

    if (sigfillset(&sa.sa_mask) != 0)
    {
        LOG_FATAL("sigfillset() failed while registering Watchcat signal handler, errno=%d", errno);
    }

    if (sigaction(CALLSTACK_SIG, &sa, nullptr) != 0)
    {
        LOG_FATAL("sigaction(%d) failed while registering Watchcat signal handler, errno=%d",
            CALLSTACK_SIG, errno);
    }
}

static void DumpStacks(const CallstackMap& callstacks)
{
    std::vector<std::pair<Callstack, size_t>> sortedCallstacks(callstacks.begin(),
        callstacks.end());
    std::sort(sortedCallstacks.begin(), sortedCallstacks.end(),
        [](const auto& a, const auto& b) { return a.second > b.second; });

    const size_t numstacks = std::min<size_t>(WATCHCAT_TOP_N_STACKS, sortedCallstacks.size());
    for (size_t i = 0; i < numstacks; ++i)
    {
        const auto& [callstack, occurs] = sortedCallstacks.at(i);

        std::vector<void*> raw_ptrs;
        raw_ptrs.reserve(callstack.size());
        for (const auto& frame : callstack)
        {
            raw_ptrs.push_back(frame.raw_ptr);
        }

        char** strstack = backtrace_symbols(raw_ptrs.data(), raw_ptrs.size());
        LOG_ERROR("Callstack %d: %d occurrences", i, occurs);
        for (size_t k = 0; k < raw_ptrs.size(); ++k)
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
    LOG_INFO("Watchcat ^.^~ sleeping for %dms before arming", g_config->warmup_msec);
    std::this_thread::sleep_for(milliseconds(g_config->warmup_msec));
    LOG_INFO("Watchcat ^.^~ thread armed");

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

        // Server stall is stuff that the server explicitly marks as taking a while;
        // eg. module loads and saves.
        // That includes NWSync operations in Resources.cpp via LoadModuleStart.
        if (g_pAppManager->m_pReentrantServerStats->m_bStallServer)
        {
            continue;
        }

        if (now - lastObservedAt < milliseconds(g_config->stall_msec))
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

            bool sampler_failed = false;
            const auto callback_deadline = steady_clock::now() + milliseconds(100);
            while (!s_callstackCallback.load(std::memory_order_acquire))
            {
                if (steady_clock::now() >= callback_deadline)
                {
                    sampler_failed = true;
                    break;
                }
                std::this_thread::yield();
            }

            if (sampler_failed)
            {
                LOG_WARNING("Failed to get callstack from main thread, giving up this sample");
                continue;
            }

            Callstack callstack;
            callstack.reserve(s_mainThreadStackLen);

            for (int i = 0; i < s_mainThreadStackLen; ++i)
            {
                void* ptr = s_mainThreadStack[i];
                Dl_info info;
                // Attempt to resolve the function base address, or fall back to raw ptr.
                void* base = (dladdr(ptr, &info) && info.dli_saddr) ? info.dli_saddr : ptr;
                callstack.push_back({ ptr, base });
            }

            callstacks[callstack]++;

            if (steady_clock::now() - lastObservedAt >
                milliseconds(g_config->stall_msec + g_config->kill_msec))
            {
                DumpStacks(callstacks);
                LOG_FATAL("Watchcat ^.^~ ran out of patience.");
            }

            std::this_thread::sleep_for(milliseconds(g_config->stall_sample_rate_msec));
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

static void WatchcatCtor() __attribute__((constructor));
static void WatchcatCtor()
{
    g_config = std::make_unique<WatchcatConfig>();

    // Invoke backtrace at least once to ensure functions are linked in and don't run
    // on the hotpath on first hit.
    backtrace(s_mainThreadStack, 0);

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

            if (g_config->test_mode && s_mainThreadCounter % 100 == 0)
            {
                LOG_INFO("Simulating long stall");
                std::this_thread::sleep_for(std::chrono::seconds(5));
                LOG_INFO("Simulated long stall complete");
            }

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
