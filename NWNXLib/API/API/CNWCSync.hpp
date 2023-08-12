#pragma once

#include "nwn_api.hpp"
#include "CExoString.hpp"
#include "SHA1.hpp"
#include "CNWSync.hpp"
#include "InstanceLookupList.hpp"

namespace NWSync {

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWCSync)
#endif

struct CNWCSyncInternal;

struct CNWCSync : InstanceLookup::List<CNWCSync> {
    struct Progress {
        int m_currentState;
        CExoString m_currentStateMessage;
        int m_currentStatePercentage;
        size_t m_currentFile;
        size_t m_totalFiles;
        CExoString m_currentTransferMessage;
        size_t m_averageNetworkBps;
        size_t m_averageDiskBps;
        uint64_t m_allFilesBytesTransferred;
        uint64_t m_allFilesBytesTotal;
        uint64_t m_manifestFilesBytesTotal;
        size_t m_manifestFiles;
        uint64_t m_manifestFilesBytesSkip;
        size_t m_manifestFilesSkip;
        size_t m_manifestParseProgress;
        bool m_manifestMetadataReceived;
        CNWSync::ManifestMetaData m_manifestMetaData;
    };

    CNWCSyncInternal* m_internal;
    CNWCSync(const CExoString& manifestUrl, const Hash::SHA1& manifestHash, const CExoString& serverAddress, const CExoString& serverKxpk);
    ~CNWCSync();
    bool Update();
    const Progress& GetStatus() const;
    void SetSyncPermission(bool allow);
    void Cancel(const CExoString& errMsg);

#ifdef NWN_CLASS_EXTENSION_CNWSync
    NWN_CLASS_EXTENSION_CNWSync
#endif
};

#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWCSync)
#endif

}
