#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoAliasListInternal__CExoAlias;

struct CExoAliasListInternal
{
    CExoString m_sEmptyAlias;
    CExoAliasListInternal__CExoAlias* m_pHeadAlias;

    // The below are auto generated stubs.
    CExoAliasListInternal(const CExoAliasListInternal&) = default;
    CExoAliasListInternal& operator=(const CExoAliasListInternal&) = default;

    CExoAliasListInternal();
    ~CExoAliasListInternal();
    void Add(CExoString, CExoString);
    void Clear();
    void Delete(CExoString);
    const CExoString& GetAliasPath(const CExoString&, int32_t);
    CExoString ResolveFileName(const CExoString&, uint16_t);
};

void CExoAliasListInternal__CExoAliasListInternalCtor__0(CExoAliasListInternal* thisPtr);
void CExoAliasListInternal__CExoAliasListInternalDtor__0(CExoAliasListInternal* thisPtr);
void CExoAliasListInternal__Add(CExoAliasListInternal* thisPtr, CExoString, CExoString);
void CExoAliasListInternal__Clear(CExoAliasListInternal* thisPtr);
void CExoAliasListInternal__Delete(CExoAliasListInternal* thisPtr, CExoString);
const CExoString& CExoAliasListInternal__GetAliasPath(CExoAliasListInternal* thisPtr, const CExoString&, int32_t);
CExoString CExoAliasListInternal__ResolveFileName(CExoAliasListInternal* thisPtr, const CExoString&, uint16_t);

}

}
