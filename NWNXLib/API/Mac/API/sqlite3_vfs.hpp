#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct sqlite3_vfs
{
    int32_t iVersion;
    int32_t szOsFile;
    int32_t mxPathname;
    sqlite3_vfs* pNext;
    const char* zName;
    void* pAppData;
    void** m_funcPtrPlaceholder__0;
    void** m_funcPtrPlaceholder__1;
    void** m_funcPtrPlaceholder__2;
    void** m_funcPtrPlaceholder__3;
    void** m_funcPtrPlaceholder__4;
    void** m_funcPtrPlaceholder__5;
    void** m_funcPtrPlaceholder__6;
    void** m_funcPtrPlaceholder__7;
    void** m_funcPtrPlaceholder__8;
    void** m_funcPtrPlaceholder__9;
    void** m_funcPtrPlaceholder__10;
    void** m_funcPtrPlaceholder__11;
    void** m_funcPtrPlaceholder__12;
    void** m_funcPtrPlaceholder__13;
    void** m_funcPtrPlaceholder__14;
    void** m_funcPtrPlaceholder__15;
};

}

}
