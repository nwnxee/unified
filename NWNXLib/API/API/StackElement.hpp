#pragma once
#include "nwn_api.hpp"
#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(StackElement)
#endif



typedef uint32_t OBJECT_ID;


struct StackElement
{
    union
    {
        OBJECT_ID   m_nStackObjectID;
        int32_t     m_nStackInt;
        float       m_fStackFloat;
        CExoString  m_sString;
        void*       m_pStackPtr;
    };

    enum Type
    {
        INVALID = 0x00,
        INTEGER = 0x03,
        FLOAT   = 0x04,
        STRING  = 0x05,
        OBJECT  = 0x06,
        ENGST0  = 0x10,
        ENGST1  = 0x11,
        ENGST2  = 0x12,
        ENGST3  = 0x13,
        ENGST4  = 0x14,
        ENGST5  = 0x15,
        ENGST6  = 0x16,
        ENGST7  = 0x17,
        ENGST8  = 0x18,
        ENGST9  = 0x19,
    };

    uint8_t m_nType;

    StackElement() { std::memset(this, 0, sizeof(*this)); }
    ~StackElement() { if (m_nType == Type::STRING) m_sString.Clear(); }



#ifdef NWN_CLASS_EXTENSION_StackElement
    NWN_CLASS_EXTENSION_StackElement
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(StackElement)
#endif

