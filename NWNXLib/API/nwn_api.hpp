#pragma once

#include "Constants.hpp"
#include <stdlib.h>

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

#define NWN_CLASS_EXTENSION_CGameObject \
    using CleanupFunc = std::function<void(void*)>;                                                                         \
    void nwnxSet(const std::string& key, int value, bool persist = false, const char *pn = PLUGIN_NAME);                    \
    void nwnxSet(const std::string& key, float value, bool persist = false, const char *pn = PLUGIN_NAME);                  \
    void nwnxSet(const std::string& key, std::string value, bool persist = false, const char *pn = PLUGIN_NAME);            \
    void nwnxSet(const std::string& key, void *value, std::optional<CleanupFunc> cleanup, const char *pn = PLUGIN_NAME);    \
    template <typename T> std::optional<T> nwnxGet(const std::string& key, const char *pn = PLUGIN_NAME);                   \
    void nwnxRemove(const std::string& key, const char *pn = PLUGIN_NAME);                                                  \
    void nwnxRemoveRegex(const std::string& regex, const char *pn = PLUGIN_NAME);                                           \

