#include "nwnx"

const string NWNX_Ruby = "NWNX_Ruby";

string NWNX_Ruby_Evaluate (string sCode);


string NWNX_Ruby_Evaluate (string sCode) 
{
    string sFunc = "EVALUATE";

    NWNX_PushArgumentString (NWNX_Ruby, sFunc, sCode);
    NWNX_CallFunction (NWNX_Ruby, sFunc);
    return NWNX_GetReturnValueString (NWNX_Ruby, sFunc);
}