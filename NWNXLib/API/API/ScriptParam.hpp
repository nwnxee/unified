#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(ScriptParam)
#endif





struct ScriptParam
{
    CExoString key;
    CExoString value;



#ifdef NWN_CLASS_EXTENSION_ScriptParam
    NWN_CLASS_EXTENSION_ScriptParam
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(ScriptParam)
#endif

