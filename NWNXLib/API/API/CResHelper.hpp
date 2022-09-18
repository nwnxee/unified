#pragma once
#include "nwn_api.hpp"

#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResHelper)
#endif



typedef int BOOL;


template<class T,RESTYPE nType> struct CResHelper
{
    BOOL m_bAutoRequest;
    T * m_pRes;
    CResRef m_cResRef;

    CResHelper();
    CResHelper(const CResRef & cNewResRef, BOOL bSetAutoRequest = true);
    virtual ~CResHelper();
    int32_t CancelRequest();
    int32_t Request();
    void SetResRef(const CResRef & cNewResRef, BOOL bSetAutoRequest = true);
    bool ClearResHelper();


#ifdef NWN_CLASS_EXTENSION_CResHelper
    NWN_CLASS_EXTENSION_CResHelper
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResHelper)
#endif

