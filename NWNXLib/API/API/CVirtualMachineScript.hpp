#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineScript)
#endif

struct CVirtualMachineStack;




struct CVirtualMachineScript
{
    CVirtualMachineStack * m_pStack;
    int32_t m_nStackSize;
    int32_t m_nInstructPtr;
    int32_t m_nSecondaryInstructPtr;
    char * m_pCode;
    int32_t m_nCodeSize;
    CExoString m_sScriptName;
    int32_t m_nLoadedFromSave;



#ifdef NWN_CLASS_EXTENSION_CVirtualMachineScript
    NWN_CLASS_EXTENSION_CVirtualMachineScript
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineScript)
#endif

