#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoString.hpp"
#include "CFileInfo.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoBaseInternal)
#endif



typedef int BOOL;
typedef uint16_t RESTYPE;


struct CExoBaseInternal
{
    int32_t m_nResTypes;
    RESTYPE * m_pnResTypes;
    CExoString * m_psResTypeNames;
    CExoString m_sInstallDirectory;

    CExoBaseInternal();
    ~CExoBaseInternal();
    void AddAlias(int32_t idxIniFile, CExoString sAlias, CExoString sDefault);
    BOOL GetDirectoryList(CExoArrayList<CExoString> * lstFilename, CExoString sPath, RESTYPE nResType, BOOL bGetDirectories = false, BOOL bSort = true);
    int32_t GetAugmentedDirectoryList(CExoArrayList<CFileInfo> * lstFileInfo, CExoString sAlias, RESTYPE nResType, BOOL bSort = true);
    void CreateResourceExtensionTable();
    const CExoString & GetResourceExtension(RESTYPE nType);
    RESTYPE GetResTypeFromExtension(const CExoString & sExtension);
    void LoadAliases(int32_t idxIniFile);
    void ShutDown();
    BOOL CheckForCD(uint32_t nLanguage);


#ifdef NWN_CLASS_EXTENSION_CExoBaseInternal
    NWN_CLASS_EXTENSION_CExoBaseInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoBaseInternal)
#endif

