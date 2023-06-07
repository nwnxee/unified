#pragma once
#include "nwn_api.hpp"

namespace Hash {

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SHA1)
#endif


struct SHA1 {
    bool m_empty;
    uint8_t m_data[20];
    char m_hex[41];

    SHA1(const CExoString& param_1);
    SHA1(const unsigned char* param_1);

    void Clear();

    SHA1 * operator=(SHA1 *param_1);

#ifdef NWN_CLASS_EXTENSION_SHA1
    NWN_CLASS_EXTENSION_SHA1
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SHA1)
#endif

}
