#include "nwnx.hpp"

#include <array>
#include <string>
#include <string.h>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <utility>

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

    std::string lower = locale;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return std::tolower(c); });
    std::string sub = lower.substr(0, 2);

    if (lower == "cp1250")
        SetDefaultLocale(cp1250);
    else if (lower == "cp1251")
        SetDefaultLocale(cp1251);
    else if (lower == "cp1252")
        SetDefaultLocale(cp1252);
    // "cz" is kept for compatibility; the ISO 639-1 code is "cs".
    else if (sub == "ru" || sub == "bg" || sub == "mk")
        SetDefaultLocale(cp1251);
    else if (sub == "pl" || sub == "cs" || sub == "cz" || sub == "sk" || sub == "hr" || sub == "hu")
        SetDefaultLocale(cp1250);
    else if (sub == "en" || sub == "de" || sub == "es" || sub == "fr" || sub == "it")
        SetDefaultLocale(cp1252);
    else
    {
        LOG_WARNING("Unknown locale '%s', using cp1252", locale);
        SetDefaultLocale(Default);
    }
}

// Bytes 0x80-0xFF from https://www.unicode.org/Public/MAPPINGS/VENDORS/MICSFT/WINDOWS/; undefined bytes map to C1 controls.
static constexpr std::array<uint16_t, 128> s_cp1250 =
{
    0x20AC, 0x0081, 0x201A, 0x0083, 0x201E, 0x2026, 0x2020, 0x2021,
    0x0088, 0x2030, 0x0160, 0x2039, 0x015A, 0x0164, 0x017D, 0x0179,
    0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x0098, 0x2122, 0x0161, 0x203A, 0x015B, 0x0165, 0x017E, 0x017A,
    0x00A0, 0x02C7, 0x02D8, 0x0141, 0x00A4, 0x0104, 0x00A6, 0x00A7,
    0x00A8, 0x00A9, 0x015E, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x017B,
    0x00B0, 0x00B1, 0x02DB, 0x0142, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
    0x00B8, 0x0105, 0x015F, 0x00BB, 0x013D, 0x02DD, 0x013E, 0x017C,
    0x0154, 0x00C1, 0x00C2, 0x0102, 0x00C4, 0x0139, 0x0106, 0x00C7,
    0x010C, 0x00C9, 0x0118, 0x00CB, 0x011A, 0x00CD, 0x00CE, 0x010E,
    0x0110, 0x0143, 0x0147, 0x00D3, 0x00D4, 0x0150, 0x00D6, 0x00D7,
    0x0158, 0x016E, 0x00DA, 0x0170, 0x00DC, 0x00DD, 0x0162, 0x00DF,
    0x0155, 0x00E1, 0x00E2, 0x0103, 0x00E4, 0x013A, 0x0107, 0x00E7,
    0x010D, 0x00E9, 0x0119, 0x00EB, 0x011B, 0x00ED, 0x00EE, 0x010F,
    0x0111, 0x0144, 0x0148, 0x00F3, 0x00F4, 0x0151, 0x00F6, 0x00F7,
    0x0159, 0x016F, 0x00FA, 0x0171, 0x00FC, 0x00FD, 0x0163, 0x02D9,
};
static constexpr std::array<uint16_t, 128> s_cp1251 =
{
    0x0402, 0x0403, 0x201A, 0x0453, 0x201E, 0x2026, 0x2020, 0x2021,
    0x20AC, 0x2030, 0x0409, 0x2039, 0x040A, 0x040C, 0x040B, 0x040F,
    0x0452, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x0098, 0x2122, 0x0459, 0x203A, 0x045A, 0x045C, 0x045B, 0x045F,
    0x00A0, 0x040E, 0x045E, 0x0408, 0x00A4, 0x0490, 0x00A6, 0x00A7,
    0x0401, 0x00A9, 0x0404, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x0407,
    0x00B0, 0x00B1, 0x0406, 0x0456, 0x0491, 0x00B5, 0x00B6, 0x00B7,
    0x0451, 0x2116, 0x0454, 0x00BB, 0x0458, 0x0405, 0x0455, 0x0457,
    0x0410, 0x0411, 0x0412, 0x0413, 0x0414, 0x0415, 0x0416, 0x0417,
    0x0418, 0x0419, 0x041A, 0x041B, 0x041C, 0x041D, 0x041E, 0x041F,
    0x0420, 0x0421, 0x0422, 0x0423, 0x0424, 0x0425, 0x0426, 0x0427,
    0x0428, 0x0429, 0x042A, 0x042B, 0x042C, 0x042D, 0x042E, 0x042F,
    0x0430, 0x0431, 0x0432, 0x0433, 0x0434, 0x0435, 0x0436, 0x0437,
    0x0438, 0x0439, 0x043A, 0x043B, 0x043C, 0x043D, 0x043E, 0x043F,
    0x0440, 0x0441, 0x0442, 0x0443, 0x0444, 0x0445, 0x0446, 0x0447,
    0x0448, 0x0449, 0x044A, 0x044B, 0x044C, 0x044D, 0x044E, 0x044F,
};
static constexpr std::array<uint16_t, 128> s_cp1252 =
{
    0x20AC, 0x0081, 0x201A, 0x0192, 0x201E, 0x2026, 0x2020, 0x2021,
    0x02C6, 0x2030, 0x0160, 0x2039, 0x0152, 0x008D, 0x017D, 0x008F,
    0x0090, 0x2018, 0x2019, 0x201C, 0x201D, 0x2022, 0x2013, 0x2014,
    0x02DC, 0x2122, 0x0161, 0x203A, 0x0153, 0x009D, 0x017E, 0x0178,
    0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
    0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
    0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7,
    0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
    0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
    0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
    0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7,
    0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
    0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
    0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
    0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7,
    0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF,
};

