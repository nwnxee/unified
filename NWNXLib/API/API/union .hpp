#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(union )
#endif

struct CExoString;
struct CScriptLocation;


typedef uint32_t OBJECT_ID;


struct union 
{
    int32_t m_int;
    float m_float;
    OBJECT_ID m_objectId;
    CExoString * m_string;
    CScriptLocation * m_location;



#ifdef NWN_CLASS_EXTENSION_union 
    NWN_CLASS_EXTENSION_union 
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(union )
#endif

