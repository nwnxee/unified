#include "nwnx_regex"
#include "nwnx_tests"
#include "x3_inc_string"

void main()
{
    WriteTimestampedLogEntry("NWNX_Regex unit test begin..");

    string str = "This string has a <cDDD>color</c> code.";
    int regex_search = NWNX_Regex_Search(str,"<c.+?(?=>)>");
    NWNX_Tests_Report("NWNX_Regex", "RegexSearch", regex_search == 1);
    str = "This string has \na new line.";
    regex_search = NWNX_Regex_Search(str,"\\n");
    NWNX_Tests_Report("NWNX_Regex", "RegexSearch", regex_search == 1);
    str = "This string does not have any non-ASCII characters.";
    regex_search = NWNX_Regex_Search(str,"[^\\x01-\\x7E]");
    NWNX_Tests_Report("NWNX_Regex", "RegexSearch", regex_search == 0);


    string sRedString = StringToRGBString("stripped colors.", STRING_COLOR_RED);
    str = "This is a <cfff>test</c> of "+sRedString;
    string strip_colors = NWNX_Regex_Replace(str,"<c.+?(?=>)>|</c>");
    NWNX_Tests_Report("NWNX_Regex", "RegexReplace", strip_colors == "This is a test of stripped colors.");
    str = "This is a “test” of stripping to just ascii printable and new lines.";
    string strip_non_ascii = NWNX_Regex_Replace(str,"[^\\n\\r\\x20-\\x7E]");
    NWNX_Tests_Report("NWNX_Regex", "RegexReplace", strip_non_ascii == "This is a test of stripping to just ascii printable and new lines.");

    WriteTimestampedLogEntry("NWNX_Regex unit test end.");
}
