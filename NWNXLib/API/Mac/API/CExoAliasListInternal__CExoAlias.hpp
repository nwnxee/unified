#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CExoAliasListInternal__CExoAlias
{
    CExoString m_Alias;
    CExoString m_Path;
    CExoAliasListInternal__CExoAlias* m_pNext;
    CExoAliasListInternal__CExoAlias* m_pPrev;
};

}

}
