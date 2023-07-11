#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoAliasList)
#endif

class CExoAliasListInternal;


typedef uint16_t RESTYPE;


class CExoAliasList
{
    CExoAliasListInternal * m_pcExoAliasListInternal;

    CExoAliasList();
    ~CExoAliasList();
    void Add(CExoString alias, CExoString path);
    void Clear();
    void Delete(CExoString alias);
    const CExoString & GetAliasPath(const CExoString & alias, int32_t nSize = 0) const;
    CExoString ResolveFileName(const CExoString & sFileName, RESTYPE nType) const;


#ifdef NWN_CLASS_EXTENSION_CExoAliasList
    NWN_CLASS_EXTENSION_CExoAliasList
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoAliasList)
#endif

