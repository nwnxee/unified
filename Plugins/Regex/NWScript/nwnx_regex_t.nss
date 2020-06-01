#include "nwnx_regex"
#include "nwnx_test"
#include "x3_inc_string"

void main()
{
    while(TEST("Regex"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_SkillRanks")));

        string str = "This string has a <cDDD>color</c> code.";
        int regex_search = NWNX_Regex_Search(str,"<c.+?(?=>)>");
        EXPECT(IS_EQUAL_INT(regex_search, 1));
        str = "This string has \na new line.";
        regex_search = NWNX_Regex_Search(str,"\\n");
        EXPECT(IS_EQUAL_INT(regex_search, 1));
        str = "This string does not have any non-ASCII characters.";
        regex_search = NWNX_Regex_Search(str,"[^\\x01-\\x7E]");
        EXPECT(IS_EQUAL_INT(regex_search, 0));


        string sRedString = StringToRGBString("stripped colors.", STRING_COLOR_RED);
        str = "This is a <cfff>test</c> of "+sRedString;
        string strip_colors = NWNX_Regex_Replace(str,"<c.+?(?=>)>|</c>");
        EXPECT(IS_EQUAL_STRING(strip_colors, "This is a test of stripped colors."));
        str = "This is a “test” of stripping to just ascii printable and new lines.";
        string strip_non_ascii = NWNX_Regex_Replace(str,"[^\\n\\r\\x20-\\x7E]");
        EXPECT(IS_EQUAL_STRING(strip_non_ascii, "This is a test of stripping to just ascii printable and new lines."));
    }
}
