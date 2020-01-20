#include "Encoding.hpp"
#include "Assert.hpp"
#include "Log.hpp"

#include <string>
#include <string.h>
#include <algorithm>

namespace NWNXLib::Encoding {

Locale g_DefaultLocale = Western;

Locale GetDefaultLocale()
{
    return g_DefaultLocale;
}
void SetDefaultLocale(Locale locale)
{
    if (locale == Default)
        locale = Western;

    g_DefaultLocale = locale;
}
void SetDefaultLocale(const std::string& locale)
{
    if (locale.empty())
        return;

    std::string sub = locale.substr(0, 2);
    std::transform(sub.begin(), sub.end(), sub.begin(), ::tolower);

    if (sub == "ru")
        SetDefaultLocale(Russian);
    else
    {
        LOG_WARNING("Unknown locale %s", locale);
        SetDefaultLocale(Default);
    }
}

std::string ToUTF8(const char *str, Locale locale)
{
    if (str == nullptr || *str == 0)
        return std::string("");

    std::string utf8("");
    utf8.reserve(2*strlen(str) + 1);

    if (locale == Default)
        locale = GetDefaultLocale();

    const char *tmp = str;

    for (; *str; ++str)
    {
        if (!(*str & 0x80))
        {
            utf8.push_back(*str);
        }
        else
        {
            int codepoint = static_cast<uint8_t>(*str);
            switch (locale)
            {
                case Western:
                    utf8.push_back(0xc2 | static_cast<char>(codepoint >> 6));
                    utf8.push_back(0xbf & static_cast<char>(codepoint & 0xFF));
                    break;
                case Russian:
                    if (codepoint == 168)
                        codepoint = 177;
                    if (codepoint > 176 && codepoint < 256)
                    {
                        codepoint += 848;
                    }
                    utf8.push_back(0xc0 | static_cast<char>(codepoint >> 6));
                    utf8.push_back((0xbf & static_cast<char>(codepoint & 0xFF)) | 0x80);
                    break;
                default:
                    utf8.push_back('?');
                    ASSERT_FAIL_MSG("Unknown locale");
                    break;
            }
        }
    }
    LOG_DEBUG("ToUTF: \"%s\" -> \"%s\"", tmp, utf8);
    return utf8;
}

// Adapted from https://stackoverflow.com/a/23690194/2771245
std::string FromUTF8(const char *str, Locale locale)
{
    if (str == nullptr || *str == 0)
        return std::string("");

    std::string iso8859("");
    iso8859.reserve(strlen(str) + 1);

    if (locale == Default)
        locale = GetDefaultLocale();

    const char *tmp = str;
    uint32_t codepoint = 0;
    for (; *str; ++str)
    {
        uint8_t ch = static_cast<uint8_t>(*str);
        if (ch <= 0x7f)
            codepoint = ch;
        else if (ch <= 0xbf)
            codepoint = (codepoint << 6) | (ch & 0x3f);
        else if (ch <= 0xdf)
            codepoint = ch & 0x1f;
        else if (ch <= 0xef)
            codepoint = ch & 0x0f;
        else
            codepoint = ch & 0x07;

        if (((str[1] & 0xc0) != 0x80) && (codepoint <= 0x10ffff))
        {
            if (codepoint <= 0xFF)
            {
                iso8859.push_back(static_cast<char>(codepoint));
            }
            else // Special character out of bounds
            {
                switch (locale)
                {
                    case Western:
                        iso8859.push_back('?');
                        break;
                    case Russian:
                        if (codepoint > 1024 && codepoint < 1106)
                        {
                            if (codepoint == 1025)
                                codepoint = 1016;

                            iso8859.push_back(static_cast<char>(codepoint - 848));
                        }
                        else
                        {
                            iso8859.push_back('?');
                        }
                        break;
                    default:
                        iso8859.push_back('?');
                        ASSERT_FAIL_MSG("Unknown locale");
                        break;
                }
            }
        }
    }
    LOG_DEBUG("FromUTF: \"%s\" -> \"%s\"", tmp, iso8859);
    return iso8859;
}


static const char base64_key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
std::string ToBase64(const std::vector<uint8_t>& in)
{
    std::string out;
    out.reserve(4*in.size()/3 + 4);

    int val = 0, valb = -6;
    for (uint8_t c : in)
    {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0)
        {
            out.push_back(base64_key[(val>>valb)&0x3F]);
            valb-=6;
        }
    }

    if (valb > -6)
    {
        out.push_back(base64_key[((val<<8)>>(valb+8))&0x3F]);
    }
    while (out.size()%4)
    {
        out.push_back('=');
    }
    return std::move(out);
}

std::vector<uint8_t> FromBase64(const std::string &in)
{
    std::vector<uint8_t> out;
    out.reserve(3*in.length()/4 + 4);

    static int Table[256];
    if (Table['+'] == 0)
    {
        memset(Table, 0xFF, sizeof(Table));
        for (int i = 0; i < 64; i++)
            Table[(uint8_t)(base64_key[i])] = i;
    }

    int val = 0, valb = -8;
    for (char c : in)
    {
        if (Table[(uint8_t)c] == -1)
            break;
        val = (val<<6) + Table[(uint8_t)c];
        valb += 6;
        if (valb>=0)
        {
            out.push_back(uint8_t((val>>valb)&0xFF));
            valb -= 8;
        }
    }
    return std::move(out);
}

}
