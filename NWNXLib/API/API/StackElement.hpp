#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(StackElement)
#endif



typedef uint32_t OBJECT_ID;


class StackElement
{
public:
    OBJECT_ID m_nStackObjectID;
    int32_t m_nStackInt;
    float m_fStackFloat;
    void * m_pStackPtr;



#ifdef NWN_CLASS_EXTENSION_StackElement
    NWN_CLASS_EXTENSION_StackElement
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(StackElement)
#endif

