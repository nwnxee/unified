#include "nwnx"


// Returns the spelling mistakes in sentence, comma delimited
// Returns blank if no errors or if .so file is improperly installed
// If it catches an error in every word, even when spelled correctly, the dictionary is not set up correctly.
string NWNX_Spell_GetSpelling(string sentence);

// Get suggestions on a single word, comma delimited
// Returns blank if no errors or if .so file is improperly installed
string NWNX_Spell_GetSuggest(string word);


const string NWNX_Spell = "NWNX_Spell";

string NWNX_Spell_GetSpell(string sentence)
{
    string sFunc = "GetSpell";

    NWNX_PushArgumentString(NWNX_Spell, sFunc, sentence);
    NWNX_CallFunction(NWNX_Spell, sFunc);
    return NWNX_GetReturnValueString(NWNX_Spell, sFunc);
}

string NWNX_Spell_GetSuggest(string word)
{
    string sFunc = "GetSuggest";
    NWNX_PushArgumentString(NWNX_Spell, sFunc, word);
    NWNX_CallFunction(NWNX_Spell, sFunc);
    return NWNX_GetReturnValueString(NWNX_Spell, sFunc);
}
