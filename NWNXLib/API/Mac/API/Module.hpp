#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct Table;
struct sqlite3_module;

struct Module
{
    const sqlite3_module* pModule;
    const char* zName;
    void* pAux;
    void** m_funcPtrPlaceholder__0;
    Table* pEpoTab;
};

}

}