static constexpr uint16_t MaxCodePoint(const std::array<uint16_t, 128>& table)
{
    uint16_t max = 0;
    for (auto cp : table)
        max = cp > max ? cp : max;
    return max;
}

// Every code point in the tables is below U+2200, so the reverse lookup is a small direct table.
static constexpr uint32_t ReverseSize = std::max({MaxCodePoint(s_cp1250), MaxCodePoint(s_cp1251), MaxCodePoint(s_cp1252)}) + 1u;

struct Codepage
{
    struct UTF8Bytes
    {
        uint8_t bytes[3];
        uint8_t length;
    };
    std::array<UTF8Bytes, 128> toUTF8;
    std::array<uint8_t, ReverseSize> fromUnicode;
};

static constexpr Codepage MakeCodepage(const std::array<uint16_t, 128>& table)
{
    Codepage codepage = {};
    for (uint32_t i = 0; i < 0x80; i++)
        codepage.fromUnicode[i] = static_cast<uint8_t>(i);
    for (uint32_t i = 0; i < 0x80; i++)
    {
        uint32_t cp = table[i];
        auto& utf8 = codepage.toUTF8[i];
        if (cp < 0x800)
        {
            utf8.bytes[0] = static_cast<uint8_t>(0xC0 | (cp >> 6));
            utf8.bytes[1] = static_cast<uint8_t>(0x80 | (cp & 0x3F));
            utf8.length = 2;
        }
        else
        {
            utf8.bytes[0] = static_cast<uint8_t>(0xE0 | (cp >> 12));
            utf8.bytes[1] = static_cast<uint8_t>(0x80 | ((cp >> 6) & 0x3F));
            utf8.bytes[2] = static_cast<uint8_t>(0x80 | (cp & 0x3F));
            utf8.length = 3;
        }
        codepage.fromUnicode[cp] = static_cast<uint8_t>(0x80 + i);
    }
    return codepage;
}

