#pragma once
#include "nwn_api.hpp"

#include "CResNSS.hpp"
#include "CResHelper.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptSourceFile)
#endif

struct CExoString;




struct CScriptSourceFile : CResHelper<CResNSS, 2009>
{

    CScriptSourceFile();
    int32_t LoadScript(const CExoString & sFileName, char * * pScript, uint32_t * nScriptLength);
    void UnloadScript();


#ifdef NWN_CLASS_EXTENSION_CScriptSourceFile
    NWN_CLASS_EXTENSION_CScriptSourceFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptSourceFile)
#endif

