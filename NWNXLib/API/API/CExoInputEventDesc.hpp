#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoInputEventDesc)
#endif





class CExoInputEventDesc
{
    CExoString m_Label;
    uint32_t m_nID;
    int32_t m_nInputDeviceType;
    int32_t m_nInputDevice;
    uint32_t m_nInputDeviceElement;
    uint32_t m_nInputMode;



#ifdef NWN_CLASS_EXTENSION_CExoInputEventDesc
    NWN_CLASS_EXTENSION_CExoInputEventDesc
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoInputEventDesc)
#endif

