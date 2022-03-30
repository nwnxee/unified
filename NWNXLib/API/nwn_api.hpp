#pragma once

#include "Constants.hpp"
#include <stdlib.h>
#include <string>
#include <memory>
#include <vector>

#include "External/json/json.hpp"

#define NWNX_INTERNAL_EXPAND(s) #s
#define NWNX_INTERNAL_STRINGIFY(s) NWNX_INTERNAL_EXPAND(s)

#define NWNX_EXPECT_VERSION(version, revision)            \
static_assert(NWNX_TARGET_NWN_BUILD == version && NWNX_TARGET_NWN_BUILD_REVISION == revision, \
"This build-specific code targets build "       \
#version " revision " #revision                 \
" but is being compiled against build "         \
NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD)  \
" revision " NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD_REVISION))

#define NWN_API_PROLOGUE(...)
#define NWN_API_EPILOGUE(...)

struct CExoLinkedListNode;
typedef uint16_t RESTYPE;
typedef uint32_t ObjectID;
typedef uint32_t PlayerID;
namespace NWSync { struct CNWSync { void *m_pInternal; char *m_tmp1; uint32_t m_tmp2; }; }

struct DataView;
using DataViewRef = std::shared_ptr<DataView>;
struct DataBlock;
using DataBlockRef = std::shared_ptr<DataBlock>;

struct DataView
{
    struct Shared
    {
        Shared(const void* data, size_t used, size_t allocated, bool owned) : m_data(const_cast<void*>(data)), m_used(used), m_allocated(allocated), m_owned(owned) {}
        ~Shared()
        {
            if (m_owned)
                free(m_data);
        }

        void* m_data;
        size_t m_used;
        size_t m_allocated;
        bool m_owned;
    };
    using SharedRef = std::shared_ptr<Shared>;

    SharedRef m_shared;
    SharedRef m_parent;

    explicit DataView(const void* data, size_t length) : m_shared(std::make_shared<Shared>(data, length, 0, false)) {}
    const void* Data() const { return m_shared->m_data; };
    size_t Used() const { return m_shared->m_used; }
    size_t Allocated() const { return m_shared->m_allocated; }
    DataViewRef View(size_t offset, size_t count) const;
    DataBlockRef MakeCopy() const;
    bool empty() const { return m_shared->m_used == 0; };
};

struct DataBlock : DataView
{
    explicit DataBlock(size_t preallocate = 0) : DataView(nullptr, 0)
    {
        m_shared->m_owned = true;
        if (preallocate > 0)
            AllocateAtLeast(preallocate);
    }
    explicit DataBlock(const void *data, size_t length) : DataView(nullptr, 0)
    {
        Append(data, length);
        m_shared->m_owned = true;
    }

    explicit DataBlock(const std::vector<uint8_t>& data) : DataView(nullptr, 0)
    {
        Append(data.data(), data.size());
        m_shared->m_owned = true;
    }
    explicit DataBlock(const std::string& data) : DataView(nullptr, 0)
    {
        Append(data.data(), data.size());
        m_shared->m_owned = true;
    }

    void* Data() { return m_shared->m_data; }
    void AllocateAtLeast(size_t length);
    void MarkUsed(size_t length);
    void Prepend(const void* payload, size_t length, size_t chunkSize = 0);
    void Append(const void* payload, size_t length, size_t chunkSize = 0);
    void Compact();
};

struct CUUID { uint64_t ab = 0, cd = 0; };
using json = nlohmann::json;

namespace Nui::JSON {
    using WindowToken = int32_t; // nwscript compat type
    using WindowIdentifier = std::string;
    using ElementId = std::string;
    using EventType = std::string;
    using EventPayload = json;
    using BindName = std::string;
    using BindValue = json;
    struct BindUpdate
    {
        ObjectID m_player = NWNXLib::API::Constants::OBJECT_INVALID;
        WindowToken m_token = 0;
        BindName m_bind;
        BindValue m_value;
        bool IsValid() const { return m_token > 0; }
    };
    //using BindUpdateQueue = std::queue<BindUpdate>;
    struct Event
    {
        ObjectID m_player = NWNXLib::API::Constants::OBJECT_INVALID;
        WindowToken m_token = 0;
        EventType m_event;
        ElementId m_element;
        int32_t m_array_index = -1;
        EventPayload m_payload;
        bool IsValid() const { return m_token > 0; }
    };
    //using EventQueue = std::queue<Event>;
}

namespace NWSQLite {
    using Database = void*;
}

#define NWN_CLASS_EXTENSION_CGameObject \
    using CleanupFunc = std::function<void(void*)>;                                                                         \
    void nwnxSet(const std::string& key, int value, bool persist = false, const char *pn = PLUGIN_NAME);                    \
    void nwnxSet(const std::string& key, float value, bool persist = false, const char *pn = PLUGIN_NAME);                  \
    void nwnxSet(const std::string& key, std::string value, bool persist = false, const char *pn = PLUGIN_NAME);            \
    void nwnxSet(const std::string& key, void *value, std::optional<CleanupFunc> cleanup, const char *pn = PLUGIN_NAME);    \
    template <typename T> std::optional<T> nwnxGet(const std::string& key, const char *pn = PLUGIN_NAME);                   \
    void nwnxRemove(const std::string& key, const char *pn = PLUGIN_NAME);                                                  \
    void nwnxRemoveRegex(const std::string& regex, const char *pn = PLUGIN_NAME);                                           \

