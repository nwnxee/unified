#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct ScopeGuard
{
    void** m_funcPtrPlaceholder__0;

    // The below are auto generated stubs.
    ScopeGuard() = default;
    ScopeGuard(const ScopeGuard&) = default;
    ScopeGuard& operator=(const ScopeGuard&) = default;

    ~ScopeGuard();
};

void ScopeGuard__ScopeGuardDtor(ScopeGuard* thisPtr);

}

}
