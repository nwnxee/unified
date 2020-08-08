#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CScriptLocation.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSScriptVar)
#endif



typedef uint32_t OBJECT_ID;


struct CNWSScriptVar
{
    int32_t m_int;
    float m_float;
    OBJECT_ID m_objectId;
    CExoString m_string;
    CScriptLocation m_location;

    CNWSScriptVar();
    CNWSScriptVar(const CNWSScriptVar &);
    CNWSScriptVar & operator=(const CNWSScriptVar &);
    void Reset(uint32_t nVarType);


#ifdef NWN_CLASS_EXTENSION_CNWSScriptVar
    NWN_CLASS_EXTENSION_CNWSScriptVar
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSScriptVar)
#endif

