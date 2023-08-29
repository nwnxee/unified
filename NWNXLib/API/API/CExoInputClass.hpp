#pragma once
#include "nwn_api.hpp"

#include "CExoInputEventDesc.hpp"
#include "CExoLinkedList.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoInputClass)
#endif





class CExoInputClass
{
public:
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

