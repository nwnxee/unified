#pragma once

namespace NWNXLib {

namespace API {

namespace Version {

#define NWNX_INTERNAL_EXPAND(s) #s
#define NWNX_INTERNAL_STRINGIFY(s) NWNX_INTERNAL_EXPAND(s)

#define NWNX_EXPECT_VERSION(version, revision)            \
static_assert(NWNX_TARGET_NWN_BUILD == version && NWNX_TARGET_NWN_BUILD_REVISION == revision, \
"This build-specific code targets build "       \
#version " revision " #revision                 \
" but is being compiled against build "         \
NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD)  \
" revision " NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD_REVISION))

}

}

}
