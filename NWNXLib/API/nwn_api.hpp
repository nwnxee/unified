#pragma once

#include "Constants.hpp"
#include <stdlib.h>
#include <string>

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

struct DataBlock { char* m_data; size_t m_used; size_t m_allocated; bool m_owning;};
#define DataBlockRef std::shared_ptr<DataBlock>

struct CUUID { uint64_t ab = 0, cd = 0; };
struct json { uint8_t m_type = 0; void* m_value = nullptr; };

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