static constexpr Codepage s_codepages[] = { MakeCodepage(s_cp1250), MakeCodepage(s_cp1251), MakeCodepage(s_cp1252) };

static const Codepage* GetCodepage(Locale locale)
{
    switch (locale)
    {
        case cp1250: return &s_codepages[0];
        case cp1251: return &s_codepages[1];
        case cp1252: return &s_codepages[2];
        default:     return nullptr;
    }
}

static uint8_t FromUnicode(const Codepage& codepage, uint32_t cp)
{
    return cp < ReverseSize ? codepage.fromUnicode[cp] : 0;
}

static constexpr uint32_t InvalidCodePoint = 0xFFFFFFFF;

// Malformed input consumes only its maximal subpart, as in WHATWG, so the next character survives.
static uint32_t DecodeUTF8(const uint8_t* str, size_t len, size_t& i)
{
    uint8_t lead = str[i++];
    if (lead < 0x80)
        return lead;

    uint32_t needed, cp;
    uint8_t lower = 0x80, upper = 0xBF;
    if (lead >= 0xC2 && lead <= 0xDF)
    {
        if (i < len && (str[i] & 0xC0) == 0x80)
            return ((lead & 0x1F) << 6) | (str[i++] & 0x3F);
        return InvalidCodePoint;
    }
    else if (lead >= 0xE0 && lead <= 0xEF)
    {
        needed = 2;
        cp = lead & 0x0F;
        if (lead == 0xE0) lower = 0xA0; // Rejects overlong forms.
        if (lead == 0xED) upper = 0x9F; // Rejects surrogates.
    }
    else if (lead >= 0xF0 && lead <= 0xF4)
    {
        needed = 3;
        cp = lead & 0x07;
        if (lead == 0xF0) lower = 0x90; // Rejects overlong forms.
        if (lead == 0xF4) upper = 0x8F; // Rejects code points above U+10FFFF.
    }
    else
    {
        return InvalidCodePoint;
    }

    for (; needed > 0; needed--)
    {
        if (i >= len || str[i] < lower || str[i] > upper)
            return InvalidCodePoint;
        cp = (cp << 6) | (str[i++] & 0x3F);
        lower = 0x80;
        upper = 0xBF;
    }
    return cp;
}

static bool g_BestFit = false;

void SetBestFit(bool enabled)
{
    g_BestFit = enabled;
}

// Characters none of the three codepages have. Substitutes are ASCII or U+00A0, which all of them have.
struct BestFitEntry
{
    uint16_t from;
    uint16_t to;
};
static constexpr BestFitEntry s_bestFit[] =
{
    { 0x2000, ' ' },
    { 0x2001, ' ' },
    { 0x2002, ' ' },
    { 0x2003, ' ' },
    { 0x2004, ' ' },
    { 0x2005, ' ' },
    { 0x2006, ' ' },
    { 0x2007, 0x00A0 },
    { 0x2008, ' ' },
    { 0x2009, ' ' },
    { 0x200A, ' ' },
    { 0x2010, '-' },
    { 0x2011, '-' },
    { 0x2012, '-' },
    { 0x2015, '-' },
    { 0x201B, '\'' },
    { 0x201F, '"' },
    { 0x202F, 0x00A0 },
    { 0x205F, ' ' },
    { 0x2212, '-' },
};

