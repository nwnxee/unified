#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoAliasList;
struct CExoArrayListTemplatedCExoString;
struct CExoArrayListTemplatedCFileInfo;
struct CExoBaseInternal;
struct CExoDebug;
struct CExoIni;
struct CExoRand;
struct CExoTimers;

struct CExoBase
{
    CExoIni* m_pcExoIni;
    CExoTimers* m_pcExoTimers;
    CExoDebug* m_pcExoDebug;
    CExoAliasList* m_pcExoAliasList;
    CExoRand* m_pcExoRand;
    uint32_t m_nExpansionPacks;
    CExoBaseInternal* m_pcExoBaseInternal;
    CExoString m_sUserDirectory;

    // The below are auto generated stubs.
    CExoBase() = default;
    CExoBase(const CExoBase&) = default;
    CExoBase& operator=(const CExoBase&) = default;

    CExoBase(CExoString);
    ~CExoBase();
    int32_t CheckForCD(uint32_t);
    int32_t GetAugmentedDirectoryList(CExoArrayListTemplatedCFileInfo*, CExoString, uint16_t, int32_t);
    int32_t GetDirectoryAndWorkshopList(CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
    int32_t GetDirectoryList(CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
    const CExoString& GetResourceExtension(uint16_t);
    uint16_t GetResTypeFromExtension(const CExoString&);
    void LoadAliases(int32_t);
    void ShutDown();
    void SpawnExternalApplication(const CExoString&, const CExoString&, int32_t);
};

void CExoBase__CExoBaseCtor__0(CExoBase* thisPtr, CExoString);
void CExoBase__CExoBaseDtor__0(CExoBase* thisPtr);
int32_t CExoBase__CheckForCD(CExoBase* thisPtr, uint32_t);
int32_t CExoBase__GetAugmentedDirectoryList(CExoBase* thisPtr, CExoArrayListTemplatedCFileInfo*, CExoString, uint16_t, int32_t);
int32_t CExoBase__GetDirectoryAndWorkshopList(CExoBase* thisPtr, CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
int32_t CExoBase__GetDirectoryList(CExoBase* thisPtr, CExoArrayListTemplatedCExoString*, CExoString, uint16_t, int32_t, int32_t);
const CExoString& CExoBase__GetResourceExtension(CExoBase* thisPtr, uint16_t);
uint16_t CExoBase__GetResTypeFromExtension(CExoBase* thisPtr, const CExoString&);
void CExoBase__LoadAliases(CExoBase* thisPtr, int32_t);
void CExoBase__ShutDown(CExoBase* thisPtr);
void CExoBase__SpawnExternalApplication(CExoBase* thisPtr, const CExoString&, const CExoString&, int32_t);

}

}
