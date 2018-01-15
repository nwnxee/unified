#include "nwnx"

string NWNX_Ruby_Evaluate (string sCode);

string NWNX_Ruby_Evaluate (string sCode) 
{
    NWNX_PushArgumentString ("NWNX_Ruby", "EVALUATE", sCode);
    NWNX_CallFunction ("NWNX_Ruby", "EVALUATE");
    return NWNX_GetReturnValueString ("NWNX_Ruby", "EVALUATE");
}