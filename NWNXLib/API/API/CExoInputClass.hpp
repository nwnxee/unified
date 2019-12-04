#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CExoLinkedList.hpp"
#include "CExoInputEventDesc.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoInputClass)
#endif





struct CExoInputClass
{
    CExoString m_Label;
    CExoLinkedList<CExoInputEventDesc> * m_pUnassignedInputEventDescList;
    CExoLinkedList<CExoInputEventDesc> * m_pInputEventDescList;



#ifdef NWN_CLASS_EXTENSION_CExoInputClass
    NWN_CLASS_EXTENSION_CExoInputClass
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoInputClass)
#endif

