#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoInputEvent)
#endif

class CExoInputEventDesc;




class CExoInputEvent
{
public:
    uint32_t m_nValue;
    uint32_t m_nTimeStamp;
    uint32_t m_nSequenceNumber;
    uint32_t m_nMouseX;
    uint32_t m_nMouseY;
    CExoInputEventDesc * m_pInputEventDesc;
    int32_t m_nInputDevice;
    uint32_t m_nInputDeviceElement;



#ifdef NWN_CLASS_EXTENSION_CExoInputEvent
    NWN_CLASS_EXTENSION_CExoInputEvent
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoInputEvent)
#endif

