#pragma once

#include "Constants.hpp"

#define NWN_API_PROLOGUE(...) namespace NWNXLib::API {
#define NWN_API_EPILOGUE(...) }

namespace NWNXLib::API {
struct CExoLinkedListNode;
typedef uint16_t RESTYPE;
namespace NWSync { struct CNWSync { void *m_pInternal; }; }
}
