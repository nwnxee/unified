#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResTLK)
#endif





class CResTLK : public CRes
{
public:
    CResTLK();
    virtual ~CResTLK();


#ifdef NWN_CLASS_EXTENSION_CResTLK
    NWN_CLASS_EXTENSION_CResTLK
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResTLK)
#endif

