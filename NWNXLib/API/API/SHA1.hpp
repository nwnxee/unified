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

    SHA1(const SHA1& other)
    {
        *this = other;
    }

    SHA1()
    {
        Clear();
    }

    explicit SHA1(const uint8_t ptr[20]); // SHA1_DIGEST_SIZE
    explicit SHA1(const CExoString& hex);

    SHA1 operator=(Hash::SHA1 const& other);

    void Clear();

#ifdef NWN_CLASS_EXTENSION_SHA1
    NWN_CLASS_EXTENSION_SHA1
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SHA1)
#endif

}
