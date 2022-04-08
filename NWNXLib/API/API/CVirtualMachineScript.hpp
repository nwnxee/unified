#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include <memory>

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
    CExoString m_sScriptName;
    DataBlockRef m_pCode;
    int32_t m_nScriptEventID;



#ifdef NWN_CLASS_EXTENSION_CVirtualMachineScript
    NWN_CLASS_EXTENSION_CVirtualMachineScript
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineScript)
#endif

