#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerSymbolTableEntry)
#endif





class CScriptCompilerSymbolTableEntry
{
    uint32_t m_nSymbolType;
    uint32_t m_nSymbolSubType1;
    uint32_t m_nSymbolSubType2;
    int32_t m_nLocationPointer;
    int32_t m_nNextEntryPointer;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerSymbolTableEntry
    NWN_CLASS_EXTENSION_CScriptCompilerSymbolTableEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerSymbolTableEntry)
#endif