// Covers every precomposed character of the three codepages (from UnicodeData.txt).
struct Composition
{
    uint16_t base;
    uint16_t mark;
    uint16_t composed;
};
static constexpr Composition s_compositions[] =
{
    {0x0041, 0x0300, 0x00C0}, {0x0041, 0x0301, 0x00C1}, {0x0041, 0x0302, 0x00C2}, {0x0041, 0x0303, 0x00C3},
    {0x0041, 0x0306, 0x0102}, {0x0041, 0x0308, 0x00C4}, {0x0041, 0x030A, 0x00C5}, {0x0041, 0x0328, 0x0104},
    {0x0043, 0x0301, 0x0106}, {0x0043, 0x030C, 0x010C}, {0x0043, 0x0327, 0x00C7}, {0x0044, 0x030C, 0x010E},
    {0x0045, 0x0300, 0x00C8}, {0x0045, 0x0301, 0x00C9}, {0x0045, 0x0302, 0x00CA}, {0x0045, 0x0308, 0x00CB},
    {0x0045, 0x030C, 0x011A}, {0x0045, 0x0328, 0x0118}, {0x0049, 0x0300, 0x00CC}, {0x0049, 0x0301, 0x00CD},
    {0x0049, 0x0302, 0x00CE}, {0x0049, 0x0308, 0x00CF}, {0x004C, 0x0301, 0x0139}, {0x004C, 0x030C, 0x013D},
    {0x004E, 0x0301, 0x0143}, {0x004E, 0x0303, 0x00D1}, {0x004E, 0x030C, 0x0147}, {0x004F, 0x0300, 0x00D2},
    {0x004F, 0x0301, 0x00D3}, {0x004F, 0x0302, 0x00D4}, {0x004F, 0x0303, 0x00D5}, {0x004F, 0x0308, 0x00D6},
    {0x004F, 0x030B, 0x0150}, {0x0052, 0x0301, 0x0154}, {0x0052, 0x030C, 0x0158}, {0x0053, 0x0301, 0x015A},
    {0x0053, 0x030C, 0x0160}, {0x0053, 0x0327, 0x015E}, {0x0054, 0x030C, 0x0164}, {0x0054, 0x0327, 0x0162},
    {0x0055, 0x0300, 0x00D9}, {0x0055, 0x0301, 0x00DA}, {0x0055, 0x0302, 0x00DB}, {0x0055, 0x0308, 0x00DC},
    {0x0055, 0x030A, 0x016E}, {0x0055, 0x030B, 0x0170}, {0x0059, 0x0301, 0x00DD}, {0x0059, 0x0308, 0x0178},
    {0x005A, 0x0301, 0x0179}, {0x005A, 0x0307, 0x017B}, {0x005A, 0x030C, 0x017D}, {0x0061, 0x0300, 0x00E0},
    {0x0061, 0x0301, 0x00E1}, {0x0061, 0x0302, 0x00E2}, {0x0061, 0x0303, 0x00E3}, {0x0061, 0x0306, 0x0103},
    {0x0061, 0x0308, 0x00E4}, {0x0061, 0x030A, 0x00E5}, {0x0061, 0x0328, 0x0105}, {0x0063, 0x0301, 0x0107},
    {0x0063, 0x030C, 0x010D}, {0x0063, 0x0327, 0x00E7}, {0x0064, 0x030C, 0x010F}, {0x0065, 0x0300, 0x00E8},
    {0x0065, 0x0301, 0x00E9}, {0x0065, 0x0302, 0x00EA}, {0x0065, 0x0308, 0x00EB}, {0x0065, 0x030C, 0x011B},
    {0x0065, 0x0328, 0x0119}, {0x0069, 0x0300, 0x00EC}, {0x0069, 0x0301, 0x00ED}, {0x0069, 0x0302, 0x00EE},
    {0x0069, 0x0308, 0x00EF}, {0x006C, 0x0301, 0x013A}, {0x006C, 0x030C, 0x013E}, {0x006E, 0x0301, 0x0144},
    {0x006E, 0x0303, 0x00F1}, {0x006E, 0x030C, 0x0148}, {0x006F, 0x0300, 0x00F2}, {0x006F, 0x0301, 0x00F3},
    {0x006F, 0x0302, 0x00F4}, {0x006F, 0x0303, 0x00F5}, {0x006F, 0x0308, 0x00F6}, {0x006F, 0x030B, 0x0151},
    {0x0072, 0x0301, 0x0155}, {0x0072, 0x030C, 0x0159}, {0x0073, 0x0301, 0x015B}, {0x0073, 0x030C, 0x0161},
    {0x0073, 0x0327, 0x015F}, {0x0074, 0x030C, 0x0165}, {0x0074, 0x0327, 0x0163}, {0x0075, 0x0300, 0x00F9},
    {0x0075, 0x0301, 0x00FA}, {0x0075, 0x0302, 0x00FB}, {0x0075, 0x0308, 0x00FC}, {0x0075, 0x030A, 0x016F},
    {0x0075, 0x030B, 0x0171}, {0x0079, 0x0301, 0x00FD}, {0x0079, 0x0308, 0x00FF}, {0x007A, 0x0301, 0x017A},
    {0x007A, 0x0307, 0x017C}, {0x007A, 0x030C, 0x017E}, {0x0406, 0x0308, 0x0407}, {0x0413, 0x0301, 0x0403},
    {0x0415, 0x0308, 0x0401}, {0x0418, 0x0306, 0x0419}, {0x041A, 0x0301, 0x040C}, {0x0423, 0x0306, 0x040E},
    {0x0433, 0x0301, 0x0453}, {0x0435, 0x0308, 0x0451}, {0x0438, 0x0306, 0x0439}, {0x043A, 0x0301, 0x045C},
    {0x0443, 0x0306, 0x045E}, {0x0456, 0x0308, 0x0457},
};

