#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineDebuggingContext)
#endif

struct CVirtualMachineDebuggerInstance;


typedef int BOOL;


struct CVirtualMachineDebuggingContext
{
    BOOL m_bStepInto;
    BOOL m_bStepOver;
    BOOL m_bRunToLineNumber;
    int32_t m_nLineNumberToRunTo;
    CVirtualMachineDebuggerInstance * m_pDebuggerInstance;



#ifdef NWN_CLASS_EXTENSION_CVirtualMachineDebuggingContext
    NWN_CLASS_EXTENSION_CVirtualMachineDebuggingContext
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineDebuggingContext)
#endif

