#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoAliasListInternal;

struct CExoAliasList
{
    CExoAliasListInternal* m_pcExoAliasListInternal;

    // The below are auto generated stubs.
    CExoAliasList(const CExoAliasList&) = default;
    CExoAliasList& operator=(const CExoAliasList&) = default;

    CExoAliasList();
    ~CExoAliasList();
    void Add(CExoString, CExoString);
    void Clear();
    void Delete(CExoString);
    const CExoString& GetAliasPath(const CExoString&, int32_t);
    CExoString ResolveFileName(const CExoString&, uint16_t);
};

void CExoAliasList__CExoAliasListCtor__0(CExoAliasList* thisPtr);
void CExoAliasList__CExoAliasListDtor__0(CExoAliasList* thisPtr);
void CExoAliasList__Add(CExoAliasList* thisPtr, CExoString, CExoString);
void CExoAliasList__Clear(CExoAliasList* thisPtr);
void CExoAliasList__Delete(CExoAliasList* thisPtr, CExoString);
const CExoString& CExoAliasList__GetAliasPath(CExoAliasList* thisPtr, const CExoString&, int32_t);
CExoString CExoAliasList__ResolveFileName(CExoAliasList* thisPtr, const CExoString&, uint16_t);

}

}
