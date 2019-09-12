#pragma once
#include "nwn_api.hpp"

#include "ResRefBatchInsertEntry.hpp"
#include "CExoString.hpp"
#include "MappingBatchInsertEntry.hpp"
#include "CExoArrayList.hpp"
#include "ManifestInfo.hpp"
#include "AsyncHousekeepingStatus.hpp"
#include "DataBlockRef.hpp"
#include "ManifestMetaData.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSync)
#endif

struct NWSync::StorageProvider;
struct NWSync::CNWSyncInternal;


typedef uint16_t RESTYPE;


struct CNWSync
{
    struct StartupConfig;
    struct RuntimeConfig;
    CNWSyncInternal * m_internal;

    CNWSync();
    ~CNWSync();
    bool IsAvailable();
    bool Configure();
    void Deconfigure();
    bool HasManifest(const CExoString & manifestSha1);
    bool HasResRef(const CExoString & resrefSha1);
    CExoArrayList<CExoString> FilterMissingResRefs(const CExoArrayList<CExoString> & resrefShas);
    CExoArrayList<CNWSync::ManifestEntry> GetManifestContents(const CExoString & manifestSha1);
    const DataBlockRef GetResrefData(const CExoString & resrefSha1);
    const DataBlockRef GetResrefData(const CExoString & manifestSha1, const CExoString & resRef, RESTYPE resType);
    bool MarkManifestUsedBy(const CExoString & manifestSha1, const CExoString & humanReadableDescriptor);
    bool BatchInsertResRefData(const CExoArrayList<ResRefBatchInsertEntry> & entries);
    bool BatchSetMappingData(const CExoString & manifestSha1, const CExoArrayList<MappingBatchInsertEntry> & mappings);
    bool CreateManifest(const CExoString & manifestSha1, const CExoString & originUrl);
    bool DeleteManifest(const CExoString & manifestSha1);
    bool UpdateManifestMetaData(const CExoString & manifestSha1, const ManifestMetaData & data);
    CExoArrayList<CNWSync::ManifestInfo> GetAllManifests(bool withoutModuleData, bool withModuleData);
    ManifestInfo GetManifest(const CExoString & manifestSha1);
    ManifestMetaData GetManifestMetaData(const CExoString & manifestSha1);
    const DataBlockRef GetCachedManifest(const CExoString & manifestSha1);
    bool SetCachedManifest(const CExoString & manifestSha1, const DataBlockRef inData);
    AsyncHousekeepingStatus AsyncHousekeeping(bool startNewIfNotRunning);
    const CExoArrayList<NWSync::StorageProvider *> & GetStorageProviders();


#ifdef NWN_CLASS_EXTENSION_CNWSync
    NWN_CLASS_EXTENSION_CNWSync
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSync)
#endif

