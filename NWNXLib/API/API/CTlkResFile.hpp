#pragma once
#include "nwn_api.hpp"

#include "CResHelper.hpp"
#include "CResTLK.hpp"
#include "CTlkFile.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CTlkResFile)
#endif

class CResRef;




class CTlkResFile : public CResHelper<CResTLK, 2018>, public CTlkFile
{
public:
    CTlkResFile(const CResRef & pResRef);
    virtual ~CTlkResFile();


#ifdef NWN_CLASS_EXTENSION_CTlkResFile
    NWN_CLASS_EXTENSION_CTlkResFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CTlkResFile)
#endif

