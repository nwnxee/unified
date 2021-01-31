#pragma once
#include "nwnx.hpp"

#include <unordered_map>
#include <unordered_set>
#include <mutex>


namespace Diagnostics {

struct Backtrace { void *bt[8]; };

class MemorySanitizer
{
public:
    MemorySanitizer();
    ~MemorySanitizer();

    static void *malloc(size_t size);
    static void free(void *ptr);
    static void *calloc(size_t num, size_t size);
    static void *realloc(void *ptr, size_t size);

    static void FreePending();

    static inline std::unordered_map<void*, Backtrace> active_allocations;
    static inline std::unordered_set<void*> pending_free;

    static inline std::recursive_mutex lock;
    static inline bool enabled = false;

    static inline void *(*real_calloc)(size_t, size_t);
    static inline void *(*real_realloc)(void *, size_t);
    static inline void  (*real_free)(void *);
    static inline void *(*real_malloc)(size_t);

    static void ResolveSymbols();

    static void ReportError(void *ptr);
};

}
