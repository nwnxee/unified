#pragma once

namespace NWNXLib {

namespace API {

namespace Version {

#define NWNX_INTERNAL_EXPAND(s) #s
#define NWNX_INTERNAL_STRINGIFY(s) NWNX_INTERNAL_EXPAND(s)
/*
#define NWNX_EXPECT_VERSION(version)            \
static_assert(NWNX_TARGET_NWN_BUILD == version, \
"This build-specific code targets build "       \
#version                                        \
" but is being compiled against build "         \
NWNX_INTERNAL_STRINGIFY(NWNX_TARGET_NWN_BUILD))
*/
#define NWNX_EXPECT_VERSION(version)            
}

}

}
