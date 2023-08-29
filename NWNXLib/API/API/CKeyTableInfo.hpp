#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "KEYFILE_HEADER.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CKeyTableInfo)
#endif

class CExoFile;
class KEYFILE_RESFILENAME;




class CKeyTableInfo
{
public:
    CExoString m_sName;
    CExoFile * m_pFile;
    KEYFILE_HEADER m_header;
    KEYFILE_RESFILENAME * m_pResFileNames;



#ifdef NWN_CLASS_EXTENSION_CKeyTableInfo
    NWN_CLASS_EXTENSION_CKeyTableInfo
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CKeyTableInfo)
#endif

