#pragma once

#include "API/CNWSMessage.hpp"

#include <string>
#include <cstring>


namespace NWNXLib::Utils {

template <typename T>
inline T PeekMessage(CNWSMessage *pMessage, int32_t offset)
{
    static_assert(std::is_pod<T>::value);
    T value;
    uint8_t *ptr = pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset;
    std::memcpy(&value, ptr, sizeof(T));
    return value;
}

template <>
inline std::string PeekMessage<std::string>(CNWSMessage *pMessage, int32_t offset)
{
    std::string string;
    auto length = PeekMessage<int32_t>(pMessage, offset);

    string.reserve(length + 1);
    string.assign(reinterpret_cast<const char*>(pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset + 4), length);
    string[length] = '\0';

    return string;
}

template <>
inline CResRef PeekMessage<CResRef>(CNWSMessage *pMessage, int32_t offset)
{
    std::string string;

    string.reserve(16 + 1);
    string.assign(reinterpret_cast<const char*>(pMessage->m_pnReadBuffer + pMessage->m_nReadBufferPtr + offset), 16);
    string[16] = '\0';

    return CResRef(string);
}

}
