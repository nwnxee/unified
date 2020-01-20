/// @addtogroup reveal Reveal
/// @brief Allows the selective revealing of a stealthing character to another character or their party.
/// @{
/// @file nwnx_reveal.nss
#include "nwnx"

const string NWNX_Reveal = "NWNX_Reveal"; ///< @private

/// @name Reveal Detection Methods
/// @{
const int NWNX_REVEAL_SEEN = 1; ///< Seen
const int NWNX_REVEAL_HEARD = 0; ///< Heard
///@}

/// @brief Selectively reveals the character to an observer until the next time they stealth out of sight.
/// @param oHiding The creature who is stealthed.
/// @param oObserver The creature to whom the hider is revealed.
/// @param iDetectionMethod Can be specified to determine whether the hidden creature is seen or heard.
void NWNX_Reveal_RevealTo(object oHiding, object oObserver, int iDetectionMethod = NWNX_REVEAL_HEARD);

/// @brief Sets whether a character remains visible to their party through stealth.
/// @param oHiding The creature who is stealthed.
/// @param bReveal TRUE for visible.
/// @param iDetectionMethod Can be specified to determine whether the hidden creature is seen or heard.
void NWNX_Reveal_SetRevealToParty(object oHiding, int bReveal, int iDetectionMethod = NWNX_REVEAL_HEARD);

/// @}

void NWNX_Reveal_RevealTo(object oHiding, object oObserver, int iDetectionMethod = NWNX_REVEAL_HEARD)
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
