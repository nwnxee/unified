#include "nwnx"
// The functions below can be performance heavy, do limit how many calls and/or how long of a sentence is passed
// Make use of delaycommands and assign commands

// Returns the spelling mistakes in sentence, comma delimited
// Returns blank if no errors or if .so file is improperly installed
// If it catches an error in every word, even when spelled correctly, the dictionary is not set up correctly.
string NWNX_SpellChecker_FindMisspell(string sentence);

// Get suggestions on a single word, comma delimited
// Returns blank if no errors or if .so file is improperly installed
string NWNX_SpellChecker_GetSuggestSpell(string word);


const string NWNX_SpellChecker = "NWNX_SpellChecker";

string NWNX_SpellChecker_FindMisspell(string sentence)
{
    string sFunc = "FindMisspell";

    NWNX_PushArgumentString(NWNX_SpellChecker, sFunc, sentence);
    NWNX_CallFunction(NWNX_SpellChecker, sFunc);
    return NWNX_GetReturnValueString(NWNX_SpellChecker, sFunc);
}

string NWNX_SpellChecker_GetSuggestSpell(string word)
{
    string sFunc = "GetSuggestSpell";
    NWNX_PushArgumentString(NWNX_SpellChecker, sFunc, word);
    NWNX_CallFunction(NWNX_SpellChecker, sFunc);
    return NWNX_GetReturnValueString(NWNX_SpellChecker, sFunc);
}
