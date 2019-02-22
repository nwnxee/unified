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
        LOG_WARNING("Unknown locale %s", locale.c_str());
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
    LOG_DEBUG("ToUTF: \"%s\" -> \"%s\"", tmp, utf8.c_str());
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
    LOG_DEBUG("FromUTF: \"%s\" -> \"%s\"", tmp, iso8859.c_str());
    return iso8859;
}


}
