#include "nwn_api.hpp"

const CNetConnectionId CNetConnectionId::INVALID = CNetConnectionId(0xfffffffd);
const CNetConnectionId CNetConnectionId::MASTERSERVER = CNetConnectionId(0xfffffffe);
const CNetConnectionId CNetConnectionId::BROADCAST = CNetConnectionId(0xffffffff);
const CNetConnectionId CNetConnectionId::SINGLEPLAYER = CNetConnectionId(0x00000000);
