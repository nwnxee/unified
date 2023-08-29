#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CScriptCompilerIdentifierHashTableEntry)
#endif





class CScriptCompilerIdentifierHashTableEntry
{
public:
    uint32_t m_nHashValue;
    uint32_t m_nIdentifierType;
    uint32_t m_nIdentifierIndex;



#ifdef NWN_CLASS_EXTENSION_CScriptCompilerIdentifierHashTableEntry
    NWN_CLASS_EXTENSION_CScriptCompilerIdentifierHashTableEntry
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CScriptCompilerIdentifierHashTableEntry)
#endif

