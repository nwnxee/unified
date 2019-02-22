#include "nwnx"

const string NWNX_Reveal = "NWNX_Reveal";

//Detection method constants

const int NWNX_REVEAL_SEEN = 1;
const int NWNX_REVEAL_HEARD = 0;

//Selectively reveals the character oHiding to the character oObserver, until the next time oHiding stealths out of sight.
//iDetectionMethod can be specified to determine whether oHiding is seen or heard. 
void NWNX_Reveal_RevealTo(object oHiding, object oObserver, int iDetectionMethod = NWNX_REVEAL_HEARD);

//Sets whether oHiding remains visible to the character's party through stealth.
//iDetectionMethod can be specified to determine whether oHiding is seen or heard. 
void NWNX_Reveal_SetRevealToParty(object oHiding, int bReveal, int iDetectionMethod = NWNX_REVEAL_HEARD); 


void NWNX_Reveal_RevealTo(object oHiding, object oObserverint, iDetectionMethod = NWNX_REVEAL_HEARD)
{
    string sFunc = "RevealTo";
    
    NWNX_PushArgumentInt(NWNX_Reveal, sFunc, iDetectionMethod);
    NWNX_PushArgumentObject(NWNX_Reveal, sFunc, oObserver);
    NWNX_PushArgumentObject(NWNX_Reveal, sFunc, oHiding);

    NWNX_CallFunction(NWNX_Reveal, sFunc);
}

void NWNX_Reveal_SetRevealToParty(object oHiding, int bReveal, int iDetectionMethod = NWNX_REVEAL_HEARD)
{
    string sFunc = "SetRevealToParty";
    
    NWNX_PushArgumentInt(NWNX_Reveal, sFunc, iDetectionMethod);
    NWNX_PushArgumentInt(NWNX_Reveal, sFunc, bReveal);
    NWNX_PushArgumentObject(NWNX_Reveal, sFunc, oHiding);

    NWNX_CallFunction(NWNX_Reveal, sFunc);
}