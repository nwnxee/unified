#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "CFileInfo.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoBase)
#endif

struct CExoAliasList;
struct CExoBaseInternal;
struct CExoConfig;
struct CExoDebug;
struct CExoIdentity;
struct CExoIni;
struct CExoRand;
struct CExoTimers;


typedef int BOOL;
typedef uint16_t RESTYPE;


struct CExoBase
{
    CExoConfig * m_pcExoConfig;
    CExoIni * m_pcExoIni;
    CExoTimers * m_pcExoTimers;
    CExoDebug * m_pcExoDebug;
    CExoAliasList * m_pcExoAliasList;
    CExoRand * m_pcExoRand;
    CExoIdentity * m_pcExoIdentity;
    uint32_t m_nExpansionPacks;
    CExoBaseInternal * m_pcExoBaseInternal;
    CExoString m_sUserDirectory;

    CExoBase(CExoString sUserDirectory);
    ~CExoBase();
    BOOL GetDirectoryList(CExoArrayList<CExoString> * lstFilename, CExoString sAlias, RESTYPE nResType, BOOL bGetDirectories = false, BOOL bSort = false);
    BOOL GetDirectoryAndWorkshopList(CExoArrayList<CExoString> * lstFilename, CExoString sAlias, RESTYPE nResType, BOOL bGetDirectories = false, BOOL bSort = false);
    int32_t GetAugmentedDirectoryList(CExoArrayList<CFileInfo> * lstFileInfo, CExoString sAlias, RESTYPE nResType, BOOL bSort = false);
    const CExoString & GetResourceExtension(RESTYPE nType);
    RESTYPE GetResTypeFromExtension(const CExoString & sExtension);
    void LoadAliases(int32_t idxIniFile);
    void ShutDown();
    void SpawnExternalApplication(const CExoString & sAppName, const CExoString & sParams, BOOL bShutDownNWN);
    BOOL CheckForCD(uint32_t nLanguage = 0);


#ifdef NWN_CLASS_EXTENSION_CExoBase
    NWN_CLASS_EXTENSION_CExoBase
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoBase)
#endif

