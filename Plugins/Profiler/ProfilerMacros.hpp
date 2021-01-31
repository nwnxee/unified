#pragma once

#include "Profiler.hpp"
#include "Timing.hpp"

#include <array>
#include <chrono>

// Used to RAII flip a bool. True on CTor, false on DTor.
struct ProfilingLandingScopeFlip
{
    ProfilingLandingScopeFlip(bool& flip) : m_flip(flip) { m_flip = true; }
    ~ProfilingLandingScopeFlip() { m_flip = false; }
    bool& m_flip;
};

#define DECLARE_PROFILE_TARGET_INTERNAL(profiler, name, fn, ret, ...)           \
static NWNXLib::Hooks::Hook g_##name##Hook = nullptr;                \
template <typename ... Params>                                                  \
static ret ProfileLanding__##name(Params ... args)                             \
{                                                                               \
    static size_t s_head = 0;                                                   \
                                                                                \
    if (s_head >= FastTimer::MAX_DEPTH)                                         \
    {                                                                           \
        /* This should never be possible, but if it is, terminate with a dump.*/\
        std::terminate();                                                       \
    }                                                                           \
                                                                                \
    using namespace NWNXLib::Services;                                          \
    static std::array<FastTimer, FastTimer::MAX_DEPTH> s_scope;                 \
                                                                                \
    SCOPEGUARD(s_scope[--s_head].Stop(profiler, #name, fn(args ...)););         \
    s_scope[s_head++].Start();                                                  \
    return g_##name##Hook->CallOriginal<ret>(args ...);                         \
}

#define DECLARE_PROFILE_TARGET_FAST_INTERNAL(profiler, name, fn, ret, ...)  \
static NWNXLib::Hooks::Hook g_##name##Hook = nullptr;            \
template <typename ... Params>                                              \
static ret ProfileLanding__##name(Params ... args)                          \
{                                                                           \
    FastTimerScope timerScope(profiler, #name, fn(args ...));               \
    return g_##name##Hook->CallOriginal<ret>(args ...);                     \
}

#define DECLARE_PROFILE_TARGET_FAST_NO_RECURSIVE_INTERNAL(profiler, name, fn, ret, ...)  \
static NWNXLib::Hooks::Hook g_##name##Hook = nullptr;                         \
template <typename ... Params>                                                           \
static ret ProfileLanding__##name(Params ... args)                                       \
{                                                                                        \
    static bool s_running = false;                                                       \
                                                                                         \
    if (s_running)                                                                       \
    {                                                                                    \
        return g_##name##Hook->CallOriginal<ret>(args ...);                              \
    }                                                                                    \
                                                                                         \
    ProfilingLandingScopeFlip flip(s_running);                                           \
    FastTimerScope timerScope(profiler, #name, fn(args ...));                            \
    return g_##name##Hook->CallOriginal<ret>(args ...);                                  \
}

// Consumes a shared hook.
#define DECLARE_PROFILE_TARGET(...) \
DECLARE_PROFILE_TARGET_INTERNAL(__VA_ARGS__)

#define DECLARE_PROFILE_TARGET_SIMPLE(profiler, name, ret, ...)                \
DECLARE_PROFILE_TARGET(                                                        \
    profiler,                                                                  \
    name,                                                                      \
    [](__VA_ARGS__) -> auto { return NWNXLib::Services::MetricData::Tags(); }, \
    ret,                                                                       \
    __VA_ARGS__)

// Consumes an exclusive hook.
#define DECLARE_PROFILE_TARGET_FAST(...) \
DECLARE_PROFILE_TARGET_FAST_INTERNAL(__VA_ARGS__)

#define DECLARE_PROFILE_TARGET_FAST_NO_RECURSIVE(...)\
DECLARE_PROFILE_TARGET_FAST_NO_RECURSIVE_INTERNAL(__VA_ARGS__)

#define DECLARE_PROFILE_TARGET_FAST_SIMPLE(profiler, name, ret, ...)           \
DECLARE_PROFILE_TARGET_FAST(                                                   \
    profiler,                                                                  \
    name,                                                                      \
    [](__VA_ARGS__) -> auto { return NWNXLib::Services::MetricData::Tags(); }, \
    ret,                                                                       \
    __VA_ARGS__)


#define DECLARE_PROFILE_TARGET_FAST_SIMPLE_NO_RECURSIVE(profiler, name, ret, ...) \
DECLARE_PROFILE_TARGET_FAST(                                                      \
    profiler,                                                                     \
    name,                                                                         \
    [](__VA_ARGS__) -> auto { return NWNXLib::Services::MetricData::Tags(); },    \
    ret,                                                                          \
    __VA_ARGS__)

#define DEFINE_PROFILER_TARGET(name, address, ret, ...)                                \
{                                                                                              \
    g_##name##Hook = Hooks::HookFunction(address,                                                     \
        (void*)&ProfileLanding__##name<__VA_ARGS__>,                                           \
        NWNXLib::Hooks::Order::Earliest);                                                    \
}

#define DEFINE_PROFILER_TARGET_FAST(name, address, ret, ...)                              \
{                                                                                                 \
    g_##name##Hook = Hooks::HookFunction(address,                                                        \
        (void*)&ProfileLanding__##name<__VA_ARGS__>,                                              \
        NWNXLib::Hooks::Order::Earliest);                                                       \
}