static constexpr bool IsSorted()
{
    for (size_t i = 1; i < std::size(s_bestFit); i++)
        if (s_bestFit[i].from <= s_bestFit[i - 1].from)
            return false;
    for (size_t i = 1; i < std::size(s_compositions); i++)
        if (s_compositions[i].base < s_compositions[i - 1].base ||
            (s_compositions[i].base == s_compositions[i - 1].base && s_compositions[i].mark <= s_compositions[i - 1].mark))
            return false;
    return true;
}
static_assert(IsSorted(), "best-fit tables must be sorted for binary search");

static uint8_t BestFit(const Codepage& codepage, uint32_t cp)
{
    auto entry = std::lower_bound(std::begin(s_bestFit), std::end(s_bestFit), cp,
                                  [](const BestFitEntry& e, uint32_t c) { return e.from < c; });
    if (entry != std::end(s_bestFit) && entry->from == cp)
        return FromUnicode(codepage, entry->to);
    return 0;
}

static uint32_t Compose(uint32_t base, uint32_t mark)
{
    auto entry = std::lower_bound(std::begin(s_compositions), std::end(s_compositions), std::make_pair(base, mark),
                                  [](const Composition& e, const std::pair<uint32_t, uint32_t>& key)
                                  { return e.base < key.first || (e.base == key.first && e.mark < key.second); });
    if (entry != std::end(s_compositions) && entry->base == base && entry->mark == mark)
        return entry->composed;
    return 0;
}

static bool IsASCII8(const char* str, size_t len)
{
    if (len < 8)
        return false;
    uint64_t chunk;
    memcpy(&chunk, str, sizeof(chunk));
    return (chunk & 0x8080808080808080ull) == 0;
}

static size_t ASCIILength(const char* str, size_t len)
{
    size_t i = 0;
    while (IsASCII8(str + i, len - i))
        i += 8;
    while (i < len && static_cast<uint8_t>(str[i]) < 0x80)
        i++;
    return i;
}

