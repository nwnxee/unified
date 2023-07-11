#pragma once
#include "nwn_api.hpp"

#include "CResHelper.hpp"
#include "CResNSS.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptSourceFile)
#endif

class CExoString;




class CScriptSourceFile : CResHelper<CResNSS, 2009>
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

