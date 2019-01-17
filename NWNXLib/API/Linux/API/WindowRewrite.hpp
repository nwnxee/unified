#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExprList;
struct Select;
struct SrcList;
struct Window_0;

struct WindowRewrite
{
    Window_0* pWin;
    SrcList* pSrc;
    ExprList* pSub;
    Select* pSubSelect;
};

}

}