static std::string ToUTF8(const char *str, size_t len, Locale locale)
{
    const size_t ascii = ASCIILength(str, len);
    if (ascii == len)
        return std::string(str, len);

    if (locale == Default)
        locale = GetDefaultLocale();

    const Codepage* codepage = GetCodepage(locale);
    if (!codepage)
    {
        ASSERT_FAIL_MSG("Unknown locale");
        return std::string(len, '?');
    }

    // A non-ASCII byte becomes at most three bytes; the extra byte is for the four-byte copy below.
    std::string utf8(ascii + (len - ascii) * 3 + 1, '\0');
    char* out = utf8.data();
    memcpy(out, str, ascii);
    out += ascii;
    for (size_t i = ascii; i < len;)
    {
        uint8_t ch = static_cast<uint8_t>(str[i]);
        if (ch >= 0x80)
        {
            const auto& encoded = codepage->toUTF8[ch - 0x80];
            memcpy(out, &encoded, sizeof(encoded));
            out += encoded.length;
            i++;
        }
        else if (IsASCII8(str + i, len - i))
        {
            memcpy(out, str + i, 8);
            out += 8;
            i += 8;
        }
        else
        {
            *out++ = static_cast<char>(ch);
            i++;
        }
    }
    utf8.resize(out - utf8.data());

    LOG_DEBUG("ToUTF8: \"%s\" -> \"%s\"", str, utf8);
    return utf8;
}

static std::string FromUTF8(const char *str, size_t len, Locale locale)
{
    const size_t ascii = ASCIILength(str, len);
    if (ascii == len)
        return std::string(str, len);

    if (locale == Default)
        locale = GetDefaultLocale();

    const Codepage* codepage = GetCodepage(locale);
    if (!codepage)
    {
        ASSERT_FAIL_MSG("Unknown locale");
        return std::string(len, '?');
    }

    std::string result(len, '\0');
    char* out = result.data();
    memcpy(out, str, ascii);
    out += ascii;
    const uint8_t* bytes = reinterpret_cast<const uint8_t*>(str);
    uint32_t last = ascii > 0 ? bytes[ascii - 1] : InvalidCodePoint;
    for (size_t i = ascii; i < len;)
    {
        if (bytes[i] < 0x80)
        {
            if (IsASCII8(str + i, len - i))
            {
                memcpy(out, str + i, 8);
                out += 8;
                i += 8;
            }
            else
            {
                *out++ = str[i++];
            }
            last = bytes[i - 1];
            continue;
        }
        uint32_t cp = DecodeUTF8(bytes, len, i);
        if (cp == InvalidCodePoint)
        {
            *out++ = '?';
            last = InvalidCodePoint;
            continue;
        }

        if (uint8_t ch = FromUnicode(*codepage, cp))
        {
            *out++ = static_cast<char>(ch);
            last = cp;
            continue;
        }

        if (g_BestFit)
        {
            if (cp >= 0x0300 && cp <= 0x036F)
            {
                // Merge a combining mark into the previous letter, or drop it.
                uint32_t composed = last != InvalidCodePoint ? Compose(last, cp) : 0;
                if (uint8_t ch = composed ? FromUnicode(*codepage, composed) : 0)
                {
                    out[-1] = static_cast<char>(ch);
                    last = composed;
                }
                continue;
            }
            if (uint8_t ch = BestFit(*codepage, cp))
            {
                *out++ = static_cast<char>(ch);
                last = InvalidCodePoint;
                continue;
            }
        }

        *out++ = '?';
        last = InvalidCodePoint;
    }
    result.resize(out - result.data());

    LOG_DEBUG("FromUTF8: \"%s\" -> \"%s\"", str, result);
    return result;
}

std::string ToUTF8(const char *str, Locale locale)
{
    if (str == nullptr)
        return std::string();
    return ToUTF8(str, strlen(str), locale);
}
std::string FromUTF8(const char *str, Locale locale)
{
    if (str == nullptr)
        return std::string();
    return FromUTF8(str, strlen(str), locale);
}
std::string ToUTF8(const std::string& str, Locale locale)
{
    return ToUTF8(str.c_str(), str.size(), locale);
}
std::string FromUTF8(const std::string& str, Locale locale)
{
    return FromUTF8(str.c_str(), str.size(), locale);
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
        // Ignoring whitespace is conveniently in-spec: Sometimes,
        // base64 is broken up in 78-column chunks.
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n')
            continue;
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
