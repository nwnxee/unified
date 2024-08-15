#pragma once
#include "nwn_api.hpp"

#define SHA1_DIGEST_SIZE 20

extern "C"
{
    int hydro_hex2bin(uint8_t *bin, size_t bin_maxlen, const char *hex, size_t hex_len, const char *ignore, const char **hex_end_p);
    char *hydro_bin2hex(char *hex, size_t hex_maxlen, const uint8_t *bin, size_t bin_len);
    void sha1(unsigned char hval[], const unsigned char data[], unsigned long len);
};

namespace Hash {

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(SHA1)
#endif

struct SHA1
{
    bool m_empty;
    uint8_t m_data[SHA1_DIGEST_SIZE];
    char m_hex[SHA1_DIGEST_SIZE * 2 + 1];

    void Clear()
    {
        m_empty = true;
        memset(m_data, 0, BinaryLength());
        hydro_bin2hex(m_hex, BinaryLength() * 2 + 1, m_data, BinaryLength());
    }

    void _swap(SHA1&& other)
    {
        std::swap(other.m_empty, m_empty);
        std::swap(other.m_data, m_data);
        std::swap(other.m_hex, m_hex);
    }

    SHA1& operator=(const SHA1& other)
    {
        m_empty = other.m_empty;
        memcpy(m_data, other.m_data, sizeof(m_data));
        memcpy(m_hex, other.m_hex, sizeof(m_hex));
        return *this;
    }

    SHA1(const SHA1& other)
    {
        *this = other;
    }

    SHA1& operator=(SHA1&& other)
    {
        _swap(std::move(other));
        return *this;
    }

    SHA1(SHA1&& other)
    {
        _swap(std::move(other));
    }

    // Returns a hexadecimal null-terminated representation of this SHA1.
    // It is always lowercase.
    // If the SHA1 is empty, this will be a empty string (NOT all zeroes).
    const char* Hex() const
    {
        if (m_empty)
        {
            //LOG_DEBUG("Getting hex of empty hash. Make sure this is "
            //          "intended behaviour and you didn't miss a IsEmpty check");
            return "";
        }

        return m_hex;
    }

    // Returns a binary representation of this SHA1.
    // If the hash is empty, this will be all zero bytes.
    // Guaranteed to be of size binaryLength().
    const uint8_t* Data() const
    {
        if (m_empty)
        {
            //LOG_DEBUG("Getting binary of empty hash. Make sure this is "
            //          "intended behaviour and you didn't miss a IsEmpty check");
        }

        return m_data;
    }

    bool IsEmpty() const { return m_empty; }
    // Returns the binary length of this checksum.
    size_t BinaryLength() const { return SHA1_DIGEST_SIZE; }
    // Returns the hex length of this checksum, EXCLUDING null terminator.
    // Use this for clearness, not BinaryLength()*2.
    size_t HexLength() const { return SHA1_DIGEST_SIZE * 2; }

    // Creates a empty SHA1.
    SHA1()
    {
        Clear();
    }

    // Create a SHA1 based on a binary pointer (such as read from disk, network, or from the sha1 lib).
    explicit SHA1(const uint8_t ptr[SHA1_DIGEST_SIZE])
    {
        Clear();

        for (size_t i = 0; i < SHA1_DIGEST_SIZE; i++)
        {
            if (ptr[i] != 0)
            {
                m_empty = false;
            }
        }

        // Empty is OK.
        if (m_empty)
        {
            return;
        }

        m_empty = false;
        memcpy(m_data, ptr, BinaryLength());
        hydro_bin2hex(m_hex, BinaryLength() * 2 + 1, ptr, BinaryLength());
    }

    // Create a SHA1 instance from a existing hex string.
    explicit SHA1(const CExoString& hex)
    {
        Clear();

        // Empty is OK.
        if (hex.GetLength() == 0 || (strspn(hex.CStr(), "0") == BinaryLength() * 2))
        {
            return;
        }

        if (strspn(hex.CStr(), "0123456789abcdefABCDEF") != BinaryLength() * 2)
        {
            //ASSERT(!"Invalid hex passed in. Dropping.");
            return;
        }

        m_empty = false;
        hydro_hex2bin(m_data, BinaryLength(), hex.CStr(), BinaryLength() * 2, nullptr, nullptr);
        hydro_bin2hex(m_hex, BinaryLength() * 2 + 1, m_data, BinaryLength());
    }

    // Hash a SHA from the given binary data.
    static SHA1 Hash(const uint8_t* data, size_t len)
    {
        uint8_t hv[SHA1_DIGEST_SIZE];
        sha1(hv, data, len);
        return SHA1(hv);
    }

    bool operator==(const SHA1& other) const
    {
        return other.m_empty == m_empty && !memcmp(other.m_data, m_data, BinaryLength());
    }

    bool operator!=(const SHA1& other) const
    {
        return !operator==(other);
    }

    bool operator<(const SHA1& other) const
    {
        //ASSERT(!m_empty && !other.m_empty);
        return strcmp(m_hex, other.m_hex) < 0;
    }

#ifdef NWN_CLASS_EXTENSION_SHA1
    NWN_CLASS_EXTENSION_SHA1
#endif
};

#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(SHA1)
#endif

}
