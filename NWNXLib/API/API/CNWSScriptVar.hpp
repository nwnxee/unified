#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSScriptVar)
#endif





struct CNWSScriptVar
{
    CExoString m_sName;
    uint32_t m_nType;
    union {
    int32_t m_int;
    float m_float;
    OBJECT_ID m_objectId;
    struct CExoString* m_string;
    struct CScriptLocation* m_location;
} m_uValue;



#ifdef NWN_CLASS_EXTENSION_CNWSScriptVar
    NWN_CLASS_EXTENSION_CNWSScriptVar
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSScriptVar)
#endif

