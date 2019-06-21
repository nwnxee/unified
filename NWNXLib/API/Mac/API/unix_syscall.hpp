#pragma once

#include <cstdint>

#include "unknown_sqlite3_syscall_ptr.hpp"

namespace NWNXLib {

namespace API {

struct unix_syscall
{
    const char* zName;
    sqlite3_syscall_ptr pCurrent;
    sqlite3_syscall_ptr pDefault;
};

}

}
