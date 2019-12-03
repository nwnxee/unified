#pragma once
#include "nwn_api.hpp"

#include "DestroyHelper.hpp"
#include "Database.hpp"
#include "using.hpp"
#include "Identifier.hpp"
#include <memory>
#include "Serial.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(StorageShard)
#endif

struct Definition;
struct CExoString;




struct StorageShard
{
    using Identifier;
    using Serial;
    bool m_force_destroy;
    std::unique_ptr<NWSQLite::Database> m_db;
    DestroyHelper m_destroy_helper;
    Serial m_serial;

    void PlatformCommit();
    virtual uint64_t GetMaxPlatformTransactionSize();
    virtual uint64_t GetBytesFittable();
    virtual uint64_t GetBytesAllocated();
    virtual bool IsAutoCompactable();
    void SetAutoCompactable(bool v);
    explicit StorageShard(Identifier id, const Definition & migrations);
    virtual ~StorageShard();
    bool ShouldDestroy();
    virtual void PlatformCommitImpl();
    T GetMeta(const CExoString & key, T otherwise);
    void SetMeta(const CExoString & key, T value);


#ifdef NWN_CLASS_EXTENSION_StorageShard
    NWN_CLASS_EXTENSION_StorageShard
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(StorageShard)
#endif

