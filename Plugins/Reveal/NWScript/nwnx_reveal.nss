#include "nwnx"

const string NWNX_Reveal = "NWNX_Reveal";

//Selectively reveals the character oHiding to the character oObserver, until the next time oHiding stealths out of sight.
void NWNX_Reveal_RevealTo(object oHiding, object oObserver);

//Sets whether oHiding remains visible to the character's party through stealth. 
void NWNX_Reveal_SetRevealToParty(object oHiding, int bReveal); 


void NWNX_Reveal_RevealTo(object oHiding, object oObserver)
{
    string sFunc = "RevealTo";
    
    NWNX_PushArgumentObject(NWNX_Reveal, sFunc, oObserver);
    NWNX_PushArgumentObject(NWNX_Reveal, sFunc, oHiding);

    NWNX_CallFunction(NWNX_Reveal, sFunc);
}

void NWNX_Reveal_SetRevealToParty(object oHiding, int bReveal)
{
    string sFunc = "SetRevealToParty";
    
    NWNX_PushArgumentInt(NWNX_Reveal, sFunc, bReveal);
    NWNX_PushArgumentObject(NWNX_Reveal, sFunc, oHiding);

    NWNX_CallFunction(NWNX_Reveal, sFunc);
}