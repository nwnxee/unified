//
// Helper library to encode/decode various streams
//

#include <string>

namespace NWNXLib::Encoding {

enum Locale
{
    Default,
    Western,
    Russian,
};

Locale GetDefaultLocale();
void SetDefaultLocale(Locale locale);
void SetDefaultLocale(const std::string& locale);

std::string ToUTF8(const char *str, Locale locale = Default);
std::string FromUTF8(const char *str, Locale locale = Default);

//
// Convenience wrappers
//
static inline std::string ToUTF8(const std::string& str, Locale locale = Default)
{
    return std::move(ToUTF8(str.c_str(), locale));
}
static inline std::string FromUTF8(const std::string& str, Locale locale = Default)
{
    return std::move(FromUTF8(str.c_str(), locale));
}


}
