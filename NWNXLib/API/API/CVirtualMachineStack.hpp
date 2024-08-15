#pragma once
#include "nwn_api.hpp"



#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CVirtualMachineStack)
#endif

struct CResGFF;
struct CResStruct;
struct CVirtualMachine;
struct StackElement;


typedef int BOOL;


struct CVirtualMachineStack
{
    int32_t m_nStackPointer;
    int32_t m_nBasePointer;
    int32_t m_nTotalSize;
    StackElement * m_pStackNodes;
    CVirtualMachine * m_pVMachine;

    CVirtualMachineStack();
    ~CVirtualMachineStack();
    void InitializeStack();
    void ModifyIntegerAtLocation(int32_t nSourceLocation, int32_t nDelta);
    void AssignLocationToLocation(int32_t nSourceLocation, int32_t nDestLocation);
    void AddToTopOfStack(int32_t nAuxCode);
    void CopyFromStack(CVirtualMachineStack * pStack, int32_t nStackSizeToSave, int32_t nBaseStackSizeToSave);
    BOOL SaveStack(CResGFF * pRes, CResStruct * pStruct);
    BOOL LoadStack(CResGFF * pRes, CResStruct * pStruct);
    void ClearStack();
    inline int32_t GetStackPointer() { return m_nStackPointer; }
    void SetStackPointer(int32_t nSize);


#ifdef NWN_CLASS_EXTENSION_CVirtualMachineStack
    NWN_CLASS_EXTENSION_CVirtualMachineStack
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CVirtualMachineStack)
#endif

