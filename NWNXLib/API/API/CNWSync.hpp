#pragma once
#include "nwn_api.hpp"
#include "SHA1.hpp"
#include <atomic>
#include <thread>


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CNWSync)
#endif


namespace NWSync {

struct CNWSync
{
    void *m_internal;
    std::atomic<bool> m_ready = false;
    std::unique_ptr<std::thread> m_init_thread;

    CNWSync(const CNWSync&) = delete;
    CNWSync(CNWSync&&) = delete;
    CNWSync& operator=(const CNWSync&) = delete;
    CNWSync& operator=(CNWSync&&) = delete;
    explicit CNWSync() noexcept;
    ~CNWSync();

    struct ManifestMetaData {
        Hash::SHA1 m_sha1;
        uint32_t m_hashTreeDepth;
        CExoString m_moduleName;
        CExoString m_description;
        CUUID m_uuid;
        uint32_t m_groupId;
        bool m_includesModuleContents;
        bool m_includesClientContents;
        uint32_t m_totalBytes;
        uint32_t m_totalFiles;
        uint32_t m_createdAt;
    };

#ifdef NWN_CLASS_EXTENSION_CNWSync
    NWN_CLASS_EXTENSION_CNWSync
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CNWSync)
#endif

}
