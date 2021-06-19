#include "nwnx.hpp"

#include <string>
#include <string.h>
#include <algorithm>

namespace NWNXLib::String {

Locale g_DefaultLocale = cp1252;

Locale GetDefaultLocale()
{
    return g_DefaultLocale;
}
void SetDefaultLocale(Locale locale)
{
    if (locale == Default)
        locale = cp1252;

    g_DefaultLocale = locale;
}

void SetDefaultLocale(const std::string& locale)
{
    if (locale.empty())
        return;

    std::string sub = locale.substr(0, 2);
    std::transform(sub.begin(), sub.end(), sub.begin(), ::tolower);

    if (sub == "cp")
    {
        if (locale == "cp1250")
            SetDefaultLocale(cp1250);
        if (locale == "cp1251")
            SetDefaultLocale(cp1251);
        if (locale == "cp1252")
            SetDefaultLocale(cp1252);
    }
    else // Symbolic country codes
    {
        if (sub == "ru" || sub == "bg" || sub == "mk")
            SetDefaultLocale(cp1251);
        else if (sub == "pl" || sub == "cz" || sub == "sk" || sub == "hr" || sub == "hu")
            SetDefaultLocale(cp1250);
        else if (sub == "en" || sub == "de" || sub == "es" || sub == "fr" || sub == "it")
            SetDefaultLocale(cp1252);
        else
        {
            LOG_WARNING("Unknown locale %s", locale);
            SetDefaultLocale(Default);
        }
    }
}

static uint16_t map_unknown[0x80] =
{
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f,
    0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f, 0x003f
};

static uint16_t map_cp1252[0x80] =
{
    0x20ac, 0x0081, 0x201a, 0x0192, 0x201e, 0x2026, 0x2020, 0x2021,
    0x02c6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008d, 0x017d, 0x008f,
    0x0090, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x02dc, 0x2122, 0x0161, 0x203a, 0x0153, 0x009d, 0x017e, 0x0178,
    0x00a0, 0x00a1, 0x00a2, 0x00a3, 0x00a4, 0x00a5, 0x00a6, 0x00a7,
    0x00a8, 0x00a9, 0x00aa, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x00af,
    0x00b0, 0x00b1, 0x00b2, 0x00b3, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
    0x00b8, 0x00b9, 0x00ba, 0x00bb, 0x00bc, 0x00bd, 0x00be, 0x00bf,
    0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c6, 0x00c7,
    0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
    0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d7,
    0x00d8, 0x00d9, 0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00df,
    0x00e0, 0x00e1, 0x00e2, 0x00e3, 0x00e4, 0x00e5, 0x00e6, 0x00e7,
    0x00e8, 0x00e9, 0x00ea, 0x00eb, 0x00ec, 0x00ed, 0x00ee, 0x00ef,
    0x00f0, 0x00f1, 0x00f2, 0x00f3, 0x00f4, 0x00f5, 0x00f6, 0x00f7,
    0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff
};

static uint16_t map_cp1251[0x80] =
{
    0x0402, 0x0403, 0x201a, 0x0453, 0x201e, 0x2026, 0x2020, 0x2021,
    0x20ac, 0x2030, 0x0409, 0x2039, 0x040a, 0x040c, 0x040b, 0x040f,
    0x0452, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x0098, 0x2122, 0x0459, 0x203a, 0x045a, 0x045c, 0x045b, 0x045f,
    0x00a0, 0x040e, 0x045e, 0x0408, 0x00a4, 0x0490, 0x00a6, 0x00a7,
    0x0401, 0x00a9, 0x0404, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x0407,
    0x00b0, 0x00b1, 0x0406, 0x0456, 0x0491, 0x00b5, 0x00b6, 0x00b7,
    0x0451, 0x2116, 0x0454, 0x00bb, 0x0458, 0x0405, 0x0455, 0x0457,
    0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
    0x0418, 0x0419, 0x041a, 0x041b, 0x041c, 0x041d, 0x041e, 0x041f,
    0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
    0x0428, 0x0429, 0x042a, 0x042b, 0x042c, 0x042d, 0x042e, 0x042f,
    0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
    0x0438, 0x0439, 0x043a, 0x043b, 0x043c, 0x043d, 0x043e, 0x043f,
    0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
    0x0448, 0x0449, 0x044a, 0x044b, 0x044c, 0x044d, 0x044e, 0x044f
};

static uint16_t map_cp1250[0x80] =
{
    0x20ac, 0x0081, 0x201a, 0x0083, 0x201e, 0x2026, 0x2020, 0x2021,
    0x0088, 0x2030, 0x0160, 0x2039, 0x015a, 0x0164, 0x017d, 0x0179,
    0x0090, 0x2018, 0x2019, 0x201c, 0x201d, 0x2022, 0x2013, 0x2014,
    0x0098, 0x2122, 0x0161, 0x203a, 0x015b, 0x0165, 0x017e, 0x017a,
    0x00a0, 0x02c7, 0x02d8, 0x0141, 0x00a4, 0x0104, 0x00a6, 0x00a7,
    0x00a8, 0x00a9, 0x015e, 0x00ab, 0x00ac, 0x00ad, 0x00ae, 0x017b,
    0x00b0, 0x00b1, 0x02db, 0x0142, 0x00b4, 0x00b5, 0x00b6, 0x00b7,
    0x00b8, 0x0105, 0x015f, 0x00bb, 0x013d, 0x02dd, 0x013e, 0x017c,
    0x0154, 0x00c1, 0x00c2, 0x0102, 0x00c4, 0x0139, 0x0106, 0x00c7,
    0x010c, 0x00c9, 0x0118, 0x00cb, 0x011a, 0x00cd, 0x00ce, 0x010e,
    0x0110, 0x0143, 0x0147, 0x00d3, 0x00d4, 0x0150, 0x00d6, 0x00d7,
    0x0158, 0x016e, 0x00da, 0x0170, 0x00dc, 0x00dd, 0x0162, 0x00df,
    0x0155, 0x00e1, 0x00e2, 0x0103, 0x00e4, 0x013a, 0x0107, 0x00e7,
    0x010d, 0x00e9, 0x0119, 0x00eb, 0x011b, 0x00ed, 0x00ee, 0x010f,
    0x0111, 0x0144, 0x0148, 0x00f3, 0x00f4, 0x0151, 0x00f6, 0x00f7,
    0x0159, 0x016f, 0x00fa, 0x0171, 0x00fc, 0x00fd, 0x0163, 0x02d9
};

std::string ToUTF8(const char *str, Locale locale)
{
    if (str == nullptr || *str == 0)
        return std::string("");

    std::string utf8("");
    utf8.reserve(2*strlen(str) + 1);

    if (locale == Default)
        locale = GetDefaultLocale();

    uint16_t *map_locale;
    switch (locale)
    {
        case cp1252:
            map_locale = map_cp1252;
            break;
        case cp1251:
            map_locale = map_cp1251;
            break;
        case cp1250:
            map_locale = map_cp1250;
            break;
        default:
            map_locale = map_unknown;
            break;
    }

    const char *tmp = str;

    for (; *str; ++str)
    {
        int codepoint = static_cast<uint8_t>(*str);
        if (codepoint >= 0x80)
        {
            codepoint = map_locale[codepoint & 0x7f];
        }

        if (codepoint <= 0x7f)
            utf8.push_back(*str);
        else if (codepoint <= 0x7ff)
        {
            utf8.push_back(0xc0 | static_cast<char>((codepoint >> 6) & 0x1f));
            utf8.push_back(0x80 | static_cast<char>(codepoint & 0x3f));
        }
        else if (codepoint <= 0xffff)
        {
            utf8.push_back(0xe0 | static_cast<char>((codepoint >> 12) & 0xf));
            utf8.push_back(0x80 | static_cast<char>((codepoint >> 6) & 0x3f));
            utf8.push_back(0x80 | static_cast<char>(codepoint & 0x3f));
        }
        else // codepoint >= 0x10000
        {
            utf8.push_back(0xf0 | static_cast<char>((codepoint >> 18) & 0x7));
            utf8.push_back(0x80 | static_cast<char>((codepoint >> 12) & 0x3f));
            utf8.push_back(0x80 | static_cast<char>((codepoint >> 6) & 0x3f));
            utf8.push_back(0x80 | static_cast<char>(codepoint & 0x3f));
        }
        if (map_locale == map_unknown)
            ASSERT_FAIL_MSG("Unknown locale");
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

    uint16_t *map_locale;
    switch (locale)
    {
        case cp1252:
            map_locale = map_cp1252;
            break;
        case cp1251:
            map_locale = map_cp1251;
            break;
        case cp1250:
            map_locale = map_cp1250;
            break;
        default:
            map_locale = map_unknown;
            break;
    }

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
                int i;
                for (i = 0; i < 0x80; i++)
                {
                    if (map_locale[i] == codepoint)
                    {
                        iso8859.push_back(static_cast<char>(i | 0x80));
                        break;
                    }
                }
                if (i == 0x80)
                    iso8859.push_back('?');
                if (map_locale == map_unknown)
                    ASSERT_FAIL_MSG("Unknown locale");
            }
        }
    }
    LOG_DEBUG("FromUTF: \"%s\" -> \"%s\"", tmp, iso8859);
    return iso8859;
}

std::string ToUTF8(const std::string& str, Locale locale)
{
    return ToUTF8(str.c_str(), locale);
}
std::string FromUTF8(const std::string& str, Locale locale)
{
    return FromUTF8(str.c_str(), locale);
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
    return out;
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
    return out;
}

}
