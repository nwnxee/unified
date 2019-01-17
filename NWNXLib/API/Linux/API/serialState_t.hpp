#pragma once

#include <cstdint>

#include "XXH64_state_s.hpp"
#include "ZSTD_CCtx_params_s.hpp"
#include "ZSTD_window_t.hpp"
#include "ldmState_t.hpp"
#include "pthread_cond_t.hpp"
#include "unknown_pthread_mutex_t_0.hpp"

namespace NWNXLib {

namespace API {

struct serialState_t
{
    pthread_mutex_t_0 mutex;
    pthread_cond_t cond;
    ZSTD_CCtx_params_s params;
    ldmState_t ldmState;
    XXH64_state_s xxhState;
    uint32_t nextJobID;
    pthread_mutex_t_0 ldmWindowMutex;
    pthread_cond_t ldmWindowCond;
    ZSTD_window_t ldmWindow;
};

}

}
