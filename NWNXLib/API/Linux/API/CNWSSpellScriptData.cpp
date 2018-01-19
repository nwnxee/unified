#include "CNWSSpellScriptData.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

int32_t CNWSSpellScriptData::LoadData(CResGFF* a0, CResStruct* a1)
{
    return CNWSSpellScriptData__LoadData(this, a0, a1);
}

int32_t CNWSSpellScriptData::SaveData(CResGFF* a0, CResStruct* a1)
{
    return CNWSSpellScriptData__SaveData(this, a0, a1);
}

int32_t CNWSSpellScriptData__LoadData(CNWSSpellScriptData* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSSpellScriptData*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSpellScriptData__LoadData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSSpellScriptData__SaveData(CNWSSpellScriptData* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSSpellScriptData*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSSpellScriptData__SaveData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
