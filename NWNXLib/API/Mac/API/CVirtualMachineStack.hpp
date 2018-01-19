#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFF;
struct CResStruct;
struct CVirtualMachine;

struct CVirtualMachineStack
{
    int32_t m_nStackPointer;
    int32_t m_nBasePointer;
    int32_t m_nTotalSize;
    char* m_pchStackTypes;
    int32_t* m_pStackNodes;
    CVirtualMachine* m_pVMachine;

    // The below are auto generated stubs.
    CVirtualMachineStack(const CVirtualMachineStack&) = default;
    CVirtualMachineStack& operator=(const CVirtualMachineStack&) = default;

    CVirtualMachineStack();
    ~CVirtualMachineStack();
    void AddToTopOfStack(int32_t);
    void AssignLocationToLocation(int32_t, int32_t);
    void ClearStack();
    void CopyFromStack(CVirtualMachineStack*, int32_t, int32_t);
    int32_t GetBasePointer();
    int32_t GetStackPointer();
    void InitializeStack();
    int32_t LoadStack(CResGFF*, CResStruct*);
    void ModifyIntegerAtLocation(int32_t, int32_t);
    int32_t SaveStack(CResGFF*, CResStruct*);
    void SetBasePointer(int32_t);
    void SetStackPointer(int32_t);
};

void CVirtualMachineStack__CVirtualMachineStackCtor__0(CVirtualMachineStack* thisPtr);
void CVirtualMachineStack__CVirtualMachineStackDtor__0(CVirtualMachineStack* thisPtr);
void CVirtualMachineStack__AddToTopOfStack(CVirtualMachineStack* thisPtr, int32_t);
void CVirtualMachineStack__AssignLocationToLocation(CVirtualMachineStack* thisPtr, int32_t, int32_t);
void CVirtualMachineStack__ClearStack(CVirtualMachineStack* thisPtr);
void CVirtualMachineStack__CopyFromStack(CVirtualMachineStack* thisPtr, CVirtualMachineStack*, int32_t, int32_t);
int32_t CVirtualMachineStack__GetBasePointer(CVirtualMachineStack* thisPtr);
int32_t CVirtualMachineStack__GetStackPointer(CVirtualMachineStack* thisPtr);
void CVirtualMachineStack__InitializeStack(CVirtualMachineStack* thisPtr);
int32_t CVirtualMachineStack__LoadStack(CVirtualMachineStack* thisPtr, CResGFF*, CResStruct*);
void CVirtualMachineStack__ModifyIntegerAtLocation(CVirtualMachineStack* thisPtr, int32_t, int32_t);
int32_t CVirtualMachineStack__SaveStack(CVirtualMachineStack* thisPtr, CResGFF*, CResStruct*);
void CVirtualMachineStack__SetBasePointer(CVirtualMachineStack* thisPtr, int32_t);
void CVirtualMachineStack__SetStackPointer(CVirtualMachineStack* thisPtr, int32_t);

}

}
