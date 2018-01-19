#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoArrayListTemplatedCExoString;
struct CExoArrayListTemplatedCFileInfo;

struct CExoBaseInternal
{
    int32_t m_nResTypes;
    uint16_t* m_pnResTypes;
    CExoString* m_psResTypeNames;

    // The below are auto generated stubs.
    CExoBaseInternal(const CExoBaseInternal&) = default;
    CExoBaseInternal& operator=(const CExoBaseInternal&) = default;

    CExoBaseInternal();
    ~CExoBaseInternal();
    void AddAlias(int32_t, CExoString, CExoString);
    int32_t CheckForCD(uint32_t);
    void CreateResourceExtensionTable();
    int32_t GetAugmentedDirectoryList(CExoArrayListTemplatedCFileInfo*, CExoString, uint16_t, int32_t);
    int32_t GetDirectoryList(CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
    const CExoString& GetResourceExtension(uint16_t);
    uint16_t GetResTypeFromExtension(const CExoString&);
    void LoadAliases(int32_t);
    void ShutDown();
    void SpawnExternalApplication(const CExoString&, const CExoString&, int32_t);
};

void CExoBaseInternal__CExoBaseInternalCtor(CExoBaseInternal* thisPtr);
void CExoBaseInternal__CExoBaseInternalDtor(CExoBaseInternal* thisPtr);
void CExoBaseInternal__AddAlias(CExoBaseInternal* thisPtr, int32_t, CExoString, CExoString);
int32_t CExoBaseInternal__CheckForCD(CExoBaseInternal* thisPtr, uint32_t);
void CExoBaseInternal__CreateResourceExtensionTable(CExoBaseInternal* thisPtr);
int32_t CExoBaseInternal__GetAugmentedDirectoryList(CExoBaseInternal* thisPtr, CExoArrayListTemplatedCFileInfo*, CExoString, uint16_t, int32_t);
int32_t CExoBaseInternal__GetDirectoryList(CExoBaseInternal* thisPtr, CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
const CExoString& CExoBaseInternal__GetResourceExtension(CExoBaseInternal* thisPtr, uint16_t);
uint16_t CExoBaseInternal__GetResTypeFromExtension(CExoBaseInternal* thisPtr, const CExoString&);
void CExoBaseInternal__LoadAliases(CExoBaseInternal* thisPtr, int32_t);
void CExoBaseInternal__ShutDown(CExoBaseInternal* thisPtr);
void CExoBaseInternal__SpawnExternalApplication(CExoBaseInternal* thisPtr, const CExoString&, const CExoString&, int32_t);

}

}
