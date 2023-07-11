#pragma once
#include "nwn_api.hpp"

#include "Vector.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CStoreCustomer)
#endif



typedef uint32_t OBJECT_ID;


class CStoreCustomer
{
    OBJECT_ID m_oidObject;
    uint8_t m_nPage;
    uint8_t m_nPanel;
    Vector m_vOpenPosition;
    char m_nBonusMarkUp;
    char m_nBonusMarkDown;

    CStoreCustomer();


#ifdef NWN_CLASS_EXTENSION_CStoreCustomer
    NWN_CLASS_EXTENSION_CStoreCustomer
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CStoreCustomer)
#endif

